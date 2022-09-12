Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route25_OnResume
	.byte 0

Route25_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route25_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route25_EventScript_SeaCottageSign::
	msgbox Route25_Text_SeaCottageSign, MSGBOX_SIGN
	end

Route25_Text_SeaCottageSign::
    .string "Sea Cottage\n"
    .string "Bill lives here!$"

Route25_EventScript_Man::
	msgbox Route25_Text_AreYouHereAlone, MSGBOX_NPC
	end

Route25_Text_AreYouHereAlone::
    .string "Hello, are you here alone?\p"
    .string "If you're out at Cerulean's cape…\n"
    .string "Well, it should be as a couple.$"

Route25_EventScript_Beauty::
	msgbox Route25_Text_MistyHighHopesAboutThisPlace, MSGBOX_NPC
	release
	end

Route25_Text_MistyHighHopesAboutThisPlace::
    .string "This cape is a famous date spot.\p"
    .string "Misty, the Gym Leader, has high\n"
    .string "hopes about this place.$"

Route25_EventScript_Franklin::
	trainerbattle_single REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinIntro, Route25_Text_FranklinDefeat, Route25_EventScript_RegisterFranklinAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route25_EventScript_FranklinRematch
	msgbox Route25_Text_FranklinPostBattle, MSGBOX_DEFAULT
	release
	end

Route25_Text_FranklinIntro::
    .string "I just got down from Mt. Moon,\n"
    .string "but I've still got gas in the tank!$"

Route25_Text_FranklinDefeat::
    .string "You worked hard!$"

Route25_Text_FranklinPostBattle::
    .string "Drat!\n"
    .string "A Zubat bit me back in that cave.$"

Route25_EventScript_RegisterFranklinAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route25_Text_FranklinRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_HIKER_FRANKLIN_1
	release
	end

Route25_Text_FranklinRegister:
	.string "Hmm...\p"
	.string "Maybe I'm not as rested as\n"
	.string "I thought...\p"
	.string "Let's have a rematch sometime!$"

Route25_EventScript_FranklinRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_HIKER_FRANKLIN_1, Route25_Text_FranklinRematchIntro, Route25_Text_FranklinDefeat
	msgbox Route25_Text_FranklinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FranklinRematchIntro::
	.string "Hey {PLAYER}!\n"
	.string "I've still got gas in the tank!\p"
	.string "Let's go another round!$"

Route25_Text_FranklinRematchPostBattle::
	.string "Maybe I'm still woozy from\n"
	.string "that Zubat bite!$"


Route25_EventScript_Joey::
	trainerbattle_single TRAINER_YOUNGSTER_JOEY, Route25_Text_JoeyIntro, Route25_Text_JoeyDefeat
	msgbox Route25_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_JoeyIntro::
    .string "Local trainers come here to\n"
    .string "practice.$"

Route25_Text_JoeyDefeat::
    .string "You're decent.$"

Route25_Text_JoeyPostBattle::
    .string "All Pokémon have weaknesses.\n"
    .string "Even the strongest ones.\p"
    .string "That's why it's best to raise\n"
    .string "Pokémon of different types.$"


Route25_EventScript_Wayne::
	trainerbattle_single TRAINER_HIKER_WAYNE, Route25_Text_WayneIntro, Route25_Text_WayneDefeat
	msgbox Route25_Text_WaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_WayneIntro::
    .string "You're going to see Bill?\n"
    .string "First, we battle!$"

Route25_Text_WayneDefeat::
    .string "You're something.$"

Route25_Text_WaynePostBattle::
    .string "The trail below is a shortcut to\n"
    .string "Cerulean City.$"

Route25_EventScript_Dan::
	trainerbattle_single TRAINER_YOUNGSTER_DAN, Route25_Text_DanIntro, Route25_Text_DanDefeat
	msgbox Route25_Text_DanPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_DanIntro::
    .string "Dad took me to a great party on\n"
    .string "the S.S. Anne at Vermilion City.$"

Route25_Text_DanDefeat::
    .string "I'm not mad!$"

Route25_Text_DanPostBattle::
    .string "On the S.S. Anne, I saw trainers\n"
    .string "from around the world.$"

Route25_EventScript_Kelsey::
	trainerbattle_single TRAINER_PICNICKER_KELSEY, Route25_Text_KelseyIntro, Route25_Text_KelseyDefeat
	msgbox Route25_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_KelseyIntro::
    .string "Hi!\n"
    .string "My boyfriend is cool!$"

Route25_Text_KelseyDefeat::
    .string "My conditioning isn't the best…$"

Route25_Text_KelseyPostBattle::
    .string "I wish my boyfriend was as good\n"
    .string "as you.$"

Route25_EventScript_Nob::
	trainerbattle_single TRAINER_HIKER_NOB, Route25_Text_NobIntro, Route25_Text_NobDefeat
	msgbox Route25_Text_NobPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_NobIntro::
    .string "I'm off to see a Pokémaniac's\n"
    .string "collection at the cape.$"

Route25_Text_NobDefeat::
    .string "You done got me, and real good,\n"
    .string "too!$"

Route25_Text_NobPostBattle::
    .string "The Pokémaniac sure lives up to\n"
    .string "his name.\p"
    .string "His collection includes many rare\n"
    .string "species of Pokémon.$"

Route25_EventScript_Flint::
	trainerbattle_single TRAINER_CAMPER_FLINT, Route25_Text_FlintIntro, Route25_Text_FlintDefeat
	msgbox Route25_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_FlintIntro::
    .string "I'm a cool guy.\n"
    .string "I've got a girlfriend!$"

Route25_Text_FlintDefeat::
    .string "Aww, darn…$"

Route25_Text_FlintPostBattle::
    .string "Oh, well.\n"
    .string "My girlfriend will cheer me up.$"

Route25_EventScript_Chad::
	trainerbattle_single TRAINER_YOUNGSTER_CHAD, Route25_Text_ChadIntro, Route25_Text_ChadDefeat
	msgbox Route25_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_ChadIntro::
    .string "I had this feeling…\n"
    .string "I knew I had to battle you!$"

Route25_Text_ChadDefeat::
    .string "I knew I'd lose, too!$"

Route25_Text_ChadPostBattle::
    .string "If your Pokémon gets confused,\n"
    .string "switch it out.\p"
    .string "That's a good tactic.$"

Route25_EventScript_Haley::
	trainerbattle_single TRAINER_LASS_HALEY, Route25_Text_HaleyIntro, Route25_Text_HaleyDefeat
	msgbox Route25_Text_HaleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route25_Text_HaleyIntro::
    .string "My friend has many cute Pokémon.\n"
    .string "I'm so jealous!$"

Route25_Text_HaleyDefeat::
    .string "I'm not so jealous!$"

Route25_Text_HaleyPostBattle::
    .string "You came from Mt. Moon?\n"
    .string "May I have a Clefairy?$"





