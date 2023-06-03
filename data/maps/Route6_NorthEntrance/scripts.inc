.set LOCALID_JENNY, 1

Route6_NorthEntrance_MapScripts::
	.byte 0

@TODO: The Gate Guards are not the road block anymore, but giving them tea will be a new daily event. Reward is TBD.

Route6_NorthEntrance_EventScript_Guard::
	goto_if_unset FLAG_DAILY_GUARD_TEA, Route6_NorthEntrance_EventScript_GuardThirsty
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route6_NorthEntrance_EventScript_RoadsClosed
	msgbox Route6_NorthEntrance_Text_HiHowsItGoing, MSGBOX_NPC
	end

Route6_NorthEntrance_Text_HiHowsItGoing::
    .string "Hi, how's it going?$"

Route6_NorthEntrance_EventScript_RoadsClosed::
	msgbox Route6_NorthEntrance_Text_RoadsClosed, MSGBOX_NPC
	release
	end

Route6_NorthEntrance_Text_RoadsClosed::
    .string "Oh, by the way, the road's closed.\p"
    .string "The International Police are on\n"
    .string "the hunt for Team Rocket!$"

Route6_NorthEntrance_EventScript_GuardThirsty::
	msgbox Route6_NorthEntrance_Text_ThirstyOnGuardDuty, MSGBOX_NPC
	checkitem ITEM_TEA
	goto_if_eq VAR_RESULT, FALSE, Route6_NorthEntrance_EventScript_GuardSmallTalk
	msgbox Route6_NorthEntrance_Text_ThatTeaLooksTasty, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route6_NorthEntrance_EventScript_DenyGuard
	removeitem ITEM_TEA, 1
	setflag FLAG_DAILY_GUARD_TEA
	msgbox Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards, MSGBOX_NPC
	random 3
	goto_if_eq VAR_RESULT, 0, GateGuard_GiveNugget
	goto_if_eq VAR_RESULT, 1, GateGuard_GiveStone
	goto_if_eq VAR_RESULT, 2, GateGuard_ResetSnorlax1
	goto_if_eq VAR_RESULT, 3, GateGuard_ResetSnorlax2
	end

Route6_NorthEntrance_Text_ThirstyOnGuardDuty::
    .string "I'm on guard duty.\n"
    .string "Gee, I'm thirsty, though!$"

Route6_NorthEntrance_Text_ThatTeaLooksTasty::
    .string "Oh, that tea…\n"
    .string "It looks awfully tasty…$"

Route6_NorthEntrance_Text_ThanksIllShareTeaWithGuards::
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

Route6_NorthEntrance_EventScript_DenyGuard::
	msgbox Route6_NorthEntrance_Text_ThatsAShame, MSGBOX_NPC
	release
	end

Route6_NorthEntrance_Text_ThatsAShame::
	.string "Oh, that's a shame.\n"
	.string "I sure could use a drink...$"

Route6_NorthEntrance_EventScript_GuardSmallTalk::
	goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, Route6_NorthEntrance_EventScript_RoadsClosed
	release
	end

Route6_NorthEntrance_EventScript_Jenny::
	msgbox Route6_NorthEntrance_Text_TipAboutTeamRocket, MSGBOX_NPC
	checkitem ITEM_ROCKET_PLANS
	goto_if_eq VAR_RESULT, TRUE, Route6_NorthEntrance_EventScript_DeliverRocketPlans
	release
	end

Route6_NorthEntrance_Text_TipAboutTeamRocket::
	.string "We received a tip that Team Rocket\n"
	.string "may be passing this way, so we can't\l"
	.string "let anyone through right now.$"

Route6_NorthEntrance_EventScript_DeliverRocketPlans::
	removeitem ITEM_ROCKET_PLANS
	setflag FLAG_DELIVERED_ROCKET_PLANS
	playse SE_PIN
	applymovement LOCALID_JENNY, Common_Movement_ExclamationMark
	waitmovement 1
	msgbox Route6_NorthEntrance_Text_DeliverRocketPlans, MSGBOX_NPC
	waitmessage
	closemessage
	applymovement LOCALID_JENNY, Route6_NorthEntrance_Movement_JennyExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_JENNY
	release
	end

Route6_NorthEntrance_Text_DeliverRocketPlans::
	.string "What? You've found some of Team\n"
	.string "Rocket's plans?\p"
	.string "This better not be a prank, kid.\p"
	.string "I'll have to see those...\n"
	.string "... ... ...\p"
	.string "These appear to be authentic!\p"
	.string "I need to deliver these to the\n"
	.string "Inspector right away!$"

Route6_NorthEntrance_Movement_JennyExit:
	face_up
	walk_in_place_faster_up
	delay_8
	step_end

