.set LOCALID_FUGITIVE, 9

Route21_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_South_OnResume
	.byte 0

Route21_South_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_EventScript_Johan::
	trainerbattle_single REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanIntro, Route21_South_Text_JohanDefeat, Route21_South_EventScript_RegisterJohanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_South_EventScript_JohanRematch
	msgbox Route21_South_Text_JohanPostBattle, MSGBOX_DEFAULT
	release
	end

Route21_South_Text_JohanIntro::
    .string "Watch me juggle all these\n"
    .string "Poké Balls!$"

Route21_South_Text_JohanDefeat::
    .string "I dropped my balls...$"

Route21_South_Text_JohanPostBattle::
    .string "Only the strongest trainers\n"
    .string "can make it to the Elite Four.$"

Route21_South_EventScript_RegisterJohanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_South_Text_JohanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_JUGGLER_JOHAN_1
	release
	end

Route21_South_Text_JohanRegister:
	.string "I teleported out here..\p"
	.string "but  I'm out of PP...\p"
	.string "Can I call you for a ride later?$"

Route21_South_EventScript_JohanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_JUGGLER_JOHAN_1, Route21_South_Text_JohanRematchIntro, Route21_South_Text_JohanDefeat
	msgbox Route21_South_Text_JohanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JohanRematchIntro::
	.string "I've been practicing my juggling!$"

Route21_South_Text_JohanRematchPostBattle::
	.string "If I didn't drop out of school, I\n"
	.string "could have been working for Silph!\p"
	.string "But would I have been happy if I\n"
	.string "wasn't out here juggling balls?\p"
	.string "Who knows...$"


Route21_South_EventScript_Claude::
	trainerbattle_single TRAINER_FISHERMAN_CLAUDE, Route21_South_Text_ClaudeIntro, Route21_South_Text_ClaudeDefeat
	msgbox Route21_South_Text_ClaudePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_ClaudeIntro::
	.string "Hey, don't scare away the fish!$"

Route21_South_Text_ClaudeDefeat::
	.string "Sorry! I'm just so frustrated from\n"
	.string "not catching anything.$"

Route21_South_Text_ClaudePostBattle::
	.string "Sheesh, I haven't caught a thing.\n"
	.string "Could this place actually be a\l"
	.string "giant pool or something?$"

Route21_South_EventScript_Nolan::
	trainerbattle_single TRAINER_FISHERMAN_NOLAN, Route21_South_Text_NolanIntro, Route21_South_Text_NolanDefeat
	msgbox Route21_South_Text_NolanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_NolanIntro::
	.string "Keep me company till I get a hit.$"

Route21_South_Text_NolanDefeat::
	.string "That burned some time.$"

Route21_South_Text_NolanPostBattle::
	.string "Oh wait!\n"
	.string "I got a bite! Yeah!$"

Route21_South_EventScript_Jack::
	trainerbattle_single TRAINER_SWIMMER_MALE_JACK, Route21_South_Text_JackIntro, Route21_South_Text_JackDefeat
	msgbox Route21_South_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JackIntro::
	.string "I caught my Pokémon at sea.$"

Route21_South_Text_JackDefeat::
	.string "Diver!!\n"
	.string "Down!!$"

Route21_South_Text_JackPostBattle::
	.string "Where'd you catch your Pokémon?$"

Route21_South_EventScript_Jerome::
	trainerbattle_single TRAINER_SWIMMER_MALE_JEROME, Route21_South_Text_JeromeIntro, Route21_South_Text_JeromeDefeat
	msgbox Route21_South_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_JeromeIntro::
	.string "Right now, I'm in a triathlon meet.$"

Route21_South_Text_JeromeDefeat::
	.string "Pant…\n"
	.string "Pant… Pant…$"

Route21_South_Text_JeromePostBattle::
	.string "I'm beat! But, I still have the\n"
	.string "bike race and marathon left!$"

Route21_South_EventScript_Roland::
	trainerbattle_single TRAINER_SWIMMER_MALE_ROLAND, Route21_South_Text_RolandIntro, Route21_South_Text_RolandDefeat
	msgbox Route21_South_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_South_Text_RolandIntro::
	.string "Ahh!\n"
	.string "Feel the sun and the wind!$"

Route21_South_Text_RolandDefeat::
	.string "Yow!\n"
	.string "I lost!$"

Route21_South_Text_RolandPostBattle::
	.string "I'm sunburnt to a crisp!$"

Route21S_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
