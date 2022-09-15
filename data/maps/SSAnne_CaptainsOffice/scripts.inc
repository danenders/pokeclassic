.set LOCALID_CAPTAIN, 1

SSAnne_CaptainsOffice_MapScripts::
	.byte 0

SSAnne_CaptainsOffice_EventScript_Captain::
	lock
	goto_if_set FLAG_RECEIVED_HM01, SSAnne_CaptainsOffice_EventScript_AlreadyGotCut
	msgbox SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick
	message SSAnne_CaptainsOffice_Text_RubbedCaptainsBack
	waitmessage
	playfanfare MUS_HEAL
	waitfanfare
	delay 50
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	checkitemspace ITEM_HM01, 1
	goto_if_eq VAR_RESULT, FALSE, SSAnne_CaptainsOffice_EventScript_NoRoomForCut
	msgbox SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut
	playfanfare MUS_OBTAIN_TMHM
	message SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain
	waitfanfare
	waitmessage
	additem ITEM_HM01, 1
	msgbox SSAnne_CaptainsOffice_Text_ExplainCut
	setflag FLAG_RECEIVED_HM01
	setvar VAR_SS_ANNE_STATE, 2
	release
	end

SSAnne_CaptainsOffice_Text_CaptainIFeelSeasick::
    .string "Captain: Ooargh…\n"
    .string "I feel hideous…\l"
    .string "Urrp! Seasick…$"

SSAnne_CaptainsOffice_Text_RubbedCaptainsBack::
    .string "{PLAYER} rubbed the Captain's\n"
    .string "back!\p"
    .string "Rub-rub…\n"
    .string "Rub-rub-rub…$"

SSAnne_CaptainsOffice_Text_ThankYouHaveHMForCut::
    .string "Captain: Whew! Thank you!\n"
    .string "I'm feeling much better now.\p"
    .string "You want to see my hidden cut\n"
    .string "technique?\p"
    .string "I could show you my prized cut\n"
    .string "technique if I weren't so ill…\p"
    .string "I know! You can have this!\n"
    .string "This Hidden Machine!\p"
    .string "Teach cut to your Pokémon, and\n"
    .string "you can see it cut anytime!$"

SSAnne_CaptainsOffice_Text_ObtainedHM01FromCaptain::
    .string "{PLAYER} obtained HM01\n"
    .string "from the Captain!$"

SSAnne_CaptainsOffice_Text_ExplainCut::
    .string "Using cut, you can chop down\n"
    .string "small trees.\p"
    .string "Why not try it with the trees\n"
    .string "around Vermilion City?$"

SSAnne_CaptainsOffice_EventScript_NoRoomForCut::
	msgbox SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis
	closemessage
	applymovement LOCALID_CAPTAIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SSAnne_CaptainsOffice_Text_YouHaveNoRoomForThis::
    .string "Oh, no!\n"
    .string "You have no room for this!\p"
    .string "Oh no, I feel another wave\n"
    .string "coming on --- HURGH!!$"

SSAnne_CaptainsOffice_EventScript_AlreadyGotCut::
	applymovement LOCALID_CAPTAIN, Common_Movement_FacePlayer
	waitmovement 1
	msgbox SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon
	release
	end

SSAnne_CaptainsOffice_Text_SSAnneWillSetSailSoon::
    .string "Captain: …Whew!\p"
    .string "Now that I'm not sick anymore,\n"
    .string "I guess it's time.\p"
    .string "The S.S. Anne will set sail soon!\p"
    .string "Farewell, until our return to\n"
    .string "Vermilion City!$"

SSAnne_CaptainsOffice_EventScript_TrashCan::
	msgbox SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_YuckShouldntHaveLooked::
    .string "Yuck!\n"
    .string "Shouldn't have looked!$"

SSAnne_CaptainsOffice_EventScript_Book::
	msgbox SSAnne_CaptainsOffice_Text_HowToConquerSeasickness, MSGBOX_SIGN
	end

SSAnne_CaptainsOffice_Text_HowToConquerSeasickness::
    .string "How to Conquer Seasickness…\n"
    .string "The Captain's reading this!$"
