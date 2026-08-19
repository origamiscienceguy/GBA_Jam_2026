#include "video.h"

u32 tripleSlashAnimGfxFrames[] = {0, 2, 4, 6, 12, 14, 16, 18, 24, 26, 28, 30, 1000};
u32 tripleSlashAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

FullScreenAnimation tripleSlashAnim = {
	.numFrames = 40,
	.gfxFrame = tripleSlashAnimGfxFrames,
	.gfx = tripleSlashAnimGfx,
	.graphics = &graphicsList[GFX_TRIPLE_SLASH_ANIM],
	.tilemap = &graphicsList[GFX_TRIPLE_SLASH_ANIM_MAP],
};