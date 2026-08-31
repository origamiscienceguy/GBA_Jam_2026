#include "main.h"
#include "sprite.h"

#define HITFRAME 54

void slashInit(){
	gameState.currentScript = SCR_SLASH;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void slashRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_SLASH, TEMPLAR_X, TEMPLAR_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.selectedAction = 0xFF;
		break;
		
		case (HITFRAME - 4):
		startFullScreenAnim(FSANIM_SLASH);
		break;
		
		case HITFRAME:
		u8 damage;
		if(gameState.criticalHit){
			damage = gameState.templarDamage * 2;
			gameState.criticalHit = 0;
			statusUpdate();
		}
		else{
			damage = gameState.templarDamage;
		}
		playSfx(SLASH);
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > damage){
			gameState.witchHealth -= damage;
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case 84:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
	}
	
	u8 done = 0;
	if(gameState.scriptCounter >= HITFRAME){
		done = witchDamageScript(gameState.scriptCounter - HITFRAME);
	}
	
	if(done){
		gameState.selectedAction = gameState.savedSelectedAction;
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
