#include "game/creature.h"

extern s32 lbl_8040B058;
extern struct NUGAMEOBJECT_s* lbl_80409430;
extern s32 lbl_8040912C;
extern s32 fn_800A8DAC(void*, void*, void*, void*, void*, void*, struct NUGAMEOBJECT_s*, u32);
extern void fn_800AA4A8(struct NUGAMEOBJECT_s*);

void fn_800AA92C(void)
{
    s32 i = 0;
    struct NUGAMEOBJECT_s* object = lbl_80409430;

    for (; i < lbl_8040B058; i++, object++) {
        if (!(object->motionFlags & 0x800)) {
            object->drawResult = fn_800A8DAC(object->characterModel,
                (char*)object + 8, (char*)object + 0xC8,
                (object->flagsF28 & 0x200) ? (char*)object + 0x108 : NULL,
                object->drawMatrixEnabled ? (char*)object + 0x148 : NULL,
                (char*)object->playerPacket + 0x194, object, object->drawFlags);
            if (object->drawResult) {
                fn_800AA4A8(object);
            }
            object->drawUpdated = 1;
            if (object->drawResult) {
                object->flagsF28 |= 0x100;
            }
            if (lbl_8040912C == 0 && object->characterData->drawFn != NULL) {
                object->characterData->drawFn(object);
            }
        }
    }
}


void fn_800B9D44(void *);
void fn_800B9DC8(void *);
extern char lbl_803E0298[];
extern s32 lbl_8040AFC8;
extern s32 lbl_8040AFCC;

void fn_800A20AC(void)
{
    lbl_8040AFC8 = (s32) (s8) lbl_803E0298[0xA];
    lbl_8040AFCC = (s32) (s8) lbl_803E0298[0xB];
    fn_800B9DC8(lbl_803E0298 + 4);
    fn_800B9D44(lbl_803E0298 + 4);
}

extern u8 NuTimeBar_DefaultColours[];
extern u8 lbl_801D53C8[];
extern s32 lbl_8040B044;

static inline s32 creatureHasCharacter(s32 id)
{
    u8 *p = NuTimeBar_DefaultColours;
    while (*p != 255) {
        if (*p == id) {
            return 1;
        }
        p++;
    }
    return 0;
}

extern s32 lbl_80409074[];
extern void *lbl_80409410;
extern s32 lbl_8040AFB8;
void fn_800AB428(s32 force, s32 a, s32 b)
{
    s32 pair[2];
    s32 i;
    if (lbl_8040AFB8 == 0 && (force || ((*(u32 *)(*(char **)((char *)lbl_80409410 + 0x1A8) + 4) & 0x5002) == 2))) {
        pair[0] = a;
        pair[1] = b;
        for (i = 0; i < 2; i++) {
            if (pair[i] != -1 && pair[i] != i[lbl_80409074] && creatureHasCharacter(pair[i])) {
                if (pair[i] != lbl_80409074[(i + 1) & 1]) {
                    i[lbl_80409074] = pair[i];
                }
            }
        }
        if (a != b && a == lbl_80409074[1] && b == lbl_80409074[0]) {
            lbl_80409074[0] = a;
            lbl_80409074[1] = b;
        }
    }
}

/* Local views preserve base-plus-member addressing; array extents are unknown. */
struct NUCHARACTERBITS_s {
    char pad0[0x1D8];
    u32 bits[0];
};
static inline s32 creatureCharacterIndex(s32 id)
{
    u8 *p = lbl_801D53C8;
    s32 i = 0;
    while (*p != 255) {
        if (*p == id) {
            return i;
        }
        p += 12;
        i++;
    }
    return -1;
}

s32 fn_800AAE44(s32 id)
{
    if (creatureHasCharacter(id)) {
        return 0;
    }
    if (creatureCharacterIndex(id) == -1 || lbl_8040B044 == 63) {
        return 0;
    }
    {
        NuTimeBar_DefaultColours[lbl_8040B044] = id;
        NuTimeBar_DefaultColours[lbl_8040B044 + 1] = 255;
        lbl_8040B044++;
        ((struct NUCHARACTERBITS_s *)lbl_803E0298)->bits[id / 32] |= 1 << (id & 31);
        return 1;
    }
    return 0;
}

struct NULEVELAVAILABILITY_s {
    char pad0[0x111];
    struct {
        u8 available;
        char pad1[7];
    } levels[0];
};
s32 fn_800AC340(void);
s32 fn_800CC764(s32);
struct NUCHARACTERAVAILABILITY_s {
    char pad0[0x1EC];
    u32 bits[0];
};
void *fn_800AAD10(s32 id)
{
    s32 index;
    s32 allowed;
    char *entry;
    index = fn_800AC340();
    allowed = 0;
    if (index != -1) {
        if (!((((struct NUCHARACTERAVAILABILITY_s *)lbl_803E0298)->bits[id / 32] >> (id & 31)) & 1)) {
            entry = (char *)lbl_801D53C8 + index * 12;
            switch ((u8)entry[1]) {
            case 1:
                break;
            case 2:
                if (*(s16 *)(entry + 2) == -1 || (u8)((struct NULEVELAVAILABILITY_s *)lbl_803E0298)->levels[*(s16 *)(entry + 2)].available == 0) {
                    break;
                }
            case 0:
allow:
                allowed = 1;
                break;
            case 3:
                if (fn_800CC764(0) && fn_800CC764(1) && fn_800CC764(2)) {
                    allowed = 1;
                } else {
                    allowed = 0;
                }
                break;
            }
        } else {
            goto allow;
        }
    }
    return allowed ? (char *)lbl_801D53C8 + index * 12 : NULL;
}

