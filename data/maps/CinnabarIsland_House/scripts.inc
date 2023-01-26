.set LOCALID_SEA_CAPTAIN, 1

CinnabarIsland_House_MapScripts::
	.byte 0

CinnabarIsland_House_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, CinnabarIsland_House_Woman2
	msgbox CinnabarIsland_House_Text_MissesSailing, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_MissesSailing::
	.string "My father was once a great\n"
	.string "Sea Captain.\p"
	.string "But he hasn't been himself since\n"
	.string "he retired.\p"
	.string "He spends his time looking\n"
	.string "longingly at the sea...$"

CinnabarIsland_House_Woman2::
	msgbox CinnabarIsland_House_Text_Wonderful, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_Wonderful::
	.string "This is wonderful!\p"
	.string "I haven't seen my father this\n"
	.string "excited in ages!$"

CinnabarIsland_House_SeaCaptain::
	lock
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, CinnabarIsland_House_SeaCaptain_Grumpy
	msgbox CinnabarIsland_House_Text_WhatsLeft, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement LOCALID_SEA_CAPTAIN, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	msgbox CinnabarIsland_House_Text_WhatsThatYeGot, MSGBOX_DEFAULT
	waitmessage
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	call_if_eq VAR_FACING, DIR_NORTH, CinnabarIsland_House_BehindSeaCaptain
	call_if_ne VAR_FACING, DIR_NORTH, CinnabarIsland_House_SideOfSeaCaptain
	waitmovement 1
	playse SE_EXIT
	removeobject LOCALID_SEA_CAPTAIN
	setflag FLAG_SHOWN_OLD_SEA_MAP
	setflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN_HOUSE
	clearflag FLAG_HIDE_CINNABAR_SEA_CAPTAIN
	release
	end

CinnabarIsland_House_BehindSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit1
	return

CinnabarIsland_House_SideOfSeaCaptain::
	applymovement LOCALID_SEA_CAPTAIN, Movement_CaptainExit2
	return

Movement_CaptainExit1::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_CaptainExit2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end


CinnabarIsland_House_Text_WhatsThatYeGot::
	.string "Aye!\p"
	.string "What's that ye got there, kiddo?\p"
	.string "..."
	.string "It's an Old Sea Map!\p"
	.string "Say...I've been around the world\n"
	.string "more times than there are Pokémon,\l"
	.string "and I dare say I've never seen that\l"
	.string "there island on this map!\p"
	.string "...\p"
	.string "What's that? You want me to sail ya\n"
	.string "there?\p"
	.string "...\p"
	.string "Let's do it! One last adventure for\n"
	.string "this old Sea Captain!$"

CinnabarIsland_House_SeaCaptain_Grumpy::
	msgbox CinnabarIsland_House_Text_Grumpy, MSGBOX_NPC
	release
	end

CinnabarIsland_House_Text_WhatsLeft::
	.string "Hrmmph...\p"
	.string "I've explored every corner\n"
	.string "of the world...\p"
	.string "What's left for me to do...$"

CinnabarIsland_House_Text_Grumpy::
	.string "Hrmmph...$"


