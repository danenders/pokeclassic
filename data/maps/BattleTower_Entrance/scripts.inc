.set LOCALID_SCOTT, 1
.set LOCALID_TOWER_ATTENDANT, 2

BattleTower_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleTower_Entrance_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleTower_Entrance_OnWarp
	.byte 0

BattleTower_Entrance_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleTower_Entrance_EventScript_TurnPlayer
	.2byte 0

BattleTower_Entrance_OnFrame::
	map_script_2 VAR_BATTLE_TOWER, 0, BattleTower_Entrance_BattleTowerCutscene
	map_script_2 VAR_TEMP_0, 0, BattleTower_Entrance_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_SAVING, BattleTower_Entrance_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_PAUSED, BattleTower_Entrance_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_WON, BattleTower_Entrance_EventScript_WonChallenge
	map_script_2 VAR_TEMP_0, CHALLENGE_STATUS_LOST, BattleTower_Entrance_EventScript_LostChallenge
	.2byte 0

BattleTower_Entrance_EventScript_TurnPlayer::
	goto_if_unset FLAG_SYS_FRONTIER_PASS, BattleTower_Entrance_EventScript_SkipTurnPlayer
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	end

BattleTower_Entrance_EventScript_SkipTurnPlayer::
	end

BattleTower_Entrance_BattleTowerCutscene::
	applymovement OBJ_EVENT_ID_PLAYER, BTCutscene_ApproachScott
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox BattleTower_Entrance_YouMadeIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	msgbox BattleTower_Entrance_LetMeExplain, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox BattleTower_Entrance_GotFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	clearflag FLAG_HIDE_SCOTT_AT_HOUSE
	waitfanfare
	closemessage
	msgbox BattleTower_Entrance_GreatToSeeYouHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottLeave
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox BattleTower_Entrance_ThisIsIt, MSGBOX_DEFAULT	
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SCOTT
	setflag FLAG_HIDE_SCOTT_HALLWAY
	setvar VAR_BATTLE_TOWER, 1
	release
	end

BTCutscene_ApproachScott::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BTCutscene_ScottLeave::
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	face_up
	step_end

BTCutscene_ScottExit::
	walk_down
	walk_down
	delay_16
	step_end


BattleTower_Entrance_YouMadeIt::
	.string "Scott: There you are, Champ!\p"
	.string "You've finally made it to the\n"
	.string "big Leagues.\p"
	.string "What? You don't know what this\n"
	.string "place is?\p"
	.string "This is my pride and joy!\p"
	.string "I wasn't watching your progress\n"
	.string "in the League just for fun, you know.\p"
	.string "I've been scouting out the best\n"
	.string "Pokémon Trainers in Kanto and\l"
	.string "inviting them to this place...\p"
	.string "the Battle Tower!$"

BattleTower_Entrance_LetMeExplain::
	.string "Scott: Let me explain.\p"
	.string "In the Pokémon League, you make\n"
	.string "your way up the ranks by battling\l"
	.string "other trainers in normal matches, right?\p"
	.string "Well, now that you're a Champion, those\n"
	.string "battles might not be enough of a\l"
	.string "challenge for you anymore.\p"
	.string "Only the best trainers from Kanto can\n"
	.string "enter the Battle Tower - so everyone\l"
	.string "you meet is at the top of their game!\p"
	.string "And to top it off, we have different\n"
	.string "rules and regulations than the\l"
	.string "League, too!\p"
	.string "There's all sorts of ways you can battle\n"
	.string "here!.\p" 
	.string "It's every trainer's dream!\p"
	.string "Now that you're here, you'll need one\n"
	.string "one of these!$"

BattleTower_Entrance_GotFrontierPass::
	.string "{PLAYER} got a Tower Pass from\n"
	.string "Scott!$"

BattleTower_Entrance_GreatToSeeYouHere:
	.string "Scott: It's great to see you here,\n"
	.string "it really is!\p"
	.string "Naturally, I hope you'll also experience\n"
	.string "the pure essence of battling.$"

BattleTower_Entrance_ThisIsIt::
	.string "Scott: This is it, champ.\p"
	.string "Your whole career- this is what\n"
	.string "it's been building up to.\p"
	.string "The best battles of your life are\n"
	.string "up that elevator.\p"
	.string "It's been a blast watching you get\n"
	.string "get here!\p"
	.string "I'd probably have to go around the\n"
	.string "world to find another trainer like you...$"

BattleTower_Entrance_CoolTrainerM::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_CoolTrainerM, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_CoolTrainerM::
	.string "I thought I was doing well, but I\n"
	.string "couldn't keep up my streak!\p"
	.string "I was hoping to earn more BP for\n"
	.string "some training items!$"

