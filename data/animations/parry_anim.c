#include "video.h"

u32 parryPosFrames[] = {0, 1000};
u32 parryXPos[] = {0};
u32 parryYPos[] = {0};
u32 parryGfxFrames[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 1000};
u32 parryGfx[] = {27, 28, 29, 30, 26, 31, 32, 33, 34};

Animation parry = {
	.numFrames = 40,
	.gfxFrame = parryGfxFrames,
	.gfx = parryGfx,
	.posFrame = parryPosFrames,
	.xPos = parryXPos,
	.yPos = parryYPos,
	.graphics = &graphicsList[GFX_TEMPLAR_BONUSES],
	.mode = ANIM_END,
	.endDetail = 0,
};