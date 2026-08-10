#include "main.h"
#include "sprite.h"

void battleManagerInit(){
	gameState.currentScript = SCR_BATTLE_MANAGER;
	gameState.scriptCounter = 0;
}

void battleManagerRun(){
	//if it is the player's turn
	if(gameState.currentTurn != 0){
		for(u32 i = 0; i < 10; i++){
			if(gameState.actionCooldown[i] != 0){
				gameState.actionCooldown[i]--;
			}
			if(gameState.actionCooldown[i] == 0){
				closeText(gameState.cooldownTextID[i]);
				gameState.cooldownTextID[i] = 0xff;
			}
		}
		scriptList[SCR_PLAYER_TURN].scriptInit();
		changeAnimation(gameState.templarTurnID, ANIM_PLAYER_TURN, TURN_X, TURN_Y);
		gameState.currentTurn--;
	}
	else{
		scriptList[SCR_WITCH_TURN].scriptInit();
		changeAnimation(gameState.witchTurnID, ANIM_WITCH_TURN, TURN_X, TURN_Y);
		gameState.currentTurn++;
	}
}