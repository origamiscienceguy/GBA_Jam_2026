#include "video.h"

u32 bloodBladeAnimGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 20, 24, 28, 32, 48, 50, 52, 54, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 1000};
u32 bloodBladeAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 4, 5, 6, 7, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

FullScreenAnimation bloodBladeAnim = {
	.numFrames = 108,
	.gfxFrame = bloodBladeAnimGfxFrames,
	.gfx = bloodBladeAnimGfx,
	.graphics = &graphicsList[GFX_BLOOD_BLADE_ANIM],
	.tilemap = &graphicsList[GFX_BLOOD_BLADE_MAP],
};