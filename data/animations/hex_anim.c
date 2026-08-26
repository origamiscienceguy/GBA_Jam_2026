#include "video.h"

u32 hexPosFrames[] = {0, 1000};
u32 hexXPos[] = {0};
u32 hexYPos[] = {0};
u32 hexGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 1000};
u32 hexGfx[] = {11, 12, 13, 14, 15, 16, 17, 18};

Animation hexAnim = {
	.numFrames = 48,
	.gfxFrame = hexGfxFrames,
	.gfx = hexGfx,
	.posFrame = hexPosFrames,
	.xPos = hexXPos,
	.yPos = hexYPos,
	.graphics = &graphicsList[GFX_WITCH_ATTACKS],
	.mode = ANIM_END,
	.endDetail = 0,
};