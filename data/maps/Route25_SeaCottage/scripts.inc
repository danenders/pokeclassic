.set LOCALID_BILL_HUMAN,    1
.set LOCALID_BILL_CLEFAIRY, 2
.set LOCALID_PIKACHU, 3

@VAR_SEA_COTTAGE_STATE
@0 = Nothing yet. Runs Pikachu event if starter is in party
@1 = Checked for Pikachu event
@2 = Bill is in Teleporter
@3 = Rescued Bill
@4 = Got Badge 2, but didn't get DexNav. Only set by Misty, if you have Badge 2 when rescuing Bill, this is skipped.
@5 = Received the call to come to Bill's. Set in Cerulean, if you already had Badge 2 when rescuing Bill this is also skipped.
@6 = Got DexNav

Route25_SeaCottage_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_SeaCottage_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route25_SeaCottage_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route25_SeaCottage_OnFrame
	.byte 0

Route25_SeaCottage_OnTransition::
	goto_if_ge VAR_SEA_COTTAGE_STATE, 3, Route25_SeaCottage_SetBillPosition
	end

Route25_SeaCottage_OnWarp:
	map_script_2 VAR_SEA_COTTAGE_STATE, 0, Route25_SeaCottage_CheckPartnerSceneSetups
	.2byte 0

Route25_SeaCottage_CheckPartnerSceneSetups::
	special IsPartnerInParty
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_End
	setflag FLAG_HIDE_FOLLOWER
	clearflag FLAG_HIDE_SEA_COTTAGE_PIKACHU
	addobject LOCALID_PIKACHU
	end

Route25_SeaCottage_SetBillPosition::
	setobjectxyperm LOCALID_BILL_HUMAN, 7,5
	end

Route25_SeaCottage_OnFrame:
	map_script_2 VAR_SEA_COTTAGE_STATE, 0, Route25_SeaCottage_PikachuLabScene
	.2byte 0

Route25_SeaCottage_PikachuLabScene::
	lock
	applymovement LOCALID_PIKACHU, Movement_PikachuScopesOutLab
	waitmovement 3
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	applymovement LOCALID_PIKACHU, Common_Movement_ExclamationMark
	waitmoncry
	applymovement LOCALID_PIKACHU, Movement_ReturnToPlayer
	waitmovement 3
	removeobject LOCALID_PIKACHU
	clearflag FLAG_HIDE_FOLLOWER
	setvar VAR_SEA_COTTAGE_STATE, 1
	release
	end

Movement_PikachuScopesOutLab::
	walk_up
	walk_up
	face_left
	delay_16
	face_right
	delay_16
	face_down
	emote_question_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	emote_question_mark
	delay_16
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Movement_ReturnToPlayer::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_SYS_DETECTOR_MODE, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto_if_set FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_CheckDexNavEvent
	goto_if_set FLAG_GOT_SS_TICKET, Route25_SeaCottage_EventScript_GetDexNavOrSmallTalk
	goto_if_set FLAG_HELPED_BILL_IN_SEA_COTTAGE, Route25_SeaCottage_EventScript_BillGiveSSTicket
	goto Route25_SeaCottage_EventScript_BillAskForHelp
	end

Route25_SeaCottage_EventScript_CheckDexNavEvent::
	goto_if_unset FLAG_BADGE05_GET, Route25_SeaCottage_EventScript_BillGoLookAtPC
	goto Route25_SeaCottage_EventScript_GetDexNavUpgrade
	end

Route25_SeaCottage_EventScript_BillAskForHelp::
	msgbox Route25_SeaCottage_Text_ImBillHelpMeOutPal, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Route25_SeaCottage_EventScript_DeclineHelpBill
	msgbox Route25_SeaCottage_Text_RunCellSeparationOnPC, MSGBOX_DEFAULT
	closemessage
	delay 10
	call_if_eq VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth
	call_if_ne VAR_FACING, DIR_SOUTH, Route25_SeaCottage_EventScript_BillWalkToTeleporter
	opendoor 10, 3
	waitdooranim
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillEnterTeleporter
	waitmovement 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	removeobject LOCALID_BILL_CLEFAIRY
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 10, 3
	waitdooranim
	setflag FLAG_BILL_IN_TELEPORTER
	setvar VAR_SEA_COTTAGE_STATE, 2
	release
	end

