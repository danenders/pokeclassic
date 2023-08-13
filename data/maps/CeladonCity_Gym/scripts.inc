CeladonCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_Gym_OnTransition
	.byte 0

CeladonCity_Gym_OnTransition::
	call_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_ResetRematchFlags
	end

CeladonCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_ERIKA_ORIGINAL
	cleartrainerflag LEADER_REMATCH_ERIKA_POSTGAME
	return

CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_ERIKA_REWARD, CeladonCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_ERIKA_REMATCH, CeladonCity_Gym_EventScript_RematchLeader
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_EventScript_ChallengeLeader::
	msgbox CeladonCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_LeaderIntro, CeladonCity_Gym_Text_LeaderDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

CeladonCity_Gym_Text_LeaderSpeech::
    .string "Hello…\n"
    .string "Lovely weather, isn't it?\l"
    .string "It's so pleasant…\p"
    .string "…Oh, dear…\n"
    .string "I must have dozed off. Welcome.\p"
    .string "My name is Erika.\n"
    .string "I am the Leader of Celadon Gym.\p"
    .string "I am a student of the art of\n"
    .string "flower arranging.\p"
    .string "My Pokémon are solely of the\n"
    .string "Grass type.$"


CeladonCity_Gym_Text_LeaderIntro::
    .string "…Oh, I'm sorry, I had no idea that\n"
    .string "you wished to challenge me.\p"
    .string "Very well, but I shall not lose.$"

CeladonCity_Gym_Text_LeaderDefeat::
    .string "Oh!\n"
    .string "I concede defeat.$"

CeladonCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox CeladonCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message CeladonCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox CeladonCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DAILY_ERIKA_REMATCH
	settrainerflag TRAINER_LASS_KAY						
	settrainerflag TRAINER_LASS_LISA						
	settrainerflag TRAINER_PICNICKER_TINA					
	settrainerflag TRAINER_BEAUTY_BRIDGET	
	settrainerflag TRAINER_BEAUTY_TAMIA					
	settrainerflag TRAINER_BEAUTY_LORI		
	settrainerflag TRAINER_COOLTRAINER_MARY
	call_if_set FLAG_RECEIVED_AIDE_EVERSTONE, CeladonCity_Gym_EventScript_NextAideCall
	goto CeladonCity_Gym_EventScript_GetTM
	end

CeladonCity_Gym_EventScript_NextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_3
	return

CeladonCity_Gym_Text_GetBadge::
    .string "You are remarkably strong.\p"
    .string "I must confer on you the\n"
    .string "Rainbow Badge.$"

CeladonCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Rainbow\n"
    .string "Badge from Erika!$"

CeladonCity_Gym_Text_ExplainBadge::
    .string "The Rainbow Badge will make\n"
    .string "Pokémon up to Lv. 50 obey.\p"
    .string "It also allows Pokémon to use\n"
    .string "Strength in and out of battle.$"

CeladonCity_Gym_EventScript_GetTM::
	msgbox CeladonCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM19, 1
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeladonCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM19, 1
	setflag FLAG_GOT_ERIKA_REWARD
	msgbox CeladonCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_TakeThisWithYou::
    .string "Please also take this with you.$"

CeladonCity_Gym_Text_ReceivedTM::
	.string "{PLAYER} received TM19\n"
    .string "from Erika.$"

CeladonCity_Gym_Text_ExplainTM::
    .string "TM19 contains Giga Drain.\p"
    .string "Half the damage it inflicts is\n"
    .string "drained to heal your Pokémon.\p"
    .string "Wouldn't you agree that it's a\n"
    .string "wonderful move?$"

CeladonCity_Gym_EventScript_NoRoomForTM::
	msgbox CeladonCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_NoRoomForTM::
    .string "You should make room for this.$"

CeladonCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox CeladonCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_LeaderPostBattle::
    .string "You are cataloging Pokémon?\n"
    .string "I must say I'm impressed.\p"
    .string "I would never collect Pokémon if\n"
    .string "they were unattractive.$"

CeladonCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox CeladonCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_PostBattleGameClear::
	.string "Lovely weather, isn't it?\p" 
	.string "It's so pleasant...\p" 
	.string "I'm afraid I might doze off...$"

CeladonCity_Gym_EventScript_RematchLeader::
	msgbox CeladonCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, CeladonCity_Gym_EventScript_PostgameRematch
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchLeader::
	.string "Oh, if it isn't the one who's \n"
	.string "been trying to fill the Pokédex.\p" 
	.string "I do hope things have been going well\n"
	.string "for you since our last encounter.\p"
	.string "...I see. You certainly have been busy.\p" 
	.string "I'm not particularly fond of those kinds\n"
	.string "of public things...\p" 
	.string "However, battles are different.\n" 
	.string "That's what you came for, isn't it?$"

