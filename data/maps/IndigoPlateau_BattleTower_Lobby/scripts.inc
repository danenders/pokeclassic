.set LOCALID_TOWER_ATTENDANT, 1

IndigoPlateau_BattleTower_Lobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerLobby_OnWarp
	.byte 0

BattleFrontier_BattleTowerLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerLobby_EventScript_TurnPlayer
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_TurnPlayer::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

BattleFrontier_BattleTowerLobby_OnFrame:
	map_script_2 VAR_TEMP_0, 0, BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleFrontier_BattleTowerLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleFrontier_BattleTowerLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleTowerLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleTowerLobby_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	release
	end

BattleFrontier_BattleTowerLobby_Text_DidntSaveBeforeQuitting:
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

Movement_LeaveKiosk:
	walk_down
	step_end

BattleFrontier_BattleTowerLobby_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden
	message BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons

BattleFrontier_BattleTowerLobby_Text_CongratsBeatenSeven:
	.string "Congratulations!\n"
	.string "You've beaten all seven Trainers!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_EventScript_DefeatedMaiden::
	msgbox BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints
	message BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_LookForwardToChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleFrontier_BattleTowerLobby_Text_CongratsDefeatedMaiden:
	.string "Congratulations!\n"
	.string "You have defeated the Salon Maiden\l"
	.string "and swept seven Trainers!$"



BattleFrontier_BattleTowerLobby_EventScript_LostChallenge::
	goto_if_ne VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying
BattleFrontier_BattleTowerLobby_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleFrontier_BattleTowerLobby_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying
	waitmessage
	call BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle::
	message BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	tower_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	message BattleFrontier_BattleTowerLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle
	case 0, BattleFrontier_EventScript_SaveBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_SaveBattle::
	frontier_savebattle
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_EventScript_BattleSaveFailed
	playse SE_SAVE
	msgbox BattleFrontier_BattleTowerLobby_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle

BattleFrontier_EventScript_BattleSaveFailed::
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle::
	return

BattleFrontier_EventScript_GetCantRecordBattle::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return

BattleFrontier_BattleTowerLobby_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end


BattleFrontier_BattleTowerLobby_EventScript_BattleTowerAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_BattleTowerLobby_Text_ChallengeBattleTower, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	release
	end

BattleFrontier_BattleTowerLobby_Text_ChallengeBattleTower::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come around to the front if you\n"
	.string "are!$"

BattleFrontier_BattleTowerLobby_EventScript_BattleTowerTrigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleFrontier_BattleTowerLobby_Text_TowerWelcome, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge
	case 1, BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge
	case 2, BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge
	case 3, BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge
	case 4, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_BattleTowerBlocker::
	lock
	playse SE_PIN
	applymovement LOCALID_TOWER_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleFrontier_BattleTowerLobby_Text_ChallengeBattleTowerBlocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleFrontier_BattleTowerLobby_Text_ChallengeBattleTowerBlocker::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come speak to me if you\n"
	.string "are!$"

BattleFrontier_Movement_PlayerFaceTowerKiosk:
	face_left
	step_end

BattleFrontier_BattleTowerLobby_Text_TowerWelcome:
	.string "Welcome to the Battle Tower,\n"
	.string "where the talents of Trainers\l"
	.string "are put to the test!\p"
	.string "I'll be your guide to the\n"
	.string "Battle Rooms.\p"
	.string "Which type of challenge will\n"
	.string "you be participating in today?$"

BattleFrontier_BattleTowerLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleTowerLobby_EventScript_ChooseBattleTowerMode
	end

BattleFrontier_BattleTowerLobby_Text_ExplainChallenge:
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

BattleFrontier_BattleTowerLobby_Text_WhichLevelMode:
	.string "Which level mode will you be\n"
	.string "challenging today?$"

BattleFrontier_BattleTowerLobby_EventScript_TryEnterSinglesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeSinglesChallenge::
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
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_TryEnterDoublesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeDoublesChallenge::
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
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_TryEnterMultisChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	message BattleFrontier_BattleTowerLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	msgbox BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge
	case YES, BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge

BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeMultisChallenge::
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
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleFrontier_BattleTowerLobby_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Singles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLv50Doubles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpen::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles
	case FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenSingles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_NotEnoughValidMonsLvOpenDoubles::
	msgbox BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
	goto BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge
	end

BattleFrontier_BattleTowerLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
BattleFrontier_BattleTowerLobby_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleTowerLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_EnterElevator::
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleFrontier_BattleTowerLobby_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	call BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleFrontier_BattleTowerLobby_EventScript_ShowYouToBattleRoom::
	call BattleFrontier_BattleTowerLobby_EventScript_BufferModeText
	msgbox BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator

BattleFrontier_BattleTowerLobby_EventScript_WalkToElevator::
	closemessage
	applymovement LOCALID_TOWER_ATTENDANT, BattleFrontier_BattleTowerLobby_Movement_WalkToPlayer
	waitmovement 1
	applymovement LOCALID_TOWER_ATTENDANT, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_WalkToElevator
	waitmovement 0
	opendoor 3, 1
	waitdooranim
	applymovement LOCALID_TOWER_ATTENDANT, BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 3, 1
	waitdooranim
	return

BattleFrontier_BattleTowerLobby_Movement_WalkToPlayer:
	walk_up
	walk_right
	walk_right
	step_end

BattleFrontier_BattleTowerLobby_Movement_WalkToElevator:
	walk_up
	step_end

