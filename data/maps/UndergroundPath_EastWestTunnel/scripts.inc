.set LOCALID_FUGITIVE, 1

UndergroundPath_EastWestTunnel_MapScripts::
	.byte 0

Undeground1_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
