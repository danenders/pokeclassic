#include "global.h"
#include "event_data.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "task.h"
#include "constants/metatile_labels.h"

static EWRAM_DATA u8 sEscalatorAnim_TaskId = 0;

static void SetEscalatorMetatile(u8 taskId, const s16 *metatileIds, u16 metatileMasks);
static void Task_DrawEscalator(u8 taskId);
static void Task_DrawTeleporterHousing(u8 taskId);
static void Task_DrawTeleporterCable(u8 taskId);

#define ESCALATOR_STAGES     3
#define LAST_ESCALATOR_STAGE (ESCALATOR_STAGES - 1)

static const u16 sEscalatorMetatiles_1F_0[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator1F_Tile0_Frame2,
    METATILE_PokemonCenter_Escalator1F_Tile0_Frame1,
    METATILE_PokemonCenter_Escalator1F_Tile0_Frame0
};

static const u16 sEscalatorMetatiles_1F_1[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator1F_Tile1_Frame2,
    METATILE_PokemonCenter_Escalator1F_Tile1_Frame1,
    METATILE_PokemonCenter_Escalator1F_Tile1_Frame0
};

static const u16 sEscalatorMetatiles_1F_2[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator1F_Tile2_Frame2,
    METATILE_PokemonCenter_Escalator1F_Tile2_Frame1,
    METATILE_PokemonCenter_Escalator1F_Tile2_Frame0
};

static const u16 sEscalatorMetatiles_1F_3[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator1F_Tile3_Frame2,
    METATILE_PokemonCenter_Escalator1F_Tile3_Frame1,
    METATILE_PokemonCenter_Escalator1F_Tile3_Frame0
};

static const u16 sEscalatorMetatiles_2F_0[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator2F_Tile0_Frame0,
    METATILE_PokemonCenter_Escalator2F_Tile0_Frame1,
    METATILE_PokemonCenter_Escalator2F_Tile0_Frame2
};

static const u16 sEscalatorMetatiles_2F_1[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator2F_Tile1_Frame0,
    METATILE_PokemonCenter_Escalator2F_Tile1_Frame1,
    METATILE_PokemonCenter_Escalator2F_Tile1_Frame2
};

static const u16 sEscalatorMetatiles_2F_2[ESCALATOR_STAGES] = {
    METATILE_PokemonCenter_Escalator2F_Tile2_Frame0,
    METATILE_PokemonCenter_Escalator2F_Tile2_Frame1,
    METATILE_PokemonCenter_Escalator2F_Tile2_Frame2
};

#define tState            data[0]
#define tTransitionStage  data[1]
#define tGoingUp          data[2]
#define tDrawingEscalator data[3]
#define tPlayerX          data[4]
#define tPlayerY          data[5]

static void SetEscalatorMetatile(u8 taskId, const s16 *metatileIds, u16 metatileMasks)
{
    s16 x = gTasks[taskId].tPlayerX - 1;
    s16 y = gTasks[taskId].tPlayerY - 1;
    s16 transitionStage = gTasks[taskId].tTransitionStage;
    s16 i;
    s16 j;

    // Check all the escalator sections and only progress the selected one to the next stage
    if (!gTasks[taskId].tGoingUp)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(x + j, y + i);

                if (metatileIds[transitionStage] == metatileId)
                {
                    if (transitionStage != LAST_ESCALATOR_STAGE)
                        MapGridSetMetatileIdAt(x + j, y + i, metatileMasks | metatileIds[transitionStage + 1]);
                    else
                        MapGridSetMetatileIdAt(x + j, y + i, metatileMasks | metatileIds[0]);
                }
            }
        }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                s16 metatileId = MapGridGetMetatileIdAt(x + j, y + i);

                if (metatileIds[LAST_ESCALATOR_STAGE - transitionStage] == metatileId)
                {
                    if (transitionStage != LAST_ESCALATOR_STAGE)
                        MapGridSetMetatileIdAt(x + j, y + i, metatileMasks | metatileIds[1 - transitionStage]);
                    else
                        MapGridSetMetatileIdAt(x + j, y + i, metatileMasks | metatileIds[LAST_ESCALATOR_STAGE]);
                }
            }
        }
    }
}

static void Task_DrawEscalator(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tDrawingEscalator = TRUE;

    // Set tile for each section of the escalator in sequence for current transition stage
    switch (tState)
    {
        case 0:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_1F_0, 0);
            break;
        case 1:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_1F_1, 0);
            break;
        case 2:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_1F_2, MAPGRID_COLLISION_MASK);
            break;
        case 3:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_1F_3, 0);
            break;
        case 4:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_2F_0, MAPGRID_COLLISION_MASK);
            break;
        case 5:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_2F_1, 0);
            break;
        case 6:
            SetEscalatorMetatile(taskId, sEscalatorMetatiles_2F_2, 0);
            break;
    }

    tState = (tState + 1) & 7;

    // If all metatiles of the escalator have been set, draw map and progress to next stage
    if (tState == 0)
    {
        DrawWholeMapView();
        tTransitionStage = (tTransitionStage + 1) % ESCALATOR_STAGES;
        tDrawingEscalator = FALSE;
    }
}

