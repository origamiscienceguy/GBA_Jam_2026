#include "tonc.h"

//enums
enum SoundMode{
	LOOP,
	CUT,
	SILENT,
};

enum SoundType{
	MUSIC,
	SFX,
};

enum MusicID{
	MAIN_LOOP,
	MENU,
	GAME_OVER,
};

enum SfxID{
	BLACK_MAGIC,
	BUTTON_SELECT_1,
	BUTTON_SELECT_2,
	CRITICAL_HIT,
	DEFEND,
	EXPLOSION,
	HEX,
	LEVEL_UP,
	MISSILE_1,
	MISSILE_2,
	MISSILE_FULL,
	POWER_UP,
	RESTORE,
	SLASH,
};

//structs
typedef const struct Sound{
	cu8 *source;
	cu32 length;
	const enum SoundMode mode;
}Sound;

typedef volatile struct SoundManager{
	vu32 musicSamplesLeft;
	vu32 sfxSamplesLeft;
	vu8 musicPlaying;
	vu8 sfxPlaying;
	vu16 timerResetValue;
	volatile enum SoundMode musicMode;
	volatile enum SoundMode sfxMode;
}SoundManager;

//external data
extern const Sound *sounds[];
extern SoundManager soundManager;

//function declarations
void playSong(u8);
void endSong();
void playSfx(u8);
void endSfx();
void manageTimer();




