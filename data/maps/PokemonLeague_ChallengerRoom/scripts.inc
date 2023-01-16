.set LOCALID_OPPONENT, 1

PokemonLeague_ChallengerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TitleMatch_Heal
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonLeague_ChallengerRoom_OnTransition
	@map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChallengerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChallengerRoom_OnFrame
	.byte 0

TitleMatch_Heal::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	end

PokemonLeague_ChallengerRoom_OnTransition::
	call_if_eq VAR_TITLE_MATCH_OPPONENT, 0, PokemonLeague_ChallengerRoom_SelectOpponent
	return


PokemonLeague_ChallengerRoom_SelectOpponent::
	call_if_ne VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_StandardOpponent
	call_if_eq VAR_TITLE_MATCHES, 3, PokemonLeague_ChallengerRoom_SpecialOpponent
	return

PokemonLeague_ChallengerRoom_StandardOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Steph
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Liz
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Mike
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Chris
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Kev
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Meghan
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Steve
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_M
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Bean
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Annie
	return

PokemonLeague_ChallengerRoom_SpecialOpponent::
	random 9
	addvar VAR_RESULT, 1
	call_if_eq VAR_RESULT, 1, PokemonLeague_ChallengerRoom_Setup_Brock
	call_if_eq VAR_RESULT, 2, PokemonLeague_ChallengerRoom_Setup_Misty
	call_if_eq VAR_RESULT, 3, PokemonLeague_ChallengerRoom_Setup_Surge
	call_if_eq VAR_RESULT, 4, PokemonLeague_ChallengerRoom_Setup_Erika
	call_if_eq VAR_RESULT, 5, PokemonLeague_ChallengerRoom_Setup_Sabrina
	call_if_eq VAR_RESULT, 6, PokemonLeague_ChallengerRoom_Setup_Koga
	call_if_eq VAR_RESULT, 7, PokemonLeague_ChallengerRoom_Setup_Blaine
	call_if_eq VAR_RESULT, 8, PokemonLeague_ChallengerRoom_Setup_Rocket
	call_if_eq VAR_RESULT, 9, PokemonLeague_ChallengerRoom_Setup_Daisy
	call_if_eq VAR_RESULT, 10, PokemonLeague_ChallengerRoom_Setup_Rival
	return

PokemonLeague_ChallengerRoom_Setup_Steph::
	setvar VAR_TITLE_MATCH_OPPONENT, 1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_LASS
	return

PokemonLeague_ChallengerRoom_Setup_Liz::
	setvar VAR_TITLE_MATCH_OPPONENT, 2
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	return

PokemonLeague_ChallengerRoom_Setup_Mike::
	setvar VAR_TITLE_MATCH_OPPONENT, 3
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_COOL_TRAINER_M
	return

PokemonLeague_ChallengerRoom_Setup_Chris::
	setvar VAR_TITLE_MATCH_OPPONENT, 4
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_CUEBALL
	return

PokemonLeague_ChallengerRoom_Setup_Kev::
	setvar VAR_TITLE_MATCH_OPPONENT, 5
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_NINJA_BOY
	return

PokemonLeague_ChallengerRoom_Setup_Meghan::
	setvar VAR_TITLE_MATCH_OPPONENT, 6
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_HEX_MANIAC
	return

PokemonLeague_ChallengerRoom_Setup_Steve::
	setvar VAR_TITLE_MATCH_OPPONENT, 7
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DRAGON_TAMER
	return

PokemonLeague_ChallengerRoom_Setup_M::
	setvar VAR_TITLE_MATCH_OPPONENT, 8
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BUG_CATCHER
	return

PokemonLeague_ChallengerRoom_Setup_Bean::
	setvar VAR_TITLE_MATCH_OPPONENT, 9
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_YOUNGSTER
	return

PokemonLeague_ChallengerRoom_Setup_Annie::
	setvar VAR_TITLE_MATCH_OPPONENT, 10
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SCHOOL_KID_F
	return

PokemonLeague_ChallengerRoom_Setup_Brock::
	setvar VAR_TITLE_MATCH_OPPONENT, 11
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BROCK
	return

PokemonLeague_ChallengerRoom_Setup_Misty::
	setvar VAR_TITLE_MATCH_OPPONENT, 12
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MISTY
	return

PokemonLeague_ChallengerRoom_Setup_Surge::
	setvar VAR_TITLE_MATCH_OPPONENT, 13
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SURGE
	return

PokemonLeague_ChallengerRoom_Setup_Erika::
	setvar VAR_TITLE_MATCH_OPPONENT, 14
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ERIKA
	return

PokemonLeague_ChallengerRoom_Setup_Sabrina::
	setvar VAR_TITLE_MATCH_OPPONENT, 15
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SABRINA
	return

PokemonLeague_ChallengerRoom_Setup_Koga::
	setvar VAR_TITLE_MATCH_OPPONENT, 16
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KOGA
	return

