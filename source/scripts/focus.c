#include "main.h"
#include "sprite.h"

void focusInit(){
	gameState.currentScript = SCR_FOCUS;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void focusRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_FOCUS, TEMPLAR_X, TEMPLAR_Y);
		changeAnimation(gameState.templarBonusID, ANIM_FOCUS, FOCUS_X, FOCUS_Y);
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
		if((gameState.templarExp + 5) >= gameState.templarNeededExp){
			gameState.templarExp = 0;
			//templarLevelUp();
		}
		else{
			gameState.templarExp += 5;
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
