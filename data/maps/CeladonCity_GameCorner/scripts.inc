.set LOCALID_ENGINEER, 1
.set LOCALID_ROCKET, 11

.set COINS_PRICE_50,  1000
.set COINS_PRICE_500, 10000

CeladonCity_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GameCorner_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, GameCorner_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, GameCorner_OnResume
	.byte 0

GameCorner_OnLoad::
	call_if_unset FLAG_OPENED_ROCKET_HIDEOUT, GameCorner_EventScript_HideRocketHideout
	end

GameCorner_EventScript_HideRocketHideout::
	setmetatile 15, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 17, 2, METATILE_GameCorner_Floor_ShadeFull, 0
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_Floor, 1
	return

GameCorner_OnTransition::
	call_if_unset FLAG_DAILY_COIN_REFRESH, GameCorner_RefreshCoins
	call_if_unset FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED, GameCorner_CheckServiceDay
	end

GameCorner_OnResume::
	call_if_unset FLAG_DAILY_COIN_REFRESH, GameCorner_RefreshCoins
	call_if_unset FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED, GameCorner_CheckServiceDay
	end

GameCorner_CheckServiceDay::
	clearflag FLAG_GAME_CORNER_SERVICE_DAY
	setflag FLAG_DAILY_GAME_CORNER_SERVICE_DAY_CHECKED
	random 10
	goto_if_lt VAR_RESULT, 9, Common_EventScript_Return
	setflag FLAG_GAME_CORNER_SERVICE_DAY
	clearflag FLAG_HIDE_GAME_CORNER_ENGINEER
	addobject LOCALID_ENGINEER
	return

GameCorner_EventScript_Engineer::
	msgbox GameCorner_Text_ServiceDay, MSGBOX_NPC
	release
	end

GameCorner_Text_ServiceDay::
	.string "I'm servicing the machines today!$"


GameCorner_RefreshCoins::
	setflag FLAG_DAILY_COIN_REFRESH
	random 12
	switch VAR_RESULT
	case 0 GameCorner_RefreshCoins_1
	case 1 GameCorner_RefreshCoins_2
	case 2 GameCorner_RefreshCoins_3
	case 3 GameCorner_RefreshCoins_4
	case 4 GameCorner_RefreshCoins_5
	case 5 GameCorner_RefreshCoins_6
	case 6 GameCorner_RefreshCoins_7
	case 7 GameCorner_RefreshCoins_8
	case 8 GameCorner_RefreshCoins_9
	case 9 GameCorner_RefreshCoins_10
	case 10 GameCorner_RefreshCoins_11
	case 11 GameCorner_RefreshCoins_12
	end

GameCorner_RefreshCoins_1::
	clearflag FLAG_FOUND_10_COINS_1
	end

GameCorner_RefreshCoins_2::
	clearflag FLAG_FOUND_10_COINS_2
	end

GameCorner_RefreshCoins_3::
	clearflag FLAG_FOUND_10_COINS_3
	end

GameCorner_RefreshCoins_4::
	clearflag FLAG_FOUND_10_COINS_4
	end

GameCorner_RefreshCoins_5::
	clearflag FLAG_FOUND_10_COINS_5
	end

GameCorner_RefreshCoins_6::
	clearflag FLAG_FOUND_10_COINS_6
	end

GameCorner_RefreshCoins_7::
	clearflag FLAG_FOUND_10_COINS_7
	end

GameCorner_RefreshCoins_8::
	clearflag FLAG_FOUND_10_COINS_8
	end

GameCorner_RefreshCoins_9::
	clearflag FLAG_FOUND_20_COINS_1
	end

GameCorner_RefreshCoins_10::
	clearflag FLAG_FOUND_20_COINS_2
	end

GameCorner_RefreshCoins_11::
	clearflag FLAG_FOUND_40_COINS
	end

GameCorner_RefreshCoins_12::
	clearflag FLAG_FOUND_100_COINS
	end

GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox GameCorner_Text_ThisIsGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NeedCoinCase
	message GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto GameCorner_EventScript_ChooseCoinsDefault50

GameCorner_Text_ThisIsGameCorner:
	.string "Welcome to the Game Corner.$"

GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for Coins?\p"
	.string "It's ¥1000 for 50 Coins.\n"
	.string "Would you like some?$"

GameCorner_EventScript_NeedCoinCase::
	msgbox GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some Coins for\n"
	.string "the games?\p"
	.string "Oh! You don't have a Coin Case for\n"
	.string "holding your Coins.$"

GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, GameCorner_EventScript_Buy50Coins
	case 1, GameCorner_EventScript_Buy500Coins
	goto GameCorner_EventScript_CancelBuyCoins
	end

GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_EventScript_NoRoomForCoins::
	msgbox GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your Coin Case is full.$"

