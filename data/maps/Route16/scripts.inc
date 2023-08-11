Route16_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route16_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route16_OnResume
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route16_OnWarp
	.byte 0

Route16_OnTransition:
	call_if_eq VAR_CYCLING_ROAD, 1, Route16_OnTransitionCyclingRoad
	call Common_EventScript_GetDayOrNight
	end

Route16_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route16_EventScript_TryRemoveSnorlax
	call Common_EventScript_GetDayOrNight
	end

Route16_OnWarp::
	map_script_2 VAR_CYCLING_ROAD, 1, Route16_OnWarpCyclingRoad
	.2byte 0

Route16_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route16_OnTransitionCyclingRoad::
	setflag FLAG_SYS_CYCLING_ROAD
	return

@Snorlax
Route16_EventScript_TryRemoveSnorlax::
	removeobject VAR_LAST_TALKED
	return

Route16_EventScript_Snorlax::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_POKE_FLUTE, Route16_EventScript_SnorlaxNoPokeFlute
    checkitem ITEM_POKE_FLUTE
    goto_if_eq VAR_RESULT, FALSE, Route16_EventScript_SnorlaxNoPokeFlute
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route16_EventScript_DontUsePokeFlute
	call Common_EventScript_AwakenSnorlax
	setwildbattle SPECIES_SNORLAX, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_HIDE_ROUTE16_SNORLAX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_WOKE_UP_ROUTE_16_SNORLAX
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route16_EventScript_FoughtSnorlax
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED,Route16_EventScript_FoughtSnorlax
	release
	end

Route16_EventScript_DontUsePokeFlute::
	release
	end

Route16_EventScript_FoughtSnorlax::
	msgbox Text_SnorlaxReturnedToMountains
	release
	end

Route16_EventScript_SnorlaxNoPokeFlute::
	msgbox Route16_Text_MonSprawledOutInSlumber
	release
	end

Route16_Text_MonSprawledOutInSlumber::
    .string "A Pokémon is sprawled out in\n"
    .string "a deep and comfortable slumber.$"

Route16_EventScript_CyclingRoadSign::
	msgbox Route16_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route16_EventScript_RouteSign::
	msgbox Route16_Text_RouteSign, MSGBOX_SIGN
	end

Route16_Text_CyclingRoadSign::
    .string "Enjoy the slope!\n"
    .string "Cycling Road$"

Route16_Text_RouteSign::
    .string "Route 16\n"
    .string "Celadon City - Fuchsia City$"

Route16_EventScript_Hideo::
	trainerbattle_single REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoIntro, Route16_Text_HideoDefeat, Route16_EventScript_RegisterHideoAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_HideoRematch
	msgbox Route16_Text_HideoPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_HideoIntro::
    .string "Hey, you just bumped me!$"

Route16_Text_HideoDefeat::
    .string "Kaboom!$"

Route16_Text_HideoPostBattle::
    .string "We'll always be hanging around here\n"
    .string "even if you don't like it.\p"
    .string "You can detour to Vermilion from\n"
    .string "Fuchsia going along the coast.$"

Route16_EventScript_RegisterHideoAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_HideoRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BIKER_HIDEO_1
	release
	end

Route16_Text_HideoRegister:
	.string "Hey, since you bumped into my\n"
	.string "bike, you'll have to pay me back.\p"
	.string "I'll take a rematch as payment.$"

Route16_EventScript_HideoRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BIKER_HIDEO_1, Route16_Text_HideoRematchIntro, Route16_Text_HideoDefeat
	msgbox Route16_Text_HideoRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_HideoRematchIntro::
	.string "Kept you waiting, huh?$"

Route16_Text_HideoRematchPostBattle::
	.string "Never be game over!$"


Route16_EventScript_Koji::
	trainerbattle_single REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiIntro, Route16_Text_KojiDefeat, Route16_EventScript_RegisterKojiAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route16_EventScript_KojiRematch
	msgbox Route16_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route16_Text_KojiIntro::
    .string "Nice Bike!\n"
    .string "Hand it over!$"

Route16_Text_KojiDefeat::
    .string "Knockout!$"

Route16_Text_KojiPostBattle::
    .string "Forget it, who needs your bike!$"

Route16_EventScript_RegisterKojiAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route16_Text_KojiRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CUE_BALL_KOJI_1
	release
	end

Route16_Text_KojiRegister:
	.string "If you're not gonna give me\n"
	.string "your bike, I'll just take your\l"
	.string "Cell Phone number instead!$"

