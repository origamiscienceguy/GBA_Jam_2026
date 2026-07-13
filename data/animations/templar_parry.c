#include "video.h"

u32 templarParryPosFrames[] = {0, 1000};
u32 templarParryXPos[] = {0};
u32 templarParryYPos[] = {0};
u32 templarParryGfxFrames[] = {0, 1000};
u32 templarParryGfx[] = {4};

Animation templarParry = {
	.numFrames = 64,
	.gfxFrame = templarParryGfxFrames,
	.gfx = templarParryGfx,
	.posFrame = templarParryPosFrames,
	.xPos = templarParryXPos,
	.yPos = templarParryYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};