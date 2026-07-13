#include "video.h"

u32 witchHurtPosFrames[] = {0, 1000};
u32 witchHurtXPos[] = {0};
u32 witchHurtYPos[] = {0};
u32 witchHurtGfxFrames[] = {0, 20, 1000};
u32 witchHurtGfx[] = {4, 5};

Animation witchHurt = {
	.numFrames = 30,
	.gfxFrame = witchHurtGfxFrames,
	.gfx = witchHurtGfx,
	.posFrame = witchHurtPosFrames,
	.xPos = witchHurtXPos,
	.yPos = witchHurtYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};