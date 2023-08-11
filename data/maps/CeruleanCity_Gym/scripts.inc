CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_Gym_OnTransition
	.byte 0

CeruleanCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_ResetRematchFlags
	end

CeruleanCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_MISTY_ORIGINAL
	cleartrainerflag LEADER_REMATCH_MISTY_POSTGAME
	return

CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_ChallengeMisty
	goto_if_unset FLAG_GOT_MISTY_REWARD, CeruleanCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_MISTY_REMATCH, CeruleanCity_Gym_EventScript_RematchLeader
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_EventScript_ChallengeMisty::
	msgbox CeruleanCity_Gym_Text_MistySpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge
	end

CeruleanCity_Gym_Text_MistySpeech::
    .string "Hi, you're a new face!\p"
    .string "Only those Trainers who have a\n"
    .string "policy about Pokémon can turn pro.\p"
    .string "What is your approach when you\n"
    .string "catch and train Pokémon?$"

CeruleanCity_Gym_Text_MistyIntro::
    .string "My policy is an all-out offensive\n"
    .string "with Water-type Pokémon!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Wow!\n"
    .string "You're too much!\p"
    .string "All right!$"

CeruleanCity_Gym_EventScript_DefeatedMistyGetBadge::
	msgbox CeruleanCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeruleanCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeruleanCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setflag FLAG_DAILY_MISTY_REMATCH
	settrainerflag TRAINER_PICNICKER_DIANA
	settrainerflag TRAINER_SWIMMER_MALE_LUIS
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_1
	goto CeruleanCity_Gym_EventScript_GetTM
	end

CeruleanCity_Gym_Text_GetBadge::
    .string "You can have the Cascade Badge\n"
    .string "to show you beat me.$"

CeruleanCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Cascade\n"
    .string "Badge from Misty!$"

CeruleanCity_Gym_Text_ExplainBadge::
	.string "The Cascade Badge makes all\n"
    .string "Pokémon up to Lv. 30 obey.\p"
    .string "That includes even outsiders you\n"
    .string "got in trades.\p"
    .string "There's more. You can now use Cut\n"
    .string "anytime, even out of battle.\p"
    .string "You can Cut down small trees to\n"
    .string "open new pathways.$"

CeruleanCity_Gym_EventScript_GetTM::
	msgbox CeruleanCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM03, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM03, 1
	setflag FLAG_GOT_MISTY_REWARD
	msgbox CeruleanCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	call_if_eq VAR_SEA_COTTAGE_STATE, 3, CeruleanCity_Gym_EventScript_PrepDexNavCall
	release
	end

CeruleanCity_Gym_Text_TakeThisWithYou::
	 .string "You can also have my favorite TM.$"

CeruleanCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} received TM03\n"
    .string "from Misty.$"

CeruleanCity_Gym_Text_ExplainTM::
    .string "TM03 teaches Water Pulse.\p"
    .string "Use it on an aquatic Pokémon!$"

CeruleanCity_Gym_EventScript_NoRoomForTM::
	msgbox CeruleanCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_NoRoomForTM::
    .string "You better make room for this!$"

CeruleanCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeruleanCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_LeaderPostBattle::
	.string "Misty: There are times when I want\n"
	.string "to just break free from a puny\l" 
	.string "little pool and swim in the big blue!$"

CeruleanCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeruleanCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_PostBattleGameClear::
	.string "Know what?\p"
    .string "My dream was to battle powerful\n" 
    .string "Trainers and become a Gym Leader...\p"
    .string "I made my dream come true, and now \n"
    .string "my next dream is to defeat you!$"

CeruleanCity_Gym_EventScript_RematchLeader::
	msgbox CeruleanCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_Gym_EventScript_PostgameRematch
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchLeader::
	.string "I heard an interesting rumor!\p" 
	.string "You and that other kid have been\n" 
	.string "taking on those Team Rocket guys.\p" 
	.string "Is that true?\p" 
	.string "Argh! I just can't take it anymore!\p" 
	.string "You've gotten so strong that I just\n" 
	.string "absolutely have to battle you again!\p" 
	.string "You got that? No refusing!$"

CeruleanCity_Gym_EventScript_DeclineRematch::
	msgbox CeruleanCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_DeclineRematch::
	.string "Argh! C'mon! Battle me!$"

CeruleanCity_Gym_EventScript_PostgameRematch::
	msgbox CeruleanCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeruleanCity_Gym_Text_RematchMode::
	.string "Now that you're the champion,\n"
	.string "would you like to go all out?$"

CeruleanCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_MISTY_ORIGINAL, CeruleanCity_Gym_Text_RematchOriginal, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchOriginal::
	.string "Okay, {PLAYER}!\n"
	.string "Let's go!$"

CeruleanCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_MISTY_POSTGAME, CeruleanCity_Gym_Text_RematchPostgame, CeruleanCity_Gym_Text_RematchDefeat, CeruleanCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeruleanCity_Gym_Text_RematchPostgame::
	.string "My adorable Pokémon are ready\n" 
	.string " to take you on!\p" 
	.string "The ultimate offense of\n" 
	.string "Water-type Pokémon!\p" 
	.string "I hope you're ready!$"

CeruleanCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_MISTY_REMATCH
	goto CeruleanCity_Gym_EventScript_LeaderPostBattle
	end

CeruleanCity_Gym_Text_RematchDefeat::
	.string "Hmph! How annoying!$"


CeruleanCity_Gym_EventScript_PrepDexNavCall::
	setvar VAR_SEA_COTTAGE_STATE, 4
	return

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_DianaIntro::
    .string "What? You?\n"
    .string "I'm more than good enough for you!\p"
    .string "Misty won't have to be bothered.$"

CeruleanCity_Gym_Text_DianaDefeat::
    .string "You overwhelmed me!$"

CeruleanCity_Gym_Text_DianaPostBattle::
    .string "You have to face other Trainers\n"
    .string "to see how good you really are.$"

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_Text_LuisIntro::
    .string "Splash!\p"
    .string "I'm first up!\n"
    .string "Let's do it!$"

CeruleanCity_Gym_Text_LuisDefeat::
    .string "That can't be!$"

CeruleanCity_Gym_Text_LuisPostBattle::
    .string "Misty is a Trainer who's going to\n"
    .string "keep improving.\p"
    .string "She won't lose to someone like you!$"

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Let me give you some advice!\p"
    .string "The Leader, Misty, is a pro who\n"
    .string "uses Water-type Pokémon.\p"
    .string "You can drain all their water with\n"
    .string "Grass-type Pokémon.\p"
    .string "Or, you might use Electric-type\n"
    .string "Pokémon and zap them!$"

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
    .string "You beat Misty!\n"
    .string "See, what'd I tell ya?\p"
    .string "You and me, kid, we make a pretty\n"
    .string "darn-good team!$"

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "Cerulean Pokémon Gym\n"
    .string "Leader: Misty\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
