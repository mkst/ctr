#include "common.h"

// typedef struct {
//     u8 pad[0x8A0];
//     s32 unk8A0;
//     s32 unk8A4;
//     s32 unk8A8;
// } GlobalState;


INCLUDE_ASM(s32, "1DAB0", func_8002D2B0);

INCLUDE_ASM(s32, "1DAB0", func_8002D2F4);

INCLUDE_ASM(s32, "1DAB0", func_8002D4CC);

INCLUDE_ASM(s32, "1DAB0", func_8002D50C);

INCLUDE_ASM(s32, "1DAB0", func_8002D554);

INCLUDE_ASM(s32, "1DAB0", func_8002D67C);

INCLUDE_ASM(s32, "1DAB0", func_8002DC4C);

extern u8 D_8008D05C;
extern u8 D_8008D070[];
extern u8 D_80083914[];
void func_80028BBC(u8);

INCLUDE_ASM(s32, "1DAB0", func_8002DCAC);
// CURRENT (250)
// void func_8002DCAC(s32 arg0, s32 arg1, s32 arg2) {
//     u8 phi_a0;
//     if (D_8008D05C != 0) {
//         if (arg1 != 0) {
//             if (arg2 < 6) {
//                 phi_a0 = D_8008D070[arg2];
//                 goto call_func;
//             }
//         } else {
//             if (arg0 < 30) {
//                 phi_a0 = D_80083914[arg0];
//             } else {
//                 phi_a0 = 4U;
//             }
// call_func:
//             func_80028BBC(phi_a0);
//         }
//     }
// }

INCLUDE_ASM(s32, "1DAB0", func_8002DD24);

INCLUDE_ASM(s32, "1DAB0", func_8002DD74);

INCLUDE_ASM(s32, "1DAB0", func_8002DE48);

INCLUDE_ASM(s32, "1DAB0", func_8002E338);
// void func_8002E338(void) {
//     gp->unk8A0 = 0;
//     gp->unk8A4 = -1;
//     gp->unk8A8 = 0;
// }
