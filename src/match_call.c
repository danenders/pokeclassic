#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_setup.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "main.h"
#include "match_call.h"
#include "menu.h"
#include "new_game.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "region_map.h"
#include "rtc.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "wild_encounter.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_frontier.h"
#include "constants/event_objects.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainers.h"

// In this file only the values normally associated with Battle Pike and Factory are swapped.
// Note that this is *not* a bug, because they are properly swapped consistently in this file.
// There would only be an issue if anything in this file interacted with something expecting
// the usual value order, or vice versa.
#define MATCH_CALL_FACTORY  FRONTIER_FACILITY_PIKE
#define MATCH_CALL_PIKE     FRONTIER_FACILITY_FACTORY

// Each match call message has variables that can be populated randomly or
// dependent on the trainer. The below are IDs for how to populate the vars
// in a given message.
// Each message may have up to 3 vars in it
enum {
    STR_TRAINER_NAME,
    STR_MAP_NAME,
    STR_SPECIES_IN_ROUTE,
    STR_SPECIES_IN_PARTY,
    STR_FACILITY_NAME,
    STR_FRONTIER_STREAK,
    STR_NONE = -1,
};
#define STRS_NORMAL_MSG      {STR_TRAINER_NAME, STR_NONE,             STR_NONE}
#define STRS_WILD_BATTLE     {STR_TRAINER_NAME, STR_SPECIES_IN_ROUTE, STR_NONE}
#define STRS_BATTLE_NEGATIVE {STR_TRAINER_NAME, STR_NONE,             STR_NONE}
#define STRS_BATTLE_POSITIVE {STR_TRAINER_NAME, STR_SPECIES_IN_PARTY, STR_NONE}
#define STRS_BATTLE_REQUEST  {STR_TRAINER_NAME, STR_MAP_NAME,         STR_NONE}
#define STRS_FRONTIER        {STR_TRAINER_NAME, STR_FACILITY_NAME,    STR_FRONTIER_STREAK}

#define NUM_STRVARS_IN_MSG 3

// Topic IDs for sMatchCallGeneralTopics
enum {
    GEN_TOPIC_PERSONAL = 1,
    GEN_TOPIC_STREAK,
    GEN_TOPIC_STREAK_RECORD,
};

// Topic IDs for sMatchCallBattleTopics
enum {
    B_TOPIC_WILD = 1,
    B_TOPIC_NEGATIVE,
    B_TOPIC_POSITIVE,
};

// Each trainer has a text id for 1 of each of the 3 battle topics
// The msgId is the index into the respective topic's message table
// For all but 2 trainers this index is the same for each topic
#define BATTLE_TEXT_IDS(msgId) {TEXT_ID(B_TOPIC_WILD, (msgId)), TEXT_ID(B_TOPIC_NEGATIVE, (msgId)), TEXT_ID(B_TOPIC_POSITIVE, (msgId))}

// Topic IDs for sMatchCallBattleRequestTopics
enum {
    REQ_TOPIC_SAME_ROUTE = 1,
    REQ_TOPIC_DIFF_ROUTE,
};

struct MatchCallState
{
    u32 minutes;
    u16 trainerId;
    u8 stepCounter;
    bool8 triggeredFromScript;
};

struct MatchCallTrainerTextInfo
{
    u16 trainerId;
    u16 unused;
    u16 battleTopicTextIds[3];
    u16 generalTextId;
    u8 battleFrontierRecordStreakTextIndex;
    u16 sameRouteMatchCallTextId;
    u16 differentRouteMatchCallTextId;
};

struct MatchCallText
{
    const u8 *text;
    s8 stringVarFuncIds[NUM_STRVARS_IN_MSG];
};

struct MultiTrainerMatchCallText
{
    u16 trainerId;
    const u8 *text;
};

struct BattleFrontierStreakInfo
{
    u16 facilityId;
    u16 streak;
};

static EWRAM_DATA struct MatchCallState sMatchCallState = {0};
static EWRAM_DATA struct BattleFrontierStreakInfo sBattleFrontierStreakInfo = {0};

static u32 GetCurrentTotalMinutes(struct Time *);
static u32 GetNumRegisteredNPCs(void);
static u32 GetActiveMatchCallTrainerId(u32);
static int GetTrainerMatchCallId(int);
static u16 GetRematchTrainerLocation(int);
static bool32 TrainerIsEligibleForRematch(int);
static void StartMatchCall(void);
static void ExecuteMatchCall(u8);
static void DrawMatchCallTextBoxBorder_Internal(u32, u32, u32);
static void Task_SpinPokenavIcon(u8);
static void InitMatchCallTextPrinter(int, const u8 *);
static bool32 RunMatchCallTextPrinter(int);
static const struct MatchCallText *GetSameRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetDifferentRouteMatchCallText(int, u8 *);
static const struct MatchCallText *GetBattleMatchCallText(int, u8 *);
static const struct MatchCallText *GetGeneralMatchCallText(int, u8 *);
static bool32 ShouldTrainerRequestBattle(int);
static void BuildMatchCallString(int, const struct MatchCallText *, u8 *);
static u16 GetFrontierStreakInfo(u16, u32 *);
static void PopulateMatchCallStringVars(int, const s8 *);
static void PopulateMatchCallStringVar(int, int, u8 *);
static bool32 MatchCall_LoadGfx(u8);
static bool32 MatchCall_DrawWindow(u8);
static bool32 MatchCall_ReadyIntro(u8);
static bool32 MatchCall_SlideWindowIn(u8);
static bool32 MatchCall_PrintIntro(u8);
static bool32 MatchCall_PrintMessage(u8);
static bool32 MatchCall_SlideWindowOut(u8);
static bool32 MatchCall_EndCall(u8);
static void PopulateTrainerName(int, u8 *);
static void PopulateMapName(int, u8 *);
static void PopulateSpeciesFromTrainerLocation(int, u8 *);
static void PopulateSpeciesFromTrainerParty(int, u8 *);
static void PopulateBattleFrontierFacilityName(int, u8 *);
static void PopulateBattleFrontierStreak(int, u8 *);

