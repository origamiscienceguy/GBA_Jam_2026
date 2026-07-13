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
	gameState.templarAnimationID = playAnimation(ANIM_TEMPLAR_IDLE, 0, 60);
	gameState.witchAnimationID = playAnimation(ANIM_WITCH_IDLE, 190, 28);
	playSong(MAIN_LOOP);
	
	gameState.selectedAction = 0;
	gameState.numAvailableActions = 8;
	gameState.witchHealth = 0;
	gameState.currentScript = SCR_BATTLE;
}
	
void battleStartRun(){};