.set LOCALID_NURSE, 1
.set MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_4
	end

.set LOCALID_NURSE, 1

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
    .string "Okay, set six Poké Balls in my\n"
    .string "belt…\p"
    .string "Yeah, that'll do it. At most, you\n"
    .string "can have six Pokémon with you.$"

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
    .string "Team Rocket attacks Cerulean\n"
    .string "citizens…\p"
    .string "Not a day goes by without Team\n"
    .string "Rocket being in the news.$"

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
    .string "Sometimes, you'll have too many\n"
    .string "Pokémon with you to add any more.\p"
    .string "In that case, you should just\n"
    .string "store some using any PC.$"

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_Newspaper, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_Newspaper::
    .string "It's a newspaper.\n"
    .string "TEAM ROCKET ATTACKS CERULEAN\p"
    .string "CITIZENS!\p"
    .string "...multiple break-ins reported\n"
    .string "...gang activity on the rise...\l"
    .string "International Police rumored to\l"
    .string "be getting involved...$"

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	msgbox Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 5, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_Text_BuyMagikarpForJust500::
    .string "Man: Hey there, kid!\n"
    .string "Have I got a deal just for you!\p"
    .string "I'll let you have a secret Pokémon\n"
    .string "- a Magikarp - for just ¥500!\p"
    .string "So, you'll buy it, am I right?$"


Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	call Common_EventScript_NameReceivedBoxMon
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
    .string "Looks like there's no more room\n"
    .string "for any more Pokémon.$"

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney 500
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	hidemoneybox
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
    .string "{PLAYER} paid an outrageous ¥500\n"
    .string "and bought the Magikarp…$"

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
    .string "No? You say no? I'm only doing this\n"
    .string "as a favor to you!$"

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
    .string "You'll need more money than that!$"

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds, MSGBOX_DEFAULT
	release
	end

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
    .string "Man: Well, I don't give refunds.\n"
    .string "You knew what you were getting!$"
