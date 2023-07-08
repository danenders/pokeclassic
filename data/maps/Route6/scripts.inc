.set LOCALID_FUGITIVE, 16

Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route6_OnResume
	.byte 0

Route6_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route6_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route6_EventScript_Keigo::
	trainerbattle_single REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoIntro, Route6_Text_KeigoDefeat, Route6_EventScript_RegisterKeigoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route6_EventScript_KeigoRematch
	msgbox Route6_Text_KeigoPostBattle, MSGBOX_DEFAULT
	release
	end

Route6_Text_KeigoIntro::
    .string "There aren't many bugs out here.$"

Route6_Text_KeigoDefeat::
    .string "No!\n"
    .string "You're kidding!$"

Route6_Text_KeigoPostBattle::
    .string "I like bugs, so I'm going back to\n"
    .string "Viridian Forest.$"

Route6_EventScript_RegisterKeigoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_KeigoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1
	release
	end

Route6_Text_KeigoRegister:
	.string "I'll prove that Bug Pokémon are\n"
	.string "the strongest. Let's have a rematch\l"
	.string "sometime!$"

Route6_EventScript_KeigoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BUG_CATCHER_KEIGO_1, Route6_Text_KeigoRematchIntro, Route6_Text_KeigoDefeat
	msgbox Route6_Text_KeigoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_KeigoRematchIntro::
	.string "I'm trying to find something good\n"
	.string "that's not a Bug Pokémon, but…$"

Route6_Text_KeigoRematchPostBattle::
	.string "I thought I should branch out,\n"
	.string "but I'll always love Bug Pokémon!$"

Route6_EventScript_Ricky::
	trainerbattle_single TRAINER_CAMPER_RICKY, Route6_Text_RickyIntro, Route6_Text_RickyDefeat
	msgbox Route6_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_RickyIntro::
    .string "Who's there?\n"
    .string "Quit listening in on us!$"

Route6_Text_RickyDefeat::
    .string "I just can't win!$"

Route6_Text_RickyPostBattle::
    .string "Whisper…\n"
    .string "Whisper…$"

Route6_EventScript_Nancy::
	trainerbattle_single TRAINER_PICNICKER_NANCY, Route6_Text_NancyIntro, Route6_Text_NancyDefeat
	msgbox Route6_Text_NancyPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_NancyIntro::
    .string "Excuse me!\n"
    .string "This is a private conversation!$"

Route6_Text_NancyDefeat::
    .string "Ugh!\n"
    .string "I hate losing.$"

Route6_Text_NancyPostBattle::
    .string "Whisper…\n"
    .string "Whisper…$"

Route6_EventScript_Elijah::
	trainerbattle_single TRAINER_BUG_CATCHER_ELIJAH, Route6_Text_ElijahIntro, Route6_Text_ElijahDefeat
	msgbox Route6_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_ElijahIntro::
    .string "I've never seen you around.\n"
    .string "Are you good?$"

Route6_Text_ElijahDefeat::
    .string "You're too good!$"

Route6_Text_ElijahPostBattle::
    .string "Are my Pokémon weak?\n"
    .string "Or, am I just bad?\l"
    .string "Which do you think?$"

Route6_EventScript_Isabelle::
	trainerbattle_single TRAINER_PICNICKER_ISABELLE, Route6_Text_IsabelleIntro, Route6_Text_IsabelleDefeat
	msgbox Route6_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_IsabelleIntro::
    .string "Me?\n"
    .string "Well, okay. I'll play!$"

Route6_Text_IsabelleDefeat::
    .string "Things just didn't work…$"

Route6_Text_IsabellePostBattle::
    .string "I want to get stronger.\n"
    .string "What's your secret?$"

Route6_EventScript_Jeff::
	trainerbattle_single TRAINER_CAMPER_JEFF, Route6_Text_JeffIntro, Route6_Text_JeffDefeat
	msgbox Route6_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_JeffIntro::
    .string "Huh?\n"
    .string "You want to talk to me?$"

Route6_Text_JeffDefeat::
    .string "This stinks…\n"
    .string "I couldn't beat your challenge…$"

Route6_Text_JeffPostBattle::
    .string "I should bring more Pokémon with\n"
    .string "me. I'll feel safer that way.$"

Route6_EventScript_UndergroundPathSign::
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
	release
	end

Route6_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Cerulean City - Vermilion City$"

Route6_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
