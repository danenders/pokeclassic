.set LOCALID_OAK, 1
.set LOCALID_SAILOR, 7

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	call Common_EventScript_GetDayOrNight
	end

VermilionCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_Text_CitySign::
    .string "Vermilion City\n"
    .string "The Port of Exquisite Sunsets$"

@TODO: Change text depending on Snorlax State
VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_Text_SnorlaxBlockingRoute12::
    .string "NOTICE!\p"
    .string "Route 12 may be blocked off by a\n"
    .string "sleeping Pokémon.\p"
    .string "Detour through Rock Tunnel to\n"
    .string "Lavender Town.\p"
    .string "Vermilion Police$"

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_Text_PokemonFanClubSign::
    .string "Pokémon Fan Club\n"
    .string "All Pokémon fans welcome!$"

VermilionCity_EventScript_GymSign::
	lockall
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

VermilionCity_Text_GymSign::
    .string "Vermilion City Pokémon Gym\n"
    .string "Leader: Lt. Surge\l"
    .string "The Lightning Lieutenant!$"

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_VermilionHarbor::
    .string "Vermilion Harbor$"

VermilionCity_EventScript_ProfOakTrigger1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 2
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOakTrigger3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 3
	goto VermilionCity_EventScript_ProfOak

VermilionCity_EventScript_ProfOak::
	applymovement LOCALID_OAK, Movement_OakDockApproach
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitse
	playbgm MUS_RG_OAK, 0
	call_if_eq VAR_TEMP_1, 1, VermilionCity_EventScript_OakApproachPlayer1
	call_if_eq VAR_TEMP_1, 2, VermilionCity_EventScript_OakApproachPlayer2
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakApproachPlayer3
	waitmovement 1
	msgbox VermilionCity_Text_VisitedSSAnne, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOak, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_PROF_OAK
	setvar VAR_OAK_LAB_STATE, 9
	release
	msgbox VermilionCity_Text_EnjoySSAnne, MSGBOX_DEFAULT
	call_if_le VAR_TEMP_1, 2, VermilionCity_EventScript_OakExit
	call_if_eq VAR_TEMP_1, 3, VermilionCity_EventScript_OakExitAlt
	waitmovement 1
	removeobject LOCALID_OAK
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	fadedefaultbgm
	releaseall
	end

Movement_OakDockApproach::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VermilionCity_Text_VisitedSSAnne::
	.string "Oak: Oh! {PLAYER}! Were you headed\n"
	.string "to visit the S.S. Anne?\p"
	.string "I'm afraid you just missed my\n"
	.string "presentation about the Pokédex!\p"
	.string "What, you didn't know I was going\n"
	.string "to be there? That's a shame...\p"
	.string "Oh! I know! You have a Cell Phone,\n"
	.string "right? I'll give you my number!\p"
	.string "That way, I could contact you if\n"
	.string "anything comes up again. And if\l"
	.string "you'd like, you can call me to rate\l"
	.string "your Pokédex even while you're\l"
	.string "out in the field.$"

VermilionCity_Text_EnjoySSAnne::
	.string "Oak: It was good to see you!\n"
	.string "Enjoy your time on the S.S. Anne.\p"
	.string "There are a lot of strong trainers\n"
	.string "gathering there, but don't get\l"
	.string "too distracted from your Pokédex!$"

VermilionCity_EventScript_OakApproachPlayer1::
	applymovement LOCALID_OAK, Movement_OakDockEntrance1
	return

Movement_OakDockEntrance1::
	walk_up
	walk_up
	walk_left
	face_up
	step_end

VermilionCity_EventScript_OakApproachPlayer2::
	applymovement LOCALID_OAK, Movement_OakDockEntrance2
	return

Movement_OakDockEntrance2::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_OakApproachPlayer3::
	applymovement LOCALID_OAK, Movement_OakDockEntrance3
	return

Movement_OakDockEntrance3::
	walk_up
	walk_up
	walk_right
	face_up
	step_end

VermilionCity_EventScript_OakExit::
	applymovement LOCALID_OAK, Movement_OakDockExit
	return

Movement_OakDockExit::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VermilionCity_EventScript_OakExitAlt::
	applymovement LOCALID_OAK, Movement_OakDockExitAlt
	return

Movement_OakDockExitAlt::
	walk_left
	walk_up
	walk_up
	walk_up
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


VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_VERMILION_CITY_STATE, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
    .string "Did you see the S.S. Anne moored\n"
    .string "in the harbor?$"

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_Text_SSAnneHasDepartedForYear::
    .string "So, the S.S. Anne has departed?\p"
    .string "She'll be back in Vermilion about\n"
    .string "this time next year.$"

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_Text_GrimerMultipliesInSludge::
    .string "We're careful about pollution here.\p"
    .string "We've heard Grimer multiplies in\n"
    .string "toxic sludge.$"

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_Text_BuildingOnThisLand::
    .string "I'm putting up a building on this\n"
    .string "plot of land. I own it all.\p"
    .string "My Pokémon is tamping the land\n"
    .string "to lay the foundation.$"

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop, MSGBOX_NPC
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat, MSGBOX_NPC
	release
	end

VermilionCity_Text_Machop::
    .string "Machop: Guoh! Gogogoh!$"

VermilionCity_Text_MachopStompingLandFlat::
    .string "A Machop is stomping the land flat.$"

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_Text_SSAnneVisitsOnceAYear::
    .string "The S.S. Anne is a famous luxury\n"
    .string "cruise ship.\p"
    .string "It visits Vermilion once a year.$"

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_VERMILION_CITY_STATE, 3, VermilionCity_EventScript_CheckSSTidal
	msgbox VermilionCity_Text_WelcomeToTheSSAnne, MSGBOX_NPC
	release
	end

VermilionCity_Text_WelcomeToTheSSAnne::
    .string "Sailor: Welcome to the S.S. Anne!$"

VermilionCity_EventScript_CheckSSTidal::
	goto_if_unset FLAG_HIDE_SS_TIDAL, VermilionCity_EventScript_SSTidalArrived
	msgbox VermilionCity_Text_TheShipSetSail, MSGBOX_NPC
	release
	end

VermilionCity_Text_TheShipSetSail::
    .string "The ship set sail.$"

VermilionCity_EventScript_SSTidalArrived::
	.string "Have you heard?\p"
	.string "A new ship, the S.S. Tidal, has\n"
	.string "arrived in the harbor!$"

VermilionCity_EventScript_TicketCheckTrigger1::
	lock
	setvar VAR_TEMP_2, 1
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheckTrigger2::
	lock
	setvar VAR_TEMP_2, 2
	goto VermilionCity_EventScript_TicketCheck
	end

VermilionCity_EventScript_TicketCheck::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_TicketCheck1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_TicketCheck2
	waitmovement 7
	msgbox VermilionCity_Text_DoYouHaveATicket, MSGBOX_NPC
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_EventScript_NoTicket
	playse SE_PIN
	msgbox VermilionCity_Text_FlashedSSTicket, MSGBOX_DEFAULT
	setvar VAR_SS_TICKET_CHECK, 1
	waitse
	msgbox VermilionCity_Text_SailorGreat, MSGBOX_NPC
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	end

VermilionCity_Text_DoYouHaveATicket::
    .string "Sailor: Welcome to the S.S. Anne!\p"
    .string "Excuse me, do you have a ticket?$"

VermilionCity_Text_FlashedSSTicket::
    .string "{PLAYER} flashed the S.S. TICKET!$"

VermilionCity_Text_SailorGreat:: 
    .string "Sailor: Great!\n"
    .string "Welcome to the S.S. Anne!$"

VermilionCity_EventScript_TicketCheck1::
	applymovement LOCALID_SAILOR, Movement_TicketCheck1
	return

Movement_TicketCheck1::
	walk_left
	walk_left
	face_up
	step_end

VermilionCity_EventScript_TicketCheck2::
	applymovement LOCALID_SAILOR, Movement_TicketCheck2
	return

Movement_TicketCheck2::
	walk_left
	face_up
	step_end

VermilionCity_EventScript_NoTicket::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark 
	waitmovement 0
	waitse
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	call_if_eq VAR_TEMP_2, 1, VermilionCity_EventScript_MoveSailor1
	call_if_eq VAR_TEMP_2, 2, VermilionCity_EventScript_MoveSailor2
	waitmovement 7
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CannotEnterSSAnne
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

VermilionCity_Text_DontHaveNeededSSTicket::
    .string "Sorry!\p"
    .string "You need an S.S. Ticket to board.$"

VermilionCity_EventScript_MoveSailor1::
	applymovement LOCALID_SAILOR, Movement_MoveSailor1
	return

Movement_MoveSailor1::
	walk_right
	walk_right
	face_up
	step_end

VermilionCity_EventScript_MoveSailor2::
	applymovement LOCALID_SAILOR, Movement_MoveSailor2
	return

Movement_MoveSailor2::
	walk_right
	face_up
	step_end

Movement_CannotEnterSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_SS_TICKET_CHECK, 0
	releaseall
	end
