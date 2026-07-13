#include "video.h"

u32 witchMissilePosFrames[] = {0, 1000};
u32 witchMissileXPos[] = {0};
u32 witchMissileYPos[] = {0};
u32 witchMissileGfxFrames[] = {0, 20, 22, 50, 52, 1000};
u32 witchMissileGfx[] = {19, 20, 21, 22, 23};

Animation witchMissile = {
	.numFrames = 120,
	.gfxFrame = witchMissileGfxFrames,
	.gfx = witchMissileGfx,
	.posFrame = witchMissilePosFrames,
	.xPos = witchMissileXPos,
	.yPos = witchMissileYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};