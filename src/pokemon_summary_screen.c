#include "global.h"
#include "main.h"
#include "battle.h"
#include "battle_anim.h"
#include "frontier_util.h"
#include "battle_message.h"
#include "battle_tent.h"
#include "battle_factory.h"
#include "bg.h"
#include "contest.h"
#include "contest_effect.h"
#include "data.h"
#include "daycare.h"
#include "decompress.h"
#include "dynamic_placeholder_text_util.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "m4a.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "mon_markings.h"
#include "party_menu.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "region_map.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "tv.h"
#include "window.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/region_map_sections.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "item_icon.h"
#include "pokemon_icon.h"
#include "constants/flags.h"
#include "battle_interface.h"

// Config options - Note that some config options need external modifications to fully work, such as CONFIG_CAN_FORGET_HM_MOVES, CONFIG_PHYSICAL_SPECIAL_SPLIT, and CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
#define CONFIG_CAN_FORGET_HM_MOVES                      TRUE
#define CONFIG_CAN_SWITCH_PAGES_WHILE_DETAILS_ARE_UP    TRUE
#define CONFIG_PHYSICAL_SPECIAL_SPLIT                   FALSE   // Takes precendence over CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
#define CONFIG_SHOW_ICONS_FOR_OLD_SPLIT                 FALSE
#define CONFIG_EXPANDED_MET_LOCATIONS                   TRUE
#define CONFIG_TRUST_OUTSIDERS                          TRUE
#define CONFIG_SHOW_HIDDEN_POWER_STATS                  TRUE
#define CONFIG_DECAPITALIZE_TITLE_STRINGS               FALSE
#define CONFIG_DECAPITALIZE_MENU_STRINGS                TRUE
#define CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS        FALSE
#define CONFIG_FATEFUL_ENCOUNTER_MARK                   TRUE
// Make sure gBallIconTable in src/data/item_icon_table.h is ordered correctly.  Default does not match RHH

enum {
    PSS_PAGE_INFO,
    PSS_PAGE_MEMO,
    PSS_PAGE_SKILLS,
    PSS_PAGE_BATTLE_MOVES,
    //PSS_PAGE_CONDITION,       moved temporarily
    PSS_PAGE_CONTEST_MOVES,
    PSS_PAGE_CONDITION,
    PSS_PAGE_COUNT,
};

enum {
    PP_FEW,
    PP_SOME,
    PP_NO_PP,
    PP_MANY
};

// Text Windows
#define PSS_LABEL_PANE_LEFT_TOP                     0
#define PSS_LABEL_PANE_LEFT_BOTTOM                  (PSS_LABEL_PANE_LEFT_TOP + 1)
#define PSS_LABEL_PANE_LEFT_MOVE                    (PSS_LABEL_PANE_LEFT_BOTTOM + 1)
#define PSS_LABEL_PANE_RIGHT                        (PSS_LABEL_PANE_LEFT_MOVE + 1)
#define PSS_LABEL_PANE_RIGHT_HP                     (PSS_LABEL_PANE_RIGHT + 1)
#define PSS_LABEL_PANE_RIGHT_SMALL                  (PSS_LABEL_PANE_RIGHT_HP + 1)
#define PSS_LABEL_PANE_RIGHT_BOTTOM                 (PSS_LABEL_PANE_RIGHT_SMALL + 1)
#define PSS_LABEL_PANE_TITLE                        (PSS_LABEL_PANE_RIGHT_BOTTOM + 1)

#define PSS_LABEL_WINDOW_END                        (PSS_LABEL_PANE_TITLE + 1)

#define MOVE_SELECTOR_SPRITES_COUNT 4
#define HP_BAR_SPRITES_COUNT        11
#define EXP_BAR_SPRITES_COUNT       11

// for the spriteIds field in PokemonSummaryScreenData
enum
{
    SPRITE_ARR_ID_MON,
    SPRITE_ARR_ID_BALL,
    SPRITE_ARR_ID_ITEM,
    SPRITE_ARR_ID_MON_ICON,
    SPRITE_ARR_ID_STATUS,
    SPRITE_ARR_ID_ORIGIN,
    SPRITE_ARR_ID_TYPE, // 2 for mon types, 5 for move types(4 moves and 1 to learn)
    SPRITE_ARR_ID_MOVE_SELECTOR1 = SPRITE_ARR_ID_TYPE + 7,
    SPRITE_ARR_ID_MOVE_SELECTOR2 = SPRITE_ARR_ID_MOVE_SELECTOR1 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_SPLIT = SPRITE_ARR_ID_MOVE_SELECTOR2 + MOVE_SELECTOR_SPRITES_COUNT,
    SPRITE_ARR_ID_COUNT = SPRITE_ARR_ID_SPLIT + 1
};

#define TILE_EMPTY_HEART  109
#define TILE_FILLED_APPEAL_HEART 108
#define TILE_FILLED_JAM_HEART    4

#define POWER_AND_ACCURACY_Y    33
#define POWER_AND_ACCURACY_Y_2  POWER_AND_ACCURACY_Y + 16

static EWRAM_DATA struct PokemonSummaryScreenData
{
    /*0x00*/ union {
        struct Pokemon *mons;
        struct BoxPokemon *boxMons;
    } monList;
    /*0x04*/ MainCallback callback;
    /*0x08*/ struct Sprite *markingsSprite;
    /*0x0C*/ struct Pokemon currentMon;
    /*0x70*/ struct PokeSummary
    {
        u16 species;
        u16 species2;
        u8 isEgg;
        u8 level;
        u8 ribbonCount;
        u8 ailment;
        u8 abilityNum;
        u8 metLocation;
        u8 metLevel;
        u8 metGame;
        u32 pid;
        u32 exp;
        u16 moves[MAX_MON_MOVES];
        u8 pp[MAX_MON_MOVES];
        u16 currentHP;
        u16 maxHP;
        u16 atk;
        u16 def;
        u16 spatk;
        u16 spdef;
        u16 speed;
        u16 item;
        u8 friendship;
        u8 OTGender;
        u8 nature;
        u8 ppBonuses;
        u8 sanity;
        bool8 fatefulEncounter;
        u8 OTName[17];
        u32 OTID;
        u8 sheen;
        u8 cool;
        u8 beauty;
        u8 cute;
        u8 smart;
        u8 tough;
        u8 hpIV;
        u8 atkIV;
        u8 defIV;
        u8 spatkIV;
        u8 spdefIV;
        u8 speedIV;
        u8 hpEV;
        u8 atkEV;
        u8 defEV;
        u8 spatkEV;
        u8 spdefEV;
        u8 speedEV;
    } summary;
    u16 bgTilemapBufferPage[0x400];
    u16 bgTilemapBufferBG[0x400];
    u16 moveDetailTilemapBuffer[0x800];
    u8 mode;
    bool8 isBoxMon;
    u8 curMonIndex;
    u8 maxMonIndex;
    u8 currPageIndex;
    u8 minPageIndex;
    u8 maxPageIndex;
    u8 trueMinPageIndex;
    u8 trueMaxPageIndex;
    u8 currStatIndex;
    bool8 lockMonFlag; // This is used to prevent the player from changing pokemon in the move deleter select, etc, but it is not needed because the input is handled differently there
    bool8 lockMovesFlag; // This is used to prevent the player from changing position of moves in a battle or when trading.
    u8 firstMoveIndex;
    u8 secondMoveIndex;
    u16 newMove;
    u8 windowIds[PSS_LABEL_WINDOW_END - 1];
    u8 spriteIds[SPRITE_ARR_ID_COUNT];
    bool8 unk40EF;
    s16 switchCounter; // Used for various switch statement cases that decompress/load graphics or pokemon data
} *sMonSummaryScreen = NULL;
EWRAM_DATA u8 gLastViewedMonIndex = 0;
static EWRAM_DATA u8 sMoveSlotToReplace = 0;
ALIGNED(4) static EWRAM_DATA u8 sAnimDelayTaskId = 0;

static EWRAM_DATA struct HealthBar
{
    struct Sprite * sprites[HP_BAR_SPRITES_COUNT];
    u16 spritePositions[HP_BAR_SPRITES_COUNT];
    u16 tileTag;
    u16 palTag;
} *sHealthBar = NULL;

static EWRAM_DATA struct ExpBar
{
    struct Sprite * sprites[EXP_BAR_SPRITES_COUNT];
    u16 spritePositions[EXP_BAR_SPRITES_COUNT];
    u16 tileTag;
    u16 palTag;
} *sExpBar = NULL;

// forward declarations
static bool8 LoadGraphics(void);
static void CB2_InitSummaryScreen(void);
static void InitBGs(void);
static bool8 DecompressGraphics(void);
static void CopyMonToSummaryStruct(struct Pokemon* a);
static bool8 ExtractMonDataToSummaryStruct(struct Pokemon* a);
static void CloseSummaryScreen(u8 taskId);
static void Task_HandleInput(u8 taskId);
static void ChangeStatTask(u8 taskId);
static void ChangeSummaryPokemon(u8 taskId, s8 a);
static void Task_ChangeSummaryMon(u8 taskId);
static s8 AdvanceMonIndex(s8 delta);
static s8 AdvanceMultiBattleMonIndex(s8 delta);
static bool8 IsValidToViewInMulti(struct Pokemon* mon);
static void ChangePage(u8 taskId, s8 a);
static void ChangePageTask(u8 taskId);
static void SwitchToMoveSelection(u8 taskId);
static void Task_SwitchToMoveDetails(u8 taskId);
static void Task_HandleInput_MoveSelect(u8 taskId);
static void Task_SwitchPageInMoveSelect(u8 taskId);
static bool8 HasMoreThanOneMove(void);
static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr);
static void CloseMoveSelectMode(u8 taskId);
static void Task_SwitchFromMoveDetails(u8 taskId);
static void SwitchToMovePositionSwitchMode(u8 a);
static void Task_HandleInput_MovePositionSwitch(u8 taskId);
static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves);
static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2);
static void Task_SetHandleReplaceMoveInput(u8 taskId);
static void Task_HandleReplaceMoveInput(u8 taskId);
static void Task_SwitchPageInReplaceMove(u8 taskId);
static void Task_ConfirmHMCantForget(u8 taskId);
static bool8 CanReplaceMove(void);
static void ShowCantForgetHMsWindow(u8 taskId);
static void ResetWindows(void);
static void PrintMonInfo(void);
static void PrintNotEggInfo(void);
static void PrintEggInfo(void);
static void PutPageWindowTilemaps(u8 a);
static void RemoveWindowByIndex(u8 a);
static void PrintPageSpecificText(u8 a);
static void PrintInfoPage(void);
static void PrintMemoPage(void);
static void BufferMonTrainerMemo(void);
static void BufferNatureString(void);
static void BufferCharacteristicString(void);
static void GetMetLevelString(u8 *a);
static bool8 DoesMonOTMatchOwner(void);
static bool8 DidMonComeFromGBAGames(void);
static bool8 DidMonComeFromRSE(void);
static bool8 DidMonComeFromFRLG(void);
static bool8 DidMonComeFromCD(void);
static bool8 DidMonComeFromDPPt(void);
static bool8 IsInGamePartnerMon(void);
static void PrintEggOTID(void);
static void BufferEggState(void);
static void BufferEggMemo(void);
static void PrintSkillsPage(void);
static void PrintConditionPage(void);
static void PrintBattleMoves(void);
static void PrintMoveNameAndPP(u8 a);
static void PrintContestMoves(void);
static void PrintMoveDetails(u16 a);
static void PrintNewMoveDetailsOrCancelText(void);
static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2);
static void ResetSpriteIds(void);
static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible);
static void HidePageSpecificSprites(void);
static void SetTypeIcons(void);
static void CreateMoveTypeIcons(void);
static void SetMonTypeIcons(void);
static void SetMoveTypeIcons(void);
static void SetContestMoveTypeIcons(void);
static void SetNewMoveTypeIcon(void);
static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2);
static u8 LoadMonGfxAndSprite(struct Pokemon *a, s16 *b);
static u8 CreateMonSprite(struct Pokemon *unused);
static void SpriteCB_Pokemon(struct Sprite *);
static void StopPokemonAnimations(void);
static void CreateMonMarkingsSprite(struct Pokemon *mon);
static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon);
static void CreateCaughtBallSprite(struct Pokemon *mon);
static void CreateHeldItemSprite(struct Pokemon *mon);
static void CreateSetStatusSprite(void);
static void CreateMoveSelectorSprites(u8 idArrayStart);
static void SpriteCb_MoveSelector(struct Sprite *sprite);
static void DestroyMoveSelectorSprites(u8 firstArrayId);
static void SetMainMoveSelectorColor(u8 whichColor);
static void KeepMoveSelectorVisible(u8 firstSpriteId);
static void SummaryScreen_DestroyAnimDelayTask(void);
static void CreateHealthBarSprites(u16 tileTag, u16 palTag);
static void ConfigureHealthBarSprites(void);
static void DestroyHealthBarSprites(void);
static void SetHealthBarSprites(void);
static void CreateExpBarSprites(u16 tileTag, u16 palTag);
static void ConfigureExpBarSprites(void);
static void DestroyExpBarSprites(void);
static void SetExpBarSprites(void);
static void PrintInfoBar(u8 pageIndex, bool8 detailsShown);
static u8 WhatRegionWasMonCaughtIn(struct Pokemon *mon);
static u8 *GetMapNameHoennKanto(u8 *dest, u16 mapSecId);
static u8 *GetMapNameOrre(u8 *dest, u16 mapSecId, bool8 isXD);

// const rom data
#include "data/text/move_descriptions.h"
#include "data/text/nature_names.h"
#include "data/text/characteristics.h"
#include "data/text/met_locations.h"

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 27,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 25,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};

static const struct WindowTemplate sSummaryTemplate[] =
{
    [PSS_LABEL_PANE_LEFT_TOP] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 10,
        .height = 4,
        .paletteNum = 2,
        .baseBlock = 1,
    },
    [PSS_LABEL_PANE_LEFT_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 16,
        .width = 8,
        .height = 5,
        .paletteNum = 2,
        .baseBlock = 44,
    },
    [PSS_LABEL_PANE_LEFT_MOVE] = {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 4,
        .width = 14,
        .height = 16,
        .paletteNum = 2,
        .baseBlock = 418,
    },
    [PSS_LABEL_PANE_RIGHT] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 2,
        .width = 19,
        .height = 18,
        .paletteNum = 2,
        .baseBlock = 76,
    },
    [PSS_LABEL_PANE_RIGHT_HP] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 2,
        .width = 19,
        .height = 3,
        .paletteNum = 2,
        .baseBlock = 76,
    },
    [PSS_LABEL_PANE_RIGHT_SMALL] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 5,
        .width = 19,
        .height = 15,
        .paletteNum = 2,
        .baseBlock = 152,
    },
    [PSS_LABEL_PANE_RIGHT_BOTTOM] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 15,
        .width = 19,
        .height = 6,
        .paletteNum = 2,
        .baseBlock = 684,
    },
    [PSS_LABEL_PANE_TITLE] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 0,
        .width = 19,
        .height = 2,
        .paletteNum = 2,
        .baseBlock = 644,
    },
    [PSS_LABEL_WINDOW_END] = DUMMY_WIN_TEMPLATE
};

enum
{
    PSS_COLOR_BLACK_GRAY_SHADOW,
    PSS_COLOR_WHITE_BLACK_SHADOW,
    PSS_COLOR_MALE_GENDER_SYMBOL,
    PSS_COLOR_FEMALE_GENDER_SYMBOL,
    PSS_COLOR_SHINY_STARS,
    PSS_COLOR_POKERUS_CURED,
    PSS_COLOR_FATEFUL_TRIANGLE,
    PP_UNK_1,
    PP_UNK_2,
    PP_UNK_3,
    PP_UNK_4,
    PP_UNK_5,
    PP_UNK_6,
    PSS_COLOR_ORANGE,
    PSS_COLOR_LIGHT_RED
};

static const u8 sTextColors[][3] =
{
    [PSS_COLOR_BLACK_GRAY_SHADOW]       = {0, 7, 8},
    [PSS_COLOR_WHITE_BLACK_SHADOW]      = {0, 1, 2},
    [PSS_COLOR_MALE_GENDER_SYMBOL]      = {0, 3, 4},
    [PSS_COLOR_FEMALE_GENDER_SYMBOL]    = {0, 5, 6},
    [PSS_COLOR_SHINY_STARS]             = {0, 5, 5},
    [PSS_COLOR_POKERUS_CURED]           = {0, 9, 9},
    [PSS_COLOR_FATEFUL_TRIANGLE]       = {0, 10, 10},
    /* Probably left from Pokémon Polar,
    check if they are actually needed so
    we can remove them if unused */
    [PP_UNK_1]                          = {0, 10, 9},
    [PP_UNK_2]                          = {13, 15, 14},
    [PP_UNK_3]                          = {0, 6, 5},
    [PP_UNK_4]                          = {0, 6, 2},
    [PP_UNK_5]                          = {0, 5, 6},
    [PP_UNK_6]                          = {0, 7, 8},
    // Used for PP text
    [PSS_COLOR_ORANGE]                  = {0, 11, 12},
    [PSS_COLOR_LIGHT_RED]               = {0, 13, 14}
};

static const u8 sSummaryAButtonBitmap[] = INCBIN_U8("graphics/summary_screen/a_button.4bpp");
static const u8 sSummaryBButtonBitmap[] = INCBIN_U8("graphics/summary_screen/b_button.4bpp");

static void (*const sTextPrinterFunctions[])(void) =
{
    [PSS_PAGE_INFO] = PrintInfoPage,
    [PSS_PAGE_MEMO] = PrintMemoPage,
    [PSS_PAGE_SKILLS] = PrintSkillsPage,
    [PSS_PAGE_BATTLE_MOVES] = PrintBattleMoves,
    [PSS_PAGE_CONDITION] = PrintConditionPage,
    [PSS_PAGE_CONTEST_MOVES] = PrintContestMoves
};

static const u8 sMemoNatureTextColor[] = _("{COLOR 5}{SHADOW 6}");
static const u8 sMemoMiscTextColor[] = _("{COLOR 7}{SHADOW 8}");

#define TAG_MOVE_SELECTOR   30000
#define TAG_MON_STATUS      30001
#define TAG_MOVE_TYPES      30002
#define TAG_MON_MARKINGS    30003
#define TAG_SPLIT_ICONS     30004
#define TAG_HEALTH_BAR      30005
#define TAG_EXP_BAR         30006

