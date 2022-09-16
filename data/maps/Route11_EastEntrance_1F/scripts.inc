Route11_EastEntrance_1F_MapScripts::
	.byte 0

Route11_EastEntrance_1F_EventScript_TopGuard::
	msgbox Route11_EastEntrance_1F_Text_ManInLavenderRatesNames, MSGBOX_NPC
	end

Route11_EastEntrance_1F_Text_ManInLavenderRatesNames::
    .string "Don't you think it's hard to think\n"
    .string "up good names for Pokémon?\p"
    .string "Especially if you've caught a\n"
    .string "whole bunch?\p"
    .string "In Lavender Town, there's a man\n"
    .string "who rates Pokémon nicknames.\p"
    .string "He can even help you rename your\n"
    .string "Pokémon, too.$"

Route11_EastEntrance_1F_EventScript_BottomGuard::
	msgbox Route11_EastEntrance_1F_Text_RockTunnelToReachLavender, MSGBOX_NPC
	end

Route11_EastEntrance_1F_Text_RockTunnelToReachLavender::
    .string "If you're aiming to reach Lavender\n"
    .string "Town, take Rock Tunnel.\p"
    .string "You can get to Rock Tunnel from\n"
    .string "Cerulean City.$"
