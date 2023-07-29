LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setflag FLAG_VISITED_LAVENDER_TOWN
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_Text_DoYouBelieveInGhosts::
    .string "Do you believe in ghosts?$"

LavenderTown_Text_JustImaginingWhiteHand::
    .string "Hahaha, I guess not.\p"
    .string "That white hand on your shoulder…\n"
    .string "I'm just imagining it.$"


LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_Text_SoThereAreBelievers::
    .string "Really?\n"
    .string "So there are believers…$"

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_Text_TownKnownAsMonGraveSite::
    .string "This town is known as the grave\n"
    .string "site of Pokémon.\p"
    .string "Memorial services are held in\n"
    .string "Pokémon Tower.$"

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_Text_GhostsAppearedInTower::
    .string "Ghosts appeared in Pokémon Tower.\p"
    .string "I think they're the spirits of\n"
    .string "Pokémon that the Rockets killed.$"

LavenderTown_Text_TownSign::
    .string "Lavender Town\n"
    .string "The Noble Purple Town$"

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_TrainerTips::
	msgbox LavenderTown_Text_TrainerTips, MSGBOX_SIGN
	end

LavenderTown_Text_TrainerTips::
    .string "Trainer Tips!\n"
    .string "Hold the A Button to walk quietly\n"
    .string "when using your PokéNav!$"

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_Text_VolunteerPokemonHouse::
    .string "Lavender Volunteer\n"
    .string "Pokémon House$"

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_Text_PokemonTowerSign::
    .string "Pokémon Tower\n"
    .string "Becalm the Spirits of Pokémon$"
