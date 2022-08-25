CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCity_OnResume
	.byte 0

CeruleanCity_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end
