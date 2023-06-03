.set LOCALID_FUGITIVE, 2

Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route7_OnResume
	.byte 0

Route7_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route7_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route7_EventScript_UndergroundPathSign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Celadon City - Lavender Town$"

Route7_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
