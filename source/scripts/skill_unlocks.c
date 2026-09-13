#include "main.h"
#define NAME_X 20
#define NAME_Y 110
#define LINE_1_X 20
#define LINE_1_Y 136
#define LINE_2_X 20
#define LINE_2_Y 146
#define COST_X 20
#define COST_Y 120

void attackUpUnlock(u8);
void actionUnlock(u8);
void hpUpUnlock(u8);

enum TextChar attackUpName[] = {D, A, M, A, G, E, SPACE, U, P};
enum TextChar twinSlashName[] = {T, W, I, N, SPACE, S, L, A, S, H};
enum TextChar tripleSlashName[] = {T, R, I, P, L, E, SPACE, S, L, A, S, H};
enum TextChar summonBladeName[] = {S, U, M, M, O, N, SPACE, B, L, A, D, E};
enum TextChar bloodBladeName[] = {B, L, O, O, D, SPACE, B, L, A, D, E};
enum TextChar blackMagicName[] = {B, L, A, C, K, SPACE, M, A, G, I, C};
enum TextChar meatName[] = {M, E, A, T};
enum TextChar cranberryName[] = {C, R, A, N, B, E, R, R, Y};
enum TextChar iceCreamName[] = {I, C, E, SPACE, C, R, E, A, M};
enum TextChar focusName[] = {F, O, C, U, S};
enum TextChar meditateName[] = {M, E, D, I, T, A, T, E};
enum TextChar guardName[] = {G, U, A, R, D};
enum TextChar parryName[] = {P, A, R, R, Y};
enum TextChar refreshName[] = {R, E, F, R, E, S, H};
enum TextChar hpUpName[] = {H, E, A, L, T, H, SPACE, U, P};

enum TextChar attackUpLine1[] = {PLUS, ONE, SPACE, D, A, M, A, G, E};
enum TextChar twinSlashLine1[] = {ONE, ZERO, ZERO, PERCENT, SPACE, X, TWO};
enum TextChar tripleSlashLine1[] = {ONE, ZERO, ZERO, PERCENT, SPACE, X, THREE};
enum TextChar summonBladeLine1[] = {THREE, ZERO, ZERO, PERCENT};
enum TextChar bloodBladeLine1[] = {THREE, ZERO, ZERO, PERCENT};
enum TextChar bloodBladeLine2[] = {H, E, A, L, SPACE, ONE, FIVE, ZERO, PERCENT};
enum TextChar blackMagicLine1[] = {D, E, A, T, H};
enum TextChar meatLine1[] = {H, E, A, L, SPACE, ONE, ZERO};
enum TextChar cranberryLine1[] = {C, R, I, T, I, C, A, L, SPACE, S, T, R, I, K, E};
enum TextChar cranberryLine2[] = {OPEN_PAREN, X, TWO, SPACE, D, A, M, A, G, E, CLOSE_PAREN};
enum TextChar iceCreamLine1[] = {E, X, T, R, A, SPACE, T, U, R, N};
enum TextChar focusLine1[] = {PLUS, FIVE, SPACE, X, P};
enum TextChar meditateLine1[] = {PLUS, EIGHT, SPACE, X, P};
enum TextChar guardLine1[] = {B, E, C, O, M, E, SPACE, I, N, V, I, N, C, I, B, L, E};
enum TextChar parryLine1[] = {R, E, F, L, E, C, T, SPACE, D, A, M, A, G, E};
enum TextChar refreshLine1[] = {R, E, D, U, C, E, SPACE, C, O, O, L, D, O, W, N, S};
enum TextChar refreshLine2[] = {OPEN_PAREN, I, M, M, U, N, E, SPACE, T, O, C, O, O, L, D, O, W, N, SPACE, C, H, A, N, G, E, S, CLOSE_PAREN};
enum TextChar hpUp1Line1[] = {PLUS, FIVE, SPACE, H, E, A, L, T, H};
enum TextChar hpUp2Line1[] = {PLUS, ONE, ZERO, SPACE, H, E, A, L, T, H};
enum TextChar emptyLine2[] = {SPACE};

enum TextChar *skillNameList[] = {
	attackUpName,
	twinSlashName,
	tripleSlashName,
	summonBladeName,
	bloodBladeName,
	blackMagicName,
	meatName,
	cranberryName,
	iceCreamName,
	focusName,
	meditateName,
	guardName,
	parryName,
	refreshName,
	hpUpName,
};

