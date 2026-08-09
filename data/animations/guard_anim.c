#include "video.h"

u32 guardPosFrames[] = {0, 1000};
u32 guardXPos[] = {0};
u32 guardYPos[] = {0};
u32 guardGfxFrames[] = {0, 6, 12, 18, 1000};
u32 guardGfx[] = {27, 28, 29, 30};

Animation guard = {
	.numFrames = 24,
	.gfxFrame = guardGfxFrames,
	.gfx = guardGfx,
	.posFrame = guardPosFrames,
	.xPos = guardXPos,
	.yPos = guardYPos,
	.graphics = &graphicsList[GFX_TEMPLAR_BONUSES],
	.mode = ANIM_END,
	.endDetail = 0,
};