Route25_SeaCottage_Text_ImBillHelpMeOutPal::
    .string "Hiya! I'm a Pokémon…\n"
    .string "…No I'm not!\p"
    .string "Call me Bill!\n"
    .string "I'm a true-blue PokéManiac!\p"
    .string "Hey!\n"
    .string "What's with that skeptical look?\p"
    .string "I'm not joshing you, pal.\p"
    .string "I screwed up an experiment and got\n"
    .string "combined with a Pokémon!\p"
    .string "So, how about it?\n"
    .string "Help me out here!$"

Route25_SeaCottage_EventScript_DeclineHelpBill::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_BILL_CLEFAIRY, Common_Movement_ExclamationMark
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox Route25_SeaCottage_Text_NoPlease, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_NoPlease::
    .string "No!?\n"
    .string "Now don't be so cold!\p"
    .string "Come on, you gotta help a guy in\n"
    .string "deep, deep trouble!\p"
    .string "What do you say?\n"
    .string "Please?\l"
    .string "Okay?\l"
    .string "All right!$"

Route25_SeaCottage_Text_RunCellSeparationOnPC::
    .string "Wait till I get inside the\n"
    .string "teleporter.\p"
    .string "When I do, go to my PC and run\n"
    .string "the Cell Separation System.$"

Route25_SeaCottage_EventScript_BillWalkToTeleporterSouth::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporterSouth
	waitmovement 2
	return

Route25_SeaCottage_Movement_BillWalkToTeleporterSouth::
	walk_right
	walk_up
	walk_up
	walk_left
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

Route25_SeaCottage_EventScript_BillWalkToTeleporter::
	applymovement LOCALID_BILL_CLEFAIRY, Route25_SeaCottage_Movement_BillWalkToTeleporter
	waitmovement 2
	return

Route25_SeaCottage_Movement_BillWalkToTeleporter::
	walk_up
	walk_up
	step_end

Route25_SeaCottage_Movement_BillEnterTeleporter::
	walk_up
	step_end

Route25_SeaCottage_EventScript_Computer::
	lockall
	goto_if_set FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_OpenBillsMonList
	goto_if_set FLAG_BILL_IN_TELEPORTER, Route25_SeaCottage_EventScript_RunCellSeparator
	msgbox Route25_SeaCottage_Text_TeleporterIsDisplayed
	releaseall
	end

Route25_SeaCottage_Text_TeleporterIsDisplayed::
    .string "Teleporter.exe is displayed on the\n"
    .string "PC's monitor.$"

Route25_SeaCottage_EventScript_RunCellSeparator::
	fadeoutbgm 0
	msgbox Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator
	closemessage
	clearflag FLAG_BILL_IN_TELEPORTER
	setvar VAR_SEA_COTTAGE_STATE, 3
	setflag FLAG_HELPED_BILL_IN_SEA_COTTAGE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Route25_SeaCottage_Movement_CameraPanToTeleporters
	waitmovement 0
	delay 35
	playse SE_PIN
	waitse
	setvar VAR_0x8004, 0
	special AnimateTeleporterHousing
	delay 10
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	setvar VAR_0x8004, 1
	special AnimateTeleporterHousing
	playse SE_WARP_IN
	special AnimateTeleporterCable
	waitse
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	call Route25_SeaCottage_EventScript_PlayTeleporterBeepSE
	opendoor 3, 3
	waitdooranim
	fadeinbgm 0
	addobject LOCALID_BILL_HUMAN
	clearflag FLAG_HIDE_SEA_COTTAGE_BILL
	delay 50
	playfanfare MUS_LEVEL_UP
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillExitTeleporter
	waitmovement 1
	waitfanfare
	applymovement OBJ_EVENT_ID_CAMERA, Route25_SeaCottage_Movement_CameraPanBackFromTeleporters
	waitmovement 0
	playse SE_CONTEST_CURTAIN_FALL
	closedoor 3, 3
	waitdooranim
	applymovement LOCALID_BILL_HUMAN, Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom
	waitmovement 1
	special RemoveCameraObject
	releaseall
	end

