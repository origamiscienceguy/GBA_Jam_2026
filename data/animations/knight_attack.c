#include "video.h"

u32 knightAttackPosFrames[] = {0, 12, 14, 16, 18, 26, 28, 30, 38, 74, 76, 78, 80};
u32 knightAttackXPos[] = {0, 40, 80, 120, 160, 163, 176, 192, 189, 120, 80, 40, 0};
u32 knightAttackYPos[] = {0, -12, -16, -12, 0, 0, 0, 0, 0, -12, -16, -12, 0};
u32 knightAttackGfxFrames[] = {0, 12, 18, 20, 22, 24, 26, 28, 30, 38, 42, 46, 54, 56, 72, 74, 80};
u32 knightAttackGfx[] = {4, 5, 6, 7, 8, 9, 10, 11, 6, 4, 12, 17, 18, 19, 4, 22, 4};

Animation knightAttack = {
	.numFrames = 84,
	.gfxFrame = knightAttackGfxFrames,
	.gfx = knightAttackGfx,
	.posFrame = knightAttackPosFrames,
	.xPos = knightAttackXPos,
	.yPos = knightAttackYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_LOOP,
	.endDetail = 0,
};