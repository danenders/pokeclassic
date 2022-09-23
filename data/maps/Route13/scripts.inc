Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route13_OnResume
	.byte 0

Route13_OnTransition:
	call Common_EventScript_GetDayOrNight
	end

Route13_OnResume:
	call Common_EventScript_GetDayOrNight
	end

Route13_EventScript_TrainerTips1::
	msgbox Route13_Text_LookToLeftOfThatPost, MSGBOX_SIGN
	end

Route13_Text_LookToLeftOfThatPost::
    .string "Trainer Tips:\p"
    .string "Look, look!\n"
    .string "Look to the left of that post!$"

Route13_EventScript_TrainerTips2::
	msgbox Route13_Text_SelectToSwitchItems, MSGBOX_SIGN
	end

Route13_Text_SelectToSwitchItems::
    .string "Trainer Tips:\p"
    .string "Use Select to switch items in the\n"
    .string "Items window.$"

Route13_EventScript_RouteSign::
	msgbox Route13_Text_RouteSign, MSGBOX_SIGN
	end

Route13_Text_RouteSign::
    .string "ROUTE 13\n"
    .string "North to Silence Bridge$"

Route13_EventScript_Lola::
	trainerbattle_single TRAINER_BEAUTY_LOLA, Route13_Text_LolaIntro, Route13_Text_LolaDefeat
	msgbox Route13_Text_LolaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_LolaIntro::
    .string "Sure, I'll play with you, sweetie.$"

Route13_Text_LolaDefeat::
    .string "Oh!\n"
    .string "You little beast!$"

Route13_Text_LolaPostBattle::
    .string "I wonder which is stronger, male or\n"
    .string "female Pokémon?$"

Route13_EventScript_Sheila::
	trainerbattle_single TRAINER_BEAUTY_SHEILA, Route13_Text_SheilaIntro, Route13_Text_SheilaDefeat
	msgbox Route13_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SheilaIntro::
    .string "Do you want to battle some\n"
    .string "Pokémon with me?$"

Route13_Text_SheilaDefeat::
    .string "It's over already?$"

Route13_Text_SheilaPostBattle::
    .string "I don't know anything about\n"
    .string "Pokémon actually.\p"
    .string "The ones I use… I picked them\n"
    .string "for their looks!$"

Route13_EventScript_Jared::
	trainerbattle_single TRAINER_BIKER_JARED, Route13_Text_JaredIntro, Route13_Text_JaredDefeat
	msgbox Route13_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_JaredIntro::
    .string "What're you lookin' at?$"

Route13_Text_JaredDefeat::
    .string "Dang!\n"
    .string "Stripped gears!$"

Route13_Text_JaredPostBattle::
    .string "Get lost!$"

Route13_EventScript_Sebastian::
	trainerbattle_single TRAINER_BIRD_KEEPER_SEBASTIAN, Route13_Text_SebastianIntro, Route13_Text_SebastianDefeat
	msgbox Route13_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SebastianIntro::
    .string "My bird Pokémon want to battle\n"
    .string "with you!$"

Route13_Text_SebastianDefeat::
    .string "My Pidgey and Pidgeotto combo\n"
    .string "lost?$"

Route13_Text_SebastianPostBattle::
    .string "My Pokémon look happy even though\n"
    .string "they lost.$"


Route13_EventScript_Perry::
	trainerbattle_single TRAINER_BIRD_KEEPER_PERRY, Route13_Text_PerryIntro, Route13_Text_PerryDefeat
	msgbox Route13_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_PerryIntro::
    .string "I'm not going to lose.\n"
    .string "Not when the wind's blowing my way!$"

Route13_Text_PerryDefeat::
    .string "The wind turned!$"

Route13_Text_PerryPostBattle::
    .string "I'm beat.\n"
    .string "I guess I'll fly home.$"

Route13_EventScript_Robert::
	trainerbattle_single TRAINER_BIRD_KEEPER_ROBERT, Route13_Text_RobertIntro, Route13_Text_RobertDefeat
	msgbox Route13_Text_RobertPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_RobertIntro::
    .string "I always go with bird Pokémon.\n"
    .string "I've dedicated myself to them.$"

Route13_Text_RobertDefeat::
    .string "Out of power!$"

Route13_Text_RobertPostBattle::
    .string "I wish I could fly like Pidgey and\n"
    .string "Pidgeotto…$"

Route13_EventScript_Alma::
	trainerbattle_single TRAINER_PICNICKER_ALMA, Route13_Text_AlmaIntro, Route13_Text_AlmaDefeat
	msgbox Route13_Text_AlmaPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_AlmaIntro::
    .string "I found a carbos in a cave once\n"
    .string "while I was spelunking.$"

Route13_Text_AlmaDefeat::
    .string "Oh, too bad!\n"
    .string "I just messed up!$"

Route13_Text_AlmaPostBattle::
    .string "Carbos boosted the speed of my\n"
    .string "Pokémon.$"

Route13_EventScript_Susie::
	trainerbattle_single TRAINER_PICNICKER_SUSIE, Route13_Text_SusieIntro, Route13_Text_SusieDefeat
	msgbox Route13_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_SusieIntro::
    .string "I'm told I'm good for a kid.$"

Route13_Text_SusieDefeat::
    .string "Ohh!\n"
    .string "I lost!$"

Route13_Text_SusiePostBattle::
    .string "I want to become a good trainer.\n"
    .string "I'll train hard, just watch.$"

Route13_EventScript_Valerie::
	trainerbattle_single TRAINER_PICNICKER_VALERIE, Route13_Text_ValerieIntro, Route13_Text_ValerieDefeat
	msgbox Route13_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_ValerieIntro::
    .string "Wow!\n"
    .string "Your badges are too cool!$"

Route13_Text_ValerieDefeat::
    .string "Not enough!$"

Route13_Text_ValeriePostBattle::
    .string "You got those Badges from Gym\n"
    .string "Leaders. I know!$"

Route13_EventScript_Gwen::
	trainerbattle_single TRAINER_PICNICKER_GWEN, Route13_Text_GwenIntro, Route13_Text_GwenDefeat
	msgbox Route13_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route13_Text_GwenIntro::
    .string "My cute Pokémon wish to make your\n"
    .string "acquaintance.$"

Route13_Text_GwenDefeat::
    .string "Good going!\n"
    .string "You totally won!$"

Route13_Text_GwenPostBattle::
    .string "You have to make Pokémon battle\n"
    .string "to toughen them up.$"
