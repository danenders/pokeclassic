.set LOCALID_FUGITIVE, 7

DiglettsCave_B1F_MapScripts::
	.byte 0

DiglettsCave_B1F_ItemSmoothRock::
	finditem ITEM_SMOOTH_ROCK, 1
	release
	end

DiglettCave_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
