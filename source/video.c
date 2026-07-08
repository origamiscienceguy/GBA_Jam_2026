#include "video.h"
OBJ_ATTR spriteBuffer[128];
u16 paletteBuffer[2][256];
VramSegment vramBuffers[16];
u8 vramSegmentsUsed = 0;
AnimationEntry activeAnimations[16];


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
	REG_BG1CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(2) | BG_CBB(0) | BG_SBB(29);
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
	//set the vcount interrupt
	playAnimation(ANIM_SLASH, 0, 60);
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
			activeAnimations[i].startingTile = 55;
			return i;
		}
	}
	return 0xff;
}

void endAnimation(u8 slot){
	activeAnimations[slot].mode = ANIMMANAGER_UNUSED;
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
			activeAnimations[i].xPos = activeAnimations[i].startXPos + activeAnimations[i].animation->xPos[activeAnimations[i].posCounter];
			activeAnimations[i].yPos = activeAnimations[i].startYPos + activeAnimations[i].animation->yPos[activeAnimations[i].posCounter];
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
		spriteBuffer[activeAnimations[i].oamEntry].attr2 = ATTR2_ID(activeAnimations[i].startingTile) | ATTR2_PRIO(0) | ATTR2_PALBANK(1);
		
		
		//chek if the end of the animation has been reached
		if(activeAnimations[i].counter == activeAnimations[i].animation->numFrames){
			if(activeAnimations[i].animation->mode == ANIM_LOOP){
				activeAnimations[i].counter = 0;
				activeAnimations[i].posCounter = 0;
				activeAnimations[i].gfxCounter = 0;
				continue;
			}
			else{
				endAnimation(i);
				return;
			}
		}
		activeAnimations[i].counter++;
	}
}