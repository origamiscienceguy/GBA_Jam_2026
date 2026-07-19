#include "video.h"

u32 healthbar5PosFrames[] = {0, 1000};
u32 healthbar5XPos[] = {0};
u32 healthbar5YPos[] = {0};
u32 healthbar5GfxFrames[] = {0, 1000};
u32 healthbar5Gfx[] = {11};

Animation healthbar5 = {
	.numFrames = 1,
	.gfxFrame = healthbar5GfxFrames,
	.gfx = healthbar5Gfx,
	.posFrame = healthbar5PosFrames,
	.xPos = healthbar5XPos,
	.yPos = healthbar5YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};