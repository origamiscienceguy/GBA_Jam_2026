#include "video.h"

u32 healthbar12PosFrames[] = {0, 1000};
u32 healthbar12XPos[] = {0};
u32 healthbar12YPos[] = {0};
u32 healthbar12GfxFrames[] = {0, 1000};
u32 healthbar12Gfx[] = {4};

Animation healthbar12 = {
	.numFrames = 1,
	.gfxFrame = healthbar12GfxFrames,
	.gfx = healthbar12Gfx,
	.posFrame = healthbar12PosFrames,
	.xPos = healthbar12XPos,
	.yPos = healthbar12YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};