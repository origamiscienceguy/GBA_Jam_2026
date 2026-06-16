#include "tonc.h"
#include "audio.h"

extern cu8 blackMagic[];
extern cu32 blackMagicLength;
extern cu8 buttonSelect1[];
extern cu32 buttonSelect1Length;
extern cu8 buttonSelect2[];
extern cu32 buttonSelect2Length;
extern cu8 criticalHit[];
extern cu32 criticalHitLength;
extern cu8 defend[];
extern cu32 defendLength;
extern cu8 explosion[];
extern cu32 explosionLength;
extern cu8 hex[];
extern cu32 hexLength;
extern cu8 levelUp[];
extern cu32 levelUpLength;
extern cu8 missile1[];
extern cu32 missile1Length;
extern cu8 missile2[];
extern cu32 missile2Length;
extern cu8 missileFull[];
extern cu32 missileFullLength;
extern cu8 powerUp[];
extern cu32 powerUpLength;
extern cu8 restore[];
extern cu32 restoreLength;
extern cu8 slash[];
extern cu32 slashLength;

const Sound sfxList[] = {
	{.source = blackMagic, .length = &blackMagicLength, .mode = CUT},
	{.source = buttonSelect1, .length = &buttonSelect1Length, .mode = CUT},
	{.source = buttonSelect2, .length = &buttonSelect2Length, .mode = CUT},
	{.source = criticalHit, .length = &criticalHitLength, .mode = CUT},
	{.source = defend, .length = &defendLength, .mode = CUT},
	{.source = explosion, .length = &explosionLength, .mode = CUT},
	{.source = hex, .length = &hexLength, .mode = CUT},
	{.source = levelUp, .length = &levelUpLength, .mode = CUT},
	{.source = missile1, .length = &missile1Length, .mode = CUT},
	{.source = missile2, .length = &missile2Length, .mode = CUT},
	{.source = missileFull, .length = &missileFullLength, .mode = CUT},
	{.source = powerUp, .length = &powerUpLength, .mode = CUT},
	{.source = restore, .length = &restoreLength, .mode = CUT},
	{.source = slash, .length = &slashLength, .mode = CUT},
};