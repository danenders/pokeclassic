CeladonCity_Condominiums_3F_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
    .string "Me?\n"
    .string "I'm the Photographer!$"

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
    .string "I'm the graphic designer!\n"
    .string "Do you like PokéMon Journal?$"

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
    .string "I write the articles!\n"
    .string "Isn't Erika cute?\p"
    .string "I like Misty a lot, too!\n"
    .string "Oh, and Sabrina, I like her!$"

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
    .string "I'm the Editor!\p"
    .string "You're working on the Pokédex?\n"
    .string "Is that right?\p"
    .string "Filling up your Pokédex is tough,\n"
    .string "but don't quit!\p"
    .string "When you finish, come tell me!\p"
    .string "We'll write an article about you!$"

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	special ShowDiploma
	waitstate
	release
	end

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
    .string "Wow! Excellent!\n"
    .string "You completed your Pokédex!\l"
    .string "Congratulations!\l"
    .string "…$"

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
    .string "POKéMON JOURNAL HQ$"

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
    .string "It's an exposé on Team Rocket!\p"
    .string "Looks like they had someone embedded\n"
    .string "in the organization!$"

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
    .string "Someone's playing a game instead of\n"
    .string "working!$"

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
    .string "It's the next issue!\n"
    .string "Professor Oak is on the cover!$"
