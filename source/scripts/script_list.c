#include "main.h"

extern void playerTurnInit();
extern void playerTurnRun();
extern void witchTurnInit();
extern void witchTurnRun();
extern void battleStartInit();
extern void battleStartRun();
extern void battleManagerInit();
extern void battleManagerRun();
extern void slashInit();
extern void slashRun();
extern void missileInit();
extern void missileRun();

Script scriptList[] = {
	{.scriptInit = playerTurnInit, .scriptRun = playerTurnRun,},
	{.scriptInit = witchTurnInit, .scriptRun = witchTurnRun,},
	{.scriptInit = battleStartInit, .scriptRun = battleStartRun,},
	{.scriptInit = battleManagerInit, .scriptRun = battleManagerRun,},
	{.scriptInit = slashInit, .scriptRun = slashRun,},
	{.scriptInit = missileInit, .scriptRun = missileRun,},
};
