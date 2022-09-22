.set LOCALID_SCIENTIST1, 1
.set LOCALID_OLD_AMBER,  6

PewterCity_Museum_1F_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
    .string "Welcome to our museum!\n"
    .string "It's ¥50 for a child's ticket.\p"
    .string "Would you like to come in?$"

PewterCity_Museum_1F_Text_ComeAgain::
    .string "Come again!$"

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou, MSGBOX_DEFAULT
	setvar VAR_PEWTER_CITY_MUSEUM_STATE, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_Text_Right50YThankYou::
    .string "Right, ¥50!\n"
    .string "Thank you!$"

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	applymovement OBJ_EVENT_ID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
    .string "You don't have enough money.$"

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_ne VAR_FACING, DIR_EAST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
    .string "Please enjoy yourself.$"

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
    .string "You can't sneak in the back way!\n"
    .string "Nice try, kid, but no.\p"
    .string "Oh, whatever!\n"
    .string "Do you know what Amber is?$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
    .string "Amber is actually sap, that gooey\n"
    .string "stuff that oozes from trees.\p"
    .string "The ancient sap fossilized over\n"
    .string "time to become rock-hard Amber.$"

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter, MSGBOX_DEFAULT
	turnobject LOCALID_SCIENTIST1, DIR_WEST
	waitmovement 1
	release
	end

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
    .string "Amber contains the genetic matter\n"
    .string "of ancient Pokémon.\p"
    .string "There's a Lab somewhere trying to\n"
    .string "resurrect Pokémon from amber.$"

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
    .string "We have two fossils of rare,\n"
    .string "prehistoric Pokémon on exhibit.$"

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined, MSGBOX_DEFAULT
	checkitemspace ITEM_OLD_AMBER, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PewterCity_Museum_1F_Text_ReceivedOldAmber
	waitfanfare
	additem ITEM_OLD_AMBER, 1
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	goto_if_set FLAG_GOT_AERODACTYL_REWARD, PewterCity_Museum_1F_EventScript_AlreadyGotReward
	goto_if_set FLAG_RESSURECTED_AERODACTYL, PewterCity_Museum_1F_EventScript_WowThatsAerodactyl
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_GetOldAmberChecked::
    .string "Ssh!\n"
    .string "Get the Old Amber checked!$"

PewterCity_Museum_1F_EventScript_WowThatsAerodactyl::
	msgbox PewterCity_Museum_1F_Text_WowThatsAerodactyl, MSGBOX_DEFAULT
	goto_if_eq VAR_FOSSIL_SELECTION, 1, PewterCity_Museum_1F_EventScript_GiveHelixFossil
	goto_if_eq VAR_FOSSIL_SELECTION, 2, PewterCity_Museum_1F_EventScript_GiveDomeFossil
	end

PewterCity_Museum_1F_EventScript_GiveHelixFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedHelixFossil
	waitfanfare
	waitmessage
	additem ITEM_HELIX_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedHelixFossil::
    .string "Obtained the Helix Fossil!$"

PewterCity_Museum_1F_EventScript_GiveDomeFossil::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Museum_1F_Text_ObtainedDomeFossil
	waitfanfare
	waitmessage
	additem ITEM_DOME_FOSSIL, 1
	goto PewterCity_Museum_1F_EventScript_GaveReward
	end

PewterCity_Museum_1F_Text_ObtainedDomeFossil::
    .string "Obtained the Dome Fossil!$"

PewterCity_Museum_1F_EventScript_GaveReward::
	setflag FLAG_GOT_AERODACTYL_REWARD
	release
	end

PewterCity_Museum_1F_Text_WowThatsAerodactyl::
    .string "Wow!\n"
    .string "You ressurected the Pokémon?\p"
    .string "I knew it contained DNA!\p"
    .string "Thank you for letting me know.\n"
    .string "Please take this as a reward!$"

PewterCity_Museum_1F_EventScript_AlreadyGotReward::
	msgbox PewterCity_Museum_1F_Text_PowerOfScience, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_PowerOfScience::
    .string "It's incredible what we can do\n"
    .string "with the power of science!$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
    .string "Ssh! Listen, I need to share a\n"
    .string "secret with someone.\p"
    .string "I think that this chunk of Amber\n"
    .string "contains Pokémon DNA!\p"
    .string "It would be a shattering scientific\n"
    .string "breakthrough if Pokémon could be\l"
    .string "resurrected from it.\p"
    .string "But, my colleagues just ignore\n"
    .string "what I have to say.\p"
    .string "So, I have a favor to ask!\p"
    .string "I want you to get this examined at\n"
    .string "a Pokémon Lab somewhere.$"

PewterCity_Museum_1F_Text_ReceivedOldAmber::
    .string "{PLAYER} received the Old Amber\n"
    .string "from the scientist.$"

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
    .string "You don't have space for this.$"

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
    .string "There is a beautiful piece of\n"
    .string "amber in a clear gold color.$"

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
    .string "I should be grateful for my long\n"
    .string "life.\p"
    .string "Never did I think I would get to\n"
    .string "see the bones of a dragon!$"

PewterCity_Museum_1F_EventScript_PokemonJournalBrock::
	msgbox PokemonJournal_Text_SpecialFeatureBrock, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureBrock::
	.string "Pokémon Journal\p"
	.string "Special Feature: Pewter Gym\n"
	.string "Leader Brock!\p"
	.string "Brock rarely laughs, but is said to\n"
	.string "be unable to stop if he starts.$"


PewterCity_Museum_1F_EventScript_AerodactylFossil::
    lockall
    setvar VAR_0x8004, SPECIES_AERODACTYL
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_AerodactylFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_AerodactylFossil::
    .string "Aerodactyl Fossil\n"
    .string "A primitive and rare Pokémon.$"

PewterCity_Museum_1F_EventScript_KabutopsFossil::
    lockall
    setvar VAR_0x8004, SPECIES_KABUTOPS
    setvar VAR_0x8005, 10
    setvar VAR_0x8006, 3
    special OpenMuseumFossilPic
    msgbox PewterCity_Museum_1F_Text_KabutopsFossil
    special CloseMuseumFossilPic
    releaseall
    end

PewterCity_Museum_1F_Text_KabutopsFossil::
    .string "Kabutops Fossil\n"
    .string "A primitive and rare Pokémon.$"
