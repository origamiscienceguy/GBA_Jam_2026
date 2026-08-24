#include "main.h"
#include "sprite.h"

#define HITFRAME 54

void chargeInit(){
	gameState.currentScript = SCR_MISSILE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void chargeRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_MISSILE, WITCH_X, WITCH_Y);
		playSfx(MISSILE_1);
		break;
		
		case HITFRAME:
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > gameState.templarDamage){
			gameState.witchHealth -= gameState.templarDamage;
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case 120:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
	}
	
	u8 done = 0;
	if(gameState.scriptCounter >= HITFRAME){
		done = templarDamageScript(gameState.scriptCounter - HITFRAME);
	}
	
	if(done){
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
