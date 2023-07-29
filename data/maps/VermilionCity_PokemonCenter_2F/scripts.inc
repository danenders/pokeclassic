VermilionCity_PokemonCenter_2F_MapScripts::
	.byte 0

VermilionCity_PokemonCenter_2F_Pokefan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_DESTINY_KNOT, VermilionCity_PokemonCenter_2F_Pokefan2
	msgbox VermilionCity_PokemonCenter_2F_DestinyKnot, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	setflag FLAG_GOT_DESTINY_KNOT
	release
	end

VermilionCity_PokemonCenter_2F_DestinyKnot::
	.string "I had to leave my sweet little\n"
	.string "Meowth at the Daycare when\l"
	.string "I went on a cruise.\p"
	.string "I didn't want it to get lonely,\n"
	.string "so I left it with a present.\p"
	.string "Here, I had an extra, so you\n"
	.string "should take it!$"

VermilionCity_PokemonCenter_2F_Pokefan2::
	msgbox VermilionCity_PokemonCenter_2F_Daycare, MSGBOX_DEFAULT
	release
	end

VermilionCity_PokemonCenter_2F_Daycare::
	.string "Have you visited the Daycare?\n"
	.string "It's on Route 5.$"
