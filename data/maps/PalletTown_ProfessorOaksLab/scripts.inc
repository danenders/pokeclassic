.set LOCALID_OAK, 1
.set LOCALID_BLUE, 2
.set LOCALID_POKEBALL, 3

@OAK LAB STATES:
@ 0:
@ 1: 
@ 2:
@ 3: 

PalletTown_ProfessorOaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
	.byte 0

PalletTown_ProfessorOaksLab_OnWarp:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene
	.2byte 0

PalletTown_ProfessorOaksLab_EventScript_SetPositionsForStarterScene::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_BLUE, DIR_NORTH
	end

PalletTown_ProfessorOaksLab_OnFrame:
	map_script_2 VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_GetStarterScene
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
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject LOCALID_BLUE, DIR_EAST
	setvar VAR_TEMP_1, 1
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu

PalletTown_ProfessorOaksLab_EventScript_PikachuAppears2::
	lockall
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	turnobject LOCALID_BLUE, DIR_EAST
	goto PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu

PalletTown_ProfessorOaksLab_EventScript_GetPartnerPikachu::
	applymovement LOCALID_OAK, Movement_OakStepBack
	waitmovement 1
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuBrokeFree, MSGBOX_DEFAULT
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox PalletTown_ProfessorOaksLab_Text_PikachuWantsToFollow, MSGBOX_DEFAULT
	waitmessage
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
	applymovement LOCALID_BLUE, Movement_RivalGoesToTable
	waitmovement 2
	turnobject LOCALID_BLUE, DIR_NORTH
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_BLUE, Common_Movement_WalkInPlaceFasterUp
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
	turnobject LOCALID_BLUE, DIR_SOUTH
	fadenewbgm MUS_RG_ENCOUNTER_RIVAL
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons, MSGBOX_DEFAULT
	waitmessage
	call_if_eq VAR_TEMP_1, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproach3
	waitmovement 2
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon, MSGBOX_DEFAULT
	applymovement LOCALID_BLUE, Movement_BlueLeavesAfterBattle
	playbgm MUS_RG_RIVAL_EXIT
	waitmovement 2
	playse SE_EXIT
	removeobject LOCALID_BLUE
	setflag FLAG_HIDE_BLUE_IN_LAB
	setvar VAR_OAK_LAB_STATE, 4
	fadedefaultbgm
	releaseall
	end

PalletTown_ProfessorOaksLab_EventScript_RivalApproach1::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepsAside1
	applymovement LOCALID_BLUE, Movement_RivalApproach
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach2::
	applymovement LOCALID_BLUE, Movement_RivalApproach
	return

PalletTown_ProfessorOaksLab_EventScript_RivalApproach3::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerStepsAside2
	applymovement LOCALID_BLUE, Movement_RivalApproach
	return

Movement_RivalApproach:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_PlayerStepsAside1:
	walk_right
	face_up
	step_end

Movement_PlayerStepsAside2:
	walk_left
	face_up
	step_end

Movement_BlueLeavesAfterBattle:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	step_end


PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons::
    .string "{RIVAL}: Wait, {PLAYER}!\n"
    .string "Let's check out our POKéMON!\p"
    .string "Come on, I'll take you on!$"

PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon::
    .string "{RIVAL}: Okay! I'll make my\n"
    .string "POKéMON battle to toughen it up!\p"
    .string "{PLAYER}! Gramps!\n"
    .string "Smell you later!$"

PalletTown_ProfessorOaksLab_EventScript_Rival::
	goto_if_eq VAR_OAK_LAB_STATE, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWaiting
	goto_if_eq VAR_OAK_LAB_STATE, 1, PalletTown_ProfessorOaksLab_EventScript_RivalNotGreedy
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
