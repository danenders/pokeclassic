Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route15_OnResume
	.byte 0

Route15_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route15_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route15_EventScript_Olivia::
	trainerbattle_single REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaIntro, Route15_Text_OliviaDefeat, Route15_EventScript_RegisterOliviaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route15_EventScript_OliviaRematch
	msgbox Route15_Text_OliviaPostBattle, MSGBOX_DEFAULT
	release
	end

Route15_Text_OliviaIntro::
    .string "I raise Pokémon for protection\n"
    .string "because I live alone.$"

Route15_Text_OliviaDefeat::
    .string "Pokémon isn't about winning or\n"
    .string "losing for me.$"

Route15_Text_OliviaPostBattle::
    .string "I love having my Pokémon greet me\n"
    .string "when I get home.\p"
    .string "It's so reassuring.$"

Route15_EventScript_RegisterOliviaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route15_Text_OliviaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1
	release
	end

Route15_Text_OliviaRegister:
	.string "Can I get your number?\p"
	.string "I could call you if I need\n"
	.string "more protection.$"

Route15_EventScript_OliviaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_BEAUTY_OLIVIA_1, Route15_Text_OliviaRematchIntro, Route15_Text_OliviaDefeat
	msgbox Route15_Text_OliviaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_OliviaRematchIntro::
	.string "I still live alone, so I need\n"
	.string "to train my Pokémon to protect me.$"

Route15_Text_OliviaRematchPostBattle::
	.string "Maybe I should find a new place...$"

Route15_EventScript_Grace::
	trainerbattle_single TRAINER_BEAUTY_GRACE, Route15_Text_GraceIntro, Route15_Text_GraceDefeat
	msgbox Route15_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_GraceIntro::
    .string "Oh, you're a little cutie!\n"
    .string "So like a darling Pokémon!$"

Route15_Text_GraceDefeat::
    .string "You looked so cute, too!$"

Route15_Text_GracePostBattle::
    .string "I forgive you.\n"
    .string "I can take it.\l"
    .string "I'm a big girl now.$"

Route15_EventScript_Ernest::
	trainerbattle_single TRAINER_BIKER_ERNEST, Route15_Text_ErnestIntro, Route15_Text_ErnestDefeat
	msgbox Route15_Text_ErnestPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ErnestIntro::
    .string "Hey, kid! C'mon!\n"
    .string "I just got these off some loser!$"

Route15_Text_ErnestDefeat::
    .string "Why not?$"

Route15_Text_ErnestPostBattle::
    .string "Life's too short.\n"
    .string "It's cool to live as an outlaw.\l"
    .string "Team Rocket Rules!$"

Route15_EventScript_Alex::
	trainerbattle_single TRAINER_BIKER_ALEX, Route15_Text_AlexIntro, Route15_Text_AlexDefeat
	msgbox Route15_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_AlexIntro::
    .string "Fork over all your cash when you\n"
    .string "lose to me, kid!$"

Route15_Text_AlexDefeat::
    .string "That can't be true!$"

Route15_Text_AlexPostBattle::
    .string "I was just joking about the money.\n"
    .string "Don't take me all serious.$"

Route15_EventScript_Edwin::
	trainerbattle_single TRAINER_BIRD_KEEPER_EDWIN, Route15_Text_EdwinIntro, Route15_Text_EdwinDefeat
	msgbox Route15_Text_EdwinPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_EdwinIntro::
    .string "When I whistle, I can summon bird\n"
    .string "Pokémon.$"

Route15_Text_EdwinDefeat::
    .string "Ow!\n"
    .string "That's tragic!$"

Route15_Text_EdwinPostBattle::
    .string "Maybe I'm not cut out for battles.\n"
    .string "I'm not the right type, I guess.$"

Route15_EventScript_Chester::
	trainerbattle_single TRAINER_BIRD_KEEPER_CHESTER, Route15_Text_ChesterIntro, Route15_Text_ChesterDefeat
	msgbox Route15_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_ChesterIntro::
    .string "Hmm? My birds are shivering!\n"
    .string "You're good, aren't you?$"

Route15_Text_ChesterDefeat::
    .string "Just as I thought!$"

