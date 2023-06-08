.set LOCALID_GIOVANNI, 1
.set LOCALID_RIVAL, 2

ViridianCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_Gym_OnTransition
	.byte 0

ViridianCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_ResetRematchFlags
	end

ViridianCity_Gym_ResetRematchFlags::
	cleartrainerflag TRAINER_RIVAL_POSTGAME_JOLTEON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_FLAREON
	cleartrainerflag TRAINER_RIVAL_POSTGAME_VAPOREON
	return

ViridianCity_Gym_EventScript_Giovanni::
	msgbox ViridianCity_Gym_Text_GiovanniSpeech, MSGBOX_NPC
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni
	goto_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_Text_GiovanniSpeech::
    .string "Fwahahaha!\n"
    .string "Welcome to my hideout!\p"
    .string "It shall be so until I can restore\n"
    .string "Team Rocket to its former glory.\p"
    .string "But, you have found me again.\n"
    .string "So be it.$"

ViridianCity_Gym_Text_GiovanniIntro::
    .string "This time, I'm not holding back!\p"
    .string "Once more, you shall face\n"
    .string "Giovanni, the greatest Trainer!$"

ViridianCity_Gym_Text_GiovanniPostBattle::
    .string "Having lost in this fashion, \n"
    .string "I can't face my followers.\l"
    .string "I have betrayed their trust.\p"
    .string "As of today, Team Rocket is\n"
    .string "finished forever!\p"
    .string "As for myself, I shall dedicate\n"
    .string "my life to training again.\p"
    .string "Let us meet again someday!\n"
    .string "Farewell!$"

ViridianCity_Gym_Text_GiovanniDefeat::
    .string "Ha!\n"
    .string "That was a truly intense fight.$"

ViridianCity_Gym_Text_GiovanniGiveBadge::
    .string "You have won!\p"
    .string "As proof, here is the Earth Badge!$"

ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni::
    .string "{PLAYER} received the Earth Badge\n"
    .string "from Giovanni.$"

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	msgbox ViridianCity_Gym_Text_GiovanniGiveBadge
	playfanfare MUS_OBTAIN_BADGE
	message ViridianCity_Gym_Text_ReceivedBadgeFromGiovanni
	waitmessage
	waitfanfare
	settrainerflag 	TRAINER_TAMER_JASON							
	settrainerflag 	TRAINER_TAMER_COLE							
	settrainerflag 	TRAINER_BLACK_BELT_ATSUSHI					
	settrainerflag 	TRAINER_BLACK_BELT_KIYO						
	settrainerflag 	TRAINER_BLACK_BELT_TAKASHI					
	settrainerflag 	TRAINER_COOLTRAINER_SAMUEL					
	settrainerflag 	TRAINER_COOLTRAINER_YUJI					
	settrainerflag 	TRAINER_COOLTRAINER_WARREN					
	setflag FLAG_BADGE08_GET
	setvar VAR_ROUTE_22_RIVAL_STATE, 4
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM26
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromGiovanni
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
    .string "The Earth Badge makes Pokémon of\n"
    .string "any level obey without question.\p"
    .string "It is evidence of your mastery as\n"
    .string "a Pokémon Trainer.\p"
    .string "With it, you can challenge the\n"
    .string "Pokémon League.\p"
    .string "Also, take this TM.\p"
    .string "Consider it a gift for your Pokémon\n"
    .string "League challenge.$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
    .string "{PLAYER} received TM26\n"
    .string "from Giovanni.$"

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_Text_ExplainTM26::
    .string "TM26 contains Earthquake.\p"
    .string "It is a powerful attack that causes\n"
    .string "a massive tremor.\p"
    .string "I made it when I ran the Gym here,\n"
    .string "far too long ago… $"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
    .string "You do not have space for this!\p"
    .string "I will not remain here for long.\p"
    .string "You should make room and speak to\n"
    .string "me again.$"


ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_JasonIntro::
    .string "Pokémon and I, we make wonderful\n"
    .string "music together!$"

