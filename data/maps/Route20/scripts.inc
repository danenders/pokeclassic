Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route20_OnResume
	.byte 0

Route20_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route20_OnResume:
	call Common_EventScript_GetDayOrNight
	end
