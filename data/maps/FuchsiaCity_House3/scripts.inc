.set LOCALID_EXPERT, 1
.set LOCALID_LASS, 2
.set LOCALID_YOUNGSTER, 3
.set LOCALID_DAISY, 4

.set NUM_OPPONENTS, VAR_0x8009

FuchsiaCity_House3_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, BerryHouse_OnTransition
	.byte 0

BerryHouse_OnTransition::
    call_if_unset FLAG_DAILY_BERRY_BLEND_OPPONENTS, BerryHouse_SetTodaysOpponents
    call BerryHouse_SetPositions
    end

BerryHouse_SetTodaysOpponents::
    setflag FLAG_DAILY_BERRY_BLEND_OPPONENTS
    random 3
    addvar VAR_RESULT, 1
    copyvar VAR_BERRY_HOUSE_VISITORS, VAR_RESULT
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_CheckForDaisy
    return


BerryHouse_CheckForDaisy::
    random 10
    goto_if_ne VAR_RESULT, 9, Common_EventScript_Return
    setvar VAR_BERRY_HOUSE_VISITORS, 4
    return


BerryHouse_SetPositions::
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 4, BerryHouse_DaisyVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 3, BerryHouse_LassAndYoungsterVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 2, BerryHouse_LassVisiting
    call_if_eq VAR_BERRY_HOUSE_VISITORS, 1, BerryHouse_NoOneVisiting
    return

BerryHouse_DaisyVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_DAISY
    addobject LOCALID_DAISY
    setobjectxyperm LOCALID_EXPERT, 4, 5
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

BerryHouse_LassAndYoungsterVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    addobject LOCALID_YOUNGSTER
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_LassVisiting::
    clearflag FLAG_HIDE_BERRY_HOUSE_LASS
    addobject LOCALID_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    return

BerryHouse_NoOneVisiting::
    removeobject LOCALID_DAISY
    setflag FLAG_HIDE_BERRY_HOUSE_DAISY
    removeobject LOCALID_LASS
    setflag FLAG_HIDE_BERRY_HOUSE_LASS
    removeobject LOCALID_YOUNGSTER
    setflag FLAG_HIDE_BERRY_HOUSE_YOUNGSTER
    return

FuchsiaCity_House3_EventScript_Grandfather::
    lock
    faceplayer
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4, FuchsiaCity_House3_EventScript_DaisyVisits
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3, FuchsiaCity_House3_EventScript_WholeFamily
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2, FuchsiaCity_House3_EventScript_OldestGrandhchild
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 1, FuchsiaCity_House3_EventScript_NoVisitors
    end

FuchsiaCity_House3_EventScript_DaisyVisits::
    msgbox FuchsiaCity_House3_Text_DaisyVisits, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_DaisyVisits:
    .string "Oh, you know Daisy, too?\p"
    .string "She visits us from time to time.\n"
    .string "She's very kind to us.\p"
    .string "My wife taught her everything she\n"
    .string "knows about Berry Blending, too!\p"
    .string "She's might even be better than her!\p"
    .string "But don't tell my wife I said that!$"

FuchsiaCity_House3_EventScript_WholeFamily::
    msgbox FuchsiaCity_House3_Text_WarmsMyHeart, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_WarmsMyHeart:
    .string "It warms my heart to see my whole\n"
    .string "family spending time together!$"

FuchsiaCity_House3_EventScript_OldestGrandhchild::
    msgbox FuchsiaCity_House3_Text_OldestGrandhchild, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_OldestGrandhchild:
    .string "My oldest grandchild is visiting us\n"
    .string "today!\p"
    .string "She's a trainer just like you!$"

FuchsiaCity_House3_EventScript_NoVisitors::
    msgbox FuchsiaCity_House3_Text_NoVisitors, MSGBOX_NPC
    call BerryHouse_EventScript_GetDailyBerry
    release
    end

FuchsiaCity_House3_Text_NoVisitors:
    .string "Getting older can be difficult.\p"
    .string "Especially on days like today, when\n"
    .string "we don't get any visitors...\p"
    .string "But then you came, and that brightened\n"
    .string "up our day!$"

FuchsiaCity_House3_EventScript_BerryBlenderSpeedRecords::
    lockall
    special ShowBerryBlenderRecordWindow
    waitbuttonpress
    special RemoveRecordsWindow
    releaseall
    end

FuchsiaCity_House3_EventScript_Picture::
    msgbox FuchsiaCity_House3_Text_Picture, MSGBOX_SIGN
    release
    end

FuchsiaCity_House3_Text_Picture::
    .string "It's a picture of the old couple\n"
    .string "when they were younger...\p"
    .string "There's a big grove of Berry Trees!$"

FuchsiaCity_House3_EventScript_Lass::
    msgbox FuchsiaCity_House3_Text_Lass, MSGBOX_NPC
    turnobject LOCALID_LASS, DIR_EAST
    release
    end

