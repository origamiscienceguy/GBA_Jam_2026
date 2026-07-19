#include "video.h"

u32 healthbar8PosFrames[] = {0, 1000};
u32 healthbar8XPos[] = {0};
u32 healthbar8YPos[] = {0};
u32 healthbar8GfxFrames[] = {0, 1000};
u32 healthbar8Gfx[] = {8};

Animation healthbar8 = {
	.numFrames = 1,
	.gfxFrame = healthbar8GfxFrames,
	.gfx = healthbar8Gfx,
	.posFrame = healthbar8PosFrames,
	.xPos = healthbar8XPos,
	.yPos = healthbar8YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};