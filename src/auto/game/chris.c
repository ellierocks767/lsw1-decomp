#include "types.h"
#include "game/levels.h"
#include "numath/nuvec.h"
#include "numath/nuvec_ps.h"

struct fn_80140918_s {
    s32 x;
    s32 y;
    s32 z;
};
extern struct fn_80140918_s lbl_801E1774[];

void fn_80140918(struct fn_80140918_s* a)
{
    lbl_801E1774[0] = *a;
}

s32 fn_800D875C(s32, s32);
s32 fn_800D99AC();
extern f32 lbl_801AF204[];
extern f32 lbl_801AF208[];
extern f32 lbl_80408E9C;
extern f32 lbl_80409578;
extern s32 lbl_80409AC0;
extern f32 lbl_8040A794;

void fn_80141DEC(void) {
    if ((s32) lbl_80409AC0 != -1) {
        if (lbl_8040A794 > lbl_801AF204[0]) {
            lbl_8040A794 -= lbl_80408E9C;
            return;
        }
        if ((lbl_80409578 == lbl_801AF208[0]) && (fn_800D99AC() == -1)) {
            fn_800D875C(lbl_80409AC0, 0);
        }
    }
}

s32 fn_80140E78(void *);

void fn_801410F4(void *arg0) {
    s32 var_r30;
    void *var_r31;

    var_r30 = 0;
    if (arg0 != NULL) {
        var_r31 = (*(void **)((s8 *)(arg0) + (0xC)));
        if (var_r30 < (s32) (*(u16 *)((s8 *)(arg0) + (2)))) {
            do {
                if (var_r31 != NULL) {
                    fn_80140E78(var_r31);
                    var_r31 = (*(void **)((s8 *)(var_r31) + (0x78)));
                }
                var_r30 += 1;
            } while (var_r30 < (s32) (*(u16 *)((s8 *)(arg0) + (2))));
        }
    }
}

void fn_801433C0(void *records, s32 count)
{
    s32 remaining;
    u8 *cursor;

    /* Retail walks the 0x50-byte records with its cursor at offset 0x20. */
    remaining = count;
    if (count > 0) {
        cursor = (u8 *)records + 0x20;
        do {
            *(s16 *)(cursor + 0x22) = 0;
            *(f32 *)(cursor - 0x20) = 80.0f;
            *(f32 *)(cursor - 0x1C) = 55.0f;
            *(f32 *)(cursor - 0x18) = 200.0f;
            *(f32 *)(cursor - 0x14) = 1.0f;
            *(f32 *)(cursor + 0x10) = 0.0f;
            *(f32 *)(cursor + 0x14) = 0.0f;
            *(f32 *)(cursor + 0x18) = 0.0f;
            *(f32 *)(cursor + 0x1C) = 0.0f;
            *(f32 *)(cursor - 0x10) = 0.0f;
            *(f32 *)(cursor - 0xC) = 0.0f;
            *(f32 *)(cursor - 4) = 0.0f;
            *(f32 *)cursor = 0.0f;
            *(f32 *)(cursor + 4) = 0.0f;
            (*(f32 *)((s8 *)(cursor) + (8))) = 0.0f;
            *(f32 *)(cursor + 0xC) = 0.0f;
            (*(f32 *)((s8 *)(cursor) + (-8))) = 200.0f;
            *(s32 *)(cursor + 0x28) = 0xFFFFFF;
            *(s16 *)(cursor + 0x20) = 0;
            *(f32 *)(cursor + 0x2C) = 5.0f;
            cursor += 0x50;
            remaining -= 1;
        } while (remaining != 0);
    }
}

struct CHRISBUFFER_s {
    void *entries;
    s32 capacity;
    s32 count;
};

struct CHRISLEVELDATA_s {
    u8 pad00000[0x636D0];
    struct CHRISBUFFER_s buffer;
    u8 pad636DC[0x44];
    f32 upperBound;
    f32 lowerBound;
    f32 field63728;
    f32 target;
    f32 current;
};


struct CHRIS43468_s {
    f32 field00[4];
    void *field10;
    s32 field14;
    s32 field18;
    s32 field1C;
    u8 pad20[0xC];
    struct CHRISLEVELDATA_s *data;
};

extern u8 lbl_801E17C0[];
extern f32 lbl_802E9B40[4];

void *memset(void *dest, int ch, unsigned int count);

void fn_80143468(struct CHRIS43468_s *state, struct CHRISLEVELDATA_s *data)
{
    struct CHRISBUFFER_s *buffer;
    s32 capacity;

    if (lbl_80409410->unk198 == 0x56) {
        lbl_802E9B40[0] = 4.0f;
        lbl_802E9B40[1] = 4.0f;
        lbl_802E9B40[2] = 4.0f;
        lbl_802E9B40[3] = 1.0f;
        state->field00[0] = -141.0f;
        state->field00[1] = -121.0f;
        state->field00[2] = -1034.0f;
        state->field00[3] = 1.0f;
        state->field10 = NULL;
    } else {
        lbl_802E9B40[0] = 4.0f;
        lbl_802E9B40[1] = 4.0f;
        lbl_802E9B40[2] = 4.0f;
        lbl_802E9B40[3] = 1.0f;
        state->field00[0] = -141.0f;
        state->field00[1] = -121.0f;
        state->field00[2] = -1034.0f;
        state->field00[3] = 1.0f;
        state->field10 = lbl_801E17C0;
    }
    buffer = &data->buffer;
    if (buffer != NULL) {
        capacity = buffer->capacity;
        if (capacity != 0) {
            memset(buffer->entries, 0, capacity * 0x60);
            buffer->count = 0;
        }
    }
    state->field14 = 0;
    state->field1C = 4;
    state->field18 = 0;
    state->data = data;
    data->target = 1.0f;
    data->current = 1.0f;
}

