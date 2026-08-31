#include "video.h"

u32 deathblowPosFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 59, 1000};
u32 deathblowXPos[] = {0};
u32 deathblowYPos[] = {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 160};
u32 deathblowGfxFrames[] = {0, 1000};
u32 deathblowGfx[] = {0};

Animation deathblowAnim = {
	.numFrames = 60,
	.gfxFrame = deathblowGfxFrames,
	.gfx = deathblowGfx,
	.posFrame = deathblowPosFrames,
	.xPos = deathblowXPos,
	.yPos = deathblowYPos,
	.graphics = &graphicsList[GFX_DEATHBLOW],
	.mode = ANIM_END,
	.endDetail = 0,
};