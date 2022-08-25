ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianForest_OnResume
	.byte 0

ViridianForest_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_OnResume:
	call Common_EventScript_GetDayOrNight
	end
