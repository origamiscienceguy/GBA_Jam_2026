#include "video.h"

u32 templarMeatPosFrames[] = {0, 1000};
u32 templarMeatXPos[] = {0};
u32 templarMeatYPos[] = {0};
u32 templarMeatGfxFrames[] = {0, 30, 32, 48, 1000};
u32 templarMeatGfx[] = {30, 31, 32, 33};

Animation templarMeat = {
	.numFrames = 40,
	.gfxFrame = templarMeatGfxFrames,
	.gfx = templarMeatGfx,
	.posFrame = templarMeatPosFrames,
	.xPos = templarMeatXPos,
	.yPos = templarMeatYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};