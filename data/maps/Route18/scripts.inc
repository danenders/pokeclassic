Route18_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route18_OnResume
	.byte 0

Route18_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route18_OnResume:
	call Common_EventScript_GetDayOrNight
	end
