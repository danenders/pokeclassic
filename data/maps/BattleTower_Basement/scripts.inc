.set LOCALID_FACTORY_ATTENDANT, 1

BattleTower_Basement_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Basement_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTower_Basement_OnWarp
	.byte 0

BattleTower_Basement_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleTower_Basement_EventScript_TurnPlayer
	.2byte 0

BattleTower_Basement_EventScript_TurnPlayer::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

BattleTower_Basement_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleTower_Basement_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleTower_Basement_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleTower_Basement_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleTower_Basement_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleTower_Basement_EventScript_LostChallenge
	.2byte 0

BattleTower_Basement_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleTower_Basement_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleTower_Basement_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	releaseall
	end

BattleTower_Basement_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleTower_Basement_EventScript_DefeatedHead
	msgbox BattleTower_Basement_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleTower_Basement_EventScript_GiveBattlePoints

BattleTower_Basement_EventScript_DefeatedHead::
	msgbox BattleTower_Basement_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleTower_Basement_EventScript_GiveBattlePoints::
	msgbox BattleTower_Basement_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleTower_Basement_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_save 0
	playse SE_SAVE
	waitse
	msgbox BattleTower_Basement_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	releaseall
	end

BattleTower_Basement_EventScript_LostChallenge::
	lockall
	message BattleTower_Basement_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleTower_Basement_EventScript_ResumeChallenge::
	lockall
	message BattleTower_Basement_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_0, 255
	setvar VAR_0x8006, 2
	goto BattleTower_Basement_EventScript_EnterChallenge

BattleTower_Basement_EventScript_FactoryTrigger::
	lock
	goto_if_set FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, BattleTower_Entrance_EventScript_Retired
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactory_Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_FACTORY_ATTENDANT, DIR_WEST
	msgbox BattleFactoryLobby_Text_Welcome, MSGBOX_DEFAULT
BattleFactoryLobby_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE_2, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Basement_EventScript_SinglesAttendant
	case 1, BattleTower_Basement_EventScript_DoublesAttendant
	case 2, BattleTower_Basement_EventScript_ExplainChallenge
	case 3, BattleTower_Basement_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_CancelChallenge
	end

BattleFactory_Movement_PlayerFaceTowerKiosk::
	face_right
	step_end

BattleFactoryLobby_Text_Welcome:
	.string "Welcome to the Battle Factory,\n"
	.string "where the intelligence of Trainers\l"
	.string "is put to the test!\p"
	.string "I am your guide to the Battle Swap\n"
	.string "Tournament.\p"
	.string "Which type of tournament will\n"
	.string "you be participating in today?$"

BattleTower_Basement_EventScript_SinglesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleTower_Basement_EventScript_StartChallenge
	end

BattleTower_Basement_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleTower_Basement_EventScript_StartChallenge
	end

BattleTower_Basement_EventScript_StartChallenge::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Basement_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Basement_EventScript_TakeDoublesChallenge
	message BattleTower_Basement_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Basement_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Basement_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleTower_Basement_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge

BattleTower_Basement_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_0, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTower_Basement_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleTower_Basement_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleTower_Basement_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_AttendantApproachPlayer
	waitmovement 1
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_ApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactoryLobby_Movement_ApproachDoor
	waitmovement 0
	opendoor 13,1
	waitdooranim
	applymovement LOCALID_FACTORY_ATTENDANT, BattleFactoryLobby_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFactoryLobby_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 13,1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFactoryLobby_Movement_AttendantApproachPlayer:
	walk_up
	walk_left
	walk_left
	step_end

BattleFactoryLobby_Movement_ApproachDoor:
	walk_up
	step_end

BattleFactoryLobby_Movement_PlayerEnterElevator:
	walk_up
BattleFactoryLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTower_Basement_EventScript_TakeSinglesChallenge::
	message BattleTower_Basement_Text_TakeSinglesChallenge
	return

BattleTower_Basement_Text_TakeSinglesChallenge:
	.string "So you'll be taking the Battle\n"
	.string "Swap Single challenge?$"

BattleTower_Basement_EventScript_TakeDoublesChallenge::
	message BattleTower_Basement_Text_TakeDoublesChallenge
	return

