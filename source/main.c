#include "main.h"

Inputs inputs = {.lastFrame = 0, .currentFrame = 0, .pressed = 0, .held = 0, .released = 0,};
enum FrameState frameState = WORKING;


int main(){
	initialize();

	while(1){
		handleInputs();
		debug();
		frameState = WAITING_FOR_VBLANK;
		while(frameState != NEW_FRAME_START){
			Halt();
		}
		frameState = WORKING;
	}
}

void initialize(){
	interruptInit();
	audioInit();
	videoInit();
	textInit();
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

void debug(){
	static u8 songID = MAIN_LOOP;
	static u8 sfxID = BLACK_MAGIC;
	static enum Colors color = BLACK;
	
	//press A to cycle music tracks
	if(inputs.pressed & KEY_A){
		if(songID == GAME_OVER){
			songID = MAIN_LOOP;
		}
		else songID++;
		playSong(songID);
	}
	
	//press B to cycle sound effects
	if(inputs.pressed & KEY_B){
		if(sfxID == SLASH){
			sfxID = BLACK_MAGIC;
		}
		else sfxID++;
		playSfx(sfxID);
	}
	
	//press R to cycle palettes
	if(inputs.pressed & KEY_R){
		if(color == BLUE){
			color = BLACK;
		}
		else{
			color++;
		}
		Palette newPalette = {PalettesBitmap[color << 1], PalettesBitmap[(color << 1) + 1]};
		setPalette(newPalette);
	}
	
	//put some sample text on-screen
	enum TextChar sampleTextMessage[] = {S,A,M,P,L,E,SPACE,T,E,X,T};
	TextField sampleText = {.xPos = 20, .yPos = 20, .length = 11, .message = sampleTextMessage};
	static u8 sampleTextID;
	sampleTextID = writeText(sampleText);
}

