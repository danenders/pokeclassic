BattleTower_Exterior_MapScripts::
	.byte 0

BattleTower_Exterior_CoolTrainer1::
	msgbox BattleTower_Exterior_Text_WaitInLine, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_WaitInLine::
	.string "Hey! You need to wait in line!$"

BattleTower_Exterior_CoolTrainer2::
	msgbox BattleTower_Exterior_Text_LineIsntMoving, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_LineIsntMoving::
	.string "Ugh, this line hasn't moved in\n"
	.string "ages!$"

BattleTower_Exterior_Trainer3::
	msgbox BattleTower_Exterior_Text_BeatElite, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_BeatElite::
	.string "Only the best trainers are invited\n"
	.string "to the Battle Tower!$"


BattleTower_Exterior_Jenny::
	goto_if_set FLAG_SYS_FRONTIER_PASS, BattleTower_Exterior_Jenny2
	msgbox BattleTower_Exterior_Text_AirTraffic, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_AirTraffic::
	.string "There's so much interest in the\n"
	.string "Battle Tower.\p"
	.string "I've been stationed here to handle\n"
	.string "the crowd.\p"
	.string "And we're not allowing anyone to Fly\n"
	.string "here unless they have a Tower Pass.$"

BattleTower_Exterior_Jenny2::
	msgbox BattleTower_Exterior_Text_TowerPass, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_TowerPass::
	.string "Oh! You have a Tower Pass.\n"
	.string "You're authorized to Fly here now!$"

BattleTower_Exterior_Lass::
	msgbox BattleTower_Exterior_Text_OnAStreak, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_OnAStreak::
	.string "I'm on a win streak at the Battle\n"
	.string "Tower.\p"
	.string "Poliwrath and I came out here for\n"
	.string "some fresh air.\p"
	.string "It's important to rest.\n"
	.string "You don't want to get psyched out!$"

BattleTower_Exterior_Poliwrath::
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox BattleTower_Exterior_Text_Poliwrath, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_Poliwrath::
	.string "Poliwrath looks at you.\n"
	.string "It's filled with determination.$"

BattleTower_Exterior_Youngster::
	lock
	faceplayer
	msgbox BattleTower_Exterior_Text_BattleTower, MSGBOX_NPC
	release
	end

BattleTower_Exterior_Text_BattleTower::
	.string "This Battle Tower is pretty sweet,\n" 
	.string "right?\p"
	.string "I hear the owner is obssessed with\n"
	.string "finding the strongest trainers!$"

BattleTower_Exterior_Punk::
	lockall
	faceplayer
	goto_if_set FLAG_GOT_RED_CARD, BattleTower_Exterior_Punk2
	msgbox BattleTower_Exterior_Text_GotCarded, MSGBOX_DEFAULT
	giveitem ITEM_RED_CARD, 1
	msgbox BattleTower_Exterior_Text_KickedOut, MSGBOX_DEFAULT
	setflag FLAG_GOT_RED_CARD
	releaseall
	end

BattleTower_Exterior_Text_GotCarded::
	.string "I can't believe it!\p"
	.string "I yelled at the referee and she gave\n"
	.string "me one of these!$"

BattleTower_Exterior_Punk2::
	lockall
	msgbox BattleTower_Exterior_Text_KickedOut, MSGBOX_DEFAULT
	releaseall
	end

BattleTower_Exterior_Text_KickedOut::
	.string "I can't believe they kicked me out\n"
	.string "just because I cheated!$"

BattleTower_Exterior_BattleTowerSign::
	msgbox BattleTower_Exterior_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleTower_Exterior_Text_BattleTowerSign::
    .string "The Kanto Battle Tower!\n"
    .string "Rise to the top!$"

