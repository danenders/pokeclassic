FuchsiaCity_Mart_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FuchsiaCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FuchsiaCity_Pokemart::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox FuchsiaCity_Mart_Text_DidYouTryXSpeed, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants, MSGBOX_NPC
	end

FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants::
    .string "Don't they have any pennants\n"
    .string "promoting the Safari Zone\p"
    .string "How about some paper lanterns?\n"
    .string "Aren't there even any calendars?$"

FuchsiaCity_Mart_Text_DidYouTryXSpeed::
    .string "Did you try X Speed?\n"
    .string "It speeds up a Pokémon in battle.$"
