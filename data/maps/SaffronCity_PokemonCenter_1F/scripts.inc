.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end


SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_Woman2
	msgbox SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_Text_RocketsUpstairs::
	.string "Team Rocket is so shady!\p"
	.string "They left us alone down here while they\n"
	.string "were looting the second floor!$"

SaffronCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
	msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
	msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff
	release
	end

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
    .string "Pokémon growth rates differ from\n"
    .string "species to species.$"

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
    .string "Siph Co. is widely known to all.\p"
    .string "It's a victim of its own fame - it\n"
    .string "attracted Team Rocket.$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
    .string "Sigh…\n"
    .string "Wouldn't this be great?\p"
    .string "If the Elite Four came and\n"
    .string "stomped Team Rocket?$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
    .string "Team Rocket took off!\n"
    .string "We can go out safely again!\l"
    .string "That's great!$"
