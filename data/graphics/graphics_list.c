#include "video.h"

extern cu32 EmptyTiles[];
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
extern cu32 Wall_BackgroundTiles[];
extern cu32 Wall_BackgroundMap[];
extern cu32 WitchTiles[];
extern cu32 Healthbar_BackingTiles[];
extern cu32 Healthbar_FrontTiles[];
extern cu32 IntentsTiles[];
extern cu32 IntentsMap[];
extern cu32 Player_TurnTiles[];
extern cu32 Witch_TurnTiles[];
extern cu32 item_throwTiles[];
extern cu32 Templar_bonusesTiles[];
extern cu32 Witch_AttacksTiles[];
extern cu32 Turn_MarkerTiles[];
extern cu32 DefenseTiles[];
extern cu32 CriticalTiles[];
extern cu32 DeathblowTiles[];
extern cu32 Exp_BarTiles[];
extern cu32 Exp_Bar_TipTiles[];
extern cu32 SkillsTiles[];
extern cu32 SkillsMetaTiles[];
extern cu32 Resign_ButtonTiles[];
extern cu32 Stats_ScreenTiles[];
extern cu32 Stats_ScreenMap[];
extern cu32 Main_MenuTiles[];
extern cu32 Main_MenuMap[];
extern cu32 Animated_SwordTiles[];
extern cu32 Animated_SwordMetaTiles[];
extern cu32 Press_Any_ButtonTiles[];
extern cu32 Skill_Tree_BackgroundTiles[];
extern cu32 Skill_Tree_BackgroundMap[];
extern cu32 black_magic_animTiles[];
extern cu32 black_magic_animMetaTiles[];
extern cu32 slash_animationTiles[];
extern cu32 slash_animationMetaTiles[];
extern cu32 Twin_Slash_animTiles[];
extern cu32 Twin_Slash_animMetaTiles[];
extern cu32 Triple_Slash_animTiles[];
extern cu32 Triple_Slash_animMetaTiles[];
extern cu32 blood_blade_animTiles[];
extern cu32 blood_blade_animMetaTiles[];
extern cu32 Summon_Blade_AnimTiles[];
extern cu32 Summon_Blade_AnimMetaTiles[];
extern cu32 Drain_animTiles[];
extern cu32 Drain_animMetaTiles[];
extern cu32 Missile_animTiles[];
extern cu32 Missile_animMetaTiles[];
extern cu32 Blood_Missile_animTiles[];
extern cu32 Blood_Missile_animMetaTiles[];
//extern cu32 [];

Graphic graphicsList[]={
{.data = EmptyTiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
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
{.data = TemplarTiles, .numWords = 6528, .width = 8, .height = 4, .defaultPalette = 1, .shape = 1, .size = 3},
{.data = Wall_BackgroundTiles, .numWords = 280, .width = 30, .height = 20, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Wall_BackgroundMap, .numWords = 300, .width = 30, .height = 20, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = WitchTiles, .numWords = 15360, .width = 8, .height = 8, .defaultPalette = 1, .shape = 0, .size = 3},
{.data = Healthbar_BackingTiles, .numWords = 32, .width = 4, .height = 1, .defaultPalette = 1, .shape = 1, .size = 1},
{.data = Healthbar_FrontTiles, .numWords = 272, .width = 2, .height = 1, .defaultPalette = 1, .shape = 1, .size = 0},
{.data = IntentsTiles, .numWords = 120, .width = 2, .height = 2, .defaultPalette = 0, .shape = 0, .size = 1},
{.data = Player_TurnTiles, .numWords = 256, .width = 8, .height = 4, .defaultPalette = 1, .shape = 1, .size = 3},
{.data = Witch_TurnTiles, .numWords = 256, .width = 8, .height = 4, .defaultPalette = 1, .shape = 1, .size = 3},
{.data = item_throwTiles, .numWords = 1728, .width = 2, .height = 4, .defaultPalette = 1, .shape = 2, .size = 2},
{.data = Templar_bonusesTiles, .numWords = 4480, .width = 4, .height = 4, .defaultPalette = 1, .shape = 0, .size = 2},
{.data = Witch_AttacksTiles, .numWords = 12288, .width = 8, .height = 8, .defaultPalette = 1, .shape = 0, .size = 3},
{.data = Turn_MarkerTiles, .numWords = 8, .width = 1, .height = 1, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = DefenseTiles, .numWords = 16, .width = 1, .height = 1, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = CriticalTiles, .numWords = 32, .width = 2, .height = 2, .defaultPalette = 1, .shape = 0, .size = 1},
{.data = DeathblowTiles, .numWords = 256, .width = 8, .height = 4, .defaultPalette = 0, .shape = 1, .size = 3},
{.data = Exp_BarTiles, .numWords = 208, .width = 10, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Exp_Bar_TipTiles, .numWords = 80, .width = 10, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = SkillsTiles, .numWords = 8160, .width = 3, .height = 3, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = SkillsMetaTiles, .numWords = 510, .width = 3, .height = 3, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Resign_ButtonTiles, .numWords = 160, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Stats_ScreenTiles, .numWords = 528, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Stats_ScreenMap, .numWords = 56, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Main_MenuTiles, .numWords = 1336, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Main_MenuMap, .numWords = 300, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Animated_SwordTiles, .numWords = 1440, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Animated_SwordMetaTiles, .numWords = 72, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Press_Any_ButtonTiles, .numWords = 80, .width = 5, .height = 2, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Skill_Tree_BackgroundTiles, .numWords = 56, .width = 30, .height = 20, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = Skill_Tree_BackgroundMap, .numWords = 300, .width = 30, .height = 20, .defaultPalette = 0, .shape = 0, .size = 0},
{.data = black_magic_animTiles, .numWords = 728, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = black_magic_animMetaTiles, .numWords = 7200, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = slash_animationTiles, .numWords = 352, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = slash_animationMetaTiles, .numWords = 1200, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Twin_Slash_animTiles, .numWords = 1256, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Twin_Slash_animMetaTiles, .numWords = 2400, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Triple_Slash_animTiles, .numWords = 1392, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Triple_Slash_animMetaTiles, .numWords = 3600, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = blood_blade_animTiles, .numWords = 4928, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = blood_blade_animMetaTiles, .numWords = 7500, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Summon_Blade_AnimTiles, .numWords = 3192, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Summon_Blade_AnimMetaTiles, .numWords = 5100, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Drain_animTiles, .numWords = 2088, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Drain_animMetaTiles, .numWords = 4800, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Missile_animTiles, .numWords = 1040, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Missile_animMetaTiles, .numWords = 4200, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Blood_Missile_animTiles, .numWords = 1040, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
{.data = Blood_Missile_animMetaTiles, .numWords = 4200, .width = 30, .height = 20, .defaultPalette = 1, .shape = 0, .size = 0},
};
//{.data = , .size = 32, .width = 2, .height = 2, .defaultPalette = 1},