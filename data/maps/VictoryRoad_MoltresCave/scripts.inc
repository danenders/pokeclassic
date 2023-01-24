.set LOCALID_MOLTRES, 1

VictoryRoad_MoltresCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_MoltresCave_OnResume
	.byte 0

VictoryRoad_MoltresCave_HeatRock::
	finditem ITEM_HEAT_ROCK, 1
	release
	end

VictoryRoad_MoltresCave_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_MoltresCave_EventScript_TryRemoveMoltres
	end

VictoryRoad_MoltresCave_OnTransition:
	call_if_set FLAG_CAUGHT_MOLTRES, VictoryRoad_MoltresCave_EventScript_HideMoltres
	call_if_unset FLAG_CAUGHT_MOLTRES, VictoryRoad_MoltresCave_EventScript_TryShowMoltres
	end

VictoryRoad_MoltresCave_EventScript_HideMoltres::
	setflag FLAG_HIDE_MOLTRES
	return

VictoryRoad_MoltresCave_EventScript_TryShowMoltres::
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_Return
	clearflag FLAG_HIDE_MOLTRES
	return

VictoryRoad_MoltresCave_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_MOLTRES
	return

VictoryRoad_MoltresCave_EventScript_Moltres::
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
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MOLTRES, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_MoltresCave_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_MoltresCave_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_MoltresCave_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

VictoryRoad_MoltresCave_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

VictoryRoad_MoltresCave_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
