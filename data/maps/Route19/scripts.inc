.set LOCALID_FUGITIVE, 13

Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route19_OnResume
	.byte 0

Route19_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route19_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route19_EventScript_RouteSign::
	msgbox Route19_Text_RouteSign, MSGBOX_SIGN
	end

Route19_Text_RouteSign::
    .string "Sea Route 19\n"
    .string "Fuchsia City - Seafoam Islands$"

Route19_EventScript_Richie::
	trainerbattle_single REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieIntro, Route19_Text_RichieDefeat, Route19_EventScript_RegisterRichieAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route19_EventScript_RichieRematch
	msgbox Route19_Text_RichiePostBattle, MSGBOX_DEFAULT
	release
	end

Route19_Text_RichieIntro::
    .string "I have to exercise and warm up\n"
    .string "before going out for a swim.$"

Route19_Text_RichieDefeat::
    .string "All warmed up!$"

Route19_Text_RichiePostBattle::
    .string "Thanks!\n"
    .string "I'm ready for a swim.$"

Route19_EventScript_RegisterRichieAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route19_Text_RichieRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_TUBER_RICHIE_1
	release
	end

Route19_Text_RichieRegister:
	.string "I love going to the beach!\n"
	.string "I'll call you whenever I'm here!$"

Route19_EventScript_RichieRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_TUBER_RICHIE_1, Route19_Text_RichieRematchIntro, Route19_Text_RichieDefeat
	msgbox Route19_Text_RichieRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_RichieRematchIntro::
	.string "Yeah! Beach day!\n"
	.string "Let's warm up for a swim!$"

Route19_Text_RichieRematchPostBattle::
	.string "I ate a big lunch before coming\n"
	.string "here, so I can't go in the water yet.$"

Route19_EventScript_Lizzie::
	trainerbattle_single TRAINER_TUBER_LIZZIE, Route19_Text_LizzieIntro, Route19_Text_LizzieDefeat
	msgbox Route19_Text_LizziePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LizzieIntro::
    .string "Wait! Slow down!\n"
    .string "You'll have a heart attack!$"

Route19_Text_LizzieDefeat::
    .string "Ooh!\n"
    .string "That's chilly!$"

Route19_Text_LizziePostBattle::
    .string "Watch out for Tentacool.\n"
    .string "They sting so painfully.$"

Route19_EventScript_Matthew::
	trainerbattle_single TRAINER_SWIMMER_MALE_MATTHEW, Route19_Text_MatthewIntro, Route19_Text_MatthewDefeat
	msgbox Route19_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_MatthewIntro::
    .string "I love swimming!\n"
    .string "What about you?$"

Route19_Text_MatthewDefeat::
    .string "Belly flop!$"

Route19_Text_MatthewPostBattle::
    .string "I can beat even marine Pokémon\n"
    .string "at swimming.$"

Route19_EventScript_Douglas::
	trainerbattle_single TRAINER_SWIMMER_MALE_DOUGLAS, Route19_Text_DouglasIntro, Route19_Text_DouglasDefeat
	msgbox Route19_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DouglasIntro::
    .string "What's beyond the horizon?$"

Route19_Text_DouglasDefeat::
    .string "Glub!$"

Route19_Text_DouglasPostBattle::
    .string "I see a couple of islands over\n"
    .string "yonder!$"

Route19_EventScript_David::
	trainerbattle_single TRAINER_SWIMMER_MALE_DAVID, Route19_Text_DavidIntro, Route19_Text_DavidDefeat
	msgbox Route19_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_DavidIntro::
    .string "I tried diving for Pokémon, but it\n"
    .string "was a no-go.$"

Route19_Text_DavidDefeat::
    .string "Help!$"

Route19_Text_DavidPostBattle::
    .string "I guess you have to fish for sea\n"
    .string "Pokémon.$"

Route19_EventScript_Tony::
	trainerbattle_single TRAINER_SWIMMER_MALE_TONY, Route19_Text_TonyIntro, Route19_Text_TonyDefeat
	msgbox Route19_Text_TonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_TonyIntro::
    .string "I look at the sea to forget all\n"
    .string "the bad things that happened.$"