GameCorner_EventScript_NotEnoughMoney::
	msgbox GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your Coins!$"

GameCorner_EventScript_CancelBuyCoins::
	msgbox GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need Coins, then?$"

GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine12::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 12
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine13::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 13
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine14::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 14
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine15::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 15
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine16::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 16
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_SlotMachine17::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 17
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

GameCorner_EventScript_NoCoinCase::
	msgbox GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a Coin Case.$"

GameCorner_EventScript_InfoClerk::
	msgbox GameCorner_Text_CanExchangeCoinsNextDoor, MSGBOX_NPC
	end

GameCorner_Text_CanExchangeCoinsNextDoor::
    .string "Welcome!\p"
    .string "You can exchange your Coins for\n"
    .string "fabulous prizes next door.$"

GameCorner_EventScript_UnusableSlotMachine1::
	msgbox GameCorner_Text_OutOfOrder, MSGBOX_SIGN
	end

GameCorner_Text_OutOfOrder::
    .string "OUT OF ORDER\n"
    .string "This is broken.$"

GameCorner_EventScript_UnusableSlotMachine2::
	msgbox GameCorner_Text_OutToLunch, MSGBOX_SIGN
	end

GameCorner_Text_OutToLunch::
    .string "Out To Lunch\n"
    .string "This is reserved.$"

GameCorner_EventScript_UnusableSlotMachine3::
	msgbox GameCorner_Text_SomeonesKeys, MSGBOX_SIGN
	end

GameCorner_Text_SomeonesKeys::
    .string "Someone's keys!\n"
    .string "They'll be back.$"

GameCorner_EventScript_UnusableSlotMachine4::
	goto_if_set FLAG_GAME_CORNER_SERVICE_DAY, GameCorner_EventScript_WorkedOn
	msgbox GameCorner_Text_Hacked, MSGBOX_SIGN
	end

GameCorner_Text_Hacked::
    .string "The Pokémon on this one are all\n"
    .string "scrambled. It was hacked!\p"
    .string "Better find a different one.$"

GameCorner_EventScript_WorkedOn::
	msgbox GameCorner_Text_Console, MSGBOX_SIGN
	end

GameCorner_Text_Console::
    .string "The Engineer has the terminal pulled\n"
    .string "up. Better not mess with it!$"

GameCorner_EventScript_FaceSlotMachine::
	closemessage
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

GameCorner_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox GameCorner_Text_RumoredTeamRocketRunsThisPlace
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_RumoredTeamRocketRunsThisPlace::
    .string "Keep this quiet.\p"
    .string "It's rumored that this place is run\n"
    .string "by Team Rocket.$"

GameCorner_EventScript_Woman1::
	lock
	faceplayer
	msgbox GameCorner_Text_ThinkMachinesHaveDifferentOdds
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_ThinkMachinesHaveDifferentOdds::
    .string "I think these machines have\n"
    .string "different odds.$"

GameCorner_EventScript_Woman2::
	lock
	faceplayer
	msgbox GameCorner_Text_WinOrLoseItsOnlyLuck
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WinOrLoseItsOnlyLuck::
    .string "These slot games…\n"
    .string "Win or lose, it's only by luck.$"

GameCorner_EventScript_Maniac::
	msgbox GameCorner_Text_RareMonsForCoins
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_RareMonsForCoins::
    .string "They offer rare Pokémon that can\n"
    .string "be exchanged for your Coins.\p"
    .string "But, I just can't seem to win!$"

GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox GameCorner_Text_SoEasyToGetHooked
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_SoEasyToGetHooked::
    .string "Games are scary!\n"
    .string "It's so easy to get hooked!$"

GameCorner_EventScript_Fisher::
	lock
	faceplayer
	goto_if_set FLAG_GOT_10_COINS_FROM_GAMBLER, GameCorner_EventScript_FisherAlreadyGotCoins
	msgbox GameCorner_Text_DoYouWantToPlay
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 10
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 10
	msgbox GameCorner_Text_Received10CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_10_COINS_FROM_GAMBLER
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DoYouWantToPlay::
    .string "Kid, do you want to play?$"

GameCorner_Text_Received10CoinsFromMan::
    .string "{PLAYER} received 10 COINS\n"
    .string "from the man.$"

GameCorner_EventScript_FisherAlreadyGotCoins::
	msgbox GameCorner_Text_WinsComeAndGo
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WinsComeAndGo::
    .string "Wins seem to come and go.\n"
    .string "Nothing's a sure thing.$"

GameCorner_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER, GameCorner_EventScript_ScientistAlreadyGotCoins
	msgbox GameCorner_Text_WantSomeCoins
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 20
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 20
	msgbox GameCorner_Text_Received20CoinsFromNiceGuy
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WantSomeCoins::
    .string "What's up?\n"
    .string "Want some coins?$"