ViridianCity_Gym_Text_JasonDefeat::
    .string "You are in perfect harmony!$"

ViridianCity_Gym_Text_JasonPostBattle::
    .string "Do you know the identity of our\n"
    .string "Gym Leader?$"

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_ColeIntro::
    .string "Your Pokémon will cower at the\n"
    .string "crack of my whip!$"

ViridianCity_Gym_Text_ColeDefeat::
    .string "Yowch!\n"
    .string "Whiplash!$"

ViridianCity_Gym_Text_ColePostBattle::
    .string "Wait!\n"
    .string "I was just careless!$"

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_AtsushiIntro::
    .string "Rrrroar!\n"
    .string "I'm working myself into a rage!$"

ViridianCity_Gym_Text_AtsushiDefeat::
    .string "Wargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
    .string "I'm still not worthy!$"

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_KiyoIntro::
    .string "Karate is the ultimate form of\n"
    .string "martial arts!$"

ViridianCity_Gym_Text_KiyoDefeat::
    .string "Aiyah!$"

ViridianCity_Gym_Text_KiyoPostBattle::
    .string "If my Pokémon were as good at\n"
    .string "karate as I…$"

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_TakashiIntro::
    .string "I'm the Karate King!\n"
    .string "Your fate rests with me!$"

ViridianCity_Gym_Text_TakashiDefeat::
    .string "Ayah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
    .string "The Pokémon League?\n"
    .string "You? Don't get cocky!$"

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_SamuelIntro::
    .string "Viridian Gym was closed for a\n"
    .string "long time.\p"
    .string "But now, our Leader is back!$"

ViridianCity_Gym_Text_SamuelDefeat::
    .string "I was beaten?$"

ViridianCity_Gym_Text_SamuelPostBattle::
    .string "You can go on to the Pokémon\n"
    .string "League only by defeating our Gym\l"
    .string "Leader!$"

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_YujiIntro::
    .string "Heh!\n"
    .string "You must be running out of steam\l"
    .string "by now!$"

ViridianCity_Gym_Text_YujiDefeat::
    .string "I ran out of gas!$"

ViridianCity_Gym_Text_YujiPostBattle::
    .string "You'll need power to keep up with\n"
    .string "our Gym Leader.$"

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_Text_WarrenIntro::
    .string "The truly talented win with style.$"

ViridianCity_Gym_Text_WarrenDefeat::
    .string "I lost my grip!$"

ViridianCity_Gym_Text_WarrenPostBattle::
    .string "The Leader will scold me for\n"
    .string "losing this way…$"


ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Even I don't know the Viridian\n"
    .string "Leader's identity.\p"
    .string "But one thing's certain.\n"
    .string "This will be the toughest of all\l"
    .string "the Gym LeaderS.\p"
    .string "Also, I heard that the Trainers\n"
    .string "here like Ground type Pokémon.$"

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_Text_GymGuyPostVictory::
    .string "Blow me away! Giovanni was the\n"
    .string "Gym Leader of Viridian?$"

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: ?\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "Viridian Pokémon Gym\n"
    .string "Leader: ?\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

ViridianCity_Gym_EventScript_Rival::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_RIVAL_REMATCH, ViridianCity_Gym_EventScript_RivalPostBattle
	goto_if_set FLAG_RIVAL_REMATCHED, ViridianCity_Gym_EventScript_SkipRivalSpeech
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	msgbox ViridianCity_Gym_Text_RivalSpeech, MSGBOX_NPC
	setflag FLAG_RIVAL_REMATCHED
ViridianCity_Gym_EventScript_SkipRivalSpeech::
	msgbox ViridianCity_Gym_Text_RematchLeader, MSGBOX_DEFAULT
	goto_if_eq VAR_RIVAL_WINRATE, 2, ViridianCity_Gym_EventScript_RivalJolteon
	goto_if_eq VAR_RIVAL_WINRATE, 1, ViridianCity_Gym_EventScript_RivalFlareon
	goto ViridianCity_Gym_EventScript_RivalVaporeon
	end

