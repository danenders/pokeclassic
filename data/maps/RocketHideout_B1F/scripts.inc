RocketHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_OnTransition
	.byte 0

RocketHideout_B1F_OnLoad::
	call_if_not_defeated TRAINER_TEAM_ROCKET_GRUNT_12 RocketHideout_B1F_EventScript_SetBarrier
	end

RocketHideout_B1F_OnTransition::
    call_if_set FLAG_HIDE_CELADON_ROCKETS, RocketHideout_B1F_EventScript_RemoveBarrier
	end

RocketHideout_B1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_8, RocketHideout_B1F_Text_Grunt1Intro, RocketHideout_B1F_Text_Grunt1Defeat
	msgbox RocketHideout_B1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt1Intro::
    .string "Who are you?\n"
    .string "How did you get here?$"

RocketHideout_B1F_Text_Grunt1Defeat::
    .string "Oww!\n"
    .string "Beaten!$"

RocketHideout_B1F_Text_Grunt1PostBattle::
    .string "Blast it… You're dissing Team\n"
    .string "Rocket, aren't you?$"

RocketHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_9, RocketHideout_B1F_Text_Grunt2Intro, RocketHideout_B1F_Text_Grunt2Defeat
	msgbox RocketHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt2Intro::
    .string "You broke into TEAM ROCKET's\n"
    .string "operation? What nerve!$"

RocketHideout_B1F_Text_Grunt2Defeat::
    .string "Boom!$"

RocketHideout_B1F_Text_Grunt2PostBattle::
    .string "You're not going to get away with\n"
    .string "this, brat!$"

RocketHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_10, RocketHideout_B1F_Text_Grunt3Intro, RocketHideout_B1F_Text_Grunt3Defeat
	msgbox RocketHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt3Intro::
    .string "Intruder alert!$"

RocketHideout_B1F_Text_Grunt3Defeat::
    .string "I can't do it!$"

RocketHideout_B1F_Text_Grunt3PostBattle::
    .string "Cubone? Humph!\n"
    .string "I don't know where it is.$"

RocketHideout_B1F_EventScript_Grunt4::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_11, RocketHideout_B1F_Text_Grunt4Intro, RocketHideout_B1F_Text_Grunt4Defeat
	msgbox RocketHideout_B1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt4Intro::
    .string "Why did you come here?$"

RocketHideout_B1F_Text_Grunt4Defeat::
    .string "This won't do!$"

RocketHideout_B1F_Text_Grunt4PostBattle::
    .string "Okay, I'll talk…\n"
    .string "Take the elevator to see my Boss.$"

RocketHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_12, RocketHideout_B1F_Text_Grunt5Intro, RocketHideout_B1F_Text_Grunt5Defeat, RocketHideout_B1F_EventScript_DefeatedGrunt5
	msgbox RocketHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B1F_Text_Grunt5Intro::
    .string "Are you lost, you little mouse?$"

RocketHideout_B1F_Text_Grunt5Defeat::
    .string "Why…?$"

RocketHideout_B1F_Text_Grunt5PostBattle::
    .string "Uh-oh, that ruckus somehow opened\n"
    .string "the door!$"

RocketHideout_B1F_EventScript_DefeatedGrunt5::
	call RocketHideout_B1F_EventScript_RemoveBarrier
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	release
	end

RocketHideout_B1F_EventScript_SetBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 21, 19, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 20, 20, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 21, 20, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B1F_EventScript_RemoveBarrier::
	setmetatile 20, 19, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 19, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 20, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 20, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 20, 21, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 21, 21, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B1F_EventScript_ItemEscapeRope::
	finditem ITEM_ESCAPE_ROPE, 1
	release
	end

RocketHideout_B1F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end


RocketHideout_Burglars_Text_GetTM::
    .string "Team Rocket left a lot of good\n"
    .string "loot behind when they left.\p"
    .string "Here, take this.\n"
    .string "There's plenty to go around!$"

RocketHideout_Burglars_TM13::
    trainerbattle_single TRAINER_BURGLAR_TYLER, RocketHideout_Burglars_Text_BurglarIntro1, RocketHideout_Burglars_Text_BurglarDefeat1
    goto_if_set FLAG_GOT_TM13, RocketHideout_Burglars_EventScript_GotTM13
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM13, 1
    setflag FLAG_GOT_TM13
RocketHideout_Burglars_EventScript_GotTM13::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle1, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro1::
    .string "Hey! I got here first.\n"
    .string "Finders keepers!$"

