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
	SCR_MAIN_MENU,
	SCR_SETTINGS,
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

//function declarations
void initialize();
void handleInputs();
void interruptInit();
void debug();