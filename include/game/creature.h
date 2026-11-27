#ifndef GAME_CREATURE_H
#define GAME_CREATURE_H

#include "game/character.h"

struct NUGAMEOBJECT_s {
    char unk0[0x60];
    void* characterModel;
    struct NUCHARACTERDATA_s* characterData;
    char unk68[4];
    f32 position[3];
    char unk78[0x190];
    u32 motionFlags;
    u32 flags20C;
    char unk210[0x7C];
    u8 drawResult;
    char unk28D[2];
    u8 unk28F;
    u8 drawUpdated;
    u8 maskIndex;
    char unk292[0xC5A];
    void* playerPacket;
    char unkEF0[0x38];
    u32 flagsF28;
    char unkF2C[0x110];
    f32 unk103C;
    char unk1040[0x20];
    u32 drawFlags;
    char unk1064[0x1C];
    u8 drawMatrixEnabled;
    char unk1081[0x17];
};

#endif
