.set LOCALID_FUGITIVE, 12

Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route20_OnResume
	.byte 0

Route20_OnTransition:
	call_if_unset FLAG_STOPPED_SEAFOAM_B3F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_STOPPED_SEAFOAM_B4F_CURRENT, Route20_EventScript_ResetSeafoamBouldersForB4F
	call Common_EventScript_GetDayOrNight
	end

Route20_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_1
	clearflag FLAG_HIDE_SEAFOAM_1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B1F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B2F_BOULDER_2
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_2
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_3
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_4
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_5
	clearflag FLAG_HIDE_SEAFOAM_B3F_BOULDER_6
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_1
	setflag FLAG_HIDE_SEAFOAM_B4F_BOULDER_2
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end

Route20_Text_SeafoamIslands::
    .string "Seafoam Islands$"

Route20_EventScript_Barry::
	trainerbattle_single TRAINER_SWIMMER_MALE_BARRY, Route20_Text_BarryIntro, Route20_Text_BarryDefeat
	msgbox Route20_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_BarryIntro::
    .string "The water is shallow here.\n"
    .string "There are many people swimming.$"

Route20_Text_BarryDefeat::
    .string "Splash!$"

Route20_Text_BarryPostBattle::
    .string "I wish I could ride my Pokémon.\n"
    .string "I bet you're not tired.$"

Route20_EventScript_Dean::
	trainerbattle_single TRAINER_SWIMMER_MALE_DEAN, Route20_Text_DeanIntro, Route20_Text_DeanDefeat
	msgbox Route20_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DeanIntro::
    .string "Check out my buff physique!$"

Route20_Text_DeanDefeat::
    .string "Wimpy!$"

Route20_Text_DeanPostBattle::
    .string "I should've been buffing up my\n"
    .string "Pokémon, not me!$"

Route20_EventScript_Darrin::
	trainerbattle_single TRAINER_SWIMMER_MALE_DARRIN, Route20_Text_DarrinIntro, Route20_Text_DarrinDefeat
	msgbox Route20_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_DarrinIntro::
    .string "Why are you riding a Pokémon?\n"
    .string "Can't you swim?$"

Route20_Text_DarrinDefeat::
    .string "Ouch!\n"
    .string "Torpedoed!$"

Route20_Text_DarrinPostBattle::
    .string "Riding a Pokémon sure looks fun!$"

Route20_EventScript_Slowbronite::
	finditem ITEM_SLOWBRONITE, 1
	release
	end

Route20_EventScript_Tiffany::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_TIFFANY, Route20_Text_TiffanyIntro, Route20_Text_TiffanyDefeat
	msgbox Route20_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_TiffanyIntro::
    .string "I love floating with the fishes\n"
    .string "here among the waves.$"

Route20_Text_TiffanyDefeat::
    .string "Yowch!$"

Route20_Text_TiffanyPostBattle::
    .string "Want to float with me?$"

Route20_EventScript_Nora::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_NORA, Route20_Text_NoraIntro, Route20_Text_NoraDefeat
	msgbox Route20_Text_NoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_NoraIntro::
    .string "My boyfriend gave me big pearls.$"

Route20_Text_NoraDefeat::
    .string "Oh, no!\n"
    .string "My pearls were in them!$"

Route20_Text_NoraPostBattle::
    .string "Will my pearls grow bigger inside\n"
    .string "Cloyster?$"

Route20_EventScript_Melissa::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_MELISSA, Route20_Text_MelissaIntro, Route20_Text_MelissaDefeat
	msgbox Route20_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MelissaIntro::
    .string "Cinnabar, in the west, has a LAB\n"
    .string "for Pokémon.\p"
    .string "My daddy works there.$"

Route20_Text_MelissaDefeat::
    .string "Wait!\n"
    .string "You're supposed to wait!$"

Route20_Text_MelissaPostBattle::
    .string "Cinnabar is a volcanic island.\p"
    .string "I heard it rose out of the sea\n"
    .string "when a volcano erupted.$"

