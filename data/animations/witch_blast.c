#include "video.h"

u32 witchBlastPosFrames[] = {0, 1000};
u32 witchBlastXPos[] = {0};
u32 witchBlastYPos[] = {0};
u32 witchBlastGfxFrames[] = {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 1000};
u32 witchBlastGfx[] = {28, 29, 28, 29, 28, 29, 28, 29, 28, 29, 28, 29};

Animation witchBlast = {
	.numFrames = 72,
	.gfxFrame = witchBlastGfxFrames,
	.gfx = witchBlastGfx,
	.posFrame = witchBlastPosFrames,
	.xPos = witchBlastXPos,
	.yPos = witchBlastYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};