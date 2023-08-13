FuchsiaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

FuchsiaCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_ResetRematchFlags
	end

FuchsiaCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_KOGA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_KOGA_POSTGAME
	return

FuchsiaCity_Gym_EventScript_Koga::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_KOGA_REWARD, FuchsiaCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_KOGA_REMATCH, FuchsiaCity_Gym_EventScript_RematchLeader
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_EventScript_ChallengeLeader::
	msgbox FuchsiaCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_LeaderIntro, FuchsiaCity_Gym_Text_LeaderDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

FuchsiaCity_Gym_Text_LeaderSpeech::
    .string "Koga: Fwahahaha!\p"
    .string "A mere child like you dares to\n"
    .string "challenge me?\p"
    .string "The very idea makes me shiver\n"
    .string "with mirth!\p"
    .string "Very well, I shall show you true\n"
    .string "terror as a ninja master.\p"
    .string "Poison brings steady doom.\n"
    .string "Sleep renders foes helpless.$"

FuchsiaCity_Gym_Text_LeaderIntro::
    .string "Despair to the creeping horror of\n"
    .string "Poison-type Pokémon!$"

FuchsiaCity_Gym_Text_LeaderDefeat::
    .string "Humph!\n"
    .string "You have proven your worth!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox FuchsiaCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message FuchsiaCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox FuchsiaCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DAILY_KOGA_REMATCH
	settrainerflag TRAINER_TAMER_PHIL					
	settrainerflag TRAINER_TAMER_EDGAR
	settrainerflag TRAINER_JUGGLER_KIRK
	settrainerflag TRAINER_JUGGLER_SHAWN
	settrainerflag TRAINER_JUGGLER_KAYDEN
	settrainerflag TRAINER_JUGGLER_NATE
	call_if_set FLAG_RECEIVED_ITEMFINDER, FuchsiaCity_Gym_EventScript_QueueNextAideCall
	goto FuchsiaCity_Gym_EventScript_GetTM
	end

FuchsiaCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_4
	return

FuchsiaCity_Gym_Text_GetBadge::
    .string "Here!\n"
    .string "Take the Soul Badge!$"

FuchsiaCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Soul\n"
    .string "Badge from Koga!$"

FuchsiaCity_Gym_Text_ExplainBadge::
    .string "The Soul Badge will allow you\n"
   .string "to SURF outside of battle.$"

FuchsiaCity_Gym_EventScript_GetTM::
	msgbox FuchsiaCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM06, 1
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox FuchsiaCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM06, 1
	setflag FLAG_GOT_KOGA_REWARD
	msgbox FuchsiaCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_TakeThisWithYou::
    .string "Ah!\n"
    .string "Take this, too!$"

FuchsiaCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} received TM06\n"
    .string "from Koga.$"

FuchsiaCity_Gym_Text_ExplainTM::
    .string "Sealed within that TM06 lies\n"
    .string "Toxic!\p"
    .string "It is a secret technique dating\n"
    .string "back some four hundred years.$"

FuchsiaCity_Gym_EventScript_NoRoomForTM::
	msgbox FuchsiaCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_NoRoomForTM::
    .string "Make space for this, child!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox FuchsiaCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_LeaderPostBattle::
    .string "When afflicted by Toxic, a Pokémon\n"
    .string "suffers more and more.\p"
    .string "It suffers worsening damage as the\n"
    .string "battle wears on!\p"
    .string "It will surely terrorize foes!$"

FuchsiaCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox FuchsiaCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_PostBattleGameClear::
	.string "With Trainers like you and {RIVAL}\n" 
	.string "the Pokémon League must be a place of\l"
	.string "formidable strength!\p" 
	.string "Truly, it is something to be proud of!\p"
	.string "As it so happens, I have been thinking\n"
	.string "of aiming to join the Elite Four myself...$"

FuchsiaCity_Gym_EventScript_RematchLeader::
	msgbox FuchsiaCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, FuchsiaCity_Gym_EventScript_PostgameRematch
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchLeader::
	.string "Fwahahaha! If it isn't the child.\p" 
	.string "It seems we are fated to meet once\n"
	.string "again.\p"
	.string "You have come at a truly opportune\n"
	.string "time.\p"
	.string "I was just thinking that I wanted to \n"
	.string "test my newly refined sinister\l"
	.string "techniques...\p" 
	.string "...in a battle that will end in\n"
	.string "your utter defeat!\n"
	.string "Will you accept my challenge?$"

