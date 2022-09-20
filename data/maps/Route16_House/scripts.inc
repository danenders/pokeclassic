Route16_House_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route16_House_EventScript_NoRoomForHM02
	playfanfare MUS_OBTAIN_TMHM
	message Route16_House_Text_ReceivedHM02FromGirl
	waitfanfare
	waitmessage
	closemessage 
	additem ITEM_HM02, 1
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_RECEIVED_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Pidgeot
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
    .string "Oh, dear.\n"
    .string "You've found my secret retreat.\p"
    .string "Please don't tell anyone I'm here.\n"
    .string "I'll make it up to you with this!$"

Route16_House_Text_ReceivedHM02FromGirl::
    .string "{PLAYER} received HM02\n"
    .string "from the girl.$"

Route16_House_Text_ExplainHM02::
    .string "HM02 is FLY.\n"
    .string "It's a wonderfully convenient move.\p"
    .string "Please, put it to good use.$"

Route16_House_Text_DontHaveAnyRoomForThis::
    .string "You don't have any room for this.$"

Route16_House_Text_Pidgeot::
    .string "Pidgeot: Kyueen!$"
