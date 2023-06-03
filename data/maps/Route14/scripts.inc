.set LOCALID_FUGITIVE, 17

Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route14_OnResume
	.byte 0

Route14_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route14_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route14_EventScript_RouteSign::
	msgbox Route14_Text_RouteSign, MSGBOX_SIGN
	end

Route14_Text_RouteSign::
    .string "Route 14\n"
    .string "West to Fuchsia City$"

Route14_EventScript_Malik::
	trainerbattle_single TRAINER_BIKER_MALIK, Route14_Text_MalikIntro, Route14_Text_MalikDefeat
	msgbox Route14_Text_MalikPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MalikIntro::
    .string "Pokémon battle?\n"
    .string "Cool! Rumble!$"

Route14_Text_MalikDefeat::
    .string "Blown away!$"

Route14_Text_MalikPostBattle::
    .string "You know who'd win, you and me\n"
    .string "one-on-one!$"

Route14_EventScript_Lukas::
	trainerbattle_single TRAINER_BIKER_LUKAS, Route14_Text_LukasIntro, Route14_Text_LukasDefeat
	msgbox Route14_Text_LukasPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_LukasIntro::
    .string "C'mon, c'mon.\n"
    .string "Let's go, let's go, let's go!$"

Route14_Text_LukasDefeat::
    .string "Arrg!\n"
    .string "Lost! Get lost!$"

Route14_Text_LukasPostBattle::
    .string "What, what, what?\n"
    .string "What do you want still?$"


Route14_EventScript_Isaac::
	trainerbattle_single TRAINER_BIKER_ISAAC, Route14_Text_IsaacIntro, Route14_Text_IsaacDefeat
	msgbox Route14_Text_IsaacPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_IsaacIntro::
    .string "I need to burn some time.\n"
    .string "Shut up and battle.$"

Route14_Text_IsaacDefeat::
    .string "What?\n"
    .string "You!?$"

Route14_Text_IsaacPostBattle::
    .string "Raising Pokémon is a drag, man.$"

Route14_EventScript_Gerald::
	trainerbattle_single TRAINER_BIKER_GERALD, Route14_Text_GeraldIntro, Route14_Text_GeraldDefeat
	msgbox Route14_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_GeraldIntro::
    .string "We ride out here because of the\n"
    .string "wide-open spaces.$"

Route14_Text_GeraldDefeat::
    .string "Wipeout!$"

Route14_Text_GeraldPostBattle::
    .string "It's cool you made your Pokémon so\n"
    .string "strong.\p"
    .string "Might is right!\n"
    .string "And you know it!$"

Route14_EventScript_Donald::
	trainerbattle_single TRAINER_BIRD_KEEPER_DONALD, Route14_Text_DonaldIntro, Route14_Text_DonaldDefeat
	msgbox Route14_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_DonaldIntro::
    .string "Have you heard the legend of the\n"
    .string "winged mirages?$"

Route14_Text_DonaldDefeat::
    .string "Why?\n"
    .string "Why'd I lose?$"

Route14_Text_DonaldPostBattle::
    .string "Well, the winged mirages are the\n"
    .string "legendary bird Pokémon.\p"
    .string "There are three of them: Articuno,\n"
    .string "Zapdos, and Moltres.$"

Route14_EventScript_Benny::
	trainerbattle_single TRAINER_BIRD_KEEPER_BENNY, Route14_Text_BennyIntro, Route14_Text_BennyDefeat
	msgbox Route14_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BennyIntro::
    .string "I'm not into it, but okay.\n"
    .string "Let's go!$"

Route14_Text_BennyDefeat::
    .string "I knew it!$"

Route14_Text_BennyPostBattle::
    .string "Winning, losing… It's insignificant\n"
    .string "under this huge sky.$"

