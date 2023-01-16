SafariZone_North_MapScripts::
	.byte 0

SafariZone_North_EventScript_ItemQuickClaw::
	finditem ITEM_QUICK_CLAW, 1
	end

SafariZone_North_EventScript_ItemTM47::
	finditem ITEM_TM47, 1
	end

SafariZone_North_EventScript_ItemProtein::
	finditem ITEM_PROTEIN, 1
	end

SafariZone_North_EventScript_RestHouseSign::
	msgbox SafariZone_North_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_North_Text_RestHouse::
    .string "Rest House$"

SafariZone_North_EventScript_TrainerTips1::
	msgbox SafariZone_North_Text_SecretHouseStillAhead, MSGBOX_SIGN
	end

SafariZone_North_Text_SecretHouseStillAhead::
    .string "Trainer Tips\p"
    .string "The Secret House is still ahead.$"

SafariZone_North_EventScript_AreaSign::
	msgbox SafariZone_North_Text_Area2, MSGBOX_SIGN
	end

SafariZone_North_Text_Area2::
    .string "Area 2$"

SafariZone_North_EventScript_TrainerTips2::
	msgbox SafariZone_North_Text_ZigzagThroughTallGrass, MSGBOX_SIGN
	end

SafariZone_North_Text_ZigzagThroughTallGrass::
    .string "Trainer Tips:\p"
    .string "Pokémon hide in tall grass.\p"
    .string "Zigzag through grassy areas to\n"
    .string "flush them out.$"

SafariZone_North_EventScript_TrainerTips3::
	msgbox SafariZone_North_Text_WinFreeHMFindSecretHouse, MSGBOX_SIGN
	end

SafariZone_North_Text_WinFreeHMFindSecretHouse::
    .string "Trainer Tips\p"
    .string "Win a free HM for finding the\n"
    .string "Secret House.$"