BattleTower_Entrance_CoolTrainerF::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_CoolTrainerF, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_CoolTrainerF::
	.string "I spent my BP on these weird mints.\p"
	.string "My Pokémon started acting different\n"
	.string "when I gave one to them!$"

BattleTower_Entrance_BattleGirl::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_BattleGirl, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_BattleGirlDisagree
	msgbox BattleTower_Entrance_Text_BattleGirlYes, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_BattleGirlDisagree::
	msgbox BattleTower_Entrance_Text_BattleGirlNo, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_BattleGirl::
	.string "Double Battles are the ultimate\n"
	.string "test of a Trainer's skills!\p"
	.string "Wouldn't you agree?$"

BattleTower_Entrance_Text_BattleGirlYes::
	.string "I knew you'd agree.$"

BattleTower_Entrance_Text_BattleGirlNo::
	.string "Oh, so you're taking his side?$"

BattleTower_Entrance_BlackBelt::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_BlackBelt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_BlackBeltDisagree
	msgbox BattleTower_Entrance_Text_BlackBeltYes, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_BlackBeltDisagree::
	msgbox BattleTower_Entrance_Text_BlackBeltNo, MSGBOX_DEFAULT
	release
	end

BattleTower_Entrance_Text_BlackBelt::
	.string "Single Battles are the ultimate\n"
	.string "test of a Trainer's skills!\p"
	.string "Wouldn't you agree?$"

BattleTower_Entrance_Text_BlackBeltYes::
	.string "I knew you'd agree.$"

BattleTower_Entrance_Text_BlackBeltNo::
	.string "Oh, so you're taking her side?$"




BattleTower_Entrance_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleTower_Entrance_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Entrance_EventScript_Retired::
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

Movement_LeaveKiosk:
	walk_down
	step_end

BattleTower_Entrance_Text_DidntSaveBeforeQuitting:
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleTower_Entrance_EventScript_WonChallenge::
	lock
	faceplayer
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleTower_Entrance_EventScript_DefeatedMaiden
	message BattleTower_Entrance_Text_CongratsBeatenSeven
	waitmessage
	goto BattleTower_Entrance_EventScript_GiveRibbons

BattleTower_Entrance_Text_CongratsBeatenSeven:
	.string "Congratulations!\n"
	.string "You've beaten all seven Trainers!\p"
	.string "$"

BattleTower_Entrance_EventScript_DefeatedMaiden::
	msgbox BattleTower_Entrance_Text_CongratsDefeatedMaiden, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_GiveRibbons::
	tower_giveribbons
	goto_if_eq VAR_RESULT, FALSE, BattleTower_Entrance_EventScript_GiveBattlePoints
	message BattleTower_Entrance_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTower_Entrance_Text_PutRibbonOnMons, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_GiveBattlePoints::
	msgbox BattleTower_Entrance_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 49, BattleTower_Entrance_EventScript_LookForwardToChallenge
	msgbox BattleTower_Entrance_Text_AboutToFace50thTrainer, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_LookForwardToChallenge::
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleTower_Entrance_Text_CongratsDefeatedMaiden:
	.string "Congratulations!\n"
	.string "You have defeated the Salon Maiden\l"
	.string "and swept seven Trainers!$"

BattleTower_Entrance_EventScript_LostChallenge::
	goto_if_ne BattleTower_Entrance_EventScript_CancelWinStreak
	tower_get TOWER_DATA_WIN_STREAK
	goto_if_ne VAR_RESULT, 0, BattleTower_Entrance_EventScript_LostThanksForPlaying
BattleTower_Entrance_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
BattleTower_Entrance_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleTower_Entrance_Text_ThankYouForPlaying
	waitmessage
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end

BattleTower_Entrance_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleTower_Entrance_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleTower_Entrance_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_BattleTowerAttendant::
	lock
	faceplayer
	msgbox BattleTower_Entrance_Text_ChallengeBattleTower, MSGBOX_DEFAULT
	waitmessage
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	release
	end

BattleTower_Entrance_Text_ChallengeBattleTower::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come around to the front if so!$"

BattleTower_Entrance_EventScript_BattleTowerTrigger::
	lock
	goto_if_set FLAG_CANCEL_BATTLE_ROOM_CHALLENGE, BattleTower_Entrance_EventScript_Retired
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_Movement_PlayerFaceTowerKiosk
	turnobject LOCALID_TOWER_ATTENDANT, DIR_EAST
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	special SavePlayerParty
	msgbox BattleTower_Entrance_Text_TowerWelcome, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_ChooseBattleTowerMode::
	multichoice 17, 0, MULTI_BATTLE_MODE_2, FALSE
	switch VAR_RESULT
	case 0, BattleTower_Entrance_EventScript_TryEnterSinglesChallenge
	case 1, BattleTower_Entrance_EventScript_TryEnterDoublesChallenge
	case 2, BattleTower_Entrance_EventScript_ExplainChallenge
	case 3, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	end

