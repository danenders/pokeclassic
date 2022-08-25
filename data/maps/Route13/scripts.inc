Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route13_OnResume
	.byte 0

Route13_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route13_OnResume:
	call Common_EventScript_GetDayOrNight
	end
