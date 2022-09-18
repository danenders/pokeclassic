.set LOCALID_GRUNT1, 1
.set LOCALID_GRUNT2, 2
.set LOCALID_GRUNT3, 3
.set LOCALID_JESSIE, 4
.set LOCALID_JAMES,  5

PokemonTower_7F_MapScripts::
	.byte 0

PokemonTower_7F_EventScript_MrFuji::
    lock
    faceplayer
    setflag FLAG_HIDE_POKEMON_TOWER_FUJI
    clearflag FLAG_HIDE_POKEHOUSE_FUJI
    setflag FLAG_RESCUED_MR_FUJI
    msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe, MSGBOX_DEFAULT
    goto_if_unset FLAG_DELIVERED_ROCKET_PLANS, PokemonTower_7F_EventScript_JessieJamesSecretBattle3
    goto PokemonTower_7F_EventScript_MrFujiExit
    release
    end

PokemonTower_7F_Text_MrFujiThankYouFollowMe::
    .string "Mr. Fuji: Heh?\n"
    .string "You came to save me?\p"
    .string "Thank you. But, I came here of my\n"
    .string "own free will.\p"
    .string "I came to calm the spirit of\n"
    .string "Cubone's mother.\p"
    .string "I think Marowak's spirit has\n"
    .string "finally left us.\p"
    .string "I must thank you for your kind\n"
    .string "concern.\p"
    .string "Follow me to my home, Pokémon\n"
    .string "House, at the foot of this tower.$"

PokemonTower_7F_EventScript_MrFujiExit::
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	clearflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	setvar VAR_POKEMON_TOWER_STATE, 3
	warp MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, 4, 6
	waitstate
	release
	end

PokemonTower_7F_EventScript_JessieJamesSecretBattle3::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	setflag FLAG_SYS_FORCE_LOAD_OFFSCREEN_OBJ
	clearflag FLAG_HIDE_POKEMON_TOWER_JESSIE_JAMES
	msgbox PokemonTower_7F_Text_HoldItKid, MSGBOX_AUTOCLOSE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject OBJ_EVENT_ID_FOLLOWER, DIR_SOUTH
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	addobject LOCALID_JESSIE
	addobject LOCALID_JAMES
	applymovement LOCALID_JESSIE, Movement_RocketDuoEnters
	applymovement LOCALID_JAMES, Movement_RocketDuoEnters
	waitmovement 4
	goto PokemonTower_7F_EventScript_JessieJamesBattle
	end

PokemonTower_7F_EventScript_JessieJamesBattle::
	trainerbattle_double TRAINER_POKEMON_TOWER_JESSIE_JAMES PokemonTower_7F_RocketDuoIntro, PokemonTower_7F_RocketDuoDefeat, Text_NeedTwoMons, PokemonTower_7F_EventScript_RocketDuoDefeated, NO_MUSIC
	end

PokemonTower_7F_Text_HoldItKid::
	.string "Jessie: Stop right there, twerp.$"

Movement_RocketDuoEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonTower_7F_RocketDuoIntro::
	.string "James: We chased you all the way\n"
	.string "from Celadon to get those plans back!\p"
	.string "Jessie: You should have turned them\n"
	.string "to the International Police while you\l"
	.string "had the chance.\p"
	.string "James: We'll be taking those back now!$"

PokemonTower_7F_RocketDuoDefeat::
    .string "Jessie: You brat!\n"
    .string "James: You'll regret this!$"

PokemonTower_7F_EventScript_RocketDuoDefeated::
	msgbox PokemonTower_7F_Text_RocketDuoDefeated, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	playse SE_FLEE
	waitse
	removeobject LOCALID_JESSIE
	removeobject LOCALID_JAMES
	fadescreen FADE_FROM_BLACK
	fadeinbgm 0
	msgbox PokemonTower_7F_Text_LetsGoToHouse, MSGBOX_AUTOCLOSE
	goto PokemonTower_7F_EventScript_MrFujiExit
	end

PokemonTower_7F_Text_RocketDuoDefeated::
    .string "Jessie: Ugh! Seriously? Again?\p"
    .string "James: Looks like our chance to\n"
    .string "retrieve the plans is a bust, then...\p"
    .string "Jessie: Don't you think I know that?\n"
    .string "Whatever, if this twerp hasn't turned\l"
    .string "the plans into the International Police\l"
    .string "yet, that means we still have time to go\l"
    .string "help with the take-over in Saffron City.\p"
    .string "Jessie & James: Looks like Team Rocket's\n"
    .string "blasting off again!$"

