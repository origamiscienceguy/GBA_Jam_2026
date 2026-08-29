#include "video.h"

u32 bloodMissileAnimGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 1000};
u32 bloodMissileAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

FullScreenAnimation bloodMissileAnim = {
	.numFrames = 84,
	.gfxFrame = bloodMissileAnimGfxFrames,
	.gfx = bloodMissileAnimGfx,
	.graphics = &graphicsList[GFX_BLOOD_MISSILE_ANIM],
	.tilemap = &graphicsList[GFX_BLOOD_MISSILE_MAP],
};