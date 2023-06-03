.set LOCALID_FUGITIVE, 19

Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route8_OnResume
	.byte 0

Route8_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route8_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route8_EventScript_UndergroundPathSign::
	msgbox Route8_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route8_Text_UndergroundPathSign::
    .string "Underground Path\n"
    .string "Celadon City - Lavender Town$"

Route8_EventScript_Aidan::
	trainerbattle_single REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanIntro, Route8_Text_AidanDefeat, Route8_EventScript_RegisterAidanAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_AidanRematch
	msgbox Route8_Text_AidanPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_Text_AidanIntro::
    .string "You look good at Pokémon, but how\n"
    .string "is your chemistry grade?$"

Route8_Text_AidanDefeat::
    .string "Ow!\n"
    .string "Meltdown!$"

Route8_Text_AidanPostBattle::
    .string "I am better at school than this!$"

Route8_EventScript_RegisterAidanAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_AidanRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1
	release
	end

Route8_Text_AidanRegister:
	.string "I'll tutor you in chemistry if\n"
	.string "you tutor me in Pokémon battles.$"

Route8_EventScript_AidanRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_SUPER_NERD_AIDAN_1, Route8_Text_AidanRematchIntro, Route8_Text_AidanDefeat
	msgbox Route8_Text_AidanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AidanRematchIntro::
	.string "Hey {PLAYER}!\n"
	.string "Have your grades improved?$"

Route8_Text_AidanRematchPostBattle::
	.string "I should be studying instead\n"
	.string "of playing with Pokémon!$"

Route8_EventScript_Julia::
	trainerbattle_single TRAINER_LASS_JULIA, Route8_Text_JuliaIntro, Route8_Text_JuliaDefeat
	msgbox Route8_Text_JuliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JuliaIntro::
    .string "What's a cute, round, and fluffy\n"
    .string "Pokémon?$"

Route8_Text_JuliaDefeat::
    .string "Stop!\p"
    .string "Don't be so mean to my Clefairy!$"

Route8_Text_JuliaPostBattle::
    .string "I read that Clefairy evolves when\n"
    .string "it's exposed to a Moon Stone.\p"
    .string "I read that in a Pokémon Journal.\n"
    .string "I wonder if it's true?$"


Route8_EventScript_Paige::
	trainerbattle_single TRAINER_LASS_PAIGE, Route8_Text_PaigeIntro, Route8_Text_PaigeDefeat
	msgbox Route8_Text_PaigePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_PaigeIntro::
    .string "I like Nidoran, so I collect them!$"

Route8_Text_PaigeDefeat::
    .string "Why?\n"
    .string "Why??$"

Route8_Text_PaigePostBattle::
    .string "When Pokémon grow up, they get\n"
    .string "ugly! They shouldn't evolve.$"

Route8_EventScript_Andrea::
	trainerbattle_single TRAINER_LASS_ANDREA, Route8_Text_AndreaIntro, Route8_Text_AndreaDefeat
	msgbox Route8_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AndreaIntro::
    .string "Meowth is so cute, meow, meow,\n"
    .string "meow!$"

Route8_Text_AndreaDefeat::
    .string "Meeeeyow!$"

Route8_Text_AndreaPostBattle::
    .string "I think Pidgey and Rattata are\n"
    .string "cute, too!$"

Route8_EventScript_Megan::
	trainerbattle_single TRAINER_LASS_MEGAN, Route8_Text_MeganIntro, Route8_Text_MeganDefeat
	msgbox Route8_Text_MeganPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_MeganIntro::
    .string "We must look silly standing here\n"
    .string "like this.$"

Route8_Text_MeganDefeat::
    .string "Look what you did to my poor, cute\n"
    .string "Pokémon!$"

Route8_Text_MeganPostBattle::
    .string "The Police in Saffron won't let us\n"
    .string "go through.\p"
    .string "I know they're doing their job, but\n"
    .string "I think that's mean.$"

Route8_EventScript_Glenn::
	trainerbattle_single TRAINER_SUPER_NERD_GLENN, Route8_Text_GlennIntro, Route8_Text_GlennDefeat
	msgbox Route8_Text_GlennPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_GlennIntro::
    .string "You should be informed.\n"
    .string "You need strategy to win at this!$"

