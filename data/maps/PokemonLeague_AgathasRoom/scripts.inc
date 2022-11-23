PokemonLeague_AgathasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_AgathasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_AgathasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_AgathasRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_AgathasRoom_OnFrame
	.byte 0

PokemonLeague_AgathasRoom_OnResume::
	setvar VAR_0x8004, 2
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_AgathasRoom_OnLoad::
	call_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 3
	call_if_eq PokemonLeague_AgathasRoom_EventScript_CloseEntry
	end

PokemonLeague_AgathasRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_AgathasRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_AgathasRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_AgathasRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 2, PokemonLeague_AgathasRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_AgathasRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 3
	releaseall
	end

PokemonLeague_AgathasRoom_EventScript_Agatha::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AGATHA, PokemonLeague_AgathasRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_AgathaPostgame
	msgbox PokemonLeague_AgathasRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_AgathaPostgame::
	msgbox PokemonLeague_AgathasRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_AGATHA, PokemonLeague_AgathasRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha
	end

PokemonLeague_AgathasRoom_EventScript_DefeatedAgatha::
	setflag FLAG_DEFEATED_AGATHA
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_AgathasRoom_EventScript_PostBattle2
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle
	release
	end

PokemonLeague_AgathasRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_AgathasRoom_Text_PostBattle2
	release
	end

PokemonLeague_AgathasRoom_Text_Intro::
    .string "I am Agatha of the Elite Four.\p"
    .string "I hear Oak's taken a lot of\n"
    .string "interest in you, child.\p"
    .string "That old duff was once tough and\n"
    .string "handsome.\p"
    .string "But that was decades ago.\n"
    .string "He's a shadow of his former self.\p"
    .string "Now he just wants to fiddle with\n"
    .string "his Pokédex.\p"
    .string "He's wrong.\n"
    .string "Pokémon are for battling!\p"
    .string "{PLAYER}! I'll show you how a real\n"
    .string "trainer battles!$"

PokemonLeague_AgathasRoom_Text_Intro2::
    .string "So you've come!\p" 
    .string "It's not in my character to\n"
    .string "lose over and over.\p" 
    .string "Give this battle everything you've\n" 
    .string "got!$"

PokemonLeague_AgathasRoom_Text_Defeat::
    .string "Oh, my!\n"
    .string "You're something special, child!$"

PokemonLeague_AgathasRoom_Text_Defeat2::
    .string "Not bad!$"

PokemonLeague_AgathasRoom_Text_PostBattle::
    .string "You win!\p"
    .string "I see what the old duff sees in\n"
    .string "you now.\p"
    .string "I have nothing else to say.\n"
    .string "Run along now, child!$"

PokemonLeague_AgathasRoom_Text_PostBattle2::
    .string "Small wonder that old-timer's taken\n" 
    .string "such an interest in you.\p" 
    .string "Oak and I used to be good rivals, too,\n" 
    .string "you know. Just like you and {RIVAL}.\p" 
    .string "Well, what are you waiting for?\n" 
    .string "Head on to the next room!$"
