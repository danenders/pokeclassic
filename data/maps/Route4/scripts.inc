.set LOCALID_JENNY_1, 7
.set LOCALID_JENNY_2, 8
.set LOCALID_LOOKER, 9
.set LOCALID_FUGITIVE_F, 15
.set LOCALID_FUGITIVE_M, 16

Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route4_OnResume
	.byte 0

Route4_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route4_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route4_EventScript_Boy::
	msgbox Route4_Text_PeopleLikeAndRespectBrock, MSGBOX_NPC
	release
	end

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Oh, wow, that's the Boulder Badge!\n"
    .string "You got it from Brock, didn't you?\p"
    .string "Brock is cool. He's not just tough.\n"
    .string "People like and respect him.\p"
    .string "I want to become a Gym Leader\n"
    .string "like him.$"

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_Text_TrippedOverGeodude::
    .string "Ouch! I tripped over a rocky\n"
    .string "Pokémon, Geodude!$"

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Tunnel Entrance$"

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_RouteSign::
    .string "Route 4\n"
    .string "Mt. Moon - Cerulean City$"

Route4_EventScript_Crissy::
    trainerbattle_single TRAINER_LASS_ROBIN, Route4_Text_CrissyIntro, Route4_Text_CrissyDefeat
    msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route4_Text_CrissyIntro::
    .string "I came to MT. MOON in search of\n"
    .string "mushroom Pokémon.$"

Route4_Text_CrissyDefeat::
    .string "After all I did to catch them!$"

Route4_Text_CrissyPostBattle::
    .string "There might not be any more\n"
    .string "mushrooms here.\p"
    .string "I think I got them all.$"

Route4_EventScript_ItemTM05::
	finditem ITEM_TM05, 1
	end

Route4_EventScript_Captured1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepDownForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepDownForLooker:
	walk_down
	face_left
	step_end

Route4_EventScript_Captured2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_TurnAroundForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_TurnAroundForLooker:
	face_left
	step_end

Route4_EventScript_Captured3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepUpForLooker
	waitmovement 0
	goto Route4_EventScript_Captured
	end

Movement_StepUpForLooker:
	walk_up
	face_left
	step_end

Movement_PoliceApproach:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_EventScript_Captured::
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_ROUTE4_POLICE
	addobject LOCALID_JENNY_1
	addobject LOCALID_JENNY_2
	addobject LOCALID_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceApproach
	applymovement LOCALID_JENNY_2, Movement_PoliceApproach
	applymovement LOCALID_LOOKER, Movement_PoliceApproach
	waitmovement 9
	msgbox Route4_Text_StopRightThere, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox Route4_Text_TeamRocketFossils, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredLooker, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_LOOKER
	applymovement LOCALID_JENNY_1, Movement_PoliceExit
	applymovement LOCALID_JENNY_2, Movement_PoliceExit
	applymovement LOCALID_LOOKER, Movement_LookerExit
	waitmovement 9
	setflag FLAG_HIDE_ROUTE4_POLICE
	removeobject LOCALID_JENNY_1
	removeobject LOCALID_JENNY_2
	removeobject LOCALID_LOOKER
	setvar VAR_MT_MOON_STATE, 3
	fadedefaultbgm
	releaseall
	end

Movement_PoliceExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Movement_LookerExit:
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route4_Text_StopRightThere::
	.string "???: Stop right there!\p"
	.string "You thought you could escape\n"
	.string "the International Police?\p"
	.string "Well, I'll always be one step\n"
	.string "ahead of your plans, Team Rocket!$"

Route4_Text_TeamRocketFossils::
	.string "Ha! You're saying your not\n"
	.string "with Team Rocket?\p"
	.string "Then how do you explain that\n"
	.string "fossil you're carrying?\p"
	.string "We know Team Rocket is seeking\n"
	.string "rare fossils to sell on the\l"
	.string "black market!\p"
	.string "...\n"
	.string "......\l"
	.string "...........oh.\p"
	.string "So you're saying you stopped them?\n"
	.string "And they already fled Mt. Moon?\p"
	.string "Blast! How did we miss them!\p"
	.string "I'm sorry for the misunderstanding.\p"
	.string "My name is Looker - since you already\n"
	.string "stopped Team Rocket once, maybe we can\l"
	.string "help each other out.\p"
	.string "Here's my Cell Phone number - call me\n"
	.string "if you learn anything about Team Rocket!$"

Route4_EventScript_PixieDust::
	finditem ITEM_PIXIE_DUST, 1
	release
	end

Route4_RocketFugitiveF::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_F
	waitse
	fadescreen FADE_FROM_BLACK
	end

Route4_RocketFugitiveM::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_M
	waitse
	fadescreen FADE_FROM_BLACK
	end
