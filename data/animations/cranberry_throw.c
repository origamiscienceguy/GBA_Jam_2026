#include "video.h"

u32 cranberryThrowPosFrames[] = {0, 1000};
u32 cranberryThrowXPos[] = {0};
u32 cranberryThrowYPos[] = {0};
u32 cranberryThrowGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 1000};
u32 cranberryThrowGfx[] = {18, 19, 20, 21, 22, 23, 24, 25, 26};

Animation cranberryThrow = {
	.numFrames = 18,
	.gfxFrame = cranberryThrowGfxFrames,
	.gfx = cranberryThrowGfx,
	.posFrame = cranberryThrowPosFrames,
	.xPos = cranberryThrowXPos,
	.yPos = cranberryThrowYPos,
	.graphics = &graphicsList[GFX_ITEM_THROW],
	.mode = ANIM_END,
	.endDetail = 0,
};