struct MINIKITMESSAGE_s {
    u8 pad00[0x7E];
    s16 field7E;
    s16 field80;
};

f32 NuFmod(f32 dividend, f32 divisor);
extern f32 lbl_803E8394[];

void GameMsgUpdate_MiniKit(struct MINIKITMESSAGE_s *message)
{
    s32 phase;

    phase = (s32)(NuFmod(lbl_803E8394[0], 4.0f) * 0.25f * 65536.0f);
    message->field80 = phase;
    message->field7E = (s16)(NuSinApprox((phase & 0xFFFF) * 2) * 1820.0f);
}

struct CHRISLEVELENTRY_s {
    u8 pad00[0x6C];
    f32 field6C;
};

struct CHRISVALUE_s {
    f32 threshold;
    f32 value;
};

extern f32 lbl_80409B70;

void fn_80145F18(struct lbl_80409410_s *level, const struct CHRISVALUE_s *entry)
{
    f32 threshold = entry->threshold;
    struct CHRISLEVELDATA_s *data = level->unk1984;
    f32 target, current, value;

    if (threshold != 0.0f) {
        do {
            if (data->lowerBound < threshold && data->upperBound >= threshold) {
                data->target = entry->value;
            }
            threshold = (++entry)->threshold;
        } while (threshold != 0.0f);
    }
    target = data->target;
    current = data->current;
    if (target > current) {
        f32 next = (lbl_80408E9C * lbl_80409B70) + current;
        data->current = next;
        if (next > target) {
            data->current = target;
        }
    } else if (target < current) {
        f32 next = current - lbl_80408E9C * lbl_80409B70;
        data->current = next;
        if (next < target) {
            data->current = target;
        }
    }
    level->unk2DC[0]->field6C = data->current * 20.0f;
    if (level->unk198 == 0x56) {
        value = level->unk2DC[0]->field6C;
        if (value != 0.0f) {
            data->field63728 = value / 11.0f;
        }
    }
}

struct CHRISFIGHTER_s {
    u8 pad000[0x110];
    s32 enabled;
    u8 pad114[0x1C];
};

struct CHRISWING_s {
    u8 pad000[0x30];
    struct nuvec_s position;
    u8 pad03C[4];
    struct CHRISFIGHTER_s fighters[5];
    struct nuvec_s velocity;
    f32 field63C;
    struct nuvec_s localPosition;
    u8 pad64C[4];
    struct nuvec_s nextPosition;
    u8 pad65C[0xC];
    s32 enabled;
    s32 mode;
    u8 pad670[4];
    s32 field674;
    f32 remainingTime;
    f32 speed;
};

s32 ProcessStarFighter(struct CHRISFIGHTER_s *fighter, struct CHRISBUFFER_s *buffer);
extern struct numtx_s lbl_803E0158;
extern struct nuvec_s lbl_803E0188;

void ProcessWing(struct CHRISWING_s *wing, struct CHRISBUFFER_s *buffer)
{
    struct nuvec_s step;
    struct CHRISFIGHTER_s *fighter;
    s32 mode, count;
    u32 enabledAddress;
    s32 result = 0;

    if (wing->enabled == 0) {
        return;
    }

    mode = wing->mode;
    if (mode <= 1) {
        if (mode >= 0) {
            struct nuvec_s *velocity = &wing->velocity;
            struct nuvec_s *position = &wing->position;
            struct nuvec_s *stepVec;
            f32 time, localZ;

            if (mode == 0) {
                NuVecSub(velocity, &lbl_803E0188, position);
                wing->field63C = 1.0f;
                NuVecNorm(velocity, velocity);
                NuVecScale(velocity, velocity, wing->speed);
            }
            stepVec = &step;
            NuVecScale(stepVec, velocity, lbl_80408E9C);
            NuVecAddPS(position, position, stepVec);
            NuVecInvMtxTransform(&wing->localPosition, position, &lbl_803E0158);
            time = wing->remainingTime - lbl_80408E9C;
            wing->remainingTime = time;
            if (time < 0.0f ||
                (((localZ = wing->localPosition.z) > 800.0f) && wing->mode == 1) ||
                (localZ < 0.0f && wing->mode == 0)) {
                wing->enabled = 0;
            }
        }
    }

    fighter = wing->fighters;
    /* The enabled-field cursor advances independently of the fighter argument. */
    enabledAddress = (u32)&fighter->enabled;
    count = sizeof(wing->fighters) / sizeof(*fighter);
    do {
        s32 enabled = *(s32 *)enabledAddress;

        enabledAddress += sizeof(*fighter);
        if (enabled != 0) {
            result |= ProcessStarFighter(fighter, buffer);
        }
        fighter++;
        count--;
    } while (count != 0);
    if (result == 0) {
        wing->field674 = 1;
    }
    if (wing->field674 != 0) {
        struct nuvec_s *stepVec = &step;

        NuVecScale(stepVec, &wing->velocity, lbl_80408E9C);
        NuVecAddPS(&wing->nextPosition, &wing->position, stepVec);
    }
}
