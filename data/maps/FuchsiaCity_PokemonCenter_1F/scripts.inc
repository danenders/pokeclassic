.set LOCALID_NURSE, 1

FuchsiaCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
    .string "You can't become a good Trainer\n"
    .string "with just one strong Pokémon.\p"
    .string "But raising many Pokémon evenly\n"
    .string "is no easy task, either.$"

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
    .string "There's a narrow trail west of\n"
    .string "Viridian City.\p"
    .string "It goes to the Pokémon League HQ.\n"
    .string "The HQ governs all Trainers.$"

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
    .string "If you're working on a PokéDex,\n"
    .string "visit the Safari Zone.\p"
    .string "All sorts of rare Pokémon breed\n"
    .string "there.$"
