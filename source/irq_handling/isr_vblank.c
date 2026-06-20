#include "tonc.h"
#include "main.h"

void vblankISR(){
	if(frameState == WAITING_FOR_VBLANK){
		frameState = NEW_FRAME_START;
	}
}