Route14_EventScript_Carter::
	trainerbattle_single TRAINER_BIRD_KEEPER_CARTER, Route14_Text_CarterIntro, Route14_Text_CarterDefeat
	msgbox Route14_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_CarterIntro::
    .string "You need to use TMs to teach good\n"
    .string "moves to Pokémon.$"

Route14_Text_CarterDefeat::
    .string "Not good enough quite yet.$"

Route14_Text_CarterPostBattle::
    .string "You have some HMs, right? Pokémon\n"
    .string "can't forget those moves easily.$"


Route14_EventScript_Mitch::
	trainerbattle_single TRAINER_BIRD_KEEPER_MITCH, Route14_Text_MitchIntro, Route14_Text_MitchDefeat
	msgbox Route14_Text_MitchPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MitchIntro::
    .string "My bird Pokémon should be ready\n"
    .string "for battle.$"

Route14_Text_MitchDefeat::
    .string "Not ready yet!$"

Route14_Text_MitchPostBattle::
    .string "My bird Pokémon need to learn\n"
    .string "better moves.$"

Route14_EventScript_Beck::
	trainerbattle_single TRAINER_BIRD_KEEPER_BECK, Route14_Text_BeckIntro, Route14_Text_BeckDefeat
	msgbox Route14_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_BeckIntro::
    .string "They have TMs on sale at the\n"
    .string "Celadon Department Store.\p"
    .string "TMs aren't really rare, but not\n"
    .string "many people have HMs.$"

Route14_Text_BeckDefeat::
    .string "Aww, bummer!$"

Route14_Text_BeckPostBattle::
    .string "Try teaching Pokémon a move that's\n"
    .string "the same type as it.\p"
    .string "That apparently boosts the power\n"
    .string "of the move.$"


Route14_EventScript_Marlon::
	trainerbattle_single TRAINER_BIRD_KEEPER_MARLON, Route14_Text_MarlonIntro, Route14_Text_MarlonDefeat
	msgbox Route14_Text_MarlonPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_MarlonIntro::
    .string "Have you taught your bird Pokémon\n"
    .string "how to Fly?\p"
    .string "You'll be able to soar with it into\n"
    .string "the sky!$"

Route14_Text_MarlonDefeat::
    .string "Shot down in flames!$"

Route14_Text_MarlonPostBattle::
    .string "Bird Pokémon are my one true love.\n"
    .string "I don't want to raise anything else.$"


Route14_EventScript_Kiri::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_KiriIntro, Route14_Text_KiriDefeat, Route14_Text_KiriNotEnoughMons
	msgbox Route14_Text_KiriPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_KiriIntro::
    .string "Kiri: Jan, let's try really,\n"
    .string "really hard together.$"

Route14_Text_KiriDefeat::
    .string "Kiri: Whimper…\n"
    .string "We lost, didn't we?$"

Route14_Text_KiriPostBattle::
    .string "Kiri: Did we lose because of me?$"

Route14_Text_KiriNotEnoughMons::
    .string "Kiri: We can battle if you have\n"
    .string "two Pokémon.$"


Route14_EventScript_Jan::
	trainerbattle_double TRAINER_TWINS_KIRI_JAN, Route14_Text_JanIntro, Route14_Text_JanDefeat, Route14_Text_JanNotEnoughMons
	msgbox Route14_Text_JanPostBattle, MSGBOX_AUTOCLOSE
	end

Route14_Text_JanIntro::
    .string "Jan: Kiri, here we go!\n"
    .string "We have to try hard!$"

Route14_Text_JanDefeat::
    .string "Jan: Eeeeh!\n"
    .string "No fair!$"

Route14_Text_JanPostBattle::
    .string "Jan: Kiri, don't cry!\n"
    .string "We'll just try harder next time.$"

Route14_Text_JanNotEnoughMons::
    .string "Jan: You want to battle?\n"
    .string "You don't have enough Pokémon.$"

Route14_EventScript_BigRoot::
    finditem ITEM_BIG_ROOT, 1
    release
    end

Route14_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

