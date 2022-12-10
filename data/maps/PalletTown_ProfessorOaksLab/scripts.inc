.set LOCALID_OAK, 1
.set LOCALID_RIVAL, 2
.set LOCALID_POKEBALL, 3
.set LOCALID_POKEDEX_L, 7
.set LOCALID_POKEDEX_R, 8
.set LOCALID_PIKACHU, 9

@OAK LAB STATES:
@ 0: Player hasn't met Oak yet
@ 1: Player met Oak and warped back to lab
@ 2: Oak gave intro speech
@ 3: Rival grabbed Eevee
@ 4: Triggered Rival Battle
@ 5: Returned from Rival Battle
@ 6: Collected Oak's Parcel
@ 7: Received Pokedex
@ 8: Left Lab after getting Pokedex
@ 9: Registered Oak in Cell Phone

PalletTown_ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, PalletTown_ProfessorOaksLab_OnReturnToField
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
	.byte 0

PalletTown_ProfessorOaksLab_OnReturnToField:
	call_if_eq VAR_OAK_LAB_STATE, 4, PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle
	end

PalletTown_ProfessorOaksLab_EventScript_HealAfterFirstBattle::
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 5
	end

PalletTown_ProfessorOaksLab_OnWarp:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_RIVAL, DIR_NORTH
	end

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForPokedexScene::
	setobjectxyperm LOCALID_RIVAL, 6, 11
	setobjectmovementtype LOCALID_OAK, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_RG_OAK
	end

PalletTown_ProfessorOaksLab_OnFrame:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_GetStarterScene
	map_script_2 VAR_OAK_LAB_STATE, 6, PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_GetStarterScene::
	lockall
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_TakeStarter, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe, MSGBOX_DEFAULT
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival, MSGBOX_DEFAULT
	setvar VAR_OAK_LAB_STATE, 2
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting:
    .string "{RIVAL}: Gramps!\n"
    .string "I'm fed up with waiting!$"

PalletTown_ProfessorOaksLab_Text_TakeStarter::
    .string "Oak: {RIVAL}?\n"
    .string "Let me think…\p"
    .string "Oh, that's right, I told you to\n"
    .string "come! Just wait!\p"
    .string "Here, {PLAYER}.\p"
    .string "There is a Pokéball on my desk.\p"
    .string "When I was young, I was a serious\n"
    .string "Pokémon trainer.\p"
    .string "But now, in my old age, I study\n"
    .string "Pokémon more than I battle.\p"
    .string "I'd like you to raise this\n"
    .string "Pokémon for me!$"

PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe::
    .string "{RIVAL}: Hey! Gramps! No fair!\n"
    .string "What about me?$"

PalletTown_ProfessorOaksLab_Text_OakBePatientRival::
    .string "Oak: Be patient, {RIVAL}.\p"
    .string "I'll take you to catch \n"
    .string "your own Pokémon later.$"

PalletTown_ProfessorOaksLab_EventScript_ApproachPokeBallBehindDesk::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk2
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_StealEeveeTooSlow
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PalletTown_ProfessorOaksLab_Text_TooSlow, MSGBOX_DEFAULT
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOakFar
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	end

Movement_RivalMoveToDesk2::
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Movement_StealEeveeTooSlow::
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	delay_16
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_TooSlow::
	.string "{RIVAL}: Too slow, {PLAYER}!\p"
	.string "This is what you get for\n"
	.string "taking the long way around.$"

Movement_PlayerReturnToOakFar::
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalStealEevee::
	lockall
	turnobject LOCALID_RIVAL, DIR_EAST
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_RivalMoveToDesk
	waitmovement 2
	playse SE_WALL_HIT
	applymovement LOCALID_RIVAL, Movement_PushPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Movement_GetPushed
	waitse
	waitmovement 2
	applymovement LOCALID_RIVAL, Movement_TakeEevee
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitse
	waitmovement 0
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	msgbox PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerReturnToOak
	waitmovement 0
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu
	end

Movement_RivalMoveToDesk::
	walk_right
	walk_right
	walk_right
	step_end

Movement_PushPlayer::
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Movement_GetPushed::
	walk_right
	face_left
	step_end

Movement_TakeEevee::
	walk_right
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	delay_16
	step_end

Movement_PlayerReturnToOak::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

