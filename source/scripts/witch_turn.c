#include "main.h"
#include "sprite.h"


WitchAction witchActions[] = {
	{.parity0Script = &scriptList[SCR_MISSILE], .parity1Script = &scriptList[SCR_MISSILE]},
	{.parity0Script = &scriptList[SCR_VAMPIRE], .parity1Script = &scriptList[SCR_VAMPIRE]},
	{.parity0Script = &scriptList[SCR_BLOOD], .parity1Script = &scriptList[SCR_BLOOD]},
	{.parity0Script = &scriptList[SCR_CHARGE], .parity1Script = &scriptList[SCR_EXPLOSION]},
	{.parity0Script = &scriptList[SCR_HEX], .parity1Script = &scriptList[SCR_MISSILE]},
};

enum Intents phaseToIntent(enum Phase phase, u8 phaseParity){
	switch(phase){
		case PHASE_BASIC:
		return INTENT_ATTACK;
		break;
		
		case PHASE_VAMPIRE:
		return INTENT_ATTACK;
		break;
		
		case PHASE_BLOOD:
		return INTENT_ATTACK;
		break;
		
		case PHASE_EXPLOSIVE:
		if(phaseParity){
			return INTENT_ATTACK;
		}
		return INTENT_CHARGE;
		break;
		
		case PHASE_CURSE:
		if(phaseParity){
			return INTENT_ATTACK;
		}		
		return INTENT_DEBUFF;
		break;
	}
	return INTENT_ATTACK;
}

void witchTurnInit(){
	gameState.currentScript = SCR_WITCH_TURN;
	gameState.scriptCounter = 0;
}

void witchTurnRun(){
	//go to the witches current script
	if(gameState.witchPhaseParity == 0){
		witchActions[gameState.witchPhase].parity0Script->scriptInit();
	}
	else{
		witchActions[gameState.witchPhase].parity1Script->scriptInit();
	}
	
	//scriptList[SCR_BATTLE_MANAGER].scriptInit();
}