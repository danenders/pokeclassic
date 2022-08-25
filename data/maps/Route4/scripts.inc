Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route4_OnResume
	.byte 0

Route4_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route4_OnResume:
	call Common_EventScript_GetDayOrNight
	end
