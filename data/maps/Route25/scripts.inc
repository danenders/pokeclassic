Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route25_OnResume
	.byte 0

Route25_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route25_OnResume:
	call Common_EventScript_GetDayOrNight
	end
