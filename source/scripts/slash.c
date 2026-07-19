#include "main.h"

#define HEALTHINTERPOLATESTART 70

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
		
		case 54:
		gameState.previousHealth = gameState.witchHealth;
		if(gameState.witchHealth > gameState.templarDamage){
			gameState.witchHealth -= gameState.templarDamage;
		}
		else{
			gameState.witchHealth = 0;
		}
		witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
		break;
		
		case 58:
		witchHealthUpdate(gameState.previousHealth, gameState.witchMaxHealth, 1);
		break;
		
		case 62:
		witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 1);
		break;
		
		case 66:
		witchHealthUpdate(gameState.previousHealth, gameState.witchMaxHealth, 1);
		break;
		
		case 84:
		changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
		break;
		
	}
	
	if(gameState.witchHealth == 0){
		switch (gameState.scriptCounter){
			case 54:
			playSfx(SLASH);
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_DEAD, WITCH_X, WITCH_Y);
			break;
			
			case 110:
			witchHealthUpdate(gameState.witchMaxHealth, gameState.witchMaxHealth, 0);
			break;
			
			case 174:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
			gameState.selectedAction = gameState.savedSelectedAction;
			gameState.witchHealth = gameState.witchMaxHealth;
			scriptList[SCR_BATTLE].scriptInit();
			break;
		}
	}
	else{
		switch (gameState.scriptCounter){
			case 54:
			playSfx(SLASH);
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_HURT, WITCH_X, WITCH_Y);
			break;
			
			case 80:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
			break;
			
			case 103:
			gameState.selectedAction = gameState.savedSelectedAction;
			scriptList[SCR_BATTLE].scriptInit();
			break;
		}
	}
	
	if((gameState.scriptCounter >= HEALTHINTERPOLATESTART) && ((gameState.scriptCounter - 33) < HEALTHINTERPOLATESTART)){
		witchHealthInterpolate(gameState.witchHealth, gameState.previousHealth, gameState.witchMaxHealth, (gameState.scriptCounter - HEALTHINTERPOLATESTART));
	}
	
	drawActionPalette();
	gameState.scriptCounter++;
}
