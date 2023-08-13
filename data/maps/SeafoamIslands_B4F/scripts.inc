.set NUM_BOULDERS_PRESENT, VAR_TEMP_2
.set LOCALID_ARTICUNO, 4

SeafoamIslands_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_B4F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SeafoamIslands_B4F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SeafoamIslands_B4F_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SeafoamIslands_B4F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SeafoamIslands_B4F_OnFrame
	.byte 0

SeafoamIslands_B4F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SeafoamIslands_B4F_EventScript_TryRemoveArticuno
	end

SeafoamIslands_B4F_OnTransition::
	call_if_set FLAG_CAUGHT_ARTICUNO, SeafoamIslands_B4F_EventScript_HideArticuno
	call_if_unset FLAG_CAUGHT_ARTICUNO, SeafoamIslands_B4F_EventScript_TryShowArticuno
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, SeafoamIslands_B4F_EventScript_CheckStoppedCurrent
	call_if_set FLAG_STOPPED_SEAFOAM_B4F_CURRENT, SeafoamIslands_B4F_EventScript_SetNoCurrentLayout
	end

SeafoamIslands_B4F_EventScript_HideArticuno::
	setflag FLAG_HIDE_ARTICUNO
	return

SeafoamIslands_B4F_EventScript_TryShowArticuno::
	goto_if_set FLAG_DEFEATED_ARTICUNO, Common_EventScript_Return
	clearflag FLAG_HIDE_ARTICUNO
	return

SeafoamIslands_B4F_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_ARTICUNO
	return

SeafoamIslands_B4F_EventScript_Articuno::
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ vertical pan
	setvar VAR_0x8005, 3  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 2  @ shake delay
	special ShakeCamera
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ARTICUNO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SeafoamIslands_B4F_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SeafoamIslands_B4F_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SeafoamIslands_B4F_EventScript_RanFromArticuno
	setflag FLAG_CAUGHT_ARTICUNO
	release
	end

SeafoamIslands_B4F_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_ARTICUNO
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

SeafoamIslands_B4F_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end

SeafoamIslands_B4F_EventScript_ItemUltraBall::
	finditem ITEM_ULTRA_BALL, 1
	release
	end

SeafoamIslands_B4F_EventScript_CheckStoppedCurrent::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B4F_EventScript_StoppedCurrent
	return

SeafoamIslands_B4F_EventScript_StoppedCurrent::
	setflag FLAG_STOPPED_SEAFOAM_B4F_CURRENT
	return

SeafoamIslands_B4F_EventScript_SetNoCurrentLayout::
	setmaplayoutindex LAYOUT_SEAFOAM_ISLANDS_B4F_CURRENT_STOPPED
	return

SeafoamIslands_B4F_OnLoad::
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	goto_if_eq NUM_BOULDERS_PRESENT, 2, SeafoamIslands_B4F_EventScript_SetCalmWaterNearStairs
	end

SeafoamIslands_B4F_EventScript_SetCalmWaterNearStairs::
	setmetatile 12, 14, METATILE_General_CalmWater, 0
	setmetatile 13, 14, METATILE_General_CalmWater, 0
	end

SeafoamIslands_B4F_OnWarp::
	map_script_2 VAR_SEAFOAM_ISLANDS_STATE, 1, SeafoamIslands_B4F_EventScript_WarpInOnCurrent
	.2byte 0

SeafoamIslands_B4F_EventScript_WarpInOnCurrent::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	special ForcePlayerToStartSurfing
	end

SeafoamIslands_B4F_OnFrame::
	map_script_2 VAR_SEAFOAM_ISLANDS_STATE, 1, SeafoamIslands_B4F_EventScript_EnterOnCurrent
	map_script_2 VAR_TEMP_1, 1, SeafoamIslands_B4F_EventScript_EnterByFalling
	.2byte 0

@ The current the player is forced in on from B3F
SeafoamIslands_B4F_EventScript_EnterOnCurrent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_EnterOnCurrent
	waitmovement 0
	setvar VAR_SEAFOAM_ISLANDS_STATE, 0
	releaseall
	end

SeafoamIslands_B4F_Movement_EnterOnCurrent::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ The current the player lands on when entering the map by falling
SeafoamIslands_B4F_EventScript_EnterByFalling::
	lockall
	setvar NUM_BOULDERS_PRESENT, 0
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_1, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	call_if_unset FLAG_HIDE_SEAFOAM_B4F_BOULDER_2, SeafoamIslands_B4F_EventScript_AddBoulderPresent
	compare NUM_BOULDERS_PRESENT, 2
	goto_if_eq SeafoamIslands_B4F_EventScript_CurrentBlocked
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_lt SeafoamIslands_B4F_EventScript_RideCurrentFar
	compare VAR_0x8008, 9
	call_if_ge SeafoamIslands_B4F_EventScript_RideCurrentClose
	special SeafoamIslandsB4F_CurrentDumpsPlayerOnLand
	setvar VAR_TEMP_1, 0
	releaseall
	end

SeafoamIslands_B4F_EventScript_AddBoulderPresent::
	addvar NUM_BOULDERS_PRESENT, 1
	return

SeafoamIslands_B4F_EventScript_RideCurrentFar::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_RideCurrentFar
	waitmovement 0
	return

SeafoamIslands_B4F_EventScript_RideCurrentClose::
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_RideCurrentClose
	waitmovement 0
	return

SeafoamIslands_B4F_EventScript_CurrentBlocked::
	setvar VAR_TEMP_1, 0
	releaseall
	end

SeafoamIslands_B4F_Movement_RideCurrentFar::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SeafoamIslands_B4F_Movement_RideCurrentClose::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

@ Triggers blocking re-entry to B3F
SeafoamIslands_B4F_EventScript_UpwardCurrent::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, SeafoamIslands_B4F_Movement_WalkUp
	waitmovement 0
	releaseall
	end

SeafoamIslands_B4F_Movement_WalkUp::
	walk_up
	step_end

SeafoamIslands_B4F_EventScript_BoulderHintSign::
	msgbox SeafoamIslands_B4F_Text_BouldersMightChangeWaterFlow, MSGBOX_SIGN
	end

SeafoamIslands_B4F_Text_BouldersMightChangeWaterFlow::
    .string "Hint: Boulders might change the\n"
    .string "flow of water.$"

SeafoamIslands_B4F_EventScript_FastCurrentSign::
	msgbox SeafoamIslands_B4F_Text_DangerFastCurrent, MSGBOX_SIGN
	end
	
SeafoamIslands_B4F_Text_DangerFastCurrent::
    .string "DANGER\n"
    .string "Fast current!$"


