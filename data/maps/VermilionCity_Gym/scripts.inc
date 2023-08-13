.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	call_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_ResetRematchFlags
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, Common_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_ResetRematchFlags::
	cleartrainerflag LEADER_REMATCH_SURGE_ORIGINAL
	cleartrainerflag LEADER_REMATCH_SURGE_POSTGAME
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	compare SWITCH1_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	compare SWITCH2_ID, TRASH_CAN_ID
	goto_if_eq VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "Nope!\n"
    .string "There's only trash here.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Hey! There's a switch under the\n"
    .string "trash! Turn it on!\p"
    .string "The first electric lock opened!$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "The second electric lock opened!\n"
    .string "The motorized door opened!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "Nope!\n"
    .string "There's only trash here.\p"
    .string "Hey!\n"
    .string "The electric locks were reset!$"


VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_ChallengeLeader
	goto_if_unset FLAG_GOT_SURGE_REWARD, VermilionCity_Gym_EventScript_GetTM
	goto_if_unset FLAG_DAILY_SURGE_REMATCH, VermilionCity_Gym_EventScript_RematchLeader
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_EventScript_ChallengeLeader::
	msgbox VermilionCity_Gym_Text_LeaderSpeech, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LEADER_SURGE, VermilionCity_Gym_Text_LeaderIntro, VermilionCity_Gym_Text_LeaderDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge
	end

VermilionCity_Gym_Text_LeaderSpeech::
    .string "Hey, kid! What do you think you're\n"
    .string "doing here?\p"
    .string "You won't live long in combat!\n"
    .string "Not with your puny power!\p"
    .string "I tell you, kid, electric Pokémon\n"
    .string "saved me during the war!$"

VermilionCity_Gym_Text_LeaderIntro::
 	.string "They zapped my enemies into\n"
    .string "paralysis!\p"
    .string "The same as I'll do to you!$"

VermilionCity_Gym_Text_LeaderDefeat::
    .string "Now that's a shocker!\p"
    .string "You're the real deal, kid!$"

VermilionCity_Gym_EventScript_DefeatedLeaderGetBadge::
	msgbox VermilionCity_Gym_Text_GetBadge, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	message VermilionCity_Gym_Text_ReceivedBadge
	waitfanfare
	waitmessage
	msgbox VermilionCity_Gym_Text_ExplainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DAILY_SURGE_REMATCH
	settrainerflag TRAINER_SAILOR_DWAYNE
	settrainerflag TRAINER_ENGINEER_BAILY
	settrainerflag TRAINER_GENTLEMAN_TUCKER
	call_if_set FLAG_RECEIVED_HM05, VermilionCity_Gym_EventScript_QueueNextAideCall
	goto VermilionCity_Gym_EventScript_GetTM
	end

VermilionCity_Gym_EventScript_QueueNextAideCall::
	setflag FLAG_QUEUE_AIDE_CALL
	setflag FLAG_AIDE_LOCATION_2
	return

VermilionCity_Gym_Text_GetBadge::
    .string "Fine, then, take the Thunder Badge!$"

VermilionCity_Gym_Text_ReceivedBadge::
	.string "{PLAYER} received the Thunder\n"
    .string "Badge from Lt. Surge!$"

VermilionCity_Gym_Text_ExplainBadge::
    .string "The Thunder Badge certifies your\n"
    .string "Pokémon to use Fly out of battle.\p"
    .string "If they know the move, they can get\n" 
    .string "around lightning-quick anytime!\p"
    .string "You're special, kid!$"

VermilionCity_Gym_EventScript_GetTM::
	msgbox VermilionCity_Gym_Text_TakeThisWithYou, MSGBOX_DEFAULT
	checkitemspace ITEM_TM34, 1
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM
	playfanfare MUS_OBTAIN_TMHM
	msgbox VermilionCity_Gym_Text_ReceivedTM, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_TM34, 1
	setflag FLAG_GOT_SURGE_REWARD
	msgbox VermilionCity_Gym_Text_ExplainTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_TakeThisWithYou::
    .string "Take this!$"

VermilionCity_Gym_Text_ReceivedTM::
    .string "{PLAYER} received TM34\n"
    .string "from Lt. Surge.$"

VermilionCity_Gym_Text_ExplainTM::
    .string "TM34 contains Shock Wave!\p"
    .string "Teach it to an Electric Pokémon!$"

VermilionCity_Gym_EventScript_NoRoomForTM::
	msgbox VermilionCity_Gym_Text_NoRoomForTM, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_NoRoomForTM::
    .string "Yo, kid, make room in your bag!$"

VermilionCity_Gym_EventScript_LeaderPostBattle::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_LeaderPostBattleGameClear
	msgbox VermilionCity_Gym_Text_LeaderPostBattle, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_LeaderPostBattle::
    .string "A little word of advice, kid!\p"
    .string "Electricity is sure powerful!\p"
    .string "But, it's useless against Ground-\n"
    .string "type Pokémon!$"

