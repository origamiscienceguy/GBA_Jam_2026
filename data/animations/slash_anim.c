#include "video.h"

u32 slashAnimGfxFrames[] = {0, 2, 4, 6, 1000};
u32 slashAnimGfx[] = {0, 1, 2, 3};

FullScreenAnimation slashAnim = {
	.numFrames = 8,
	.gfxFrame = slashAnimGfxFrames,
	.gfx = slashAnimGfx,
	.graphics = &graphicsList[GFX_SLASH_ANIM],
	.tilemap = &graphicsList[GFX_SLASH_ANIM_MAP],
};