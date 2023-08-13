Route15_WestEntrance_2F_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	goto_if_set FLAG_CAUGHT_ARTICUNO, Route15_WestEntrance_2F_EventScript_RightBinoculars
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_Text_LargeShiningBird::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "A large, shining bird is flying\n"
    .string "toward the sea.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
    .string "Let's see what the binoculars have\n"
    .string "to show…\p"
    .string "It looks like a small island on\n"
    .string "the horizon!$"

@Aide Gift 5
Route15_WestEntrance_2F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_EXP_SHARE, Route15_WestEntrance_2F_EventScript_AlreadyGotReward
    msgbox Route15_WestEntrance_2F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EXP_SHARE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EXP_SHARE, 1
    waitmessage
    setflag FLAG_RECEIVED_EXP_SHARE
    setflag FLAG_HIDE_AIDE_ROUTE15
    clearflag FLAG_AIDE_LOCATION_5
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    clearflag FLAG_HIDE_AIDE_OAK_LAB
    release
    end

Route15_WestEntrance_2F_Text_GiveReward::
    .string "{PLAYER}!\p"
    .string "You're really on a roll.\p"
    .string "As your journey continues, \n"
    .string "raising Pokémon may get harder,\l"
    .string "especially if your team changes!\p"
    .string "So we came up with a device that\n"
    .string "might make raising Pokémon easier.$"

Route15_WestEntrance_2F_EventScript_AlreadyGotReward::
    msgbox Route15_WestEntrance_2F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route15_WestEntrance_2F_Text_ExplainReward::
    .string "You can turn Exp. Share on in you\n"
    .string "Key Items bag.\p"
    .string "It spreads EXP. Points to Pokémon\n"
    .string "in your party, even if they didn't\l"
    .string "participate in the battle.\p"
    .string "You can turn it off at any time, too!$"
