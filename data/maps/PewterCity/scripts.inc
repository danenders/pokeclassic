.set LOCALID_MUSEUM_GUIDE, 2
.set LOCALID_GYM_GUIDE, 5
.set LOCALID_LADY, 14
.set LOCALID_SLOWPOKE, 13
.set LOCALID_FUGITIVE, 15

@VAR_PEWTER_CITY_STATE
@0 = Brock Undefeated
@1 = Brock Defeated

PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PewterCity_OnResume
	.byte 0

PewterCity_OnTransition:
	setflag FLAG_VISITED_PEWTER_CITY
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 0
	call Common_EventScript_GetDayOrNight
	end

PewterCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

PewterCity_Trigger_RegisterOakAide::
	goto_if_set FLAG_REGISTERED_AIDE, Common_EventScript_End
	lockall
	goto_if_unset FLAG_MET_CEDAR, PewterCity_Trigger_RegisterOakAideAlternate
	pokenavcall MatchCall_Text_AideIntro
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	releaseall
	end

PewterCity_Trigger_RegisterOakAideAlternate::
	pokenavcall MatchCall_Text_AideIntro2
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	releaseall
	end

PewterCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_BrockOnlySeriousTrainerHere::
    .string "There aren't many serious Pokémon\n"
    .string "Trainers here.\p"
    .string "They're all like Bug Catchers,\n"
    .string "you know, just hobbyists.\p"
    .string "But Pewter Gym's Brock isn't like\n"
    .string "that, not one bit.$"


PewterCity_EventScript_MuseumGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
	msgbox PewterCity_Text_ReallyYouHaveToGo, MSGBOX_DEFAULT
	closemessage
	delay 10
	playbgm MUS_RG_FOLLOW_ME, 0
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
	goto_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
	end

PewterCity_Text_DidYouCheckOutMuseum::
    .string "Did you check out the Museum?$"

PewterCity_Text_ReallyYouHaveToGo::
    .string "Really?\n"
    .string "You absolutely have to go!$"

PewterCity_EventScript_LeadToMuseumNorth::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumNorth::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumNorth::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumSouth::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumSouth::
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumSouth::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumWest::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumWest::
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumWest::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_LeadToMuseumEast::
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
	waitmovement 0
	goto PewterCity_EventScript_MuseumGuideFinished

PewterCity_Movement_PlayerWalkToMuseumEast::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_Movement_GuideWalkToMuseumEast::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

PewterCity_EventScript_MuseumGuideFinished::
	msgbox PewterCity_Text_ThisIsTheMuseum, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_MUSEUM_GUIDE
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
	release
	end

PewterCity_Movement_MuseumGuideExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Text_ThisIsTheMuseum::
    .string "This is it, the Museum.\p"
    .string "You have to pay to get in, but it's\n"
    .string "worth it. See you around!$"

PewterCity_EventScript_CheckedOutMuseum::
	msgbox PewterCity_Text_WerentThoseFossilsAmazing, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_WerentThoseFossilsAmazing::
    .string "Weren't those fossils from Mt. Moon\n"
    .string "amazing?$"

PewterCity_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_DoYouKnowWhatImDoing::
    .string "Psssst!\n"
    .string "Do you know what I'm doing?$"

PewterCity_Text_SprayingRepelToKeepWildMonsOut::
    .string "I'm spraying Repel to keep wild\n"
    .string "Pokémon out of my garden!$"

PewterCity_EventScript_KnowWhatTheyreDoing::
	msgbox PewterCity_Text_ThatsRightItsHardWork, MSGBOX_DEFAULT
	release
	end

PewterCity_Text_ThatsRightItsHardWork::
    .string "That's right!\n"
    .string "It's hard work!$"

PewterCity_EventScript_Lass::
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
	end

PewterCity_Text_ClefairyCameFromMoon::
    .string "Clefairy came from the moon.\n"
    .string "That's what the rumor is.\p"
    .string "They appeared after Moon Stones\n"
    .string "fell on Mt. Moon.$"


PewterCity_EventScript_GymGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_FOLLOW_ME, 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWaitForGuideEast::
	delay_16
	delay_16
	delay_4
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

PewterCity_Movement_GuideMoveToLeadEast::
	walk_down
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_up
	walk_in_place_up
	step_end

PewterCity_Movement_GuideWalkToGymEast::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_Movement_PlayerWalkToGymEast::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_EventScript_GymGuideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTrigger::
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_FOLLOW_ME, 0
	goto_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
	goto_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
	goto_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
	end

