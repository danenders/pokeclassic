Route14_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route14_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route14_OnResume
	.byte 0

Route14_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route14_OnResume:
	call Common_EventScript_GetDayOrNight
	end