s32 APILoadCharacterModels(s32, s32, s32 *, s32 *, s32);
s32 (*fn_80009970(s32 *, s32))();
extern s32 lbl_8019FA30[];
extern s32 lbl_8019FA48[];
extern s32 lbl_8019FA64[];
extern s32 lbl_8019FA70[];
extern s32 lbl_80408F6C;
extern s32 lbl_80408F70;
extern s32 lbl_80408F7C;
extern s32 lbl_80408F80;

void GameLoadCharacterModels(s32 arg0, s32 arg1)
{
    s32 sp8;
    s32 (*temp_r0)();
    s32 *var_r4;

    temp_r0 = fn_80009970(lbl_8019FA30, 0x1A6B);
    if (arg1 != 0) {
        var_r4 = lbl_8019FA64;
    } else {
        var_r4 = lbl_8019FA70;
    }
    temp_r0(lbl_8019FA48, var_r4);
    if (arg1 != 0) {
        sp8 = lbl_80408F70;
        APILoadCharacterModels(arg0, arg1, &lbl_80408F6C, &sp8, 1);
        return;
    }
    sp8 = lbl_80408F80;
    APILoadCharacterModels(arg0, 0, &lbl_80408F7C, &sp8, 1);
}

u64 __lshrdi3();
void fn_800868B4(void *, void *);
s32 fn_8008F180(void *, u8, f32, f32, f32);
void *fn_800A55D4(u8, s32);
extern f32 lbl_8019FB9C[];
struct CRLEVEL_s {
    char pad0[8];
    s32 count;
    char padC[0xC];
    void *sets;
    char pad1C[4];
    char *defs;
};
extern struct CRLEVEL_s *lbl_80408DF0;
extern s32 lbl_80408FB4;

void fn_800A4C78(char *arg0) {
    s32 i;
    s32 j;
    s32 r27;
    char *e;
    char *obj;
    u32 flags;
    f32 zero;
    struct CRLEVEL_s *lvl;

    if (lbl_80408FB4 == 0 && arg0 != NULL) {
        for (i = 0; i < *(s32 *)(arg0 + 0x10); i++) {
            e = *(char **)(arg0 + 0x14) + i * 0xA8;
            r27 = 0;
            j = 0;
            if (j < *(u8 *)(e + 0x5E)) {
            zero = lbl_8019FB9C[0];
            do {
                if ((u32)((u64)*(u32 *)(e + 0x60) >> j) & 1) {
                    obj = fn_800A55D4(*(u8 *)(e + 0x5D), 1);
                    if (obj != NULL) {
                        lvl = lbl_80408DF0;
                        *(u32 *)(obj + 0x20C) &= ~0x80000;
                        *(u32 *)(obj + 0x208) |= 0x400;
                        if (*(u32 *)(lvl->defs + *(u8 *)(e + 0x5D) * 0x48 + 4) & 0x200) {
                            *(u32 *)(obj + 0x208) |= 4;
                        } else if (*(u32 *)(lvl->defs + *(u8 *)(e + 0x5D) * 0x48 + 4) & 4) {
                            *(u32 *)(obj + 0x208) |= 1;
                        }
                        if (*(u32 *)(lbl_80408DF0->defs + *(u8 *)(e + 0x5D) * 0x48 + 4) & 0x400) {
                            *(u32 *)(obj + 0x105C) |= 1;
                        }
                        if (*(u32 *)(lbl_80408DF0->defs + *(u8 *)(e + 0x5D) * 0x48 + 4) & 0x2000) {
                            *(u32 *)(obj + 0x105C) |= 4;
                        }
                        *(s8 *)(obj + 0x346) = i;
                        if (j == 0 && *(u8 *)(e + 0x5E) > 1 && *(f32 *)(e + 0x94) == zero) {
                            r27 = fn_8008F180(arg0, *(u8 *)(e + 0x5F), *(f32 *)(e + 0x64), *(f32 *)(e + 0x68),
                                *(f32 *)(*(char **)(*(char **)(obj + 0x64) + 0x20) + 0x18));
                        }
                        if (r27 != 0) {
                            fn_800868B4((void *)r27, obj);
                        }
                        *(s32 *)(obj + 0x398) = *(s32 *)(e + 0x80);
                        *(s32 *)(obj + 0x39C) = *(s32 *)(e + 0x84);
                    }
                }
                j++;
            } while (j < *(u8 *)(e + 0x5E));
            }
        }
        *(u32 *)(arg0 + 0x1378) &= ~0x8000;
    }
}

void ResetPlayerContexts(void *);
void fn_80103EA8(void *);

