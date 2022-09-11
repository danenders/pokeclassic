CeruleanCity_House1_MapScripts::
	.byte 0

CeruleanCity_House1_EventScript_BulbasaurBreeder::
	msgbox CeruleanCity_House1_Text_HowsThatBulbasaur, MSGBOX_NPC
	release
	end

CeruleanCity_House1_Text_HowsThatBulbasaur::
	.string "How is that Bulbasaur getting\n"
	.string "along with your Pokémon?\p"
	.string "I hope you're treating it well!$"

CeruleanCity_House1_EventScript_BerryGuy::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WATERING_CAN, CeruleanCity_House1_EventScript_GetWailmerPail
	goto_if_set FLAG_DAILY_CERULEAN_BERRY, CeruleanCity_House1_EventScript_GrowAVariety
	goto CeruleanCity_House1_EventScript_GetDailyBerry

CeruleanCity_House1_EventScript_GetDailyBerry::
	msgbox CeruleanCity_House1_Text_PokemonLoveBerries, MSGBOX_DEFAULT
	random 6
	call_if_eq VAR_RESULT, 0, CeruleanCity_House1_EventScript_GiveGrepaBerry
	call_if_eq VAR_RESULT, 1, CeruleanCity_House1_EventScript_GiveHondewBerry
	call_if_eq VAR_RESULT, 2, CeruleanCity_House1_EventScript_GiveKelpsyBerry
	call_if_eq VAR_RESULT, 3, CeruleanCity_House1_EventScript_GivePomegBerry
	call_if_eq VAR_RESULT, 4, CeruleanCity_House1_EventScript_GiveQualotBerry
	call_if_eq VAR_RESULT, 5, CeruleanCity_House1_EventScript_GiveTamatoBerry
	setflag FLAG_DAILY_CERULEAN_BERRY
	goto CeruleanCity_House1_EventScript_GrowAVariety
	end


CeruleanCity_House1_Text_PokemonLoveBerries::
	.string "Pokémon love berries!\p"
	.string "Feeding your Pokémon is a\n"
	.string "great way to strengthen your\l"
	.string "bond.\p"
	.string "Here, why don't you see for\n"
	.string "yourself!$"

CeruleanCity_House1_EventScript_GiveGrepaBerry::
	giveitem ITEM_GREPA_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveHondewBerry::
	giveitem ITEM_HONDEW_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveKelpsyBerry::
	giveitem ITEM_KELPSY_BERRY, 1
	return

CeruleanCity_House1_EventScript_GivePomegBerry::
	giveitem ITEM_POMEG_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveQualotBerry::
	giveitem ITEM_QUALOT_BERRY, 1
	return

CeruleanCity_House1_EventScript_GiveTamatoBerry::
	giveitem ITEM_TAMATO_BERRY, 1
	return

CeruleanCity_House1_EventScript_GrowAVariety::
	msgbox CeruleanCity_House1_Text_GrowAVariety, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_GrowAVariety::
	.string "There are all kinds of berries.\p"
	.string "And they don't all have the\n"
	.string "same effects!\p"
	.string "Try growing a variety!$"

CeruleanCity_House1_EventScript_GetWailmerPail::
	msgbox CeruleanCity_House1_Text_WifeAndIGrowBerries, MSGBOX_DEFAULT
	checkitemspace ITEM_WAILMER_PAIL, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House1_EventScript_BagFull
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_House1_Text_GetWailmerPail, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_WAILMER_PAIL
	setflag FLAG_RECEIVED_WATERING_CAN
	goto CeruleanCity_House1_EventScript_GetDailyBerry
	end

CeruleanCity_House1_Text_GetWailmerPail::
	.string "{PLAYER} received the Watering Can\n"
	.string "from the Berry Guy!\p"
	.string "{PLAYER} put the Watering Can into\n"
	.string "the Key Items pocket.$"

CeruleanCity_House1_Text_WifeAndIGrowBerries::
	.string "You may not know this, but Kanto\n"
	.string "didn't aways have Berries!\p"
	.string "They can be really hard to grow\n"
	.string "and people didn't really know\l"
	.string "about berries back then.\p"
	.string "So, my wife and I traveled across\n"
	.string "Kanto planting Berry Trees!\p"
	.string "If you see any of them, please\n"
	.string "help yourself.\p"
	.string "We want everyone to take better\n"
	.string "care of the land, for both people\l"
	.string "and Pokémon!\p"
	.string "So if you pick a berry, please plant\n"
	.string "another! And if you have a moment,\l"
	.string "you can water them with this!$"

CeruleanCity_House1_EventScript_BagFull::
	msgbox CeruleanCity_House1_Text_MaybeLater, MSGBOX_DEFAULT
	release
	end

CeruleanCity_House1_Text_MaybeLater::
 .string "Oops - your bag is full.\p"
 .string "Maybe come back later?$"


