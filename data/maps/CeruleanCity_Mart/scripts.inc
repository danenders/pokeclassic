CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Youngster::
	msgbox CeruleanCity_Mart_Text_RepelWorksOnWeakMons, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_RepelWorksOnWeakMons::
    .string "Repel not only keeps bugs away,\n"
    .string "it also works on weak Pokémon.\p"
    .string "Put your strongest Pokémon at the\n"
    .string "left of the Pokémon LIST.\p"
    .string "If your first Pokémon is strong,\n"
    .string "REPEL's effect is boosted.$"

CeruleanCity_Mart_EventScript_Woman::
	msgbox CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy, MSGBOX_NPC
	end

CeruleanCity_Mart_Text_DoYouKnowAboutRareCandy::
    .string "Do you know about Rare Candy?\n"
    .string "They don't sell it in shops.\p"
    .string "I think it makes Pokémon grow\n"
    .string "very quickly all of a sudden.$"

CeruleanCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeruleanCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CeruleanCity_Pokemart::
	.2byte ITEM_POKE_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end
