.set LOCALID_NURSE, 1
.set LOCALID_GUARD, 5

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "At the Pokémon League, you will\n"
    .string "face the Elite Four all in a row.\p"
    .string "If you lose, you have to start all\n"
    .string "over again!\p"
    .string "This is it!\n"
    .string "Go for it!$"

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
    lock
    faceplayer
    goto_if_unset FLAG_SYS_GAME_CLEAR, IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge
    msgbox IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion, MSGBOX_NPC
    goto_if_unset FLAG_DAILY_TITLE_MATCH, IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame
    end

IndigoPlateau_PokemonCenter_1F_Text_GreetingsChampion::
	.string "Hello, Champion {PLAYER}!$"
	
IndigoPlateau_PokemonCenter_1F_EventScript_TitleMatch::
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_ExclamationMark
	waitmovement 5
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Challenger, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
	setflag FLAG_DAILY_TITLE_MATCH
	setvar VAR_TITLE_MATCH_OPPONENT, 0
	addvar VAR_TITLE_MATCHES, 1
	call ClearTitleMatches
	msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

ClearTitleMatches::
	cleartrainerflag TITLE_MATCH_STEPH
	cleartrainerflag TITLE_MATCH_LIZ
	cleartrainerflag TITLE_MATCH_MIKE
	cleartrainerflag TITLE_MATCH_CHRIS
	cleartrainerflag TITLE_MATCH_KEV
	cleartrainerflag TITLE_MATCH_MEGHAN
	cleartrainerflag TITLE_MATCH_STEVE
	cleartrainerflag TITLE_MATCH_M
	cleartrainerflag TITLE_MATCH_BEAN
	cleartrainerflag TITLE_MATCH_ANNIE
	cleartrainerflag TITLE_MATCH_BROCK
	cleartrainerflag TITLE_MATCH_MISTY
	cleartrainerflag TITLE_MATCH_SURGE
	cleartrainerflag TITLE_MATCH_ERIKA
	cleartrainerflag TITLE_MATCH_SABRINA
	cleartrainerflag TITLE_MATCH_KOGA
	cleartrainerflag TITLE_MATCH_BLAINE
	cleartrainerflag TITLE_MATCH_ROCKET
	cleartrainerflag TITLE_MATCH_DAISY
	cleartrainerflag TITLE_MATCH_RIVAL_VAPOREON
	cleartrainerflag TITLE_MATCH_RIVAL_JOLTEON
	cleartrainerflag TITLE_MATCH_RIVAL_FLAREON
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourPostGame::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 2
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_Text_Challenger::
	.string "Oh! It seems someone has defeated the\n"
	.string "Elite Four today.\p"
	.string "They are challenging you to a Title Match!\n"
	.string "Are you here to accept their challenge?$"

IndigoPlateau_PokemonCenter_1F_EventScript_EliteFourFirstChallenge::
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, IndigoPlateau_PokemonCenter_1F_EventScript_Decline
    msgbox IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck, MSGBOX_DEFAULT
    setvar VAR_ELITE_4_MODE, 1
    goto IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour
    end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEliteFour::
	call_if_eq VAR_FACING, DIR_NORTH, IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth
	call_if_eq VAR_FACING, DIR_WEST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest
	call_if_eq VAR_FACING, DIR_EAST, IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast
	goto_if_eq VAR_ELITE_4_MODE, 0, IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch
	warp MAP_POKEMON_LEAGUE_LORELEIS_ROOM, 6, 12
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_WarpTitleMatch::
	warp MAP_POKEMON_LEAGUE_CHALLENGER_ROOM, 6, 3
	waitstate
	end

IndigoPlateau_PokemonCenter_1F_EventScript_EnterNorth::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterNorth
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterWest::
	applymovement LOCALID_GUARD, Guard_Movement_StepLeft
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterWest
	waitmovement 0
	return

