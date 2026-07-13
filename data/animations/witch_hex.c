#include "video.h"

u32 witchHexPosFrames[] = {0, 1000};
u32 witchHexXPos[] = {0};
u32 witchHexYPos[] = {0};
u32 witchHexGfxFrames[] = {0, 20, 22, 50, 52, 1000};
u32 witchHexGfx[] = {19, 20, 21, 22, 23};

Animation witchHex = {
	.numFrames = 80,
	.gfxFrame = witchHexGfxFrames,
	.gfx = witchHexGfx,
	.posFrame = witchHexPosFrames,
	.xPos = witchHexXPos,
	.yPos = witchHexYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};