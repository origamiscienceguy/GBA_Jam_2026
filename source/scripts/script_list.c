#include "main.h"

extern void battleInit();
extern void battleRun();

Script scriptList[] = {
	{.scriptInit = battleInit, .scriptRun = battleRun,},
};