BattleTower_Basement_Text_TakeDoublesChallenge:
	.string "So you'll be taking the Battle\n"
	.string "Swap Double challenge?$"

BattleTower_Basement_EventScript_ExplainChallenge::
	msgbox BattleTower_Basement_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleFactoryLobby_EventScript_ChooseBattleTowerMode
	end

BattleTower_Basement_Text_ExplainChallenge:
	.string "The Battle Swap Tournament is a \n"
	.string "competition using only rental Pokémon.\p"
	.string "First, you will be loaned three\n"
	.string "Pokémon specifically for this event.\p"
	.string "Using the supplied rental Pokémon,\n"
	.string "you must conduct either Single or \l"
	.string "Double battles, depending on the mode.\p"
	.string "If you win, you are permitted to trade\n"
	.string "one of your rental Pokémon.\p"
	.string "Repeat this cycle of battling and\n"
	.string "trading--if you win seven times in\l"
	.string "a row, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save, you will be\n"
	.string "disqualified from your challenge.$"

BattleTower_Basement_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleTower_Basement_EventScript_CancelChallenge

BattleTower_Basement_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
BattleTower_Basement_EventScript_CancelChallenge::
	msgbox BattleTower_Basement_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleTower_Basement_Text_LookForwardToNextVisit:
	.string "We look forward to your next visit.$"

BattleTower_Basement_Text_WhichLevelMode:
	.string "Which level do you wish to challenge?\n"
	.string "Level 50 or Open Level?$"

BattleTower_Basement_Text_OkayToSaveBeforeChallenge:
	.string "Before you begin your challenge,\n"
	.string "I need to save the game. Is that okay?$"

BattleTower_Basement_Text_StepThisWay:
	.string "Please step this way.$"

BattleTower_Basement_Text_ReturnMonsSaveResults:
	.string "Thank you for participating!\p"
	.string "I will return your Pokémon in exchange\n"
	.string "for our rental Pokémon.\p"
	.string "I must also save the event results.\n"
	.string "Please wait.$"

BattleTower_Basement_Text_CongratsSevenWins:
	.string "Congratulations! You've won seven\n"
	.string "straight Battle Swap matches!$"

BattleTower_Basement_Text_WaitingForYouToResume:
	.string "We've been waiting for you!\p"
	.string "Before we resume your challenge,\n"
	.string "I must save the game.$"

BattleTower_Basement_Text_DidntSaveBeforeQuitting:
	.string "I'm sorry to say this, but you didn't\n"
	.string "save before you quit playing last time.\p"
	.string "As a result, you have been disqualified\n"
	.string "from your challenge.$"

BattleTower_Basement_Text_CongratsForDefeatingHead:
	.string "Congratulations for defeating\n"
	.string "the Factory Head and winning\l"
	.string "seven matches in a row!$"

BattleTower_Basement_Text_AwardBattlePoints:
	.string "In recognition of your wealth of\n"
	.string "knowledge and keen intelligence,\l"
	.string "we award you these Battle Point(s).$"

BattleTower_Basement_Text_ExchangeMonsAndSave:
	.string "Let me exchange your Pokémon\n"
	.string "for our rental Pokémon.\p"
	.string "I need to save the battle data,\n"
	.string "so please wait.$"

BattleTower_Basement_EventScript_RulesBoard::
	lockall
	msgbox BattleTower_Basement_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_RulesAreListed:
	.string "The Battle Swap rules are listed.$"

BattleTower_Basement_EventScript_ReadRulesBoard::
	message BattleTower_Basement_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Basement_EventScript_RulesBasics
	case 1, BattleTower_Basement_EventScript_RulesSwapPartner
	case 2, BattleTower_Basement_EventScript_RulesSwapNumber
	case 3, BattleTower_Basement_EventScript_RulesSwapNotes
	case 4, BattleTower_Basement_EventScript_RulesOpenLv
	case 5, BattleTower_Basement_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleTower_Basement_EventScript_ExitRules
	end

BattleTower_Basement_Text_ReadWhichHeading:
	.string "Which heading do you want to read?$"

BattleTower_Basement_EventScript_RulesBasics::
	msgbox BattleTower_Basement_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainBasicRules:
	.string "In a Battle Swap event, you may use\n"
	.string "only three Pokémon.\p"
	.string "Whether you are renting or swapping,\n"
	.string "your team may not have two or more\l"
	.string "of the same Pokémon.$"

