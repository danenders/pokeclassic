LavenderTown_House2_MapScripts::
	.byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	msgbox LavenderTown_House2_Text_WantMeToRateNicknames, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseMon
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_lt LavenderTown_House2_EventScript_CheckCanRateMon
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	msgbox LavenderTown_House2_Text_ISeeComeVisitAgain
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, IsMonOTNameNotPlayers
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavenderTown_House2_EventScript_ChooseNewNickname
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call Common_EventScript_ChangePokemonNickname
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_Text_WantMeToRateNicknames::
    .string "Hello, hello!\n"
    .string "I am the official Name Rater!\p"
    .string "Want me to rate the nicknames of\n"
    .string "your Pokémon?$"

LavenderTown_House2_Text_CritiqueWhichMonsNickname::
    .string "Which Pokémon's nickname should\n"
    .string "I critique?$"

LavenderTown_House2_Text_GiveItANicerName::
    .string "{STR_VAR_1}, is it?\n"
    .string "That is a decent nickname!\p"
    .string "But, would you like me to give it\n"
    .string "a nicer name?\p"
    .string "How about it?$"

LavenderTown_House2_Text_WhatShallNewNicknameBe::
    .string "Ah, good. Then, what shall the new\n"
    .string "nickname be?$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsName::
    .string "Done! From now on, this Pokémon\n"
    .string "shall be known as {STR_VAR_1}!\p"
    .string "It is a better name than before!\n"
    .string "How fortunate for you!$"

LavenderTown_House2_Text_ISeeComeVisitAgain::
    .string "I see.\n"
    .string "Do come visit again.$"

LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName::
    .string "Done! From now on, this Pokémon\n"
    .string "shall be known as {STR_VAR_1}!\p"
    .string "It looks no different from before,\n"
    .string "and yet, this is vastly superior!\p"
    .string "How fortunate for you!$"

LavenderTown_House2_Text_TrulyImpeccableName::
    .string "{STR_VAR_1}, is it?\n"
    .string "That is a truly impeccable name!\p"
    .string "Take good care of {STR_VAR_1}!$"

LavenderTown_House2_Text_ThatIsMerelyAnEgg::
    .string "Now, now.\n"
    .string "That is merely an egg!$"

