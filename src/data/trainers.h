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
        .trainerName = _("Lorelei"),
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
        .trainerName = _("Bruno"),
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
        .trainerName = _("Agatha"),
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
        .trainerName = _("Lance"),
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
    [REMATCHABLE_TRAINER_LASS_JANICE_1] = {
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
    [REMATCHABLE_TRAINER_LASS_JANICE_2] = {
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
    [REMATCHABLE_TRAINER_LASS_JANICE_3] = {
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
    [TRAINER_BUG_CATCHER_COLTON] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Colton"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherColton),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherColton}
    },
    [REMATCHABLE_TRAINER_YOUNGSTER_BEN_1] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_YoungsterBen),
        .party = {.NoItemDefaultMoves = sParty_YoungsterBen}
    },
    [REMATCHABLE_TRAINER_YOUNGSTER_BEN_2] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_YoungsterBen2),
        .party = {.NoItemDefaultMoves = sParty_YoungsterBen2}
    },
    [REMATCHABLE_TRAINER_YOUNGSTER_BEN_3] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Ben"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_YoungsterBen3),
        .party = {.NoItemDefaultMoves = sParty_YoungsterBen3}
    },
    [TRAINER_BUG_CATCHER_GREG] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Greg"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherGreg),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherGreg}
    },
    [TRAINER_YOUNGSTER_CALVIN] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Calvin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_YoungsterCalvin),
        .party = {.NoItemDefaultMoves = sParty_YoungsterCalvin}
    },
    [TRAINER_LASS_SALLY] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Sally"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassSally),
        .party = {.NoItemDefaultMoves = sParty_LassSally}
    },    
    [TRAINER_BUG_CATCHER_JAMES] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("James"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherJames),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherJames}
    },
    [TRAINER_LASS_ROBIN] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Robin"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassRobin),
        .party = {.NoItemDefaultMoves = sParty_LassRobin}
    },

//Route 4
    [TRAINER_LASS_CRISSY] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Crissy"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassCrissy),
        .party = {.NoItemDefaultMoves = sParty_LassCrissy}
    },

//Mt Moon
    [TRAINER_HIKER_MARCOS] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_HIKER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_HIKER,
        .trainerPic = TRAINER_PIC_HIKER,
        .trainerName = _("Marcos"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_HikerMarcos),
        .party = {.NoItemDefaultMoves = sParty_HikerMarcos}
    },
    [TRAINER_YOUNGSTER_JOSH] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_YOUNGSTER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_YOUNGSTER,
        .trainerName = _("Josh"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_YoungsterJosh),
        .party = {.NoItemDefaultMoves = sParty_YoungsterJosh}
    },
    [TRAINER_LASS_MIRIAM] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Miriam"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassMiriam),
        .party = {.NoItemDefaultMoves = sParty_LassMiriam}
    },
    [TRAINER_LASS_IRIS] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_LASS,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_FEMALE | F_TRAINER_FEMALE,
        .trainerPic = TRAINER_PIC_LASS,
        .trainerName = _("Iris"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_LassIris),
        .party = {.NoItemDefaultMoves = sParty_LassIris}
    },
    [TRAINER_SUPER_NERD_JOVAN] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Jovan"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_SuperNerdJovan),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdJovan}
    },
    [TRAINER_BUG_CATCHER_KENT] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Kent"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherKent),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherKent}
    },
    [TRAINER_BUG_CATCHER_ROBBY] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_BUG_CATCHER,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_MALE,
        .trainerPic = TRAINER_PIC_BUG_CATCHER,
        .trainerName = _("Robby"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_BugCatcherRobby),
        .party = {.NoItemDefaultMoves = sParty_BugCatcherRobby}
    },
    [TRAINER_TEAM_ROCKET_GRUNT] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TeamRocketGrunt),
        .party = {.NoItemDefaultMoves = sParty_TeamRocketGrunt}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_2] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TeamRocketGrunt2),
        .party = {.NoItemDefaultMoves = sParty_TeamRocketGrunt2}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_3] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_F,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TeamRocketGrunt3),
        .party = {.NoItemDefaultMoves = sParty_TeamRocketGrunt3}
    },
    [TRAINER_TEAM_ROCKET_GRUNT_4] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TeamRocketGrunt4),
        .party = {.NoItemDefaultMoves = sParty_TeamRocketGrunt4}
    },
    [TRAINER_SUPER_NERD_MIGUEL] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_SUPER_NERD,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS,
        .trainerPic = TRAINER_PIC_SUPER_NERD,
        .trainerName = _("Miguel"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_SuperNerdMiguel),
        .party = {.NoItemDefaultMoves = sParty_SuperNerdMiguel}
    },
    [TRAINER_ROCKET_DUO_1] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_ROCKET_DUO,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_ROCKET,
        .trainerPic = TRAINER_PIC_ROCKET_DUO,
        .trainerName = _("Duo"),
        .items = {},
        .doubleBattle = TRUE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE || AI_FLAG_TRY_TO_FAINT,
        .partySize = ARRAY_COUNT(sParty_RocketDuo1),
        .party = {.NoItemDefaultMoves = sParty_RocketDuo1}
    },
//Cerulean City
    [TRAINER_TEAM_ROCKET_GRUNT_5] = {
        .partyFlags = 0,
        .trainerClass = TRAINER_CLASS_TEAM_ROCKET,
        .encounterMusic_gender = TRAINER_ENCOUNTER_MUSIC_AQUA,
        .trainerPic = TRAINER_PIC_ROCKET_GRUNT_M,
        .trainerName = _("Grunt"),
        .items = {},
        .doubleBattle = FALSE,
        .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
        .partySize = ARRAY_COUNT(sParty_TeamRocketGrunt5),
        .party = {.NoItemDefaultMoves = sParty_TeamRocketGrunt5}
    },

};
