SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Welcome.\p"
    .string "The President is in the boardroom\n"
    .string "on 11F.$"

SilphCo_1F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "1F$"
