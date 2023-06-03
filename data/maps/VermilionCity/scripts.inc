.set LOCALID_OAK, 1
.set LOCALID_SAILOR, 7
.set LOCALID_JENNY, 9
.set LOCALID_SQUIRTLE, 10

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	setflag FLAG_VISITED_VERMILION_CITY
	call_if_set FLAG_GOT_SQUIRTLE,  VermillionCity_EventScript_RepositionJenny
	call Common_EventScript_GetDayOrNight
	end

VermillionCity_EventScript_RepositionJenny::
	setobjectxyperm LOCALID_JENNY, 22, 20
	setobjectmovementtype LOCALID_JENNY, MOVEMENT_TYPE_LOOK_AROUND
	return

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
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
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
	goto_if_eq VAR_SS_ANNE_STATE, 3, VermilionCity_EventScript_CheckSSTidal
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

VermilionCity_EventScript_SquirtleEventAlternate::
	setvar VAR_GOT_SQUIRTLE, 2
VermilionCity_EventScript_SquirtleEvent::
	lockall
	turnobject LOCALID_JENNY, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitse
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_EventScript_DontGiveSquirtle
	call_if_eq VAR_GOT_SQUIRTLE, 2, VermilionCity_EventScript_Sidestep
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepForward
	waitmovement 0
	playse SE_PIN
	message VermilionCity_Text_PlayerFlashedBadge
	waitse
	waitmessage
	msgbox VermilionCity_Text_AStrongTrainer, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_JENNY, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_SQUIRTLE, Movement_MoveToPlayer
	waitmovement 10
	playse SE_PIN
	applymovement LOCALID_SQUIRTLE, Common_Movement_Heart
	setvar VAR_TEMP_1, SPECIES_SQUIRTLE
	givemon SPECIES_SQUIRTLE, 10, ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, 0, VermilionCity_EventScript_SquirtleParty
	goto_if_eq VAR_RESULT, 1, VermilionCity_EventScript_SquirtlePC
	goto_if_eq VAR_RESULT, 2, VermilionCity_EventScript_NoRoomForSquirtle
	releaseall
	end


VermilionCity_EventScript_SquirtleParty::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_GotSquirtle
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_GetSquirtle::
	playfanfare MUS_LEVEL_UP
	message VermilionCity_EventScript_Text_BailedOutSquirtle
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	return

VermilionCity_EventScript_Text_BailedOutSquirtle::
	.string "{PLAYER} bailed out the Squirtle!$"

VermilionCity_EventScript_GotSquirtle::
	setflag FLAG_GOT_SQUIRTLE
	setvar VAR_GOT_SQUIRTLE, 1
	removeobject LOCALID_SQUIRTLE
	release
	end

VermilionCity_EventScript_SquirtlePC::
	call VermilionCity_EventScript_GetSquirtle
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VermilionCity_EventScript_TransferSquirtle
	call Common_EventScript_NameReceivedBoxMon
	goto VermilionCity_EventScript_TransferSquirtle
	end

VermilionCity_EventScript_TransferSquirtle::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto VermilionCity_EventScript_GotSquirtle
	end

VermilionCity_EventScript_NoRoomForSquirtle::
	msgbox VermilionCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	applymovement LOCALID_SQUIRTLE, Movement_SquirtleReturn
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	release
	end

Movement_SquirtleReturn::
	walk_right
	walk_up
	face_left
	step_end

VermilionCity_Text_NoRoomForMorePokemon::
    .string "Officer: You don't have room?\n"
    .string "Guess it's off to jail then!$"

VermilionCity_EventScript_Sidestep::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_Sidestep
	waitmovement 0
	return

Movement_Sidestep::
	walk_left
	step_end

Movement_MoveToPlayer::
	walk_down
	walk_left
	step_end

VermilionCity_Text_PlayerFlashedBadge::
	.string "{PLAYER} flashed their Thunder Badge.$"

VermilionCity_Text_AStrongTrainer::
	.string "Officer: Oh! You have a Thunder Badge?\p"
	.string "You must be quite a strong trainer.\p"
	.string "What's that?\p"
	.string "You're saying you'll vouch for this\n"
	.string "Pokémon?\p"
	.string "...\p"
	.string "I'm not sure what my boss will say\n"
	.string "about this, but I have a good feeling\l"
	.string "about you.\p"
	.string "You've proven your skills as a Pokémon\n"
	.string "trainer, after all.\p"
	.string "Maybe a good role model is what this\n"
	.string "Pokémon needs!$"


VermilionCity_EventScript_DontGiveSquirtle::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	setvar VAR_GOT_SQUIRTLE, 0
	release
	end

 Movement_StepForward::
 	walk_up
 	step_end

VermilionCity_Text_SquirtleIsAMenace::
	.string "Officer: Stand back, citizen!\p"
	.string "This Squirtle is a menace!\p"
	.string "It's been committing crimes all\n"
	.string "over Vermilion City!\p"
	.string "I've got it cornered, but I'm\n"
	.string "waiting for backup to take it in!$"

VermilionCity_EventScript_Jenny::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SQUIRTLE, VermilionCity_EventScript_JennyGaveSquirtle
	msgbox VermilionCity_Text_SquirtleIsAMenace, MSGBOX_NPC
	release
	end

VermilionCity_EventScript_JennyGaveSquirtle::
	msgbox VermilionCity_Text_JennyGaveSquirtle, MSGBOX_NPC
	release
	end

VermilionCity_Text_JennyGaveSquirtle::
	.string "First it was Bikers and Burglars,\n"
	.string "and then it was Team Rocket.\p"
	.string "This job is hard enough without\n"
	.string "Pokémon resorting to crime, too!$"

VermilionCity_EventScript_Squirtle::
	lock
	faceplayer
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_SquirtleGlasses, MSGBOX_NPC
	release
	end

VermilionCity_Text_SquirtleGlasses::
	.string "Is that Squirtle wearing sunglasses?$"
	
VermilionCity_EventScript_Blastoisinite::
	finditem ITEM_BLASTOISINITE, 1
	release
	end
