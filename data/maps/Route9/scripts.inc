Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route9_OnResume
	.byte 0

Route9_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route9_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route9_EventScript_Alicia::
	trainerbattle_single REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaIntro, Route9_Text_AliciaDefeat, Route9_EventScript_RegisterAliciaAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route9_EventScript_AliciaRematch
	msgbox Route9_Text_AliciaPostBattle, MSGBOX_DEFAULT
	release
	end

Route9_Text_AliciaIntro::
    .string "You have Pokémon with you!\n"
    .string "You're mine!$"

Route9_Text_AliciaDefeat::
    .string "You deceived me…$"

Route9_Text_AliciaPostBattle::
    .string "The tunnel coming up is pitch-black\n"
    .string "inside.\p"
    .string "You'll need FLASH to get through\n"
    .string "there.$"

Route9_EventScript_RegisterAliciaAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route9_Text_AliciaRegister, MSGBOX_DEFAULT
	register_matchcall REMATCHABLE_TRAINER_PICNICKER_ALICIA_1
	release
	end

Route9_Text_AliciaRegister:
	.string "Tricking me was mean, but I'll\n"
	.string "forgive you if you give me your\l"
	.string "Cell Phone number.$"

Route9_EventScript_AliciaRematch::
	trainerbattle_rematch REMATCHABLE_TRAINER_PICNICKER_ALICIA_1, Route9_Text_AliciaRematchIntro, Route9_Text_AliciaDefeat
	msgbox Route9_Text_AliciaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_AliciaRematchIntro::
	.string "We're to battle again?\n"
	.string "This time, you're mine!$"

Route9_Text_AliciaRematchPostBattle::
	.string "You tricked me again!$"


Route9_EventScript_Brent::
	trainerbattle_single TRAINER_BUG_CATCHER_BRENT, Route9_Text_BrentIntro, Route9_Text_BrentDefeat
	msgbox Route9_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

Route9_Text_BrentIntro::
    .string "I got up early every day to raise\n"
    .string "my Pokémon from cocoons!$"

Route9_Text_BrentDefeat::
    .string "WHAT?\p"
    .string "What a total waste of time!$"

Route9_Text_BrentPostBattle::
    .string "I have to collect more than bugs\n"
    .string "to get stronger…$"

Route9_EventScript_Conner::
    trainerbattle_single TRAINER_BUG_CATCHER_CONNER, Route9_Text_ConnerIntro, Route9_Text_ConnerDefeat
    msgbox Route9_Text_ConnerPostBattle, MSGBOX_AUTOCLOSE
    end
    
Route9_Text_ConnerIntro::
    .string "Go, my super bug Pokémon!$"

Route9_Text_ConnerDefeat::
    .string "My bugs…$"

Route9_Text_ConnerPostBattle::
    .string "If you don't like bug Pokémon,\n"
    .string "you bug me!$"

Route9_EventScript_Chris::
    trainerbattle_single TRAINER_CAMPER_CHRIS, Route9_Text_ChrisIntro, Route9_Text_ChrisDefeat
    msgbox Route9_Text_ChrisPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_ChrisIntro::
    .string "Who's that walking there with those\n"
    .string "good-looking Pokémon?$"

Route9_Text_ChrisDefeat::
    .string "Out like a light!$"

Route9_Text_ChrisPostBattle::
    .string "Keep walking!$"

Route9_EventScript_Drew::
    trainerbattle_single TRAINER_CAMPER_DREW, Route9_Text_DrewIntro, Route9_Text_DrewDefeat
    msgbox Route9_Text_DrewPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_DrewIntro::
    .string "I'm taking the Rock Tunnel to\n"
    .string "go to Lavender…$"

Route9_Text_DrewDefeat::
    .string "Can't measure up…$"

Route9_Text_DrewPostBattle::
    .string "Are you off to Rock Tunnel, too?$"

Route9_EventScript_Caitlin::
    trainerbattle_single TRAINER_PICNICKER_CAITLIN, Route9_Text_CaitlinIntro, Route9_Text_CaitlinDefeat
    msgbox Route9_Text_CaitlinPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_CaitlinIntro::
    .string "Don't you dare patronize me!$"

Route9_Text_CaitlinDefeat::
    .string "No!\n"
    .string "You're too much.$"

Route9_Text_CaitlinPostBattle::
    .string "You're obviously talented.\n"
    .string "Good luck to you!$"

Route9_EventScript_Alan::
    trainerbattle_single TRAINER_HIKER_ALAN, Route9_Text_AlanIntro, Route9_Text_AlanDefeat
    msgbox Route9_Text_AlanPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_AlanIntro::
    .string "Hahahaha!\n"
    .string "Bring it on!$"

Route9_Text_AlanDefeat::
    .string "Hahahaha!\n"
    .string "You beat me fair!$"

Route9_Text_AlanPostBattle::
    .string "Hahahaha!\n"
    .string "Us hearty guys always laugh!$"

Route9_EventScript_Brice::
    trainerbattle_single TRAINER_HIKER_BRICE, Route9_Text_BriceIntro, Route9_Text_BriceDefeat
    msgbox Route9_Text_BricePostBattle, MSGBOX_AUTOCLOSE
    end
    
Route9_Text_BriceIntro::
    .string "Hahaha!\n"
    .string "Aren't you a little toughie!$"

Route9_Text_BriceDefeat::
    .string "What's that?$"

Route9_Text_BricePostBattle::
    .string "Hahaha!\n"
    .string "Kids should be tough!$"

Route9_EventScript_Jeremy::
    trainerbattle_single TRAINER_HIKER_JEREMY, Route9_Text_JeremyIntro, Route9_Text_JeremyDefeat
    msgbox Route9_Text_JeremyPostBattle, MSGBOX_AUTOCLOSE
    end

Route9_Text_JeremyIntro::
    .string "Bwahaha!\n"
    .string "Great! I was bored, eh!$"

Route9_Text_JeremyDefeat::
    .string "Keep it coming, eh!\p"
    .string "Oh wait.\n"
    .string "I'm out of Pokémon!$"

Route9_Text_JeremyPostBattle::
    .string "You sure had guts standing up to\n"
    .string "me there, eh?$"

Route9_EventScript_RouteSign::
	msgbox Route9_Text_RouteSign, MSGBOX_SIGN
	end

Route9_Text_RouteSign::
    .string "Route 9\n"
    .string "Cerulean City - Rock Tunnel$"

Route9_EventScript_ItemBurnHeal::
	finditem ITEM_BURN_HEAL, 1
	release
	end

Route9_EventScript_ItemTM40::
    finditem ITEM_TM40, 1
    release
    end
