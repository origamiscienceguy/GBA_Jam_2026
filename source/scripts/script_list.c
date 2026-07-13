#include "main.h"

extern void battleInit();
extern void battleRun();
extern void battleStartInit();
extern void battleStartRun();
extern void slashInit();
extern void slashRun();

Script scriptList[] = {
	{.scriptInit = battleInit, .scriptRun = battleRun,},
	{.scriptInit = battleStartInit, .scriptRun = battleStartRun,},
	{.scriptInit = slashInit, .scriptRun = slashRun,},
};
