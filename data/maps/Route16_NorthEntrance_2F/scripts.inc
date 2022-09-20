Route16_NorthEntrance_2F_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_OnTransition::
	call_if_unset FLAG_RECEIVED_AIDE_AMULET_COIN, Route16_NorthEntrance_2F_EventScript_CheckAideAppearance
	end

@Check if you've completed the requirement and Cedar has called you
Route16_NorthEntrance_2F_EventScript_CheckAideAppearance::
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_Return
	goto_if_unset FLAG_AIDE_LOCATION_4, Common_EventScript_Return
	goto_if_lt VAR_AIDE_CALL_STEP_COUNTER, 200, Common_EventScript_Return
	clearflag FLAG_HIDE_AIDE_ROUTE16
	return

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
    .string "I'm on a relaxing ride on my new\n"
    .string "bike with my girlfriend.$"

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
    .string "We're going riding together on our\n"
    .string "new bikes.$"

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "It's the Celadon Department Store!$"

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_Text_LongPathOverWater::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "There's a long path over water far\n"
    .string "away.$"


@Aide Gift 3
Route16_NorthEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_AMULET_COIN, Route16_NorthEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route16_NorthEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_AMULET_COIN, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_AMULET_COIN, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_AMULET_COIN
    setflag FLAG_HIDE_AIDE_ROUTE16
    clearflag FLAG_AIDE_LOCATION_4
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    call Route16_NorthEntrance_2F_EventScript_CheckAideNextLocation
    release
    end

Route16_NorthEntrance_2F_Text_GiveReward::
    .string "Oh… {PLAYER}!\p"
    .string "I'm glad you were able to find\n"
    .string "me!\p"
    .string "Between the sleeping Snorlax and\n"
    .string "the scary Bikers, I wasn't sure\l"
    .string "if we'd be able to meet up!\p"
    .string "Life as a Trainer must be hard,\n"
    .string "so hopefully this helps ease some\l"
    .string "of the struggles.$"

Route16_NorthEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route16_NorthEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route16_NorthEntrance_2F_Text_ExplainReward::
	.string "Did you know Pokémon can hold items?\p"
    .string "An Amulet Coin is an item to be\n"
    .string "held by a Pokémon.\p"
    .string "If the Pokémon appears in a winning\n"
    .string "battle, you will earn more money.$"

@Check if you've already completed the next requirement
Route16_NorthEntrance_2F_EventScript_CheckAideNextLocation::
    goto_if_unset FLAG_BADGE06_GET, Common_EventScript_Return
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_5
    return
