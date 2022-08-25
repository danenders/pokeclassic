Route21_North_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_North_OnResume
	.byte 0

Route21_North_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_North_OnResume:
	call Common_EventScript_GetDayOrNight
	end
