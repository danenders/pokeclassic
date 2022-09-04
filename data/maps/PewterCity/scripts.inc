PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PewterCity_OnResume
	.byte 0

PewterCity_OnTransition:
	setflag FLAG_VISITED_PEWTER_CITY
	call Common_EventScript_GetDayOrNight
	end

PewterCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

PewterCity_Trigger_RegisterOakAide::
	lockall
	goto_if_set FLAG_REGISTERED_AIDE, Common_EventScript_End
	goto_if_unset FLAG_MET_CEDAR, PewterCity_Trigger_RegisterOakAideAlternate
	pokenavcall MatchCall_Text_AideIntro
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	releaseall
	end

PewterCity_Trigger_RegisterOakAideAlternate::
	pokenavcall MatchCall_Text_AideIntro2
	waitmessage
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOaksAide, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_AIDE
	setflag FLAG_HIDE_AIDE_OAK_LAB
	releaseall
	end
