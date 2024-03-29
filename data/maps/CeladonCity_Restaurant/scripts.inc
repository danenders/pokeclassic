CeladonCity_Restaurant_MapScripts::
	.byte 0
CeladonCity_Restaurant_EventScript_Chef::
	msgbox CeladonCity_Restaurant_Text_TakingBreakRightNow, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_TakingBreakRightNow::
    .string "Hi!\p"
    .string "Sorry, but we're taking a break\n"
    .string "right now.$"

CeladonCity_Restaurant_EventScript_Woman::
	msgbox CeladonCity_Restaurant_Text_OftenGoToDrugstore, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_OftenGoToDrugstore::
    .string "My Pokémon are weak, so I often\n"
    .string "have to go to the Drugstore.$"

CeladonCity_Restaurant_EventScript_CoinCaseMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase
	msgbox CeladonCity_Restaurant_Text_TakeThisImBusted
	checkitemspace ITEM_COIN_CASE, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Restaurant_EventScript_NoRoomForCoinCase
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan
	waitfanfare
	waitmessage
	additem ITEM_COIN_CASE, 1
	setflag FLAG_RECEIVED_COIN_CASE
	release
	end

CeladonCity_Restaurant_Text_TakeThisImBusted::
    .string "Go ahead! Laugh!\n"
    .string "I'm flat-out busted!\p"
    .string "No more slots for me!\n"
    .string "I'm going straight!\p"
    .string "Here!\n"
    .string "I won't be needing this anymore!$"

CeladonCity_Restaurant_Text_ReceivedCoinCaseFromMan::
    .string "{PLAYER} received a Coin Case\n"
    .string "from the man.$"

CeladonCity_Restaurant_EventScript_NoRoomForCoinCase::
	msgbox CeladonCity_Restaurant_Text_MakeRoomForThis
	release
	end

CeladonCity_Restaurant_Text_MakeRoomForThis::
    .string "Make room for this!$"

CeladonCity_Restaurant_EventScript_AlreadyGotCoinCase::
	msgbox CeladonCity_Restaurant_Text_ThoughtIdWinItBack
	release
	end

CeladonCity_Restaurant_Text_ThoughtIdWinItBack::
    .string "I always thought I was going to\n"
    .string "win it back…$"

CeladonCity_Restaurant_EventScript_WorkerM::
	msgbox CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_PsstBasementUnderGameCorner::
    .string "Psst! There's a secret basement \n"
    .string "under the Game Corner, I hear.$"

CeladonCity_Restaurant_EventScript_FatMan::
	msgbox CeladonCity_Restaurant_Text_ManLostItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Restaurant_Text_ManLostItAllAtSlots::
    .string "Munch…\p"
    .string "The man at that table lost it all\n"
    .string "at the slots.$"
