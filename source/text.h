#include "tonc.h"
#include "video.h"

//enums
enum TextFieldMode{
	TEXT_UNUSED,
	TEXT_ACTIVE,
};

enum TextChar{
	A, B, C, D, E, F, G, H,
	I, J, K, L, M, N, O, P,
	Q, R, S, T, U, V, W, X,
	Y, Z, ZERO, ONE, TWO, 
	THREE, FOUR, FIVE, SIX,
	SEVEN, EIGHT, NINE, MINUS,
	PERIOD, QUESTION, EXCLAMATION,
	COMMA, APOSTRAPHE, COLON,
	UNDERSCORE, GREATER, LESS,
	OPEN_PAREN, CLOSE_PAREN, 
	AMPERSAND, PLUS, FORWARD_SLASH,
	BACK_SLASH, PERCENT, SPACE,
};

//structs
typedef struct TextField{
	u8 xPos;
	u8 yPos;
	u8 length;
	enum TextChar *message;
	u8 firstSprite;
	enum TextFieldMode mode;
	u8 palette;
}TextField;

//external data
extern cu32 FontTiles[];

//function declarations
void textInit();
u8 writeText(TextField);
void closeText(u8);
void closeAllText();