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
