#include "video.h"

u32 playerTurnPosFrames[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 1000};
u32 playerTurnXPos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u32 playerTurnYPos[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
u32 playerTurnGfxFrames[] = {0, 1000};
u32 playerTurnGfx[] = {0};

Animation playerTurn = {
	.numFrames = 64,
	.gfxFrame = playerTurnGfxFrames,
	.gfx = playerTurnGfx,
	.posFrame = playerTurnPosFrames,
	.xPos = playerTurnXPos,
	.yPos = playerTurnYPos,
	.graphics = &graphicsList[GFX_PLAYER_TURN],
	.mode = ANIM_END,
	.endDetail = 0,
};