static const struct OamData sOamData_MoveTypes =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_TypeNormal[] = {
    ANIMCMD_FRAME(TYPE_NORMAL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFighting[] = {
    ANIMCMD_FRAME(TYPE_FIGHTING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFlying[] = {
    ANIMCMD_FRAME(TYPE_FLYING * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePoison[] = {
    ANIMCMD_FRAME(TYPE_POISON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGround[] = {
    ANIMCMD_FRAME(TYPE_GROUND * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeRock[] = {
    ANIMCMD_FRAME(TYPE_ROCK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeBug[] = {
    ANIMCMD_FRAME(TYPE_BUG * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGhost[] = {
    ANIMCMD_FRAME(TYPE_GHOST * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeSteel[] = {
    ANIMCMD_FRAME(TYPE_STEEL * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeMystery[] = {
    ANIMCMD_FRAME(TYPE_MYSTERY * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeFire[] = {
    ANIMCMD_FRAME(TYPE_FIRE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeWater[] = {
    ANIMCMD_FRAME(TYPE_WATER * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeGrass[] = {
    ANIMCMD_FRAME(TYPE_GRASS * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeElectric[] = {
    ANIMCMD_FRAME(TYPE_ELECTRIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypePsychic[] = {
    ANIMCMD_FRAME(TYPE_PSYCHIC * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeIce[] = {
    ANIMCMD_FRAME(TYPE_ICE * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDragon[] = {
    ANIMCMD_FRAME(TYPE_DRAGON * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_TypeDark[] = {
    ANIMCMD_FRAME(TYPE_DARK * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCool[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_COOL + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryBeauty[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_BEAUTY + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryCute[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_CUTE + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategorySmart[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_SMART + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_CategoryTough[] = {
    ANIMCMD_FRAME((CONTEST_CATEGORY_TOUGH + NUMBER_OF_MON_TYPES) * 8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveTypes[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] = {
    sSpriteAnim_TypeNormal,
    sSpriteAnim_TypeFighting,
    sSpriteAnim_TypeFlying,
    sSpriteAnim_TypePoison,
    sSpriteAnim_TypeGround,
    sSpriteAnim_TypeRock,
    sSpriteAnim_TypeBug,
    sSpriteAnim_TypeGhost,
    sSpriteAnim_TypeSteel,
    sSpriteAnim_TypeMystery,
    sSpriteAnim_TypeFire,
    sSpriteAnim_TypeWater,
    sSpriteAnim_TypeGrass,
    sSpriteAnim_TypeElectric,
    sSpriteAnim_TypePsychic,
    sSpriteAnim_TypeIce,
    sSpriteAnim_TypeDragon,
    sSpriteAnim_TypeDark,
    sSpriteAnim_CategoryCool,
    sSpriteAnim_CategoryBeauty,
    sSpriteAnim_CategoryCute,
    sSpriteAnim_CategorySmart,
    sSpriteAnim_CategoryTough,
};

static const struct CompressedSpriteSheet sSpriteSheet_MoveTypes =
{
    .data = gMoveTypes_Gfx,
    .size = (NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT) * 0x100,
    .tag = TAG_MOVE_TYPES
};
static const struct SpriteTemplate sSpriteTemplate_MoveTypes =
{
    .tileTag = TAG_MOVE_TYPES,
    .paletteTag = TAG_MOVE_TYPES,
    .oam = &sOamData_MoveTypes,
    .anims = sSpriteAnimTable_MoveTypes,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u8 sMoveTypeToOamPaletteNum[NUMBER_OF_MON_TYPES + CONTEST_CATEGORIES_COUNT] =
{
    [TYPE_NORMAL] = 13,
    [TYPE_FIGHTING] = 13,
    [TYPE_FLYING] = 14,
    [TYPE_POISON] = 14,
    [TYPE_GROUND] = 13,
    [TYPE_ROCK] = 13,
    [TYPE_BUG] = 15,
    [TYPE_GHOST] = 14,
    [TYPE_STEEL] = 13,
    [TYPE_MYSTERY] = 15,
    [TYPE_FIRE] = 13,
    [TYPE_WATER] = 14,
    [TYPE_GRASS] = 15,
    [TYPE_ELECTRIC] = 13,
    [TYPE_PSYCHIC] = 14,
    [TYPE_ICE] = 14,
    [TYPE_DRAGON] = 15,
    [TYPE_DARK] = 13,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_COOL] = 13,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_BEAUTY] = 14,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_CUTE] = 14,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_SMART] = 15,
    [NUMBER_OF_MON_TYPES + CONTEST_CATEGORY_TOUGH] = 13,
};
static const struct OamData sOamData_MoveSelector =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftRed[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorCenterRed[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightRed[] = {
    ANIMCMD_FRAME(0, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorLeftWhite[] = {
    ANIMCMD_FRAME(32, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorCenterWhite[] = {
    ANIMCMD_FRAME(48, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_MoveSelectorRightWhite[] = {
    ANIMCMD_FRAME(32, 0, TRUE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_MoveSelector[] = {
    sSpriteAnim_MoveSelectorLeftRed,
    sSpriteAnim_MoveSelectorCenterRed,
    sSpriteAnim_MoveSelectorCenterRed,
    sSpriteAnim_MoveSelectorRightRed,
    sSpriteAnim_MoveSelectorLeftWhite,
    sSpriteAnim_MoveSelectorCenterWhite,
    sSpriteAnim_MoveSelectorCenterWhite,
    sSpriteAnim_MoveSelectorRightWhite
};
static const struct CompressedSpriteSheet sMoveSelectorSpriteSheet =
{
    .data = gSummaryMoveSelect_Gfx,
    .size = 0x800,
    .tag = TAG_MOVE_SELECTOR
};
static const struct CompressedSpritePalette sMoveSelectorSpritePal =
{
    .data = gSummaryMoveSelect_Pal,
    .tag = TAG_MOVE_SELECTOR
};
static const struct SpriteTemplate sMoveSelectorSpriteTemplate =
{
    .tileTag = TAG_MOVE_SELECTOR,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_MoveSelector,
    .anims = sSpriteAnimTable_MoveSelector,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const struct OamData sOamData_StatusCondition =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sSpriteAnim_StatusPoison[] = {
    ANIMCMD_FRAME(0, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusParalyzed[] = {
    ANIMCMD_FRAME(4, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusSleep[] = {
    ANIMCMD_FRAME(8, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFrozen[] = {
    ANIMCMD_FRAME(12, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusBurn[] = {
    ANIMCMD_FRAME(16, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusPokerus[] = {
    ANIMCMD_FRAME(20, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd sSpriteAnim_StatusFaint[] = {
    ANIMCMD_FRAME(24, 0, FALSE, FALSE),
    ANIMCMD_END
};
static const union AnimCmd *const sSpriteAnimTable_StatusCondition[] = {
    sSpriteAnim_StatusPoison,
    sSpriteAnim_StatusParalyzed,
    sSpriteAnim_StatusSleep,
    sSpriteAnim_StatusFrozen,
    sSpriteAnim_StatusBurn,
    sSpriteAnim_StatusPokerus,
    sSpriteAnim_StatusFaint,
};
static const struct CompressedSpriteSheet sStatusIconsSpriteSheet =
{
    .data = gStatusGfx_Icons,
    .size = 0x380,
    .tag = TAG_MON_STATUS
};
static const struct CompressedSpritePalette sStatusIconsSpritePalette =
{
    .data = gStatusPal_Icons,
    .tag = TAG_MON_STATUS
};
static const struct SpriteTemplate sSpriteTemplate_StatusCondition =
{
    .tileTag = TAG_MON_STATUS,
    .paletteTag = TAG_MON_STATUS,
    .oam = &sOamData_StatusCondition,
    .anims = sSpriteAnimTable_StatusCondition,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};
static const u16 sSummaryMarkingsPalette[] = INCBIN_U16("graphics/summary_screen/markings.gbapal");

static const struct OamData sOamData_ExpHealthBars = {
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivisionEmpty[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision2[] =
{
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision3[] =
{
    ANIMCMD_FRAME(3, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision4[] =
{
    ANIMCMD_FRAME(4, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision5[] =
{
    ANIMCMD_FRAME(5, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision6[] =
{
    ANIMCMD_FRAME(6, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivision7[] =
{
    ANIMCMD_FRAME(7, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarDivisionFull[] =
{
    ANIMCMD_FRAME(8, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarNameLeft[] =
{
    ANIMCMD_FRAME(9, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarNameRight[] =
{
    ANIMCMD_FRAME(10, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sSpriteAnim_ExpHealthBarEnd[] =
{
    ANIMCMD_FRAME(11, 20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd * const sSpriteAnimTable_ExpHealthBars[] =
{
    sSpriteAnim_ExpHealthBarDivisionEmpty,
    sSpriteAnim_ExpHealthBarDivision1,
    sSpriteAnim_ExpHealthBarDivision2,
    sSpriteAnim_ExpHealthBarDivision3,
    sSpriteAnim_ExpHealthBarDivision4,
    sSpriteAnim_ExpHealthBarDivision5,
    sSpriteAnim_ExpHealthBarDivision6,
    sSpriteAnim_ExpHealthBarDivision7,
    sSpriteAnim_ExpHealthBarDivisionFull,
    sSpriteAnim_ExpHealthBarNameLeft,
    sSpriteAnim_ExpHealthBarNameRight,
    sSpriteAnim_ExpHealthBarEnd
};

static const u16 sHealthBarYellowPal[] = INCBIN_U16("graphics/summary_screen/hp_yellow.gbapal");
static const u16 sHealthBarRedPal[] = INCBIN_U16("graphics/summary_screen/hp_red.gbapal");

static const u16 * const sHealthBarPals[] =
{
    gExpBarHealthBarGreenPal,
    sHealthBarYellowPal,
    sHealthBarRedPal,
};

static const u32 * const sPageTilemaps[] =
{
    gSummaryScreenPageInfoTilemap,
    gSummaryScreenPageMemoTilemap,
    gSummaryScreenPageSkillsTilemap,
    gSummaryScreenPageMovesTilemap,
    //gSummaryScreenPageConditionTilemap,
    gSummaryScreenPageContestMovesTilemap,
    gSummaryScreenPageConditionTilemap
};

const u8 sText_Shiny[] = _("{SUM_SHINY}");
const u8 sText_Pokerus[] = _("{SUM_IMMUNE}");
const u8 sText_Fateful[] = _("{SUM_FATEFUL}");
const u8 sText_NatureUp[] = _("{SUM_UP}");
const u8 sText_NatureDown[] = _("{SUM_DOWN}");
const u8 sText_OTName[] = _("OT");
const u8 sText_OTID[] = _("ID No.");
const u8 sText_HP[] = _("HP");
const u8 sText_PP[] = _("PP");
#if CONFIG_DECAPITALIZE_TITLE_STRINGS
const u8 sText_TitleInfo[] = _("Pokémon Info");
const u8 sText_TitleMemo[] = _("Trainer Memo");
const u8 sText_TitleSkills[] = _("Pokémon Stats");
const u8 sText_TitleBattleMoves[] = _("Battle Moves");
const u8 sText_TitleCondition[] = _("Condition");
const u8 sText_TitleContestMoves[] = _("Contest Moves");
const u8 sText_TitleRibbons[] = _("Ribbons");
const u8 sText_TitleIVs[] = _("Pokémon IVs");
const u8 sText_TitleEVs[] = _("Pokémon EVs");
const u8 sText_TitlePage[] = _("{DPAD_LEFTRIGHT}Page");
const u8 sText_TitlePageDetail[] = _("{DPAD_LEFTRIGHT}Page {A_BUTTON}Detail");
const u8 sText_TitlePickSwitch[] = _("{DPAD_UPDOWN}Pick {A_BUTTON}Switch");
const u8 sText_TitlePageIVs[] = _("{DPAD_LEFTRIGHT}Page {A_BUTTON}IVs");
const u8 sText_TitlePageEVs[] = _("{DPAD_LEFTRIGHT}Page {A_BUTTON}EVs");
const u8 sText_TitlePageStats[] = _("{DPAD_LEFTRIGHT}Page {A_BUTTON}Stats");
#else
const u8 sText_TitleInfo[] = _("POKéMON INFO");
const u8 sText_TitleMemo[] = _("TRAINER MEMO");
const u8 sText_TitleSkills[] = _("POKéMON STATS");
const u8 sText_TitleBattleMoves[] = _("BATTLE MOVES");
const u8 sText_TitleCondition[] = _("CONDITION");
const u8 sText_TitleContestMoves[] = _("CONTEST MOVES");
const u8 sText_TitleRibbons[] = _("RIBBONS");
const u8 sText_TitleIVs[] = _("POKéMON IVS");
const u8 sText_TitleEVs[] = _("POKéMON EVS");
const u8 sText_TitlePage[] = _("{DPAD_LEFTRIGHT}PAGE");
const u8 sText_TitlePageDetail[] = _("{DPAD_LEFTRIGHT}PAGE {A_BUTTON}DETAIL");
const u8 sText_TitlePickSwitch[] = _("{DPAD_UPDOWN}PICK {A_BUTTON}SWITCH");
const u8 sText_TitlePageIVs[] = _("{DPAD_LEFTRIGHT}PAGE {A_BUTTON}IVS");
const u8 sText_TitlePageEVs[] = _("{DPAD_LEFTRIGHT}PAGE {A_BUTTON}EVS");
const u8 sText_TitlePageStats[] = _("{DPAD_LEFTRIGHT}PAGE {A_BUTTON}STATS");
#endif
#if CONFIG_DECAPITALIZE_MENU_STRINGS
const u8 sText_None[] = _("None");
const u8 sText_Cancel[] = _("Cancel");
const u8 sText_Power[] = _("Power");
const u8 sText_Accuracy[] = _("Accuracy");
const u8 sText_Appeal[] = _("Appeal");
const u8 sText_Jam[] = _("Jam");
const u8 sText_DexNo[] = _("Pokédex No.");
const u8 sText_Species[] = _("Name");
const u8 sText_Type[] = _("Type");
const u8 sText_ExpPoints[] = _("Exp. Points");
const u8 sText_ToNextLevel[] = _("To Next Lv.");
const u8 sText_Attack[] = _("Attack");
const u8 sText_Defense[] = _("Defense");
const u8 sText_SpecialAttack[] = _("Sp. Atk");
const u8 sText_SpecialDefense[] = _("Sp. Def");
const u8 sText_Speed[] = _("Speed");
const u8 sText_Ability[] = _("Ability");
const u8 sText_Sheen[] = _("Sheen");
const u8 sText_Cool[] = _("Cool");
const u8 sText_Beauty[] = _("Beauty");
const u8 sText_Cute[] = _("Cute");
const u8 sText_Smart[] = _("Smart");
const u8 sText_Tough[] = _("Tough");
const u8 sText_HeldItem[] = _("Held Item");
#else
const u8 sText_None[] = _("NONE");
const u8 sText_Cancel[] = _("CANCEL");
const u8 sText_Power[] = _("POWER");
const u8 sText_Accuracy[] = _("ACCURACY");
const u8 sText_Appeal[] = _("APPEAL");
const u8 sText_Jam[] = _("JAM");
const u8 sText_DexNo[] = _("POKéDEX No.");
const u8 sText_Species[] = _("NAME");
const u8 sText_Type[] = _("TYPE");
const u8 sText_ExpPoints[] = _("EXP. POINTS");
const u8 sText_ToNextLevel[] = _("TO NEXT LV.");
const u8 sText_Attack[] = _("ATTACK");
const u8 sText_Defense[] = _("DEFENSE");
const u8 sText_SpecialAttack[] = _("SP. ATK");
const u8 sText_SpecialDefense[] = _("SP. DEF");
const u8 sText_Speed[] = _("SPEED");
const u8 sText_Ability[] = _("ABILITY");
const u8 sText_Sheen[] = _("SHEEN");
const u8 sText_Cool[] = _("COOL");
const u8 sText_Beauty[] = _("BEAUTY");
const u8 sText_Cute[] = _("CUTE");
const u8 sText_Smart[] = _("SMART");
const u8 sText_Tough[] = _("TOUGH");
const u8 sText_HeldItem[] = _("HELD ITEM");
#endif

#if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
static const u16 sSplitIcons_Pal[] = INCBIN_U16("graphics/summary_screen/split_icons.gbapal");
static const u32 sSplitIcons_Gfx[] = INCBIN_U32("graphics/summary_screen/split_icons.4bpp.lz");

static const struct OamData sOamData_SplitIcons =
{
    .size = SPRITE_SIZE(32x16),
    .shape = SPRITE_SHAPE(32x16),
    .priority = 0,
};

static const struct CompressedSpriteSheet sSpriteSheet_SplitIcons =
{
    .data = sSplitIcons_Gfx,
    .size = 32*16*3/2,
    .tag = TAG_SPLIT_ICONS,
};

static const struct SpritePalette sSpritePal_SplitIcons =
{
    .data = sSplitIcons_Pal,
    .tag = TAG_SPLIT_ICONS
};

static const union AnimCmd sSpriteAnim_SplitIcon0[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SplitIcon1[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_SplitIcon2[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_SplitIcons[] =
{
    sSpriteAnim_SplitIcon0,
    sSpriteAnim_SplitIcon1,
    sSpriteAnim_SplitIcon2,
};

static const struct SpriteTemplate sSpriteTemplate_SplitIcons =
{
    .tileTag = TAG_SPLIT_ICONS,
    .paletteTag = TAG_SPLIT_ICONS,
    .oam = &sOamData_SplitIcons,
    .anims = sSpriteAnimTable_SplitIcons,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static u8 ShowSplitIcon(u32 split)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT] == 0xFF)
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT] = CreateSprite(&sSpriteTemplate_SplitIcons, 58, 74, 0);

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT]].invisible = FALSE;
    StartSpriteAnim(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT]], split);
    return sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT];
}

static void DestroySplitIcon(void)
{
    if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT] != 0xFF)
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT]]);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT] = 0xFF;
}
#endif

// code
void ShowPokemonSummaryScreen(u8 mode, void *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    sMonSummaryScreen = AllocZeroed(sizeof(*sMonSummaryScreen));
    sMonSummaryScreen->mode = mode;
    sMonSummaryScreen->monList.mons = mons;
    sMonSummaryScreen->curMonIndex = monIndex;
    sMonSummaryScreen->maxMonIndex = maxMonIndex;
    sMonSummaryScreen->callback = callback;

    if (mode == SUMMARY_MODE_BOX)
        sMonSummaryScreen->isBoxMon = TRUE;
    else
        sMonSummaryScreen->isBoxMon = FALSE;

    switch (mode)
    {
    case SUMMARY_MODE_NORMAL:
    case SUMMARY_MODE_BOX:
        sMonSummaryScreen->trueMinPageIndex = PSS_PAGE_INFO;
        sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_CONTEST_MOVES;
        break;
    case SUMMARY_MODE_LOCK_MOVES:
        sMonSummaryScreen->trueMinPageIndex = PSS_PAGE_INFO;
        sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->lockMovesFlag = TRUE;
        break;
    case SUMMARY_MODE_SELECT_MOVE:    // Index limiters aren't actually used in this case, but we'll keep them for clarity
        sMonSummaryScreen->trueMinPageIndex = PSS_PAGE_BATTLE_MOVES;
        if (CONFIG_CAN_SWITCH_PAGES_WHILE_DETAILS_ARE_UP)
            sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_CONTEST_MOVES;
        else
            sMonSummaryScreen->trueMaxPageIndex = PSS_PAGE_BATTLE_MOVES;
        sMonSummaryScreen->lockMonFlag = TRUE;
        break;
    }

    sMonSummaryScreen->minPageIndex = sMonSummaryScreen->trueMinPageIndex;
    sMonSummaryScreen->maxPageIndex = sMonSummaryScreen->trueMaxPageIndex;
    sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;
    sMonSummaryScreen->currStatIndex = 0;
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT] = 0xFF;
    SummaryScreen_SetAnimDelayTaskId(TASK_NONE);

    if (gMonSpritesGfxPtr == NULL)
        CreateMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A, MON_SPR_GFX_MODE_NORMAL);

    SetMainCallback2(CB2_InitSummaryScreen);
}

void ShowSelectMovePokemonSummaryScreen(struct Pokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void), u16 newMove)
{
    ShowPokemonSummaryScreen(SUMMARY_MODE_SELECT_MOVE, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->newMove = newMove;
}

void ShowPokemonSummaryScreenSet40EF(u8 mode, struct BoxPokemon *mons, u8 monIndex, u8 maxMonIndex, void (*callback)(void))
{
    ShowPokemonSummaryScreen(mode, mons, monIndex, maxMonIndex, callback);
    sMonSummaryScreen->unk40EF = TRUE;
}

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlank(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_InitSummaryScreen(void)
{
    while (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && LoadGraphics() != TRUE && MenuHelpers_IsLinkActive() != TRUE);
}

static bool8 LoadGraphics(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ResetVramOamAndBgCntRegs();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        gPaletteFade.bufferTransferDisabled = 1;
        gMain.state++;
        break;
    case 3:
        ResetSpriteData();
        gMain.state++;
        break;
    case 4:
        FreeAllSpritePalettes();
        gMain.state++;
        break;
    case 5:
        InitBGs();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 6:
        if (DecompressGraphics() != FALSE)
            gMain.state++;
        break;
    case 7:
        ResetWindows();
        gMain.state++;
        break;
    case 8:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 9:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) != 0)
            gMain.state++;
        break;
    case 10:
        PrintMonInfo();
        gMain.state++;
        break;
    case 11:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 12:
        PutPageWindowTilemaps(sMonSummaryScreen->currPageIndex);
        gMain.state++;
        break;
    case 13:
        ResetSpriteIds();
        CreateMoveTypeIcons();
        sMonSummaryScreen->switchCounter = 0;
        gMain.state++;
        break;
    case 14:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &sMonSummaryScreen->switchCounter);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] != SPRITE_NONE)
        {
            sMonSummaryScreen->switchCounter = 0;
            gMain.state++;
        }
        break;
    case 15:
        CreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 16:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 17:
        CreateHeldItemSprite(&sMonSummaryScreen->currentMon);
        gMain.state++;
        break;
    case 18:
        LoadMonIconPalette(sMonSummaryScreen->summary.species2);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON] = CreateMonIcon(sMonSummaryScreen->summary.species2, SpriteCB_MonIcon, 20, 47, 1, sMonSummaryScreen->summary.pid, TRUE);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]].hFlip = !IsMonSpriteNotFlipped(sMonSummaryScreen->summary.species2);
        SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
        gMain.state++;
        break;
    case 19:
        CreateHealthBarSprites(TAG_HEALTH_BAR, TAG_HEALTH_BAR);
        gMain.state++;
        break;
    case 20:
        CreateExpBarSprites(TAG_EXP_BAR, TAG_HEALTH_BAR);
        gMain.state++;
    case 21:
        CreateSetStatusSprite();
        gMain.state++;
        break;
    case 22:
        SetTypeIcons();
        gMain.state++;
        break;
    case 23:
        if (sMonSummaryScreen->mode == SUMMARY_MODE_SELECT_MOVE)
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_ITEM, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            StopPokemonAnimations();
            sMonSummaryScreen->markingsSprite->x = 257;
            sMonSummaryScreen->markingsSprite->y = 332;
        }
        gMain.state++;
        break;
    case 24:
        if (sMonSummaryScreen->mode != SUMMARY_MODE_SELECT_MOVE)
        {
            LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            CreateTask(Task_HandleInput, 0);
        }
        else
        {
            LZDecompressWram(gSummaryScreenPageNewMoveTilemap, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            DoScheduledBgTilemapCopiesToVram();
            PrintInfoBar(sMonSummaryScreen->currPageIndex, TRUE);
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(PSS_LABEL_PANE_RIGHT_BOTTOM);
            PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            ChangeBgX(1, 0, 0);
            CreateTask(Task_SetHandleReplaceMoveInput, 0);
        }
        gMain.state++;
        break;
    case 25:
        BlendPalettes(PALETTES_ALL, 16, 0);
        gMain.state++;
        break;
    case 26:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gPaletteFade.bufferTransferDisabled = 0;
        gMain.state++;
        break;
    default:
        SetVBlankCallback(VBlank);
        SetMainCallback2(MainCB2);
        return TRUE;
    }
    return FALSE;
}

static void InitBGs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
    SetBgTilemapBuffer(3, sMonSummaryScreen->bgTilemapBufferBG);
    ResetAllBgsCoordinates();
    ChangeBgX(1, 0x10000, 0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(3);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static bool8 DecompressGraphics(void)
{
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, &gSummaryScreenTiles, 0, 0, 0);
        sMonSummaryScreen->switchCounter++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != 1)
        {
            LZDecompressWram(gSummaryScreenBackgroundTilemap, sMonSummaryScreen->bgTilemapBufferBG);
            sMonSummaryScreen->switchCounter++;
        }
        break;
    case 2:
        LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
        sMonSummaryScreen->switchCounter++;
        break;
    case 3:
        LoadCompressedPalette(gSummaryScreenPalette, 0, 0x100);
        LoadPalette(&gPPTextPalette, 0x81, 0x1E);
        sMonSummaryScreen->switchCounter++;
        break;
    case 4:
        LoadCompressedSpriteSheet(&sSpriteSheet_MoveTypes);
        sMonSummaryScreen->switchCounter++;
        break;
    case 5:
        LoadCompressedSpriteSheet(&sMoveSelectorSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 6:
        LoadCompressedSpriteSheet(&sStatusIconsSpriteSheet);
        sMonSummaryScreen->switchCounter++;
        break;
    case 7:
        LoadCompressedSpritePalette(&sStatusIconsSpritePalette);
        sMonSummaryScreen->switchCounter++;
        break;
    case 8:
        LoadCompressedPalette(gMoveTypes_Pal, 0x1D0, 0x60);
    #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
        sMonSummaryScreen->switchCounter++;
        break;
    case 9:
        LoadCompressedSpriteSheet(&sSpriteSheet_SplitIcons);
        LoadSpritePalette(&sSpritePal_SplitIcons);
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    #else
        sMonSummaryScreen->switchCounter = 0;
        return TRUE;
    #endif
    }
    return FALSE;
}

static void CopyMonToSummaryStruct(struct Pokemon *mon)
{
    if (!sMonSummaryScreen->isBoxMon)
    {
        struct Pokemon *partyMon = sMonSummaryScreen->monList.mons;
        *mon = partyMon[sMonSummaryScreen->curMonIndex];
    }
    else
    {
        struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
        BoxMonToMon(&boxMon[sMonSummaryScreen->curMonIndex], mon);
    }
}

static bool8 ExtractMonDataToSummaryStruct(struct Pokemon *mon)
{
    u32 i;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    // Spread the data extraction over multiple frames.
    switch (sMonSummaryScreen->switchCounter)
    {
    case 0:
        sum->species = GetMonData(mon, MON_DATA_SPECIES);
        sum->species2 = GetMonData(mon, MON_DATA_SPECIES2);
        sum->exp = GetMonData(mon, MON_DATA_EXP);
        sum->level = GetMonData(mon, MON_DATA_LEVEL);
        sum->abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
        sum->item = GetMonData(mon, MON_DATA_HELD_ITEM);
        sum->pid = GetMonData(mon, MON_DATA_PERSONALITY);
        sum->sanity = GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG);

        if (sum->sanity)
            sum->isEgg = TRUE;
        else
            sum->isEgg = GetMonData(mon, MON_DATA_IS_EGG);

        break;
    case 1:
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            sum->moves[i] = GetMonData(mon, MON_DATA_MOVE1+i);
            sum->pp[i] = GetMonData(mon, MON_DATA_PP1+i);
        }
        sum->ppBonuses = GetMonData(mon, MON_DATA_PP_BONUSES);
        break;
    case 2:
        if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
        {
            sum->nature = GetNature(mon);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK);
            sum->def = GetMonData(mon, MON_DATA_DEF);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF);
            sum->speed = GetMonData(mon, MON_DATA_SPEED);
        }
        else
        {
            sum->nature = GetNature(mon);
            sum->currentHP = GetMonData(mon, MON_DATA_HP);
            sum->maxHP = GetMonData(mon, MON_DATA_MAX_HP);
            sum->atk = GetMonData(mon, MON_DATA_ATK2);
            sum->def = GetMonData(mon, MON_DATA_DEF2);
            sum->spatk = GetMonData(mon, MON_DATA_SPATK2);
            sum->spdef = GetMonData(mon, MON_DATA_SPDEF2);
            sum->speed = GetMonData(mon, MON_DATA_SPEED2);
        }
        break;
    case 3:
        GetMonData(mon, MON_DATA_OT_NAME, sum->OTName);
        ConvertInternationalString(sum->OTName, GetMonData(mon, MON_DATA_LANGUAGE));
        sum->ailment = GetMonAilment(mon);
        sum->OTGender = GetMonData(mon, MON_DATA_OT_GENDER);
        sum->OTID = GetMonData(mon, MON_DATA_OT_ID);
        sum->metLocation = GetMonData(mon, MON_DATA_MET_LOCATION);
        sum->metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        sum->metGame = GetMonData(mon, MON_DATA_MET_GAME);
        sum->friendship = GetMonData(mon, MON_DATA_FRIENDSHIP);
        break;
    case 4:
        sum->sheen = GetMonData(mon, MON_DATA_SHEEN);
        sum->cool = GetMonData(mon, MON_DATA_COOL);
        sum->beauty = GetMonData(mon, MON_DATA_BEAUTY);
        sum->cute = GetMonData(mon, MON_DATA_CUTE);
        sum->smart = GetMonData(mon, MON_DATA_SMART);
        sum->tough = GetMonData(mon, MON_DATA_TOUGH);
        break;
    case 5:
        sum->hpIV = GetMonData(mon, MON_DATA_HP_IV);
        sum->atkIV = GetMonData(mon, MON_DATA_ATK_IV);
        sum->defIV = GetMonData(mon, MON_DATA_DEF_IV);
        sum->spatkIV = GetMonData(mon, MON_DATA_SPATK_IV);
        sum->spdefIV = GetMonData(mon, MON_DATA_SPDEF_IV);
        sum->speedIV = GetMonData(mon, MON_DATA_SPEED_IV);
        break;
    case 6:
        sum->hpEV = GetMonData(mon, MON_DATA_HP_EV);
        sum->atkEV = GetMonData(mon, MON_DATA_ATK_EV);
        sum->defEV = GetMonData(mon, MON_DATA_DEF_EV);
        sum->spatkEV = GetMonData(mon, MON_DATA_SPATK_EV);
        sum->spdefEV = GetMonData(mon, MON_DATA_SPDEF_EV);
        sum->speedEV = GetMonData(mon, MON_DATA_SPEED_EV);
        break;
    default:
        sum->ribbonCount = GetMonData(mon, MON_DATA_RIBBON_COUNT);
        sum->fatefulEncounter = GetMonData(mon, MON_DATA_EVENT_LEGAL);
        if (sum->isEgg)
        {
            sMonSummaryScreen->minPageIndex = PSS_PAGE_MEMO;
            sMonSummaryScreen->maxPageIndex = PSS_PAGE_MEMO;
            sMonSummaryScreen->currPageIndex = PSS_PAGE_MEMO;
        }
        else
        {
            sMonSummaryScreen->minPageIndex = sMonSummaryScreen->trueMinPageIndex;
            sMonSummaryScreen->maxPageIndex = sMonSummaryScreen->trueMaxPageIndex;
        }
        return TRUE;
    }
    sMonSummaryScreen->switchCounter++;
    return FALSE;
}

static void FreeSummaryScreen(void)
{
    FreeAllWindowBuffers();
    Free(sMonSummaryScreen);
}

static void BeginCloseSummaryScreen(u8 taskId)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = CloseSummaryScreen;
}

static void CloseSummaryScreen(u8 taskId)
{
    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        SetMainCallback2(sMonSummaryScreen->callback);
        gLastViewedMonIndex = sMonSummaryScreen->curMonIndex;
        SummaryScreen_DestroyAnimDelayTask();
        DestroyHealthBarSprites();
        DestroyExpBarSprites();
        ResetSpriteData();
        FreeAllSpritePalettes();
        StopCryAndClearCrySongs();
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, 0x100);
        if (gMonSpritesGfxPtr == NULL)
            DestroyMonSpritesGfxManager(MON_SPR_GFX_MANAGER_A);
        FreeSummaryScreen();
        DestroyTask(taskId);
    }
}

static void Task_HandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    data[0] = 0;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && !gPaletteFade.active)
    {
        if (JOY_NEW(DPAD_UP))
        {
            ChangeSummaryPokemon(taskId, -1);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            ChangeSummaryPokemon(taskId, 1);
        }
        else if ((JOY_NEW(DPAD_LEFT)) || GetLRKeysPressed() == MENU_L_PRESSED)
        {
            ChangePage(taskId, -1);
        }
        else if ((JOY_NEW(DPAD_RIGHT)) || GetLRKeysPressed() == MENU_R_PRESSED)
        {
            ChangePage(taskId, 1);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES || sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
            {
                PlaySE(SE_SELECT);
                SwitchToMoveSelection(taskId);
            }
            else if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS && FlagGet(FLAG_SYS_GAME_CLEAR))
            {
                PlaySE(SE_SELECT);
                SetTaskFuncWithFollowupFunc(taskId, ChangeStatTask, gTasks[taskId].func);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            StopPokemonAnimations();
            PlaySE(SE_SELECT);
            BeginCloseSummaryScreen(taskId);
        }
    }
}

static void ChangeStatTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            sMonSummaryScreen->currStatIndex = (sMonSummaryScreen->currStatIndex + 1) % 3;
            ClearWindowTilemap(PSS_LABEL_PANE_RIGHT);
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            PrintInfoBar(PSS_PAGE_SKILLS, FALSE);
            PrintSkillsPage();
            data[0]++;
            break;
        case 2:
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void ChangeSummaryPokemon(u8 taskId, s8 delta)
{
    s8 monId;

    if (sMonSummaryScreen->maxMonIndex == 0)
        return;

    if (!sMonSummaryScreen->lockMonFlag)
    {
        if (sMonSummaryScreen->isBoxMon == TRUE)
        {
            if (sMonSummaryScreen->currPageIndex != PSS_PAGE_MEMO)
            {
                if (delta == 1)
                    delta = 0;
                else
                    delta = 2;
            }
            else
            {
                if (delta == 1)
                    delta = 1;
                else
                    delta = 3;
            }
            monId = AdvanceStorageMonIndex(sMonSummaryScreen->monList.boxMons, sMonSummaryScreen->curMonIndex, sMonSummaryScreen->maxMonIndex, delta);
        }
        else if (IsMultiBattle() == TRUE)
        {
            monId = AdvanceMultiBattleMonIndex(delta);
        }
        else
        {
            monId = AdvanceMonIndex(delta);
        }

        if (monId != -1)
        {
            PlaySE(SE_SELECT);
            if (sMonSummaryScreen->summary.ailment != AILMENT_NONE)
                SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            sMonSummaryScreen->curMonIndex = monId;
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].func = Task_ChangeSummaryMon;
        }
    }
}

static void Task_ChangeSummaryMon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        StopCryAndClearCrySongs();
        break;
    case 1:
        SummaryScreen_DestroyAnimDelayTask();
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]]);
        break;
    case 2:
        DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]]);
        break;
    case 3:
        if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HELD_ITEM))
            DestroySpriteAndFreeResources(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM]]);
        break;
    case 4:
        FreeAndDestroyMonIconSprite(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]]);
        break;
    case 5:
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        sMonSummaryScreen->switchCounter = 0;
        break;
    case 6:
        if (ExtractMonDataToSummaryStruct(&sMonSummaryScreen->currentMon) == FALSE)
            return;
        break;
    case 7:
        RemoveAndCreateMonMarkingsSprite(&sMonSummaryScreen->currentMon);
        break;
    case 8:
        CreateCaughtBallSprite(&sMonSummaryScreen->currentMon);
        break;
    case 9:
        CreateHeldItemSprite(&sMonSummaryScreen->currentMon);
        break;
    case 10:
        FreeMonIconPalettes();
        LoadMonIconPalette(sMonSummaryScreen->summary.species2);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON] = CreateMonIcon(sMonSummaryScreen->summary.species2, SpriteCB_MonIcon, 20, 47, 1, sMonSummaryScreen->summary.pid, TRUE);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON_ICON]].hFlip = !IsMonSpriteNotFlipped(sMonSummaryScreen->summary.species2);
        SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
        break;
    case 11:
        data[1] = 0;
        break;
    case 12:
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] = LoadMonGfxAndSprite(&sMonSummaryScreen->currentMon, &data[1]);
        if (sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON] == SPRITE_NONE)
            return;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 1;
        data[1] = 0;
        break;
    case 13:
        ConfigureHealthBarSprites();
        break;
    case 14:
        ConfigureExpBarSprites();
        break;
    case 15:
        SetTypeIcons();
        break;
    case 16:
        PrintMonInfo();
        break;
    case 17:
        PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
        break;
    case 18:
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[2] = 0;
        break;
    default:
        if (MenuHelpers_ShouldWaitForLinkRecv() == 0)
        {
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput;
        }
        return;
    }
    data[0]++;
}

static s8 AdvanceMonIndex(s8 delta)
{
    struct Pokemon *mon = sMonSummaryScreen->monList.mons;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_MEMO)
    {
        if (delta == -1 && sMonSummaryScreen->curMonIndex == 0)
            return sMonSummaryScreen->maxMonIndex;
        else if (delta == 1 && sMonSummaryScreen->curMonIndex >= sMonSummaryScreen->maxMonIndex)
            return 0;
        else
            return sMonSummaryScreen->curMonIndex + delta;
    }
    else
    {
        s8 index = sMonSummaryScreen->curMonIndex;

        do
        {
            index += delta;
            if (index < 0)
                index = sMonSummaryScreen->maxMonIndex;
            else if (index > sMonSummaryScreen->maxMonIndex)
                index = 0;
        } while (GetMonData(&mon[index], MON_DATA_IS_EGG));
        return index;
    }
}

static s8 AdvanceMultiBattleMonIndex(s8 delta)
{
    struct Pokemon *mons = sMonSummaryScreen->monList.mons;
    s8 index, arrId = 0;
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (sMultiBattleOrder[i] == sMonSummaryScreen->curMonIndex)
        {
            arrId = i;
            break;
        }
    }

    while (TRUE)
    {
        const s8 *order = sMultiBattleOrder;

        arrId += delta;
        if (arrId < 0)
            arrId = PARTY_SIZE;
        else if (arrId >= PARTY_SIZE)
            arrId = 0;
        index = order[arrId];
        if (IsValidToViewInMulti(&mons[index]) == TRUE)
            return index;
    }
}

static bool8 IsValidToViewInMulti(struct Pokemon* mon)
{
    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    else if (sMonSummaryScreen->curMonIndex != 0 || !GetMonData(mon, MON_DATA_IS_EGG))
        return TRUE;
    else
        return FALSE;
}

static void ChangePage(u8 taskId, s8 delta)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    s16 *data = gTasks[taskId].data;

    if (sMonSummaryScreen->minPageIndex == sMonSummaryScreen->maxPageIndex)
        return;
    else if (delta == -1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->minPageIndex)
        sMonSummaryScreen->currPageIndex = sMonSummaryScreen->maxPageIndex;
    else if (delta == 1 && sMonSummaryScreen->currPageIndex == sMonSummaryScreen->maxPageIndex)
        sMonSummaryScreen->currPageIndex = sMonSummaryScreen->minPageIndex;
    else
        sMonSummaryScreen->currPageIndex += delta;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
    else
        LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);

    LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
    PlaySE(SE_SELECT);
    ClearWindowTilemap(PSS_LABEL_PANE_RIGHT);
    ScheduleBgCopyTilemapToVram(0);
    data[0] = 0;
    SetTaskFuncWithFollowupFunc(taskId, ChangePageTask, gTasks[taskId].func);
}

static void ChangePageTask(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            HidePageSpecificSprites();
            data[0]++;
            break;
        case 1:
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            SetHealthBarSprites();
            SetExpBarSprites();
            SetTypeIcons();
            data[0]++;
            break;
        case 3:
            PrintPageSpecificText(sMonSummaryScreen->currPageIndex);
            data[0]++;
            break;
        case 4:
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            ScheduleBgCopyTilemapToVram(1);
            data[0]++;
            break;
        case 5:
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void SwitchToMoveSelection(u8 taskId)
{
    u32 i;
    s16 *data = gTasks[taskId].data;

    sMonSummaryScreen->firstMoveIndex = 0;
    data[1] = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];

    gTasks[taskId].func = Task_HandleInput_MoveSelect;
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchToMoveDetails, gTasks[taskId].func);
}

static void Task_SwitchToMoveDetails(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_ITEM, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
            StopPokemonAnimations();
            sMonSummaryScreen->markingsSprite->x = 257;
            sMonSummaryScreen->markingsSprite->y = 332;
            ClearWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(PSS_LABEL_PANE_RIGHT_BOTTOM);
            SetNewMoveTypeIcon();
            PrintInfoBar(sMonSummaryScreen->currPageIndex, TRUE);
            CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
            data[0]++;
            break;
        case 2:
            ChangeBgX(1, 0, 0);
            PrintMoveDetails(data[1]);
            PutWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            data[0]++;
            break;
        case 3:
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void Task_HandleInput_MoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != 1)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 4;
            ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 4;
            ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
        }
        else if (CONFIG_CAN_SWITCH_PAGES_WHILE_DETAILS_ARE_UP && (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED || JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED))
        {
            if (sMonSummaryScreen->maxPageIndex > PSS_PAGE_BATTLE_MOVES)
            {
                if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                    sMonSummaryScreen->currPageIndex = PSS_PAGE_CONTEST_MOVES;
                else
                    sMonSummaryScreen->currPageIndex = PSS_PAGE_BATTLE_MOVES;

                LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
                PlaySE(SE_SELECT);
                data[0] = 0;
                gTasks[taskId].func = Task_SwitchPageInMoveSelect;
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->lockMovesFlag == TRUE
             || (sMonSummaryScreen->newMove == MOVE_NONE && sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES))
            {
                PlaySE(SE_SELECT);
                CloseMoveSelectMode(taskId);
            }
            else if (HasMoreThanOneMove() == TRUE)
            {
                PlaySE(SE_SELECT);
                SwitchToMovePositionSwitchMode(taskId);
            }
            else
            {
                PlaySE(SE_FAILURE);
            }
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            CloseMoveSelectMode(taskId);
        }
    }
}
 void Task_SwitchPageInMoveSelect(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            ClearWindowTilemap(PSS_LABEL_PANE_RIGHT);
            ClearWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
            DestroySplitIcon();
            #endif
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                if (sMonSummaryScreen->newMove != MOVE_NONE)
                    LZDecompressWram(gSummaryScreenPageNewMoveTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                else
                    LZDecompressWram(gSummaryScreenPageMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            else
            {
                if (sMonSummaryScreen->newMove != MOVE_NONE)
                    LZDecompressWram(gSummaryScreenPageContestNewMoveTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                else
                    LZDecompressWram(gSummaryScreenPageContestMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                PrintBattleMoves();
            else
                PrintContestMoves();
            data[0]++;
            break;
        case 3:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(PSS_LABEL_PANE_RIGHT_BOTTOM);
            SetTypeIcons();
            PrintInfoBar(sMonSummaryScreen->currPageIndex, TRUE);
            data[0]++;
            break;
        case 4:
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                PrintMoveDetails(sMonSummaryScreen->newMove);
            else
                PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            PutWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            data[0]++;
            break;
        case 5:
            data[0] = 0;
            gTasks[taskId].func = Task_HandleInput_MoveSelect;
            break;
    }
}

static bool8 HasMoreThanOneMove(void)
{
    u8 i;
    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (sMonSummaryScreen->summary.moves[i] != 0)
            return TRUE;
    }
    return FALSE;
}

static void ChangeSelectedMove(s16 *taskData, s8 direction, u8 *moveIndexPtr)
{
    s8 i, newMoveIndex;
    u16 move;

    PlaySE(SE_SELECT);
    newMoveIndex = *moveIndexPtr;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        newMoveIndex += direction;
        if (newMoveIndex > taskData[0])
            newMoveIndex = 0;
        else if (newMoveIndex < 0)
            newMoveIndex = taskData[0];

        if (newMoveIndex == MAX_MON_MOVES)
        {
            move = sMonSummaryScreen->newMove;
            break;
        }
        move = sMonSummaryScreen->summary.moves[newMoveIndex];
        if (move != 0)
            break;
    }
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    PrintMoveDetails(move);

    if ((*moveIndexPtr == MAX_MON_MOVES && sMonSummaryScreen->newMove == MOVE_NONE) || taskData[1] == 1)
        ScheduleBgCopyTilemapToVram(0);

    if (*moveIndexPtr != MAX_MON_MOVES && newMoveIndex == MAX_MON_MOVES && sMonSummaryScreen->newMove == MOVE_NONE)
    {
        #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
        DestroySplitIcon();
        #endif
        ScheduleBgCopyTilemapToVram(0);
    }

    *moveIndexPtr = newMoveIndex;
    // Get rid of the 'flicker' effect(while idle) when scrolling.
    if (moveIndexPtr == &sMonSummaryScreen->firstMoveIndex)
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR1);
    else
        KeepMoveSelectorVisible(SPRITE_ARR_ID_MOVE_SELECTOR2);
}

static void CloseMoveSelectMode(u8 taskId)
{
    u32 i;
    s16 *data = gTasks[taskId].data;
    data[0] = 0;

    gTasks[taskId].func = Task_HandleInput;
    SetTaskFuncWithFollowupFunc(taskId, Task_SwitchFromMoveDetails, gTasks[taskId].func);
}

static void Task_SwitchFromMoveDetails(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
            PrintMoveDetails(0);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
            SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, TRUE);
            #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
            DestroySplitIcon();
            #endif
            data[0]++;
            break;
        case 1:
            ChangeBgX(1, 0x10000, 0);
            data[0]++;
            break;
        case 2:
            PutWindowTilemap(PSS_LABEL_PANE_LEFT_TOP);
            PutWindowTilemap(PSS_LABEL_PANE_LEFT_BOTTOM);
            PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
            SetSpriteInvisibility(SPRITE_ARR_ID_MON, FALSE);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode = ST_OAM_AFFINE_NORMAL;
            CalcCenterToCornerVec(&gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]], gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.shape, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.size, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].hFlip = !gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].data[1];
            FreeOamMatrix(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.matrixNum);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.matrixNum |= (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].hFlip << 3);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.affineMode = ST_OAM_AFFINE_OFF;
            RequestSpriteFrameImageCopy(gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].anims[0][0].frame.imageValue, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.tileNum, gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].images);
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].x2 = 0;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].y2 = 0;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.x = gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].x + gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].centerToCornerVecX;
            gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.y = gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].y + gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].centerToCornerVecY;

            if (GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HELD_ITEM))
                SetSpriteInvisibility(SPRITE_ARR_ID_ITEM, FALSE);

            CreateSetStatusSprite();
            sMonSummaryScreen->markingsSprite->x = 57;
            sMonSummaryScreen->markingsSprite->y = 132;
            PrintInfoBar(sMonSummaryScreen->currPageIndex, FALSE);
            data[0]++;
            break;
        case 3:
            ScheduleBgCopyTilemapToVram(0);
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0] = 0;
            SwitchTaskToFollowupFunc(taskId);
            break;
    }
}

static void SwitchToMovePositionSwitchMode(u8 taskId)
{
    sMonSummaryScreen->secondMoveIndex = sMonSummaryScreen->firstMoveIndex;
    SetMainMoveSelectorColor(1);
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);
    gTasks[taskId].func = Task_HandleInput_MovePositionSwitch;
}

static void Task_HandleInput_MovePositionSwitch(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (JOY_NEW(DPAD_UP))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], -1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            data[0] = 3;
            ChangeSelectedMove(&data[0], 1, &sMonSummaryScreen->secondMoveIndex);
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (sMonSummaryScreen->firstMoveIndex == sMonSummaryScreen->secondMoveIndex)
                ExitMovePositionSwitchMode(taskId, FALSE);
            else
                ExitMovePositionSwitchMode(taskId, TRUE);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            ExitMovePositionSwitchMode(taskId, FALSE);
        }
    }
}

static void ExitMovePositionSwitchMode(u8 taskId, bool8 swapMoves)
{
    u16 move;

    PlaySE(SE_SELECT);
    SetMainMoveSelectorColor(0);
    DestroyMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR2);

    if (swapMoves == TRUE)
    {
        if (!sMonSummaryScreen->isBoxMon)
        {
            struct Pokemon *mon = sMonSummaryScreen->monList.mons;
            SwapMonMoves(&mon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        else
        {
            struct BoxPokemon *boxMon = sMonSummaryScreen->monList.boxMons;
            SwapBoxMonMoves(&boxMon[sMonSummaryScreen->curMonIndex], sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        }
        CopyMonToSummaryStruct(&sMonSummaryScreen->currentMon);
        SwapMovesNamesPP(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        SwapMovesTypeSprites(sMonSummaryScreen->firstMoveIndex, sMonSummaryScreen->secondMoveIndex);
        sMonSummaryScreen->firstMoveIndex = sMonSummaryScreen->secondMoveIndex;
    }

    move = sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex];
    PrintMoveDetails(move);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    gTasks[taskId].func = Task_HandleInput_MoveSelect;
}

static void SwapMonMoves(struct Pokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void SwapBoxMonMoves(struct BoxPokemon *mon, u8 moveIndex1, u8 moveIndex2)
{
    struct PokeSummary* summary = &sMonSummaryScreen->summary;

    u16 move1 = summary->moves[moveIndex1];
    u16 move2 = summary->moves[moveIndex2];
    u8 move1pp = summary->pp[moveIndex1];
    u8 move2pp = summary->pp[moveIndex2];
    u8 ppBonuses = summary->ppBonuses;

    // Calculate PP bonuses
    u8 ppUpMask1 = gPPUpGetMask[moveIndex1];
    u8 ppBonusMove1 = (ppBonuses & ppUpMask1) >> (moveIndex1 * 2);
    u8 ppUpMask2 = gPPUpGetMask[moveIndex2];
    u8 ppBonusMove2 = (ppBonuses & ppUpMask2) >> (moveIndex2 * 2);
    ppBonuses &= ~ppUpMask1;
    ppBonuses &= ~ppUpMask2;
    ppBonuses |= (ppBonusMove1 << (moveIndex2 * 2)) + (ppBonusMove2 << (moveIndex1 * 2));

    // Swap the moves
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex1, &move2);
    SetBoxMonData(mon, MON_DATA_MOVE1 + moveIndex2, &move1);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex1, &move2pp);
    SetBoxMonData(mon, MON_DATA_PP1 + moveIndex2, &move1pp);
    SetBoxMonData(mon, MON_DATA_PP_BONUSES, &ppBonuses);

    summary->moves[moveIndex1] = move2;
    summary->moves[moveIndex2] = move1;

    summary->pp[moveIndex1] = move2pp;
    summary->pp[moveIndex2] = move1pp;

    summary->ppBonuses = ppBonuses;
}

static void Task_SetHandleReplaceMoveInput(u8 taskId)
{
    SetNewMoveTypeIcon();
    CreateMoveSelectorSprites(SPRITE_ARR_ID_MOVE_SELECTOR1);
    gTasks[taskId].func = Task_HandleReplaceMoveInput;
}

static void Task_HandleReplaceMoveInput(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE)
    {
        if (gPaletteFade.active != TRUE)
        {
            if (JOY_NEW(DPAD_UP))
            {
                data[0] = 4;
                ChangeSelectedMove(data, -1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                data[0] = 4;
                ChangeSelectedMove(data, 1, &sMonSummaryScreen->firstMoveIndex);
            }
            else if (CONFIG_CAN_SWITCH_PAGES_WHILE_DETAILS_ARE_UP && (JOY_NEW(DPAD_LEFT) || GetLRKeysPressed() == MENU_L_PRESSED || JOY_NEW(DPAD_RIGHT) || GetLRKeysPressed() == MENU_R_PRESSED))
            {
                if (sMonSummaryScreen->maxPageIndex > PSS_PAGE_BATTLE_MOVES)
                {
                    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                        sMonSummaryScreen->currPageIndex = PSS_PAGE_CONTEST_MOVES;
                    else
                        sMonSummaryScreen->currPageIndex = PSS_PAGE_BATTLE_MOVES;

                    LZDecompressWram(sPageTilemaps[sMonSummaryScreen->currPageIndex], sMonSummaryScreen->bgTilemapBufferPage);
                    PlaySE(SE_SELECT);
                    data[0] = 0;
                    gTasks[taskId].func = Task_SwitchPageInReplaceMove;
                }
            }
            else if (JOY_NEW(A_BUTTON))
            {
                if (CanReplaceMove() == TRUE)
                {
                    StopPokemonAnimations();
                    PlaySE(SE_SELECT);
                    sMoveSlotToReplace = sMonSummaryScreen->firstMoveIndex;
                    gSpecialVar_0x8005 = sMoveSlotToReplace;
                    BeginCloseSummaryScreen(taskId);
                }
                else
                {
                    PlaySE(SE_FAILURE);
                    ShowCantForgetHMsWindow(taskId);
                    gTasks[taskId].func = Task_ConfirmHMCantForget;
                }
            }
            else if (JOY_NEW(B_BUTTON))
            {
                StopPokemonAnimations();
                PlaySE(SE_SELECT);
                sMoveSlotToReplace = MAX_MON_MOVES;
                gSpecialVar_0x8005 = MAX_MON_MOVES;
                BeginCloseSummaryScreen(taskId);
            }
        }
    }
}

static void Task_SwitchPageInReplaceMove(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
        case 0:
            ClearWindowTilemap(PSS_LABEL_PANE_RIGHT);
            ClearWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
            DestroySplitIcon();
            #endif
            ScheduleBgCopyTilemapToVram(0);
            data[0]++;
            break;
        case 1:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
            {
                if (sMonSummaryScreen->newMove != MOVE_NONE)
                    LZDecompressWram(gSummaryScreenPageNewMoveTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                else
                    LZDecompressWram(gSummaryScreenPageMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            else
            {
                if (sMonSummaryScreen->newMove != MOVE_NONE)
                    LZDecompressWram(gSummaryScreenPageContestNewMoveTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                else
                    LZDecompressWram(gSummaryScreenPageContestMovesTilemap, sMonSummaryScreen->bgTilemapBufferPage);
                LZDecompressWram(gSummaryScreenPageContestMoveDetailsTilemap, sMonSummaryScreen->moveDetailTilemapBuffer);
            }
            SetBgTilemapBuffer(2, sMonSummaryScreen->bgTilemapBufferPage);
            SetBgTilemapBuffer(1, sMonSummaryScreen->moveDetailTilemapBuffer);
            ScheduleBgCopyTilemapToVram(1);
            ScheduleBgCopyTilemapToVram(2);
            data[0]++;
            break;
        case 2:
            if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
                PrintBattleMoves();
            else
                PrintContestMoves();
            data[0]++;
            break;
        case 3:
            PrintNewMoveDetailsOrCancelText();
            PutWindowTilemap(PSS_LABEL_PANE_RIGHT_BOTTOM);
            SetTypeIcons();
            PrintInfoBar(sMonSummaryScreen->currPageIndex, TRUE);
            data[0]++;
            break;
        case 4:
            if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES)
                PrintMoveDetails(sMonSummaryScreen->newMove);
            else
                PrintMoveDetails(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]);
            PutWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
            data[0]++;
            break;
        case 5:
            data[0] = 0;
            gTasks[taskId].func = Task_HandleReplaceMoveInput;
            break;
    }
}

static void Task_ConfirmHMCantForget(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    if (MenuHelpers_ShouldWaitForLinkRecv() != TRUE && gPaletteFade.active != TRUE && JOY_NEW(A_BUTTON))
    {
        data[0] = 4;
        ChangeSelectedMove(data, 0, &sMonSummaryScreen->firstMoveIndex);
        gTasks[taskId].func = Task_HandleReplaceMoveInput;
    }
}

static bool8 CanReplaceMove(void)
{
    if (CONFIG_CAN_FORGET_HM_MOVES)
        return TRUE;
    else if (sMonSummaryScreen->firstMoveIndex == MAX_MON_MOVES
        || sMonSummaryScreen->newMove == MOVE_NONE
        || IsMoveHm(sMonSummaryScreen->summary.moves[sMonSummaryScreen->firstMoveIndex]) != TRUE)
        return TRUE;
    else
        return FALSE;
}

static void PrintTextOnWindow(u8 windowId, const u8 *string, u8 x, u8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4(windowId, 1, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void PrintTextOnWindowSigned(u8 windowId, const u8 *string, u8 x, s8 y, u8 lineSpacing, u8 colorId)
{
    AddTextPrinterParameterized4Signed(windowId, 1, x, y, 0, lineSpacing, sTextColors[colorId], 0, string);
}

static void ShowCantForgetHMsWindow(u8 taskId)
{
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
    {
        FillWindowPixelBuffer(PSS_LABEL_PANE_LEFT_MOVE, PIXEL_FILL(0));
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Power, 8, POWER_AND_ACCURACY_Y, 0, 1);
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Accuracy, 8, POWER_AND_ACCURACY_Y_2, 0, 1);
    }
    else
    {
        FillBgTilemapBufferRect(1, TILE_EMPTY_HEART, 9, 8, 4, 4, 3);
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Appeal, 8, POWER_AND_ACCURACY_Y, 0, 1);
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Jam, 8, POWER_AND_ACCURACY_Y_2, 0, 1);
        CopyBgTilemapBufferToVram(1);
    }

    #if CONFIG_PHYSICAL_SPECIAL_SPLIT || CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_SPLIT]].invisible = TRUE;
    #endif

    PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, gText_HMMovesCantBeForgotten2, 2, 64, 0, 0);
    PutWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
}

u8 GetMoveSlotToReplace(void)
{
    return sMoveSlotToReplace;
}

static void ResetWindows(void)
{
    u8 i;

    InitWindows(sSummaryTemplate);
    DeactivateAllTextPrinters();
    for (i = 0; i < PSS_LABEL_WINDOW_END; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));
    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        sMonSummaryScreen->windowIds[i] = WINDOW_NONE;
}

static void PrintMonInfo(void)
{
    FillWindowPixelBuffer(PSS_LABEL_PANE_LEFT_TOP, PIXEL_FILL(0));
    FillWindowPixelBuffer(PSS_LABEL_PANE_LEFT_BOTTOM, PIXEL_FILL(0));

    if (!sMonSummaryScreen->summary.isEgg)
        PrintNotEggInfo();
    else
        PrintEggInfo();
    PutWindowTilemap(PSS_LABEL_PANE_LEFT_TOP);
    PutWindowTilemap(PSS_LABEL_PANE_LEFT_BOTTOM);
    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNotEggInfo(void)
{
    u8 x;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    GetMonNickname(mon, gStringVar1);
    PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, gStringVar1, 20, 2, 0, 1);
    StringCopy(gStringVar1, gText_LevelSymbol);
    ConvertIntToDecimalStringN(gStringVar2, summary->level, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringAppend(gStringVar1, gStringVar2);
    PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, gStringVar1, 6, 18, 0, 0);

    if (summary->species2 != SPECIES_NIDORAN_M && summary->species2 != SPECIES_NIDORAN_F)
    {
        switch (GetMonGender(mon))
        {
        case MON_MALE:
            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, gText_MaleSymbol, 71, 19, 0, PSS_COLOR_MALE_GENDER_SYMBOL);
            break;
        case MON_FEMALE:
            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, gText_FemaleSymbol, 71, 19, 0, PSS_COLOR_FEMALE_GENDER_SYMBOL);
            break;
        }
    }
    if (IsMonShiny(mon))
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, sText_Shiny, 62, 18, 0, PSS_COLOR_SHINY_STARS);
    #if CONFIG_FATEFUL_ENCOUNTER_MARK
    if (summary->fatefulEncounter)
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, sText_Fateful, 52, 18, 0, PSS_COLOR_FATEFUL_TRIANGLE);
    if (!CheckPartyPokerus(mon, 0) && CheckPartyHasHadPokerus(mon, 0))
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, sText_Pokerus, 43, 18, 0, PSS_COLOR_POKERUS_CURED);
    #else
    if (!CheckPartyPokerus(mon, 0) && CheckPartyHasHadPokerus(mon, 0))
        PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, sText_Pokerus, 52, 18, 0, PSS_COLOR_POKERUS_CURED);
    #endif

    if (sMonSummaryScreen->summary.item == ITEM_NONE)
        StringCopy(gStringVar1, sText_None);
    else
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);

    x = GetStringCenterAlignXOffset(0, gStringVar1, 60);
    AddTextPrinterParameterized4(PSS_LABEL_PANE_LEFT_BOTTOM, 0, 9, 7, 0, 0, sTextColors[PSS_COLOR_WHITE_BLACK_SHADOW], 0, sText_HeldItem);
    AddTextPrinterParameterized4(PSS_LABEL_PANE_LEFT_BOTTOM, 0, x, 19, 0, 0, sTextColors[PSS_COLOR_BLACK_GRAY_SHADOW], 0, gStringVar1);
}

