#include "video.h"

u32 healthbarBackPosFrames[] = {0, 1000};
u32 healthbarBackXPos[] = {0};
u32 healthbarBackYPos[] = {0};
u32 healthbarBackGfxFrames[] = {0, 1000};
u32 healthbarBackGfx[] = {0};

Animation healthbarBack = {
	.numFrames = 1,
	.gfxFrame = healthbarBackGfxFrames,
	.gfx = healthbarBackGfx,
	.posFrame = healthbarBackPosFrames,
	.xPos = healthbarBackXPos,
	.yPos = healthbarBackYPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_BACKING],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};