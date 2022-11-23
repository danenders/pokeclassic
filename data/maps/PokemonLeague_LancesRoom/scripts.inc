.set LOCALID_LANCE, 1

PokemonLeague_LancesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LancesRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LancesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LancesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LancesRoom_OnFrame
	.byte 0

PokemonLeague_LancesRoom_OnResume::
	setvar VAR_0x8004, 3
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LancesRoom_OnLoad::
	compare VAR_ELITE_4_STATE, 4
	call_if_eq PokemonLeague_LancesRoom_EventScript_CloseEntry
	call_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	end

PokemonLeague_LancesRoom_EventScript_CloseEntry::
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	return

PokemonLeague_LancesRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpenLance
	return

PokemonLeague_LancesRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_LancesRoom_OnFrame::
	map_script_2 VAR_ELITE_4_STATE, 3, PokemonLeague_LancesRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LancesRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_LancesRoom_Movement_WalkThroughCorridor
	waitmovement 0
	setflag FLAG_TEMP_2
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

PokemonLeague_LancesRoom_EventScript_SetEntryClosed::
	setmetatile 5, 14, METATILE_PokemonLeague_Entry_TopLeft_Closed, 1
	setmetatile 6, 14, METATILE_PokemonLeague_Entry_TopMid_Closed, 1
	setmetatile 7, 14, METATILE_PokemonLeague_Entry_TopRight_Closed, 1
	setmetatile 5, 15, METATILE_PokemonLeague_Entry_BottomLeft_Closed, 1
	setmetatile 6, 15, METATILE_PokemonLeague_Entry_BottomMid_Closed, 1
	setmetatile 7, 15, METATILE_PokemonLeague_Entry_BottomRight_Closed, 1
	setmetatile 6, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	setmetatile 7, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	return

PokemonLeague_LancesRoom_Movement_WalkThroughCorridor::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_LancesRoom_EventScript_Lance::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_PostBattle
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_LancePostgame
	msgbox PokemonLeague_LancesRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat
	setdynamicwarp MAP_POKEMON_LEAGUE_CHAMPIONS_ROOM, 6, 19
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_LancePostgame::
	msgbox PokemonLeague_LancesRoom_Text_Intro2

	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro POSTGAME_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat2
	clearflag FLAG_TEMP_5
	setdynamicwarp MAP_POKEMON_LEAGUE_SECRET_BATTLE, 6, 19
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_DefeatedLance::
	setvar VAR_0x8004, 0
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_LANCE
	call PokemonLeague_EventScript_OpenDoorLance
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	closemessage
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle::
	goto_if_ge VAR_ELITE_4_MODE, 2, PokemonLeague_LancesRoom_EventScript_PostBattle2
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	release
	end

PokemonLeague_LancesRoom_EventScript_PostBattle2::
	msgbox PokemonLeague_LancesRoom_Text_PostBattle2
	release
	end

PokemonLeague_LancesRoom_Text_Intro::
    .string "Ah! I've heard about you,\n"
    .string "{PLAYER}!\p"
    .string "I lead the Elite Four.\p"
    .string "You can call me Lance the dragon\n"
    .string "master.\p"
    .string "You know that dragons are\n"
    .string "mythical Pokémon.\p"
    .string "They're hard to catch and raise,\n"
    .string "but their powers are superior.\p"
    .string "They're virtually indestructible.\n"
    .string "There's no being clever with them.\p"
    .string "Well, are you ready to lose?\p"
    .string "Your League challenge ends with\n"
    .string "me, {PLAYER}!$"

PokemonLeague_LancesRoom_Text_Intro2::
    .string "I'm glad you've come.\p" 
    .string "The Pokémon League's reputation has\n" 
    .string "really taken off!\p" 
    .string "It's all thanks to you.\p" 
    .string "I'd feel ashamed to call myself Lance\n" 
    .string "the Dragon Trainer if I didn't challenge\l" 
    .string "you to a battle!$"

PokemonLeague_LancesRoom_Text_Defeat::
    .string "That's it!\p"
    .string "I hate to admit it, but you are a\n"
    .string "Pokémon master!$"

PokemonLeague_LancesRoom_Text_Defeat2::
    .string "How could I be pushed to\n" 
    .string "such a point?$"

PokemonLeague_LancesRoom_Text_PostBattle::
    .string "I still can't believe my dragons\n"
    .string "lost to you, {PLAYER}.\p"
    .string "You are now the Pokémon League\n"
    .string "Champion!\p"
    .string "…Or, you would have been, but\n"
    .string "you have one more challenge left.\p"
    .string "There is one more trainer to face!\n"
    .string "His name is…\p"
    .string "{RIVAL}!\p"
    .string "He beat the Elite Four before\n"
    .string "you.\p"
    .string "He is the real Pokémon League\n"
    .string "Champion.$"

PokemonLeague_LancesRoom_Text_PostBattle2::
    .string "My dragon brigade is not weak.\p" 
    .string "...What I'm saying is that means your\n" 
    .string "strength is truly incredible!\p" 
    .string "Now then, {PLAYER}!\p" 
    .string "You have defeated the Elite Four once\n"
    .string "again, but one last challenge awaits!\p"
    .string "We've arranged a special challenge\n"
    .string "for you, Champion!$"
