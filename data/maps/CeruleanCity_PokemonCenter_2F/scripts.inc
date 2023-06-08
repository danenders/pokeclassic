CeruleanCity_PokemonCenter_2F_MapScripts::
	.byte 0

CeruleanCity_PokemonCenter_2F_Girl::
	lock
	faceplayer
	goto_if_set FLAG_GOT_EVIOLITE, CeruleanCity_PokemonCenter_2F_Girl2
	msgbox CeruleanCity_PokemonCenter_2F_Text_Eviolite, MSGBOX_DEFAULT
	giveitem ITEM_EVIOLITE
	setflag FLAG_GOT_EVIOLITE
	release
	end

CeruleanCity_PokemonCenter_2F_Text_Eviolite::
	.string "Have you heard about Evioltie?\p"
	.string "It's an item that boosts\n"
	.string "the stast of a Pokémon that\l"
	.string "hasn't evolved yet!\p"
	.string "Here, you should take one!$"

CeruleanCity_PokemonCenter_2F_Girl2::
	msgbox CeruleanCity_PokemonCenter_2F_Oddish, MSGBOX_DEFAULT
	release
	end

CeruleanCity_PokemonCenter_2F_Oddish::
	.string "I never want my Oddish to evolve!\n"
	.string "It's just too cute!$"
