#include "video.h"

u32 chargePosFrames[] = {0, 1000};
u32 chargeXPos[] = {0};
u32 chargeYPos[] = {0};
u32 chargeGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 1000};
u32 chargeGfx[] = {19, 20, 21, 22, 21, 22, 21, 23};

Animation chargeAnim = {
	.numFrames = 48,
	.gfxFrame = chargeGfxFrames,
	.gfx = chargeGfx,
	.posFrame = chargePosFrames,
	.xPos = chargeXPos,
	.yPos = chargeYPos,
	.graphics = &graphicsList[GFX_WITCH_ATTACKS],
	.mode = ANIM_END,
	.endDetail = 0,
};