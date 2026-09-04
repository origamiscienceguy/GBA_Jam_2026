#include "main.h"
#include "sprite.h"

void meditateInit(){
	gameState.currentScript = SCR_MEDITATE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void meditateRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_FOCUS, TEMPLAR_X, TEMPLAR_Y);
		changeAnimation(gameState.templarBonusID, ANIM_MEDITATE, FOCUS_X, FOCUS_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		playSfx(DEFEND);
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 3;
		break;
		
		case 34:
		if((gameState.templarExp + 8) >= gameState.templarNeededExp){
			gameState.templarExp = gameState.templarExp + 8 - gameState.templarNeededExp;
			gameState.templarLevelUpCounter = 0;
			gameState.templarLevelSfxDelay = 5;
		}
		else{
			gameState.templarExp += 8;
		}
		break;
		
		case 68:
		changeAnimation(gameState.templarBonusID, ANIM_GUARD, GUARD_X, 160);
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		gameState.selectedAction = gameState.savedSelectedAction;
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
		break;
		
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
