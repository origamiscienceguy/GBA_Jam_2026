#include "main.h"
#include "sprite.h"

#define HITFRAME 58

void explosionInit(){
	gameState.currentScript = SCR_EXPLOSION;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void explosionRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_BLAST, WITCH_X, WITCH_Y);
		break;
		
		case 16:
		changeAnimation(gameState.witchAttackID, ANIM_EXPLOSION, EXPLOSION_X, EXPLOSION_Y);
		break;
		
		case 32:
		playSfx(EXPLOSION);
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
		}
		else if(gameState.defendStatus == 2){
			gameState.previousHealth = gameState.witchHealth;
			if(gameState.witchHealth > gameState.witchDamage){
				gameState.witchHealth -= gameState.witchDamage;
			}
			else{
				gameState.witchHealth = 0;
			}
			u8 damage = gameState.witchDamage;
			if((gameState.templarExp + damage) >= gameState.templarNeededExp){
				gameState.templarExp = gameState.templarExp + damage - gameState.templarNeededExp;
				gameState.templarLevelUpCounter = 0;
				gameState.templarLevelSfxDelay = 30;
			}
			else{
				gameState.templarExp += damage;
			}
		}
		u8 savedDefendStatus = gameState.defendStatus;
		gameState.defendStatus = 0;
		statusUpdate();
		gameState.defendStatus = savedDefendStatus;
		break;
		
		case 66:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
		
		case 88:
		changeAnimation(gameState.witchAttackID, ANIM_EXPLOSION, EXPLOSION_X, 160);
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
