#include "tonc.h"
#include "main.h"

Inputs inputs = {.lastFrame = 0, .currentFrame = 0, .pressed = 0, .held = 0, .released = 0,};

int main(){
	initialize();
	u8 songID = MAIN_LOOP;
	u8 sfxID = BLACK_MAGIC;
	while(1){
		while(REG_VCOUNT != 159);
		while(REG_VCOUNT != 160);
		handleInputs();
		if(inputs.pressed & KEY_A){
			if(songID == GAME_OVER){
				songID = MAIN_LOOP;
			}
			else songID++;
			playSong(songID);
		}
		if(inputs.pressed & KEY_B){
			if(sfxID == SLASH){
				sfxID = BLACK_MAGIC;
			}
			else sfxID++;
			playSFX(sfxID);
		}
	}
}

void initialize(){
	REG_SNDSTAT = SSTAT_ENABLE;
	REG_SNDDSCNT = SDS_A100 | SDS_B100 | SDS_AR | SDS_AL | SDS_ATMR0 | SDS_ARESET | SDS_BR | SDS_BL | SDS_BTMR0 | SDS_BRESET;
	REG_DMA1DAD = (u32) 0x040000A0;
	REG_DMA2DAD = (u32) 0x040000A4;
	REG_TM0D = 0x10000 - 512;
	REG_TM0CNT = TM_FREQ_1 | TM_ENABLE;
	playSong(MAIN_LOOP);
	
}

void playSong(u8 songID){
	REG_DMA1CNT = 0;
	REG_DMA1SAD = (u32)musicList[songID];
	REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void playSFX(u8 sfxID){
	REG_DMA2CNT = 0;
	REG_DMA2SAD = (u32)sfxList[sfxID];
	REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void handleInputs(){
	inputs.lastFrame = inputs.currentFrame;
	inputs.currentFrame = ~REG_KEYINPUT;
	inputs.pressed = inputs.currentFrame & ~inputs.lastFrame;
	inputs.released = inputs.lastFrame & ~inputs.currentFrame;
	inputs.held = inputs.currentFrame & inputs.lastFrame;
}

