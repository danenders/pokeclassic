ViridianForest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, ViridianForest_OnResume
	.byte 0

ViridianForest_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_OnResume:
	call Common_EventScript_GetDayOrNight
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_Text_FriendsItchingToBattle::
    .string "I came here with some friends to\n"
    .string "catch us some Bug Pokémon!\p"
    .string "They're all itching to get into\n"
    .string "some Pokémon battles!$"

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_Text_RanOutOfPokeBalls::
    .string "I was throwing Poké Balls to\n"
    .string "catch Pokémon, and I ran out.\p"
    .string "That's why you can never have too\n"
    .string "many Poké Balls.$"

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_RickIntro::
    .string "Hey! You have Pokémon!\n"
    .string "Come on!\l"
    .string "Let's battle 'em!$"

ViridianForest_Text_RickDefeat::
    .string "No!\nCaterpie can't hack it!$"

ViridianForest_Text_RickPostBattle::
    .string "Ssh! You'll scare the bugs away.\n"
    .string "Another time, okay?$"

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_DougIntro::
    .string "Yo!\n"
    .string "You can't jam out if you're a\l"
    .string "Pokémon Trainer!$"

ViridianForest_Text_DougDefeat::
    .string "Huh?\n"
    .string "I ran out of Pokémon!$"

ViridianForest_Text_DougPostBattle::
    .string "That totally stinks! I'm going to\n"
    .string "catch some stronger ones!$"


ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_SammyIntro::
    .string "Hey, wait up!\n"
    .string "What's the hurry? Why the rush?$"

ViridianForest_Text_SammyDefeat::
    .string "I give!\n"
    .string "You're good at this!$"

ViridianForest_Text_SammyPostBattle::
    .string "Sometimes, you can find stuff on\n"
    .string "the ground.\p"
    .string "I'm looking for the stuff I\n"
    .string "dropped. Can you help me?$"

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_AnthonyIntro::
    .string "I might be little, but I won't like\n"
    .string "it if you go easy on me!$"

ViridianForest_Text_AnthonyDefeat::
    .string "Oh, boo.\n"
    .string "Nothing went right.$"

ViridianForest_Text_AnthonyPostBattle::
    .string "I lost some of my allowance…$"

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_CharlieIntro::
    .string "Did you know that Pokémon evolve?$"

ViridianForest_Text_CharlieDefeat::
    .string "Oh!\n"
    .string "I lost!$"

ViridianForest_Text_CharliePostBattle::
    .string "Bug Pokémon evolve quickly.\n"
    .string "They're a lot of fun!$"


ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
    .string "Trainer Tips:\p"
    .string "If your Pokémon are weak and you\n"
    .string "want to avoid battles, stay away\l"
    .string "from grassy areas!$"

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_Text_UseAntidoteForPoison::
    .string "Trainer Tips:\p"
    .string "For poison, use Antidote!\n"
    .string "Get it at Pokémon Marts!$"

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_Text_ContactOakViaPCToRatePokedex::
    .string "Trainer Tips:\p"
    .string "You can call Prof. Oak with\n"
    .string "your Cell Phone to get your\l"
    .string "Pokédex evaluated!$"

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_Text_CantCatchOwnedMons::
    .string "Trainer Tips:\p"
    .string "You can't catch a Pokémon that\n"
    .string "belongs to someone else.\p"
    .string "Throw Poké Balls only at wild\n"
    .string "Pokémon to catch them!$"

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_Text_WeakenMonsBeforeCapture::
    .string "Trainer Tips:\p"
    .string "Weaken Pokémon before attempting\n"
    .string "capture!\p"
    .string "When healthy, they may escape!$"

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_Text_LeavingViridianForest::
    .string "Leaving Viridian Forest\n"
    .string "Pewter City Ahead$"

ViridianForest_EventScript_ItemPotion::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemPotion2::
	finditem ITEM_POTION, 1
	end

ViridianForest_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE, 1
	end

ViridianForest_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL, 1
	end

ViridianForest_EventScript_Beedrillite::
    finditem ITEM_BEEDRILLITE, 1
    end