PewterCity_EventScript_WalkToGymTop::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymTop::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadTop::
	walk_left
	walk_down
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymTop::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_WalkToGymMid::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymMid::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadMid::
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymMid::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_WalkToGymBottom::
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
	waitmovement 0
	goto PewterCity_EventScript_GymGuideFinish

PewterCity_Movement_PlayerWalkToGymBottom::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_Movement_GuideMoveToLeadBottom::
	walk_down
	walk_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymBottom::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

PewterCity_EventScript_GymGuideFinish::
	msgbox PewterCity_Text_GoTakeOnBrock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	release
	end

PewterCity_Movement_GymGuideExit::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Text_GoTakeOnBrock::
    .string "If you have the right stuff,\n"
    .string "go take on Brock!$"

PewterCity_Text_BrocksLookingForChallengersFollowMe::
    .string "You're a Trainer, right?\p"
    .string "Brock's looking for new\n"
    .string "challengers. Follow me!$"

PewterCity_EventScript_TrainerTips::
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
	end

PewterCity_Text_TrainerTipsEarningEXP::
    .string "Trainer Tips:\p"
    .string "All Pokémon that appear in battle,\n"
    .string "however briefly, earn Exp Points.$"


PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
	end

PewterCity_Text_CitySign::
    .string "Pewter City\n"
    .string "A Stone Gray City$"

PewterCity_EventScript_PoliceNotice::
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
	end

PewterCity_Text_CallPoliceIfInfoOnThieves::
    .string "NOTICE!\p"
    .string "Thieves have been stealing Pokémon\n"
    .string "fossils from Mt. Moon.\p"
    .string "Please call the Pewter Police if\n"
    .string "you have any information.$"

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
	end

PewterCity_Text_MuseumOfScience::
    .string "Pewter City Science Museum$"

PewterCity_EventScript_GymSign::
	lockall
	msgbox PewterCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

PewterCity_Text_GymSign::
    .string "Pewter City Pokémon GYM\n"
    .string "Leader: Brock\l"
    .string "The Rock-Solid Pokémon Trainer!$"


PewterCity_EventScript_SlowpokeLady::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_MIXING_BERRY, PewterCity_EventScript_WatchedSlowpoke
	msgbox PewterCity_Text_RunAnErrand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_WatchSlowpoke
	msgbox PewterCity_Text_MaybeLater, MSGBOX_NPC
	release
	end

PewterCity_Text_RunAnErrand::
	.string "Oh, hello there.\p"
	.string "My Slowpoke likes to come here and\n"
	.string "look at the berries with me.\p"
	.string "It's usually quite nice, but I need\n"
	.string "to run an errand today...\p"
	.string "Could you stay here with Slowpoke for\n"
	.string "a moment so I could run my errand?$"

PewterCity_Text_MaybeLater::
	.string "Oh, I guess I could run my errand\n"
	.string "later then...$"


PewterCity_EventScript_WatchSlowpoke::
	msgbox PewterCity_Text_WatchSlowpoke, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LadyLeave1
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LadyLeave2
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LadyLeave3
	waitmovement 14
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	fadescreen FADE_TO_BLACK
	delay 48
	delay 48
	playmoncry SPECIES_SLOWPOKE, CRY_MODE_NORMAL
	waitmoncry
	delay 48
	delay 48
	fadescreen FADE_FROM_BLACK
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LadyReturn1
	call_if_eq VAR_FACING, DIR_EAST,	PewterCity_EventScript_LadyReturn2
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LadyReturn3
	waitmovement 14
	msgbox PewterCity_Text_ThankYouForWatchingSlowpoke, MSGBOX_NPC
	random 14
	call_if_eq VAR_RESULT, 0, PewterCity_EventScript_GiveBelueBerry
	call_if_eq VAR_RESULT, 1, PewterCity_EventScript_GiveDurinBerry
	call_if_eq VAR_RESULT, 2, PewterCity_EventScript_GiveWatmelBerry
	call_if_eq VAR_RESULT, 3, PewterCity_EventScript_GivePamtreBerry
	call_if_eq VAR_RESULT, 4, PewterCity_EventScript_GiveSpelonBerry
	call_if_eq VAR_RESULT, 5, PewterCity_EventScript_GiveNomelBerry
	call_if_eq VAR_RESULT, 6, PewterCity_EventScript_GiveRabutaBerry
	call_if_eq VAR_RESULT, 7, PewterCity_EventScript_GiveMagostBerry
	call_if_eq VAR_RESULT, 8, PewterCity_EventScript_GiveCornnBerry
	call_if_eq VAR_RESULT, 9, PewterCity_EventScript_GivePinapBerry
	call_if_eq VAR_RESULT, 10, PewterCity_EventScript_GiveWepearBerry
	call_if_eq VAR_RESULT, 11, PewterCity_EventScript_GiveNanabBerry
	call_if_eq VAR_RESULT, 12, PewterCity_EventScript_GiveBlukBerry
	call_if_eq VAR_RESULT, 13, PewterCity_EventScript_GiveRazzBerry
	setflag FLAG_DAILY_MIXING_BERRY
	goto PewterCity_EventScript_WatchedSlowpoke
	end

