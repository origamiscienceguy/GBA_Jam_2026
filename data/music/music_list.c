#include "tonc.h"
#include "music_list.h"

extern cu8 fwf_main_loop[];
extern cu32 fwf_main_loop_length;
extern cu8 fwf_menu[];
extern cu32 fwf_menu_length;
extern cu8 fwf_gameover[];
extern cu32 fwf_gameover_length;

cu8 *musicList[3] = {
	fwf_main_loop,
	fwf_menu,
	fwf_gameover,
};

cu32 *musicListLength[3] = {
	&fwf_main_loop_length,
	&fwf_menu_length,
	&fwf_gameover_length,
};