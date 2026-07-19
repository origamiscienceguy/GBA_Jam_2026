#include "video.h"

u32 healthbar2PosFrames[] = {0, 1000};
u32 healthbar2XPos[] = {0};
u32 healthbar2YPos[] = {0};
u32 healthbar2GfxFrames[] = {0, 1000};
u32 healthbar2Gfx[] = {14};

Animation healthbar2 = {
	.numFrames = 1,
	.gfxFrame = healthbar2GfxFrames,
	.gfx = healthbar2Gfx,
	.posFrame = healthbar2PosFrames,
	.xPos = healthbar2XPos,
	.yPos = healthbar2YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};