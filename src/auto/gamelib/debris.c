#include "types.h"
#include "numath/numath.h"

extern u8 lbl_802B1504[];
extern f32 lbl_80195760[];
extern f32 lbl_80195764[];
extern f32 lbl_80195768[];
extern f32 lbl_804083AC;
extern f32 lbl_804083C8;
extern s32 lbl_804083DC;
extern s32 lbl_8040840C;
extern s32 lbl_80408410;
extern s32 lbl_8040A5D0;
extern f32 lbl_8040A600;
extern s32 lbl_8040AE4C;

void fn_8005A42C(s32 a)
{
    lbl_8040AE4C = a;
}

s32 fn_8005A434(void)
{
    return lbl_8040AE4C;
}

s32 fn_8005A82C(void)
{
    return lbl_8040A5D0;
}

void fn_8005A8D4(f32 x)
{
    lbl_8040A600 = x;
}

void fn_8005A8DC(f32 x)
{
    lbl_804083AC = x;
}

void fn_8006497C(s32 a)
{
    lbl_8040840C = a;
}

void fn_800649FC(f32 x)
{
    lbl_804083C8 = x;
}

void fn_80064A50(s32 a)
{
    lbl_804083DC = a;
}

void fn_80064BEC(s32 a)
{
    lbl_80408410 = a;
}

void fn_8005A834(u8* a)
{
    a[0] = lbl_802B1504[96];
    a[1] = lbl_802B1504[97];
    a[2] = lbl_802B1504[98];
    a[3] = lbl_802B1504[99];
}

void GenDebMomAdjFromPosAll(s32 a, s32 b, f32* c)
{
    f32 k = lbl_80195760[0];
    c[4] = c[0] * k;
    c[5] = c[1] * k;
    c[6] = c[2] * k;
}

void GenDebMomAdjFromSplash(s32 a, s32 b, f32* c)
{
    f32 k = lbl_80195764[0];
    c[4] = c[0] * k;
    c[6] = c[2] * k;
}

void GenDebMomAdjFromAshRock(s32 a, s32 b, f32* c)
{
    f32 k = lbl_80195768[0];
    c[4] = c[0] * k;
    c[6] = c[2] * k;
}

void AddChunkControlToStack(void *arg0, void **arg1) {
    s32 temp_r0;
    void **var_r4;
    void *temp_r9;

    var_r4 = arg1;
    if ((void *) *var_r4 != NULL) {
        do {
            temp_r9 = *var_r4;
            temp_r0 = (*(s32 *)((s8 *)(temp_r9) + (0x10)));
            var_r4 = temp_r9 + 0x10;
        } while (temp_r0 != 0);
    }
    *var_r4 = arg0;
    (*(s32 *)((s8 *)(arg0) + (0x10))) = 0;
}

void FullReflect(void *arg0, void *arg1, void *arg2) {
    f32 temp_f13;
    f32 temp_f8;
    f32 temp_f9;

    temp_f8 = (*(f32 *)((s8 *)(arg1) + (0)));
    temp_f13 = (*(f32 *)((s8 *)(arg0) + (0)));
    temp_f9 = ((*(f32 *)((s8 *)(arg0) + (8))) * -(*(f32 *)((s8 *)(arg1) + (8)))) + ((temp_f13 * -temp_f8) + ((*(f32 *)((s8 *)(arg0) + (4))) * -(*(f32 *)((s8 *)(arg1) + (4)))));
    (*(f32 *)((s8 *)(arg2) + (0))) = (f32) ((2.0f * (temp_f13 * temp_f9)) + temp_f8);
    (*(f32 *)((s8 *)(arg2) + (4))) = (f32) ((2.0f * ((*(f32 *)((s8 *)(arg0) + (4))) * temp_f9)) + (*(f32 *)((s8 *)(arg1) + (4))));
    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) ((2.0f * ((*(f32 *)((s8 *)(arg0) + (8))) * temp_f9)) + (*(f32 *)((s8 *)(arg1) + (8))));
}

void fn_8005A6C4(s32 arg0, s32 arg1) {
    if ((arg0 >= 0) && (arg0 < (s32) (*(s32 *)((s8 *)(lbl_8040AE4C) + (0xA59C))))) {
        (*(s32 *)((s8 *)(((arg0 * 0x6C) + (*(s32 *)((s8 *)(lbl_8040AE4C) + (0x68))))) + (0x40))) = arg1;
    }
}

void fn_8005A7F8(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_r11;

    if (arg0 >= 0) {
        temp_r11 = arg0 * 0x6C;
        *arg1 = (*(s32 *)((s8 *)(lbl_8040AE4C) + (0x68))) + temp_r11;
        *arg2 = (*(s32 *)((s8 *)((temp_r11 + (*(s32 *)((s8 *)(lbl_8040AE4C) + (0x68))))) + (0x40)));
    }
}

extern s32 lbl_80408404;

void fn_80063D78(s32 *arg0) {
    s32 temp_r3;

    temp_r3 = *arg0;
    if (temp_r3 != -1) {
        (*(s8 *)((s8 *)(((temp_r3 * 0x2EC) + lbl_80408404)) + (0x274))) = 0;
    }
}

void fn_8005EF6C(s32, f32);
extern s32 lbl_80408404;

void fn_80064888(s32 arg0, f32 farg0) {
    fn_8005EF6C(lbl_80408404 + (arg0 * 0x2EC), farg0);
}

extern s32 lbl_80408404;

void fn_800648D8(s32 arg0, s16 arg1) {
    if (arg0 != -1) {
        (*(s16 *)((s8 *)(((arg0 * 0x2EC) + lbl_80408404)) + (0x270))) = arg1;
    }
}

void *fn_8005A8E4(void *, void *, f32);

void fn_80064CD4(void *a, void *b, f32 c) {
    fn_8005A8E4(a, b, c);
}

s32 NuScratchAlloc32(s32);
s32 NuScratchRelease();
extern s32 lbl_8040A588;
extern s32 lbl_8040A5A4;
extern s32 lbl_8040A5C4;
extern s32 lbl_8040A5E4;
extern s32 lbl_8040A5E8;
extern s32 lbl_8040AE4C;
extern s32 lbl_8040AE5C;

void fn_8005A560(void)
{
  int new_var;
 do { lbl_8040A5E4 = 0; new_var = 0; lbl_8040A588 = new_var; lbl_8040A5E8 = new_var; lbl_8040A5A4 = 0; lbl_8040AE5C = NuScratchAlloc32(0x948); NuScratchRelease(); } while (0);
  lbl_8040A5C4 = new_var;
  lbl_8040AE4C = 0;
}

void fn_80064C54(void *arg0, void **arg1)
{
  void *temp_r9;
  void *temp_r9_2;
  void *temp_r11;
  temp_r11 = *((void **) (((s8 *) arg0) + 0x14C));
  if (temp_r11 == ((void *) 0))
  {
    temp_r9 = *((void **) (((s8 *) arg0) + 0x148));
    *arg1 = temp_r9;
    if (temp_r9 != ((void *) 0))
    {
      *((void **) (((s8 *) temp_r9) + 0x14C)) = temp_r11;
    }
  }
  else
  {
    *((void **) (((s8 *) temp_r11) + 0x148)) = (void *) (*((void **) (((s8 *) arg0) + 0x148)));
    temp_r9_2 = *((void **) (((s8 *) arg0) + 0x148));
    if (temp_r9_2 != ((void *) 0))
    {
      *((void **) (((s8 *) temp_r9_2) + 0x14C)) = (void *) (*((void **) (((s8 *) arg0) + 0x14C)));
    }
  }
  *((void **) (((s8 *) arg0) + 0x14C)) = (void *) 0;
  *((void **) (((s8 *) arg0) + 0x148)) = (void *) 0;
}

extern f32 lbl_80195740[];
extern s32 lbl_80408404;

