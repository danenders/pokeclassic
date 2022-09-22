FuchsiaCity_SafariZone_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_SafariZone_Entrance_OnFrame
	.byte 0

FuchsiaCity_SafariZone_Entrance_OnFrame:
	map_script_2 VAR_SAFARI_ZONE_STATE, 1, FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone
	.2byte 0

FuchsiaCity_SafariZone_Entrance_EventScript_ExitSafariZone::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone
	waitmovement 0
	setvar VAR_SAFARI_ZONE_STATE, 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_ExitSafariZone:
	walk_down
	walk_down
	walk_down
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_WelcomeAttendant::
	lock
	faceplayer
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZone_Entrance_EventScript_InfoAttendant::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_TrainerTip, MSGBOX_SIGN
	end

FuchsiaCity_SafariZone_Entrance_Text_TrainerTip:
	.string "Here's a tip!\p"
	.string "Throw {POKEBLOCK}s at wild Pokémon to make\n"
	.string "them less likely to flee.$"

FuchsiaCity_SafariZone_Entrance_Text_WelcomeFirstTime:
	.string "Welcome to the Safari Zone!\n"
	.string "Is it your first time here?$"

FuchsiaCity_SafariZone_Entrance_Text_ComeInAndEnjoy:
	.string "Come in and enjoy the Safari Zone!$"

FuchsiaCity_SafariZone_Entrance_EventScript_FirstTimeInfo::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_SafariZone_Entrance_Text_FirstTimeInfo:
	.string "When you enter the Safari Zone, you\n"
	.string "start with 30 Safari Balls for\l"
	.string "catching Pokémon.\p"
	.string "The Safari Game is over when you run\n"
	.string "out of Safari Balls, or when you've\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the Safari Zone!$"

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterLeft
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter
	end

Movement_ApproachCounterLeft::
	walk_right
	walk_right
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounterTriggerMid::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterMid
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter
	end

Movement_ApproachCounterMid::
	walk_right
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_EntranceCounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmoneybox 0, 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_WouldYouLikeToPlay:
	.string "Welcome to the Safari Zone!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a Safari Game?$"

FuchsiaCity_SafariZone_Entrance_Text_PlayAnotherTime:
	.string "Okay.\n"
	.string "Please play another time!$"

FuchsiaCity_SafariZone_Entrance_EventScript_TryEnterSafariZone::
	call FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon
	checkmoney 500
	goto_if_eq VAR_RESULT, 0, FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney
	playse SE_SHOP
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please, MSGBOX_DEFAULT
	removemoney 500
	updatemoneybox
	msgbox FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls
	waitfanfare
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone
	waitmovement 0
	special EnterSafariMode
	setvar VAR_SAFARI_ZONE_STATE, 2
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Text_ThatWillBe500Please:
	.string "That will be ¥500, please.$"

FuchsiaCity_SafariZone_Entrance_Text_HereAreYourSafariBalls:
	.string "Here are your Safari Balls.$"

FuchsiaCity_SafariZone_Entrance_Text_Received30SafariBalls:
    .string "{PLAYER} received 30 Safari Balls\n"
    .string "from the attendant.$"

FuchsiaCity_SafariZone_Entrance_Text_PleaseEnjoyYourself:
    .string "We'll call you on the PA when you\n"
    .string "run out of time or Safari Balls.\p"
    .string "Well, I'll wish you the best of\n"
    .string "luck!$"

FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone:
	walk_left
	walk_up
	walk_up
	delay_16
	step_end

FuchsiaCity_SafariZone_Entrance_EventScript_CheckHasRoomForPokemon::
	getpartysize
	goto_if_ne VAR_RESULT, PARTY_SIZE, Common_EventScript_Return
	specialvar VAR_RESULT, ScriptCheckFreePokemonStorageSpace
	goto_if_eq VAR_RESULT, 1, Common_EventScript_Return
	msgbox FuchsiaCity_SafariZone_Entrance_Text_PCIsFull, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_PCIsFull:
	.string "Excuse me!\n"
	.string "Your PC Box is full.$"

FuchsiaCity_SafariZone_Entrance_EventScript_NotEnoughMoney::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_NotEnoughMoney:
	.string "You don't have enough money.\n"
	.string "Sorry.$"

FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter::
	closemessage
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_BackAwayFromCounter
	waitmovement 0
	releaseall
	end

FuchsiaCity_SafariZone_Entrance_Movement_BackAwayFromCounter:
	walk_down
	step_end



FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounterTriggerLeft::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterLeft
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounterTriggerMid::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachCounterMid
	waitmovement 0
	goto FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter
	end

FuchsiaCity_SafariZone_Entrance_EventScript_ExitCounter::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox FuchsiaCity_SafariZone_Entrance_Text_StillHaveTimeExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_SafariZone_Entrance_EventScript_Exit
	msgbox FuchsiaCity_SafariZone_Entrance_Text_EnjoyTheRestOfYourAdventure, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_SafariZone_Entrance_Movement_EnterSafariZone
	waitmovement 0
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
	waitstate
	end

FuchsiaCity_SafariZone_Entrance_Text_EnjoyTheRestOfYourAdventure:
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"

FuchsiaCity_SafariZone_Entrance_Text_StillHaveTimeExit:
    .string "Are you going to leave the\n"
    .string "Safari Zone early?$"

FuchsiaCity_SafariZone_Entrance_EventScript_Exit::
	msgbox FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThankYouForPlaying, MSGBOX_DEFAULT
	setvar VAR_SAFARI_ZONE_STATE, 0
	special ExitSafariMode
	goto FuchsiaCity_SafariZone_Entrance_EventScript_MovePlayerBackFromCounter
	end

FuchsiaCity_SafariZone_Entrance_Text_ExitEarlyThankYouForPlaying:
    .string "Please return any Safari Balls\n"
    .string "you may have left.$"
