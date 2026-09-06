#include "main.h"


Action actions[15] = {
	{.unselectedGraphic = GFX_EMPTY, .selectedGraphic = GFX_EMPTY, .cooldownGraphic = GFX_EMPTY, .selectedScript = 0},
	{.unselectedGraphic = GFX_SLASH_1, .selectedGraphic = GFX_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_SLASH]},
	{.unselectedGraphic = GFX_TWIN_SLASH_1, .selectedGraphic = GFX_TWIN_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_TWIN_SLASH]},
	{.unselectedGraphic = GFX_TRIPLE_SLASH_1, .selectedGraphic = GFX_TRIPLE_SLASH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_TRIPLE_SLASH]},
	{.unselectedGraphic = GFX_SUMMON_BLADE_1, .selectedGraphic = GFX_SUMMON_BLADE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_SUMMON_BLADE]},
	{.unselectedGraphic = GFX_BLOOD_BLADE_1, .selectedGraphic = GFX_BLOOD_BLADE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_BLOOD_BLADE]},
	{.unselectedGraphic = GFX_BLACK_MAGIC_1, .selectedGraphic = GFX_BLACK_MAGIC_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_BLACK_MAGIC]},
	{.unselectedGraphic = GFX_MEAT_1, .selectedGraphic = GFX_MEAT_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_MEAT]},
	{.unselectedGraphic = GFX_CRANBERRY_1, .selectedGraphic = GFX_CRANBERRY_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_CRANBERRY]},
	{.unselectedGraphic = GFX_ICE_CREAM_1, .selectedGraphic = GFX_ICE_CREAM_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_ICE_CREAM]},
	{.unselectedGraphic = GFX_FOCUS_1, .selectedGraphic = GFX_FOCUS_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_FOCUS]},
	{.unselectedGraphic = GFX_MEDITATE_1, .selectedGraphic = GFX_MEDITATE_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_MEDITATE]},
	{.unselectedGraphic = GFX_GUARD_1, .selectedGraphic = GFX_GUARD_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_GUARD]},
	{.unselectedGraphic = GFX_PARRY_1, .selectedGraphic = GFX_PARRY_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_PARRY]},
	{.unselectedGraphic = GFX_REFRESH_1, .selectedGraphic = GFX_REFRESH_2, .cooldownGraphic = GFX_BLANK, .selectedScript = &scriptList[SCR_REFRESH]},
};

void playerTurnInit(){
	gameState.currentScript = SCR_PLAYER_TURN;
	gameState.selectedAction = 0;
}

void playerTurnRun(){
	//check inputs, move selected action accordingly
	if((inputs.pressed & KEY_START) || (inputs.pressed & KEY_SELECT)){
		openSkillTree();
	}
	else if(inputs.pressed & KEY_A){
		if(gameState.selectedAction < 10){
			if(gameState.actionPalette[gameState.selectedAction] == ACT_ICE_CREAM || 
				gameState.actionPalette[gameState.selectedAction] == ACT_MEAT || 
				gameState.actionPalette[gameState.selectedAction] == ACT_CRANBERRY){
				
			}
			else if(gameState.currentTurn == 0){
				gameState.currentTurn = 5;
				turnUpdate();
				gameState.currentTurn = 0;
			}
			else{
				turnUpdate();
			}
		}
		else if(gameState.selectedAction == 10){
			openSkillTree();
		}
		else if(gameState.selectedAction == 11){
			gameOver();
		}
		
		actions[gameState.actionPalette[gameState.selectedAction]].selectedScript->scriptInit();
	}
	else if(inputs.pressed & KEY_RIGHT){
		if(gameState.selectedAction < 10){
			do{
				if(gameState.selectedAction == gameState.numAvailableActions - 1){
					gameState.selectedAction = 0;
				}
				else{
					gameState.selectedAction++;
				}
			}
			while(gameState.actionCooldown[gameState.selectedAction] != 0);
			
		}
		else if(gameState.selectedAction == 10){
			gameState.selectedAction = 11;
		}
		else if(gameState.selectedAction == 11){
			gameState.selectedAction = 10;
		}
		playSfx(BUTTON_SELECT_1);
	}
	else if(inputs.pressed & KEY_LEFT){
		if(gameState.selectedAction < 10){
			do{
				if(gameState.selectedAction == 0){
					gameState.selectedAction = gameState.numAvailableActions - 1;
				}
				else{
					gameState.selectedAction--;
				}
			}
			while(gameState.actionCooldown[gameState.selectedAction] != 0);
		}
		else if(gameState.selectedAction == 10){
			gameState.selectedAction = 11;
		}
		else if(gameState.selectedAction == 11){
			gameState.selectedAction = 10;
		}
		playSfx(BUTTON_SELECT_1);
	}
	else if((inputs.pressed & KEY_UP) || (inputs.pressed & KEY_DOWN)){
		if(gameState.selectedAction <= 4){
			gameState.selectedAction = 10;
		}
		else if(gameState.selectedAction <= 9){
			gameState.selectedAction = 11;
		}
		else if(gameState.selectedAction == 10){
			gameState.selectedAction = 0;
		}
		else if(gameState.selectedAction == 11){
			gameState.selectedAction = gameState.numAvailableActions - 1;
		}
		playSfx(BUTTON_SELECT_1);
	}
	drawActionPalette();
}