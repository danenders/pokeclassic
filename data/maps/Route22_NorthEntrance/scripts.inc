.set LOCALID_GUARD, 1

Route22_NorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_NorthEntrance_OnTransition
	.byte 0

Route22_NorthEntrance_OnTransition::
	goto_if_set FLAG_BADGE08_GET, Route22_NorthEntrance_MoveGateGuard
	end

Route22_NorthEntrance_MoveGateGuard::
	setobjectxyperm LOCALID_GUARD, 8, 2
	end

Route22_NorthEntrance_EventScript_GateGuard::
	goto_if_set FLAG_BADGE08_GET,  Route22_NorthEntrance_HeadToVictoryRoad
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_GUARD, Common_Movement_QuestionMark
	waitmovement 1
	waitse
	msgbox Route22_NorthEntrance_Text_Collect8Badges, MSGBOX_NPC
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

Route22_NorthEntrance_Text_Collect8Badges::
	.string "Oh? You want to head to Indigo\n"
	.string "Plateau?\p"
	.string "I'm sorry, I can't let you through\n"
	.string "unless you've collected all 8 Gym\l"
	.string "Badges.$"

Route22_NorthEntrance_HeadToVictoryRoad::
	msgbox Route22_NorthEntrance_Text_HeadToVictoryRoad, MSGBOX_NPC
	release
	end

Route22_NorthEntrance_Text_HeadToVictoryRoad::
	.string "You'll find Victory Road at the end\n"
	.string "of Route 23.\p"
	.string "It's full of elite trainers and strong\n"
	.string "Pokémon.\n"
	.string "It's your final test before you face the\n"
	.string "Elite Four!$"

