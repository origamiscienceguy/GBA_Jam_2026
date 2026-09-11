#include "main.h"
#include "sprite.h"

void openSkillTreeInit(){
	//setup the starting action palette
	
	if(gameState.witchHealthMessageID != 0xff){
		closeText(gameState.witchHealthMessageID);
		gameState.witchHealthMessageID = 0xff;
	}
	if(gameState.templarHealthMessageID != 0xff){
		closeText(gameState.templarHealthMessageID);
		gameState.templarHealthMessageID = 0xff;
	}
	if(gameState.templarLevelMessageID != 0xff){
		closeText(gameState.templarLevelMessageID);
		gameState.templarLevelMessageID = 0xff;
	}
	if(gameState.witchLevelMessageID != 0xff){
		closeText(gameState.witchLevelMessageID);
		gameState.witchLevelMessageID = 0xff;
	}
	if(gameState.intentMessageID != 0xff){
		closeText(gameState.intentMessageID);
		gameState.intentMessageID = 0xff;
	}
	if(gameState.levelUpsTextID != 0xff){
		closeText(gameState.levelUpsTextID);
		gameState.levelUpsTextID = 0xff;
	}
	if(gameState.expAmountTextID != 0xff){
		closeText(gameState.expAmountTextID);
		gameState.expAmountTextID = 0xff;
	}
	
	for(u32 i = 0; i < 10; i++){
		if(gameState.cooldownTextID[i] != 0xff){
			closeText(gameState.cooldownTextID[i]);
		}
		gameState.cooldownTextID[i] = 0xff;
	}
	
	memcpy32(&(tile_mem[1][0]), graphicsList[GFX_SKILL_TREE_BACKGROUND].data, graphicsList[GFX_SKILL_TREE_BACKGROUND].numWords);
	memcpy32(&(tile_mem[1][7]), graphicsList[GFX_SKILLS].data, graphicsList[GFX_SKILLS].numWords);
	
	for(u32 i = 0; i < 20; i++){
		for(u32 j = 0; j < 15; j++){
			se_mem[29][i * 32 + j * 2] = (u16)((graphicsList[GFX_SKILL_TREE_BACKGROUND_MAP].data[i * 15 + j] + 0x1000) & 0xffff);
			se_mem[29][i * 32 + j * 2 + 1] = (u16)((graphicsList[GFX_SKILL_TREE_BACKGROUND_MAP].data[i * 15 + j] >> 16) + 0x1000);
		}
	}
	
	gameState.selectedSkill = SKILL_ATTACK_1;
	gameState.skillStates[SKILL_ATTACK_1] = SKILL_AVAILABLE_VIEWED;
	REG_BG1CNT = BG_4BPP | BG_REG_32x32 | BG_PRIO(1) | BG_CBB(1) | BG_SBB(29);
	
	//setup the skills based on their current state
	refreshSkills();
	scriptList[SCR_SKILL_TREE].scriptInit();
}
	
void openSkillTreeRun(){
	
};