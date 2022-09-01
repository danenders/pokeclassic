#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
}

// This shows your Hoenn Pokedex rating and not your National Dex.
const u8 *GetPokedexRatingText(u16 count)
{
    if (count < 10)
        return gOakDexRatingText_LessThan10;
    if (count < 20)
        return gOakDexRatingText_LessThan20;
    if (count < 30)
        return gOakDexRatingText_LessThan30;
    if (count < 40)
        return gOakDexRatingText_LessThan40;
    if (count < 50)
        return gOakDexRatingText_LessThan50;
    if (count < 60)
        return gOakDexRatingText_LessThan60;
    if (count < 70)
        return gOakDexRatingText_LessThan70;
    if (count < 80)
        return gOakDexRatingText_LessThan80;
    if (count < 90)
        return gOakDexRatingText_LessThan90;
    if (count < 100)
        return gOakDexRatingText_LessThan100;
    if (count < 110)
        return gOakDexRatingText_LessThan110;
    if (count < 120)
        return gOakDexRatingText_LessThan120;
    if (count < 130)
        return gOakDexRatingText_LessThan130;
    if (count < 140)
        return gOakDexRatingText_LessThan140;
    if (count < 150)
        return gOakDexRatingText_LessThan150;
    if (count < 151)
        return gOakDexRatingText_LessThan151;
    if (count == 151)
    {
        return gOakDexRatingText_DexCompleted;
    }
    if (count == HOENN_DEX_COUNT - 1)
    {
        return gOakDexRatingText_DexCompleted;
    }
    if (count == HOENN_DEX_COUNT)
        return gOakDexRatingText_DexCompleted;
    return gOakDexRatingText_LessThan10;
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
