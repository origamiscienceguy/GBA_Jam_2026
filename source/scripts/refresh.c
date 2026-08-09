#include "main.h"
#include "sprite.h"

void refreshInit(){
	gameState.currentScript = SCR_REFRESH;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void refreshRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_REFRESH, TEMPLAR_X, TEMPLAR_Y);
		changeAnimation(gameState.templarBonusID, ANIM_REFRESH, REFRESH_X, REFRESH_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		playSfx(DEFEND);
		break;
		
		case 10:
		gameState.selectedAction = 0xFF;
		break;
		
		case 34:
		//reduce cooldowns
		break;
		
		case 84:
		changeAnimation(gameState.templarBonusID, ANIM_GUARD, GUARD_X, 160);
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		gameState.selectedAction = gameState.savedSelectedAction;
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
		break;
		
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
