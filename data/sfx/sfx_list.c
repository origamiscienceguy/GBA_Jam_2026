#include "tonc.h"
#include "sfx_list.h"

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

cu8 *sfxList[] = {
	blackMagic,
	buttonSelect1,
	buttonSelect2,
	criticalHit,
	defend,
	explosion,
	hex,
	levelUp,
	missile1,
	missile2,
	missileFull,
	powerUp,
	restore,
	slash,
};

cu32 *sfxListLength[] = {
	&blackMagicLength,
	&buttonSelect1Length,
	&buttonSelect2Length,
	&criticalHitLength,
	&defendLength,
	&explosionLength,
	&hexLength,
	&levelUpLength,
	&missile1Length,
	&missile2Length,
	&missileFullLength,
	&powerUpLength,
	&restoreLength,
	&slashLength,
};