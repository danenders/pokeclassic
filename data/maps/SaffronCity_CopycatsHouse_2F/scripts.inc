SaffronCity_CopycatsHouse_2F_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_Text_Doduo::
    .string "Doduo: Giiih!\p"
    .string "Pretty mirror look at me,\n"
    .string "see how pretty I can be?$"

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
    .string "This is a rare Pokémon!\n"
    .string "Huh? It's only a doll!$"

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL, 1
	goto_if_eq VAR_RESULT, TRUE, MoveTutor_Mimic
	random 2
	call_if_eq VAR_RESULT, 0, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, 1, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
    .string "{PLAYER}: Hi!\n"
    .string "Do you like Pokémon?\p"
    .string "{PLAYER}: Uh, no, I just asked you.\p"
    .string "{PLAYER}: Huh?\n"
    .string "You're strange!\p"
    .string "Copycat: Hmm? Quit mimicking?\n"
    .string "But, that's my favorite hobby!$"

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
    .string "{PLAYER}: Hi.\n"
    .string "You must like Pokémon.\p"
    .string "{PLAYER}: No, not me.\n"
    .string "I asked you.\p"
    .string "{PLAYER}: Pardon?\n"
    .string "You're weird!\l"
    .string " \l"
    .string "Copycat: Hmm? Quit mimicking?\l"
    .string "But that's my favorite hobby!$"

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
    .string "…\p"
    .string "My Secrets!\p"
    .string "Skill: Mimicry!\n"
    .string "Hobby: Collecting dolls!\l"
    .string "Favorite Pokémon: Clefairy!$"

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
    .string "A game with Mario wearing a bucket\n"
    .string "on his head!$"
