#include "video.h"

u32 templarSummonBladePosFrames[] = {0, 1000};
u32 templarSummonBladeXPos[] = {0};
u32 templarSummonBladeYPos[] = {0};
u32 templarSummonBladeGfxFrames[] = {0, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 52, 54, 1000};
u32 templarSummonBladeGfx[] = {4, 12, 13, 14, 15, 16, 13, 14, 15, 16, 13, 14, 15, 16, 17, 25, 26};

Animation templarSummonBlade = {
	.numFrames = 100,
	.gfxFrame = templarSummonBladeGfxFrames,
	.gfx = templarSummonBladeGfx,
	.posFrame = templarSummonBladePosFrames,
	.xPos = templarSummonBladeXPos,
	.yPos = templarSummonBladeYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};