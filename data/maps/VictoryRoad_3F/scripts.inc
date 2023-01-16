VictoryRoad_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_VICTORY_ROAD_3F_STATE, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm 7
	copyobjectxytoperm 10
	setvar VAR_VICTORY_ROAD_3F_STATE, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_GeorgeIntro::
    .string "I heard rumors of a child prodigy.$"

VictoryRoad_3F_Text_GeorgeDefeat::
    .string "The rumors were true!$"

VictoryRoad_3F_Text_GeorgePostBattle::
    .string "So, it was you who beat Giovanni\n"
    .string "of Team Rocket?$"

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_ColbyIntro::
    .string "Only the chosen can pass here!$"

VictoryRoad_3F_Text_ColbyDefeat::
    .string "I don't believe it!$"

VictoryRoad_3F_Text_ColbyPostBattle::
    .string "All Trainers here are headed to\n"
    .string "the Pokémon League.\p"
    .string "Don't let down your guard.$"

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_CarolineIntro::
    .string "I'll show you just how good you\n"
    .string "are. Not!$"

VictoryRoad_3F_Text_CarolineDefeat::
    .string "I'm furious!$"

VictoryRoad_3F_Text_CarolinePostBattle::
    .string "You showed me just how good\n"
    .string "I was…$"

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_AlexaIntro::
    .string "Trainers live to seek stronger\n"
    .string "opponents.$"

VictoryRoad_3F_Text_AlexaDefeat::
    .string "Oh!\n"
    .string "So strong!$"

VictoryRoad_3F_Text_AlexaPostBattle::
    .string "By fighting tough battles, you get\n"
    .string "stronger.$"

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_RayIntro::
    .string "Ray: Together, the two of us are\n"
    .string "destined for greatness!$"

VictoryRoad_3F_Text_RayDefeat::
    .string "Ray: Ludicrous!\n"
    .string "This can't be!$"

VictoryRoad_3F_Text_RayPostBattle::
    .string "Ray: You've beaten us.\n"
    .string "Greatness remains elusive…$"

VictoryRoad_3F_Text_RayNotEnoughMons::
    .string "Ray: Together, the two of us are\n"
    .string "striving for the pinnacle.\p"
    .string "We need you to bring two Pokémon\n"
    .string "into battle with us.$"

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_Text_TyraIntro::
    .string "Tyra: We're trying to become\n"
    .string "champions together.$"

VictoryRoad_3F_Text_TyraDefeat::
    .string "Tyra: Oh, but…$"

VictoryRoad_3F_Text_TyraPostBattle::
    .string "Tyra: You've taught me that power\n"
    .string "can be infinite in shape and form.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
    .string "Tyra: You can't battle with us if\n"
    .string "you have only one Pokémon.$"

VictoryRoad_3F_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

VictoryRoad_3F_EventScript_ItemTM50::
	finditem ITEM_TM50, 1
	release
	end

VictoryRoad_3F_EventScript_ItemPowerStone::
	finditem ITEM_POWER_STONE, 1
	release
	end
