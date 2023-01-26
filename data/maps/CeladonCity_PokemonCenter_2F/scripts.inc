CeladonCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeladonCity_PokemonCenter_2F_Shopper::
	lock
	faceplayer
	msgbox CeladonCity_PokemonCenter_2F_Shopping, MSGBOX_DEFAULT
	release
	end

CeladonCity_PokemonCenter_2F_Shopping::
	.string "The League Services here have some\n"
	.string "interesting options, but I prefer to\l"
	.string "do my shopping at the Department Store.$"