#define TEXT_ID(topic, id) (((topic) << 8) | ((id) & 0xFF))

static const struct MatchCallTrainerTextInfo sMatchCallTrainers[] = //TODO: Personalize these
{
    {
        .trainerId = REMATCHABLE_TRAINER_LASS_JANICE_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(1),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 1),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 1),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 1),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_YOUNGSTER_BEN_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(5),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 2),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 5),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 5),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_CAMPER_SHANE_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(4),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 3),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 4),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 4),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_HIKER_FRANKLIN_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(2),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 4),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 2),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 2),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(3),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 5),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 3),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 3),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_GAMBLER_HUGO_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(4),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 6),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 4),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 4),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_ENGINEER_BERNIE_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(3),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 7),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 3),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 3),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_FISHERMAN_NED_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(2),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 8),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 2),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 2),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_ROCKER_LUCA_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(5),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 9),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 5),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 5),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_PICNICKER_ALICIA_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(1),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 10),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 1),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 1),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_POKEMANIAC_MARK_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(4),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 11),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 4),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 4),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(4),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 12),
        .battleFrontierRecordStreakTextIndex = 4,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 4),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 4),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_BIKER_HIDEO_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(5),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 13),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 5),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 5),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_CUE_BALL_KOJI_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(5),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 14),
        .battleFrontierRecordStreakTextIndex = 5,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 5),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 5),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(1),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 15),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 1),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 1),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(2),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 16),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 2),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 2),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_TUBER_RICHIE_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(1),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 17),
        .battleFrontierRecordStreakTextIndex = 1,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 1),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 1),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(3),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 18),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 3),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 3),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_JUGGLER_JOHAN_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(3),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 19),
        .battleFrontierRecordStreakTextIndex = 3,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 3),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 3),
    },
    {
        .trainerId = REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1,
        .unused = 0,
        .battleTopicTextIds = BATTLE_TEXT_IDS(2),
        .generalTextId = TEXT_ID(GEN_TOPIC_PERSONAL, 20),
        .battleFrontierRecordStreakTextIndex = 2,
        .sameRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_SAME_ROUTE, 2),
        .differentRouteMatchCallTextId = TEXT_ID(REQ_TOPIC_DIFF_ROUTE, 2),
    },

};

static const struct MatchCallText sMatchCallWildBattleTexts[] =
{
    { .text = MatchCall_WildBattleText1,  .stringVarFuncIds = STRS_WILD_BATTLE },
    { .text = MatchCall_WildBattleText2,  .stringVarFuncIds = STRS_WILD_BATTLE },
    { .text = MatchCall_WildBattleText3,  .stringVarFuncIds = STRS_WILD_BATTLE },
    { .text = MatchCall_WildBattleText4,  .stringVarFuncIds = STRS_WILD_BATTLE },
    { .text = MatchCall_WildBattleText5,  .stringVarFuncIds = STRS_WILD_BATTLE },
};

static const struct MatchCallText sMatchCallNegativeBattleTexts[] =
{
    { .text = MatchCall_NegativeBattleText1,  .stringVarFuncIds = STRS_BATTLE_NEGATIVE },
    { .text = MatchCall_NegativeBattleText2,  .stringVarFuncIds = STRS_BATTLE_NEGATIVE },
    { .text = MatchCall_NegativeBattleText3,  .stringVarFuncIds = STRS_BATTLE_NEGATIVE },
    { .text = MatchCall_NegativeBattleText4,  .stringVarFuncIds = STRS_BATTLE_NEGATIVE },
    { .text = MatchCall_NegativeBattleText5,  .stringVarFuncIds = STRS_BATTLE_NEGATIVE },
};

static const struct MatchCallText sMatchCallPositiveBattleTexts[] =
{
    { .text = MatchCall_PositiveBattleText1,  .stringVarFuncIds = STRS_BATTLE_POSITIVE },
    { .text = MatchCall_PositiveBattleText2,  .stringVarFuncIds = STRS_BATTLE_POSITIVE },
    { .text = MatchCall_PositiveBattleText3,  .stringVarFuncIds = STRS_BATTLE_POSITIVE },
    { .text = MatchCall_PositiveBattleText4,  .stringVarFuncIds = STRS_BATTLE_POSITIVE },
    { .text = MatchCall_PositiveBattleText5,  .stringVarFuncIds = STRS_BATTLE_POSITIVE },
};

