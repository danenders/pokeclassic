.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_MetBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
    .string "Have you heard about Bill?\p"
    .string "Everyone calls him a PokéManiac!\p"
    .string "I think people are just jealous of\n"
    .string "Bill, though.\p"
    .string "Who wouldn't want to boast about\n"
    .string "their Pokémon?$"

CeruleanCity_PokemonCenter_1F_EventScript_MetBill:
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillNumber, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillNumber::
	.string "Oh, so you've met Bill\n"
	.string "And he even gave you his\l"
	.string "Cell Phone number!\p"
	.string "Wow, he's so approachable!$"

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	goto_if_set FLAG_REGISTERED_BILL, CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
    .string "That Bill!\p"
    .string "I heard that he'll do whatever it\n"
    .string "takes to get rare Pokémon.\p"
    .string "He's not above doing all sorts\n"
    .string "of things, I've heard.$"

CeruleanCity_PokemonCenter_1F_EventScript_IsItTrueAboutBill::
	msgbox CeruleanCity_PokemonCenter_1F_Text_IsItTrue, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_IsItTrue::
	.string "Oh, you've met Bill?\p"
	.string "Is it true what they say?\n"
	.string "Will he do anything to get\l"
	.string "rare Pokémon?$"


CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons, MSGBOX_NPC
	release
	end

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
    .string "Bill has lots of Pokémon!\n"
    .string "He collects rare ones, too!$"

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
    .string "Back in my day, we would go upstairs\n"
    .string "and trade Pokémon with our friends.\p"
    .string "You could get a lot more variety\n"
    .string "by trading.\p"
    .string "But nobody seems to trade POKéMON\n"
    .string "these days.$"

CeruleanCity_PokemonCenter_1F_EventScript_PokemonJournalMisty::
	msgbox PokemonJournal_Text_SpecialFeatureMisty, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureMisty::
	.string "Pokémon Journal:\p"
	.string "Special Feature: Cerulean Gym\n"
	.string "Leader Misty!\p"
	.string "Misty is said to worship Lorelei\n"
	.string "of the Elite Four.$"
