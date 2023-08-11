PewterCity_PokemonCenter_2F_MapScripts::
	.byte 0

PewterCity_PokemonCenter_2F_Trainer::
	lock
	faceplayer
	msgbox PewterCity_PokemonCenter_2F_Brock, MSGBOX_DEFAULT
	release
	end

PewterCity_PokemonCenter_2F_Brock::
	.string "Brock is really tough!\p"
	.string "I need to find his weakness if\n"
	.string "I want to take him down and earn\l"
	.string "that badge!$"