void fn_800A30A8(char *obj, s32 unused) {
    s32 i;
    f32 *p;

    *(f32 *)(obj + 0x6C4) = 0.0f;
    *(f32 *)(obj + 0x6E8) = 0.0f;
    *(f32 *)(obj + 0x6C8) = 0.0f;
    *(s16 *)(obj + 0x7AA) = 0;
    *(s16 *)(obj + 0x7AC) = 0;
    *(s16 *)(obj + 0x7AE) = 0;
    ResetPlayerContexts(obj);
    *(s32 *)(*(char **)(obj + 0x61C) + 0x4) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x8) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0xC) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x10) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x14) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x18) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x1C) = 0;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x20) = 0;
    *(f32 *)(*(char **)(obj + 0x61C) + 0x40) = 0.0f;
    *(f32 *)(*(char **)(obj + 0x61C) + 0x44) = 0.0f;
    *(f32 *)(*(char **)(obj + 0x61C) + 0x48) = 0.0f;
    *(f32 *)(*(char **)(obj + 0x61C) + 0x4C) = 0.0f;
    *(u32 *)(*(char **)(obj + 0x61C) + 0x58) &= ~0x4000;
    *(u32 *)(*(char **)(obj + 0x61C) + 0x58) &= ~0x2000;
    *(s32 *)(*(char **)(obj + 0x61C) + 0x54) = 0;
    p = (f32 *)(obj + 0x130);
    for (i = 0; i < 16; i++) {
        *p = 2000000.0f;
        p -= 5;
    }
    *(u8 *)(obj + 0x7C0) = 0;
    *(f32 *)(obj + 0x720) = 0.0f;
    *(f32 *)(obj + 0x738) = 0.0f;
    *(f32 *)(obj + 0x750) = 0.0f;
    *(f32 *)(obj + 0x730) = 0.0f;
    *(f32 *)(obj + 0x73C) = 0.0f;
    *(u8 *)(obj + 0x7CF) = 0xFF;
    *(s32 *)(obj + 0x658) = 0;
    *(s32 *)(obj + 0x65C) = 0;
    *(s32 *)(obj + 0x660) = 0;
    *(s32 *)(obj + 0x664) = 0;
    *(s32 *)(obj + 0x694) = 0;
    *(s32 *)(obj + 0x698) = 0;
    *(s8 *)(obj + 0x7E6) = -1;
    fn_80103EA8(obj);
    *(f32 *)(obj + 0x824) = 0.0f;
    *(u32 *)(obj + 0x7B0) &= ~0x80000000;
    *(f32 *)(obj + 0x760) = 2000000.0f;
    *(f32 *)(obj + 0x77C) = 0.0f;
}

s32 fn_800B9ED4(void);

void ResetPlayerContexts(void *arg) {
    char *obj = arg;

    *(s8 *)(obj + 0x7E4) = -1;
    *(f32 *)(obj + 0x704) = 0.0f;
    *(f32 *)(obj + 0x754) = 0.0f;
    if (*(u8 *)(obj + 0x7B4)) {
        *(f32 *)(obj + 0x6BC) = 1.0f;
    } else {
        *(f32 *)(obj + 0x6BC) = 0.0f;
    }
    *(s8 *)(obj + 0x7DF) = -1;
    *(s8 *)(obj + 0x7CC) = 0;
    *(f32 *)(obj + 0x6AC) = 0.0f;
    *(f32 *)(obj + 0x6B4) = 0.0f;
    *(s8 *)(obj + 0x7BD) = 0;
    *(s8 *)(obj + 0x7BE) = 0;
    *(f32 *)(obj + 0x6EC) = 0.0f;
    *(f32 *)(obj + 0x768) = 0.0f;
    *(s32 *)(obj + 0x620) = 0;
    *(u32 *)(*(char **)(obj + 0x61C) + 0x58) &= ~0x2000;
    *(s32 *)(obj + 0x690) = 0;
    *(s8 *)(obj + 0x7E3) = fn_800B9ED4() / 32768;
    *(s16 *)(obj + 0x79A) = 0;
    *(s8 *)(obj + 0x7CB) = 0;
    *(f32 *)(obj + 0x594) = 1000.0f;
    *(f32 *)(obj + 0x6E0) = 0.0f;
    *(s16 *)(obj + 0x796) = -1;
    *(s8 *)(obj + 0x7E2) = -1;
    *(s16 *)(obj + 0x798) = -1;
    *(f32 *)(obj + 0x71C) = 0.0f;
    *(s16 *)(obj + 0x79E) = -1;
    *(f32 *)(obj + 0x6B0) = 0.0f;
    *(s16 *)(obj + 0x7A0) = -1;
    *(s16 *)(obj + 0x7A2) = -1;
    *(f32 *)(obj + 0x758) = 0.0f;
    *(f32 *)(obj + 0x75C) = 0.0f;
    *(f32 *)(obj + 0x774) = 0.0f;
    *(f32 *)(obj + 0x778) = 0.0f;
}

struct CRVEC_s { f32 x, y, z; };
extern struct CRVEC_s lbl_801D5964;
extern f32 lbl_8040902C;
void fn_80095558(void *, s32);
void fn_800955A8(void *, void *);
void fn_800ABC50(void *);
void fn_800ABEB0(void *, s32);

struct CRPKT_s {
    char pad0[0x144];
    f32 f144;
    char pad148[0x6F8 - 0x148];
    f32 f6F8;
    char pad6FC[0x764 - 0x6FC];
    f32 f764;
    char pad768[0x7DD - 0x768];
    u8 b7DD;
    char pad7DE[0x7E6 - 0x7DE];
    u8 b7E6;
};
void fn_800A3224(char *obj) {
    fn_800A30A8(*(char **)(obj + 0xEEC), *(s32 *)(obj + 0x64));
    *(struct CRVEC_s *)(obj + 0x210) = lbl_801D5964;
    (*(struct CRPKT_s **)(obj + 0xEEC))->f6F8 = 0.0f;
    *(f32 *)(*(char **)(obj + 0xEEC) + 0x764) = lbl_8040902C;
    *(u32 *)(obj + 0xF28) |= 0x100000;
    if (*(u32 *)(obj + 0x208) & 0x400) {
        *(u8 *)(*(char **)(obj + 0xEEC) + 0x7E6) = 0;
    }
    fn_800ABEB0(obj, 2);
    fn_80095558(obj + 8, 1);
    fn_800955A8(*(void **)(obj + 0x60), obj + 8);
    *(u8 *)(obj + 0x286) = 0;
    *(u8 *)(obj + 0x285) = 0;
    fn_800ABC50(obj);
    *(f32 *)(obj + 0x102C) = 0.0f;
    *(u32 *)(obj + 0xF28) &= ~0x10;
    *(f32 *)(obj + 0x1044) = 0.0f;
    *(u8 *)(*(char **)(obj + 0xEEC) + 0x7DD) = 0;
    *(f32 *)(*(char **)(obj + 0xEEC) + 0x144) = 1.0f;
    *(f32 *)(obj + 0x1E8) = 0.0f;
    *(u32 *)(obj + 0x20C) &= ~0x40000;
}