BattleTower_Entrance_EventScript_BattleTowerBlocker::
	lock
	playse SE_PIN
	applymovement LOCALID_TOWER_ATTENDANT, Common_Movement_ExclamationMark
	waitse
	msgbox BattleTower_Entrance_Text_ChallengeBattleTowerBlocker, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_LeaveKiosk
	waitmovement 0
	release
	end

BattleTower_Entrance_Text_ChallengeBattleTowerBlocker::
	.string "Oh! Are you interested in challenging\n"
	.string "the Battle Tower?\p"
	.string "Please come speak to me if so!$"

BattleFrontier_Movement_PlayerFaceTowerKiosk::
	face_left
	step_end

BattleTower_Entrance_Text_TowerWelcome:
	.string "Welcome to the Battle Tower,\n"
	.string "where the talents of Trainers\l"
	.string "are put to the test!\p"
	.string "I'll be your guide to the\n"
	.string "Battle Rooms.\p"
	.string "Which type of challenge will\n"
	.string "you be participating in today?$"

BattleTower_Entrance_EventScript_ExplainChallenge::
	msgbox BattleTower_Entrance_Text_ExplainChallenge, MSGBOX_DEFAULT
	waitmessage
	goto BattleTower_Entrance_EventScript_ChooseBattleTowerMode
	end

BattleTower_Entrance_Text_ExplainChallenge:
	.string "The Battle Tower is a facility where\n"
	.string "two types of battles are waged--\l"
	.string "Single Battle and Double Battles.\p"
	.string "For each of these types, there are\n"
	.string "separate Battle Rooms.\p"
	.string "Depending on the Battle Room you are\n"
	.string "entering, you will be required to take\l"
	.string "a certain number of Pokémon.\p"
	.string "The Single Battle mode requires\n"
	.string "three Pokémon, and the Double Battle\l"
	.string "mode requires four.$"

BattleTower_Entrance_Text_WhichLevelMode:
	.string "Which level mode will you be\n"
	.string "challenging today?$"

BattleTower_Entrance_EventScript_TryEnterSinglesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	message BattleTower_Entrance_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTower_Entrance_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Entrance_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	msgbox BattleTower_Entrance_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	case YES, BattleTower_Entrance_EventScript_SaveBeforeSinglesChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge

BattleTower_Entrance_EventScript_SaveBeforeSinglesChallenge::
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
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, TRUE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_TryEnterDoublesChallenge::
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	message BattleTower_Entrance_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleTower_Entrance_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTower_Entrance_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleTower_Entrance_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	msgbox BattleTower_Entrance_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge
	case YES, BattleTower_Entrance_EventScript_SaveBeforeDoublesChallenge
	case MULTI_B_PRESSED, BattleTower_Entrance_EventScript_LoadPartyCancelChallenge

BattleTower_Entrance_EventScript_SaveBeforeDoublesChallenge::
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
	goto_if_eq VAR_RESULT, 0, BattleTower_Entrance_EventScript_CancelChallengeSaveFailed
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, FALSE
	goto BattleTower_Entrance_EventScript_EnterElevator
	end

BattleTower_Entrance_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpen
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Singles
	case FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Doubles
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Singles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLv50Doubles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpen::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenSingles
	case FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenDoubles
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenSingles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_NotEnoughValidMonsLvOpenDoubles::
	msgbox BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_EndCancelChallenge
	end

BattleTower_Entrance_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS  @ No status provided, so it relies on VAR_0x8006 being 0 already
	goto BattleTower_Entrance_EventScript_CancelChallenge
	end

BattleTower_Entrance_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
BattleTower_Entrance_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleTower_Entrance_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
BattleTower_Entrance_EventScript_EndCancelChallenge::
	release
	end

BattleTower_Entrance_EventScript_EnterElevator::
	special SavePlayerParty
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleTower_Entrance_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	call BattleTower_Entrance_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 2, 5
	setvar VAR_TEMP_0, 0
	waitstate
	end

BattleTower_Entrance_EventScript_ShowYouToBattleRoom::
	call BattleTower_Entrance_EventScript_BufferModeText
	msgbox BattleTower_Entrance_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
	goto BattleTower_Entrance_EventScript_WalkToElevator

BattleTower_Entrance_EventScript_WalkToElevator::
	closemessage
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_WalkToPlayer
	waitmovement 2
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_WalkToElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Entrance_Movement_WalkToElevator
	waitmovement 0
	opendoor 13, 1
	waitdooranim
	applymovement LOCALID_TOWER_ATTENDANT, BattleTower_Entrance_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Entrance_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor 13, 1
	waitdooranim
	return

