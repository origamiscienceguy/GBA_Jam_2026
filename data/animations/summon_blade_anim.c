#include "video.h"

u32 summonBladeAnimGfxFrames[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 20, 24, 28, 32, 48, 50, 52, 54, 56, 84, 88, 92, 96, 1000};
u32 summonBladeAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 4, 5, 6, 7, 4, 8, 9, 10, 11, 12, 13, 14, 15, 16};

FullScreenAnimation summonBladeAnim = {
	.numFrames = 100,
	.gfxFrame = summonBladeAnimGfxFrames,
	.gfx = summonBladeAnimGfx,
	.graphics = &graphicsList[GFX_SUMMON_BLADE_ANIM],
	.tilemap = &graphicsList[GFX_SUMMON_BLADE_MAP],
};