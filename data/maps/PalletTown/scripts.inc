.set LOCALID_MOM, 1

PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PalletTown_OnResume
	.byte 0

PalletTown_OnTransition:
	setflag FLAG_VISITED_PALLET_TOWN
	call_if_eq VAR_SECRET_BATTLE_CLEAR, 3, EventScript_UpdatePostgame
	call_if_eq VAR_OAK_LAB_STATE, 7, EventScript_UpdateOakLabState
	call Common_EventScript_GetDayOrNight
	end

PalletTown_OnResume:
	call Common_EventScript_GetDayOrNight
	end

EventScript_UpdatePostgame::
	setvar VAR_SECRET_BATTLE_CLEAR, 4
	setflag FLAG_HIDE_PALLET_BILL
	return

EventScript_UpdateOakLabState::
	setvar VAR_OAK_LAB_STATE, 8
	return

PalletTown_EventScript_PokenavSceneStart1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 1
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 2
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 3
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavSceneStart4::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 4
	goto PalletTown_EventScript_PokenavSceneStartFar

PalletTown_EventScript_PokenavSceneStart5::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setvar VAR_TEMP_1, 5
	goto PalletTown_EventScript_PokenavSceneStartFar

PalletTown_EventScript_MomEntersFromDoor::
	opendoor 6,7
	playse SE_DOOR
	waitdooranim
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	closedoor 6,7
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomApproach1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomApproach2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomApproach3
	return

PalletTown_EventScript_PokenavSceneStartFar::
	setobjectxyperm LOCALID_MOM, 11, 7
	goto PalletTown_EventScript_PokenavScene

PalletTown_EventScript_PokenavScene::
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_MomEntersFromDoor
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomApproach4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomApproach5
	msgbox PalletTown_Text_DidYouMeetOak, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, Common_Movement_Heart
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 1
	msgbox PalletTown_Text_WhatACutePokemon, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_Text_ReceivedPokeGear
	waitmessage
	waitfanfare
	msgbox PalletTown_Text_CallMeSometime, MSGBOX_DEFAULT
	closemessage
	delay 30
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_PokenavMomExit1
	call_if_eq VAR_TEMP_1, 2, PalletTown_EventScript_PokenavMomExit2
	call_if_eq VAR_TEMP_1, 3, PalletTown_EventScript_PokenavMomExit3
	call_if_eq VAR_TEMP_1, 4, PalletTown_EventScript_PokenavMomExit4
	call_if_eq VAR_TEMP_1, 5, PalletTown_EventScript_PokenavMomExit5
	waitmovement 1
	call_if_le VAR_TEMP_1, 3, PalletTown_EventScript_PokenavSceneExitDoor
	removeobject LOCALID_MOM
	setflag FLAG_HIDE_MOM_PALLET_TOWN
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setvar VAR_ADVENTURE_BEGINS, 4
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

PalletTown_Text_DidYouMeetOak:
	.string "Mom: {PLAYER}!\p"
	.string "Did you meet with Professor Oak?$"

PalletTown_Text_WhatACutePokemon:
	.string "Oh! What an adorable Pokémon!\n"
	.string "You got it from Prof. Oak? How nice!\p"
	.string "And now you're on your way up to \n"
	.string "Viridian City?\p"
	.string "Well, I guess everyone dreams of\n"
	.string "traveling. At least it said so on TV.\p"
	.string "In that case, you wouldn't want to leave\n"
	.string "without your PokéGear, would you?$"

PalletTown_Text_CallMeSometime:
	.string "Your PokéGear has a map app, so\n"
	.string "you should never get lost.\p"
	.string "I already registered my number\n"
	.string "in your Cell Phone, too.\p"
	.string "Don't forget about your mom during\n"
	.string "your adventures. Call me sometime!$"

PalletTown_Text_ReceivedPokeGear:
	.string "{PLAYER} received the PokéGear\n"
    .string "from Mom!$"

PalletTown_EventScript_PokenavSceneExitDoor::
	applymovement LOCALID_MOM, Movement_MomExitDoor
	waitmovement 1
	closedoor 6,7
	playse SE_EXIT
	return

Movement_MomExitDoor:
	walk_up
	step_end

PalletTown_EventScript_PokenavMomApproach1::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav1
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Movement_MomApproachPokenav1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end

PalletTown_EventScript_PokenavMomApproach2::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav2
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomApproach3::
	applymovement LOCALID_MOM, Movement_MomApproachPokenav3
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomApproach4::
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, Movement_MomApproachPokenav4
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

Movement_MomApproachPokenav4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	face_left
	step_end

PalletTown_EventScript_PokenavMomApproach5::
	clearflag FLAG_HIDE_MOM_PALLET_TOWN
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, Movement_MomApproachPokenav5
	waitmovement 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

Movement_MomApproachPokenav5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_right
	step_end

PalletTown_EventScript_PokenavMomExit1::
	applymovement LOCALID_MOM, Movement_MomExitPokenav1
	waitmovement 1
	opendoor 6, 7
	waitdooranim
	return

Movement_MomExitPokenav1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit2::
	applymovement LOCALID_MOM, Movement_MomExitPokenav2
	return

Movement_MomExitPokenav2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit3::
	applymovement LOCALID_MOM, Movement_MomExitPokenav3
	return

Movement_MomExitPokenav3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PalletTown_EventScript_PokenavMomExit4::
	applymovement LOCALID_MOM, Movement_MomExitPokenav4
	return

Movement_MomExitPokenav4:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_EventScript_PokenavMomExit5::
	applymovement LOCALID_MOM, Movement_MomExitPokenav5
	return

Movement_MomExitPokenav5:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
	end

PalletTown_Text_TownSign::
    .string "Pallet Town\n"
    .string "Shades of your journey await!$"

PalletTown_EventScript_TrainerTips::
	lockall
	msgbox PalletTown_Text_PressStartToOpenMenu, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_Text_PressStartToOpenMenu::
	.string "Trainer Tips:\p"
	.string "Press Start to open the Menu!$"

PalletTown_EventScript_OaksLabSign::
	lockall
	msgbox PalletTown_Text_OakPokemonResearchLab, MSGBOX_SIGN
	releaseall
	end

PalletTown_Text_OakPokemonResearchLab::
    .string "Oak Pokémon Research Lab$"

PalletTown_EventScript_Lady::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEMON_GET, PalletTown_EventScript_SignLady
	msgbox PalletTown_Text_RaisingMonsToo, MSGBOX_DEFAULT
	release
	end

PalletTown_Text_RaisingMonsToo::
    .string "I'm raising Pokémon, too.\p"
    .string "When they get strong, they can\n"
    .string "protect me.$"

PalletTown_EventScript_SignLady::
	msgbox PalletTown_Text_SignsAreUsefulArentThey, MSGBOX_DEFAULT
	release
	end

PalletTown_Text_SignsAreUsefulArentThey::
	.string "Signs are useful, aren't they?$"
	.string "You can learn quite a lot from\n"
	.string "those Trainer Tips signs!$"

PalletTown_EventScript_FatMan::
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
	end

PalletTown_Text_CanStoreItemsAndMonsInPC::
    .string "Technology is incredible!\p"
    .string "You can now store and recall items\n"
    .string "and Pokémon as data via PC.$"

PalletTown_EventScript_PlayersHouseSign::
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
	end

PalletTown_Text_PlayersHouse::
    .string "{PLAYER}'s house$"

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
	end

PalletTown_Text_RivalsHouse::
    .string "{RIVAL}'s house$"
