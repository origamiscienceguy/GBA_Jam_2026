#include "video.h"

u32 healthbar6PosFrames[] = {0, 1000};
u32 healthbar6XPos[] = {0};
u32 healthbar6YPos[] = {0};
u32 healthbar6GfxFrames[] = {0, 1000};
u32 healthbar6Gfx[] = {10};

Animation healthbar6 = {
	.numFrames = 1,
	.gfxFrame = healthbar6GfxFrames,
	.gfx = healthbar6Gfx,
	.posFrame = healthbar6PosFrames,
	.xPos = healthbar6XPos,
	.yPos = healthbar6YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};