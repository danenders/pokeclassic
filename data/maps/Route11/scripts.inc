Route11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route11_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route11_OnResume
	.byte 0

Route11_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route11_OnResume:
	call Common_EventScript_GetDayOrNight
	end