static const struct MatchCallText sMatchCallSameRouteBattleRequestTexts[] =
{
    { .text = MatchCall_SameRouteBattleRequestText1,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_SameRouteBattleRequestText2,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_SameRouteBattleRequestText3,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_SameRouteBattleRequestText4,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_SameRouteBattleRequestText5,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
};

static const struct MatchCallText sMatchCallDifferentRouteBattleRequestTexts[] =
{
    { .text = MatchCall_DifferentRouteBattleRequestText1,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_DifferentRouteBattleRequestText2,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_DifferentRouteBattleRequestText3,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_DifferentRouteBattleRequestText4,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
    { .text = MatchCall_DifferentRouteBattleRequestText5,  .stringVarFuncIds = STRS_BATTLE_REQUEST },
};

static const struct MatchCallText sMatchCallPersonalizedTexts[] =
{
    { .text = MatchCall_PersonalizedText1,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText2,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText3,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText4,  .stringVarFuncIds = { STR_TRAINER_NAME, STR_MAP_NAME, STR_NONE } },
    { .text = MatchCall_PersonalizedText5,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText6,  .stringVarFuncIds = { STR_TRAINER_NAME, STR_MAP_NAME, STR_NONE } },
    { .text = MatchCall_PersonalizedText7,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText8,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText9,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText10, .stringVarFuncIds = { STR_TRAINER_NAME, STR_SPECIES_IN_PARTY, STR_NONE } },
    { .text = MatchCall_PersonalizedText11, .stringVarFuncIds = { STR_TRAINER_NAME, STR_SPECIES_IN_ROUTE, STR_NONE } },
    { .text = MatchCall_PersonalizedText12,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText13,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText14,  .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText15, .stringVarFuncIds = { STR_TRAINER_NAME, STR_SPECIES_IN_PARTY, STR_NONE } },
    { .text = MatchCall_PersonalizedText16, .stringVarFuncIds = { STR_TRAINER_NAME, STR_SPECIES_IN_PARTY, STR_NONE } },
    { .text = MatchCall_PersonalizedText17, .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText18, .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText19, .stringVarFuncIds = STRS_NORMAL_MSG },
    { .text = MatchCall_PersonalizedText20, .stringVarFuncIds = STRS_NORMAL_MSG },
};

static const struct MatchCallText sMatchCallBattleFrontierStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierStreakText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierStreakText5,  .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText sMatchCallBattleFrontierRecordStreakTexts[] =
{
    { .text = MatchCall_BattleFrontierRecordStreakText1,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText2,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText3,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText4,  .stringVarFuncIds = STRS_FRONTIER },
    { .text = MatchCall_BattleFrontierRecordStreakText5,  .stringVarFuncIds = STRS_FRONTIER },
};

static const struct MatchCallText *const sMatchCallBattleTopics[] =
{
    [B_TOPIC_WILD - 1]     = sMatchCallWildBattleTexts,
    [B_TOPIC_NEGATIVE - 1] = sMatchCallNegativeBattleTexts,
    [B_TOPIC_POSITIVE - 1] = sMatchCallPositiveBattleTexts,
};

static const struct MatchCallText *const sMatchCallBattleRequestTopics[] =
{
    [REQ_TOPIC_SAME_ROUTE - 1] = sMatchCallSameRouteBattleRequestTexts,
    [REQ_TOPIC_DIFF_ROUTE - 1] = sMatchCallDifferentRouteBattleRequestTexts,
};

static const struct MatchCallText *const sMatchCallGeneralTopics[] =
{
    [GEN_TOPIC_PERSONAL - 1]      = sMatchCallPersonalizedTexts,
    [GEN_TOPIC_STREAK - 1]        = sMatchCallBattleFrontierStreakTexts,
    [GEN_TOPIC_STREAK_RECORD - 1] = sMatchCallBattleFrontierRecordStreakTexts,
};

extern const u8 gOakDexRatingText_AreYouCurious[];
extern const u8 gOakDexRatingText_SoYouveSeenAndCaught[];

void InitMatchCallCounters(void)
{
    RtcCalcLocalTime();
    sMatchCallState.minutes = GetCurrentTotalMinutes(&gLocalTime) + 10;
    sMatchCallState.stepCounter = 0;
}

static u32 GetCurrentTotalMinutes(struct Time *time)
{
    return time->days * 24 * 60 + time->hours * 60 + time->minutes;
}

static bool32 UpdateMatchCallMinutesCounter(void)
{
    int curMinutes;
    RtcCalcLocalTime();
    curMinutes = GetCurrentTotalMinutes(&gLocalTime);
    if (sMatchCallState.minutes > curMinutes || curMinutes - sMatchCallState.minutes > 9)
    {
        sMatchCallState.minutes = curMinutes;
        return TRUE;
    }

    return FALSE;
}

static bool32 CheckMatchCallChance(void)
{
    int callChance = 1;
    if (!GetMonData(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG) && GetMonAbility(&gPlayerParty[0]) == ABILITY_LIGHTNING_ROD)
        callChance = 2;

    if (Random() % 10 < callChance * 3)
        return TRUE;
    else
        return FALSE;
}

static bool32 MapAllowsMatchCall(void)
{
    if (!Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) || gMapHeader.regionMapSectionId == MAPSEC_SAFARI_ZONE)
        return FALSE;

    //Retained as example for blocking a Match Call
    /*if (gMapHeader.regionMapSectionId == MAPSEC_MT_CHIMNEY
     && FlagGet(FLAG_MET_ARCHIE_METEOR_FALLS) == TRUE
     && FlagGet(FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY) == FALSE)
        return FALSE;*/

    return TRUE;
}

static bool32 UpdateMatchCallStepCounter(void)
{
    if (++sMatchCallState.stepCounter >= 10)
    {
        sMatchCallState.stepCounter = 0;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 SelectMatchCallTrainer(void)
{
    u32 matchCallId;
    u32 numRegistered = GetNumRegisteredNPCs();
    if (numRegistered == 0)
        return FALSE;

    sMatchCallState.trainerId = GetActiveMatchCallTrainerId(Random() % numRegistered);
    sMatchCallState.triggeredFromScript = FALSE;
    if (sMatchCallState.trainerId == REMATCH_TABLE_ENTRIES)
        return FALSE;

    matchCallId = GetTrainerMatchCallId(sMatchCallState.trainerId);
    if (GetRematchTrainerLocation(matchCallId) == gMapHeader.regionMapSectionId && !TrainerIsEligibleForRematch(matchCallId))
        return FALSE;

    return TRUE;
}

static u32 GetNumRegisteredNPCs(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + i))
            count++;
    }

    return count;
}

