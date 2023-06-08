.set LOCALID_SCOTT, 3

PewterCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_Gym_OnTransition
	.byte 0

PewterCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_ResetRematchFlags
	end

PewterCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_BROCK_ORIGINAL
	cleartrainerflag LEADER_REMATCH_BROCK_POSTGAME
	return

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ChallengeBrock
	goto_if_unset FLAG_GOT_BROCK_REWARD, PewterCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_BROCK_REMATCH, PewterCity_Gym_EventScript_RematchLeader
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_EventScript_ChallengeBrock::
	msgbox PewterCity_Gym_Text_BrockSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_BROCK, PewterCity_Gym_Text_BrockIntro, PewterCity_Gym_Text_BrockDefeat, PewterCity_Gym_EventScript_DefeatedBrockGetBadge
	end

PewterCity_Gym_Text_BrockSpeech::
	.string "So, you're here. I'm Brock.\n"
    .string "I'm Pewter's Gym Leader.\p"
    .string "My rock-hard willpower is evident\n"
    .string "even in my Pokémon.\p"
    .string "My Pokémon are all rock hard, and\n"
    .string "have true-grit determination.\p"
    .string "That's right - my Pokémon are all\n"
    .string "the Rock type!\p"
    .string "Fuhaha! You're going to challenge\n"
    .string "me knowing that you'll lose?\p"
    .string "That's the trainer's honor that\n"
    .string "compels you to challenge me.$"

PewterCity_Gym_Text_BrockIntro::
    .string "Fine, then!\n"
    .string "Show me your best!$"

PewterCity_Gym_Text_BrockDefeat::
    .string "I took you for granted, and so\n"
    .string "I lost.$"

PewterCity_Gym_EventScript_DefeatedBrockGetBadge::
	msgbox PewterCity_Gym_Text_GetBadgeFromBrock, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message PewterCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox PewterCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DAILY_BROCK_REMATCH
	setflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	settrainerflag TRAINER_CAMPER_LIAM
	setvar VAR_PEWTER_CITY_STATE, 1
	goto PewterCity_Gym_EventScript_GetTM
	end

PewterCity_Gym_Text_GetBadgeFromBrock::
	.string "As proof of your victory, I confer\n"
    .string "on you this…the official Pokémon\l"
    .string "League Boulder Badge.$"

PewterCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Boulder\n"
    .string "Badge from Brock!$"

PewterCity_Gym_Text_ExplainBadge::
	.string "Just having the Boulder Badge makes\n"
    .string "your Pokémon more powerful.\p"
    .string "It also enables the use of the\n"
    .string "move Flash outside of battle.\p"
    .string "Of course, a Pokémon must know the\n"
    .string "move Flash to use it.$"

PewterCity_Gym_EventScript_GetTM::
	msgbox PewterCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM39, 1
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox PewterCity_Gym_Text_ReceivedTMFromBrock, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM39, 1
	setflag FLAG_GOT_BROCK_REWARD
	msgbox PewterCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TakeThisWithYou::
    .string "Wait!\n"
    .string "Take this with you.$"

PewterCity_Gym_Text_ReceivedTMFromBrock::
    .string "{PLAYER} received TM39\n"
    .string "from Brock.$"

PewterCity_Gym_Text_ExplainTM::
    .string "A TM, Technical Machine, contains a\n"
    .string "technique for Pokémon.\p"
    .string "Using a TM teaches the move it\n"
    .string "contains to a Pokémon.\p"
    .string "TM39 contains Rock Tomb.\p"
    .string "It hurls boulders at the foe and\n"
    .string "lowers its speed.$"

PewterCity_Gym_EventScript_NoRoomForTM::
	msgbox PewterCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_NoRoomForTM::
    .string "You don't have room for this.$"

PewterCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox PewterCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_LeaderPostBattle::
    .string "There are all kinds of trainers in\n"
    .string "this huge world of ours.\p"
    .string "You appear to be very gifted as a\n"
    .string "Pokémon Trainer.\p"
    .string "So let me make a suggestion.\p"
    .string "Go to the Gym in Cerulean and test\n"
    .string "your abilities.$"

PewterCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox PewterCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_PostBattleGameClear::
	.string "You've come a long way since\n"
	.string "you earned your Boulder Badge, {PLAYER}!$"

PewterCity_Gym_EventScript_RematchLeader::
	msgbox PewterCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, PewterCity_Gym_EventScript_PostgameRematch
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchLeader::
	.string "...You sure look different from when we\n" 
	.string "first met!\p" 
	.string "...Please allow me the privilege of facing\n" 
	.string "you in battle once again!$" 

PewterCity_Gym_EventScript_DeclineRematch::
	msgbox PewterCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_DeclineRematch::
	.string "I see...$"

PewterCity_Gym_EventScript_PostgameRematch::
	msgbox PewterCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

PewterCity_Gym_Text_RematchMode::
	.string "Now that you're the champion,\n"
	.string "would you like to go all out?$"

PewterCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_BROCK_ORIGINAL, PewterCity_Gym_Text_RematchOriginal, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchOriginal::
	.string "Alright, {PLAYER}!\n"
	.string "Let's relive our first battle!$"

PewterCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_BROCK_POSTGAME, PewterCity_Gym_Text_RematchPostgame, PewterCity_Gym_Text_RematchDefeat, PewterCity_Gym_EventScript_DefeatedLeaderRematch
	end

PewterCity_Gym_Text_RematchPostgame::
	.string "Allow me to show you the true rock-hard\n" 
	.string "strength of my Pokémon!$"

PewterCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_BROCK_REMATCH
	goto PewterCity_Gym_EventScript_LeaderPostBattle
	end

PewterCity_Gym_Text_RematchDefeat::
	.string "I knew you were strong, but this...$"

PewterCity_Gym_EventScript_Liam::
	trainerbattle_single TRAINER_CAMPER_LIAM, PewterCity_Gym_Text_LiamIntro, PewterCity_Gym_Text_LiamDefeat
	msgbox PewterCity_Gym_Text_LiamPostBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_Text_LiamIntro::
    .string "Stop right there, kid!\p"
    .string "You're ten thousand light-years \n"
    .string "from facing Brock!$"

PewterCity_Gym_Text_LiamDefeat::
    .string "Darn!\p"
    .string "Light-years isn't time…\n"
    .string "It measures distance!$"

PewterCity_Gym_Text_LiamPostBattle::
    .string "You're pretty hot.\n"
    .string "…But not as hot as Brock!$"

PewterCity_Gym_EventScript_ScottTrigger1::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott1
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott1:
	walk_up
	walk_up
	walk_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger2::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott2
	waitmovement 0
	turnobject LOCALID_SCOTT, DIR_WEST
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott2:
	walk_up
	face_right
	step_end

PewterCity_Gym_EventScript_ScottTrigger3::
	call PewterCity_Gym_EventScript_ScottTriggered
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToScott3
	waitmovement 0
	goto PewterCity_Gym_EventScript_ThatWasReallySomething
	end

Movement_MoveToScott3:
	walk_up
	step_end

PewterCity_Gym_EventScript_ScottTriggered::
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox PewterCity_Gym_Text_HeyWaitUp, MSGBOX_DEFAULT
	return

PewterCity_Gym_Text_HeyWaitUp::
	.string "Hey kid! Wait up!$"

PewterCity_Gym_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_SCOTT, PewterCity_Gym_EventScript_GymGuyPostVictory
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_ThatWasReallySomething
	msgbox PewterCity_Gym_Text_LetMeTakeYouToTheTop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Gym_EventScript_GymGuyTakeMeToTop
	goto_if_eq VAR_RESULT, NO, PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop
	end

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
    .string "Hiya!\n"
    .string "Do you want to dream big?\p"
    .string "Do you dare to dream of becoming\n"
    .string "the Pokémon champ?\p"
    .string "I'm no trainer, but I can advise\n"
    .string "you on how to win.\p"
    .string "Let me take you to the top!$"

PewterCity_Gym_EventScript_GymGuyTakeMeToTop::
	msgbox PewterCity_Gym_Text_LetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_LetsGetHappening::
    .string "All right!\n"
    .string "Let's get happening!$"

PewterCity_Gym_EventScript_GymGuyDontTakeMeToTop::
	msgbox PewterCity_Gym_Text_ItsFreeLetsGetHappening, MSGBOX_DEFAULT
	goto PewterCity_Gym_EventScript_GymGuyAdvice
	end

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
    .string "It's a free service!\n"
    .string "Let's get happening!$"

PewterCity_Gym_EventScript_GymGuyAdvice::
	msgbox PewterCity_Gym_Text_TryDifferentPartyOrders, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_TryDifferentPartyOrders::
    .string "The first Pokémon out in a match is\n"
    .string "at the left of the Pokémon List.\p"
    .string "By changing the order of Pokémon,\n"
    .string "you may gain an advantage.\p"
    .string "Try different orders to suit your\n"
    .string "opponent's party.$"


PewterCity_Gym_EventScript_GymGuyPostVictory::
	msgbox PewterCity_Gym_Text_YoureChampMaterial, MSGBOX_DEFAULT
	release
	end

PewterCity_Gym_Text_YoureChampMaterial::
    .string "You're Pokémon champ material!$"

PewterCity_Gym_EventScript_ThatWasReallySomething::
	msgbox PewterCity_Gym_Text_ThatWasReallySomething, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_SCOTT
	setvar VAR_PEWTER_CITY_STATE, 2
	release
	end

PewterCity_Gym_Text_ThatWasReallySomething::
    .string "Wow, that was really something!\p"
    .string "It may have only been your first\n"
    .string "Gym Badge, but I have a sense for\l"
    .string "this kind of thing.\p"
    .string "You've got what it takes!\p"
    .string "Listen, I'm searching across Kanto\n"
    .string "for talented trainers.\p"
    .string "Let me give you my number.\n"
    .string "It might come in handy!$"

PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "Pewter Pokémon Gym\n"
    .string "Leader: Brock\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
