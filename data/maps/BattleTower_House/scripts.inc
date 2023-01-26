BattleTower_House_MapScripts::
	.byte 0

BattleTower_House_Scott::
	lock
	faceplayer
	msgbox BattleTower_House_Text_Scott, MSGBOX_NPC
	release
	end

BattleTower_House_Text_Scott::
	.string "Scott: Hey, Champ!\n"
	.string "Enjoying the Battle Tower?\p"
	.string "I think I'm finally going to\n"
	.string "to take a break from scouting\l"
	.string "trainers.\p"
	.string "Who knows, maybe I'll try out\n"
	.string "some battles of my own! Ha!$"

BattleTower_House_Sign::
	msgbox BattleTower_House_Text_Permit, MSGBOX_SIGN
	release
	end

BattleTower_House_Text_Permit::
	.string "It's a permit to build the\n"
	.string "the Battle Tower!$"
