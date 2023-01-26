#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "start_menu.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
static EWRAM_DATA u8 sPopupTaskId = 0;

// .rodata
static const u8 sMapPopUp_Table[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2.4bpp"),
};

static const u8 sMapPopUp_OutlineTable[][960] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U8("graphics/map_popup/wood_outline.4bpp"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U8("graphics/map_popup/marble_outline.4bpp"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U8("graphics/map_popup/stone_outline.4bpp"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U8("graphics/map_popup/brick_outline.4bpp"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U8("graphics/map_popup/underwater_outline.4bpp"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U8("graphics/map_popup/stone2_outline.4bpp"),
};

static const u16 sMapPopUp_PaletteTable[][16] =
{
    [MAPPOPUP_THEME_WOOD]       = INCBIN_U16("graphics/map_popup/wood.gbapal"),
    [MAPPOPUP_THEME_MARBLE]     = INCBIN_U16("graphics/map_popup/marble_outline.gbapal"),
    [MAPPOPUP_THEME_STONE]      = INCBIN_U16("graphics/map_popup/stone_outline.gbapal"),
    [MAPPOPUP_THEME_BRICK]      = INCBIN_U16("graphics/map_popup/brick_outline.gbapal"),
    [MAPPOPUP_THEME_UNDERWATER] = INCBIN_U16("graphics/map_popup/underwater_outline.gbapal"),
    [MAPPOPUP_THEME_STONE2]     = INCBIN_U16("graphics/map_popup/stone2_outline.gbapal"),
};

static const u16 sMapPopUp_Palette_Underwater[16] = INCBIN_U16("graphics/map_popup/underwater.gbapal");

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping[] =
{
    [MAPSEC_PALLET_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_PEWTER_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_VIRIDIAN_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_CERULEAN_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_VERMILION_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_CELADON_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SAFFRON_CITY] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_FUCHSIA_CITY] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_LAVENDER_TOWN] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_CINNABAR_ISLAND] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_INDIGO_PLATEAU] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ROUTE_1] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_2] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_3] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_4] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_5] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_6] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_7] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_8] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_9] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_10] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_11] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_12] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_13] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_14] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_15] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_16] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_17] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_18] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_19] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_20] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_21] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROUTE_22] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_23] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_ROUTE_24] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_ROUTE_25] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DIGLETTS_CAVE] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_VICTORY_ROAD] = MAPPOPUP_THEME_STONE,
    [MAPSEC_ROCK_TUNNEL] = MAPPOPUP_THEME_STONE,
    [MAPSEC_MT_MOON] = MAPPOPUP_THEME_STONE2,
    [MAPSEC_SEAFOAM_ISLANDS] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_POKEMON_MANSION] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_POKEMON_TOWER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_POWER_PLANT] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_CERULEAN_CAVE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_S_S_ANNE] = MAPPOPUP_THEME_UNDERWATER,
    [MAPSEC_ROCKET_HIDEOUT] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_SILPH_CO] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SAFARI_ZONE] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_UNDERGROUND_PATH] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_UNDERGROUND_PATH_2] = MAPPOPUP_THEME_BRICK,
    [MAPSEC_BATTLE_FRONTIER] = MAPPOPUP_THEME_MARBLE,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_STONE,
    [MAPSEC_FARAWAY_ISLAND] = MAPPOPUP_THEME_WOOD,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_MARBLE
};

static const u8 sText_PyramidFloor1[] = _("Pyramid Floor 1");
static const u8 sText_PyramidFloor2[] = _("Pyramid Floor 2");
static const u8 sText_PyramidFloor3[] = _("Pyramid Floor 3");
static const u8 sText_PyramidFloor4[] = _("Pyramid Floor 4");
static const u8 sText_PyramidFloor5[] = _("Pyramid Floor 5");
static const u8 sText_PyramidFloor6[] = _("Pyramid Floor 6");
static const u8 sText_PyramidFloor7[] = _("Pyramid Floor 7");
static const u8 sText_Pyramid[] = _("Pyramid");

static const u8 * const sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    sText_PyramidFloor1,
    sText_PyramidFloor2,
    sText_PyramidFloor3,
    sText_PyramidFloor4,
    sText_PyramidFloor5,
    sText_PyramidFloor6,
    sText_PyramidFloor7,
    sText_Pyramid,
};

// Unused
static bool8 StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            sPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
            SetGpuReg(REG_OFFSET_BG0VOFS, 40);
            gTasks[sPopupTaskId].data[0] = 6;
            gTasks[sPopupTaskId].data[2] = 40;
        }
        else
        {
            if (gTasks[sPopupTaskId].data[0] != 2)
                gTasks[sPopupTaskId].data[0] = 2;
            gTasks[sPopupTaskId].data[3] = 1;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 6:
        task->data[4]++;
        if (task->data[4] > 30)
        {
            task->data[0] = 0;
            task->data[4] = 0;
            ShowMapNamePopUpWindow();
        }
        break;
    case 0:
        task->data[2] -= 2;
        if (task->data[2] <= 0 )
        {
            task->data[2] = 0;
            task->data[0] = 1;
            gTasks[sPopupTaskId].data[1] = 0;
        }
        break;
    case 1:
        task->data[1]++;
        if (task->data[1] > 120 )
        {
            task->data[1] = 0;
            task->data[0] = 2;
        }
        break;
    case 2:
        task->data[2] += 2;
        if (task->data[2] > 39)
        {
            task->data[2] = 40;
            if (task->data[3])
            {
                task->data[0] = 6;
                task->data[4] = 0;
                task->data[3] = 0;
            }
            else
            {
                task->data[0] = 4;
                return;
            }
        }
        break;
    case 4:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        task->data[0] = 5;
        break;
    case 5:
        HideMapNamePopUpWindow();
        return;
    }
    SetGpuReg(REG_OFFSET_BG0VOFS, task->data[2]);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        RemoveMapNamePopUpWindow();
        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(sPopupTaskId);
    }
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8* mapDisplayHeaderSource;

    if (InBattlePyramid())
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[3]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[3]);
        GetMapName(withoutPrefixPtr, gMapHeader.regionMapSectionId, 0);
    }
    AddMapNamePopUpWindow();
    LoadMapNamePopUpWindowBg();
    x = GetStringCenterAlignXOffset(FONT_NARROW, withoutPrefixPtr, 80);
    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_HIGHLIGHT;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    AddTextPrinterParameterized(GetMapNamePopUpWindowId(), FONT_NARROW, mapDisplayHeader, x, 3, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(GetMapNamePopUpWindowId(), COPYWIN_FULL);
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    // Draw top edge
    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    // Draw sides
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    // Draw bottom edge
    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    u16 regionMapSectionId = gMapHeader.regionMapSectionId;

    popUpThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping[regionMapSectionId];

    LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
    CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
    PutWindowTilemap(popupWindowId);
    if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
        LoadPalette(&sMapPopUp_Palette_Underwater, 0xE0, sizeof(sMapPopUp_Palette_Underwater));
    else
        LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], 0xE0, sizeof(sMapPopUp_PaletteTable[0]));
    BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
}
