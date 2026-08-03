#include "video.h"

u32 blackMagicAnimGfxFrames[] = {0, 4, 8, 12, 1000};
u32 blackMagicAnimGfx[] = {0, 1, 2, 3};

FullScreenAnimation blackMagicAnim = {
	.numFrames = 16,
	.gfxFrame = blackMagicAnimGfxFrames,
	.gfx = blackMagicAnimGfx,
	.graphics = &graphicsList[GFX_TWIN_SLASH_ANIM],
	.tilemap = &graphicsList[GFX_TWIN_SLASH_ANIM_MAP],
};