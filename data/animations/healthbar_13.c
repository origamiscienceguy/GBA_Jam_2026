#include "video.h"

u32 healthbar13PosFrames[] = {0, 1000};
u32 healthbar13XPos[] = {0};
u32 healthbar13YPos[] = {0};
u32 healthbar13GfxFrames[] = {0, 1000};
u32 healthbar13Gfx[] = {3};

Animation healthbar13 = {
	.numFrames = 1,
	.gfxFrame = healthbar13GfxFrames,
	.gfx = healthbar13Gfx,
	.posFrame = healthbar13PosFrames,
	.xPos = healthbar13XPos,
	.yPos = healthbar13YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};