#include "main.h"
#include "sprite.h"

void skillTreeCloseInit(){
	gameState.currentScript = SCR_CLOSE_SKILL_TREE;
}
	
void skillTreeCloseRun(){
	startFullScreenAnim(FSANIM_NONE);
	REG_BG1CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(0) | BG_CBB(1) | BG_SBB(29);
	
	if(gameState.skillCostID != 0xff){
		closeText(gameState.skillCostID);
	}
	if(gameState.skillLine2ID != 0xff){
		closeText(gameState.skillLine2ID);
	}
	if(gameState.skillLine1ID != 0xff){
		closeText(gameState.skillLine1ID);
	}
	if(gameState.skillNameID != 0xff){
		closeText(gameState.skillNameID);
	}	
	
	if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED){
		gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE;
	}
	else if(gameState.skillStates[gameState.selectedSkill] == SKILL_LOCKED_VIEWED){
		gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED;
	}
	else{
		gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED;
	}
	
	intentUpdate(phaseToIntent(gameState.witchPhase, gameState.witchPhaseParity));
	witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
	templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
	witchLevelUpdate(gameState.witchLevel, 0);
	templarLevelUpdate(gameState.templarLevel, 0);
	drawActionPalette();
	scriptList[SCR_PLAYER_TURN].scriptInit();
};