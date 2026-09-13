#include "main.h"
#include "sprite.h"
#define STAT_X 140
#define STAT_1_Y 65
#define STAT_2_Y 75
#define STAT_3_Y 85

void gameOverInit(){
	gameState.currentScript = SCR_GAME_OVER;
	playSong(GAME_OVER);
	changeAnimation(gameState.templarAnimationID, ANIM_TEMPLAR_DEAD, TEMPLAR_X, TEMPLAR_Y);
	gameState.scriptCounter = 0;
	gameState.selectedAction = 0xff;
	drawActionPalette();
	if(gameState.templarHealth != 0){
		gameState.previousHealth = gameState.templarHealth;
	}
	gameState.templarHealth = 0;
}

void gameOverRun(){
	if(gameState.scriptCounter < 80){
		switch(gameState.scriptCounter){
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
		
		if((gameState.scriptCounter >= 16) && ((gameState.scriptCounter - 33) < 16)){
			templarHealthInterpolate(gameState.templarHealth, gameState.previousHealth, gameState.templarMaxHealth, (gameState.scriptCounter - 16));
		}
		gameState.scriptCounter++;
	}
	else if(gameState.scriptCounter == 80){
		changeAnimation(gameState.witchAnimationID, ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
		//pull up the stats window
		memcpy32(&(tile_mem[1][0]), graphicsList[GFX_STATS_SCREEN].data, graphicsList[GFX_STATS_SCREEN].numWords);
		for(u32 i = 0; i < 8; i++){
			for(u32 j = 0; j < 7; j++){
				se_mem[29][(j + 4) * 2 + (i + 6) * 32] = (u16)(0x1000 + ((graphicsList[GFX_STATS_SCREEN_MAP].data[7 * i + j]) & 0xffff));
				se_mem[29][(j + 4) * 2 + (i + 6) * 32 + 1] = (u16)(0x1000 + ((graphicsList[GFX_STATS_SCREEN_MAP].data[7 * i + j]) >> 16));
			}
		}
		
		//write the three stats
		u8 ones = 0;
		u8 tens = 0;
		u8 hundreds = 0;
		enum TextChar stat[3];
		
		while(gameState.witchLevel >= 10){
			tens++;
			gameState.witchLevel -= 10;
		}
		ones = gameState.witchLevel;
		if(tens){
			stat[0] = ZERO + tens;
			stat[1] = ZERO + ones;
			stat[2] = SPACE;
		}
		else{
			stat[0] = ZERO + ones;
			stat[1] = SPACE;
			stat[2] = SPACE;
		}
		if(gameState.skillNameID != 0xff){
			closeText(gameState.skillNameID);
		}
		TextField sampleText = {.xPos = STAT_X, .yPos = STAT_1_Y, .length = 3, .message = stat,  .palette = 0};
		gameState.skillNameID = writeText(sampleText);
		
		ones = 0;
		tens = 0;
		while(gameState.templarLevel >= 10){
			tens++;
			gameState.templarLevel -= 10;
		}
		ones = gameState.templarLevel;
		if(tens){
			stat[0] = ZERO + tens;
			stat[1] = ZERO + ones;
			stat[2] = SPACE;
		}
		else{
			stat[0] = ZERO + ones;
			stat[1] = SPACE;
			stat[2] = SPACE;
		}
		if(gameState.skillLine1ID != 0xff){
			closeText(gameState.skillLine1ID);
		}
		TextField line1Text = {.xPos = STAT_X, .yPos = STAT_2_Y, .length = 3, .message = stat,  .palette = 0};
		gameState.skillLine1ID = writeText(line1Text);
		
		tens = 0;
		ones = 0;
		while(gameState.totalDamage >= 100){
			hundreds++;
			gameState.totalDamage -= 100;
		}
		while(gameState.totalDamage >= 10){
			tens++;
			gameState.totalDamage -= 10;
		}
		ones = gameState.totalDamage;
		if(hundreds){
			stat[0] = ZERO + hundreds;
			stat[1] = ZERO + tens;
			stat[2] = ZERO + ones;		
		}
		else if(tens){
			stat[0] = ZERO + tens;
			stat[1] = ZERO + ones;
			stat[2] = SPACE;
		}
		else{
			stat[0] = ZERO + ones;
			stat[1] = SPACE;
			stat[2] = SPACE;
		}
		if(gameState.skillLine2ID != 0xff){
			closeText(gameState.skillLine2ID);
		}
		TextField line2Text = {.xPos = STAT_X, .yPos = STAT_3_Y, .length = 3, .message = stat,  .palette = 0};
		gameState.skillLine2ID = writeText(line2Text);
		
		gameState.scriptCounter++;
	}
	else{
		if(inputs.pressed){
			closeAllText();
			scriptList[SCR_BATTLE_START].scriptInit();
		}
	}
}