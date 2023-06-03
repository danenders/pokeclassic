.set LOCALID_JENNY, 1

Route8_WestEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route8_WestEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route8_WestEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	msgbox Route8_WestEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route8_WestEntrance_Text_HiHowsItGoing::
    .string "Hi, how's it going?$"

Route8_WestEntrance_EventScript_RoadsClosed::
	msgbox Route8_WestEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_RoadsClosed::
    .string "Oh, by the way, the road's closed.\p"
    .string "The International Police are on\n"
    .string "the hunt for Team Rocket!$"

Route8_WestEntrance_EventScript_GuardThirsty::
	msgbox Route8_WestEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route8_WestEntrance_EventScript_GuardSmallTalk
	msgbox Route8_WestEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route8_WestEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

GateGuard_GiveNugget::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_NUGGET, 1
	release
	end

GateGuard_GiveStone::
	msgbox GateGuard_Text_FoundThis, MSGBOX_NPC
	giveitem ITEM_POWER_STONE, 1
	release
	end

GateGuard_Text_FoundThis::
	.string "Hey, since you shared your\n"
	.string "Tea with me, why don't you\l"
	.string "take this?\p"
	.string "It's been in the Lost & Found\n"
	.string "forever, I don't think anyone\l"
	.string "is going to claim it!$"

GateGuard_ResetSnorlax1::
	goto_if_unset FLAG_HIDE_ROUTE12_SNORLAX, GateGuard_GiveNugget
	msgbox GateGuard_Text_SnorlaxLavender, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE12_SNORLAX
	release
	end

GateGuard_Text_SnorlaxLavender:
	.string "Oh, did you hear?\p"
	.string "A huge Pokémon was seen\n"
	.string "sleeping in the road near\l"
	.string "Lavender Town!\p"
	.string "I wish I could nap like that.$"

GateGuard_ResetSnorlax2::
	goto_if_unset FLAG_HIDE_ROUTE16_SNORLAX, GateGuard_GiveStone
	msgbox GateGuard_Text_SnorlaxCyclingRoad, MSGBOX_NPC
	clearflag FLAG_HIDE_ROUTE16_SNORLAX
	release
	end

GateGuard_Text_SnorlaxCyclingRoad::
	.string "Oh, did you hear?\p"
	.string "A huge Pokémon was seen\n"
	.string "sleeping in the road near\l"
	.string "Celadon City!\p"
	.string "I wish I could nap like that.$"

Route8_WestEntrance_Text_ThirstyOnGuardDuty::
    .string "I'm on guard duty.\n"
    .string "Gee, I'm thirsty, though!$"

Route8_WestEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, that tea…\n"
    .string "It looks awfully tasty…$"

Route8_WestEntrance_Text_ThanksIllShareTeaWithGuards::
    .string "Huh? I can have this drink?\n"
    .string "Gee, thanks!\l"
    .string "… …\l"
    .string "Glug, glug…\l"
    .string "… …\l"
    .string "Gulp…\l"
    .string "… …\l"
    .string "That really hits the spot!…\p"
    .string "I'll share this tea with the other\n"
    .string "guards!$"

Route8_WestEntrance_EventScript_DenyGuard::
	msgbox Route8_WestEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route8_WestEntrance_Text_ThatsAShame::
	.string "Oh, that's a shame.\n"
	.string "I sure could use a drink...$"

Route8_WestEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route8_WestEntrance_EventScript_RoadsClosed
	release
	end

Route8_WestEntrance_EventScript_Jenny::
	msgbox Route8_WestEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route8_WestEntrance_EventScript_DeliverRocketPlans
	release
	end

Route8_WestEntrance_Text_TipAboutTeamRocket::
	.string "We received a tip that Team Rocket\n"
	.string "may be passing this way, so we can't\l"
	.string "let anyone through right now.$"

Route8_WestEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route8_WestEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route8_WestEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route8_WestEntrance_Text_DeliverRocketPlans::
	.string "What? You've found some of Team\n"
	.string "Rocket's plans?\p"
	.string "This better not be a prank, kid.\p"
	.string "I'll have to see those...\n"
	.string "... ... ...\p"
	.string "These appear to be authentic!\p"
	.string "I need to deliver these to the\n"
	.string "Inspector right away!$"

Route8_WestEntrance_Movement_JennyExit:
	face_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_8
	step_end

