SaffronCity_PokemonCenter_2F_MapScripts::
	.byte 0

SaffronCity_PokemonCenter_2F_Rocket1::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket1, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket1::
	.string "Heh, scram kid!\n"
	.string "This is Team Rocket's Loot now!$"


SaffronCity_PokemonCenter_2F_Rocket2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket2, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket2::
	.string "Uh..I forgot what we came here for.$"

SaffronCity_PokemonCenter_2F_Rocket3::
	msgbox SaffronCity_PokemonCenter_2F_Text_Rocket3, MSGBOX_NPC
	release
	end

SaffronCity_PokemonCenter_2F_Text_Rocket3::
	.string "Whoa! They have some really rare\n"
	.string "goods back here!\p"
	.string "The Boss is going to love this haul!$"


SaffronCity_PokemonCenter_2F_BlackBelt::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLACK_BELT, SaffronCity_PokemonCenter_2F_BlackBelt2
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_BELT, 1
	setflag FLAG_RECEIVED_BLACK_BELT
	release
	end

SaffronCity_PokemonCenter_2F_BlackBelt2::
	msgbox SaffronCity_PokemonCenter_2F_Text_Unworthy2, MSGBOX_DEFAULT
	release
	end

SaffronCity_PokemonCenter_2F_Text_Unworthy::
	.string "I am ashamed.\p"
	.string "When Team Rocket attacked Saffron City,\n"
	.string "I was unable to stop them.\p"
	.string "I am unworthy of this.$"

SaffronCity_PokemonCenter_2F_Text_Unworthy2::
	.string "I need to return to the Dojo.\n"
	.string "I must retrain my body and spirit.$"
