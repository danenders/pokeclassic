EventScript_Dresser::
	lockall
	msgbox Text_ChangeClothes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CloseDresser
	message Text_ChooseRegionStyle
	waitmessage
	multichoicedefault 0, 0, MULTI_DRESSER_DRAWERS, 5, FALSE
	switch VAR_RESULT
	case 0, EventScript_KantoCostumes
	case 1, EventScript_JohtoCostumes
	case 2, EventScript_HoennCostumes
	case 3, EventScript_SinnohCostumes
	case 4, EventScript_Dresser_Exit
	case MULTI_B_PRESSED, EventScript_Dresser_Exit
	end

Text_ChangeClothes:
	.string "It's full of clean clothes!\p"
	.string "Would you like to change?$"

Text_ChooseRegionStyle:
	.string "Which drawer do you want to\n"
	.string "to choose an outfit from?$"

EventScript_CloseDresser::
	closemessage
	releaseall
	end

EventScript_Dresser_Exit::
	closemessage
	msgbox Text_ChangeClothes_Cancel, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EventScript_Dresser_Loop
	releaseall
	end

Text_ChangeClothes_Cancel:
	.string "Would you like to keep\n"
	.string "your current outfit?$"

EventScript_Dresser_Loop::
	message Text_ChooseRegionStyle
	waitmessage
	multichoicedefault 0, 0, MULTI_DRESSER_DRAWERS, 4, FALSE
	switch VAR_RESULT
	case 0, EventScript_KantoCostumes
	case 1, EventScript_JohtoCostumes
	case 2, EventScript_HoennCostumes
	case 3, EventScript_SinnohCostumes
	case MULTI_B_PRESSED, EventScript_Dresser_Exit
	end

Text_ChooseOutfit:
	.string "There are lots of options!\n"
	.string "Choose a style!$"

EventScript_KantoCostumes::
	msgbox Text_ChooseOutfit
	waitmessage
	multichoicedefault 0, 0, MULTI_KANTO_COSTUMES, 3, FALSE
	switch VAR_RESULT
	case 0, EventScript_CostumeSwap_Red
	case 1, EventScript_CostumeSwap_Leaf
	case 2, EventScript_Dresser_Loop
	case MULTI_B_PRESSED, EventScript_Dresser_Loop
	end

EventScript_CostumeSwap_Red::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, RED_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_Leaf::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, LEAF_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end


EventScript_JohtoCostumes::
	msgbox Text_ChooseOutfit
	waitmessage
	multichoicedefault 0, 0, MULTI_JOHTO_COSTUMES, 4, FALSE
	switch VAR_RESULT
	case 0, EventScript_CostumeSwap_Ethan
	case 1, EventScript_CostumeSwap_Lyra
	case 2, EventScript_CostumeSwap_Kris
	case 3, EventScript_Dresser_Loop
	case MULTI_B_PRESSED, EventScript_Dresser_Loop
	end

EventScript_CostumeSwap_Ethan::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, ETHAN_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_Lyra::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, LYRA_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_Kris::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, KRIS_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end


EventScript_HoennCostumes::
	msgbox Text_ChooseOutfit
	waitmessage
	multichoicedefault 0, 0, MULTI_HOENN_COSTUMES, 3, FALSE
	switch VAR_RESULT
	case 0, EventScript_CostumeSwap_Brendan
	case 1, EventScript_CostumeSwap_May
	case 2, EventScript_Dresser_Loop
	case MULTI_B_PRESSED, EventScript_Dresser_Loop
	end

EventScript_CostumeSwap_Brendan::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, BRENDAN_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_May::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, MAY_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end


EventScript_SinnohCostumes::
	msgbox Text_ChooseOutfit
	waitmessage
	multichoicedefault 0, 0, MULTI_SINNOH_COSTUMES, 5, FALSE
	switch VAR_RESULT
	case 0, EventScript_CostumeSwap_Lucas
	case 1, EventScript_CostumeSwap_Dawn
	case 2, EventScript_CostumeSwap_LucasPlatinum
	case 3, EventScript_CostumeSwap_DawnPlatinum
	case 4, EventScript_Dresser_Loop
	case MULTI_B_PRESSED, EventScript_Dresser_Loop
	end

EventScript_CostumeSwap_Lucas::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, LUCAS_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_Dawn::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, DAWN_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_LucasPlatinum::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, LUCAS_PLATINUM_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_CostumeSwap_DawnPlatinum::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_TEMP_1, DAWN_PLATINUM_COSTUME
	special SwapPlayersCostume
	fadescreen FADE_FROM_BLACK
	goto EventScript_Dresser_Finish
	end

EventScript_Dresser_Finish::
	closemessage
	msgbox Text_ChangeClothes_Confirm, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, EventScript_Dresser_Loop
	msgbox Text_ChangeClothes_Finished, MSGBOX_DEFAULT
	releaseall
	end

Text_ChangeClothes_Confirm:
	.string "Wear this outfit?$"

Text_ChangeClothes_Finished:
	.string "Lookin' good!$"
