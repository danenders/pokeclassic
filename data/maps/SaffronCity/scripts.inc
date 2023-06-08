.set LOCALID_DOOR_GUARD, 1
.set LOCALID_LOOKER, 16

SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	call_if_set FLAG_LOOKER_POSTGAME_STARTED, CheckLookerPostgame
	end

CheckLookerPostgame::
	call_if_unset FLAG_LOOKER_POSTGAME_COMPLETED, ShowPostGameRockets
	return

ShowPostGameRockets::
	clearflag FLAG_HIDE_SILPH_POSTGAME_ROCKET
	return

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_DOOR_GUARD, 33, 31
	return

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	faceplayer
	msgbox SaffronCity_Text_ImASecurityGuard
	turnobject LOCALID_DOOR_GUARD, DIR_SOUTH
	release
	end

SaffronCity_Text_ImASecurityGuard::
    .string "I'm a security guard.\p"
    .string "Suspicious kids I don't allow in!$"

SaffronCity_EventScript_DoorGuardAsleep::
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_Text_HesTakingASnooze::
    .string "…\n"
    .string "Snore…\p"
    .string "Hah! He's taking a snooze!$"

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_Text_WhatDoYouWantGetLost::
    .string "What do you want?\n"
    .string "Get lost!$"

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_BossTakeTownForTeamRocket::
    .string "Boss said he'll take this town\n"
    .string "in the name of Team Rocket!$"

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
    .string "Don't get defiant!\n"
    .string "Or I'll have to hurt you!$"

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_SaffronBelongsToTeamRocket::
    .string "Saffron belongs to Team Rocket!$"

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
    .string "My life as a criminal makes me feel\n"
    .string "so alive!$"

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_Text_WatchWhereYoureWalking::
    .string "Ow!\n"
    .string "Watch where you're walking!$"

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_Text_WeCanExploitMonsAroundWorld::
    .string "With Silph under control, we can\n"
    .string "exploit Pokémon around the world!\p"
    .string "We'll get stinking rich, yeahah!$"


SaffronCity_EventScript_BattleGirl::
	msgbox SaffronCity_Text_HowCanClubNotRecognizeLance, MSGBOX_NPC
	release
	end

SaffronCity_Text_HowCanClubNotRecognizeLance::
    .string "This Fan Club…\n"
    .string "No one here has a clue!\p"
    .string "How could they not recognize\n"
    .string "the brilliance that is Lance?\p"
    .string "He stands for justice!\n"
    .string "He's cool, and yet passionate!\l"
    .string "He's the greatest, Lance!$"

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_Text_YouBeatTeamRocket::
    .string "You beat Team Rocket all alone?\n"
    .string "That's amazing!$"

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_Text_SafeToGoOutAgain::
    .string "Yeah! Team Rocket is gone!\n"
    .string "It's safe to go out again!$"

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_Text_PeopleComingBackToSaffron::
    .string "People fled from here in droves\n"
    .string "when those Rockets came.\p"
    .string "They should be flocking back to\n"
    .string "Saffron now.$"

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_Text_FlewHereOnPidgeot::
    .string "I flew here on my Pidgeot when\n"
    .string "I read about Silph.\p"
    .string "It's already over?\n"
    .string "I missed the media action…$"

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_Text_Pidgeot::
    .string "Pidgeot: Bi bibii!$"

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_Text_SawRocketBossEscaping::
    .string "I saw the Rocket Boss escaping\n"
    .string "Silph's building.$"

