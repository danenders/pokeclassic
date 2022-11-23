.set LOCALID_BRUNO, 1

PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_BrunosRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_BrunosRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_BrunosRoom_OnFrame
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 1
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_BrunosRoom_OnLoad::
	call_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_SetDoorOpen
	compare VAR_ELITE_4_STATE, 2
	call_if_eq PokemonLeague_BrunosRoom_EventScript_CloseEntry
	end

PokemonLeague_BrunosRoom_EventScript_CloseEntry::
	call PokemonLeague_EventScript_CloseEntry
	return

PokemonLeague_BrunosRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpen
	return

PokemonLeague_BrunosRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_BrunosRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 1, PokemonLeague_BrunosRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_BrunosRoom_EventScript_EnterRoom::
	lockall
	call PokemonLeague_EventScript_EnterRoom
	setvar VAR_ELITE_4_STATE, 2
	releaseall
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BRUNO, PokemonLeague_BrunosRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_BrunoPostgame
	msgbox PokemonLeague_BrunosRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat
	clearflag FLAG_TEMP_5
	goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
	end

PokemonLeague_BrunosRoom_EventScript_BrunoPostgame::
	msgbox PokemonLeague_BrunosRoom_Text_Intro2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_BRUNO, PokemonLeague_BrunosRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	goto PokemonLeague_BrunosRoom_EventScript_DefeatedBruno
	end

PokemonLeague_BrunosRoom_EventScript_DefeatedBruno::
	setflag FLAG_DEFEATED_BRUNO
	call PokemonLeague_EventScript_OpenDoor
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_PostBattle2
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_BrunosRoom_EventScript_PostBattle2
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_BrunosRoom_Text_PostBattle2
	closemessage
	goto PokemonLeague_BrunosRoom_EventScript_BrunoLookAway
	end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAway::
	call_if_eq VAR_FACING, DIR_NORTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayLeft::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 1
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayRight::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterRight
	waitmovement 1
	return

PokemonLeague_BrunosRoom_EventScript_BrunoLookAwayDown::
	applymovement LOCALID_BRUNO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 1
	return

PokemonLeague_BrunosRoom_Text_Intro::
    .string "I am Bruno of the Elite Four!\p"
    .string "Through rigorous training, people\n"
    .string "and Pokémon can become stronger\l"
    .string "without limit.\p"
    .string "I've lived and trained with my\n"
    .string "fighting Pokémon!\l"
    .string "And that will never change!\p"
    .string "{PLAYER}!\p"
    .string "We will grind you down with our\n"
    .string "superior power!\p"
    .string "Hoo hah!$"

PokemonLeague_BrunosRoom_Text_Intro2::
    .string "I could feel the intensity of your\n"
    .string "battle with Lorelei, even from here!\p" 
    .string "Now it's time to show you the power\n" 
    .string "of my Fighting-type Pokémon, who I've\l" 
    .string "been training just as hard as you've\l" 
    .string "trained your team, surely!\p" 
    .string "Hoo hah! Hoo! HAH!!!$"

PokemonLeague_BrunosRoom_Text_Defeat::
    .string "Why?\n"
    .string "How could I lose?$"

PokemonLeague_BrunosRoom_Text_Defeat2::
    .string "I have regrets!$"

PokemonLeague_BrunosRoom_Text_PostBattle::
    .string "My job is done.\n"
    .string "Go face your next challenge.$"

PokemonLeague_BrunosRoom_Text_PostBattle2::
    .string "Ugh! No! So my training is still\n" 
    .string "lacking, is that it?\p"
    .string "...Go.\p"
    .string "Do not trouble yourself on my behalf.\n" 
    .string "Continue to move forward!$"
