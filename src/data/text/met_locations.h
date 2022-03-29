#define REGION_UNKNOWN	0
#define REGION_KANTO	1
#define REGION_HOENN	2
#define REGION_ORRE		3

//Battle Tower from Ruby/Sapphire
#define MAPSEC_BATTLE_TOWER					0xFC

//Orre met locations
#define MAPSEC_DISTANT_LAND					0x00
#define MAPSEC_OUTSKIRT_STAND				0x01
#define MAPSEC_PHENAC_CITY					0x02
#define MAPSEC_MAYORS_HOUSE					0x03
#define MAPSEC_PRE_GYM						0x04
#define MAPSEC_PHENAC_STADIUM				0x05
#define MAPSEC_PYRITE_TOWN					0x06
#define MAPSEC_PYRITE_BLDG					0x07
#define MAPSEC_PYRITE_CAVE					0x08
#define MAPSEC_MIRORS_HIDEOUT				0x09
#define MAPSEC_PYRITE_COLOSSEUM				0x10
#define MAPSEC_AGATE_VILLAGE				0x11
#define MAPSEC_RELIC_CAVE					0x12
#define MAPSEC_THE_UNDER					0x13
#define MAPSEC_THE_UNDER_SUBWAY				0x14
#define MAPSEC_UNDER_COLOSSEUM				0x15
#define MAPSEC_DEEP_COLOSSEUM				0x16
#define MAPSEC_FRONT_OF_LAB					0x17
#define MAPSEC_LABORATORY					0x18
#define MAPSEC_MT_BATTLE					0x19
#define MAPSEC_MTBTL_COLOSSEUM				0x20
#define MAPSEC_REALGAM_TOWER				0x21
#define MAPSEC_REALGAMTWR_DOME				0x22
#define MAPSEC_REALGAMTWR_LOBBY				0x23
#define MAPSEC_TOWER_COLOSSEUM				0x24
#define MAPSEC_ORRE_COLOSSEUM				0x25
#define MAPSEC_SNAGEM_HIDEOUT				0x26
#define MAPSEC_REALGAM_TOWER_2F				0x27
#define MAPSEC_CIPHER_LAB					0x28
#define MAPSEC_S_S_LIBRA					0x29
#define MAPSEC_CIPHER_KEY_LAIR				0x30
#define MAPSEC_CITADARK_ISLE				0x31
#define MAPSEC_ROCK							0x32
#define MAPSEC_OASIS						0x33
#define MAPSEC_CAVE							0x34
#define MAPSEC_POKEMON_HQ_LAB				0x35
#define MAPSEC_GATEON_PORT					0x36
#define MAPSEC_KAMINKOS_HOUSE				0x37

#define ORRE_MAPSEC_START					MAPSEC_DISTANT_LAND
#define ORRE_MAPSEC_END						MAPSEC_KAMINKOS_HOUSE
#define ORRE_MAPSEC_COUNT				    (ORRE_MAPSEC_END - ORRE_MAPSEC_START + 1)

#if CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", Kanto");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", Orre");
#else
static const u8 sRegionString_Unknown[] = _("");
static const u8 sRegionString_Kanto[] = _(", KANTO");
static const u8 sRegionString_Hoenn[] = _("");
static const u8 sRegionString_Orre[] = _(", ORRE");
#endif

const u8 *const gRegionStringPointers[] =
{
	[REGION_UNKNOWN] = sRegionString_Unknown,
	[REGION_KANTO]   = sRegionString_Kanto,
	[REGION_HOENN]   = sRegionString_Hoenn,
	[REGION_ORRE]    = sRegionString_Orre,
};

