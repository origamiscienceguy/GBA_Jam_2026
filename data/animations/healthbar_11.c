#include "video.h"

u32 healthbar11PosFrames[] = {0, 1000};
u32 healthbar11XPos[] = {0};
u32 healthbar11YPos[] = {0};
u32 healthbar11GfxFrames[] = {0, 1000};
u32 healthbar11Gfx[] = {5};

Animation healthbar11 = {
	.numFrames = 1,
	.gfxFrame = healthbar11GfxFrames,
	.gfx = healthbar11Gfx,
	.posFrame = healthbar11PosFrames,
	.xPos = healthbar11XPos,
	.yPos = healthbar11YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};