FuchsiaCity_Gym_EventScript_DeclineRematch::
	msgbox FuchsiaCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_Text_DeclineRematch::
	.string "You have already lost!$"

FuchsiaCity_Gym_EventScript_PostgameRematch::
	msgbox FuchsiaCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

FuchsiaCity_Gym_Text_RematchMode::
	.string "Now that you're the champion,\n"
	.string "would you like to go all out?$"

FuchsiaCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_KOGA_ORIGINAL, FuchsiaCity_Gym_Text_RematchOriginal, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchOriginal::
	.string "Fwahahaha!\n" 
	.string "Let us relive our past battles!$" 

FuchsiaCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_KOGA_POSTGAME, FuchsiaCity_Gym_Text_RematchPostgame, FuchsiaCity_Gym_Text_RematchDefeat, FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch
	end

FuchsiaCity_Gym_Text_RematchPostgame::
	.string "Fwahahaha!\p" 
	.string "Today I'll not only defeat you, but I\n" 
	.string "will also demonstrate my fatherly dignity\l" 
	.string "to my daughter!$"

FuchsiaCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_KOGA_REMATCH
	goto FuchsiaCity_Gym_EventScript_LeaderPostBattle
	end

FuchsiaCity_Gym_Text_RematchDefeat::
	.string "...If I am not strong enough to defeat\n" 
	.string "you now, there is but one thing to do.\p" 
	.string "I must hone my skills.$"

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_PhilIntro::
    .string "Stop right there!\p"
    .string "The famed invisible walls of\n"
    .string "Fuchsia Gym have you frustrated?$"

FuchsiaCity_Gym_Text_PhilDefeat::
    .string "Whoa!\n"
    .string "You've got it!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
    .string "You impressed me!\n"
    .string "Here's a hint!\p"
    .string "Look very closely for gaps in the\n"
    .string "invisible walls!$"

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_EdgarIntro::
    .string "I also study the way of the ninja\n"
    .string "with Master Koga!\p"
    .string "Ninja have a long history of using\n"
    .string "animals!$"

FuchsiaCity_Gym_Text_EdgarDefeat::
    .string "Awoo!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
    .string "I still have much to learn.$"

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KirkIntro::
    .string "I was a magician once upon a time.\p"
    .string "But I dreamt of becoming a ninja,\n"
    .string "so I joined this gym.$"

FuchsiaCity_Gym_Text_KirkDefeat::
    .string "I'm done for!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
    .string "Even though I've lost, I will keep\n"
    .string "training according to the teachings\l"
    .string "of Koga, my ninja master.$"

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_ShawnIntro::
    .string "Master Koga comes from a long line\n"
    .string "of ninjas.\p"
    .string "What did you descend from?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
    .string "You're more skilled than I'd\n"
    .string "thought!$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
    .string "Where there is light, there is\n"
    .string "shadow!\p"
    .string "Light and shadow!\n"
    .string "Which do you choose?$"

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_KaydenIntro::
    .string "Strength isn't the key for Pokémon.\n"
    .string "Do you understand this?\p"
    .string "Pokémon is about strategy!\p"
    .string "I'll show you how strategy can\n"
    .string "beat brute strength.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
    .string "What?\n"
    .string "Extraordinary!$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
    .string "So, you mix brawn with brains?\n"
    .string "Good strategy!\p"
    .string "That's remarkable for a child\n"
    .string "trainer.$"

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_Text_NateIntro::
    .string "Let's see you beat my special\n"
    .string "techniques!$"

FuchsiaCity_Gym_Text_NateDefeat::
    .string "You had me fooled!$"

FuchsiaCity_Gym_Text_NatePostBattle::
    .string "I like poison and sleep techniques,\n"
    .string "as they linger after battle!$"

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Fuchsia Gym is a tricked-up place.\n"
    .string "It's riddled with invisible walls!\p"
    .string "Koga might appear close, but he's\n"
    .string "blocked off.\p"
    .string "You have to find gaps in the walls\n"
    .string "to reach him.$"

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_Text_GymGuyPostVictory::
    .string "It's amazing how ninja can terrify,\n"
    .string "even now!$"

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_GymStatue::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
    .string "Fuchsia Pokémon Gym\n"
    .string "Leader: Koga\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"

