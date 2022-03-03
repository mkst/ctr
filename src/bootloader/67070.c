#include "common.h"

#include <LIBSPU.H>

void _SpuInit(int);

void SpuInit(void) {
    _SpuInit(0);
}

// TODO: is this really SpuSetVoiceVolume?
INCLUDE_ASM("asm/bootloader/nonmatchings/67070", SpuSetVoiceVolume);