PewterCity_EventScript_WatchedSlowpoke::
	msgbox PewterCity_Text_SlowpokeLovesPokeblocks, MSGBOX_NPC
	release
	end

PewterCity_Text_SlowpokeLovesPokeblocks::
	.string "My Slowpoke here loves the\n"
	.string "PokéBlocks that are made with\l"
	.string "those berries.\p"
	.string "If only I had a way to make my\n"
	.string "my own at home!$"

PewterCity_EventScript_GiveBelueBerry::
	giveitem ITEM_BELUE_BERRY, 1
	return

PewterCity_EventScript_GiveDurinBerry::
	giveitem ITEM_DURIN_BERRY, 1
	return

PewterCity_EventScript_GiveWatmelBerry::
	giveitem ITEM_WATMEL_BERRY, 1
	return

PewterCity_EventScript_GivePamtreBerry::
	giveitem ITEM_PAMTRE_BERRY, 1
	return

PewterCity_EventScript_GiveSpelonBerry::
	giveitem ITEM_SPELON_BERRY, 1
	return

PewterCity_EventScript_GiveNomelBerry::
	giveitem ITEM_NOMEL_BERRY, 1
	return

PewterCity_EventScript_GiveRabutaBerry::
	giveitem ITEM_RABUTA_BERRY, 1
	return

PewterCity_EventScript_GiveMagostBerry::
	giveitem ITEM_MAGOST_BERRY, 1
	return

PewterCity_EventScript_GiveCornnBerry::
	giveitem ITEM_CORNN_BERRY, 1
	return

PewterCity_EventScript_GivePinapBerry::
	giveitem ITEM_PINAP_BERRY, 1
	return

PewterCity_EventScript_GiveWepearBerry::
	giveitem ITEM_WEPEAR_BERRY, 1
	return

PewterCity_EventScript_GiveNanabBerry::
	giveitem ITEM_NANAB_BERRY, 1
	return

PewterCity_EventScript_GiveBlukBerry::
	giveitem ITEM_BLUK_BERRY, 1
	return

PewterCity_EventScript_GiveRazzBerry::
	giveitem ITEM_RAZZ_BERRY, 1
	return

PewterCity_Text_ThankYouForWatchingSlowpoke::
	.string "Sorry that took so long!\p"
	.string "Let me give you something\n"
	.string "for your trouble.$"

PewterCity_Text_WatchSlowpoke::
	.string "Oh, thank you!\n"
	.string "This won't take long at all!$"


PewterCity_EventScript_LadyLeave1:
	applymovement LOCALID_LADY, Movement_LadyLeave1
	return

PewterCity_EventScript_LadyLeave2:
	applymovement LOCALID_LADY, Movement_LadyLeave2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

PewterCity_EventScript_LadyLeave3:
	applymovement LOCALID_LADY, Movement_LadyLeave1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

Movement_LadyLeave1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_LadyLeave2:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PewterCity_EventScript_LadyReturn1::
	applymovement LOCALID_LADY, Movement_LadyReturn1
	return

PewterCity_EventScript_LadyReturn2::
	applymovement LOCALID_LADY, Movement_LadyReturn2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

PewterCity_EventScript_LadyReturn3::
	applymovement LOCALID_LADY, Movement_LadyReturn1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

Movement_LadyReturn1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Movement_LadyReturn2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PewterCity_EventScript_Slowpoke::
	lock
	faceplayer
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_SLOWPOKE, Common_Movement_QuestionMark
	waitse
	waitmovement 13
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end
	end

PewterCity_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end