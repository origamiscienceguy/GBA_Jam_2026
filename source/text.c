#include "tonc.h"
#include "text.h"

TextField activeTextFields[8];

void textInit(){
	//transfer the font glyphs into sprite VRAM
	memcpy32(tile8_mem_obj[0], FontTiles, 424);
}

u8 writeText(TextField textParams){
	u8 xPos = textParams.xPos;
	u8 objectID = 20;
	for(u32 i = 0; i < textParams.length; i++){
		OBJ_ATTR glyph;
		glyph.attr0 = ATTR0_REG | ATTR0_4BPP | ATTR0_SQUARE | ATTR0_Y(textParams.yPos);
		glyph.attr1 = ATTR1_SIZE_8 | ATTR1_X(xPos);
		glyph.attr2 = ATTR2_ID(textParams.message[i]) | ATTR2_PRIO(0) | ATTR2_PALBANK(0);
		oam_mem[objectID] = glyph;
		xPos += 5;
		objectID++;
	}
	
	return 0;
}

void closeText(u8 textID){

}

void closeAllText(){

};