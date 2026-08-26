#include "main.h"
#include "sprite.h"

#define HITFRAME 54

void hexInit(){
	gameState.currentScript = SCR_HEX;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void hexRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_HEX, WITCH_X, WITCH_Y);
		changeAnimation(gameState.witchAttackID, ANIM_HEX, HEX_X, HEX_Y);
		playSfx(MISSILE_1);
		break;
		
		case 48:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		changeAnimation(gameState.witchAttackID, ANIM_HEX, HEX_X, 160);
		for(u32 i = 1; i < 10; i++){
			if(gameState.actionPalette[i] == 0xFF){
				continue;
			}
			if(gameState.actionPalette[i] == ACT_REFRESH){
				continue;
			}
			gameState.actionCooldown[i] += 2;
		}
		break;
		
		case 70:
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
		break;
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
