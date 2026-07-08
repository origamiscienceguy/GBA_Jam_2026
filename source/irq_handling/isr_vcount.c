#include "tonc.h"

void vcountISR(){
	//shift bg0 right 4 pixels
	REG_BG0HOFS = 508;
}