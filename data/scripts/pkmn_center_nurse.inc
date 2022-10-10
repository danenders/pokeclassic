Common_EventScript_PkmnCenterNurse::
	goto_if_set FLAG_IS_CHAMPION, EventScript_PkmnCenterNurse_ChampionHeal
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_PkmnCenterNurse_GameClearHeal
	goto EventScript_PkmnCenterNurse_NormalHeal
	end

EventScript_PkmnCenterNurse_NormalHeal::
	msgbox gText_WouldYouLikeToRestYourPkmn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_WouldYouLikeToRestYourPkmn::
    .string "Hello, and welcome to\n"
    .string "the Pokémon Center.\p"
    .string "We restore your tired Pokémon\n"
    .string "to full health.\p"
    .string "Would you like to rest your Pokémon?$"

EventScript_PkmnCenterNurse_GameClearHeal::
	msgbox gText_YouWantTheUsual, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_YouWantTheUsual::
    .string "I'm delighted to see you, {PLAYER}!\n"
    .string "You want the usual, am I right?$"

EventScript_PkmnCenterNurse_ChampionHeal::
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	playse SE_PIN
	msgbox gText_ItsTheChampion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_PkmnCenterNurse_HealPkmn
	goto_if_eq VAR_RESULT, NO, EventScript_PkmnCenterNurse_Goodbye
	end

gText_ItsTheChampion::
    .string "Oh! It's the Champion, {PLAYER}!\n"
    .string "Shall we heal your Pokémon?$"

EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message gText_IllTakeYourPkmn
	waitmessage
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	call_if_unset FLAG_POKERUS_EXPLAINED, EventScript_PkmnCenterNurse_CheckPokerus
	msgbox gText_RestoredPkmnToFullHealth, MSGBOX_DEFAULT
	applymovement VAR_0x800B, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	goto EventScript_PkmnCenterNurse_Goodbye

gText_IllTakeYourPkmn::
    .string "Okay, I'll take your Pokémon\n"
    .string "for a few seconds.$"

gText_RestoredPkmnToFullHealth::
    .string "Thank you for waiting.\p"
    .string "We've restored your Pokémon\n"
    .string "to full health.$"

EventScript_PkmnCenterNurse_CheckPokerus::
	specialvar VAR_RESULT, IsPokerusInParty
	goto_if_eq VAR_RESULT, TRUE, EventScript_PkmnCenterNurse_ExplainPokerus
	return

EventScript_PkmnCenterNurse_ExplainPokerus::
	msgbox gText_PokerusExplanation, MSGBOX_DEFAULT
	setflag FLAG_POKERUS_EXPLAINED
	return

gText_PokerusExplanation::
	.string "Your Pokémon may be infected with\n"
	.string "Pokérus.\p"
	.string "Little is known about the Pokérus\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to Pokémon.\p"
	.string "While infected, Pokémon are said to\n"
	.string "grow exceptionally well.$"

gText_WeHopeToSeeYouAgain::
    .string "We hope to see you again!$"

Movement_PkmnCenterNurse_Bow:
	nurse_joy_bow
	delay_4
	step_end

EventScript_PkmnCenterNurse_Goodbye::
	msgbox gText_WeHopeToSeeYouAgain, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end
