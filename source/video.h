#include "tonc.h"

//enum
enum Colors{
	BLACK,
	PURPLE,
	RED,
	GREEN,
	BLUE,
};

enum VramSegmentMode{
	VRAM_UNUSED,
	VRAM_ACTIVE,
};

enum AnimMode{
	ANIM_END,
	ANIM_LOOP,
};

enum AnimManagerMode{
	ANIMMANAGER_UNUSED,
	ANIMMANAGER_ACTIVE,
};

enum GraphicsEnum{
	GFX_BLACK_MAGIC_1,
	GFX_BLACK_MAGIC_2,
	GFX_BLOOD_BLADE_1,
	GFX_BLOOD_BLADE_2,
	GFX_CRANBERRY_1,
	GFX_CRANBERRY_2,
	GFX_FOCUS_1,
	GFX_FOCUS_2,
	GFX_GUARD_1,
	GFX_GUARD_2,
	GFX_ICE_CREAM_1,
	GFX_ICE_CREAM_2,
	GFX_MEAT_1,
	GFX_MEAT_2,
	GFX_MEDITATE_1,
	GFX_MEDITATE_2,
	GFX_PARRY_1,
	GFX_PARRY_2,
	GFX_REFRESH_1,
	GFX_REFRESH_2,
	GFX_SLASH_1,
	GFX_SLASH_2,
	GFX_SUMMON_BLADE_1,
	GFX_SUMMON_BLADE_2,
	GFX_TRIPLE_SLASH_1,
	GFX_TRIPLE_SLASH_2,
	GFX_TWIN_SLASH_1,
	GFX_TWIN_SLASH_2,
	GFX_BLACK_OCTAGON,
	GFX_BLANK,
	GFX_TEMPLAR,
};

enum AnimationEnum{
	ANIM_SLASH,
};

//structs
typedef struct Palette{
	u16 color1;
	u16 color2;
}Palette;

typedef struct VramSegment{
	void *destinationPtr;
	void *sourcePtr;
	u32 numWords;
	enum VramSegmentMode mode;
}VramSegment;

typedef const struct Graphic{
	cu32 *data;
	cu32 numWords;
	cu8 width;
	cu8 height;
	cu8 defaultPalette;
	cu8 shape;
	cu8 size;
}Graphic;

typedef const struct Animation{
	cu32 numFrames;
	cu32 *gfxFrame;
	cu32 *gfx;
	cu32 *posFrame;
	cu32 *xPos;
	cu32 *yPos;
	Graphic *graphics;
	enum AnimMode mode;
	u32 endDetail;
}Animation;

typedef struct AnimationEntry{
	Animation *animation;
	u32 counter;
	u32 posCounter;
	u32 gfxCounter;
	u32 startXPos;
	u32 startYPos;
	u32 xPos;
	u32 yPos;
	u32 startingTile;
	u32 oamEntry;
	enum AnimManagerMode mode;
}AnimationEntry;

//external Data
extern const unsigned short PalettesBitmap[];
extern OBJ_ATTR spriteBuffer[];
extern Graphic graphicsList[];
extern Animation *animationList[];

//function declarations
void setPalette(Palette);
void videoInit();
void vblankUpdate();
void vramAddUpdate(void *, void *, u32);
u8 playAnimation(u32, u32, u32);
void animationManager();