Route25_SeaCottage_Text_InitiatedTeleportersCellSeparator::
    .string "{PLAYER} opened Teleporter.exe!\n"
    .string "It initiated the Cell Separator.$"

Route25_SeaCottage_Movement_CameraPanToTeleporters::
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route25_SeaCottage_EventScript_PlayTeleporterBeepSE::
	playse SE_BALL
	waitse
	delay 20
	return

Route25_SeaCottage_Movement_BillExitTeleporter::
	walk_down
	step_end

Route25_SeaCottage_Movement_CameraPanBackFromTeleporters::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

Route25_SeaCottage_Movement_BillWalkToMiddleOfRoom::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Route25_SeaCottage_EventScript_BillGiveSSTicket::
	msgbox Route25_SeaCottage_Text_ThanksTakeThis, MSGBOX_DEFAULT
	checkitemspace ITEM_SS_TICKET, 1
	goto_if_eq VAR_RESULT, FALSE, Route25_SeaCottage_EventScript_NoRoomForSSTicket
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_ReceivedSSTicketFromBill
	waitfanfare
	waitmessage
	additem ITEM_SS_TICKET, 1
	setflag FLAG_GOT_SS_TICKET
	setflag FLAG_SYS_PC_BILL
	closemessage
	goto Route25_SeaCottage_EventScript_CheckRegisterBill
	end

Route25_SeaCottage_Text_ThanksTakeThis::
    .string "Bill: Yeehah!\n"
    .string "Thanks, bud! I owe you one!\p"
    .string "So, did you come to see my\n"
    .string "Pokémon collection?\p"
    .string "You didn't?\n"
    .string "That's a bummer.\p"
    .string "I've got to thank you…\n"
    .string "Oh, here, maybe this'll do.$"

Route25_SeaCottage_Text_ReceivedSSTicketFromBill::
    .string "{PLAYER} received an S.S. Anne\n"
    .string "ticket from Bill.$"

Route25_SeaCottage_EventScript_NoRoomForSSTicket::
	msgbox Route25_SeaCottage_Text_YouveGotTooMuchStuff
	release
	end
	
Route25_SeaCottage_Text_YouveGotTooMuchStuff::
    .string "You've got too much stuff!$"


Route25_SeaCottage_EventScript_GetDexNavOrSmallTalk::
	goto_if_unset FLAG_SYS_DEXNAV_GET, Route25_SeaCottage_EventScript_CheckRegisterBill
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_CheckRegisterBill::
	goto_if_set FLAG_BADGE02_GET, Route25_SeaCottage_EventScript_RegisterBill
	goto Route25_SeaCottage_EventScript_BillGoToSSAnne
	end

Route25_SeaCottage_EventScript_BillGoToSSAnne::
	msgbox Route25_SeaCottage_Text_SSAnnePartyYouGoInstead, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_Text_SSAnnePartyYouGoInstead::
    .string "Bill: That cruise ship S.S. Anne\n"
    .string "is in Vermilion City.\p"
    .string "I hear there are lots of trainers\n"
    .string "on board, too.\p"
    .string "They invited me to their party, but\n"
    .string "I can't stand fancy do's.\p"
    .string "Why don't you go instead of me?\n"
    .string "Go on and have a good time.$"

