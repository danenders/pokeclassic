.set LOCALID_SCOTT, 1

IndigoPlateau_BattleTowerHallway_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_BattleTowerHallway_OnFrame
	.byte 0

IndigoPlateau_BattleTowerHallway_OnFrame::
	map_script_2 VAR_BATTLE_TOWER, 0, IndigoPlateau_BattleTowerHallway_BattleTowerCutscene
	.2byte 0

IndigoPlateau_BattleTowerHallway_BattleTowerCutscene::
	applymovement OBJ_EVENT_ID_PLAYER, BTCutscene_ApproachScott
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox IndigoPlateau_BattleTowerHallway_YouMadeIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitse
	waitmovement 0
	msgbox IndigoPlateau_BattleTowerHallway_LetMeExplain, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox IndigoPlateau_BattleTowerHallway_GotFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	waitfanfare
	closemessage
	msgbox IndigoPlateau_BattleTowerHallway_GreatToSeeYouHere, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottLeave
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox IndigoPlateau_BattleTowerHallway_ThisIsIt, MSGBOX_DEFAULT	
	waitmessage
	closemessage
	applymovement LOCALID_SCOTT, BTCutscene_ScottExit
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SCOTT
	setflag FLAG_HIDE_SCOTT_HALLWAY
	setvar VAR_BATTLE_TOWER, 1
	release
	end

BTCutscene_ApproachScott::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BTCutscene_ScottLeave::
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	face_up
	step_end

BTCutscene_ScottExit::
	walk_down
	walk_down
	delay_16
	step_end


IndigoPlateau_BattleTowerHallway_YouMadeIt::
	.string "Scott: There you are, Champ!\p"
	.string "You've finally made it to the\n"
	.string "big Leagues.\p"
	.string "What? You don't know what this\n"
	.string "place is?\p"
	.string "This is my pride and joy!\p"
	.string "I wasn't watching your progress\n"
	.string "in the League just for fun, you know.\p"
	.string "I've been scouting out the best\n"
	.string "Pokémon Trainers in Kanto and\l"
	.string "inviting them here -\p"
	.string "to the Battle Frontier!$"

IndigoPlateau_BattleTowerHallway_LetMeExplain::
	.string "Scott: Let me explain.\p"
	.string "In the Pokémon League, you make\n"
	.string "your way up the ranks by battling\l"
	.string "other trainers in normal matches, right?\p"
	.string "Well, now that you're a Champion, those\n"
	.string "battles might not be enough of a\l"
	.string "challenge for you anymore.\p"
	.string "Only the best trainers from Kanto can\n"
	.string "enter the Battle Frontier - so everyone\l"
	.string "you meet is at the top of their game!\p"
	.string "And to top it off, we have different\n"
	.string "rules and regulations than the\l"
	.string "League, too!\p"
	.string "There's all sorts of ways you can battle\n"
	.string "here!.\p" 
	.string "It's every trainer's dream!\p"
	.string "Oh...I got carried away.\p"
	.string "Here...take this.$"

IndigoPlateau_BattleTowerHallway_GotFrontierPass::
	.string "{PLAYER} got the Frontier Pass from\n"
	.string "Scott!$"

IndigoPlateau_BattleTowerHallway_GreatToSeeYouHere:
	.string "Scott: It's great to see you here,\n"
	.string "it really is!\p"
	.string "Naturally, I hope you'll also experience\n"
	.string "the pure essence of battling.$"

IndigoPlateau_BattleTowerHallway_ThisIsIt::
	.string "Scott: This is it, champ.\p"
	.string "Your whole career- this is what\n"
	.string "it's been building up to.\p"
	.string "The best battles of your life are\n"
	.string "up that elevator.\p"
	.string "It's been a blast watching you get\n"
	.string "get here!\p"
	.string "I'd probably have to go around the\n"
	.string "world to find another trainer like you...$"

IndigoPlateau_BattleTowerHallway_BattleGirl::
	lock
	faceplayer
	msgbox IndigoPlateau_BattleTowerHallway_Text_BattleGirl, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_BattleTowerHallway_Text_BattleGirl::
	.string "I thought I was doing well, but I\n"
	.string "couldn't keep up my streak!\p"
	.string "I was hoping to earn more BP for\n"
	.string "some training items!$"


IndigoPlateau_BattleTowerHallway_BlackBelt::
	lock
	faceplayer
	msgbox IndigoPlateau_BattleTowerHallway_Text_BlackBelt, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_BattleTowerHallway_Text_BlackBelt::
	.string "I spent my BP on these weird mints.\p"
	.string "My Pokémon started acting different\n"
	.string "when I gave one to them!$"

IndigoPlateau_BattleTowerHallway_CoolTrainerM::
	lock
	faceplayer
	msgbox IndigoPlateau_BattleTowerHallway_Text_CoolTrainerM, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_BattleTowerHallway_Text_CoolTrainerM::
	.string "The 3rd Floor has the Battle Factory.\p"
	.string "That's a real test of trainer's skills.$"

IndigoPlateau_BattleTowerHallway_CoolTrainerF::
	lock
	faceplayer
	msgbox IndigoPlateau_BattleTowerHallway_Text_CoolTrainerF, MSGBOX_DEFAULT
	release
	end

IndigoPlateau_BattleTowerHallway_Text_CoolTrainerF::
	.string "I made it all the way here, but\n"
	.string "I'm too scared to get in that\l"
	.string "elevator...\p"
	.string "What if I'm not good enough?$"
