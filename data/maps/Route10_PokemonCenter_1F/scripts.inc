.set LOCALID_NURSE, 1

Route10_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_PokemonCenter_1F_OnTransition
	.byte 0

Route10_PokemonCenter_1F_OnTransition::
	call_if_unset FLAG_RECEIVED_ITEMFINDER, Route10_PokemonCenter_1F_EventScript_CheckAideAppearance
	setrespawn HEAL_LOCATION_ROUTE_10
	end

@Check if you've completed the requirement and Cedar has called you
Route10_PokemonCenter_1F_EventScript_CheckAideAppearance::
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_Return
	goto_if_unset FLAG_AIDE_LOCATION_2, Common_EventScript_Return
	goto_if_lt VAR_AIDE_CALL_STEP_COUNTER, 200, Common_EventScript_Return
	clearflag FLAG_HIDE_AIDE_ROUTE10
	return

Route10_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	setvar VAR_0x800B, LOCALID_NURSE
	goto Common_EventScript_PkmnCenterNurse
	end

Route10_PokemonCenter_1F_EventScript_FatMan::
	msgbox Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_NuggetUselessSoldFor5000::
    .string "A nugget is totally useless.\n"
    .string "So I sold it for ¥5000.$"

Route10_PokemonCenter_1F_EventScript_Gentleman::
	msgbox Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_EveryTypeStrongerThanOthers::
    .string "The types of Pokémon match up\n"
    .string "differently with each other.\p"
    .string "Every type is stronger than some\n"
    .string "types and weaker than others.$"

Route10_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender, MSGBOX_NPC
	end

Route10_PokemonCenter_1F_Text_HeardGhostsHauntLavender::
    .string "I heard that ghosts haunt\n"
    .string "Lavender Town.$"

@Aide Gift 3
Route10_PokemonCenter_1F_EventScript_Aide::
    lock
    faceplayer
    goto_if_set FLAG_RECEIVED_AIDE_EVERSTONE, Route10_PokemonCenter_1F_EventScript_AlreadyGotReward
    msgbox Route10_PokemonCenter_1F_Text_GiveReward, MSGBOX_DEFAULT
    checkitemspace ITEM_EVERSTONE, 1
    goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
    giveitem ITEM_EVERSTONE, 1
    waitmessage
    setflag FLAG_RECEIVED_AIDE_EVERSTONE
    setflag FLAG_HIDE_AIDE_ROUTE10
    clearflag FLAG_AIDE_LOCATION_2
    clearflag FLAG_QUEUE_AIDE_CALL
    setvar VAR_AIDE_CALL_STEP_COUNTER, 0
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    call Route10_PokemonCenter_1F_EventScript_CheckAideNextLocation
    release
    end

Route10_PokemonCenter_1F_Text_GiveReward::
    .string "Oh… {PLAYER}!\n"
    .string "I've been looking for you!\p"
    .string "It's me, Cedar, the ever-present\n"
    .string "aide to Prof. Oak.\p"
    .string "How's your Pokédex coming along?\p"
    .string "Give Prof. Oak a call sometime to\n"
    .string "review your progress!\p"
    .string "Anyway, he entrusted me with this\n"
    .string "Everstone.\p"
    .string "So, {PLAYER}, here you go!.$"

Route10_PokemonCenter_1F_EventScript_AlreadyGotReward::
    msgbox Route10_PokemonCenter_1F_Text_ExplainReward, MSGBOX_DEFAULT
    release
    end

Route10_PokemonCenter_1F_Text_ExplainReward::
    .string "Making Pokémon evolve certainly\n"
    .string "can add to the Pokédex.\p"
    .string "However, at times, you may not\n"
    .string "want a certain Pokémon to evolve.\p"
    .string "In that case, give the Everstone\n"
    .string "to that Pokémon.\p"
    .string "It will prevent evolution according\n"
    .string "to the Professor.$"

@Check if you've already completed the next requirement
Route10_PokemonCenter_1F_EventScript_CheckAideNextLocation::
    goto_if_unset FLAG_BADGE04_GET, Common_EventScript_Return
    setflag FLAG_QUEUE_AIDE_CALL
    setflag FLAG_AIDE_LOCATION_3
    return
