#include "video.h"

u32 templarDeadPosFrames[] = {0, 1000};
u32 templarDeadXPos[] = {0};
u32 templarDeadYPos[] = {0};
u32 templarDeadGfxFrames[] = {0, 1000};
u32 templarDeadGfx[] = {29};

Animation templarDead = {
	.numFrames = 10,
	.gfxFrame = templarDeadGfxFrames,
	.gfx = templarDeadGfx,
	.posFrame = templarDeadPosFrames,
	.xPos = templarDeadXPos,
	.yPos = templarDeadYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};