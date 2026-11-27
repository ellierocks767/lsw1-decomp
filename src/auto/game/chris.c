#include "types.h"
#include "game/levels.h"
#include "game/turret.h"
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
    u32 cursor;

    /* Retail walks the 0x50-byte records with its cursor at offset 0x20. */
    remaining = count;
    if (count > 0) {
        cursor = (u32)records + 0x20;
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
    s32 field63734;
};


struct CHRISACTION_s {
    s32 kind;
    f32 value;
};

struct CHRIS43468_s {
    f32 field00[4];
    struct CHRISACTION_s *actions;
    struct CHRISACTION_s *action;
    s32 nextAction;
    s32 actionKind;
    u8 pad20[4];
    f32 remaining;
    u8 pad28[4];
    struct CHRISLEVELDATA_s *data;
};

extern struct CHRISACTION_s lbl_801E17C0[];
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
        state->actions = NULL;
    } else {
        lbl_802E9B40[0] = 4.0f;
        lbl_802E9B40[1] = 4.0f;
        lbl_802E9B40[2] = 4.0f;
        lbl_802E9B40[3] = 1.0f;
        state->field00[0] = -141.0f;
        state->field00[1] = -121.0f;
        state->field00[2] = -1034.0f;
        state->field00[3] = 1.0f;
        state->actions = lbl_801E17C0;
    }
    buffer = &data->buffer;
    if (buffer != NULL) {
        capacity = buffer->capacity;
        if (capacity != 0) {
            memset(buffer->entries, 0, capacity * 0x60);
            buffer->count = 0;
        }
    }
    state->action = 0;
    state->actionKind = 4;
    state->nextAction = 0;
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
    struct numtx_s transform;
    u8 pad040[0x4C];
    f32 field8C;
    u8 pad090[0x30];
    s32 pitch;
    s32 yaw;
    u8 pad0C8[0x48];
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

void fn_8002A3A8(struct nugscn_s *scene);

void fn_80141D20(struct lbl_80409410_s *level)
{
    struct nugscn_s *scene = level->unk214;

    if (scene != NULL) {
        fn_8002A3A8(scene);
        level->unk214 = NULL;
        level->unk218 = 0;
    }
}

void fn_80141CD8(struct lbl_80409410_s *level)
{
    struct nugscn_s *scene = level->unk208;

    if (scene != NULL) {
        fn_8002A3A8(scene);
        level->unk208 = NULL;
        level->unk20C = 0;
        level->unk210 = 0;
    }
}

struct CHRISSAVEPROGRESS_s {
    u8 pad0[0x10];
    s16 unk10[0x7F];
    u8 pad10E[2];
    struct {
        u8 pad0[2];
        u8 superkit;
        u8 unk3;
        u8 unk4;
        u8 pad5[3];
    } levels[22];
};

extern struct CHRISSAVEPROGRESS_s lbl_803E0298;
extern u8 gSuperkitTotal[];
extern u8 lbl_8040B0FF;

void Progress_SetSuperkitFlags(void)
{
    s32 i;

    for (i = 21; i >= 0; i--) {
        lbl_803E0298.levels[i].superkit = 1;
    }
    gSuperkitTotal[0] = lbl_8040B0FF;
}

s32 NuStrCmp(char *a, char *b);
extern char lbl_801E1780[2][16];