static u32 GetActiveMatchCallTrainerId(u32 activeMatchCallId)
{
    u32 i;
    for (i = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (FlagGet(FLAG_MATCH_CALL_REGISTERED + i))
        {
            if (!activeMatchCallId)
                return gRematchTable[i].trainerIds[0];

            activeMatchCallId--;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

/*
    From the function calls below, a call can only be triggered...
    - If the player has match call
    - Every 10th step
    - Every 10 minutes
    - 1/3 of the time (or 2/3 of the time, if the lead party Pokémon has Lightning Rod)
    - If in a valid outdoor map (not Safari Zone, not underwater, not Mt Chimney with Team Magma, not Sootopolis with legendaries)
    - If an eligible trainer to call the player is selected
*/
bool32 TryStartMatchCall(void)
{
    if (FlagGet(FLAG_HAS_MATCH_CALL)
        && UpdateMatchCallStepCounter()
        && UpdateMatchCallMinutesCounter()
        && CheckMatchCallChance()
        && MapAllowsMatchCall()
        && SelectMatchCallTrainer())
    {
        StartMatchCall();
        return TRUE;
    }

    return FALSE;
}

void StartMatchCallFromScript(const u8 *message)
{
    sMatchCallState.triggeredFromScript = TRUE;
    StartMatchCall();
}

bool32 IsMatchCallTaskActive(void)
{
    return FuncIsActiveTask(ExecuteMatchCall);
}

static void StartMatchCall(void)
{
    if (!sMatchCallState.triggeredFromScript)
    {
        ScriptContext2_Enable();
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }

    PlaySE(SE_POKENAV_CALL);
    CreateTask(ExecuteMatchCall, 1);
}

static const u16 sMatchCallWindow_Pal[] = INCBIN_U16("graphics/pokenav/match_call/window.gbapal");
static const u8 sMatchCallWindow_Gfx[] = INCBIN_U8("graphics/pokenav/match_call/window.4bpp");
static const u16 sPokenavIcon_Pal[] = INCBIN_U16("graphics/pokenav/match_call/nav_icon.gbapal");
static const u32 sPokenavIcon_Gfx[] = INCBIN_U32("graphics/pokenav/match_call/nav_icon.4bpp.lz");

static const u8 sText_PokenavCallEllipsis[] = _("………………\p");

#define tState      data[0]
#define tWindowId   data[2]
#define tIconTaskId data[5]

static bool32 (*const sMatchCallTaskFuncs[])(u8) =
{
    MatchCall_LoadGfx,
    MatchCall_DrawWindow,
    MatchCall_ReadyIntro,
    MatchCall_SlideWindowIn,
    MatchCall_PrintIntro,
    MatchCall_PrintMessage,
    MatchCall_SlideWindowOut,
    MatchCall_EndCall,
};

static void ExecuteMatchCall(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sMatchCallTaskFuncs[tState](taskId))
    {
        tState++;
        data[1] = 0; // Never read
        if ((u16)tState > 7)
            DestroyTask(taskId);
    }
}

static const struct WindowTemplate sMatchCallTextWindow =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 15,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x200
};

#define TILE_MC_WINDOW    0x270
#define TILE_POKENAV_ICON 0x279

static bool32 MatchCall_LoadGfx(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tWindowId = AddWindow(&sMatchCallTextWindow);
    if (tWindowId == WINDOW_NONE)
    {
        DestroyTask(taskId);
        return FALSE;
    }

    if (LoadBgTiles(0, sMatchCallWindow_Gfx, sizeof(sMatchCallWindow_Gfx), TILE_MC_WINDOW) == 0xFFFF)
    {
        RemoveWindow(tWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    if (!DecompressAndCopyTileDataToVram(0, sPokenavIcon_Gfx, 0, TILE_POKENAV_ICON, 0))
    {
        RemoveWindow(tWindowId);
        DestroyTask(taskId);
        return FALSE;
    }

    FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));
    LoadPalette(sMatchCallWindow_Pal, 0xE0, sizeof(sMatchCallWindow_Pal));
    LoadPalette(sPokenavIcon_Pal, 0xF0, sizeof(sPokenavIcon_Pal));
    ChangeBgY(0, -0x2000, BG_COORD_SET);
    return TRUE;
}

static bool32 MatchCall_DrawWindow(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (FreeTempTileDataBuffersIfPossible())
        return FALSE;

    PutWindowTilemap(tWindowId);
    DrawMatchCallTextBoxBorder_Internal(tWindowId, TILE_MC_WINDOW, 14);
    WriteSequenceToBgTilemapBuffer(0, (0xF << 12) | TILE_POKENAV_ICON, 1, 15, 4, 4, 17, 1);
    tIconTaskId = CreateTask(Task_SpinPokenavIcon, 10);
    CopyWindowToVram(tWindowId, COPYWIN_GFX);
    CopyBgTilemapBufferToVram(0);
    return TRUE;
}

static bool32 MatchCall_ReadyIntro(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!IsDma3ManagerBusyWithBgCopy())
    {
        // Note that "..." is not printed yet, just readied
        InitMatchCallTextPrinter(tWindowId, sText_PokenavCallEllipsis);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_SlideWindowIn(u8 taskId)
{
    if (ChangeBgY(0, 0x600, BG_COORD_ADD) >= 0)
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_PrintIntro(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!RunMatchCallTextPrinter(tWindowId))
    {
        FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));

        // Ready the message
        if (!sMatchCallState.triggeredFromScript)
            SelectMatchCallMessage(sMatchCallState.trainerId, gStringVar4);
        InitMatchCallTextPrinter(tWindowId, gStringVar4);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_PrintMessage(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!RunMatchCallTextPrinter(tWindowId) && !IsSEPlaying() && JOY_NEW(A_BUTTON | B_BUTTON))
    {
        FillWindowPixelBuffer(tWindowId, PIXEL_FILL(8));
        CopyWindowToVram(tWindowId, COPYWIN_GFX);
        PlaySE(SE_POKENAV_HANG_UP);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_SlideWindowOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (ChangeBgY(0, 0x600, BG_COORD_SUB) <= -0x2000)
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 14, 30, 6);
        DestroyTask(tIconTaskId);
        RemoveWindow(tWindowId);
        CopyBgTilemapBufferToVram(0);
        return TRUE;
    }

    return FALSE;
}

