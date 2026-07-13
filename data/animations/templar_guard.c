#include "video.h"

u32 templarGuardPosFrames[] = {0, 1000};
u32 templarGuardXPos[] = {0};
u32 templarGuardYPos[] = {0};
u32 templarGuardGfxFrames[] = {0, 1000};
u32 templarGuardGfx[] = {4};

Animation templarGuard = {
	.numFrames = 40,
	.gfxFrame = templarGuardGfxFrames,
	.gfx = templarGuardGfx,
	.posFrame = templarGuardPosFrames,
	.xPos = templarGuardXPos,
	.yPos = templarGuardYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};