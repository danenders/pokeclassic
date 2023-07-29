.set LOCALID_BOAT, 4 
.set LOCALID_CAPTAIN, 5 

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CinnabarIsland_OnResume
	.byte 0

CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
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

CinnabarIsland_EventScript_PokemonMansionSign::
	msgbox CinnabarIsland_Text_PokemonMansion, MSGBOX_SIGN
	end

CinnabarIsland_Text_PokemonMansion::
    .string "Pokémon Mansion\n"
    .string "NOTICE: CONDEMNED$"

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

CinnabarIsland_EventScript_Depart::
	lock
	faceplayer
	msgbox CinnabarIsland_EventScript_Text_ReadyToSail, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_EventScript_NotSail
	msgbox CinnabarIsland_EventScript_Text_LetsSail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPTAIN, Movement_CaptainEnterShip
	waitmovement 5
	call_if_eq VAR_FACING, DIR_NORTH, CinnabarIsland_EventScript_PlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, CinnabarIsland_EventScript_PlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, CinnabarIsland_EventScript_PlayerEast
	call_if_eq VAR_FACING, DIR_WEST, CinnabarIsland_EventScript_PlayerWest
	waitmovement 0
	setvar VAR_0x8004, LOCALID_BOAT
	call Common_EventScript_FerryDepart
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 15, 39
	waitstate
	release
	end

CinnabarIsland_EventScript_Text_ReadyToSail::
	.string "Ready for an adventure?$"

CinnabarIsland_EventScript_NotSail::
	msgbox CinnabarIsland_EventScript_Text_ReadyWhenYouAre, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_EventScript_Text_ReadyWhenYouAre:
	.string "We'll set sail as soon as you're\n"
	.string "ready!$"

CinnabarIsland_EventScript_Text_LetsSail:
	.string "Excellent! We'll set sail right away!\p"
	.string "Let's find this island on\n"
	.string "this Old Sea Map!$"

Movement_CaptainEnterShip::
	walk_up
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

CinnabarIsland_EventScript_PlayerNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipNorth
	return

CinnabarIsland_EventScript_PlayerSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipSouth
	return

CinnabarIsland_EventScript_PlayerEast::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipEast
	return

CinnabarIsland_EventScript_PlayerWest::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterShipWest
	return

Movement_PlayerEnterShipNorth::
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipSouth::
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipEast::
	walk_right
	walk_up
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end

Movement_PlayerEnterShipWest::
	walk_left
	walk_up
	walk_up
	walk_up
	face_right
	walk_in_place_faster_right
	walk_in_place_faster_right
	set_invisible
	step_end
