.set LOCALID_CALE, 1
.set LOCALID_ALI, 2
.set LOCALID_TIMMY, 3
.set LOCALID_RELI, 4
.set LOCALID_ETHAN, 5
.set LOCALID_DISGUISED_ROCKET, 8
.set LOCALID_JESSIE, 9
.set LOCALID_JAMES, 10
.set LOCALID_ROCKET, 11
.set LOCALID_LOOKER, 12
.set LOCALID_CHARMANDER, 13


Route24_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route24_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route24_OnResume
	.byte 0

Route24_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route24_OnResume:
	call Common_EventScript_GetDayOrNight
	end

@Charmander
Route24_EventScript_Charmander::
	call Route24_EventScript_CharmanderEmote
	playmoncry SPECIES_CHARMANDER, CRY_MODE_NORMAL
	msgbox Route24_Text_Charmander, MSGBOX_NPC
	waitmoncry
	release
	end

Route24_Text_Charmander:
	.string "Charmander: Char!$"

Route24_EventScript_CharmanderEmote::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CHARMANDER, Common_Movement_ExclamationMark
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Route24_EventScript_CharmanderGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_CHARMANDER, Route24_EventScript_HowsCharmander
	msgbox Route24_Text_NotCutOutToBeATrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_BetterReleaseIt
	setvar VAR_TEMP_1, SPECIES_CHARMANDER
	givemon SPECIES_CHARMANDER, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, Route24_EventScript_CharmanderParty
	goto_if_eq VAR_RESULT, 1, Route24_EventScript_CharmanderPC
	goto_if_eq VAR_RESULT, 2, Route24_EventScript_NoRoomForCharmander
	end

Route24_EventScript_HowsCharmander::
	msgbox Route24_Text_HowsCharmander, MSGBOX_NPC
	release
	end

Route24_Text_HowsCharmander::
	.string "How's Charmander doing?$"

Route24_Text_NotCutOutToBeATrainer::
	.string "I'm not good at raising Pokémon.\p" 
	.string "I should release my Charmander\n"
	.string "because I haven't raised it well...\p" 
	.string "If you promise me you'll take\n"
	.string "good care of it, it's yours.$"

Route24_EventScript_BetterReleaseIt::
	msgbox Route24_Text_BetterReleaseIt, MSGBOX_NPC
	release
	end

Route24_Text_BetterReleaseIt::
	.string "Oh...I better release it then...$"


Route24_EventScript_CharmanderParty::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_GotCharmander
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_GetCharmander::
	playfanfare MUS_LEVEL_UP
	message Route24_EventScript_Text_TakeCareOfCharmander
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	return

Route24_EventScript_Text_TakeCareOfCharmander::
	.string "{PLAYER} promised to take good care\n"
	.string "of the trainer's Charmander!$"

Route24_EventScript_GotCharmander::
	setflag FLAG_GOT_CHARMANDER
	removeobject LOCALID_CHARMANDER
	release
	end

Route24_EventScript_CharmanderPC::
	call Route24_EventScript_GetCharmander
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route24_EventScript_TransferCharmander
	call Common_EventScript_NameReceivedBoxMon
	goto Route24_EventScript_TransferCharmander
	end

Route24_EventScript_TransferCharmander::
	call Common_EventScript_TransferredToPC
	goto Route24_EventScript_GotCharmander
	end

Route24_EventScript_NoRoomForCharmander::
	msgbox Route24_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

Route24_Text_NoRoomForMorePokemon::
    .string "Oh! You don't have room\n"
    .string "for any more Pokémon!$"

@Rocket Scene

Route24_EventScript_RocketTriggerLeft::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerLeft
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerLeft
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerLeft:
	face_left
	emote_question_mark
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	step_end

Movement_CenterPlayerLeft:
	walk_down
	walk_right
	face_up
	step_end

Route24_EventScript_RocketTriggerRight::
	lock
	applymovement LOCALID_DISGUISED_ROCKET, Movement_StopPlayerRight
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 8
	msgbox Route24_Text_GetYourReward, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CenterPlayerRight
	waitmovement 0
	turnobject LOCALID_DISGUISED_ROCKET, DIR_SOUTH
	goto Route24_EventScript_DisguisedRocket
	end

Movement_StopPlayerRight:
	face_right
	emote_question_mark
	delay_16
	delay_16
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_CenterPlayerRight:
	walk_down
	walk_left
	face_up
	step_end

Route24_Text_GetYourReward:
	.string "Excuse me!\n"
	.string "Don't you want your reward?$"

