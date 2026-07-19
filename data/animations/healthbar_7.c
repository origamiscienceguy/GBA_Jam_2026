#include "video.h"

u32 healthbar7PosFrames[] = {0, 1000};
u32 healthbar7XPos[] = {0};
u32 healthbar7YPos[] = {0};
u32 healthbar7GfxFrames[] = {0, 1000};
u32 healthbar7Gfx[] = {9};

Animation healthbar7 = {
	.numFrames = 1,
	.gfxFrame = healthbar7GfxFrames,
	.gfx = healthbar7Gfx,
	.posFrame = healthbar7PosFrames,
	.xPos = healthbar7XPos,
	.yPos = healthbar7YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};