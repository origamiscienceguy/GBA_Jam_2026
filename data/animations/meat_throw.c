#include "video.h"

u32 meatThrowPosFrames[] = {0, 1000};
u32 meatThrowXPos[] = {0};
u32 meatThrowYPos[] = {0};
u32 meatThrowGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 1000};
u32 meatThrowGfx[] = {9, 10, 11, 12, 13, 14, 15, 16, 17};

Animation meatThrow = {
	.numFrames = 18,
	.gfxFrame = meatThrowGfxFrames,
	.gfx = meatThrowGfx,
	.posFrame = meatThrowPosFrames,
	.xPos = meatThrowXPos,
	.yPos = meatThrowYPos,
	.graphics = &graphicsList[GFX_ITEM_THROW],
	.mode = ANIM_END,
	.endDetail = 0,
};