BattleTower_Basement_EventScript_RulesSwapPartner::
	msgbox BattleTower_Basement_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapPartnerRules:
	.string "You may swap Pokémon only with\n"
	.string "the Trainer you have just defeated.\p"
	.string "You may swap for only those Pokémon\n"
	.string "used by the beaten Trainer.$"

BattleTower_Basement_EventScript_RulesSwapNumber::
	msgbox BattleTower_Basement_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapNumberRules:
	.string "After every battle you win, you may\n"
	.string "swap for one of your defeated\l"
	.string "opponent's Pokémon.\p"
	.string "You will not be able to swap Pokémon\n"
	.string "with the seventh Trainer in the event.$"

BattleTower_Basement_EventScript_RulesSwapNotes::
	msgbox BattleTower_Basement_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainSwapNotesRules:
	.string "There are two key points to be aware\n"
	.string "of when swapping Pokémon.\p"
	.string "First, when swapping, you can't check\n"
	.string "the stats of the Pokémon you are\l"
	.string "about to receive.\p"
	.string "Second, the Pokémon on your team\n"
	.string "are lined up in sequence, depending on\l"
	.string "the order in which you rented them.\p"
	.string "This sequence remains unchanged\n"
	.string "even when swaps are made.$"

BattleTower_Basement_EventScript_RulesOpenLv::
	msgbox BattleTower_Basement_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleTower_Basement_EventScript_ReadRulesBoard
	end

BattleTower_Basement_Text_ExplainOpenLvRules:
	.string "In the Open Level, the rental Pokémon\n"
	.string "and the opposing Trainers' Pokémon\l"
	.string "are all Level 100.$"

BattleTower_Basement_EventScript_ExitRules::
	releaseall
	end

BattleTower_Basement_EventScript_Blocker::
	lock
	playse SE_PIN
	applymovement LOCALID_FACTORY_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleTower_Basement_Text_Blocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Basement_Text_Blocker::
	.string "Oh! Only participants in the Battle\n"
	.string "Swap Tournament can go that way.\p"
	.string "Please come speak to me if you\n"
	.string "are interested in entering!$"

BattleTower_Basement_EventScript_Attendant::
	lock
	faceplayer
	msgbox BattleTower_Basement_Text_JoinBattleSwap, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_WEST
	release
	end

BattleTower_Basement_Text_JoinBattleSwap::
	.string "This is where we conduct the Battle Swap\n"
	.string "tournaments.\p"
	.string "Please come around to the front if you\n"
	.string "are interested in joining.$"

BattleTower_Basement_EventScript_Woman::
	msgbox BattleTower_Basement_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleTower_Basement_Text_NeedKnowledgeOfMonsMoves:
	.string "Hi!\n"
	.string "You, there!\p"
	.string "Are you thinking that the events here\n"
	.string "are easy since you don't need to have\l"
	.string "a raised team of Pokémon?\p"
	.string "I wouldn't be too sure about winning\n"
	.string "that easily.\p"
	.string "If you don't have thorough knowledge\n"
	.string "about Pokémon and their moves,\l"
	.string "it will be tough to keep winning.$"

BattleTower_Basement_EventScript_Camper::
	msgbox BattleTower_Basement_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleTower_Basement_Text_SwappedForWeakMon:
	.string "I swapped for a weak Pokémon…\n"
	.string "I thought it was a good kind to have…\p"
	.string "They wiped the floor with us…$"

BattleTower_Basement_EventScript_Picnicker::
	lock
	faceplayer
	msgbox BattleTower_Basement_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleTower_Basement_Text_NeedToCheckOpponentsMons:
	.string "Things haven't been going my way\n"
	.string "at all.\p"
	.string "You need to check your opponent's\n"
	.string "Pokémon during battle to see if\l"
	.string "they're any good.$"

BattleTower_Basement_EventScript_FatMan::
	msgbox BattleTower_Basement_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleTower_Basement_Text_CantFigureOutStaffHints:
	.string "You know how the staff here give you\n"
	.string "a few hints about your next opponent?\p"
	.string "Well, I'm a full-grown man, but I have\n"
	.string "trouble figuring out their hints.$"

