#include "text.h"
TextField activeTextFields[16];
u8 textSpritesUsed = 0;

void textInit(){
	//transfer the font glyphs into sprite VRAM
	vramAddUpdate((void *)tile_mem_obj[0], (void *)FontTiles, 424);
	for(u32 i = 0; i < 16; i++){
		activeTextFields[i].mode = TEXT_UNUSED;
	}
}

u8 writeText(TextField textParams){
	//find earliest open text field
	u32 index = 0;
	for(u32 i = 0; i < 16; i++){
		if(activeTextFields[i].mode == TEXT_UNUSED){
			index = i;
			break;
		}
		else if(i == 15){
			//return error
			return 255;
		}
	}
	
	//copy the arguments into persistent storage
	activeTextFields[index].xPos = textParams.xPos;
	activeTextFields[index].yPos = textParams.yPos;
	activeTextFields[index].length = textParams.length;
	activeTextFields[index].message = textParams.message;
	activeTextFields[index].firstSprite = 0x20 + textSpritesUsed;
	activeTextFields[index].mode = TEXT_ACTIVE;
	
	//write the message to the screen
	u8 xPos = textParams.xPos;
	u8 objectID = activeTextFields[index].firstSprite;
	for(u32 i = 0; i < textParams.length; i++){
		OBJ_ATTR glyph;
		glyph.attr0 = ATTR0_REG | ATTR0_4BPP | ATTR0_SQUARE | ATTR0_Y(textParams.yPos);
		glyph.attr1 = ATTR1_SIZE_8 | ATTR1_X(xPos);
		glyph.attr2 = ATTR2_ID(textParams.message[i]) | ATTR2_PRIO(1) | ATTR2_PALBANK(0);
		spriteBuffer[objectID] = glyph;
		xPos += 5;
		objectID++;
	}
	
	textSpritesUsed += activeTextFields[index].length;
	return index;
}

void closeText(u8 textID){
	//check if this text is active
	if(activeTextFields[textID].mode == TEXT_UNUSED){
		return;
	}
	
	//mark the text field as inactive
	activeTextFields[textID].mode = TEXT_UNUSED;
	
	//shift all text sprites down to fill the gap this message used to fill
	u32 startingIndex = activeTextFields[textID].firstSprite + activeTextFields[textID].length;
	u32 endingIndex = textSpritesUsed + 0x20;
	for(u32 i = startingIndex; i < endingIndex; i++){
		u32 destinationIndex = i - activeTextFields[textID].length;
		u32 sourceIndex = i;
		spriteBuffer[destinationIndex].attr0 = spriteBuffer[sourceIndex].attr0;
		spriteBuffer[destinationIndex].attr1 = spriteBuffer[sourceIndex].attr1;
		spriteBuffer[destinationIndex].attr2 = spriteBuffer[sourceIndex].attr2;
	}
	
	//shift the firstSprite value of every open text field that is greater than the one deleted
	for(u32 i = 0; i < 16; i++){
		if((activeTextFields[i].mode == TEXT_ACTIVE) && (activeTextFields[i].firstSprite > activeTextFields[textID].firstSprite)){
			activeTextFields[i].firstSprite -= activeTextFields[textID].length;
		}
	}
	
	//clear the sprites that were just shifted down
	for(u32 i = textSpritesUsed + 0x20 - activeTextFields[textID].length; i < (textSpritesUsed + 0x20); i++){
		spriteBuffer[i].attr0 = ATTR0_HIDE;
	}
	
	textSpritesUsed -= activeTextFields[textID].length;
}

void closeAllText(){
	for(u32 i = 0; i < 16; i++){
		closeText(i);
	}
};