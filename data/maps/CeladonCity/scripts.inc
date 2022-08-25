CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeladonCity_OnResume
	.byte 0

CeladonCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end
