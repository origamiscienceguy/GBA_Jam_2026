#include "main.h"

void drawActionPalette(){
	//set the tilemap with the actionPalette
	for(u32 i = 0; i < 10; i++){
		if(gameState.actionPalette[i] != ACT_EMPTY){
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