PokemonTower_7F_Text_LetsGoToHouse::
	.string "Mr. Fuji: Well, that was certainly\n"
	.string "unexpected.\p"
	.string "Let's get back to my house before\n"
	.string "any more Rockets show up...$"

PokemonTower_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_19, PokemonTower_7F_Text_Grunt1Intro, PokemonTower_7F_Text_Grunt1Defeat, PokemonTower_7F_EventScript_DefeatedGrunt1
	msgbox PokemonTower_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_EventScript_DefeatedGrunt1::
	msgbox PokemonTower_7F_Text_Grunt1PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitMid
	compare VAR_0x8004, 11
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt1ExitLeft
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitMid::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitMid
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitRight::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_EventScript_Grunt1ExitLeft::
	applymovement LOCALID_GRUNT1, PokemonTower_7F_Movement_Grunt1ExitLeft
	waitmovement 0
	playse SE_EXIT
	delay 25
	goto PokemonTower_7F_EventScript_RemoveGrunt1
	end

PokemonTower_7F_Text_Grunt1Intro::
    .string "What do you want?\n"
    .string "Why are you here?$"

PokemonTower_7F_Text_Grunt1Defeat::
    .string "I give up!$"

PokemonTower_7F_Text_Grunt1PostBattle::
    .string "I'm not going to forget this!$"

PokemonTower_7F_EventScript_RemoveGrunt1::
	removeobject LOCALID_GRUNT1
	release
	end

PokemonTower_7F_Movement_Grunt1ExitMid::
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt1ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PokemonTower_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_20, PokemonTower_7F_Text_Grunt2Intro, PokemonTower_7F_Text_Grunt2Defeat, PokemonTower_7F_EventScript_DefeatedGrunt2
	msgbox PokemonTower_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt2Intro::
    .string "This old guy marched right up to\n"
    .string "our Hideout.\p"
    .string "Then, he starts ranting about how\n"
    .string "Team Rocket's abusing Pokémon.\p"
    .string "So, we're just talking it over as\n"
    .string "adults.$"

PokemonTower_7F_Text_Grunt2Defeat::
    .string "Please!\n"
    .string "No more!$"

PokemonTower_7F_Text_Grunt2PostBattle::
    .string "Pokémon are only good for making\n"
    .string "money. Why not use them?\p"
    .string "You stay out of our business!$"

PokemonTower_7F_EventScript_DefeatedGrunt2::
	msgbox PokemonTower_7F_Text_Grunt2PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 12
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitLeft
	compare VAR_0x8004, 13
	goto_if_eq PokemonTower_7F_EventScript_Grunt2ExitRight
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitLeft::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_Grunt2ExitRight::
	applymovement LOCALID_GRUNT2, PokemonTower_7F_Movement_Grunt2ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt2
	end

PokemonTower_7F_EventScript_RemoveGrunt2::
	removeobject LOCALID_GRUNT2
	release
	end

PokemonTower_7F_Movement_Grunt2ExitLeft::
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt2ExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_21, PokemonTower_7F_Text_Grunt3Intro, PokemonTower_7F_Text_Grunt3Defeat, PokemonTower_7F_EventScript_DefeatedGrunt3
	msgbox PokemonTower_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_7F_Text_Grunt3Intro::
    .string "You're not saving anyone, kid!$"

PokemonTower_7F_Text_Grunt3Defeat::
    .string "Don't fight us Rockets!$"

PokemonTower_7F_Text_Grunt3PostBattle::
    .string "You're not getting away with this!$"

PokemonTower_7F_EventScript_DefeatedGrunt3::
	msgbox PokemonTower_7F_Text_Grunt3PostBattle
	closemessage
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 10
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitRight
	compare VAR_0x8004, 9
	goto_if_eq PokemonTower_7F_EventScript_Grunt3ExitLeft
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3Exit
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitRight::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitRight
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_Grunt3ExitLeft::
	applymovement LOCALID_GRUNT3, PokemonTower_7F_Movement_Grunt3ExitLeft
	waitmovement 0
	goto PokemonTower_7F_EventScript_RemoveGrunt3
	end

PokemonTower_7F_EventScript_RemoveGrunt3::
	removeobject LOCALID_GRUNT3
	release
	end

PokemonTower_7F_EventScript_Unused::
	release
	end

PokemonTower_7F_Movement_Grunt3ExitRight::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3Exit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_Grunt3ExitLeft::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
