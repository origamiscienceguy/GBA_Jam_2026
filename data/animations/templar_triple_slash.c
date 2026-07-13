#include "video.h"

u32 templarTripleSlashPosFrames[] = {0, 12, 14, 16, 18, 26, 28, 30, 38, 120, 122, 124, 126, 1000};
u32 templarTripleSlashXPos[] = {0, 40, 80, 120, 160, 163, 176, 192, 189, 120, 80, 40, 0};
u32 templarTripleSlashYPos[] = {0, -12, -16, -12, 0, 0, 0, 0, 0, -12, -16, -12, 0};
u32 templarTripleSlashGfxFrames[] = {0, 12, 18, 20, 22, 24, 26, 28, 30, 38, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 76, 78, 88, 90, 100, 102, 118, 120, 1261000};
u32 templarTripleSlashGfx[] = {4, 5, 6, 7, 8, 9, 10, 11, 6, 4, 12, 13, 14, 15, 16, 13, 14, 15, 16, 13, 14, 15, 16, 17, 18, 19, 20, 21, 23, 24, 4, 22, 4};

Animation templarTripleSlash = {
	.numFrames = 128,
	.gfxFrame = templarTripleSlashGfxFrames,
	.gfx = templarTripleSlashGfx,
	.posFrame = templarTripleSlashPosFrames,
	.xPos = templarTripleSlashXPos,
	.yPos = templarTripleSlashYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};