PalletTown_ProfessorOaksLab_Text_WereGoingToGetOne::
	.string "Oak: {RIVAL}!\p"
	.string "Sigh...alright.\n"
	.string "That Pokémon is yours.\p"
	.string "{PLAYER}, come over here.$"

PalletTown_ProfessorOaksLab_EventScript_PreventExit::
	applymovement LOCALID_OAK, Movement_OakStopPlayer
	waitmovement 1
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_QuestionMark
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_DontWantAPokemon, MSGBOX_DEFAULT
	applymovement LOCALID_OAK, Movement_OakReturnToPosition
	applymovement OBJ_EVENT_ID_PLAYER, Movement_CantExitLab
	waitmovement 0
	release
	end

Movement_OakStopPlayer::
	walk_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	delay_8
	step_end

Movement_OakReturnToPosition::
	walk_up
	face_down
	step_end

PalletTown_ProfessorOaksLab_Text_DontWantAPokemon::
	.string "Oak: Do you not want a\n"
	.string "Pokémon, {PLAYER}?$"

Movement_CantExitLab::
	walk_up
	face_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu::
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier, MSGBOX_DEFAULT
	playse SE_BALL_OPEN
	clearflag FLAG_HIDE_OAK_LAB_PIKACHU
	addobject LOCALID_PIKACHU
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	turnobject LOCALID_OAK, DIR_WEST
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow, MSGBOX_DEFAULT
	applymovement LOCALID_PIKACHU, Movement_PikachuJoinsParty
	waitmovement 9
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_PIKACHU, Common_Movement_Heart
	waitmovement 9
	waitse
	givemon SPECIES_PIKACHU_PARTNER, 5
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	msgbox PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

Movement_PikachuJoinsParty::
	walk_down
	face_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	step_end

PalletTown_ProfessorOaksLab_Text_PikachuFromEarlier:
	.string "Oak: Technically, that was\n"
	.string "not my last Pokémon.\p"
	.string "I still have the Pikachu\n"
	.string "I caught earlier...\p"
	.string "I was going to return it to\n"
	.string "its natural habitat, but\l"
	.string "perhaps you should take it.$"
	
PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree:
	.string "Oak: Incredible!\p"
	.string "It broke free of its Pokéball!$"

PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow:
	.string "Oak: It seems to have taken quite\n"
	.string "an interest in you, {PLAYER}.\p"
	.string "It looks like Pikachu has already\n"
	.string "made its decision!\p"
	.string "You should absolutely take this\n"
	.string "Pokémon.$"

PalletTown_ProfessorOaksLab_Text_PikachuJoinedTeam:
	.string "Pikachu decided to stay by\n"
	.string "{PLAYER}'s side!$"

PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon:
	.string "Oak: Say, why don't you give\n"
	.string "a nickname to your new partner?$"

PalletTown_ProfessorOaksLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty
	end

PalletTown_ProfessorOaksLab_EventScript_PikachuJoinsParty::
	removeobject LOCALID_PIKACHU
	setflag FLAG_HIDE_OAK_LAB_PIKACHU
	callnative UpdateFollowingPokemon
	setvar VAR_OAK_LAB_STATE, 3
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger1::
	setvar VAR_TEMP_1, 1
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger2::
	setvar VAR_TEMP_1, 2
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalTrigger3::
	setvar VAR_TEMP_1, 3
	goto PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWantsToBattle::
	lockall
	setvar VAR_OAK_LAB_STATE, 4
	turnobject LOCALID_RIVAL, DIR_SOUTH
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons, MSGBOX_DEFAULT
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproach3
	waitmovement 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	trainerbattle_no_whiteout_continue_script TRAINER_RIVAL_FIRST_BATTLE,PalletTown_ProfessorOaksLab_Text_RivalBattleIntro,PalletTown_ProfessorOaksLab_Text_RivalDefeated,PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome
	end

PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons::
    .string "{RIVAL}: Wait, {PLAYER}!$"

PalletTown_ProfessorOaksLab_Text_RivalBattleIntro::
    .string "Let's check out our Pokémon!\p"
    .string "Come on, I'll take you on!$"

PalletTown_ProfessorOaksLab_Text_RivalDefeated::
    .string "{RIVAL}: WHAT?\n"
    .string "Unbelievable!\l"
    .string "I picked the wrong Pokémon!$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleOutcome::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost
	end

