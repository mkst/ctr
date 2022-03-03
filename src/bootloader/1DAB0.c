#include "common.h"

// typedef struct {
//     u8 pad[0x8A0];
//     s32 unk8A0;
//     s32 unk8A4;
//     s32 unk8A8;
// } GlobalState;


INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Voiceline_SetDefaults);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_SetState);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_SetState_Safe);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_AdvHub_SwapSong);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_SetMaskSong);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_PerFrame);

INCLUDE_ASM("asm/bootloader/nonmatchings/1DAB0", Audio_SetDefaults);