FuchsiaCity_House3_Text_Lass:
    .string "I'm trying to get better at Contests,\n"
    .string "so I'm learning how to Blend Berries\l"
    .string "from my Grandmother!$"

FuchsiaCity_House3_EventScript_Youngster::
    msgbox FuchsiaCity_House3_Text_Youngster, MSGBOX_NPC
    turnobject LOCALID_YOUNGSTER, DIR_WEST
    release
    end

FuchsiaCity_House3_Text_Youngster:
    .string "I'd rather be out there battling.\n"
    .string "My sister says it's nice to visit\l"
    .string "Grandma and Granpa though.\p"
    .string "At least Berry Blending is kind of\n"
    .string "fun, if that's your thing.$"

FuchsiaCity_House3_EventScript_Daisy::
    msgbox FuchsiaCity_House3_Text_Daisy, MSGBOX_NPC
    turnobject LOCALID_DAISY, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Daisy:
    .string "Oh! Hello, {PLAYER}!\p"
    .string "I didn't know you knew the Berry\n"
    .string "masters, too!\p"
    .string "I met them back when I was travelling\n"
    .string "to Contests.\p"
    .string "They taught me everything I know about\n"
    .string "Berry Blending.\p"
    .string "I still try to visit from time to time.\n"
    .string "And it doesn't hurt to practice, too!$"

FuchsiaCity_House3_EventScript_Expert::
    msgbox FuchsiaCity_House3_Text_Expert, MSGBOX_NPC
    turnobject LOCALID_EXPERT, DIR_SOUTH
    release
    end

FuchsiaCity_House3_Text_Expert:
    .string "My husband and I moved to Kanto\n"
    .string "a long time ago, but no one here\l"
    .string "knew about Berry Blending...\p"
    .string "It was quite popular in our homeland,\n"
    .string "so we try to keep the tradition alive.\p"
    .string "Whenever someone visits, we will Blend\n"
    .string "Berries together!$"


BerryHouse_EventScript_BerryBlender::
    lockall
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 4 BerryHouse_EventScript_VsDaisy
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 3 BerryHouse_EventScript_ThreeOpponents
    goto_if_eq VAR_BERRY_HOUSE_VISITORS, 2 BerryHouse_EventScript_TwoOpponents
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_TwoOpponents::
    setvar NUM_OPPONENTS, 2
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_ThreeOpponents::
    setvar NUM_OPPONENTS, 3
    applymovement LOCALID_EXPERT, Common_Movement_WalkInPlaceFasterDown
    applymovement LOCALID_LASS, Common_Movement_WalkInPlaceFasterRight
    applymovement LOCALID_YOUNGSTER, Common_Movement_WalkInPlaceFasterLeft
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlender
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_EventScript_VsDaisy::
    setvar NUM_OPPONENTS, 1
    applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterDown
    waitmovement 1
    msgbox BerryHouse_Text_WantToMakePokeblocksDaisy, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_TryUseBerryBlenderDaisy
    goto BerryHouse_EventScript_DeclineBlender
    end

BerryHouse_Text_WantToMakePokeblocks:
    .string "Oh? Did you want to make some {POKEBLOCK}S?$"

BerryHouse_Text_WantToMakePokeblocksDaisy:
    .string "Oh? Did you want to make some {POKEBLOCK}S\n"
    .string "with me, {PLAYER}?$"

BerryHouse_EventScript_DeclineBlender:
    msgbox BerryHouse_Text_MadeOldTimerSad, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_MadeOldTimerSad:
    .string "Oh…\n"
    .string "Maybe another time then…$"

BerryHouse_EventScript_TryUseBerryBlender:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCase
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerries
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_Text_Excellent:
    .string "Excellent!$"

BerryHouse_EventScript_TryUseBerryBlenderDaisy:
    checkitem ITEM_POKEBLOCK_CASE
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoCaseDaisy
    specialvar VAR_RESULT, GetFirstFreePokeblockSlot
    goto_if_eq VAR_RESULT, 65535, BerryHouse_EventScript_BlenderCaseFull
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, FALSE, BerryHouse_EventScript_BlenderNoBerriesDaisy
    msgbox BerryHouse_Text_Excellent, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_UseBerryBlender
    end

BerryHouse_EventScript_BlenderNoCase:
    msgbox BerryHouse_Text_DontHavePokeblockCase, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCase:
    .string "But you don't have a {POKEBLOCK} Case.\p"
    .string "You should get a {POKEBLOCK} Case first.$"

BerryHouse_EventScript_BlenderNoCaseDaisy:
    msgbox BerryHouse_Text_DontHavePokeblockCaseDaisy, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHavePokeblockCaseDaisy:
    .string "Oh? You don't have a {POKEBLOCK} Case?\p"
    .string "Didn't {RIVAL} give you one?$"

