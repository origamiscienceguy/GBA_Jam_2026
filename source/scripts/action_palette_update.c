#include "main.h"
#include "sprite.h"

u16 ExpInverseTable[] = {
0x0, 0x0, 0x8000, 0x5555, 0x4000, 0x3333, 0x2AAA, 0x2492, 
0x2000, 0x1C71, 0x1999, 0x1745, 0x1555, 0x13B1, 0x1249, 
0x1111, 0x1000, 0xF0F, 0xE38, 0xD79, 0xCCC, 0xC30, 0xBA2, 
0xB21, 0xAAA, 0xA3D, 0x9D8, 0x97B, 0x924, 0x8D3, 0x888, 
0x842, 0x800, 0x7C1, 0x787, 0x750, 0x71C, 0x6EB, 0x6BC, 
0x690, 0x666, 0x63E, 0x618, 0x5F4, 0x5D1, 0x5B0, 0x590, 
0x572, 0x555, 0x539, 0x51E, 0x505, 0x4EC, 0x4D4, 0x4BD, 
0x4A7, 0x492, 0x47D, 0x469, 0x456, 0x444, 0x432, 0x421, 
0x410, 0x400, 0x3F0, 0x3E0, 0x3D2, 0x3C3, 0x3B5, 0x3A8, 
0x39B, 0x38E, 0x381, 0x375, 0x369, 0x35E, 0x353, 0x348, 
0x33D, 0x333, 0x329, 0x31F, 0x315, 0x30C, 0x303, 0x2FA, 
0x2F1, 0x2E8, 0x2E0, 0x2D8, 0x2D0, 0x2C8, 0x2C0, 0x2B9, 
0x2B1, 0x2AA, 0x2A3, 0x29C, 0x295, 0x28F, 0x288, 0x282, 
0x27C, 0x276, 0x270, 0x26A, 0x264, 0x25E, 0x259, 0x253, 
0x24E, 0x249, 0x243, 0x23E, 0x239, 0x234, 0x230, 0x22B, 
0x226, 0x222, 0x21D, 0x219, 0x214, 0x210, 0x20C, 0x208, 
0x204, 0x200, 0x1FC, 0x1F8, 0x1F4, 0x1F0, 0x1EC, 0x1E9, 
0x1E5, 0x1E1, 0x1DE, 0x1DA, 0x1D7, 0x1D4, 0x1D0, 0x1CD, 
0x1CA, 0x1C7, 0x1C3, 0x1C0, 0x1BD, 0x1BA, 0x1B7, 0x1B4, 
0x1B2, 0x1AF, 0x1AC, 0x1A9, 0x1A6, 0x1A4, 0x1A1, 0x19E, 
0x19C, 0x199, 0x197, 0x194, 0x192, 0x18F, 0x18D, 0x18A, 
0x188, 0x186, 0x183, 0x181, 0x17F, 0x17D, 0x17A, 0x178, 
0x176, 0x174, 0x172, 0x170, 0x16E, 0x16C, 0x16A, 0x168, 
0x166, 0x164, 0x162, 0x160, 0x15E, 0x15C, 0x15A, 0x158, 
0x157, 0x155, 0x153, 0x151, 0x150, 0x14E, 0x14C, 0x14A, 
0x149, 0x147, 0x146, 0x144, 0x142, 0x141, 0x13F, 0x13E, 
0x13C, 0x13B, 0x139, 0x138, 0x136, 0x135, 0x133, 0x132, 
0x130, 0x12F, 0x12E, 0x12C, 0x12B, 0x129, 0x128, 0x127, 
0x125, 0x124, 0x123, 0x121, 0x120, 0x11F, 0x11E, 0x11C, 
0x11B, 0x11A, 0x119, 0x118, 0x116, 0x115, 0x114, 0x113, 
0x112, 0x111, 0x10F, 0x10E, 0x10D, 0x10C, 0x10B, 0x10A, 
0x109, 0x108, 0x107, 0x106, 0x105, 0x104, 0x103, 0x102, 0x101
};

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
	
	//At this point I got lazy and stopped with the intermediate VRAM buffers. Pretty sure performance is good enough to not ever result in screen tearing.
	if(gameState.selectedAction != 10){
		se_mem[28][1 + 1 * 32] = 1 + 0x10B8;
		se_mem[28][2 + 1 * 32] = 1 + 0x10B9;
		se_mem[28][1 + 2 * 32] = 1 + 0x10C5;
		se_mem[28][2 + 2 * 32] = 1 + 0x10C6;
	}
	else{
		se_mem[28][1 + 1 * 32] = 1 + 0x10BA;
		se_mem[28][2 + 1 * 32] = 1 + 0x10BB;
		se_mem[28][1 + 2 * 32] = 1 + 0x10C7;
		se_mem[28][2 + 2 * 32] = 1 + 0x10C8;
	}
	//set exp bar to black
	for(u32 i = 0; i < 4; i++){
		se_mem[28][i+3 + 1 * 32] = 1 + 0x10BC;
		se_mem[28][i+3 + 2 * 32] = 1 + 0x10C9;
	}
	u32 expPixels = (gameState.templarExp * ExpInverseTable[gameState.templarNeededExp]) >> 11;
	u32 tile = 0;
	while(expPixels >= 8){
		se_mem[28][tile+3 + 1 * 32] = 1 + 0x10C4;
		se_mem[28][tile+3 + 2 * 32] = 1 + 0x10D1;
		expPixels -= 8;
		if(tile == 3){
			break;
		}
		else{
			tile++;
		}
	}
	se_mem[28][tile+3 + 1 * 32] = 1 + 0x10BC + expPixels;
	se_mem[28][tile+3 + 2 * 32] = 1 + 0x10C9 + expPixels;
	se_mem[28][7 + 1 * 32] = 0x10D3;
	se_mem[28][8 + 1 * 32] = 0x10D4;
	se_mem[28][9 + 1 * 32] = 0x10D5;
	se_mem[28][10 + 1 * 32] = 0x10D6;
	se_mem[28][7 + 2 * 32] = 0x10D7;
	se_mem[28][8 + 2 * 32] = 0x10D8;
	se_mem[28][9 + 2 * 32] = 0x10D9;
	se_mem[28][10 + 2 * 32] = 0x10Da;
	
	//write the messages
	u8 levelUps = gameState.templarLevelUpsAvailable;
	if(gameState.templarLevelUpsAvailable > 9){
		levelUps = 9;
	}
	
	enum TextChar levelUpsMessage[1] = {ZERO + levelUps};
	if(gameState.levelUpsTextID != 0xFF){
		closeText(gameState.levelUpsTextID);
	}
	if(gameState.selectedAction != 10){
		TextField sampleText = {.xPos = LEVEL_UPS_X, .yPos = LEVEL_UPS_Y, .length = 1, .message = levelUpsMessage, .palette = 0,};
		gameState.levelUpsTextID = writeText(sampleText);
	}
	else{
		TextField sampleText = {.xPos = LEVEL_UPS_X, .yPos = LEVEL_UPS_Y, .length = 1, .message = levelUpsMessage, .palette = 1,};
		gameState.levelUpsTextID = writeText(sampleText);
	}
	
	enum TextChar expMessage[5] = {SPACE, SPACE, FORWARD_SLASH, SPACE, SPACE};
	if(gameState.expAmountTextID != 0xFF){
		closeText(gameState.expAmountTextID);
	}
	u8 expNeededTens = 0;
	u8 expNeededOnes = gameState.templarNeededExp;
	u8 expTens = 0;
	u8 expOnes = gameState.templarExp;
	while(expNeededOnes >= 10){
		expNeededTens++;
		expNeededOnes -= 10;
	}
	while(expOnes >= 10){
		expTens++;
		expOnes -= 10;
	}
	if(expTens > 0){
		expMessage[0] = ZERO + expTens;
	}
	expMessage[1] = ZERO + expOnes;
	if(expNeededTens > 0){
		expMessage[3] = ZERO + expNeededTens;
		expMessage[4] = ZERO + expNeededOnes;
	}
	else{
		expMessage[3] = ZERO + expNeededOnes;
	}
	TextField expText = {.xPos = EXP_X, .yPos = EXP_Y, .length = 5, .message = expMessage, .palette = 1,};
	gameState.expAmountTextID = writeText(expText);
}