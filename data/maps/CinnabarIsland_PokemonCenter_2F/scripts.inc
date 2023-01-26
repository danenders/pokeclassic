CinnabarIsland_PokemonCenter_2F_MapScripts::
	.byte 0

CinnabarIsland_PokemonCenter_2F_Resident::
	lock
	faceplayer
	msgbox CinnabarIsland_PokemonCenter_2F_Volcano, MSGBOX_DEFAULT
	release
	end

CinnabarIsland_PokemonCenter_2F_Volcano::
	.string "They say Cinnabar Island is\n"
	.string "an active volcano.\p"
	.string "I hope nothing ever happens!$"