SaffronCity_EventScript_GymSign::
	lockall
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_Text_GymSign::
    .string "Saffron City Pokémon Gym\n"
    .string "Leader: Sabrina\l"
    .string "The Master of Psychic Pokémon!$"

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_Text_CitySign::
    .string "Saffron City\n"
    .string "Shining, Golden Land of Commerce$"

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Text_FightingDojo::
    .string "Fighting Dojo$"

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_TrainerFanClubSign::
    .string "Pokémon Trainer Fan Club\p"
    .string "Many trainers have scribbled their\n"
    .string "names on this sign.$"

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_Text_FullHealCuresStatus::
    .string "Trainer Tips:\p"
    .string "Full Heal cures all ailments like\n"
    .string "burns, paralysis, poisoning,\l"
    .string "freezing, and sleep.\p"
    .string "It costs a bit more, but it's more\n"
    .string "convenient than buying other items.$"

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_Text_GreatBallImprovedCatchRate::
    .string "Trainer Tips:\p"
    .string "The new Great Ball offers improved\n"
    .string "catching rates.\p"
    .string "Try it on those hard-to-catch\n"
    .string "Pokémon.$"

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_Text_SilphCoSign::
    .string "Silph Co. Headquarters$"

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_Text_MrPsychicsHouse::
    .string "Mr. Psychic's House$"

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_Text_SilphsLatestProduct::
    .string "Silph's latest product!\n"
    .string "Release to be determined…$"

SaffronCity_EventScript_SkippedLookerScene::
	setvar VAR_SILPH_STATE, 4
	end

SaffronCity_EventScript_LookerTriggerL1::
	setobjectxyperm LOCALID_LOOKER, 24, 32
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL2::
	setobjectxyperm LOCALID_LOOKER, 24, 33
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerL3::
	setobjectxyperm LOCALID_LOOKER, 24, 34
	setvar VAR_TEMP_1, 1
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR1::
	setobjectxyperm LOCALID_LOOKER, 42, 32
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR2::
	setobjectxyperm LOCALID_LOOKER, 42, 33
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_LookerTriggerR3::
	setobjectxyperm LOCALID_LOOKER, 42, 34
	setvar VAR_TEMP_1, 2
	goto SaffronCity_EventScript_Looker

SaffronCity_EventScript_Looker::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_CHAMPION, 0
	clearflag FLAG_HIDE_SAFFRON_CITY_LOOKER
	addobject LOCALID_LOOKER
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerLeft
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerRight
	waitmovement 16
	playse SE_PIN
	applymovement LOCALID_LOOKER, Common_Movement_ExclamationMark
	waitse
	waitmovement 16
	msgbox SaffronCity_Text_ShouldntBeSurprised, MSGBOX_DEFAULT
	waitmessage
	call_if_eq VAR_TEMP_1, 1, SaffronCity_EventScript_MoveLookerRight
	call_if_eq VAR_TEMP_1, 2, SaffronCity_EventScript_MoveLookerLeft
	waitmovement 16
	removeobject LOCALID_LOOKER
	fadedefaultbgm
	setvar VAR_SILPH_STATE, 4
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

SaffronCity_EventScript_MoveLookerLeft::
	applymovement LOCALID_LOOKER, Movement_LookerWalksRight
	return

Movement_LookerWalksRight::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SaffronCity_EventScript_MoveLookerRight::
	applymovement LOCALID_LOOKER, Movement_LookerWalksLeft
	return

Movement_LookerWalksLeft::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SaffronCity_Text_ShouldntBeSurprised::
	.string "Looker: Alright, let's start setting\n"
	.string "up a perimeter...Oh! {PLAYER}!\p"
	.string "We just finished rounding up the Team\n"
	.string "Rocket Grunts that were terrorizing the\l"
	.string "Citizens. We're ready to make our assault\l"
	.string "on Silph Co and take down their Boss!\p"
	.string "Those Rocket Plans you delivered were\n"
	.string "very helpful, but I'll need you to step\l"
	.string "aside for this one and let the adults take\l"
	.string "care of it now!\p"
	.string "...\p"
	.string "You what?!\p"
	.string "You already took out the Rockets inside\n"
	.string "Silph Co and rescued their President?\p"
	.string "That's incredible, but very reckless!\p"
	.string "Wait...\n"
	.string "What about the Rocket Boss?\p"
	.string "He got away? Again? Blast!\p"
	.string "We've busted every Rocket Base we could\n"
	.string "find, and we've chased him across Kanto.\p"
	.string "There can't be many places left\n"
	.string "for him to hide.\p"
	.string "But we have no leads!\n"
	.string "I'll have to continue my investigation.$"
