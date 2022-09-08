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
	trainerbattle_single REMATCHABLE_TRAINER_JANICE_1, Route3_Text_JaniceIntro, Route3_Text_JaniceDefeat, Route3_EventScript_RegisterJaniceAfterBattle
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
	register_matchcall REMATCHABLE_TRAINER_JANICE_1
	release
	end

Route3_Text_JaniceRegister:
	.string "I hate losing!\n"
	.string "Let's have a rematch sometime.$"

Route3_EventScript_JaniceRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_JANICE_1, Route3_Text_JaniceRematchIntro, Route3_Text_JaniceDefeat
	msgbox Route3_Text_JaniceRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_Text_JaniceRematchIntro::
	.string "Excuse me!\n"
	.string "You keep looking at me, don't you?$"

Route3_Text_JaniceRematchPostBattle::
	.string "I hate mean trainers like you!\n"
	.string "I'll teach you a lesson one day!$"

