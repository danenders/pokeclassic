ViridianCity_PokemonCenter_2F_MapScripts::
	.byte 0

ViridianCity_PokemonCenter_2F_LittleGirl::
	lock
	faceplayer
	msgbox ViridianCity_PokemonCenter_2F_Text_Rank, MSGBOX_DEFAULT
	release
	end

ViridianCity_PokemonCenter_2F_Text_Rank::
	.string "That man won't let me buy stuff!\n"
	.string "He says I'm not a high enough rank!\p"
	.string "What's that even mean?$"
