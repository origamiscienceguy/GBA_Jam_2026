#include "video.h"

u32 templarHurtPosFrames[] = {0, 1000};
u32 templarHurtXPos[] = {0};
u32 templarHurtYPos[] = {0};
u32 templarHurtGfxFrames[] = {0, 10, 1000};
u32 templarHurtGfx[] = {27, 28};

Animation templarHurt = {
	.numFrames = 30,
	.gfxFrame = templarHurtGfxFrames,
	.gfx = templarHurtGfx,
	.posFrame = templarHurtPosFrames,
	.xPos = templarHurtXPos,
	.yPos = templarHurtYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};