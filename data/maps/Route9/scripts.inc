Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route9_OnResume
	.byte 0

Route9_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route9_OnResume:
	call Common_EventScript_GetDayOrNight
	end