static void PrintEggInfo(void)
{
    u8 x;

    GetMonNickname(&sMonSummaryScreen->currentMon, gStringVar1);
    PrintTextOnWindow(PSS_LABEL_PANE_LEFT_TOP, gStringVar1, 20, 2, 0, 1);
    if (sMonSummaryScreen->summary.item == ITEM_NONE)
        StringCopy(gStringVar1, sText_None);
    else
        CopyItemName(sMonSummaryScreen->summary.item, gStringVar1);
    x = GetStringCenterAlignXOffset(0, gStringVar1, 60);
    AddTextPrinterParameterized4(PSS_LABEL_PANE_LEFT_BOTTOM, 0, 9, 7, 0, 0, sTextColors[PSS_COLOR_WHITE_BLACK_SHADOW], 0, sText_HeldItem);
    AddTextPrinterParameterized4(PSS_LABEL_PANE_LEFT_BOTTOM, 0, x, 19, 0, 0, sTextColors[PSS_COLOR_BLACK_GRAY_SHADOW], 0, gStringVar1);
}

static void PutPageWindowTilemaps(u8 page)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->windowIds); i++)
        PutWindowTilemap(sMonSummaryScreen->windowIds[i]);

    ScheduleBgCopyTilemapToVram(0);
}

static u8 AddWindowFromTemplateList(const struct WindowTemplate *template, u8 templateId)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[templateId];
    if (*windowIdPtr == WINDOW_NONE)
    {
        *windowIdPtr = AddWindow(&template[templateId]);
        FillWindowPixelBuffer(*windowIdPtr, PIXEL_FILL(0));
    }
    return *windowIdPtr;
}

