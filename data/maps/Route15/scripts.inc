Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route15_OnResume
	.byte 0

Route15_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route15_OnResume:
	call Common_EventScript_GetDayOrNight
	end