const u8 gText_TrainerMemo_Standard[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nMet at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Hatched[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nHatched at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Trade[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\nObtained in {DYNAMIC 0}a trade{DYNAMIC 1}.\n\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Fateful[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\nObtained in a\n{DYNAMIC 0}fateful encounter{DYNAMIC 1} at {LV_2}{DYNAMIC 3}.\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_Untrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nApparently met at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_HatchedUntrusted[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature.\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 5}{DYNAMIC 1}\nApparently hatched at {LV_2}{DYNAMIC 3}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
#if CONFIG_DECAPITALIZE_MET_LOCATION_STRINGS
const u8 gText_TrainerMemo_EggFromDayCare[] = _("An odd Pokémon Egg found\nby {DYNAMIC 0}the Day Care couple{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _("An peculiar Pokémon Egg\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _("A peculiar Pokémon Egg\nobtained at {DYNAMIC 0}a nice place{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _("A peculiar Pokémon Egg\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _("A Pokémon Egg obtained\nat {DYNAMIC 0}the hot springs{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _("An odd Pokémon Egg\nobtained from {DYNAMIC 0}a traveler{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _("An odd Pokémon Egg found\nby {DYNAMIC 0}the Day Care couple{DYNAMIC 1}\nin the {DYNAMIC 0}Kanto{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _("A Pokémon Egg obtained\nfrom {DYNAMIC 0}Brigette{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _("A very mysterious\nPokémon Egg.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}'s old friend\nfrom {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\nreceived from {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nin {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\ngiven to {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} by his dad\nin {DYNAMIC 0}Orre{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");

//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("Battle Tower");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("A Distant Land");
static const u8 sMapName_OutskirtStand[] = _("Outskirt Stand");
static const u8 sMapName_PhenacCity[] = _("Phenac City");
static const u8 sMapName_MayorsHouse[] = _("Mayor's House");
static const u8 sMapName_PreGym[] = _("Pre Gym");
static const u8 sMapName_PhenacStadium[] = _("Phenac Stadium");
static const u8 sMapName_PyriteTown[] = _("Pyrite Town");
static const u8 sMapName_PyriteBldg[] = _("Pyrite Bldg");
static const u8 sMapName_PyriteCave[] = _("Pyrite Cave");
static const u8 sMapName_MirorsHideout[] = _("Miror's Hideout");
static const u8 sMapName_PyriteColosseum[] = _("Pyrite Colosseum");
static const u8 sMapName_AgateVillage[] = _("Agate Village");
static const u8 sMapName_RelicCave[] = _("Relic Cave");
static const u8 sMapName_TheUnder[] = _("The Under");
static const u8 sMapName_TheUnderSubway[] = _("The Under Subway");
static const u8 sMapName_UnderColosseum[] = _("Under Colosseum");
static const u8 sMapName_DeepColosseum[] = _("Deep Colosseum");
static const u8 sMapName_FrontOfLab[] = _("Front Of Lab");
static const u8 sMapName_Laboratory[] = _("Laboratory");
static const u8 sMapName_MtBattle[] = _("Mt. Battle");
static const u8 sMapName_MtBtlColosseum[] = _("Mt.Btl Colosseum");
static const u8 sMapName_RealgamTower[] = _("Realgam Tower");
static const u8 sMapName_RealgamTwrDome[] = _("Realgamtwr Dome");
static const u8 sMapName_RealgamTwrLobby[] = _("Realgamtwr Lobby");
static const u8 sMapName_TowerColosseum[] = _("Tower Colosseum");
static const u8 sMapName_OrreColosseum[] = _("Orre Colosseum");
static const u8 sMapName_SnagemHideout[] = _("Snagem Hideout");
static const u8 sMapName_RealgamTower2F[] = _("Realgam Tower 2F");
static const u8 sMapName_CipherLab[] = _("Cipher Lab");
static const u8 sMapName_SSLibra[] = _("S.S. Libra");
static const u8 sMapName_CipherKeyLair[] = _("Cipher Key Lair");
static const u8 sMapName_CitadarkIsle[] = _("Citadark Isle");
static const u8 sMapName_Rock[] = _("Rock");
static const u8 sMapName_Oasis[] = _("Oasis");
static const u8 sMapName_Cave[] = _("Cave");
static const u8 sMapName_PokemonHQLab[] = _("Pokémon HQ Lab");
static const u8 sMapName_GateonPort[] = _("Gateon Port");
static const u8 sMapName_KaminkosHouse[] = _("Kaminko's House");
#else
const u8 gText_TrainerMemo_EggFromDayCare[] = _("An odd POKÉMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggTraded[] = _("An peculiar POKÉMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFateful[] = _("A peculiar POKÉMON EGG\nobtained at {DYNAMIC 0}a nice place{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFatefulTraded[] = _("A peculiar POKÉMON EGG\nobtained in a trade.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromHotSprings[] = _("A POKÉMON EGG obtained\nat {DYNAMIC 0}the hot springs{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromTraveler[] = _("An odd POKÉMON EGG\nobtained from {DYNAMIC 0}a traveler{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromKanto[] = _("An odd POKÉMON EGG found\nby {DYNAMIC 0}the DAY CARE couple{DYNAMIC 1}\nin the {DYNAMIC 0}KANTO{DYNAMIC 1} region.\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_EggFromBrigette[] = _("A POKÉMON EGG obtained\nfrom {DYNAMIC 0}BRIGETTE{DYNAMIC 1}.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_BadEgg[] = _("A very mysterious\nPOKÉMON EGG.\n\n\n“The Egg Watch”\n{DYNAMIC 2}");
const u8 gText_TrainerMemo_OldFriend[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\n{DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}'s old friend\nfrom {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ReceivedFrom[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\nreceived from {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1}\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");
const u8 gText_TrainerMemo_ObtainedFromDad[] = _("{DYNAMIC 0}{DYNAMIC 2}{DYNAMIC 1} nature,\n\ngiven to {DYNAMIC 0}{DYNAMIC 4}{DYNAMIC 1} by his dad\nin {DYNAMIC 0}ORRE{DYNAMIC 1}.\n\n{DYNAMIC 6}\n{DYNAMIC 7}");


//Battle Tower from Ruby/Sapphire
const u8 gMapName_BattleTower[] = _("BATTLE TOWER");

//Orre met locations
static const u8 sMapName_DistantLand[] = _("A DISTANT LAND");
static const u8 sMapName_OutskirtStand[] = _("OUTSKIRT STAND");
static const u8 sMapName_PhenacCity[] = _("PHENAC CITY");
static const u8 sMapName_MayorsHouse[] = _("MAYOR'S HOUSE");
static const u8 sMapName_PreGym[] = _("PRE GYM");
static const u8 sMapName_PhenacStadium[] = _("PHENAC STADIUM");
static const u8 sMapName_PyriteTown[] = _("PYRITE TOWN");
static const u8 sMapName_PyriteBldg[] = _("PYRITE BLDG");
static const u8 sMapName_PyriteCave[] = _("PYRITE CAVE");
static const u8 sMapName_MirorsHideout[] = _("MIROR'S HIDEOUT");
static const u8 sMapName_PyriteColosseum[] = _("PYRITE COLOSSEUM");
static const u8 sMapName_AgateVillage[] = _("AGATE VILLAGE");
static const u8 sMapName_RelicCave[] = _("RELIC CAVE");
static const u8 sMapName_TheUnder[] = _("THE UNDER");
static const u8 sMapName_TheUnderSubway[] = _("THE UNDER SUBWAY");
static const u8 sMapName_UnderColosseum[] = _("UNDER COLOSSEUM");
static const u8 sMapName_DeepColosseum[] = _("DEEP COLOSSEUM");
static const u8 sMapName_FrontOfLab[] = _("FRONT OF LAB");
static const u8 sMapName_Laboratory[] = _("LABORATORY");
static const u8 sMapName_MtBattle[] = _("MT. BATTLE");
static const u8 sMapName_MtBtlColosseum[] = _("MT.BTL COLOSSEUM");
static const u8 sMapName_RealgamTower[] = _("REALGAM TOWER");
static const u8 sMapName_RealgamTwrDome[] = _("REALGAMTWR DOME");
static const u8 sMapName_RealgamTwrLobby[] = _("REALGAMTWR LOBBY");
static const u8 sMapName_TowerColosseum[] = _("TOWER COLOSSEUM");
static const u8 sMapName_OrreColosseum[] = _("ORRE COLOSSEUM");
static const u8 sMapName_SnagemHideout[] = _("SNAGEM HIDEOUT");
static const u8 sMapName_RealgamTower2F[] = _("REALGAM TOWER 2F");
static const u8 sMapName_CipherLab[] = _("CIPHER LAB");
static const u8 sMapName_SSLibra[] = _("S.S. LIBRA");
static const u8 sMapName_CipherKeyLair[] = _("CIPHER KEY LAIR");
static const u8 sMapName_CitadarkIsle[] = _("CITADARK ISLE");
static const u8 sMapName_Rock[] = _("ROCK");
static const u8 sMapName_Oasis[] = _("OASIS");
static const u8 sMapName_Cave[] = _("CAVE");
static const u8 sMapName_PokemonHQLab[] = _("POKÉMON HQ LAB");
static const u8 sMapName_GateonPort[] = _("GATEON PORT");
static const u8 sMapName_KaminkosHouse[] = _("KAMINKO'S HOUSE");
#endif

const u8 *const gOrreMapNamePointers[] =
{
	[MAPSEC_DISTANT_LAND]               = sMapName_DistantLand,
	[MAPSEC_OUTSKIRT_STAND]             = sMapName_OutskirtStand,
	[MAPSEC_PHENAC_CITY]                = sMapName_PhenacCity,
	[MAPSEC_MAYORS_HOUSE]               = sMapName_MayorsHouse,
	[MAPSEC_PRE_GYM]                    = sMapName_PreGym,
	[MAPSEC_PHENAC_STADIUM]             = sMapName_PhenacStadium,
	[MAPSEC_PYRITE_TOWN]                = sMapName_PyriteTown,
	[MAPSEC_PYRITE_BLDG]                = sMapName_PyriteBldg,
	[MAPSEC_PYRITE_CAVE]                = sMapName_PyriteCave,
	[MAPSEC_MIRORS_HIDEOUT]             = sMapName_MirorsHideout,
	[MAPSEC_PYRITE_COLOSSEUM]           = sMapName_PyriteColosseum,
	[MAPSEC_AGATE_VILLAGE]              = sMapName_AgateVillage,
	[MAPSEC_RELIC_CAVE]                 = sMapName_RelicCave,
	[MAPSEC_THE_UNDER]                  = sMapName_TheUnder,
	[MAPSEC_THE_UNDER_SUBWAY]           = sMapName_TheUnderSubway,
	[MAPSEC_UNDER_COLOSSEUM]            = sMapName_UnderColosseum,
	[MAPSEC_DEEP_COLOSSEUM]             = sMapName_DeepColosseum,
	[MAPSEC_FRONT_OF_LAB]               = sMapName_FrontOfLab,
	[MAPSEC_LABORATORY]                 = sMapName_Laboratory,
	[MAPSEC_MT_BATTLE]                  = sMapName_MtBattle,
	[MAPSEC_MTBTL_COLOSSEUM]            = sMapName_MtBtlColosseum,
	[MAPSEC_REALGAM_TOWER]              = sMapName_RealgamTower,
	[MAPSEC_REALGAMTWR_DOME]            = sMapName_RealgamTwrDome,
	[MAPSEC_REALGAMTWR_LOBBY]           = sMapName_RealgamTwrLobby,
	[MAPSEC_TOWER_COLOSSEUM]            = sMapName_TowerColosseum,
	[MAPSEC_ORRE_COLOSSEUM]             = sMapName_OrreColosseum,
	[MAPSEC_SNAGEM_HIDEOUT]             = sMapName_SnagemHideout,
	[MAPSEC_REALGAM_TOWER_2F]           = sMapName_RealgamTower2F,
	[MAPSEC_CIPHER_LAB]                 = sMapName_CipherLab,
	[MAPSEC_S_S_LIBRA]                  = sMapName_SSLibra,
	[MAPSEC_CIPHER_KEY_LAIR]            = sMapName_CipherKeyLair,
	[MAPSEC_CITADARK_ISLE]              = sMapName_CitadarkIsle,
	[MAPSEC_ROCK]                       = sMapName_Rock,
	[MAPSEC_OASIS]                      = sMapName_Oasis,
	[MAPSEC_CAVE]                       = sMapName_Cave,
	[MAPSEC_POKEMON_HQ_LAB]             = sMapName_PokemonHQLab,
	[MAPSEC_GATEON_PORT]                = sMapName_GateonPort,
	[MAPSEC_KAMINKOS_HOUSE]             = sMapName_KaminkosHouse
};