Route25_SeaCottage_EventScript_RegisterBill::
	msgbox Route25_SeaCottage_Text_ReallyOweYouOne, MSGBOX_DEFAULT
	applymovement LOCALID_BILL_HUMAN, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route25_SeaCottage_Text_IsThatAPokedex, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_GetDexNav
	waitfanfare
	waitmessage
	closemessage
	msgbox Route25_SeaCottage_Text_StillABeta, MSGBOX_DEFAULT
	setflag FLAG_SYS_DEXNAV_GET
	setvar VAR_SEA_COTTAGE_STATE, 6
	playfanfare MUS_REGISTER_MATCH_CALL
	message MatchCall_Text_RegisteredBill
	waitfanfare 
	waitmessage
	closemessage
	setflag FLAG_REGISTERED_BILL
	goto Route25_SeaCottage_EventScript_ExplainDexNav
	end
	
Route25_SeaCottage_Text_ReallyOweYouOne::
	.string "Bill: You know, I really owe you\n"
	.string "for helping with my teleporter\l"
	.string "accident.\p"
	.string "I wish I could repay the favor\n"
	.string "with something more than that\l"
	.string "S.S. Ticket...$"

Route25_SeaCottage_Text_IsThatAPokedex::
	.string "Oh! Is that a Pokédex?\p"
	.string "The other guy that came by\n"
	.string "earlier had one of those, too.\p"
	.string "You've got a PokéGear, right?\p"
	.string "Let me hook you up with an app\n"
	.string "I've been developing.$"

Route25_SeaCottage_Text_GetDexNav::
	.string "Bill added the DexNav app to\n"
	.string "{PLAYER}'s PokéGear!$"

Route25_SeaCottage_Text_StillABeta::
	.string "Bill: It's still technically in\n"
	.string "its Beta stages, I guess.\p"
	.string "There are a few more features I'd\n"
	.string "like to add, but it might take some\l"
	.string "time.\p"
	.string "I know! I'll give you my Cell Phone\n"
	.string "number.\p"
	.string "You can keep me updated on how the\n"
	.string "DexNav is working, and I can let you\l"
	.string "know if I have any new updates!$"

Route25_SeaCottage_EventScript_ExplainDexNav::
	msgbox Route25_SeaCottage_Text_ExplainDexNav, MSGBOX_DEFAULT
	release
	end

Route25_SeaCottage_Text_ExplainDexNav::
	.string "I learned about the PokéDex while\n"
	.string "emailing with Prof. Oak!\p"
	.string "The DexNav should make finding rare\n"
	.string "Pokémon more interesting!\p"
	.string "You can track all sorts of Pokémon\n"
	.string "with it, but it works best when it\l"
	.string "has data from the PokéDex to learn\l"
	.string "from! Try catching lots of Pokémon!$"

Route25_SeaCottage_EventScript_DontLeaveMe::
	lock
	playse SE_WALL_HIT
	waitse
	playse SE_WALL_HIT
	waitse
	playse SE_WALL_HIT
	waitse
	msgbox Route25_SeaCottage_Text_DontLeaveMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_DontLeaveBills
	waitmovement 0
	release
	end

Route25_SeaCottage_Text_DontLeaveMe::
	.string "Bill: Hey! Did you run the program?\p"
	.string "Hello?\n"
	.string "Hello!?\p"
	.string "Don't leave me in here!$"

Movement_DontLeaveBills:
	walk_up
	step_end


Route25_SeaCottage_EventScript_BillGoLookAtPC::
	msgbox Route25_SeaCottage_Text_CheckOutRareMonsOnPC, MSGBOX_NPC
	release
	end

Route25_SeaCottage_Text_CheckOutRareMonsOnPC::
    .string "Bill: Feel like checking out some\n"
    .string "of my rare Pokémon on my PC?\p"
    .string "Go on, check out my PC.$"

Route25_SeaCottage_EventScript_OpenBillsMonList::
	msgbox Route25_SeaCottage_Text_BillsFavoriteMonList
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_Text_BillsFavoriteMonList::
    .string "Bill's favorite Pokémon list!$"

