#include "video.h"

u32 templarTwinSlashPosFrames[] = {0, 12, 14, 16, 18, 26, 28, 30, 38, 100, 102, 104, 106, 1000};
u32 templarTwinSlashXPos[] = {0, 25, 50, 75, 100, 103, 116, 132, 129, 75, 50, 25, 0};
u32 templarTwinSlashYPos[] = {0, -12, -16, -12, 0, 0, 0, 0, 0, -12, -16, -12, 0};
u32 templarTwinSlashGfxFrames[] = {0, 12, 18, 20, 22, 24, 26, 28, 30, 38, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 68, 70, 80, 82, 98, 100, 106, 1000};
u32 templarTwinSlashGfx[] = {4, 5, 6, 7, 8, 9, 10, 11, 6, 4, 12, 13, 14, 15, 16, 13, 14, 15, 16, 17, 18, 19, 20, 21, 4, 22, 4};

Animation templarTwinSlash = {
	.numFrames = 110,
	.gfxFrame = templarTwinSlashGfxFrames,
	.gfx = templarTwinSlashGfx,
	.posFrame = templarTwinSlashPosFrames,
	.xPos = templarTwinSlashXPos,
	.yPos = templarTwinSlashYPos,
	.graphics = &graphicsList[GFX_TEMPLAR],
	.mode = ANIM_END,
	.endDetail = 0,
};