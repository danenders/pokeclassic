.set LOCALID_FUGITIVE, 7

Route21_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_North_OnResume
	.byte 0

Route21_North_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_EventScript_Anri::
	trainerbattle_single REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriIntro, Route21_North_Text_AnriDefeat, Route21_North_EventScript_RegisterAnriAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route21_North_EventScript_AnriRematch
	msgbox Route21_North_Text_AnriPostBattle, MSGBOX_DEFAULT
	release
	end

Route21_North_Text_AnriIntro::
    .string "I'm training for Victory Road!$"

Route21_North_Text_AnriDefeat::
    .string "I gave it my all.$"

Route21_North_Text_AnriPostBattle::
    .string "Only the strongest trainers\n"
    .string "can make it to the Elite Four.$"

Route21_North_EventScript_RegisterAnriAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route21_North_Text_AnriRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1
	release
	end

Route21_North_Text_AnriRegister:
	.string "I like your style!\p"
	.string "Call me if you find anywhere\n"
	.string "good to train!$"

Route21_North_EventScript_AnriRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_COOLTRAINER_ANRI_1, Route21_North_Text_AnriRematchIntro, Route21_North_Text_AnriDefeat
	msgbox Route21_North_Text_AnriRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_AnriRematchIntro::
	.string "Alright! Time to practice!$"

Route21_North_Text_AnriRematchPostBattle::
	.string "You'll need more than brute force\n"
	.string "to make it through the Elite Four!$"


Route21_North_EventScript_Ronald::
	trainerbattle_single TRAINER_FISHERMAN_RONALD, Route21_North_Text_RonaldIntro, Route21_North_Text_RonaldDefeat
	msgbox Route21_North_Text_RonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_RonaldIntro::
	.string "You want to know if the fish are\n"
	.string "biting?$"

Route21_North_Text_RonaldDefeat::
	.string "Dang!$"

Route21_North_Text_RonaldPostBattle::
	.string "I can't catch anything good.\n"
	.string "Not one good Pokémon to be had!$"

Route21_North_EventScript_Wade::
	trainerbattle_single TRAINER_FISHERMAN_WADE, Route21_North_Text_WadeIntro, Route21_North_Text_WadeDefeat
	msgbox Route21_North_Text_WadePostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_WadeIntro::
	.string "I got a big haul!\n"
	.string "Wanna go for it?$"

Route21_North_Text_WadeDefeat::
	.string "Heheh, Magikarp just don't make\n"
	.string "the grade, do they?$"

Route21_North_Text_WadePostBattle::
	.string "I seem to only catch Magikarp!$"

Route21_North_EventScript_Spencer::
	trainerbattle_single TRAINER_SWIMMER_MALE_SPENCER, Route21_North_Text_SpencerIntro, Route21_North_Text_SpencerDefeat
	msgbox Route21_North_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_SpencerIntro::
	.string "The sea cleanses my body and soul!$"

Route21_North_Text_SpencerDefeat::
	.string "Ayah!$"

Route21_North_Text_SpencerPostBattle::
	.string "The sea is great and all, but I\n"
	.string "like the mountains, too.$"

Route21_North_EventScript_Lil::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_LilIntro, Route21_North_Text_LilDefeat, Route21_North_Text_LilNotEnoughMons
	msgbox Route21_North_Text_LilPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_LilIntro::
	.string "Lil: Huh? A battle?\n"
	.string "Ian, can't you do it alone?$"

Route21_North_Text_LilDefeat::
	.string "Lil: Oh, see?\n"
	.string "We lost. Happy now?$"

Route21_North_Text_LilPostBattle::
	.string "Lil: I'm tired.\n"
	.string "Can't we go home already?$"

Route21_North_Text_LilNotEnoughMons::
	.string "Lil: Huh? A battle?\n"
	.string "I can't be bothered to do it alone.\l"
	.string "Bring two Pokémon, won't you?$"

Route21_North_EventScript_Ian::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIL_IAN, Route21_North_Text_IanIntro, Route21_North_Text_IanDefeat, Route21_North_Text_IanNotEnoughMons
	msgbox Route21_North_Text_IanPostBattle, MSGBOX_AUTOCLOSE
	end

Route21_North_Text_IanIntro::
	.string "Ian: My sis doesn't get enough\n"
	.string "exercise, so I made her come.$"

Route21_North_Text_IanDefeat::
	.string "Ian: Awww, Sis!\n"
	.string "Get it together!$"

Route21_North_Text_IanPostBattle::
	.string "Ian: Come on, Sis!\p"
	.string "You're not going to lose weight\n"
	.string "like this!$"

Route21_North_Text_IanNotEnoughMons::
	.string "Ian: We want a two-on-two battle.\n"
	.string "So can you bring two Pokémon?$"


Route21_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
