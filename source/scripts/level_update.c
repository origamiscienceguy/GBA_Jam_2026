#include "main.h"
#include "sprite.h"

void witchLevelUpdate(u8 newLevel, u8 hide){
	if(hide){
		closeText(gameState.witchLevelMessageID);
		gameState.witchLevelMessageID = 0xFF;
		return;
	}
	
	enum TextChar witchLevelMessage[6] = {L, V, L, SPACE, SPACE, SPACE};
	if(newLevel < 10){
		witchLevelMessage[4] = ZERO + newLevel;
	}
	else{
		u8 tens = 0;
		while(newLevel >= 10){
			tens++;
			newLevel -= 10;
		}
		witchLevelMessage[4] = ZERO + tens;
		witchLevelMessage[5] = ZERO + newLevel;
	}
	
	if(gameState.witchLevelMessageID != 0xFF){
		closeText(gameState.witchLevelMessageID);
	}
	
	TextField sampleText = {.xPos = WITCH_LEVEL_TEXT_X, .yPos = WITCH_LEVEL_TEXT_Y, .length = 6, .message = witchLevelMessage};
	gameState.witchLevelMessageID = writeText(sampleText);
}

void templarLevelUpdate(u8 newLevel){
	enum TextChar templarLevelMessage[6] = {L, V, L, SPACE, SPACE, SPACE};
	if(newLevel < 10){
		templarLevelMessage[4] = ZERO + newLevel;
	}
	else{
		u8 tens = 0;
		while(newLevel >= 10){
			tens++;
			newLevel -= 10;
		}
		templarLevelMessage[4] = ZERO + tens;
		templarLevelMessage[5] = ZERO + newLevel;
	}
	
	if(gameState.templarLevelMessageID != 0xFF){
		closeText(gameState.templarLevelMessageID);
	}
	
	TextField sampleText = {.xPos = TEMPLAR_LEVEL_TEXT_X, .yPos = TEMPLAR_LEVEL_TEXT_Y, .length = 6, .message = templarLevelMessage};
	gameState.templarLevelMessageID = writeText(sampleText);
}