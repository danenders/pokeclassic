#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "constants/trainers.h"


// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_RIVAL,
    MC_TYPE_OAK,
    MC_TYPE_AIDE,
    MC_TYPE_LEADER
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u8 mapSec;
};

struct MatchCallRival {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *name;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallOak {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallAide {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallRival *rival;
    const struct MatchCallOak *oak;
    const struct MatchCallAide *aide;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCall_GetEnabled_NPC(match_call_t);
static bool32 MatchCall_GetEnabled_Trainer(match_call_t);
static bool32 MatchCall_GetEnabled_Rival(match_call_t);
static bool32 MatchCall_GetEnabled_Oak(match_call_t);
static bool32 MatchCall_GetEnabled_Aide(match_call_t);

static u8 MatchCall_GetMapSec_NPC(match_call_t);
static u8 MatchCall_GetMapSec_Trainer(match_call_t);
static u8 MatchCall_GetMapSec_Rival(match_call_t);
static u8 MatchCall_GetMapSec_Oak(match_call_t);
static u8 MatchCall_GetMapSec_Aide(match_call_t);

static bool32 MatchCall_IsRematchable_NPC(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer(match_call_t);
static bool32 MatchCall_IsRematchable_Rival(match_call_t);
static bool32 MatchCall_IsRematchable_Oak(match_call_t);
static bool32 MatchCall_IsRematchable_Aide(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival(match_call_t);
static bool32 MatchCall_HasCheckPage_Oak(match_call_t);
static bool32 MatchCall_HasCheckPage_Aide(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Oak(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Aide(match_call_t);

static void MatchCall_GetMessage_NPC(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival(match_call_t, u8 *);
static void MatchCall_GetMessage_Oak(match_call_t, u8 *);
static void MatchCall_GetMessage_Aide(match_call_t, u8 *);

static void MatchCall_GetNameAndDesc_NPC(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Oak(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Aide(match_call_t, const u8 **, const u8 **);

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

// .rodata

//Updated

//OAK
static const struct MatchCallOak sProfOakMatchCallHeader =
{
    .type = MC_TYPE_OAK,
    .mapSec = MAPSEC_PALLET_TOWN,
    .flag = FLAG_REGISTERED_PROF_OAK,
    .desc = gText_ProfOakMatchCallDesc,
    .name = gText_ProfOakMatchCallName
};

//MOM
static const match_call_text_data_t sMomTextScripts[] = {
    { MatchCall_Text_Mom1,  0xFFFF,                         0xFFFF },
    { MatchCall_Text_Mom2,  FLAG_VISITED_CERULEAN_CITY,     0xFFFF },
    { MatchCall_Text_Mom3,  FLAG_VISITED_VERMILION_CITY,    0xFFFF },
    { MatchCall_Text_Mom4,  FLAG_VISITED_LAVENDER_TOWN,     0xFFFF },
    { MatchCall_Text_Mom5,  FLAG_VISITED_CELADON_CITY,      0xFFFF },
    { MatchCall_Text_Mom6,  FLAG_VISITED_FUCHSIA_CITY,      0xFFFF },
    { MatchCall_Text_Mom7,  FLAG_VISITED_SAFFRON_CITY,      0xFFFF },
    { MatchCall_Text_Mom8,  FLAG_VISITED_CINNABAR_ISLAND,   0xFFFF },
    { MatchCall_Text_Mom9,  FLAG_BADGE07_GET,   0xFFFF },    
    { MatchCall_Text_MomGameClear, FLAG_SYS_GAME_CLEAR,     0xFFFF },
    { NULL,                 0xFFFF,                         0xFFFF }
};

static const struct MatchCallStructNPC sMomMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_PALLET_TOWN,
    .flag = 0xFFFF,
    .desc = gText_MomMatchCallDesc,
    .name = gText_MomMatchCallName,
    .textData = sMomTextScripts
};

//RIVAL
static const match_call_text_data_t sRivalTextScripts[] = {
    { MatchCall_Text_Rival1,  0xFFFF,                      0xFFFF },
    { MatchCall_Text_Rival2,  FLAG_BADGE01_GET,            0xFFFF },
    { MatchCall_Text_Rival3,  FLAG_BADGE02_GET,            0xFFFF },
    { MatchCall_Text_Rival4,  FLAG_BADGE03_GET,            0xFFFF },
    { MatchCall_Text_Rival5,  FLAG_BADGE04_GET,            0xFFFF },
    { MatchCall_Text_Rival6,  FLAG_BADGE05_GET,            0xFFFF },
    { MatchCall_Text_Rival7,  FLAG_BADGE06_GET,            0xFFFF },
    { MatchCall_Text_Rival8,  FLAG_BADGE07_GET,            0xFFFF },
    { MatchCall_Text_Rival9,  FLAG_BADGE08_GET,            0xFFFF },
    { MatchCall_Text_RivalGameClear, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { NULL,                 0xFFFF,                        0xFFFF }
};

static const struct MatchCallLocationOverride sRivalLocationData[] = {
    { FLAG_REGISTERED_RIVAL, MAPSEC_ROUTE_22 },
    { FLAG_BADGE01_GET, MAPSEC_CERULEAN_CITY },
    { FLAG_BADGE02_GET, MAPSEC_VERMILION_CITY },
    { FLAG_BADGE03_GET, MAPSEC_LAVENDER_TOWN },
    { FLAG_BADGE04_GET, MAPSEC_SAFFRON_CITY },
    { FLAG_HIDE_SILPH_RIVAL, MAPSEC_INDIGO_PLATEAU },
    { FLAG_SYS_GAME_CLEAR, MAPSEC_VIRIDIAN_CITY},
    { 0xFFFF, MAPSEC_NONE }
};

static const struct MatchCallRival sRivalMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .mapSec = 0,
    .flag = FLAG_REGISTERED_RIVAL,
    .desc = gText_RivalMatchCallDesc,
    .textData = sRivalTextScripts,
    .locationData = sRivalLocationData
};

//AIDE
static const match_call_text_data_t sAideTextScripts[] = {
    { MatchCall_Text_AideWatchingProgress,      0xFFFF,      FLAG_REGISTERED_AIDE },
    { MatchCall_Text_AideOnMyWayRoute2,   FLAG_AIDE_LOCATION_1,      0xFFFF },
    { MatchCall_Text_AideOnMyWayRoute10,  FLAG_AIDE_LOCATION_2,      0xFFFF },
    { MatchCall_Text_AideOnMyWayRoute11,  FLAG_AIDE_LOCATION_3,      0xFFFF },
    { MatchCall_Text_AideOnMyWayRoute16,  FLAG_AIDE_LOCATION_4,      0xFFFF },
    { MatchCall_Text_AideOnMyWayRoute15,  FLAG_AIDE_LOCATION_5,      0xFFFF },
    { MatchCall_Text_AideGameClear,       FLAG_SYS_GAME_CLEAR,       0xFFFF },
    { NULL,                               0xFFFF,                    0xFFFF }
};

static const struct MatchCallLocationOverride sAideLocationData[] = {
    { FLAG_AIDE_LOCATION_1, MAPSEC_ROUTE_2  },
    { FLAG_AIDE_LOCATION_2, MAPSEC_ROUTE_10 },
    { FLAG_AIDE_LOCATION_3, MAPSEC_ROUTE_11 },
    { FLAG_AIDE_LOCATION_4, MAPSEC_ROUTE_16 },
    { FLAG_AIDE_LOCATION_5, MAPSEC_ROUTE_15 },
    { 0xFFFF, MAPSEC_PALLET_TOWN }
};

static const struct MatchCallAide sAideMatchCallHeader =
{
    .type = MC_TYPE_AIDE,
    .mapSec = 0,
    .flag = FLAG_REGISTERED_AIDE,
    .desc = gText_AideMatchCallDesc,
    .name = gText_AideMatchCallName,
    .textData = sAideTextScripts,
    .locationData = sAideLocationData
};

//SCOTT
static const match_call_text_data_t sScottTextScripts[] = {
    { MatchCall_Text_ScottBusy,         0xFFFF,                         0xFFFF },
    { MatchCall_Text_ScottCerulean,     FLAG_VISITED_CERULEAN_CITY,     0xFFFF },
    { MatchCall_Text_ScottGotBadge2,    FLAG_BADGE02_GET,               0xFFFF },
    { MatchCall_Text_ScottVermilion,    FLAG_VISITED_VERMILION_CITY,    0xFFFF },
    { MatchCall_Text_ScottGotBadge3,    FLAG_BADGE03_GET,               0xFFFF },
    { MatchCall_Text_ScottCeladon,      FLAG_VISITED_CELADON_CITY,      0xFFFF },
    { MatchCall_Text_ScottGotBadge4,    FLAG_BADGE04_GET,               0xFFFF },
    { MatchCall_Text_ScottSaffron,      FLAG_VISITED_SAFFRON_CITY,      0xFFFF },
    { MatchCall_Text_ScottGotBadge5,    FLAG_BADGE05_GET,               0xFFFF },
    { MatchCall_Text_ScottFuchsia,      FLAG_VISITED_FUCHSIA_CITY,      0xFFFF },
    { MatchCall_Text_ScottGotBadge6,    FLAG_BADGE06_GET,               0xFFFF },
    { MatchCall_Text_ScottCinnabar,     FLAG_VISITED_CINNABAR_ISLAND,   0xFFFF },
    { MatchCall_Text_ScottGotBadge7,    FLAG_BADGE07_GET,               0xFFFF },
    { MatchCall_Text_ScottFinalBadge,   FLAG_GOT_SEVEN_BADGES,          0xFFFF },
    { MatchCall_Text_ScottPkmnLeague,   FLAG_BADGE08_GET,               0xFFFF },
    { MatchCall_Text_ScottThisIsIt,     FLAG_VISITED_INDIGO_PLATEAU,    0xFFFF },
    { MatchCall_Text_ScottBattleTower,  FLAG_SYS_GAME_CLEAR,            0xFFFF },
    { MatchCall_Text_ScottBattleTower2, FLAG_SYS_FRONTIER_PASS,         0xFFFF },
    { NULL,                  0xFFFF,                                    0xFFFF }
};

static const struct MatchCallLocationOverride sScottLocationData[] = {
    { FLAG_BADGE01_GET,             MAPSEC_CERULEAN_CITY  },
    { FLAG_BADGE02_GET,             MAPSEC_VERMILION_CITY },
    { FLAG_BADGE03_GET,             MAPSEC_CELADON_CITY },
    { FLAG_BADGE04_GET,             MAPSEC_SAFFRON_CITY },
    { FLAG_BADGE05_GET,             MAPSEC_FUCHSIA_CITY },
    { FLAG_BADGE06_GET,             MAPSEC_CINNABAR_ISLAND },
    { FLAG_GOT_SEVEN_BADGES,        MAPSEC_VIRIDIAN_CITY },
    { FLAG_BADGE08_GET,             MAPSEC_INDIGO_PLATEAU },
    { FLAG_SYS_GAME_CLEAR,          MAPSEC_BATTLE_FRONTIER },
    { 0xFFFF,                       MAPSEC_NONE }
};

static const struct MatchCallAide sScottMatchCallHeader =
{
    .type = MC_TYPE_AIDE,
    .mapSec = 0,
    .flag = FLAG_REGISTERED_SCOTT,
    .desc = gText_ScottMatchCallDesc,
    .name = gText_ScottMatchCallName,
    .textData = sScottTextScripts,
    .locationData = sScottLocationData
};

//LOOKER
static const match_call_text_data_t sLookerTextScripts[] = {
    { MatchCall_Text_LookerIntro,               0xFFFF,                             0xFFFF },
    { MatchCall_Text_LookerCeladon,             FLAG_GOT_SS_TICKET,                 0xFFFF },
    { MatchCall_Text_LookerRocketHideout,       FLAG_HIDE_CELADON_ROCKETS,          0xFFFF },
    { MatchCall_Text_LookerSaffron,             FLAG_DELIVERED_ROCKET_PLANS,        0xFFFF },
    { MatchCall_Text_LookerSilphCo,             FLAG_HIDE_SAFFRON_ROCKETS,          0xFFFF },
    { MatchCall_Text_LookerGiovanni,            FLAG_BADGE08_GET,                   0xFFFF },
    { MatchCall_Text_LookerPostgameWaiting,     FLAG_LOOKER_POSTGAME_STARTED,       0xFFFF },
    { MatchCall_Text_LookerPostgameCompleted,   FLAG_LOOKER_POSTGAME_COMPLETED,     0xFFFF },
    { NULL,                     0xFFFF,                         0xFFFF }
};

static const struct MatchCallLocationOverride sLookerLocationData[] = {
    { FLAG_REGISTERED_LOOKER,       MAPSEC_CERULEAN_CITY  },
    { 0xFFFF,                       MAPSEC_NONE }
};

static const struct MatchCallAide sLookerMatchCallHeader =
{
    .type = MC_TYPE_AIDE,
    .mapSec = 0,
    .flag = FLAG_REGISTERED_LOOKER,
    .desc = gText_LookerMatchCallDesc,
    .name = gText_LookerMatchCallName,
    .textData = sLookerTextScripts,
    .locationData = sLookerLocationData
};

//BILL
static const match_call_text_data_t sBillTextScripts[] = {
    { MatchCall_Text_Bill1,  0xFFFF,                      0xFFFF },
    { MatchCall_Text_Bill2,  FLAG_BADGE05_GET,            0xFFFF },
    { MatchCall_Text_Bill3,  FLAG_SYS_DEXNAV_GET,         0xFFFF },
    { MatchCall_Text_Bill4,  FLAG_BADGE08_GET,            FLAG_GAVE_BILL_IDEA},
    { MatchCall_Text_Bill5,  FLAG_SYS_DETECTOR_MODE,      0xFFFF },
    { MatchCall_Text_Bill6,  FLAG_SYS_GAME_CLEAR,         0xFFFF },
    { NULL,                  0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sBillMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_ROUTE_25,
    .flag = FLAG_REGISTERED_BILL,
    .desc = gText_BillMatchCallDesc,
    .name = gText_BillMatchCallName,
    .textData = sBillTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    [MC_HEADER_MOM]        = {.npc    = &sMomMatchCallHeader},
    [MC_HEADER_PROF_OAK]   = {.oak    = &sProfOakMatchCallHeader},
    [MC_HEADER_RIVAL]      = {.rival  = &sRivalMatchCallHeader},
    [MC_HEADER_AIDE]       = {.aide   = &sAideMatchCallHeader},
    [MC_HEADER_SCOTT]      = {.aide   = &sScottMatchCallHeader},
    [MC_HEADER_LOOKER]     = {.aide   = &sLookerMatchCallHeader},
    [MC_HEADER_BILL]       = {.npc    = &sBillMatchCallHeader},
};

static bool32 (*const sMatchCallGetEnabledFuncs[])(match_call_t) = {
    MatchCall_GetEnabled_NPC,
    MatchCall_GetEnabled_Trainer,
    MatchCall_GetEnabled_Rival,
    MatchCall_GetEnabled_Aide,
    MatchCall_GetEnabled_Oak
};

static u8 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCall_GetMapSec_NPC,
    MatchCall_GetMapSec_Trainer,
    MatchCall_GetMapSec_Rival,
    MatchCall_GetMapSec_Aide,
    MatchCall_GetMapSec_Oak
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_NPC,
    MatchCall_IsRematchable_Trainer,
    MatchCall_IsRematchable_Rival,
    MatchCall_IsRematchable_Aide,
    MatchCall_IsRematchable_Oak
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_NPC,
    MatchCall_HasCheckPage_Trainer,
    MatchCall_HasCheckPage_Rival,
    MatchCall_HasCheckPage_Aide,
    MatchCall_HasCheckPage_Oak
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_NPC,
    MatchCall_GetRematchTableIdx_Trainer,
    MatchCall_GetRematchTableIdx_Rival,
    MatchCall_GetRematchTableIdx_Aide,
    MatchCall_GetRematchTableIdx_Oak
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_NPC,
    MatchCall_GetMessage_Trainer,
    MatchCall_GetMessage_Rival,
    MatchCall_GetMessage_Aide,
    MatchCall_GetMessage_Oak
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_NPC,
    MatchCall_GetNameAndDesc_Trainer,
    MatchCall_GetNameAndDesc_Rival,
    MatchCall_GetNameAndDesc_Aide,
    MatchCall_GetNameAndDesc_Oak
};

static const struct MatchCallCheckPageOverride sCheckPageOverrides[] = {
    {
        .idx = MC_HEADER_RIVAL,
        .facilityClass = FACILITY_CLASS_BLUE,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallRival_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallRival_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallRival_Intro1,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallRival_Intro2
        }
    },
    {
        .idx = MC_HEADER_PROF_OAK,
        .facilityClass = FACILITY_CLASS_OAK,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallOak_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallOak_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallOak_Intro1,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallOak_Intro2
        }
    },
    {
        .idx = MC_HEADER_SCOTT,
        .facilityClass = FACILITY_CLASS_SCOTT,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallScott_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallScott_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallScott_Intro1,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallScott_Intro2
        }
    },
    {
        .idx = MC_HEADER_LOOKER,
        .facilityClass = FACILITY_CLASS_LOOKER,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallLooker_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallLooker_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallLooker_Intro1,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallLooker_Intro2
        }
    },
    {
        .idx = MC_HEADER_BILL,
        .facilityClass = FACILITY_CLASS_BILL,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallBill_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallBill_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallBill_Intro1,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallBill_Intro2
        }
    }
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_RIVAL:
            return 2;
        case MC_TYPE_AIDE:
            return 3;
        case MC_TYPE_OAK:
            return 4;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetEnabledFuncs[i](matchCall);
}

static bool32 MatchCall_GetEnabled_NPC(match_call_t matchCall)
{
    if (matchCall.npc->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}

static bool32 MatchCall_GetEnabled_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}

static bool32 MatchCall_GetEnabled_Rival(match_call_t matchCall)
{
    if (matchCall.rival->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}

static bool32 MatchCall_GetEnabled_Aide(match_call_t matchCall)
{
    if (matchCall.aide->flag == 0xFFFF)
        return TRUE;
    return FlagGet(matchCall.aide->flag);
}

static bool32 MatchCall_GetEnabled_Oak(match_call_t matchCall)
{
    return FlagGet(matchCall.oak->flag);
}

u8 MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u8 MatchCall_GetMapSec_NPC(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}

static u8 MatchCall_GetMapSec_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}

static u8 MatchCall_GetMapSec_Rival(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.rival->locationData[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.rival->locationData[i].flag))
            break;
    }
    return matchCall.rival->locationData[i].mapSec;
}

static u8 MatchCall_GetMapSec_Aide(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.aide->locationData[i].flag != 0xFFFF; i++)
    {
        if (!FlagGet(matchCall.aide->locationData[i].flag))
            break;
    }
    return matchCall.aide->locationData[i].mapSec;
}

static u8 MatchCall_GetMapSec_Oak(match_call_t matchCall)
{
    return MAPSEC_PALLET_TOWN;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Trainer(match_call_t matchCall)
{
    #ifndef FREE_MATCH_CALL
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
    #else
    return FALSE;
    #endif
}

static bool32 MatchCall_IsRematchable_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Aide(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Oak(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Trainer(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Rival(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Aide(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Oak(match_call_t matchCall)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Aide(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Oak(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_NPC(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.npc->textData, dest);
}

// This is the one functional difference between MC_TYPE_TRAINER and MC_TYPE_LEADER
static void MatchCall_GetMessage_Trainer(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != MC_TYPE_LEADER)
        MatchCall_BufferCallMessageText(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Rival(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.rival->textData, dest);
}

static void MatchCall_GetMessage_Aide(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.aide->textData, dest);
}

static void MatchCall_GetMessage_Oak(match_call_t matchCall, u8 *dest)
{
    BufferPokedexRatingForMatchCall(dest);
}

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
        ;
    if (i)
        i--;
    while (i)
    {
        if (textData[i].flag != 0xFFFF && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    if (textData[i].flag2 != 0xFFFF)
        FlagSet(textData[i].flag2);
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
    #ifndef FREE_MATCH_CALL
    u32 i;
    for (i = 0; textData[i].text != NULL; i++)
    {
        if (textData[i].flag == 0xFFFE)
            break;
        if (textData[i].flag != 0xFFFF && !FlagGet(textData[i].flag))
            break;
    }
    if (textData[i].flag != 0xFFFE)
    {
        if (i)
            i--;
        if (textData[i].flag2 != 0xFFFF)
            FlagSet(textData[i].flag2);
        StringExpandPlaceholders(dest, textData[i].text);
    }
    else
    {
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do
            {
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                else
                    i++;
            } while (0);
        }

        StringExpandPlaceholders(dest, textData[i].text);
    }
    #endif
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx >= ARRAY_COUNT(sMatchCallHeaders))
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_NPC(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}

static void MatchCall_GetNameAndDesc_Trainer(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}

static void MatchCall_GetNameAndDesc_Rival(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = gSaveBlock2Ptr->rivalName;
}

static void MatchCall_GetNameAndDesc_Aide(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.aide->desc;
    *name = matchCall.aide->name;
}

static void MatchCall_GetNameAndDesc_Oak(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.oak->desc;
    *name = matchCall.oak->name;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
        {
            for (; i + 1 < ARRAY_COUNT(sCheckPageOverrides) &&
                sCheckPageOverrides[i + 1].idx == idx &&
                FlagGet(sCheckPageOverrides[i + 1].flag); i++);
            return sCheckPageOverrides[i].flavorTexts[offset];
        }
    }
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return sCheckPageOverrides[i].facilityClass;
    }
    return -1;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 id = MatchCall_GetRematchTableIdx(i);
        if (id != REMATCH_TABLE_ENTRIES && id == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