static void RemoveWindowByIndex(u8 windowIndex)
{
    u8 *windowIdPtr = &sMonSummaryScreen->windowIds[windowIndex];
    if (*windowIdPtr != WINDOW_NONE)
    {
        ClearWindowTilemap(*windowIdPtr);
        RemoveWindow(*windowIdPtr);
        *windowIdPtr = WINDOW_NONE;
    }
}

static void PrintPageSpecificText(u8 pageIndex)
{
    u16 i;

    PrintInfoBar(pageIndex, FALSE);
    sTextPrinterFunctions[pageIndex]();
}

static void SetTypeSpritePosAndPal(u8 typeId, u8 x, u8 y, u8 spriteArrayId)
{
    struct Sprite *sprite = &gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]];
    StartSpriteAnim(sprite, typeId);
    sprite->oam.paletteNum = sMoveTypeToOamPaletteNum[typeId];
    sprite->x = x + 16;
    sprite->y = y + 8;
    SetSpriteInvisibility(spriteArrayId, FALSE);
}

static void PrintInfoPage(void)
{
    u8 x, i;
    s64 numExpProgressBarTicks;
    u16 *dst;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u16 dexNum = SpeciesToPokedexNum(summary->species);

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_DexNo, 8, 16, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    if (dexNum == 0xFFFF)
        StringCopy(gStringVar1, gText_ThreeMarks);
    else
        ConvertIntToDecimalStringN(gStringVar1, dexNum, STR_CONV_MODE_LEADING_ZEROS, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 16, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Species, 8, 32, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    StringCopy(gStringVar1, gSpeciesNames[summary->species2]);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 32, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Type, 8, 48, 0, PSS_COLOR_WHITE_BLACK_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_OTName, 8, 64, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    StringCopy(gStringVar1, summary->OTName);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    if (summary->OTGender == MALE)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 64, 0, PSS_COLOR_MALE_GENDER_SYMBOL);
    else
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 64, 0, PSS_COLOR_FEMALE_GENDER_SYMBOL);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_OTID, 8, 80, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    ConvertIntToDecimalStringN(gStringVar1, (u16)summary->OTID, STR_CONV_MODE_LEADING_ZEROS, 5);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 80, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_ExpPoints, 8, 100, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    ConvertIntToDecimalStringN(gStringVar1, summary->exp, STR_CONV_MODE_RIGHT_ALIGN, 7);
    x = GetStringRightAlignXOffset(1, gStringVar1, 42) + 91;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 100, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_ToNextLevel, 8, 116, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    if (summary->level < MAX_LEVEL)
        ConvertIntToDecimalStringN(gStringVar1, gExperienceTables[gBaseStats[summary->species].growthRate][summary->level + 1] - summary->exp, STR_CONV_MODE_RIGHT_ALIGN, 6);
    else
        ConvertIntToDecimalStringN(gStringVar1, 0, STR_CONV_MODE_RIGHT_ALIGN, 6);
    x = GetStringRightAlignXOffset(1, gStringVar1, 42) + 91;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 116, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    if (summary->level < MAX_LEVEL)
    {
        u32 expBetweenLevels = gExperienceTables[gBaseStats[summary->species].growthRate][summary->level + 1] - gExperienceTables[gBaseStats[summary->species].growthRate][summary->level];
        u32 expSinceLastLevel = summary->exp - gExperienceTables[gBaseStats[summary->species].growthRate][summary->level];

        // Calculate the number of 1-pixel "ticks" to illuminate in the experience progress bar.
        // There are 8 tiles that make up the bar, and each tile has 8 "ticks". Hence, the numerator
        // is multiplied by 64.
        numExpProgressBarTicks = expSinceLastLevel * 64 / expBetweenLevels;
        if (numExpProgressBarTicks == 0 && expSinceLastLevel != 0)
            numExpProgressBarTicks = 1;
    }
    else
        numExpProgressBarTicks = 0;
    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
}

