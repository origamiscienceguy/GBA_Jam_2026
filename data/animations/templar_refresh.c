#include "video.h"

u32 templarRefreshPosFrames[] = {0, 1000};
u32 templarRefreshXPos[] = {0};
u32 templarRefreshYPos[] = {0};
u32 templarRefreshGfxFrames[] = {0, 1000};
u32 templarRefreshGfx[] = {4};

Animation templarRefresh = {
	.numFrames = 84,
	.gfxFrame = templarRefreshGfxFrames,
	.gfx = templarRefreshGfx,
	.posFrame = templarRefreshPosFrames,
	.xPos = templarRefreshXPos,
	.yPos = templarRefreshYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};