#include "main.h"
#include "sprite.h"


Script witchActions[] = {

};

enum Intents phaseToIntent(enum Phase phase, u8 phaseParity){
	switch(phase){
		case PHASE_BASIC:
		return INTENT_ATTACK;
		break;
		
		case PHASE_VAMPIRE:
		return INTENT_ATTACK;
		break;
		
		case PHASE_EXPLOSIVE:
		return INTENT_ATTACK;
		break;
		
		case PHASE_BLOOD:
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
	//figure out what the witch is doing
	switch(gameState.witchPhase){
		case PHASE_BASIC:
		
		break;
		
		case PHASE_VAMPIRE:
		
		break;
		
		case PHASE_EXPLOSIVE:
		
		break;
		
		case PHASE_BLOOD:
		
		break;
		
		case PHASE_CURSE:
		
		break;
	}
	
	scriptList[SCR_BATTLE_MANAGER].scriptInit();
}