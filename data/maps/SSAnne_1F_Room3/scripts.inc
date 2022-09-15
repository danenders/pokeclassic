SSAnne_1F_Room3_MapScripts::
	.byte 0

SSAnne_1F_Room3_EventScript_LittleGirl::
	msgbox SSAnne_1F_Room3_Text_AlwaysTravelWithJigglypuff, MSGBOX_NPC
	end

SSAnne_1F_Room3_Text_AlwaysTravelWithJigglypuff::
    .string "I always travel with Jigglypuff.\n"
    .string "I never leave home without it.$"

SSAnne_1F_Room3_EventScript_BaldingMan::
	msgbox SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy, MSGBOX_NPC
	end

SSAnne_1F_Room3_Text_CruiseIsElegantAndCozy::
    .string "A world cruise is so elegant yet\n"
    .string "cozy!$"

SSAnne_1F_Room3_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room3_Text_Jigglypuff
	waitmoncry
	release
	end

SSAnne_1F_Room3_Text_Jigglypuff::
    .string "Jigglypuff: Puup pupuu!$"