BattleTower_Entrance_Movement_WalkToPlayer:
	walk_up
	walk_right
	walk_right
	step_end

BattleTower_Entrance_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_Entrance_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTower_Entrance_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleTower_Entrance_EventScript_BufferModeText::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_BufferTextSingle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_BufferTextDouble
	return

BattleTower_Entrance_EventScript_BufferTextSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleTower_Entrance_EventScript_BufferTextDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleTower_Entrance_EventScript_GetPartySize::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleTower_Entrance_EventScript_GetSinglesPartySize
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleTower_Entrance_EventScript_GetDoublesPartySize
	return

BattleTower_Entrance_EventScript_GetSinglesPartySize::
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	return

BattleTower_Entrance_EventScript_GetDoublesPartySize::
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	return

BattleFrontier_EventScript_GetLvlMode::
	frontier_get FRONTIER_DATA_LVL_MODE
	return

BattleTower_Entrance_Text_HereAreSomeRibbons:
	.string "Here are some Ribbons for beating\n"
	.string "seven tough Trainers in a row.\p"
	.string "{PLAYER} received some Ribbons!$"

BattleTower_Entrance_Text_PutRibbonOnMons:
	.string "{PLAYER} put the Ribbons on\n"
	.string "the challenger Pokémon.$"

BattleTower_Entrance_Text_LookForwardToAnotherChallenge:
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleTower_Entrance_Text_OkayToSaveBeforeEntering:
	.string "Before entering a Battle Room, your\n"
	.string "progress must be saved. Is that okay?$"

BattleTower_Entrance_Text_ShowYouToBattleRoom:
	.string "I will now show you to the\n"
	.string "{STR_VAR_1} Battle Room.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLv50Singles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenSingles:
	.string "Excuse me!\p"
	.string "You don't have three eligible Pokémon.\p"
	.string "You must have three different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLv50Doubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Entrance_Text_NotEnoughValidMonsLvOpenDoubles:
	.string "Excuse me!\p"
	.string "You don't have four eligible Pokémon.\p"
	.string "You must have four different Pokémon\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "Also, Eggs are ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Entrance_Text_SelectThreeMons:
	.string "Now please select the three Pokémon\n"
	.string "that are to be entered.$"

BattleTower_Entrance_Text_PleaseSelectFourMons:
	.string "Now please select the four Pokémon\n"
	.string "that are to be entered.$"

BattleTower_Entrance_Text_PleaseSelectTwoMons:
	.string "Now please select the two Pokémon\n"
	.string "that are to be entered.$"

BattleTower_Entrance_Text_SaveGameBeforeShowingIn:
	.string "I will save the game before\n"
	.string "showing you in. Please wait.$"

BattleTower_Entrance_Text_AwardYouTheseBattlePoints:
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleFrontier_Text_ObtainedXBattlePoints:
	.string "{PLAYER} obtained {STR_VAR_1} Battle Point(s).$"

BattleTower_Entrance_Text_ReceivedPrize:
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleTower_Entrance_Text_ThankYouForPlaying:
	.string "Thank you for playing!\p"
	.string "$"

BattleTower_Entrance_Text_WeveBeenWaitingForYou:
	.string "We've been waiting for you!\p"
	.string "$"

BattleTower_Entrance_Text_ProgressWillBeSaved:
	.string "Before entering a Battle Room, your\n"
	.string "progress will be saved. Please wait.$"

BattleTower_Entrance_Text_AboutToFace50thTrainer:
	.string "You're finally about to face the\n"
	.string "50th Trainer.\p"
	.string "From here on, every time you beat seven\n"
	.string "Trainers in a row, your Pokémon will\l"
	.string "receive a commemorative Ribbon.\p"
	.string "Good luck!$"

BattleTower_Entrance_EventScript_Woman::
	msgbox BattleTower_Entrance_Text_WinsInRowRecorded, MSGBOX_NPC
	end

BattleTower_Entrance_Text_WinsInRowRecorded:
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in\n"
	.string "an embarrassing way!$"

BattleTower_Entrance_EventScript_Boy::
	msgbox BattleTower_Entrance_Text_CanLeaveUntilLossOrSevenWins, MSGBOX_NPC
	end

BattleTower_Entrance_Text_CanLeaveUntilLossOrSevenWins:
	.string "Once you've entered the Battle Tower,\n"
	.string "you can't leave until you either lose\l"
	.string "or you beat seven Trainers in a row.\p"
	.string "You'd best be certain that you're up\n"
	.string "to the challenge.$"

