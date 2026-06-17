#include "tonc.h"
#include "audio.h"

extern cu8 fwfMainLoop[];
cu32 fwfMainLoopLength = 3774874;
extern cu8 fwfMenu[];
cu32 fwfMenuLength = 1926758;
extern cu8 fwfGameover[];
cu32 fwfGameoverLength = 1625418;

const Sound musicList[] = {
	{.source = fwfMainLoop, .length = fwfMainLoopLength, .mode = LOOP},
	{.source = fwfMenu, .length = fwfMenuLength, .mode = LOOP},
	{.source = fwfGameover, .length = fwfGameoverLength, .mode = LOOP},
};
