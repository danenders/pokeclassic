LavenderTown_PokemonCenter_2F_MapScripts::
	.byte 0


LavenderTown_PokemonCenter_2F_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, LavenderTown_PokemonCenter_2F_EventScript_OldWoman2
	msgbox LavenderTown_PokemonCenter_2F_Text_SilkScarf, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_SILK_SCARF, 1
	setflag FLAG_GOT_SILK_SCARF
	release
	end

LavenderTown_PokemonCenter_2F_Text_SilkScarf::
	.string "This was my Meowth's...\n"
	.string "It always looked so fancy...\p"
	.string "I think they would like you to\n"
	.string "have it...$"

LavenderTown_PokemonCenter_2F_EventScript_OldWoman2::
	lock
	faceplayer
	msgbox LavenderTown_PokemonCenter_2F_Text_FancyPants, MSGBOX_DEFAULT
	release
	end

LavenderTown_PokemonCenter_2F_Text_FancyPants::
	.string "Pokémon are more than pets.\n"
	.string "They're friends and family.$"
