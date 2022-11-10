.set LOCALID_DAYCARE_MAN, 1
.set LOCALID_VOLUNTEER, 2

Route5_PokemonDayCare_MapScripts::
	.byte 0

Route5_PokemonDayCare_EventScript_Clefairy::
	playmoncry SPECIES_CLEFAIRY, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_Clefairy, MSGBOX_NPC
	waitmoncry
	release
	end

Route5_PokemonDayCare_Text_Clefairy::
    .string "Clefairy: Fiififiii!$"

Route5_PokemonDayCare_EventScript_DaycareEmployee::
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_PokemonDayCare_EventScript_EggWaitingPartner
	msgbox Route5_PokemonDayCare_Text_Volunteers, MSGBOX_NPC
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_Volunteers::
	.string "The owner of this Day Care used\n"
	.string "to do it all on his own, but\l"
	.string "he lets us volunteer here to\l"
	.string "spend time with Pokémon!$"

Route5_PokemonDayCare_EventScript_EggWaitingPartner::
	msgbox Route5_PokemonDayCare_Text_PartnerWasLookingForYou, MSGBOX_DEFAULT
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_PartnerWasLookingForYou:
	.string "Oh! My partner was looking for you\n"
	.string "out front!$"


Route5_PokemonDayCare_EventScript_EmployeesOnly::
	turnobject LOCALID_VOLUNTEER, DIR_EAST
	playse SE_PIN
	applymovement LOCALID_VOLUNTEER, Common_Movement_ExclamationMark
	msgbox Route5_PokemonDayCare_Text_EmployeesOnly, MSGBOX_NPC
	applymovement OBJ_EVENT_ID_PLAYER, Movement_StepBack
	waitmovement 0
	turnobject LOCALID_VOLUNTEER, DIR_NORTH
	release
	end

Route5_PokemonDayCare_Text_EmployeesOnly::
	.string "Excuse me!\p"
	.string "Only employees are allowed to\n"
	.string "go back there.$"

Movement_StepBack:
	walk_down
	step_end

Route5_PokemonDayCare_EventScript_DaycareMan::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route5_PokemonDayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route5_PokemonDayCare_EventScript_TwoMonsInDaycare
	msgbox Route5_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route5_PokemonDayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_EventScript_EggWaiting::
	msgbox Route5_PokemonDayCare_Text_SomeoneWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_SomeoneWasLookingForYou:
	.string "Oh! It's you!\p"
	.string "The volunteer out front wanted to\n"
	.string "speak with you!$"

Route5_PokemonDayCare_EventScript_OneMonInDaycare::
	msgbox Route5_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained
	msgbox Route5_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	msgbox Route5_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_GoodToSeeYou:
	.string "Ah, it's you! Good to see you.\n"
	.string "Your Pokémon are doing good!$"

Route5_PokemonDayCare_Text_TakeYourMonBack:
	.string "Did you want to take one of\n"
	.string "your Pokémon back?$"

Route5_PokemonDayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_YourMonHasGrownXLevels
	return

Route5_PokemonDayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route5_PokemonDayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route5_PokemonDayCare_Text_YourMonHasGrownXLevels:
	.string "So far, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2} levels.$"

Route5_PokemonDayCare_EventScript_DisplayLevelsGained2::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_YourOtherMonHasGrownXLevels
	return

Route5_PokemonDayCare_EventScript_YourOtherMonHasGrownXLevels::
	msgbox Route5_PokemonDayCare_Text_YourOtherMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route5_PokemonDayCare_Text_YourOtherMonHasGrownXLevels:
	.string "And your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2} levels.$"

Route5_PokemonDayCare_Text_WeCanRaiseOneMore:
	.string "Did you know that we can raise two\n"
	.string "of your Pokémon?\p"
	.string "Would you like us to raise one more?$"

Route5_PokemonDayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route5_PokemonDayCare_EventScript_OnlyTwoAliveMons
	msgbox Route5_PokemonDayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route5_PokemonDayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
  	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_CanRaiseOneMore
	release
	end

Route5_PokemonDayCare_Text_WhichMonShouldWeRaise:
	.string "Which Pokémon should we raise for\n"
	.string "you?$"

Route5_PokemonDayCare_Text_WellRaiseYourMon:
	.string "Great! We'll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Don't forget to come back for it!$"

Route5_PokemonDayCare_EventScript_OnlyOneMon::
	msgbox Route5_PokemonDayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YouHaveJustOneMon:
	.string "Oh? But you have just one\n"
	.string "Pokémon.\p"
	.string "I couldn't leave you alone!\n"
	.string "Come back another time.$"

Route5_PokemonDayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route5_PokemonDayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YoullBeLeftWithJustOne:
	.string "If you leave that Pokémon with\n"
	.string "me, you'll be left with just one.\p"
	.string "If you want my advice, you should\n"
	.string "try to catch some more.$"

Route5_PokemonDayCare_EventScript_ComeAgain::
	msgbox Route5_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_ComeAgain:
	.string "Come again.$"

Route5_PokemonDayCare_EventScript_OnlyOneAliveMon::
	msgbox Route5_PokemonDayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_WhatWillYouBattleWith:
	.string "Oh! If you leave me that Pokémon,\n"
	.string "what will you battle with?\p"
	.string "You should come back another time!$"

