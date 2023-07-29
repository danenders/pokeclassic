.set LOCALID_FUGITIVE, 18

Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route11_OnResume
	.byte 0

Route11_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route11_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route11_EventScript_DiglettsCaveSign::
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
	end

Route11_Text_DiglettsCave::
    .string "Diglett's Cave$"

Route11_EventScript_Hugo::
	trainerbattle_single REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoIntro, Route11_Text_HugoDefeat, Route11_EventScript_RegisterHugoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_HugoRematch
	msgbox Route11_Text_HugoPostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_HugoIntro::
    .string "Win, lose, or draw!$"

Route11_Text_HugoDefeat::
    .string "Atcha!\n"
    .string "Didn't go my way!$"

Route11_Text_HugoPostBattle::
    .string "Pokémon is life!\n"
    .string "And to live is to play games!$"

Route11_EventScript_RegisterHugoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_HugoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_GAMBLER_HUGO_1
	release
	end

Route11_Text_HugoRegister:
	.string "Hey, how about rematch sometime?\n"
	.string "Maybe I'll have better luck.$"

Route11_EventScript_HugoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_GAMBLER_HUGO_1, Route11_Text_HugoRematchIntro, Route11_Text_HugoDefeat
	msgbox Route11_Text_HugoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_HugoRematchIntro::
	.string "Win, lose, or draw!\n"
	.string "Now for our rematch!$"

Route11_Text_HugoRematchPostBattle::
	.string "Ouch! There goes my streak.$"

Route11_EventScript_Jasper::
	trainerbattle_single TRAINER_GAMBLER_JASPER, Route11_Text_JasperIntro, Route11_Text_JasperDefeat
	msgbox Route11_Text_JasperPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_JasperIntro::
    .string "Competition!\n"
    .string "I can't get enough!$"

Route11_Text_JasperDefeat::
    .string "I had a chance!$"

Route11_Text_JasperPostBattle::
    .string "You can't be a coward in the world\n"
    .string "of Pokémon!$"

Route11_EventScript_Bernie::
	trainerbattle_single REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieIntro, Route11_Text_BernieDefeat, Route11_EventScript_RegisterBernieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route11_EventScript_BernieRematch
	msgbox Route11_Text_BerniePostBattle, MSGBOX_DEFAULT
	release
	end

Route11_Text_BernieIntro::
    .string "Watch out for live wires!$"

Route11_Text_BernieDefeat::
    .string "Whoa!\n"
    .string "You spark plug!$"

Route11_Text_BerniePostBattle::
    .string "Well, better get back to work.$"

Route11_EventScript_RegisterBernieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route11_Text_BernieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_ENGINEER_BERNIE_1
	release
	end

Route11_Text_BernieRegister:
	.string "Next time I take a break, let's\n"
	.string "have a rematch.$"

Route11_EventScript_BernieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_ENGINEER_BERNIE_1, Route11_Text_BernieRematchIntro, Route11_Text_BernieDefeat
	msgbox Route11_Text_BernieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BernieRematchIntro::
	.string "Whoo! Time for a break.\n"
	.string "How about a rematch?$"

Route11_Text_BernieRematchPostBattle::
	.string "Well, back to the grind.$"

Route11_EventScript_Braxton::
	trainerbattle_single TRAINER_ENGINEER_BRAXTON, Route11_Text_BraxtonIntro, Route11_Text_BraxtonDefeat
	msgbox Route11_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_BraxtonIntro::
    .string "Careful!\n"
    .string "I'm laying down some cables!$"

Route11_Text_BraxtonDefeat::
    .string "That was electric!$"

Route11_Text_BraxtonPostBattle::
    .string "Spread the word to save energy!$"

Route11_EventScript_Eddie::
	trainerbattle_single TRAINER_YOUNGSTER_EDDIE, Route11_Text_EddieIntro, Route11_Text_EddieDefeat
	msgbox Route11_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_EddieIntro::
    .string "Let's go, but don't cheat!$"

Route11_Text_EddieDefeat::
    .string "Huh?\n"
    .string "That's not right!$"

Route11_Text_EddiePostBattle::
    .string "I did my best.\n"
    .string "I have no regrets.$"

Route11_EventScript_Dillon::
	trainerbattle_single TRAINER_YOUNGSTER_DILLON, Route11_Text_DillonIntro, Route11_Text_DillonDefeat
	msgbox Route11_Text_DillonPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DillonIntro::
    .string "I just became a trainer.\n"
    .string "But, I think I can win.$"

Route11_Text_DillonDefeat::
    .string "My Pokémon couldn't win…\n"
    .string "Haven't they grown enough?$"

Route11_Text_DillonPostBattle::
    .string "What now?\n"
    .string "Leave me alone!$"

Route11_EventScript_Yasu::
	trainerbattle_single TRAINER_YOUNGSTER_YASU, Route11_Text_YasuIntro, Route11_Text_YasuDefeat
	msgbox Route11_Text_YasuPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_YasuIntro::
    .string "I'm the best in my class.\n"
    .string "I train every morning.$"

Route11_Text_YasuDefeat::
    .string "Darn!\n"
    .string "My Pokémon need to be stronger!$"

Route11_Text_YasuPostBattle::
    .string "There's a fat Pokémon that comes\n"
    .string "down from the mountains.\p"
    .string "I bet it'd be strong if you can\n"
    .string "catch it.$"

Route11_EventScript_Dave::
	trainerbattle_single TRAINER_YOUNGSTER_DAVE, Route11_Text_DaveIntro, Route11_Text_DaveDefeat
	msgbox Route11_Text_DavePostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DaveIntro::
    .string "I raised my Pokémon carefully.\n"
    .string "They should be ready by now!$"

Route11_Text_DaveDefeat::
    .string "Bye-bye!\n"
    .string "Thank you, and good-bye!$"

Route11_Text_DavePostBattle::
    .string "Tch…\n"
    .string "I better go find stronger ones!$"

Route11_EventScript_Dirk::
	trainerbattle_single TRAINER_GAMBLER_DIRK, Route11_Text_DirkIntro, Route11_Text_DirkDefeat
	msgbox Route11_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DirkIntro::
    .string "Fwahaha!\n"
    .string "I have never lost!$"

Route11_Text_DirkDefeat::
    .string "My first loss!$"

Route11_Text_DirkPostBattle::
    .string "You were just lucky, that's all.$"

Route11_EventScript_Darian::
	trainerbattle_single TRAINER_GAMBLER_DARIAN, Route11_Text_DarianIntro, Route11_Text_DarianDefeat
	msgbox Route11_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route11_Text_DarianIntro::
    .string "I have never won before…$"

Route11_Text_DarianDefeat::
    .string "I saw this coming…$"

Route11_Text_DarianPostBattle::
    .string "I was unlucky, as always.$"


Route11_EventScript_ItemGreatBall::
	finditem ITEM_GREAT_BALL, 1
	release
	end

Route11_EventScript_ItemXDefend::
	finditem ITEM_X_DEFEND, 1
	release
	end

Route11_EventScript_ItemAwakening::
	finditem ITEM_AWAKENING, 1
	release
	end

Route11_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
