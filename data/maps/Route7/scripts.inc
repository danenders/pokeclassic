Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route7_OnResume
	.byte 0

Route7_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route7_OnResume:
	call Common_EventScript_GetDayOrNight
	end
