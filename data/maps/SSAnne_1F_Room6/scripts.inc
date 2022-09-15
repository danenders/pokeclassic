SSAnne_1F_Room6_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_Text_TakeAShortRest::
    .string "You look tired. Would you like to\n"
    .string "take a short rest?$"

SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed::
    .string "I'm glad to see that everyone is\n"
    .string "looking refreshed and chipper.$"

SSAnne_1F_Room6_EventScript_DeclineHeal::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone
	release
	end

SSAnne_1F_Room6_Text_SorryYouLookLikeSomeone::
    .string "Oh, I'm sorry for fussing over you.\n"
    .string "You just remind me of my grandchild…$"
