SafariZone_Center_RestHouse_MapScripts::
	.byte 0

SafariZone_Center_RestHouse_EventScript_Sara::
	msgbox SafariZone_Center_Text_WhereDidErikGo, MSGBOX_NPC
	end

SafariZone_Center_Text_WhereDidErikGo::
    .string "Sara: Where did my boyfriend,\n"
    .string "Erik, go?$"

SafariZone_Center_RestHouse_EventScript_Scientist::
	msgbox SafariZone_Center_Text_CatchingMonsAsGifts, MSGBOX_NPC
	end

SafariZone_Center_Text_CatchingMonsAsGifts::
    .string "I'm catching Pokémon to take home\n"
    .string "as gifts.$"


SafariZone_Center_RestHouse_EventScript_RangerF::
	msgbox SafariZone_Center_RestHouse_Text_RangerF, MSGBOX_NPC
	end

SafariZone_Center_RestHouse_Text_RangerF:
	.string "If you use {POKEBLOCK}s, wild Pokémon won't\n"
	.string "be so quick to run away.\p"
	.string "It's not much use to give {POKEBLOCK}s to\n"
	.string "Pokémon that don't flee easily.$"
