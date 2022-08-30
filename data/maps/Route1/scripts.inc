.set LOCALID_OAK, 1
.set LOCALID_PIKACHU, 2

Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route1_OnResume
	.byte 0

Route1_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route1_OnResume:
	removeobject LOCALID_PIKACHU
	call Common_EventScript_GetDayOrNight
	end

Route1_EventScript_OakAppears1::
	lockall
	addobject LOCALID_OAK
	applymovement LOCALID_OAK, Movement_OakAppears
	waitmovement 1
	msgbox Route1_Text_OakDontGoOut, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_OAK, Movement_OakApproaches1
	waitmovement 1
	msgbox Route1_Text_OakGrassUnsafe, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_PIKACHU
	applymovement LOCALID_PIKACHU, Movement_PikachuApproaches1
	goto Route1_EventScript_PikachuEncounter
	waitmovement 2
	end

Route1_EventScript_OakAppears2::
	lockall
	addobject LOCALID_OAK
	applymovement LOCALID_OAK, Movement_OakAppears
	waitmovement 1
	msgbox Route1_Text_OakDontGoOut, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_OAK, Movement_OakApproaches2
	waitmovement 1
	msgbox Route1_Text_OakGrassUnsafe, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_PIKACHU
	applymovement LOCALID_PIKACHU, Movement_PikachuApproaches2
	waitmovement 2
	goto Route1_EventScript_PikachuEncounter
	end

Movement_OakAppears:
	walk_down
	step_end

Route1_Text_OakDontGoOut::
    .string "Oak: Hey! Wait!\n"
    .string "Don't come out this way!$"


Movement_OakApproaches1:
	walk_down
	walk_down
	walk_down
	step_end

Movement_OakApproaches2:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Route1_Text_OakGrassUnsafe::
    .string "OAK: It's unsafe!\n"
    .string "Wild Pokémon live in tall grass!\p"
    .string "You need your own Pokémon for\n"
    .string "your protection.$"

Movement_PikachuApproaches1:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_PikachuApproaches2:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route1_EventScript_PikachuEncounter::
	turnobject LOCALID_OAK, DIR_NORTH
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	special StartWallyTutorialBattle
	setflag FLAG_HIDE_PIKACHU_ROUTE1
	waitstate
	special LoadPlayerParty
	turnobject LOCALID_OAK, DIR_SOUTH
	msgbox Route1_Text_ThatWasClose, MSGBOX_DEFAULT
	setvar VAR_ROUTE_1_STATE, 1
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_HIDE_OAK_IN_LAB
	setvar VAR_OAK_LAB_STATE, 1
	givemon SPECIES_PIKACHU_PARTNER, 5
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 5
	waitstate
	releaseall
	end

Route1_Text_ThatWasClose::
    .string "Oak: That was close!\n"
    .string "But that's odd...\p"
    .string "You don't often see Pikachu\n"
    .string "in this area...\p"
    .string "Let's head back to my lab!$"
