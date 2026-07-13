#include "main.h"

Inputs inputs = {.lastFrame = 0, .currentFrame = 0, .pressed = 0, .held = 0, .released = 0,};
enum FrameState frameState = WORKING;
u32 globalTimer = 0;
GameState gameState;


int main(){
	initialize();

	while(1){
		handleInputs();
		globalTimer++;
		vblankUpdate();
		animationManager();
		//process the currently-running script
		scriptList[gameState.currentScript].scriptRun();
		
		//debug();
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
	scriptList[SCR_BATTLE_START].scriptInit();
}

void interruptInit(){
	//disable interrupts
	REG_IME = 0;

	//set the interrupt service routine functions and priority order (first is highest priority)
	u16 priorityList[14] = {IRQ_HBLANK, IRQ_VCOUNT, IRQ_VBLANK, IRQ_TIMER2, IRQ_TIMER1, IRQ_SERIAL,
						   IRQ_TIMER0, IRQ_TIMER3, IRQ_DMA0, IRQ_DMA1, IRQ_DMA2, IRQ_KEYPAD, IRQ_DMA3, IRQ_GAMEPAK};
	void (*isrFunctionPointers[14])() = {0, vcountISR, vblankISR, 0, timer1ISR, 0, 0, 0, 0, 0, 0, 0, 0, cartridgeISR};
	
	//apply the chosen priorities
	setInterruptHandlers(priorityList, (u32 *)isrFunctionPointers);
	//set the master service routine
	*(u32 *)0x03007FFC = (u32)&irqMasterServiceRoutine;
	
	//interupt master service routine expects every bit in REG_IE to be set when not in an interrupt state
	REG_IE = 0x1FFF; 
	
	//enable Vblank interrupts
	REG_DISPCNT = 0;
	REG_DISPSTAT = DSTAT_VBL_IRQ | DSTAT_VCT_IRQ | DSTAT_VCT(135); 
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
	static u8 sampleTextID;
	static u8 sampleFirstFrame = 1;
	if(!sampleFirstFrame){
		closeText(sampleTextID);
	}
	else{
		sampleFirstFrame = 0;
	}	
	enum TextChar sampleTextMessage[] = {S,A,M,P,L,E,SPACE,T,E,X,T};
	TextField sampleText = {.xPos = 20, .yPos = 20, .length = 11, .message = sampleTextMessage};
	sampleTextID = writeText(sampleText);
	
	//put some blinking text on-screen
	static u8 blinkingTextID;
	if((globalTimer & 15) == 0){
		enum TextChar blinkingTextMessage[] = {B,L,I,N,K,I,N,G,SPACE,T,E,X,T};
		TextField blinkingText = {.xPos = 120, .yPos = 30, .length = 13, .message = blinkingTextMessage};
		blinkingTextID = writeText(blinkingText);
	}
	if((globalTimer & 15) == 8){
		closeText(blinkingTextID);
	}
	
	//put some text that changes on-screen
	static u8 changingTextID;
	static u8 firstFrame = 1;
	enum TextChar changingTextMessage1[] = {T,E,X,T};
	enum TextChar changingTextMessage2[] = {T,H,A,T};
	enum TextChar changingTextMessage3[] = {C,H,A,N,G,E,S};
	if((globalTimer & 63) == 0){
		TextField changingText = {.xPos = 160, .yPos = 55, .length = 4, .message = changingTextMessage1};
		if(!firstFrame){
			closeText(changingTextID);
		}
		else{
			firstFrame = 0;
		}
		changingTextID = writeText(changingText);
	}
	if((globalTimer & 63) == 21){
		TextField changingText = {.xPos = 160, .yPos = 55, .length = 4, .message = changingTextMessage2};
		closeText(changingTextID);
		changingTextID = writeText(changingText);
	}
	if((globalTimer & 63) == 42){
		TextField changingText = {.xPos = 160, .yPos = 55, .length = 7, .message = changingTextMessage3};
		closeText(changingTextID);
		changingTextID = writeText(changingText);
	}
	
	//put a graphic on screen
	u16 graphicsBuffer[128];
	//zero out the graphics buffer
	for(u32 i = 0; i < 64; i++){
		graphicsBuffer[i] = 0;
	}
	//display the default palette
	if((globalTimer & 127) == 0){
		for(u32 i = 0; i < 10; i++){
			graphicsBuffer[i * 3] = SE_ID((1 + i) * 8) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 1] = SE_ID((1 + i) * 8 + 1) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 32] = SE_ID((1 + i) * 8 + 2) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 33] = SE_ID((1 + i) * 8 + 3) | SE_PALBANK(graphicsList[i].defaultPalette);
		}
		vramAddUpdate(&se_mat[28][17][0], graphicsBuffer, 32);
	}
	//display the inverted palette
	if((globalTimer & 127) == 64){
		for(u32 i = 0; i < 10; i++){
			graphicsBuffer[i * 3] = SE_ID((1 + i) * 8 + 4) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 1] = SE_ID((1 + i) * 8 + 5) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 32] = SE_ID((1 + i) * 8 + 6) | SE_PALBANK(graphicsList[i].defaultPalette);
			graphicsBuffer[i * 3 + 33] = SE_ID((1 + i) * 8 + 7) | SE_PALBANK(graphicsList[i].defaultPalette);
		}
		vramAddUpdate(&se_mat[28][17][0], graphicsBuffer, 32);
	}
	
	//add animated sprites of the templar and the witch
	static u32 playing = 0;
	if(playing == 0){
		playAnimation(ANIM_TEMPLAR_SLASH, 0, 80);
		playing = 1;
	}
}

