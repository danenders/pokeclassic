Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route23_OnResume
	.byte 0

Route23_OnTransition:
	clearflag FLAG_HIDE_VICTORY_ROAD_3F_BOULDER
	setflag FLAG_HIDE_VICTORY_ROAD_2F_BOULDER
	setvar VAR_VICTORY_ROAD_1F_STATE, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER1, 0
	setvar VAR_VICTORY_ROAD_2F_BOULDER2, 0
	setvar VAR_VICTORY_ROAD_3F_STATE, 0
	call Common_EventScript_GetDayOrNight
	end

Route23_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route23_EventScript_VictoryRoadGateSign::
	msgbox Route23_Text_VictoryRoadGateSign, MSGBOX_SIGN
	end

Route23_Text_VictoryRoadGateSign::
    .string "Victory Road Gate -\n"
    .string "Pokémon League$"

Route23_EventScript_ItemTM10::
	finditem ITEM_TM10, 1
	release
	end