Route19_Text_TonyDefeat::
    .string "Ooh!\n"
    .string "Traumatic!$"

Route19_Text_TonyPostBattle::
    .string "I'm looking at the sea to forget\n"
    .string "the bad thing that happened!$"

Route19_EventScript_Axle::
	trainerbattle_single TRAINER_SWIMMER_MALE_AXLE, Route19_Text_AxleIntro, Route19_Text_AxleDefeat
	msgbox Route19_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AxleIntro::
    .string "Ahoy, there!\n"
    .string "These waters are treacherous!$"

Route19_Text_AxleDefeat::
    .string "Ooh!\n"
    .string "Dangerous!$"

Route19_Text_AxlePostBattle::
    .string "M-my legs! They cramped up!\n"
    .string "Glub, glub…$"

Route19_EventScript_Anya::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ANYA, Route19_Text_AnyaIntro, Route19_Text_AnyaDefeat
	msgbox Route19_Text_AnyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AnyaIntro::
    .string "Oh, I just love your ride!\n"
    .string "Can I have it if I win?$"

Route19_Text_AnyaDefeat::
    .string "Oh! I lost!$"

Route19_Text_AnyaPostBattle::
    .string "It's still a long way to go to\n"
    .string "Seafoam Iskands…\p"
    .string "I want to go back to Fuchsia…$"

Route19_EventScript_Alice::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_ALICE, Route19_Text_AliceIntro, Route19_Text_AliceDefeat
	msgbox Route19_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_AliceIntro::
    .string "Swimming's great!\n"
    .string "Sunburns aren't!$"

Route19_Text_AliceDefeat::
    .string "Shocker!$"

Route19_Text_AlicePostBattle::
    .string "My boyfriend wanted to swim to\n"
    .string "Seafoam Islands.$"

Route19_EventScript_Connie::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_CONNIE, Route19_Text_ConnieIntro, Route19_Text_ConnieDefeat
	msgbox Route19_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_ConnieIntro::
    .string "I swam here with my friends…\n"
    .string "I'm tired…$"

Route19_Text_ConnieDefeat::
    .string "I'm exhausted…$"

Route19_Text_ConniePostBattle::
    .string "If I were to ride a Pokémon on\n"
    .string "the sea, I'd like a Lapras.\p"
    .string "Lapras is so big, I bet it\n"
    .string "would keep me dry on water.$"

Route19_EventScript_Lia::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LiaIntro, Route19_Text_LiaDefeat, Route19_Text_LiaNotEnoughMons
	msgbox Route19_Text_LiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LiaIntro::
    .string "Lia: I'm looking after my brother.\n"
    .string "He just became a Trainer.$"

Route19_Text_LiaDefeat::
    .string "Lia: That's no way to treat my\n"
    .string "little brother!$"

Route19_Text_LiaPostBattle::
    .string "Lia: Do you have a younger\n"
    .string "brother?\p"
    .string "I hope you're teaching him all\n"
    .string "sorts of things.$"

Route19_Text_LiaNotEnoughMons::
    .string "Lia: I want to battle together\n"
    .string "with my little brother.\p"
    .string "Don't you have two Pokémon?$"

Route19_EventScript_Luc::
	trainerbattle_double TRAINER_SIS_AND_BRO_LIA_LUC, Route19_Text_LucIntro, Route19_Text_LucDefeat, Route19_Text_LucNotEnoughMons
	msgbox Route19_Text_LucPostBattle, MSGBOX_AUTOCLOSE
	end

Route19_Text_LucIntro::
    .string "Luc: My big sis taught me how\n"
    .string "to swim and train Pokémon.$"

Route19_Text_LucDefeat::
    .string "Luc: Oh, wow!\n"
    .string "Someone tougher than my big sis!$"

Route19_Text_LucPostBattle::
    .string "Luc: My big sis is strong and nice.\n"
    .string "I think she's awesome!$"

Route19_Text_LucNotEnoughMons::
    .string "Luc: I don't want to if I can't\n"
    .string "battle you with my big sis.\p"
    .string "Don't you have two Pokémon?$"

Route19_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end