s32 LookupRippleEffectIndex(char *name)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        if (NuStrCmp(lbl_801E1780[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

struct CHRISPROGRESSCONFIG_s {
    u8 pad0[0x33];
    u8 unk33;
    u8 pad34[0x68 - 0x34];
};

extern struct CHRISPROGRESSCONFIG_s lbl_801DC074[];

void DebugMenu_HandleEntry4(void)
{
    s32 i;
    struct CHRISPROGRESSCONFIG_s *config = lbl_801DC074;

    for (i = 0; i < 22; i++) {
        lbl_803E0298.levels[i].unk4 = config->unk33;
        lbl_803E0298.levels[i].unk3 = 1;
        config++;
    }
    for (i = 0x7E; i >= 0; i--) {
        lbl_803E0298.unk10[i] = -1;
    }
}

void fn_8014093C(struct lbl_80409410_s *level)
{
    struct NUTURRET_s *turrets;
    struct NUTURRETENTRY_s *entry;
    struct NUTURRETMASK_s *mask;
    s32 i;

    if (level == NULL)
        return;
    mask = level->unk1B4;
    if (mask == NULL)
        return;
    turrets = level->turrets;
    if (turrets == NULL)
        return;

    mask->turretMask = 0;
    entry = turrets->entries;
    for (i = 0; i < turrets->count; i++, entry++) {
        if (entry->flags & 0x80)
            level->unk1B4->turretMask |= 1u << i;
    }
}

s32 NuStrICmp(char *, char *);

struct NUTURRETENTRY_s *FindTurret(struct NUTURRET_s *turrets, char *name)
{
    struct NUTURRETENTRY_s *entry;
    s32 i;

    if (turrets != NULL) {
        entry = turrets->entries;
        for (i = 0; i < turrets->count; i++, entry++) {
            if (NuStrICmp(name, entry->name) == 0)
                return entry;
        }
    }
    return NULL;
}

struct NUTURRETENTRY_s *fn_801408D4(struct NUTURRET_s *turrets, s32 key)
{
    struct NUTURRETENTRY_s *entry;
    s32 i;

    if (turrets != NULL) {
        entry = turrets->entries;
        for (i = 0; i < turrets->count; i++, entry++) {
            if (entry->unk6C == key)
                return entry;
        }
    }
    return NULL;
}

s32 fn_800135B0(struct nuhspecial_s *);
s32 fn_8005A5F8(s32);

void fn_801407F8(struct NUTURRET_s *turrets)
{
    struct NUTURRETENTRY_s *entry;
    s32 i;

    if (turrets != NULL) {
        entry = turrets->entries;
        for (i = 0; i < turrets->count; i++, entry++)
            entry->unk6C = fn_8005A5F8(fn_800135B0(&entry->special));
    }
}

s32 NuSpecialFind(struct nugscn_s *, struct nuhspecial_s *, char *, s32);

struct NUTURRETENTRY_s *CreateTurret(struct NUTURRET_s *turrets, char *name, u8 value)
{
    struct nuhspecial_s special;
    struct NUTURRETENTRY_s *entry = NULL;

    if (turrets != NULL && turrets->count < 32 &&
        NuSpecialFind(turrets->scene, &special, name, 1)) {
        entry = &turrets->entries[turrets->count++];
        if (entry != NULL) {
            entry->special = special;
            entry->unk72 = value;
            entry->unk60 = 1.0f;
            entry->unk64 = 70.0f;
            entry->unk68 = 50.0f;
            entry->counter = 1;
        }
    }
    return entry;
}

struct CHRISVEC4_s {
    struct nuvec_s xyz;
    f32 w;
};

u16 fn_800B9ED4(void);
void fn_80144D64(struct nuvec_s *start, struct nuvec_s *end, s32 mode, f32 value);

void ProcessSpaceLevelActionList(struct CHRIS43468_s *state)
{
    struct CHRISVEC4_s from, to, rotated, transformed;
    struct CHRISVEC4_s *fromPtr, *toPtr;
    struct CHRISVEC4_s *rotatedPtr, *transformedPtr;
    struct CHRISACTION_s *actions;
    s32 advanced = 0;
    f32 one, time, first, second;

    actions = state->actions;
    if (actions == NULL) {
        return;
    }
    if (state->actionKind == 4) {
        advanced = 1;
        state->action = &actions[state->nextAction++];
        state->actionKind = state->action->kind;
        if (state->actionKind == 3) {
            state->action = actions;
            state->nextAction = 1;
            state->actionKind = actions[0].kind;
        }
    }
    if (advanced) {
        switch (state->actionKind) {
        case 0:
            state->remaining = state->action->value;
            break;
        case 1:
            toPtr = &to;
            toPtr->xyz = lbl_803E0188;
            fromPtr = &from;
            fromPtr->xyz.x = 0.0f;
            fromPtr->xyz.y = 0.0f;
            fromPtr->xyz.z = 300.0f;
            fromPtr->w = 1.0f;
            /* The matrix immediately precedes lbl_803E0188 in the retail layout. */
            NuVecMtxTransform(&fromPtr->xyz, &fromPtr->xyz,
                              (struct numtx_s *)((u32)&lbl_803E0188 - 0x30));
            fn_80144D64(&fromPtr->xyz, &toPtr->xyz, 1, state->action->value);
            state->actionKind = 4;
            break;
        case 2:
            first = -10.0f;
            second = -5.0f;
            one = 1.0f;
            rotatedPtr = &rotated;
            rotatedPtr->xyz.x = first;
            rotatedPtr->xyz.y = second;
            rotatedPtr->xyz.z = first;
            rotatedPtr->w = one;
            NuVecRotateZ(&rotatedPtr->xyz, &rotatedPtr->xyz, fn_800B9ED4());
            NuVecMtxTransform(&rotatedPtr->xyz, &rotatedPtr->xyz, &lbl_803E0158);
            transformedPtr = &transformed;
            transformedPtr->xyz.x = 0.0f;
            transformedPtr->xyz.y = 0.0f;
            transformedPtr->xyz.z = 400.0f;
            transformedPtr->w = one;
            NuVecMtxTransform(&transformedPtr->xyz, &transformedPtr->xyz, &lbl_803E0158);
            fn_80144D64(&rotatedPtr->xyz, &transformedPtr->xyz, 0, state->action->value);
            state->actionKind = 4;
            break;
        }
    }

    if (state->actionKind == 0) {
        time = state->remaining - lbl_80408E9C;
        state->remaining = time;
        if (time <= 0.0f) {
            state->actionKind = 4;
        }
    }
}

s32 fn_8000ABDC(f32 a, f32 b);
void fn_8000E318(struct numtx_s *matrix, s32 angle);
void fn_8000E498(struct numtx_s *matrix, s32 angle);
void fn_8000E608(struct numtx_s *matrix, s32 angle);

void fn_801435B8(struct CHRISFIGHTER_s *fighter, struct nuvec_s *direction,
                 s32 fixedBank, f32 weight)
{
    struct CHRISVEC4_s localDirection, axis;
    struct nuvec_s *local = &localDirection.xyz;
    struct nuvec_s *rotation;
    struct CHRISVEC4_s *axisPtr;
    s32 yaw, pitch;
    s16 turn;
    f32 zero, one, limit, bank;

    NuVecInvMtxRotate(local, direction, &fighter->transform);
    yaw = (s16)fn_8000ABDC(localDirection.xyz.x, localDirection.xyz.z);
    fighter->yaw = yaw;
    NuVecRotateY(local, local, -yaw);
    pitch = (s16)fn_8000ABDC(localDirection.xyz.y, localDirection.xyz.z);
    fighter->pitch = pitch;
    fn_8000E498(&fighter->transform, yaw);
    fn_8000E318(&fighter->transform, -pitch);

    if (fixedBank) {
        fn_8000E608(&fighter->transform, 0x200);
        return;
    }

    axisPtr = &axis;
    rotation = &axisPtr->xyz;
    yaw = (s16)fn_8000ABDC(direction->x, direction->z);
    NuVecRotateY(rotation, direction, -yaw);
    pitch = (s16)fn_8000ABDC(axis.xyz.y, axis.xyz.z);

    one = 1.0f;
    zero = 0.0f;
    axis.xyz.x = one;
    axisPtr->xyz.y = zero;
    axisPtr->xyz.z = zero;
    axisPtr->w = zero;
    NuVecRotateZ(rotation, rotation, (s16)fighter->field8C + 0x4000);
    NuVecRotateX(rotation, rotation, -pitch);
    NuVecRotateY(rotation, rotation, yaw);
    NuVecInvMtxRotate(rotation, rotation, &fighter->transform);

    turn = (s16)fn_8000ABDC(axis.xyz.x, axis.xyz.y);
    limit = lbl_80408E9C * 24000.0f;
    if ((f32)turn > limit) {
        turn = (s16)limit;
    }
    limit = lbl_80408E9C * -24000.0f;
    if ((f32)turn < limit) {
        turn = (s16)limit;
    }
    bank = turn;
    if (weight > 2.0f) {
        bank = zero;
    } else if (weight > one) {
        bank *= 2.0f - weight;
    }
    fn_8000E608(&fighter->transform, -(s16)bank);
}

extern char str_SourceFile_Chris[];
extern char str_Assert_ChrisSLevel_OutOfMem[];
extern void (*fn_80009948(char *, s32))(char *, ...);

static __inline__ void *AllocSpaceState(void **cursor, void **end, u32 size)
{
    u32 start = ((u32)*cursor + 15) & ~15u;
    *cursor = (void *)(start + size);
    if ((u32)*cursor > (u32)*end) {
        fn_80009948(str_SourceFile_Chris, 0x122B)(str_Assert_ChrisSLevel_OutOfMem);
    }
    return (void *)start;
}

void fn_80146018(struct lbl_80409410_s *level)
{
    struct CHRISLEVELDATA_s *data;
    f32 entry;

    level->unk1980 = 1;
    switch (level->unk198) {
    case 0x56:
        data = AllocSpaceState(&level->creditBuffer, &level->creditBufferEnd, 0x63F40);
        level->unk1984 = data;
        data->buffer.entries = (u8 *)data + 0x5D6D0;
        data->buffer.capacity = 0x100;
        level->unk1984->field63728 = 1.0f;
        if (level->unk198 == 0x56) {
            entry = level->unk2DC[0]->field6C;
            if (entry != 0.0f) {
                level->unk1984->field63728 = entry / 11.0f;
            }
        }
        level->unk1984->field63734 = 0;
        break;
    case 0x1B:
    case 0x1C:
    case 0x1D:
        level->unk198C = AllocSpaceState(&level->creditBuffer, &level->creditBufferEnd, 0xB020);
        break;
    default:
        level->unk1980 = 0;
        break;
    }
}
