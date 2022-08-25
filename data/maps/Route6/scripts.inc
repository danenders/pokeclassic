Route6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route6_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route6_OnResume
	.byte 0

Route6_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route6_OnResume:
	call Common_EventScript_GetDayOrNight
	end
