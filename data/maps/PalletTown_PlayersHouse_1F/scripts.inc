.set LOCALID_MOM, 1

PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EvenScripts_Mom::
	lock
	faceplayer
	msgbox PalletTown_PlayersHouse_1F_Text_BetterHurry, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BetterHurry:
	.string "Mom: You don't want to miss\n"
	.string "Professor Oak!\p"
	.string "You better hurry!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
	
PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "Running Shoes.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your Running Shoes.\p"
	.string "“Lace up your Running Shoes and hit\n"
	.string "the road running!”$"
