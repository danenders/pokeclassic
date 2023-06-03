.set LOCALID_FUGITIVE, 18

Route10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route10_OnResume
	.byte 0

Route10_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route10_OnResume:
	call Common_EventScript_GetDayOrNight
	end


Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_Text_RockTunnelDetourToLavender::
    .string "Rock Tunnel\n"
    .string "Detour to Lavender Town$"

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_Text_RockTunnel::
    .string "Rock Tunnel$"

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_Text_PowerPlant::
    .string "Power Plant$"

Route10_EventScript_Mark::
	trainerbattle_single REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkIntro, Route10_Text_MarkDefeat, Route10_EventScript_RegisterMarkAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route10_EventScript_MarkRematch
	msgbox Route10_Text_MarkPostBattle, MSGBOX_DEFAULT
	release
	end

Route10_Text_MarkIntro::
    .string "Wow, you came all the way here?\n"
    .string "Maybe you're a PokéManiac, too?\l"
    .string "Want to see my collection?$"

Route10_Text_MarkDefeat::
    .string "Humph.\n"
    .string "I'm not angry!$"

Route10_Text_MarkPostBattle::
    .string "I have more rare Pokémon at home!$"

Route10_EventScript_RegisterMarkAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route10_Text_MarkRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_POKEMANIAC_MARK_1
	release
	end

Route10_Text_MarkRegister:
	.string "If you give me your number,\n"
	.string "I'll show you my Pokémon\l"
	.string "collection sometime.$"

Route10_EventScript_MarkRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_POKEMANIAC_MARK_1, Route10_Text_MarkRematchIntro, Route10_Text_MarkDefeat
	msgbox Route10_Text_MarkRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_MarkRematchIntro::
	.string "My Pokémon!\n"
	.string "Let me show you them!$"

Route10_Text_MarkRematchPostBattle::
	.string "You're the real PokéManiac!$"


Route10_EventScript_Herman::
	trainerbattle_single TRAINER_POKEMANIAC_HERMAN, Route10_Text_HermanIntro, Route10_Text_HermanDefeat
	msgbox Route10_Text_HermanPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HermanIntro::
    .string "Hi, kid!\n"
    .string "Want to see my Pokémon?$"

Route10_Text_HermanDefeat::
    .string "Oh, no!\n"
    .string "My Pokémon!$"

Route10_Text_HermanPostBattle::
    .string "I don't like you.\n"
    .string "I don't like anyone better than me!$"

Route10_EventScript_Heidi::
	trainerbattle_single TRAINER_PICNICKER_HEIDI, Route10_Text_HeidiIntro, Route10_Text_HeidiDefeat
	msgbox Route10_Text_HeidiPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_HeidiIntro::
    .string "I've been out at a Pokémon Gym\n"
    .string "a few times.\p"
    .string "…But I always lose.$"

Route10_Text_HeidiDefeat::
    .string "Ohh!\n"
    .string "After all my training!$"

Route10_Text_HeidiPostBattle::
    .string "I noticed some PokéManiacs\n"
    .string "prowling around.\p"
    .string "Can you imagine? Them?\n"
    .string "Up here in the mountains?$"

Route10_EventScript_Carol::
	trainerbattle_single TRAINER_PICNICKER_CAROL, Route10_Text_CarolIntro, Route10_Text_CarolDefeat
	msgbox Route10_Text_CarolPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_CarolIntro::
    .string "I'm feeling a bit faint.\n"
    .string "I haven't hiked in some time.$"

Route10_Text_CarolDefeat::
    .string "I'm too tired.\n"
    .string "I wasn't up for it.$"

Route10_Text_CarolPostBattle::
    .string "The Pokémon here in the mountains\n"
    .string "are so chunky…\p"
    .string "I wish there were pink Pokémon\n"
    .string "with a floral pattern!$"

Route10_EventScript_Clark::
	trainerbattle_single TRAINER_HIKER_CLARK, Route10_Text_ClarkIntro, Route10_Text_ClarkDefeat
	msgbox Route10_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_ClarkIntro::
    .string "Ha-hahah-ah-ha!$"

Route10_Text_ClarkDefeat::
    .string "Ha-haha!\n"
    .string "Not laughing!\l"
    .string "Ha-hay fever! Haha-ha-choo!$"

Route10_Text_ClarkPostBattle::
    .string "Haha-ha-choo!\n"
    .string "Ha-choo!\l"
    .string "Snort! Snivel!$"

Route10_EventScript_Trent::
	trainerbattle_single TRAINER_HIKER_TRENT, Route10_Text_TrentIntro, Route10_Text_TrentDefeat
	msgbox Route10_Text_TrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route10_Text_TrentIntro::
    .string "Ah!\n"
    .string "This mountain air is delicious!$"

Route10_Text_TrentDefeat::
    .string "That cleared my head!$"

Route10_Text_TrentPostBattle::
    .string "I feel bloated on mountain air!$"

Route10_EventScript_LightBall::
	finditem ITEM_LIGHT_BALL, 1
	release
	end

Route10_EventScript_BerryLass::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_HEALING_BERRY, Route10_EventScript_GotDailyBerry
	msgbox Route10_Text_BerryLass, MSGBOX_DEFAULT
	random 7
	call_if_eq VAR_RESULT, 0, Route10_EventScript_GiveOranBerry
	call_if_eq VAR_RESULT, 1, Route10_EventScript_GiveSitrusBerry
	call_if_eq VAR_RESULT, 2, Route10_EventScript_GiveFigyBerry
	call_if_eq VAR_RESULT, 3, Route10_EventScript_GiveWikiBerry
	call_if_eq VAR_RESULT, 4, Route10_EventScript_GiveMagoBerry
	call_if_eq VAR_RESULT, 5, Route10_EventScript_GiveAguavBerry
	call_if_eq VAR_RESULT, 6, Route10_EventScript_GiveIapapaBerry
	setflag FLAG_DAILY_HEALING_BERRY
	goto Route10_EventScript_GotDailyBerry
	end

Route10_EventScript_GiveOranBerry::
	giveitem ITEM_ORAN_BERRY, 1
	return

Route10_EventScript_GiveSitrusBerry::
	giveitem ITEM_SITRUS_BERRY, 1
	return

Route10_EventScript_GiveFigyBerry::
	giveitem ITEM_FIGY_BERRY, 1
	return

Route10_EventScript_GiveWikiBerry::
	giveitem ITEM_WIKI_BERRY, 1
	return

Route10_EventScript_GiveMagoBerry::
	giveitem ITEM_MAGO_BERRY, 1
	return

Route10_EventScript_GiveAguavBerry::
	giveitem ITEM_AGUAV_BERRY, 1
	return

Route10_EventScript_GiveIapapaBerry::
	giveitem ITEM_IAPAPA_BERRY, 1
	return

Route10_Text_BerryLass::
	.string "You never know how long it may\n"
	.string "be before you find the next Pokémon\l"
	.string "Center.\p"
	.string "Berries can help you out in a pinch.$"

Route10_EventScript_GotDailyBerry::
	msgbox Route10_Text_BerryPrepared, MSGBOX_NPC
	release
	end

Route10_Text_BerryPrepared::
	.string "I always make sure to have some\n"
	.string "Berries with me when I go out.\p"
	.string "You could say I'm berry prepared.\p"
	.string "...\p"
	.string "Get it?$"

Route10_RocketFugitive::
	trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
	msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_ROCKET_FUGITIVE_CAPTURED
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	removeobject LOCALID_FUGITIVE
	waitse
	fadescreen FADE_FROM_BLACK
	end
