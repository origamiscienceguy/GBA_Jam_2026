#include "main.h"
void templarLevelUp(){
	
	//update level text and make it blink
	switch(gameState.templarLevelUpCounter){
		case 0:
		gameState.templarLevel++;
		gameState.templarNeededExp += 6;
		gameState.templarHealth = gameState.templarMaxHealth;
		templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
		break;
		
		case 4:
		templarLevelUpdate(gameState.templarLevel, 1);
		break;
		
		case 8:
		templarLevelUpdate(gameState.templarLevel, 0);
		break;
		
		case 12:
		templarLevelUpdate(gameState.templarLevel, 1);
		break;
		
		case 16:
		templarLevelUpdate(gameState.templarLevel, 0);
		break;
		
		case 20:
		templarLevelUpdate(gameState.templarLevel, 1);
		break;
		
		case 24:
		templarLevelUpdate(gameState.templarLevel, 0);
		break;
		
		case 28:
		templarLevelUpdate(gameState.templarLevel, 1);
		break;
		
		case 32:
		templarLevelUpdate(gameState.templarLevel, 0);
		break;
	}
	
	if(gameState.templarLevelUpCounter == gameState.templarLevelSfxDelay){
		playSfx(LEVEL_UP);
	}
	
	if((gameState.templarLevelUpCounter >= 32) && (gameState.templarLevelUpCounter >= (gameState.templarLevelSfxDelay + 60))){
		gameState.templarLevelUpCounter = 0xff;
	}
	
	if(gameState.templarLevelUpCounter != 0xff){
		gameState.templarLevelUpCounter++;
	}
	
}