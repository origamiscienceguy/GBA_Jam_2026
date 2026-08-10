#include "main.h"

void drawActionPalette(){
	//set the tilemap with the actionPalette
	for(u32 i = 0; i < 10; i++){
		if(gameState.actionPalette[i] != ACT_EMPTY){
			if(gameState.actionCooldown[i] == 0){
				Action *action = &actions[gameState.actionPalette[i]];
				if(i == gameState.selectedAction){
					ActionPalettetilemapBuffer[i * 3] = SE_ID((action->selectedGraphic + 1) * 4) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 1] = SE_ID((action->selectedGraphic + 1) * 4 + 1) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
					ActionPalettetilemapBuffer[i * 3 + 32] = SE_ID((action->selectedGraphic + 1) * 4 + 2) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 33] = SE_ID((action->selectedGraphic + 1) * 4 + 3) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);	
				}
				else{
					ActionPalettetilemapBuffer[i * 3] = SE_ID((action->unselectedGraphic + 1) * 4) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 1] = SE_ID((action->unselectedGraphic + 1) * 4 + 1) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
					ActionPalettetilemapBuffer[i * 3 + 32] = SE_ID((action->unselectedGraphic + 1) * 4 + 2) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 33] = SE_ID((action->unselectedGraphic + 1) * 4 + 3) | SE_PALBANK(1);
					ActionPalettetilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);	
				}
			}
			else{
				Action *action = &actions[gameState.actionPalette[i]];
				ActionPalettetilemapBuffer[i * 3] = SE_ID((action->cooldownGraphic + 1) * 4) | SE_PALBANK(1);
				ActionPalettetilemapBuffer[i * 3 + 1] = SE_ID((action->cooldownGraphic + 1) * 4 + 1) | SE_PALBANK(1);
				ActionPalettetilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
				ActionPalettetilemapBuffer[i * 3 + 32] = SE_ID((action->cooldownGraphic + 1) * 4 + 2) | SE_PALBANK(1);
				ActionPalettetilemapBuffer[i * 3 + 33] = SE_ID((action->cooldownGraphic + 1) * 4 + 3) | SE_PALBANK(1);
				ActionPalettetilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);	
				
				u8 textHPos = i * 24 + 10;
				enum TextChar cooldownText[2] = {SPACE, SPACE};
				if(gameState.actionCooldown[i] >= 10){
					cooldownText[0] = ONE;
					cooldownText[1] = ZERO + gameState.actionCooldown[i] - 10;
					textHPos -= 3;
				}
				else{
					cooldownText[0] = ZERO + gameState.actionCooldown[i];
				}
				
				if(gameState.cooldownTextID[i] != 0xFF){
					closeText(gameState.cooldownTextID[i]);
				}
				
				TextField sampleText = {.xPos = textHPos, .yPos = 140, .length = 2, .message = cooldownText, .palette = 1};
				gameState.cooldownTextID[i] = writeText(sampleText);
			}
		}
		else{
			ActionPalettetilemapBuffer[i * 3] = SE_ID(4) | SE_PALBANK(0);
			ActionPalettetilemapBuffer[i * 3 + 1] = SE_ID(4) | SE_PALBANK(0);
			ActionPalettetilemapBuffer[i * 3 + 2] = SE_ID(4) | SE_PALBANK(0);
			ActionPalettetilemapBuffer[i * 3 + 32] = SE_ID(4) | SE_PALBANK(0);
			ActionPalettetilemapBuffer[i * 3 + 33] = SE_ID(4) | SE_PALBANK(0);
			ActionPalettetilemapBuffer[i * 3 + 34] = SE_ID(4) | SE_PALBANK(0);
		}
	}
	
	ActionPalettetilemapBuffer[30] = SE_ID(4) | SE_PALBANK(0);
	ActionPalettetilemapBuffer[31] = SE_ID(4) | SE_PALBANK(0);
	ActionPalettetilemapBuffer[62] = SE_ID(4) | SE_PALBANK(0);
	ActionPalettetilemapBuffer[63] = SE_ID(4) | SE_PALBANK(0);
	
	vramAddUpdate(&se_mat[28][17][0], ActionPalettetilemapBuffer, 32);
}