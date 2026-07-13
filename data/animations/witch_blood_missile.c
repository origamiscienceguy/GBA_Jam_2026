#include "video.h"

u32 witchBloodMissilePosFrames[] = {0, 1000};
u32 witchBloodMissileXPos[] = {0};
u32 witchBloodMissileYPos[] = {0};
u32 witchBloodMissileGfxFrames[] = {0, 20, 22, 50, 52, 1000};
u32 witchBloodMissileGfx[] = {19, 24, 25, 26, 27};

Animation witchBloodMissile = {
	.numFrames = 94,
	.gfxFrame = witchBloodMissileGfxFrames,
	.gfx = witchBloodMissileGfx,
	.posFrame = witchBloodMissilePosFrames,
	.xPos = witchBloodMissileXPos,
	.yPos = witchBloodMissileYPos,
	.graphics = &graphicsList[GFX_WITCH],
	.mode = ANIM_END,
	.endDetail = 0,
};