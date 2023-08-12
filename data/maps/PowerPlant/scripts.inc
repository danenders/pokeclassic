.set LOCALID_ZAPDOS, 1

PowerPlant_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	.byte 0

PowerPlant_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PowerPlant_EventScript_TryRemoveZapdos
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, PowerPlant_EventScript_TryRemoveElectrode
	end

PowerPlant_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject VAR_LAST_TALKED
	return

PowerPlant_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	call_if_unset FLAG_DEFEATED_POWER_PLANT_ELECTRODE_1, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_POWER_PLANT_ELECTRODE_2, PowerPlant_EventScript_ShowElectrode2
	call_if_set FLAG_CAUGHT_ZAPDOS, PowerPlant_EventScript_HideZapdos
	call_if_unset FLAG_CAUGHT_ZAPDOS, PowerPlant_EventScript_TryShowZapdos
	end

PowerPlant_EventScript_ShowElectrode1::
	clearflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_1
	return

PowerPlant_EventScript_ShowElectrode2::
	clearflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_2
	return

PowerPlant_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 25
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON,PowerPlant_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_1
	release
	end

PowerPlant_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_1
	goto Common_EventScript_RemoveStaticPokemon
	end

PowerPlant_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 25
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_2
	release
	end

PowerPlant_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_POWER_PLANT_ELECTRODE_2
	goto Common_EventScript_RemoveStaticPokemon
	end

PowerPlant_EventScript_HideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_TryShowZapdos::
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_Return
	clearflag FLAG_HIDE_ZAPDOS
	return

PowerPlant_EventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_Return
	removeobject LOCALID_ZAPDOS
	return

PowerPlant_EventScript_Zapdos::
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
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZAPDOS, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

PowerPlant_EventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

PowerPlant_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

PowerPlant_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION, 1
	release
	end

PowerPlant_EventScript_ItemTM25::
	finditem ITEM_TM25, 1
	release
	end

PowerPlant_EventScript_ItemTM17::
	finditem ITEM_TM17, 1
	release
	end

PowerPlant_EventScript_ItemElixir::
	finditem ITEM_ELIXIR, 1
	release
	end

PowerPlant_EventScript_ItemThunderStone::
	finditem ITEM_THUNDER_STONE, 1
	release
	end
