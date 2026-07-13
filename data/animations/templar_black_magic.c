#include "video.h"

u32 templarBlackMagicPosFrames[] = {0, 1000};
u32 templarBlackMagicXPos[] = {0};
u32 templarBlackMagicYPos[] = {0};
u32 templarBlackMagicGfxFrames[] = {0, 10, 20, 30, 1000};
u32 templarBlackMagicGfx[] = {0, 1, 2, 3};

Animation templarBlackMagic = {
	.numFrames = 40,
	.gfxFrame = templarBlackMagicGfxFrames,
	.gfx = templarBlackMagicGfx,
	.posFrame = templarBlackMagicPosFrames,
	.xPos = templarBlackMagicXPos,
	.yPos = templarBlackMagicYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};