static void PrintMemoPage(void)
{
    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    if (sMonSummaryScreen->summary.isEgg)
        BufferEggMemo();
    else
        BufferMonTrainerMemo();
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar4, 8, 16, 0, 0);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
}

static void BufferMonTrainerMemo(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    const u8 *text;

    DynamicPlaceholderTextUtil_Reset();
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sMemoNatureTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sMemoMiscTextColor);
    BufferNatureString();
    BufferCharacteristicString();

    if (InBattleFactory() == TRUE || InSlateportBattleTent() == TRUE || IsInGamePartnerMon() == TRUE)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, gText_XNature);
    }
    else
    {
        u8 *metLevelString = Alloc(32);
        u8 *metLocationString = Alloc(32);
        GetMetLevelString(metLevelString);

        #if CONFIG_EXPANDED_MET_LOCATIONS
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, gRegionStringPointers[WhatRegionWasMonCaughtIn(mon)]);

        if (sum->metLocation == MAPSEC_AQUA_HIDEOUT_OLD && sum->metGame == VERSION_SAPPHIRE)
        {
            GetMapNameGeneric(metLocationString, MAPSEC_AQUA_HIDEOUT);
        }
        else if (sum->metLocation == MAPSEC_AQUA_HIDEOUT_OLD && sum->metGame == VERSION_RUBY)
        {
            GetMapNameGeneric(metLocationString, MAPSEC_MAGMA_HIDEOUT);
        }
        else if (sum->metLocation == MAPSEC_BATTLE_FRONTIER && (sum->metGame == VERSION_SAPPHIRE || sum->metGame == VERSION_RUBY))
        {
            StringCopy(metLocationString, gMapName_BattleTower);
        }
        else if (sum->metLocation == MAPSEC_ROUTE_130 && DidMonComeFromRSE() && (sum->species == SPECIES_WYNAUT || sum->species == SPECIES_WOBBUFFET) && sum->metLevel > 0)
        {
            GetMapNameHoennKanto(metLocationString, MAPSEC_MIRAGE_ISLAND);
        }
        else if (sum->metGame == VERSION_GAMECUBE)
        {
            GetMapNameOrre(metLocationString, sum->metLocation, sum->fatefulEncounter);
        }
        else
        {
            GetMapNameHoennKanto(metLocationString, sum->metLocation);
        }

        if (sum->metGame == VERSION_GAMECUBE)
        {
            if (sum->metLocation == METLOC_IN_GAME_TRADE)
            {
                DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, sum->OTName);
                if (sum->species == SPECIES_ESPEON || sum->species == SPECIES_UMBREON)
                    text = gText_TrainerMemo_OldFriend; //Colosseum starter
                 else
                    text = gText_TrainerMemo_ReceivedFrom; //Duking's Plusle
            }
            else if (sum->fatefulEncounter && sum->metLocation == 0 && (sum->species == SPECIES_EEVEE || sum->species == SPECIES_VAPOREON || sum->species == SPECIES_JOLTEON || sum->species == SPECIES_FLAREON || sum->species == SPECIES_ESPEON || sum->species == SPECIES_UMBREON))
            {
                DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, sum->OTName);
                text = gText_TrainerMemo_ObtainedFromDad; //XD starter
            }
            else
            {
                DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
                #if CONFIG_TRUST_OUTSIDERS
                text = gText_TrainerMemo_Standard;
                #else
                text = gText_TrainerMemo_Untrusted;
                #endif
            }
        }
        else if (sum->metLevel == 0)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            #if CONFIG_TRUST_OUTSIDERS
            text = gText_TrainerMemo_Hatched;
            #else
            if (DoesMonOTMatchOwner())
                text = gText_TrainerMemo_Hatched;
            else
                text = gText_TrainerMemo_HatchedUntrusted;
            #endif
        }
        else if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            text = gText_TrainerMemo_Fateful;
        }
        else if (sum->metLocation != METLOC_IN_GAME_TRADE)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            #if CONFIG_TRUST_OUTSIDERS
            text = gText_TrainerMemo_Standard;
            #else
            if (DoesMonOTMatchOwner())
                text = gText_TrainerMemo_Standard;
            else
                text = gText_TrainerMemo_Untrusted;
            #endif
        }
        else
        {
            text = gText_TrainerMemo_Trade;
        }
        #else
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(5, sRegionString_Unknown);
        GetMapNameHandleAquaHideout(metLocationString, sum->metLocation);

        if (!DidMonComeFromGBAGames())
            StringCopy(metLocationString, sMapName_DistantLand);

        if (sum->metLevel == 0)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            #if CONFIG_TRUST_OUTSIDERS
            text = gText_TrainerMemo_Hatched;
            #else
            if (DoesMonOTMatchOwner())
                text = gText_TrainerMemo_Hatched;
            else
                text = gText_TrainerMemo_HatchedUntrusted;
            #endif
        }
        else if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            text = gText_TrainerMemo_Fateful;
        }
        else if (sum->metLocation != METLOC_IN_GAME_TRADE)
        {
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(4, metLocationString);
            #if CONFIG_TRUST_OUTSIDERS
            text = gText_TrainerMemo_Standard;
            #else
            if (DoesMonOTMatchOwner())
                text = gText_TrainerMemo_Standard;
            else
                text = gText_TrainerMemo_Untrusted;
            #endif
        }
        else
        {
            text = gText_TrainerMemo_Trade;
        }
        #endif

        DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);
        Free(metLevelString);
        Free(metLocationString);
    }
}

static void BufferNatureString(void)
{
    struct PokemonSummaryScreenData *sumStruct = sMonSummaryScreen;
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, gNatureNamePointers[sumStruct->summary.nature]);
}

static void BufferCharacteristicString(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u8 index, highestIV, highestValue, i, j;
    u8 iv[6];
    u8 ties[6] = { 0, 0, 0, 0, 0, 0 };

    iv[0] = GetMonData(mon, MON_DATA_HP_IV);
    iv[1] = GetMonData(mon, MON_DATA_ATK_IV);
    iv[2] = GetMonData(mon, MON_DATA_DEF_IV);
    iv[3] = GetMonData(mon, MON_DATA_SPEED_IV);
    iv[4] = GetMonData(mon, MON_DATA_SPATK_IV);
    iv[5] = GetMonData(mon, MON_DATA_SPDEF_IV);
    index = sum->pid % 6;

    highestValue = iv[0];

    for (i = 0; i < 6; i++)
    {
        if (iv[i] > highestValue)
        {
            highestValue = iv[i];
            ties[0] = i + 1;
            for (j = 1; j < 6; j++)
                ties[j] = 0;
        }
        else if (iv[i] == highestValue)
        {
            for (j = 0; j < 6; j++)
            {
                if (ties[j] == 0)
                {
                    ties[j] = i + 1;
                    break;
                }
            }
        }
    }

    for (i = 0; i < 6; i++)
    {
        if (ties[(index + i) % 6] != 0)
        {
            highestIV = ties[(index + i) % 6] - 1;
            break;
        }
    }

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(6, gCharacteristicPointers[(highestValue % 5) * 6 + highestIV]);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(7, gNatureFlavorPointers[sum->nature]);
}

static void GetMetLevelString(u8 *output)
{
    u8 level = sMonSummaryScreen->summary.metLevel;
    if (level == 0)
        level = EGG_HATCH_LEVEL;
    ConvertIntToDecimalStringN(output, level, STR_CONV_MODE_LEFT_ALIGN, 3);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(3, output);
}

