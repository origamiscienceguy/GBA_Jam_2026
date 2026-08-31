#include "main.h"
#include "sprite.h"

void turnUpdate(){
	//update the turn marker
	switch(gameState.currentTurn){
		case 0:
		//witch's turn
		se_mem[28][27 + 11 * 32] = 0x14B2;
		se_mem[28][2 + 11 * 32] = 0;
		se_mem[28][2 + 10 * 32] = 0;
		se_mem[28][2 + 9 * 32] = 0;
		se_mem[28][2 + 8 * 32] = 0x0;
		break;
		
		case 1:
		se_mem[28][27 + 11 * 32] = 0;
		se_mem[28][2 + 11 * 32] = 0x10B2;
		se_mem[28][2 + 10 * 32] = 0;
		se_mem[28][2 + 9 * 32] = 0;
		se_mem[28][2 + 8 * 32] = 0x0;
		break;
		
		case 2:
		se_mem[28][27 + 11 * 32] = 0;
		se_mem[28][2 + 11 * 32] = 0x10B2;
		se_mem[28][2 + 10 * 32] = 0x10B2;
		se_mem[28][2 + 9 * 32] = 0;
		se_mem[28][2 + 8 * 32] = 0x0;
		break;
		
		case 3:
		se_mem[28][27 + 11 * 32] = 0;
		se_mem[28][2 + 11 * 32] = 0x10B2;
		se_mem[28][2 + 10 * 32] = 0x10B2;
		se_mem[28][2 + 9 * 32] = 0x10B2;
		se_mem[28][2 + 8 * 32] = 0x0;
		break;
		
		case 4:
		se_mem[28][27 + 11 * 32] = 0;
		se_mem[28][2 + 11 * 32] = 0x10B2;
		se_mem[28][2 + 10 * 32] = 0x10B2;
		se_mem[28][2 + 9 * 32] = 0x10B2;
		se_mem[28][2 + 8 * 32] = 0x10B2;
		break;
		
		case 5:
		//display nothing
		se_mem[28][27 + 11 * 32] = 0;
		se_mem[28][2 + 11 * 32] = 0;
		se_mem[28][2 + 10 * 32] = 0;
		se_mem[28][2 + 9 * 32] = 0;
		
	}
}

void statusUpdate(){
	switch(gameState.defendStatus){
		case 0:
		//no defense status
		se_mem[28][1 + 10 * 32] = 0;
		break;
		
		case 1:
		se_mem[28][1 + 10 * 32] = 0x10B3;
		break;
		
		case 2:
		se_mem[28][1 + 10 * 32] = 0x10B4;
		break;
	}
	
	if(gameState.criticalHit == 1){
		se_mem[28][0 + 8 * 32] = 0x10B5;
		se_mem[28][1 + 8 * 32] = 0x10B6;
		se_mem[28][0 + 9 * 32] = 0x10B7;
		se_mem[28][1 + 9 * 32] = 0x10B8;
	}
	else{
		se_mem[28][0 + 8 * 32] = 0x0;
		se_mem[28][1 + 8 * 32] = 0x0;
		se_mem[28][0 + 9 * 32] = 0x0;
		se_mem[28][1 + 9 * 32] = 0x0;
	}
}