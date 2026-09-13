#include "main.h"
#include "sprite.h"

void mainMenuInit(){
	gameState.currentScript = SCR_MAIN_MENU;
	playSong(MENU);
	videoInit();
	textInit();

	gameState.scriptCounter = 0xff;
	gameState.templarLevelUpCounter = 0xff;
	memcpy32(&(tile_mem[1][0]), graphicsList[GFX_MAIN_MENU].data, graphicsList[GFX_MAIN_MENU].numWords);
	for(u32 i = 0; i < 20; i++){
		for(u32 j = 0; j < 15; j++){
			se_mem[29][(j) * 2 + (i) * 32] = (u16)(0x1000 + ((graphicsList[GFX_MAIN_MENU_MAP].data[15 * i + j]) & 0xffff));
			se_mem[29][(j) * 2 + (i) * 32 + 1] = (u16)(0x1000 + ((graphicsList[GFX_MAIN_MENU_MAP].data[15 * i + j]) >> 16));
		}
	}
	memcpy32(&(tile_mem[1][167]), graphicsList[GFX_ANIMATED_SWORD].data, graphicsList[GFX_ANIMATED_SWORD].numWords);
	memcpy32(&(tile_mem[1][347]), graphicsList[GFX_PRESS_ANY_BUTTON].data, graphicsList[GFX_PRESS_ANY_BUTTON].numWords);
}

void mainMenuRun(){
	if(gameState.scriptCounter == 0xff){
		gameState.scriptCounter = 0;
		return;
	}
	
	if(inputs.pressed){
		scriptList[SCR_BATTLE_START].scriptInit();
	}
	
	static u8 frame = 0;
	switch(gameState.scriptCounter){
		case 0:
		frame = 0;
		break;
		
		case 6:
		frame = 1;
		break;
		
		case 12:
		frame = 2;
		break;
		
		case 18:
		frame = 3;
		break;
		
		case 24:
		frame = 4;
		break;
		
		case 30:
		frame = 5;
		break;
		
		case 60:
		frame = 6;
		break;
		
		case 66:
		frame = 7;
		break;
		
		case 72:
		frame = 8;
		break;
		
		case 78:
		frame = 9;
		break;
		
		case 254:
		gameState.scriptCounter = 0;
		break;
		
	}
	
	u8 pressAnyButton = 1;
	if(gameState.scriptCounter & 0x20){
		pressAnyButton = 0;
	}
	
	se_mem[29][14 + (2) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 0]) & 0xffff));
	se_mem[29][15 + (2) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 0] >> 16));
	se_mem[29][16 + (2) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 1]) & 0xffff));
	se_mem[29][14 + (3) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 1] >> 16));
	se_mem[29][15 + (3) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 2]) & 0xffff));
	se_mem[29][16 + (3) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 2] >> 16));
	se_mem[29][14 + (4) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 3]) & 0xffff));
	se_mem[29][15 + (4) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 3] >> 16));
	se_mem[29][16 + (4) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 4]) & 0xffff));
	se_mem[29][14 + (5) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 4] >> 16));
	se_mem[29][15 + (5) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 5]) & 0xffff));
	se_mem[29][16 + (5) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 5] >> 16));
	se_mem[29][14 + (6) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 6]) & 0xffff));
	se_mem[29][15 + (6) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 6] >> 16));
	se_mem[29][16 + (6) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 7]) & 0xffff));
	se_mem[29][14 + (7) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 7] >> 16));
	se_mem[29][15 + (7) * 32] = (u16)(0x10A7 + ((graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 8]) & 0xffff));
	se_mem[29][16 + (7) * 32] = (u16)(0x10A7 + (graphicsList[GFX_ANIMATED_SWORD_MAP].data[frame * 9 + 8] >> 16));
	
	
	if(pressAnyButton){
		se_mem[29][3 + (9) * 32] = 0x015B;
		se_mem[29][4 + (9) * 32] = 0x015C;
		se_mem[29][5 + (9) * 32] = 0x015D;
		se_mem[29][6 + (9) * 32] = 0x015E;
		se_mem[29][7 + (9) * 32] = 0x015F;
		se_mem[29][8 + (9) * 32] = 0x0160;
		se_mem[29][9 + (9) * 32] = 0x0161;
		se_mem[29][10 + (9) * 32] = 0x0162;
		se_mem[29][11 + (9) * 32] = 0x0163;
		se_mem[29][12 + (9) * 32] = 0x0164;
	}
	else{
		se_mem[29][3 + (9) * 32] = 0;
		se_mem[29][4 + (9) * 32] = 0;
		se_mem[29][5 + (9) * 32] = 0;
		se_mem[29][6 + (9) * 32] = 0;
		se_mem[29][7 + (9) * 32] = 0;
		se_mem[29][8 + (9) * 32] = 0;
		se_mem[29][9 + (9) * 32] = 0;
		se_mem[29][10 + (9) * 32] = 0;
		se_mem[29][11 + (9) * 32] = 0;
		se_mem[29][12 + (9) * 32] = 0;
	}
	gameState.scriptCounter++;
}