static bool32 MatchCall_EndCall(u8 taskId)
{
    u8 playerObjectId;
    if (!IsDma3ManagerBusyWithBgCopy() && !IsSEPlaying())
    {
        ChangeBgY(0, 0, BG_COORD_SET);
        if (!sMatchCallState.triggeredFromScript)
        {
            LoadMessageBoxAndBorderGfx();
            playerObjectId = GetObjectEventIdByLocalIdAndMap(OBJ_EVENT_ID_PLAYER, 0, 0);
            ObjectEventClearHeldMovementIfFinished(&gObjectEvents[playerObjectId]);
            ScriptMovement_UnfreezeObjectEvents();
            UnfreezeObjectEvents();
            ScriptContext2_Disable();
        }

        return TRUE;
    }

    return FALSE;
}

static void DrawMatchCallTextBoxBorder_Internal(u32 windowId, u32 tileOffset, u32 paletteId)
{
    int bg, x, y, width, height;
    int tileNum;

    bg = GetWindowAttribute(windowId, WINDOW_BG);
    x = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    y = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    height = GetWindowAttribute(windowId, WINDOW_HEIGHT);
    tileNum = tileOffset + GetBgAttribute(bg, BG_ATTR_BASETILE);

    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 0), x - 1, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 1), x, y - 1, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 2), x + width, y - 1, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 3), x - 1, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 4), x + width, y, 1, height);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 5), x - 1, y + height, 1, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 6), x, y + height, width, 1);
    FillBgTilemapBufferRect_Palette0(bg, ((paletteId << 12) & 0xF000) | (tileNum + 7), x + width, y + height, 1, 1);
}

static void InitMatchCallTextPrinter(int windowId, const u8 *str)
{
    struct TextPrinterTemplate printerTemplate;
    printerTemplate.currentChar = str;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = FONT_NORMAL;
    printerTemplate.x = 32;
    printerTemplate.y = 1;
    printerTemplate.currentX = 32;
    printerTemplate.currentY = 1;
    printerTemplate.letterSpacing = 0;
    printerTemplate.lineSpacing = 0;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = TEXT_DYNAMIC_COLOR_1;
    printerTemplate.bgColor = TEXT_COLOR_BLUE;
    printerTemplate.shadowColor = TEXT_DYNAMIC_COLOR_5;
    gTextFlags.useAlternateDownArrow = FALSE;

    AddTextPrinter(&printerTemplate, GetPlayerTextSpeedDelay(), NULL);
}

static bool32 RunMatchCallTextPrinter(int windowId)
{
    if (JOY_HELD(A_BUTTON))
        gTextFlags.canABSpeedUpPrint = TRUE;
    else
        gTextFlags.canABSpeedUpPrint = FALSE;

    RunTextPrinters();
    return IsTextPrinterActive(windowId);
}

#define tTimer     data[0]
#define tSpinStage data[1]
#define tTileNum   data[2]

static void Task_SpinPokenavIcon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (++tTimer > 8)
    {
        tTimer = 0;
        if (++tSpinStage > 7)
            tSpinStage = 0;

        tTileNum = (tSpinStage * 16) + TILE_POKENAV_ICON;
        WriteSequenceToBgTilemapBuffer(0, tTileNum | ~0xFFF, 1, 15, 4, 4, 17, 1);
        CopyBgTilemapBufferToVram(0);
    }
}

#undef tTimer
#undef tSpinStage
#undef tTileNum

static bool32 TrainerIsEligibleForRematch(int matchCallId)
{
    #ifndef FREE_MATCH_CALL
    return gSaveBlock1Ptr->trainerRematches[matchCallId] > 0;
    #endif
}

static u16 GetRematchTrainerLocation(int matchCallId)
{
    const struct MapHeader *mapHeader = Overworld_GetMapHeaderByGroupAndId(gRematchTable[matchCallId].mapGroup, gRematchTable[matchCallId].mapNum);
    return mapHeader->regionMapSectionId;
}

static u32 GetNumRematchTrainersFought(void)
{
    u32 i, count;
    for (i = 0, count = 0; i < REMATCH_SPECIAL_TRAINER_START; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
            count++;
    }

    return count;
}

// Look through the rematch table for trainers that have been defeated once before.
// Return the index into the rematch table of the nth defeated trainer,
// or REMATCH_TABLE_ENTRIES if fewer than n rematch trainers have been defeated.
static u32 GetNthRematchTrainerFought(int n)
{
    u32 i, count;

    for (i = 0, count = 0; i < REMATCH_TABLE_ENTRIES; i++)
    {
        if (HasTrainerBeenFought(gRematchTable[i].trainerIds[0]))
        {
            if (count == n)
                return i;

            count++;
        }
    }

    return REMATCH_TABLE_ENTRIES;
}

