#include "main.h"
#include "sprite.h"

void cranberryInit(){
	gameState.currentScript = SCR_CRANBERRY;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void cranberryRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_CRANBERRY, TEMPLAR_X, TEMPLAR_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.selectedAction = 0xFF;
		break;
		
		case 30:
		changeAnimation(gameState.itemThrowID, ANIM_CRANBERRY_THROW, ITEM_THROW_X, ITEM_THROW_Y);
		break;
		
		case 48:
		changeAnimation(gameState.itemThrowID, ANIM_MEAT_THROW, ITEM_THROW_X, 160);
		playSfx(RESTORE);
		gameState.criticalHit = 1;
		templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
		break;
		
		case 70:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
		
		case 80:
		gameState.selectedAction = gameState.savedSelectedAction;
		scriptList[SCR_PLAYER_TURN].scriptInit();
		break;
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
