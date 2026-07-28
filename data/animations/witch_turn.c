#include "video.h"

u32 witchTurnPosFrames[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 1000};
u32 witchTurnXPos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u32 witchTurnYPos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
u32 witchTurnGfxFrames[] = {0, 1000};
u32 witchTurnGfx[] = {0};

Animation witchTurn = {
	.numFrames = 48,
	.gfxFrame = witchTurnGfxFrames,
	.gfx = witchTurnGfx,
	.posFrame = witchTurnPosFrames,
	.xPos = witchTurnXPos,
	.yPos = witchTurnYPos,
	.graphics = &graphicsList[GFX_WITCH_TURN],
	.mode = ANIM_END,
	.endDetail = 0,
};