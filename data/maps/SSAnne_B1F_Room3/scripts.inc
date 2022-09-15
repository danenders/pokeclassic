SSAnne_B1F_Room3_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
    .string "I like feisty kids like you!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
    .string "Argh!\n"
    .string "Lost it!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
    .string "Sea Pokémon live in deep water.\n"
    .string "You'll need a rod to fish them up!$"

SSAnne_B1F_Room3_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end
