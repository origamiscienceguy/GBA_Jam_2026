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
	cu32 *length;
	const enum SoundMode mode;
}Sound;

typedef struct SoundManager{
	u32 musicSamplesLeft;
	u32 sfxSamplesLeft;
	u8 musicPlaying;
	u8 sfxPlaying;
	u16 timerResetValue;
	enum SoundMode musicMode;
	enum SoundMode sfxMode;
}SoundManager;

//external data
extern const Sound *sounds[];
extern SoundManager soundManager;

//function declarations
void playSong(u8);
void endSong();
void playSFX(u8);
void endSFX();
void manageTimer();




