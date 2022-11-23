@Pokemon League Services

PkmnLeague_Services_RankSign::
	msgbox PkmnLeague_Services_Text_RankingsBoard, MSGBOX_SIGN
	release
	end

PkmnLeague_Services_Text_RankingsBoard::
	.string "Pokémon League - Rankings Board$"

PkmnLeague_Services_RankBoard::
	msgbox PkmnLeague_Services_Text_RankBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_End
	playse SE_PC_LOGIN
	waitse
	message PkmnLeague_Services_Text_Searching
	waitmessage
	playse SE_RG_HELP_OPEN
	waitse
	goto_if_set FLAG_SYS_GAME_CLEAR, PkmnLeague_Services_Ranking_Champion
	call PkmnLeague_Services_CalculateBadges
	goto_if_eq  VAR_TEMP_1, 8, PkmnLeague_Services_Ranking_Elite
	goto_if_ge  VAR_TEMP_1, 6, PkmnLeague_Services_Ranking_Veteran
	goto_if_ge  VAR_TEMP_1, 3, PkmnLeague_Services_Ranking_Seasoned
	goto_if_ge  VAR_TEMP_1, 1, PkmnLeague_Services_Ranking_Beginner
	goto PkmnLeague_Services_Ranking_Unranked
	end

PkmnLeague_Services_CalculateBadges::
	setvar VAR_TEMP_1, 0
	call_if_set FLAG_BADGE01_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE02_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE03_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE04_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE05_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE06_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE07_GET, PkmnLeague_Services_AddBadgeToVar
	call_if_set FLAG_BADGE08_GET, PkmnLeague_Services_AddBadgeToVar
	return

PkmnLeague_Services_AddBadgeToVar:
	addvar VAR_TEMP_1, 1
	return

PkmnLeague_Services_Text_RankBoard:
	.string "It's the Pokémon League rankings.\p"
	.string "Look up your current rank?$"

PkmnLeague_Services_Ranking_Unranked::
	msgbox PkmnLeague_Services_Ranking_Text_Unranked, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Unranked:
	.string "You are currently Unranked!\p"
	.string "You need to earn at least 1\n"
	.string "Badge to earn a rank.$"

PkmnLeague_Services_Ranking_Beginner::
	msgbox PkmnLeague_Services_Ranking_Text_Beginner, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Beginner:
	.string "Your current rank is:\n"
	.string "Beginner!$"

PkmnLeague_Services_Ranking_Seasoned::
	msgbox PkmnLeague_Services_Ranking_Text_Seasoned, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Seasoned:
	.string "Your current rank is:\p"
	.string "Seasoned!$"

PkmnLeague_Services_Ranking_Veteran::
	msgbox PkmnLeague_Services_Ranking_Text_Veteran, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Veteran:
	.string "Your current rank is:\p"
	.string "Veteran!$"

PkmnLeague_Services_Ranking_Elite::
	msgbox PkmnLeague_Services_Ranking_Text_Elite, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_Elite:
	.string "Your current rank is:\p"
	.string "Elite!$"

PkmnLeague_Services_Ranking_Champion::
	msgbox PkmnLeague_Services_Ranking_Text_Champion, MSGBOX_DEFAULT
	goto_if_unset FLAG_DAILY_TITLE_MATCH, PkmnLeague_Services_Ranking_TitleMatch
	release
	end

PkmnLeague_Services_Ranking_Text_Champion:
	.string "Your current rank is:\p"
	.string "Champion!$"

PkmnLeague_Services_Text_Searching:
	.string "Searching database....\p"
	.string "..........\p"
	.string "Found trainer....\p"
	.string "{PLAYER} from Pallet Town.$"

PkmnLeague_Services_Ranking_TitleMatch::
	msgbox PkmnLeague_Services_Ranking_Text_TitleMatch, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Ranking_Text_TitleMatch:
	.string "Someone is challenging your status as\n"
	.string "the champion!\p"
	.string "Visit the Pokémon League to face your\n"
	.string "challenger in a Title Match!$"

@BADGE CHECKS
PkmnLeague_Services_MustBeBeginner::
	msgbox PkmnLeague_Services_Text_MustBeBeginner, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeBeginner:
	.string "I'm sorry, but you need to be at\n"
	.string "least Beginner Rank in the Pokémon\l"
	.string "League to use our services.$"

PkmnLeague_Services_MustBeSeasoned::
	msgbox PkmnLeague_Services_Text_MustBeSeasoned, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeSeasoned:
	.string "I'm sorry, but you need to be a\n"
	.string "Seasoned trainer in the Pokémon\l"
	.string "League to use my services.$"

PkmnLeague_Services_MustBeElite::
	msgbox PkmnLeague_Services_Text_MustBeElite, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_Text_MustBeElite:
	.string "Whoa, slow down there, kid!\p"
	.string "I only work the most Elite\n"
	.string "trainers.\p"
	.string "Come back and see me after you\n"
	.string "earn a few more badges.$"

