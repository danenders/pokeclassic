Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route2_OnResume
	.byte 0

Route2_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route2_OnResume:
	call Common_EventScript_GetDayOrNight
	end