IndigoPlateau_PokemonCenter_1F_EventScript_EnterEast::
	applymovement LOCALID_GUARD, Guard_Movement_StepRight
	waitmovement 5
	applymovement OBJ_EVENT_ID_PLAYER, Player_Movement_EnterEast
	waitmovement 0
	return

Guard_Movement_StepRight:
	walk_right
	face_down
	step_end

Guard_Movement_StepLeft:
	walk_left
	face_down
	step_end

Player_Movement_EnterNorth:
	walk_up
	walk_up
	set_invisible
	step_end

Player_Movement_EnterWest:
	walk_left
	walk_up
	set_invisible
	step_end

Player_Movement_EnterEast:
	walk_right
	walk_up
	set_invisible
	step_end

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFour::
    .string "From here on, you face the\n"
    .string "Elite Four one by one.\p"
    .string "If you win, a door opens to the\n"
    .string "next trainer.\p"
    .string "You cannot return until you have\n"
    .string "defeated them all, or have failed.\p"
    .string "Are you prepared for the challenge?$"

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourPostGame::
    .string "As the Champion, you can challenge\n"
    .string "the Elite Four to exhibition battles.\p"
    .string "Be warned, though.\p"
    .string "Now that you have already proven your\n"
    .string "skills, they will not be holding back.\p"
    .string "Are you prepared for the challenge?$"

IndigoPlateau_PokemonCenter_1F_EventScript_Decline::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GuardDecline, MSGBOX_DEFAULT
	turnobject LOCALID_GUARD, DIR_SOUTH
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_GuardDecline::
	.string "I understand.\n"
	.string "Please see me if you change your mind.$"

IndigoPlateau_PokemonCenter_1F_Text_ExcellentGoodLuck::
	.string "Excellent!\n"
	.string "Good luck!$"

IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
    .string "Agatha's Ghost type Pokémon are\n"
    .string "horrifically terrifying in toughness.\p"
    .string "I took my Fighting type Pokémon\n"
    .string "and raised them to the max.\p"
    .string "I went at Agatha feeling pretty\n"
    .string "confident, but she whupped us.\p"
    .string "That old lady's also got a really\n"
    .string "short fuse, too.\p"
    .string "It doesn't take anything to get\n"
    .string "that scary lady hollering.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Dragontamer::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
    .string "Maybe becoming an Elite Four\n"
    .string "member is in the blood.\p"
    .string "From what I've heard, Lance has\n"
    .string "a cousin who's a Gym Leader\l"
    .string "somewhere far away.$"

IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal::
	lock
	faceplayer
	msgbox PokemonJournal_Text_SpecialFeatureLance
	release
	end

PokemonJournal_Text_SpecialFeatureLance::
	.string "Pokémon Journal\p"
	.string "Special Feature:\n"
	.string "Elite Four's Lance!\p"
	.string "Lance's grandfather is thought to\n"
	.string "be the elder of a famous clan of\l"
	.string "dragon masters.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end


IndigoPlateau_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BATTLE_BERRY, IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	msgbox IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters MSGBOX_NPC
	random 3
	call_if_eq VAR_RESULT, 0, IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 1, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry
	call_if_eq VAR_RESULT, 2, IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry
	setflag FLAG_DAILY_BATTLE_BERRY
	goto IndigoPlateau_PokemonCenter_1F_EventScript_Determination
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLumBerry::
	giveitem ITEM_LUM_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_EventScript_GiveLeppaBerry::
	giveitem ITEM_LEPPA_BERRY, 1
	return

IndigoPlateau_PokemonCenter_1F_Text_NoPokeCenters::
	.string "When you take on the Elite Four, you\n"
	.string "won't be able to return to the Pokémon\l"
	.string "Center to heal!\p"
	.string "A berry like this could make all the\n"
	.string "difference!$"

IndigoPlateau_PokemonCenter_1F_EventScript_Determination::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_Determination, MSGBOX_NPC
	release
	end

IndigoPlateau_PokemonCenter_1F_Text_Determination::
	.string "It takes every thing you have to\n"
	.string "to take on the Elite Four!\p"
	.string "I hope you're filled with determination!$"
