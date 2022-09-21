Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route17_OnResume
	.byte 0

Route17_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route17_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route17_EventScript_ItemsNotice::
	msgbox Route17_Text_WatchOutForDiscardedItems, MSGBOX_SIGN
	end

Route17_Text_WatchOutForDiscardedItems::
    .string "It's a notice.\p"
    .string "Watch out for discarded items.$"

Route17_EventScript_TrainerTips1::
	msgbox Route17_Text_SameSpeciesGrowDifferentRates, MSGBOX_SIGN
	end

Route17_Text_SameSpeciesGrowDifferentRates::
    .string "Trainer Tips:\p"
    .string "All Pokémon are unique.\p"
    .string "Even Pokémon of the same species\n"
    .string "and level grow at different rates.$"

Route17_EventScript_TrainerTips2::
	msgbox Route17_Text_PressBToStayInPlace, MSGBOX_SIGN
	end

Route17_Text_PressBToStayInPlace::
    .string "Trainer Tips:\p"
    .string "Press the B Button to stay in place\n"
    .string "while on a slope.$"

Route17_EventScript_RouteSign::
	msgbox Route17_Text_RouteSign, MSGBOX_SIGN
	end

Route17_Text_RouteSign::
    .string "Route 17\n"
    .string "Celadon City - Fuchsia City$"

Route17_EventScript_BallsNotice::
	msgbox Route17_Text_DontThrowGameThrowBalls, MSGBOX_SIGN
	end

Route17_Text_DontThrowGameThrowBalls::
    .string "It's a notice!\p"
    .string "Don't throw the game, throw\n"
    .string "Poké Balls instead!$"

Route17_EventScript_CyclingRoadSign::
	msgbox Route17_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route17_Text_CyclingRoadSign::
    .string "Cycling Road\n"
    .string "Slope ends here!$"

Route17_EventScript_Billy::
	trainerbattle_single TRAINER_BIKER_BILLY, Route17_Text_BillyIntro, Route17_Text_BillyDefeat
	msgbox Route17_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_BillyIntro::
    .string "We're Bikers!\n"
    .string "We rule the roads, man!$"

Route17_Text_BillyDefeat::
    .string "Smoked!$"

Route17_Text_BillyPostBattle::
    .string "Are you looking for adventure?$"

Route17_EventScript_Nikolas::
	trainerbattle_single TRAINER_BIKER_NIKOLAS, Route17_Text_NikolasIntro, Route17_Text_NikolasDefeat
	msgbox Route17_Text_NikolasPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_NikolasIntro::
    .string "Let Voltorb electrify you!$"

Route17_Text_NikolasDefeat::
    .string "Grounded out!$"

Route17_Text_NikolasPostBattle::
    .string "I got my Voltorb at the abandoned\n"
    .string "Power Plant.$"

Route17_EventScript_Jaxon::
	trainerbattle_single TRAINER_BIKER_JAXON, Route17_Text_JaxonIntro, Route17_Text_JaxonDefeat
	msgbox Route17_Text_JaxonPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JaxonIntro::
    .string "Nice BIKE!\n"
    .string "How's it handle?$"

Route17_Text_JaxonDefeat::
    .string "Shoot!$"

Route17_Text_JaxonPostBattle::
    .string "The slope makes it hard to steer.$"

Route17_EventScript_William::
	trainerbattle_single TRAINER_BIKER_WILLIAM, Route17_Text_WilliamIntro, Route17_Text_WilliamDefeat
	msgbox Route17_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_WilliamIntro::
    .string "Get lost, kid!\n"
    .string "I'm bushed!$"

Route17_Text_WilliamDefeat::
    .string "Are you satisfied?$"

Route17_Text_WilliamPostBattle::
    .string "I need to catch a few z's!$"

Route17_EventScript_Raul::
	trainerbattle_single TRAINER_CUE_BALL_RAUL, Route17_Text_RaulIntro, Route17_Text_RaulDefeat
	msgbox Route17_Text_RaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_RaulIntro::
    .string "There's no getting rich quick in\n"
    .string "battling kids.$"

Route17_Text_RaulDefeat::
    .string "Burned out!$"

Route17_Text_RaulPostBattle::
    .string "You can find good stuff lying\n"
    .string "around on Cycling Road.\p"
    .string "There's good money in picking them\n"
    .string "up and selling them.$"

Route17_EventScript_Isaiah::
	trainerbattle_single TRAINER_CUE_BALL_ISAIAH, Route17_Text_IsaiahIntro, Route17_Text_IsaiahDefeat
	msgbox Route17_Text_IsaiahPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_IsaiahIntro::
    .string "I'm mighty proud of my bod, kiddo.\n"
    .string "Come on!$"

Route17_Text_IsaiahDefeat::
    .string "Whoo!$"

Route17_Text_IsaiahPostBattle::
    .string "I could belly-bump you outta\n"
    .string "here!$"

Route17_EventScript_Zeek::
	trainerbattle_single TRAINER_CUE_BALL_ZEEK, Route17_Text_ZeekIntro, Route17_Text_ZeekDefeat
	msgbox Route17_Text_ZeekPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_ZeekIntro::
    .string "I leveled up my Pokémon, but it\n"
    .string "won't evolve. Why?$"

Route17_Text_ZeekDefeat::
    .string "Why, you!$"

Route17_Text_ZeekPostBattle::
    .string "Maybe some Pokémon need element\n"
    .string "stones to evolve.$"

Route17_EventScript_Jamal::
	trainerbattle_single TRAINER_CUE_BALL_JAMAL, Route17_Text_JamalIntro, Route17_Text_JamalDefeat
	msgbox Route17_Text_JamalPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_JamalIntro::
    .string "I need a little exercise!$"

Route17_Text_JamalDefeat::
    .string "Whew!\n"
    .string "Good workout!$"

Route17_Text_JamalPostBattle::
    .string "I'm sure I lost weight there!$"

Route17_EventScript_Corey::
	trainerbattle_single TRAINER_CUE_BALL_COREY, Route17_Text_CoreyIntro, Route17_Text_CoreyDefeat
	msgbox Route17_Text_CoreyPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_CoreyIntro::
    .string "Be a rebel!$"

Route17_Text_CoreyDefeat::
    .string "Aaaargh!$"

Route17_Text_CoreyPostBattle::
    .string "Be ready to fight for your beliefs!$"

Route17_EventScript_Virgil::
	trainerbattle_single TRAINER_BIKER_VIRGIL, Route17_Text_VirgilIntro, Route17_Text_VirgilDefeat
	msgbox Route17_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

Route17_Text_VirgilIntro::
    .string "You heading to FUCHSIA?$"

Route17_Text_VirgilDefeat::
    .string "Crash and burn!$"

Route17_Text_VirgilPostBattle::
    .string "I love racing downhill!$"

