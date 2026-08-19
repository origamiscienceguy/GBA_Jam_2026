#include "main.h"
#include "sprite.h"

#define HITFRAME1 80
#define HITFRAME2 90
#define HITFRAME3 100

void tripleSlashInit(){
	gameState.currentScript = SCR_TRIPLE_SLASH;
	gameState.scriptCounter = 0;
	gameState.savedSelectedAction = gameState.selectedAction;
	
}

void tripleSlashRun(){
	switch (gameState.scriptCounter){
		case 0:
		gameState.selectedAction = 0xFF;
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_TRIPLE_SLASH, TEMPLAR_X, TEMPLAR_Y);
		playSfx(BUTTON_SELECT_2);
		break;
		
		case 5:
		gameState.selectedAction = gameState.savedSelectedAction;
		break;
		
		case 10:
		gameState.actionCooldown[gameState.savedSelectedAction] = 4;
		break;
		
		case (HITFRAME1 - 4):
		startFullScreenAnim(FSANIM_TRIPLE_SLASH);
		break;
		
		case HITFRAME1:
		playSfx(SLASH);
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > gameState.templarDamage){
			gameState.witchHealth -= gameState.templarDamage;
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case HITFRAME2 - 2:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
		
		case HITFRAME2:
		playSfx(SLASH);
		if(gameState.witchHealth > gameState.templarDamage){
			gameState.witchHealth -= gameState.templarDamage;
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case HITFRAME3 - 2:
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		break;
		
		case HITFRAME3:
		playSfx(SLASH);
		if(gameState.witchHealth > gameState.templarDamage){
			gameState.witchHealth -= gameState.templarDamage;
		}
		else{
			gameState.witchHealth = 0;
		}
		break;
		
		case 128:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
	}
	
	u8 done = 0;
	if(gameState.scriptCounter >= HITFRAME3){
		done = witchDamageScript(gameState.scriptCounter - HITFRAME3);
	}
	else if(gameState.scriptCounter >= HITFRAME2){
		witchDamageScript(gameState.scriptCounter - HITFRAME2);
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