BattleFrontier_BattleTowerLobby_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerLobby_EventScript_BufferModeText::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_BattleTowerLobby_EventScript_BufferTextMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_BattleTowerLobby_EventScript_GetPartySize::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS, BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize
	return

BattleFrontier_BattleTowerLobby_EventScript_GetSinglesPartySize::
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetDoublesPartySize::
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	return

BattleFrontier_BattleTowerLobby_EventScript_GetMultisPartySize::
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	return

BattleFrontier_EventScript_GetLvlMode::
	frontier_get FRONTIER_DATA_LVL_MODE
	return

BattleFrontier_BattleTowerLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_Text_WinsInRowRecorded:
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleFrontier_BattleTowerLobby_EventScript_Boy::
	msgbox BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end

BattleFrontier_BattleTowerLobby_Text_CanLeaveUntilLossOrSevenWins:
	.string "Once you've entered the Battle Tower,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven Trainers in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"


BattleFrontier_BattleTowerLobby_Text_HereAreSomeRibbons:
	.string "Here are some Ribbons for beating\n"
	.string "seven tough Trainers in a row.\p"
	.string "{PLAYER} received some Ribbons!$"

BattleFrontier_BattleTowerLobby_Text_PutRibbonOnMons:
	.string "{PLAYER} put the Ribbons on\n"
	.string "the challenger Pokémon.$"

BattleFrontier_BattleTowerLobby_Text_LookForwardToAnotherChallenge:
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleFrontier_BattleTowerLobby_Text_OkayToSaveBeforeEntering:
	.string "Before entering a Battle Room, your\n"
	.string "progress must be saved. Is that okay?$"

BattleFrontier_BattleTowerLobby_Text_ShowYouToBattleRoom:
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} Battle Room.$"

BattleFrontier_BattleTowerLobby_Text_RecordLastMatch:
	.string "Shall I record your last Battle Tower\n"
	.string "match on your Frontier Pass?$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Singles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenSingles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Doubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenDoubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLv50Multis:
	.string "Excuse me!\p"
	.string "You don't have two eligible Pokémon.\p"
	.string "You must have two different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_NotEnoughValidMonsLvOpenMultis:
	.string "Excuse me!\p"
	.string "You don't have two eligible Pokémon.\p"
	.string "You must have two different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleFrontier_BattleTowerLobby_Text_SelectThreeMons:
	.string "Now please select the three Pokémon\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectFourMons:
	.string "Now please select the four Pokémon\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_PleaseSelectTwoMons:
	.string "Now please select the two Pokémon\n"
	.string "that are to be entered.$"

BattleFrontier_BattleTowerLobby_Text_SaveGameBeforeShowingIn:
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_AwardYouTheseBattlePoints:
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleFrontier_BattleTowerLobby_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleTowerLobby_Text_ThankYouForPlaying:
	.string "Thank you for playing!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_RecordWillBeSaved:
	.string "Your record will be saved.\n"
	.string "Please wait.$"

BattleFrontier_BattleTowerLobby_Text_WeveBeenWaitingForYou:
	.string "We've been waiting for you!\p"
	.string "$"

BattleFrontier_BattleTowerLobby_Text_ProgressWillBeSaved:
	.string "Before entering a Battle Room, your\n"
	.string "progress will be saved. Please wait.$"

BattleFrontier_BattleTowerLobby_Text_AboutToFace50thTrainer:
	.string "You're finally about to face the\n"
	.string "50th Trainer.\p"
	.string "From here on, every time you beat seven\n"
	.string "Trainers in a row, your Pokémon will\l"
	.string "receive a commemorative Ribbon.\p"
	.string "Good luck!$"

BattleFrontier_BattleTowerLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleTowerLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleTowerLobby_EventScript_RulesTower
	case 1, BattleFrontier_BattleTowerLobby_EventScript_RulesMons
	case 2, BattleFrontier_BattleTowerLobby_EventScript_RulesSalon
	case 3, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerLobby_EventScript_ExitRules
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesTower::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesMons::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_RulesSalon::
	msgbox BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleTowerLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleTowerLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleTowerLobby_Text_RulesAreListed:
	.string "The Battle Tower rules are listed.$"

BattleFrontier_BattleTowerLobby_Text_ReadWhichHeading:
	.string "Which heading do you want to read?$"

BattleFrontier_BattleTowerLobby_Text_ExplainTowerRules:
	.string "The Battle Tower is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "Single Battle, Double Battle, Multi\l"
	.string "Battle, and Link Multi Battle.\p"
	.string "For each of these types, there are\n"
	.string "separate Battle Rooms.\p"
	.string "Please speak with a guide offering\n"
	.string "the type of battle you wish to enter.$"

BattleFrontier_BattleTowerLobby_Text_ExplainMonRules:
	.string "Depending on the Battle Room you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of Pokémon.\p"
	.string "The Single Battle mode requires\n"
	.string "three Pokémon.\p"
	.string "The Double Battle mode requires four,\n"
	.string "and the Multi modes both require two.$"

BattleFrontier_BattleTowerLobby_Text_ExplainSalonRules:
	.string "The Battle Salon is where you must\n"
	.string "find a partner to form a tag team for\l"
	.string "the Multi Battle Room challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other Trainers'\l"
	.string "Pokémon and their moves.\p"
	.string "You may choose a new tag partner\n"
	.string "after winning seven straight matches.$"

