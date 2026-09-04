#include "main.h"
#include "sprite.h"

#define HITFRAME 121

void blackMagicInit(){
	gameState.currentScript = SCR_BLACK_MAGIC;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void blackMagicRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_DEAD, TEMPLAR_X, TEMPLAR_Y);
		playSfx(BUTTON_SELECT_2);

		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 10;
		break;
		
		case 15:
		startFullScreenAnim(FSANIM_BLACK_MAGIC);
		playSfx(BLACK_MAGIC);
		break;
		
		case HITFRAME:
		u8 damage = gameState.witchMaxHealth;
		gameState.previousHealth = gameState.witchHealth;
		gameState.witchHealth = 0;
		if((gameState.templarExp + damage) >= gameState.templarNeededExp){
			gameState.templarExp = gameState.templarExp + damage - gameState.templarNeededExp;
			gameState.templarLevelUpCounter = 0;
			gameState.templarLevelSfxDelay = 40;
		}
		else{
			gameState.templarExp += damage;
		}
		break;
		
		case HITFRAME + 4:
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
