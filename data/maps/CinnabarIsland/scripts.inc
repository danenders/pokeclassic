CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CinnabarIsland_OnResume
	.byte 0

CinnabarIsland_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

CinnabarIsland_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CinnabarIsland_EventScript_Woman::
	lock
	faceplayer
	msgbox CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab
	release
	end

CinnabarIsland_Text_BlaineLivedHereSinceBeforeLab::
    .string "Cinnabar Gym's Blaine is quite the\n"
    .string "odd fellow.\p"
    .string "He's lived on the island since way\n"
    .string "before the LAB was built.$"

CinnabarIsland_EventScript_OldMan::
	msgbox CinnabarIsland_Text_ScientistsExperimentInMansion, MSGBOX_NPC
	end

CinnabarIsland_Text_ScientistsExperimentInMansion::
    .string "Scientists conduct experiments \n"
    .string "in the burned-out building.\p"
    .string "You know, the one they call the\n"
    .string "Pokémon Mansion.$"

CinnabarIsland_EventScript_Kid::
	msgbox CinnabarIsland_Text_GhostStory, MSGBOX_NPC
	end

CinnabarIsland_Text_GhostStory::
	.string "The local kids like to make up\n"
	.string "stories about the Pokémon Mansion.\p"
	.string "My favorite was the one about there\n"
	.string "being an Old Treasure Map hidden\l"
	.string "somehwere inside!$"

CinnabarIsland_EventScript_IslandSign::
	msgbox CinnabarIsland_Text_IslandSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_IslandSign::
    .string "Cinnabar Island\n"
    .string "The Fiery Town of Burning Desire$"

CinnabarIsland_EventScript_PokemonLabSign::
	msgbox CinnabarIsland_Text_PokemonLab, MSGBOX_SIGN
	end

CinnabarIsland_Text_PokemonLab::
    .string "Pokémon Lab$"

CinnabarIsland_EventScript_GymSign::
	lockall
	msgbox CinnabarIsland_Text_GymSign
	releaseall
	end

CinnabarIsland_Text_GymSign::
    .string "Cinnabar Island Pokémon Gym\n"
    .string "Leader: Blaine\l"
    .string "The Hotheaded Quiz Master!$"

CinnabarIsland_EventScript_ShellBell::
	finditem ITEM_SHELL_BELL, 1
	release
	end

CinnabarIsland_EventScript_LightClay::
	finditem ITEM_LIGHT_CLAY, 1
	release
	end
