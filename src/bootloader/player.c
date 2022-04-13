#include "common.h"

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Steer_ReturnToRest);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Steer_AnalogStrength);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Steer_AbsoluteStrength);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Driving_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Driving_Audio);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Driving_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Driving_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Freeze_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Freeze_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_State9_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_State9_ReverseOneFrame);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_State9_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_Finalize);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_InitSetUpdate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Drifting_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Crashing_Interpolate);

void Player_Crashing_Update(void) {
}

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Crashing_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Crashing_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Crashing_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Spinning_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Spinning_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Spinning_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Spinning_InitSetUpdate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Spinning_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_LastSpin_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_LastSpin_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_LastSpin_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_LastSpin_Init);

void Player_EndSpinning_Update(void) {
}

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EndSpinning_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EndSpinning_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EndSpinning_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EndSpinning_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_ChangeState);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Driver_boolGoodGuy);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", FireWeapon_Mask);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Missile_GetTargetDriver);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", ThrowMineWeapon);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", FireWeapon);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_FireWeapon_CirclePress);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_FindDestPos);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_Particles);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskGrab_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskRespawn_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskRespawn_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskRespawn_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_MaskRespawn_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Null_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EngineRevving_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EngineRevving_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EngineRevving_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_EngineRevving_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Blasted_Update);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Blasted_Input);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Blasted_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Blasted_Animate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Blasted_Init);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Warp_MoveDustPuff);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Warp_AddDustPuff1);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Warp_AddDustPuff2);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Warp_Interpolate);

INCLUDE_ASM("asm/bootloader/nonmatchings/player", Player_Warp_Init);
