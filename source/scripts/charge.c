#include "main.h"
#include "sprite.h"

#define HITFRAME 54

void chargeInit(){
	gameState.currentScript = SCR_CHARGE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void chargeRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_CHARGE, WITCH_X, WITCH_Y);
		changeAnimation(gameState.witchAttackID, ANIM_CHARGE, CHARGE_X, CHARGE_Y);
		playSfx(MISSILE_1);
		break;
		
		case 48:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		changeAnimation(gameState.witchAttackID, ANIM_CHARGE, CHARGE_X, 160);
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
		break;
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
