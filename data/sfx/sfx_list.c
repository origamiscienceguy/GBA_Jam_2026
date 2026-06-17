#include "tonc.h"
#include "audio.h"

extern cu8 blackMagic[];
cu32 blackMagicLength = 104858;
extern cu8 buttonSelect1[];
cu32 buttonSelect1Length = 3766;
extern cu8 buttonSelect2[];
cu32 buttonSelect2Length = 15131;
extern cu8 criticalHit[];
cu32 criticalHitLength = 22599;
extern cu8 defend[];
cu32 defendLength = 42598;
extern cu8 explosion[];
cu32 explosionLength = 31711;
extern cu8 hex[];
cu32 hexLength = 22599;
extern cu8 levelUp[];
cu32 levelUpLength = 35829;
extern cu8 missile1[];
cu32 missile1Length = 21497;
extern cu8 missile2[];
cu32 missile2Length = 28322;
extern cu8 missileFull[];
cu32 missileFullLength = 52548;
extern cu8 powerUp[];
cu32 powerUpLength = 38362;
extern cu8 restore[];
cu32 restoreLength = 22599;
extern cu8 slash[];
cu32 slashLength = 34669;

const Sound sfxList[] = {
	{.source = blackMagic, .length = blackMagicLength, .mode = CUT},
	{.source = buttonSelect1, .length = buttonSelect1Length, .mode = CUT},
	{.source = buttonSelect2, .length = buttonSelect2Length, .mode = CUT},
	{.source = criticalHit, .length = criticalHitLength, .mode = CUT},
	{.source = defend, .length = defendLength, .mode = CUT},
	{.source = explosion, .length = explosionLength, .mode = CUT},
	{.source = hex, .length = hexLength, .mode = CUT},
	{.source = levelUp, .length = levelUpLength, .mode = CUT},
	{.source = missile1, .length = missile1Length, .mode = CUT},
	{.source = missile2, .length = missile2Length, .mode = CUT},
	{.source = missileFull, .length = missileFullLength, .mode = CUT},
	{.source = powerUp, .length = powerUpLength, .mode = CUT},
	{.source = restore, .length = restoreLength, .mode = CUT},
	{.source = slash, .length = slashLength, .mode = CUT},
};