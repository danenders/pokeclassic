Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route12_OnResume:
	call Common_EventScript_GetDayOrNight
	end