void NuVecAdd(void *, void *, void *);
void NuVecScale(void *, void *, f32);
void fn_80098190(void *, void *, s32, s32, void *);
void *memset(void *, s32, u32);
extern struct NUGAMEOBJECT_s *gPlayer1Pointer[];

s32 fn_800AAC04(void *outPos, s8 *outInfo)
{
    struct CRVEC_s sum;
    f32 count;
    s32 i;

    memset(&sum, 0, sizeof(sum));
    count = 0.0f;
    for (i = 0; i < 2; i++) {
        struct NUGAMEOBJECT_s *player = gPlayer1Pointer[i];
        if (player != NULL && (player->flags20C & 0x01000000)) {
            NuVecAdd(&sum, &sum, player->position);
            count += 1.0f;
        }
    }
    if (count > 0.0f) {
        NuVecScale(outPos, &sum, 1.0f / count);
        if (outInfo != NULL) {
            fn_80098190(*(void **)((char *)lbl_80409410 + 0x2DC), outPos, -1, -1, outInfo);
        }
        return 1;
    }
    if (outInfo != NULL) {
        outInfo[1] = -1;
    }
    return 0;
}

void NuMtxTranslate(void *, void *);
void fn_8000DCE0(void *, void *);
void fn_8001AF60(s32);
void fn_8001AF70(void);
s32 fn_800BA014(s32, void *);
s32 fn_800CF9D8(void *, s32, void *, f32);
extern s32 lbl_803E04B4[];

struct CRCHARMODEL_s {
    char pad0[0x14];
    void *parts[1];
};

struct CRMTX_s {
    f32 m[4][4];
};

struct CRPKT_AA178_s {
    char pad0[0x194];
    struct {
        f32 r[3][4];
        struct CRVEC_s pos;
        f32 w;
    } mats[1];
};

void fn_800AA178(char *arg0, s32 arg1)
{
    struct CRMTX_s mtx;
    struct CRMTX_s mtx2;
    struct CRVEC_s scale;
    char *charInfo = *(char **)(*(char **)(arg0 + 0x64) + 0x20);
    s8 idx = *(s8 *)(charInfo + 0xDC);

    if (idx != -1 && ((struct CRCHARMODEL_s *)*(void **)(arg0 + 0x60))->parts[idx] != NULL) {
        if (*(u8 *)(*(char **)(arg0 + 0xEEC) + 0x7D6) == 0 && *(u8 *)(charInfo + 0xC3) != 0 && *(f32 *)(*(char **)(arg0 + 0xEEC) + 0x6B0) > 0.0f) {
            if ((u32)(lbl_803E04B4[0] & 3) > 1U) {
                return;
            }
            scale.x = 1.0f;
        } else {
            f32 s = *(f32 *)(*(char **)(arg0 + 0xEEC) + 0x6AC);
            if (s <= 0.0f) {
                return;
            }
            scale.x = s;
        }
        scale.y = scale.z = scale.x;
        fn_8000DCE0(&mtx, &scale);
        NuMtxTranslate(&mtx, &((struct CRPKT_AA178_s *)*(void **)(arg0 + 0xEEC))->mats[idx].pos);
        fn_800BA014(*(f32 *)(*(char **)(arg0 + 0xEEC) + 0x6B0) > 0.0f ? 4 : 3, &mtx);
        if (arg1 != 0) {
            u8 *pFlag = (u8 *)(arg0 + 0x107F);
            fn_800CF9D8(&mtx, *pFlag, &mtx2, *(f32 *)(arg0 + 0x1040));
            fn_8001AF60(0);
            fn_800BA014(*(f32 *)(*(char **)(arg0 + 0xEEC) + 0x6B0) > 0.0f ? 0x2C : 0x2B, &mtx2);
            fn_8001AF70();
        }
    }
}

s32 fn_800952D8(s32);
s32 fn_8009D158(void);
void fn_8009D160(void *, s32, s32, s32);
s32 fn_800B2ED4(void);
void fn_800AC85C(void);
extern s32 gDebugLevelStreamingEnabled;
extern s32 lbl_80408DF4;
extern s32 lbl_80408FD4;
extern s32 lbl_8040907C;
extern s32 lbl_80409080;
extern f32 lbl_8040B020;

