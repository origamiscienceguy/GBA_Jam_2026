#include "video.h"
OBJ_ATTR spriteBuffer[128];
u16 paletteBuffer[2][256];
VramSegment vramBuffers[16];
u8 vramSegmentsUsed = 0;
AnimationEntry activeAnimations[16];
u16 ActionPalettetilemapBuffer[64];
u16 animationStartingTile = 55;
enum FullScreenAnimationEnum currentFullScreenAnimation;
u32 fsAnimCounter = 0;
u32 fsAnimgfxCounter = 0;
u32 fsAnimBuffer[320];



void setPalette(Palette palette){
	paletteBuffer[0][0] = palette.color1;
	paletteBuffer[0][1] = palette.color2;
	paletteBuffer[0][2] = palette.color1;
	paletteBuffer[0][16] = palette.color2;
	paletteBuffer[0][17] = palette.color1;
	paletteBuffer[0][18] = palette.color2;
	paletteBuffer[1][0] = palette.color1;
	paletteBuffer[1][1] = palette.color2;
	paletteBuffer[1][2] = palette.color1;
	paletteBuffer[1][16] = palette.color2;
	paletteBuffer[1][17] = palette.color1;
	paletteBuffer[1][18] = palette.color2;
}

void videoInit(){
	Palette initialPalette = {PalettesBitmap[0], PalettesBitmap[1]};
	setPalette(initialPalette);
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
	REG_BG0CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(3) | BG_CBB(0) | BG_SBB(28);
	REG_BG1CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(0) | BG_CBB(1) | BG_SBB(29);
	REG_BG2CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(1) | BG_CBB(0) | BG_SBB(30);
	REG_BG3CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(0) | BG_CBB(0) | BG_SBB(31);
	for(u32 i = 0; i < 16; i++){
		vramBuffers[i].mode = VRAM_UNUSED;
	}
	//clear all sprites
	for(u32 i = 0; i < 128; i++){
		spriteBuffer[i].attr0 = ATTR0_HIDE;
	}
	//add all bg graphics to vram
	for(u32 i = 0; i < 31; i++){
		memcpy32(&(tile_mem[0][4 * (i + 1)]), graphicsList[i].data, graphicsList[i].numWords);
	}
	//clear all animations
	for(u32 i = 0; i < 16; i++){
		activeAnimations[i].mode = ANIMMANAGER_UNUSED;
	}
	//set the castle wall background
	memcpy32(&(tile_mem[0][128]), graphicsList[GFX_WALL_BACKGROUND].data, graphicsList[GFX_WALL_BACKGROUND].numWords);
	for(u32 i = 0; i < 20; i++){
		for(u32 j = 0; j < 15; j++){
			se_mem[28][i * 32 + j * 2] = (u16)((graphicsList[GFX_WALL_BACKGROUND_MAP].data[i * 15 + j] & 0xffff) + 4224);
			se_mem[28][i * 32 + j * 2 + 1] = (u16)(((graphicsList[GFX_WALL_BACKGROUND_MAP].data[i * 15 + j] & 0xffff0000) >> 16) + 4224);
		}
		se_mem[28][i * 32 + 30] = SE_ID(4) | SE_PALBANK(0);
		se_mem[28][i * 32 + 31] = SE_ID(4) | SE_PALBANK(0);
		
	}
	memcpy32(&(tile_mem[0][163]), graphicsList[GFX_INTENTS].data, graphicsList[GFX_INTENTS].numWords);
	se_mem[28][23 + 5 * 32] = 1 + 0x10A3;
	se_mem[28][24 + 5 * 32] = 2 + 0x10A3;
	se_mem[28][23 + 6 * 32] = 1 + 0x18A3;
	se_mem[28][24 + 6 * 32] = 2 + 0x18A3;
	
	memcpy32(&(tile_mem[0][178]), graphicsList[GFX_TURN_MARKER].data, graphicsList[GFX_TURN_MARKER].numWords);
	memcpy32(&(tile_mem[0][179]), graphicsList[GFX_DEFENSE].data, graphicsList[GFX_DEFENSE].numWords);
	memcpy32(&(tile_mem[0][181]), graphicsList[GFX_CRITICAL].data, graphicsList[GFX_CRITICAL].numWords);
	memcpy32(&(tile_mem[0][185]), graphicsList[GFX_EXP_BAR].data, graphicsList[GFX_EXP_BAR].numWords);
	memcpy32(&(tile_mem[0][211]), graphicsList[GFX_EXP_BAR_TIP].data, graphicsList[GFX_EXP_BAR_TIP].numWords);
	memcpy32(&(tile_mem[0][224]), graphicsList[GFX_RESIGN_BUTTON].data, graphicsList[GFX_RESIGN_BUTTON].numWords);
}

