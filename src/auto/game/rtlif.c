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
