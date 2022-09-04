.set LOCALID_OAK, 1
.set LOCALID_RIVAL, 2
.set LOCALID_POKEBALL, 3
.set LOCALID_POKEDEX_L, 7
.set LOCALID_POKEDEX_R, 8

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
	msgbox PalletTown_ProfessorOaksLab_Text_TakeStarter
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival
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
    .string "Oak: Be patient, {RIVAL}.\n"
    .string "You can have one, too!$"



PalletTown_ProfessorOaksLab_EventScript_PikachuAppears1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MovetoPikachu1
	turnobject LOCALID_RIVAL, DIR_EAST
	setvar VAR_TEMP_1, 1
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu

PalletTown_ProfessorOaksLab_EventScript_PikachuAppears2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_MovetoPikachu2
	turnobject LOCALID_RIVAL, DIR_EAST
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu

PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu::
	applymovement LOCALID_OAK, Movement_OakStepBack
	waitmovement 1
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree, MSGBOX_DEFAULT
	waitmessage
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	msgbox PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_RivalGetsEevee
	end

Movement_OakStepBack:
	walk_up
	face_down
	emote_exclamation_mark
	walk_in_place_faster_down
	step_end

Movement_MovetoPikachu1:
	walk_up
	face_up
	step_end

Movement_MovetoPikachu2:
	walk_left
	face_up
	step_end

PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree:
	.string "Oak: Incredible!\p"
	.string "The Pikachu from earlier broke\n"
	.string "free of its Pokéball!$"

PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow:
	.string "Oak: It seems to have taken quite\n"
	.string "an interest in you, {PLAYER}.\p"
	.string "I know! Why don't you take this\n"
	.string "Pokémon instead.\p"
	.string "{PLAYER} received the Pikachu\n"
    .string "from Prof. Oak!$"

PalletTown_ProfessorOaksLab_Text_WhyNotGiveNicknameToMon:
	.string "Oak: Say, why don't you give\n"
	.string "a nickname to that Pikachu?$"

PalletTown_ProfessorOaksLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletTown_ProfessorOaksLab_EventScript_RivalGetsEevee
	end

PalletTown_ProfessorOaksLab_EventScript_RivalGetsEevee::
	applymovement LOCALID_RIVAL, Movement_RivalGoesToTable
	waitmovement 2
	turnobject LOCALID_RIVAL, DIR_NORTH
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	removeobject LOCALID_POKEBALL
	setflag FLAG_HIDE_OAK_LAB_POKEBALL
	setvar VAR_OAK_LAB_STATE, 3
	releaseall
	end

Movement_RivalGoesToTable:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen::
    .string "{RIVAL}: I'll take this one, then!$"

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
    .string "Let's check out our POKéMON!\p"
    .string "Come on, I'll take you on!$"

PalletTown_ProfessorOaksLab_Text_RivalDefeated::
    .string "{RIVAL}: WHAT?\n"
    .string "Unbelievable!\l"
    .string "I picked the wrong POKéMON!$"

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
    .string "POKéMON battle to toughen it up!\p"
    .string "{PLAYER}! Gramps!\n"
    .string "Smell you later!$"

PalletTown_ProfessorOaksLab_EventScript_PostRivalBattle::
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
	@TODO: Register Oak in Match Call
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
	msgbox PalletTown_ProfessorOaksLab_Text_CedarRunsErrands
	release
	end

PalletTown_ProfessorOaksLab_Text_CedarRunsErrands::
    .string "Cedar is the newest aide in the lab,\n"
    .string "so she is always out running errands.$"

PalletTown_ProfessorOaksLab_EventScript_Cedar::
	lock
	faceplayer
	msgbox PalletTown_ProfessorOaksLab_Text_JustJoined
	setflag FLAG_MET_CEDAR
	release
	end

PalletTown_ProfessorOaksLab_Text_JustJoined::
    .string "Cedar: Hello. Nice to meet you!\n"
    .string "I recently joined Professor Oak's\l"
    .string "team.\p"
    .string "I'm excited to work with everyone.\p"

PalletTown_ProfessorOaksLab_EventScript_Pokedex::
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia::
    .string "It's like an encyclopedia, but the\n"
    .string "pages are blank.$"

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
	msgbox PalletTown_ProfessorOaksLab_Text_TakeMyPokemon
	release
	end

PalletTown_ProfessorOaksLab_Text_TakeMyPokemon::
    .string "Oak: Now, {PLAYER}.\p"
    .string "Inside that Pokéball is\n"
    .string "one of my Pokémon.\p"
    .string "Please take good care of it!$"

PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon
	release
	end

PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon::
    .string "Oak: If a wild Pokémon appears,\n"
    .string "your Pokémon can battle it.\p"
    .string "With it at your side, you should be\n"
    .string "able to reach the next town.$"

PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow
	release
	end

PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow::
    .string "Oak: {PLAYER}, raise your young\n"
    .string "Pokémon by making it battle.\p"
    .string "It has to battle for it to grow.$"

PalletTown_ProfessorOaksLab_EventScript_OakMonsAroundWorldWait::
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait
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
