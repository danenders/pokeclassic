.set LOCALID_RIVAL, 1
.set LOCALID_FUGITIVE, 2

Route22_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, Route22_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route22_OnResume
	.byte 0

Route22_OnReturnToField:
	call_if_eq VAR_ROUTE_22_RIVAL_STATE, 2, Route22_EventScript_HealAfterRivalBattle
	end

Route22_EventScript_HealAfterRivalBattle::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setvar VAR_ROUTE_22_RIVAL_STATE, 3
	end

Route22_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route22_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route22_EventScript_EarlyRivalTriggerTop::
	setobjectxyperm LOCALID_RIVAL, 33, 4
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerMiddle::
	setobjectxyperm LOCALID_RIVAL, 33, 5
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRivalTriggerBottom::
	setobjectxyperm LOCALID_RIVAL, 33, 6
	goto Route22_EventScript_EarlyRival
	end

Route22_EventScript_EarlyRival::
	setvar VAR_ROUTE_22_RIVAL_STATE, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	clearflag FLAG_HIDE_RIVAL_ROUTE_22
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Movement_RivalApproach
	delay 6
	trainerbattle_no_whiteout_continue_script TRAINER_RIVAL_OPTIONAL_BATTLE,Route22_Text_EarlyRivalIntro,Route22_Text_EarlyRivalDefeated,Route22_EventScript_RivalBattleOutcome
	end

Route22_Text_EarlyRivalIntro::
	.string "{RIVAL}: Hey! {PLAYER}!\p"
	.string "You're off to the Pokémon League?\n"
	.string "Forget about it!\p"
	.string "You probably don't have any\n"
	.string "Badges, do you?\p"
	.string "The guard won't let you through\n"
	.string "without them.\p"
	.string "By the way, did your Pokémon get\n"
	.string "any stronger?$"

Route22_Text_EarlyRivalDefeated::
	.string "Awww!\n"
	.string "You just lucked out!$"

Route22_EventScript_RivalBattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route22_EventScript_EarlyRivalBattleWon
	goto Route22_EventScript_EarlyRivalBattleLost

Route22_EventScript_EarlyRivalBattleWon::
	addvar VAR_RIVAL_WINRATE, 1
	goto Route22_EventScript_EarlyRivalPostBattle
	
Route22_EventScript_EarlyRivalBattleLost::
	msgbox Route22_Text_EarlyRivalVictory, MSGBOX_DEFAULT
	goto Route22_EventScript_EarlyRivalPostBattle

Route22_Text_EarlyRivalVictory:
	.string "{RIVAL}: Hahaha! {PLAYER}!\p"
	.string "That's your best? You're nowhere\n" 
	.string "near as good as me, pal!\p"
	.string "Go train some more! You loser!$"

Route22_EventScript_EarlyRivalPostBattle::
	msgbox Route22_Text_EarlyRivalPostBattle, MSGBOX_DEFAULT
	playbgm MUS_RG_RIVAL_EXIT, 0
	applymovement LOCALID_RIVAL, Movement_RivalExit
	waitmovement 1
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_ROUTE_22
	releaseall
	end

Route22_Text_EarlyRivalPostBattle::
	.string "I heard the Pokémon League is\n"
	.string "crawling with tough Trainers.\p"
	.string "I have to figure out how to get\n"
	.string "past them.\p"
	.string "You should quit dawdling and get a\n"
	.string "move on!$"

Movement_RivalApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_RivalExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route22_EventScript_LateRivalTriggerTop::
	setobjectxyperm LOCALID_RIVAL, 33, 4
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerMiddle::
	setobjectxyperm LOCALID_RIVAL, 33, 5
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRivalTriggerBottom::
	setobjectxyperm LOCALID_RIVAL, 33, 6
	goto Route22_EventScript_LateRival
	end

Route22_EventScript_LateRival::
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	clearflag FLAG_HIDE_RIVAL_ROUTE_22
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, Movement_RivalApproach
	delay 6
	goto_if_eq VAR_RIVAL_WINRATE, 2, Route22_EventScript_LateRival_Jolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, Route22_EventScript_LateRival_Flareon
	goto Route22_EventScript_LateRival_Vaporeon
	end

Route22_EventScript_LateRival_Jolteon::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_JOLTEON, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_EventScript_LateRival_Flareon::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_FLAREON, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_EventScript_LateRival_Vaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_VAPOREON, Route22_Text_LateRivalDefeat
	goto Route22_EventScript_LateRivalPostBattle

Route22_Text_LateRivalDefeat::
	.string "What!?\p"
	.string "I was just careless!$"

Route22_EventScript_LateRivalPostBattle::
	msgbox Route22_Text_LateRivalPostBattle, MSGBOX_DEFAULT
	delay 10
	playbgm MUS_RG_RIVAL_EXIT, 0
	applymovement LOCALID_RIVAL, Movement_RivalExit
	waitmovement 1
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_ROUTE_22
	setvar VAR_ROUTE_22_RIVAL_STATE, 5
	releaseall
	end

Route22_Text_LateRivalPostBattle::
	.string "That loosened me up.\n"
	.string "I'm ready for the Pokémon League!\p"
	.string "{PLAYER}, you need more practice.\p"
	.string "But hey, you know that!\n"
	.string "I'm out of here. Smell ya!$"

Route22_EventScript_LeagueGateSign::
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
	end

Route22_Text_LeagueGateSign::
	.string "Pokémon League\n"
	.string "Front Gate $"

Route22_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