PalletTown_ProfessorOaksLab_EventScript_RivalBattleLost::
	msgbox PalletTown_ProfessorOaksLab_Text_RivalVictory, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalVictory::
    .string "{RIVAL}: Yeah!\n"
    .string "Am I great or what?$"

PalletTown_ProfessorOaksLab_EventScript_RivalBattleWon::
	addvar VAR_RIVAL_WINRATE, 1
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon, MSGBOX_DEFAULT
	goto PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle
	end

PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon::
    .string "{RIVAL}: Okay! I'll make my\n"
    .string "Pokémon battle to toughen it up!\p"
    .string "{PLAYER}! Gramps!\n"
    .string "Smell you later!$"

PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle::
	closemessage
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3
	playbgm MUS_RG_RIVAL_EXIT, 0
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RIVAL_IN_LAB
	setvar VAR_ADVENTURE_BEGINS, 3
	fadedefaultbgm
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalApproach1::
	applymovement LOCALID_RIVAL, Movement_RivalApproach1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach2::
	applymovement LOCALID_RIVAL, Movement_RivalApproach2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach3::
	applymovement LOCALID_RIVAL, Movement_RivalApproach3
	return

Movement_RivalApproach1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Movement_RivalApproach3:
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle1::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle1
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle2::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle2
	return

PalletTown_ProfessorOaksLab_EventScript_RivalLeavesAfterBattle3::
	applymovement LOCALID_RIVAL, Movement_RivalLeavesAfterBattle3
	return

Movement_RivalLeavesAfterBattle1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle2:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

Movement_RivalLeavesAfterBattle3:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_GetPokedexScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachOak
	waitmovement 0
	turnobject LOCALID_OAK, DIR_SOUTH
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_TMHM
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
	waitmessage
	waitfanfare
	removeitem ITEM_OAKS_PARCEL, 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
	addobject LOCALID_RIVAL
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_RIVAL, Movement_RivalReturnsToLab
	waitmovement 2
	fadedefaultbgm
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
	closemessage
	delay 30
	playse SE_PIN
	applymovement LOCALID_OAK, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
	closemessage
	applymovement LOCALID_OAK, Movement_OakGoToPokedex1
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
	closemessage
	delay 40
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
	closemessage
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_L
	delay 10
	applymovement LOCALID_OAK, Movement_OakGoToPokedex2
	waitmovement 1
	applymovement LOCALID_OAK, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	removeobject LOCALID_POKEDEX_R
	setflag FLAG_HIDE_POKEDEX_ON_TABLE
	delay 10
	applymovement LOCALID_OAK, Movement_OakReturnToPlayer
	waitmovement 1
	delay 10
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
	giveitem ITEM_POKE_BALL, 5
	@PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls 
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
	turnobject LOCALID_RIVAL, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_RIVAL, Movement_RivalLeavesWithPokedex
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	fadedefaultbgm
	setflag FLAG_HIDE_OFFICER_JENNY_VIRIDIAN_CITY
	setvar VAR_OAK_LAB_STATE, 7
	setvar VAR_ADVENTURE_BEGINS, 6
	setvar VAR_ROUTE_22_RIVAL_STATE, 1
	release
	end

Movement_PlayerApproachOak:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_RivalReturnsToLab:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	face_up
	step_end

Movement_OakGoToPokedex1:
	walk_up
	walk_left
	walk_left
	face_up
	step_end

Movement_OakGoToPokedex2:
	walk_right
	face_up
	step_end

Movement_OakReturnToPlayer:
	walk_right
	walk_down
	step_end

Movement_RivalLeavesWithPokedex:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe::
    .string "Oak: Oh, {PLAYER}!\n"
    .string "How is your new Pokémon?\p"
    .string "Well, it seems to be growing more\n"
    .string "attached to you.\p"
    .string "You must be talented as a Pokémon\n"
    .string "trainer.\p"
    .string "What's that?\n"
    .string "You have something for me?$"

PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel::
    .string "{PLAYER} delivered Oak's Parcel.$"

PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered::
    .string "Ah! \n"
    .string "It's the custom Poké Ball!\p"
    .string "I had it on order.\n"
    .string "Thank you!$"

PalletTown_ProfessorOaksLab_Text_RivalGramps::
    .string "{RIVAL}: Gramps!$"

PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor::
    .string "{RIVAL}: I almost forgot!\n"
    .string "What did you call me for?$"

PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo::
    .string "Oak: Oh, right!\n"
    .string "I have a request for you two.$"

PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk::
    .string "On the desk there is my invention,\n"
    .string "the Pokédex!\p"
    .string "It automatically records data on\n"
    .string "Pokémon you've seen or caught.\p"
    .string "It's a high-tech encyclopedia!$"

PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou::
    .string "Oak: {PLAYER} and {RIVAL}.\n"
    .string "Take these with you.$"

PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak::
    .string "{PLAYER} received the Pokédex\n"
    .string "from Professor Oak!$"

PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese::
    .string "Oak: You can't get detailed data\n"
    .string "on Pokémon by just seeing them.\p"
    .string "You must catch them to obtain\n"
    .string "complete data.\p"
    .string "So, here are some tools for\n"
    .string "catching wild Pokémon.$"

PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls::
    .string "{PLAYER} received five Poké Balls.$"

PalletTown_ProfessorOaksLab_Text_OakExplainCatching::
    .string "When a wild Pokémon appears,\n"
    .string "it's fair game.\p"
    .string "Just throw a Poké Ball at it and\n"
    .string "try to catch it!\p"
    .string "This won't always work, however.\p"
    .string "A healthy Pokémon can escape.\n"
    .string "You have to be lucky!$"

PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream::
    .string "To make a complete guide on all\n"
    .string "the Pokémon in the world…\p"
    .string "That was my dream!\p"
    .string "But, I'm too old.\n"
    .string "I can't get the job done.\p"
    .string "So, I want you two to fulfill my\n"
    .string "dream for me.\p"
    .string "Get moving, you two.\p"
    .string "This is a great undertaking in\n"
    .string "Pokémon history!$"

PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps::
    .string "{RIVAL}: All right, Gramps!\n"
    .string "Leave it all to me!$"

PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouNumber::
    .string "{PLAYER}, I hate to say it, but you\n"
    .string "won't be necessary for this.\p"
    .string "You're on your own from here, so\n"
    .string "don't bother calling me!\p"
    .string "And don't try and get my number from\n"
    .string "my sister, either.\p"
    .string "I'll tell her not to give it to you,\n"
    .string "{PLAYER}! Hahaha!$"

PalletTown_ProfessorOaksLab_EventScript_Rival::
	goto_if_eq VAR_OAK_LAB_STATE, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWaiting
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough
	end

PalletTown_ProfessorOaksLab_EventScript_RivalWaiting::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround::
    .string "{RIVAL}: What, it's only {PLAYER}?\n"
    .string "Gramps isn't around.$"

PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer:
    .string "{RIVAL}: Heh, I don't need to be\n"
    .string "greedy like you. I'm mature!\p"
    .string "Go ahead and take it, {PLAYER}!$"

PalletTown_ProfessorOaksLab_EventScript_RivalMyMonLooksTough::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher, MSGBOX_DEFAULT
	release
	end 

PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher::
    .string "{RIVAL}: My Pokémon looks a lot\n"
    .string "tougher than yours, {PLAYER}.$"

PalletTown_ProfessorOaksLab_EventScript_Computer::
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_EmailMessage::
    .string "There's an e-mail message here.\p"
    .string "…\p"
    .string "Finally!\n"
    .string "The ultimate trainers of the\l"
    .string "Pokémon League are ready to\l"
    .string "take on all comers!\p"
    .string "Bring your best Pokémon and see\n"
    .string "how you rate as a trainer!\p"
    .string "Pokémon League HQ\n"
    .string "Indigo Plateau\p"
    .string "Prof. Oak, please visit us!\n"
    .string "…$"

PalletTown_ProfessorOaksLab_EventScript_LeftSign::
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu::
    .string "Press START to open the MENU!\p"
    .string "The SAVE option is on the MENU.\n"
    .string "Use it regularly.$"

PalletTown_ProfessorOaksLab_EventScript_RightSign::
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
	releaseall
	end

PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints::
    .string "All Pokémon types have strong and\n"
    .string "weak points against others.$"

PalletTown_ProfessorOaksLab_EventScript_Aide1::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
	release
	end

PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide::
    .string "I study Pokémon as Prof. Oak's\n"
    .string "Aide.$"

