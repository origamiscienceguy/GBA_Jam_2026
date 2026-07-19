#include "video.h"

u32 healthbar15PosFrames[] = {0, 1000};
u32 healthbar15XPos[] = {0};
u32 healthbar15YPos[] = {0};
u32 healthbar15GfxFrames[] = {0, 1000};
u32 healthbar15Gfx[] = {1};

Animation healthbar15 = {
	.numFrames = 1,
	.gfxFrame = healthbar15GfxFrames,
	.gfx = healthbar15Gfx,
	.posFrame = healthbar15PosFrames,
	.xPos = healthbar15XPos,
	.yPos = healthbar15YPos,
	.graphics = &graphicsList[GFX_HEALTHBAR_FRONT],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};