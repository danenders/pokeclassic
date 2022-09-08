const struct Trainer gTrainers[] = {
    [TRAINER_NONE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _(""),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = 0,
        .partySize = 0,
        .party = {.NoItemDefaultMoves = NULL},
    },

    //Emerald
    [TRAINER_STEVEN] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_STEVEN,
        .trainerName = _("Steven"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Steven),
        .party = {.ItemCustomMoves = sParty_Steven},
    },

    //Frontier Brains
    [TRAINER_ANABEL] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SALON_MAIDEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_SALON_MAIDEN_ANABEL,
        .trainerName = _("Anabel"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Anabel),
        .party = {.NoItemDefaultMoves = sParty_Anabel},
    },

    [TRAINER_TUCKER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_DOME_ACE,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_DOME_ACE_TUCKER,
        .trainerName = _("Tucker"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Tucker),
        .party = {.NoItemDefaultMoves = sParty_Tucker},
    },

    [TRAINER_SPENSER] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PALACE_MAVEN,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PALACE_MAVEN_SPENSER,
        .trainerName = _("Spenser"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Spenser),
        .party = {.NoItemDefaultMoves = sParty_Spenser},
    },

    [TRAINER_GRETA] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_ARENA_TYCOON,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_ARENA_TYCOON_GRETA,
        .trainerName = _("Greta"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Greta),
        .party = {.NoItemDefaultMoves = sParty_Greta},
    },

    [TRAINER_NOLAND] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_FACTORY_HEAD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_FACTORY_HEAD_NOLAND,
        .trainerName = _("Noland"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Noland),
        .party = {.NoItemDefaultMoves = sParty_Noland},
    },

    [TRAINER_LUCY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PIKE_QUEEN,
        .encounterMusic_gender = F_TRAINER_FEMALE | TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PIKE_QUEEN_LUCY,
        .trainerName = _("Lucy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Lucy),
        .party = {.NoItemDefaultMoves = sParty_Lucy},
    },

    [TRAINER_BRANDON] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_PYRAMID_KING,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_PYRAMID_KING_BRANDON,
        .trainerName = _("Brandon"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_Brandon),
        .party = {.NoItemDefaultMoves = sParty_Brandon},
    },

//Elite Four
[TRAINER_LORELEI] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LORELEI,
        .trainerName = _("LORELEI"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_EliteFourLorelei),
        .party = {.ItemCustomMoves = sParty_EliteFourLorelei}
    },
    [TRAINER_BRUNO] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_BRUNO,
        .trainerName = _("BRUNO"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_EliteFourBruno),
        .party = {.ItemCustomMoves = sParty_EliteFourBruno}
    },
    [TRAINER_AGATHA] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_AGATHA,
        .trainerName = _("AGATHA"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_EliteFourAgatha),
        .party = {.ItemCustomMoves = sParty_EliteFourAgatha}
    },
    [TRAINER_LANCE] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET | F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_ELITE_FOUR,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ELITE_FOUR,
        .trainerPic = TRAINER_PIC_LANCE,
        .trainerName = _("LANCE"),
        .items = {ITEM_FULL_RESTORE, ITEM_FULL_RESTORE},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_EliteFourLance),
        .party = {.ItemCustomMoves = sParty_EliteFourLance}
    },

