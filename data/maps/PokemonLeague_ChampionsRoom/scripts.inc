.equ LOCALID_RIVAL,    1
.equ LOCALID_PROF_OAK, 2

PokemonLeague_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerJolteon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerFlareon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerVaporeon::
	goto_if_defeated TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	setflag FLAG_TEMP_2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_RG_VICTORY_GYM_LEADER
	call PokemonLeague_ChampionsRoom_EventScript_Battle
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_RIVAL_CHAMPION
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 255, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonLeague_ChampionsRoom_EventScript_BattleJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonLeague_ChampionsRoom_EventScript_BattleFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon
	return

PokemonLeague_ChampionsRoom_EventScript_BattleJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_JOLTEON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_FLAREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_CHAMPION_VAPOREON, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end


PokemonLeague_ChampionsRoom_Text_Intro::
    .string "{RIVAL}: Hey, {PLAYER}!\p"
    .string "I was looking forward to seeing\n"
    .string "you, {PLAYER}.\p"
    .string "My rival should be strong to keep\n"
    .string "me sharp.\p"
    .string "While working on my Pokédex, I\n"
    .string "looked all over for Pokémon.\p"
    .string "Not only that, I assembled teams\n"
    .string "that would beat any Pokémon type.\p"
    .string "And now…\p"
    .string "I'm the Pokémon League Champion!\p"
    .string "{PLAYER}!\n"
    .string "Do you know what that means?\p"
    .string "I'll tell you.\p"
    .string "I am the most powerful trainer in\n"
    .string "the world!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
    .string "NO!\n"
    .string "That can't be!\l"
    .string "You beat me at my best!\p"
    .string "After all that work to become\n"
    .string "the League Champ?\p"
    .string "My reign is over already?\n"
    .string "It's not fair!$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
    .string "Why?\n"
    .string "Why did I lose?\p"
    .string "I never made any mistakes raising\n"
    .string "my Pokémon…\p"
    .string "Darn it! You're the new Pokémon\n"
    .string "League Champion!\p"
    .string "Although I don't like to admit it…$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
    .string "Oak: {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
    .string "Oak: So, you've won!\n"
    .string "Sincerely, congratulations!\p"
    .string "You're the new Pokémon League\n"
    .string "Champion!\p"
    .string "You've grown up so much since you\n"
    .string "first left with Pikachu to work\l"
    .string "on the Pokédex.\p"
    .string "{PLAYER}, you have come of age!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
    .string "Oak: {RIVAL}…\n"
    .string "I'm disappointed in you.\p"
    .string "I came when I heard you'd beaten\n"
    .string "the Elite Four.\p"
    .string "But, when I got here, you had\n"
    .string "already lost!\p"
    .string "{RIVAL}, do you understand why\n"
    .string "you lost?\p"
    .string "You have forgotten to treat your\n"
    .string "Pokémon with love and trust.\p"
    .string "Without them, you will never\n"
    .string "become a Champ again!$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
    .string "Oak: {PLAYER}.\p"
    .string "You understand that your victory\n"
    .string "was not just your own doing.\p"
    .string "The bond you share with your\n"
    .string "Pokémon is marvelous.\p"
    .string "{PLAYER}!\n"
    .string "Come with me!$"