void vblankUpdate(){
	//update the palette
	memcpy32(pal_bg_mem, paletteBuffer, 256);
	
	//update OAM
	memcpy32(oam_mem, spriteBuffer, 256);
	
	REG_BG0HOFS = 0;
	
	//update segments of VRAM
	for(u32 i = 0; i < 16; i++){
		if(vramBuffers[i].mode == VRAM_ACTIVE){
			memcpy32(vramBuffers[i].destinationPtr, vramBuffers[i].sourcePtr, vramBuffers[i].numWords);
			vramBuffers[i].mode = VRAM_UNUSED;
		}
	}
	vramSegmentsUsed = 0;
}

void vramAddUpdate(void *destinationPtr, void *sourcePtr, u32 numWords){
	vramBuffers[vramSegmentsUsed].destinationPtr = destinationPtr;
	vramBuffers[vramSegmentsUsed].sourcePtr = sourcePtr;
	vramBuffers[vramSegmentsUsed].numWords = numWords;
	vramBuffers[vramSegmentsUsed].mode = VRAM_ACTIVE;
	vramSegmentsUsed++;
}

u8 playAnimation(u32 animationID, u32 xPos, u32 yPos){
	//add animation details to the animation manager
	//find an animation manager slot with an opening
	for (u32 i = 0; i < 16; i++){
		if(activeAnimations[i].mode == ANIMMANAGER_UNUSED){
			activeAnimations[i].animation = animationList[animationID];
			activeAnimations[i].counter = 0;
			activeAnimations[i].posCounter = 0;
			activeAnimations[i].gfxCounter = 0;
			activeAnimations[i].startXPos = xPos;
			activeAnimations[i].startYPos = yPos;
			activeAnimations[i].mode = ANIMMANAGER_ACTIVE;
			activeAnimations[i].oamEntry = i;
			activeAnimations[i].startingTile = animationStartingTile;
			animationStartingTile += animationList[animationID]->graphics->width * animationList[animationID]->graphics->height;
			return i;
		}
	}
	return 0xff;
}

void changeAnimation(u8 slot, u32 animationID, u32 xPos, u32 yPos){
	activeAnimations[slot].animation = animationList[animationID];
	activeAnimations[slot].counter = 0;
	activeAnimations[slot].posCounter = 0;
	activeAnimations[slot].gfxCounter = 0;
	activeAnimations[slot].startXPos = xPos;
	activeAnimations[slot].startYPos = yPos;
}

void endAnimation(u8 slot){
	activeAnimations[slot].mode = ANIMMANAGER_UNUSED;
	animationStartingTile = 55;
	//rework the graphics associated with animations
	
}

