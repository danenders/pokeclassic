.set LOCALID_OFFICER, 1
.set LOCALID_OLD_MAN, 2

ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianCity_OnResume
	.byte 0

ViridianCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	call ViridianCity_CheckGymStatus
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_CheckGymStatus::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_Return
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_Return
	setvar VAR_VIRIDIAN_CITY_GYM, 1
	return

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


ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_Text_CitySign::
    .string "Viridian City \n"
    .string "The Eternally Green Paradise$"

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_Text_GymSign::
    .string "Viridian City Pokémon Gym$"

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_Text_CatchMonsForEasierBattles::
    .string "Trainer Tips:\p"
    .string "Catch Pokémon and expand your\n"
    .string "collection.\p"
    .string "The more you have, the easier it\n"
    .string "is to battle.$"

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_Text_MovesLimitedByPP::
    .string "Trainer Tips:\p"
    .string "The battle moves of Pokémon are\n"
    .string "limited by their Power Points (PP).\p"
    .string "To replenish PP, rest your tired\n"
    .string "Pokémon at a Pokémon Center.$"

ViridianCity_EventScript_GymDoorLocked::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_StepAside
	waitmovement 0
	releaseall
	end

ViridianCity_Text_GymDoorsAreLocked::
    .string "Viridian Gym's doors are locked…$"

ViridianCity_Movement_StepAside::
	walk_right
	step_end

ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_VIRIDIAN_CITY_GYM, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs, MSGBOX_DEFAULT
	turnobject LOCALID_OLD_MAN, DIR_NORTH
	waitmovement 2
	release
	end

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
    .string "This Pokémon Gym is always closed.\p"
    .string "I wonder who the leader is?$"

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ViridiansGymLeaderReturned::
    .string "Virdian Gym's leader returned!$"

ViridianCity_EventScript_Boy::
	lock
	faceplayer
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_CanCarryMonsAnywhere::
    .string "Those Poké Balls at your waist!\n"
    .string "You have Pokémon, don't you?\p"
    .string "It's great that you can carry and\n"
    .string "use Pokémon anytime, anywhere.$"

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_GoShoppingInPewterOccasionally::
    .string "I go shopping in Pewter City\n"
    .string "occasionally.\p"
    .string "I have to take the winding trail in\n"
    .string "Viridian Forest when I go.$"

ViridianCity_EventScript_OldMan2::
	lock
	faceplayer
	msgbox ViridianCity_Text_UsedToGetGrumpy, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_UsedToGetGrumpy:
	.string "I used to get very grumpy when\n"
	.string "I didn't my coffee.\p"
	.string "I'd block the road and everything!\p"
	.string "It was a whole thing...\p"
	.string "So my granddaughter made me give up\n"
	.string "the stuff.\p"
	.string "Now I get refreshed by talking walks!$"

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ViridianCity_EventScript_YoungsterExplainCaterpillars
	compare VAR_RESULT, NO
	goto_if_eq ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
    .string "You want to know about the two\n"
    .string "kinds of caterpillar Pokémon?$"

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	lock
	faceplayer
	msgbox ViridianCity_Text_ExplainCaterpieWeedle, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_ExplainCaterpieWeedle::
    .string "Caterpie has no poison,\n"
    .string "but Weedle does.\p"
    .string "Watch that your Pokémon aren't\n"
    .string "stabbed by Weedle's Poison Sting.$"

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_OhOkayThen::
    .string "Oh, okay then!$"

ViridianCity_FindItem_Potion::
	finditem ITEM_POTION, 1
	end

ViridianCity_EventScript_BerryTreeGuy::
	lock
	faceplayer
	msgbox ViridianCity_Text_PlantingBerries, MSGBOX_DEFAULT
	release
	end

ViridianCity_Text_PlantingBerries::
	.string "It looks like a Pokémon was digging\n"
	.string "in the ground over here.\p"
	.string "The soil is nice and soft...\n"
	.string "I should plant something there!$"