void fn_80064830(s32 arg0, f32 farg0, f32 farg1, f32 farg2)
{
  void *temp_r11;
  if (arg0 != (-1))
  {
 do { temp_r11 = (arg0 * 0x2EC) + lbl_80408404; *((f32 *) (((s8 *) temp_r11) + 0x280)) = (f32) lbl_80195740[0]; *((f32 *) (((s8 *) temp_r11) + 0x110)) = farg0; } while (0);
    *((f32 *) (((s8 *) temp_r11) + 0x114)) = farg1;
    *((f32 *) (((s8 *) temp_r11) + 0x118)) = farg2;
  }
}

void GenDebMomAdjFromPos(s32 pad0, s32 pad1, void *arg2) {
    (*(f32 *)((s8 *)(arg2) + (0x10))) = (f32) (2.0f * (*(f32 *)((s8 *)(arg2) + (0))));
    (*(f32 *)((s8 *)(arg2) + (0x18))) = (f32) (2.0f * (*(f32 *)((s8 *)(arg2) + (8))));
}

void GenDebMomAdjFromPosRev(s32 pad0, s32 pad1, void *arg2) {
    (*(f32 *)((s8 *)(arg2) + (0x10))) = (f32) -(*(f32 *)((s8 *)(arg2) + (0)));
    (*(f32 *)((s8 *)(arg2) + (0x18))) = (f32) -(*(f32 *)((s8 *)(arg2) + (8)));
}

s32 fn_80027510(s32, s32, s32);
s32 fn_800275E0(s32);
s32 fn_80043F9C(s32);
s32 fn_80060F58(s32, s32);
extern s32 lbl_80408428;
extern s32 lbl_8040AE94;

void fn_80064984(void) {
    s32 saved_reg_r31;
    s32 var_r9;

    if ((s32) lbl_80408428 != 0) {
        fn_80027510(-1, -2, 1);
        var_r9 = 0;
        if ((s32) lbl_8040AE94 > 0) {
            var_r9 = 1;
        }
        if (var_r9 != 0) {
            fn_80060F58(0, 2);
        }
        fn_80043F9C(saved_reg_r31);
        fn_800275E0(0);
    }
}

extern s16 lbl_8040A5D4;
#define lbl_8040AE4C (*(s32 *(*))&lbl_8040AE4C)

s16 fn_8005A43C(void) {
    void *temp_r11;

    if ((s16) lbl_8040A5D4 != -1) {
        temp_r11 = (lbl_8040A5D4 * 0x38) + *lbl_8040AE4C;
        if ((s32) (*(s32 *)((s8 *)(temp_r11) + (0x2C))) == 1) {
            return (*(s16 *)((s8 *)(temp_r11) + (0x30)));
        }
    }
    return -1;
}
#undef lbl_8040AE4C

void fn_8005FF74(s32, void *, s32, s16, s16, void *);

void fn_80063E40(s32 arg0, void *arg1, s32 arg2, s16 arg3, s16 arg4) {
    fn_8005FF74(arg0, arg1, arg2, arg3, arg4, 0);
}

s32 fn_800631DC(void *, s8, s32);

void fn_80064A04(void *arg0, s8 arg1) {
    fn_800631DC(arg0, arg1, 0);
}

s32 fn_800631DC(void *, s8, s32);

s32 fn_80064A28(void *arg0) {
    return fn_800631DC(arg0, 0, 0);
}

s32 fn_8005F114(void *, s32, void *, void *, void *, s32);

void fn_80063E14(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    fn_8005F114(arg0, arg1, arg2, 0, 0, arg3);
}

s32 TerrainInitEx(s32, void *, void *, s32, void *, void *, s32, s32, s32, s32);

void fn_8005A3F8(s32 arg0, void *arg1, void *arg2, s32 arg3, void *arg4, void *arg5, s32 arg6) {
    s32 sp8;
    s32 spC;

    TerrainInitEx(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 0x1000, 0xC00, 0x100);
}

void fn_80064860(s32 arg0, s16 arg1, s16 arg2, f32 farg0, f32 farg1) {
    void *temp_r9;

    if (arg0 != -1) {
        temp_r9 = (arg0 * 0x2EC) + lbl_80408404;
        (*(s16 *)((s8 *)(temp_r9) + (0x25C))) = arg1;
        (*(s16 *)((s8 *)(temp_r9) + (0x25E))) = arg2;
        (*(f32 *)((s8 *)(temp_r9) + (0x260))) = farg0;
        (*(f32 *)((s8 *)(temp_r9) + (0x264))) = farg1;
    }
}

void fn_800648B4(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    void *temp_r9;

    if (arg0 != -1) {
        temp_r9 = (arg0 * 0x2EC) + lbl_80408404;
        (*(s32 *)((s8 *)(temp_r9) + (0x250))) = arg1;
        (*(s32 *)((s8 *)(temp_r9) + (0x254))) = arg2;
        (*(f32 *)((s8 *)(temp_r9) + (0x258))) = farg0;
    }
}

struct DebBits_8005A6F4 { u32 flag : 1; u32 rest : 31; };

void fn_8005A6F4(s32 arg0, s32 arg1) {
    if ((arg0 >= 0) && (arg0 < (*(s32 *)((s8 *)(lbl_8040AE4C) + (0xA59C))))) {
        ((struct DebBits_8005A6F4 *)((s8 *)((arg0 * 0x6C) + (*(s32 *)((s8 *)(lbl_8040AE4C) + (0x68)))) + 0x4C))->flag = arg1;
    }
}

extern s32 lbl_804083F0;
s32 fn_8005EB80(s32 *);
void fn_80063D9C(void) {
    s32 sp8;
    s32 i;

    for (i = 0; i < lbl_804083F0; i++) {
        s8 *p = (s8 *)(i * 0x2EC + lbl_80408404);
        if (*(s16 *)(p + 0x102) != 0 && *(u8 *)(p + 0x279) != 0) {
            sp8 = i;
            fn_8005EB80(&sp8);
        }
    }
}

extern const f32 lbl_80195420[];

void fn_8005A72C(s32 arg0, f32 farg0, f32 farg1, f32 farg2) {
    if (arg0 >= 0 && arg0 < *(s32 *)((s8 *)lbl_8040AE4C + 0xA59C)) {
        s8 *g = (s8 *)lbl_8040AE4C;
        if (*(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x54) == lbl_80195420[0]) {
            *(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x58) = lbl_80195420[0];
            *(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x5C) = lbl_80195420[0];
        }
        g = (s8 *)lbl_8040AE4C;
        *(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x54) = farg0;
        *(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x60) = farg1;
        *(f32 *)(arg0 * 0x6C + *(s8 **)(g + 0x68) + 0x64) = farg2;
    }
}

s32 NuAnimCurveSetApplyToJointBasic(s32, s32, f32, f32, s32);
extern s32 lbl_8040AEA0;
extern s32 lbl_8040AEA4;

