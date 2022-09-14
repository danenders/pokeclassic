.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_1F_OnTransition
	.byte 0

VermilionCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

VermilionCity_PokemonCenter_1F_EventScript_Man::
	msgbox VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_PoisonedMonFaintedWhileWalking::
    .string "My Pokémon was poisoned!\n"
    .string "It fainted while we were walking!$"

VermilionCity_PokemonCenter_1F_EventScript_Hiker::
	msgbox VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_TrainerMonsStrongerThanWild::
    .string "Even if they are the same level,\n"
    .string "Pokémon can have very different\l"
    .string "stats and abilities.\p"
    .string "A Pokémon raised by a trainer is\n"
    .string "stronger than one in the wild.$"

VermilionCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes, MSGBOX_NPC
	end

VermilionCity_PokemonCenter_1F_Text_AllMonWeakToSpecificTypes::
    .string "It is true that a higher-level\n"
    .string "Pokémon will be more powerful…\p"
    .string "But, all Pokémon will have weak\n"
    .string "points against specific types.\p"
    .string "So, there appears to be no\n"
    .string "universally strong Pokémon.$"

VermilionCity_PokemonCenter_1F_EventScript_RematchWoman::
	msgbox VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain, MSGBOX_NPC
	release
	end

VermilionCity_PokemonCenter_1F_Text_UrgeToBattleSomeoneAgain::
    .string "The urge to battle with someone\n"
    .string "you've tangled with before…\p"
    .string "Have you ever had that urge?\n"
    .string "I'm sure you have.\p"
    .string "I wanted to battle certain people\n"
    .string "again over and over, too.\p"
    .string "I should give some trainers a call\n"
    .string "on my Cell Phone!$"
