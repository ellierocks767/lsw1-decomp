#ifndef GAME_TURRET_H
#define GAME_TURRET_H

#include "types.h"

struct NUTURRETENTRY_s {
    u8 unk0[8];
    char name[0x10];
    u8 unk18[0x6E - 0x18];
    u16 flags;
    u16 initialFlags;
    char unk72;
    u8 counter;
    u8 initialCounter;
    char unk75[3];
};

struct NUTURRET_s {
    s32 count;
    struct NUTURRETENTRY_s entries[32];
    u32 valueF04;
};

struct NUTURRETMASK_s {
    u8 unk0[0xD8];
    u32 turretMask;
};

#endif
