.set LOCALID_GIOVANNI, 1
.set LOCALID_GRUNT1,   4
.set LOCALID_GRUNT2,   5
.set LOCALID_JESSIE,   6
.set LOCALID_JAMES,    7
.set LOCALID_ROCKET_LEADER, 9
.set LOCALID_LOOKER, 10

SilphCo_11F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_ItemZinc::
	finditem ITEM_ZINC, 1
	release
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_PresidentPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_PresidentHostage
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	msgbox SilphCo_11F_Text_ThanksForSavingMe
	checkitemspace ITEM_MASTER_BALL, 1
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentPostgame::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_PresidentPostgamePostBattle
	msgbox SilphCo_11F_Text_PracticeBattling, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_11F_EventScript_DeclinePrezBattle
	trainerbattle_no_intro TRAINER_SILPH_PREZ, SilphCo_11F_Text_PrezDefeat
	msgbox SilphCo_11F_Text_WhatAGreatBattle, MSGBOX_NPC
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message SilphCo_11F_Text_ObtainedMasterBallFromPresident
	additem ITEM_MASTER_BALL, 1
	waitfanfare
	setflag FLAG_DAILY_PREZ_BATTLE
	release
	end

SilphCo_11F_Text_WhatAGreatBattle::
	.string "President: I see I still have\n"
	.string "room to improve!\p"
	.string "But you won't have to worry about\n"
	.string "rescuing me anymore!\p"
	.string "Please, take this as a reward.$"

SilphCo_11F_Text_PrezDefeat::
	.string "It seems even a President is no\n"
	.string "match for a Champion!$"	

SilphCo_11F_Text_PracticeBattling::
	.string "President: Ah, hello {PLAYER}!\p"
	.string "Come to check up on me?\p"
	.string "Hoho..well, don't worry. There's\n"
	.string "been no sign of Team Rocket here.\p"
	.string "One can never be too careful though,\n"
	.string "so I've started to train my own\l"
	.string "Pokémon for protection!\p"
	.string "Say...since you came all this way,\n"
	.string "how about a battle?$"

SilphCo_11F_EventScript_DeclinePrezBattle::
	msgbox SilphCo_11F_Text_IUnderstand, MSGBOX_NPC
	release
	end

SilphCo_11F_Text_IUnderstand::
	.string "I understand. Things must be busy\n"
	.string "for a Champion.$"

SilphCo_11F_EventScript_PresidentPostgamePostBattle::
	msgbox SilphCo_11F_Text_TheseRocketsPunks, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRocketsPunks::
	.string "President: Silph Co. is trying\n"
	.string "to make the world a better place\l"
	.string "for both people and Pokémon.\p"
	.string "But punks like Team Rocket will\n"
	.string "never understand.$"

SilphCo_11F_EventScript_PresidentHostage::
	msgbox SilphCo_11F_Text_TheseRockets, MSGBOX_NPC
	end

SilphCo_11F_Text_TheseRockets::
	.string "President: I've had enough of\n" 
	.string "these Rockets!$"

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	goto_if_set FLAG_DAILY_PREZ_BATTLE, SilphCo_11F_EventScript_SecretaryPostbattle
	goto_if_set FLAG_LOOKER_POSTGAME_COMPLETED, SilphCo_11F_EventScript_SecretaryPostgame
	goto_if_set	FLAG_LOOKER_POSTGAME_STARTED, SilphCo_11F_EventScript_HappeningAgain
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostbattle::
	msgbox SilphCo_11F_Text_PrezTeam, MSGBOX_NPC
	end

SilphCo_11F_Text_PrezTeam::
	.string "After seeing you battle Team Rocket\n"
	.string "twice, the President has become\l"
	.string "obsessed with Pokémon battles.\p"
	.string "He spends all his time researching\n"
	.string "new moves...\p"
	.string "Which means I have to answer all his\n"
	.string "emails!$"

SilphCo_11F_EventScript_HappeningAgain::
	msgbox SilphCo_11F_Text_HappeningAgain, MSGBOX_NPC
	end

SilphCo_11F_EventScript_SecretaryPostgame::
	msgbox SilphCo_11F_Text_NotWhatIExpected, MSGBOX_NPC
	end

SilphCo_11F_Text_NotWhatIExpected::
	.string "This job is not what I expected.\n"
	.string "I'm a secretary, not a bodyguard.\p"
	.string "I'm thinking about asking for\n"
	.string "a raise!$"