s32 fn_80064A94(s32 arg0, f32 farg0, f32 farg1) {
    s32 var_r30;
    s32 var_r31;

    var_r30 = 0;
    if (var_r30 < (s32) lbl_8040AEA4) {
        var_r31 = 0;
loop_2:
        if (((*(s32 *)((s8 *)((var_r31 + lbl_8040AEA0)) + (4))) & 3) && (NuAnimCurveSetApplyToJointBasic(*(s32 *)(var_r31 + lbl_8040AEA0), arg0, farg0, farg1, 3) != 0)) {
            return *(s32 *)(var_r31 + lbl_8040AEA0);
        }
        var_r30 += 1;
        var_r31 += 8;
        if (var_r30 >= (s32) lbl_8040AEA4) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return -1;
}

s32 fn_80063834(s32, void *, f32, f32, u8);
extern s32 lbl_8040AE9C;
extern s32 lbl_8040AEA8;

s32 fn_80064B40(s32 arg0, f32 farg0, f32 farg1) {
    s32 var_r30;
    s32 var_r31;

    var_r30 = 0;
    if (var_r30 < (s32) lbl_8040AEA8) {
        var_r31 = 0;
loop_2:
        if (((*(s32 *)((s8 *)((var_r31 + lbl_8040AE9C)) + (4))) & 3) && (fn_80063834(*(s32 *)(var_r31 + lbl_8040AE9C), arg0, farg0, farg1, 3) != 0)) {
            return *(s32 *)(var_r31 + lbl_8040AE9C);
        }
        var_r30 += 1;
        var_r31 += 8;
        if (var_r30 >= (s32) lbl_8040AEA8) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return -1;
}

s32 fn_80027348();
s32 fn_8005F254(s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern f32 lbl_8019570C[];
extern f32 lbl_80195710[];
extern s32 lbl_804083FC;

void fn_80063F80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_r31;
    u8 temp_r0;
    void *temp_r9;

    if ((arg0 >= 0) && (temp_r9 = *(s32 *)((arg0 * 4) + lbl_804083FC), ((temp_r9 == NULL) == 0))) {
        temp_r0 = (*(u8 *)((s8 *)(temp_r9) + (0x2E)));
        switch ((s8) temp_r0) {                     /* irregular */
        case 2:
            var_r31 = 0xC350;
            break;
        case 3:
            var_r31 = 0x9C40;
            break;
        case 7:
            var_r31 = 0x4E20;
            break;
        case 0:
        default:
            var_r31 = 0x7530;
            break;
        }
        if (fn_80027348() == 0) {
            fn_8005F254(arg0, arg1, arg2, arg3 * 0x32, arg4, arg5, var_r31, 0, lbl_8019570C[0]);
            return;
        }
        fn_8005F254(arg0, arg1, arg2, arg3 * 0x3C, arg4, arg5, var_r31, 0, lbl_80195710[0]);
    }
}

extern s32 lbl_8040A5AC;

s32 fn_8005A5C8(void) {
    if (lbl_8040A5AC != NULL) {
        return *(u8 *)((s8 *)lbl_8040A5AC + 0x60);
    }
    return -1;
}

extern s32 lbl_8040A5A8;

s32 fn_8005A5E0(void) {
    if (lbl_8040A5A8 != NULL) {
        return *(u8 *)((s8 *)lbl_8040A5A8 + 0x61);
    }
    return -1;
}

s32 fn_8005A5B0(void) {
    if (lbl_8040A5A4 != NULL) {
        return *(u8 *)((s8 *)lbl_8040A5A4 + 0x60);
    }
    return -1;
}

s32 fn_8005A5F8(s32 arg0) {
    s32 i;
    s32 r;
    s8 *g;
    s8 *p;

    if (arg0 == -1) {
        return -1;
    }
    r = -1;
    i = 0;
    g = (s8 *)lbl_8040AE4C;
    goto check;
next:
    i++;
check:
    if (i < *(s32 *)(g + 0xA59C)) {
        p = (s8 *)(i * 0x6C + *(s32 *)(g + 0x68));
        if (*(s32 *)(p + 0x40) == 0 || *(s16 *)(p + 0x4A) != arg0) {
            goto next;
        }
        r = i;
    }
    return r;
}

extern f32 lbl_80195744[];

extern s32 rand(void);
extern const f32 lbl_8019576C[];
extern const f32 lbl_80195770[];
extern const f32 lbl_80195780[];
extern const f32 lbl_80195784[];

struct deb_lifetime_params {
    u8 unk00[0xA4];
    f32 lifetime;
};

struct deb_particle_motion {
    struct nuvec_s position;
    f32 unk0C;
    struct nuvec_s momentum;
    f32 inverseLifetime;
};

void GenDebMomAdjFromPosRevTree(void *key, struct deb_lifetime_params *effect,
                               struct deb_particle_motion *particle)
{
    f32 x;
    f32 z;
    f32 distance;
    f32 random;
    f32 lifetime;

    x = particle->position.x;
    particle->momentum.x += x * lbl_8019576C[0];
    z = particle->position.z;
    particle->momentum.z += z * lbl_8019576C[0];
    distance = NuFsqrt(x * x + z * z);
    particle->position.y -= distance * lbl_80195770[0];
    random = (f32)rand();
    lifetime = effect->lifetime;
    particle->inverseLifetime = lbl_80195784[0] / (lifetime + lifetime * random / lbl_80195780[0]);
}

f32 fn_80064A58(struct nuvec_s *arg0) {
    f32 d;

    if (lbl_804083DC != 0) {
        d = NuVecDist(arg0, (struct nuvec_s *)lbl_804083DC, NULL);
    } else {
        d = lbl_80195744[0];
    }
    return d;
}

s32 NuPortalWhichRoom(s32, s32);

void fn_800648F4(s32 arg0, s32 arg1) {
    s32 room;
    s32 off;
    s8 *p;
    s8 *q;

    if (arg1 != 0) {
        off = arg0 * 0x2EC;
        room = NuPortalWhichRoom(arg1, lbl_80408404 + off + 0x110);
        p = (s8 *)(off + lbl_80408404);
        *(s16 *)(p + 0x272) = room;
        if ((s16)room == -1) {
            *(s32 *)(p + 0x27C) = 0;
            return;
        }
        *(s32 *)(p + 0x27C) = arg1;
        return;
    }
    q = (s8 *)(arg0 * 0x2EC + lbl_80408404);
    *(s16 *)(q + 0x272) = -1;
    *(s32 *)(q + 0x27C) = arg1;
}

extern f32 lbl_80195700[];
extern f32 lbl_80195704[];
extern f32 lbl_80195708[];

void fn_80063E64(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 v[3];
    f32 *pv;
    s32 var_r31;
    u8 temp_r0;
    void *temp_r9;

    pv = v;
    v[2] = lbl_80195700[0];
    v[1] = lbl_80195700[0];
    v[0] = lbl_80195700[0];
    if ((arg0 >= 0) && (temp_r9 = *(s32 *)((arg0 * 4) + lbl_804083FC), ((temp_r9 == NULL) == 0))) {
        temp_r0 = (*(u8 *)((s8 *)(temp_r9) + (0x2E)));
        switch ((s8) temp_r0) {
        case 2:
            var_r31 = 0xC350;
            break;
        case 3:
            var_r31 = 0x9C40;
            break;
        case 7:
            var_r31 = 0x4E20;
            break;
        case 0:
        default:
            var_r31 = 0x7530;
            break;
        }
        if (fn_80027348() == 0) {
            fn_8005F254(arg0, arg1, (s32)pv, arg2 * 0x32, arg3, arg4, var_r31, 0, lbl_80195704[0]);
            return;
        }
        fn_8005F254(arg0, arg1, (s32)pv, arg2 * 0x3C, arg3, arg4, var_r31, 0, lbl_80195708[0]);
    }
}

extern const f32 lbl_80195724[];

struct deb_effect_kind {
    u8 unk00[0x2E];
    s8 kind;
};

void fn_8006436C(s32 effect, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 value)
{
    struct nuvec_s offset;
    struct nuvec_s *offsetPtr = &offset;
    struct deb_effect_kind *definition;
    s32 amount;

    offset.z = lbl_80195724[0];
    offset.y = lbl_80195724[0];
    offset.x = lbl_80195724[0];
    if (effect >= 0 && (definition = ((struct deb_effect_kind **)lbl_804083FC)[effect]) != NULL) {
        switch (definition->kind) {
        case 2:
            amount = 50000;
            break;
        case 3:
            amount = 40000;
            break;
        case 7:
            amount = 20000;
            break;
        case 0:
        default:
            amount = 30000;
            break;
        }
        fn_8005F254(effect, arg1, (s32)offsetPtr, arg2, arg3, arg4, amount, 0, value);
    }
}

s32 fn_8005DA6C(void *);

void fn_80064424(s8 *arg0, s32 arg1) {
    s8 *t;

    t = *(s8 **)(*(s16 *)(arg0 + 0x102) * 4 + lbl_804083FC);
    *(u16 *)(arg0 + 0x10E) = arg1;
    if (*(u8 *)(t + 0x2E) == 7) {
        *(s16 *)(arg0 + 0x10C) = (arg1 + 0xB) / 12;
    } else {
        *(s16 *)(arg0 + 0x10C) = (arg1 + 0x1F) / 32;
    }
    if (*(s16 *)(arg0 + 0x10C) > 0x20) {
        *(s16 *)(arg0 + 0x10C) = 0x20;
        if (*(u8 *)(t + 0x2E) == 7) {
            *(u16 *)(arg0 + 0x10E) = 0x180;
        } else {
            *(u16 *)(arg0 + 0x10E) = 0x400;
        }
    }
    if (*(s16 *)(arg0 + 0x10C) == *(s16 *)(arg0 + 0x100)) {
        *(u16 *)(arg0 + 0x106) = *(u16 *)(arg0 + 0x10E);
    } else {
        fn_8005DA6C(arg0);
    }
}

extern s32 lbl_8038E714[];
void **fn_80064BF4(s32 arg0) {
    s32 i;
    void **pp;

    for (i = 0; i < 32; i++) {
        pp = (void **)&lbl_8038E714[i];
        while (*pp != NULL) {
            if ((s32)*pp == arg0) {
                return (void **)&lbl_8038E714[i];
            }
            pp = (void **)((s8 *)*pp + 0x148);
        }
    }
    return NULL;
}

extern s32 lbl_8040A5C8;
struct V3_8005A7A4 { s32 x, y, z; };
extern struct V3_8005A7A4 lbl_802B1568;
extern u8 lbl_802B1574[];

s32 fn_8005A7A4(struct V3_8005A7A4 *arg0, s32 *arg1, s32 *arg2) {
    s32 r;

    if (lbl_8040A5C8 != -1) {
        *arg0 = lbl_802B1568;
        *arg1 = lbl_802B1574[0x60];
        *arg2 = lbl_802B1574[0x61];
    }
    r = lbl_8040A5C8;
    lbl_8040A5C8 = -1;
    return r;
}

void fn_8005A65C(s32 arg0, s32 arg1) {
    s8 *g;

    g = (s8 *)lbl_8040AE4C;
    if (g != NULL && arg0 >= 0 && arg0 < *(s32 *)(g + 0xA59C)) {
        if (arg1 != 0) {
            *(s32 *)(*(s16 *)(arg0 * 0x6C + *(s32 *)(g + 0x68) + 0x48) * 0x38 + *(s32 *)g + 0x2C) = 1;
        } else {
            *(s32 *)(*(s16 *)(arg0 * 0x6C + *(s32 *)(g + 0x68) + 0x48) * 0x38 + *(s32 *)g + 0x2C) = -1;
        }
    }
}

void fn_8000E540(struct numtx_s *, s32);
void fn_8000E3C0(struct numtx_s *, s32);
extern struct numtx_s lbl_801B0F08[];
extern f32 lbl_80195640[];
extern f32 lbl_80195644[];
extern f32 lbl_80195648[];

extern const f32 lbl_80195720[];

static inline void DebInitDispatchTransform(struct numtx_s *transform)
{
    *transform = lbl_801B0F08[0];
}

void fn_800641F8(s32 effect, s32 arg1, s32 arg2, f32 value, s32 angleZ, s32 angleY, s32 arg5)
{
    typedef s32 (*DebDispatch)(s32, s32, s32, s32, f32, s32, s32, s32, s32);
    struct numtx_s transform;
    struct nuvec_s offset;
    struct numtx_s *transformPtr;
    struct nuvec_s *offsetPtr;
    struct deb_effect_kind *definition;
    s32 amount;

    DebInitDispatchTransform(&transform);
    fn_8000E540(&transform, angleZ);
    fn_8000E3C0(&transform, angleY);
    transformPtr = &transform;
    offsetPtr = &offset;
    offset.z = lbl_80195720[0];
    offset.y = lbl_80195720[0];
    offset.x = lbl_80195720[0];
    if (effect >= 0 && (definition = ((struct deb_effect_kind **)lbl_804083FC)[effect]) != NULL) {
        switch (definition->kind) {
        case 2:
            amount = 50000;
            break;
        case 3:
            amount = 40000;
            break;
        case 7:
            amount = 20000;
            break;
        case 0:
        default:
            amount = 30000;
            break;
        }
        /* The float occupies f1 independently of the integer arguments. */
        ((DebDispatch)fn_8005F254)(effect, arg1, (s32)offsetPtr, arg2, value,
                                  (s32)transformPtr, arg5, amount, 0);
    }
}

extern const f32 lbl_8019572C[];

struct deb_transform_slot {
    u8 unk00[0x80];
    struct numtx_s transform80;
    struct numtx_s transformC0;
    u8 unk100[2];
    s16 definition;
    u8 unk104[0x17C];
    f32 unk280;
    u8 unk284[0x68];
};

static inline void DebInitTransform80(s32 slot)
{
    ((struct deb_transform_slot *)lbl_80408404)[slot].transform80 = lbl_801B0F08[0];
}

void fn_800644E4(s32 slot, s16 angleZ, s16 angleY)
{
    struct deb_transform_slot *effects;
    struct deb_transform_slot *effect;
    s32 base;

    if (slot != -1) {
        DebInitTransform80(slot);
        base = lbl_80408404;
        effects = (struct deb_transform_slot *)base;
        effect = &effects[slot];
        fn_8000E540(&effect->transform80, angleZ);
        base = lbl_80408404;
        effects = (struct deb_transform_slot *)base;
        effect = &effects[slot];
        fn_8000E3C0(&effect->transform80, angleY);
        effects = (struct deb_transform_slot *)lbl_80408404;
        effects[slot].unk280 = lbl_8019572C[0];
    }
}

void fn_8000E250(struct numtx_s *, s32);
extern const f32 lbl_80195738[];

static inline void DebInitTransformC0(s32 slot)
{
    ((struct deb_transform_slot *)lbl_80408404)[slot].transformC0 = lbl_801B0F08[0];
}

void fn_80064730(s32 slot, s16 angleZ, s16 angleY, s16 angleX)
{
    struct deb_transform_slot *effects;
    struct deb_transform_slot *effect;
    s32 base;

    if (slot != -1) {
        DebInitTransformC0(slot);
        base = lbl_80408404;
        effects = (struct deb_transform_slot *)base;
        effect = &effects[slot];
        fn_8000E540(&effect->transformC0, angleZ);
        base = lbl_80408404;
        effects = (struct deb_transform_slot *)base;
        effect = &effects[slot];
        fn_8000E3C0(&effect->transformC0, angleY);
        base = lbl_80408404;
        effects = (struct deb_transform_slot *)base;
        effect = &effects[slot];
        fn_8000E250(&effect->transformC0, angleX);
        effects = (struct deb_transform_slot *)lbl_80408404;
        effects[slot].unk280 = lbl_80195738[0];
    }
}

extern f32 lbl_801956E8[];

struct deb_definition_flags {
    u8 unk00[0x2EE];
    u8 flags;
};

struct deb_scan_hit {
    s32 slot;
    s32 flags;
};

static inline s32 DebSlotIsMissing(s16 id)
{
    return ((struct deb_definition_flags **)lbl_804083FC)[id] == NULL;
}

static inline u8 DebFlagForSlot(s32 i)
{
    return ((struct deb_definition_flags **)lbl_804083FC)
           [((struct deb_transform_slot *)lbl_80408404)[i].definition]->flags;
}

static inline void DebAppendScan(s32 table, s32 *count, s32 i)
{
    s32 index = *count;
    s32 offset = index * 8;
    struct deb_scan_hit *hit = (struct deb_scan_hit *)(offset + (s32)table);
    hit->slot = i;
    hit->flags = DebFlagForSlot(i);
    *count = index + 1;
}

s32 fn_80063A58(void *query, f32 value)
{
    s32 i;
    s32 slot;
    u16 id;
    struct deb_transform_slot *slots;

    lbl_8040AEA8 = 0;
    lbl_8040AEA4 = 0;
    for (i = 0; i < lbl_804083F0; i++) {
        slots = (struct deb_transform_slot *)lbl_80408404;
        id = (u16)slots[i].definition;
        if ((u16)(id + 1) > 1U) {
            if (DebSlotIsMissing((s16)id)) {
                slot = i;
                fn_8005EB80(&slot);
            } else {
                if (fn_80063834(i, query, value, lbl_801956E8[0], 3) != 0) {
                    DebAppendScan(lbl_8040AE9C, &lbl_8040AEA8, i);
                }
                if (NuAnimCurveSetApplyToJointBasic(i, (s32)query, value, lbl_801956E8[0], 3) != 0) {
                    DebAppendScan(lbl_8040AEA0, &lbl_8040AEA4, i);
                }
            }
        }
    }
    return lbl_8040AEA8 + lbl_8040AEA4;
}

void fn_8005FF74(s32 effect, void *arg1, s32 arg2, s16 angleZ, s16 angleY, void *arg5)
{
    struct numtx_s matrix = lbl_801B0F08[0];
    struct nuvec_s zero;
    struct numtx_s *transform;
    struct nuvec_s *offset;
    s8 *definition;
    s32 duration;

    fn_8000E540(&matrix, angleZ);
    fn_8000E3C0(&matrix, angleY);
    offset = &zero;
    transform = &matrix;
    zero.z = lbl_80195640[0];
    zero.y = lbl_80195640[0];
    zero.x = lbl_80195640[0];

    if (effect >= 0 && (definition = ((s8 **)lbl_804083FC)[effect]) != NULL) {
        switch (definition[0x2E]) {
        case 2:
            duration = 50000;
            break;
        case 3:
            duration = 40000;
            break;
        case 7:
            duration = 20000;
            break;
        case 0:
        default:
            duration = 30000;
            break;
        }
        if (fn_80027348() == 0) {
            fn_8005F254(effect, (s32)arg1, (s32)offset, arg2 * 50, (s32)transform, (s32)arg5,
                        duration, 0, lbl_80195644[0]);
        } else {
            fn_8005F254(effect, (s32)arg1, (s32)offset, arg2 * 60, (s32)transform, (s32)arg5,
                        duration, 0, lbl_80195648[0]);
        }
    }
}

typedef struct debrisnode_s {
    u8 pad00[8];
    s8 *deb;
    u8 pad0c[0x4c];
    struct debrisnode_s *prev;
    struct debrisnode_s *next;
    u16 unk60;
} debrisnode_s;

extern debrisnode_s *lbl_8038E6D8[];
extern s32 lbl_80408414;
extern s32 lbl_80408418;

void fn_8005D8BC(void) {
    s32 start = lbl_80408418;
    debrisnode_s *node;
    while (lbl_8038E6D8[lbl_80408418] == NULL) {
        lbl_80408418++;
        if (lbl_80408418 > 4) {
            lbl_80408418 = 0;
        }
        if (lbl_80408418 == start) {
            break;
        }
    }
    if (lbl_8038E6D8[lbl_80408418] != NULL) {
        node = lbl_8038E6D8[lbl_80408414];
        while (node != NULL) {
            s8 *deb = node->deb;
            if (deb != NULL && *(u8 *)(deb + 0x278) != 0) {
                f32 v = *(f32 *)(deb + 0x2dc) * 500.0f + (f32)(s32)*(u16 *)(deb + 0x2e8);
                if (v > 65535.0f) {
                    v = 65535.0f;
                }
                node->unk60 = (s16)v;
            }
            node = node->next;
        }
    }
}

void fn_8005E80C(s32 *);
extern s16 *lbl_804083E0;
extern s32 lbl_8040AEB4;

typedef struct debris_eb80_s {
    u8 pad00[0x102];
    s16 unk102;
    u8 pad104[0x1e8];
} debris_eb80_s;

typedef struct debrisinfo_s {
    u8 pad00[0x3c8];
    s16 unk3c8[8];
} debrisinfo_s;

s32 fn_8005EB80(s32 *arg0) {
    s32 i;
    s16 type;
    if (*arg0 != -1) {
        for (i = lbl_8040AEB4; i < lbl_804083F0; i++) {
            if (lbl_804083E0[i] == *arg0) {
                *arg0 = -1;
                return;
            }
        }
        type = *(s16 *)((s8 *)lbl_80408404 + (*arg0) * 0x2ec + 0x102);
        if (type != 0) {
            debrisinfo_s *info = ((debrisinfo_s **)lbl_804083FC)[type];
            void **p;
            fn_8005E80C(arg0);
            p = fn_80064BF4(lbl_80408404 + (*arg0) * 0x2ec);
            if (p != NULL) {
                fn_80064C54((void *)(lbl_80408404 + (*arg0) * 0x2ec), p);
            }
            for (i = 0; i < 8; i++) {
                if (info->unk3c8[i] == *arg0) {
                    info->unk3c8[i] = -1;
                }
            }
            ((debris_eb80_s *)lbl_80408404)[*arg0].unk102 = 0;
            lbl_8040AEB4--;
            lbl_804083E0[lbl_8040AEB4] = *arg0;
            *arg0 = -1;
        }
    }
}

s32 fn_80060120(void *, s32, f32, f32, f32);
extern f32 lbl_804083BC;

typedef struct debris_f114_s {
    u8 pad00[0x104];
    s16 unk104;
    u8 pad106[0x22];
    f32 unk128;
    f32 unk12c;
    f32 unk130;
    f32 unk134;
    f32 unk138;
    f32 unk13c;
    u8 pad140[0x14];
    s32 unk154;
    s16 unk158;
    u8 pad15a[6];
    f32 unk160;
    f32 unk164;
    u8 pad168[0x178];
    f32 unk2e0;
    f32 unk2e4;
    u8 pad2e8[4];
} debris_f114_s;

s32 fn_8005F114(void *arg0, s32 arg1, void *arg2, void *arg3, void *arg4, s32 arg5) {
    s32 *handle = (s32 *)arg0;
    f32 *pos = (f32 *)arg2;
    f32 *v3 = (f32 *)arg3;
    f32 *v4 = (f32 *)arg4;
    fn_80060120(handle, arg1, pos[0], pos[1], pos[2]);
    if (*handle != -1) {
        f32 diff;
        ((debris_f114_s *)lbl_80408404)[*handle].unk154 = arg5;
        ((debris_f114_s *)lbl_80408404)[*handle].unk158 = 0;
        diff = ((debris_f114_s *)lbl_80408404)[*handle].unk160 - lbl_804083BC;
        ((debris_f114_s *)lbl_80408404)[*handle].unk160 -= diff;
        ((debris_f114_s *)lbl_80408404)[*handle].unk164 -= diff;
        ((debris_f114_s *)lbl_80408404)[*handle].unk2e4 = ((debris_f114_s *)lbl_80408404)[*handle].unk2e0;
        ((debris_f114_s *)lbl_80408404)[*handle].unk104 = 1;
        if (v3 != NULL) {
            f32 x = v3[0];
            f32 y = v3[1];
            f32 z = v3[2];
            s32 idx = *handle;
            if (idx != -1) {
                ((debris_f114_s *)lbl_80408404)[idx].unk134 = x;
                ((debris_f114_s *)lbl_80408404)[idx].unk138 = y;
                ((debris_f114_s *)lbl_80408404)[idx].unk13c = z;
            }
        }
        if (v4 != NULL) {
            f32 x = v4[0];
            f32 y = v4[1];
            f32 z = v4[2];
            s32 idx = *handle;
            if (idx != -1) {
                ((debris_f114_s *)lbl_80408404)[idx].unk128 = x;
                ((debris_f114_s *)lbl_80408404)[idx].unk12c = y;
                ((debris_f114_s *)lbl_80408404)[idx].unk130 = z;
            }
            return idx;
        }
    }
}

f32 NuRandIntSeeded(s32 *);
extern f32 lbl_804083C0;

typedef struct debrisdef_ef6c_s {
    u8 pad00[0x1c];
    f32 unk1c;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    u8 unk2c;
    u8 pad2d[0x23];
    f32 unk50;
    f32 unk54;
    u8 pad58[0x295];
    u8 unk2ed;
} debrisdef_ef6c_s;

typedef struct debris_ef6c_s {
    u8 pad00[0x102];
    s16 unk102;
    u8 pad104[0x4c];
    s16 unk150;
    s16 unk152;
    u8 pad154[8];
    f32 unk15c;
    f32 unk160;
    f32 unk164;
} debris_ef6c_s;

void fn_8005EF6C(s32 arg0, f32 farg0) {
    debris_ef6c_s *deb = (debris_ef6c_s *)arg0;
    s32 frames = (s32)(farg0 * 60.0f);
    if (deb != NULL) {
        debrisdef_ef6c_s *def = ((debrisdef_ef6c_s **)lbl_804083FC)[deb->unk102];
        f32 t;
        if (def->unk2ed == 4) {
            t = lbl_804083C0;
        } else {
            t = lbl_804083BC;
        }
        if (def->unk20 != 0.0f || def->unk28 != 0.0f) {
            deb->unk160 = t;
        } else {
            f32 period = def->unk1c + def->unk24;
            f32 base = period * (f32)(s32)(t / period);
            if (def->unk2c == 7 && def->unk24 == 0.0f) {
                deb->unk150 = (s16)((f32)frames * def->unk50);
                deb->unk152 = (s16)((f32)frames * def->unk54);
                deb->unk160 = base + period;
            } else {
                deb->unk160 = base + farg0 + period;
            }
            while (deb->unk160 > t) {
                deb->unk160 -= period;
            }
        }
        deb->unk164 = NuRandIntSeeded(&lbl_80408410) * def->unk20 + (deb->unk160 + def->unk1c);
        deb->unk15c = -10.0f;
    }
}

typedef struct debriscmd_s {
    void *obj;
    s32 unk04;
    s32 unk08;
    s32 unk0c;
    struct debriscmd_s *next;
    s32 unk14;
    f32 unk18;
    u16 unk1c;
    s16 unk1e;
    s16 unk20;
    u8 pad22[2];
    f32 unk24;
    f32 unk28;
} debriscmd_s;

typedef struct debristrash2_s {
    void *obj;
    void *owner;
    s32 state;
    u8 pad0c[0x4c];
    struct debristrash2_s *prev;
    struct debristrash2_s *next;
    u8 pad60[4];
} debristrash2_s;

extern debriscmd_s *lbl_8038E5D8[2][32];
extern s32 lbl_804083CC;
extern s32 lbl_804083D0;
extern s32 lbl_8040AE74;
extern debriscmd_s **lbl_8040AE78;
extern s32 lbl_8040AE7C[2];
extern debristrash2_s *lbl_8040AE90;

static inline void cmd_unlink(debriscmd_s **head, debriscmd_s *node) {
    while (*head != NULL) {
        if (*head == node) {
            *head = node->next;
            break;
        }
        head = &(*head)->next;
    }
    node->next = NULL;
}

static inline void cmd_append(debriscmd_s **head, debriscmd_s *node) {
    while (*head != NULL) {
        head = &(*head)->next;
    }
    *head = node;
    node->next = NULL;
}

void fn_8005ECC8(void *arg0) {
    s32 i;
    for (i = 0; i < lbl_804083CC + lbl_804083D0; i++) {
        if (lbl_8040AE90[i].state == 0 && lbl_8040AE90[i].owner == arg0) {
            s32 q, slot;
            debriscmd_s *cmd;
            s32 qidx, bidx;
            debristrash2_s *tr;
            s32 list_idx;
            void *obj = lbl_8040AE90[i].obj;

            for (q = 0; q < 2; q++) {
                for (slot = 0; slot < 32; slot++) {
                    debriscmd_s *cur = lbl_8038E5D8[q][slot];
                    while (cur != NULL) {
                        debriscmd_s *nxt = cur->next;
                        if (cur->obj == obj) {
                            cmd_unlink(&lbl_8038E5D8[q][slot], cur);
                            lbl_8040AE78[--lbl_8040AE74] = cur;
                            cur->obj = NULL;
                        }
                        cur = nxt;
                    }
                }
            }

            lbl_8040AE78[lbl_8040AE74]->obj = lbl_8040AE90[i].obj;
            lbl_8040AE78[lbl_8040AE74]->unk04 = 0;
            if (*(u8 *)((s8 *)arg0 + 0x2e) == 7) {
                lbl_8040AE78[lbl_8040AE74]->unk08 = 9;
            } else {
                lbl_8040AE78[lbl_8040AE74]->unk08 = 2;
            }
            lbl_8040AE78[lbl_8040AE74]->unk0c = 0;

            cmd = lbl_8040AE78[lbl_8040AE74];
            qidx = (*(u8 *)((s8 *)arg0 + 0x2ed) == 4);
            bidx = (lbl_8040AE7C[qidx] + 4) & 31;
            cmd_append(&lbl_8038E5D8[qidx][bidx], cmd);
            lbl_8040AE74++;

            tr = (debristrash2_s *)(i * 0x64 + (u32)lbl_8040AE90);
            list_idx = *(s8 *)((s8 *)arg0 + 0x2ed);
            if ((debristrash2_s *)lbl_8038E6D8[list_idx] == tr) {
                debristrash2_s *nxt = tr->next;
                lbl_8038E6D8[list_idx] = (debrisnode_s *)nxt;
                if (nxt != NULL) {
                    nxt->prev = NULL;
                }
            } else if (tr->prev != NULL) {
                tr->prev->next = tr->next;
                if (tr->next != NULL) {
                    tr->next->prev = tr->prev;
                }
            }
            tr->prev = NULL;
            tr->next = NULL;
            lbl_8040AE90[i].obj = NULL;
            lbl_8040AE90[i].owner = NULL;
        }
    }
}

typedef struct debris_e80c_s {
    void *objs[0x20];
    u8 pad80[0x80];
    s16 count;
    s16 type;
    s16 unk104;
    s16 unk106;
    u8 pad108[0x16e];
    u8 unk276;
    u8 pad277[0x75];
} debris_e80c_s;

void fn_8005E80C(s32 *arg0) {
    debris_e80c_s *d = (debris_e80c_s *)((*arg0) * 0x2ec + lbl_80408404);
    s16 type = d->type;
    if (type != 0) {
        s8 *def = ((s8 **)lbl_804083FC)[type];
        if (d->count != 0) {
            s32 i;
            s32 total;
            for (i = 0; i < ((debris_e80c_s *)lbl_80408404)[*arg0].count; i++) {
                s32 q, slot;
                debriscmd_s *cmd;
                s32 qidx, bidx;
                void *obj = ((debris_e80c_s *)((*arg0) * 0x2ec + lbl_80408404))->objs[i];

                for (q = 0; q < 2; q++) {
                    for (slot = 0; slot < 32; slot++) {
                        debriscmd_s *cur = lbl_8038E5D8[q][slot];
                        while (cur != NULL) {
                            debriscmd_s *nxt = cur->next;
                            if (cur->obj == obj) {
                                cmd_unlink(&lbl_8038E5D8[q][slot], cur);
                                lbl_8040AE78[--lbl_8040AE74] = cur;
                                cur->obj = NULL;
                            }
                            cur = nxt;
                        }
                    }
                }

                lbl_8040AE78[lbl_8040AE74]->obj = ((debris_e80c_s *)lbl_80408404)[*arg0].objs[i];
                lbl_8040AE78[lbl_8040AE74]->unk04 = 0;
                if (*(u8 *)(def + 0x2e) == 7) {
                    lbl_8040AE78[lbl_8040AE74]->unk08 = 9;
                } else {
                    lbl_8040AE78[lbl_8040AE74]->unk08 = 2;
                }
                lbl_8040AE78[lbl_8040AE74]->unk0c = 0;

                cmd = lbl_8040AE78[lbl_8040AE74];
                qidx = (*(u8 *)(def + 0x2ed) == 4);
                bidx = (lbl_8040AE7C[qidx] + 4) & 31;
                cmd_append(&lbl_8038E5D8[qidx][bidx], cmd);
                lbl_8040AE74++;
            }

            total = lbl_804083CC + lbl_804083D0;
            {
                s32 j;
                for (j = 0; j < total; j++) {
                    debristrash2_s *tr = &lbl_8040AE90[j];
                    if (tr->obj == ((debris_e80c_s *)lbl_80408404)[*arg0].objs[0]) {
                        if (((debris_e80c_s *)lbl_80408404)[*arg0].unk276 != 0) {
                            s32 list_idx = *(s8 *)(def + 0x2ed);
                            if ((debristrash2_s *)lbl_8038E6D8[list_idx] == tr) {
                                debristrash2_s *nxt = tr->next;
                                lbl_8038E6D8[list_idx] = (debrisnode_s *)nxt;
                                if (nxt != NULL) {
                                    nxt->prev = NULL;
                                }
                            } else if (tr->prev != NULL) {
                                tr->prev->next = tr->next;
                                if (tr->next != NULL) {
                                    tr->next->prev = tr->prev;
                                }
                            }
                            tr->prev = NULL;
                            tr->next = NULL;
                        }
                        tr->obj = NULL;
                        tr->owner = NULL;
                    }
                }
            }

            for (i = 0; i < ((debris_e80c_s *)lbl_80408404)[*arg0].count; i++) {
                ((debris_e80c_s *)lbl_80408404)[*arg0].objs[i] = NULL;
            }
            {
                debris_e80c_s *d2 = (debris_e80c_s *)((*arg0) * 0x2ec + lbl_80408404);
                d2->unk106 = 0;
                d2->count = 0;
            }
        }
    }
}

void fn_8006E3E0(void *);

typedef struct debparticle_s {
    struct nuvec_s pos;
    f32 time;
    struct nuvec_s vel;
    f32 inv_life;
} debparticle_s;

typedef struct debchunk_s {
    u8 pad00[0x20];
    debparticle_s particles[32];
} debchunk_s;

typedef struct debinst_s {
    debchunk_s *chunks[0x20];
    u8 pad80[0x40];
    struct numtx_s mtx;
    s16 unk100;
    s16 unk102;
    s16 unk104;
    s16 unk106;
    s16 unk108;
    s16 unk10a;
    u8 pad10c[0x10];
    struct nuvec_s pos_off;
    struct nuvec_s vel_off;
    u8 pad134[0x10];
    void (*cb)(struct debinst_s *, void *, debparticle_s *);
    u8 pad148[8];
    s16 unk150;
    s16 unk152;
    u8 pad154[0xc];
    f32 unk160;
    u8 pad164[0xfa];
    s16 unk25e;
    f32 unk260;
    f32 unk264;
    u8 pad268[0x78];
    f32 start_time;
    f32 last_time;
    u8 pad2e8[4];
} debinst_s;

typedef struct debdef_s {
    u8 pad00[0x2e];
    u8 unk2e;
    u8 pad2f[0x19];
    f32 unk48;
    f32 unk4c;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5c;
    f32 unk60;
    struct nuvec_s unk64;
    u8 pad70[0x30];
    f32 gravity;
    f32 life;
    u8 pada8[0x200];
    s32 unk2a8;
    u8 pad2ac[0x15c];
    s16 repeat_count;
    s16 unk40a;
    f32 repeat_dt;
    f32 ramp_time;
    f32 unk414;
} debdef_s;

debparticle_s *fn_8005ACFC(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    s16 idx;
    debparticle_s *p;
    s32 rot_y;
    s32 rot_z;
    f32 speed;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        return NULL;
    }
    p = inst->chunks[inst->unk10a / 32]->particles;
    p += (s16)(inst->unk10a % 32);
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    rot_y = (s32)((2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk50 - def->unk50) + def->unk5c);
    rot_z = (s32)((2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk54 - def->unk54) + def->unk60);

    if (def->ramp_time != 0.0f && (lbl_804083BC - inst->start_time) < def->ramp_time) {
        v.y = def->unk58 * ((lbl_804083BC - inst->start_time) / def->ramp_time);
    } else {
        v.y = def->unk58;
    }

    v.z = 0.0f;
    v.x = 0.0f;
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    {
        f32 r = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
        v.z = 0.0f;
        v.y = r + def->unk48;
        v.x = 0.0f;
    }
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        s32 chunk;
        s16 rem;
        debparticle_s *base;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        base = inst->chunks[inst->unk10a / 32]->particles;
        p2 = &base[(s16)(inst->unk10a % 32)];
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

s32 fn_8000AEC4(f32);

debparticle_s *fn_8005B9DC(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    struct numtx_s m;
    debparticle_s *p;
    s32 rot_y;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        p = inst->chunks[(s16)(inst->unk10a / 12)]->particles;
        p += (s16)(inst->unk10a % 12);
    } else {
        p = inst->chunks[inst->unk10a / 32]->particles;
        p += (s16)(inst->unk10a % 32);
    }
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    v.x = NuFsqrt(NuRandIntSeeded(&lbl_80408410));
    v.z = 0.0f;
    v.y = 0.0f;
    rot_y = (s32)(NuRandIntSeeded(&lbl_80408410) * 65536.0f);
    NuVecRotateZ(&v, &v, fn_8000AEC4(2.0f * NuRandIntSeeded(&lbl_80408410) - 1.0f));
    NuVecRotateY(&v, &v, rot_y);
    NuMtxSetIdentity(&m);
    m._00 = def->unk58;
    m._11 = def->unk5c;
    m._22 = def->unk60;
    NuVecMtxTransform(&v, &v, &m);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    v.x = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
    v.y = (2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk50 - def->unk50) + def->unk48;
    v.z = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk54 - def->unk54;
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        if (def->unk2e == 7) {
            p2 = inst->chunks[(s16)(inst->unk10a / 12)]->particles;
            p2 += (s16)(inst->unk10a % 12);
        } else {
            p2 = inst->chunks[inst->unk10a / 32]->particles;
            p2 += (s16)(inst->unk10a % 32);
        }
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

debparticle_s *fn_8005C29C(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    struct nuvec_s dir = {1.0f, 0.0f, 0.0f};
    struct nuvec_s plane_pt;
    struct nuvec_s end_pos;
    struct nuvec_s d0;
    struct nuvec_s d1;
    debchunk_s *chunk;
    debparticle_s *p;
    f32 dot0, dot1;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        return NULL;
    }
    chunk = inst->chunks[inst->unk10a / 32];
    p = &chunk->particles[(s16)(inst->unk10a % 32)];
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    v.x = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk58 - def->unk58;
    v.y = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk5c - def->unk5c;
    v.z = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk60 - def->unk60;
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    v.x = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
    v.y = (2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk50 - def->unk50) + def->unk48;
    v.z = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk54 - def->unk54;
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    NuVecRotateY(&dir, &dir, inst->unk25e);
    NuVecScale(&plane_pt, &dir, inst->unk260);
    end_pos.x = p->pos.x + def->life * p->vel.x;
    end_pos.y = 0.0f;
    end_pos.z = p->pos.z + def->life * p->vel.z;
    NuVecSub(&d0, &plane_pt, &p->pos);
    NuVecSub(&d1, &plane_pt, &end_pos);
    dot0 = d0.x * dir.x + d0.z * dir.z;
    dot1 = d1.x * dir.x + d1.z * dir.z;
    if ((dot0 < 0.0f && dot1 > 0.0f) || (dot0 > 0.0f && dot1 < 0.0f)) {
        f32 t = def->life * ((0.0f - dot0) / (dot1 - dot0));
        if (lbl_8040AE74 < lbl_804083CC + lbl_804083D0) {
            lbl_8040AE78[lbl_8040AE74]->obj = chunk;
            lbl_8040AE78[lbl_8040AE74]->unk04 = (s32)(t * 60.0f);
            lbl_8040AE78[lbl_8040AE74]->unk08 = 6;
            lbl_8040AE78[lbl_8040AE74]->unk0c = 0;
            lbl_8040AE78[lbl_8040AE74]->unk1c = inst->unk102;
            lbl_8040AE78[lbl_8040AE74]->unk20 = inst->unk25e;
            lbl_8040AE78[lbl_8040AE74]->unk1e = 0;
            lbl_8040AE78[lbl_8040AE74]->unk24 = inst->unk260;
            lbl_8040AE78[lbl_8040AE74]->unk28 = inst->unk264;
            lbl_8040AE78[lbl_8040AE74]->unk14 = (s16)(inst->unk10a % 32);
            lbl_8040AE78[lbl_8040AE74]->unk18 = t;
            AddChunkControlToStack(lbl_8040AE78[lbl_8040AE74], (void **)&lbl_8038E5D8[0][lbl_8040AE7C[0]]);
            lbl_8040AE74++;
        }
    }

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }
    inst->unk10a++;

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

void *fn_8005A8E4(void *arg0, void *arg1, f32 time) {
    debinst_s *inst = (debinst_s *)arg0;
    debdef_s *def = (debdef_s *)arg1;
    struct nuvec_s v;
    struct nuvec_s offset;
    debparticle_s *p;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        p = inst->chunks[(s16)(inst->unk10a / 12)]->particles;
        p += (s16)(inst->unk10a % 12);
    } else {
        p = inst->chunks[inst->unk10a / 32]->particles;
        p += (s16)(inst->unk10a % 32);
    }
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    NuVecScale(&offset, &def->unk64, time - inst->unk160);

    v.x = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk58 - def->unk58;
    v.y = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk5c - def->unk5c;
    v.z = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk60 - def->unk60;
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x + offset.x;
    p->pos.y = v.y + offset.y;
    p->pos.z = v.z + offset.z;

    v.x = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
    v.y = (2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk50 - def->unk50) + def->unk48;
    v.z = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk54 - def->unk54;
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        if (def->unk2e == 7) {
            p2 = inst->chunks[(s16)(inst->unk10a / 12)]->particles;
            p2 += (s16)(inst->unk10a % 12);
        } else {
            p2 = inst->chunks[inst->unk10a / 32]->particles;
            p2 += (s16)(inst->unk10a % 32);
        }
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

debparticle_s *fn_8005B0BC(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    struct nuvec_s base;
    debparticle_s *p;
    s32 rot_y, rot_z;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        return NULL;
    }
    p = inst->chunks[inst->unk10a / 32]->particles;
    p += (s16)(inst->unk10a % 32);
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    NuVecScale(&base, &def->unk64, time - inst->unk160);
    NuVecAdd(&base, &base, (struct nuvec_s *)&def->unk58);

    v.z = 0.0f;
    v.y = base.x;
    v.x = 0.0f;
    rot_y = (s32)((f32)inst->unk150 + base.y);
    rot_z = (s32)((f32)inst->unk152 + base.z);
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    {
        f32 r = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
        v.z = 0.0f;
        v.y = r + def->unk48;
        v.x = 0.0f;
    }
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        p2 = inst->chunks[inst->unk10a / 32]->particles;
        p2 += (s16)(inst->unk10a % 32);
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }

    if (def->unk50 == 0.0f) {
        inst->unk150 = 0;
    } else {
        inst->unk150 = (s16)((f32)inst->unk150 + def->unk50);
    }
    if (def->unk54 == 0.0f) {
        inst->unk152 = 0;
    } else {
        inst->unk152 = (s16)((f32)inst->unk152 + def->unk54);
    }
    return p;
}

