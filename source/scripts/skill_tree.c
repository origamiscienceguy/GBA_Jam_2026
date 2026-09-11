#include "main.h"
#include "sprite.h"

void skillTreeInit(){
	gameState.currentScript = SCR_SKILL_TREE;
}
	
void skillTreeRun(){
	if(inputs.pressed & KEY_B){
		scriptList[SCR_CLOSE_SKILL_TREE].scriptInit();
	}
	else if(inputs.pressed & KEY_A){
		if((gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED) && 
			(skills[gameState.selectedSkill].cost <= gameState.templarLevelUpsAvailable)){
			gameState.templarLevelUpsAvailable -= skills[gameState.selectedSkill].cost;
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED_VIEWED;
			if(skills[gameState.selectedSkill].unlockList[0] != SKILL_NONE){
				gameState.skillStates[skills[gameState.selectedSkill].unlockList[0]] = SKILL_AVAILABLE;
			}
			if(skills[gameState.selectedSkill].unlockList[1] != SKILL_NONE){
				gameState.skillStates[skills[gameState.selectedSkill].unlockList[1]] = SKILL_AVAILABLE;
			}
			playSfx(POWER_UP);
			unlockFunctions[skills[gameState.selectedSkill].skillUnlockScript](gameState.selectedSkill);
		}
	}
	else if((inputs.pressed & KEY_LEFT) || (inputs.pressed & KEY_L)){
		playSfx(BUTTON_SELECT_1);
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_LOCKED_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED;
		}
		gameState.selectedSkill = skills[gameState.selectedSkill].leftSkill;
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE_VIEWED;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_PURCHASED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED_VIEWED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED_VIEWED;
		}
	}
	else if((inputs.pressed & KEY_RIGHT) || (inputs.pressed & KEY_R)){
		playSfx(BUTTON_SELECT_1);
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_LOCKED_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED;
		}
		gameState.selectedSkill = skills[gameState.selectedSkill].rightSkill;
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE_VIEWED;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_PURCHASED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED_VIEWED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED_VIEWED;
		}
	}
	else if(inputs.pressed & KEY_UP){
		playSfx(BUTTON_SELECT_1);
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_LOCKED_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED;
		}
		gameState.selectedSkill = skills[gameState.selectedSkill].upSkill;
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE_VIEWED;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_PURCHASED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED_VIEWED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED_VIEWED;
		}
	}
	else if(inputs.pressed & KEY_DOWN){
		playSfx(BUTTON_SELECT_1);
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_LOCKED_VIEWED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED;
		}
		gameState.selectedSkill = skills[gameState.selectedSkill].downSkill;
		if(gameState.skillStates[gameState.selectedSkill] == SKILL_AVAILABLE){
			gameState.skillStates[gameState.selectedSkill] = SKILL_AVAILABLE_VIEWED;
		}
		else if(gameState.skillStates[gameState.selectedSkill] == SKILL_PURCHASED){
			gameState.skillStates[gameState.selectedSkill] = SKILL_PURCHASED_VIEWED;
		}
		else{
			gameState.skillStates[gameState.selectedSkill] = SKILL_LOCKED_VIEWED;
		}
	}
	refreshSkills();
};