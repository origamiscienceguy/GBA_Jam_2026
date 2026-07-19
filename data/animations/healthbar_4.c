#include "video.h"

u32 healthbar4PosFrames[] = {0, 1000};
u32 healthbar4XPos[] = {0};
u32 healthbar4YPos[] = {0};
u32 healthbar4GfxFrames[] = {0, 1000};
u32 healthbar4Gfx[] = {12};

Animation healthbar4 = {
	.numFrames = 1,
	.gfxFrame = healthbar4GfxFrames,
	.gfx = healthbar4Gfx,
	.posFrame = healthbar4PosFrames,
	.xPos = healthbar4XPos,
	.yPos = healthbar4YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};