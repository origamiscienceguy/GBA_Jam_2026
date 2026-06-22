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
	//if sfx is playing, modify its remaining samples by the timer
	if(soundManager.sfxMode != SILENT){
		soundManager.sfxSamplesLeft -= (REG_TM1CNT_L - soundManager.timerResetValue);
	}
	soundManager.musicSamplesLeft = sounds[MUSIC][songID].length;
	soundManager.musicPlaying = songID;
	soundManager.musicMode = sounds[MUSIC][songID].mode;
	manageTimer();
	REG_DMA1CNT = 0;
	REG_DMA1SAD = (u32)(sounds[MUSIC][songID].source);
	REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void endSong(){
	soundManager.musicSamplesLeft = 0;
	soundManager.musicPlaying = 0;
	soundManager.musicMode = SILENT;
	manageTimer();
	REG_DMA1CNT = 0;
}

void playSfx(u8 sfxID){
	//if music is playing, modify its remaining samples by the timer
	if(soundManager.musicMode != SILENT){
		soundManager.musicSamplesLeft -= (REG_TM1CNT_L - soundManager.timerResetValue);
	}
	soundManager.sfxSamplesLeft = sounds[SFX][sfxID].length;
	soundManager.sfxPlaying = sfxID;
	soundManager.sfxMode = sounds[SFX][sfxID].mode;
	manageTimer();
	REG_DMA2CNT = 0;
	REG_DMA2SAD = (u32)sounds[SFX][sfxID].source;
	REG_DMA2CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
}

void endSfx(){
	soundManager.sfxSamplesLeft = 0;
	soundManager.sfxPlaying = 0;
	soundManager.sfxMode = SILENT;
	manageTimer();
	REG_DMA2CNT = 0;
}

void manageTimer(){
	if(soundManager.musicMode == SILENT){
		if(soundManager.sfxMode == SILENT){
			//no music, no sfx 
			REG_TM1CNT_L = 0;
			REG_TM1CNT_H = 0;
		}
		else{
			//yes sfx, no music
			sfxNext();
		}
	}
	else{
		if(soundManager.sfxMode == SILENT){
			//yes music, no sfx
			musicNext();
		}
		else{
			//yes music, yes sfx
			if(soundManager.musicSamplesLeft > soundManager.sfxSamplesLeft){
				sfxNext();
			}
			else{
				musicNext();
			}
		}
	}
}

void musicNext(){
	if(soundManager.musicSamplesLeft > 0x10000){
		soundManager.timerResetValue = 0;
		REG_TM1CNT_L = soundManager.timerResetValue;
		REG_TM1CNT_H = 0;
		REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
	}
	else{
		soundManager.timerResetValue = (0x10000 - soundManager.musicSamplesLeft);
		REG_TM1CNT_L = soundManager.timerResetValue;
		REG_TM1CNT_H = 0;
		REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
	}
}

void sfxNext(){
	if(soundManager.sfxSamplesLeft > 0x10000){
		soundManager.timerResetValue = 0;
		REG_TM1CNT_L = soundManager.timerResetValue;
		REG_TM1CNT_H = 0;
		REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
	}
	else{
		soundManager.timerResetValue = (0x10000 - soundManager.sfxSamplesLeft);
		REG_TM1CNT_L = soundManager.timerResetValue;
		REG_TM1CNT_H = 0;
		REG_TM1CNT_H = TM_FREQ_1 | TM_CASCADE | TM_IRQ | TM_ENABLE;
	}
}

void audioInit(){
	REG_SNDSTAT = SSTAT_ENABLE;
	REG_SNDDSCNT = SDS_A100 | SDS_B100 | SDS_AR | SDS_AL | SDS_ATMR0 | SDS_ARESET | SDS_BR | SDS_BL | SDS_BTMR0 | SDS_BRESET;
	REG_DMA1DAD = (u32) 0x040000A0;
	REG_DMA2DAD = (u32) 0x040000A4;
	REG_TM0D = 0x10000 - 512;
	REG_TM0CNT = TM_FREQ_1 | TM_ENABLE;
}