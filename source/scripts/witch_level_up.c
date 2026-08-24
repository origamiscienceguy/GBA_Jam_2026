#include "main.h"

const u8 witchDamage[] = {
	1, 1, 1, 2, 2, 2, 3, 3, 3, 6,
	6, 6, 3, 3, 3, 4, 4, 4, 5, 5,
	5, 9, 9, 9, 14, 14, 14, 8, 8, 8,
	9, 9, 9, 10, 10, 10, 17, 17, 17, 24,
	24, 24, 13, 13, 13, 14, 14, 14, 15, 15,
	15, 24, 24, 24, 34, 34, 34, 18, 18, 18,
	19, 19, 19, 20, 20, 20, 32, 32, 32, 44,
	44, 44, 23, 23, 23, 24, 24, 24, 25, 25,
	25, 39, 39, 39, 54, 54, 54, 28, 28, 28,
	29, 29, 29, 30, 30, 30, 47, 47, 47, 64,
	64,
};



void witchLevelUp(u32 currentFrame){
	
	//update level text and make it blink
	switch(currentFrame){
		case 0:
		gameState.witchLevel++;
		gameState.witchDamage = witchDamage[gameState.witchLevel];
		gameState.witchPhaseLevel++;
		if(gameState.witchPhaseLevel == 3){
			gameState.witchPhaseLevel = 0;
			gameState.witchPhaseParity = 0;
			gameState.witchMaxHealth += 2;
			if(gameState.witchPhase == PHASE_CURSE){
				gameState.witchPhase = PHASE_BASIC;
				Palette palette = {PalettesBitmap[0], PalettesBitmap[1]};
				setPalette(palette);
			}
			else{
				gameState.witchPhase++;
				Palette palette = {PalettesBitmap[gameState.witchPhase << 1], PalettesBitmap[(gameState.witchPhase << 1) + 1]};
				setPalette(palette);
			}
		}
		break;
		
		case 4:
		witchLevelUpdate(gameState.witchLevel, 1);
		break;
		
		case 8:
		witchLevelUpdate(gameState.witchLevel, 0);
		break;
		
		case 12:
		witchLevelUpdate(gameState.witchLevel, 1);
		break;
		
		case 16:
		witchLevelUpdate(gameState.witchLevel, 0);
		break;
		
		case 20:
		witchLevelUpdate(gameState.witchLevel, 1);
		break;
		
		case 24:
		witchLevelUpdate(gameState.witchLevel, 0);
		intentUpdate(phaseToIntent(gameState.witchPhase, gameState.witchPhaseParity));
		break;
		
		case 28:
		witchLevelUpdate(gameState.witchLevel, 1);
		break;
		
		case 32:
		witchLevelUpdate(gameState.witchLevel, 0);
		break;
	}
	
}