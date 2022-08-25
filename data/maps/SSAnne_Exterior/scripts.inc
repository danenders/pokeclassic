SSAnne_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SSAnne_Exterior_OnResume
	.byte 0

SSAnne_Exterior_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

SSAnne_Exterior_OnResume:
	call Common_EventScript_GetDayOrNight
	end
