#include "video.h"

u32 iceCreamThrowPosFrames[] = {0, 1000};
u32 iceCreamThrowXPos[] = {0};
u32 iceCreamThrowYPos[] = {0};
u32 iceCreamThrowGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 1000};
u32 iceCreamThrowGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

Animation iceCreamThrow = {
	.numFrames = 18,
	.gfxFrame = iceCreamThrowGfxFrames,
	.gfx = iceCreamThrowGfx,
	.posFrame = iceCreamThrowPosFrames,
	.xPos = iceCreamThrowXPos,
	.yPos = iceCreamThrowYPos,
	.graphics = &graphicsList[GFX_ITEM_THROW],
	.mode = ANIM_END,
	.endDetail = 0,
};