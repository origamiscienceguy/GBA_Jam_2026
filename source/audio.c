#include "audio.h"

extern const Sound musicList[];
extern const Sound sfxList[];

//global data
const Sound *sounds[] = {
	musicList, sfxList,
};

SoundManager soundManager = {
	.musicSamplesLeft = 0x0,
	.sfxSamplesLeft = 0x0,
	.musicPlaying = 0x0,
	.sfxPlaying = 0x0,
	.timerResetValue = 0x0,
	.musicMode = SILENT,
	.sfxMode = SILENT,
};

//functions

void playSong(u8 songID){
	soundManager.musicSamplesLeft = *sounds[MUSIC][songID].length;
	soundManager.musicPlaying = songID;
	soundManager.musicMode = sounds[MUSIC][songID].mode;
	manageTimer();
	REG_DMA1CNT = 0;
	REG_DMA1SAD = (u32)(sounds[MUSIC][songID].source);
	REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void endSong(){

}

void playSFX(u8 sfxID){
	soundManager.sfxSamplesLeft = *sounds[SFX][sfxID].length;
	soundManager.sfxPlaying = sfxID;
	soundManager.sfxMode = sounds[SFX][sfxID].mode;
	manageTimer();
	REG_DMA2CNT = 0;
	REG_DMA2SAD = (u32)sounds[SFX][sfxID].source;
	REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void manageTimer(){
	if(soundManager.musicMode == SILENT){
		if(soundManager.sfxMode == SILENT){
			//no music, no sfx 
		}
		else{
			//no music, yes sfx
		}
	}
	else{
		if(soundManager.sfxMode == SILENT){
			//yes music, no sfx
			if(soundManager.musicSamplesLeft > 0x10000){
				soundManager.timerResetValue = 0;
				REG_TM1CNT_L = soundManager.timerResetValue;
				REG_TM1CNT_H = 0;
				REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
			}
			else{
				soundManager.timerResetValue = soundManager.musicSamplesLeft;
				REG_TM1CNT_L = soundManager.timerResetValue;
				REG_TM1CNT_H = 0;
				REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
			}
		}
		else{
			//yes music, yes sfx
		}
	}
}