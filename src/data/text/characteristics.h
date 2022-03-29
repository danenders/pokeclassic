static const u8 sCharacteristic00[] = _("Loves to eat.");
static const u8 sCharacteristic01[] = _("Proud of its power.");
static const u8 sCharacteristic02[] = _("Sturdy body.");
static const u8 sCharacteristic03[] = _("Likes to run.");
static const u8 sCharacteristic04[] = _("Highly curious.");
static const u8 sCharacteristic05[] = _("Strong willed.");
static const u8 sCharacteristic06[] = _("Takes plenty of siestas.");	//Is "Often dozes off" in Gens 4 and 5
static const u8 sCharacteristic07[] = _("Likes to thrash about.");
static const u8 sCharacteristic08[] = _("Capable of taking hits.");
static const u8 sCharacteristic09[] = _("Alert to sounds.");
static const u8 sCharacteristic10[] = _("Mischievous.");
static const u8 sCharacteristic11[] = _("Somewhat vain.");
static const u8 sCharacteristic12[] = _("Nods off a lot.");			//Is "Often scatters things" in Gens 4 and 5
static const u8 sCharacteristic13[] = _("A little quick tempered.");
static const u8 sCharacteristic14[] = _("Highly persistent.");
static const u8 sCharacteristic15[] = _("Impetuous and silly.");
static const u8 sCharacteristic16[] = _("Thoroughly cunning.");
static const u8 sCharacteristic17[] = _("Strongly defiant.");
static const u8 sCharacteristic18[] = _("Scatters things often.");
static const u8 sCharacteristic19[] = _("Likes to fight.");
static const u8 sCharacteristic20[] = _("Good endurance.");
static const u8 sCharacteristic21[] = _("Somewhat of a clown.");
static const u8 sCharacteristic22[] = _("Often lost in thought.");
static const u8 sCharacteristic23[] = _("Hates to lose.");
static const u8 sCharacteristic24[] = _("Likes to relax.");
static const u8 sCharacteristic25[] = _("Quick tempered.");
static const u8 sCharacteristic26[] = _("Good perseverance.");
static const u8 sCharacteristic27[] = _("Quick to flee.");
static const u8 sCharacteristic28[] = _("Very finicky.");
static const u8 sCharacteristic29[] = _("Somewhat stubborn.");

static const u8 sFlavorSpicy[] = _("Likes {COLOR 5}{SHADOW 6}spicy{COLOR 7}{SHADOW 8} food.");
static const u8 sFlavorDry[] = _("Likes {COLOR 5}{SHADOW 6}dry{COLOR 7}{SHADOW 8} food.");
static const u8 sFlavorSweet[] = _("Likes {COLOR 5}{SHADOW 6}sweet{COLOR 7}{SHADOW 8} food.");
static const u8 sFlavorBitter[] = _("Likes {COLOR 5}{SHADOW 6}bitter{COLOR 7}{SHADOW 8} food.");
static const u8 sFlavorSour[] = _("Likes {COLOR 5}{SHADOW 6}sour{COLOR 7}{SHADOW 8} food.");
static const u8 sFlavorNeutral[] = _("Happily eats anything.");

const u8 *const gCharacteristicPointers[30] = 
{
    sCharacteristic00,
	sCharacteristic01,
    sCharacteristic02,
	sCharacteristic03,
    sCharacteristic04,
	sCharacteristic05,
    sCharacteristic06,
	sCharacteristic07,
    sCharacteristic08,
	sCharacteristic09,
    sCharacteristic10,
	sCharacteristic11,
    sCharacteristic12,
	sCharacteristic13,
    sCharacteristic14,
	sCharacteristic15,
    sCharacteristic16,
	sCharacteristic17,
    sCharacteristic18,
	sCharacteristic19,
    sCharacteristic20,
	sCharacteristic21,
    sCharacteristic22,
	sCharacteristic23,
    sCharacteristic24,
	sCharacteristic25,
    sCharacteristic26,
	sCharacteristic27,
    sCharacteristic28,
	sCharacteristic29,
};

const u8 *const gNatureFlavorPointers[25] =
{
	[NATURE_HARDY]   = sFlavorNeutral,
	[NATURE_LONELY]  = sFlavorSpicy,
	[NATURE_BRAVE]   = sFlavorSpicy,
	[NATURE_ADAMANT] = sFlavorSpicy,
	[NATURE_NAUGHTY] = sFlavorSpicy,
	[NATURE_BOLD]    = sFlavorSour,
	[NATURE_DOCILE]  = sFlavorNeutral,
	[NATURE_RELAXED] = sFlavorSour,
	[NATURE_IMPISH]  = sFlavorSour,
	[NATURE_LAX]     = sFlavorSour,
	[NATURE_TIMID]   = sFlavorSweet,
	[NATURE_HASTY]   = sFlavorSweet,
	[NATURE_SERIOUS] = sFlavorNeutral,
	[NATURE_JOLLY]   = sFlavorSweet,
	[NATURE_NAIVE]   = sFlavorSweet,
	[NATURE_MODEST]  = sFlavorDry,
	[NATURE_MILD]    = sFlavorDry,
	[NATURE_QUIET]   = sFlavorDry,
	[NATURE_BASHFUL] = sFlavorNeutral,
	[NATURE_RASH]    = sFlavorDry,
	[NATURE_CALM]    = sFlavorBitter,
	[NATURE_GENTLE]  = sFlavorBitter,
	[NATURE_SASSY]   = sFlavorBitter,
	[NATURE_CAREFUL] = sFlavorBitter,
	[NATURE_QUIRKY]  = sFlavorNeutral,
};
