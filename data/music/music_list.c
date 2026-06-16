#include "tonc.h"
#include "audio.h"

extern cu8 fwfMainLoop[];
extern cu32 fwfMainLoopLength;
extern cu8 fwfMenu[];
extern cu32 fwfMenuLength;
extern cu8 fwfGameover[];
extern cu32 fwfGameoverLength;

const Sound musicList[] = {
	{.source = fwfMainLoop, .length = &fwfMainLoopLength, .mode = LOOP},
	{.source = fwfMenu, .length = &fwfMenuLength, .mode = LOOP},
	{.source = fwfGameover, .length = &fwfGameoverLength, .mode = LOOP},
};
