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

//struct declarations
typedef struct Inputs{
	u16 lastFrame;
	u16 currentFrame;
	u16 pressed;
	u16 held;
	u16 released;
}Inputs;



//external data
extern enum FrameState frameState;

//function declarations
void initialize();
void handleInputs();
void interruptInit();
void debug();