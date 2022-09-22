SafariZone_North_RestHouse_MapScripts::
	.byte 0

SafariZone_North_RestHouse_EventScript_Fisher::
	msgbox SafariZone_East_Text_PrizeInDeepestPartOfSafariZone, MSGBOX_NPC
	end

SafariZone_East_Text_PrizeInDeepestPartOfSafariZone::
    .string "Go to the deepest part of the\n"
    .string "Safari Zone. You will win a prize!$"

SafariZone_North_RestHouse_EventScript_Scientist::
	msgbox SafariZone_East_Text_KeepAnyItemFoundOnSafari, MSGBOX_NPC
	end

SafariZone_East_Text_KeepAnyItemFoundOnSafari::
    .string "You can keep any item you find in\n"
    .string "the Safari Zone.\p"
    .string "But, you'll run out of time if you\n"
    .string "try for all of them at once.$"

SafariZone_North_RestHouse_EventScript_Gentleman::
	msgbox SafariZone_East_Text_MyEeveeEvolvedIntoFlareon, MSGBOX_NPC
	end

SafariZone_East_Text_MyEeveeEvolvedIntoFlareon::
    .string "My Eevee evolved into Flareon.\p"
    .string "But, a friend's Eevee turned into a\n"
    .string "Vaporeon. I wonder why?$"

SafariZone_North_RestHouse_EventScript_Woman::
	msgbox SafariZone_North_RestHouse_Text_Woman, MSGBOX_NPC
	end

SafariZone_North_RestHouse_Text_Woman:
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "Pokémon, it gets ignored.\p"
	.string "Do Pokémon have likes and dislikes\n"
	.string "about what they eat?$"

SafariZone_North_RestHouse_EventScript_BaldingMan::
	lock
	faceplayer
	msgbox SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften
	release
	end

SafariZone_North_RestHouse_Text_KogaPatrolsSafariEverySoOften::
    .string "The Safari Zone's huge, wouldn't\n"
    .string "you say?\p"
    .string "Fuchsia's Gym Leader, Koga, \n"
    .string "patrols the grounds every so often.\p"
    .string "Thanks to him, we can play here\n"
    .string "knowing that we're safe.$"
