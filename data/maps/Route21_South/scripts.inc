Route21_South_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route21_South_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route21_South_OnResume
	.byte 0

Route21_South_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route21_South_OnResume:
	call Common_EventScript_GetDayOrNight
	end
