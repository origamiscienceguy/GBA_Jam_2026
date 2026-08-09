#include "video.h"

u32 blackMagicAnimGfxFrames[] = {0, 2, 4, 6, 12, 18, 24, 48, 54, 60, 90, 94, 98, 102, 1000};
u32 blackMagicAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

FullScreenAnimation blackMagicAnim = {
	.numFrames = 106,
	.gfxFrame = blackMagicAnimGfxFrames,
	.gfx = blackMagicAnimGfx,
	.graphics = &graphicsList[GFX_BLACK_MAGIC_ANIM],
	.tilemap = &graphicsList[GFX_BLACK_MAGIC_MAP],
};