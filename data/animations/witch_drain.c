#include "video.h"

u32 witchDrainPosFrames[] = {0, 1000};
u32 witchDrainXPos[] = {0};
u32 witchDrainYPos[] = {0};
u32 witchDrainGfxFrames[] = {0, 2, 24, 26, 54, 60, 66, 72, 78, 84, 90, 96, 102, 108, 1000};
u32 witchDrainGfx[] = {24, 25, 26, 27, 28, 29, 28, 29, 28, 29, 28, 29, 28, 29};

Animation witchDrain = {
	.numFrames = 114,
	.gfxFrame = witchDrainGfxFrames,
	.gfx = witchDrainGfx,
	.posFrame = witchDrainPosFrames,
	.xPos = witchDrainXPos,
	.yPos = witchDrainYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};