Route24_EventScript_DisguisedRocket::
	lock
	msgbox Route24_Text_JustEarnedFabulousPrize, MSGBOX_DEFAULT
	checkitemspace ITEM_NUGGET, 1
	goto_if_eq VAR_RESULT, FALSE, Route24_EventScript_NoRoomForNugget
	playfanfare MUS_OBTAIN_ITEM
	msgbox Route24_Text_ReceivedNuggetFromMysteryTrainer, MSGBOX_DEFAULT
	waitfanfare
	additem ITEM_NUGGET, 1
	applymovement LOCALID_DISGUISED_ROCKET, Movement_LookSuspicious
	msgbox Route24_Text_SecretPrize, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route24_EventScript_SecretPrize
	msgbox Route24_Text_WasntReallyAQuestion, MSGBOX_DEFAULT
	removeobject LOCALID_ROCKET
	setobjectxyperm LOCALID_ROCKET, 11, 15
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	applymovement LOCALID_DISGUISED_ROCKET, Movement_RocketReveal
	playse SE_EXIT
	waitse
	addobject LOCALID_ROCKET
	removeobject LOCALID_DISGUISED_ROCKET
	goto Route24_EventScript_DisguisedRocketBattle
	end

Route24_Text_JustEarnedFabulousPrize::
    .string "Congratulations! You beat our\n"
    .string "five contest Trainers!\p"
    .string "You just earned a fabulous prize!$"

Route24_Text_ReceivedNuggetFromMysteryTrainer::
    .string "{PLAYER} received a Nugget\n"
    .string "from the mystery Trainer!$"

Route24_Text_SecretPrize::
	.string "You know kid, I've never\n"
	.string "seen anyone battle like that\l"
	.string "before...\p"
	.string "I think you qualify for the\n"
	.string "Secret Prize!\p"
	.string "So, what do you say...\n"
	.string "Would you like the Secret Prize?$"

Movement_LookSuspicious:
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

Route24_Text_WasntReallyAQuestion::
	.string "Maybe I wasn't very clear.\p"
	.string "That wasn't really a question.\p"
	.string "See, Nugget Bridge is funded\n"
	.string "by none other than Team Rocket!$"

Movement_RocketReveal::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	step_end

Route24_EventScript_DisguisedRocketBattle::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_6, Route24_Text_RocketGruntIntro, Route24_Text_RocketGruntDefeat, Route24_EventScript_DisguisedRocketDefeated
	end

Route24_Text_RocketGruntIntro:
	.string "We're a group of professional\n"
    .string "criminals specializing in POKéMON!\p"
    .string "A stronger trainer like you, well\n"
    .string "my bosses would be pretty upset if\l"
    .string "if I missed my chance to recruit you!\p"
    .string "That's the secret prize - you get to\n"
    .string "join the one and only Team Rocket!\p"
    .string "…Okay, you need convincing!\p"
    .string "I'll make you an offer you can't\n"
    .string "refuse!$"

Route24_Text_RocketGruntDefeat::
    .string "Arrgh!\n"
    .string "You are good!$"

Route24_EventScript_DisguisedRocketDefeated::
	msgbox Route24_Text_BossesAreGonnaKillMe, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	waitmovement 11
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	goto Route24_EventScript_LookerConclusion
	end

Route24_Text_BossesAreGonnaKillMe::
	.string "My bosses are gonna kill me!\n"
	.string "I gotta bail!$"

Route24_EventScript_SecretPrize::
	applymovement LOCALID_DISGUISED_ROCKET, Common_Movement_ExclamationMark
	msgbox Route24_Text_OhWowThatsGreat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DISGUISED_ROCKET, Movement_GetJessieJames
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	waitmovement 9
	removeobject LOCALID_DISGUISED_ROCKET
	delay 10
	fadescreen FADE_FROM_BLACK
	fadenewbgm MUS_RG_ENCOUNTER_ROCKET
	applymovement LOCALID_ROCKET, Movement_RocketApproach
	applymovement LOCALID_JESSIE, Movement_JessieJamesEnter
	applymovement LOCALID_JAMES, Movement_JessieJamesEnter
	waitmovement 11
	msgbox Route24_Text_ThisIsTheKid, MSGBOX_DEFAULT
	applymovement LOCALID_JESSIE, Movement_JessieAction
	applymovement LOCALID_JAMES, Movement_JamesAction
	waitmovement 9
	msgbox Route24_Text_YouFool, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitmovement 11
	msgbox Route24_Text_YourProblemNow, MSGBOX_DEFAULT
	applymovement LOCALID_ROCKET, Movement_RocketBails
	closemessage
	waitmovement 11
	removeobject LOCALID_ROCKET
	applymovement LOCALID_JESSIE, Movement_JessieApproach
	applymovement LOCALID_JAMES, Movement_JamesApproach
	waitmovement 9
	goto Route24_EventScript_BattleJessieJames
	end