Route16_EventScript_KojiRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CUE_BALL_KOJI_1, Route16_Text_KojiRematchIntro, Route16_Text_KojiDefeat
	msgbox Route16_Text_KojiRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_KojiRematchIntro::
	.string "Hey! Hand over that bike...\n"
	.string "Oh, it's you, {PLAYER}!$"

Route16_Text_KojiRematchPostBattle::
	.string "I'll never afford a cool bike,\n"
	.string "so I'm going to take one!$"

Route16_EventScript_Lao::
	trainerbattle_single TRAINER_BIKER_LAO, Route16_Text_LaoIntro, Route16_Text_LaoDefeat
	msgbox Route16_Text_LaoPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LaoIntro::
    .string "What do you want?$"

Route16_Text_LaoDefeat::
    .string "Don't you dare laugh!$"

Route16_Text_LaoPostBattle::
    .string "We like just hanging here.\n"
    .string "What's it to you?$"

Route16_EventScript_Ruben::
	trainerbattle_single TRAINER_BIKER_RUBEN, Route16_Text_RubenIntro, Route16_Text_RubenDefeat
	msgbox Route16_Text_RubenPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_RubenIntro::
    .string "Hey, there!\n"
    .string "Let's have ourselves a good time!$"

Route16_Text_RubenDefeat::
    .string "Don't make me mad!$"

Route16_Text_RubenPostBattle::
    .string "I get my kicks by harassing people\n"
    .string "with my stinking Pokémon.\p"
    .string "They're great for startling people.\n"
    .string "And, they bite, too.$"

Route16_EventScript_Luke::
	trainerbattle_single TRAINER_CUE_BALL_LUKE, Route16_Text_LukeIntro, Route16_Text_LukeDefeat
	msgbox Route16_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LukeIntro::
    .string "Come out and play, little mouse!$"

Route16_Text_LukeDefeat::
    .string "You little rat!$"

Route16_Text_LukePostBattle::
    .string "I hate losing!\n"
    .string "Get out of my face!$"

Route16_EventScript_Camron::
	trainerbattle_single TRAINER_CUE_BALL_CAMRON, Route16_Text_CamronIntro, Route16_Text_CamronDefeat
	msgbox Route16_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_CamronIntro::
    .string "I'm feeling hungry and mean!\n"
    .string "I need a punching bag!$"

Route16_Text_CamronDefeat::
    .string "Bad, bad, bad!$"

Route16_Text_CamronPostBattle::
    .string "If I'm going to have Pokémon, they\n"
    .string "may as well be ferocious.\p"
    .string "I'd use them to leave my enemies\n"
    .string "in tatters.$"

Route16_EventScript_Jed::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_JedIntro, Route16_Text_JedDefeat, Route16_Text_JedNotEnoughMons
	msgbox Route16_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_JedIntro::
    .string "Jed: Our love knows no bounds.\n"
    .string "We're in love and we show it!$"

Route16_Text_JedDefeat::
    .string "Jed: Oh, no!\n"
    .string "My love has seen me as a loser!$"

Route16_Text_JedPostBattle::
    .string "Jed: Listen, Lea.\n"
    .string "You need to focus less on me.$"

Route16_EventScript_Lea::
	trainerbattle_double TRAINER_YOUNG_COUPLE_LEA_JED, Route16_Text_LeaIntro, Route16_Text_LeaDefeat, Route16_Text_LeaNotEnoughMons
	msgbox Route16_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

Route16_Text_LeaIntro::
    .string "Lea: Sometimes, the intensity of\n"
    .string "our love scares me.$"

Route16_Text_LeaDefeat::
    .string "Lea: Ohh! But Jed looks cool\n"
    .string "even in a loss!$"

Route16_Text_LeaPostBattle::
    .string "Lea: Ehehe, I'm sorry.\n"
    .string "Jed is so cool.$"

Route16_Text_JedNotEnoughMons::
    .string "Jed: You have just one Pokémon?\n"
    .string "Is there no love in your heart?$"

Route16_Text_LeaNotEnoughMons::
    .string "Lea: Oh, you don't have two\n"
    .string "Pokémon with you?\p"
    .string "Doesn't it feel lonely for you or\n"
    .string "your Pokémon?$"


@TODO: Change based on if a new snorlax is here
Route16_EventScript_BerryMan::
	lock
	faceplayer
	msgbox Route16_Text_SnorlaxEatsBerries, MSGBOX_NPC
	release
	end

Route16_Text_SnorlaxEatsBerries:
	.string "Sometimes Snorlax wanders into our\n"
	.string "Berry Grove and eats our whole crop!\p"
	.string "Afterwards, it takes a long nap.\p"
	.string "Even the noise from Cycling Road can't\n"
	.string "wake it up.$"







