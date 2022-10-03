.set LOCALID_NURSE, 1

IndigoPlateau_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_PokemonCenter_1F_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU
	end

IndigoPlateau_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

IndigoPlateau_PokemonCenter_1F_EventScript_GymGuy::
	msgbox IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice, MSGBOX_NPC
	end

IndigoPlateau_PokemonCenter_1F_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "At the Pokémon League, you will\n"
    .string "face the Elite Four all in a row.\p"
    .string "If you lose, you have to start all\n"
    .string "over again!\p"
    .string "This is it!\n"
    .string "Go for it!$"

IndigoPlateau_PokemonCenter_1F_EventScript_DoorGuard::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_FaceEliteFourGoodLuck::
    .string "From here on, you face the\n"
    .string "Elite Four one by one.\p"
    .string "If you win, a door opens to the\n"
    .string "next trainer. Good luck!$"

IndigoPlateau_PokemonCenter_1F_EventScript_BlackBelt::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_AgathaWhuppedUs::
    .string "Agatha's Ghost type Pokémon are\n"
    .string "horrifically terrifying in toughness.\p"
    .string "I took my Fighting type Pokémon\n"
    .string "and raised them to the max.\p"
    .string "I went at Agatha feeling pretty\n"
    .string "confident, but she whupped us.\p"
    .string "That old lady's also got a really\n"
    .string "short fuse, too.\p"
    .string "It doesn't take anything to get\n"
    .string "that scary lady hollering.$"

IndigoPlateau_PokemonCenter_1F_EventScript_CooltrainerM::
    lock
    faceplayer
    msgbox IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway
    release
    end

IndigoPlateau_PokemonCenter_1F_Text_LancesCousinGymLeaderFarAway::
    .string "Maybe becoming an Elite Four\n"
    .string "member is in the blood.\p"
    .string "From what I've heard, Lance has\n"
    .string "a cousin who's a Gym Leader\l"
    .string "somewhere far away.$"

IndigoPlateau_PokemonCenter_1F_EventScript_PokemonJournal::
	lock
	faceplayer
	msgbox PokemonJournal_Text_SpecialFeatureLance
	release
	end

PokemonJournal_Text_SpecialFeatureLance::
	.string "Pokémon Journal\p"
	.string "Special Feature:\n"
	.string "Elite Four's Lance!\p"
	.string "Lance's grandfather is thought to\n"
	.string "be the elder of a famous clan of\l"
	.string "dragon masters.$"

IndigoPlateau_PokemonCenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IndigoPlateau_PokemonCenter_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
IndigoPlateau_PokemonCenter_1F_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end