ViridianCity_Gym_Text_RivalSpeech::
	.string "{RIVAL}: ...{PLAYER}?\n"
	.string "I've just been thinking...\p"
	.string "Back when I started this journey,\n"
	.string "I really thought I was the best\l"
	.string "there ever was...\p"
	.string "But you were always there, right\n"
	.string "behind me...and I got careless.\p"
	.string "I need to take some time to reflect.\n"
	.string "Who knows...\p"
	.string "I may not be the champion, but maybe\n"
	.string "one day, I could be a Gym Leader...\p"
	.string "...\p"
	.string "Eh, whatever! No time to get all\n"
	.string "sentimental!$"

ViridianCity_Gym_Text_RematchLeader::
	.string "So what are you doing here?\n"
	.string "Come here to rub it in?\p"
	.string "Well, you made a mistake!\p"
	.string "Don't think I'll just let you show\n"
	.string "up without challenging you to a battle!$"

ViridianCity_Gym_EventScript_RivalJolteon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_JOLTEON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalFlareon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_FLAREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_EventScript_RivalVaporeon::
	trainerbattle_single TRAINER_RIVAL_POSTGAME_VAPOREON, ViridianCity_Gym_Text_RivalIntro, ViridianCity_Gym_Text_RivalDefeat, ViridianCity_Gym_EventScript_DefeatedRival
	end

ViridianCity_Gym_Text_RivalIntro::
	.string "All right!\n"
	.string "It's been a while since I've gone all out.\p"
	.string "I'll prove I'm still the best there is!$"

ViridianCity_Gym_Text_RivalDefeat::
	.string "Aw man, what was I doing?$"

ViridianCity_Gym_EventScript_DefeatedRival::
	setflag FLAG_DAILY_RIVAL_REMATCH
ViridianCity_Gym_EventScript_RivalPostBattle::
	msgbox ViridianCity_Gym_Text_RivalPostBattle, MSGBOX_DEFAULT
	call_if_unset FLAG_GOT_GIOVANNI_REWARD, ViridianCity_Gym_EventScript_RivalFoundTM
	turnobject LOCALID_RIVAL, DIR_NORTH
	release
	end

ViridianCity_Gym_Text_RivalPostBattle::
	.string "I don't like to admit it, but I'm\n"
	.string "still not at your level.\p"
	.string "But next time, I'll beat you!$"

ViridianCity_Gym_EventScript_RivalFoundTM::
	msgbox ViridianCity_Gym_Text_FoundThis, MSGBOX_DEFAULT
	checkitemspace ITEM_TM26, 1
	compare VAR_RESULT, FALSE
	goto_if_eq ViridianCity_Gym_EventScript_NoRoomForTM262
	playfanfare MUS_OBTAIN_TMHM
	message ViridianCity_Gym_Text_ReceivedTM26FromRival
	waitmessage
	waitfanfare
	additem ITEM_TM26, 1
	setflag FLAG_GOT_GIOVANNI_REWARD
	msgbox ViridianCity_Gym_Text_RivalExplainTM26	
	return

ViridianCity_Gym_Text_FoundThis::
	.string "Oh, I almost forgot!\p"
	.string "I found this when I was scoping this\n" 
	.string "place out.\p"
	.string "As much as I hate rewarding you, I\n"
	.string "already have this TM.\p" 
	.string "You should take it.$"

ViridianCity_Gym_Text_ReceivedTM26FromRival::
    .string "{PLAYER} received TM26\n"
    .string "from {RIVAL}.$"

ViridianCity_Gym_EventScript_NoRoomForTM262::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace2
	release
	end

ViridianCity_Gym_Text_RivalExplainTM26::
    .string "TM26 contains Earthquake.\p"
    .string "It is a powerful attack that causes\n"
    .string "a massive tremor.$"

ViridianCity_Gym_Text_YouDoNotHaveSpace2::
    .string "Oh, you don't have space for this?\p"
    .string "Too bad! Guess I'll keep it. Ha!$"
