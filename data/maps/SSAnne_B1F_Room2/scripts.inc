SSAnne_B1F_Room2_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
    .string "Even us sailors have Pokémon, too!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
    .string "Okay, you're not bad.$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
    .string "We caught all our Pokémon while\n"
    .string "we were out at sea.$"

SSAnne_B1F_Room2_EventScript_ItemTM44::
	finditem ITEM_TM44, 1
	release
	end
