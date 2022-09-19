.set LOCALID_PORYGON, 2

CeladonCity_Condominiums_RoofRoom_MapScripts::
	.byte 0

CeladonCity_Condominiums_RoofRoom_EventScript_Maniac::
	goto_if_set FLAG_GOT_PORYGON, CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon, MSGBOX_NPC
	end

CeladonCity_Condominiums_RoofRoom_Text_CreatedMyOwnPokemon::
	.string "If Pokémon can be turned into\n"
	.string "data and stored in a PC, then\l"
	.string "we should be able to artifically\l"
	.string "create Pokémon, right?\p"
	.string "That was my hypothesis - and I\n"
	.string "proved it by creating Porygon!\p"
	.string "Don't believe me?\p"
	.string "Take the Poké Ball over there,\n"
	.string "you can have my Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_AlreadyGotPorygon::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked, MSGBOX_NPC
	release
	end

CeladonCity_Condominiums_RoofRoom_Text_CanAPokemonBeHacked::
	.string "If we can turn Pokémon into\n"
	.string "data, does that mean a Pokémon  \l"
	.string "can be hacked?$"

CeladonCity_Condominiums_RoofRoom_EventScript_TMsPamphlet::
	msgbox CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs, MSGBOX_SIGN
	end

CeladonCity_Condominiums_RoofRoom_Text_PamphletOnTMs::
    .string "It's an email about TMs.\p"
    .string "… …\p"
    .string "There are fifty TMs in all.\p"
    .string "There are also eight HMs that\n"
    .string "can be used in the field!\p"
    .string "SILPH CO.$"

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonBall::
    setvar VAR_TEMP_1, SPECIES_PORYGON
    givemon SPECIES_PORYGON, 25, ITEM_NONE
    goto_if_eq VAR_RESULT, 0, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty
    goto_if_eq VAR_RESULT, 1, CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC
    goto_if_eq VAR_RESULT, 2, CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonParty::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    call Common_EventScript_GetGiftMonPartySlot
    call Common_EventScript_NameReceivedPartyMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon::
    playfanfare MUS_LEVEL_UP
    message CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon
    waitmessage
    waitfanfare
    bufferspeciesname STR_VAR_1, SPECIES_PORYGON
    return

CeladonCity_Condominiums_RoofRoom_EventScript_Text_FoundPorygon::
    .string "{PLAYER} found a Poké Ball.\n"
    .string "It contained a Porygon!$"

CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon::
    setflag FLAG_GOT_PORYGON
    removeobject LOCALID_PORYGON
    release
    end

CeladonCity_Condominiums_RoofRoom_EventScript_PorygonPC::
    call CeladonCity_Condominiums_RoofRoom_EventScript_GetPorygon
    msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    call Common_EventScript_NameReceivedBoxMon
    goto CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_TransferPorygon::
    call Common_EventScript_TransferredToPC
    goto CeladonCity_Condominiums_RoofRoom_EventScript_GotPorygon
    end

CeladonCity_Condominiums_RoofRoom_EventScript_NoRoomForPorygon::
    msgbox CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
    release
    end

CeladonCity_Condominiums_RoofRoom_Text_NoRoomForMorePokemon::
    .string "Oh! You don't have room\n"
    .string "for any more Pokémon!$"
