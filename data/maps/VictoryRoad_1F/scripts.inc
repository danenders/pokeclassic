VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

VictoryRoad_1F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_1F_STATE, 100, VictoryRoad_1F_EventScript_SetRockBarrier
	end

VictoryRoad_1F_EventScript_SetRockBarrier::
	setmetatile 12, 14, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 15, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_1F_OnTransition::
	end

VictoryRoad_1F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_1F_STATE, 100, VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 14, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 15, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 5
	setvar VAR_VICTORY_ROAD_1F_STATE, 100
	releaseall
	end

VictoryRoad_1F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_1F_EventScript_Naomi::
	trainerbattle_single TRAINER_COOLTRAINER_NAOMI, VictoryRoad_1F_Text_NaomiIntro, VictoryRoad_1F_Text_NaomiDefeat
	msgbox VictoryRoad_1F_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_NaomiIntro::
    .string "I wonder if you are good enough\n"
    .string "for me?$"

VictoryRoad_1F_Text_NaomiDefeat::
    .string "I lost out…$"

VictoryRoad_1F_Text_NaomiPostBattle::
    .string "I never wanted to lose to anybody,\n"
    .string "especially to a younger kid…$"

VictoryRoad_1F_EventScript_Rolando::
	trainerbattle_single TRAINER_COOLTRAINER_ROLANDO, VictoryRoad_1F_Text_RolandoIntro, VictoryRoad_1F_Text_RolandoDefeat
	msgbox VictoryRoad_1F_Text_RolandoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_RolandoIntro::
    .string "I can see you're good.\n"
    .string "Let me see exactly how good!$"

VictoryRoad_1F_Text_RolandoDefeat::
    .string "I had a chance…$"

VictoryRoad_1F_Text_RolandoPostBattle::
    .string "Tch!\n"
    .string "I concede, you are better than I!$"

VictoryRoad_1F_EventScript_ItemTM02::
	finditem ITEM_TM02, 1
	release
	end

VictoryRoad_1F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end
