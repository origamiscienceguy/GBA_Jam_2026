#include "video.h"

u32 healthbar1PosFrames[] = {0, 1000};
u32 healthbar1XPos[] = {0};
u32 healthbar1YPos[] = {0};
u32 healthbar1GfxFrames[] = {0, 1000};
u32 healthbar1Gfx[] = {15};

Animation healthbar1 = {
	.numFrames = 1,
	.gfxFrame = healthbar1GfxFrames,
	.gfx = healthbar1Gfx,
	.posFrame = healthbar1PosFrames,
	.xPos = healthbar1XPos,
	.yPos = healthbar1YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};