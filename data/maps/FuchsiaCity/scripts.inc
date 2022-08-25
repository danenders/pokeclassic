FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FuchsiaCity_OnResume
	.byte 0

FuchsiaCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

FuchsiaCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end
