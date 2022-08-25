Route23_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route23_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route23_OnResume
	.byte 0

Route23_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route23_OnResume:
	call Common_EventScript_GetDayOrNight
	end
