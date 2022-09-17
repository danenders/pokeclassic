.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
    .string "Team Rocket will do anything for\n"
    .string "the sake of money!\p"
    .string "There is no job too dirty, no deed\n"
    .string "too heinous, no crime too wicked!$"

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
    .string "I saw a Cubone's mother trying to\n"
    .string "escape from Team Rocket.\p"
    .string "She was killed trying to get away…$"

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
    .string "You know how the Cubone species\n"
    .string "wears skulls, right?\p"
    .string "People will pay a lot for one.$"

LavenderTown_PokemonCenter_1F_EventScript_BaldingMan::
	msgbox LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere, MSGBOX_NPC
	release
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
    .string "I recently moved to this town.\p"
    .string "I hear that Mr. Fuji's not from\n"
    .string "these parts originally, either.$"