void fn_800AB534(void)
{
    s32 candidates[134];
    s32 sp220[2];
    s32 state = fn_800B2ED4();

    if (*(s32 *)((char *)lbl_80409410 + 0x198) == 0x7B && state != 0x16 &&
        (u32)(state - 0x18) > 1U && lbl_8040907C == -1 && lbl_80409080 == -1 &&
        fn_8009D158() == 0 && (u32)(lbl_80408F80 - lbl_80408F7C) > 0xFFFFFU) {
        s32 count = 0;
        s32 i;
        if (fn_800952D8(0x6A) == 0) {
            candidates[count++] = 0x6A;
        } else if (fn_800952D8(0x7F) == 0) {
            candidates[count++] = 0x7F;
        } else if (fn_800952D8(0x5E) == 0) {
            candidates[count++] = 0x5E;
        } else {
            for (i = 0; i < 0x85; i++) {
                if (creatureCharacterIndex(i) != -1 && creatureHasCharacter(i) && fn_800952D8(i) == 0) {
                    candidates[count++] = i;
                }
            }
        }
        if (count > 0) {
            i = (count > 1) ? (fn_800B9ED4() / ((0xFFFF / count) + 1)) : 0;
            lbl_8040907C = candidates[i];
            lbl_8040B020 = 0.0f;
            if (lbl_80408FD4 != 0 || gDebugLevelStreamingEnabled == 0) {
                struct {
                    u8 id;
                    u8 flag;
                    s16 end;
                } req;
                s32 *memEndPtr = sp220;
                req.id = (u8)lbl_8040907C;
                req.end = -0x100;
                req.flag = 1;
                lbl_80408DF4 = 1;
                sp220[0] = lbl_80408F80;
                APILoadCharacterModels((s32)&req, 0, &lbl_80408F7C, memEndPtr, 1);
                lbl_80409080 = lbl_8040907C;
                lbl_8040907C = -1;
            } else {
                fn_8009D160(fn_800AC85C, 0, 0, 0);
            }
        }
    }
}

void NuMtxPreScale(void *, void *);
void fn_8000D134(void *, void *, void *);

void fn_800AA2F4(char *arg0, s32 arg1)
{
    struct CRMTX_s mtx0;
    struct CRMTX_s mtx;
    struct CRMTX_s mtx2;
    struct CRVEC_s scale;
    s8 idx = *(s8 *)(*(char **)(*(char **)(arg0 + 0x64) + 0x20) + 0xE1);

    if (idx != -1 && ((struct CRCHARMODEL_s *)*(void **)(arg0 + 0x60))->parts[idx] != NULL) {
        s32 id1 = -1;
        s32 id2 = -1;
        s32 doMul = 0;
        switch (*(s16 *)(arg0 + 0x1074)) {
        case 2:
        case 0x3F:
        case 0x40:
        case 0x41:
            id1 = 5;
            id2 = 0x2D;
            doMul = 0;
            break;
        }
        mtx = *(struct CRMTX_s *)(*(char **)(arg0 + 0xEEC) + (idx << 6) + 0x194);
        if (doMul != 0) {
            fn_8000D134(&mtx, &mtx0, &mtx);
        }
        {
            f32 s = *(f32 *)(*(char **)(arg0 + 0xEEC) + 0x6B4);
            if (s != 1.0f) {
                scale.z = s;
                scale.y = s;
                scale.x = s;
                NuMtxPreScale(&mtx, &scale);
            }
        }
        if (id1 != -1) {
            fn_800BA014(id1, &mtx);
        }
        if (arg1 != 0 && id2 != -1) {
            u8 *pFlag = (u8 *)(arg0 + 0x107F);
            fn_800CF9D8(&mtx, *pFlag, &mtx2, *(f32 *)(arg0 + 0x1040));
            fn_8001AF60(0);
            fn_800BA014(id2, &mtx2);
            fn_8001AF70();
        }
    }
}

void NuSpecialFindMultiWC(void *, void *);
s32 fn_800130F4(void *);

void fn_800AAA2C(char *arg0, s32 arg1, struct CRMTX_s *arg2, struct CRMTX_s *arg3)
{
    struct CRMTX_s aligned;
    void *special;

    switch (arg1) {
    case 0x79:
    case 0x39:
        special = arg0 + 0x1E4;
        break;
    case 0x24:
        special = arg0 + 0x1CC;
        break;
    case 0x38:
        special = arg0 + 0x1D8;
        break;
    case 0x1B:
        special = arg0 + 0x1F0;
        break;
    case 0x5A:
        special = arg0 + 0x1FC;
        break;
    default:
        special = NULL;
        break;
    }
    if (fn_800130F4(special) != 0) {
        if (arg2 != NULL) {
            if ((u32)arg2 & 0xF) {
                aligned = *arg2;
                arg2 = &aligned;
            }
            NuSpecialFindMultiWC(special, arg2);
        }
        if (arg3 != NULL) {
            if ((u32)arg3 & 0xF) {
                aligned = *arg3;
                arg3 = &aligned;
            }
            NuSpecialFindMultiWC(special, arg3);
        }
    }
}

s32 fn_80095630(void *, s32, s32, s32);
void fn_800A9794(struct NUGAMEOBJECT_s *, s32);
void fn_800F78FC(void *, s32, f32, f32);
extern u8 lbl_801D59C6[];
extern f32 lbl_80409808;

struct CRGAME774_s {
    char pad0[0x774];
    struct {
        void *p;
        char pad4[0xC];
    } entries[1];
};

#define IS_CAPE_ANIM(a) ((s16)(a) == 0x11 || (s16)(a) == 0x4E || (s16)(a) == 0x5D || (s16)(a) == 0x4F || (s16)(a) == 0x29)

static inline void drawExtra100(struct NUGAMEOBJECT_s *arg0, s32 arg1)
{
    if (*(s16 *)((char *)arg0 + 0x1074) != 0x71 || (s8)arg0->unk1081[4] > 1) {
        struct CRMTX_s mtx;
        struct CRMTX_s mtx2;
        s8 idx = *(s8 *)((char *)arg0->characterData->config + 0xDE);
        if (idx != -1 && ((struct CRCHARMODEL_s *)arg0->characterModel)->parts[idx] != NULL) {
            mtx = *(struct CRMTX_s *)((char *)arg0->playerPacket + (idx << 6) + 0x194);
            fn_800BA014(0x100, &mtx);
            if (arg1 != 0) {
                fn_800CF9D8(&mtx, (u8)arg0->unk1064[0x1B], &mtx2, *(f32 *)((char *)arg0 + 0x1040));
                fn_8001AF60(0);
                fn_800BA014(0x100, &mtx2);
                fn_8001AF70();
            }
        }
    }
}

