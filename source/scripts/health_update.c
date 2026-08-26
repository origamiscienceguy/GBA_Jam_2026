#include "main.h"
#include "sprite.h"

const u16 maxHealthInverse[99] = {
0x8000, 0x4000, 0x2AAB, 0x2000, 0x199A, 0x1556, 0x124A, 0x1000, 0xE39, 
0xCCD, 0xBA3, 0xAAB, 0x9D9, 0x925, 0x889, 0x800, 0x788, 0x71D, 0x6BD, 
0x667, 0x619, 0x5D2, 0x591, 0x556, 0x51F, 0x4ED, 0x4BE, 0x493, 0x46A, 
0x445, 0x422, 0x400, 0x3E1, 0x3C4, 0x3A9, 0x38F, 0x376, 0x35F, 0x349, 
0x334, 0x320, 0x30D, 0x2FB, 0x2E9, 0x2D9, 0x2C9, 0x2BA, 0x2AB, 0x29D, 
0x290, 0x283, 0x277, 0x26B, 0x25F, 0x254, 0x24A, 0x23F, 0x235, 0x22C, 
0x223, 0x21A, 0x211, 0x209, 0x200, 0x1F9, 0x1F1, 0x1EA, 0x1E2, 0x1DB, 
0x1D5, 0x1CE, 0x1C8, 0x1C1, 0x1BB, 0x1B5, 0x1B0, 0x1AA, 0x1A5, 0x19F, 
0x19A, 0x195, 0x190, 0x18B, 0x187, 0x182, 0x17E, 0x179, 0x175, 0x171, 
0x16D, 0x169, 0x165, 0x161, 0x15D, 0x159, 0x156, 0x152, 0x14F, 0x14B
};

u8 generateHealthMessage(enum TextChar *, u32, u32);

void templarHealthUpdate(u32 currentHealth, u32 maxHealth, u8 mode){
	u32 templarInverseMax = maxHealthInverse[maxHealth - 1];
	u32 healthbarPos = (templarInverseMax * currentHealth) >> 11;
	switch(mode){
		case 0: //update text and healthbar
		enum TextChar templarHealthMessage[5] = {SPACE, SPACE, SPACE, SPACE, SPACE};
		if(gameState.templarHealthMessageID != 0xFF){
			closeText(gameState.templarHealthMessageID);
		}
		u8 charsUsed = generateHealthMessage(templarHealthMessage, currentHealth, maxHealth);
		TextField sampleText = {.xPos = TEMPLAR_HEALTH_TEXT_X - charsUsed * 5, .yPos = TEMPLAR_HEALTH_TEXT_Y, .length = 5, .message = templarHealthMessage, .palette = 0,};
		gameState.templarHealthMessageID = writeText(sampleText);
		
		changeAnimation(gameState.templarHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, TEMPLAR_HEALTH_FRONT_X, TEMPLAR_HEALTH_FRONT_Y);
		break;
		
		case 1: //update only healthbar
		changeAnimation(gameState.templarHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, TEMPLAR_HEALTH_FRONT_X, TEMPLAR_HEALTH_FRONT_Y);
	}
}

void witchHealthUpdate(u32 currentHealth, u32 maxHealth, u8 mode){
	u32 witchInverseMax = maxHealthInverse[maxHealth - 1];
	u32 healthbarPos = (witchInverseMax * currentHealth) >> 11;
	switch(mode){
		case 0: //update text and healthbar
		enum TextChar witchHealthMessage[5] = {SPACE, SPACE, SPACE, SPACE, SPACE};
		if(gameState.witchHealthMessageID != 0xFF){
			closeText(gameState.witchHealthMessageID);
		}
		generateHealthMessage(witchHealthMessage, currentHealth, maxHealth);
		TextField sampleText = {.xPos = WITCH_HEALTH_TEXT_X, .yPos = WITCH_HEALTH_TEXT_Y, .length = 5, .message = witchHealthMessage};
		gameState.witchHealthMessageID = writeText(sampleText);
		
		changeAnimation(gameState.witchHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, WITCH_HEALTH_FRONT_X, WITCH_HEALTH_FRONT_Y);
		break;
		
		case 1: //update only healthbar
		changeAnimation(gameState.witchHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, WITCH_HEALTH_FRONT_X, WITCH_HEALTH_FRONT_Y);
	}
}

void witchHealthInterpolate(u32 currentHealth, u32 previousHealth, u32 maxHealth, u8 step){
	u32 witchInverseMax = maxHealthInverse[maxHealth - 1];
	u32 healthbarPos = (witchInverseMax * currentHealth);
	u32 previousHealthbarPos = (witchInverseMax * previousHealth);
	u32 delta = previousHealthbarPos - healthbarPos;
	healthbarPos = (previousHealthbarPos - ((delta * step) >> 5)) >> 11;
	changeAnimation(gameState.witchHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, WITCH_HEALTH_FRONT_X, WITCH_HEALTH_FRONT_Y);
}

