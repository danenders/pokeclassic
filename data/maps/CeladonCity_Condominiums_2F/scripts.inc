CeladonCity_Condominiums_2F_MapScripts::
	.byte 0

CeladonCity_Condominiums_2F_EventScript_MeetingRoomSign::
	msgbox CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_2F_Text_GameFreakMeetingRoom::
    .string "Pokémon Journal Meeting Room$"

CeladonCity_Condominiums_2F_EventScript_PokemonJournalErika::
	msgbox PokemonJournal_Text_SpecialFeatureErika, MSGBOX_SIGN
	release
	end

PokemonJournal_Text_SpecialFeatureErika::
	.string "Pokémon Journal:\p"
	.string "Special Feature: Celadon Gym\n"
	.string "Leader Erika!\p"
	.string "Rumor has it that if you peek into\n"
	.string "Celadon Gym, you can often\l"
	.string "see Erika snoozing.$"