PokemonLeague_ChallengerRoom_Setup_Blaine::
	setvar VAR_TITLE_MATCH_OPPONENT, 17
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLAINE
	return

PokemonLeague_ChallengerRoom_Setup_Rocket::
	setvar VAR_TITLE_MATCH_OPPONENT, 18
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_ROCKET_MEMBER_F
	return

PokemonLeague_ChallengerRoom_Setup_Daisy::
	setvar VAR_TITLE_MATCH_OPPONENT, 19
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_DAISY
	return

PokemonLeague_ChallengerRoom_Setup_Rival::
	setvar VAR_TITLE_MATCH_OPPONENT, 20
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BLUE
	return

PokemonLeague_ChallengerRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, PokemonLeague_ChallengerRoom_EnterScene
	.2byte 0

PokemonLeague_ChallengerRoom_EnterScene::
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, ChallengeRoom_PlayerEnter
	waitmovement 0
	applymovement LOCALID_OPPONENT, ChallengeRoom_OpponentEnter
	waitmovement 1
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 1, TitleMatch_Steph
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 2, TitleMatch_Liz
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 3, TitleMatch_Mike
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 4, TitleMatch_Chris
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 5, TitleMatch_Kev
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 6, TitleMatch_Meghan
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 7, TitleMatch_Steve
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 8, TitleMatch_M
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 9, TitleMatch_Bean
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 10, TitleMatch_Annie
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 11, TitleMatch_Brock
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 12, TitleMatch_Misty
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 13, TitleMatch_Surge
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 14, TitleMatch_Erika
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 15, TitleMatch_Sabrina
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 16, TitleMatch_Koga
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 17, TitleMatch_Blaine
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 18, TitleMatch_Rocket
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 19, TitleMatch_Daisy
	goto_if_eq VAR_TITLE_MATCH_OPPONENT, 20, TitleMatch_Rival
	end

ChallengeRoom_PlayerEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ChallengeRoom_OpponentEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TitleMatch_BattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TitleMatch_EventScript_Victory
	goto TitleMatch_EventScript_Defeat
	end

TitleMatch_EventScript_Victory::
	msgbox TitleMatch_Text_TitleMatchVictory, MSGBOX_DEFAULT
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	goto TitleMatch_EventScript_Exit
	end

TitleMatch_EventScript_Defeat::
	msgbox TitleMatch_Text_TitleMatchVictory, MSGBOX_DEFAULT
TitleMatch_EventScript_Exit::
	waitmessage
	closemessage
	applymovement LOCALID_OPPONENT, ChallengeRoom_PlayerEnter
	waitmovement 1
	warp MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F, 11, 14
	waitstate
	end


TitleMatch_Text_TitleMatchVictory::
	.string "The Title Match has concluded!\n"
	.string "{PLAYER} has won the match!$"

TitleMatch_Text_TitleMatchDefeated::
	.string "The Title Match has concluded!\n"
	.string "{PLAYER} has been defeated!\p"
	.string "Kanto has a new champion!$"

TitleMatch_Steph::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEPH, TitleMatch_Text_StephIntro, TitleMatch_Text_StephDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_StephIntro::
	.string "I'm ready!$"

TitleMatch_Text_StephDefeated::
	.string "Alright, I'm gonna head out.$"

TitleMatch_Liz::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_LIZ, TitleMatch_Text_LizIntro, TitleMatch_Text_LizDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_LizIntro::
	.string "I'm a genius.$"

TitleMatch_Text_LizDefeated::
	.string "Oh no!$"

TitleMatch_Mike::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MIKE, TitleMatch_Text_MikeIntro, TitleMatch_Text_MikeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MikeIntro::
	.string "My rival is Chris.$"

TitleMatch_Text_MikeDefeated::
	.string "I don't care if you win, as long\n"
	.string "as he loses.$"

TitleMatch_Chris::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_CHRIS, TitleMatch_Text_ChrisIntro, TitleMatch_Text_ChrisDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ChrisIntro::
	.string "It's not time for games!$"

TitleMatch_Text_ChrisDefeated::
	.string "Too scared!"

TitleMatch_Kev::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KEV, TitleMatch_Text_KevIntro, TitleMatch_Text_KevDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KevIntro::
	.string "I have the power of Pokémon\n"
	.string "on my side!$"

TitleMatch_Text_KevDefeated::
	.string "No! I should have used my full power!$"

TitleMatch_Meghan::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MEGHAN, TitleMatch_Text_MeghanIntro, TitleMatch_Text_MeghanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MeghanIntro::
	.string "It is no longer possible to log off.$"

TitleMatch_Text_MeghanDefeated::
	.string "Hit the bricks!$"

TitleMatch_Steve::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_STEVE, TitleMatch_Text_SteveIntro, TitleMatch_Text_SteveDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SteveIntro::
	.string "Pokémon is all about power.$"

TitleMatch_Text_SteveDefeated::
	.string "Today was not my day.$"