Movement_RocketApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_JessieJamesEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_Text_ThisIsTheKid::
	.string "Jessie, James, this is the\n"
	.string "kid I was telling you about!\p"
	.string "They earned the Secret Prize.\p"
    .string "With their ability, they'd become\n"
    .string "a top leader in Team Rocket.\p"
    .string "I'm sure of it!\p"
    .string "So, what do you say!\n"
    .string "Should we let them join up?$"

Route24_Text_OhWowThatsGreat::
	.string "Wow! Really?\p"
	.string "It usually takes some more\n"
	.string "convincing...\p"
	.string "Well that's great! Let me\n"
	.string "get my bosses, and then we\l"
	.string "get ready for your Secret Prize!$"

Movement_GetJessieJames::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieAction:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	step_end

Movement_JamesAction:
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Movement_RocketBails:
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_JessieApproach:
	walk_down
	face_right
	emote_exclamation_mark
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	delay_16
	step_end

Movement_JamesApproach:
	delay_16
	delay_16
	walk_down
	face_left
	emote_exclamation_mark
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route24_Text_YouFool:
	.string "Jessie: You fool!\p"
	.string "James: You imbecile!\p"
	.string "Jessie: This is the brat that\n"
	.string "ruined our plans at Mt. Moon!\p"
	.string "James: They've probably led the\n"
	.string "International Police right to us!$"

Route24_Text_YourProblemNow:
	.string "Rocket: Yikes!\p"
	.string "Well...erm...that means\n"
	.string "you both want a rematch, right?\p"
	.string "Yeah! Um, I'll go warn the others!$"

Route24_EventScript_BattleJessieJames::
	trainerbattle_double TRAINER_ROCKET_DUO_NB, Route24_Text_RocketDuoIntro, Route24_Text_RocketDuoDefeat, Text_NeedTwoMons, Route24_EventScript_RocketDuoDefeated, NO_MUSIC
	end

Route24_Text_RocketDuoIntro:
	.string "Jessie: For beating us in\n"
	.string "Mt. Moon...\p"
	.string "James: We'll make you look\n"
	.string "like a buffoon!\p"
	.string "Jessie: Prepare for trouble!\n"
	.string "James: And make it double!$"

Route24_Text_RocketDuoDefeat:
	.string "You brat! How could you\n"
	.string "do this to us again!$"

Route24_EventScript_RocketDuoDefeated::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox Route24_Text_WontBeTheLastTime, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	closemessage
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_CERULEAN_CITY_ROCKETS, 1
	fadenewbgm MUS_ENCOUNTER_CHAMPION
	fadescreen FADE_FROM_BLACK
	goto Route24_EventScript_LookerConclusion

Route24_Text_WontBeTheLastTime::
	.string "This won't be the last time\n"
	.string "you face off against Team\l"
	.string "Rocket!\p"
	.string "So just be happy we're letting\n"
	.string "you off so easy!$"

Route24_EventScript_LookerConclusion::
	closemessage
	clearflag FLAG_HIDE_ROUTE24_LOOKER
	addobject LOCALID_LOOKER
	setobjectxyperm LOCALID_ROCKET, 11,9
	clearflag FLAG_HIDE_ROUTE24_ROCKET
	addobject LOCALID_ROCKET
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MoveToLooker
	waitmovement 0
	message Route25_Text_ComingWithUs
	waitmessage
	delay 10
	closemessage
	applymovement LOCALID_LOOKER, Movement_LookerCaughtRocket
	applymovement LOCALID_ROCKET, Movement_RocketGotCaught
	waitmovement 12
	removeobject LOCALID_LOOKER
	removeobject LOCALID_ROCKET
	fadedefaultbgm
	releaseall
	end

Route25_Text_ComingWithUs::
	.string "Looker: Not so fast.\n"
	.string "You'll be coming with us.\p"
	.string "I can't wait to hear more\n"
	.string "about this Secret Prize...$"

Movement_MoveToLooker::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	emote_exclamation_mark
	step_end

Movement_LookerCaughtRocket::
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RocketGotCaught::
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_16
	delay_16
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_NoRoomForNugget::
	msgbox Route24_Text_YouDontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route24_Text_YouDontHaveAnyRoom::
    .string "You don't have any room!\p"
    .string "My boss would hate it if\n"
    .string "I didn't give you your\l"
    .string "prize, so please come\l"
    .string "back when you have room!$"

Route24_EventScript_ItemTM45::
	finditem ITEM_TM45, 1
	end

Route24_EventScript_Shane::
	trainerbattle_single REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneIntro, Route24_Text_ShaneDefeat, Route24_EventScript_RegisterShaneAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route24_EventScript_ShaneRematch
	msgbox Route24_Text_ShanePostBattle, MSGBOX_DEFAULT
	release
	end

