#include "main.h"

const u8 witchDamage[] = {
	0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3,
	3, 3, 3, 3, 3, 4, 4, 4, 5, 5,
	5, 6, 6, 6, 7, 7, 7, 8, 8, 8,
	9, 9, 9, 10, 10, 10, 11, 11, 11, 12,
	12, 12, 13, 13, 13, 14, 14, 14, 15, 15,
	15, 16, 16, 16, 17, 17, 17, 18, 18, 18,
	19, 19, 19, 20, 20, 20, 21, 21, 21, 22,
	22, 22, 23, 23, 23, 24, 24, 24, 25, 25,
	25, 26, 26, 26, 27, 27, 27, 28, 28, 28,
	29, 29, 29, 30, 30, 30, 31, 31, 31, 32,
	32,
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