TitleMatch_M::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_M, TitleMatch_Text_MIntro, TitleMatch_Text_MDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MIntro::
	.string "This is my swamp!$"

TitleMatch_Text_MDefeated::
	.string "Leave me alone!$"

TitleMatch_Bean::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BEAN, TitleMatch_Text_BeanIntro, TitleMatch_Text_BeanDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BeanIntro::
	.string "I won't tolerate bullies.$"

TitleMatch_Text_BeanDefeated::
	.string "You're tough! I like that!$"

TitleMatch_Annie::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ANNIE, TitleMatch_Text_AnnieIntro, TitleMatch_Text_AnnieDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_AnnieIntro::
	.string "I borrowed my mom's Pokémon.$"

TitleMatch_Text_AnnieDefeated::
	.string "Wahhhhhhh! I want my mommy!$"

TitleMatch_Brock::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BROCK, TitleMatch_Text_BrockIntro, TitleMatch_Text_BrockDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BrockIntro::
	.string "Brock: I'm on a roll!$"

TitleMatch_Text_BrockDefeated::
	.string "You've come a long way, {PLAYER}.$"

TitleMatch_Misty::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_MISTY, TitleMatch_Text_MistyIntro, TitleMatch_Text_MistyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_MistyIntro::
	.string "Misty: Hey, it's you!\p"
	.string "This champion thing should be\n"
	.string "easy, then.$"

TitleMatch_Text_MistyDefeated::
	.string "Ew! I can't believe I lost\n"
	.string "to you again!$"

TitleMatch_Surge::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SURGE, TitleMatch_Text_SurgeIntro, TitleMatch_Text_SurgeDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SurgeIntro::
	.string "Surge: Life's a war, kid.\p"
	.string "This is just another battlefield.$"

TitleMatch_Text_SurgeDefeated::
	.string "Back to basic training!$"

TitleMatch_Erika::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ERIKA, TitleMatch_Text_ErikaIntro, TitleMatch_Text_ErikaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_ErikaIntro::
	.string "Erika: Hello, {PLAYER}.\p"
	.string "Shall we battle again?$"

TitleMatch_Text_ErikaDefeated::
	.string "Looks like I lost again...$"

TitleMatch_Sabrina::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_SABRINA, TitleMatch_Text_SabrinaIntro, TitleMatch_Text_SabrinaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_SabrinaIntro::
	.string "Sabrina: I have forseen this battle.$"

TitleMatch_Text_SabrinaDefeated::
	.string "I knew it would end this way...$"

TitleMatch_Koga::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_KOGA, TitleMatch_Text_KogaIntro, TitleMatch_Text_KogaDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_KogaIntro::
	.string "Koga: I've decided to make my move\n"
	.string "and become one of the Elite Four.\p"
	.string "You are my only obstacle!$"

TitleMatch_Text_KogaDefeated::
	.string "I am still unworthy$"

TitleMatch_Blaine::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_BLAINE, TitleMatch_Text_BlaineIntro, TitleMatch_Text_BlaineDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_BlaineIntro::
	.string "Blaine: You got me all fired up!$"

TitleMatch_Text_BlaineDefeated::
	.string "Not hot enough!$"

TitleMatch_Rocket::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_ROCKET, TitleMatch_Text_RocketIntro, TitleMatch_Text_RocketDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RocketIntro::
	.string "We fought back at Silph Co.\p"
	.string "I'm trying to go straight.\n"
	.string "You inspired me to try and be\l"
	.string "a real trainer.$"

TitleMatch_Text_RocketDefeated::
	.string "I didn't deserve to win after\n"
	.string "all the terrible things I've done.$"

TitleMatch_Daisy::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_DAISY, TitleMatch_Text_DaisyIntro, TitleMatch_Text_DaisyDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_DaisyIntro::
	.string "Daisy: Hi, {PLAYER}!\p"
	.string "You and my brother were always\n"
	.string "talking about battling, so I\l"
	.string "decided to give a try.\p"
	.string "I guess I'm pretty good, too!$"

TitleMatch_Text_DaisyDefeated::
	.string "That was fun!$"

TitleMatch_Rival::
	goto_if_eq VAR_RIVAL_WINRATE, 2, TitleMatch_Rival_Jolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, TitleMatch_Rival_Flareon
	goto TitleMatch_Rival_Vaporeon

TitleMatch_Rival_Jolteon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_JOLTEON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Flareon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_FLAREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Rival_Vaporeon::
	trainerbattle_no_whiteout_continue_script TITLE_MATCH_RIVAL_VAPOREON, TitleMatch_Text_RivalIntro, TitleMatch_Text_RivalDefeated, TitleMatch_BattleOutcome
	end

TitleMatch_Text_RivalIntro::
	.string "{RIVAL}: Alright, we meet again!\p"
	.string "Now's my chance to prove I'm the\n"
	.string "true champion!$"

TitleMatch_Text_RivalDefeated::
	.string "Heh, still can't hack it.$"
