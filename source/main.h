#include "tonc.h"
#include "audio.h"


//enums

//struct declarations
typedef struct Inputs{
	u16 lastFrame;
	u16 currentFrame;
	u16 pressed;
	u16 held;
	u16 released;
}Inputs;



//external data

//function declarations
void initialize();
void handleInputs();