f32 NuSinApprox(s32);

debparticle_s *fn_8005B56C(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    struct nuvec_s base;
    debparticle_s *p;
    f32 s0, s1;
    s32 rot_y, rot_z;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        return NULL;
    }
    p = inst->chunks[inst->unk10a / 32]->particles;
    p += (s16)(inst->unk10a % 32);
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    NuVecScale(&base, &def->unk64, time - inst->unk160);
    NuVecAdd(&base, &base, (struct nuvec_s *)&def->unk58);

    rot_y = (s32)(NuRandIntSeeded(&lbl_80408410) * 65536.0f - 32768.0f);
    s0 = NuSinApprox((s32)(base.z - def->unk54));
    s1 = NuSinApprox((s32)(base.z + def->unk54));
    rot_z = fn_8000AEC4(NuRandIntSeeded(&lbl_80408410) * (s1 - s0) + s0);
    rot_y = (s32)((f32)rot_y * def->unk50 * (1.0f / 32768.0f));
    rot_y = (s32)((f32)rot_y + base.y);

    v.x = base.x;
    v.z = 0.0f;
    v.y = 0.0f;
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    {
        f32 spd = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
        v.z = 0.0f;
        v.x = spd + def->unk48;
        v.y = 0.0f;
    }
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        p2 = inst->chunks[inst->unk10a / 32]->particles;
        p2 += (s16)(inst->unk10a % 32);
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

