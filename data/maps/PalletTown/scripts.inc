PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PalletTown_OnResume
	.byte 0

PalletTown_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

PalletTown_OnResume:
	call Common_EventScript_GetDayOrNight
	end