.set LOCALID_MOM, 1

PalletTown_PlayersHouse_1F_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EvenScripts_Mom::
	lock
	faceplayer
	goto_if_le VAR_ADVENTURE_BEGINS, 2, PalletTown_PlayersHouse_1F_EventScript_BetterHurry
	goto_if_eq VAR_ADVENTURE_BEGINS, 3, PlayersHouse_1F_EventScript_PokenavScene
	goto PalletTown_PlayersHouse_1F_EventScript_MomHeal
	end

PalletTown_PlayersHouse_1F_EventScript_BetterHurry::
	msgbox PalletTown_PlayersHouse_1F_Text_BetterHurry, MSGBOX_DEFAULT
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_BetterHurry:
	.string "Mom: You don't want to miss\n"
	.string "Professor Oak!\p"
	.string "You better hurry!$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
    .string "There's a movie on TV.\n"
    .string "Four boys are walking on railroad\l"
    .string "tracks.\p"
    .string "…I better go, too.$"

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
	
PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "Running Shoes.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your Running Shoes.\p"
	.string "Lace up your Running Shoes and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_EventScript_PokenavScene::
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
	setflag FLAG_SYS_POKENAV_GET
	setvar VAR_ADVENTURE_BEGINS, 4
	turnobject LOCALID_MOM, DIR_WEST
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	turnobject LOCALID_MOM, DIR_WEST
	release
	end

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
    .string "Mom: {PLAYER}!\n"
    .string "You should take a quick rest.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
    .string "Mom: Oh, good! You and your\n"
    .string "Pokémon are looking great.\l"
    .string "Take care now!$"

PlayersHouse_1F_EventScript_GameclearTrigger1::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_GameclearTrigger2::
	setvar VAR_TEMP_1, 2
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	goto PlayersHouse_1F_EventScript_Gameclear

PlayersHouse_1F_EventScript_Gameclear::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToStairs1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToStairs2
	waitmovement 1
	msgbox PlayersHouse_1F_Text_Gameclear, MSGBOX_DEFAULT
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox PlayersHouse_1F_Text_FollowerOptions, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	msgbox PlayersHouse_1F_Text_Gameclear2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_Heart
	waitmovement 1
	waitse
	call_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_MoveMomToTable1
	call_if_eq VAR_TEMP_1, 2, PlayersHouse_1F_EventScript_MoveMomToTable2
	waitmovement 1
	setvar VAR_ADVENTURE_BEGINS, 8
	releaseall
	end

PlayersHouse_1F_Text_Gameclear::
	.string "Mom: Oh, {PLAYER}!\n"
	.string "You're already up?\p"
	.string "After everything you've been doing\n"
	.string "I thought you'd need more rest.\p"
	.string "...\p"
	.string "You've really grown up, {PLAYER}.\p"
	.string "I think your Pokémon can see that, too.\p"
	.string "They'll follow you anywhere!$"

PlayersHouse_1F_Text_FollowerOptions::
	.string "Your Follower settings in the Options\n"
	.string "menu can now be set to Any mode!\p"
	.string "When this is selected, your first\n"
	.string "Pokémon will follow you around!$"

PlayersHouse_1F_Text_Gameclear2::
	.string "Mom: Just because you're the new\n"
	.string "champion doesn't mean your story\l"
	.string "is over!\p"
	.string "There's a whole world out there\n"
	.string "for you and your Pokémon to explore!\p"
	.string "I'm so proud of you, {PLAYER}!\n"
	.string "Go have fun with your Pokémon!$"

PlayersHouse_1F_EventScript_MoveMomToStairs1::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs1
	return

PlayersHouse_1F_EventScript_MoveMomToStairs2::
	applymovement LOCALID_MOM, Movement_MoveMomToStairs2
	return

PlayersHouse_1F_EventScript_MoveMomToTable1::
	applymovement LOCALID_MOM, Movement_MoveMomToTable1
	return

PlayersHouse_1F_EventScript_MoveMomToTable2::
	applymovement LOCALID_MOM, Movement_MoveMomToTable2
	return

Movement_MoveMomToStairs1::
	walk_up
	walk_up
	face_right
	step_end

Movement_MoveMomToStairs2::
	walk_right
	walk_right
	face_up
	step_end

Movement_MoveMomToTable1::
	walk_down
	walk_down
	face_left
	step_end

Movement_MoveMomToTable2::
	walk_left
	walk_left
	step_end