Route15_Text_ChesterPostBattle::
    .string "This is so obvious, you should know\n"
    .string "this, but…\p"
    .string "Moves like Earthquake and Fissure\n"
    .string "have no effect on bird Pokémon.$"

Route15_EventScript_Yazmin::
	trainerbattle_single TRAINER_PICNICKER_YAZMIN, Route15_Text_YazminIntro, Route15_Text_YazminDefeat
	msgbox Route15_Text_YazminPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_YazminIntro::
    .string "Want to play with my Pokémon?$"

Route15_Text_YazminDefeat::
    .string "I was too impatient!$"

Route15_Text_YazminPostBattle::
    .string "I'll go train with weaker people.$"

Route15_EventScript_Kindra::
	trainerbattle_single TRAINER_PICNICKER_KINDRA, Route15_Text_KindraIntro, Route15_Text_KindraDefeat
	msgbox Route15_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_KindraIntro::
    .string "I just got some Pokémon in trades.\n"
    .string "Can I try them out on you?$"

Route15_Text_KindraDefeat::
    .string "Not good enough!$"

Route15_Text_KindraPostBattle::
    .string "You can't change the nickname of\n"
    .string "any Pokémon you get in a trade.\p"
    .string "Only the Original Trainer can get\n"
    .string "the nickname changed.$"

Route15_EventScript_Becky::
	trainerbattle_single TRAINER_PICNICKER_BECKY, Route15_Text_BeckyIntro, Route15_Text_BeckyDefeat
	msgbox Route15_Text_BeckyPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_BeckyIntro::
    .string "You look gentle, so I think I can\n"
    .string "beat you.\p"
    .string "I'll give it a go!$"

Route15_Text_BeckyDefeat::
    .string "No, wrong!$"

Route15_Text_BeckyPostBattle::
    .string "I'm afraid of Bikers. They look so\n"
    .string "ugly and mean!$"

Route15_EventScript_Celia::
	trainerbattle_single TRAINER_PICNICKER_CELIA, Route15_Text_CeliaIntro, Route15_Text_CeliaDefeat
	msgbox Route15_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_CeliaIntro::
    .string "What's cool and happening?\n"
    .string "Trading Pokémon!$"

Route15_Text_CeliaDefeat::
    .string "I said trade!$"

Route15_Text_CeliaPostBattle::
    .string "I trade Pokémon with my friends\n"
    .string "all the time.$"

Route15_EventScript_Mya::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_MyaIntro, Route15_Text_MyaDefeat, Route15_Text_MyaNotEnoughMons
	msgbox Route15_Text_MyaPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_MyaIntro::
    .string "Mya: You're perfect.\n"
    .string "Help me train my little brother?$"

Route15_Text_MyaDefeat::
    .string "Mya: Ron, you have to focus!\n"
    .string "Concentrate on what you're doing!$"

Route15_Text_MyaPostBattle::
    .string "Mya: Okay, we'll turn it up.\n"
    .string "I'll add to our training menu!$"

Route15_Text_MyaNotEnoughMons::
    .string "Mya: Do you want to challenge us?\n"
    .string "You'll need two Pokémon, though.$"

Route15_EventScript_Ron::
	trainerbattle_double TRAINER_CRUSH_KIN_RON_MYA, Route15_Text_RonIntro, Route15_Text_RonDefeat, Route15_Text_RonNotEnoughMons
	msgbox Route15_Text_RonPostBattle, MSGBOX_AUTOCLOSE
	end

Route15_Text_RonIntro::
    .string "Ron: My sister gets scary when we\n"
    .string "lose.$"

Route15_Text_RonDefeat::
    .string "Ron: Oh, no, no…\n"
    .string "Sis, I'm sorry!$"

Route15_Text_RonPostBattle::
    .string "Ron: Oh, bleah…\n"
    .string "I wish I had a nice sister…$"

Route15_Text_RonNotEnoughMons::
    .string "Ron: Did you want to battle with\n"
    .string "my sister and me?\p"
    .string "You need two Pokémon, then.$"

Route15_EventScript_RouteSign::
	msgbox Route15_Text_RouteSign, MSGBOX_SIGN
	end

Route15_Text_RouteSign::
    .string "Route 15\n"
    .string "West to Fuchsia City$"

Route15_EventScript_ItemTM18::
	finditem ITEM_TM18, 1
	release
	end
