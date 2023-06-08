.set LOCALID_JENNY, 5
.set LOCALID_SLOWBRO, 9
.set LOCALID_LASS, 4
.set LOCALID_RIVAL, 10
.set LOCALID_TMBALL, 12
.set LOCALID_GRUNT, 6
.set LOCALID_BULBASAUR, 14
.set LOCALID_BREEDER, 13

CeruleanCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCity_OnResume
	.byte 0

CeruleanCity_OnTransition:
	setflag FLAG_VISITED_CERULEAN_CITY
	call_if_set FLAG_SYS_GAME_CLEAR, CeruleanCity_EventScript_ClearCeruleanCaveGuard
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	call_if_set FLAG_GOT_BULBASAUR,  CeruleanCity_EventScript_MoveBreederInside
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_ClearCeruleanCaveGuard::
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	return

CeruleanCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_JENNY, 30, 12
	setobjectxyperm LOCALID_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_LASS, 27, 31
	return

CeruleanCity_EventScript_MoveBreederInside::
	clearflag FLAG_HIDE_CERULEAN_BREEDER
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_Text_CitySign::
    .string "Cerulean City\n"
    .string "A Mysterious, Blue Aura Surrounds\l"
    .string "It$"

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_Text_TrainerTipsHeldItems::
    .string "Trainer Tips:\p"
    .string "A Pokémon can be made to hold\n"
    .string "an item.\p"
    .string "Some items can even be used by\n"
    .string "the holding Pokémon in battle.$"

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_Text_BikeShopSign::
    .string "Grass and caves handled easily!\n"
    .string "Bike Shop$"

CeruleanCity_EventScript_GymSign::
	lockall
	msgbox CeruleanCity_Text_GymSign, MSGBOX_SIGN
	releaseall
	end

CeruleanCity_Text_GymSign::
    .string "Cerulean City Pokémon Gym\n"
    .string "Leader: Misty\l"
    .string "The Tomboyish Mermaid!$"

CeruleanCity_EventScript_Police::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_JENNY, DIR_SOUTH
	release
	end

CeruleanCity_Text_PeopleHereWereRobbed::
    .string "The people here were robbed.\p"
    .string "It's obvious that Team Rocket is\n"
    .string "behind this most heinous crime!\p"
    .string "Our Police Force is having\n"
    .string "trouble with the Rockets, so\l"
    .string "we asked for help from the\l"
    .string "International Police!$"

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
    .string "If that Slowbro wasn't there, you\n"
    .string "could Cut down the small tree.\p"
    .string "That way, you could get to the\n"
    .string "other side.\p"
    .string "I think there's a way around it,\n"
    .string "though.$"

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_YouCanCutDownSmallTrees::
    .string "Did you know that you can Cut down\n"
    .string "small trees?\p"
    .string "Even that small tree in front of\n"
    .string "the shop can be Cut down.\p"
    .string "I think there's a way around it,\n"
    .string "though.$"

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_Text_PokemonEncyclopediaAmusing::
    .string "You're making an encyclopedia on\n"
    .string "Pokémon? That sounds amusing.$"

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
    .string "You're a Trainer, too?\p"
    .string "Collecting, battling…\n"
    .string "It's a tough life, isn't it?$"

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	turnobject LOCALID_WOMAN, DIR_NORTH
	release
	end

CeruleanCity_Text_WantBrightRedBicycle::
    .string "I want a bright red bicycle.\p"
    .string "I'll keep it at home, so it won't\n"
    .string "get dirty.$"

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_Text_ThisIsCeruleanCave::
    .string "This is Cerluean Cave.\p"
    .string "Very strong Pokémon live inside\n"
    .string "there.\p"
    .string "It takes a very special Trainer to\n"
    .string "be allowed inside there.\p"
    .string "How strong?\n"
    .string "Hmm....\p"
    .string "I'd say only someone could\n"
    .string "become the Pokémon League\l"
    .string "Champion could handle it.$"

CeruleanCity_EventScript_Lass::
	lock
	random 3
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_SlowbroLass1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_SlowbroLass2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_SlowbroLass3
	end

CeruleanCity_Slowbro::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 40
	playse SE_PIN
	applymovement LOCALID_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 9
	delay 30
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

