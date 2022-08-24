#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

void CB2_InitMainMenu(void);
//void CreateYesNoMenuParameterized(u8 a, u8 b, u16 c, u16 d, u8 e, u8 f);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);

#endif // GUARD_MAIN_MENU_H
