#include "video.h"

u32 refreshPosFrames[] = {0, 1000};
u32 refreshXPos[] = {0};
u32 refreshYPos[] = {0};
u32 refreshGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 1000};
u32 refreshGfx[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

Animation refresh = {
	.numFrames = 84,
	.gfxFrame = refreshGfxFrames,
	.gfx = refreshGfx,
	.posFrame = refreshPosFrames,
	.xPos = refreshXPos,
	.yPos = refreshYPos,
	.graphics = &graphicsList[GFX_TEMPLAR_BONUSES],
	.mode = ANIM_END,
	.endDetail = 0,
};