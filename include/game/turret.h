#ifndef GAME_TURRET_H
#define GAME_TURRET_H

#include "game/levels.h"

struct NUTURRETENTRY_s {
    u8 unk0[8];
    char name[0x10];
    struct nuhspecial_s special;
    u8 unk24[0x60 - 0x24];
    f32 unk60;
    f32 unk64;
    f32 unk68;
    s16 unk6C;                   /* fn_801407F8 writes this lookup key */
    u16 flags;
    u16 initialFlags;
    u8 unk72;
    u8 counter;
    u8 initialCounter;
    char unk75[3];
};

struct NUTURRET_s {
    s32 count;
    struct NUTURRETENTRY_s entries[32];
    struct nugscn_s *scene;
};

struct NUTURRETMASK_s {
    u8 unk0[0xD8];
    u32 turretMask;
};

#endif
