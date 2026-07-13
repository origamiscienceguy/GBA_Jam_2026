#include "video.h"

u32 witchChargePosFrames[] = {0, 1000};
u32 witchChargeXPos[] = {0};
u32 witchChargeYPos[] = {0};
u32 witchChargeGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 1000};
u32 witchChargeGfx[] = {28, 29, 28, 29, 28, 29, 28, 29};

Animation witchCharge = {
	.numFrames = 48,
	.gfxFrame = witchChargeGfxFrames,
	.gfx = witchChargeGfx,
	.posFrame = witchChargePosFrames,
	.xPos = witchChargeXPos,
	.yPos = witchChargeYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};