static bool8 DoesMonOTMatchOwner(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    u32 trainerId;
    u8 gender;

    if (sMonSummaryScreen->monList.mons == gEnemyParty)
    {
        u8 multiID = GetMultiplayerId() ^ 1;
        trainerId = gLinkPlayers[multiID].trainerId & 0xFFFF;
        gender = gLinkPlayers[multiID].gender;
        StringCopy(gStringVar1, gLinkPlayers[multiID].name);
    }
    else
    {
        trainerId = GetPlayerIDAsU32() & 0xFFFF;
        gender = gSaveBlock2Ptr->playerGender;
        StringCopy(gStringVar1, gSaveBlock2Ptr->playerName);
    }

    if (gender != sum->OTGender || trainerId != (sum->OTID & 0xFFFF) || StringCompareWithoutExtCtrlCodes(gStringVar1, sum->OTName))
        return FALSE;
    else
        return TRUE;
}

static bool8 DidMonComeFromGBAGames(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame >= VERSION_SAPPHIRE && sum->metGame <= VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromRSE(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame >= VERSION_SAPPHIRE && sum->metGame <= VERSION_EMERALD)
        return TRUE;
    return FALSE;
}

static bool8 DidMonComeFromFRLG(void)
{
    struct PokeSummary *sum = &sMonSummaryScreen->summary;
    if (sum->metGame == VERSION_FIRE_RED || sum->metGame == VERSION_LEAF_GREEN)
        return TRUE;
    return FALSE;
}

static bool8 IsInGamePartnerMon(void)
{
    if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && gMain.inBattle)
    {
        if (sMonSummaryScreen->curMonIndex == 1 || sMonSummaryScreen->curMonIndex == 4 || sMonSummaryScreen->curMonIndex == 5)
            return TRUE;
    }
    return FALSE;
}

static void BufferEggState(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    if (sMonSummaryScreen->summary.sanity == TRUE)
        text = gText_EggWillTakeALongTime;
    else if (sum->friendship <= 5)
        text = gText_EggAboutToHatch;
    else if (sum->friendship <= 10)
        text = gText_EggWillHatchSoon;
    else if (sum->friendship <= 40)
        text = gText_EggWillTakeSomeTime;
    else
        text = gText_EggWillTakeALongTime;

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(2, text);
}

static void BufferEggMemo(void)
{
    const u8 *text;
    struct PokeSummary *sum = &sMonSummaryScreen->summary;

    DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, sMemoNatureTextColor);
    DynamicPlaceholderTextUtil_SetPlaceholderPtr(1, sMemoMiscTextColor);
    BufferEggState();

    #if CONFIG_EXPANDED_MET_LOCATIONS
    if (sMonSummaryScreen->summary.sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            u8 boxOT[17] = _("AZUSA");
            if (!StringCompareWithoutExtCtrlCodes(boxOT, sum->OTName) && sum->OTID == 0)
                text = gText_TrainerMemo_EggFromBrigette;
            else
                text = gText_TrainerMemo_EggFateful;
        }
        #if CONFIG_TRUST_OUTSIDERS == FALSE
        else if (!DoesMonOTMatchOwner())
        {
            text = gText_TrainerMemo_EggTraded;
        }
        #endif
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
        {
            if (DidMonComeFromRSE())
                text = gText_TrainerMemo_EggFromHotSprings;
            else
                text = gText_TrainerMemo_EggFromTraveler;
        }
        else if (DidMonComeFromFRLG())
        {
            text = gText_TrainerMemo_EggFromKanto;
        }
        else
        {
            text = gText_TrainerMemo_EggFromDayCare;
        }
    }
    else
    {
        text = gText_TrainerMemo_BadEgg;
    }
    #else
    if (sMonSummaryScreen->summary.sanity != 1)
    {
        if (sum->metLocation == METLOC_FATEFUL_ENCOUNTER)
        {
            text = gText_TrainerMemo_EggFateful;
        }
        #if CONFIG_TRUST_OUTSIDERS == FALSE
        else if (!DoesMonOTMatchOwner())
        {
            text = gText_TrainerMemo_EggTraded;
        }
        #endif
        else if (sum->metLocation == METLOC_SPECIAL_EGG)
        {
            if (DidMonComeFromRSE())
                text = gText_TrainerMemo_EggFromHotSprings;
            else
                text = gText_TrainerMemo_EggFromTraveler;
        }
        else
        {
            text = gText_TrainerMemo_EggFromDayCare;
        }
    }
    else
    {
        text = gText_TrainerMemo_BadEgg;
    }
    #endif

    DynamicPlaceholderTextUtil_ExpandPlaceholders(gStringVar4, text);
}

#define COLOR_STAT_ARROWS   PSS_COLOR_WHITE_BLACK_SHADOW

static void PrintSkillsPage(void)
{
    u8 x, i;
    s64 numHPBarTicks;
    u16 *dst;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    const s8 *natureMod = gNatureStatTable[sMonSummaryScreen->summary.nature];

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gText_HP3, 12, 1, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    if (sMonSummaryScreen->currStatIndex == 0)
    {
        ConvertIntToDecimalStringN(gStringVar1, summary->currentHP, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(gStringVar1, gText_Slash);
        ConvertIntToDecimalStringN(gStringVar2, summary->maxHP, STR_CONV_MODE_LEFT_ALIGN, 3);
        StringAppend(gStringVar1, gStringVar2);
    }
    else if (sMonSummaryScreen->currStatIndex == 1)
    {
        ConvertIntToDecimalStringN(gStringVar1, summary->hpIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, summary->hpEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    }
        x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 1, 0, 0);

    numHPBarTicks = summary->currentHP * 64 / summary->maxHP;
    if (numHPBarTicks == 0 && summary->currentHP != 0)
        numHPBarTicks = 1;

    if (natureMod[STAT_ATK - 1] > 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureUp, 0, 24, 0, COLOR_STAT_ARROWS);
    else if (natureMod[STAT_ATK - 1] < 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureDown, 0, 24, 0, COLOR_STAT_ARROWS);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Attack, 12, 24, 0, 1);
    if (sMonSummaryScreen->currStatIndex == 0)
        ConvertIntToDecimalStringN(gStringVar1, summary->atk, STR_CONV_MODE_LEFT_ALIGN, 3);
    else if (sMonSummaryScreen->currStatIndex == 1)
        ConvertIntToDecimalStringN(gStringVar1, summary->atkIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        ConvertIntToDecimalStringN(gStringVar1, summary->atkEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 24, 0, 0);

    if (natureMod[STAT_DEF - 1] > 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureUp, 0, 40, 0, COLOR_STAT_ARROWS);
    else if (natureMod[STAT_DEF - 1] < 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureDown, 0, 40, 0, COLOR_STAT_ARROWS);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Defense, 12, 40, 0, 1);
    if (sMonSummaryScreen->currStatIndex == 0)
        ConvertIntToDecimalStringN(gStringVar1, summary->def, STR_CONV_MODE_LEFT_ALIGN, 3);
    else if (sMonSummaryScreen->currStatIndex == 1)
        ConvertIntToDecimalStringN(gStringVar1, summary->defIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        ConvertIntToDecimalStringN(gStringVar1, summary->defEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 40, 0, 0);

    if (natureMod[STAT_SPATK - 1] > 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureUp, 0, 56, 0, COLOR_STAT_ARROWS);
    else if (natureMod[STAT_SPATK - 1] < 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureDown, 0, 56, 0, COLOR_STAT_ARROWS);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_SpecialAttack, 12, 56, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    if (sMonSummaryScreen->currStatIndex == 0)
        ConvertIntToDecimalStringN(gStringVar1, summary->spatk, STR_CONV_MODE_LEFT_ALIGN, 3);
    else if (sMonSummaryScreen->currStatIndex == 1)
        ConvertIntToDecimalStringN(gStringVar1, summary->spatkIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        ConvertIntToDecimalStringN(gStringVar1, summary->spatkEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 56, 0, 0);

    if (natureMod[STAT_SPDEF - 1] > 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureUp, 0, 72, 0, COLOR_STAT_ARROWS);
    else if (natureMod[STAT_SPDEF - 1] < 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureDown, 0, 72, 0, COLOR_STAT_ARROWS);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_SpecialDefense, 12, 72, 0, 1);
    if (sMonSummaryScreen->currStatIndex == 0)
        ConvertIntToDecimalStringN(gStringVar1, summary->spdef, STR_CONV_MODE_LEFT_ALIGN, 3);
    else if (sMonSummaryScreen->currStatIndex == 1)
        ConvertIntToDecimalStringN(gStringVar1, summary->spdefIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        ConvertIntToDecimalStringN(gStringVar1, summary->spdefEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 72, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    if (natureMod[STAT_SPEED - 1] > 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureUp, 0, 88, 0, COLOR_STAT_ARROWS);
    else if (natureMod[STAT_SPEED - 1] < 0)
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_NatureDown, 0, 88, 0, COLOR_STAT_ARROWS);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Speed, 12, 88, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    if (sMonSummaryScreen->currStatIndex == 0)
        ConvertIntToDecimalStringN(gStringVar1, summary->speed, STR_CONV_MODE_LEFT_ALIGN, 3);
    else if (sMonSummaryScreen->currStatIndex == 1)
        ConvertIntToDecimalStringN(gStringVar1, summary->speedIV, STR_CONV_MODE_LEFT_ALIGN, 2);
    else
        ConvertIntToDecimalStringN(gStringVar1, summary->speedEV, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 88, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_Ability, 8, 112, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    StringCopy(gStringVar1, gAbilityNames[GetAbilityBySpecies(sMonSummaryScreen->summary.species, summary->abilityNum)]);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 88) + 58;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, 112, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    StringCopy(gStringVar1, gAbilityDescriptionPointers[GetAbilityBySpecies(sMonSummaryScreen->summary.species, summary->abilityNum)]);
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, 8, 128, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
}

static void PrintConditionPage(void)
{
    u8 x, i;
    s64 numSheenBarTicks;
    u16 *dst;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT_HP, PIXEL_FILL(0));
    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT_SMALL, PIXEL_FILL(0));

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_HP, sText_Sheen, 12, 0, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->sheen, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_HP, gStringVar1, x, 0, 0, 0);

    numSheenBarTicks = summary->sheen * 64 / 255;
    if (numSheenBarTicks == 0 && summary->sheen != 0)
        numSheenBarTicks = 1;

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, sText_Cool, 12, 0, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->cool, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, gStringVar1, x, 0, 0, 0);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, sText_Beauty, 12, 16, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->beauty, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, gStringVar1, x, 16, 0, 0);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, sText_Cute, 12, 32, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->cute, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, gStringVar1, x, 32, 0, 0);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, sText_Smart, 12, 48, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->smart, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, gStringVar1, x, 48, 0, 0);

    PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, sText_Tough, 12, 64, 0, 1);
    ConvertIntToDecimalStringN(gStringVar1, summary->tough, STR_CONV_MODE_LEFT_ALIGN, 3);
    x = GetStringCenterAlignXOffset(1, gStringVar1, 72) + 76;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_SMALL, gStringVar1, x, 64, 0, 0);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT_HP);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT_SMALL);
}

static void PrintBattleMoves(void)
{
    u32 i;

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
}

static void PrintMoveNameAndPP(u8 moveIndex)
{
    u32 pp, color, x;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;

    if (summary->moves[moveIndex] != MOVE_NONE)
    {
        pp = CalculatePPWithBonus(summary->moves[moveIndex], summary->ppBonuses, moveIndex);
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gMoveNames[summary->moves[moveIndex]], 64, moveIndex * 29, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
        ConvertIntToDecimalStringN(gStringVar1, summary->pp[moveIndex], STR_CONV_MODE_LEFT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gStringVar1, gText_Slash);
        StringAppend(gStringVar1, gStringVar2);
        switch (GetCurrentPpToMaxPpState(summary->pp[moveIndex], pp))
        {
            case PP_FEW:
                color = PSS_COLOR_LIGHT_RED;
                break;
            case PP_SOME:
                color = PSS_COLOR_ORANGE;
                break;
            case PP_NO_PP:
                color = PSS_COLOR_FEMALE_GENDER_SYMBOL;
                break;
            case PP_MANY:
                color = PSS_COLOR_BLACK_GRAY_SHADOW;
                break;
        }
        x = GetStringCenterAlignXOffset(1, gStringVar1, 32) + 113;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, sText_PP, 80, moveIndex * 29 + 13, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gStringVar1, x, moveIndex * 29 + 13, 0, color);

        if (moveIndex == 3)
        {
            FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT_BOTTOM, PIXEL_FILL(0));
            PrintTextOnWindowSigned(PSS_LABEL_PANE_RIGHT_BOTTOM, sText_PP, 80, -4, 0, PSS_COLOR_BLACK_GRAY_SHADOW);
            PrintTextOnWindowSigned(PSS_LABEL_PANE_RIGHT_BOTTOM, gStringVar1, x, -4, 0, color);
        }
    }
    else
    {
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gText_OneDash, 64, moveIndex * 29, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
        x = GetStringCenterAlignXOffset(1, gText_TwoDashes, 32) + 113;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT, gText_TwoDashes, x, moveIndex * 29 + 13, 0, PSS_COLOR_BLACK_GRAY_SHADOW);

        if (moveIndex == 3)
        {
            FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT_BOTTOM, PIXEL_FILL(0));
            PrintTextOnWindowSigned(PSS_LABEL_PANE_RIGHT_BOTTOM, gText_TwoDashes, x, -4, 0, color);
        }
    }
}

static void PrintContestMoves(void)
{
    u32 i;

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);

    ScheduleBgCopyTilemapToVram(0);
    PutWindowTilemap(PSS_LABEL_PANE_RIGHT);
}

static u8 GetBattleMoveCategory(u16 move)
{
    if (gBattleMoves[move].power == 0)
    {
        return 2;
    }
    else
    {
        switch (gBattleMoves[move].type)
        {
            case TYPE_NORMAL:
            case TYPE_FIGHTING:
            case TYPE_FLYING:
            case TYPE_GROUND:
            case TYPE_ROCK:
            case TYPE_BUG:
            case TYPE_GHOST:
            case TYPE_POISON:
            case TYPE_STEEL:
                return 0;
            default:
                return 1;
        }
    }
}

static void PrintMoveDetails(u16 move)
{
    u32 heartRow1, heartRow2;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    SetSpriteInvisibility(SPRITE_ARR_ID_MON, TRUE);
    SetSpriteInvisibility(SPRITE_ARR_ID_ITEM, TRUE);
    SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    sMonSummaryScreen->markingsSprite->x = 257;
    sMonSummaryScreen->markingsSprite->y = 332;
    FillWindowPixelBuffer(PSS_LABEL_PANE_LEFT_MOVE, PIXEL_FILL(0));

    SetSpriteInvisibility(SPRITE_ARR_ID_MON_ICON, FALSE);
    SetTypeSpritePosAndPal(gBaseStats[summary->species].type1, 41, 45, SPRITE_ARR_ID_TYPE);

    if (gBaseStats[summary->species].type1 != gBaseStats[summary->species].type2)
    {
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type2, 75, 45, SPRITE_ARR_ID_TYPE + 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
    }

    if (move != MOVE_NONE)
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Power, 8, POWER_AND_ACCURACY_Y, 0, 1);

        #ifdef BATTLE_ENGINE
            if (move == MOVE_HIDDEN_POWER && CONFIG_SHOW_HIDDEN_POWER_STATS && B_HIDDEN_POWER_DMG < GEN_6)
        #else
            if (move == MOVE_HIDDEN_POWER && CONFIG_SHOW_HIDDEN_POWER_STATS)
        #endif
            {
                u8 powerBits = ((GetMonData(mon, MON_DATA_HP_IV) & 2) >> 1)
                        | ((GetMonData(mon, MON_DATA_ATK_IV) & 2) << 0)
                        | ((GetMonData(mon, MON_DATA_DEF_IV) & 2) << 1)
                        | ((GetMonData(mon, MON_DATA_SPEED_IV) & 2) << 2)
                        | ((GetMonData(mon, MON_DATA_SPATK_IV)& 2) << 3)
                        | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 2) << 4);

                u8 powerForHiddenPower = (40 * powerBits) / 63 + 30;

                ConvertIntToDecimalStringN(gStringVar1, powerForHiddenPower, STR_CONV_MODE_RIGHT_ALIGN, 3);
            }
            else
            {
                if (gBattleMoves[move].power < 2)
                    StringCopy(gStringVar1, gText_ThreeDashes);
                else
                    ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].power, STR_CONV_MODE_RIGHT_ALIGN, 3);
            }

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, gStringVar1, 84, POWER_AND_ACCURACY_Y, 0, 0);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Accuracy, 8, POWER_AND_ACCURACY_Y_2, 0, 1);

            if (gBattleMoves[move].accuracy == 0)
            {
                StringCopy(gStringVar1, gText_ThreeDashes);
            }
            else
                ConvertIntToDecimalStringN(gStringVar1, gBattleMoves[move].accuracy, STR_CONV_MODE_RIGHT_ALIGN, 3);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, gStringVar1, 84, POWER_AND_ACCURACY_Y_2, 0, 0);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, gMoveFourLineDescriptionPointers[move - 1], 2, 64, 0, 0);

            #if CONFIG_PHYSICAL_SPECIAL_SPLIT
            ShowSplitIcon(GetBattleMoveSplit(move));
            #elif CONFIG_SHOW_ICONS_FOR_OLD_SPLIT
            ShowSplitIcon(GetBattleMoveCategory(move));
            #endif
        }
        else
        {
            FillBgTilemapBufferRect(1, TILE_EMPTY_HEART, 9, 8, 4, 4, 3);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Appeal, 8, POWER_AND_ACCURACY_Y, 0, 1);

            if (gContestEffects[gContestMoves[move].effect].appeal / 10 > 4)
            {
                heartRow1 = 4;
                heartRow2 = gContestEffects[gContestMoves[move].effect].appeal / 10 - 4;
            }
            else
            {
                heartRow1 = gContestEffects[gContestMoves[move].effect].appeal / 10;
                heartRow2 = 0;
            }
            FillBgTilemapBufferRect(1, TILE_FILLED_APPEAL_HEART, 9, 8, heartRow1, 1, 3);
            FillBgTilemapBufferRect(1, TILE_FILLED_APPEAL_HEART, 9, 9, heartRow2, 1, 3);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, sText_Jam, 8, POWER_AND_ACCURACY_Y_2, 0, 1);

            if (gContestEffects[gContestMoves[move].effect].jam / 10 > 4)
            {
                heartRow1 = 4;
                heartRow2 = gContestEffects[gContestMoves[move].effect].jam / 10 - 4;
            }
            else
            {
                heartRow1 = gContestEffects[gContestMoves[move].effect].jam / 10;
                heartRow2 = 0;
            }
            FillBgTilemapBufferRect(1, TILE_FILLED_JAM_HEART, 9, 10, heartRow1, 1, 3);
            FillBgTilemapBufferRect(1, TILE_FILLED_JAM_HEART, 9, 11, heartRow2, 1, 3);
            CopyBgTilemapBufferToVram(1);

            PrintTextOnWindow(PSS_LABEL_PANE_LEFT_MOVE, gContestEffectFourLineDescriptionPointers[gContestMoves[move].effect], 8, 64, 0, 0);
        }

        PutWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
    }
    else
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
        {
            FillBgTilemapBufferRect(1, 109, 9, 8, 4, 4, 3);
            CopyBgTilemapBufferToVram(1);
        }

        ClearWindowTilemap(PSS_LABEL_PANE_LEFT_MOVE);
    }

    ScheduleBgCopyTilemapToVram(0);
}

