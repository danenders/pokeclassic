Route22_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route22_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route22_OnResume
	.byte 0

Route22_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route22_OnResume:
	call Common_EventScript_GetDayOrNight
	end