PalletTown_ProfessorOaksLab_EventScript_Aide2::
	lock
	faceplayer
	goto_if_set FLAG_REGISTERED_AIDE, PalletTown_ProfessorOaksLab_EventScript_JealousAide
	msgbox PalletTown_ProfessorOaksLab_Text_CedarRunsErrands
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarRunsErrands::
    .string "Cedar is the newest aide in the lab,\n"
    .string "so she is always out running errands.$"

PalletTown_ProfessorOaksLab_EventScript_JealousAide::
	msgbox PalletTown_ProfessorOaksLab_Text_Jealous
	release
	end

PalletTown_ProfessorOaksLab_Text_Jealous::
    .string "If I'm being honest, lab work can\n"
    .string "get a little boring.\p"
    .string "I teased her in the beginning, but\n"
    .string "now I'm a little jealous that Cedar\l"
    .string "had the chance to travel so often!$"

PalletTown_ProfessorOaksLab_EventScript_Cedar::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ALL_CHARMS, PalletTown_ProfessorOaksLab_EventScript_CedarAllItems
	goto_if_set FLAG_RECEIVED_EXP_SHARE, PalletTown_ProfessorOaksLab_EventScript_CedarPostgame
	msgbox PalletTown_ProfessorOaksLab_Text_JustJoined
	setflag FLAG_MET_CEDAR
	release
	end

PalletTown_ProfessorOaksLab_Text_JustJoined::
    .string "Cedar: Hello. Nice to meet you!\n"
    .string "I recently joined Professor Oak's\l"
    .string "team.\p"
    .string "I'm excited to work with everyone.$"

PalletTown_ProfessorOaksLab_EventScript_CedarPostgame::
	msgbox PalletTown_ProfessorOaksLab_Text_CedarHiPlayer, MSGBOX_DEFAULT
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm
PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext::
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm
PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems::
	msgbox PalletTown_ProfessorOaksLab_Text_MaybeMoreItems, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_EventScript_GetCatchingCharm::
	goto_if_unset FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_CatchingCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_CATCHING_CHARM
	additem ITEM_CATCHING_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_CatchingCharmReward::
	.string "Wow! You defeated the Elite Four?\n"
	.string "That's quite an accomplishment!\p"
	.string "You know, there's still more Pokémon\n"
	.string "to see out there.\p"
	.string "This should help you complete your Pokédex!$"

PalletTown_ProfessorOaksLab_Text_ReceivedCatchingCharm::
	.string "{PLAYER} earned the Catching Charm!"

PalletTown_ProfessorOaksLab_EventScript_GetOvalCharm::
	goto_if_unset FLAG_CLEARED_SECRET_BATTLE, PalletTown_ProfessorOaksLab_EventScript_CedarCheckNext
	msgbox PalletTown_ProfessorOaksLab_Text_OvalCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_OVAL_CHARM
	additem ITEM_OVAL_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_OvalCharmReward::
	.string "Wow! You defeated Professor Oak?\n"
	.string "That's quite an accomplishment!\p"
	.string "Raising Pokémon is just as important\n"
	.string "as battling, you know.\p"
	.string "This should help you raise new Pokémon!$"

PalletTown_ProfessorOaksLab_Text_ReceivedOvalCharm::
	.string "{PLAYER} earned the Oval Charm!"

PalletTown_ProfessorOaksLab_EventScript_GetShinyCharm::
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_CedarMaybeMoreItems
	msgbox PalletTown_ProfessorOaksLab_Text_ShinyCharmReward
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm
	waitmessage
	waitfanfare
	setflag FLAG_RECEIVED_SHINY_CHARM
	additem ITEM_SHINY_CHARM, 1
	call_if_unset FLAG_RECEIVED_ALL_CHARMS, Cedar_CheckCharms
	release
	end

PalletTown_ProfessorOaksLab_Text_ShinyCharmReward::
	.string "Incredible! You caught them all?\n"
	.string "That's an amazing accomplishment!\p"
	.string "I've heard that Pokémon have rare\n"
	.string "variations.\p"
	.string "I've never seen one, though...\p"
	.string "This might help you find them!$"

PalletTown_ProfessorOaksLab_Text_ReceivedShinyCharm::
	.string "{PLAYER} earned the Shiny Charm!"

