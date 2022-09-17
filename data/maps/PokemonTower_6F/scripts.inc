PokemonTower_6F_MapScripts::
	.byte 0

PokemonTower_6F_EventScript_ItemXAccuracy::
	finditem ITEM_X_ACCURACY, 1
	release
	end

PokemonTower_6F_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

PokemonTower_6F_EventScript_Angelica::
	trainerbattle_single TRAINER_CHANNELER_ANGELICA, PokemonTower_6F_Text_AngelicaIntro, PokemonTower_6F_Text_AngelicaDefeat
	msgbox PokemonTower_6F_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_AngelicaIntro::
    .string "Give…me…\n"
    .string "blood…$"

PokemonTower_6F_Text_AngelicaDefeat::
    .string "Groan!$"

PokemonTower_6F_Text_AngelicaPostBattle::
    .string "I feel anemic and weak…$"

PokemonTower_6F_EventScript_Emilia::
	trainerbattle_single TRAINER_CHANNELER_EMILIA, PokemonTower_6F_Text_EmiliaIntro, PokemonTower_6F_Text_EmiliaDefeat
	msgbox PokemonTower_6F_Text_EmiliaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_EmiliaIntro::
    .string "Urff…\n"
    .string "Kwaah!$"

PokemonTower_6F_Text_EmiliaDefeat::
    .string "Something fell out!$"

PokemonTower_6F_Text_EmiliaPostBattle::
    .string "My hair didn't fall out!\n"
    .string "It was a malevolent spirit!$"

PokemonTower_6F_EventScript_Jennifer::
	trainerbattle_single TRAINER_CHANNELER_JENNIFER, PokemonTower_6F_Text_JenniferIntro, PokemonTower_6F_Text_JenniferDefeat
	msgbox PokemonTower_6F_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_6F_Text_JenniferIntro::
    .string "Ke…ke…ke…\n"
    .string "ke…ke…ke!$"

PokemonTower_6F_Text_JenniferDefeat::
    .string "Keee!$"

PokemonTower_6F_Text_JenniferPostBattle::
    .string "What's going on here?$"


PokemonTower_6F_EventScript_MarowakGhost::
	@unused right now
	end

PokemonTower_6F_EventScript_DefeatedMarowakGhost::
	@unused right now
	end

PokemonTower_6F_Movement_ForcePlayerUp::
	walk_up
	step_end

PokemonTower_6F_Text_BeGoneIntruders::
    .string "Be gone…\n"
    .string "Intruders…$"

PokemonTower_6F_Text_GhostWasCubonesMother::
    .string "The ghost was the restless spirit\n"
    .string "of the Cubone's mother!$"

PokemonTower_6F_Text_MothersSpiritWasCalmed::
    .string "The mother's spirit was calmed.\p"
    .string "It departed to the afterlife…$"
