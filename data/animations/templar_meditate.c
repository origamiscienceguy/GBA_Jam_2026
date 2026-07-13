#include "video.h"

u32 templarMeditatePosFrames[] = {0, 1000};
u32 templarMeditateXPos[] = {0};
u32 templarMeditateYPos[] = {0};
u32 templarMeditateGfxFrames[] = {0, 1000};
u32 templarMeditateGfx[] = {4};

Animation templarMeditate = {
	.numFrames = 68,
	.gfxFrame = templarMeditateGfxFrames,
	.gfx = templarMeditateGfx,
	.posFrame = templarMeditatePosFrames,
	.xPos = templarMeditateXPos,
	.yPos = templarMeditateYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};