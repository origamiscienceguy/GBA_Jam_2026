#include "main.h"
#include "sprite.h"

void parryInit(){
	gameState.currentScript = SCR_PARRY;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void parryRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_GUARD, TEMPLAR_X, TEMPLAR_Y);
		changeAnimation(gameState.templarBonusID, ANIM_PARRY, GUARD_X, GUARD_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		playSfx(DEFEND);
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 5;
		break;
		
		case 40:
		changeAnimation(gameState.templarBonusID, ANIM_GUARD, GUARD_X, 160);
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		gameState.defendStatus = 2;
		break;
		
		case 60:
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
		break;
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
