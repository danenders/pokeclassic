Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route8_OnResume
	.byte 0

Route8_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route8_OnResume:
	call Common_EventScript_GetDayOrNight
	end
