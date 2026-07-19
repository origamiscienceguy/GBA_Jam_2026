#include "video.h"

u32 healthbar10PosFrames[] = {0, 1000};
u32 healthbar10XPos[] = {0};
u32 healthbar10YPos[] = {0};
u32 healthbar10GfxFrames[] = {0, 1000};
u32 healthbar10Gfx[] = {6};

Animation healthbar10 = {
	.numFrames = 1,
	.gfxFrame = healthbar10GfxFrames,
	.gfx = healthbar10Gfx,
	.posFrame = healthbar10PosFrames,
	.xPos = healthbar10XPos,
	.yPos = healthbar10YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};