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
extern void blackMagicInit();
extern void blackMagicRun();
extern void meatInit();
extern void meatRun();
extern void cranberryInit();
extern void cranberryRun();
extern void iceCreamInit();
extern void iceCreamRun();
extern void guardInit();
extern void guardRun();
extern void parryInit();
extern void parryRun();
extern void refreshInit();
extern void refreshRun();
extern void focusInit();
extern void focusRun();
extern void meditateInit();
extern void meditateRun();
extern void bloodBladeInit();
extern void bloodBladeRun();
extern void summonBladeInit();
extern void summonBladeRun();
extern void twinSlashInit();
extern void twinSlashRun();
extern void tripleSlashInit();
extern void tripleSlashRun();
extern void hexInit();
extern void hexRun();
extern void chargeInit();
extern void chargeRun();
extern void explosionInit();
extern void explosionRun();
extern void vampireInit();
extern void vampireRun();
extern void missileInit();
extern void missileRun();
extern void bloodInit();
extern void bloodRun();

Script scriptList[] = {
	{.scriptInit = playerTurnInit, .scriptRun = playerTurnRun,},
	{.scriptInit = witchTurnInit, .scriptRun = witchTurnRun,},
	{.scriptInit = battleStartInit, .scriptRun = battleStartRun,},
	{.scriptInit = battleManagerInit, .scriptRun = battleManagerRun,},
	{.scriptInit = slashInit, .scriptRun = slashRun,},
	{.scriptInit = blackMagicInit, .scriptRun = blackMagicRun,},
	{.scriptInit = meatInit, .scriptRun = meatRun,},
	{.scriptInit = cranberryInit, .scriptRun = cranberryRun,},
	{.scriptInit = iceCreamInit, .scriptRun = iceCreamRun,},
	{.scriptInit = guardInit, .scriptRun = guardRun,},
	{.scriptInit = parryInit, .scriptRun = parryRun,},
	{.scriptInit = refreshInit, .scriptRun = refreshRun,},
	{.scriptInit = focusInit, .scriptRun = focusRun,},
	{.scriptInit = meditateInit, .scriptRun = meditateRun,},
	{.scriptInit = bloodBladeInit, .scriptRun = bloodBladeRun,},
	{.scriptInit = summonBladeInit, .scriptRun = summonBladeRun,},
	{.scriptInit = twinSlashInit, .scriptRun = twinSlashRun,},
	{.scriptInit = tripleSlashInit, .scriptRun = tripleSlashRun,},
	{.scriptInit = hexInit, .scriptRun = hexRun,},
	{.scriptInit = chargeInit, .scriptRun = chargeRun,},
	{.scriptInit = explosionInit, .scriptRun = explosionRun,},
	{.scriptInit = vampireInit, .scriptRun = vampireRun,},
	{.scriptInit = missileInit, .scriptRun = missileRun,},
	{.scriptInit = bloodInit, .scriptRun = bloodRun,},
};
