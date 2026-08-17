#include "main.h"
#include "sprite.h"

#define HITFRAME 64

void bloodBladeInit(){
	gameState.currentScript = SCR_BLOOD_BLADE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void bloodBladeRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_BLOOD_BLADE, TEMPLAR_X, TEMPLAR_Y);
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 5;
		playSfx(MISSILE_1);
		startFullScreenAnim(FSANIM_BLOOD_BLADE);
		break;
		
		case HITFRAME - 2:
		playSfx(EXPLOSION);
		break;
		
		case HITFRAME:
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > (gameState.templarDamage * 3)){
			gameState.witchHealth -= (gameState.templarDamage * 3);
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case HITFRAME + 40:
		playSfx(RESTORE);
		break;
		
		case 112:
		if((gameState.templarHealth + ((gameState.templarDamage * 3) >> 1)) > gameState.templarMaxHealth){
			gameState.templarHealth = gameState.templarMaxHealth;
		}
		else{
			gameState.templarHealth += ((gameState.templarDamage * 3) >> 1);
		}
		templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
		break;
		
		case 123:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
	}
	
	u8 done = 0;
	if(gameState.scriptCounter >= HITFRAME){
		done = witchDamageScript(gameState.scriptCounter - HITFRAME);
	}
	
	if(done && gameState.scriptCounter >= 123){
		gameState.selectedAction = gameState.savedSelectedAction;
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
