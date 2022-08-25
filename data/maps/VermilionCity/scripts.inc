VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VermilionCity_OnResume
	.byte 0

VermilionCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

VermilionCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end
