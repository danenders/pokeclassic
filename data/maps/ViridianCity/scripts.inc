ViridianCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianCity_OnResume
	.byte 0

ViridianCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end
