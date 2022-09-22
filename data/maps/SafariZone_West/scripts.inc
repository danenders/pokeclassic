SafariZone_West_MapScripts::
	.byte 0

SafariZone_West_EventScript_ItemTM32::
	finditem ITEM_TM32, 1
	release
	end

SafariZone_West_EventScript_ItemGoldTeeth::
	finditem ITEM_GOLD_TEETH, 1
	release
	end

SafariZone_West_EventScript_ItemMaxRevive::
	finditem ITEM_MAX_REVIVE, 1
	release
	end

SafariZone_West_EventScript_RestHouseSign::
	msgbox SafariZone_West_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_RestHouse::
    .string "Rest House$"

SafariZone_West_EventScript_LostTeethNotice::
	msgbox SafariZone_West_Text_PleaseFindWardensLostTeeth, MSGBOX_SIGN
	end

SafariZone_West_Text_PleaseFindWardensLostTeeth::
    .string "Request Notice\p"
    .string "Please find the Safari Warden's\n"
    .string "lost Gold Teeth.\l"
    .string "They're around here somewhere.\p"
    .string "Reward offered!\n"
    .string "Contact: Warden$"

SafariZone_West_EventScript_TrainerTips::
	msgbox SafariZone_West_Text_SearchForSecretHouse, MSGBOX_SIGN
	end

SafariZone_West_Text_SearchForSecretHouse::
    .string "Trainer Tips:\p"
    .string "Zone Exploration Campaign!\n"
    .string "The Search for the Secret House!$"

SafariZone_West_EventScript_AreaSign::
	msgbox SafariZone_West_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_West_Text_AreaSign::
    .string "Area 3\n"
    .string "East: Center Area$"
