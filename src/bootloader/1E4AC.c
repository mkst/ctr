#include "common.h"

extern u8 D_8008D05C;
extern u8 D_8008D070[];
extern u8 D_80083914[];
s32 SetReverbMode(s32);

INCLUDE_ASM("asm/bootloader/nonmatchings/1E4AC", Audio_SetReverbMode);
// CURRENT (130)
// void Audio_SetReverbMode(s32 arg0, s32 arg1, s32 arg2) {
//     s32 phi_a0;
//     if (D_8008D05C != 0) {
//         if (arg1 != 0) {
//             if (arg2 < 6) {
//                 phi_a0 = D_8008D070[arg2];
//                 SetReverbMode(phi_a0);
//             }
//         } else {
//             if (arg0 < 30) {
//                 phi_a0 = D_80083914[arg0];
//             } else {
//                 phi_a0 = 4U;
//             }
//             SetReverbMode(phi_a0);
//         }
//     }
// }
