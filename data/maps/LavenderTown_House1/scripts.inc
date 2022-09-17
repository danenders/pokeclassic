LavenderTown_House1_MapScripts::
	.byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_House1_EventScript_CooltrainerFGhostGone
	goto_if_set FLAG_RESCUED_CUBONE, LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn
	msgbox LavenderTown_House1_Text_RocketsKilledCubonesMother
	release
	end

LavenderTown_House1_Text_RocketsKilledCubonesMother::
    .string "Those horrible Rockets!\n"
    .string "They deserve no mercy!\p"
    .string "They kidnapped that Cubone and\n"
    .string "killed its poor mother…$"

LavenderTown_House1_EventScript_CooltrainerSawCuboneReturn::
	msgbox LavenderTown_House1_Text_CuboneReturnedToTower
	release
	end

LavenderTown_House1_Text_CuboneReturnedToTower::
	.string "I saw the Cubone return to Pokémon\n"
	.string "Tower!\p"
	.string "It looked very determined!$"

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	msgbox LavenderTown_House1_Text_GhostOfPokemonTowerIsGone
	release
	end

LavenderTown_House1_Text_GhostOfPokemonTowerIsGone::
    .string "So the ghost of Pokémon Tower was\n"
    .string "Cubone's mother?\p"
    .string "I'm glad this Cubone was able to\n"
    .string "soothe her restless spirit!$"

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end

LavenderTown_House1_Text_Cubone::
    .string "CUBONE: Kyarugoo!$"
