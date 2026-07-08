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
}GameState;

typedef struct Script{
	void (*scriptInit)(void);
	void (*scriptRun)(void);
}Script;

//external data
extern enum FrameState frameState;
extern GameState gameState;
extern Script scriptList[];

//function declarations
void initialize();
void handleInputs();
void interruptInit();
void debug();