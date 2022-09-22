SafariZone_West_RestHouse_MapScripts::
	.byte 0


SafariZone_West_RestHouse_EventScript_Man::
	msgbox SafariZone_West_Text_BaitMakesMonStickAround, MSGBOX_NPC
	end

SafariZone_West_Text_BaitMakesMonStickAround::
	.string "I don't have any {POKEBLOCK}s, but I caught\n"
	.string "a good number of Pokémon.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a Safari Ball.$"

SafariZone_West_RestHouse_EventScript_Scientist::
	msgbox SafariZone_West_Text_RocksMakeMonRunButEasierCatch, MSGBOX_NPC
	end

SafariZone_West_Text_RocksMakeMonRunButEasierCatch::
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} Feeder.\n"
	.string "But it seems to have disappeared.\p"
	.string "I guess Pokémon must have eaten it\n"
	.string "without me noticing.$"


SafariZone_West_RestHouse_EventScript_CooltrainerF::
	msgbox SafariZone_West_Text_HikedLotsDidntSeeMonIWanted, MSGBOX_NPC
	end

SafariZone_West_Text_HikedLotsDidntSeeMonIWanted::
    .string "I hiked a lot, but I didn't see any\n"
    .string "Pokémon I wanted.$"