void templarHealthInterpolate(u32 currentHealth, u32 previousHealth, u32 maxHealth, u8 step){
	u32 templarInverseMax = maxHealthInverse[maxHealth - 1];
	u32 healthbarPos = (templarInverseMax * currentHealth);
	u32 previousHealthbarPos = (templarInverseMax * previousHealth);
	u32 delta = previousHealthbarPos - healthbarPos;
	healthbarPos = (previousHealthbarPos - ((delta * step) >> 5)) >> 11;
	changeAnimation(gameState.templarHealthFrontID, ANIM_HEALTH_BAR_0 - healthbarPos, TEMPLAR_HEALTH_FRONT_X, TEMPLAR_HEALTH_FRONT_Y);
}

u8 generateHealthMessage(enum TextChar *healthMessage, u32 currentHealth, u32 maxHealth){
	u8 textPos = 0;
	if(currentHealth < 10){
		healthMessage[textPos] = ZERO + currentHealth;
		healthMessage[textPos + 1] = FORWARD_SLASH;
		textPos = 2;
	}
	else{
		u8 healthTens = 0;
		u8 healthOnes = 0;
		while(currentHealth >= 10){
			healthTens++;
			currentHealth -= 10;
		}
		healthOnes = currentHealth;
		healthMessage[textPos] = ZERO + healthTens;
		healthMessage[textPos + 1] = ZERO + healthOnes;
		healthMessage[textPos + 2] = FORWARD_SLASH;
		textPos = 3;
	}
	if(maxHealth < 10){
		healthMessage[textPos] = ZERO + maxHealth;
		textPos += 1;
	}
	else{
		u8 healthTens = 0;
		u8 healthOnes = 0;
		while(maxHealth >= 10){
			healthTens++;
			maxHealth -= 10;
		}
		healthOnes = maxHealth;
		healthMessage[textPos] = ZERO + healthTens;
		healthMessage[textPos + 1] = ZERO + healthOnes;
		textPos += 2;
	}
	return textPos;
}

u8 templarDamageScript(s32 currentFrame){
	switch(currentFrame){
		case 0:
		templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
		break;
		
		case 4:
		templarHealthUpdate(gameState.previousHealth, gameState.templarMaxHealth, 1);
		break;
		
		case 8:
		templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 1);
		break;
		
		case 12:
		templarHealthUpdate(gameState.previousHealth, gameState.templarMaxHealth, 1);
		break;
	}
	
	//change behavior if the templar is brought to zero health
	if((currentFrame >= 16) && ((currentFrame - 33) < 16)){
		templarHealthInterpolate(gameState.templarHealth, gameState.previousHealth, gameState.templarMaxHealth, (currentFrame - 16));
	}
	
	if(gameState.templarHealth == 0){
		//game over logic
		return 1;
	}
	
	else if(currentFrame < 50){
		switch (currentFrame){
			case 0:
			changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_HURT, TEMPLAR_X, TEMPLAR_Y);
			break;
			
			case 26:
			changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
			break;
		}
	}
	
	else{
		return 1;
	}
	
	return 0;
}

u8 witchDamageScript(s32 currentFrame){
	switch(currentFrame){
		case 0:
		witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
		break;
		
		case 4:
		witchHealthUpdate(gameState.previousHealth, gameState.witchMaxHealth, 1);
		break;
		
		case 8:
		witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 1);
		break;
		
		case 12:
		witchHealthUpdate(gameState.previousHealth, gameState.witchMaxHealth, 1);
		break;
	}
	
	//change behavior if the witch is brought to zero health
	if((currentFrame >= 16) && ((currentFrame - 33) < 16)){
		witchHealthInterpolate(gameState.witchHealth, gameState.previousHealth, gameState.witchMaxHealth, (currentFrame - 16));
	}
	
	if(gameState.witchHealth == 0){
		switch (currentFrame){
			case 0:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_DEAD, WITCH_X, WITCH_Y);
			gameState.currentTurn++;
			break;
			
			case 56:
			witchHealthUpdate(gameState.witchMaxHealth, gameState.witchMaxHealth, 0);
			break;
			
			case 120:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
			gameState.witchHealth = gameState.witchMaxHealth;
			return 1;
			break;
			
		}
		//run level up animations and logic
		if(currentFrame >= 49){
			witchLevelUp(currentFrame - 49);
		}
	}
	else if(currentFrame < 50){
		switch (currentFrame){
			case 0:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_HURT, WITCH_X, WITCH_Y);
			break;
			
			case 26:
			changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
			break;
			
		}
	}
	else{
		return 1;
	}
	return 0;
}