.set LOCALID_FAT_MAN,   1
.set LOCALID_POLIWRATH, 2
.set LOCALID_FUGITIVE, 17

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CeladonCity_OnResume
	.byte 0

CeladonCity_OnTransition:
	setflag FLAG_VISITED_CELADON_CITY
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_OnResume:
	call Common_EventScript_GetDayOrNight
	end

CeladonCity_EventScript_ItemEther::
	finditem ITEM_ETHER, 1
	release
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 1
	release
	end

CeladonCity_Text_MyTrustedPalPoliwrath::
    .string "This is my trusted pal, Poliwrath.\p"
    .string "It evolved from a Poliwhirl when\n"
    .string "I used a Water Stone.$"

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 2
	release
	end

CeladonCity_Text_Poliwrath::
    .string "Poliwrath: Ribi ribit!$"

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_Text_ScaldedTongueOnTea::
    .string "Aaaagh, ow…\n"
    .string "I scalded my tongue!\p"
    .string "This nice old lady in the Mansion\n"
    .string "gave me some Tea.\p"
    .string "But it was boiling hot!\n"
    .string "Gotta cool it to drink it.$"

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_Text_GameCornerIsBadForCitysImage::
    .string "Celadon takes pride in its efforts\n"
    .string "to keep the city beautiful.\p"
    .string "That's why the new Game Corner is\n"
    .string "bad for our city's image.$"

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_Text_KeepOutOfTeamRocketsWay::
    .string "Keep out of Team Rocket's way!$"

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_Text_GetLostOrIllPunchYou::
    .string "What are you staring at?\n"
    .string "Get lost, or I'll punch you.$"

CeladonCity_EventScript_Breeder::
	goto_if_set FLAG_RESCUED_CUBONE, CeladonCity_EventScript_BreederRescuedCubone 
	msgbox CeladonCity_Text_KidnappedPokemon, MSGBOX_NPC
	end

CeladonCity_Text_KidnappedPokemon::
    .string "Oh, what am I to do…\p"
    .string "Team Rocket has been kidnapping\n" 
    .string "Pokémon.\p"
    .string "I chased a Rocket Grunt with a\n"
    .string "Cubone all the way from Lavender!\p"
    .string "They came running this way,\n"
    .string "I'm sure of it.\p"
    .string "But I lost sight of him!\n"
    .string "Where are they hiding?$"

CeladonCity_EventScript_BreederRescuedCubone::
	msgbox CeladonCity_Text_RescuedCubone, MSGBOX_NPC
	end

CeladonCity_Text_RescuedCubone::
    .string "Oh! You rescued the Cubone from\n"
    .string "Team Rocket?\p" 
    .string "That's wonderul!$"

CeladonCity_EventScript_OldMan::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_Text_BlewItAllAtSlots::
    .string "Moan…\n"
    .string "I blew it all at the slots!\p"
    .string "I knew I should have cashed in my\n"
    .string "Coins for prizes!$"

CeladonCity_EventScript_Pervert::
    msgbox CeladonCity_Text_OwOwOw, MSGBOX_NPC
    end

CeladonCity_Text_OwOwOw::
    .string "Hey! Not so tight!\n"
    .string "Ow ow ow!$"

CeladonCity_EventScript_Jenny::
    msgbox CeladonCity_Text_CaughtThisCreep, MSGBOX_NPC
    end

CeladonCity_Text_CaughtThisCreep::
    .string "Hold still, creep.\n"
    .string "You're coming with me.$"

CeladonCity_EventScript_Police::
    msgbox CeladonCity_Text_GettingComplaints, MSGBOX_NPC
    end

CeladonCity_Text_GettingComplaints::
    .string "We kept getting complaints\n"
    .string "from trainers at Erika's gym\l"
    .string "about someone bothering them.$"

CeladonCity_EventScript_GymSign::
	lockall
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_Text_GymSign::
    .string "Celadon City Pokémon Gym\n"
    .string "Leader: Erika\l"
    .string "The Nature-Loving Princess!$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_Text_CitySign::
    .string "Celadon City\n"
    .string "The City of Rainbow Dreams$"

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_Text_DeptStoreSign::
    .string "Find what you need at the\n"
    .string "Celadon Department Store!$"

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_Text_MansionSign::
    .string "Celadon Mansion$"

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_Text_ExplainXAccuracyDireHit::
    .string "Trainer Tips:\p"
    .string "X Accuracy boosts the accuracy of\n"
    .string "techniques.\p"
    .string "Dire Hit jacks up the likelihood\n"
    .string "of critical hits.\p"
    .string "Get your items at the Celadon\n"
    .string "Department Store!$"

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_Text_GuardSpecProtectsFromStatus::
    .string "Trainer Tips:\p"
    .string "Guard Spec. protects Pokémon\n"
    .string "from status-reduction moves during\l"
    .string "battle.\p"
    .string "Get your items at the\n"
    .string "Celadon Department Store!$"

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_Text_PrizeExchangeSign::
    .string "Coins exchanged for prizes!\n"
    .string "Prize Exchange$"

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GameCornerSign::
    .string "Rocket Game Corner\n"
    .string "Blast Off to a World of Riches!$"

CeladonCity_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_F, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
