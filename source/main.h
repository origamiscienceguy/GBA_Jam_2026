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

enum Scripts{
	SCR_BATTLE,
	SCR_BATTLE_START,
	SCR_SLASH,
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
	u8 previousHealth;
	u8 templarHealthMessageID;
	u8 witchHealthMessageID;
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