debparticle_s *fn_8005C6C8(debinst_s *inst, debdef_s *def, f32 time) {
    struct nuvec_s v;
    debparticle_s *p;
    s32 rot_y, rot_z;
    s32 step;
    f32 scale;
    s32 i;

    if (inst->unk10a >= inst->unk106) {
        inst->unk10a = 0;
    }
    if (def->unk2e == 7) {
        return NULL;
    }
    p = inst->chunks[inst->unk10a / 32]->particles;
    p += (s16)(inst->unk10a % 32);
    inst->unk10a++;
    p->time = time;
    inst->last_time = time;
    p->inv_life = 64.0f / def->life;

    rot_y = (s32)((2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk50 - def->unk50) + def->unk5c);
    rot_z = (s32)((2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk54 - def->unk54) + def->unk60);

    if (def->ramp_time != 0.0f && (lbl_804083BC - inst->start_time) < def->ramp_time) {
        v.y = def->unk58 * ((lbl_804083BC - inst->start_time) / def->ramp_time);
    } else {
        v.y = def->unk58;
    }

    step = 0x10000 / def->unk40a;
    scale = 1.0f - NuSinApprox((s32)(((f32)((rot_y + 0x10000) % step) / (f32)step) * 32768.0f));
    scale = (1.0f - def->unk414) * scale + def->unk414;
    v.z = 0.0f;
    v.x = 0.0f;
    v.y *= scale;
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->pos.x = v.x;
    p->pos.y = v.y;
    p->pos.z = v.z;

    {
        f32 r = 2.0f * NuRandIntSeeded(&lbl_80408410) * def->unk4c - def->unk4c;
        v.z = 0.0f;
        v.y = r + def->unk48;
        v.x = 0.0f;
    }
    NuVecRotateZ(&v, &v, rot_z);
    NuVecRotateY(&v, &v, rot_y);
    NuVecMtxTransform(&v, &v, &inst->mtx);
    p->vel.x = v.x;
    p->vel.y = v.y;
    p->vel.z = v.z;

    if (inst->cb != NULL) {
        inst->cb(inst, def, p);
    }

    p->pos.x += inst->pos_off.x;
    p->pos.y += inst->pos_off.y;
    p->pos.z += inst->pos_off.z;
    p->vel.x += inst->vel_off.x;
    p->vel.y += inst->vel_off.y;
    p->vel.z += inst->vel_off.z;

    for (i = 0; i < def->repeat_count; i++) {
        debparticle_s *p2;
        if (inst->unk10a >= inst->unk106) {
            inst->unk10a = 0;
        }
        p2 = inst->chunks[inst->unk10a / 32]->particles;
        p2 += (s16)(inst->unk10a % 32);
        inst->unk10a++;
        *p2 = *p;
        p2->time += (f32)(i + 1) * def->repeat_dt;
    }

    if (def->unk2a8 == 0) {
        fn_8006E3E0(def);
    }
    return p;
}