bool32 SelectMatchCallMessage(int trainerId, u8 *str)
{
    u32 matchCallId;
    const struct MatchCallText *matchCallText;
    bool32 newRematchRequest = FALSE;

    matchCallId = GetTrainerMatchCallId(trainerId);
    sBattleFrontierStreakInfo.facilityId = 0;

    // If the player is on the same route as the trainer
    // and they can be rematched, they will always request a battle
    if (TrainerIsEligibleForRematch(matchCallId)
     && GetRematchTrainerLocation(matchCallId) == gMapHeader.regionMapSectionId)
    {
        matchCallText = GetSameRouteMatchCallText(matchCallId, str);
    }
    // If the player is not on the same route as the trainer
    // and they can be rematched, there is a random chance for
    // the trainer to request a battle
    else if (ShouldTrainerRequestBattle(matchCallId))
    {
        matchCallText = GetDifferentRouteMatchCallText(matchCallId, str);
        newRematchRequest = TRUE;
        UpdateRematchIfDefeated(matchCallId);
    }
    else if (Random() % 3)
    {
        // Message talking about a battle the NPC had
        matchCallText = GetBattleMatchCallText(matchCallId, str);
    }
    else
    {
        // Message talking about something else
        matchCallText = GetGeneralMatchCallText(matchCallId, str);
    }

    BuildMatchCallString(matchCallId, matchCallText, str);
    return newRematchRequest;
}

static int GetTrainerMatchCallId(int trainerId)
{
    int i = 0;
    while (1)
    {
        if (sMatchCallTrainers[i].trainerId == trainerId)
            return i;
        else
            i++;
    }
}

static const struct MatchCallText *GetSameRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].sameRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetDifferentRouteMatchCallText(int matchCallId, u8 *str)
{
    u16 textId = sMatchCallTrainers[matchCallId].differentRouteMatchCallTextId;
    int mask = 0xFF;
    u32 topic = (textId >> 8) - 1;
    u32 id = (textId & mask) - 1;
    return &sMatchCallBattleRequestTopics[topic][id];
}

static const struct MatchCallText *GetBattleMatchCallText(int matchCallId, u8 *str)
{
    int mask;
    u32 textId, topic, id;

    topic = Random() % 3;
    textId = sMatchCallTrainers[matchCallId].battleTopicTextIds[topic];
    if (!textId)
        SpriteCallbackDummy(NULL); // leftover debugging ???

    mask = 0xFF;
    topic = (textId >> 8) - 1;
    id = (textId & mask) - 1;
    return &sMatchCallBattleTopics[topic][id];
}

static const struct MatchCallText *GetGeneralMatchCallText(int matchCallId, u8 *str)
{
    int i;
    int count;
    u32 topic, id;
    u16 rand;

    rand = Random();
    if (!(rand & 1))
    {
        // Count the number of facilities with a win streak
        for (count = 0, i = 0; i < NUM_FRONTIER_FACILITIES; i++)
        {
            if (GetFrontierStreakInfo(i, &topic) > 1)
                count++;
        }

        if (count)
        {
            // At least one facility with a win streak
            // Randomly choose one to have a call about
            count = Random() % count;
            for (i = 0; i < NUM_FRONTIER_FACILITIES; i++)
            {
                sBattleFrontierStreakInfo.streak = GetFrontierStreakInfo(i, &topic);
                if (sBattleFrontierStreakInfo.streak < 2)
                    continue;

                if (!count)
                    break;

                count--;
            }

            sBattleFrontierStreakInfo.facilityId = i;
            id = sMatchCallTrainers[matchCallId].battleFrontierRecordStreakTextIndex - 1;
            return &sMatchCallGeneralTopics[topic][id];
        }
    }

    topic = (sMatchCallTrainers[matchCallId].generalTextId >> 8) - 1;
    id = (sMatchCallTrainers[matchCallId].generalTextId & 0xFF) - 1;
    return &sMatchCallGeneralTopics[topic][id];
}

static void BuildMatchCallString(int matchCallId, const struct MatchCallText *matchCallText, u8 *str)
{
    PopulateMatchCallStringVars(matchCallId, matchCallText->stringVarFuncIds);
    StringExpandPlaceholders(str, matchCallText->text);
}

static u8 *const sMatchCallTextStringVars[] = { gStringVar1, gStringVar2, gStringVar3 };

static void PopulateMatchCallStringVars(int matchCallId, const s8 *stringVarFuncIds)
{
    int i;
    for (i = 0; i < NUM_STRVARS_IN_MSG; i++)
    {
        if (stringVarFuncIds[i] >= 0)
            PopulateMatchCallStringVar(matchCallId, stringVarFuncIds[i], sMatchCallTextStringVars[i]);
    }
}

static void (*const sPopulateMatchCallStringVarFuncs[])(int, u8 *) =
{
    [STR_TRAINER_NAME]     = PopulateTrainerName,
    [STR_MAP_NAME]         = PopulateMapName,
    [STR_SPECIES_IN_ROUTE] = PopulateSpeciesFromTrainerLocation,
    [STR_SPECIES_IN_PARTY] = PopulateSpeciesFromTrainerParty,
    [STR_FACILITY_NAME]    = PopulateBattleFrontierFacilityName,
    [STR_FRONTIER_STREAK]  = PopulateBattleFrontierStreak,
};

static void PopulateMatchCallStringVar(int matchCallId, int funcId, u8 *destStr)
{
    sPopulateMatchCallStringVarFuncs[funcId](matchCallId, destStr);
}

static const struct MultiTrainerMatchCallText sMultiTrainerMatchCallTexts[] =
{
    //{ .trainerId = TRAINER_KIRA_AND_DAN_1, .text = gText_Kira },
    //{ .trainerId = TRAINER_AMY_AND_LIV_1,  .text = gText_Amy },
    //{ .trainerId = TRAINER_JOHN_AND_JAY_1, .text = gText_John },
    //{ .trainerId = TRAINER_LILA_AND_ROY_1, .text = gText_Roy },
    //{ .trainerId = TRAINER_GABBY_AND_TY_1, .text = gText_Gabby },
    //{ .trainerId = TRAINER_ANNA_AND_MEG_1, .text = gText_Anna },
};

