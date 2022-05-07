#ifndef GUARD_DEXNAV_H
#define GUARD_DEXNAV_H

#define DEXNAV_TIMEOUT                  15  //15 seconds is the time out. Max of 1092 seconds allowed
#define SNEAKING_PROXIMITY              4   //Tile amount
#define CREEPING_PROXIMITY              2
#define MAX_PROXIMITY                   20

#define DEXNAV_CHAIN_MAX                100

//hidden pokemon options - no info so I just guessed at values
#define HIDDEN_MON_STEP_COUNT       100  //look for hidden pokemon every x steps
#define HIDDEN_MON_SEARCH_RATE      25  //x% chance of finding hidden pokemon every x steps
#define HIDDEN_MON_PROBABILTY       15  //x% chance of finding hidden mon compared to regular encounter data

//// SEARCH PROBABILITIES
// see https://m.bulbapedia.bulbagarden.net/wiki/DexNav#Benefits
//Chance of encountering egg move at search levels
#define SEARCHLEVEL0_MOVECHANCE         0
#define SEARCHLEVEL5_MOVECHANCE         21
#define SEARCHLEVEL10_MOVECHANCE        46
#define SEARCHLEVEL25_MOVECHANCE        58
#define SEARCHLEVEL50_MOVECHANCE        63
#define SEARCHLEVEL100_MOVECHANCE       83
//Chance of encountering Hidden Abilities at search levels
#define SEARCHLEVEL0_ABILITYCHANCE      0
#define SEARCHLEVEL5_ABILITYCHANCE      0
#define SEARCHLEVEL10_ABILITYCHANCE     5
#define SEARCHLEVEL25_ABILITYCHANCE     15
#define SEARCHLEVEL50_ABILITYCHANCE     20
#define SEARCHLEVEL100_ABILITYCHANCE    23
//Chance of encountering held item
#define SEARCHLEVEL0_ITEM               0
#define SEARCHLEVEL5_ITEM               0
#define SEARCHLEVEL10_ITEM              1
#define SEARCHLEVEL25_ITEM              7
#define SEARCHLEVEL50_ITEM              6
#define SEARCHLEVEL100_ITEM             12
//Chance of encountering one star potential
#define SEARCHLEVEL0_ONESTAR            0
#define SEARCHLEVEL5_ONESTAR            14
#define SEARCHLEVEL10_ONESTAR           17
#define SEARCHLEVEL25_ONESTAR           17
#define SEARCHLEVEL50_ONESTAR           15
#define SEARCHLEVEL100_ONESTAR          8
//Chance of encountering two star potential
#define SEARCHLEVEL0_TWOSTAR            0
#define SEARCHLEVEL5_TWOSTAR            1
#define SEARCHLEVEL10_TWOSTAR           9
#define SEARCHLEVEL25_TWOSTAR           16
#define SEARCHLEVEL50_TWOSTAR           17
#define SEARCHLEVEL100_TWOSTAR          24
//Chance of encountering three star potential
#define SEARCHLEVEL0_THREESTAR          0
#define SEARCHLEVEL5_THREESTAR          0
#define SEARCHLEVEL10_THREESTAR         1
#define SEARCHLEVEL25_THREESTAR         7
#define SEARCHLEVEL50_THREESTAR         6
#define SEARCHLEVEL100_THREESTAR        12

// GUI Info
#define ROW_WATER       0
#define ROW_LAND_TOP    1
#define ROW_LAND_BOT    2
#define ROW_HIDDEN      3
#define ROWS_COUNT      4

#define ROW_WATER_ICON_X        30
#define ROW_WATER_ICON_Y        35

#define ROW_LAND_ICON_X         20
#define ROW_LAND_TOP_ICON_Y     72
#define ROW_LAND_BOT_ICON_Y     (ROW_LAND_TOP_ICON_Y + 28)

#define ROW_HIDDEN_ICON_X       52
#define ROW_HIDDEN_ICON_Y       138

#define ENCOUNTER_TYPE_LAND     0
#define ENCOUNTER_TYPE_WATER    1
#define ENCOUNTER_TYPE_HIDDEN   2   //get from species

#define COL_WATER_COUNT         5
#define COL_LAND_COUNT          6
#define COL_HIDDEN_COUNT        3

#define COL_WATER_MAX           (COL_WATER_COUNT - 1)
#define COL_LAND_MAX            (COL_LAND_COUNT - 1)
#define COL_HIDDEN_MAX          (COL_HIDDEN_COUNT - 1)

// SEARCH INFO
#define SCANSTART_X             0
#define SCANSTART_Y             0
#define SCANSIZE_X              12
#define SCANSIZE_Y              12

#define SPECIES_INFO_Y          5
#define TYPE_ICONS_Y            (SPECIES_INFO_Y + 24)
#define SEARCH_LEVEL_Y          (TYPE_ICONS_Y + 24)
#define HA_INFO_Y               (SEARCH_LEVEL_Y + 24)
#define CHAIN_BONUS_Y           (HA_INFO_Y + 24)

#define MON_LEVEL_NONEXISTENT   255 //if mon not in area GetEncounterLevel returns this to exit the search

// gui tags
#define ICON_PAL_TAG            56000
#define ICON_GFX_TAG            55130
#define SELECTION_CURSOR_TAG    0x4005
#define CAPTURED_ALL_TAG        0x4002

//search tags
#define OWNED_ICON_TAG          0x4003
#define HIDDEN_SEARCH_TAG       SELECTION_CURSOR_TAG
#define HIDDEN_MON_ICON_TAG     0x4006
#define LIT_STAR_TILE_TAG       0x4010
//#define SIGHT_TAG               0x5424
#define HELD_ITEM_TAG           0xd750

// dexnav search variable
#define MASK_SPECIES         0x3FFF  //first 14 bits
#define MASK_ENVIRONMENT     0xC000  //last two bit

//funcs
void EndDexNavSearch(u8 taskId);
void Task_OpenDexNavFromStartMenu(u8 taskId);
bool8 TryStartDexnavSearch(void);
void TryIncrementSpeciesSearchLevel(u16 dexNum);
void ResetDexNavSearch(void);
bool8 TryFindHiddenPokemon(void);
bool8 DexNavTryMakeShinyMon(void);
void IncrementDexNavChain(void);

//ewram
extern u8 gCurrentDexNavChain;
extern bool8 gDexnavBattle;

#endif //GUARD_DEXNAV_H