.set LOCALID_CHAIRMAN, 1
.set LOCALID_WOMAN,   3
.set LOCALID_FAT_MAN, 4

VermilionCity_PokemonFanClub_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BIKE_VOUCHER, VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory
	msgbox VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_PokemonFanClub_EventScript_ChairmanStory
	msgbox VermilionCity_PokemonFanClub_Text_ComeBackToHearStory
	release
	end

VermilionCity_PokemonFanClub_EventScript_AlreadyHeardStory::
	msgbox VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain
	call_if_unset FLAG_DAILY_FANCLUB_REWARD, VermilionCity_PokemonFanClub_DailyReward
	release
	end

VermilionCity_PokemonFanClub_Text_DidntComeToSeeAboutMonsAgain::
    .string "Hello, {PLAYER}!\p"
    .string "Did you come see me about my\n"
    .string "Pokémon again?\p"
    .string "No?\n"
    .string "Too bad!$"

VermilionCity_PokemonFanClub_DailyReward::
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, Common_EventScript_Return
	checkitemspace ITEM_RARE_CANDY, 1
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_Return
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playse SE_PIN
	applymovement LOCALID_CHAIRMAN, Common_Movement_Heart
	waitse
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox VermilionCity_PokemonFanClub_Text_TruePokeFan, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	setflag FLAG_DAILY_FANCLUB_REWARD
	return

VermilionCity_PokemonFanClub_Text_TruePokeFan::
	.string "I can tell you take excellent\n"
	.string "care of your Pokémon!\p"
	.string "You are a true PokéFan!\p"
	.string "Please, take this and share it\n"
	.string "with your Pokémon!$"

VermilionCity_PokemonFanClub_Text_DidYouComeToHearAboutMyMons::
    .string "I chair the Pokémon Fan Club!\p"
    .string "I raise more than a hundred\n"
    .string "Pokémon!\p"
    .string "I'm very fussy when it comes to\n"
    .string "Pokémon! I surely am!\p"
    .string "So…\p"
    .string "Did you come visit to hear about\n"
    .string "my Pokémon?$"

VermilionCity_PokemonFanClub_Text_ComeBackToHearStory::
    .string "Oh. Come back when you want to\n"
    .string "hear my story!$"

VermilionCity_PokemonFanClub_EventScript_ChairmanStory::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmansStory
	checkitemspace ITEM_BIKE_VOUCHER, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher
	setflag FLAG_GOT_BIKE_VOUCHER
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman, MSGBOX_DEFAULT
	additem ITEM_BIKE_VOUCHER, 1
	waitfanfare
	msgbox VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmansStory::
    .string "Good!\n"
    .string "Then listen up!\p"
    .string "My favorite Rapidash…\p"
    .string "It's…cute…lovely…smart… \n"
    .string "plus…amazing…you think so?…\l"
    .string "oh yes…it's…stunning…\l"
    .string "kindly…love it!\p"
    .string "Hug it…when…sleeping…warm\n"
    .string "and cuddly…spectacular…\l"
    .string "ravishing…\l"
    .string "…Oops! Look at the time!\l"
    .string "I kept you too long!\p"
    .string "Thanks for hearing me out!\n"
    .string "I want you to have this!$"

VermilionCity_PokemonFanClub_EventScript_NoRoomForBikeVoucher::
	msgbox VermilionCity_PokemonFanClub_Text_MakeRoomForThis
	release
	end

VermilionCity_PokemonFanClub_Text_MakeRoomForThis::
    .string "Make room for this!$"

VermilionCity_PokemonFanClub_Text_ReceivedBikeVoucherFromChairman::
    .string "{PLAYER} received a Bike Voucher\n"
    .string "from the Chairman.$"

VermilionCity_PokemonFanClub_Text_ExplainBikeVoucher::
    .string "Take that Bike Voucher to the\n"
    .string "Bike Shop in Cerulean City.\p"
    .string "Exchange that for a Bicylce\n"
    .string "free of charge!\p"
    .string "Don't worry, my favorite Fearow\n"
    .string "will fly me anywhere I need to go.\p"
    .string "So, I have no need for a Bicycle.\p"
    .string "I hope you like cycling!$"

VermilionCity_PokemonFanClub_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon
	release
	end

VermilionCity_PokemonFanClub_EventScript_WorkerFGameClear::
	msgbox VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons
	release
	end

VermilionCity_PokemonFanClub_Text_ChairmanReallyAdoresHisMons::
    .string "Our Chairman really does adore his\n"
    .string "Pokémon.\p"
    .string "But the person who is most liked by\n"
    .string "Pokémon is Daisy, I think.$"

VermilionCity_PokemonFanClub_Text_ChairmanVeryVocalAboutPokemon::
    .string "Our Chairman is very vocal about\n"
    .string "Pokémon.$"

VermilionCity_PokemonFanClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 2, VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan
	msgbox VermilionCity_PokemonFanClub_Text_AdoreMySeel
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 1
	release
	end

VermilionCity_PokemonFanClub_Text_AdoreMySeel::
    .string "I just adore my Seel!\n"
    .string "It's so lovable!\p"
    .string "It squeals, “Kyuuuh,” when I\n"
    .string "hug it!$"

VermilionCity_PokemonFanClub_EventScript_WomanSpokeToFatMan::
	msgbox VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive
	closemessage
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_SeelFarMoreAttractive::
    .string "Oh, dear!\p"
    .string "My Seel is far more attractive.\n"
    .string "By double, I would say.$"

VermilionCity_PokemonFanClub_EventScript_FatMan::
	lock
	faceplayer
	goto_if_eq VAR_TEMP_1, 1, VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman
	msgbox VermilionCity_PokemonFanClub_Text_AdmirePikachusTail
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 2
	release
	end

VermilionCity_PokemonFanClub_Text_AdmirePikachusTail::
    .string "Won't you admire my Pikachu's\n"
    .string "adorable tail?$"

VermilionCity_PokemonFanClub_EventScript_FatManSpokeToWoman::
	msgbox VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_TEMP_1, 0
	release
	end

VermilionCity_PokemonFanClub_Text_PikachuTwiceAsCute::
    .string "Humph!\p"
    .string "My Pikachu is twice as cute as\n"
    .string "that one!$"

VermilionCity_PokemonFanClub_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Pikachu
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Pikachu::
    .string "Pikachu: Chu! Pikachu!$"

VermilionCity_PokemonFanClub_EventScript_Seel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SEEL, CRY_MODE_NORMAL
	msgbox VermilionCity_PokemonFanClub_Text_Seel
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Text_Seel::
    .string "Seel: Kyuoo!$"

VermilionCity_PokemonFanClub_EventScript_RulesSign1::
	msgbox VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_ListenPolitelyToOtherTrainers::
    .string "Let's all listen politely to other\n"
    .string "trainers!$"

VermilionCity_PokemonFanClub_EventScript_RulesSign2::
	msgbox VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack, MSGBOX_SIGN
	end

VermilionCity_PokemonFanClub_Text_SomeoneBragsBragBack::
    .string "If someone brags, brag right back!$"
