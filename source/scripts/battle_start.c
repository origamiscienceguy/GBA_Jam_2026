#include "main.h"
#include "sprite.h"

void battleStartInit(){
	//setup the starting action palette

	//debug
	for(u32 i = 0; i < 10; i++){
		gameState.actionPalette[i] = ACT_EMPTY;
	}
	//set the starting action palette
	gameState.actionPalette[0] = ACT_SLASH;
	gameState.actionPalette[1] = ACT_GUARD;
	gameState.actionPalette[2] = ACT_FOCUS;
	gameState.actionPalette[3] = ACT_BLACK_MAGIC;
	gameState.actionPalette[4] = ACT_BLOOD_BLADE;
	gameState.actionPalette[5] = ACT_SUMMON_BLADE;
	gameState.actionPalette[6] = ACT_TWIN_SLASH;
	gameState.actionPalette[7] = ACT_TRIPLE_SLASH;
	gameState.actionPalette[8] = ACT_PARRY;
	gameState.actionPalette[9] = ACT_REFRESH;

	gameState.itemThrowID = playAnimation(ANIM_MEAT_THROW, ITEM_THROW_X, 160);
	gameState.templarBonusID = playAnimation(ANIM_GUARD, GUARD_X, 160);
	gameState.templarAnimationID = playAnimation(ANIM_TEMPLAR_IDLE, TEMPLAR_X, TEMPLAR_Y);
	gameState.witchAnimationID = playAnimation(ANIM_WITCH_IDLE, WITCH_X, WITCH_Y);
	gameState.templarHealthFrontID = playAnimation(ANIM_HEALTH_BAR_16, TEMPLAR_HEALTH_FRONT_X, TEMPLAR_HEALTH_FRONT_Y);
	gameState.witchHealthFrontID = playAnimation(ANIM_HEALTH_BAR_16, WITCH_HEALTH_FRONT_X, WITCH_HEALTH_FRONT_Y);
	gameState.templarHealthBackID = playAnimation(ANIM_HEALTH_BAR_BACK, TEMPLAR_HEALTH_BACK_X, TEMPLAR_HEALTH_BACK_Y);
	gameState.witchHealthBackID = playAnimation(ANIM_HEALTH_BAR_BACK, WITCH_HEALTH_BACK_X, WITCH_HEALTH_BACK_Y);
	gameState.templarTurnID = playAnimation(ANIM_PLAYER_TURN, TURN_X, 160);
	gameState.witchTurnID = playAnimation(ANIM_WITCH_TURN, TURN_X, 160);

	startFullScreenAnim(FSANIM_NONE);

	playSong(MAIN_LOOP);
	
	gameState.selectedAction = 0;
	gameState.numAvailableActions = 10;
	gameState.witchHealth = 4;
	gameState.witchMaxHealth = 4;
	gameState.templarHealth = 1;
	gameState.templarMaxHealth = 5;
	gameState.witchHealthMessageID = 0xff;
	gameState.templarHealthMessageID = 0xff;
	gameState.templarDamage = 3;
	gameState.witchDamage = 1;
	gameState.templarLevel = 1;
	gameState.witchLevel = 1;
	gameState.templarLevelMessageID = 0xff;
	gameState.witchLevelMessageID = 0xff;
	gameState.intentMessageID = 0xff;
	gameState.currentTurn = 1;
	gameState.witchPhase = PHASE_BASIC;
	gameState.witchPhaseParity = 0;
	gameState.witchPhaseLevel = 0;
	gameState.criticalHit = 0;
	gameState.defendStatus = 0;
	gameState.templarExp = 0;
	gameState.templarNeededExp = 7;
	
	witchHealthUpdate(gameState.witchHealth, gameState.witchMaxHealth, 0);
	witchLevelUpdate(gameState.witchLevel, 0);
	templarHealthUpdate(gameState.templarHealth, gameState.templarMaxHealth, 0);
	templarLevelUpdate(gameState.templarLevel);
	intentUpdate(INTENT_ATTACK);
	
	for(u32 i = 0; i < 10; i++){
		gameState.actionCooldown[i] = 0;
		gameState.cooldownTextID[i] = 0xff;
	}
	
	scriptList[SCR_BATTLE_MANAGER].scriptInit();
}
	
void battleStartRun(){};