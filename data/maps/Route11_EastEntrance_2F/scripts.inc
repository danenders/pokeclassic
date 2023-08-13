Route11_EastEntrance_2F_MapScripts::
	.byte 0

Route11_EastEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_WOKE_UP_ROUTE_12_SNORLAX, Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone
	msgbox Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad
	releaseall
	end

Route11_EastEntrance_2F_Text_BigMonAsleepOnRoad::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "A big Pokémon is asleep on a road!$"

Route11_EastEntrance_2F_EventScript_LeftBinocularsSnorlaxGone::
	msgbox Route11_EastEntrance_2F_Text_WhatABreathtakingView
	releaseall
	end

Route11_EastEntrance_2F_Text_WhatABreathtakingView::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "What a breathtaking view!$"

Route11_EastEntrance_2F_EventScript_RightBinoculars::
	msgbox Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender, MSGBOX_SIGN
	end

Route11_EastEntrance_2F_Text_RockTunnelGoodRouteToLavender::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "To get to Lavender Town from\n"
    .string "Cerulean City…\p"
    .string "Rock Tunnel appears to be a good\n"
    .string "route to take.$"

Route11_EastEntrance_2F_EventScript_Turner::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_NIDORINA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_NIDORINA, Route11_EastEntrance_2F_EventScript_AlreadyTraded
	msgbox Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route11_EastEntrance_2F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route11_EastEntrance_2F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, Route11_EastEntrance_2F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox Route11_EastEntrance_2F_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_NIDORINA
	release
	end

Route11_EastEntrance_2F_Text_HeyThanks::
	.string "Hey, thanks!$"

Route11_EastEntrance_2F_Text_LookingForMonWannaTradeForMon::
	.string "Hi!\n"
	.string "Do you have a {STR_VAR_1}?\p"
	.string "Want to trade it for my\n"
	.string "{STR_VAR_2}?$"

Route11_EastEntrance_2F_EventScript_DeclineTrade::
	msgbox Route11_EastEntrance_2F_Text_DeclinedTrade
	release
	end

Route11_EastEntrance_2F_Text_DeclinedTrade::
	.string "That's too bad.$"

Route11_EastEntrance_2F_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox Route11_EastEntrance_2F_Text_WhatThatsNotMon
	release
	end

Route11_EastEntrance_2F_Text_WhatThatsNotMon::
	.string "What?\n"
	.string "That's no {STR_VAR_1}!$"

Route11_EastEntrance_2F_EventScript_AlreadyTraded::
	msgbox Route11_EastEntrance_2F_Text_IsntMyOldMonGreat
	release
	end

Route11_EastEntrance_2F_Text_IsntMyOldMonGreat::
	.string "How is my old {STR_VAR_2}?\n"
	.string "My {STR_VAR_1} is doing great!$"

@Aide Gift 3
Route11_EastEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_ITEMFINDER, Route11_EastEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route11_EastEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_ITEMFINDER, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_ITEMFINDER, 1
    waitmessage
    setflag FLAG_RECEIVED_ITEMFINDER
    setflag FLAG_HIDE_AIDE_ROUTE11
    clearflag FLAG_AIDE_LOCATION_3
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call_if_set FLAG_BADGE05_GET, Route11_EastEntrance_2F_EventScript_AideNextLocation
    release
    end

Route11_EastEntrance_2F_Text_GiveReward::
    .string "Hi, {PLAYER}!\p"
    .string "Prof. Oak says you're doing quite\n" 
    .string "well, so I'm supposed to give you\l"
    .string "this reward.$"

Route11_EastEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route11_EastEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route11_EastEntrance_2F_Text_ExplainReward::
    .string "There are items on the ground that\n"
    .string "may be hidden from view.\p"
    .string "Use the Item Finder to detect any\n"
    .string "hidden items close to you.\p"
    .string "The machine is a bit limited.\n"
    .string "It can't pinpoint item locations.\p"
    .string "What it does is show the direction\n"
    .string "where the item is.\p"
    .string "Use it to get your bearings, then\n"
    .string "search the suspect area by hand.$"

Route11_EastEntrance_2F_EventScript_AideNextLocation::
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_4
    return
