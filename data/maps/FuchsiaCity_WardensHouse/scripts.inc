FuchsiaCity_WardensHouse_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
    .string "Warden: Hif fuff hefifoo!\p"
    .string "Ha lof ha feef ee hafahi ho.\n"
    .string "Heff hee fwee!$"

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	checkplayergender
	msgbox FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden
	waitfanfare
	additem ITEM_HM04, 1
	setflag FLAG_RECEIVED_HM04
	removeitem ITEM_GOLD_TEETH, 1
	release
	end

FuchsiaCity_WardensHouse_Text_ThanksGiveYouSomething::
    .string "Warden: Thanks! \n"
    .string "You're a real lifesaver!\p"
    .string "No one could understand a word\n"
    .string "that I said, not a one!\p"
    .string "I was too ashamed to show my face\n"
    .string "around the Office, even.\p"
    .string "Let me give you something for your\n"
    .string "trouble.$"

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
    .string "Ah howhee ho hoo!\n"
    .string "Eef ee hafahi ho!$"

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
    .string "Ha?\n"
    .string "He ohay heh ha hoo ee haheh!$"

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_Text_ExplainStrength::
    .string "Warden: Inside HM04 you'll find\n"
    .string "Strength.\p"
    .string "It lets Pokémon move boulders when\n"
    .string "you're outside of battle.\p"
    .string "Oh yes, did you find the Secret\n"
    .string "House in the Safari Zone?$"

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
    .string "{PLAYER} gave the Gold Teeth\n"
    .string "to the Warden.$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
    .string "The Warden popped in his teeth!$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
    .string "{PLAYER} received HM04\n"
    .string "from the Warden.$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
    .string "Pokémon photos and fossils are on\n"
    .string "display.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
    .string "Old Pokémon merchandise is on\n"
    .string "display.$"

FuchsiaCity_WardensHouse_EventScript_PokemonJournalKoga::
	msgbox PokemonJournal_Text_SpecialFeatureKoga, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureKoga::
	.string "Pokémon Journal:\p"
	.string "Special Feature: Fuchsia Gym\n"
	.string "Leader Koga!\p"
	.string "Koga is said to have a thorough\n"
	.string "knowledge of medicine.\p"
	.string "He even concocts medicine to nurse\n"
	.string "his Pokémon to health.$"

FuchsiaCity_WardensHouse_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY, 1
	release
	end

