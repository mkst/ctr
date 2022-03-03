#include "common.h"

#include <LIBSPU.H>

u32 _SpuSetAnyVoice(s32, s32, s32, s32);

typedef struct {
    u8 pad0[0x1AA];
    s16 CommonCDReverb;
} struct000;

extern struct000 *D_8008C3B4;

void SpuSetCommonCDReverb(long cd_reverb) {
    if (!cd_reverb) {
        D_8008C3B4->CommonCDReverb &= ~SPU_DONT_CARE;
    } else {
        D_8008C3B4->CommonCDReverb |= SPU_DONT_CARE;
    }
}

u32 SpuSetReverbVoice(long on_off, unsigned long voice_bit) {
    return _SpuSetAnyVoice(on_off, voice_bit, 204, 205);
}

// nops here suggest file split
