#include "video.h"

u32 templarIdlePosFrames[] = {0, 1000};
u32 templarIdleXPos[] = {0};
u32 templarIdleYPos[] = {0};
u32 templarIdleGfxFrames[] = {0, 10, 20, 30, 1000};
u32 templarIdleGfx[] = {0, 1, 2, 3};

Animation templarIdle = {
	.numFrames = 40,
	.gfxFrame = templarIdleGfxFrames,
	.gfx = templarIdleGfx,
	.posFrame = templarIdlePosFrames,
	.xPos = templarIdleXPos,
	.yPos = templarIdleYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};