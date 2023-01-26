Route10_PokemonCenter_2F_MapScripts::
	.byte 0

Route10_PokemonCenter_2F_Hiker::
	lock
	faceplayer
	msgbox Route10_PokemonCenter_2F_Darkness, MSGBOX_DEFAULT
	release
	end

Route10_PokemonCenter_2F_Darkness::
	.string "Rock Tunnel is too dark to get through!$"
