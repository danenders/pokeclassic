CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CinnabarIsland_OnResume
	.byte 0

CinnabarIsland_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

CinnabarIsland_OnResume:
	call Common_EventScript_GetDayOrNight
	end
