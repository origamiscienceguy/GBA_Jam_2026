#include "main.h"
#include "sprite.h"

void intentUpdate(u8 intent){
	enum TextChar intentMessage[2] = {SPACE, SPACE};

	switch(intent){
		case INTENT_ATTACK:
			se_mem[28][25 + 5 * 32] = 7 + 0x10A3;
			se_mem[28][26 + 5 * 32] = 8 + 0x10A3;
			se_mem[28][25 + 6 * 32] = 13 + 0x10A3;
			se_mem[28][26 + 6 * 32] = 14 + 0x10A3;
			
			if(gameState.intentMessageID != 0xff){
				closeText(gameState.intentMessageID);
			}
			
			u8 damage = gameState.witchDamage;
			if(damage < 10){
				intentMessage[1] = ZERO + damage;
			}
			else{
				u8 tens = 0;
				while(damage >= 10){
					tens++;
					damage -= 10;
				}
				intentMessage[0] = ZERO + tens;
				intentMessage[1] = ZERO + damage;
			}
			TextField sampleText1 = {.xPos = WITCH_INTENT_X, .yPos = WITCH_INTENT_Y, .length = 2, .message = intentMessage};
			gameState.intentMessageID = writeText(sampleText1);
		break;
		
		case INTENT_DEBUFF:
			se_mem[28][25 + 5 * 32] = 3 + 0x10A3;
			se_mem[28][26 + 5 * 32] = 4 + 0x10A3;
			se_mem[28][25 + 6 * 32] = 9 + 0x10A3;
			se_mem[28][26 + 6 * 32] = 10 + 0x10A3;
			if(gameState.intentMessageID != 0xff){
				closeText(gameState.intentMessageID);
			}
			intentMessage[0] = SPACE;
			intentMessage[1] = TWO;
			TextField sampleText2 = {.xPos = WITCH_INTENT_X, .yPos = WITCH_INTENT_Y, .length = 2, .message = intentMessage};
			gameState.intentMessageID = writeText(sampleText2);
			
		break;
		
		case INTENT_CHARGE:
			se_mem[28][25 + 5 * 32] = 5 + 0x10A3;
			se_mem[28][26 + 5 * 32] = 6 + 0x10A3;
			se_mem[28][25 + 6 * 32] = 11 + 0x10A3;
			se_mem[28][26 + 6 * 32] = 12 + 0x10A3;
			if(gameState.intentMessageID != 0xff){
				closeText(gameState.intentMessageID);
			}
			
			intentMessage[0] = SPACE;
			intentMessage[1] = SPACE;
			TextField sampleText3 = {.xPos = WITCH_INTENT_X, .yPos = WITCH_INTENT_Y, .length = 2, .message = intentMessage};
			gameState.intentMessageID = writeText(sampleText3);
		break;
	}
}