GameCorner_Text_Received20CoinsFromNiceGuy::
    .string "{PLAYER} received 20 coins\n"
    .string "from the nice guy.$"

GameCorner_EventScript_ScientistAlreadyGotCoins::
	msgbox GameCorner_Text_NeedMoreCoinsForMonIWant
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_NeedMoreCoinsForMonIWant::
    .string "Darn! I need more coins for the\n"
    .string "Pokémon Plush I want!$"

GameCorner_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_20_COINS_FROM_GAMBLER_2, GameCorner_EventScript_GentlemanAlreadyGotCoins
	msgbox GameCorner_Text_HereAreSomeCoinsShoo, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, GameCorner_EventScript_GamblerNoCoinCase
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, (MAX_COINS + 1) - 20
	goto_if_ge GameCorner_EventScript_GamblerNoRoomForCoins
	addcoins 20
	msgbox GameCorner_Text_Received20CoinsFromMan
	playse SE_SHOP
	waitse
	setflag FLAG_GOT_20_COINS_FROM_GAMBLER_2
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_HereAreSomeCoinsShoo::
    .string "Hey, what? You're throwing me off!\n"
    .string "Here are some coins, so shoo!$"

GameCorner_Text_Received20CoinsFromMan::
    .string "{PLAYER} received 20 coins\n"
    .string "from the man.$"

GameCorner_EventScript_GentlemanAlreadyGotCoins::
	msgbox GameCorner_Text_WatchReelsClosely
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_WatchReelsClosely::
    .string "The trick is to watch the reels\n"
    .string "closely.$"

GameCorner_EventScript_GamblerNoRoomForCoins::
	msgbox GameCorner_Text_DontNeedMyCoins
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DontNeedMyCoins::
    .string "Hmm, you have plenty of coins.$"

GameCorner_EventScript_GamblerNoCoinCase::
	msgbox GameCorner_Text_DontHaveCoinCase
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_DontHaveCoinCase::
    .string "Hey! Go grab your Coin Case\n"
    .string "so you can hold these!$"


GameCorner_EventScript_Poster::
	lockall
	goto_if_unset FLAG_OPENED_ROCKET_HIDEOUT, GameCorner_EventScript_PosterButton
	releaseall
	end

GameCorner_EventScript_PosterButton::
	msgbox GameCorner_Text_SwitchBehindPosterPushIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GameCorner_EventScript_OpenRocketHideout
	msgbox GameCorner_Text_LeaveItAlone
	release
	end

GameCorner_Text_SwitchBehindPosterPushIt::
    .string "Hey!\p"
    .string "A switch behind the poster!?\n"
    .string "Let's push it!$"

GameCorner_Text_LeaveItAlone::
    .string "On second thought, better leave it\pn"
    .string "alone...$"

GameCorner_EventScript_OpenRocketHideout::
	playse SE_UNLOCK
	setmetatile 15, 2, METATILE_GameCorner_Floor_StairsTop, 0
	setmetatile 16, 2, METATILE_GameCorner_StairsTop, 1
	setmetatile 17, 2, METATILE_GameCorner_StairsBottom, 1
	setmetatile 16, 3, METATILE_GameCorner_PurpleWall_StairsTop, 1
	setmetatile 17, 3, METATILE_GameCorner_PurpleWall_stairsBottom, 1
	special DrawWholeMapView
	setflag FLAG_OPENED_ROCKET_HIDEOUT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_EAST
	goto GameCorner_EventScript_RocketAppears
	end

GameCorner_EventScript_RocketAppears::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	clearflag FLAG_HIDE_GAME_CORNER_ROCKET
	addobject LOCALID_ROCKET
	playse SE_DOOR
	waitse
	playse SE_PIN
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitmovement 11
	waitse
	applymovement LOCALID_ROCKET, Movement_GCRocketAppears
	waitmovement 11
	goto GameCorner_EventScript_RocketBattle

Movement_GCRocketAppears:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GameCorner_EventScript_RocketBattle::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_7, GameCorner_Text_GruntIntro, GameCorner_Text_GruntDefeat, GameCorner_EventScript_DefeatedGrunt
	end

GameCorner_Text_GruntIntro::
    .string "Hey! What gives!?\n"
    .string "You're not supposed to press that!\p"
    .string "Go away, or else!$"

GameCorner_Text_GruntDefeat::
    .string "Dang!$"

GameCorner_EventScript_DefeatedGrunt::
	msgbox GameCorner_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	applymovement LOCALID_ROCKET, Movement_GCGruntExit
	waitmovement 11
	playse SE_EXIT
	removeobject LOCALID_ROCKET
	release
	end

