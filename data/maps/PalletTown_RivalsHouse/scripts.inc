.set LOCALID_DAISY, 1

PalletTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
    .string "It's a big map of the Kanto region.\p"
    .string "Isn't it so much easier to use\n"
    .string "the map from your PokéGear?!$"

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
    .string "The shelves are crammed full of\n"
    .string "books on Pokémon.$"

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	goto_if_le VAR_OAK_LAB_STATE, 3, PalletTown_RivalsHouse_EventScript_Daisy1
	goto_if_le VAR_OAK_LAB_STATE, 4, PalletTown_RivalsHouse_EventScript_Daisy2
	goto_if_unset FLAG_REGISTERED_RIVAL, PalletTown_RivalsHouse_EventScript_Daisy3
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
    .string "Daisy: Just like people, Pokémon\n"
    .string "are living things.\p"
    .string "When they get tired, please give\n"
    .string "them a rest.$"

PalletTown_RivalsHouse_EventScript_Daisy1::
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
    .string "Daisy: Hi, {PLAYER}!\p"
    .string "My brother, {RIVAL}, is out at\n"
    .string "Grandpa's Lab.$"

PalletTown_RivalsHouse_EventScript_Daisy2::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival, MSGBOX_DEFAULT
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
    .string "Daisy: {PLAYER}, I heard you had\n"
    .string "a battle against {RIVAL}.\p"
    .string "I wish I'd seen that!$"

PalletTown_RivalsHouse_EventScript_Daisy3::
	goto_if_le VAR_OAK_LAB_STATE, 7, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	msgbox PalletTown_RivalsHouse_Text_GetRivalNumber, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredRival, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_RIVAL
	setflag FLAG_REGISTERED_DAISY
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	release
	end

PalletTown_RivalsHouse_Text_GetRivalNumber::
    .string "Grandpa asked you to run an\n"
    .string "errand?\p"
    .string "And {RIVAL} wouldn't even give\n"
    .string "you his number, either?\p"
    .string "Gee, that's rude of him.\n"
    .string "Here, let me help you.$"

PalletTown_RivalsHouse_EventScript_GroomMon:: @TODO
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_DAISY, Common_Movement_Heart
	applymovement LOCALID_DAISY, Common_Movement_Delay48
	waitmovement 1
	release
	end

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
    .string "Daisy: Hi, {PLAYER}!\n"
    .string "Good timing.\p"
    .string "I'm about to have some tea.\n"
    .string "Would you like to join me?\p"
    .string "Oh, but look.\n"
    .string "Your Pokémon are a little dirty.\p"
    .string "Would you like me to groom one?$"

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
    .string "You don't need any grooming done?\n"
    .string "Okay, we'll just have tea.$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
    .string "Which one should I groom?$"

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
    .string "Oh, sorry. I honestly can't\n"
    .string "groom an Egg.$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
    .string "Daisy: Okay, I'll get it looking\n"
    .string "nice in no time.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
    .string "{STR_VAR_1} looks dreamily content…\p"
    .string "Daisy: There you go! All done.\n"
    .string "See? Doesn't it look nice?\p"
    .string "Giggle…\n"
    .string "It's such a cute Pokémon.$"


PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
    .string "Daisy: Your Pokémon grow to love\n"
    .string "you if you raise them with love.\p"
    .string "For example, {PLAYER}, may I see\n"
    .string "your first Pokémon?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
    .string "…Um, it's not easy for me to say\n"
    .string "this, but…\p"
    .string "Is there some reason why your\n"
    .string "Pokémon would hate you so much?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
    .string "{PLAYER}, I don't like the way it\n"
    .string "glares at you.\p"
    .string "Could you try being a little nicer\n"
    .string "to it?$"

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
    .string "It's not quite familiar with you\n"
    .string "yet.\p"
    .string "Pokémon are all quite wary when\n"
    .string "you first get them.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
    .string "It's warming up to you.\n"
    .string "Trust must be growing between you.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
    .string "It's quite friendly with you.\n"
    .string "Keep being good to it!$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
    .string "It looks very happy.\p"
    .string "I wish {RIVAL} could see this and\n"
    .string "learn something from it.$"

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore, MSGBOX_DEFAULT
	release
	end

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
    .string "It couldn't possibly love you\n"
    .string "any more than it does now.\p"
    .string "Your Pokémon is happy beyond\n"
    .string "words.$"



