SilphCo_2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "2F$"

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
    .string "Help!\n"
    .string "I'm a Silph employee.$"

SilphCo_2F_Text_ConnorDefeat::
    .string "How did you know\n"
    .string "I was a Rocket?$"

SilphCo_2F_Text_ConnorPostBattle::
    .string "I work for both Silph and Team\n"
    .string "Rocket.$"

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_JerryIntro::
    .string "It's off-limits here!\n"
    .string "Go home!$"

SilphCo_2F_Text_JerryDefeat::
    .string "You're good.$"

SilphCo_2F_Text_JerryPostBattle::
    .string "Can you solve the maze in here?\n"
    .string "It's not easy, I tell you!$"

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt1Intro::
    .string "No kids are allowed in here!$"

SilphCo_2F_Text_Grunt1Defeat::
    .string "Tough!$"

SilphCo_2F_Text_Grunt1PostBattle::
    .string "Diamond-shaped tiles are teleport\n"
    .string "blocks.\p"
    .string "They're transporters for this\n"
    .string "high-tech building.$"

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_Grunt2Intro::
    .string "Hey, kid!\n"
    .string "What are you wandering here for?$"

SilphCo_2F_Text_Grunt2Defeat::
    .string "I goofed!$"

SilphCo_2F_Text_Grunt2PostBattle::
    .string "Silph Co. will be associated with\n"
    .string "Team Rocket!$"