Route20_EventScript_Shirley::
	trainerbattle_single TRAINER_SWIMMER_FEMALE_SHIRLEY, Route20_Text_ShirleyIntro, Route20_Text_ShirleyDefeat
	msgbox Route20_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_ShirleyIntro::
    .string "Seafoam is a quiet getaway.\n"
    .string "I'm vacationing here.$"

Route20_Text_ShirleyDefeat::
    .string "Quit it!$"

Route20_Text_ShirleyPostBattle::
    .string "There's a huge cavern underneath\n"
    .string "this island.$"

Route20_EventScript_Missy::
	trainerbattle_single TRAINER_PICNICKER_MISSY, Route20_Text_MissyIntro, Route20_Text_MissyDefeat
	msgbox Route20_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_MissyIntro::
    .string "I swam here from Cinnabar Island.\n"
    .string "It wasn't easy, I tell you.$"

Route20_Text_MissyDefeat::
    .string "I'm so disappointed!$"

Route20_Text_MissyPostBattle::
    .string "Pokémon have taken over an\n"
    .string "abandoned mansion on Cinnabar.\p"
    .string "They call it the Pokémon Mansion\n"
    .string "now.$"

Route20_EventScript_Irene::
	trainerbattle_single TRAINER_PICNICKER_IRENE, Route20_Text_IreneIntro, Route20_Text_IreneDefeat
	msgbox Route20_Text_IrenePostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_IreneIntro::
    .string "Are you on vacation, too?$"

Route20_Text_IreneDefeat::
    .string "No mercy at all!$"

Route20_Text_IrenePostBattle::
    .string "Seafoam used to be a single island\n"
    .string "in the distant past.$"

Route20_EventScript_Roger::
	trainerbattle_single REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerIntro, Route20_Text_RogerDefeat, Route20_EventScript_RegisterRogerAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route20_EventScript_RogerRematch
	msgbox Route20_Text_RogerPostBattle, MSGBOX_DEFAULT
	release
	end

Route20_Text_RogerIntro::
    .string "You'll never make it to the\n"
    .string "Elite Four with that team!$"

Route20_Text_RogerDefeat::
    .string "No! Now I'll never meet Lance!$"

Route20_Text_RogerPostBattle::
    .string "Wait, you mean Gyarados isn't\n"
    .string "a Dragon type Pokémon?$"

Route20_EventScript_RegisterRogerAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route20_Text_RogerRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1
	release
	end

Route20_Text_RogerRegister:
	.string "Ha! I let you win...\p"
	.string "Call me when you feel like\n"
	.string "having a real match.$"

Route20_EventScript_RogerRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_DRAGON_TAMER_ROGER_1, Route20_Text_RogerRematchIntro, Route20_Text_RogerDefeat
	msgbox Route20_Text_RogerRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route20_Text_RogerRematchIntro::
	.string "I'll crush you with my\n"
	.string "Dragon Pokémon this time!$"

Route20_Text_RogerRematchPostBattle::
	.string "Gyarados isn't Dragon type, but\n"
	.string "it can learn Dragon type moves!$"

Route20_EventScript_Camper::
	lock
	faceplayer
	msgbox Route20_Text_MistyTrainsHere
	release
	end

Route20_Text_MistyTrainsHere::
    .string "Strong Trainers and Water Pokémon\n"
    .string "are common sights in these parts.\p"
    .string "They say that Misty of the\n"
    .string "Cerulean Gym trains here.$"

Route20_RocketFugitive::
    trainerbattle_single TRAINER_FUGITIVE_M, RocketFugitive_Text_Intro, RocketFugitive_Text_Defeat
    msgbox RocketFugitive_Text_PostBattle, MSGBOX_AUTOCLOSE
    setflag FLAG_ROCKET_FUGITIVE_CAPTURED
    fadescreen FADE_TO_BLACK
    playse SE_FLEE
    removeobject LOCALID_FUGITIVE
    waitse
    fadescreen FADE_FROM_BLACK
    end