RocketHideout_Burglars_Text_BurglarDefeat1::
    .string "Losers weepers...$"

RocketHideout_Burglars_Text_BurglarPostBattle1::
    .string "Some of my buddies are here, too.\n"
    .string "It was too hard to pass up!$"



RocketHideout_Burglars_TM23::
    trainerbattle_single TRAINER_BURGLAR_GREG, RocketHideout_Burglars_Text_BurglarIntro2, RocketHideout_Burglars_Text_BurglarDefeat2
    goto_if_set FLAG_GOT_TM23, RocketHideout_Burglars_EventScript_GotTM23
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM23, 1
    setflag FLAG_GOT_TM23
RocketHideout_Burglars_EventScript_GotTM23::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle2, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro2::
    .string "Let's see...what do we have here?$"

RocketHideout_Burglars_Text_BurglarDefeat2::
    .string "No! I wanted that one!$"

RocketHideout_Burglars_Text_BurglarPostBattle2::
    .string "You never know what you're gonna\n"
    .string "find when you break into a place.$"


RocketHideout_Burglars_TM24::
    trainerbattle_single TRAINER_BURGLAR_TONY, RocketHideout_Burglars_Text_BurglarIntro3, RocketHideout_Burglars_Text_BurglarDefeat3
    goto_if_set FLAG_GOT_TM24, RocketHideout_Burglars_EventScript_GotTM24
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM24, 1
    setflag FLAG_GOT_TM24
RocketHideout_Burglars_EventScript_GotTM24::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle3, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro3::
    .string "Whoa, hey, are you stealing that?\n"
    .string "That's not very nice!$"

RocketHideout_Burglars_Text_BurglarDefeat3::
    .string "What'd you do that for?$"

RocketHideout_Burglars_Text_BurglarPostBattle3::
    .string "Oh, me? I'm not stealing this.\n"
    .string "I'm just borrowing it!$"


RocketHideout_Burglars_TM30::
    trainerbattle_single TRAINER_BURGLAR_JAKE, RocketHideout_Burglars_Text_BurglarIntro4, RocketHideout_Burglars_Text_BurglarDefeat4
    goto_if_set FLAG_GOT_TM30, RocketHideout_Burglars_EventScript_GotTM30
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM30, 1
    setflag FLAG_GOT_TM30
RocketHideout_Burglars_EventScript_GotTM30::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle4, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro4::
    .string "Let's see...what can I find in\n"
    .string "here today?$"

RocketHideout_Burglars_Text_BurglarDefeat4::
    .string "Nothing!$"

RocketHideout_Burglars_Text_BurglarPostBattle4::
    .string "What? Get an honest job?\n"
    .string "In this economy?$"

RocketHideout_Burglars_TM35::
    trainerbattle_single TRAINER_BURGLAR_KYLE, RocketHideout_Burglars_Text_BurglarIntro5, RocketHideout_Burglars_Text_BurglarDefeat5
    goto_if_set FLAG_GOT_TM35, RocketHideout_Burglars_EventScript_GotTM35
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM35, 1
    setflag FLAG_GOT_TM35
RocketHideout_Burglars_EventScript_GotTM35::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle5, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro5::
    .string "Stealing is cool!$"

RocketHideout_Burglars_Text_BurglarDefeat5::
    .string "Losing is not!$"

RocketHideout_Burglars_Text_BurglarPostBattle5::
    .string "I just love stealing so much.\n"
    .string "Its the only thing I love!$"


RocketHideout_Burglars_TM36::
    trainerbattle_single TRAINER_BURGLAR_PETE, RocketHideout_Burglars_Text_BurglarIntro6, RocketHideout_Burglars_Text_BurglarDefeat6
    goto_if_set FLAG_GOT_TM36, RocketHideout_Burglars_EventScript_GotTM36
    msgbox RocketHideout_Burglars_Text_GetTM, MSGBOX_AUTOCLOSE
    giveitem ITEM_TM36, 1
    setflag FLAG_GOT_TM36
RocketHideout_Burglars_EventScript_GotTM36::
    msgbox RocketHideout_Burglars_Text_BurglarPostBattle6, MSGBOX_AUTOCLOSE
    release
    end

RocketHideout_Burglars_Text_BurglarIntro6::
    .string "Whoa! This looks's expensive!$"

RocketHideout_Burglars_Text_BurglarDefeat6::
    .string "Aw man, it's just junk!$"

RocketHideout_Burglars_Text_BurglarPostBattle6::
    .string "I never seem to find anything good.$"

