SafariZone_East_MapScripts::
	.byte 0

SafariZone_East_EventScript_RestHouseSign::
	msgbox SafariZone_East_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_East_Text_RestHouse::
    .string "Rest House$"

SafariZone_East_EventScript_TrainerTips::
	msgbox SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk, MSGBOX_SIGN
	end

SafariZone_East_Text_TimeDeclinesOnlyWhileYouWalk::
    .string "Trainer Tips:\p"
    .string "The remaining time declines only\n"
    .string "while you walk.$"

SafariZone_East_EventScript_AreaSign::
	msgbox SafariZone_East_Text_AreaSign, MSGBOX_SIGN
	end

SafariZone_East_Text_AreaSign::
    .string "Area 1\n"
    .string "West: Center Area$"

SafariZone_East_EventScript_ItemMaxPotion::
	finditem ITEM_MAX_POTION, 1
	release
	end

SafariZone_East_EventScript_ItemFullRestore::
	finditem ITEM_FULL_RESTORE, 1
	release
	end

SafariZone_East_EventScript_ItemLeafStone::
	finditem ITEM_LEAF_STONE, 1
	release
	end

SafariZone_East_EventScript_ItemTM11::
	finditem ITEM_TM11, 1
	release
	end

SafariZone_East_EventScript_Kangaskhanite::
	finditem ITEM_KANGASKHANITE, 1
	release
	end
