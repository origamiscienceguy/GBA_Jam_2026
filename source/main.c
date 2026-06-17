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
			//playSFX(sfxID);
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
	interruptInit();
}

void interruptInit(){
	//disable interrupts
	REG_IME = 0;

	//set the interrupt service routine functions and priority order (first is highest priority)
	u16 priorityList[14] = {IRQ_HBLANK, IRQ_VCOUNT, IRQ_VBLANK, IRQ_TIMER2, IRQ_TIMER1, IRQ_SERIAL,
						   IRQ_TIMER0, IRQ_TIMER3, IRQ_DMA0, IRQ_DMA1, IRQ_DMA2, IRQ_KEYPAD, IRQ_DMA3, IRQ_GAMEPAK};
	void (*isrFunctionPointers[14])() = {0, 0, vblankISR, 0, timer1ISR, 0, 0, 0, 0, 0, 0, 0, 0, cartridgeISR};
	
	//apply the chosen priorities
	setInterruptHandlers(priorityList, (u32 *)isrFunctionPointers);
	//set the master service routine
	*(u32 *)0x03007FFC = (u32)&irqMasterServiceRoutine;
	
	//interupt master service routine expects every bit in REG_IE to be set when not in an interrupt state
	REG_IE = 0x1FFF; 
	
	//enable Vblank interrupts
	REG_DISPCNT = 0;
	REG_DISPSTAT = DSTAT_VBL_IRQ; 
	REG_WAITCNT = WS_SRAM_8 | WS_ROM0_N3 | WS_ROM0_S1;
}

void handleInputs(){
	inputs.lastFrame = inputs.currentFrame;
	inputs.currentFrame = ~REG_KEYINPUT;
	inputs.pressed = inputs.currentFrame & ~inputs.lastFrame;
	inputs.released = inputs.lastFrame & ~inputs.currentFrame;
	inputs.held = inputs.currentFrame & inputs.lastFrame;
}

