#include "video.h"

u32 healthbar0PosFrames[] = {0, 1000};
u32 healthbar0XPos[] = {0};
u32 healthbar0YPos[] = {0};
u32 healthbar0GfxFrames[] = {0, 1000};
u32 healthbar0Gfx[] = {16};

Animation healthbar0 = {
	.numFrames = 1,
	.gfxFrame = healthbar0GfxFrames,
	.gfx = healthbar0Gfx,
	.posFrame = healthbar0PosFrames,
	.xPos = healthbar0XPos,
	.yPos = healthbar0YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};