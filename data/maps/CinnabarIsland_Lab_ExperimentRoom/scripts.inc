.set LOCALID_SCIENTIST, 1

CinnabarIsland_Lab_ExperimentRoom_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
	lock
	faceplayer
	goto_if_set FLAG_QUEUE_FOSSIL_RESURRECTION, FossilResurrection_Status
	msgbox FossilResurrection_Text_InventedAMachine, MSGBOX_NPC
	call FossilRessurection_CheckAmber
	call FossilRessurection_CheckHelix
	call FossilRessurection_CheckDome
	goto_if_eq VAR_TEMP_1, TRUE, FossilResurrection_HasFossil
	msgbox FossilResurrection_Text_BringMeAFossil, MSGBOX_NPC
	release
	end

FossilResurrection_Text_InventedAMachine::
	.string "Did you know that Pokémon have been\n"
	.string "around for millions of years?\p"
	.string "We have evidence of ancient Pokémon from\n"
	.string "fossil records!\p"
	.string "Sadly, these Pokémon have gone extinct…\n"
	.string "but I've been working on a machine that\l"
	.string "resurrects Pokémon from their fossils!$"

FossilResurrection_Text_BringMeAFossil::
	.string "If you ever find a Fossil, please\n"
	.string "bring it to me!$"

FossilRessurection_CheckAmber::
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setvar VAR_TEMP_1, TRUE
	return

FossilRessurection_CheckHelix::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setvar VAR_TEMP_1, TRUE
	return

FossilRessurection_CheckDome::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setvar VAR_TEMP_1, TRUE
	return

FossilResurrection_HasFossil::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox FossilResurrection_Text_WhatsThat
	checkitem ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasAmber
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasHelix
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasDome
	end

FossilResurrection_Text_WhatsThat::
	.string "Oh! What do you have there?\n"
	.string "Let me see...$"

FossilResurrection_HasAmber::
	checkitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasAmberHelix
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasAmberDome
	msgbox FossilResurrection_Text_WantToTryOldAmber, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FossilResurrection_AnotherTime
	goto FossilResurrection_ChooseOldAmber
	end

FossilResurrection_Text_WantToTryOldAmber::
	.string "You have some Old Amber!\p"
	.string "Would you like to try and resurrect\n"
	.string "a Pokémon from the DNA contained inside?$"

FossilResurrection_HasHelix::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasHelixDome
	msgbox FossilResurrection_Text_WantToTryHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FossilResurrection_AnotherTime
	goto FossilResurrection_ChooseHelixFossil
	end


FossilResurrection_Text_WantToTryHelixFossil::
	.string "You have a Helix Fossil!\p"
	.string "Would you like to try and resurrect\n"
	.string "a Pokémon from the fossilized bones?$"

FossilResurrection_HasDome::
	msgbox FossilResurrection_Text_WantToTryDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FossilResurrection_AnotherTime
	goto FossilResurrection_ChooseDomeFossil
	end

FossilResurrection_Text_WantToTryDomeFossil::
	.string "You have a Dome Fossil!\p"
	.string "Would you like to try and resurrect\n"
	.string "a Pokémon from the fossilized bones?$"

FossilResurrection_HasAmberHelix::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasAmberHelixDome
	message FossilResurrection_Text_WhichFossil
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_AMBERHELIX, FALSE
	switch VAR_RESULT
	case 0, FossilResurrection_ChooseOldAmber
	case 1, FossilResurrection_ChooseHelixFossil
	case 2, FossilResurrection_AnotherTime
	case MULTI_B_PRESSED, FossilResurrection_AnotherTime
	end

FossilResurrection_HasAmberDome::
	message FossilResurrection_Text_WhichFossil
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_AMBERDOME, FALSE
	switch VAR_RESULT
	case 0, FossilResurrection_ChooseOldAmber
	case 1, FossilResurrection_ChooseDomeFossil
	case 2, FossilResurrection_AnotherTime
	case MULTI_B_PRESSED, FossilResurrection_AnotherTime
	end

FossilResurrection_HasHelixDome::
	checkitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, FossilResurrection_HasAmberHelixDome
	message FossilResurrection_Text_WhichFossil
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_DOMEHELIX, FALSE
	switch VAR_RESULT
	case 0, FossilResurrection_ChooseHelixFossil
	case 1, FossilResurrection_ChooseDomeFossil
	case 2, FossilResurrection_AnotherTime
	case MULTI_B_PRESSED, FossilResurrection_AnotherTime
	end

FossilResurrection_HasAmberHelixDome::
	message FossilResurrection_Text_WhichFossil
	waitmessage
	multichoice 17, 0, MULTI_FOSSIL_ALL, FALSE
	switch VAR_RESULT
	case 0, FossilResurrection_ChooseOldAmber
	case 1, FossilResurrection_ChooseHelixFossil
	case 2, FossilResurrection_ChooseDomeFossil
	case 3, FossilResurrection_AnotherTime
	case MULTI_B_PRESSED, FossilResurrection_AnotherTime
	end

FossilResurrection_Text_WhichFossil::
	.string "Oh! You actually have multiple\n"
	.string "fossils!\p"
	.string "Which Fossil would you like to\n"
	.string "resurrect?$"

FossilResurrection_ChooseOldAmber::
	removeitem ITEM_OLD_AMBER
	setvar VAR_RESURRECTION_FOSSIL, 3
	goto FossilResurrection_Begin
	end

FossilResurrection_ChooseHelixFossil::
	removeitem ITEM_HELIX_FOSSIL
	setvar VAR_RESURRECTION_FOSSIL, 2
	goto FossilResurrection_Begin
	end

