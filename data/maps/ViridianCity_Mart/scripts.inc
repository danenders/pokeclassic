.set LOCALID_EMPLOYEE, 1

ViridianCity_Mart_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ViridianCity_Mart_OnFrame
	.byte 0

ViridianCity_Mart_OnFrame:
	map_script_2 VAR_ADVENTURE_BEGINS, 4, ViridianCity_Mart_EventScript_GetOakParcel
	.2byte 0


ViridianCity_Mart_EventScript_GetOakParcel::
	lockall
	turnobject LOCALID_EMPLOYEE, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_EMPLOYEE, Common_Movement_Delay48
	waitmovement 1
	msgbox ViridianCity_Mart_Text_YouCameFromPallet, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	turnobject LOCALID_EMPLOYEE, DIR_EAST
	msgbox ViridianCity_Mart_Text_TakeThisToProfOak, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message ViridianCity_Mart_Text_ReceivedOaksParcelFromClerk
	waitmessage
	waitfanfare
	msgbox ViridianCity_Mart_Text_SayHiToOakForMe, MSGBOX_DEFAULT
	closemessage
	additem ITEM_OAKS_PARCEL
	setvar VAR_ADVENTURE_BEGINS, 5
	setvar VAR_OAK_LAB_STATE, 6
	release
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end


ViridianCity_Mart_Text_YouCameFromPallet::
    .string "Hey!\n"
    .string "You came from Pallet Town?$"

ViridianCity_Mart_Text_TakeThisToProfOak::
    .string "You know Professor Oak, right?\p"
    .string "His order came in.\n"
    .string "Can I get you to take it to him?$"

ViridianCity_Mart_Text_ReceivedOaksParcelFromClerk::
    .string "{PLAYER} received Oak's Parcel\n"
    .string "from the Pokémon Mart clerk.$"

ViridianCity_Mart_Text_SayHiToOakForMe::
    .string "Okay, thanks! Please say hi to\n"
    .string "Professor Oak for me, too.$"

ViridianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	goto_if_le VAR_OAK_LAB_STATE, 7, ViridianCity_Mart_EventScript_SayHiToOak
	message gText_HowMayIServeYou
	waitmessage
	pokemart ViridianCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ViridianCity_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_NONE
	release
	end

ViridianCity_Mart_EventScript_SayHiToOak::
	msgbox ViridianCity_Mart_Text_SayHiToOakForMe, MSGBOX_DEFAULT
	release
	end

ViridianCity_Mart_EventScript_Customer1::
	lock
	faceplayer
	msgbox ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes, MSGBOX_DEFAULT
	release
	end

ViridianCity_Mart_Text_ShopDoesGoodBusinessInAntidotes::
    .string "This shop does good business in\n"
    .string "antidotes, I've heard.$"

ViridianCity_Mart_EventScript_Customer2::
	lock
	faceplayer
	msgbox ViridianCity_Mart_Text_GotToBuySomePotions, MSGBOX_DEFAULT
	release
	end

ViridianCity_Mart_Text_GotToBuySomePotions::
    .string "I've got to buy some potions.\p"
    .string "You never know when your Pokémon\n"
    .string "will need quick healing.$"