//Rival Battles
    [TRAINER_RIVAL_FIRST_BATTLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_RivalFirstBattle),
        .party = {.NoItemDefaultMoves = sParty_RivalFirstBattle},
    },

    [TRAINER_RIVAL_OPTIONAL_BATTLE] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_RivalOptionalBattle),
        .party = {.NoItemDefaultMoves = sParty_RivalOptionalBattle},
    },

    [TRAINER_RIVAL_CERULEAN_CITY] =
    {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_RivalCeruleanCity),
        .party = {.NoItemDefaultMoves = sParty_RivalCeruleanCity},
    },

    [TRAINER_RIVAL_SS_ANNE] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_RivalSSAnne),
        .party = {.ItemDefaultMoves = sParty_RivalSSAnne},
    },

    [TRAINER_RIVAL_POKEMON_TOWER_JOLTEON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPokemonTowerJolteon),
        .party = {.ItemCustomMoves = sParty_RivalPokemonTowerJolteon},
    },

    [TRAINER_RIVAL_POKEMON_TOWER_FLAREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPokemonTowerFlareon),
        .party = {.ItemCustomMoves = sParty_RivalPokemonTowerFlareon},
    },

    [TRAINER_RIVAL_POKEMON_TOWER_VAPOREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPokemonTowerVaporeon),
        .party = {.ItemCustomMoves = sParty_RivalPokemonTowerVaporeon},
    },

    [TRAINER_RIVAL_SILPH_CO_JOLTEON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalSilphCoJolteon),
        .party = {.ItemCustomMoves = sParty_RivalSilphCoJolteon},
    },

    [TRAINER_RIVAL_SILPH_CO_FLAREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalSilphCoFlareon),
        .party = {.ItemCustomMoves = sParty_RivalSilphCoFlareon},
    },

    [TRAINER_RIVAL_SILPH_CO_VAPOREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalSilphCoVaporeon),
        .party = {.ItemCustomMoves = sParty_RivalSilphCoVaporeon},
    },

    [TRAINER_RIVAL_ROUTE22_JOLTEON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRoute22Jolteon),
        .party = {.ItemCustomMoves = sParty_RivalRoute22Jolteon},
    },

    [TRAINER_RIVAL_ROUTE22_FLAREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRoute22Flareon),
        .party = {.ItemCustomMoves = sParty_RivalRoute22Flareon},
    },

    [TRAINER_RIVAL_ROUTE22_VAPOREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalRoute22Vaporeon),
        .party = {.ItemCustomMoves = sParty_RivalRoute22Vaporeon},
    },

    [TRAINER_RIVAL_CHAMPION_JOLTEON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalChampionJolteon),
        .party = {.ItemCustomMoves = sParty_RivalChampionJolteon},
    },

    [TRAINER_RIVAL_CHAMPION_FLAREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalChampionFlareon),
        .party = {.ItemCustomMoves = sParty_RivalChampionFlareon},
    },

    [TRAINER_RIVAL_CHAMPION_VAPOREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalChampionVaporeon),
        .party = {.ItemCustomMoves = sParty_RivalChampionVaporeon},
    },

    [TRAINER_RIVAL_POSTGAME_JOLTEON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPostGameJolteon),
        .party = {.ItemCustomMoves = sParty_RivalPostGameJolteon},
    },

    [TRAINER_RIVAL_POSTGAME_FLAREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPostGameFlareon),
        .party = {.ItemCustomMoves = sParty_RivalPostGameFlareon},
    },

    [TRAINER_RIVAL_POSTGAME_VAPOREON] =
    {
        .partyFlags = F_TRAINER_PARTY_HELD_ITEM | F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_RIVAL,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_RIVAL,
        .trainerPic = TRAINER_PIC_BLUE,
        .trainerName = _("{B_RIVAL_NAME}"),
        .items = {ITEM_POTION, ITEM_POTION, ITEM_POTION, ITEM_POTION},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_RivalPostGameVaporeon),
        .party = {.ItemCustomMoves = sParty_RivalPostGameVaporeon},
    },

//Viridian Forest
    [TRAINER_BUG_CATCHER_RICK] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Rick"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherRick),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherRick}
    },
    [TRAINER_BUG_CATCHER_DOUG] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Doug"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherDoug),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherDoug}
    },
    [TRAINER_BUG_CATCHER_SAMMY] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Sammy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherSammy),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherSammy}
    },
    [TRAINER_BUG_CATCHER_ANTHONY] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Anthony"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherAnthony),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherAnthony}
    },
    [TRAINER_BUG_CATCHER_CHARLIE] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Charlie"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherCharlie),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherCharlie}
    },

//Pewter Gym
    [TRAINER_CAMPER_LIAM] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_CAMPER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_CAMPER,
        .trainerName = _("Liam"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_CamperLiam),
        .party = {.NoItemCustomMoves = sParty_CamperLiam}
    },

    [TRAINER_LEADER_BROCK] = {
        .partyFlags = F_TRAINER_PARTY_CUSTOM_MOVESET,
        .trainerClass = TRAINER_CLASS_LEADER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BROCK,
        .trainerName = _("Brock"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY,
        .partySize = ARRAY_COUNT(sParty_LeaderBrock),
        .party = {.NoItemCustomMoves = sParty_LeaderBrock}
    },

//Route 3
    [REMATCHABLE_TRAINER_JANICE_1] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassJanice1),
        .party = {.NoItemDefaultMoves = sParty_LassJanice1}
    },
    [REMATCHABLE_TRAINER_JANICE_2] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassJanice2),
        .party = {.NoItemDefaultMoves = sParty_LassJanice2}
    },
    [REMATCHABLE_TRAINER_JANICE_3] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Janice"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassJanice3),
        .party = {.NoItemDefaultMoves = sParty_LassJanice3}





},











};


