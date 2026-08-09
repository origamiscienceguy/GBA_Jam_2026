#include "video.h"

u32 meditatePosFrames[] = {0, 1000};
u32 meditateXPos[] = {0};
u32 meditateYPos[] = {0};
u32 meditateGfxFrames[] = {0, 4, 8, 12, 16, 20, 48, 52, 56, 60, 64, 1000};
u32 meditateGfx[] = {6, 7, 8, 9, 10, 11, 10, 9, 8, 7, 6};

Animation meditate = {
	.numFrames = 68,
	.gfxFrame = meditateGfxFrames,
	.gfx = meditateGfx,
	.posFrame = meditatePosFrames,
	.xPos = meditateXPos,
	.yPos = meditateYPos,
	.graphics = &graphicsList[GFX_TEMPLAR_BONUSES],
	.mode = ANIM_END,
	.endDetail = 0,
};