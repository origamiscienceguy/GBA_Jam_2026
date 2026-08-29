#include "video.h"

extern Animation templarIdle;
extern Animation templarHurt;
extern Animation templarDead;
extern Animation templarTwinSlash;
extern Animation templarTripleSlash;
extern Animation templarSummonBlade;
extern Animation templarSlash;
extern Animation templarRefresh;
extern Animation templarParry;
extern Animation templarMeditate;
extern Animation templarMeat;
extern Animation templarIceCream;
extern Animation templarGuard;
extern Animation templarFocus;
extern Animation templarCranberry;
extern Animation templarBloodBlade;
extern Animation templarBlackMagic;
extern Animation witchIdle;
extern Animation witchHurt;
extern Animation witchDead;
extern Animation witchMissile;
extern Animation witchHex;
extern Animation witchDrain;
extern Animation witchCharge;
extern Animation witchBloodMissile;
extern Animation witchBlast;
extern Animation healthbarBack;
extern Animation healthbar16;
extern Animation healthbar15;
extern Animation healthbar14;
extern Animation healthbar13;
extern Animation healthbar12;
extern Animation healthbar11;
extern Animation healthbar10;
extern Animation healthbar9;
extern Animation healthbar8;
extern Animation healthbar7;
extern Animation healthbar6;
extern Animation healthbar5;
extern Animation healthbar4;
extern Animation healthbar3;
extern Animation healthbar2;
extern Animation healthbar1;
extern Animation healthbar0;
extern Animation playerTurn;
extern Animation witchTurn;
extern Animation meatThrow;
extern Animation cranberryThrow;
extern Animation iceCreamThrow;
extern Animation focus;
extern Animation meditate;
extern Animation guard;
extern Animation parry;
extern Animation refresh;
extern Animation hexAnim;
extern Animation chargeAnim;
extern Animation explosionAnim;
extern FullScreenAnimation blackMagicAnim;
extern FullScreenAnimation slashAnim;
extern FullScreenAnimation twinSlashAnim;
extern FullScreenAnimation tripleSlashAnim;
extern FullScreenAnimation bloodBladeAnim;
extern FullScreenAnimation summonBladeAnim;
extern FullScreenAnimation drainAnim;
extern FullScreenAnimation missileAnim;
extern FullScreenAnimation bloodMissileAnim;

Animation *animationList[] = {
	&templarIdle,
	&templarHurt,
	&templarDead,
	&templarTwinSlash,
	&templarTripleSlash,
	&templarSummonBlade,
	&templarSlash,
	&templarRefresh,
	&templarParry,
	&templarMeditate,
	&templarMeat,
	&templarIceCream,
	&templarGuard,
	&templarFocus,
	&templarCranberry,
	&templarBloodBlade,
	&templarBlackMagic,
	&witchIdle,
	&witchHurt,
	&witchDead,
	&witchMissile,
	&witchHex,
	&witchDrain,
	&witchCharge,
	&witchBloodMissile,
	&witchBlast,
	&healthbarBack,
	&healthbar16,
	&healthbar15,
	&healthbar14,
	&healthbar13,
	&healthbar12,
	&healthbar11,
	&healthbar10,
	&healthbar9,
	&healthbar8,
	&healthbar7,
	&healthbar6,
	&healthbar5,
	&healthbar4,
	&healthbar3,
	&healthbar2,
	&healthbar1,
	&healthbar0,
	&playerTurn,
	&witchTurn,
	&meatThrow,
	&cranberryThrow,
	&iceCreamThrow,
	&focus,
	&meditate,
	&refresh,
	&guard,
	&parry,
	&hexAnim,
	&chargeAnim,
	&explosionAnim,
};

FullScreenAnimation *fullScreenAnimationList[] = {
	&blackMagicAnim,
	&slashAnim,
	&twinSlashAnim,
	&tripleSlashAnim,
	&bloodBladeAnim,
	&summonBladeAnim,
	&drainAnim,
	&missileAnim,
	&bloodMissileAnim,
};