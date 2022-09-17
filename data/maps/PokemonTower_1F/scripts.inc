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
