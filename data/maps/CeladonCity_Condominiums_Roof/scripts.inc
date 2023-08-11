.set LOCALID_ROCKET, 5
.set LOCALID_JESSIE, 4
.set LOCALID_JAMES,  3
.set LOCALID_PLANS,  2

CeladonCity_Condominiums_Roof_MapScripts::
	.byte 0

CeladonCity_Condominiums_Roof_EventScript_Sign::
	msgbox CeladonCity_Condominiums_Roof_Text_IKnowEverything, MSGBOX_SIGN
	end

CeladonCity_Condominiums_Roof_Text_IKnowEverything::
    .string "I Know EVERYTHING!$"

CeladonCity_Condominiums_Roof_EventScript_Girl::
	goto_if_set FLAG_GOT_ROCKET_PLANS, CeladonCity_Condominiums_Roof_EventScript_SpyMovie
	msgbox CeladonCity_Condominiums_Roof_Text_SawAStrangeMan, MSGBOX_NPC
	end

CeladonCity_Condominiums_Roof_Text_SawAStrangeMan::
	.string "I saw a strange man drop something\n"
	.string "in the bushes back there.\p"
	.string "He looked like one of those Rockets!$"

CeladonCity_Condominiums_Roof_EventScript_SpyMovie::
	msgbox CeladonCity_Condominiums_Roof_Text_SpyMovie, MSGBOX_NPC
	end

CeladonCity_Condominiums_Roof_Text_SpyMovie::
	.string "Whoa, it really was a Rocket dropoff?\p"
	.string "I feel like I'm in a spy movie!$"

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger1::
	lock
	setobjectxyperm LOCALID_ROCKET, 8, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger2::
	lock
	setobjectxyperm LOCALID_ROCKET, 9, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end

CeladonCity_Condominiums_Roof_EventScript_RocketTrigger3::
	lock
	setobjectxyperm LOCALID_ROCKET, 10, 16
	goto CeladonCity_Condominiums_Roof_EventScript_Rocket
	end


CeladonCity_Condominiums_Roof_EventScript_Rocket::
	clearflag FLAG_HIDE_CELADON_ROOFTOP_ROCKET
	addobject LOCALID_ROCKET
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_ROCKET, Movement_ApproachPlayerRooftop
	waitmovement 5
	playse SE_PIN
	applymovement LOCALID_ROCKET, Common_Movement_ExclamationMark
	waitse
	trainerbattle_single TRAINER_ROOFTOP_ROCKET_GRUNT, RooftopRocket_Intro, RooftopRocket_Defeat, CeladonCity_Condominiums_Roof_EventScript_RocketFlee
	end

Movement_ApproachPlayerRooftop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RooftopRocket_Intro::
	.string "Rocket: Hey, Kid.\p"
	.string "I'm just enjoying a smoke break.\n"
	.string "Definitely not doing anything shady.\p"
	.string "What? You don't believe me?\n"
	.string "Fine, I'll make you believe me!$"

RooftopRocket_Defeat::
	.string "I didn't do anything wrong!\n"
	.string "You don't have any proof!$"

CeladonCity_Condominiums_Roof_EventScript_RocketFlee::
	msgbox RooftopRocket_PostBattle, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROCKET
	setvar VAR_ROOFTOP_ROCKET_PLANS, 1
	playse SE_FLEE
	waitse
	delay 8
	fadescreen FADE_FROM_BLACK
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

RooftopRocket_PostBattle::
	.string "I don't have time to be messing\n"
	.string "around battling kids.\p"
	.string "You didn't see anything, got that?\p"
	.string "And don't go poking around those\n"
	.string "bushes back there.$"

CeladonCity_Condominiums_Roof_EventScript_RocketPlans::
	msgbox CeladonCity_Condominiums_Roof_Text_RocketPlans
	removeobject LOCALID_PLANS
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_ROCKET_PLANS, 1
	message CeladonCity_Condominiums_Roof_Text_ObtainRocketPlans
	waitfanfare
	waitmessage
	closemessage
	goto_if_eq VAR_ROOFTOP_ROCKET_PLANS, 2, CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle2
	release
	end

CeladonCity_Condominiums_Roof_Text_RocketPlans::
	.string "It's a suspicious looking bag...\p"
	.string "It's full of messages from Team\n"
	.string "Rocket!$"

CeladonCity_Condominiums_Roof_Text_ObtainRocketPlans::
	.string "{PLAYER} found the Rocket Plans!$"

CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle2::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	clearflag FLAG_HIDE_CELADON_ROOFTOP_JESSIE_JAMES
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox CeladonCity_Condominiums_Roof_Text_LookWhoItIs, MSGBOX_AUTOCLOSE
	applymovement LOCALID_JESSIE, Movement_BlockPlayerEscape
	applymovement LOCALID_JAMES, Movement_BlockPlayerEscape
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_EAST
	waitmovement 4
	goto PokemonTower_7F_EventScript_JessieJamesBattle
	end

CeladonCity_Condominiums_Roof_EventScript_JessieJamesBattle::
	trainerbattle_double TRAINER_POKEMON_TOWER_JESSIE_JAMES CeladonCity_Condominiums_Roof_Text_RocketDuoIntro, CeladonCity_Condominiums_Roof_Text_RocketDuoDefeat, Text_NeedTwoMons, CeladonCity_Condominiums_Roof_EventScript_RocketDuoDefeated, NO_MUSIC
	end

CeladonCity_Condominiums_Roof_Text_LookWhoItIs::
	.string "James: Well, look who it is.\n"
	.string "Jessie: Of course it's this twerp.$"

Movement_BlockPlayerEscape:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

	.string "James: How did you know about our\n"
	.string "secret drop off spot? It's secret!\p"
	.string "Jessie: Someone in the base must have\n"
	.string "talked!\p"
	.string ""

CeladonCity_Condominiums_Roof_Text_RocketDuoIntro::
	.string "Jessie: How did you know about our\n"
	.string "secret drop off point?\p"
	.string "James: Yeah, the point of it is that\n"
	.string "it's a secret!\p"
	.string "Jessie: Well, I guess we'll just have\n"
	.string "to make sure it stays a secret!$"


CeladonCity_Condominiums_Roof_Text_RocketDuoDefeat::
	.string "Jessie: You're really starting\n"
	.string "to annoy me, twerp!\p"
	.string "James: How does this keep happening!?$"

CeladonCity_Condominiums_Roof_EventScript_RocketDuoDefeated::
	msgbox CeladonCity_Condominiums_Roof_Text_RocketDuoDefeated, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JAMES
	removeobject LOCALID_JESSIE
	setvar VAR_ROOFTOP_ROCKET_PLANS, 3
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

CeladonCity_Condominiums_Roof_Text_RocketDuoDefeated::
	.string "Jessie: Looks like we're blasting off!\n"
	.string "James: Looks like we're blasting off!$"
