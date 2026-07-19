#include "video.h"

u32 healthbar3PosFrames[] = {0, 1000};
u32 healthbar3XPos[] = {0};
u32 healthbar3YPos[] = {0};
u32 healthbar3GfxFrames[] = {0, 1000};
u32 healthbar3Gfx[] = {13};

Animation healthbar3 = {
	.numFrames = 1,
	.gfxFrame = healthbar3GfxFrames,
	.gfx = healthbar3Gfx,
	.posFrame = healthbar3PosFrames,
	.xPos = healthbar3XPos,
	.yPos = healthbar3YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};