static void PopulateTrainerName(int matchCallId, u8 *destStr)
{
    u32 i;
    u16 trainerId = sMatchCallTrainers[matchCallId].trainerId;
    for (i = 0; i < ARRAY_COUNT(sMultiTrainerMatchCallTexts); i++)
    {
        if (sMultiTrainerMatchCallTexts[i].trainerId == trainerId)
        {
            StringCopy(destStr, sMultiTrainerMatchCallTexts[i].text);
            return;
        }
    }

    StringCopy(destStr, gTrainers[trainerId].trainerName);
}

static void PopulateMapName(int matchCallId, u8 *destStr)
{
    GetMapName(destStr, GetRematchTrainerLocation(matchCallId), 0);
}

static u8 GetLandEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 20)
        return 0;
    else if (rand >= 20 && rand < 40)
        return 1;
    else if (rand >= 40 && rand < 50)
        return 2;
    else if (rand >= 50 && rand < 60)
        return 3;
    else if (rand >= 60 && rand < 70)
        return 4;
    else if (rand >= 70 && rand < 80)
        return 5;
    else if (rand >= 80 && rand < 85)
        return 6;
    else if (rand >= 85 && rand < 90)
        return 7;
    else if (rand >= 90 && rand < 94)
        return 8;
    else if (rand >= 94 && rand < 98)
        return 9;
    else if (rand >= 98 && rand < 99)
        return 10;
    else
        return 11;
}

static u8 GetWaterEncounterSlot(void)
{
    int rand = Random() % 100;
    if (rand < 60)
        return 0;
    else if (rand >= 60 && rand < 90)
        return 1;
    else if (rand >= 90 && rand < 95)
        return 2;
    else if (rand >= 95 && rand < 99)
        return 3;
    else
        return 4;
}

static void PopulateSpeciesFromTrainerLocation(int matchCallId, u8 *destStr)
{
    u16 species[2];
    int numSpecies;
    u8 slot;
    int i = 0;

    if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED)) // ??? This check is nonsense.
    {
        while (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            if (gWildMonHeaders[i].mapGroup == gRematchTable[matchCallId].mapGroup
             && gWildMonHeaders[i].mapNum == gRematchTable[matchCallId].mapNum)
                break;

            i++;
        }

        if (gWildMonHeaders[i].mapGroup != MAP_GROUP(UNDEFINED))
        {
            numSpecies = 0;
            if (gWildMonHeaders[i].landMonsInfo)
            {
                slot = GetLandEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].landMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (gWildMonHeaders[i].waterMonsInfo)
            {
                slot = GetWaterEncounterSlot();
                species[numSpecies] = gWildMonHeaders[i].waterMonsInfo->wildPokemon[slot].species;
                numSpecies++;
            }

            if (numSpecies)
            {
                StringCopy(destStr, gSpeciesNames[species[Random() % numSpecies]]);
                return;
            }
        }
    }

    destStr[0] = EOS;
}

static void PopulateSpeciesFromTrainerParty(int matchCallId, u8 *destStr)
{
    u16 trainerId;
    union TrainerMonPtr party;
    u8 monId;
    const u8 *speciesName;

    trainerId = GetLastBeatenRematchTrainerId(sMatchCallTrainers[matchCallId].trainerId);
    party = gTrainers[trainerId].party;
    monId = Random() % gTrainers[trainerId].partySize;

    switch (gTrainers[trainerId].partyFlags)
    {
    case 0:
    default:
        speciesName = gSpeciesNames[party.NoItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET:
        speciesName = gSpeciesNames[party.NoItemCustomMoves[monId].species];
        break;
    case F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemDefaultMoves[monId].species];
        break;
    case F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM:
        speciesName = gSpeciesNames[party.ItemCustomMoves[monId].species];
        break;
    }

    StringCopy(destStr, speciesName);
}

static const u8 *const sBattleFrontierFacilityNames[NUM_FRONTIER_FACILITIES] =
{
    [FRONTIER_FACILITY_TOWER]   = gText_BattleTower2,
    [FRONTIER_FACILITY_DOME]    = gText_BattleDome,
    [FRONTIER_FACILITY_PALACE]  = gText_BattlePalace,
    [FRONTIER_FACILITY_ARENA]   = gText_BattleArena,
    [MATCH_CALL_PIKE]           = gText_BattlePike,
    [MATCH_CALL_FACTORY]        = gText_BattleFactory,
    [FRONTIER_FACILITY_PYRAMID] = gText_BattlePyramid,
};

static void PopulateBattleFrontierFacilityName(int matchCallId, u8 *destStr)
{
    StringCopy(destStr, sBattleFrontierFacilityNames[sBattleFrontierStreakInfo.facilityId]);
}

static void PopulateBattleFrontierStreak(int matchCallId, u8 *destStr)
{
    int i = 0;
    int streak = sBattleFrontierStreakInfo.streak;
    while (streak != 0)
    {
        streak /= 10;
        i++;
    }

    ConvertIntToDecimalStringN(destStr, sBattleFrontierStreakInfo.streak, STR_CONV_MODE_LEFT_ALIGN, i);
}

static const u16 sBadgeFlags[NUM_BADGES] =
{
    FLAG_BADGE01_GET,
    FLAG_BADGE02_GET,
    FLAG_BADGE03_GET,
    FLAG_BADGE04_GET,
    FLAG_BADGE05_GET,
    FLAG_BADGE06_GET,
    FLAG_BADGE07_GET,
    FLAG_BADGE08_GET,
};