SilphCo_11F_Text_HappeningAgain::
	.string "Aiiieee!! I can't believe it's\n"
	.string "happening again! Help us!$"

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	applymovement LOCALID_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 1
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq  VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_GRUNT1
	removeobject LOCALID_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_SILPH_STATE, 3
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_ROCKET_BURGLARS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 1
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 1
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_fast_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_fast_right
	step_end


SilphCo_11F_EventScript_JessieJames::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_JESSIE, Movement_JessieJamesApproachPlayer
	applymovement LOCALID_JAMES, Movement_JessieJamesApproachPlayer
	waitmovement 6
	msgbox SilphCo_11F_Text_StopYouOnceAndForAll
	trainerbattle_no_intro TRAINER_SILPH_CO_JESSIE_JAMES, SilphCo_11F_Text_JessieJamesDefeat
	msgbox SilphCo_11F_Text_JessieJamesPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	delay 10
	setvar VAR_SILPH_STATE, 2
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SilphCo_11F_Text_StopYouOnceAndForAll::
	.string "James: Well, look who it is.\n"
	.string "Jessie: The twerp is right on time.\p"
	.string "Jessie: We knew you'd be coming.\n"
	.string "James: But this is as far as you go.\l"
	.string "Jessie: Our Boss is in a meeting.\n"
	.string "James: So you'll deal with us!$"

SilphCo_11F_Text_JessieJamesDefeat::
	.string "Jessie: Argh! I hate kids!\p"
	.string "James: Same as always...$"

SilphCo_11F_Text_JessieJamesPostBattle::
	.string "Jessie: We've failed the boss.\n"
	.string "James: This was our last chance!\p"
	.string "Jessie & James: Looks like we'll\n"
	.string "be blasting off again!$"

Movement_JessieJamesApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMe::
    .string "President: Oh, dear child!\n"
    .string "Thank you for saving Silph.\p"
    .string "I will never forget you saved us in\n"
    .string "our moment of peril.\p"
    .string "I have to thank you in some way.\p"
    .string "Because I am rich, I can give you\n"
    .string "anything.\p"
    .string "Here, maybe this will do.$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
    .string "{PLAYER} obtained a Master Ball\n"
    .string "from the President!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
    .string "President: You can't buy that\n"
    .string "anywhere.\p"
    .string "It's our secret prototype Master\n"
    .string "Ball.\p"
    .string "It will catch any Pokémon without\n"
    .string "fail!\p"
    .string "You should be quiet about using it,\n"
    .string "though.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
    .string "You have no room for this.$"

SilphCo_11F_Text_ThanksForRescuingUs::
    .string "Secretary: Thank you for rescuing\n"
    .string "all of us.\p"
    .string "We, from the President down,\n"
    .string "are indebted to you.$"

SilphCo_11F_Text_GiovanniIntro::
    .string "Ah, {PLAYER}!\n"
    .string "So we meet again!\p"
    .string "The President and I are discussing\n"
    .string "a vital business proposition.\p"
    .string "Keep your nose out of grown-up\n"
    .string "matters…\p"
    .string "Or, experience a world of pain!$"

SilphCo_11F_Text_GiovanniDefeat::
    .string "Arrgh!!\n"
    .string "I lost again!?$"

SilphCo_11F_Text_GiovanniPostBattle::
    .string "Blast it all!\n"
    .string "You ruined our plans for Silph!\p"
    .string "But, Team Rocket will never fall!\p"
    .string "{PLAYER}! Never forget that all\n"
    .string "Pokémon exist for Team Rocket!\p"
    .string "I must go, but I shall return!$"

SilphCo_11F_Text_Grunt2Intro::
    .string "Stop right there!\n"
    .string "Don't you move!$"

SilphCo_11F_Text_Grunt2Defeat::
    .string "Don't…\n"
    .string "Please!$"

SilphCo_11F_Text_Grunt2PostBattle::
    .string "So, you want to see my Boss?$"

SilphCo_11F_Text_Grunt1Intro::
    .string "Halt! Do you have an appointment\n"
    .string "with my Boss?$"

SilphCo_11F_Text_Grunt1Defeat::
    .string "Gaah!\n"
    .string "Demolished!$"

SilphCo_11F_Text_Grunt1PostBattle::
    .string "Watch your step…\n"
    .string "My Boss likes his Pokémon tough!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
    .string "The monitor has Pokémon on it!$"

SilphCo_11F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "11F$"


