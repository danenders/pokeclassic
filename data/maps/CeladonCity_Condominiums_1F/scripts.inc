CeladonCity_Condominiums_1F_MapScripts::
	.byte 0

CeladonCity_Condominiums_1F_EventScript_TeaWoman::
	lock
	faceplayer
	goto_if_set FLAG_TALKED_TO_TEA_LADY_POSTGAME, CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy
	goto_if_set FLAG_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea
	msgbox CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead
	setflag FLAG_GOT_TEA
	giveitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea
	release
	end

CeladonCity_Condominiums_1F_Text_TryThisDrinkInstead::
    .string "You shouldn't spend all your money\n"
    .string "on drinks.\p"
    .string "Try this instead.$"

CeladonCity_Condominiums_1F_Text_NothingBeatsThirstLikeTea::
    .string "Nothing beats thirst like some hot\n"
    .string "Tea.\p"
    .string "It really is the best.$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanAfterTea::
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany::
    .string "My dear Pokémon keep me company.\n"
    .string "Meowth even brings money home!$"

CeladonCity_Condominiums_1F_EventScript_TeaWomanMentionDaisy::
	setflag FLAG_TALKED_TO_TEA_LADY_POSTGAME
	msgbox CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea
	release
	end

CeladonCity_Condominiums_1F_EventScript_PostgameTeaWoman::
	call_if_unset FLAG_DAILY_GOT_TEA, CeladonCity_Condominiums_1F_EventScript_GetDailyTea
	msgbox CeladonCity_Condominiums_1F_Text_MyDearMonsKeepMeCompany
	release
	end

CeladonCity_Condominiums_1F_EventScript_GetDailyTea::
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_Return
	msgbox CeladonCity_Condominiums_1F_Text_TakeThisDear
	release
	setflag FLAG_DAILY_GOT_TEA
	giveitem ITEM_TEA
	return

CeladonCity_Condominiums_1F_Text_TakeThisDear::
	.string "Come for some Tea, dear?"

CeladonCity_Condominiums_1F_Text_DaisyComesToBuyTea::
    .string "Oh, hello, dearie.\n"
    .string "Did you enjoy my Tea?\p"
    .string "By the way, dear. Are you, by any\n"
    .string "chance, from Pallet Town?\p"
    .string "A girl from Pallet Town, Daisy,\n"
    .string "she enjoys my Tea every day.\p"
    .string "If you ever want some tea,\n"
    .string "just come visit me.$"

CeladonCity_Condominiums_1F_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Meowth
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Meowth::
    .string "Meowth: Meow!$"

CeladonCity_Condominiums_1F_EventScript_Clefairy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Clefairy
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Clefairy::
    .string "Clefairy: Pi pippippi!$"

CeladonCity_Condominiums_1F_EventScript_Nidoran::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORAN_F, CRY_MODE_NORMAL
	msgbox CeladonCity_Condominiums_1F_Text_Nidoran
	waitmoncry
	release
	end

CeladonCity_Condominiums_1F_Text_Nidoran::
    .string "Nidoran♀: Kya kyaoo!$"

CeladonCity_Condominiums_1F_EventScript_SuiteSign::
	msgbox CeladonCity_Condominiums_1F_Text_ManagersSuite, MSGBOX_SIGN
	end

CeladonCity_Condominiums_1F_Text_ManagersSuite::
    .string "Celadon Mansion\n"
    .string "Manager's Suite$"
