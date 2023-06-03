.set LOCALID_FUGITIVE, 6 

Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route18_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition:
	call_if_eq VAR_CYCLING_ROAD, 1, Route18_OnTransitionCyclingRoad
	call Common_EventScript_GetDayOrNight
	end

Route18_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_CYCLING_ROAD, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_EventScript_Ramiro::
	trainerbattle_single TRAINER_BIRD_KEEPER_RAMIRO, Route18_Text_RamiroIntro, Route18_Text_RamiroDefeat
	msgbox Route18_Text_RamiroPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_RamiroIntro::
    .string "Kurukkoo!\n"
    .string "How do you like my birdcall?$"

Route18_Text_RamiroDefeat::
    .string "I had to bug you!$"

Route18_Text_RamiroPostBattle::
    .string "I collect sea POKéMON on weekends\n"
    .string "because the sea is so close.$"

Route18_EventScript_Jacob::
	trainerbattle_single TRAINER_BIRD_KEEPER_JACOB, Route18_Text_JacobIntro, Route18_Text_JacobDefeat
	msgbox Route18_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_JacobIntro::
    .string "This is my turf!\n"
    .string "Get out of here!$"

Route18_Text_JacobDefeat::
    .string "Darn!$"

Route18_Text_JacobPostBattle::
    .string "This is my fave area for catching\n"
    .string "Pokémon.$"

Route18_Text_RouteSign::
    .string "Route 18\n"
    .string "Celadon City - Fuchsia City $"

Route18_Text_CyclingRoadSign::
    .string "Cycling Road\n"
    .string "No pedestrians permitted!$"

Route18_EventScript_Wilton::
	trainerbattle_single REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1, Route18_Text_WiltonIntro, Route18_Text_WiltonDefeat, Route18_EventScript_RegisterWiltonAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route18_EventScript_WiltonRematch
	msgbox Route18_Text_WiltonPostBattle, MSGBOX_DEFAULT
	release
	end

Route18_Text_WiltonIntro::
    .string "I always check every grassy area\n"
    .string "for new Pokémon.$"

Route18_Text_WiltonDefeat::
    .string "Tch!$"

Route18_Text_WiltonPostBattle::
    .string "I wish I had a bike!$"

Route18_EventScript_RegisterWiltonAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route18_Text_WiltonRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1
	release
	end

Route18_Text_WiltonRegister:
	.string "You're working on a PokéDex?\p"
	.string "Call me if you find any good\l"
	.string "spots to catch Pokémon!"

Route18_EventScript_WiltonRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BIRD_KEEPER_WILTON_1, Route18_Text_WiltonRematchIntro, Route18_Text_WiltonDefeat
	msgbox Route18_Text_WiltonRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route18_Text_WiltonRematchIntro::
	.string "Hey {PLAYER}!\n"
	.string "Catch any rare Pokémon?$"

Route18_Text_WiltonRematchPostBattle::
	.string "If I had a bike, I could go\n"
	.string "search for Pokémon anywhere!$"

Route18_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
