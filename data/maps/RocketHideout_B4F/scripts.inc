.set LOCALID_GIOVANNI,  1
.set LOCALID_CUBONE, 	2
.set LOCALID_JAMES,		3
.set LOCALID_ROCKET2,	4
.set LOCALID_ROCKET3,  	5
.set LOCALID_JESSIE,	6
.set LOCALID_LIFT_KEY,  7

.set NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_OnLoad::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_ne RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_EventScript_CountGruntDefeated::
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return

RocketHideout_B4F_EventScript_Giovanni::
	lock
	faceplayer
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	delay 10
	closemessage
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_HIDE_HIDEOUT_CUBONE
	addobject LOCALID_CUBONE
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	msgbox RocketHideout_B4F_Text_MeetAgain
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_GIOVANNI
	setflag FLAG_HIDE_CELADON_ROCKETS
	setflag FLAG_RESCUED_CUBONE
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	removeobject LOCALID_ROCKET2
	removeobject LOCALID_ROCKET3
	fadescreen FADE_FROM_BLACK
	goto RocketHideout_B4F_EventScript_Cubone
	end

RocketHideout_B4F_Text_GiovanniIntro::
    .string "???: So! I must say, I am impressed\n"
    .string "you got here.\p"
    .string "Team Rocket captures Pokémon from\n"
    .string "around the world.\p"
    .string "They're important tools for keeping\n"
    .string "our criminal enterprise going.\p"
    .string "I am the leader, Giovanni!\p"
    .string "For your insolence, you will feel a\n"
    .string "world of pain!$"

RocketHideout_B4F_Text_GiovanniDefeat::
    .string "What!\n"
    .string "This can't be!$"

RocketHideout_B4F_Text_GiovanniPostBattle::
    .string "Giovanni: I see that you raise\n"
    .string "Pokémon with utmost care.\p"
    .string "A child like you would never\n"
    .string "understand what I hope to achieve.\p"
    .string "I shall step aside this time, and\n"
    .string "release this Cubone back to you.$"

RocketHideout_B4F_Text_MeetAgain::
    .string "I hope we meet again…$"

RocketHideout_B4F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_Text_Grunt1Intro::
    .string "The elevator doesn't work?\n"
    .string "Who has the Lift Key?$"

RocketHideout_B4F_Text_Grunt1Defeat::
    .string "No!$"

RocketHideout_B4F_EventScript_DefeatedGrunt1::
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_Text_Grunt1PostBattle::
    .string "Oh, no!\n"
    .string "I dropped the Lift Key!$"

RocketHideout_B4F_EventScript_LiftKey::
	lock
	faceplayer
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	goto_if_eq  VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt2Intro::
    .string "I know you!\n"
    .string "You ruined our plans at Mt. Moon!$"

RocketHideout_B4F_Text_Grunt2Defeat::
    .string "Burned again!$"

RocketHideout_B4F_Text_Grunt2PostBattle::
    .string "Do you have something against Team\n"
    .string "Rocket?$"

RocketHideout_B4F_EventScript_DefeatedGrunt2::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3::
	lock
	faceplayer
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_Grunt3Intro::
    .string "How can you not see the beauty of\n"
    .string "our evil?$"

RocketHideout_B4F_Text_Grunt3Defeat::
    .string "Boss!\n"
    .string "I'm sorry I failed you!$"

RocketHideout_B4F_Text_Grunt3PostBattle::
    .string "You may have beaten me, but\n"
    .string "more of us are coming!$"

RocketHideout_B4F_EventScript_DefeatedGrunt3::
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Jessie::
	trainerbattle_single TRAINER_ROCKET_HIDEOUT_JESSIE, RocketHideout_B4F_Text_JessieIntro, RocketHideout_B4F_Text_JessieDefeat
	msgbox RocketHideout_B4F_Text_JessiePostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_JessieIntro::
	.string "Jessie: You're that twerp that\n"
	.string "keeps interrupting our schemes!$"

RocketHideout_B4F_Text_JessieDefeat::
	.string "Jessie: No! No! No!$"

RocketHideout_B4F_Text_JessiePostBattle::
	.string "Jessie: You may have defeated\n"
	.string "me again, but the Boss will\l"
	.string "finally get rid of you for good.$"

RocketHideout_B4F_EventScript_James::
	trainerbattle_single TRAINER_ROCKET_HIDEOUT_JAMES, RocketHideout_B4F_Text_JamesIntro, RocketHideout_B4F_Text_JamesDefeat
	msgbox RocketHideout_B4F_Text_JamesPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_Text_JamesIntro::
	.string "James: You're starting to take\n"
	.string "the fun out of all of this.$"

RocketHideout_B4F_Text_JamesDefeat::
	.string "James: This is really starting\n"
	.string "to get to me!$"

RocketHideout_B4F_Text_JamesPostBattle::
	.string "James: For what it's worth, I\n"
	.string "am sorry about what happened to\l"
	.string "that Cubone's mother...$"

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval::
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

RocketHideout_B4F_EventScript_SetBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier::
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return


RocketHideout_B4F_EventScript_ItemTM49::
	finditem ITEM_TM49, 1
	release
	end

RocketHideout_B4F_EventScript_ItemMaxEther::
	finditem ITEM_MAX_ETHER, 1
	release
	end

RocketHideout_B4F_EventScript_ItemCalcium::
	finditem ITEM_CALCIUM, 1
	release
	end

RocketHideout_B4F_EventScript_Cubone::
	delay 30
	playse SE_PIN
	applymovement LOCALID_CUBONE, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_CUBONE, Movement_CuboneExit
	waitmovement 2
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	waitmoncry
	removeobject LOCALID_CUBONE
	release
	end

Movement_CuboneExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end
