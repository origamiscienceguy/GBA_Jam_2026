#include "video.h"

u32 missileAnimGfxFrames[] = {0, 4, 8, 12, 16, 22, 26, 30, 32, 34, 36, 38, 40, 42, 44, 46, 1000};
u32 missileAnimGfx[] = {0, 1, 2, 3, 4, 3, 2, 5, 6, 7, 8, 9, 10, 11, 12, 13};

FullScreenAnimation missileAnim = {
	.numFrames = 50,
	.gfxFrame = missileAnimGfxFrames,
	.gfx = missileAnimGfx,
	.graphics = &graphicsList[GFX_MISSILE_ANIM],
	.tilemap = &graphicsList[GFX_MISSILE_MAP],
};