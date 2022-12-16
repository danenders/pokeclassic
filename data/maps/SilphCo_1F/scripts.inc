SilphCo_1F_MapScripts::
	.byte 0

SilphCo_1F_EventScript_Receptionist::
	msgbox SilphCo_1F_Text_WelcomePresidentInBoardroom, MSGBOX_NPC
	end

SilphCo_1F_EventScript_FloorSign::
	msgbox SilphCo_1F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_1F_Text_WelcomePresidentInBoardroom::
    .string "Welcome.\p"
    .string "The President is in the boardroom\n"
    .string "on 11F.$"

SilphCo_1F_Text_FloorSign::
    .string "Silph Co. Head Office\n"
    .string "1F$"


SilphCo_1F_EventScript_PostgameGrunt1::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_1, SilphCo_1F_Text_PostgameGrunt1Intro, SilphCo_1F_Text_PostgameGrunt1Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt1Intro::
    .string "Team Rocket is back, baby!$"

SilphCo_1F_Text_PostgameGrunt1Defeat::
    .string "Cut down in my prime!$"

SilphCo_1F_Text_PostgameGrunt1PostBattle::
    .string "We're here to finish what\n"
    .string "Giovanni started.$"

SilphCo_1F_EventScript_PostgameGrunt2::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_2, SilphCo_1F_Text_PostgameGrunt2Intro, SilphCo_1F_Text_PostgameGrunt2Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt2Intro::
    .string "Unlike some of us, we didn't\n"
    .string "cut and run when Giovanni\l"
    .string "was defeatd in Viridian.$"

SilphCo_1F_Text_PostgameGrunt2Defeat::
    .string "Maybe I shoudl quit...$"

SilphCo_1F_Text_PostgameGrunt2PostBattle::
    .string "I'll never give up!\n"
    .string "Team Rocket forever!$"

SilphCo_1F_EventScript_PostgameGrunt3::
	trainerbattle_single TRAINER_POSTGAME_ROCKET_3, SilphCo_1F_Text_PostgameGrunt3Intro, SilphCo_1F_Text_PostgameGrunt3Defeat
	msgbox SilphCo_1F_Text_PostgameGrunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_1F_Text_PostgameGrunt3Intro::
    .string "Gimme all your money!$"

SilphCo_1F_Text_PostgameGrunt3Defeat::
    .string "We're broke!$"

SilphCo_1F_Text_PostgameGrunt3PostBattle::
    .string "The new boss doesn't want to\n"
    .string "admit it, but Team Rocket is\l"
    .string "running on fumes.\p"
    .string "We need this job to succeed!$"
