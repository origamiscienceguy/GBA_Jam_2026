#include "video.h"

u32 templarFocusPosFrames[] = {0, 1000};
u32 templarFocusXPos[] = {0};
u32 templarFocusYPos[] = {0};
u32 templarFocusGfxFrames[] = {0, 1000};
u32 templarFocusGfx[] = {4};

Animation templarFocus = {
	.numFrames = 68,
	.gfxFrame = templarFocusGfxFrames,
	.gfx = templarFocusGfx,
	.posFrame = templarFocusPosFrames,
	.xPos = templarFocusXPos,
	.yPos = templarFocusYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};