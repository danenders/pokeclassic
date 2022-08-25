Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route19_OnResume
	.byte 0

Route19_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route19_OnResume:
	call Common_EventScript_GetDayOrNight
	end
