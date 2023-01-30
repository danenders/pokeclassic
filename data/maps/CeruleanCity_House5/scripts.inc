CeruleanCity_House5_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BadgeGuy::
	msgbox CeruleanCity_House5_Text_BadgesHaveAmazingSecrets, MSGBOX_NPC
	release
	end

CeruleanCity_House5_Text_BadgesHaveAmazingSecrets::
	.string "Badges are more than just a cool pin!\p"
	.string "A badge certifies a Trainer to use\n"
	.string "certain Hidden Moves, like Flash or\l"
	.string "Fly.\p"
	.string "Pokémon seem to understand their\n"
	.string "importance as well.\p"
	.string "Higher level Pokémon won't obey you\n"
	.string "if you don't have enough badges!$"

CeruleanCity_House5_EventScript_BadgeSign::
	msgbox CeruleanCity_House5_Text_BadgeSign, MSGBOX_SIGN
	release
	end

CeruleanCity_House5_Text_BadgeSign::
	.string "Official Pokémon League\n"
	.string "Badge Expert Certification$"
