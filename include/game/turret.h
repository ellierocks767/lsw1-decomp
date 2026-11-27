#ifndef GAME_TURRET_H
#define GAME_TURRET_H

#include "types.h"

struct NUTURRET_s {
    char unk0[0xF04];
    u32 valueF04;
};

struct NUTURRETENTRY_s {
    char unk0[0x6E];
    u16 flags;
    u16 initialFlags;
    char unk72;
    u8 counter;
    u8 initialCounter;
    char unk75[3];
};

struct NUTURRETLIST_s {
    s32 count;
    struct NUTURRETENTRY_s entries[1];
};

struct NUTURRETMASK_s {
    u8 unk0[0xD8];
    u32 turretMask;
};

#endif
