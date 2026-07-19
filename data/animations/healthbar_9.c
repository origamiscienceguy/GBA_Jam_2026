#include "video.h"

u32 healthbar9PosFrames[] = {0, 1000};
u32 healthbar9XPos[] = {0};
u32 healthbar9YPos[] = {0};
u32 healthbar9GfxFrames[] = {0, 1000};
u32 healthbar9Gfx[] = {7};

Animation healthbar9 = {
	.numFrames = 1,
	.gfxFrame = healthbar9GfxFrames,
	.gfx = healthbar9Gfx,
	.posFrame = healthbar9PosFrames,
	.xPos = healthbar9XPos,
	.yPos = healthbar9YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};