VermilionCity_Gym_EventScript_LeaderPostBattleGameClear::
	msgbox VermilionCity_Gym_Text_PostBattleGameClear, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_PostBattleGameClear::
	.string "Looks like there's still a gap\n"
	.string "between our skill levels I need\l"
	.string "to close, kid!\p" 
	.string "This is the first time I've felt\n"
	.string "like this since I first became\l"
	.string "Vermilion's Gym Leader.$"

VermilionCity_Gym_EventScript_RematchLeader::
	msgbox VermilionCity_Gym_Text_RematchLeader, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_DeclineRematch
	goto_if_set FLAG_SYS_GAME_CLEAR, VermilionCity_Gym_EventScript_PostgameRematch
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchLeader::
	.string "Hey there, kid! Pretty shocking you made\n"
	.string "it this far in your journey!\p"
	.string "No doubt some Electric-type Pokémon had\n"
	.string "a pretty big hand in that, right?\p"
	.string "All right, then. How about a rematch to\n"
	.string "show me what kind of Pokémon you've raised?$"

VermilionCity_Gym_EventScript_DeclineRematch::
	msgbox VermilionCity_Gym_Text_DeclineRematch, MSGBOX_DEFAULT
	release
	end

VermilionCity_Gym_Text_DeclineRematch::
	.string "Huh. Coward!$"

VermilionCity_Gym_EventScript_PostgameRematch::
	msgbox VermilionCity_Gym_Text_RematchMode, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam
	goto VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam
	end

VermilionCity_Gym_Text_RematchMode::
	.string "Now that you're the champion,\n"
	.string "would you like to go all out?$"

VermilionCity_Gym_EventScript_LeaderRematch_OriginalTeam::
	trainerbattle_single LEADER_REMATCH_SURGE_ORIGINAL, VermilionCity_Gym_Text_RematchOriginal, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchOriginal::
	.string "Ten-hut!\n" 
	.string "Remember, a Pokémon battle is a war!\p" 
	.string "Let's go, kid!$"

VermilionCity_Gym_EventScript_LeaderRematch_PostGameTeam::
	trainerbattle_single LEADER_REMATCH_SURGE_POSTGAME, VermilionCity_Gym_Text_RematchPostgame, VermilionCity_Gym_Text_RematchDefeat, VermilionCity_Gym_EventScript_DefeatedLeaderRematch
	end

VermilionCity_Gym_Text_RematchPostgame::
	.string "No need for introductions this time!\n" 
	.string "Trainers like us have no need for words!\p" 
	.string "Let's go, kid!$"

VermilionCity_Gym_EventScript_DefeatedLeaderRematch::
	setflag FLAG_DAILY_SURGE_REMATCH
	goto VermilionCity_Gym_EventScript_LeaderPostBattle
	end

VermilionCity_Gym_Text_RematchDefeat::
	.string "Absolutely shocking!$"

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_DwayneIntro::
    .string "This is no place for kids!\n"
    .string "Not even if you're good!$"

VermilionCity_Gym_Text_DwayneDefeat::
    .string "Wow!\n"
    .string "Surprised me!$"

VermilionCity_Gym_Text_DwaynePostBattle::
    .string "Lt. Surge installed the traps in\n"
    .string "the gym himself.\p"
    .string "He set up double locks everywhere.\n"
    .string "Let me give you a hint.\p"
    .string "When you open the first lock, the\n"
    .string "second lock is right next to it.$"

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_BailyIntro::
    .string "I'm a lightweight, but I'm good\n"
    .string "with electricity!\p"
    .string "That's why I joined this gym.$"

VermilionCity_Gym_Text_BailyDefeat::
    .string "Fried!$"

VermilionCity_Gym_Text_BailyPostBattle::
    .string "Okay, I'll talk!\p"
    .string "Lt. Surge said he hid door\n"
    .string "switches inside something.$"

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_Text_TuckerIntro::
    .string "When I was in the Army, LT. Surge\n"
    .string "was my strict CO.\p"
    .string "He was a hard taskmaster.$"

VermilionCity_Gym_Text_TuckerDefeat::
    .string "Stop!\n"
    .string "You're very good!$"

VermilionCity_Gym_Text_TuckerPostBattle::
    .string "It's not easy opening that door.\p"
    .string "Lt. Surge was always famous for\n"
    .string "his cautious nature in the Army.$"


VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Yo!\n"
    .string "Champ in the making!\p"
    .string "Lt. Surge has a nickname.\p"
    .string "People refer to him as the\n"
    .string "Lightning Lieutenant!\p"
    .string "He's an expert on electric Pokémon.\p"
    .string "Bird and Water-type Pokémon better\n"
    .string "watch out against Electric attacks!\p"
    .string "Beware of paralysis, too.\p"
    .string "Lt. Surge is very cautious.\p"
    .string "He's locked himself in, so it won't\n"
    .string "be easy getting to him.$"

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_Text_GymGuyPostVictory::
    .string "Whew!\n"
    .string "That match was electric!$"

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_Text_GymStatue::
    .string "Vermilion Pokémon Gym\n"
    .string "Leader: Lt. Surge\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}$"

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "Vermilion Pokémon Gym\n"
    .string "Leader: Lt. Surge\p"
    .string "Winning Trainers:\n"
    .string "{RIVAL}, {PLAYER}$"