void fn_800AA4A8(struct NUGAMEOBJECT_s *arg0)
{
    fn_800AAA2C(lbl_80409410, *(s16 *)((char *)arg0 + 0x1074),
        (struct CRMTX_s *)((char *)arg0 + 0xC8),
        arg0->drawMatrixEnabled ? (struct CRMTX_s *)((char *)arg0 + 0x148) : NULL);
    if (*(f32 *)((char *)arg0->playerPacket + 0x6BC) > 0.0f) {
        fn_800A9794(arg0, arg0->drawMatrixEnabled);
    }
    if (*(f32 *)((char *)arg0->playerPacket + 0x6AC) > 0.0f ||
        *(f32 *)((char *)arg0->playerPacket + 0x6B0) > 0.0f) {
        fn_800AA178((char *)arg0, arg0->drawMatrixEnabled);
    }
    if (*(f32 *)((char *)arg0->playerPacket + 0x6B4) > 0.0f) {
        fn_800AA2F4((char *)arg0, arg0->drawMatrixEnabled);
    }
    {
        char *pkt = (char *)arg0->playerPacket;
        f32 t = *(f32 *)(pkt + 0x740);
        if (t > 0.0f && *(f32 *)(pkt + 0x74C) > 0.0f &&
            ((struct CRGAME774_s *)lbl_80409410)->entries[*(s16 *)(pkt + 0x7A8)].p != NULL) {
            fn_800F78FC(pkt + 0x604, *(s16 *)(pkt + 0x7A8), *(f32 *)(pkt + 0x74C), t / lbl_80409808);
        }
    }
    if (lbl_8040AFB8 == 0 && lbl_801D59C6[0] != 0 && *(s32 *)((char *)lbl_80409410 + 0x1774) != 0) {
        drawExtra100(arg0, arg0->drawMatrixEnabled);
    }
    if (*(s16 *)((char *)arg0 + 0x1074) == 0xF) {
        s16 setIdx = *(s16 *)(*(char **)((char *)lbl_80408DF0 + 0x1C) + 0x92);
        if (setIdx != -1) {
            char *set = (char *)lbl_80408DF0->sets + setIdx * 0x54;
            if (((u8)arg0->unk0[0x45] == 0 && IS_CAPE_ANIM(*(u16 *)((char *)arg0 + 0x4A)) &&
                 (*(void ***)(set + 0xC))[(s16)*(u16 *)((char *)arg0 + 0x4A)] != NULL) ||
                ((u8)arg0->unk0[0x45] != 0 && IS_CAPE_ANIM(*(u16 *)((char *)arg0 + 0x46)) &&
                 (*(void ***)(set + 0xC))[(s16)*(u16 *)((char *)arg0 + 0x46)] != NULL &&
                 IS_CAPE_ANIM(*(u16 *)((char *)arg0 + 0x48)) &&
                 (*(void ***)(set + 0xC))[(s16)*(u16 *)((char *)arg0 + 0x48)] != NULL)) {
                struct CRMTX_s mtx;
                struct CRMTX_s *capeMtx = (struct CRMTX_s *)((char *)arg0->playerPacket + 0x150);
                void *reflMtx;
                if (fn_80095630(&arg0->unk0[8], 0x4F, 1, 1) == 0) {
                    *capeMtx = *(struct CRMTX_s *)((char *)arg0 + 0xC8);
                    *(f32 *)((char *)capeMtx + 0x40) =
                        (arg0->drawMatrixEnabled != 0 && (u8)arg0->unk1064[0x1B] == 2)
                            ? *(f32 *)((char *)arg0 + 0x1040)
                            : 2000000.0f;
                }
                reflMtx = (*(f32 *)((char *)capeMtx + 0x40) != 2000000.0f &&
                           fn_800CF9D8(capeMtx, 2, &mtx, *(f32 *)((char *)capeMtx + 0x40)) != 0)
                              ? &mtx
                              : NULL;
                fn_800A8DAC(set, &arg0->unk0[8], capeMtx, NULL, reflMtx, NULL, NULL, 1U);
            }
        }
    }
}

f32 NuSinApprox(s32);
s32 fn_80095AF8(s32, s32, s32 *);
void fn_800D6968(s32, f32, s32, f32, s32, f32, f32, f32, f32);
struct CRPOS2_s {
    f32 x;
    f32 y;
};
extern struct CRPOS2_s lbl_803E808C[];
extern f32 lbl_803E8394[];
extern f32 lbl_80408F00;
extern f32 lbl_80409064;
extern f32 lbl_80409068;
extern s32 lbl_80409070;
extern f32 lbl_804094D8;

