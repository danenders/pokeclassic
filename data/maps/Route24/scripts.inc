Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route24_OnResume
	.byte 0

Route24_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route24_OnResume:
	call Common_EventScript_GetDayOrNight
	end
