#include "video.h"

extern cu32 Black_Magic_1Tiles[];
extern cu32 Black_Magic_2Tiles[];
extern cu32 Blank_OctagonTiles[];
extern cu32 BlankTiles[];
extern cu32 Blood_Blade_1Tiles[];
extern cu32 Blood_Blade_2Tiles[];
extern cu32 Cranberry_1Tiles[];
extern cu32 Cranberry_2Tiles[];
extern cu32 Focus_1Tiles[];
extern cu32 Focus_2Tiles[];
extern cu32 Guard_1Tiles[];
extern cu32 Guard_2Tiles[];
extern cu32 Ice_Cream_1Tiles[];
extern cu32 Ice_Cream_2Tiles[];
extern cu32 Meat_1Tiles[];
extern cu32 Meat_2Tiles[];
extern cu32 Meditate_1Tiles[];
extern cu32 Meditate_2Tiles[];
extern cu32 Parry_1Tiles[];
extern cu32 Parry_2Tiles[];
extern cu32 Refresh_1Tiles[];
extern cu32 Refresh_2Tiles[];
extern cu32 Slash_1Tiles[];
extern cu32 Slash_2Tiles[];
extern cu32 Summon_Blade_1Tiles[];
extern cu32 Summon_Blade_2Tiles[];
extern cu32 Triple_Slash_1Tiles[];
extern cu32 Triple_Slash_2Tiles[];
extern cu32 Twin_Slash_1Tiles[];
extern cu32 Twin_Slash_2Tiles[];
extern cu32 TemplarTiles[];
//extern cu32 [];

Graphic graphicsList[]={
{.data = Black_Magic_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Black_Magic_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Blood_Blade_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Blood_Blade_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Cranberry_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Cranberry_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Focus_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Focus_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Guard_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Guard_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Ice_Cream_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Ice_Cream_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Meat_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Meat_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Meditate_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Meditate_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Parry_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Parry_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Refresh_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Refresh_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Slash_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Slash_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Summon_Blade_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Summon_Blade_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Triple_Slash_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Triple_Slash_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Twin_Slash_1Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Twin_Slash_2Tiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Blank_OctagonTiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = BlankTiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = TemplarTiles, .numWords = 6528, .width = 8, .height = 4, .defaultPalette = 0, .shape = 1, .size = 3},
};
//{.data = , .size = 32, .width = 2, .height = 2, .defaultPalette = 1},