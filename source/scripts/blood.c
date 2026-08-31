#include "main.h"
#include "sprite.h"

#define HITFRAME 54

void bloodInit(){
	gameState.currentScript = SCR_BLOOD;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void bloodRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_BLOOD_MISSILE, WITCH_X, WITCH_Y);
		startFullScreenAnim(FSANIM_BLOOD_MISSILE);
		playSfx(MISSILE_1);
		break;
		
		case HITFRAME - 2:
		playSfx(SLASH);
		break;
		
		case HITFRAME:
		if((gameState.witchDamage >> 1) >= gameState.witchHealth){
			gameState.witchHealth = 1;
		}
		else{
		gameState.witchHealth -= (gameState.witchDamage >> 1);
		}
		witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
		
		if(gameState.defendStatus == 0){
			gameState.previousHealth = gameState.templarHealth;
			if(gameState.templarHealth > gameState.witchDamage){
				gameState.templarHealth -= gameState.witchDamage;
			}
			else{
				gameState.templarHealth = 0;
			}
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
		u8 savedDefendStatus = gameState.defendStatus;
		gameState.defendStatus = 0;
		statusUpdate();
		gameState.defendStatus = savedDefendStatus;
		break;
		
		case HITFRAME + 8:
		playSfx(SLASH);
		break;
		
		case HITFRAME + 18:
		playSfx(SLASH);
		break;
		
		case 94:
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