CeruleanCity_EventScript_SlowbroLass1::
	msgbox CeruleanCity_Text_SlowbroUseSonicboom, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_SlowbroPayAttention, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroUseSonicboom::
    .string "Okay! Slowbro!\n"
    .string "Use Sonic Boom!$"

CeruleanCity_Text_SlowbroPayAttention::
    .string "Come on, Slowbro, pay attention!$"

CeruleanCity_EventScript_SlowbroLass2::
	msgbox CeruleanCity_Text_SlowbroPunch, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_NoYouBlewItAgain, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroPunch::
    .string "Slowbro, punch!$"

CeruleanCity_Text_NoYouBlewItAgain::
    .string "No!\n"
    .string "You blew it again!$"

CeruleanCity_EventScript_SlowbroLass3::
	msgbox CeruleanCity_Text_SlowbroWithdraw, MSGBOX_DEFAULT
	call CeruleanCity_Slowbro
	msgbox CeruleanCity_Text_HardToControlMonsObedience, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroWithdraw::
    .string "Slowbro, WITHDRAW!$"

CeruleanCity_Text_HardToControlMonsObedience::
    .string "No! That's wrong!\n"
    .string "It's so hard to control Pokémon!\p"
    .string "Your Pokémon's obedience depends\n"
    .string "on your abilities as a trainer.$"

CeruleanCity_EventScript_Slowbro::
	lock
	random 4 
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_Slowbro1
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_Slowbro2
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_Slowbro3
	goto_if_eq VAR_RESULT, 3, CeruleanCity_EventScript_Slowbro4
	end

CeruleanCity_EventScript_Slowbro1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTookSnooze::
    .string "Slowbro took a snooze…$"

CeruleanCity_EventScript_Slowbro2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroLoafingAround::
    .string "Slowbro is loafing around…$"

CeruleanCity_EventScript_Slowbro3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroTurnedAway::
    .string "Slowbro turned away…$"

CeruleanCity_EventScript_Slowbro4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_SlowbroIgnoredOrders::
    .string "Slowbro ignored orders…$"

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	setvar VAR_ROUTE_22_RIVAL_STATE, 3
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	clearflag FLAG_HIDE_CERULEAN_RIVAL
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 10
	msgbox CeruleanCity_Text_RivalAppears, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_RIVAL_CERULEAN_CITY, CeruleanCity_Text_RivalIntro, CeruleanCity_Text_RivalDefeat, CeruleanCity_EventScript_RivalDefeated, NO_MUSIC
	end

CeruleanCity_EventScript_RivalDefeated::
	msgbox CeruleanCity_Text_RivalPostBattle, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor, MSGBOX_DEFAULT
	setvar VAR_RIVAL_CERULEAN_CITY, 1
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox CeruleanCity_Text_ObtainedPokeblockCase, MSGBOX_DEFAULT
	additem ITEM_POKEBLOCK_CASE
	waitfanfare
	msgbox CeruleanCity_Text_ExplainPokeblockSmellYa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 10
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_Text_RivalAppears::
    .string "{RIVAL}: Yo! {PLAYER}!\p"
    .string "You're still struggling along back\n"
    .string "here?\p"
    .string "I'm doing great! I caught a bunch\n"
    .string "of strong and smart Pokémon!$"

CeruleanCity_Text_RivalIntro::
    .string "Here, let me see what you caught,\n"
    .string "{PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
    .string "Hey!\n"
    .string "Take it easy!\l"
    .string "You won already!$"

CeruleanCity_Text_RivalPostBattle::
    .string "{RIVAL}: Hey, guess what?\p"
    .string "I went to Bill's and got him to\n"
    .string "show me his latest invention.\p"
    .string "It's really going to help add\n" 
    .string "a lot of pages to my Pokédex!\p"
    .string "After all, Bill's world famous as a\n"
    .string "PokéManiac.\p"
    .string "He invented the Pokémon Storage\n"
    .string "System on PC, too.\p"
    .string "Since you're using his system,\n"
    .string "you should go thank him.\p"
    .string "Well, I better get rolling!\n"
    .string "Smell ya later!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
    .string "Oh, yeah, right.\p"
    .string "My sister sent me a present, but\n"
    .string "she accidentally put two of these\l"
    .string "in the box.\p"
    .string "I don't need them both, so you can\n"
    .string "have one.\p"
    .string "No, really.\p"
    .string "I'll give it to you as a favor, since\n"
    .string "you're always plodding behind me.$"