Route8_Text_GlennDefeat::
    .string "It's not logical!$"

Route8_Text_GlennPostBattle::
    .string "Go with Grimer first…and…\n"
    .string "…and…then…$"

Route8_EventScript_Leslie::
	trainerbattle_single TRAINER_SUPER_NERD_LESLIE, Route8_Text_LeslieIntro, Route8_Text_LeslieDefeat
	msgbox Route8_Text_LesliePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_LeslieIntro::
    .string "School is fun, but so are Pokémon.$"

Route8_Text_LeslieDefeat::
    .string "You made it clear to me that\n"
    .string "I should stick with school.$"

Route8_Text_LesliePostBattle::
    .string "I was planning on getting some\n"
    .string "fresh air for a change, but…\p"
    .string "We're stuck here because of the\n"
    .string "gates at Saffron.$"

Route8_EventScript_Stan::
	trainerbattle_single TRAINER_GAMBLER_STAN, Route8_Text_StanIntro, Route8_Text_StanDefeat
	msgbox Route8_Text_StanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_StanIntro::
    .string "All right!\n"
    .string "Let's play a game!$"

Route8_Text_StanDefeat::
    .string "Drat!\n"
    .string "Came up short!$"

Route8_Text_StanPostBattle::
    .string "Things didn't work today.$"

Route8_EventScript_Rich::
	trainerbattle_single TRAINER_GAMBLER_RICH, Route8_Text_RichIntro, Route8_Text_RichDefeat
	msgbox Route8_Text_RichPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RichIntro::
    .string "I'm a rambling, gambling dude!$"

Route8_Text_RichDefeat::
    .string "Missed the big chance!$"

Route8_Text_RichPostBattle::
    .string "Playing games and Pokémon are like\n"
    .string "eating peanuts! I just can't stop!$"

Route8_EventScript_Eli::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_EliIntro, Route8_Text_EliDefeat, Route8_Text_EliNotEnoughMons
	msgbox Route8_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_EliIntro::
    .string "Eli: Twin power is fantastic.\n"
    .string "Did you know?$"

Route8_Text_EliDefeat::
    .string "Eli: But…\n"
    .string "We used our twin power…$"

Route8_Text_EliPostBattle::
    .string "Eli: I caught my Pokémon with\n"
    .string "Anne!$"

Route8_Text_EliNotEnoughMons::
    .string "Eli: We can't battle if you don't\n"
    .string "have two Pokémon.$"

Route8_EventScript_Anne::
	trainerbattle_double TRAINER_TWINS_ELI_ANNE, Route8_Text_AnneIntro, Route8_Text_AnneDefeat, Route8_Text_AnneNotEnoughMons
	msgbox Route8_Text_AnnePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_AnneIntro::
    .string "Anne: We'll shock you with our twin\n"
    .string "power!$"

Route8_Text_AnneDefeat::
    .string "Anne: Our twin power…$"

Route8_Text_AnnePostBattle::
    .string "Anne: I'm raising Pokémon with\n"
    .string "Eli.$"

Route8_Text_AnneNotEnoughMons::
    .string "Anne: Hi, hi! Let's battle!\n"
    .string "But bring two Pokémon.$"

Route8_EventScript_Ricardo::
	trainerbattle_single TRAINER_BIKER_RICARDO, Route8_Text_RicardoIntro, Route8_Text_RicardoDefeat
	msgbox Route8_Text_RicardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_RicardoIntro::
    .string "My bike's acting up, man.$"

Route8_Text_RicardoDefeat::
    .string "Aww, man.\n"
    .string "I'm not into this.$"

Route8_Text_RicardoPostBattle::
    .string "I got grass caught up in my\n"
    .string "spokes, man.$"

Route8_EventScript_Jaren::
	trainerbattle_single TRAINER_BIKER_JAREN, Route8_Text_JarenIntro, Route8_Text_JarenDefeat
	msgbox Route8_Text_JarenPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_JarenIntro::
    .string "Clear the way, or I'll run you\n"
    .string "down!$"

Route8_Text_JarenDefeat::
    .string "You for real, kid?$"

Route8_Text_JarenPostBattle::
    .string "Don't think you're all special and\n"
    .string "all just because of this.$"

Route8_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
