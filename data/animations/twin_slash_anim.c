#include "video.h"

u32 twinSlashAnimGfxFrames[] = {0, 2, 4, 6, 12, 14, 16, 18, 1000};
u32 twinSlashAnimGfx[] = {0, 1, 2, 3, 4, 5, 6, 7};

FullScreenAnimation twinSlashAnim = {
	.numFrames = 30,
	.gfxFrame = twinSlashAnimGfxFrames,
	.gfx = twinSlashAnimGfx,
	.graphics = &graphicsList[GFX_TWIN_SLASH_ANIM],
	.tilemap = &graphicsList[GFX_TWIN_SLASH_ANIM_MAP],
};