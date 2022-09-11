CeruleanCity_House3_MapScripts::
	.byte 0

CeruleanCity_House3_EventScript_OldWoman::
	msgbox CeruleanCity_House3_Text_PleaseTradeWithMyHusband, MSGBOX_NPC
	end

CeruleanCity_House3_Text_PleaseTradeWithMyHusband::
    .string "My husband likes trading Pokémon.\p"
    .string "You're collecting Pokémon for your\n"
    .string "Pokédex, aren't you?\p"
    .string "Would you please trade with him?$"

CeruleanCity_House3_EventScript_Dontae::
	lock
	faceplayer
	goto_if_set FLAG_IN_GAME_TRADE_JYNX, CeruleanCity_House3_EventScript_AlreadyTraded
	setvar VAR_0x8008, INGAME_TRADE_JYNX
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox CeruleanCity_House3_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CeruleanCity_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CeruleanCity_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox CeruleanCity_House3_Text_ThanksForTrading, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_JYNX
	release
	end

CeruleanCity_House3_Text_ThanksForTrading::
	.string "Thanks!$"

CeruleanCity_House3_Text_LookingForMonWannaTradeForMon::
	.string "Hello, there! Do you happen to\n"
	.string "have a {STR_VAR_1}?\p"
	.string "Would you agree to a trade for\n"
	.string "my {STR_VAR_2}?$"

CeruleanCity_House3_EventScript_DeclineTrade::
	msgbox CeruleanCity_House3_Text_DeclinedTrade
	release
	end

CeruleanCity_House3_Text_DeclinedTrade::
	.string "Well, if you don't want to…$"

CeruleanCity_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox CeruleanCity_House3_Text_WhatThatsNoMon
	release
	end

CeruleanCity_House3_Text_WhatThatsNoMon::
	.string "Hmmm?\n"
	.string "This isn't a {STR_VAR_1}.\p"
	.string "Think of me if you get one.$"

CeruleanCity_House3_EventScript_AlreadyTraded::
	msgbox CeruleanCity_House3_Text_IsntMyOldMonGreat
	release
	end

CeruleanCity_House3_Text_IsntMyOldMonGreat::
	.string "The {STR_VAR_2} that I traded you,\n"
	.string "has it grown stronger?$"

