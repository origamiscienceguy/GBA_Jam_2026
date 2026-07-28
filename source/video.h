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
	GFX_EMPTY,
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
	GFX_WALL_BACKGROUND,
	GFX_WALL_BACKGROUND_MAP,
	GFX_WITCH,
	GFX_HEALTHBAR_BACKING,
	GFX_HEALTHBAR_FRONT,
	GFX_INTENTS,
	GFX_PLAYER_TURN,
	GFX_WITCH_TURN,
};

enum AnimationEnum{
	ANIM_TEMPLAR_IDLE,
	ANIM_TEMPLAR_HURT,
	ANIM_TEMPLAR_DEAD,
	ANIM_TEMPLAR_TWIN_SLASH,
	ANIM_TEMPLAR_TRIPLE_SLASH,
	ANIM_TEMPLAR_SUMMON_BLADE,
	ANIM_TEMPLAR_SLASH,
	ANIM_TEMPLAR_REFRESH,
	ANIM_TEMPLAR_PARRY,
	ANIM_TEMPLAR_MEDITATE,
	ANIM_TEMPLAR_MEAT,
	ANIM_TEMPLAR_ICE_CREAM,
	ANIM_TEMPLAR_GUARD,
	ANIM_TEMPLAR_FOCUS,
	ANIM_TEMPLAR_CRANBERRY,
	ANIM_TEMPLAR_BLOOD_BLADE,
	ANIM_TEMPLAR_BLACK_MAGIC,
	ANIM_WITCH_IDLE,
	ANIM_WITCH_HURT,
	ANIM_WITCH_DEAD,
	ANIM_WITCH_MISSILE,
	ANIM_WITCH_HEX,
	ANIM_WITCH_DRAIN,
	ANIM_WITCH_CHARGE,
	ANIM_WITCH_BLOOD_MISSILE,
	ANIM_WITCH_BLAST,
	ANIM_HEALTH_BAR_BACK,
	ANIM_HEALTH_BAR_16,
	ANIM_HEALTH_BAR_15,
	ANIM_HEALTH_BAR_14,
	ANIM_HEALTH_BAR_13,
	ANIM_HEALTH_BAR_12,
	ANIM_HEALTH_BAR_11,
	ANIM_HEALTH_BAR_10,
	ANIM_HEALTH_BAR_9,
	ANIM_HEALTH_BAR_8,
	ANIM_HEALTH_BAR_7,
	ANIM_HEALTH_BAR_6,
	ANIM_HEALTH_BAR_5,
	ANIM_HEALTH_BAR_4,
	ANIM_HEALTH_BAR_3,
	ANIM_HEALTH_BAR_2,
	ANIM_HEALTH_BAR_1,
	ANIM_HEALTH_BAR_0,
	ANIM_PLAYER_TURN,
	ANIM_WITCH_TURN,
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
extern u16 ActionPalettetilemapBuffer[];

//function declarations
void setPalette(Palette);
void videoInit();
void vblankUpdate();
void vramAddUpdate(void *, void *, u32);
u8 playAnimation(u32, u32, u32);
void endAnimation(u8);
void animationManager();
extern void drawActionPalette();
void changeAnimation(u8, u32, u32, u32);
void templarHealthUpdate(u32, u32, u8);
void witchHealthUpdate(u32, u32, u8);
void templarHealthInterpolate(u32, u32, u32, u8);
void witchHealthInterpolate(u32, u32, u32, u8);
void templarDamageScript(u32);
u8 witchDamageScript(s32);
void templarLevelUpdate(u8);
void witchLevelUpdate(u8);
void intentUpdate(u8);