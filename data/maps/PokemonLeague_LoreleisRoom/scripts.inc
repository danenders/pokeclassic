PokemonLeague_LoreleisRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LoreleisRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LoreleisRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_LoreleisRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LoreleisRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LoreleisRoom_OnFrame
	.byte 0

PokemonLeague_LoreleisRoom_OnResume::
	setvar VAR_0x8004, 0
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LoreleisRoom_OnLoad::
	call_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 1
	call_if_eq PokemonLeague_LoreleisRoom_EventScript_CloseEntry
	end

PokemonLeague_LoreleisRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_LoreleisRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_LoreleisRoom_OnTransition::
	end

PokemonLeague_LoreleisRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_LoreleisRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 0, PokemonLeague_LoreleisRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LoreleisRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

PokemonLeague_LoreleisRoom_EventScript_Lorelei::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LORELEI, PokemonLeague_LoreleisRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_LoreleiPostgame
	msgbox PokemonLeague_LoreleisRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_Text_Intro::
    .string "Welcome to the Pokémon League.\p"
    .string "I am Lorelei of the Elite Four.\p"
    .string "No one can best me when it comes\n"
    .string "to icy Pokémon.\p"
    .string "Freezing moves are powerful.\p"
    .string "Your Pokémon will be at my mercy\n"
    .string "when they are frozen solid.\p"
    .string "Hahaha!\n"
    .string "Are you ready?$"

PokemonLeague_LoreleisRoom_Text_Defeat::
    .string "…Things shouldn't be this way!$"

PokemonLeague_LoreleisRoom_EventScript_LoreleiPostgame::
	msgbox PokemonLeague_LoreleisRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_LORELEI, PokemonLeague_LoreleisRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei
	end

PokemonLeague_LoreleisRoom_Text_Intro2::
    .string "Welcome to the Pokémon League!\p" 
    .string "Hey, fantastic timing!\p" 
    .string "I was just thinking how I'd like to\n"
    .string "battle you. I hope you're ready.$"

PokemonLeague_LoreleisRoom_Text_Defeat2::
	.string "Argh! How?!$"

PokemonLeague_LoreleisRoom_EventScript_DefeatedLorelei::
	setflag FLAG_DEFEATED_LORELEI
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LoreleisRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle
	release
	end

PokemonLeague_LoreleisRoom_Text_PostBattle::
    .string "You're better than I thought.\n"
    .string "Go on ahead.\p"
    .string "You only got a taste of the\n"
    .string "Pokémon League's power.$"

PokemonLeague_LoreleisRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_LoreleisRoom_Text_PostBattle2
	release
	end

PokemonLeague_LoreleisRoom_Text_PostBattle2::
    .string "I may have lost, but I'll never\n" 
    .string "give up on my Ice-type Pokémon!\p" 
    .string "You should aim to win using\n"
    .string "Pokémon you like best, too!$"
