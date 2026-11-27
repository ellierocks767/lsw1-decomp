#include "types.h"


s32 fn_8013F540(void)
{
    return 16384;
}

s32 fn_80063E40(s32, void *, s32, s32, s32);
s32 fn_800957E0(f32, f32);
extern f32 lbl_80408E9C;
extern void *lbl_80409410;
extern f32 lbl_80409A30;

struct RtlV { f32 x, y, z; };
void NuMtxTranslate(void *, struct RtlV *);
void fn_8000DDD0(void *, u16);
void fn_8000EFE0(void *, void *, s32 *);
extern f32 lbl_801AEE18[];
extern s32 lbl_803E0158[];

void fn_8013F304(void *arg0) {
    struct RtlV v;
    s32 a;
    s32 b;
    v = *(struct RtlV *)((s8 *)arg0 + 0x30);
    b = *(u16 *)((s8 *)arg0 + 0x11E);
    a = lbl_80408E9C * lbl_801AEE18[0] + (f32)b;
    *(u16 *)((s8 *)arg0 + 0x11E) = a;
    fn_8000DDD0(arg0, (u16)a);
    if (*(s32 *)((s8 *)lbl_80409410 + 0x19C) == 0xD) {
        fn_8000EFE0(arg0, arg0, lbl_803E0158);
    }
    NuMtxTranslate(arg0, &v);
}

f32 NuSinApprox(s32);
void NuVecAdd(struct RtlV *, void *, void *);
extern f32 lbl_801AEE1C[];
extern f32 lbl_801AEE20[];
extern f32 lbl_80409A10;
extern f32 lbl_80409A14;
extern f32 lbl_80409A18;

void fn_8013F3D0(void *arg0) {
    struct RtlV v;
    f32 t;
    f32 k;
    s32 ang;
    s8 *p = *(s8 **)((s8 *)arg0 + 0xD8);
    t = lbl_801AEE1C[0] - (*(f32 *)((s8 *)arg0 + 0x100) / lbl_80409A10);
    if (*(s32 *)((s8 *)lbl_80409410 + 0x19C) == 3) {
        NuVecAdd(&v, p + 0x90, (s8 *)arg0 + 0xC8);
        k = lbl_80409A14;
    } else {
        v = *(struct RtlV *)((s8 *)arg0 + 0xC8);
        k = lbl_80409A18;
    }
    ang = (s32)(t * lbl_801AEE20[0]);
    *(f32 *)((s8 *)arg0 + 0x30) = (*(f32 *)(p + 0x90) - v.x) * t + v.x;
    *(f32 *)((s8 *)arg0 + 0x34) = NuSinApprox(ang) * k + ((*(f32 *)(p + 0x94) - v.y) * t + v.y);
    *(f32 *)((s8 *)arg0 + 0x38) = (*(f32 *)(p + 0x98) - v.z) * t + v.z;
}

void fn_8013F4CC(void *arg0) {
    s32 temp_r31;
    s32 temp_r3;

    if ((*(s32 *)((s8 *)(arg0) + (0x128))) & 0x400000) {
        temp_r31 = (*(s32 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1B8)))) + (8)))) + (0x474)));
        if (temp_r31 != -1) {
            temp_r3 = fn_800957E0(lbl_80409A30, lbl_80408E9C);
            if (temp_r3 > 0) {
                fn_80063E40(temp_r31, arg0 + 0x30, temp_r3, 0, 0);
            }
        }
    }
}

f32 NuFmod(f32, f32);
s32 fn_8002D9E8(void *, void *, void *, void *, void *, void *);
s32 fn_8002DAD0(void *);
s32 fn_8013FBB4(void);
extern f32 lbl_801AEEC8[];
extern f32 lbl_801AEECC[];
extern f32 lbl_801AEED0[];
extern f32 lbl_801AEED4[];
extern f32 lbl_801AEED8[];
extern f32 lbl_801AEEDC[];
extern f32 lbl_801AEEE0[];
extern f32 lbl_801AEEE4[];
extern f32 lbl_801AEEE8[];
extern f32 lbl_801AEEEC[];
extern f32 lbl_801AEEF0[];
extern f32 lbl_801AEEF4[];
extern f32 lbl_801AEEF8[];
extern f32 lbl_801AEEFC[];
extern u8 lbl_801D59A6[];
extern f32 lbl_80409440;
extern f32 lbl_80409A48;
extern f32 lbl_80409A4C;
extern f32 lbl_80409A50;

