.set LOCALID_NURSE, 1

CinnabarIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
    .string "The Gym Leader's friend used to\n"
    .string "live in that burned-out mansion.\p"
    .string "At least that's what they say.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
    .string "Do you have lots of friends?\p"
    .string "Getting older can be lonely, so\n"
    .string "its important to try new things\l"
    .string "every once in a while.\p"
    .string "Who knows, you may end up making\n"
    .string "new friends.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
    .string "Pokémon can still learn techniques\n"
    .string "after canceling evolution.\p"
    .string "Evolution can wait until new moves\n"
    .string "have been learned.$"
