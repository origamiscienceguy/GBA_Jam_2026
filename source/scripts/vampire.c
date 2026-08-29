#include "main.h"
#include "sprite.h"

#define HITFRAME 30

void vampireInit(){
	gameState.currentScript = SCR_VAMPIRE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void vampireRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_DRAIN, WITCH_X, WITCH_Y);
		startFullScreenAnim(FSANIM_DRAIN);
		break;
		
		case HITFRAME - 2:
		playSfx(MISSILE_2);
		break;
		
		case HITFRAME:
		if(gameState.defendStatus == 0){
			gameState.previousHealth = gameState.templarHealth;
			if(gameState.templarHealth > gameState.witchDamage){
				gameState.templarHealth -= gameState.witchDamage;
			}
			else{
				gameState.templarHealth = 0;
			}
			
			if((gameState.witchHealth + (gameState.witchDamage >> 1)) >= gameState.witchMaxHealth){
				gameState.witchHealth = gameState.witchMaxHealth;
			}
			else{
				gameState.witchHealth += (gameState.witchDamage >> 1);
			}
			witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
		}
		else if(gameState.defendStatus == 2){
			gameState.previousHealth = gameState.witchHealth;
			if(gameState.witchHealth > gameState.witchDamage){
				gameState.witchHealth -= gameState.witchDamage;
			}
			else{
				gameState.witchHealth = 0;
			}
		}
		break;
		
		case HITFRAME + 30:
		playSfx(RESTORE);
		break;
		
		case 114:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
	}
	
	u8 done = 0;
	if((gameState.scriptCounter >= HITFRAME) && gameState.defendStatus == 0){
		done = templarDamageScript(gameState.scriptCounter - HITFRAME);
	}
	else if(gameState.defendStatus == 2){
		done = witchDamageScript(gameState.scriptCounter - HITFRAME);
	}
	else{
		done = 1;
	}
	
	if(done && (gameState.scriptCounter >= 120)){
		gameState.defendStatus = 0;
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