void fn_800AAF44(s32 arg0, s32 arg1, s32 arg4, f32 farg0, f32 farg1, f32 farg2)
{
    s32 sp8;
    f32 stepX = lbl_80409064 * farg1;
    f32 stepY = lbl_80409068 * farg1;
    f32 size = lbl_804094D8 * farg1;
    s32 count = 0;

    if (!(lbl_80408F00 > -0.1f)) {
        if (farg2 > 1.0f) {
            farg2 = 1.0f;
        }
        if (*lbl_801D53C8 != 255) {
            u8 *p = lbl_801D53C8;
            do {
                count++;
                if (count > 63) {
                    break;
                }
                p += 12;
            } while (*p != 255);
        }
        if (count > 0) {
            s32 cols = lbl_80409070;
            s32 rows = (count / cols) + 1;
            f32 y = farg0 - ((f32)(count / cols) * stepY * 0.5f);
            f32 startX = -((f32)(cols - 1) * stepX * 0.5f);
            s32 r;
            for (r = 0; r < rows; r++, y += stepY) {
                f32 x = startX;
                s32 c;
                for (c = 0; c < lbl_80409070; c++, x += stepX) {
                    s32 idx = r * lbl_80409070 + c;
                    if (idx < count) {
                        s32 ch;
                        lbl_803E808C[idx].x = x;
                        lbl_803E808C[idx].y = y;
                        ch = lbl_801D53C8[idx * 12];
                        if (!(farg2 <= 0.0f)) {
                            s32 icon = 0xCA;
                            f32 alpha = 1.0f;
                            if (arg0 != 0 && fn_80095AF8(arg0, ch, &sp8) != 0) {
                                s32 pulse;
                                if (arg1 != 0) {
                                    continue;
                                }
                                if (sp8 == 0) {
                                    icon = 0xC9;
                                    pulse = 1;
                                } else if (sp8 == 1) {
                                    icon = 0xC8;
                                    pulse = 1;
                                } else {
                                    alpha = 0.25f;
                                    pulse = 0;
                                }
                                if (pulse != 0) {
                                    alpha = NuSinApprox((s32)(lbl_803E8394[2] * 65536.0f)) * 0.125f + 0.375f;
                                }
                            }
                            if (!creatureHasCharacter(ch)) {
                                alpha = 0.25f;
                                ch = -1;
                            }
                            alpha *= farg2;
                            fn_800D6968(ch, x, icon, y, 1, 0.002f, size, alpha, alpha);
                        }
                    }
                }
            }
        }
    }
}

void NuMtxSetIdentity(void *);
u8 NuPortalClipTest(void *, void *, f32, s16);
s16 NuPortalWhichRoom(void *, void *);
void fn_8000E250(void *, s32);
void fn_8000E318(void *, s32);
void fn_8000E3C0(void *, s32);
void fn_8000E498(void *, s32);
void fn_8000E540(void *, s32);
void fn_8000E608(void *, s32);
extern f32 lbl_8040904C;

