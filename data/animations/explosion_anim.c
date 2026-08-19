#include "video.h"

u32 explosionPosFrames[] = {0, 1000};
u32 explosionXPos[] = {0};
u32 explosionYPos[] = {0};
u32 explosionGfxFrames[] = {0, 6, 12, 18, 24, 36, 42, 48, 54, 60, 66, 1000};
u32 explosionGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

Animation explosionAnim = {
	.numFrames = 72,
	.gfxFrame = explosionGfxFrames,
	.gfx = explosionGfx,
	.posFrame = explosionPosFrames,
	.xPos = explosionXPos,
	.yPos = explosionYPos,
	.graphics = &graphicsList[GFX_WITCH_ATTACKS],
	.mode = ANIM_END,
	.endDetail = 0,
};