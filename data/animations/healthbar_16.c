#include "video.h"

u32 healthbar16PosFrames[] = {0, 1000};
u32 healthbar16XPos[] = {0};
u32 healthbar16YPos[] = {0};
u32 healthbar16GfxFrames[] = {0, 1000};
u32 healthbar16Gfx[] = {0};

Animation healthbar16 = {
	.numFrames = 1,
	.gfxFrame = healthbar16GfxFrames,
	.gfx = healthbar16Gfx,
	.posFrame = healthbar16PosFrames,
	.xPos = healthbar16XPos,
	.yPos = healthbar16YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};