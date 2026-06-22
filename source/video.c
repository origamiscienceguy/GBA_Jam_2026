#include "video.h"


void setPalette(Palette palette){
	pal_bg_mem[0] = palette.color1;
	pal_bg_mem[1] = palette.color2;
	pal_bg_mem[16] = palette.color2;
	pal_bg_mem[17] = palette.color1;
	pal_obj_mem[0] = palette.color1;
	pal_obj_mem[1] = palette.color2;
	pal_obj_mem[16] = palette.color2;
	pal_obj_mem[17] = palette.color1;
}

void videoInit(){
	Palette initialPalette = {PalettesBitmap[0], PalettesBitmap[1]};
	setPalette(initialPalette);
	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ;
}