void SetCreatureLights(void **arg0) {
    struct RtlV amb;
    struct RtlV dir[3];
    struct RtlV col[4];
    f32 var_f31, var_f29, var_f28;
    f32 temp_f0, temp_f11, temp_f1, temp_f30, temp_f1_2, temp_f13, temp_f1_3, temp_f13_2, var_f11, temp_f13_3, temp_f0_2, var_f11_2;
    s8 *c = *arg0;
    s8 *o;

    if (lbl_801D59A6[0] != 0) {
        fn_8013FBB4();
        return;
    }
    if (*(u8 *)(c + 0x28F) != 0) {
        fn_8002D9E8(c + 0x504, c + 0x4E0, c + 0x510, c + 0x4EC, c + 0x51C, c + 0x4F8);
        fn_8002DAD0(c + 0x528);
        return;
    }
    amb = *(struct RtlV *)(c + 0x5AC);
    col[0] = *(struct RtlV *)(c + 0x5B8);
    dir[0] = *(struct RtlV *)(c + 0x5DC);
    col[1] = *(struct RtlV *)(c + 0x5C4);
    dir[1] = *(struct RtlV *)(c + 0x5E8);
    col[2] = *(struct RtlV *)(c + 0x5D0);
    var_f31 = lbl_801AEEC8[0];
    var_f29 = var_f31;
    var_f28 = var_f31;
    dir[2] = *(struct RtlV *)(c + 0x5F4);
    temp_f0 = *(f32 *)(c + 0x1044);
    if (temp_f0 > lbl_801AEECC[0]) {
        temp_f11 = temp_f0 / lbl_801AEED0[0];
        var_f28 = (lbl_80409A48 - var_f31) * temp_f11 + var_f31;
        var_f29 = (lbl_80409A4C - var_f31) * temp_f11 + var_f31;
        var_f31 += (lbl_80409A50 - var_f31) * temp_f11;
    } else if ((*(s32 *)(c + 0x20C) & 0x01000000) && (temp_f1 = *(f32 *)(*(s8 **)(c + 0xEEC) + 0x6F8), temp_f1 > lbl_801AEECC[0]) && ((temp_f30 = lbl_801AEED4[0], temp_f1 >= temp_f30) || (temp_f1_2 = NuFmod(temp_f1, lbl_801AEED0[0]), temp_f1_2 >= lbl_801AEED8[0]))) {
        if (*(u8 *)(c + 0x284) == 1) {
            var_f28 = lbl_801AEEDC[0];
            var_f29 = temp_f30;
            var_f31 = lbl_801AEEE0[0];
        } else {
            var_f28 = lbl_801AEEE0[0];
            var_f31 = temp_f30;
            var_f29 = lbl_801AEEE4[0];
        }
    } else {
        temp_f13 = *(f32 *)(c + 0x102C);
        if (temp_f13 > lbl_801AEECC[0] && *(s8 *)(c + 0x284) != -1) {
            temp_f1_3 = 2.0f * NuFmod(lbl_80409440 - temp_f13, lbl_801AEEE8[0]) * lbl_801AEEEC[0];
            var_f31 = NuSinApprox((u16)(s32)temp_f1_3) + lbl_801AEEC8[0];
            var_f29 = var_f31;
            var_f28 = var_f31;
        }
        o = *(s8 **)(c + 0xEEC);
        temp_f13_2 = *(f32 *)(o + 0x70C);
        if (temp_f13_2 > lbl_801AEECC[0]) {
            if (temp_f13_2 >= lbl_801AEEC8[0]) {
                var_f11 = lbl_801AEEF0[0];
            } else {
                var_f11 = lbl_801AEEC8[0] - temp_f13_2 * lbl_801AEEF4[0];
            }
            if (var_f11 != lbl_801AEEC8[0]) {
                var_f29 = var_f31 * var_f11;
                var_f28 = var_f29;
                var_f31 = var_f29;
            }
        }
        temp_f13_3 = *(f32 *)(o + 0x710);
        if (temp_f13_3 > lbl_801AEECC[0]) {
            temp_f0_2 = *(f32 *)(o + 0x70C);
            if (temp_f0_2 >= lbl_801AEEC8[0]) {
                var_f11_2 = lbl_801AEEF8[0];
            } else {
                var_f11_2 = lbl_801AEEC8[0] - temp_f13_3 * lbl_801AEEFC[0];
            }
            if (var_f11_2 != lbl_801AEEC8[0]) {
                var_f31 *= var_f11_2;
                var_f28 *= var_f11_2;
                var_f29 *= var_f11_2;
            }
        }
    }
    if (var_f28 != lbl_801AEEC8[0]) {
        amb.x *= var_f28;
        col[0].x *= var_f28;
        col[1].x *= var_f28;
        col[2].x *= var_f28;
    }
    if (var_f29 != lbl_801AEEC8[0]) {
        amb.y *= var_f29;
        col[0].y *= var_f29;
        col[1].y *= var_f29;
        col[2].y *= var_f29;
    }
    if (var_f31 != lbl_801AEEC8[0]) {
        amb.z *= var_f31;
        col[0].z *= var_f31;
        col[1].z *= var_f31;
        col[2].z *= var_f31;
    }
    if (*(s16 *)(c + 0x1074) == 0x24) {
        col[2].z = lbl_801AEECC[0];
        col[1].x = lbl_801AEECC[0];
        col[1].y = lbl_801AEECC[0];
        col[1].z = lbl_801AEECC[0];
        col[2].x = lbl_801AEECC[0];
        col[2].y = lbl_801AEECC[0];
    }
    fn_8002D9E8(&dir[0], &col[0], &dir[1], &col[1], &dir[2], &col[2]);
    fn_8002DAD0(&amb);
}

int sprintf(char *, const char *, ...);
s32 fn_800701F8(char *, void *, u32 *);
void (*fn_80009948(const char *, s32))(void *, ...);
extern char str_Extension_Rtl[];
extern char str_SourceFile_RtlIf[];
extern s32 lbl_801AEF1C[];

void LoadLights(void *arg0) {
    char name[256];
    u32 n;
    sprintf(name, str_Extension_Rtl, (s8 *)arg0 + 0x80);
    n = *(u32 *)((s8 *)arg0 + 0x188);
    *(s32 *)((s8 *)arg0 + 0x760) = fn_800701F8(name, (s8 *)arg0 + 0x184, &n);
    if (*(u32 *)((s8 *)arg0 + 0x184) >= *(u32 *)((s8 *)arg0 + 0x188)) {
        fn_80009948(str_SourceFile_RtlIf, 0x18F)(lbl_801AEF1C);
    }
}
