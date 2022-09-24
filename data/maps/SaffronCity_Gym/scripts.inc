SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHANNA, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_JohanIntro::
    .string "Does our unseen power scare you?$"

SaffronCity_Gym_Text_JohanDefeat::
    .string "I never foresaw this!$"

SaffronCity_Gym_Text_JohanPostBattle::
    .string "Psychic Pokémon fear only ghosts\n"
    .string "and bugs!$"

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TRISH, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TyronIntro::
    .string "You understand, don't you?\p"
    .string "That power alone isn't enough to\n"
    .string "win in the world of Pokémon?$"

SaffronCity_Gym_Text_TyronDefeat::
    .string "I don't believe this!$"

SaffronCity_Gym_Text_TyronPostBattle::
    .string "Sabrina just wiped out the Karate\n"
    .string "Master next door.$"

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_CameronIntro::
    .string "Sabrina is young, but she's also\n"
    .string "our highly skilled Leader.\p"
    .string "You won't reach her easily!$"

SaffronCity_Gym_Text_CameronDefeat::
    .string "Ow!\n"
    .string "Down and out!$"

SaffronCity_Gym_Text_CameronPostBattle::
    .string "There used to be two Pokémon Gyms\n"
    .string "in Saffron.\p"
    .string "The Fighting Dojo next door lost\n"
    .string "its Gym status, though.\p"
    .string "We simply creamed them when we\n"
    .string "decided to have just one Gym.$"

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_PrestonIntro::
    .string "Saffron Pokémon Gym is famous for\n"
    .string "training psychics.\p"
    .string "You want to see Sabrina, don't\n"
    .string "you? I can tell!$"

SaffronCity_Gym_Text_PrestonDefeat::
    .string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
    .string "That's right! I used telepathy to\n"
    .string "read your mind!$"

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_AmandaIntro::
    .string "Sabrina is far younger than I,\n"
    .string "but she has earned my respect.$"

SaffronCity_Gym_Text_AmandaDefeat::
    .string "Not good enough!$"

SaffronCity_Gym_Text_AmandaPostBattle::
    .string "In a battle of equals, the one\n"
    .string "with the stronger will wins.\p"
    .string "If you wish to beat Sabrina, focus\n"
    .string "and will yourself to victory.$"

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_StacyIntro::
    .string "Pokémon take on the appearance of\n"
    .string "their trainers.\p"
    .string "Your Pokémon must be tough, then!$"

SaffronCity_Gym_Text_StacyDefeat::
    .string "I knew it!$"

SaffronCity_Gym_Text_StacyPostBattle::
    .string "I have much to learn still…\p"
    .string "I must master Psychic and teach it\n"
    .string "to my Pokémon…$"

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_Text_TashaIntro::
    .string "You and I, our Pokémon shall\n"
    .string "battle!$"

SaffronCity_Gym_Text_TashaDefeat::
    .string "I lost after all!$"

SaffronCity_Gym_Text_TashaPostBattle::
    .string "I knew that this was going to take\n"
    .string "place.$"


SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SABRINA_REWARD, SaffronCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SABRINA_REMATCH, SaffronCity_Gym_EventScript_RematchLeader
	goto SaffronCity_Gym_EventScript_LeaderPostBattle
	end

SaffronCity_Gym_EventScript_ChallengeLeader::
	msgbox SaffronCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_LeaderIntro, SaffronCity_Gym_Text_LeaderDefeat, SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

SaffronCity_Gym_Text_LeaderSpeech::
    .string "I had a vision of your arrival.\p"
    .string "I have had psychic powers since\n"
    .string "I was a child.\p"
    .string "It started when a spoon I\n"
    .string "carelessly tossed, bent.$"

SaffronCity_Gym_Text_LeaderIntro::
    .string "I dislike battling, but if you wish,\n"
    .string "I will show you my powers!$"

SaffronCity_Gym_Text_LeaderDefeat::
    .string "This loss shocks me!\n"
    .string "But, a loss is a loss.$"

SaffronCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox SaffronCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message SaffronCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox SaffronCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE06_GET
	setflag FLAG_DAILY_SABRINA_REMATCH
	settrainerflag TRAINER_PSYCHIC_PRESTON
	settrainerflag TRAINER_PSYCHIC_CAMERON				
	settrainerflag TRAINER_CHANNELER_TASHA
	settrainerflag TRAINER_PSYCHIC_TRISH
	settrainerflag TRAINER_CHANNELER_STACY
	settrainerflag TRAINER_PSYCHIC_JOHANNA
	settrainerflag TRAINER_CHANNELER_AMANDA
	goto SaffronCity_Gym_EventScript_GetTM
	end

SaffronCity_Gym_Text_GetBadge::
    .string "I admit, I didn't work hard enough\n"
    .string "to win.\p"
    .string "Your victory has earned you the\n"
    .string "Marsh Badge.$"

SaffronCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Soul\n"
    .string "Badge from Sabrina!$"

SaffronCity_Gym_Text_ExplainBadge::
    .string "The Marsh Badge makes Pokémon up\n"
    .string "to Lv. 70 obey you.\p"
    .string "Stronger Pokémon will become wild,\n"
    .string "ignoring your orders in battle.\p"
    .string "Just don't raise your Pokémon too\n"
    .string "much to avoid that problem.$"

SaffronCity_Gym_EventScript_GetTM::
	msgbox SaffronCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM04, 1
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox SaffronCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM04, 1
	setflag FLAG_GOT_SABRINA_REWARD
	msgbox SaffronCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_TakeThisWithYou::
    .string "Wait, please take this TM with you.$"

SaffronCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} received TM04\n"
    .string "from Sabrina.$"

SaffronCity_Gym_Text_ExplainTM::
    .string "TM04 is Calm Mind.\p"
    .string "It makes the Pokémon concentrate\n"
    .string "to raise both Sp. Atk and Sp. Def.$"

SaffronCity_Gym_EventScript_NoRoomForTM::
	msgbox SaffronCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_NoRoomForTM::
    .string "Your Bag is full of other items.$"

SaffronCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_IS_CURRENTLY_CHAMPION, SaffronCity_Gym_EventScript_LeaderPostBattleCurrentChampion
	goto_if_set FLAG_SYS_GAME_CLEAR, SaffronCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox SaffronCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_LeaderPostBattle::
    .string "Psychic power isn't something that\n"
    .string "only a few people have.\p"
    .string "Everyone has psychic power.\n"
    .string "People just don't realize it.$"

SaffronCity_Gym_EventScript_LeaderPostBattleCurrentChampion::
	msgbox SaffronCity_Gym_Text_PostBattleCurrentChampion, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_PostBattleCurrentChampion::
	.string "With Trainers like you and {RIVAL}\n" 
	.string "the Pokémon League must be a place of\l"
	.string "formidable strength!\p" 
	.string "Truly, it is something to be proud of!\p"
	.string "As it so happens, I have been thinking\n"
	.string "of aiming to join the Elite Four myself...$"

SaffronCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox SaffronCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

SaffronCity_Gym_Text_PostBattleGameClear::
	.string "You have done well.\p" 
	.string "If I cannot match you now, I \n"
	.string "can only train further.\p" 
	.string "Continue testing your skill!$"

@TODO: Leader Rematches
SaffronCity_Gym_EventScript_RematchLeader::
	msgbox SaffronCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	release
	end

SaffronCity_Gym_Text_RematchLeader::
	.string "Fwahahaha! If it isn't the child.\n" 
	.string "It seems we are fated to meet once again.\p" 
	.string "You have come at a truly opportune time.\n" 
	.string "I was just thinking that I wanted to test\l"
	.string "my newly refined sinister techniques...\l" 
	.string "in a battle that will end in your utter defeat!$"


SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Sabrina's Pokémon use psychic\n"
    .string "power instead of force.\p"
    .string "Fighting Pokémon are especially\n"
    .string "weak against Psychic Pokémon.\p"
    .string "They'll get destroyed before they\n"
    .string "can even aim a punch!$"

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_Text_GymGuyPostVictory::
    .string "Psychic power, huh?\p"
    .string "If I had that, I'd make a bundle\n"
    .string "at the slots!$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_Text_GymStatue::
    .string "Saffron Pokémon GYM\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "Saffron Pokémon GYM\n"
    .string "Leader: Sabrina\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
