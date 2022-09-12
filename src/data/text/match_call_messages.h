const u8 gText_MatchCallLass_Janice_Strategy[] = _("I'll show you some guts!");
const u8 gText_MatchCallLass_Janice_Pokemon[] = _("Cute Pokémon are my faves!");
const u8 gText_MatchCallLass_Janice_Intro1[] = _("After a battle, I always");
const u8 gText_MatchCallLass_Janice_Intro2[] = _("bathe with my Pokémon.");

const u8 gText_MatchCallYoungster_Ben_Strategy[] = _("I like shorts!");
const u8 gText_MatchCallYoungster_Ben_Pokemon[] = _("Cool Pokémon are my faves!");
const u8 gText_MatchCallYoungster_Ben_Intro1[] = _("Shorts are the ultimate");
const u8 gText_MatchCallYoungster_Ben_Intro2[] = _("expression of freedom.");

const u8 gText_MatchCallCamper_Shane_Strategy[] = _("I get scared easily.");
const u8 gText_MatchCallCamper_Shane_Pokemon[] = _("Brave Pokémon are my faves!");
const u8 gText_MatchCallCamper_Shane_Intro1[] = _("I want to be brave enough");
const u8 gText_MatchCallCamper_Shane_Intro2[] = _("to take on Nugget Bridge!");

const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] =
{
	[REMATCH_JANICE] = MCFLAVOR(Lass_Janice),
	[REMATCH_BEN] = MCFLAVOR(Youngster_Ben),
	[REMATCH_SHANE] = MCFLAVOR(Camper_Shane),
};
