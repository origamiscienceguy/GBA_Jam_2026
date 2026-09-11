#include "main.h"
#include "sprite.h"

void skillTreeInit(){
	gameState.currentScript = SCR_SKILL_TREE;
}
	
void skillTreeRun(){
	if(inputs.pressed & KEY_B){
		scriptList[SCR_CLOSE_SKILL_TREE].scriptInit();
	}
	else if(inputs.pressed & KEY_LEFT){
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
	else if(inputs.pressed & KEY_RIGHT){
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