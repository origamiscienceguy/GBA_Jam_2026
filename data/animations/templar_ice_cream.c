#include "video.h"

u32 templarIceCreamPosFrames[] = {0, 1000};
u32 templarIceCreamXPos[] = {0};
u32 templarIceCreamYPos[] = {0};
u32 templarIceCreamGfxFrames[] = {0, 30, 32, 48, 1000};
u32 templarIceCreamGfx[] = {30, 31, 32, 33};

Animation templarIceCream = {
	.numFrames = 70,
	.gfxFrame = templarIceCreamGfxFrames,
	.gfx = templarIceCreamGfx,
	.posFrame = templarIceCreamPosFrames,
	.xPos = templarIceCreamXPos,
	.yPos = templarIceCreamYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};