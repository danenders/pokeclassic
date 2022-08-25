Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route10_OnResume
	.byte 0

Route10_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route10_OnResume:
	call Common_EventScript_GetDayOrNight
	end
