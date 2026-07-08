#include "main.h"

typedef const struct Action{
	const enum GraphicsEnum unselectedGraphic;
	const enum GraphicsEnum selectedGraphic;
	const enum GraphicsEnum cooldownGraphic;
	const Script *selectedScript;
	u8 cooldown;
}Action;

u16 tilemapBuffer[64];

Action actions[15] = {
	{.unselectedGraphic = GFX_EMPTY, .selectedGraphic = GFX_EMPTY, .cooldownGraphic = GFX_EMPTY, .selectedScript = 0},
	{.unselectedGraphic = GFX_SLASH_1, .selectedGraphic = GFX_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_TWIN_SLASH_1, .selectedGraphic = GFX_TWIN_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_TRIPLE_SLASH_1, .selectedGraphic = GFX_TRIPLE_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_SUMMON_BLADE_1, .selectedGraphic = GFX_SUMMON_BLADE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_BLOOD_BLADE_1, .selectedGraphic = GFX_BLOOD_BLADE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_BLACK_MAGIC_1, .selectedGraphic = GFX_BLACK_MAGIC_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_MEAT_1, .selectedGraphic = GFX_MEAT_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_CRANBERRY_1, .selectedGraphic = GFX_CRANBERRY_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_ICE_CREAM_1, .selectedGraphic = GFX_ICE_CREAM_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_FOCUS_1, .selectedGraphic = GFX_FOCUS_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_MEDITATE_1, .selectedGraphic = GFX_MEDITATE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_GUARD_1, .selectedGraphic = GFX_GUARD_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_PARRY_1, .selectedGraphic = GFX_PARRY_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
	{.unselectedGraphic = GFX_REFRESH_1, .selectedGraphic = GFX_REFRESH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = 0},
};

void battleInit(){
	gameState.currentScript = SCR_BATTLE;
	//debug
	for(u32 i = 0; i < 10; i++){
		gameState.actionPalette[i] = ACT_EMPTY;
	}
	//set the starting action palette
	gameState.actionPalette[0] = ACT_SLASH;
	for(u32 i = 1; i < 8; i++){
		gameState.actionPalette[i] = ACT_SLASH + i;
	}
	
}

void battleRun(){
	
	//set the tilemap with the actionPalette

	for(u32 i = 0; i < 10; i++){
		if(gameState.actionPalette[i] != ACT_EMPTY){
			Action *action = &actions[gameState.actionPalette[i]];
			tilemapBuffer[i * 3] = SE_ID((action->unselectedGraphic + 1) * 4) | SE_PALBANK(1);
			tilemapBuffer[i * 3 + 1] = SE_ID((action->unselectedGraphic + 1) * 4 + 1) | SE_PALBANK(1);
			tilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 32] = SE_ID((action->unselectedGraphic + 1) * 4 + 2) | SE_PALBANK(1);
			tilemapBuffer[i * 3 + 33] = SE_ID((action->unselectedGraphic + 1) * 4 + 3) | SE_PALBANK(1);
			tilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);			
		}
		else{
			tilemapBuffer[i * 3] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 1] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 32] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 33] = SE_ID(4) | SE_PALBANK(0);
			tilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);
		}
	}
	
	tilemapBuffer[30] = SE_ID(4) | SE_PALBANK(0);
	tilemapBuffer[31] = SE_ID(4) | SE_PALBANK(0);
	tilemapBuffer[62] = SE_ID(4) | SE_PALBANK(0);
	tilemapBuffer[63] = SE_ID(4) | SE_PALBANK(0);
	
	vramAddUpdate(&se_mat[28][17][0], tilemapBuffer, 32);
}