enum TextChar *lineOneList[] = {
	attackUpLine1,
	twinSlashLine1,
	tripleSlashLine1,
	summonBladeLine1,
	bloodBladeLine1,
	blackMagicLine1,
	meatLine1,
	cranberryLine1,
	iceCreamLine1,
	focusLine1,
	meditateLine1,
	guardLine1,
	parryLine1,
	refreshLine1,
	hpUp1Line1,
	hpUp2Line1,
};

enum TextChar *lineTwoList[] = {
	emptyLine2,
	bloodBladeLine2,
	cranberryLine2,
	refreshLine2,
};

void (*unlockFunctions[])(enum Skills) = {
	&attackUpUnlock,
	&actionUnlock,
	&hpUpUnlock,
};

Skill skills[20] = {
{},
	//attack up 1
	{.unlockList = {SKILL_ATTACK_2, SKILL_NONE}, .xPos = 2, .yPos = 2, .cost = 1, .startAvailable = 1,
		.graphicPos = 0, .skillUnlockScript = 0, .nameIndex = 0, .line1Index = 0, .line2Index = 0,
		.upSkill = SKILL_ATTACK_3, .downSkill = SKILL_ATTACK_2, .leftSkill = SKILL_DEFENSE_1, .rightSkill = SKILL_TWIN_SLASH,
		.nameLength = 9, .line1Length = 9, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
	//attack up 2	
	{.unlockList = {SKILL_ATTACK_3, SKILL_NONE}, .xPos = 2, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 0, .skillUnlockScript = 0, .nameIndex = 0, .line1Index = 0, .line2Index = 0,
		.upSkill = SKILL_ATTACK_1, .downSkill = SKILL_ATTACK_3, .leftSkill = SKILL_DEFENSE_2, .rightSkill = SKILL_SUMMON_BLADE,
		.nameLength = 9, .line1Length = 9, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
	//attack up 3	
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 2, .yPos = 10, .cost = 2, .startAvailable = 0, 
		.graphicPos = 1, .skillUnlockScript = 0, .nameIndex = 0, .line1Index = 0, .line2Index = 0,
		.upSkill = SKILL_ATTACK_2, .downSkill = SKILL_ATTACK_1, .leftSkill = SKILL_DEFENSE_3, .rightSkill = SKILL_BLACK_MAGIC,
		.nameLength = 9, .line1Length = 9, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
	//twin slash	
	{.unlockList = {SKILL_SUMMON_BLADE, SKILL_TRIPLE_SLASH}, .xPos = 6, .yPos = 2, .cost = 1, .startAvailable = 1,
		.graphicPos = 2, .skillUnlockScript = 1, .nameIndex = 1, .line1Index = 1, .line2Index = 0,
		.upSkill = SKILL_BLACK_MAGIC, .downSkill = SKILL_SUMMON_BLADE, .leftSkill = SKILL_ATTACK_1, .rightSkill = SKILL_MEAT,
		.nameLength = 10, .line1Length = 7, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_TWIN_SLASH},
	//triple slash
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 10, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 3, .skillUnlockScript = 1, .nameIndex = 2, .line1Index = 2, .line2Index = 0,
		.upSkill = SKILL_BLOOD_BLADE, .downSkill = SKILL_BLOOD_BLADE, .leftSkill = SKILL_SUMMON_BLADE, .rightSkill = SKILL_CRANBERRY,
		.nameLength = 12, .line1Length = 7, .line2Length = 1, .replaces = ACT_TWIN_SLASH, .action = ACT_TRIPLE_SLASH},
	//summon blade
	{.unlockList = {SKILL_BLACK_MAGIC, SKILL_BLOOD_BLADE}, .xPos = 6, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 4, .skillUnlockScript = 1, .nameIndex = 3, .line1Index = 3, .line2Index = 0,
		.upSkill = SKILL_TWIN_SLASH, .downSkill = SKILL_BLACK_MAGIC, .leftSkill = SKILL_ATTACK_2, .rightSkill = SKILL_TRIPLE_SLASH,
		.nameLength = 12, .line1Length = 4, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_SUMMON_BLADE},
	//blood blade	
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 10, .yPos = 10, .cost = 1, .startAvailable = 0, 
		.graphicPos = 5, .skillUnlockScript = 1, .nameIndex = 4, .line1Index = 4, .line2Index = 1,
		.upSkill = SKILL_TRIPLE_SLASH, .downSkill = SKILL_TRIPLE_SLASH, .leftSkill = SKILL_BLACK_MAGIC, .rightSkill = SKILL_ICE_CREAM,
		.nameLength = 11, .line1Length = 4, .line2Length = 9, .replaces = ACT_SUMMON_BLADE, .action = ACT_BLOOD_BLADE},
	//black magic	
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 6, .yPos = 10, .cost = 2, .startAvailable = 0, 
		.graphicPos = 6, .skillUnlockScript = 1, .nameIndex = 5, .line1Index = 5, .line2Index = 0,
		.upSkill = SKILL_SUMMON_BLADE, .downSkill = SKILL_TWIN_SLASH, .leftSkill = SKILL_ATTACK_3, .rightSkill = SKILL_BLOOD_BLADE,
		.nameLength = 11, .line1Length = 5, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_BLACK_MAGIC},
	//meat
	{.unlockList = {SKILL_CRANBERRY, SKILL_NONE}, .xPos = 14, .yPos = 2, .cost = 1, .startAvailable = 1,
		.graphicPos = 7, .skillUnlockScript = 1, .nameIndex = 6, .line1Index = 6, .line2Index = 0,
		.upSkill = SKILL_ICE_CREAM, .downSkill = SKILL_CRANBERRY, .leftSkill = SKILL_TWIN_SLASH, .rightSkill = SKILL_FOCUS,
		.nameLength = 4, .line1Length = 7, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_MEAT},
	//cranberry	
	{.unlockList = {SKILL_ICE_CREAM, SKILL_NONE}, .xPos = 14, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 8, .skillUnlockScript = 1, .nameIndex = 7, .line1Index = 7, .line2Index = 2,
		.upSkill = SKILL_MEAT, .downSkill = SKILL_ICE_CREAM, .leftSkill = SKILL_TRIPLE_SLASH, .rightSkill = SKILL_MEDITATE,
		.nameLength = 9, .line1Length = 15, .line2Length = 11, .replaces = ACT_EMPTY, .action = ACT_CRANBERRY},
	//ice cream	
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 14, .yPos = 10, .cost = 2, .startAvailable = 0, 
		.graphicPos = 9, .skillUnlockScript = 1, .nameIndex = 8, .line1Index = 8, .line2Index = 0,
		.upSkill = SKILL_CRANBERRY, .downSkill = SKILL_MEAT, .leftSkill = SKILL_BLOOD_BLADE, .rightSkill = SKILL_PARRY,
		.nameLength = 9, .line1Length = 10, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_ICE_CREAM},
	//focus
	{.unlockList = {SKILL_MEDITATE, SKILL_GUARD}, .xPos = 22, .yPos = 2, .cost = 1, .startAvailable = 1,
		.graphicPos = 10, .skillUnlockScript = 1, .nameIndex = 9, .line1Index = 9, .line2Index = 0,
		.upSkill = SKILL_REFRESH, .downSkill = SKILL_GUARD, .leftSkill = SKILL_MEAT, .rightSkill = SKILL_DEFENSE_1,
		.nameLength = 5, .line1Length = 5, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_FOCUS},
	//meditate
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 18, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 11, .skillUnlockScript = 1, .nameIndex = 10, .line1Index = 10, .line2Index = 0,
		.upSkill = SKILL_PARRY, .downSkill = SKILL_PARRY, .leftSkill = SKILL_CRANBERRY, .rightSkill = SKILL_GUARD,
		.nameLength = 8, .line1Length = 5, .line2Length = 1, .replaces = ACT_FOCUS, .action = ACT_MEDITATE},
	//guard
	{.unlockList = {SKILL_PARRY, SKILL_REFRESH}, .xPos = 22, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 12, .skillUnlockScript = 1, .nameIndex = 11, .line1Index = 11, .line2Index = 0,
		.upSkill = SKILL_FOCUS, .downSkill = SKILL_REFRESH, .leftSkill = SKILL_MEDITATE, .rightSkill = SKILL_DEFENSE_2,
		.nameLength = 5, .line1Length = 17, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_GUARD},
	//parry
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 18, .yPos = 10, .cost = 1, .startAvailable = 0, 
		.graphicPos = 13, .skillUnlockScript = 1, .nameIndex = 12, .line1Index = 12, .line2Index = 0,
		.upSkill = SKILL_MEDITATE, .downSkill = SKILL_MEDITATE, .leftSkill = SKILL_ICE_CREAM, .rightSkill = SKILL_REFRESH,
		.nameLength = 5, .line1Length = 14, .line2Length = 1, .replaces = ACT_GUARD, .action = ACT_PARRY},
	//refresh
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 22, .yPos = 10, .cost = 2, .startAvailable = 0, 
		.graphicPos = 14, .skillUnlockScript = 1, .nameIndex = 13, .line1Index = 13, .line2Index = 3,
		.upSkill = SKILL_GUARD, .downSkill = SKILL_FOCUS, .leftSkill = SKILL_PARRY, .rightSkill = SKILL_DEFENSE_3,
		.nameLength = 7, .line1Length = 16, .line2Length = 27, .replaces = ACT_EMPTY, .action = ACT_REFRESH},
	//defense 1
	{.unlockList = {SKILL_DEFENSE_2, SKILL_NONE}, .xPos = 26, .yPos = 2, .cost = 1, .startAvailable = 1,
		.graphicPos = 15, .skillUnlockScript = 2, .nameIndex = 14, .line1Index = 14, .line2Index = 0,
		.upSkill = SKILL_DEFENSE_3, .downSkill = SKILL_DEFENSE_2, .leftSkill = SKILL_FOCUS, .rightSkill = SKILL_ATTACK_1,
		.nameLength = 9, .line1Length = 9, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
	//defense 2
	{.unlockList = {SKILL_DEFENSE_3, SKILL_NONE}, .xPos = 26, .yPos = 6, .cost = 1, .startAvailable = 0, 
		.graphicPos = 15, .skillUnlockScript = 2, .nameIndex = 14, .line1Index = 14, .line2Index = 0,
		.upSkill = SKILL_DEFENSE_1, .downSkill = SKILL_DEFENSE_3, .leftSkill = SKILL_GUARD, .rightSkill = SKILL_ATTACK_2,
		.nameLength = 9, .line1Length = 9, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
	//defense 3
	{.unlockList = {SKILL_NONE, SKILL_NONE}, .xPos = 26, .yPos = 10, .cost = 2, .startAvailable = 0, 
		.graphicPos = 16, .skillUnlockScript = 2, .nameIndex = 14, .line1Index = 15, .line2Index = 0,
		.upSkill = SKILL_DEFENSE_2, .downSkill = SKILL_DEFENSE_1, .leftSkill = SKILL_REFRESH, .rightSkill = SKILL_ATTACK_3,
		.nameLength = 9, .line1Length = 10, .line2Length = 1, .replaces = ACT_EMPTY, .action = ACT_EMPTY},
};

void refreshSkills(){
	for(u32 i = 1; i < 20; i++){
		cu32 *graphics = 0;
		u8 xPos = skills[i].xPos;
		u8 yPos = skills[i].yPos;
		switch(gameState.skillStates[i]){
			case SKILL_LOCKED:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 2 * 6;
			break;
			
			case SKILL_AVAILABLE:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 0 * 6;
			break;
			
			case SKILL_PURCHASED:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 1 * 6;
			break;
			
			case SKILL_AVAILABLE_VIEWED:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 1 * 6;
			break;
			
			case SKILL_PURCHASED_VIEWED:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 0 * 6;
			break;
			
			case SKILL_LOCKED_VIEWED:
			graphics = graphicsList[GFX_SKILLS_MAP].data + skills[i].graphicPos * 30 + 3 * 6;
			break;
		}
		se_mem[29][yPos * 32 + xPos] = (u16)(graphics[0] & 0xffff) + 0x1007;
		se_mem[29][yPos * 32 + xPos + 1] = (u16)(graphics[0] >> 16) + 0x1007;
		se_mem[29][(yPos + 1) * 32 + xPos] = (u16)(graphics[1] >> 16) + 0x1007;
		se_mem[29][(yPos + 1) * 32 + xPos + 1] = (u16)(graphics[2] & 0xffff) + 0x1007;
		se_mem[29][(yPos + 1) * 32 + xPos + 2] = (u16)(graphics[2] >> 16) + 0x1007;
		se_mem[29][(yPos + 2) * 32 + xPos + 1] = (u16)(graphics[3] >> 16) + 0x1007;
		se_mem[29][(yPos + 2) * 32 + xPos + 2] = (u16)(graphics[4] & 0xffff) + 0x1007;
	}
	
	if(gameState.skillNameID != 0xff){
		closeText(gameState.skillNameID);
	}
	TextField sampleText = {.xPos = NAME_X, .yPos = NAME_Y, .length = skills[gameState.selectedSkill].nameLength, 
		.message = skillNameList[skills[gameState.selectedSkill].nameIndex],  .palette = 0};
	gameState.skillNameID = writeText(sampleText);
	
	if(gameState.skillLine1ID != 0xff){
		closeText(gameState.skillLine1ID);
	}
	TextField line1Text = {.xPos = LINE_1_X, .yPos = LINE_1_Y, .length = skills[gameState.selectedSkill].line1Length, 
		.message = lineOneList[skills[gameState.selectedSkill].line1Index],  .palette = 0};
	gameState.skillLine1ID = writeText(line1Text);
	
	if(gameState.skillLine2ID != 0xff){
		closeText(gameState.skillLine2ID);
	}
	TextField line2Text = {.xPos = LINE_2_X, .yPos = LINE_2_Y, .length = skills[gameState.selectedSkill].line2Length, 
		.message = lineTwoList[skills[gameState.selectedSkill].line2Index],  .palette = 0};
	gameState.skillLine2ID = writeText(line2Text);
	
	if(gameState.skillCostID != 0xff){
		closeText(gameState.skillCostID);
	}
	if(gameState.skillStates[gameState.selectedSkill] == SKILL_PURCHASED_VIEWED){
		enum TextChar costMessage[] = {P, U, R, C, H, A, S, E, D};
		TextField costText = {.xPos = COST_X, .yPos = COST_Y, .length = 9, .message = costMessage,  .palette = 0};
		gameState.skillCostID = writeText(costText);
	}
	else{
		enum TextChar costMessage[] = {C, O, S, T, COLON, SPACE, ZERO + skills[gameState.selectedSkill].cost};
		TextField costText = {.xPos = COST_X, .yPos = COST_Y, .length = 7, .message = costMessage,  .palette = 0};
		gameState.skillCostID = writeText(costText);
	}


	
	se_mem[29][13 * 32 + 14] = (u16)((graphicsList[GFX_SKILLS_MAP].data + skills[gameState.selectedSkill].graphicPos * 30 + 4 * 6)[0] & 0xffff) + 0x1007;
	se_mem[29][13 * 32 + 15] = (u16)((graphicsList[GFX_SKILLS_MAP].data + skills[gameState.selectedSkill].graphicPos * 30 + 4 * 6)[0] >> 16) + 0x1007;
	se_mem[29][14 * 32 + 14] = (u16)((graphicsList[GFX_SKILLS_MAP].data + skills[gameState.selectedSkill].graphicPos * 30 + 4 * 6)[1] >> 16) + 0x1007;
	se_mem[29][14 * 32 + 15] = (u16)((graphicsList[GFX_SKILLS_MAP].data + skills[gameState.selectedSkill].graphicPos * 30 + 4 * 6)[2] & 0xffff) + 0x1007;
}

void hpUpUnlock(enum Skills skill){
	if(skill == SKILL_DEFENSE_3){
		gameState.templarMaxHealth += 10;
		gameState.templarHealth += 10;
	}
	else{
		gameState.templarMaxHealth += 5;
		gameState.templarHealth += 5;
	}
}

void attackUpUnlock(enum Skills skill){
	//just to get rid of "unused parameter" warnings
	if(skill != 0){
		gameState.templarDamage += 1;
	}
}

void actionUnlock(enum Skills skill){
	u8 slot = 1;
	if(skills[skill].replaces == ACT_EMPTY){
		slot = gameState.numAvailableActions;
		gameState.numAvailableActions++;
	}
	else{
		for(u32 i = 0; i < 10; i++){
			if(gameState.actionPalette[i] == skills[skill].replaces){
				slot = i;
				break;
			}
		}
	}
	gameState.actionPalette[slot] = skills[skill].action;
}