@Postgame
SilphCo_11F_EventScript_PostgameRocket::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_GiovanniWasWeak, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_POSTGAME_ROCKET_LEADER, SilphCo_11F_Text_RocketLeaderDefeat
	playse SE_PIN
	applymovement LOCALID_ROCKET_LEADER, Common_Movement_ExclamationMark
	waitse
	msgbox SilphCo_11F_Text_HowCouldThisHappen, MSGBOX_NPC
	clearflag FLAG_HIDE_SILPH_POSTGAME_LOOKER
	addobject LOCALID_LOOKER
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement1
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement2
	msgbox SilphCo_11F_Text_ThatsEnoughFromYou, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_RocketWellNeverStop, MSGBOX_NPC
	waitmessage
	closemessage
	msgbox SilphCo_11F_Text_TakingYouIn, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_EAST, SilphCo_11F_EventScript_LookerMovement3
	call_if_eq VAR_FACING, DIR_WEST, SilphCo_11F_EventScript_LookerMovement4
	waitmovement 10
	setflag	FLAG_HIDE_SILPH_POSTGAME_ROCKET
	setflag	FLAG_HIDE_SILPH_POSTGAME_LOOKER
	setflag FLAG_LOOKER_POSTGAME_COMPLETED
	clearflag FLAG_HIDE_LOOKER_CELADON
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET_LEADER
	fadedefaultbgm
	release
	end

SilphCo_11F_Text_ThatsEnoughFromYou::
	.string "Looker: That's enough!\p"
	.string "We've heard it all before.\p"
	.string "That's the problem with you\n"
	.string "Rockets. It's all about one\l"
	.string "thing...power!\p"
	.string "That's why you'll always lose\n"
	.string "to someone like {PLAYER}.\p"
	.string "They know what it truly means\n"
	.string "to live alongside Pokémon.\p"
	.string "...\p"
	.string "You called Giovanni weak, but I\n"
	.string "think even he knew that at the end.$"

SilphCo_11F_Text_RocketWellNeverStop::
	.string "Rocket: ...\p"
	.string "Maybe so...\p"
	.string "But we'll never stop!\p"
	.string "Team Rocket will rise again!$"

SilphCo_11F_Text_TakingYouIn::
	.string "Looker: We'll see about that.\p"
	.string "{PLAYER}! I'm taking this Rocket in.\p"
	.string "Thanks for all your help here.\n"
	.string "You should come see me the next\n"
	.string "time you're in Celadon City.$"

SilphCo_11F_EventScript_LookerMovement1::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach1
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_EAST
	return

SilphCo_11F_EventScript_LookerMovement2::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Approach2
	waitmovement 10
	turnobject LOCALID_ROCKET_LEADER, DIR_WEST
	return

SilphCo_11F_LookerMovement_Approach1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

SilphCo_11F_LookerMovement_Approach2::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

SilphCo_11F_EventScript_LookerMovement3::
	applymovement LOCALID_LOOKER, SilphCo_11F_LookerMovement_Exit1
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit1
	return

SilphCo_11F_RocketMovement_Exit1::
	walk_right
SilphCo_11F_LookerMovement_Exit1::
	walk_right	
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SilphCo_11F_RocketMovement_Exit2::
	walk_left
SilphCo_11F_LookerMovement_Exit2::
	walk_left	
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_EventScript_LookerMovement4::
	applymovement LOCALID_LOOKER, SilphCo_11F_RocketMovement_Exit2
	applymovement LOCALID_ROCKET_LEADER, SilphCo_11F_RocketMovement_Exit2
	return


SilphCo_11F_Text_GiovanniWasWeak::
	.string "Rocket: Ha! You actually\n"
	.string "showed up?\p"
	.string "What? The big bad champion\n"
	.string "of Kanto thinks he's going to\l"
	.string "take me down?\p"
	.string "Well, listen up, kid.\p"
	.string "Giovanni was weak!\p"
	.string "He let some chump like you\n"
	.string "push him around!\p"
	.string "Under my leadership, Team\n"
	.string "Rocket won't roll over just\l"
	.string "because some kid stands in our\l"
	.string "way!\p"
	.string "Say hello to the new Team Rocket!$"

SilphCo_11F_Text_RocketLeaderDefeat::
	.string "What?! Am I weaker than Giovanni?\p"

SilphCo_11F_Text_HowCouldThisHappen::
	.string "I can't believe it...\p"
	.string "This was supposed to be our big\n"
	.string "comeback!\p"
	.string "We thought Giovanni was weak...\n"
	.string "but you're just too good!$"



