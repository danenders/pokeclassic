Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	.byte 0

Route16_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route16_OnResume:
	call Common_EventScript_GetDayOrNight
	end
