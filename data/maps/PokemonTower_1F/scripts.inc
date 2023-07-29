PokemonTower_1F_MapScripts::
	.byte 0

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
    .string "I am a Channeler.\p"
    .string "There are spirits up to mischief.\n"
    .string "I sense them high in the tower.$"

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_CueBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM42, PokemonTower_1F_EventScript_CueBall2
	msgbox PokemonTower_1F_Text_IDontNeedThis, MSGBOX_NPC
	giveitem ITEM_TM42, 1
	release
	end

PokemonTower_1F_Text_IDontNeedThis::
	.string "Oh...sniff...\n"
	.string "Nuffle...I miss you!\p"
	.string "Here...I don't need this...$"

PokemonTower_1F_EventScript_CueBall2::
	msgbox PokemonTower_1F_Text_BraveFace, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_BraveFace::
	.string "Whenever we battled, I was\n"
	.string "always able to put on a brave\l"
	.string "face for my Pokémon.\p"
	.string "But now, I can't keep up the\n"
	.string "the facade...$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
    .string "My Growlithe…\n"
    .string "Why did you die?$"


PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	msgbox PokemonTower_1F_Text_ComeToPayRespects, MSGBOX_NPC
	release
	end

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
    .string "I came to pray for my dearly\n"
    .string "departed Clefairy.\p"
    .string "Sniff!\n"
    .string "I'm awash in tears…$"

PokemonTower_1F_Text_ComeToPayRespects::
    .string "Did you come to pay respects?\p"
    .string "Bless your Pokémon-loving heart.$"

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
    .string "Pokémon Tower was erected in the\n"
    .string "memory of Pokémon that died.$"
