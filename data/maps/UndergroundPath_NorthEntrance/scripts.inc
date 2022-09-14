UndergroundPath_NorthEntrance_MapScripts::
	.byte 0

UndergroundPath_NorthEntrance_EventScript_Saige::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORAN
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_NIDORAN, UndergroundPath_NorthEntrance_EventScript_AlreadyTraded
	msgbox UndergroundPath_NorthEntrance_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, UndergroundPath_NorthEntrance_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UndergroundPath_NorthEntrance_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, UndergroundPath_NorthEntrance_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox UndergroundPath_NorthEntrance_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_NIDORAN
	release
	end

UndergroundPath_NorthEntrance_Text_HeyThanks::
	.string "Hey, thanks!$"

UndergroundPath_NorthEntrance_Text_LookingForMonWannaTradeForMon::
	.string "Hi!\n"
	.string "Do you have a {STR_VAR_1}?\p"
	.string "Want to trade it for my\n"
	.string "{STR_VAR_2}?$"

UndergroundPath_NorthEntrance_EventScript_DeclineTrade::
	msgbox UndergroundPath_NorthEntrance_Text_DeclinedTrade
	release
	end

UndergroundPath_NorthEntrance_Text_DeclinedTrade::
	.string "That's too bad.$"

UndergroundPath_NorthEntrance_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox UndergroundPath_NorthEntrance_Text_WhatThatsNotMon
	release
	end

UndergroundPath_NorthEntrance_Text_WhatThatsNotMon::
	.string "What?\n"
	.string "That's no {STR_VAR_1}!$"

UndergroundPath_NorthEntrance_EventScript_AlreadyTraded::
	msgbox UndergroundPath_NorthEntrance_Text_IsntMyOldMonGreat
	release
	end

UndergroundPath_NorthEntrance_Text_IsntMyOldMonGreat::
	.string "How is my old {STR_VAR_2}?\n"
	.string "My {STR_VAR_1} is doing great!$"

