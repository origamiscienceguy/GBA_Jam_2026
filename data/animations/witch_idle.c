#include "video.h"

u32 witchIdlePosFrames[] = {0, 1000};
u32 witchIdleXPos[] = {0};
u32 witchIdleYPos[] = {0};
u32 witchIdleGfxFrames[] = {0, 10, 20, 30, 1000};
u32 witchIdleGfx[] = {0, 1, 2, 3};

Animation witchIdle = {
	.numFrames = 40,
	.gfxFrame = witchIdleGfxFrames,
	.gfx = witchIdleGfx,
	.posFrame = witchIdlePosFrames,
	.xPos = witchIdleXPos,
	.yPos = witchIdleYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};