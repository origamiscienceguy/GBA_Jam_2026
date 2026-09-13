#include "tonc.h"
#include "audio.h"
#include "interrupt.h"
#include "text.h"



//enums
enum FrameState{
	WORKING,
	WAITING_FOR_VBLANK,
	NEW_FRAME_START,
};

enum Actions{
	ACT_EMPTY,
	ACT_SLASH,
	ACT_TWIN_SLASH,
	ACT_TRIPLE_SLASH,
	ACT_SUMMON_BLADE,
	ACT_BLOOD_BLADE,
	ACT_BLACK_MAGIC,
	ACT_MEAT,
	ACT_CRANBERRY,
	ACT_ICE_CREAM,
	ACT_FOCUS,
	ACT_MEDITATE,
	ACT_GUARD,
	ACT_PARRY,
	ACT_REFRESH,
};

enum Intents{
	INTENT_ATTACK,
	INTENT_DEBUFF,
	INTENT_CHARGE,
};

enum Phase{
	PHASE_BASIC,
	PHASE_VAMPIRE,
	PHASE_BLOOD,
	PHASE_EXPLOSIVE,
	PHASE_CURSE,
};

enum SkillState{
	SKILL_LOCKED,
	SKILL_AVAILABLE,
	SKILL_PURCHASED,
	SKILL_AVAILABLE_VIEWED,
	SKILL_LOCKED_VIEWED,
	SKILL_PURCHASED_VIEWED
};

enum Skills{
	SKILL_NONE,
	SKILL_ATTACK_1,
	SKILL_ATTACK_2,
	SKILL_ATTACK_3,
	SKILL_TWIN_SLASH,
	SKILL_TRIPLE_SLASH,
	SKILL_SUMMON_BLADE,
	SKILL_BLOOD_BLADE,
	SKILL_BLACK_MAGIC,
	SKILL_MEAT,
	SKILL_CRANBERRY,
	SKILL_ICE_CREAM,
	SKILL_FOCUS,
	SKILL_MEDITATE,
	SKILL_GUARD,
	SKILL_PARRY,
	SKILL_REFRESH,
	SKILL_DEFENSE_1,
	SKILL_DEFENSE_2,
	SKILL_DEFENSE_3,
};

enum Scripts{
	SCR_PLAYER_TURN,
	SCR_WITCH_TURN,
	SCR_BATTLE_START,
	SCR_BATTLE_MANAGER,
	SCR_SLASH,
	SCR_BLACK_MAGIC,
	SCR_MEAT,
	SCR_CRANBERRY,
	SCR_ICE_CREAM,
	SCR_GUARD,
	SCR_PARRY,
	SCR_REFRESH,
	SCR_FOCUS,
	SCR_MEDITATE,
	SCR_BLOOD_BLADE,
	SCR_SUMMON_BLADE,
	SCR_TWIN_SLASH,
	SCR_TRIPLE_SLASH,
	SCR_HEX,
	SCR_CHARGE,
	SCR_EXPLOSION,
	SCR_VAMPIRE,
	SCR_MISSILE,
	SCR_BLOOD,
	SCR_OPEN_SKILL_TREE,
	SCR_SKILL_TREE,
	SCR_CLOSE_SKILL_TREE,
	SCR_GAME_OVER,
	SCR_MAIN_MENU,
};

//struct declarations
typedef struct Inputs{
	u16 lastFrame;
	u16 currentFrame;
	u16 pressed;
	u16 held;
	u16 released;
}Inputs;


typedef struct GameState{
	enum Scripts currentScript;
	enum Actions actionPalette[10];
	u8 actionCooldown[10];
	u8 cooldownTextID[10];
	enum SkillState skillStates[20];
	enum Phase witchPhase;
	u8 witchPhaseParity;
	u8 witchPhaseLevel;
	u8 actionPosition[14];
	u8 selectedAction;
	u8 savedSelectedAction;
	u8 numAvailableActions;
	u8 templarAnimationID;
	u8 witchAnimationID;
	u8 templarHealthBackID;
	u8 witchHealthBackID;
	u8 templarHealthFrontID;
	u8 witchHealthFrontID;
	u8 scriptCounter;
	u8 witchHealth;
	u8 witchMaxHealth;
	u8 templarHealth;
	u8 templarMaxHealth;
	u8 templarDamage;
	u8 witchDamage;
	u8 previousHealth;
	u8 templarHealthMessageID;
	u8 witchHealthMessageID;
	u8 templarLevelMessageID;
	u8 witchLevelMessageID;
	u8 templarLevel;
	u8 witchLevel;
	u8 intentMessageID;
	u8 templarTurnID;
	u8 witchTurnID;
	u8 currentTurn;
	u8 itemThrowID;
	u8 criticalHit;
	u8 templarBonusID;
	u8 defendStatus;
	u8 templarExp;
	u8 templarNeededExp;
	u8 witchAttackID;
	u8 deathblow1ID;
	u8 deathblow2ID;
	u8 deathblow3ID;
	u8 activeDeathblows;
	u8 templarLevelUpCounter;
	u8 templarLevelSfxDelay;
	u8 templarLevelUpsAvailable;
	u8 levelUpsTextID;
	u8 expAmountTextID;
	u8 selectedSkill;
	u8 skillNameID;
	u8 skillLine1ID;
	u8 skillLine2ID;
	u8 skillCostID;
	u16 totalDamage;
}GameState;

typedef struct Script{
	void (*scriptInit)(void);
	void (*scriptRun)(void);
}Script;

typedef const struct Action{
	const enum GraphicsEnum unselectedGraphic;
	const enum GraphicsEnum selectedGraphic;
	const enum GraphicsEnum cooldownGraphic;
	const Script *selectedScript;
	u8 cooldown;
}Action;

typedef const struct Skill{
	const enum Skills unlockList[2];
	cu8 xPos;
	cu8 yPos;
	cu8 cost;
	cu8 startAvailable;
	cu8 graphicPos;
	cu8 skillUnlockScript;
	cu8 nameIndex;
	cu8 line1Index;
	cu8 line2Index;
	const enum Skills upSkill;
	const enum Skills downSkill;
	const enum Skills leftSkill;
	const enum Skills rightSkill;
	cu8 nameLength;
	cu8 line1Length;
	cu8 line2Length;
	const enum Actions replaces;
	const enum Actions action;
}Skill;

typedef const struct WitchAction{
	const Script *parity0Script;
	const Script *parity1Script;
}WitchAction;

//external data
extern enum FrameState frameState;
extern GameState gameState;
extern Script scriptList[];
extern Inputs inputs;
extern Action actions[];
extern Skill skills[];
extern void (*unlockFunctions[])(u8);

//function declarations
void initialize();
void handleInputs();
void interruptInit();
void debug();