Route5_PokemonDayCare_EventScript_CanRaiseOneMore::
	msgbox Route5_PokemonDayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_GiveMonToRaise
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_EventScript_TryRetrieveMon::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route5_PokemonDayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route5_PokemonDayCare_EventScript_ComeAgain
	goto Route5_PokemonDayCare_EventScript_CostPrompt
	end

Route5_PokemonDayCare_EventScript_NoRoom::
	msgbox Route5_PokemonDayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_YourTeamIsFull:
	.string "Oh! Your Pokémon team is full.\n"
	.string "Come see me when you have room.$"

Route5_PokemonDayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route5_PokemonDayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_CheckEnoughMoney
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_ItWillCostX:
	.string "We took good care of {STR_VAR_1},\n"
	.string "so it will cost ¥{STR_VAR_2}.$"

Route5_PokemonDayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_RetrieveMon
	msgbox Route5_PokemonDayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_EventScript_RetrieveMon::
	call_if_eq VAR_FACING, DIR_SOUTH, Route5_PokemonDayCare_EventScript_GoRetrieveMonAlt
	call_if_ne VAR_FACING, DIR_SOUTH, Route5_PokemonDayCare_EventScript_GoRetrieveMon
	waitmovement 0
	faceplayer
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route5_PokemonDayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route5_PokemonDayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route5_PokemonDayCare_EventScript_AskRetrieveOtherMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_EventScript_GoRetrieveMon::
	applymovement LOCALID_DAYCARE_MAN, Route5_PokemonDayCare_Movement_RetrieveDaycareMon
	return

Route5_PokemonDayCare_EventScript_GoRetrieveMonAlt::
	applymovement LOCALID_DAYCARE_MAN, Route5_PokemonDayCare_Movement_RetrieveDaycareMonAlt
	return

Route5_PokemonDayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_up
	walk_up
	walk_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_down
	walk_down
	walk_down
	step_end

Route5_PokemonDayCare_Movement_RetrieveDaycareMonAlt:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_down
	walk_left
	walk_down
	walk_down
	walk_right
	step_end

Route5_PokemonDayCare_Text_HeresYourMon:
	.string "Perfect!\n"
	.string "Here's your Pokémon.$"

Route5_PokemonDayCare_Text_TookBackMon:
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the Day Care.$"

Route5_PokemonDayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route5_PokemonDayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	goto Route5_PokemonDayCare_EventScript_ComeAgain
	end

Route5_PokemonDayCare_Text_TakeOtherOneBackToo:
	.string "Will you take back the other one,\n"
	.string "too?$"

Route5_PokemonDayCare_Text_NotEnoughMoney:
	.string "You don't have enough money…$"

Route5_PokemonDayCare_EventScript_TwoMonsInDaycare::
	msgbox Route5_PokemonDayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route5_PokemonDayCare_EventScript_DisplayLevelsGained2
	msgbox Route5_PokemonDayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route5_PokemonDayCare_EventScript_TryRetrieveMon
	msgbox Route5_PokemonDayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route5_PokemonDayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "I'm the owner of the Day Care.\p"
	.string "We can raise Pokémon for you.\p"
	.string "Would you like us to raise one?$"

Route5_PokemonDayCare_Text_FineThenComeAgain:
	.string "Have a nice day!$"

EventScript_EggHatch::
	lockall
	msgbox Text_EggHatchHuh, MSGBOX_DEFAULT
	special EggHatch
	waitstate
	releaseall
	end

Text_EggHatchHuh:
	.string "Huh?$"


Route5_PokemonDayCare_EventScript_GetDailyBerry::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_STATUS_BERRY, Route5_PokemonDayCare_EventScript_PlantBerries
	msgbox Route5_PokemonDayCare_Text_PokemonLoveBerries, MSGBOX_DEFAULT
	random 6
	call_if_eq VAR_RESULT, 0, Route5_PokemonDayCare_EventScript_GiveCheriBerry
	call_if_eq VAR_RESULT, 1, Route5_PokemonDayCare_EventScript_GiveChestoBerry
	call_if_eq VAR_RESULT, 2, Route5_PokemonDayCare_EventScript_GivePechaBerry
	call_if_eq VAR_RESULT, 3, Route5_PokemonDayCare_EventScript_GiveRawstBerry
	call_if_eq VAR_RESULT, 4, Route5_PokemonDayCare_EventScript_GiveAspearBerry
	call_if_eq VAR_RESULT, 5, Route5_PokemonDayCare_EventScript_GivePersimBerry
	setflag FLAG_DAILY_STATUS_BERRY
	goto Route5_PokemonDayCare_EventScript_PlantBerries
	end

Route5_PokemonDayCare_Text_PokemonLoveBerries::
	.string "Pokémon love berries!\p"
	.string "I found this while I was exploring\n"
	.string "with my Pokémon.$"

Route5_PokemonDayCare_EventScript_GiveCheriBerry::
	giveitem ITEM_CHERI_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveChestoBerry::
	giveitem ITEM_CHESTO_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GivePechaBerry::
	giveitem ITEM_PECHA_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveRawstBerry::
	giveitem ITEM_RAWST_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GiveAspearBerry::
	giveitem ITEM_ASPEAR_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_GivePersimBerry::
	giveitem ITEM_PERSIM_BERRY, 1
	return

Route5_PokemonDayCare_EventScript_PlantBerries::
	msgbox Route5_PokemonDayCare_Text_SoftSoil MSGBOX_NPC
	release
	end

Route5_PokemonDayCare_Text_SoftSoil::
	.string "If you stick it in some soft soil,\n"
	.string "it might grow!$"
