#include "main.h"

void slashInit(){
	gameState.currentScript = SCR_SLASH;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void slashRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_SLASH, 0, 60);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.selectedAction = 0xFF;
		break;
	}
	
	if(gameState.witchHealth == 0){
		switch (gameState.scriptCounter){
			case 54:
			playSfx(SLASH);
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_DEAD, 190, 28);
			break;
			
			case 84:
			changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, 0, 60);
			break;
			
			case 174:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, 190, 28);
			gameState.selectedAction = gameState.savedSelectedAction;
			scriptList[SCR_BATTLE].scriptInit();
			break;
		}
	}
	else{
		switch (gameState.scriptCounter){
			case 54:
			playSfx(SLASH);
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_HURT, 190, 28);
			break;
			
			case 80:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, 190, 28);
			break;
			
			case 84:
			changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, 0, 60);
			gameState.selectedAction = gameState.savedSelectedAction;
			scriptList[SCR_BATTLE].scriptInit();
			break;
		}
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
