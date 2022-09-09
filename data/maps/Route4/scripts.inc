Route4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route4_OnResume
	.byte 0

Route4_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route4_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route4_EventScript_Boy::
	msgbox Route4_Text_PeopleLikeAndRespectBrock, MSGBOX_NPC
	release
	end

Route4_Text_PeopleLikeAndRespectBrock::
    .string "Oh, wow, that's the Boulder Badge!\n"
    .string "You got it from Brock, didn't you?\p"
    .string "Brock is cool. He's not just tough.\n"
    .string "People like and respect him.\p"
    .string "I want to become a Gym Leader\n"
    .string "like him.$"

Route4_EventScript_Woman::
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_Text_TrippedOverGeodude::
    .string "Ouch! I tripped over a rocky\n"
    .string "Pokémon, Geodude!$"

Route4_EventScript_MtMoonSign::
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_Text_MtMoonEntrance::
    .string "Mt. Moon\n"
    .string "Tunnel Entrance$"

Route4_EventScript_RouteSign::
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_Text_RouteSign::
    .string "Route 4\n"
    .string "Mt. Moon - Cerulean City$"

Route4_EventScript_Crissy::
    trainerbattle_single TRAINER_LASS_ROBIN, Route4_Text_CrissyIntro, Route4_Text_CrissyDefeat
    msgbox Route4_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
    end

Route4_Text_CrissyIntro::
    .string "I came to MT. MOON in search of\n"
    .string "mushroom Pokémon.$"

Route4_Text_CrissyDefeat::
    .string "After all I did to catch them!$"

Route4_Text_CrissyPostBattle::
    .string "There might not be any more\n"
    .string "mushrooms here.\p"
    .string "I think I got them all.$"

Route4_EventScript_ItemTM05::
	finditem ITEM_TM05, 1
	end
