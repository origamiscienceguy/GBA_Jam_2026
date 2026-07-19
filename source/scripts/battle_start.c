#include "main.h"

void battleStartInit(){
	//setup the starting action palette

	//debug
	for(u32 i = 0; i < 10; i++){
		gameState.actionPalette[i] = ACT_EMPTY;
	}
	//set the starting action palette
	gameState.actionPalette[0] = ACT_SLASH;
	for(u32 i = 1; i < 8; i++){
		gameState.actionPalette[i] = ACT_SLASH + i;
	}
	gameState.templarAnimationID = playAnimation(ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
	gameState.witchAnimationID = playAnimation(ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
	gameState.templarHealthFrontID = playAnimation(ANIM_HEALTH_BAR_16, TEMPLAR_HEALTH_FRONT_X, TEMPLAR_HEALTH_FRONT_Y);
	gameState.witchHealthFrontID = playAnimation(ANIM_HEALTH_BAR_16, WITCH_HEALTH_FRONT_X, WITCH_HEALTH_FRONT_Y);
	gameState.templarHealthBackID = playAnimation(ANIM_HEALTH_BAR_BACK, TEMPLAR_HEALTH_BACK_X, TEMPLAR_HEALTH_BACK_Y);
	gameState.witchHealthBackID = playAnimation(ANIM_HEALTH_BAR_BACK, WITCH_HEALTH_BACK_X, WITCH_HEALTH_BACK_Y);

	playSong(MAIN_LOOP);
	
	gameState.selectedAction = 0;
	gameState.numAvailableActions = 8;
	gameState.witchHealth = 11;
	gameState.witchMaxHealth = 11;
	gameState.templarHealth = 8;
	gameState.templarMaxHealth = 8;
	gameState.currentScript = SCR_BATTLE;
	gameState.witchHealthMessageID = 0xff;
	gameState.templarHealthMessageID = 0xff;
	gameState.templarDamage = 3;
	
	witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
	templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
}
	
void battleStartRun(){};