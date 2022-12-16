SilphCo_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION, 1
	release
	end

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SAFFRON_ROCKETS, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
    .string "I work for Silph Co.\n"
    .string "What am I to do?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
    .string "{PLAYER}!\n"
    .string "You and your Pokémon saved us!$"

SilphCo_3F_Text_GruntIntro::
    .string "Quit messing with us, kid!$"

SilphCo_3F_Text_GruntDefeat::
    .string "I give up!$"

SilphCo_3F_Text_GruntPostBattle::
    .string "A hint? You can open doors with\n"
    .string "a Card Key!$"

SilphCo_3F_Text_JoseIntro::
    .string "I support Team Rocket more than\n"
    .string "I support Silph Co.!$"

SilphCo_3F_Text_JoseDefeat::
    .string "You really got me!$"

SilphCo_3F_Text_JosePostBattle::
    .string "Humph…\p"
    .string "Team Rocket said that if I helped\n"
    .string "them, they'd let me study Pokémon.$"

SilphCo_3F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "3F$"

SilphCo_3F_EventScript_PostgameGrunt4::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_4, SilphCo_3F_Text_PostgameGrunt4Intro, SilphCo_3F_Text_PostgameGrunt4Defeat
	msgbox SilphCo_3F_Text_PostgameGrunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_PostgameGrunt4Intro::
    .string "Rockets never say die!$"

SilphCo_3F_Text_PostgameGrunt4Defeat::
    .string "We're dead!$"

SilphCo_3F_Text_PostgameGrunt4PostBattle::
    .string "This was our last shot.\p"
    .string "The Boss has taken the Silph\n"
    .string "Co President hostage again.\p"
    .string "There's no coming back from this!$"