void animationManager(){
	//manage every animation in the queue
	for (u32 i = 0; i < 16; i++){
		if(activeAnimations[i].mode == ANIMMANAGER_UNUSED){
			continue;
		}
		//if there is an active animation, process it
		
		//check if the position has reached a keyframe
		if(activeAnimations[i].animation->posFrame[activeAnimations[i].posCounter] == activeAnimations[i].counter){
			//if so, update position
			activeAnimations[i].xPos = (activeAnimations[i].startXPos + activeAnimations[i].animation->xPos[activeAnimations[i].posCounter]) & 0x1ff;
			activeAnimations[i].yPos = (activeAnimations[i].startYPos + activeAnimations[i].animation->yPos[activeAnimations[i].posCounter]) & 0xff;
			activeAnimations[i].posCounter++;
		}
		
		//check if the graphics have reached a keyframe
		if(activeAnimations[i].animation->gfxFrame[activeAnimations[i].gfxCounter] == activeAnimations[i].counter){
			//if so, update the graphic tiles in VRAM
			Graphic *gfx = activeAnimations[i].animation->graphics;
			cu32 *sourcePtr = gfx->data + (gfx->width * gfx->height * 8 * activeAnimations[i].animation->gfx[activeAnimations[i].gfxCounter]);
			u32 numWords = gfx->width * gfx->height * 8;
			vramAddUpdate((void *)&(tile_mem_obj[0][activeAnimations[i].startingTile]), (void *)sourcePtr, numWords);
			activeAnimations[i].gfxCounter++;
		}
		
		//queue the oam update to take place next vblank
		spriteBuffer[activeAnimations[i].oamEntry].attr0 = ATTR0_REG | ATTR0_4BPP | ATTR0_SHAPE(activeAnimations[i].animation->graphics->shape) | ATTR0_Y(activeAnimations[i].yPos);
		spriteBuffer[activeAnimations[i].oamEntry].attr1 = ATTR1_SIZE(activeAnimations[i].animation->graphics->size) | ATTR1_X(activeAnimations[i].xPos);
		spriteBuffer[activeAnimations[i].oamEntry].attr2 = ATTR2_ID(activeAnimations[i].startingTile) | ATTR2_PRIO(2) | ATTR2_PALBANK(activeAnimations[i].animation->graphics->defaultPalette);
		
		
		//chek if the end of the animation has been reached
		if(activeAnimations[i].counter == activeAnimations[i].animation->numFrames){
			if(activeAnimations[i].animation->mode == ANIM_LOOP){
				activeAnimations[i].counter = 0;
				activeAnimations[i].posCounter = 0;
				activeAnimations[i].gfxCounter = 0;
				continue;
			}
			else{
				activeAnimations[i].counter = activeAnimations[i].animation->numFrames;
				continue;
			}
		}
		activeAnimations[i].counter++;
	}
	
	//now manage the full screen animation (if there is one)
	if(currentFullScreenAnimation == FSANIM_NONE){
		return;
	}
	FullScreenAnimation *fsAnimation = fullScreenAnimationList[currentFullScreenAnimation];
	
	//check if this animation is finished
	if(fsAnimCounter == fsAnimation->numFrames){
		startFullScreenAnim(FSANIM_NONE);
	}
	
	//check if the current counter matches a gfx counter
	if(fsAnimCounter == fsAnimation->gfxFrame[fsAnimgfxCounter]){
		//send over the new tilemap
		for(u32 i = 0; i < 20; i++){
			for(u32 j = 0; j < 15; j++){
				u32 correction = 0x00000000;
				if(fsAnimation->graphics->defaultPalette == 1){
					correction = 0x10001000;
				}
				fsAnimBuffer[i * 16 + j] = fsAnimation->tilemap->data[300 * fsAnimation->gfx[fsAnimgfxCounter] + i * 15 + j] + correction;
			}
		}
		vramAddUpdate((void *)&(se_mem[29][0]), (void *)fsAnimBuffer, 320);
		
		fsAnimgfxCounter++;
	}
	
	fsAnimCounter++;
	
}

void startFullScreenAnim(u8 animationID){
	if(animationID == FSANIM_NONE){
		currentFullScreenAnimation = FSANIM_NONE;
		//clear this background
		memset32(fsAnimBuffer, 0, 320);
		vramAddUpdate((void *)&(se_mem[29][0]), (void *)fsAnimBuffer, 320);
		return;
	}
	
	//move all the graphic tiles for this fs animation into VRAM
	memcpy32(&tile_mem[1][0], graphicsList[GFX_BLACK_MAGIC_ANIM + (animationID << 1)].data, graphicsList[GFX_BLACK_MAGIC_ANIM + (animationID << 1)].numWords);
	currentFullScreenAnimation = animationID;
	
	fsAnimCounter = 0;
	fsAnimgfxCounter = 0;
	
}