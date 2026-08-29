#include "video.h"

u32 drainAnimGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 54, 60, 66, 72, 78, 84, 90, 96, 1000};
u32 drainAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

FullScreenAnimation drainAnim = {
	.numFrames = 102,
	.gfxFrame = drainAnimGfxFrames,
	.gfx = drainAnimGfx,
	.graphics = &graphicsList[GFX_DRAIN_ANIM],
	.tilemap = &graphicsList[GFX_DRAIN_MAP],
};