static int GetNumOwnedBadges(void)
{
    u32 i;

    for (i = 0; i < NUM_BADGES; i++)
    {
        if (!FlagGet(sBadgeFlags[i]))
            break;
    }

    return i;
}

// Whether or not a trainer calling the player from a different route should request a battle
static bool32 ShouldTrainerRequestBattle(int matchCallId)
{
    int dayCount;
    int otId;
    u16 dewfordRand;
    int numRematchTrainersFought;
    int max, rand, n;

    if (GetNumOwnedBadges() < 5)
        return FALSE;

    dayCount = RtcGetLocalDayCount();
    otId = GetTrainerId(gSaveBlock2Ptr->playerTrainerId) & 0xFFFF;

    dewfordRand = gSaveBlock1Ptr->dewfordTrends[0].rand;
    numRematchTrainersFought = GetNumRematchTrainersFought();
    max = (numRematchTrainersFought * 13) / 10;
    rand = ((dayCount ^ dewfordRand) + (dewfordRand ^ GetGameStat(GAME_STAT_TRAINER_BATTLES))) ^ otId;
    n = rand % max;
    if (n < numRematchTrainersFought)
    {
        if (GetNthRematchTrainerFought(n) == matchCallId)
            return TRUE;
    }

    return FALSE;
}

static u16 GetFrontierStreakInfo(u16 facilityId, u32 *topicTextId)
{
    int i;
    int j;
    u16 streak = 0;

    switch (facilityId)
    {
    case FRONTIER_FACILITY_TOWER:
        for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.towerRecordWinStreaks); i++)
        {
            for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    case MATCH_CALL_FACTORY:
        for (i = 0; i < (int)ARRAY_COUNT(gSaveBlock2Ptr->frontier.factoryRecordWinStreaks); i++)
        {
            for (j = 0; j < FRONTIER_LVL_MODE_COUNT; j++)
            {
                if (streak < gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j])
                    streak = gSaveBlock2Ptr->frontier.factoryRecordWinStreaks[i][j];
            }
        }
        *topicTextId = GEN_TOPIC_STREAK_RECORD - 1;
        break;
    }

    return streak;
}

static u8 GetPokedexRatingLevel(u16 numSeen)
{
    if (numSeen < 10)
        return 0;
    if (numSeen < 20)
        return 1;
    if (numSeen < 30)
        return 2;
    if (numSeen < 40)
        return 3;
    if (numSeen < 50)
        return 4;
    if (numSeen < 60)
        return 5;
    if (numSeen < 70)
        return 6;
    if (numSeen < 80)
        return 7;
    if (numSeen < 90)
        return 8;
    if (numSeen < 100)
        return 9;
    if (numSeen < 110)
        return 10;
    if (numSeen < 120)
        return 11;
    if (numSeen < 130)
        return 12;
    if (numSeen < 140)
        return 13;
    if (numSeen < 150)
        return 14;
    if (numSeen < 151)
        return 15;
    else
        return 16;
}

static const u8 *const sOakDexRatingTexts[] =
{
    gOakDexRatingText_LessThan10,
    gOakDexRatingText_LessThan20,
    gOakDexRatingText_LessThan30,
    gOakDexRatingText_LessThan40,
    gOakDexRatingText_LessThan50,
    gOakDexRatingText_LessThan60,
    gOakDexRatingText_LessThan70,
    gOakDexRatingText_LessThan80,
    gOakDexRatingText_LessThan90,
    gOakDexRatingText_LessThan100,
    gOakDexRatingText_LessThan110,
    gOakDexRatingText_LessThan120,
    gOakDexRatingText_LessThan130,
    gOakDexRatingText_LessThan140,
    gOakDexRatingText_LessThan150,
    gOakDexRatingText_LessThan151,
    gOakDexRatingText_DexCompleted,
};

void BufferPokedexRatingForMatchCall(u8 *destStr)
{
    int numSeen, numCaught;
    u8 *str;
    u8 dexRatingLevel;

    u8 *buffer = Alloc(sizeof(gStringVar4));
    if (!buffer)
    {
        destStr[0] = EOS;
        return;
    }

    numSeen = GetHoennPokedexCount(FLAG_GET_SEEN);
    numCaught = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
    dexRatingLevel = GetPokedexRatingLevel(numCaught);
    str = StringCopy(buffer, gOakDexRatingText_AreYouCurious);
    *(str++) = CHAR_PROMPT_CLEAR;
    str = StringCopy(str, gOakDexRatingText_SoYouveSeenAndCaught);
    *(str++) = CHAR_PROMPT_CLEAR;
    StringCopy(str, sOakDexRatingTexts[dexRatingLevel]);
    str = StringExpandPlaceholders(destStr, buffer);

    if (IsNationalPokedexEnabled())
    {
        *(str++) = CHAR_PROMPT_CLEAR;
        numSeen = GetNationalPokedexCount(FLAG_GET_SEEN);
        numCaught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
        ConvertIntToDecimalStringN(gStringVar1, numSeen, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, numCaught, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringExpandPlaceholders(str, gOakDexRatingText_SoYouveSeenAndCaught);
    }

    Free(buffer);
}

void LoadMatchCallWindowGfx(u32 windowId, u32 destOffset, u32 paletteId)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    LoadBgTiles(bg, sMatchCallWindow_Gfx, 0x100, destOffset);
    LoadPalette(sMatchCallWindow_Pal, paletteId << 4, sizeof(sMatchCallWindow_Pal));
}

void DrawMatchCallTextBoxBorder(u32 windowId, u32 tileOffset, u32 paletteId)
{
    DrawMatchCallTextBoxBorder_Internal(windowId, tileOffset, paletteId);
}