Route24_Text_ShaneIntro::
    .string "I was watching your battles\n"
    .string "on Nugget Bridge from over here!$"

Route24_Text_ShaneDefeat::
    .string "I thought not!$"

Route24_Text_ShanePostBattle::
    .string "I hid because the people on the\n"
    .string "bridge frightened me.$"

Route24_EventScript_RegisterShaneAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route24_Text_ShaneRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_CAMPER_SHANE_1
	release
	end

Route24_Text_ShaneRegister:
	.string "Wow! You're strong!\p"
	.string "If you were my friend, I\n"
	.string "won't have to be frightened!$"

Route24_EventScript_ShaneRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_CAMPER_SHANE_1, Route24_Text_ShaneRematchIntro, Route24_Text_ShaneDefeat
	msgbox Route24_Text_ShaneRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route24_Text_ShaneRematchIntro::
	.string "Hey {PLAYER}!\n"
	.string "Teach me to be strong like you!$"

Route24_Text_ShaneRematchPostBattle::
	.string "I'll keep watching you from\n"
	.string "over here!$"


@Normal Nugget Bridge Trainers
Movement_NuggetBridgeTrainerExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route24_EventScript_Cale::
	trainerbattle_single TRAINER_BUG_CATCHER_CALE, Route24_Text_CaleIntro, Route24_Text_CaleDefeat, Route24_EventScript_CalePostBattle
	end

Route24_EventScript_CalePostBattle::
	msgbox Route24_Text_CalePostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_CALE, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 1
	removeobject LOCALID_CALE
	end

Route24_Text_CaleIntro::
    .string "People call this the Nugget\n"
    .string "Bridge!\p"
    .string "Beat us five Trainers and win\n"
    .string "a fabulous prize!\p"
    .string "Think you got what it takes?$"

Route24_Text_CaleDefeat::
    .string "Whoo!\n"
    .string "Good stuff!$"

Route24_Text_CalePostBattle::
    .string "I did my best. I have no regrets!$"

Route24_EventScript_Ali::
	trainerbattle_single TRAINER_LASS_ALI, Route24_Text_AliIntro, Route24_Text_AliDefeat, Route24_EventScript_AliPostBattle
	
Route24_EventScript_AliPostBattle::
	msgbox Route24_Text_AliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ALI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 2
	removeobject LOCALID_ALI
	end

Route24_Text_AliIntro::
    .string "I'm second!\n"
    .string "Now it's serious!$"

Route24_Text_AliDefeat::
    .string "How could I lose?$"

Route24_Text_AliPostBattle::
    .string "I did my best. I have no regrets!$"

Route24_EventScript_Timmy::
	trainerbattle_single TRAINER_YOUNGSTER_TIMMY, Route24_Text_TimmyIntro, Route24_Text_TimmyDefeat, Route24_EventSript_TimmyPostBattle
	end

Route24_EventSript_TimmyPostBattle::
	msgbox Route24_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_TIMMY, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 3
	removeobject LOCALID_TIMMY
	end

Route24_Text_TimmyIntro::
    .string "Here's No. 3!\n"
    .string "I won't be easy!$"

Route24_Text_TimmyDefeat::
    .string "Ow!\n"
    .string "Stomped flat!$"

Route24_Text_TimmyPostBattle::
    .string "I did my best. I have no regrets!$"

Route24_EventScript_Reli::
	trainerbattle_single TRAINER_LASS_RELI, Route24_Text_ReliIntro, Route24_Text_ReliDefeat, Route24_EventScript_ReliPostBattle
	end

Route24_EventScript_ReliPostBattle::
	msgbox Route24_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_RELI, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 4
	removeobject LOCALID_RELI
	end

Route24_Text_ReliIntro::
    .string "I'm No. 4!\n"
    .string "Getting tired?$"

Route24_Text_ReliDefeat::
    .string "I lost, too!$"

Route24_Text_ReliPostBattle::
    .string "I did my best, so I've no regrets!$"

Route24_EventScript_Ethan::
	trainerbattle_single TRAINER_CAMPER_ETHAN, Route24_Text_EthanIntro, Route24_Text_EthanDefeat, Route24_EventScript_EthanPostBattle
	end

Route24_EventScript_EthanPostBattle::
	msgbox Route24_Text_EthanPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ETHAN, Movement_NuggetBridgeTrainerExit
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	waitmovement 5
	removeobject LOCALID_ETHAN
	end

Route24_Text_EthanIntro::
    .string "Okay! I'm No. 5!\n"
    .string "I'll stomp you!$"

Route24_Text_EthanDefeat::
    .string "Whoa!\n"
    .string "Too much!$"

Route24_Text_EthanPostBattle::
    .string "I did my best. I have no regrets!$"

@TODO: Postgame Nugget Bridge

