Route17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route17_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route17_OnResume
	.byte 0

Route17_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route17_OnResume:
	call Common_EventScript_GetDayOrNight
	end