CeruleanCity_Text_ObtainedPokeblockCase::
	.string "Obtained a PokéBlock Case!\p"
	.string "{PLAYER} put the PokéBlock Case\n"
	.string "in the Key Items pocket.$"

CeruleanCity_Text_ExplainPokeblockSmellYa::
    .string "A weakling like you…\n"
    .string "That thing's perfect.\p"
    .string "I don't need it because I don't\n"
    .string "give a hoot about Pokémon Contests.\p"
    .string "All right, this time I really am\n"
    .string "gone. Smell ya!$"

CeruleanCity_EventScript_RivalStartExit::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 10
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 10
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_fast_right
	walk_in_place_fast_right
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_fast_left
	walk_in_place_fast_left
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntIntro, CeruleanCity_Text_GruntDefeat, CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_Text_GruntIntro::
    .string "Hey! Stay out!\n"
    .string "It's not your yard!\p"
    .string "…Huh?\n"
    .string "Me?\p"
    .string "I'm an innocent bystander!\n"
    .string "Don't you believe me?$"

CeruleanCity_Text_GruntDefeat::
    .string "Grunt: Stop! I give up!\n"
    .string "I'll leave quietly!$"

CeruleanCity_EventScript_GruntDefeated::
	setvar VAR_CERULEAN_CITY_ROCKETS, 2
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_CERULEAN_ROCKET
	removeobject LOCALID_GRUNT
	clearflag FLAG_HIDE_CERULEAN_TM28
	addobject LOCALID_TMBALL
	fadescreen FADE_FROM_BLACK
	release
	end

CeruleanCity_Text_OkayIllReturnStolenTM::
    .string "…Fine! Here!\p"
    .string "I'm not going to prison\n"
    .string "over a some TM!$"

CeruleanCity_EventScript_StolenTM::
	lock
	checkitemspace ITEM_TM28, 1
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	setflag FLAG_HIDE_CERULEAN_TM28
	removeobject LOCALID_TMBALL
	playfanfare MUS_OBTAIN_TMHM
	msgbox CeruleanCity_Text_RecoveredStolenTM, MSGBOX_DEFAULT
	additem ITEM_TM28, 1
	setflag FLAG_RECOVERED_STOLEN_TM
	release
	end

CeruleanCity_Text_RecoveredStolenTM::
	.string "{PLAYER} recovered the stolen\n"
	.string "TM28!$"

CeruleanCity_EventScript_NoRoomForTM28::
	msgbox CeruleanCity_Text_MakeRoomForThis, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_MakeRoomForThis::
	.string "You don't have enough room.\n"
	.string "Better make some space!$"

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_Grunt
	end

CeruleanCity_EventScript_Bulbasaur::
	lock
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurHappy
	turnobject LOCALID_BULBASAUR, DIR_NORTH
	playmoncry SPECIES_BULBASAUR, CRY_MODE_NORMAL
	msgbox CeruleanCity_Text_Bulbasaur, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeruleanCity_Text_Bulbasaur:
	.string "Bulbasaur: ...grrr...$"

CeruleanCity_EventScript_BulbasaurHappy::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

CeruleanCity_EventScript_BulbasaurBreeder::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BULBASAUR, CeruleanCity_EventScript_ProudOfBulbasaur
	msgbox CeruleanCity_Text_BulbasaurDoesntTrustPeople, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_lt VAR_RESULT, 4, CeruleanCity_EventScript_BulbasaurStillNeedsTime
	call_if_eq VAR_FACING, DIR_NORTH, CeruleanCity_EventScript_BulbasaurApproachPlayerNear
	call_if_eq VAR_FACING, DIR_WEST, CeruleanCity_EventScript_BulbasaurApproachPlayerFar
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	delay 8
	playse SE_PIN
	applymovement LOCALID_BULBASAUR, Common_Movement_Heart
	waitmovement 14
	delay 8
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	turnobject LOCALID_BREEDER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_BREEDER, Common_Movement_ExclamationMark
	waitse
	waitmovement 13
	faceplayer
	msgbox CeruleanCity_Text_BulbasaurTrustsYou, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_BULBASAUR
	givemon SPECIES_BULBASAUR, 7, ITEM_NONE
	goto_if_eq VAR_RESULT, 0, CeruleanCity_EventScript_BulbasaurParty
	goto_if_eq VAR_RESULT, 1, CeruleanCity_EventScript_BulbasaurPC
	goto_if_eq VAR_RESULT, 2, CeruleanCity_EventScript_NoRoomForBulbasaur
	end