char *strcpy(char *, const char *);

struct DebSetVec_8038E840 { s32 a, b, c; };

struct DebSet_8038E840 {
    s32 unk0;
    s32 count2;
    s32 count1;
    u8 pad0C[0x1C - 0x0C];
    char names2[8][16];
    s32 a2[8];
    s32 b2[8];
    s32 c2[8];
    struct DebSetVec_8038E840 v2[8];
    u8 pad15C[0x180 - 0x15C];
    char names1[8][16];
    s32 x1[8];
    u8 pad220[0x240 - 0x220];
    f32 f1[8];
    struct DebSetVec_8038E840 v1[8];
    u8 pad2C0[0x2D4 - 0x2C0];
};

extern struct DebSet_8038E840 lbl_8038E840[];

void fn_800659B8(s32 set, s32 index) {
    s32 i;

    for (i = index; i < lbl_8038E840[set].count1 - 1; i++) {
        lbl_8038E840[set].x1[i] = lbl_8038E840[set].x1[i + 1];
        lbl_8038E840[set].f1[i] = lbl_8038E840[set].f1[i + 1];
        lbl_8038E840[set].v1[i] = lbl_8038E840[set].v1[i + 1];
        strcpy(lbl_8038E840[set].names1[i], lbl_8038E840[set].names1[i + 1]);
    }
    lbl_8038E840[set].count1--;
}