Route25_SeaCottage_EventScript_BillsMonList::
	message Route25_SeaCottage_Text_SeeWhichMon
	waitmessage
	multichoice 0, 0, MULTI_BILLS_POKEMON, FALSE
	switch VAR_RESULT
	case 0, Route25_SeaCottage_EventScript_ViewEevee
	case 1, Route25_SeaCottage_EventScript_ViewFlareon
	case 2, Route25_SeaCottage_EventScript_ViewJolteon
	case 3, Route25_SeaCottage_EventScript_ViewVaporeon
	case 4, Route25_SeaCottage_EventScript_ExitBillsMonList
	case MULTI_B_PRESSED, Route25_SeaCottage_EventScript_ExitBillsMonList
	end

Route25_SeaCottage_Text_SeeWhichMon::
    .string "Which Pokémon do you want to see?$"

Route25_SeaCottage_EventScript_ViewEevee::
	showmonpic SPECIES_EEVEE, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_EEVEE
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewFlareon::
	showmonpic SPECIES_FLAREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_FLAREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewJolteon::
	showmonpic SPECIES_JOLTEON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_JOLTEON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ViewVaporeon::
	showmonpic SPECIES_VAPOREON, 10, 3
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_VAPOREON
	special SetSeenMon
	goto Route25_SeaCottage_EventScript_BillsMonList
	end

Route25_SeaCottage_EventScript_ExitBillsMonList::
	releaseall
	end

Route25_SeaCottage_EventScript_GetDexNavUpgrade::
	msgbox Route25_SeaCottage_Text_HeyPlayerBeatGiovanni, MSGBOX_DEFAULT
	call_if_set FLAG_GAVE_BILL_IDEA, Route25_SeaCottage_EventScript_GaveBillIdea
	call_if_unset FLAG_GAVE_BILL_IDEA, Route25_SeaCottage_EventScript_BillHadIdea
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message Route25_SeaCottage_Text_GetDetectorMode
	waitfanfare
	waitmessage
	closemessage
	msgbox Route25_SeaCottage_Text_DetectorMode, MSGBOX_DEFAULT
	setflag FLAG_SYS_DETECTOR_MODE
	release
	end

Route25_SeaCottage_Text_HeyPlayerBeatGiovanni::
	.string "Bill: Hey, {PLAYER}!\n"
	.string "Thanks for coming by.\p"
	.string "I've been seeing a lot of buzz about\n"
	.string "you online!\p"
	.string "So, are all the rumors I was reading\n"
	.string "on the net true?\p"
	.string "Did you really take down Team Rocket's\n"
	.string "Boss?\p"
	.string "Wow. That's incredible.$"

Route25_SeaCottage_EventScript_GaveBillIdea::
	msgbox Route25_SeaCottage_Text_YourIdea, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_YourIdea::
	.string "I'm glad you called earlier.\n"
	.string "You gave me a great idea!\p"
	.string "All this talk about Giovanni and his\n"
	.string "hidden base... it got me thinking about\l"
	.string "what else could be hiding all around us.\p"
	.string "Maybe there's rare Pokémon right under\n"
	.string "our noses!\p"
	.string "I think this upgrade will help us find\n"
	.string "out if I'm right!$"

Route25_SeaCottage_EventScript_BillHadIdea::
	msgbox Route25_SeaCottage_Text_MyIdea, MSGBOX_DEFAULT
	return

Route25_SeaCottage_Text_MyIdea::
	.string "Anyway, I'm glad you came by.\n"
	.string "I've been working on some upgrades for\l"
	.string "the DexNav.\p"
	.string "I think this upgrade will be realy useful!$"

Route25_SeaCottage_Text_GetDetectorMode::
	.string "Bill upgraded your DexNav!\n"
	.string "Detector Mode has been enabled!$"

Route25_SeaCottage_Text_DetectorMode::
	.string "Bill: Detector Mode helps you find\n"
	.string "hidden Pokémon all across Kanto!\p"
	.string "Hidden Pokémon may know new moves\n"
	.string "or even have rare abilities.\p"
	.string "It's truly amazing!\n"
	.string "Go try it out!$"