static void PrintNewMoveDetailsOrCancelText(void)
{
    u32 pp, x;

    if (sMonSummaryScreen->newMove != MOVE_NONE)
    {
        pp = gBattleMoves[sMonSummaryScreen->newMove].pp;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_BOTTOM, gMoveNames[sMonSummaryScreen->newMove], 64, 12, 0, 1);
        ConvertIntToDecimalStringN(gStringVar1, pp, STR_CONV_MODE_LEFT_ALIGN, 2);
        ConvertIntToDecimalStringN(gStringVar2, pp, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(gStringVar1, gText_Slash);
        StringAppend(gStringVar1, gStringVar2);
        x = GetStringCenterAlignXOffset(1, gStringVar1, 32) + 113;
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_BOTTOM, sText_PP, 80, 25, 0, 0);
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_BOTTOM, gStringVar1, x, 25, 0, 0);
    }
    else
    {
        PrintTextOnWindow(PSS_LABEL_PANE_RIGHT_BOTTOM, sText_Cancel, 64, 12, 0, 1);
    }
}

static void SwapMovesNamesPP(u8 moveIndex1, u8 moveIndex2)
{
    u32 i;

    FillWindowPixelBuffer(PSS_LABEL_PANE_RIGHT, PIXEL_FILL(0));

    for (i = 0; i < MAX_MON_MOVES; i++)
        PrintMoveNameAndPP(i);
}

static void ResetSpriteIds(void)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
        sMonSummaryScreen->spriteIds[i] = SPRITE_NONE;
}

static void DestroySpriteInArray(u8 spriteArrayId)
{
    if (sMonSummaryScreen->spriteIds[spriteArrayId] != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]]);
        sMonSummaryScreen->spriteIds[spriteArrayId] = SPRITE_NONE;
    }
}

static void SetSpriteInvisibility(u8 spriteArrayId, bool8 invisible)
{
    gSprites[sMonSummaryScreen->spriteIds[spriteArrayId]].invisible = invisible;
}

static void HidePageSpecificSprites(void)
{
    // Keeps Pokémon, caught ball and status sprites visible.
    u8 i;

    for (i = SPRITE_ARR_ID_ORIGIN; i < ARRAY_COUNT(sMonSummaryScreen->spriteIds); i++)
    {
        if (sMonSummaryScreen->spriteIds[i] != SPRITE_NONE)
            SetSpriteInvisibility(i, TRUE);
    }

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        sHealthBar->sprites[i]->invisible = TRUE;
    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
        sExpBar->sprites[i]->invisible = TRUE;
}

static void SetTypeIcons(void)
{
    switch (sMonSummaryScreen->currPageIndex)
    {
    case PSS_PAGE_INFO:
        SetMonTypeIcons();
        break;
    case PSS_PAGE_BATTLE_MOVES:
        SetMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    case PSS_PAGE_CONTEST_MOVES:
        SetContestMoveTypeIcons();
        SetNewMoveTypeIcon();
        break;
    }
}

static void CreateMoveTypeIcons(void)
{
    u8 i;

    for (i = SPRITE_ARR_ID_TYPE; i < SPRITE_ARR_ID_TYPE + 7; i++)
    {
        if (sMonSummaryScreen->spriteIds[i] == SPRITE_NONE)
            sMonSummaryScreen->spriteIds[i] = CreateSprite(&sSpriteTemplate_MoveTypes, 0, 0, 2);

        SetSpriteInvisibility(i, TRUE);
    }
}

static void SetMonTypeIcons(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (gBaseStats[summary->species].type1 != gBaseStats[summary->species].type2)
    {
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type1, 167, 65, SPRITE_ARR_ID_TYPE);
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type2, 201, 65, SPRITE_ARR_ID_TYPE + 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, FALSE);
    }
    else
    {
        SetTypeSpritePosAndPal(gBaseStats[summary->species].type1, 184, 65, SPRITE_ARR_ID_TYPE);
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 1, TRUE);
    }
}

static void SetMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
        {
            if (summary->moves[i] == MOVE_HIDDEN_POWER && CONFIG_SHOW_HIDDEN_POWER_STATS)
            {
                u8 typeBits  = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                    | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                    | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                    | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                    | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                    | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);

                u8 type = (15 * typeBits) / 63 + 1;
                if (type >= TYPE_MYSTERY)
                    type++;
                type |= 0xC0;
                SetTypeSpritePosAndPal(type & 0x3F, 116, i * 29 + 20, SPRITE_ARR_ID_TYPE + 2 + i);
            }
            else
            {
                SetTypeSpritePosAndPal(gBattleMoves[summary->moves[i]].type, 116, i * 29 + 20, SPRITE_ARR_ID_TYPE + 2 + i);
            }
        }
        else
        {
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 2 + i, TRUE);
        }
    }
}

static void SetContestMoveTypeIcons(void)
{
    u8 i;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (summary->moves[i] != MOVE_NONE)
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[summary->moves[i]].contestCategory, 116, i * 29 + 20, SPRITE_ARR_ID_TYPE + 2 + i);
        else
            SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 2 + i, TRUE);
    }
}

static void SetNewMoveTypeIcon(void)
{
    struct Pokemon *mon = &sMonSummaryScreen->currentMon;
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if (sMonSummaryScreen->newMove == MOVE_NONE)
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_TYPE + 6, TRUE);
    }
    else
    {
        if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES)
        {
            if (sMonSummaryScreen->newMove == MOVE_HIDDEN_POWER && CONFIG_SHOW_HIDDEN_POWER_STATS)
            {
                u8 typeBits  = ((GetMonData(mon, MON_DATA_HP_IV) & 1) << 0)
                    | ((GetMonData(mon, MON_DATA_ATK_IV) & 1) << 1)
                    | ((GetMonData(mon, MON_DATA_DEF_IV) & 1) << 2)
                    | ((GetMonData(mon, MON_DATA_SPEED_IV) & 1) << 3)
                    | ((GetMonData(mon, MON_DATA_SPATK_IV) & 1) << 4)
                    | ((GetMonData(mon, MON_DATA_SPDEF_IV) & 1) << 5);

                u8 type = (15 * typeBits) / 63 + 1;
                if (type >= TYPE_MYSTERY)
                    type++;
                type |= 0xC0;
                SetTypeSpritePosAndPal(type & 0x3F, 116, 136, SPRITE_ARR_ID_TYPE + 6);
            }
            else
            {
                SetTypeSpritePosAndPal(gBattleMoves[sMonSummaryScreen->newMove].type, 116, 136, SPRITE_ARR_ID_TYPE + 6);
            }
        }
        else
        {
            SetTypeSpritePosAndPal(NUMBER_OF_MON_TYPES + gContestMoves[sMonSummaryScreen->newMove].contestCategory, 116, 136, SPRITE_ARR_ID_TYPE + 6);
        }
    }
}

static void SwapMovesTypeSprites(u8 moveIndex1, u8 moveIndex2)
{
    struct Sprite *sprite1 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex1 + SPRITE_ARR_ID_TYPE + 2]];
    struct Sprite *sprite2 = &gSprites[sMonSummaryScreen->spriteIds[moveIndex2 + SPRITE_ARR_ID_TYPE + 2]];

    u8 temp = sprite1->animNum;
    sprite1->animNum = sprite2->animNum;
    sprite2->animNum = temp;

    temp = sprite1->oam.paletteNum;
    sprite1->oam.paletteNum = sprite2->oam.paletteNum;
    sprite2->oam.paletteNum = temp;

    sprite1->animBeginning = TRUE;
    sprite1->animEnded = FALSE;
    sprite2->animBeginning = TRUE;
    sprite2->animEnded = FALSE;
}

static u8 LoadMonGfxAndSprite(struct Pokemon *mon, s16 *state)
{
    const struct CompressedSpritePalette *pal;
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    switch (*state)
    {
    default:
        return CreateMonSprite(mon);
    case 0:
        if (gMain.inBattle)
        {
            if (ShouldIgnoreDeoxysForm(3, sMonSummaryScreen->curMonIndex))
                HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
            else
                HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
        }
        else
        {
            if (gMonSpritesGfxPtr != NULL)
            {
                if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
                    HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
                else
                    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], gMonSpritesGfxPtr->sprites.ptr[1], summary->species2, summary->pid);
            }
            else
            {
                if (sMonSummaryScreen->monList.mons == gPlayerParty || sMonSummaryScreen->mode == SUMMARY_MODE_BOX || sMonSummaryScreen->unk40EF == TRUE)
                    HandleLoadSpecialPokePic_2(&gMonFrontPicTable[summary->species2], MonSpritesGfxManager_GetSpritePtr(MON_SPR_GFX_MANAGER_A, B_POSITION_OPPONENT_LEFT), summary->species2, summary->pid);
                else
                    HandleLoadSpecialPokePic_DontHandleDeoxys(&gMonFrontPicTable[summary->species2], MonSpritesGfxManager_GetSpritePtr(MON_SPR_GFX_MANAGER_A, B_POSITION_OPPONENT_LEFT), summary->species2, summary->pid);
            }
        }
        (*state)++;
        return 0xFF;
    case 1:
        pal = GetMonSpritePalStructFromOtIdPersonality(summary->species2, summary->OTID, summary->pid);
        LoadCompressedSpritePalette(pal);
        SetMultiuseSpriteTemplateToPokemon(pal->tag, 1);
        (*state)++;
        return 0xFF;
    }
}

static void PlayMonCry(void)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    if (!summary->isEgg)
    {
        if (ShouldPlayNormalMonCry(&sMonSummaryScreen->currentMon) == TRUE)
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_NORMAL);
        else
            PlayCry_ByMode(summary->species2, 0, CRY_MODE_WEAK);
    }
}

static u8 CreateMonSprite(struct Pokemon *unused)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;
    u8 spriteId = CreateSprite(&gMultiuseSpriteTemplate, 40, 85, 5);

    FreeSpriteOamMatrix(&gSprites[spriteId]);
    gSprites[spriteId].data[0] = summary->species2;
    gSprites[spriteId].data[2] = 0;
    gSprites[spriteId].callback = SpriteCB_Pokemon;
    gSprites[spriteId].oam.priority = 0;

    if (!IsMonSpriteNotFlipped(summary->species2))
        gSprites[spriteId].hFlip = TRUE;
    else
        gSprites[spriteId].hFlip = FALSE;

    return spriteId;
}

static void SpriteCB_Pokemon(struct Sprite *sprite)
{
    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (!gPaletteFade.active && sprite->data[2] != 1)
    {
        sprite->data[1] = IsMonSpriteNotFlipped(sprite->data[0]);
        PlayMonCry();
        PokemonSummaryDoMonAnimation(sprite, sprite->data[0], summary->isEgg);
    }
}

// Track and then destroy Task_PokemonSummaryAnimateAfterDelay
// Normally destroys itself but it can be interrupted before the animation starts
void SummaryScreen_SetAnimDelayTaskId(u8 taskId)
{
    sAnimDelayTaskId = taskId;
}

static void SummaryScreen_DestroyAnimDelayTask(void)
{
    if (sAnimDelayTaskId != TASK_NONE)
    {
        DestroyTask(sAnimDelayTaskId);
        sAnimDelayTaskId = TASK_NONE;
    }
}

static void StopPokemonAnimations(void)  // A subtle effect, this function stops pokemon animations when leaving the PSS
{
    u16 i;
    u16 paletteIndex;

    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].animPaused = TRUE;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].callback = SpriteCallbackDummy;
    StopPokemonAnimationDelayTask();

    paletteIndex = (gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MON]].oam.paletteNum * 16) | 0x100;

    for (i = 0; i < 16; i++)
    {
        u16 id = i + paletteIndex;
        gPlttBufferUnfaded[id] = gPlttBufferFaded[id];
    }
}

static void CreateMonMarkingsSprite(struct Pokemon *mon)
{
    struct Sprite *sprite = CreateMonMarkingAllCombosSprite(TAG_MON_MARKINGS, TAG_MON_MARKINGS, sSummaryMarkingsPalette);

    sMonSummaryScreen->markingsSprite = sprite;
    if (sprite != NULL)
    {
        StartSpriteAnim(sprite, GetMonData(mon, MON_DATA_MARKINGS));
        sMonSummaryScreen->markingsSprite->x = 57;
        sMonSummaryScreen->markingsSprite->y = 132;
        sMonSummaryScreen->markingsSprite->oam.priority = 1;
    }
}

static void RemoveAndCreateMonMarkingsSprite(struct Pokemon *mon)
{
    DestroySprite(sMonSummaryScreen->markingsSprite);
    FreeSpriteTilesByTag(TAG_MON_MARKINGS);
    CreateMonMarkingsSprite(mon);
}

static void CreateCaughtBallSprite(struct Pokemon *mon)
{
    u8 ball = ItemIdToBallId(GetMonData(mon, MON_DATA_POKEBALL));

    FreeSpriteTilesByTag(5500);
    FreeSpritePaletteByTag(5500);
    sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL] = AddBallIconSprite(5500, 5500, ball);
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].callback = SpriteCallbackDummy;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].oam.priority = 0;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].x = 12;
    gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_BALL]].y = 11;
}

static void CreateHeldItemSprite(struct Pokemon *mon)
{
    u16 item = GetMonData(mon, MON_DATA_HELD_ITEM);

    if (item != ITEM_NONE)
    {
        FreeSpriteTilesByTag(5501);
        FreeSpritePaletteByTag(5501);
        sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM] = AddItemIconSprite(5501, 5501, item);
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM]].callback = SpriteCallbackDummy;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM]].oam.priority = 0;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM]].x = 16;
        gSprites[sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_ITEM]].y = 153;
    }
}

static void CreateSetStatusSprite(void)
{
    u8 *spriteId = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_STATUS];
    u8 statusAnim;

    if (*spriteId == SPRITE_NONE)
        *spriteId = CreateSprite(&sSpriteTemplate_StatusCondition, 20, 132, 0);

    statusAnim = GetMonAilment(&sMonSummaryScreen->currentMon);
    if (statusAnim != 0)
    {
        StartSpriteAnim(&gSprites[*spriteId], statusAnim - 1);
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, FALSE);
    }
    else
    {
        SetSpriteInvisibility(SPRITE_ARR_ID_STATUS, TRUE);
    }
}

static void CreateMoveSelectorSprites(u8 idArrayStart)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[idArrayStart];

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_BATTLE_MOVES || sMonSummaryScreen->currPageIndex == PSS_PAGE_CONTEST_MOVES)
    {
        u8 subpriority = 1;
        if (idArrayStart == SPRITE_ARR_ID_MOVE_SELECTOR1)
            subpriority = 0;

        for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        {
            spriteIds[i] = CreateSprite(&sMoveSelectorSpriteTemplate, i * 32 + 128, 31, subpriority);
            StartSpriteAnim(&gSprites[spriteIds[i]], i);

            gSprites[spriteIds[i]].callback = SpriteCb_MoveSelector;
            gSprites[spriteIds[i]].data[0] = idArrayStart;
            gSprites[spriteIds[i]].data[1] = 0;
        }
    }
}

static void SpriteCb_MoveSelector(struct Sprite *sprite)
{
    sprite->invisible = FALSE;

    if (sprite->data[0] == SPRITE_ARR_ID_MOVE_SELECTOR1)
    {
        sprite->y2 = sMonSummaryScreen->firstMoveIndex * 29;
        if (sMonSummaryScreen->firstMoveIndex > 0)
            sprite->y2--;
    }
    else
    {
        sprite->y2 = sMonSummaryScreen->secondMoveIndex * 29;
        if (sMonSummaryScreen->secondMoveIndex > 0)
            sprite->y2--;
    }
}

static void DestroyMoveSelectorSprites(u8 firstArrayId)
{
    u8 i;
    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
        DestroySpriteInArray(firstArrayId + i);
}

static void SetMainMoveSelectorColor(u8 which)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[SPRITE_ARR_ID_MOVE_SELECTOR1];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        StartSpriteAnim(&gSprites[spriteIds[i]], which * 4 + i);
    }
}

static void KeepMoveSelectorVisible(u8 firstSpriteId)
{
    u8 i;
    u8 *spriteIds = &sMonSummaryScreen->spriteIds[firstSpriteId];

    for (i = 0; i < MOVE_SELECTOR_SPRITES_COUNT; i++)
    {
        gSprites[spriteIds[i]].data[1] = 0;
        gSprites[spriteIds[i]].invisible = FALSE;
    }
}

static void CreateHealthBarSprites(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void * gfxBufferPtr;
    u32 curHp;
    u32 maxHp;
    u8 hpBarPalTagOffset = 0;

    sHealthBar = AllocZeroed(sizeof(struct HealthBar));
    gfxBufferPtr = AllocZeroed(0x20 * 12);
    LZ77UnCompWram(gSummaryHealthBar_Tiles, gfxBufferPtr);

    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (maxHp / 4 > curHp)
        hpBarPalTagOffset = 2;
    else if (maxHp / 2 > curHp)
        hpBarPalTagOffset = 1;

    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette greenPal = {.data = sHealthBarPals[0], .tag = palTag};
        struct SpritePalette yellowPal = {.data = sHealthBarPals[1], .tag = palTag + 1};
        struct SpritePalette redPal = {.data = sHealthBarPals[2], .tag = palTag + 2};

        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&greenPal);
        LoadSpritePalette(&yellowPal);
        LoadSpritePalette(&redPal);
    }

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
    {
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag + hpBarPalTagOffset,
            .oam = &sOamData_ExpHealthBars,
            .anims = sSpriteAnimTable_ExpHealthBars,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        sHealthBar->spritePositions[i] = i * 8 + 158;
        spriteId = CreateSprite(&template, sHealthBar->spritePositions[i], 38, 0);
        sHealthBar->sprites[i] = &gSprites[spriteId];
        sHealthBar->sprites[i]->oam.priority = 1;
        sHealthBar->sprites[i]->invisible = TRUE;
        sHealthBar->tileTag = tileTag;
        sHealthBar->palTag = palTag;
        StartSpriteAnim(sHealthBar->sprites[i], 8);
    }

    ConfigureHealthBarSprites();
    SetHealthBarSprites();

    FREE_AND_SET_NULL(gfxBufferPtr);
}

