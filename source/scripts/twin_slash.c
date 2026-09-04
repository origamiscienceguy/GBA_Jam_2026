#include "main.h"
#include "sprite.h"

#define HITFRAME1 70
#define HITFRAME2 80

void twinSlashInit(){
	gameState.currentScript = SCR_TWIN_SLASH;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void twinSlashRun(){
	u8 damage;
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_TWIN_SLASH, TEMPLAR_X, TEMPLAR_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 4;
		break;
		
		case (HITFRAME1 - 4):
		startFullScreenAnim(FSANIM_TWIN_SLASH);
		break;
		
		case HITFRAME1:
		if(gameState.criticalHit){
			damage = gameState.templarDamage * 2;
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
		
		if((gameState.templarExp + damage) >= gameState.templarNeededExp){
			gameState.templarExp = gameState.templarExp + damage - gameState.templarNeededExp;
			gameState.templarLevelUpCounter = 0;
			gameState.templarLevelSfxDelay = 30;
		}
		else{
			gameState.templarExp += damage;
		}
		break;
		
		case HITFRAME2 - 2:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
		
		case HITFRAME2:
		if(gameState.criticalHit){
			damage = gameState.templarDamage * 2;
			gameState.criticalHit = 0;
			statusUpdate();
		}
		else{
			damage = gameState.templarDamage;
		}
		playSfx(SLASH);
		if(gameState.witchHealth > damage){
			gameState.witchHealth -= damage;
		}
		else{
			gameState.witchHealth = 0;
		}
		if((gameState.templarExp + damage) >= gameState.templarNeededExp){
			gameState.templarExp = gameState.templarExp + damage - gameState.templarNeededExp;
			gameState.templarLevelUpCounter = 0;
			gameState.templarLevelSfxDelay = 20;
		}
		else{
			gameState.templarExp += damage;
		}
		break;
		
		case 110:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
	}
	
	u8 done = 0;
	if(gameState.scriptCounter >= HITFRAME2){
		done = witchDamageScript(gameState.scriptCounter - HITFRAME2);
	}
	else if(gameState.scriptCounter >= HITFRAME1){
		witchDamageScript(gameState.scriptCounter - HITFRAME1);
	}
	
	if(done){
		scriptList[SCR_BATTLE_MANAGER].scriptInit();
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
