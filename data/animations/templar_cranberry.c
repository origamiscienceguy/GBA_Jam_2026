#include "video.h"

u32 templarCranberryPosFrames[] = {0, 1000};
u32 templarCranberryXPos[] = {0};
u32 templarCranberryYPos[] = {0};
u32 templarCranberryGfxFrames[] = {0, 30, 32, 48, 1000};
u32 templarCranberryGfx[] = {30, 31, 32, 33};

Animation templarCranberry = {
	.numFrames = 70,
	.gfxFrame = templarCranberryGfxFrames,
	.gfx = templarCranberryGfx,
	.posFrame = templarCranberryPosFrames,
	.xPos = templarCranberryXPos,
	.yPos = templarCranberryYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};