static void ConfigureHealthBarSprites(void)
{
    u8 numWholeHpBarTiles = 0;
    u8 i;
    u8 animNum;
    u8 hpBarPalOffset = 0;
    u32 curHp;
    u32 maxHp;
    s64 v0;
    s64 v1;

    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (summary->isEgg)
        return;

    curHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_HP);
    maxHp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_MAX_HP);

    if (maxHp / 5 >= curHp)
        hpBarPalOffset = 2;
    else if (maxHp / 2 >= curHp)
        hpBarPalOffset = 1;

    switch (GetHPBarLevel(curHp, maxHp))
    {
    case 3:
    default:
        hpBarPalOffset = 0;
        break;
    case 2:
        hpBarPalOffset = 1;
        break;
    case 1:
        hpBarPalOffset = 2;
        break;
    }

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        sHealthBar->sprites[i]->oam.paletteNum = IndexOfSpritePaletteTag(TAG_HEALTH_BAR) + hpBarPalOffset;

    if (curHp == maxHp)
    {
        for (i = 2; i < HP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 8);
    }
    else
    {
        v0 = (maxHp << 2) / 8;
        v1 = (curHp << 2);

        while (TRUE)
        {
            if (v1 <= v0)
                break;
            v1 -= v0;
            numWholeHpBarTiles++;
        }

        numWholeHpBarTiles += 2;

        for (i = 2; i < numWholeHpBarTiles; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 8);

        animNum = (v1 * 8) / v0;
        StartSpriteAnim(sHealthBar->sprites[numWholeHpBarTiles], animNum);

        for (i = numWholeHpBarTiles + 1; i < HP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sHealthBar->sprites[i], 0);
    }

    StartSpriteAnim(sHealthBar->sprites[0], 9);
    StartSpriteAnim(sHealthBar->sprites[1], 10);
    StartSpriteAnim(sHealthBar->sprites[HP_BAR_SPRITES_COUNT - 1], 11);
}

static void DestroyHealthBarSprites(void)
{
    u8 i;

    for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
        if (sHealthBar->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sHealthBar->sprites[i]);

    FREE_AND_SET_NULL(sHealthBar);
}

static void SetHealthBarSprites(void)
{
    u8 i;
    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_SKILLS)
    {
        for (i = 0; i < HP_BAR_SPRITES_COUNT; i++)
            sHealthBar->sprites[i]->invisible = FALSE;
    }
}

static void CreateExpBarSprites(u16 tileTag, u16 palTag)
{
    u8 i;
    u8 spriteId;
    void * gfxBufferPtr;
    sExpBar = AllocZeroed(sizeof(struct ExpBar));
    gfxBufferPtr = AllocZeroed(0x20 * 12);

    LZ77UnCompWram(gSummaryExpBar_Tiles, gfxBufferPtr);
    if (gfxBufferPtr != NULL)
    {
        struct SpriteSheet sheet = {
            .data = gfxBufferPtr,
            .size = 0x20 * 12,
            .tag = tileTag
        };

        struct SpritePalette palette = {.data = gExpBarHealthBarGreenPal, .tag = palTag};
        LoadSpriteSheet(&sheet);
        LoadSpritePalette(&palette);
    }

    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
    {
        struct SpriteTemplate template = {
            .tileTag = tileTag,
            .paletteTag = palTag,
            .oam = &sOamData_ExpHealthBars,
            .anims = sSpriteAnimTable_ExpHealthBars,
            .images = NULL,
            .affineAnims = gDummySpriteAffineAnimTable,
            .callback = SpriteCallbackDummy,
        };

        sExpBar->spritePositions[i] = i * 8 + 158;
        spriteId = CreateSprite(&template, sExpBar->spritePositions[i], 153, 0);
        sExpBar->sprites[i] = &gSprites[spriteId];
        sExpBar->sprites[i]->oam.priority = 1;
        sExpBar->sprites[i]->invisible = TRUE;
        sExpBar->tileTag = tileTag;
        sExpBar->palTag = palTag;
    }

    ConfigureExpBarSprites();
    SetExpBarSprites();

    FREE_AND_SET_NULL(gfxBufferPtr);
}

static void ConfigureExpBarSprites(void)
{
    u8 numWholeExpBarTiles = 0;
    u8 i;
    u8 level;
    u32 exp;
    u32 totalExpToNextLevel;
    u32 curExpToNextLevel;
    u16 species;
    s64 v0;
    s64 v1;
    u8 animNum;

    struct PokeSummary *summary = &sMonSummaryScreen->summary;

    if (summary->isEgg)
        return;

    exp = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_EXP);
    level = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_LEVEL);
    species = GetMonData(&sMonSummaryScreen->currentMon, MON_DATA_SPECIES);

    if (level < 100)
    {
        totalExpToNextLevel = gExperienceTables[gBaseStats[species].growthRate][level + 1] - gExperienceTables[gBaseStats[species].growthRate][level];
        curExpToNextLevel = exp - gExperienceTables[gBaseStats[species].growthRate][level];
        v0 = ((totalExpToNextLevel << 2) / 8);
        v1 = (curExpToNextLevel << 2);

        while (TRUE)
        {
            if (v1 <= v0)
                break;
            v1 -= v0;
            numWholeExpBarTiles++;
        }

        numWholeExpBarTiles += 2;

        for (i = 2; i < numWholeExpBarTiles; i++)
            StartSpriteAnim(sExpBar->sprites[i], 8);

        if (numWholeExpBarTiles >= EXP_BAR_SPRITES_COUNT - 1)
        {
            if (totalExpToNextLevel == curExpToNextLevel)
                return;
            else
                StartSpriteAnim(sExpBar->sprites[EXP_BAR_SPRITES_COUNT - 2], 7);
        }

        animNum = (v1 * 8) / v0;
        StartSpriteAnim(sExpBar->sprites[numWholeExpBarTiles], animNum);

        for (i = numWholeExpBarTiles + 1; i < EXP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sExpBar->sprites[i], 0);
    }
    else
        for (i = 2; i < EXP_BAR_SPRITES_COUNT - 1; i++)
            StartSpriteAnim(sExpBar->sprites[i], 0);

    StartSpriteAnim(sExpBar->sprites[0], 9);
    StartSpriteAnim(sExpBar->sprites[1], 10);
    StartSpriteAnim(sExpBar->sprites[EXP_BAR_SPRITES_COUNT - 1], 11);
}

static void DestroyExpBarSprites(void)
{
    u8 i;

    for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
        if (sExpBar->sprites[i] != NULL)
            DestroySpriteAndFreeResources(sExpBar->sprites[i]);

    FREE_AND_SET_NULL(sExpBar);
}

static void SetExpBarSprites(void)
{
    u8 i;

    if (sMonSummaryScreen->currPageIndex == PSS_PAGE_INFO)
    {
        for (i = 0; i < EXP_BAR_SPRITES_COUNT; i++)
            sExpBar->sprites[i]->invisible = FALSE;
    }
}


static void PrintInfoBar(u8 pageIndex, bool8 detailsShown)
{
    u8 x;

    FillWindowPixelBuffer(PSS_LABEL_PANE_TITLE, PIXEL_FILL(0));

    switch (pageIndex)
    {
        case PSS_PAGE_INFO:
            StringCopy(gStringVar1, sText_TitleInfo);
            StringCopy(gStringVar2, sText_TitlePage);
            break;
        case PSS_PAGE_MEMO:
            StringCopy(gStringVar1, sText_TitleMemo);
            StringCopy(gStringVar2, sText_TitlePage);
            break;
        case PSS_PAGE_SKILLS:
            if (!FlagGet(FLAG_SYS_GAME_CLEAR))
            {
                StringCopy(gStringVar1, sText_TitleSkills);
                StringCopy(gStringVar2, sText_TitlePage);
            }
            else if (sMonSummaryScreen->currStatIndex == 0)
            {
                StringCopy(gStringVar1, sText_TitleSkills);
                StringCopy(gStringVar2, sText_TitlePageIVs);
            }
            else if (sMonSummaryScreen->currStatIndex == 1)
            {
                StringCopy(gStringVar1, sText_TitleIVs);
                StringCopy(gStringVar2, sText_TitlePageEVs);
            }
            else
            {
                StringCopy(gStringVar1, sText_TitleEVs);
                StringCopy(gStringVar2, sText_TitlePageStats);
            }
            break;
        case PSS_PAGE_BATTLE_MOVES:
            StringCopy(gStringVar1, sText_TitleBattleMoves);
            if (detailsShown)
                StringCopy(gStringVar2, sText_TitlePickSwitch);
            else
                StringCopy(gStringVar2, sText_TitlePageDetail);
            break;
        case PSS_PAGE_CONDITION:
            StringCopy(gStringVar1, sText_TitleCondition);
            StringCopy(gStringVar2, sText_TitlePage);
            break;
        case PSS_PAGE_CONTEST_MOVES:
            StringCopy(gStringVar1, sText_TitleContestMoves);
            if (detailsShown)
                StringCopy(gStringVar2, sText_TitlePickSwitch);
            else
                StringCopy(gStringVar2, sText_TitlePageDetail);
            break;
    }

    PrintTextOnWindow(PSS_LABEL_PANE_TITLE, gStringVar1, 3, 0, 0, PSS_COLOR_WHITE_BLACK_SHADOW);
    x = GetStringRightAlignXOffset(0, gStringVar2, 150);
    AddTextPrinterParameterized4(PSS_LABEL_PANE_TITLE, 0, x, 0, 0, 0, sTextColors[PSS_COLOR_WHITE_BLACK_SHADOW], 0, gStringVar2);
    PutWindowTilemap(PSS_LABEL_PANE_TITLE);
}

static u8 WhatRegionWasMonCaughtIn(struct Pokemon *mon)
{
    u8 originGame, versionModifier, metLocation;

    originGame = GetMonData(mon, MON_DATA_MET_GAME, 0);
    metLocation = GetMonData(mon, MON_DATA_MET_LOCATION, 0);

    if (originGame == VERSION_GAMECUBE)
        return REGION_ORRE;
    else if ((metLocation >= KANTO_MAPSEC_START && metLocation <= KANTO_MAPSEC_END) || metLocation == MAPSEC_BIRTH_ISLAND || metLocation == MAPSEC_NAVEL_ROCK)
        return REGION_KANTO;
    else if (metLocation == MAPSEC_FARAWAY_ISLAND || metLocation == METLOC_FATEFUL_ENCOUNTER || metLocation == METLOC_IN_GAME_TRADE)
        return REGION_UNKNOWN;
    else if (originGame == 0 || originGame == 6 || originGame == 9 || originGame == 13 || originGame == 14)
        return REGION_UNKNOWN;
    else
        return REGION_HOENN;
}

static u8 *GetMapNameHoennKanto(u8 *dest, u16 regionMapId)
{
    if (regionMapId < MAPSEC_NONE && gRegionMapEntries[regionMapId].name != 0)
    {
        StringCopy(dest, gRegionMapEntries[regionMapId].name);
    }
    else
    {
        StringCopy(dest, gOrreMapNamePointers[MAPSEC_DISTANT_LAND]);
    }
}

static u8 *GetMapNameOrre(u8 *dest, u16 regionMapId, bool8 isXD)
{
    if (!isXD)
    {
        switch (regionMapId)
        {
        case 1:
        case 2:
        case 200:
            regionMapId = MAPSEC_OUTSKIRT_STAND;
            break;
        case 3:
        case 4:
        case 7:
        case 8:
        case 9:
        case 10:
        case 119:
        case 128:
        case 202:
            regionMapId = MAPSEC_PHENAC_CITY;
            break;
        case 5:
        case 6:
        case 204:
            regionMapId = MAPSEC_MAYORS_HOUSE;
            break;
        case 11:
        case 12:
        case 203:
            regionMapId = MAPSEC_PRE_GYM;
            break;
        case 13:
        case 14:
            regionMapId = MAPSEC_PHENAC_STADIUM;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 205:
            regionMapId = MAPSEC_PYRITE_TOWN;
            break;
        case 25:
        case 26:
        case 27:
        case 28:
        case 207:
            regionMapId = MAPSEC_PYRITE_BLDG;
            break;
        case 29:
        case 31:
        case 32:
        case 33:
        case 34:
        case 206:
            regionMapId = MAPSEC_PYRITE_CAVE;
            break;
        case 30:
            regionMapId = MAPSEC_MIRORS_HIDEOUT;
            break;
        case 35:
        case 120:
        case 142:
            regionMapId = MAPSEC_PYRITE_COLOSSEUM;
            break;
        case 36:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 208:
        case 209:
            regionMapId = MAPSEC_AGATE_VILLAGE;
            break;
        case 37:
        case 38:
        case 210:
            regionMapId = MAPSEC_RELIC_CAVE;
            break;
        case 47:
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 62:
        case 122:
        case 127:
        case 211:
        case 212:
            regionMapId = MAPSEC_THE_UNDER;
            break;
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 138:
        case 139:
        case 213:
            regionMapId = MAPSEC_THE_UNDER_SUBWAY;
            break;
        case 63:
        case 121:
            regionMapId = MAPSEC_UNDER_COLOSSEUM;
            break;
        case 64:
        case 125:
            regionMapId = MAPSEC_DEEP_COLOSSEUM;
            break;
        case 65:
        case 214:
            regionMapId = MAPSEC_FRONT_OF_LAB;
            break;
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 140:
        case 141:
        case 215:
            regionMapId = MAPSEC_LABORATORY;
            break;
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
        case 90:
        case 91:
        case 92:
        case 93:
        case 94:
        case 216:
        case 217:
        case 218:
        case 219:
        case 220:
            regionMapId = MAPSEC_MT_BATTLE;
            break;
        case 95:
        case 228:
            regionMapId = MAPSEC_MTBTL_COLOSSEUM;
            break;
        case 102:
        case 115:
        case 116:
        case 117:
        case 123:
        case 124:
        case 223:
        case 224:
            regionMapId = MAPSEC_REALGAM_TOWER;
            break;
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 221:
            regionMapId = MAPSEC_REALGAMTWR_DOME;
            break;
        case 114:
        case 222:
            regionMapId = MAPSEC_REALGAMTWR_LOBBY;
            break;
        case 118:
        case 227:
            regionMapId = MAPSEC_TOWER_COLOSSEUM;
            break;
        case 126:
            regionMapId = MAPSEC_ORRE_COLOSSEUM;
            break;
        case 129:
        case 130:
        case 131:
        case 132:
        case 133:
        case 134:
        case 135:
        case 136:
        case 137:
        case 201:
            regionMapId = MAPSEC_SNAGEM_HIDEOUT;
            break;
        case 225:
        case 226:
            regionMapId = MAPSEC_REALGAM_TOWER_2F;
            break;
        default:
            regionMapId = MAPSEC_DISTANT_LAND;
        }
    }
    else
    {
        switch (regionMapId)
        {
        case 1:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            regionMapId = MAPSEC_CIPHER_LAB;
            break;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
            regionMapId = MAPSEC_MT_BATTLE;
            break;
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
            regionMapId = MAPSEC_S_S_LIBRA;
            break;
        case 45:
        case 46:
        case 49:
        case 50:
        case 51:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
            regionMapId = MAPSEC_REALGAM_TOWER;
            break;
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
            regionMapId = MAPSEC_CIPHER_KEY_LAIR;
            break;
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
        case 80:
        case 81:
        case 82:
        case 83:
        case 84:
        case 85:
        case 86:
        case 87:
        case 88:
        case 89:
            regionMapId = MAPSEC_CITADARK_ISLE;
            break;
        case 90:
            regionMapId = MAPSEC_ROCK;
            break;
        case 91:
            regionMapId = MAPSEC_OASIS;
            break;
        case 92:
            regionMapId = MAPSEC_CAVE;
            break;
        case 93:
        case 94:
        case 95:
        case 96:
        case 97:
        case 98:
        case 99:
        case 100:
        case 101:
        case 102:
        case 103:
        case 104:
        case 105:
        case 106:
        case 107:
        case 181:
            regionMapId = MAPSEC_PHENAC_CITY;
            break;
        case 108:
        case 109:
        case 110:
        case 111:
        case 112:
        case 113:
        case 115:
        case 116:
        case 117:
        case 118:
        case 119:
        case 120:
        case 121:
        case 122:
        case 123:
            regionMapId = MAPSEC_PYRITE_TOWN;
            break;
        case 125:
        case 126:
        case 127:
        case 128:
        case 129:
        case 130:
        case 131:
        case 132:
        case 133:
        case 134:
        case 135:
            regionMapId = MAPSEC_AGATE_VILLAGE;
            break;
        case 138:
        case 139:
        case 140:
        case 141:
        case 142:
        case 143:
            regionMapId = MAPSEC_POKEMON_HQ_LAB;
            break;
        case 144:
        case 145:
        case 146:
        case 147:
        case 148:
        case 149:
        case 150:
        case 151:
        case 152:
        case 153:
        case 154:
        case 155:
        case 156:
        case 157:
        case 158:
        case 159:
        case 160:
        case 161:
        case 162:
            regionMapId = MAPSEC_GATEON_PORT;
            break;
        case 163:
        case 164:
            regionMapId = MAPSEC_OUTSKIRT_STAND;
            break;
        case 165:
        case 166:
        case 167:
        case 168:
            regionMapId = MAPSEC_SNAGEM_HIDEOUT;
            break;
        case 169:
        case 170:
        case 171:
        case 172:
        case 173:
            regionMapId = MAPSEC_KAMINKOS_HOUSE;
            break;
        case 174:
            regionMapId = MAPSEC_ORRE_COLOSSEUM;
            break;
        default:
            regionMapId = MAPSEC_DISTANT_LAND;
        }
    }

    if (regionMapId < ORRE_MAPSEC_END && gOrreMapNamePointers[regionMapId] != 0)
    {
        StringCopy(dest, gOrreMapNamePointers[regionMapId]);
    }
    else
    {
        StringCopy(dest, gOrreMapNamePointers[MAPSEC_DISTANT_LAND]);
    }
}
