#include "video.h"

u32 witchDeadPosFrames[] = {0, 1000};
u32 witchDeadXPos[] = {0};
u32 witchDeadYPos[] = {0};
u32 witchDeadGfxFrames[] = {0, 6, 12, 24, 30, 36, 48, 54, 72, 78, 80, 102, 104, 1000};
u32 witchDeadGfx[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};

Animation witchDead = {
	.numFrames = 120,
	.gfxFrame = witchDeadGfxFrames,
	.gfx = witchDeadGfx,
	.posFrame = witchDeadPosFrames,
	.xPos = witchDeadXPos,
	.yPos = witchDeadYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};