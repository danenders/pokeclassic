Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route3_OnResume
	.byte 0

Route3_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route3_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route3_EventScript_Youngster::
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
	end

Route3_Text_TunnelFromCeruleanTiring::
    .string "Whew… I better take a rest…\n"
    .string "Groan…\p"
    .string "That tunnel from Cerulean takes a\n"
    .string "lot out of you!$"

Route3_EventScript_RouteSign::
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
	end

Route3_Text_RouteSign::
    .string "Route 3\n"
    .string "Mt. Moon Ahead$"

Route3_EventScript_Janice::
	trainerbattle_single REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceIntro, Route3_Text_JaniceDefeat, Route3_EventScript_RegisterJaniceAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_JaniceRematch
	msgbox Route3_Text_JanicePostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_JaniceIntro::
    .string "Excuse me!\n"
    .string "You looked at me, didn't you?$"

Route3_Text_JaniceDefeat::
    .string "You're mean!$"

Route3_Text_JanicePostBattle::
    .string "You shouldn't be staring if you\n"
    .string "don't want to battle!$"

Route3_EventScript_RegisterJaniceAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_JaniceRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_LASS_JANICE_1
	release
	end

Route3_Text_JaniceRegister:
	.string "I hate losing!\n"
	.string "Let's have a rematch sometime.$"

Route3_EventScript_JaniceRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_LASS_JANICE_1, Route3_Text_JaniceRematchIntro, Route3_Text_JaniceDefeat
	msgbox Route3_Text_JaniceRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JaniceRematchIntro::
	.string "Excuse me!\n"
	.string "You keep looking at me, don't you?$"

Route3_Text_JaniceRematchPostBattle::
	.string "I hate mean trainers like you!\n"
	.string "I'll teach you a lesson one day!$"


Route3_EventScript_Colton::
	trainerbattle_single TRAINER_BUG_CATCHER_COLTON, Route3_Text_ColtonIntro, Route3_Text_ColtonDefeat
	msgbox Route3_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_ColtonIntro::
    .string "Hey! You battled my friend back\n"
    .string "in Viridian Forest!$"

Route3_Text_ColtonDefeat::
    .string "You beat me, too!$"

Route3_Text_ColtonPostBattle::
    .string "There are other kinds of Pokémon\n"
    .string "than the ones you find in forests.$"

Route3_EventScript_Ben::
	trainerbattle_single REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenIntro, Route3_Text_BenDefeat, Route3_EventScript_RegisterBenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_BenRematch
	msgbox Route3_Text_BenPostBattle, MSGBOX_DEFAULT
	release
	end

Route3_Text_BenIntro::
    .string "Hi!\n"
    .string "I like shorts!\p"
    .string "They're delightfully comfy and\n"
    .string "easy to wear!$"

Route3_Text_BenDefeat::
    .string "I don't believe it!$"

Route3_Text_BenPostBattle::
    .string "Are you using a Pokémon Center's\n"
    .string "PC for storing your Pokémon?\p"
    .string "Each Box can hold up to\n"
    .string "30 Pokémon.$"

Route3_EventScript_RegisterBenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_BenRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_YOUNGSTER_BEN_1
	release
	end

Route3_Text_BenRegister:
	.string "You seem like a trainer that\n"
	.string "gets me. Let's be friends!$"

Route3_EventScript_BenRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_YOUNGSTER_BEN_1, Route3_Text_BenRematchIntro, Route3_Text_BenDefeat
	msgbox Route3_Text_BenRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_BenRematchIntro::
	.string "Yo!\n"
	.string "Have tried wearing shorts yet?$"

Route3_Text_BenRematchPostBattle::
	.string "You gotta try it!\n"
	.string "It'll change your life!$"

Route3_EventScript_Greg::
	trainerbattle_single TRAINER_BUG_CATCHER_GREG, Route3_Text_GregIntro, Route3_Text_GregDefeat
	msgbox Route3_Text_GregPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_GregIntro::
    .string "Are you a trainer?\n"
    .string "Let's get with it right away!$"

Route3_Text_GregDefeat::
    .string "If I had new Pokémon, I would've\n"
    .string "won!$"

Route3_Text_GregPostBattle::
    .string "If a Pokémon BOX on the PC gets\n"
    .string "full, just switch to another box.$"

Route3_EventScript_Calvin::
	trainerbattle_single TRAINER_YOUNGSTER_CALVIN, Route3_Text_CalvinIntro, Route3_Text_CalvinDefeat
	msgbox Route3_Text_CalvinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_CalvinIntro::
    .string "Hey! You're not wearing shorts!\n"
    .string "What's wrong with you?$"

Route3_Text_CalvinDefeat::
    .string "Lost!\n"
    .string "Lost! Lost!$"

Route3_Text_CalvinPostBattle::
    .string "I always wear shorts, even in\n"
    .string "winter. That's my policy.$"

Route3_EventScript_Sally::
	trainerbattle_single TRAINER_LASS_SALLY, Route3_Text_SallyIntro, Route3_Text_SallyDefeat
	msgbox Route3_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_SallyIntro::
    .string "That look you gave me…\n"
    .string "It's so intriguing!$"

Route3_Text_SallyDefeat::
    .string "Be nice!$"

Route3_Text_SallyPostBattle::
    .string "You can avoid battles by not\n"
    .string "letting trainers see you.$"

Route3_EventScript_James::
	trainerbattle_single TRAINER_BUG_CATCHER_JAMES, Route3_Text_JamesIntro, Route3_Text_JamesDefeat
	msgbox Route3_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JamesIntro::
    .string "I'll battle you with the Pokémon\n"
    .string "I just caught.$"

Route3_Text_JamesDefeat::
    .string "Done like dinner!$"

Route3_Text_JamesPostBattle::
    .string "Trained Pokémon are stronger than\n"
    .string "the wild ones.$"

Route3_EventScript_Robin::
	trainerbattle_single TRAINER_LASS_ROBIN, Route3_Text_RobinIntro, Route3_Text_RobinDefeat
	msgbox Route3_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_RobinIntro::
    .string "Eek!\n"
    .string "Did you touch me?$"

Route3_Text_RobinDefeat::
    .string "That's it?$"

Route3_Text_RobinPostBattle::
    .string "Route 4 is at the foot of\n"
    .string "Mt. Moon.$"
