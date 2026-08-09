#include "video.h"

u32 focusPosFrames[] = {0, 1000};
u32 focusXPos[] = {0};
u32 focusYPos[] = {0};
u32 focusGfxFrames[] = {0, 4, 8, 12, 16, 20, 48, 52, 56, 60, 64, 1000};
u32 focusGfx[] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

Animation focus = {
	.numFrames = 68,
	.gfxFrame = focusGfxFrames,
	.gfx = focusGfx,
	.posFrame = focusPosFrames,
	.xPos = focusXPos,
	.yPos = focusYPos,
	.graphics = &graphicsList[GFX_TEMPLAR_BONUSES],
	.mode = ANIM_END,
	.endDetail = 0,
};