s32 fn_800A8FF4(void)
{
    s32 i = 0;
    struct NUGAMEOBJECT_s *obj = lbl_80409430;

    for (; i < lbl_8040B058; i++, obj++) {
        obj->motionFlags |= 0x800;
        if ((obj->flags20C & 0x80080000) == 0x80080000) {
            *(u8 *)((char *)obj->playerPacket + 0x7DE) = obj->drawUpdated;
            obj->drawUpdated = 0;
            if ((obj->unk28F == 0 || (!(obj->unk103C > 0.0f) && *(f32 *)((char *)obj + 0x1038) != 0.0f) ||
                 (*(u8 *)((char *)obj->characterData->config + 0xE5) == 8 && *(u8 *)((char *)obj->playerPacket + 0x7D5) != 0)) &&
                ((*(u32 *)((char *)obj->playerPacket + 0x7B0) & 0x04000000) == 0 ||
                 *(s8 *)((char *)obj->playerPacket + 0x7DF) != -1) &&
                (*(u8 *)((char *)obj->playerPacket + 0x7DF) != 0x12 ||
                 *(u8 *)((char *)obj->playerPacket + 0x7CA) != 2)) {
                struct CRVEC_s scale;
                struct CRVEC_s pos;
                struct CRMTX_s mtx;
                struct CRMTX_s shadowMtx;
                struct CRMTX_s reflMtx;

                pos.x = obj->position[0];
                pos.y = obj->position[1];
                if (obj->motionFlags & 0x100) {
                    pos.y += *(f32 *)((char *)obj + 0x101C) * *(f32 *)((char *)obj + 0xB8);
                }
                pos.z = obj->position[2];
                obj->drawResult = 1;
                if (*(u32 *)((char *)obj + 0xF24) & 0x40) {
                    if ((*(u32 *)((char *)obj + 0xF24) & 0x20) && !(obj->flags20C & 0x20000000)) {
                        *(s16 *)((char *)obj + 0x1078) =
                            (*(void **)((char *)lbl_80409410 + 0x1C0) != NULL)
                                ? NuPortalWhichRoom(*(void **)((char *)lbl_80409410 + 0x1C0), &obj->unk78[0x18])
                                : -1;
                    }
                    if (*(void **)((char *)lbl_80409410 + 0x1C0) != NULL) {
                        if (NuPortalClipTest(*(void **)((char *)lbl_80409410 + 0x1C0), &obj->unk78[0x18],
                                (*(f32 *)((char *)obj + 0x1F0) > *(f32 *)((char *)obj + 0x1EC))
                                    ? *(f32 *)((char *)obj + 0x1F0)
                                    : *(f32 *)((char *)obj + 0x1EC),
                                *(s16 *)((char *)obj + 0x1078)) == 0) {
                            obj->drawResult = 0;
                            continue;
                        }
                    }
                }
                {
                    f32 s = *(f32 *)((char *)obj + 0xB8);
                    scale.z = s;
                    scale.y = s;
                    scale.x = s;
                }
                fn_8000DCE0(&mtx, &scale);
                switch ((u8)obj->unk1064[0x1A]) {
                case 0:
                    fn_8000E3C0(&mtx, 0x8000);
                    if (*(u16 *)((char *)obj + 0x27C) != 0) {
                        fn_8000E250(&mtx, *(u16 *)((char *)obj + 0x27C));
                    }
                    if (*(u16 *)((char *)obj + 0x27E) != 0) {
                        fn_8000E3C0(&mtx, *(u16 *)((char *)obj + 0x27E));
                    }
                    if (*(u16 *)((char *)obj + 0x280) != 0) {
                        fn_8000E540(&mtx, *(u16 *)((char *)obj + 0x280));
                    }
                    NuMtxTranslate(&mtx, &pos);
                    break;
                case 1:
                    fn_8000E3C0(&mtx, *(u16 *)((char *)obj + 0x27E) + 0x8000);
                    if (*(u16 *)((char *)obj + 0x27C) != 0) {
                        fn_8000E250(&mtx, *(u16 *)((char *)obj + 0x27C));
                    }
                    if (*(u16 *)((char *)obj + 0x280) != 0) {
                        fn_8000E540(&mtx, *(u16 *)((char *)obj + 0x280));
                    }
                    NuMtxTranslate(&mtx, &pos);
                    break;
                default:
                    fn_8000E3C0(&mtx, *(u16 *)((char *)obj + 0x27E) + 0x8000);
                    if (*(u16 *)((char *)obj + 0x280) != 0) {
                        fn_8000E540(&mtx, *(u16 *)((char *)obj + 0x280));
                    }
                    if (*(u16 *)((char *)obj + 0x27C) != 0) {
                        fn_8000E250(&mtx, *(u16 *)((char *)obj + 0x27C));
                    }
                    NuMtxTranslate(&mtx, &pos);
                    break;
                case 3:
                    fn_8000E3C0(&mtx, 0x8000);
                    if (*(u16 *)((char *)obj + 0x280) != 0) {
                        fn_8000E540(&mtx, *(u16 *)((char *)obj + 0x280));
                    }
                    if (*(u16 *)((char *)obj + 0x27C) != 0) {
                        fn_8000E250(&mtx, *(u16 *)((char *)obj + 0x27C));
                    }
                    if (*(u16 *)((char *)obj + 0x27E) != 0) {
                        fn_8000E3C0(&mtx, *(u16 *)((char *)obj + 0x27E));
                    }
                    NuMtxTranslate(&mtx, &pos);
                    break;
                case 4:
                    mtx = *(struct CRMTX_s *)((char *)obj->playerPacket + 0x594);
                    NuMtxPreScale(&mtx, &scale);
                    fn_8000E498(&mtx, 0x8000);
                    NuMtxTranslate(&mtx, &pos);
                    break;
                case 5:
                    mtx = *(struct CRMTX_s *)((char *)obj->playerPacket + 0x594);
                    NuMtxPreScale(&mtx, &scale);
                    fn_8000E498(&mtx, 0x8000);
                    break;
                }
                if (obj->playerPacket != NULL) {
                    if (*(s16 *)((char *)obj->playerPacket + 0x7AA) != 0) {
                        fn_8000E608(&mtx, *(s16 *)((char *)obj->playerPacket + 0x7AA));
                    }
                    if (*(s16 *)((char *)obj->playerPacket + 0x7AC) != 0) {
                        fn_8000E318(&mtx, *(s16 *)((char *)obj->playerPacket + 0x7AC));
                    }
                    if (*(s16 *)((char *)obj->playerPacket + 0x7AE) != 0) {
                        fn_8000E498(&mtx, *(s16 *)((char *)obj->playerPacket + 0x7AE));
                    }
                }
                *(struct CRMTX_s *)((char *)obj + 0xC8) = mtx;
                if (scale.x == 0.0f && scale.y == 0.0f && scale.z == 0.0f) {
                    obj->drawResult = 0;
                } else {
                    obj->motionFlags ^= 0x800;
                    obj->flagsF28 &= ~0x200;
                    obj->drawMatrixEnabled = 0;
                    if ((u8)obj->unk1064[0x1B] != 0 && *(f32 *)((char *)obj + 0x1040) != 2000000.0f &&
                        *(f32 *)((char *)obj + 0x1048) < *(f32 *)(*(char **)((char *)lbl_80409410 + 0x1A8) + 0x88)) {
                        obj->drawMatrixEnabled = fn_800CF9D8(&mtx, (u8)obj->unk1064[0x1B], &reflMtx, *(f32 *)((char *)obj + 0x1040));
                        *(struct CRMTX_s *)((char *)obj + 0x148) = reflMtx;
                    }
                    if (obj->unk28F == 0 && *(f32 *)((char *)obj + 0x220) != 2000000.0f &&
                        (obj->motionFlags & 0x40) && *(u16 *)((char *)obj->characterData->config + 0xBA) == 0) {
                        NuMtxSetIdentity(&shadowMtx);
                        if (*(u16 *)((char *)obj + 0x106C) != 0) {
                            fn_8000E540(&shadowMtx, *(u16 *)((char *)obj + 0x106C));
                        }
                        if (*(u16 *)((char *)obj + 0x106A) != 0) {
                            fn_8000E250(&shadowMtx, *(u16 *)((char *)obj + 0x106A));
                        }
                        shadowMtx.m[3][0] = obj->position[0];
                        shadowMtx.m[3][1] = *(f32 *)((char *)obj + 0x220) + lbl_8040904C;
                        shadowMtx.m[3][2] = obj->position[2];
                        *(struct CRMTX_s *)((char *)obj + 0x108) = shadowMtx;
                        obj->flagsF28 |= 0x200;
                    }
                }
            }
        }
    }
    return 0;
}
