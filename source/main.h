#include "tonc.h"
#include "music_list.h"
#include "sfx_list.h"

//function declarations
void initialize();
void handleInputs();
void playSong(u8);
void endSong();
void playSFX(u8);
void endSFX();

//struct declarations
typedef struct Inputs{
	u16 lastFrame;
	u16 currentFrame;
	u16 pressed;
	u16 held;
	u16 released;
}Inputs;


//external data