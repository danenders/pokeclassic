    @ Game Corner prices
    .set CHEAP_CUSHION_COINS, 		150
    .set CUSHION_COINS, 			250
    .set PREMIUM_CUSHION_COINS, 	350
    .set DOLL_COINS,  				500
    .set PREMIUM_DOLL_COINS,  		750
	.set BIG_DOLL_COINS,  			1500
	.set PREMIUM_BIG_DOLL_COINS,  	3000

CeladonCity_GameCornerPrizeRoom_MapScripts::
	.byte 0

CeladonCity_GameCorner_PrizeRoom_EventScript_BaldingMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_Text_FancyThatPorygon::
    .string "I sure do fancy those big plushies!\n"
    .string "But, it's hard to win at slots!$"

CeladonCity_GameCorner_PrizeRoom_EventScript_OldMan::
	msgbox CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday, MSGBOX_NPC
	end

CeladonCity_GameCorner_PrizeRoom_Text_RakedItInToday::
    .string "Gahaha! I raked it in today!\n"
    .string "If only every day were like this…$"


CeladonCity_GameCorner_EventScript_PrizeCornerBigDolls::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_EventScript_ChooseBigDollPrizeMessage
	release
	end

CeladonCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your Coins for\n"
	.string "prizes here.$"

CeladonCity_GameCorner_EventScript_ChooseBigDollPrizeMessage::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto CeladonCity_GameCorner_EventScript_ChooseBigDollPrize

CeladonCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

CeladonCity_GameCorner_EventScript_ChooseBigDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_BIG_DOLLS, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_EventScript_LaprasDoll
	case 1, CeladonCity_GameCorner_EventScript_SnorlaxDoll
	case 2, CeladonCity_GameCorner_EventScript_RhydonDoll
	case 3, CeladonCity_GameCorner_EventScript_VenusaurDoll
	case 4, CeladonCity_GameCorner_EventScript_CharizardDoll
	case 5, CeladonCity_GameCorner_EventScript_BlastoiseDoll
	goto CeladonCity_GameCorner_EventScript_CancelBigDollSelect
	end

CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	goto CeladonCity_GameCorner_EventScript_ChooseBigDollPrize

CeladonCity_GameCorner_EventScript_LaprasDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_LAPRAS_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuyLaprasDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_LAPRAS_DOLL
	checkdecorspace DECOR_LAPRAS_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins BIG_DOLL_COINS
	adddecoration DECOR_LAPRAS_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_SnorlaxDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_SNORLAX_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuySnorlaxDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_SNORLAX_DOLL
	checkdecorspace DECOR_SNORLAX_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins BIG_DOLL_COINS
	adddecoration DECOR_SNORLAX_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_RhydonDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_RHYDON_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuyRhydonDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_RHYDON_DOLL
	checkdecorspace DECOR_RHYDON_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins BIG_DOLL_COINS
	adddecoration DECOR_RHYDON_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_VenusaurDoll::
	setvar VAR_TEMP_1, 4
	bufferdecorationname STR_VAR_1, DECOR_VENUSAUR_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuyVenusaurDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_VENUSAUR_DOLL
	checkdecorspace DECOR_VENUSAUR_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins PREMIUM_BIG_DOLL_COINS
	adddecoration DECOR_VENUSAUR_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_CharizardDoll::
	setvar VAR_TEMP_1, 5
	bufferdecorationname STR_VAR_1, DECOR_CHARIZARD_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuyCharizardDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_CHARIZARD_DOLL
	checkdecorspace DECOR_CHARIZARD_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins PREMIUM_BIG_DOLL_COINS
	adddecoration DECOR_CHARIZARD_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_BlastoiseDoll::
	setvar VAR_TEMP_1, 6
	bufferdecorationname STR_VAR_1, DECOR_BLASTOISE_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize

CeladonCity_GameCorner_EventScript_BuyBlastoiseDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_BIG_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll
	bufferdecorationname STR_VAR_2, DECOR_BLASTOISE_DOLL
	checkdecorspace DECOR_BLASTOISE_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForBigDoll
	removecoins PREMIUM_BIG_DOLL_COINS
	adddecoration DECOR_BLASTOISE_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_ConfirmBigDollPrize::
	msgbox CeladonCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_CancelBigDollSelect
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_EventScript_BuyLaprasDoll
	case 2, CeladonCity_GameCorner_EventScript_BuySnorlaxDoll
	case 3, CeladonCity_GameCorner_EventScript_BuyRhydonDoll
	case 4, CeladonCity_GameCorner_EventScript_BuyVenusaurDoll
	case 5, CeladonCity_GameCorner_EventScript_BuyCharizardDoll
	case 6, CeladonCity_GameCorner_EventScript_BuyBlastoiseDoll
	end


CeladonCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

CeladonCity_GameCorner_EventScript_NotEnoughCoinsForBigDoll::
	msgbox CeladonCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_NoRoomForBigDoll::
	call Common_EventScript_NoRoomForDecor
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseBigDollPrize
	end

CeladonCity_GameCorner_EventScript_CancelBigDollSelect::
	msgbox CeladonCity_GameCorner_Text_SeeYouAgain, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

CeladonCity_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

CeladonCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough coins.$"

CeladonCity_GameCorner_Text_SeeYouAgain:
	.string "See you again!$"

CeladonCity_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

CeladonCity_GameCorner_EventScript_ChooseDollPrizeMessage::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto CeladonCity_GameCorner_EventScript_ChooseDollPrize

CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	goto CeladonCity_GameCorner_EventScript_ChooseDollPrize


CeladonCity_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_EventScript_MeowthDoll
	case 1, CeladonCity_GameCorner_EventScript_ClefairyDoll
	case 2, CeladonCity_GameCorner_EventScript_JigglypuffDoll
	case 3, CeladonCity_GameCorner_EventScript_DittoDoll
	case 4, CeladonCity_GameCorner_EventScript_PikachuDoll
	goto CeladonCity_GameCorner_EventScript_CancelDollSelect
	end

CeladonCity_GameCorner_EventScript_MeowthDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_MEOWTH_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmDollPrize

CeladonCity_GameCorner_EventScript_BuyMeowthDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MEOWTH_DOLL
	checkdecorspace DECOR_MEOWTH_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MEOWTH_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

CeladonCity_GameCorner_EventScript_ClefairyDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_CLEFAIRY_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmDollPrize

CeladonCity_GameCorner_EventScript_BuyClefairyDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_CLEFAIRY_DOLL
	checkdecorspace DECOR_CLEFAIRY_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_CLEFAIRY_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

CeladonCity_GameCorner_EventScript_JigglypuffDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_JIGGLYPUFF_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmDollPrize

CeladonCity_GameCorner_EventScript_BuyJigglypuffDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_JIGGLYPUFF_DOLL
	checkdecorspace DECOR_JIGGLYPUFF_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_JIGGLYPUFF_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end


CeladonCity_GameCorner_EventScript_DittoDoll::
	setvar VAR_TEMP_1, 4
	bufferdecorationname STR_VAR_1, DECOR_DITTO_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmDollPrize

CeladonCity_GameCorner_EventScript_BuyDittoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_DITTO_DOLL
	checkdecorspace DECOR_DITTO_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForDoll
	removecoins PREMIUM_DOLL_COINS
	adddecoration DECOR_DITTO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

CeladonCity_GameCorner_EventScript_PikachuDoll::
	setvar VAR_TEMP_1, 5
	bufferdecorationname STR_VAR_1, DECOR_PIKACHU_DOLL
	goto CeladonCity_GameCorner_EventScript_ConfirmDollPrize

CeladonCity_GameCorner_EventScript_BuyPikachuDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_DOLL_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_PIKACHU_DOLL
	checkdecorspace DECOR_PIKACHU_DOLL
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForDoll
	removecoins PREMIUM_DOLL_COINS
	adddecoration DECOR_PIKACHU_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end


CeladonCity_GameCorner_EventScript_ConfirmDollPrize::
	msgbox CeladonCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_EventScript_BuyMeowthDoll
	case 2, CeladonCity_GameCorner_EventScript_BuyClefairyDoll
	case 3, CeladonCity_GameCorner_EventScript_BuyJigglypuffDoll
	case 4, CeladonCity_GameCorner_EventScript_BuyDittoDoll
	case 5, CeladonCity_GameCorner_EventScript_BuyPikachuDoll
	end

CeladonCity_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox CeladonCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

CeladonCity_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseDollPrize
	end

CeladonCity_GameCorner_EventScript_CancelDollSelect::
	msgbox CeladonCity_GameCorner_Text_SeeYouAgain, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end


CeladonCity_GameCorner_EventScript_PrizeCornerCushions::
	lock
	faceplayer
	msgbox CeladonCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_GameCorner_EventScript_ChooseCushionPrizeMessage
	release
	end

CeladonCity_GameCorner_EventScript_ChooseCushionPrizeMessage::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto CeladonCity_GameCorner_EventScript_ChooseCushionPrize

CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize::
	message CeladonCity_GameCorner_Text_WhichPrize
	waitmessage
	goto CeladonCity_GameCorner_EventScript_ChooseCushionPrize

CeladonCity_GameCorner_EventScript_ChooseCushionPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_CUSHIONS, FALSE
	switch VAR_RESULT
	case 0, CeladonCity_GameCorner_EventScript_BallCushion
	case 1, CeladonCity_GameCorner_EventScript_GrassCushion
	case 2, CeladonCity_GameCorner_EventScript_FireCushion
	case 3, CeladonCity_GameCorner_EventScript_WaterCushion
	case 4, CeladonCity_GameCorner_EventScript_PikaCushion
	goto CeladonCity_GameCorner_EventScript_CancelCushionSelect
	end

CeladonCity_GameCorner_EventScript_BallCushion::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_BALL_CUSHION
	goto CeladonCity_GameCorner_EventScript_ConfirmCushionPrize

CeladonCity_GameCorner_EventScript_BuyBallCushion::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CHEAP_CUSHION_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion
	bufferdecorationname STR_VAR_2, DECOR_BALL_CUSHION
	checkdecorspace DECOR_BALL_CUSHION
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForCushion
	removecoins CHEAP_CUSHION_COINS
	adddecoration DECOR_BALL_CUSHION
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_GrassCushion::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_GRASS_CUSHION
	goto CeladonCity_GameCorner_EventScript_ConfirmCushionPrize

CeladonCity_GameCorner_EventScript_BuyGrassCushion::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CUSHION_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion
	bufferdecorationname STR_VAR_2, DECOR_GRASS_CUSHION
	checkdecorspace DECOR_GRASS_CUSHION
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForCushion
	removecoins CUSHION_COINS
	adddecoration DECOR_GRASS_CUSHION
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_FireCushion::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_FIRE_CUSHION
	goto CeladonCity_GameCorner_EventScript_ConfirmCushionPrize

CeladonCity_GameCorner_EventScript_BuyFireCushion::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CUSHION_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion
	bufferdecorationname STR_VAR_2, DECOR_FIRE_CUSHION
	checkdecorspace DECOR_FIRE_CUSHION
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForCushion
	removecoins CUSHION_COINS
	adddecoration DECOR_FIRE_CUSHION
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_WaterCushion::
	setvar VAR_TEMP_1, 4
	bufferdecorationname STR_VAR_1, DECOR_WATER_CUSHION
	goto CeladonCity_GameCorner_EventScript_ConfirmCushionPrize

CeladonCity_GameCorner_EventScript_BuyWaterCushion::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CUSHION_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion
	bufferdecorationname STR_VAR_2, DECOR_WATER_CUSHION
	checkdecorspace DECOR_WATER_CUSHION
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForCushion
	removecoins CUSHION_COINS
	adddecoration DECOR_WATER_CUSHION
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_PikaCushion::
	setvar VAR_TEMP_1, 5
	bufferdecorationname STR_VAR_1, DECOR_PIKA_CUSHION
	goto CeladonCity_GameCorner_EventScript_ConfirmCushionPrize

CeladonCity_GameCorner_EventScript_BuyPikaCushion::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PREMIUM_CUSHION_COINS, CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion
	bufferdecorationname STR_VAR_2, DECOR_PIKA_CUSHION
	checkdecorspace DECOR_PIKA_CUSHION
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_GameCorner_EventScript_NoRoomForCushion
	removecoins PREMIUM_CUSHION_COINS
	adddecoration DECOR_PIKA_CUSHION
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox CeladonCity_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_ConfirmCushionPrize::
	msgbox CeladonCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeladonCity_GameCorner_EventScript_CancelCushionSelect
	switch VAR_TEMP_1
	case 1, CeladonCity_GameCorner_EventScript_BuyBallCushion
	case 2, CeladonCity_GameCorner_EventScript_BuyGrassCushion
	case 3, CeladonCity_GameCorner_EventScript_BuyFireCushion
	case 4, CeladonCity_GameCorner_EventScript_BuyWaterCushion
	case 5, CeladonCity_GameCorner_EventScript_BuyPikaCushion
	end

CeladonCity_GameCorner_EventScript_NotEnoughCoinsForCushion::
	msgbox CeladonCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_NoRoomForCushion::
	call Common_EventScript_NoRoomForDecor
	goto CeladonCity_GameCorner_EventScript_ReturnToChooseCushionPrize
	end

CeladonCity_GameCorner_EventScript_CancelCushionSelect::
	msgbox CeladonCity_GameCorner_Text_SeeYouAgain, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end
