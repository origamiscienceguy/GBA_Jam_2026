#include "tonc.h"
#include "main.h"

int main(){
	initialize();
	while(1);
}

void initialize(){
	REG_SNDSTAT = SSTAT_ENABLE;
	REG_SNDDSCNT = SDS_A100 | SDS_B100 | SDS_AR | SDS_AL | SDS_ATMR0 | SDS_ARESET | SDS_BR | SDS_BL | SDS_BTMR0 | SDS_BRESET;
	REG_DMA1SAD = (u32) fwf_main_loop;
	REG_DMA1DAD = (u32) 0x040000A0;
	REG_DMA1CNT = DMA_DST_FIXED | DMA_SRC_INC | DMA_REPEAT | DMA_32 | DMA_AT_SPECIAL | DMA_ENABLE;
	REG_TM0D = 0x10000 - 512;
	REG_TM0CNT = TM_FREQ_1 | TM_ENABLE;
}