#include "common.h"

INCLUDE_ASM("asm/bootloader/nonmatchings/67000", SpuSetCommonCDReverb);

// INCLUDE_ASM("asm/bootloader/nonmatchings/67000", func_80076840);
void SpuSetReverbVoice(s32 arg0, s32 arg1) {
    _SpuSetAnyVoice(arg0, arg1, 204, 205);
}

// nops here suggest file split
