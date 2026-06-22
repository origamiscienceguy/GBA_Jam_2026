#include "tonc.h"

//enum
enum Colors{
	BLACK,
	PURPLE,
	RED,
	GREEN,
	BLUE,
};

//structs
typedef struct Palette{
	u16 color1;
	u16 color2;
}Palette;

//external Data
extern const unsigned short PalettesBitmap[];

//function declarations
void setPalette(Palette);
void videoInit();