CeruleanCity_EventScript_BulbasaurApproachPlayerNear::
	applymovement LOCALID_BULBASAUR, Movement_BulbaNear
	waitmovement 14
	return

Movement_BulbaNear:
 	walk_down
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	walk_in_place_fast_right
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurApproachPlayerFar::
	applymovement LOCALID_BULBASAUR,  Movement_BulbaFar
	waitmovement 14
	return

Movement_BulbaFar:
 	walk_down
 	walk_right
 	walk_right
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	walk_in_place_fast_up
 	delay_16
 	step_end

CeruleanCity_EventScript_BulbasaurParty::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_GotBulbasaur
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_GetBulbasaur::
	playfanfare MUS_LEVEL_UP
	message CeruleanCity_EventScript_Text_BefriendedBulbasaur
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	return

CeruleanCity_EventScript_Text_BefriendedBulbasaur::
	.string "{PLAYER} befriended the Bulbasaur!$"

CeruleanCity_EventScript_GotBulbasaur::
	setflag FLAG_GOT_BULBASAUR
	removeobject LOCALID_BULBASAUR
	release
	end

CeruleanCity_EventScript_BulbasaurPC::
	call CeruleanCity_EventScript_GetBulbasaur
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_EventScript_TransferBulbasaur
	call Common_EventScript_NameReceivedBoxMon
	goto CeruleanCity_EventScript_TransferBulbasaur
	end

CeruleanCity_EventScript_TransferBulbasaur::
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	call Common_EventScript_TransferredToPC
	goto CeruleanCity_EventScript_GotBulbasaur
	end

CeruleanCity_EventScript_NoRoomForBulbasaur::
	msgbox CeruleanCity_Text_NoRoomForMorePokemon, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_NoRoomForMorePokemon::
    .string "Oh! You don't have room\n"
    .string "for any more Pokémon!$"

CeruleanCity_Text_BulbasaurDoesntTrustPeople::
	.string "This Bulbasaur was hurt trying\n"
	.string "to stop Team Rocket from\l"
	.string "kidnapping other Pokémon...\p"
	.string "I'm trying to get it to trust\n"
	.string "people again.$"

CeruleanCity_Text_BulbasaurTrustsYou::
	.string "Amazing! Wonderful!\p"
	.string "This Bulbasaur trusts you!\p"
	.string "Its opened its heart to\n"
	.string "people again...\p"
	.string "I think it wants to go with you.\p"
	.string "Alright! I trust you too!\p"
	.string "Please take good care of it!$"

CeruleanCity_EventScript_BulbasaurStillNeedsTime::
	turnobject LOCALID_BREEDER, DIR_WEST
	msgbox CeruleanCity_Text_BulbasaurNeedsTime, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_BulbasaurNeedsTime::
	.string "It still needs time, though.\p"
	.string "I don't blame it for holding\n"
	.string "a grudge. What Team Rocket did\l"
	.string "is unforgivable!$"

CeruleanCity_EventScript_ProudOfBulbasaur::
	msgbox CeruleanCity_Text_ProudOfBulbasaur, MSGBOX_DEFAULT
	release
	end

CeruleanCity_Text_ProudOfBulbasaur::
	.string "I'm very proud of Bulbasaur.\p"
	.string "It takes a lot of courage to\n"
	.string "trust others.$"

CeruleanCity_EventScript_BillCallsPlayer::
	lockall
	pokenavcall CeruleanCity_Text_DexNavCall
	setvar VAR_SEA_COTTAGE_STATE, 5
	release
	end

CeruleanCity_Text_DexNavCall::
	.string "???: Hey, is this {PLAYER}?\p"
	.string "Bill: Yeah, it's BilL!\p"
	.string "I had to email Prof. Oak for your\n"
	.string "number, I hope that's OK!\p"
	.string "My brain must have been a little\n"
	.string "scrambled from the teleporter\l"
	.string "after you rescued me - I totally\l"
	.string "forgot to show you something!\p"
	.string "Come back to the Sea Cottage\n"
	.string "sometime and I'll show you!$"

CeruleanCity_EventScript_Venusaurite::
	finditem ITEM_VENUSAURITE, 1
	release
	end
