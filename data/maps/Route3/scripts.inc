Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route3_OnResume
	.byte 0

Route3_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route3_OnResume:
	call Common_EventScript_GetDayOrNight
	end
