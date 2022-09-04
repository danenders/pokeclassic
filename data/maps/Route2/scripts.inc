Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route2_OnResume
	.byte 0

Route2_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route2_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route2_EventScript_RouteSign::
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_Text_RouteSign::
    .string "Route 2\n"
    .string "Viridian City - Pewter City$"

Route2_EventScript_DiglettsCaveSign::
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_Text_DiglettsCave::
    .string "Diglett'S Cave$"

Route2_FindItem_Ether::
	finditem ITEM_ETHER, 1
	end

Route2_FindItem_ParlyzHeal::
	finditem ITEM_PARALYZE_HEAL, 1
	end
