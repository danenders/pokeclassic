Route5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route5_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route5_OnResume
	.byte 0

Route5_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route5_OnResume:
	call Common_EventScript_GetDayOrNight
	end