BerryHouse_EventScript_BlenderCaseFull:
    msgbox BerryHouse_Text_PokeblockCaseIsFull, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_PokeblockCaseIsFull:
    .string "Your {POKEBLOCK} Case is full,\n"
    .string "it looks like.\p"
    .string "You should use some {POKEBLOCK}S up\n"
    .string "and then come back.$"

BerryHouse_EventScript_BlenderNoBerries:
    msgbox BerryHouse_Text_DontHaveAnyBerries, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_HusbandGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerries:
    .string "You don't have any Berries,\n"
    .string "do you?\p"
    .string "If you don't have any Berries,\n"
    .string "you can't make any {POKEBLOCK}S.\p"
    .string "We'll always be making {POKEBLOCK}S here,\n"
    .string "so let's make some together when\l"
    .string "you get a Berry or two.$"

BerryHouse_EventScript_HusbandGiveYouBerry::
    msgbox BerryHouse_Text_HusbandGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_HusbandGiveYouBerry:
    .string "If you ask nicely, my husband might have\n"
    .string "an extra Berry to spare.$"

BerryHouse_EventScript_BlenderNoBerriesDaisy:
    msgbox BerryHouse_Text_DontHaveAnyBerriesDaisy, MSGBOX_DEFAULT
    call_if_unset FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_OldManGiveYouBerry
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesDaisy:
    .string "Oh! You don't have any Berries?\n"
    .string "If you don't have any Berries,\n"
    .string "you can't make any {POKEBLOCK}S.$"

BerryHouse_EventScript_OldManGiveYouBerry::
    msgbox BerryHouse_Text_OldManGiveYouBerry, MSGBOX_DEFAULT
    return

BerryHouse_Text_OldManGiveYouBerry:
    .string "You know, if you ask nicely, the old man\n"
    .string "may have an extra Berry to spare.$"

BerryHouse_EventScript_GetDailyBerry::
    specialvar VAR_RESULT, PlayerHasBerries
    goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
    dotimebasedevents
    goto_if_set FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY, BerryHouse_EventScript_BlenderNoSpareBerries
    goto BerryHouse_EventScript_GiveSpareBerry
    end

BerryHouse_EventScript_BlenderNoSpareBerries::
    msgbox BerryHouse_Text_DontHaveAnyBerriesToSpare, MSGBOX_DEFAULT
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesToSpare:
    .string "If I had some Berries left over,\n"
    .string "I'd gladly give you one…\p"
    .string "But, I don't have any to spare today.\n"
    .string "We'll have to do this another time.$"

BerryHouse_EventScript_GiveSpareBerry:
    msgbox BerryHouse_Text_DontHaveAnyBerriesHaveOne, MSGBOX_DEFAULT
    giveitem ITEM_PECHA_BERRY
    setflag FLAG_DAILY_BERRY_HOUSE_RECEIVED_BERRY
    releaseall
    end

BerryHouse_Text_DontHaveAnyBerriesHaveOne:
    .string "Oh?\n"
    .string "You don't have any Berries?\p"
    .string "Well, that won't do at all now, will it?\p"
    .string "If you don't mind leftovers, you can\n"
    .string "have one of my Berries.$"


BerryHouse_EventScript_UseBerryBlender:
    msgbox BerryHouse_Text_KnowHowToMakePokeblocks, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, BerryHouse_EventScript_StartBlender
    goto BerryHouse_EventScript_ExplainBlending
    end

BerryHouse_Text_KnowHowToMakePokeblocks:
    .string "Do you know how to make a {POKEBLOCK}?$"

BerryHouse_EventScript_ExplainBlending:
    msgbox BerryHouse_Text_ExplainBerryBlending, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_StartBlender
    end

BerryHouse_Text_ExplainBerryBlending:
    .string "Okay, a little explanation, then.\p"
    .string "Oh, don't worry, it's quite simple.\p"
    .string "When the Blender's arrow comes to\n"
    .string "your marker, just press the A Button.\p"
    .string "That's all you have to do.\n"
    .string "You'll see how easy it is when you try.$"

BerryHouse_EventScript_StartBlender:
    msgbox BerryHouse_Text_LetsBerryBlender, MSGBOX_DEFAULT
    goto BerryHouse_EventScript_DoBerryBlending
    end

BerryHouse_Text_LetsBerryBlender:
    .string "Let's get started, then!\p"
    .string "Let's Berry Blender!$"

BerryHouse_EventScript_DoBerryBlending:
    @callnative RemoveFollowingPokemon
    copyvar VAR_0x8004, NUM_OPPONENTS
    fadescreen FADE_TO_BLACK
    special DoBerryBlending
    waitstate
    @callnative UpdateFollowingPokemon
    releaseall
    end




