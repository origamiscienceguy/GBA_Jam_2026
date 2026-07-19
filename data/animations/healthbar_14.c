#include "video.h"

u32 healthbar14PosFrames[] = {0, 1000};
u32 healthbar14XPos[] = {0};
u32 healthbar14YPos[] = {0};
u32 healthbar14GfxFrames[] = {0, 1000};
u32 healthbar14Gfx[] = {2};

Animation healthbar14 = {
	.numFrames = 1,
	.gfxFrame = healthbar14GfxFrames,
	.gfx = healthbar14Gfx,
	.posFrame = healthbar14PosFrames,
	.xPos = healthbar14XPos,
	.yPos = healthbar14YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};