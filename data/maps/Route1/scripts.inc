Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route1_OnResume
	.byte 0

Route1_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route1_OnResume:
	call Common_EventScript_GetDayOrNight
	end
