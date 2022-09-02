.set LOCALID_OFFICER, 1

ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianCity_OnResume
	.byte 0

ViridianCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_EventScripts_TeamRocketRumor1::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath1
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath1:
	walk_left
	face_down
	step_end

ViridianCity_EventScripts_TeamRocketRumor2::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	goto ViridianCity_EventScripts_TeamRocketRumor

ViridianCity_EventScripts_TeamRocketRumor3::
	lockall
	setvar VAR_TEMP_1, 3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachJenny
	waitmovement 0
	applymovement LOCALID_OFFICER, Movement_OfficerBlockPath3
	waitmovement 1
	goto ViridianCity_EventScripts_TeamRocketRumor

Movement_OfficerBlockPath3:
	walk_right
	face_down
	step_end

Movement_PlayerApproachJenny:
	walk_up
	face_up
	step_end

ViridianCity_EventScripts_TeamRocketRumor::
	turnobject LOCALID_OFFICER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OFFICER, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OFFICER, Common_Movement_Delay48
	waitmovement 1
	msgbox ViridianCity_Text_InvestigatingTeamRocket, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, ViridianCity_EventScripts_ReturnJennyToPosition1
	call_if_eq VAR_TEMP_1, 3, ViridianCity_EventScripts_ReturnJennyToPosition2
	turnobject LOCALID_OFFICER, DIR_NORTH
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepsBack
	waitmovement 0
	releaseall
	end

ViridianCity_Text_InvestigatingTeamRocket:
	.string "Officer: We're investigating a\n"
	.string "rumor that Team Rocket was seen\l"
	.string "in this area.\p"
	.string "We can't let anyone through until\n"
	.string "we've completed our search.$"

ViridianCity_EventScripts_ReturnJennyToPosition1::
	applymovement LOCALID_OFFICER, Movement_JennyStepsRight
	waitmovement 1
	return

Movement_JennyStepsRight:
	walk_right
	face_up
	step_end

ViridianCity_EventScripts_ReturnJennyToPosition2::
	applymovement LOCALID_OFFICER, Movement_JennyStepsLeft
	waitmovement 1
	return

Movement_JennyStepsLeft:
	walk_left
	face_up
	step_end

Movement_PlayerStepsBack:
	walk_down
	walk_down
	step_end

