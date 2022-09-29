CinnabarIsland_Lab_Lounge_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_Lounge_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_FoundFossilInMtMoon, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Lounge_Text_FoundFossilInMtMoon::
    .string "I found this most remarkable fossil\n"
    .string "inside Mt. Moon.\p"
    .string "I think it's of a rare, prehistoric\n"
    .string "Pokémon.$"

CinnabarIsland_PokemonLab_Lounge_EventScript_Clifton::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_ELECTRODE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_ELECTRODE, CinnabarIsland_PokemonLab_Lounge_EventScript_AlreadyTraded
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_Lounge_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_ELECTRODE
	release
	end

CinnabarIsland_PokemonLab_Lounge_Text_HeyThanks::
	.string "Hey, thanks!$"

CinnabarIsland_PokemonLab_Lounge_Text_LookingForMonWannaTradeForMon::
	.string "Hi!\n"
	.string "Do you have a {STR_VAR_1}?\p"
	.string "Want to trade it for my\n"
	.string "{STR_VAR_2}?$"

CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_DeclinedTrade
	release
	end

CinnabarIsland_PokemonLab_Lounge_Text_DeclinedTrade::
	.string "That's too bad.$"

CinnabarIsland_PokemonLab_Lounge_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_WhatThatsNotMon
	release
	end

CinnabarIsland_PokemonLab_Lounge_Text_WhatThatsNotMon::
	.string "What?\n"
	.string "That's no {STR_VAR_1}!$"

CinnabarIsland_PokemonLab_Lounge_EventScript_AlreadyTraded::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_IsntMyOldMonGreat
	release
	end

CinnabarIsland_PokemonLab_Lounge_Text_IsntMyOldMonGreat::
	.string "How is my old {STR_VAR_2}?\n"
	.string "My {STR_VAR_1} is doing great!$"

CinnabarIsland_PokemonLab_Lounge_EventScript_Norma::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_TANGELA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_TANGELA, CinnabarIsland_PokemonLab_Lounge_EventScript_AlreadyTraded2
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade2
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade2
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_Lounge_EventScript_NotRequestedMon2
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_TANGELA
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_DeclineTrade2::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_DeclinedTrade
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_NotRequestedMon2::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_WhatThatsNotMon
	release
	end

CinnabarIsland_PokemonLab_Lounge_EventScript_AlreadyTraded2::
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_IsntMyOldMonGreat
	release
	end
