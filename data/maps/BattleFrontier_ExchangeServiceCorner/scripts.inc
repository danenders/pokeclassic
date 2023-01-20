BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_ABILITY_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_ABILITY_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_AbilityPatch
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityCapsule::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_ABILITY_CAPSULE
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityCapsule:
	.string "You've chosen the Ability Capsule.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_AbilityPatch::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityPatch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseAbilityItem
	setvar VAR_0x8008, 200
	setvar VAR_0x8009, ITEM_ABILITY_PATCH
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAbilityPatch:
	.string "You've chosen the Ability Patch.\n"
	.string "Is that correct?$"


BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Protein
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_Calcium
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_Iron
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_Zinc
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Carbos
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_HPUp
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Protein::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Calcium::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Iron::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Zinc::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Carbos::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPUp::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the Exchange Service\n"
	.string "Corner.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "You've chosen the Protein.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "You've chosen the Calcium.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "You've chosen the Iron.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "You've chosen the Zinc.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "You've chosen the Carbos.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "You've chosen the HP Up.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the Brightpowder.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the White Herb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the Quick Claw.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the Mental Herb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the Choice Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the King's Rock.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the Focus Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the Scope Lens.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the Leftovers.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my Pokémon will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the Battle facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Raises the stat Attack of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Raises the stat Sp. Atk of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Raises the stat Defense of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Raises the stat Sp. Def of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Raises the stat Speed of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Raises the HP of one Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps Pokémon out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_Text_AbilityCapsuleDesc::
	.string "Switches a Pokémon's ability.$"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_Text_AbilityPatchDesc::
	.string "Turns the ability of a Pokémon into\n"
	.string "a rare ability.$"

BattleFrontier_ExchangeServiceCorner_EventScript_MintLady::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	end

BattleFrontier_ExchangeServiceCorner_EventScript_MintLady2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_MINT_LADY_2
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_MINT_LADY
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint
	case 11, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_LonelyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_LONELY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLonelyMint:
	.string "You've chosen the Lonely Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_LaxMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_LAX_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaxMint:
	.string "You've chosen the Lax Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_JollyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_JOLLY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmJollyMint:
	.string "You've chosen the Jolly Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ImpishMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_IMPISH_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmImpishMint:
	.string "You've chosen the Impish Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_HastyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_HASTY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHastyMint:
	.string "You've chosen the Hasty Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_AdamantMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_ADAMANT_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmAdamantMint:
	.string "You've chosen the Adamant Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_BoldMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_BOLD_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBoldMint:
	.string "You've chosen the Bold Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_BraveMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_BRAVE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBraveMint:
	.string "You've chosen the Brave Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_CalmMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_CALM_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalmMint:
	.string "You've chosen the Calm Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_CarefulMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_CAREFUL_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarefulMint:
	.string "You've chosen the Careful Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_GentleMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_GENTLE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmGentleMint:
	.string "You've chosen the Gentle Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_MINT_LADY_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_MildMint
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_RashMint
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint
	case 10, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_TimidMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_TIMID_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTimidMint:
	.string "You've chosen the Timid Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SeriousMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_SERIOUS_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSeriousMint:
	.string "You've chosen the Serious Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SassyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_SASSY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSassyMint:
	.string "You've chosen the Sassy Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RelaxedMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_RELAXED_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRelaxedMint:
	.string "You've chosen the Relaxed Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RashMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_RASH_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRashMint:
	.string "You've chosen the Rash Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_QuietMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_QUIET_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuietMint:
	.string "You've chosen the Quiet Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_NaughtyMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_NAUGHTY_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaughtyMint:
	.string "You've chosen the Naughty Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_NaiveMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_NAIVE_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmNaiveMint:
	.string "You've chosen the Naive Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ModestMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_MODEST_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmModestMint:
	.string "You've chosen the Modest Mint.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MildMint::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseMint2
	setvar VAR_0x8008, 50
	setvar VAR_0x8009, ITEM_MILD_MINT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMildMint:
	.string "You've chosen the Mild Mint.\n"
	.string "Is that correct?$"



