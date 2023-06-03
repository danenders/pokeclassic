.set LOCALID_FUGITIVE, 16

Route12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
	.byte 0

Route12_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route12_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route12_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route12_EventScript_RouteSign::
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
	end

Route12_Text_RouteSign::
    .string "Route 12 \n"
    .string "North to Lavender$"

Route12_EventScript_FishingSign::
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
	end

Route12_Text_SportfishingArea::
    .string "Sportfishing Area$"

@Snorlax
Route12_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route12_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route12_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE12_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route12_EventScript_FoughtSnorlax
	release
	end

Route12_EventScript_DontUsePokeFlute::
	release
	end

Route12_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route12_EventScript_SnorlaxNoPokeFlute::
	msgbox Route12_Text_MonSprawledOutInSlumber
	release
	end

Route12_Text_MonSprawledOutInSlumber::
    .string "A Pokémon is sprawled out in\n"
    .string "a deep and comfortable slumber.$"

Text_PlayedPokeFlute::
    .string "{PLAYER} played the Poké Flute.$"

@Trainers
Route12_EventScript_Ned::
	trainerbattle_single REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedIntro, Route12_Text_NedDefeat, Route12_EventScript_RegisterNedAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_NedRematch
	msgbox Route12_Text_NedPostBattle, MSGBOX_DEFAULT
	release
	end

Route12_Text_NedIntro::
    .string "Yeah!\n"
    .string "I got a bite here!$"

Route12_Text_NedDefeat::
    .string "Tch!\n"
    .string "Just a small fry…$"

Route12_Text_NedPostBattle::
    .string "Hang on!\n"
    .string "My line's snagged!$"

Route12_EventScript_RegisterNedAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route12_Text_NedRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_FISHERMAN_NED_1
	release
	end

Route12_Text_NedRegister:
	.string "Give me a call if you ever\n"
	.string "want to go fishing.$"

Route12_EventScript_NedRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_FISHERMAN_NED_1, Route12_Text_NedRematchIntro, Route12_Text_NedDefeat
	msgbox Route12_Text_NedRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_NedRematchIntro::
	.string "Whoa!\n"
	.string "This is gonna be a big one!$"

Route12_Text_NedRematchPostBattle::
	.string "Just another Magikarp.$"

Route12_EventScript_Luca::
    trainerbattle_single REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaIntro, Route12_Text_LucaDefeat, Route12_EventScript_RegisterLucaAfterBattle
    specialvar VAR_RESULT, ShouldTryRematchBattle
    goto_if_eq VAR_RESULT, TRUE, Route12_EventScript_LucaRematch
    msgbox Route12_Text_LucaPostBattle, MSGBOX_DEFAULT
    release
    end

Route12_Text_LucaIntro::
    .string "Electricity is my specialty.\p"
    .string "I don't know a thing about Pokémon\n"
    .string "of the sea, though.$"

Route12_Text_LucaDefeat::
    .string "Unplugged!$"

Route12_Text_LucaPostBattle::
    .string "Water conducts electricity, so you\n"
    .string "should zap sea Pokémon.$"

Route12_EventScript_RegisterLucaAfterBattle::
    special PlayerFaceTrainerAfterBattle
    waitmovement 0
    msgbox Route12_Text_LucaRegister, MSGBOX_DEFAULT
    register_matchcall REMATCHABLE_TRAINER_ROCKER_LUCA_1
    release
    end

Route12_Text_LucaRegister:
    .string "After I recharge, let's have\n"
    .string "a rematch.$"

Route12_EventScript_LucaRematch::
    trainerbattle_rematch REMATCHABLE_TRAINER_ROCKER_LUCA_1, Route12_Text_LucaRematchIntro, Route12_Text_LucaDefeat
    msgbox Route12_Text_LucaRematchPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_LucaRematchIntro::
    .string "I still don't know a thing \n"
    .string "about Pokémon of the sea.$"

Route12_Text_LucaRematchPostBattle::
    .string "Zapped!$"

Route12_EventScript_Chip::
	trainerbattle_single TRAINER_FISHERMAN_CHIP, Route12_Text_ChipIntro, Route12_Text_ChipDefeat
	msgbox Route12_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route12_Text_ChipIntro::
    .string "Be patient.\n"
    .string "Fishing is a waiting game.$"

Route12_Text_ChipDefeat::
    .string "That one got away!$"

