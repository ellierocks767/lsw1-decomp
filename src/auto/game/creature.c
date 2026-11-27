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

struct CRLEVEL_s {
    char pad0[8];
    s32 count;
    char padC[0xC];
    void *sets;
    char pad1C[4];
    char *defs;
};
extern struct CRLEVEL_s *lbl_80408DF0;

struct CRANIMSET_s {
    char pad0[4];
    void *hgobj;
    void **mtx;
    void **anims;
    char pad10[0x44];
};
struct CRROOTDATA_s {
    char pad0[0x270];
    f32 pos[3];
    char pad27C[0x20];
};
void fn_800AC7AC();
extern f32 lbl_8019FA7C[];
void NuHGobjEvalAnim2Root(void *hgobj, void *anim, f32 time, s32 njanims, void *janim, void *mtx_array, void *rootfn, void *rootdata);

void fn_800A2370(void)
{
    char mtx[0x4000];
    struct CRROOTDATA_s root;
    s32 i;
    s32 j;
    struct CRANIMSET_s *set = lbl_80408DF0->sets;
    f32 zero;

    for (i = 0; i <= 30; i++, set++) {
        j = 0;
        if (j < lbl_80408DF0->count) {
            zero = lbl_8019FA7C[0];
            do {
                if (set != NULL && set->anims[j] != NULL && set->hgobj != NULL) {
                    root.pos[0] = zero;
                    root.pos[1] = zero;
                    root.pos[2] = zero;
                    NuHGobjEvalAnim2Root(set->hgobj, set->anims[j], zero, 0, 0, mtx, fn_800AC7AC, &root);
                    *(f32 *)((char *)set->mtx[j] + 0x34) = root.pos[0];
                    *(f32 *)((char *)set->mtx[j] + 0x38) = root.pos[1];
                    *(f32 *)((char *)set->mtx[j] + 0x3C) = root.pos[2];
                }
                j++;
            } while (j < lbl_80408DF0->count);
        }
    }
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

s32 fn_8006F8B0();
void fn_80071A70(s32, s32);
void fn_80071B78(s32, f32, f32);
void fn_80071C04(s32, f32 *, s32);
extern struct NUGAMEOBJECT_s *gPlayer1Pointer[];
extern f32 lbl_802DA01C[];

void fn_800A474C(void)
{
    s32 i;
    s32 id;

    for (i = 0; i < 2; i++) {
        if (gPlayer1Pointer[i] != NULL) {
            *(s32 *)((char *)gPlayer1Pointer[i]->playerPacket + 0x820) = fn_8006F8B0();
            id = *(s32 *)((char *)gPlayer1Pointer[i]->playerPacket + 0x820);
            if (id != -1) {
                lbl_802DA01C[0] = (u32)((u8 *)gPlayer1Pointer[i]->characterData->config)[0xC5] / 255.0f;
                lbl_802DA01C[1] = (u32)((u8 *)gPlayer1Pointer[i]->characterData->config)[0xC6] / 255.0f;
                lbl_802DA01C[2] = (u32)((u8 *)gPlayer1Pointer[i]->characterData->config)[0xC7] / 255.0f;
                fn_80071A70(id, 2);
                fn_80071C04(id, lbl_802DA01C, 0);
                fn_80071B78(id, 0.0f, 1.25f);
            }
        }
    }
}

u64 __lshrdi3();
void fn_800868B4(void *, void *);
s32 fn_8008F180(void *, u8, f32, f32, f32);
void *fn_800A55D4(u8, s32);
extern f32 lbl_8019FB9C[];
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

s32 fn_800B9ED4(void);
extern f32 lbl_80408E9C;
void fn_800A5A3C(char *obj);

static inline void creatureResetTimer(char *obj)
{
    *(s16 *)(obj + 0x50) = 1;
    *(f32 *)(obj + 0x24) = 0.0f;
    *(f32 *)(obj + 0x28) = (f32)fn_800B9ED4() * 1.5259022e-05f * 7.0f + 8.0f;
    *(f32 *)(obj + 0x20) = 0.0f;
}

void fn_800A5C64(char *obj)
{
    f32 dt;
    f32 a;
    f32 b;
    f32 lim;

    if (*(s32 *)(obj + 0x60) != 0) {
        if (*(s16 *)(obj + 0x4E) == 1) {
            dt = lbl_80408E9C;
            a = *(f32 *)(obj + 0x20);
            b = *(f32 *)(obj + 0x24);
            lim = *(f32 *)(obj + 0x28);
            a += dt;
            b += dt;
            *(f32 *)(obj + 0x20) = a;
            *(f32 *)(obj + 0x24) = b;
            if (b >= lim) {
                if (*(s16 *)(obj + 0x50) == 1) {
                    fn_800A5A3C(obj);
                } else {
                    creatureResetTimer(obj);
                }
            }
            *(s16 *)(obj + 0x4E) = *(s16 *)(obj + 0x50);
        } else {
            creatureResetTimer(obj);
        }
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

struct creature_vec_s {
    f32 x, y, z;
};
void NuVecRotateX(struct creature_vec_s *dst, struct creature_vec_s *src, u16 a);
void NuVecRotateY(struct creature_vec_s *dst, struct creature_vec_s *src, u16 a);

void CurrentStart(char *obj, s32 force, s32 tilt)
{
    struct creature_vec_s v;
    s32 *tbl;
    s8 idx;

    *(f32 *)(*(char **)(obj + 0xEEC) + 0x730) = 0.0f;
    idx = *(s8 *)(obj + 0x601);
    if (idx != -1) {
        tbl = *(s32 **)((char *)lbl_80409410 + 0x2DC);
        if (tbl != NULL && *(f32 *)(*tbl + idx * 0x104 + 0x6C) != 0.0f
            && (force != 0 || *(s8 *)(*(char **)(obj + 0xEEC) + 0x7E5) == 1
                || *(s8 *)(*(char **)(obj + 0xEEC) + 0x7E5) == 4)) {
            *(f32 *)(*(char **)(obj + 0xEEC) + 0x730) =
                *(f32 *)(**(s32 **)((char *)lbl_80409410 + 0x2DC) + *(s8 *)(obj + 0x601) * 0x104 + 0x6C);
            v.x = v.y = 0.0f;
            if (*(u32 *)(obj + 0xF24) & 0x400) {
                v.z = *(f32 *)(*(char **)(obj + 0xEEC) + 0x730) * *(f32 *)(obj + 0xF04);
            } else {
                v.z = *(f32 *)(*(char **)(obj + 0xEEC) + 0x730) * *(f32 *)(*(char **)(obj + 0xEEC) + 0x708);
            }
            if (tilt != 0) {
                NuVecRotateX((struct creature_vec_s *)(obj + 0x78), &v, *(u16 *)(obj + 0x624));
                NuVecRotateY((struct creature_vec_s *)(obj + 0x78), (struct creature_vec_s *)(obj + 0x78), *(u16 *)(obj + 0x626));
            } else {
                NuVecRotateY((struct creature_vec_s *)(obj + 0x78), (struct creature_vec_s *)(obj + 0x78), *(u16 *)(obj + 0x27E));
            }
            *(struct creature_vec_s *)(obj + 0xF3C) = *(struct creature_vec_s *)(obj + 0x78);
            *(u32 *)(obj + 0x440) &= ~0x1000;
        }
    }
}
