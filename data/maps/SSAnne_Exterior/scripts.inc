.set LOCALID_SS_ANNE, 1
.set LOCALID_SS_TIDAL, 2
.set LOCALID_MEW, 3
.set LOCALID_SCOTT, 4
.set LOCALID_SAILOR, 5

SSAnne_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SSAnne_Exterior_OnResume
	.byte 0

SSAnne_Exterior_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

SSAnne_Exterior_OnResume:
	call Common_EventScript_GetDayOrNight
	end

SSAnne_Exterior_EventScript_MewUnderTruck::
	goto_if_set FLAG_CHECKED_UNDER_TRUCK, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_CAUGHT_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	goto_if_set FLAG_DEFEATED_MEW, SSAnne_Exterior_EventScript_MewNotUnderTruck
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadeoutbgm 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	clearflag FLAG_HIDE_MEW_UNDER_TRUCK
	addobject LOCALID_MEW
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	waitmoncry
	applymovement LOCALID_MEW, Movement_MewFlees
	waitmovement 3
	removeobject LOCALID_MEW
	setflag FLAG_CHECKED_UNDER_TRUCK
	delay 10
	fadeinbgm 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Movement_MewFlees::
	delay_16
	delay_16
	emote_exclamation_mark
	face_right
	delay_16
	face_left
	delay_16
	walk_up
	walk_up
	walk_up
	set_invisible
	delay_16
	step_end

SSAnne_Exterior_EventScript_MewNotUnderTruck::
	lock
	msgbox SSAnne_Exterior_Text_MewNotUnderTruck, MSGBOX_DEFAULT
	release
	end

SSAnne_Exterior_Text_MewNotUnderTruck::
	.string "There's nothing there...$"