CeladonCity_Gym_EventScript_DeclineRematch::
	msgbox CeladonCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

CeladonCity_Gym_Text_DeclineRematch::
	.string "Oh well...perhapse another time.$"

CeladonCity_Gym_EventScript_PostgameRematch::
	msgbox CeladonCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

CeladonCity_Gym_Text_RematchMode::
	.string "Now that you're the champion,\n"
	.string "would you like to go all out?$"

CeladonCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_ERIKA_ORIGINAL, CeladonCity_Gym_Text_RematchOriginal, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchOriginal::
	.string "Lovely, {PLAYER}!\n"
	.string "Let's cherish this memory!$"

CeladonCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_ERIKA_POSTGAME, CeladonCity_Gym_Text_RematchPostgame, CeladonCity_Gym_Text_RematchDefeat, CeladonCity_Gym_EventScript_DefeatedLeaderRematch
	end

CeladonCity_Gym_Text_RematchPostgame::
	.string "Very well, {PLAYER}!\n"
	.string "Prepare for an all out battle!$"

CeladonCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_ERIKA_REMATCH
	goto CeladonCity_Gym_EventScript_LeaderPostBattle
	end

CeladonCity_Gym_Text_RematchDefeat::
	.string "Simply marvelous.\p" 
	.string "That was an effort worthy at\n" 
	.string "least 10 Rainbow Badges.$"

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_KayIntro::
    .string "I should tell you about this Gym.\p"
    .string "Only real ladies are allowed in\n"
    .string "here!$"

CeladonCity_Gym_Text_KayDefeat::
    .string "You're too rough!$"

CeladonCity_Gym_Text_KayPostBattle::
    .string "Bleaah!\n"
    .string "I hope Erika wipes you out!$"

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LisaIntro::
    .string "Oh, hey!\p"
    .string "We don't like Bug or Fire type\n"
    .string "Pokémon in here!$"

CeladonCity_Gym_Text_LisaDefeat::
    .string "Oh!\n"
    .string "You!$"

CeladonCity_Gym_Text_LisaPostBattle::
    .string "Our Leader Erika might be quiet,\n"
    .string "but she's famous around here.$"

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TinaIntro::
    .string "…Weren't you peeking in here\n"
    .string "earlier?$"

CeladonCity_Gym_Text_TinaDefeat::
    .string "You're an eye-opener!$"

CeladonCity_Gym_Text_TinaPostBattle::
    .string "Oh, you were looking at Erika…\n"
    .string "You weren't looking at me…$"

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BridgetIntro::
    .string "Oh, welcome.\n"
    .string "I was getting bored.$"

CeladonCity_Gym_Text_BridgetDefeat::
    .string "My makeup!$"

CeladonCity_Gym_Text_BridgetPostBattle::
    .string "Grass-type Pokémon are tough\n"
    .string "against the Water type.\p"
    .string "They also have an edge on Rock\n"
    .string "and Ground type Pokémon.$"

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TamiaIntro::
    .string "Look, look!\n"
    .string "See my Pokémon!\p"
    .string "I like the Grass type.\n"
    .string "I like how they're easy to raise.$"

CeladonCity_Gym_Text_TamiaDefeat::
    .string "No!$"

CeladonCity_Gym_Text_TamiaPostBattle::
    .string "We only use Grass-type Pokémon at\n"
    .string "our Gym.\p"
    .string "Why? We also use them for making\n"
    .string "flower arrangements!$"

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LoriIntro::
    .string "Pleased to meet you.\n"
    .string "My hobby is Pokémon training.$"

CeladonCity_Gym_Text_LoriDefeat::
    .string "Oh!\n"
    .string "Splendid!$"

CeladonCity_Gym_Text_LoriPostBattle::
    .string "I have a blind date coming up.\n"
    .string "I have to learn to be polite,\l"
    .string "especially if I have to battle.$"

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_MaryIntro::
    .string "Welcome to Celadon Gym!\p"
    .string "You'd better not underestimate\n"
    .string "the nice ladies here.$"

CeladonCity_Gym_Text_MaryDefeat::
    .string "Oh!\n"
    .string "Beaten!$"

CeladonCity_Gym_Text_MaryPostBattle::
    .string "I didn't bring my best Pokémon.\n"
    .string "Wait until next time!$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "Celadon POKémon Gym\n"
    .string "Leader: Erika\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "Celadon POKémon Gym\n"
    .string "Leader: Erika\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
