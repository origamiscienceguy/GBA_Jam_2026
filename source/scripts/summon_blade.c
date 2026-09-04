#include "main.h"
#include "sprite.h"

#define HITFRAME 64

void summonBladeInit(){
	gameState.currentScript = SCR_SUMMON_BLADE;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void summonBladeRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_SUMMON_BLADE, TEMPLAR_X, TEMPLAR_Y);
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 5;
		playSfx(MISSILE_1);
		startFullScreenAnim(FSANIM_SUMMON_BLADE);
		break;
		
		case HITFRAME - 2:
		playSfx(EXPLOSION);
		break;
		
		case HITFRAME:
		u8 damage;
		if(gameState.criticalHit){
			damage = gameState.templarDamage * 6;
			gameState.criticalHit = 0;
			statusUpdate();
		}
		else{
			damage = gameState.templarDamage * 3;
		}
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > (damage)){
			gameState.witchHealth -= (damage);
		}
		else{
			gameState.witchHealth = 0;
		}
		if((gameState.templarExp + damage) >= gameState.templarNeededExp){
			gameState.templarExp = gameState.templarExp + damage - gameState.templarNeededExp;
			gameState.templarLevelUpCounter = 0;
			gameState.templarLevelSfxDelay = 40;
		}
		else{
			gameState.templarExp += damage;
		}
		break;
		
		case 105:
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