BattleFrontier_ExchangeServiceCorner_Text_AdamantMintDesc::
 	.string "Loved by Pokémon!\n"
    .string "This mint has an Adamant flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_BoldMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Bold flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_BraveMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Brave flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_CalmMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Calm flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_CarefulMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Careful flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_GentleMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Gentle flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_HastyMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Hasty flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_ImpishMintDesc::
	.string "Loved by Pokémon!\n"
    .string  "This mint has an Impish flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_JollyMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Jolly flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_LaxMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Lax flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_LonelyMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Lonely flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_MildMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Mild flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_ModestMintDesc::
    .string "Loved by Pokémon!\n"
    .string "This mint has a Modest flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_NaiveMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Naive flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_NaughtyMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Naughty flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_QuietMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Quiet flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_RashMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Rash flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_RelaxedMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Relaxed flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_SassyMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Sassy flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_SeriousMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Serious flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_TimidMintDesc::
	.string "Loved by Pokémon!\n"
    .string "This mint has a Timid flavor.$"

BattleFrontier_ExchangeServiceCorner_Text_RazorFang::
    .string "A hold item that may cause\n"
    .string "flinching when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_RazorClaw::
    .string "A hooked claw that ups the\n"
    .string "holder's critical-hit ratio.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceSpecs::
    .string "Boosts Sp. Atk, but allows\n"
    .string "the use of only one move.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceScarf::
    .string "Boosts Speed, but allows\n"
    .string "the use of only one move.$"

BattleFrontier_ExchangeServiceCorner_Text_MuscleBand::
    .string "A headband that boosts\n"
    .string "the power of physical moves.$"

BattleFrontier_ExchangeServiceCorner_Text_LifeOrb::
    .string "Boosts the power of moves at\n"
    .string "the cost of some HP per turn.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerHerb::
    .string "Allows immediate use of\n"
    .string "a move that charges first.$"

BattleFrontier_ExchangeServiceCorner_Text_WiseGlasses::
    .string "A pair of glasses that ups\n"
    .string "the power of special moves.$"

BattleFrontier_ExchangeServiceCorner_Text_RedCard::
    .string "Switches out the foe\n"
    .string "if they hit the holder.$"


BattleFrontier_ExchangeServiceCorner_Text_PowerAnklet::
    .string "A hold item that promotes\n"
    .string "Spd gain, but reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBracer::
    .string "A hold item that promotes\n"
    .string "Atk gain, but reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBelt::
    .string "A hold item that promotes\n"
    .string "Def gain, but reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerBand::
    .string "A hold item that promotes\n"
    .string "Sp. Def gain, but reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerWeight::
    .string "A hold item that promotes\n"
    .string "HP gain, but reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_Text_PowerLens::
    .string "A hold item that promotes\n"
    .string "Sp. Atk gain, reduces Speed.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK_2
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	end

BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_RazorClaw
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_MuscleBand
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_PowerHerb
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_WiseGlasses
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_RedCard
	case 9, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RazorFang::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorFang, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_FANG
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorFang:
	.string "You've chosen the Razor Fang.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RazorClaw::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_RAZOR_CLAW
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRazorClaw:
	.string "You've chosen the Razor Claw.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceSpecs::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_CHOICE_SPECS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceSpecs:
	.string "You've chosen the ChoiceSpecs.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ChoiceScarf::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceScarf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_CHOICE_SCARF
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceScarf:
	.string "You've chosen the Choice Scarf.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MuscleBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_MUSCLE_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMuscleBand:
	.string "You've chosen the Muscle Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_LifeOrb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmLifeOrb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LIFE_ORB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLifeOrb:
	.string "You've chosen the Life Orb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerHerb::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, ITEM_POWER_HERB
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerHerb:
	.string "You've chosen the Power Herb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_WiseGlasses::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmWiseGlasses, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WISE_GLASSES
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWiseGlasses:
	.string "You've chosen the Wise Glasses.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RedCard::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRedCard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseHoldItem2
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_RED_CARD
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRedCard:
	.string "You've chosen the Red Card.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_POWER_ITEM_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	end


BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_POWER_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_PowerAnklet
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBracer
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBelt
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_PowerBand
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_PowerWeight
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_PowerLens
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PowerAnklet::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerAnklet, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_ANKLET
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerAnklet:
	.string "You've chosen the Power Anklet.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBracer::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBracer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BRACER
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBracer:
	.string "You've chosen the Power Bracer.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBelt::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBelt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BELT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBelt:
	.string "You've chosen the Power Belt.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerBand::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_BAND
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerBand:
	.string "You've chosen the Power Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerWeight::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerWeight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_WEIGHT
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerWeight:
	.string "You've chosen the Power Weight.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_PowerLens::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChoosePowerItem
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, ITEM_POWER_LENS
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmPowerLens:
	.string "You've chosen the Power Lens.\n"
	.string "Is that correct?$"


BattleFrontier_ExchangeServiceCorner_EventScript_CandyClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_CANDY_CLERK
	call BattleFrontier_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	end


BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_CANDY_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, BattleFrontier_ExchangeServiceCorner_EventScript_HPCandy
	case 1, BattleFrontier_ExchangeServiceCorner_EventScript_ATKCandy
	case 2, BattleFrontier_ExchangeServiceCorner_EventScript_DEFCandy
	case 3, BattleFrontier_ExchangeServiceCorner_EventScript_SPATKCandy
	case 4, BattleFrontier_ExchangeServiceCorner_EventScript_SPDEFCandy
	case 5, BattleFrontier_ExchangeServiceCorner_EventScript_SPEEDCandy
	case 6, BattleFrontier_ExchangeServiceCorner_EventScript_MAXCandy
	case 7, BattleFrontier_ExchangeServiceCorner_EventScript_RESETCandy
	case 8, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, BattleFrontier_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

BattleFrontier_ExchangeServiceCorner_EventScript_HPCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_HP_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPCandy:
	.string "You've chosen the HP Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_ATKCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmATKCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_ATK_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmATKCandy:
	.string "You've chosen the Atk Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_DEFCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmDEFCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_DEF_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDEFCandy:
	.string "You've chosen the Def Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPATKCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPATKCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPATK_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPATKCandy:
	.string "You've chosen the Sp.Atk Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPDEFCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPDEFCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPDEF_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPDEFCandy:
	.string "You've chosen the Sp.Def Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_SPEEDCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPEEDCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 24
	setvar VAR_0x8009, ITEM_SPEED_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSPEEDCandy:
	.string "You've chosen the Speed Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_MAXCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmMAXCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_MAX_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMAXCandy:
	.string "You've chosen the Max Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_EventScript_RESETCandy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ConfirmRESETCandy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_ExchangeServiceCorner_EventScript_ChooseCandy
	setvar VAR_0x8008, 8
	setvar VAR_0x8009, ITEM_RESET_CANDY
	goto BattleFrontier_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

BattleFrontier_ExchangeServiceCorner_Text_ConfirmRESETCandy:
	.string "You've chosen the Reset Candy.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_HPCandy::
    .string "Raises a Pokémon'score HP stat.$"

BattleFrontier_ExchangeServiceCorner_Text_ATKCandy::
    .string "Raises a Pokémon's core Attack stat.$"

BattleFrontier_ExchangeServiceCorner_Text_DEFCandy::
    .string "Raises a Pokémon's core Defense stat.$"

BattleFrontier_ExchangeServiceCorner_Text_SPATKCandy::
   .string  "Raises a Pokémon's core Sp. Attack stat.$"

BattleFrontier_ExchangeServiceCorner_Text_SPDEFCandy::
    .string "Raises a Pokémon's core Sp. Defense stat.$"

BattleFrontier_ExchangeServiceCorner_Text_SPEEDCandy::
   .string  "Raises a Pokémon's core Speed stat.$"

BattleFrontier_ExchangeServiceCorner_Text_MAXCandy::
    .string "Maximizes a Pokémon's core stats.$"

BattleFrontier_ExchangeServiceCorner_Text_RESETCandy::
    .string "Neutralizes a Pokémon's core stats.$"
