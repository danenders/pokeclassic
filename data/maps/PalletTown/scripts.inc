.set LOCALID_MOM, 1

PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PalletTown_OnResume
	.byte 0

PalletTown_OnTransition:
	setflag FLAG_VISITED_PALLET_TOWN
	call_if_eq VAR_OAK_LAB_STATE, 7, EventScript_UpdateOakLabState
	call Common_EventScript_GetDayOrNight
	end

PalletTown_OnResume:
	call Common_EventScript_GetDayOrNight
	end

EventScript_UpdateOakLabState::
	setvar VAR_OAK_LAB_STATE, 8
	return

PalletTown_EventScript_PokenavSceneStart1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER PlayerMovement_StepAsideRight
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER PlayerMovement_StepAsideLeft
	setvar VAR_TEMP_1, 2
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER PlayerMovement_StepAsideLeft
	setvar VAR_TEMP_1, 3
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart4::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER PlayerMovement_StepAsideRight
	setvar VAR_TEMP_1, 4
	goto PalletTown_EventScript_PokenavSceneStartFar

PalletTown_EventScript_PokenavSceneStart5::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER PlayerMovement_StepAsideLeft
	setvar VAR_TEMP_1, 5
	goto PalletTown_EventScript_PokenavSceneStartFar

PlayerMovement_StepAsideRight:
	walk_right
	face_down
	step_end

PlayerMovement_StepAsideLeft:
	walk_left
	face_down
	step_end

PalletTown_EventScript_PokenavSceneEnterSFX::
	playse SE_DOOR
	return

PalletTown_EventScript_PokenavSceneStartFar::
	setobjectxyperm LOCALID_MOM, 11, 7
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavScene::
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_PokenavSceneEnterSFX
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomApproach3
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomApproach4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomApproach5
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement 1
	msgbox PalletTown_Text_DidYouMeetOak, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, Common_Movement_Heart
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_Text_WhatACutePokemon, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_Text_ReceivedPokeGear
	waitmessage
	waitfanfare
	msgbox PalletTown_Text_CallMeSometime, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomExit1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomExit2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomExit3
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomExit4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomExit5
	waitmovement 1
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_PokenavSceneExitSFX
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_MOM_PALLET_TOWN
	setflag FLAG_SYS_POKENAV_GET
	setvar VAR_ADVENTURE_BEGINS, 4
	releaseall
	end

PalletTown_Text_DidYouMeetOak:
	.string "Mom: {PLAYER}!\p"
	.string "Did you meet with Professor Oak?$"

PalletTown_Text_WhatACutePokemon:
	.string "Oh! What an adorable Pokémon!\n"
	.string "You got it from Prof. Oak? How nice!\p"
	.string "And now you're on your way up to \n"
	.string "Viridian City?\p"
	.string "Well, I guess everyone dreams of\n"
	.string "traveling. At least it said so on TV.\p"
	.string "In that case, you wouldn't want to leave\n"
	.string "without your PokéGear, would you?$"

PalletTown_Text_CallMeSometime:
	.string "Your PokéGear has a map app, so\n"
	.string "you should never get lost.\p"
	.string "I already registered my number\n"
	.string "in your Cell Phone, too.\p"
	.string "Don't forget about your mom during\n"
	.string "your adventures. Call me sometime!$"

PalletTown_Text_ReceivedPokeGear:
	.string "{PLAYER} received the PokéGear\n"
    .string "from Mom!$"

PalletTown_EventScript_PokenavSceneExitSFX::
	playse SE_EXIT
	return

PalletTown_EventScript_PokenavMomApproach1::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav1
	return

Movement_MomApproachPokenav1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PalletTown_EventScript_PokenavMomApproach2::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav2
	return

Movement_MomApproachPokenav2:
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PalletTown_EventScript_PokenavMomApproach3::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav3
	return

Movement_MomApproachPokenav3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PalletTown_EventScript_PokenavMomApproach4::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav4
	return

Movement_MomApproachPokenav4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

PalletTown_EventScript_PokenavMomApproach5::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav5
	return

Movement_MomApproachPokenav5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit1::
	applymovement LOCALID_MOM, Movement_MomExitPokenav1
	return

Movement_MomExitPokenav1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit2::
	applymovement LOCALID_MOM, Movement_MomExitPokenav2
	return

Movement_MomExitPokenav2:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit3::
	applymovement LOCALID_MOM, Movement_MomExitPokenav3
	return

Movement_MomExitPokenav3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit4::
	applymovement LOCALID_MOM, Movement_MomExitPokenav4
	return

Movement_MomExitPokenav4:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_EventScript_PokenavMomExit5::
	applymovement LOCALID_MOM, Movement_MomExitPokenav5
	return

Movement_MomExitPokenav5:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end






