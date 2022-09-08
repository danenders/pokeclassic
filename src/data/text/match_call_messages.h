const u8 gText_MatchCallLass_Janice_Strategy[] = _("I'll show you some guts!");
const u8 gText_MatchCallLass_Janice_Pokemon[] = _("Cute Pokémon are my faves!");
const u8 gText_MatchCallLass_Janice_Intro1[] = _("After a battle, I always");
const u8 gText_MatchCallLass_Janice_Intro2[] = _("bathe with my Pokémon.");

const u8 gText_MatchCallYoungster_Ben_Strategy[] = _("I like shorts!");
const u8 gText_MatchCallYoungster_Ben_Pokemon[] = _("Cool Pokémon are my faves!");
const u8 gText_MatchCallYoungster_Ben_Intro1[] = _("Shorts are the ultimate");
const u8 gText_MatchCallYoungster_Ben_Intro2[] = _("expression of freedom.");

const u8 gText_MatchCall_Rival_Strategy[] = _("I'm in the mood for battle!");
const u8 gText_MatchCall_Rival_Pokemon[] = _("My Pokémon is the strongest!");
const u8 gText_MatchCall_Rival_Intro1[] = _("Hey, {PLAYER}! Thanks for");
const u8 gText_MatchCall_Rival_Intro2[] = _("coming to lose to me!");

const u8 *const gMatchCallFlavorTexts[REMATCH_TABLE_ENTRIES][CHECK_PAGE_ENTRY_COUNT] =
{
	[REMATCH_JANICE] = MCFLAVOR(Lass_Janice),
	[REMATCH_BEN] = MCFLAVOR(Youngster_Ben),
};
