#include "video.h"

u32 templarBloodBladePosFrames[] = {0, 54, 1000};
u32 templarBloodBladeXPos[] = {0, 8};
u32 templarBloodBladeYPos[] = {0};
u32 templarBloodBladeGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 52, 54, 1000};
u32 templarBloodBladeGfx[] = {12, 13, 14, 15, 16, 13, 14, 15, 16, 13, 14, 15, 16, 17, 25, 26};

Animation templarBloodBlade = {
	.numFrames = 118,
	.gfxFrame = templarBloodBladeGfxFrames,
	.gfx = templarBloodBladeGfx,
	.posFrame = templarBloodBladePosFrames,
	.xPos = templarBloodBladeXPos,
	.yPos = templarBloodBladeYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};