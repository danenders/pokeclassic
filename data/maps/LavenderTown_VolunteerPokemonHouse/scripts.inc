.set LOCALID_MRFUJI, 1

LavenderTown_VolunteerPokemonHouse_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE, 1
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji
	waitmessage
	waitfanfare
	additem ITEM_POKE_FLUTE, 1
	setflag FLAG_RECEIVED_POKE_FLUTE
	setvar VAR_POKEMON_TOWER_STATE, 4
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
    .string "Mr. Fuji: {PLAYER}…\p"
    .string "Your Pokédex quest is one that\n"
    .string "requires strong dedication.\p"
    .string "Without deep love for Pokémon,\n"
    .string "your quest may fail.\p"
    .string "I'm not sure if this will help you,\n"
    .string "but I'd like you to have it.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
    .string "{PLAYER} received a Poké Flute\n"
    .string "from Mr. Fuji.$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
    .string "Upon hearing the Poké Flute,\n"
    .string "sleeping Pokémon will spring awake.\p"
    .string "Try using it on Pokémon that are\n"
    .string "sleeping obstacles.$"

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
    .string "Mr. Fuji: Has my Poké Flute\n"
    .string "helped you?$"

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
    .string "You must make room for this!$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
    .string "This is really Mr. Fuji's house.\p"
    .string "He's really kind.\p"
    .string "He looks after abandoned and\n"
    .string "orphaned Pokémon.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
    .string "It's so warm!\n"
    .string "Pokémon are so nice to hug.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
    .string "That's odd, Mr. Fuji isn't here.\n"
    .string "Where'd he go?$"

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
    .string "Mr. Fuji had been praying alone\n"
    .string "for Cubone's mother.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
    .string "Nidorino: Gaoo!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
    .string "Psyduck: Gwappa!$"


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
    .string "Pokémon Fan Magazine\n"
    .string "Monthly Grand Prize Drawing!\p"
    .string "The application form is…\p"
    .string "Gone! It's been clipped out.\n"
    .string "Someone must have applied already.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
    .string "Pokémon magazines line the shelf.\p"
    .string "Pokémon Insider…\p"
    .string "Pokémon Fan…$"

LavenderTown_VolunteerPokemonHouse_EventScript_GetReward::
	playse SE_PIN
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_MRFUJI, Common_Movement_QuestionMark
	waitmovement 1
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GetReward, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Movement_ApproachFuji
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	release
	end

LavenderTown_VolunteerPokemonHouse_Text_GetReward::
	.string "Mr. Fuji: Oh, {PLAYER}, I have\n"
	.string "something for you.\p"
	.string "Come here for a moment.$"

 Movement_ApproachFuji::
 	walk_up
 	walk_up
 	step_end