PkmnLeague_Services_MoveDeleter::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_lt VAR_TEMP_1, 3, PkmnLeague_Services_MustBeSeasoned
	msgbox PkmnLeague_Services_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnLeague_Services_ComeAgain
	goto PkmnLeague_Services_ChooseMonAndMoveToForget
	end

PkmnLeague_Services_ChooseMonAndMoveToForget::
	msgbox PkmnLeague_Services_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PkmnLeague_Services_ComeAgain
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, PkmnLeague_Services_MonOnlyKnowsOneMove
	msgbox PkmnLeague_Services_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, PkmnLeague_Services_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnLeague_Services_ComeAgain
	special IsLastMonThatKnowsSurf
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox PkmnLeague_Services_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_EggCantForgetMoves::
	msgbox PkmnLeague_Services_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_ComeAgain::
	msgbox PkmnLeague_Services_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_LastMonWithSurf::
	special BufferMoveDeleterNicknameAndMove
	msgbox PkmnLeague_Services_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

PkmnLeague_Services_Text_ICanMakeMonForgetMove:
	.string "Uh… Oh, yes!\n"
	.string "I'm a pupil of the Move Deleter.\p"
	.string "I can make Pokémon forget their moves.\p"
	.string "Would you like me to do that?$"

PkmnLeague_Services_Text_WhichMonShouldForget:
	.string "Which Pokémon should forget a move?$"

PkmnLeague_Services_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

PkmnLeague_Services_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

PkmnLeague_Services_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

PkmnLeague_Services_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

PkmnLeague_Services_Text_ComeAgain:
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

PkmnLeague_Services_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No Egg should know any moves.$"

PkmnLeague_Services_Text_CantForgetSurf:
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget Surf.$"

PkmnLeague_Services_EventScript_MoveRelearner::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_eq VAR_TEMP_1, 0, PkmnLeague_Services_MustBeBeginner
	goto_if_set FLAG_TEMP_1, PkmnLeague_Services_EventScript_AskTeachMove
	msgbox PkmnLeague_Services_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PkmnLeague_Services_EventScript_AskTeachMove
	end

PkmnLeague_Services_EventScript_AskTeachMove::
	msgbox PkmnLeague_Services_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, Common_EventScript_End
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_EventScript_ChooseMon::
	msgbox PkmnLeague_Services_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Common_EventScript_End
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PkmnLeague_Services_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, PkmnLeague_Services_EventScript_NoMoveToTeachMon
	goto PkmnLeague_Services_EventScript_ChooseMove
	end

PkmnLeague_Services_EventScript_ChooseMove::
	msgbox PkmnLeague_Services_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, PkmnLeague_Services_EventScript_ChooseMon
	releaseall
	end

PkmnLeague_Services_EventScript_NoMoveToTeachMon::
	msgbox PkmnLeague_Services_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_EventScript_CantTeachEgg::
	msgbox PkmnLeague_Services_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PkmnLeague_Services_EventScript_ChooseMon
	end

PkmnLeague_Services_Text_ImTheMoveTutor:
	.string "I'm a Move Tutor.\p"
	.string "I know all the moves that Pokémon\n"
	.string "learn--every one of them--and I can\l"
	.string "teach Pokémon those moves.\p"
	.string "I can teach a move to a Pokémon\n"
	.string "of yours if you'd like.$"

PkmnLeague_Services_Text_TutorWhichMon:
	.string "Which Pokémon needs tutoring?$"

PkmnLeague_Services_Text_WantMeToTeachMove:
	.string "Want me to tutor a Pokémon?$"

PkmnLeague_Services_Text_TeachWhichMove:
	.string "Which move should I teach?$"

PkmnLeague_Services_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that Pokémon.$"

PkmnLeague_Services_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an Egg.$"


PkmnLeague_Services_EliteShop::
	lockall
	call PkmnLeague_Services_CalculateBadges
	goto_if_lt VAR_TEMP_1, 8, PkmnLeague_Services_MustBeElite
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, PkmnLeague_Services_EliteShop_PostGameShop
	goto PkmnLeague_Services_EliteShop_Elite
	end

PkmnLeague_Services_EliteShop_PostGameShop::
	pokemart PkmnLeague_Services_Mart_EliteShop_Postgame
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

PkmnLeague_Services_EliteShop_Elite::
	pokemart PkmnLeague_Services_Mart_EliteShop_Elite
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PkmnLeague_Services_Mart_EliteShop_Elite:
	.2byte ITEM_PP_UP
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_NONE
	release
	end

	.align 2
PkmnLeague_Services_Mart_EliteShop_Postgame:
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_NONE
	release
	end
