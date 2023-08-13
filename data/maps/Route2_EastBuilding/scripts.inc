Route2_EastBuilding_MapScripts::
	.byte 0

@Aide Gift 1
Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05, MSGBOX_DEFAULT
	checkitemspace ITEM_HM05, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_HM05, 1
	waitmessage
	setflag FLAG_RECEIVED_HM05
	setflag FLAG_HIDE_AIDE_ROUTE2
	clearflag FLAG_AIDE_LOCATION_1
	clearflag FLAG_QUEUE_AIDE_CALL
	setvar VAR_AIDE_CALL_STEP_COUNTER, 0
	call_if_set FLAG_BADGE03_GET, Route2_EastBuilding_EventScript_AideNextLocation
	msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
	release
	end

Route2_EastBuilding_Text_GiveHM05::
    .string "Hi! Thanks for meeting me, {PLAYER}.\p"
    .string "We've been monitoring your progress\n"
    .string "back at the lab! You're doing great!\p"
    .string "I'm here to deliver your reward.\p"
    .string "Professor Oak entrusted me with\n"
    .string "HM05 for you.$"

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05, MSGBOX_DEFAULT
	release
	end

Route2_EastBuilding_Text_ExplainHM05::
    .string "HM05 contains the hidden move\n"
    .string "Flash.\p"
    .string "Flash lights up even the darkest\n"
    .string "of caves and dungeons.$"

Route2_EastBuilding_EventScript_AideNextLocation::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_2
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
    .string "Once a Pokémon learns Flash, you\n"
    .string "can get through Rock Tunnel.$"
