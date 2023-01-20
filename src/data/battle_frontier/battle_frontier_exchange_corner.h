static const u16 sFrontierExchangeCorner_Mints[] =
{
    ITEM_ADAMANT_MINT,
    ITEM_BOLD_MINT,
    ITEM_BRAVE_MINT,
    ITEM_CALM_MINT,
    ITEM_CAREFUL_MINT,
    ITEM_GENTLE_MINT,
    ITEM_HASTY_MINT,
    ITEM_IMPISH_MINT,
    ITEM_JOLLY_MINT,
    ITEM_LAX_MINT,
    ITEM_LONELY_MINT,
    ITEM_MILD_MINT,
    ITEM_MODEST_MINT,
    ITEM_NAIVE_MINT,
    ITEM_NAUGHTY_MINT,
    ITEM_QUIET_MINT,
    ITEM_RASH_MINT,
    ITEM_RELAXED_MINT,
    ITEM_SASSY_MINT,
    ITEM_SERIOUS_MINT,
    ITEM_TIMID_MINT,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_Ability[] =
{
    ITEM_ABILITY_CAPSULE,
    ITEM_ABILITY_PATCH,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_Vitamins[] =
{
    ITEM_PROTEIN,
    ITEM_CALCIUM,
    ITEM_IRON,
    ITEM_ZINC,
    ITEM_CARBOS,
    ITEM_HP_UP,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_Candy[] =
{
    ITEM_HP_CANDY,
    ITEM_ATK_CANDY,
    ITEM_DEF_CANDY,
    ITEM_SPATK_CANDY,
    ITEM_SPDEF_CANDY,
    ITEM_SPEED_CANDY,
    ITEM_MAX_CANDY,
    ITEM_RESET_CANDY,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_HoldItems[] =
{
    ITEM_LEFTOVERS,
    ITEM_WHITE_HERB,
    ITEM_QUICK_CLAW,
    ITEM_MENTAL_HERB,
    ITEM_BRIGHT_POWDER,
    ITEM_CHOICE_BAND,
    ITEM_KINGS_ROCK,
    ITEM_FOCUS_BAND,
    ITEM_SCOPE_LENS,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_HoldItems2[] =
{
    ITEM_RAZOR_FANG,
    ITEM_RAZOR_CLAW,
    ITEM_CHOICE_SPECS,
    ITEM_CHOICE_SCARF,
    ITEM_MUSCLE_BAND,
    ITEM_LIFE_ORB,
    ITEM_POWER_HERB,
    ITEM_WISE_GLASSES,
    ITEM_RED_CARD,
    0xFFFF
};

static const u16 sFrontierExchangeCorner_PowerItems[] =
{
    ITEM_POWER_ANKLET,
    ITEM_POWER_BRACER,
    ITEM_POWER_BELT,
    ITEM_POWER_BAND,
    ITEM_POWER_WEIGHT,
    ITEM_POWER_LENS,
    0xFFFF
};

static const u8 *const sFrontierExchangeCorner_MintsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_AdamantMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_BoldMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_BraveMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CalmMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CarefulMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_GentleMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_HastyMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ImpishMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_JollyMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LaxMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LonelyMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_MildMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ModestMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_NaiveMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_NaughtyMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_QuietMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_RashMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_RelaxedMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_SassyMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_SeriousMintDesc,
    BattleFrontier_ExchangeServiceCorner_Text_TimidMintDesc,
    gText_Exit,
};

static const u8 *const sFrontierExchangeCorner_AbilityDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_AbilityCapsuleDesc,
    BattleFrontier_ExchangeServiceCorner_Text_AbilityPatchDesc,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_VitaminsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc,
    BattleFrontier_ExchangeServiceCorner_Text_IronDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ZincDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc,
    BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_HoldItemsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc,
    BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc,
    BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc,
    BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc,
    BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc,
    BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc,
    BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_HoldItemsDescriptions2[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_RazorFang,
    BattleFrontier_ExchangeServiceCorner_Text_RazorClaw,
    BattleFrontier_ExchangeServiceCorner_Text_ChoiceSpecs,
    BattleFrontier_ExchangeServiceCorner_Text_ChoiceScarf,
    BattleFrontier_ExchangeServiceCorner_Text_MuscleBand,
    BattleFrontier_ExchangeServiceCorner_Text_LifeOrb,
    BattleFrontier_ExchangeServiceCorner_Text_PowerHerb,
    BattleFrontier_ExchangeServiceCorner_Text_WiseGlasses,
    BattleFrontier_ExchangeServiceCorner_Text_RedCard,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_PowerItemsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_PowerAnklet,
    BattleFrontier_ExchangeServiceCorner_Text_PowerBracer,
    BattleFrontier_ExchangeServiceCorner_Text_PowerBelt,
    BattleFrontier_ExchangeServiceCorner_Text_PowerBand,
    BattleFrontier_ExchangeServiceCorner_Text_PowerWeight,
    BattleFrontier_ExchangeServiceCorner_Text_PowerLens,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_CandyDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_HPCandy,
    BattleFrontier_ExchangeServiceCorner_Text_ATKCandy,
    BattleFrontier_ExchangeServiceCorner_Text_DEFCandy,
    BattleFrontier_ExchangeServiceCorner_Text_SPATKCandy,
    BattleFrontier_ExchangeServiceCorner_Text_SPDEFCandy,
    BattleFrontier_ExchangeServiceCorner_Text_SPEEDCandy,
    BattleFrontier_ExchangeServiceCorner_Text_MAXCandy,
    BattleFrontier_ExchangeServiceCorner_Text_RESETCandy,
    gText_Exit
};