FossilResurrection_ChooseDomeFossil::
	removeitem ITEM_DOME_FOSSIL
	setvar VAR_RESURRECTION_FOSSIL, 1
	goto FossilResurrection_Begin
	end

FossilResurrection_Begin::
	msgbox FossilResurrection_Text_LetsGetStarted, MSGBOX_NPC
	setflag FLAG_QUEUE_FOSSIL_RESURRECTION
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

FossilResurrection_Text_LetsGetStarted::
	.string "Excellent!\p"
	.string "The resurrection process could take\n"
	.string "some time, so I'll get started right\l"
	.string "away!\p"
	.string "You should come back again later.$"

FossilResurrection_AnotherTime::
	msgbox FossilResurrection_Text_AnotherTime
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

FossilResurrection_Text_AnotherTime::
	.string "Ah, alright...\n"
	.string "Perhaps another time!$"

FossilResurrection_Status::
	goto_if_lt VAR_FOSSIL_STEP_COUNTER, 500, FossilResurrection_ComeBackLater
	goto_if_eq VAR_RESURRECTION_FOSSIL, 1, FossilResurrection_Kabuto
	goto_if_eq VAR_RESURRECTION_FOSSIL, 2, FossilResurrection_Omanyte
	goto FossilResurrection_Aerodactyl
	end

FossilResurrection_ComeBackLater::
	msgbox FossilResurrection_Text_FossilNotReady, MSGBOX_NPC
	release
	end

FossilResurrection_Text_FossilNotReady::
	.string "The process still needs more time.\n"
    .string "Why not go for walk a little while?$"

FossilResurrection_Omanyte::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	msgbox Text_FossilMonBackToLife, MSGBOX_NPC
	setvar VAR_TEMP_1, SPECIES_OMANYTE
	givemon SPECIES_OMANYTE, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FossilResurrection_ReceiveOmanyteParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FossilResurrection_ReceiveOmanytePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

FossilResurrection_ReceiveOmanyteParty::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_Finish
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FossilResurrection_Finish
	end

FossilResurrection_ReceiveOmanytePC::
	bufferspeciesname STR_VAR_2, SPECIES_OMANYTE
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_TransferToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FossilResurrection_TransferToPC
	end

FossilResurrection_Kabuto::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	msgbox Text_FossilMonBackToLife, MSGBOX_NPC
	setvar VAR_TEMP_1, SPECIES_KABUTO
	givemon SPECIES_KABUTO, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FossilResurrection_ReceiveKabutoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FossilResurrection_ReceiveKabutoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end	

FossilResurrection_ReceiveKabutoParty::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_Finish
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FossilResurrection_Finish
	end

FossilResurrection_ReceiveKabutoPC::
	bufferspeciesname STR_VAR_2, SPECIES_KABUTO
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_TransferToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FossilResurrection_TransferToPC
	end

FossilResurrection_Aerodactyl::
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	msgbox Text_FossilMonBackToLife, MSGBOX_NPC
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
	givemon SPECIES_AERODACTYL, 20
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, FossilResurrection_ReceiveAerodactylParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, FossilResurrection_ReceiveAerodactylPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end	

FossilResurrection_ReceiveAerodactylParty::
	setflag FLAG_RESSURECTED_AERODACTYL
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_Finish
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FossilResurrection_Finish
	end

FossilResurrection_ReceiveAerodactylPC::
	setflag FLAG_RESSURECTED_AERODACTYL
	bufferspeciesname STR_VAR_2, SPECIES_AERODACTYL
	playfanfare MUS_OBTAIN_ITEM
	message Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FossilResurrection_TransferToPC
	call Common_EventScript_NameReceivedBoxMon
	goto FossilResurrection_TransferToPC
	end
	
FossilResurrection_TransferToPC::
	call Common_EventScript_TransferredToPC
	goto FossilResurrection_Finish
	end

FossilResurrection_Finish::
	setvar VAR_FOSSIL_STEP_COUNTER, 0
	setvar VAR_RESURRECTION_FOSSIL, 0
	clearflag FLAG_QUEUE_FOSSIL_RESURRECTION
	release
	end

Text_FossilMonBackToLife::
    .string "There you are!\n"
    .string "The experiment is complete, and\p"
    .string "your fossil came back to life!\n"
    .string "We successfully revived {STR_VAR_2}!$"

Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the Researcher.$"

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
	lock
	faceplayer
	setvar VAR_0x8008, INGAME_TRADE_SEEL
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	goto_if_set FLAG_IN_GAME_TRADE_SEEL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_LookingForMonWannaTradeForMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HeyThanks, MSGBOX_DEFAULT
	setflag FLAG_IN_GAME_TRADE_SEEL
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_Text_HeyThanks::
	.string "Hey, thanks!$"

CinnabarIsland_PokemonLab_ExperimentRoom_Text_LookingForMonWannaTradeForMon::
	.string "Hi!\n"
	.string "Do you have a {STR_VAR_1}?\p"
	.string "Want to trade it for my\n"
	.string "{STR_VAR_2}?$"

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_DeclinedTrade
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_Text_DeclinedTrade::
	.string "That's too bad.$"

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_WhatThatsNotMon
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_Text_WhatThatsNotMon::
	.string "What?\n"
	.string "That's no {STR_VAR_1}!$"

CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_IsntMyOldMonGreat
	release
	end

CinnabarIsland_PokemonLab_ExperimentRoom_Text_IsntMyOldMonGreat::
	.string "How is my old {STR_VAR_2}?\n"
	.string "My {STR_VAR_1} is doing great!$"
