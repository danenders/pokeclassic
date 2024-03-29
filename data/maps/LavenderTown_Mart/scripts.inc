LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavenderTown_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavenderTown_Pokemart::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

LavenderTown_Mart_EventScript_BaldingMan::
	msgbox LavenderTown_Mart_Text_SearchingForStatRaiseItems, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderTown_Mart_Text_DidYouBuyRevives, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Youngster::
	msgbox LavenderTown_Mart_Text_TrainerDuosCanChallengeYou, MSGBOX_NPC
	end

LavenderTown_Mart_Text_SearchingForStatRaiseItems::
    .string "I'm searching for items that raise\n"
    .string "the stats of Pokémon.\p"
    .string "They're effective over the course\n"
    .string "of a single battle.\p"
    .string "X Attack, X Defend, X Speed, \n"
    .string "and X Special are what I'm after.\p"
    .string "Do you know where I can get them?$"

LavenderTown_Mart_Text_DidYouBuyRevives::
    .string "Did you buy some Revives?\n"
    .string "They revive any fainted Pokémon!$"

LavenderTown_Mart_Text_TrainerDuosCanChallengeYou::
    .string "Sometimes, a trainer duo will\n"
    .string "challenge you with two Pokémon\l"
    .string "at the same time.\p"
    .string "If that happens, you have to send\n"
    .string "out two Pokémon to battle, too.$"