static u8 CreateEscalatorTask(bool16 goingUp)
{
    u8 taskId = CreateTask(Task_DrawEscalator, 0);
    s16 *data = gTasks[taskId].data;

    PlayerGetDestCoords(&tPlayerX, &tPlayerY);
    tState = 0;
    tTransitionStage = 0;
    tGoingUp = goingUp;
    Task_DrawEscalator(taskId);
    return taskId;
}

void StartEscalator(bool8 goingUp)
{
    sEscalatorAnim_TaskId = CreateEscalatorTask(goingUp);
}

void StopEscalator(void)
{
    DestroyTask(sEscalatorAnim_TaskId);
}

bool8 IsEscalatorMoving(void)
{
    if (gTasks[sEscalatorAnim_TaskId].tDrawingEscalator == FALSE
     && gTasks[sEscalatorAnim_TaskId].tTransitionStage == LAST_ESCALATOR_STAGE)
        return FALSE;
    else
        return TRUE;
}

#undef tState
#undef tTransitionStage
#undef tGoingUp
#undef tDrawingEscalator
#undef tPlayerX
#undef tPlayerY

#undef tState
#undef tTransitionStage
#undef tGoingUp
#undef tDrawingEscalator
#undef tPlayerX
#undef tPlayerY

#define tTimer data[0]
#define tState data[1]
#define tX     data[2]
#define tY     data[3]

void AnimateTeleporterHousing(void)
{
    u8 taskId;
    s16 *data;
    
    taskId = CreateTask(Task_DrawTeleporterHousing, 0);
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tState = 0;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&tX, &tY);

    // Set the coords of whichever teleporter is being animated
    // 0 for the right teleporter, 1 for the left teleporter
    if (gSpecialVar_0x8004 == 0)
    {
        gTasks[taskId].tX += 6;
        gTasks[taskId].tY -= 5;
    }
    else
    {
        gTasks[taskId].tX -= 1;
        gTasks[taskId].tY -= 5;
    }    
}

static void Task_DrawTeleporterHousing(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (tTimer == 0)
    {
        // Alternate the teleporter light / brightness of the teleporter door
        if ((tState & 1) == 0)
        {
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Yellow | MAPGRID_COLLISION_MASK );
            MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door_HalfGlowing | MAPGRID_COLLISION_MASK );
        }
        else
        {
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Red | MAPGRID_COLLISION_MASK );
            MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door_FullGlowing | MAPGRID_COLLISION_MASK );
        }
        CurrentMapDrawMetatileAt(tX, tY);
        CurrentMapDrawMetatileAt(tX, tY + 2);
    }
    
    tTimer++;
    if (tTimer != 16)
        return;
    
    tTimer = 0;
    tState++;
    if (tState != 13)
        return;
    
    MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Light_Green | MAPGRID_COLLISION_MASK );
    MapGridSetMetatileIdAt(tX, tY + 2, METATILE_SeaCottage_Teleporter_Door | MAPGRID_COLLISION_MASK );
    CurrentMapDrawMetatileAt(tX, tY);
    CurrentMapDrawMetatileAt(tX, tY + 2);
    DestroyTask(taskId);
}

void AnimateTeleporterCable(void)
{
    u8 taskId;
    s16 *data;
    
    taskId = CreateTask(Task_DrawTeleporterCable, 0);
    gTasks[taskId].tTimer = 0;
    gTasks[taskId].tState = 0;
    data = gTasks[taskId].data;
    PlayerGetDestCoords(&tX, &tY);
    gTasks[taskId].tX += 4;
    gTasks[taskId].tY -= 5;
}

static void Task_DrawTeleporterCable(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    
    if (tTimer == 0)
    {
        if (tState != 0)
        {
            // Set default cable tiles to clear the ball
            MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_Cable_Top | MAPGRID_COLLISION_MASK );
            MapGridSetMetatileIdAt(tX, tY + 1, METATILE_SeaCottage_Teleporter_Cable_Bottom | MAPGRID_COLLISION_MASK );
            CurrentMapDrawMetatileAt(tX, tY);
            CurrentMapDrawMetatileAt(tX, tY + 1);

            // End after drawing 4 times (length of the cable)
            if (tState == 4)
            {
                DestroyTask(taskId);
                return;
            }
            
            tX--;
        }

        // Draw the cable ball
        MapGridSetMetatileIdAt(tX, tY, METATILE_SeaCottage_Teleporter_CableBall_Top | MAPGRID_COLLISION_MASK );
        MapGridSetMetatileIdAt(tX, tY + 1, METATILE_SeaCottage_Teleporter_CableBall_Bottom | MAPGRID_COLLISION_MASK );
        CurrentMapDrawMetatileAt(tX, tY);
        CurrentMapDrawMetatileAt(tX, tY + 1);
    }
    
    tTimer++;
    if (tTimer == 4)
    {
        tTimer = 0;
        tState++;
    }
}

#undef tTimer
#undef tState
#undef tX
#undef tY