Cedar_CheckCharms::
	goto_if_unset FLAG_RECEIVED_CATCHING_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_OVAL_CHARM, Common_EventScript_Return
	goto_if_unset FLAG_RECEIVED_SHINY_CHARM, Common_EventScript_Return
	setflag FLAG_RECEIVED_ALL_CHARMS
	return

PalletTown_ProfessorOaksLab_EventScript_CedarAllItems::
	msgbox PalletTown_ProfessorOaksLab_Text_WhatAJourney
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarHiPlayer:
	.string "Cedar: Hi, {PLAYER}!\n"
	.string "Stopping by to see the Prof?\p"
	.string "Oh? You came to see me?$"

PalletTown_ProfessorOaksLab_Text_MaybeMoreItems::
	.string "Hmm, I don't have any new items\n"
	.string "to give you right now.\p"
	.string "I'd love to keep hearing about your\n"
	.string "adventures, though!\p"
	.string "If you have a good accomplishment\n"
	.string "to tell me about, I could convince\l"
	.string "Prof. Oak to give you something good!$"

PalletTown_ProfessorOaksLab_Text_WhatAJourney::
	.string "Cedar: Oh, {PLAYER}!\n"
	.string "It's so nice to see you.\p"
	.string "I don't have any new items for you\n"
	.string "this time, though. Ha!\p"
	.string "You know, when I joined Prof. Oak's\n"
	.string "Lab, I wasn't happy that I'd spend so\l"
	.string "much time travelling away from it!\p"
	.string "But, following your journey was also\n"
	.string "an adventure for me!\p"
	.string "I saw so much of Kanto, and got to\n"
	.string "what life as a Trainer must be like.\p"
	.string "I see now why Prof. Oak gave me that\n"
	.string "assignment.\p"
	.string "So, thanks for the adventure!$"

PalletTown_ProfessorOaksLab_EventScript_Pokedex::
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia::
    .string "It's like an encyclopedia, but the\n"
    .string "pages are blank.$"

PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon, MSGBOX_DEFAULT
	release
	end

PalletTown_ProfessorOaksLab_Text_OaksLastMon::
    .string "That's Prof. Oak's last Pokémon.$"

PalletTown_ProfessorOaksLab_EventScript_ProfOak::
	lock
	faceplayer
	goto_if_eq VAR_OAK_LAB_STATE, 2, PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball
	goto_if_eq VAR_OAK_LAB_STATE, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
	goto_if_le VAR_OAK_LAB_STATE, 5, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
	goto_if_eq VAR_OAK_LAB_STATE, 7, PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait
	goto_if_unset FLAG_REGISTERED_PROF_OAK, EventScript_RegisterProfOak
	goto ProfOak_EventScript_AskRatePokedex
	end

PalletTown_ProfessorOaksLab_EventScript_GoTakePokeball::
	msgbox PalletTown_ProfessorOaksLab_Text_TakeMyPokemon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_TakeMyPokemon::
    .string "Oak: Now, {PLAYER}.\p"
    .string "Inside that Pokéball is\n"
    .string "one of my Pokémon.\p"
    .string "Please take good care of it!$"

PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon::
    .string "Oak: If a wild Pokémon appears,\n"
    .string "your Pokémon can battle it.\p"
    .string "With it at your side, you should be\n"
    .string "able to reach the next town.$"

PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow::
    .string "Oak: {PLAYER}, raise your young\n"
    .string "Pokémon by making it battle.\p"
    .string "It has to battle for it to grow.$"

PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait::
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait, MSGBOX_DEFAULT
	turnobject LOCALID_OAK, DIR_SOUTH
	release
	end

PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait::
    .string "Pokémon around the world wait for\n"
    .string "you, {PLAYER}!$"

EventScript_RegisterProfOak::
	msgbox MatchCall_Text_OakRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredOak, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_PROF_OAK
	setvar VAR_OAK_LAB_STATE, 9
	release
	end

ProfOak_EventScript_AskRatePokedex::
	msgbox gOakDexRatingText_GoodToSeeYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfOak_EventScript_DeclineRating
	call ProfOak_EventScript_RatePokedex
	release
	end

ProfOak_EventScript_DeclineRating::
	msgbox gOakDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfOak_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfOak_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gOakDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfOak_EventScript_ShowRatingMessage
	return

