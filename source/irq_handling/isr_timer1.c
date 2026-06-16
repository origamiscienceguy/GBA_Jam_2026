#include "tonc.h"
#include "audio.h"

void timer1ISR(){
	//check if the music has reached the end
	if(soundManager.musicMode != SILENT){
		if((0x10000 - soundManager.timerResetValue) >= soundManager.musicSamplesLeft){
			if(soundManager.musicMode == LOOP){
				playSong(soundManager.musicPlaying);
			}
			else{
				endSong();
			}
		}
		else{
			soundManager.musicSamplesLeft -= soundManager.timerResetValue;
		}
	}
}