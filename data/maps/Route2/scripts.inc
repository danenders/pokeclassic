.set LOCALID_FUGITIVE_M, 14
.set LOCALID_FUGITIVE_F, 15

Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route2_OnResume
	.byte 0

Route2_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route2_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_Text_RouteSign::
    .string "Route 2\n"
    .string "Viridian City - Pewter City$"

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_Text_DiglettsCave::
    .string "Diglett'S Cave$"

Route2_FindItem_Ether::
	finditem ITEM_ETHER, 1
	end

Route2_FindItem_ParlyzHeal::
	finditem ITEM_PARALYZE_HEAL, 1
	end

Route2_FindItem_Pidgeotite::
	finditem ITEM_PIDGEOTITE, 1
	end

Route2_RocketFugitiveM::
	trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_M
	waitse
	fadescreen FADE_FROM_BLACK
	end

Route2_RocketFugitiveF::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE_F
	waitse
	fadescreen FADE_FROM_BLACK
	end