Route12_Text_ChipPostBattle::
    .string "With a better rod, I could catch\n"
    .string "better Pokémon…$"

Route12_EventScript_Hank::
    trainerbattle_single TRAINER_FISHERMAN_HANK, Route12_Text_HankIntro, Route12_Text_HankDefeat
    msgbox Route12_Text_HankPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_HankIntro::
    .string "The fishing fool versus Pokémon\n"
    .string "kid!$"

Route12_Text_HankDefeat::
    .string "Touch too much!$"

Route12_Text_HankPostBattle::
    .string "I guess you get to be good at\n"
    .string "what you like.\p"
    .string "Well, you beat me at Pokémon,\n"
    .string "but you can't top me at fishing.$"

Route12_EventScript_Elliot::
    trainerbattle_single TRAINER_FISHERMAN_ELLIOT, Route12_Text_ElliotIntro, Route12_Text_ElliotDefeat
    msgbox Route12_Text_ElliotPostBattle, MSGBOX_AUTOCLOSE
    end
    
Route12_Text_ElliotIntro::
    .string "I love fishing, don't get me wrong.\p"
    .string "But it'd be best if I also had more\n"
    .string "work.$"

Route12_Text_ElliotDefeat::
    .string "It's not easy…$"

Route12_Text_ElliotPostBattle::
    .string "It's all right.\n"
    .string "Losing doesn't bug me anymore.$"

Route12_EventScript_Jes::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_JesIntro, Route12_Text_JesDefeat, Route12_Text_JesNotEnoughMons
    msgbox Route12_Text_JesPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JesIntro::
    .string "Jes: If I win, I'm going to\n"
    .string "propose to Gia.$"

Route12_Text_JesDefeat::
    .string "Jes: Oh, please, why couldn't you\n"
    .string "let us win?$"

Route12_Text_JesPostBattle::
    .string "Jes: Oh, Gia, forgive me,\n"
    .string "my love!$"

Route12_Text_JesNotEnoughMons::
    .string "Jes: Gia and I, we'll be\n"
    .string "together forever.\p"
    .string "We won't battle unless you have\n"
    .string "two Pokémon of your own.$"

Route12_EventScript_Gia::
    trainerbattle_double TRAINER_YOUNG_COUPLE_GIA_JES, Route12_Text_GiaIntro, Route12_Text_GiaDefeat, Route12_Text_GiaNotEnoughMons
    msgbox Route12_Text_GiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_GiaIntro::
    .string "Gia: Hey, Jes…\p"
    .string "If we win, I'll marry you!$"

Route12_Text_GiaDefeat::
    .string "Gia: Oh, but why?$"

Route12_Text_GiaPostBattle::
    .string "Gia: Jes, you silly!\n"
    .string "You ruined this!$"

Route12_Text_GiaNotEnoughMons::
    .string "Gia: I can't bear to battle\n"
    .string "without my Jes!\p"
    .string "Don't you have one more Pokémon?$"

Route12_EventScript_Justin::
    trainerbattle_single TRAINER_CAMPER_JUSTIN, Route12_Text_JustinIntro, Route12_Text_JustinDefeat
    msgbox Route12_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_JustinIntro::
    .string "I'm searching for a Moon Stone.\n"
    .string "Have you found one?$"

Route12_Text_JustinDefeat::
    .string "Oww!$"

Route12_Text_JustinPostBattle::
    .string "I could have made my Pokémon\n"
    .string "evolve with a Moon Stone.\p"
    .string "I would have won then, I bet.$"

Route12_EventScript_Andrew::
    trainerbattle_single TRAINER_FISHERMAN_ANDREW, Route12_Text_AndrewIntro, Route12_Text_AndrewDefeat
    msgbox Route12_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route12_Text_AndrewIntro::
    .string "What's catching?\p"
    .string "You never know what you could\n"
    .string "catch!$"

Route12_Text_AndrewDefeat::
    .string "Lost it!$"

Route12_Text_AndrewPostBattle::
    .string "What, Magikarp?\p"
    .string "I catch them all the time, sure.\n"
    .string "But, boy are they wimpy.$"

Route12_EventScript_ItemIron::
    finditem ITEM_IRON, 1
    release
    end

Route12_EventScript_ItemTM48::
    finditem ITEM_TM48, 1
    release
    end

Route12_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