GameCorner_Text_GruntPostBattle::
    .string "The Team Rocket Hideout might\n"
    .string "be discovered!\p"
    .string "I better tell Boss!$"

Movement_GCGruntExit::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HiddenCoins_1::
	goto_if_set FLAG_FOUND_10_COINS_1, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_1
	waitfanfare
	release
	end

HiddenCoins_2::
	goto_if_set FLAG_FOUND_10_COINS_2, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_2
	waitfanfare
	release
	end

HiddenCoins_3::
	goto_if_set FLAG_FOUND_20_COINS_1, Common_EventScript_End
	call HiddenCoins_Get20Coins
	setflag FLAG_FOUND_20_COINS_1
	waitfanfare
	release
	end

HiddenCoins_4::
	goto_if_set FLAG_FOUND_10_COINS_3, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_3
	waitfanfare
	release
	end

HiddenCoins_5::
	goto_if_set FLAG_FOUND_10_COINS_4, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_4
	waitfanfare
	release
	end

HiddenCoins_6::
	goto_if_set FLAG_FOUND_20_COINS_2, Common_EventScript_End
	call HiddenCoins_Get20Coins
	setflag FLAG_FOUND_20_COINS_2
	waitfanfare
	release
	end

HiddenCoins_7::
	goto_if_set FLAG_FOUND_10_COINS_5, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_5
	waitfanfare
	release
	end

HiddenCoins_8::
	goto_if_set FLAG_FOUND_10_COINS_6, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_6
	waitfanfare
	release
	end

HiddenCoins_9::
	goto_if_set FLAG_FOUND_10_COINS_7, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_7
	waitfanfare
	release
	end

HiddenCoins_10::
	goto_if_set FLAG_FOUND_40_COINS, Common_EventScript_End
	call HiddenCoins_Get40Coins
	setflag FLAG_FOUND_40_COINS
	waitfanfare
	release
	end

HiddenCoins_11::
	goto_if_set FLAG_FOUND_10_COINS_7, Common_EventScript_End
	call HiddenCoins_Get10Coins
	setflag FLAG_FOUND_10_COINS_7
	waitfanfare
	release
	end

HiddenCoins_12::
	goto_if_set FLAG_FOUND_100_COINS, Common_EventScript_End
	call HiddenCoins_Get100Coins
	setflag FLAG_FOUND_100_COINS
	waitfanfare
	release
	end

HiddenCoins_Get10Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 10), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found10Coins, MSGBOX_AUTOCLOSE
	addcoins 10
	return

HiddenCoins_Get20Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 20), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found20Coins, MSGBOX_AUTOCLOSE
	addcoins 20
	return

HiddenCoins_Get40Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 40), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found40Coins, MSGBOX_AUTOCLOSE
	addcoins 40
	return

HiddenCoins_Get100Coins::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, HiddenCoins_NoCase
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 100), HiddenCoins_NoSpace
	playfanfare MUS_OBTAIN_ITEM
	msgbox HiddenCoins_Found100Coins, MSGBOX_AUTOCLOSE
	addcoins 100
	return

HiddenCoins_NoSpace::
	msgbox HiddenCoins_FoundCoinsNoSpace, MSGBOX_AUTOCLOSE
	release
	end

HiddenCoins_FoundCoinsNoSpace::
	.string "{PLAYER} found some coins scattered\n"
	.string "on the floor...\p"
	.string "Too bad your Coin Case is full!$"

HiddenCoins_NoCase::
	msgbox HiddenCoins_FoundCoinsNoCase, MSGBOX_AUTOCLOSE
	release
	end

HiddenCoins_FoundCoinsNoCase::
	.string "{PLAYER} found some coins scattered\n"
	.string "on the floor...\p"
	.string "Too bad you don't have a Coin Case!$"

HiddenCoins_Found10Coins::
	.string "{PLAYER} found 10 coins scattered\n"
	.string "on the floor!$"

HiddenCoins_Found20Coins::
	.string "{PLAYER} found 20 coins scattered\n"
	.string "on the floor!$"

HiddenCoins_Found40Coins::
	.string "{PLAYER} found 40 coins scattered\n"
	.string "on the floor!$"

HiddenCoins_Found100Coins::
	.string "{PLAYER} found 100 coins scattered\n"
	.string "on the floor!$"

GameCorner_EventScript_Scott::
	lock
	faceplayer
	msgbox GameCorner_Text_GymGuide
	goto GameCorner_EventScript_FaceSlotMachine
	end

GameCorner_Text_GymGuide::
	.string "Hey! You have better things to do,\n" 
	.string "champ in making!\p" 
	.string "Celadon Gym's Leader is Erika!\n"
	.string "She uses grass-type Pokémon!\p" 
	.string "She might appear docile, but don't\n" 
	.string "be fooled!$"
