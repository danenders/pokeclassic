Route4_PokemonCenter_2F_MapScripts::
	.byte 0

Route4_PokemonCenter_2F_Hiker::
	lockall
	goto_if_set FLAG_GOT_HM06, Route4_PokemonCenter_2F_HikerRockSmash
	msgbox Route4_PokemonCenter_2F_Text_RockSmash, MSGBOX_DEFAULT
	giveitem ITEM_HM06
	waitmessage
	setflag FLAG_GOT_HM06
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_DEFAULT
	releaseall
	end


Route4_PokemonCenter_2F_Text_RockSmash::
	.string "I'm hunting for Moon Stones with\n"
	.string "my Pokémon!\p"
	.string "You should try it too!$"

Route4_PokemonCenter_2F_HikerRockSmash::
	lock
	msgbox Route4_PokemonCenter_2F_Text_MyGeodude, MSGBOX_NPC
	release
	end

Route4_PokemonCenter_2F_Text_MyGeodude::
	.string "Be careful when using Rock Smash.\n"
	.string "Sometimes, a Pokémon might jump out!\p"
	.string "That's how I met my Geodude!$"
