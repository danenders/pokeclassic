.set LOCALID_TOWER_ATTENDANT, 1

IndigoPlateau_BattleTower_Lobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTowerLobby_OnFrame
	.byte 0

BattleTowerLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleTowerLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleTowerLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleTowerLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleTowerLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleTowerLobby_EventScript_LostChallenge
	.2byte 0

BattleTowerLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleTowerLobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTowerLobby_Text_DidntSaveBeforeQuitting:
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleTowerLobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleTowerLobby_EventScript_EnterElevator
	end

BattleTowerLobby_Text_WeveBeenWaitingForYou:
	.string "We've been waiting for you!\p"
	.string "$"

BattleTowerLobby_Text_ProgressWillBeSaved:
	.string "Before entering a Battle Room, your\n"
	.string "progress will be saved. Please wait.$"

BattleTowerLobby_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleTowerLobby_EventScript_DefeatedMaiden
	message BattleTowerLobby_Text_CongratsBeatenSeven
	waitmessage
	goto BattleTowerLobby_EventScript_GiveRibbons

BattleTowerLobby_Text_CongratsBeatenSeven:
	.string "Congratulations!\n"
	.string "You've beaten all seven Trainers!\p"
	.string "$"

BattleTowerLobby_EventScript_DefeatedMaiden::
	msgbox BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleTowerLobby_EventScript_GiveBattlePoints
	message BattleTowerLobby_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_GiveBattlePoints::
	msgbox BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	call BattleTowerLobby_EventScript_AskSaveBattle
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleTowerLobby_EventScript_LookForwardToChallenge
	msgbox BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_LookForwardToChallenge::
	msgbox BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTowerLobby_Text_CongratsDefeatedMaiden:
	.string "Congratulations!\n"
	.string "You have defeated the Salon Maiden\l"
	.string "and swept seven Trainers!$"

BattleTowerLobby_Text_AwardYouTheseBattlePoints:
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleTowerLobby_Text_HereAreSomeRibbons:
	.string "Here are some Ribbons for beating\n"
	.string "seven tough Trainers in a row.\p"
	.string "{PLAYER} received some Ribbons!$"

BattleTowerLobby_Text_PutRibbonOnMons:
	.string "{PLAYER} put the Ribbons on\n"
	.string "the challenger Pokémon.$"

BattleTowerLobby_Text_AboutToFace50thTrainer:
	.string "You're finally about to face the\n"
	.string "50th Trainer.\p"
	.string "From here on, every time you beat seven\n"
	.string "Trainers in a row, your Pokémon will\l"
	.string "receive a commemorative Ribbon.\p"
	.string "Good luck!$"

BattleTowerLobby_EventScript_LostChallenge::
	goto_if_ne VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleTowerLobby_EventScript_CancelWinStreak
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
BattleTowerLobby_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleTowerLobby_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	call BattleTowerLobby_EventScript_AskSaveBattle
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTowerLobby_Text_ThankYouForPlaying:
	.string "Thank you for playing!\p"
	.string "$"

BattleTowerLobby_EventScript_AskSaveBattle::
	message BattleTowerLobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	tower_save 0
	playse SE_SAVE
	waitse
	call BattleTowerLobby_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleTowerLobby_EventScript_EndSaveBattle
	case 0, BattleTowerLobby_EventScript_SaveBattle
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_EndSaveBattle

BattleTowerLobby_Text_RecordWillBeSaved:
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleTowerLobby_EventScript_SaveBattle::
	frontier_savebattle
	goto_if_eq VAR_RESULT, FALSE, BattleTowerLobby_EventScript_BattleSaveFailed
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndSaveBattle

BattleTowerLobby_EventScript_BattleSaveFailed::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_EndSaveBattle::
	return

BattleTowerLobby_EventScript_GetCantRecordBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return

BattleTowerLobby_EventScript_BattleTowerAttendant::
	lock
	faceplayer
	msgbox BattleTowerLobby_Text_ChallengeBattleTower, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	release
	end

BattleTowerLobby_Text_ChallengeBattleTower::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come around to the front if you\n"
	.string "are!$"

BattleTowerLobby_EventScript_BattleTowerTrigger::
	lock
	setvar VAR_TEMP_2, 1
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleTowerLobby_Text_TowerWelcome, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, BattleTowerLobby_EventScript_TryEnterSinglesChallenge
	case 1, BattleTowerLobby_EventScript_TryEnterDoublesChallenge
	case 2, BattleTowerLobby_EventScript_TryEnterMultisChallenge
	case 3, BattleTowerLobby_EventScript_ExplainChallenge
	case 4, BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_CancelChallenge
	end

BattleTowerLobby_EventScript_BattleTowerBlocker::
	lock
	playse SE_PIN
	applymovement LOCALID_TOWER_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleTowerLobby_Text_ChallengeBattleTowerBlocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTowerLobby_Text_ChallengeBattleTowerBlocker::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come speak to me if you\n"
	.string "are!$"

Movement_PlayerFaceTowerKiosk:
	face_left
	step_end

BattleTowerLobby_Text_TowerWelcome:
	.string "Welcome to the Battle Tower,\n"
	.string "where the talents of Trainers\l"
	.string "are put to the test!\p"
	.string "I'll be your guide to the\n"
	.string "Battle Rooms.\p"
	.string "Which type of challenge will\n"
	.string "you be participating in today?$"


BattleTowerLobby_EventScript_TryEnterSinglesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	message BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 0, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleTower_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	end


BattleTowerLobby_EventScript_TryEnterDoublesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	message BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 0, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleTower_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	end

BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	goto BattleTowerLobby_EventScript_EnterElevator
	end

BattleTowerLobby_EventScript_TryEnterMultisChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	message BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 0, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleTower_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
	case MULTI_B_PRESSED, BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleTowerLobby_EventScript_SaveBeforeMultisChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleTowerLobby_EventScript_EnterElevator
	end

BattleTower_EventScript_GetLvlMode::
	frontier_get FRONTIER_DATA_LVL_MODE
	return

BattleTowerLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLv50::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
	case FRONTIER_MODE_DOUBLES, BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles::
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles::
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
	case FRONTIER_MODE_DOUBLES, BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles::
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles::
	msgbox BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis:
	.string "Excuse me!\p"
	.string "You don't have two eligible Pokémon.\p"
	.string "You must have two different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis:
	.string "Excuse me!\p"
	.string "You don't have two eligible Pokémon.\p"
	.string "You must have two different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Eggs{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTowerLobby_Text_SelectThreeMons:
	.string "Now please select the three Pokémon\n"
	.string "that are to be entered.$"

BattleTowerLobby_EventScript_ExplainChallenge::
	msgbox BattleTowerLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleTowerLobby_EventScript_ChooseBattleTowerMode
	end

BattleTowerLobby_Text_ExplainChallenge:
	.string "The Battle Tower is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "Single Battle, Double Battle, and\l"
	.string "Multi Battle.\p"
	.string "For each of these types, there are\n"
	.string "separate Battle Rooms.\p"
	.string "Depending on the Battle Room you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of Pokémon.\p"
	.string "The Single Battle mode requires\n"
	.string "three Pokémon, and the Double Battle\l"
	.string "mode requires four.\p"
	.string "In the Multi Battle mode, you will\n"
	.string "choose a partner to battle alongside you,\l" 
	.string "and each trainer will bring two Pokémon.$"

BattleTowerLobby_Text_WhichLevelMode:
	.string "Which level mode will you be\n"
	.string "challenging today?$"

BattleTowerLobby_Text_OkayToSaveBeforeEntering:
	.string "Before entering a Battle Room, your\n"
	.string "progress must be saved. Is that okay?$"

BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_0, 255
	goto_if_eq VAR_RESULT, 0, BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	goto BattleTowerLobby_EventScript_EnterElevator
	end

BattleTowerLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
	goto BattleTowerLobby_EventScript_CancelChallenge
	end

BattleTowerLobby_EventScript_EnterElevator::
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleTowerLobby_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	@LINK OPPONENT SCRIPT/MACRO REMOVED
	call BattleTowerLobby_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleTowerLobby_EventScript_GetPartySize::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTowerLobby_EventScript_GetSinglesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTowerLobby_EventScript_GetDoublesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleTowerLobby_EventScript_GetMultisPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleTowerLobby_EventScript_GetLinkMultisPartySize
	return

BattleTowerLobby_EventScript_GetSinglesPartySize::
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	return

BattleTowerLobby_EventScript_GetDoublesPartySize::
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	return

BattleTowerLobby_EventScript_GetMultisPartySize::
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	return

BattleTowerLobby_EventScript_GetLinkMultisPartySize::
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	return

BattleTowerLobby_EventScript_ShowYouToBattleRoom::
	call BattleTowerLobby_EventScript_BufferModeText
	goto_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom
	msgbox BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
	goto BattleTowerLobby_EventScript_WalkToElevator

BattleTowerLobby_EventScript_BufferModeText::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTowerLobby_EventScript_BufferTextSingle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTowerLobby_EventScript_BufferTextDouble
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleTowerLobby_EventScript_BufferTextMulti
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS, BattleTowerLobby_EventScript_BufferTextLinkMulti
	return

BattleTowerLobby_EventScript_BufferTextSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleTowerLobby_EventScript_BufferTextDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleTowerLobby_EventScript_BufferTextMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleTowerLobby_EventScript_BufferTextLinkMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleTowerLobby_EventScript_ShowYouToLinkMultiBattleRoom::
	messageautoscroll BattleTowerLobby_Text_ShowYouToBattleRoom
	waitmessage
	delay 48
BattleTowerLobby_EventScript_WalkToElevator::
	closemessage
	applymovement LOCALID_TOWER_ATTENDANT, BattleTowerLobby_Movement_WalkToPlayer
	waitmovement 1
	applymovement LOCALID_TOWER_ATTENDANT, BattleTowerLobby_Movement_WalkToElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTowerLobby_Movement_WalkToElevator
	waitmovement 0
	opendoor 3, 1
	waitdooranim
	applymovement LOCALID_TOWER_ATTENDANT, BattleTowerLobby_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTowerLobby_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 3, 1
	waitdooranim
	return

BattleTowerLobby_Movement_WalkToPlayer:
	walk_up
	walk_right
	walk_right
	step_end

BattleTowerLobby_Movement_WalkToElevator:
	walk_up
	step_end

BattleTowerLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTowerLobby_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

BattleTowerLobby_Text_ShowYouToBattleRoom:
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} Battle Room.$"

BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
BattleTowerLobby_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
BattleTowerLobby_EventScript_EndCancelChallenge::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

Movement_LeaveKiosk:
	walk_down
	step_end

BattleTowerLobby_Text_LookForwardToAnotherChallenge:
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleTowerLobby_Text_PleaseSelectFourMons:
	.string "Now please select the four Pokémon\n"
	.string "that are to be entered.$"

BattleTowerLobby_Text_PleaseSelectTwoMons:
	.string "Now please select the two Pokémon\n"
	.string "that are to be entered.$"
