#include "types.h"

extern s32 lbl_80408E84;
extern s32 lbl_8040A624;

void fn_8009CF2C(void)
{

}

void fn_8009CFF0()
{

}

void fn_8009CFF4()
{

}

s32 fn_8009CFF8(void)
{
    return 0;
}

s32 fn_8009D158(void)
{
    return lbl_8040A624;
}

void fn_8009D238(void)
{

}

s32 fn_8009D414(void)
{
    return lbl_80408E84;
}

void fn_8009D540(void)
{
    lbl_80408E84 = (lbl_80408E84 + -1);
}

s32 fn_800A1F94(void)
{
    return 0;
}

extern f32 lbl_8019EA00[];
extern f32 lbl_8019EA04[];
extern f32 lbl_8019EA08[];
extern f32 lbl_80408E9C;
extern f32 lbl_80408F00;
extern f32 lbl_80408F04;
extern s32 lbl_80408F08;
extern s32 lbl_80408F14;

void fn_8009DC18(void) {
    f32 temp_f0;
    f32 temp_f11;
    s32 var_r0;

    temp_f11 = lbl_80408F00;
    temp_f0 = (lbl_80408F04 * lbl_80408E9C) + temp_f11;
    lbl_80408F00 = temp_f0;
    if (temp_f0 > lbl_8019EA00[0]) {
        lbl_80408F00 = lbl_8019EA00[0];
    } else if (temp_f0 < lbl_8019EA04[0]) {
        lbl_80408F00 = lbl_8019EA04[0];
    }
    if ((temp_f11 < lbl_8019EA00[0]) && (lbl_80408F00 == lbl_8019EA00[0])) {
        var_r0 = 1;
        goto block_9;
    }
    if ((s32) lbl_80408F08 != 0) {
        var_r0 = lbl_80408F08 - 1;
block_9:
        lbl_80408F08 = var_r0;
    }
    if ((lbl_80408F00 == lbl_8019EA04[0]) || (lbl_80408F00 == lbl_8019EA00[0])) {
        lbl_80408F04 = lbl_8019EA08[0];
    }
    if ((lbl_80408F00 == lbl_8019EA04[0]) && (temp_f11 > lbl_8019EA04[0])) {
        lbl_80408F14 = 0;
    }
}

s32 fn_8009ED84(s32);
extern s32 lbl_80408FA0;

void fn_800A1BD4(void) {
    s32 var_r31;

    var_r31 = 0;
    do {
        fn_8009ED84(var_r31);
        var_r31 += 1;
    } while (var_r31 <= 1);
    lbl_80408FA0 = 0;
}

void *fn_80024C18(s32);
void fn_80024CD4(void *);
extern void *lbl_8040AF8C;

void fn_800A1F9C(void) {
    void *temp_r3;

    temp_r3 = fn_80024C18(1);
    lbl_8040AF8C = temp_r3;
    if (temp_r3 != NULL) {
        (*(s8 *)((s8 *)(temp_r3) + (0xBE))) = 0;
        (*(s8 *)((s8 *)(lbl_8040AF8C) + (0xB8))) = 0;
        (*(s8 *)((s8 *)(lbl_8040AF8C) + (0xC0))) = 1;
        fn_80024CD4(lbl_8040AF8C);
    }
}

s32 fn_800CA018(s32);
extern s32 lbl_80408E84;

void fn_8009D550(void)
{
  s32 new_var;
  s32 temp_r9;
  temp_r9 = lbl_80408E84 + 1;
  lbl_80408E84 = temp_r9;
  fn_800CA018(new_var);
  new_var = temp_r9;
}

void *fn_80024BF0(s32);
void *fn_80024C18(s32);
void fn_80024CD4(void *);
extern void *lbl_8040AF68;
extern void *lbl_8040AF6C;
extern void *lbl_8040AF70;

void fn_8009D9D8(void)
{
  void *temp_r3;
  void *temp_r3_2;
  void *temp_r3_3;
  temp_r3 = fn_80024BF0(1);
  lbl_8040AF68 = temp_r3;
  *((s8 *) (((s8 *) temp_r3) + 0xBE)) = 3;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xB9)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xBF)) = 2;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xBB)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xBC)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xC0)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF68) + 0xB8)) = 3;
  fn_80024CD4(lbl_8040AF68);
  temp_r3_2 = fn_80024BF0(1);
  lbl_8040AF6C = temp_r3_2;
  *((s8 *) (((s8 *) temp_r3_2) + 0xBE)) = 3;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xB9)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xBF)) = 2;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xBB)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xBC)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xC0)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF6C) + 0xB8)) = 1;
  fn_80024CD4(lbl_8040AF6C);
  temp_r3_3 = fn_80024C18(1);
  lbl_8040AF70 = temp_r3_3;
  *((s8 *) (((s8 *) temp_r3_3) + 0xBE)) = 3;
  *((s8 *) (((s8 *) lbl_8040AF70) + 0xB9)) = 1;
  *(((s8 *) lbl_8040AF70) + 0xBF) = 2;
  *((s8 *) (((s8 *) lbl_8040AF70) + 0xBB)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF70) + 0xBC)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF70) + 0xC0)) = 1;
  *((s8 *) (((s8 *) lbl_8040AF70) + 0xB8)) = 1;
  temp_r3_3 = lbl_8040AF70;
  *((s16 *) (((s8 *) temp_r3_3) + 0xF8)) = 0x64;
  fn_80024CD4(temp_r3_3);
}

s32 fn_800092F0(void *, void *, void *, s32);

void fn_8009D504(void *arg0) {
    s32 sp8;

    sp8 = (*(s32 *)((s8 *)(arg0) + (0x14)));
    fn_800092F0((s8 *)arg0 + 0x18, *(void **)((s8 *)arg0 + 0x10), &sp8, 0);
}

s32 fn_8009EC80(s32);
s32 fn_800B2ED4(void);
s32 fn_8011EAA8(s32);
extern f32 lbl_8019EAEC[];
extern s32 lbl_803D9A58[];
extern u8 lbl_803E028C[];
extern s32 lbl_80408EA8;
extern f32 lbl_80408F00;
extern s32 lbl_80408FE0;
extern s32 lbl_80409118;
extern s32 lbl_8040912C;
extern s32 lbl_8040913C;
extern s32 lbl_804093B0;
extern void *lbl_80409410;
extern s32 lbl_8040AFA8;
extern s32 lbl_8040AFAC;
extern s32 lbl_8040AFB0;
extern s32 lbl_8040AFB4;

void fn_8009F0B8(s32 arg0)
{
  s32 temp_r3;
  s32 temp_r9;
  void *new_var;
  s32 var_r0;
  void *temp_r9_2;
  void *temp_r9_3;
  if (((s32) lbl_8040912C) == 0)
  {
    temp_r9 = arg0 * 0x5C;
    new_var = (s8 *) lbl_803D9A58;
    if (((((((s32) (*((u8 *) (((s8 *) (temp_r9 + new_var)) + 0x24)))) == 0) || ((temp_r9 = (*((s32 *) (((s8 *) (*((s32 *) (new_var + temp_r9)))) + 0x6C))) & 0x20000000, (temp_r9 == 0) == 0))) || (((s32) lbl_80408FE0) != 0)) || ((temp_r3 = fn_800B2ED4(), (temp_r3 == 1) != 0))) || ((var_r0 = 1, (temp_r3 == 0x1A) != 0)))
    {
      var_r0 = 0;
    }
    new_var = (void *) 0;
    if (((((((((((((var_r0 != 0) && (((s32) lbl_8040913C) == (-1))) && (((s32) lbl_804093B0) == (-1))) && (lbl_80408F00 == lbl_8019EAEC[0])) && (((s32) lbl_80408EA8) == 0)) && (((s32) lbl_80409118) == 0)) && (((s32) lbl_8040AFA8) == 0)) && ((((s32) (*((s32 *) (((s8 *) lbl_80409410) + 0x19C)))) != 0x15) || (((s32) lbl_803E028C[0]) != 5))) && (((temp_r9_2 = *((void **) (((s8 *) lbl_80409410) + 0x1AC)), (temp_r9_2 == new_var) != 0)) || (!((*((u8 *) (((s8 *) temp_r9_2) + 0x32))) & 4)))) && (((temp_r9_3 = *((void **) (((s8 *) lbl_80409410) + 0x1A8)), (temp_r9_3 == new_var) != 0)) || (!((*((s32 *) (((s8 *) (*((void **) (((s8 *) lbl_80409410) + 0x1A8)))) + 4))) & 0x1000)))) && (fn_800B2ED4() == (-1))) && ((((s32) lbl_8040AFAC) == 0) || (fn_8011EAA8(lbl_8040AFB0) != 0))) && (((s32) lbl_8040AFB4) == 0))
    {
      fn_8009EC80(arg0);
    }
  }
}

void Menu_ResetStack(void);
s32 fn_8006DCD4(void *, void *);
void fn_8006DF18(void);
void fn_8006E184(void);
void fn_80078E90(void *);
extern s32 gMenuDepth;
extern s32 gMenuStack[];
extern s32 lbl_8019EACC[];
extern s32 lbl_8040912C;

void Menu_CleanupAndReset(void) {
    lbl_8040912C = 0;
    fn_80078E90((gMenuDepth * 0xE0) + ((s8 *)gMenuStack));
    Menu_ResetStack();
    fn_8006DF18();
    fn_8006E184();
    fn_8006DCD4(lbl_8019EACC, 0);
}

void AXFXSetHooks(s32, s32, f32);
void NuRndrFootPrints(s32);
s32 fn_800274BC(s32);
void fn_80027564(void);
void fn_8009E6FC(void);
extern f32 lbl_8019EB90[];
extern s32 lbl_80408ED0;

void fn_800A1C70(s32 arg0) {
    s32 var_r31;

    var_r31 = arg0;
    do {
        if ((s32) lbl_80408ED0 != 0) {
            fn_8009E6FC();
        } else if (fn_800274BC(-1) != 0) {
            AXFXSetHooks(0xB00, 0, lbl_8019EB90[0]);
            fn_80027564();
        }
        NuRndrFootPrints(-1);
        var_r31 -= 1;
    } while (var_r31 > 0);
    lbl_80408ED0 = 0;
}

void fn_8002A3A8(s32);

void fn_800A1F54(void *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0x1C0) != 0) {
        fn_8002A3A8(*(s32 *)((s8 *)arg0 + 0x1C0));
    }
    *(s32 *)((s8 *)arg0 + 0x1C0) = 0;
}

extern s32 lbl_8019E714[];
extern s32 lbl_80408E88;
extern s32 lbl_80408F8C;

void fn_8009D57C(void) {
    volatile s32 sp8;
    s32 spC;

    lbl_80408E84++;
    spC = lbl_80408F8C - 0x100000;
    sp8 = lbl_80408F8C;
    lbl_80408E88 = fn_800092F0(lbl_8019E714, &spC, (s32 *)&sp8, 4);
}

s32 TerrainInitEx(s32, void *, s32, s32, void *, s32, s32, s32, s32, s32);
s32 fn_8005A3F8(s32, void *, s32, s32, void *, s32, s32);

void fn_800A1D44(void *arg0) {
    s32 type;
    s32 var_r3;

    *(s32 *)((s8 *)arg0 + 0x1C4) = 0;
    if (*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x1A8) + 4) & 8) {
        *(s32 *)((s8 *)arg0 + 0x184) = (*(s32 *)((s8 *)arg0 + 0x184) + 0x3F) & ~0x3F;
        type = *(s32 *)((s8 *)arg0 + 0x198);
        if (type == 0x21) {
            var_r3 = TerrainInitEx(type, (s8 *)arg0 + 0x184, *(s32 *)((s8 *)arg0 + 0x188), 0, (s8 *)arg0 + 0x80, *(s32 *)((s8 *)arg0 + 0x1C0), 0, 0x100, 0x100, 0);
        } else {
            var_r3 = fn_8005A3F8(type, (s8 *)arg0 + 0x184, *(s32 *)((s8 *)arg0 + 0x188), 0, (s8 *)arg0 + 0x80, *(s32 *)((s8 *)arg0 + 0x1C0), 0);
        }
        *(s32 *)((s8 *)arg0 + 0x1C4) = var_r3;
    }
}

void fn_8002823C(s32, s32, s32, f32, f32);
extern f32 lbl_8019EB28[];
extern s32 lbl_804093C8;

void fn_800A039C(void) {
    s32 temp_r11;
    s32 temp_r9;
    void *temp_r10;

    if ((void *) lbl_80409410 != NULL) {
        temp_r10 = (*(void **)((s8 *)(lbl_80409410) + (0x1A8)));
        temp_r11 = (*(s32 *)((s8 *)(temp_r10) + (4)));
        if (!(temp_r11 & 0x4000) && ((s32) lbl_804093C8 != -1) && ((s32) (temp_r11 & 0x44000) == 0x40000) && (((s32) lbl_8040AFAC == 0) || !((*(s32 *)((s8 *)((*(void **)((s8 *)(lbl_8040AFB0) + (8)))) + (0x3C))) & 0x40))) {
            temp_r9 = (*(u8 *)((s8 *)(temp_r10) + (0x59))) << 8;
            fn_8002823C(((*(u8 *)((s8 *)(temp_r10) + (0x5B))) << 0x18) | ((*(u8 *)((s8 *)(temp_r10) + (0x5A))) << 0x10) | temp_r9 | (*(u8 *)((s8 *)(temp_r10) + (0x58))), 0, 0, (*(f32 *)((s8 *)(temp_r10) + (0x50))), (*(f32 *)((s8 *)(temp_r10) + (0x54))));
            return;
        }
    }
    fn_8002823C(0, 0, 0, lbl_8019EB28[0], lbl_8019EB28[0]);
}

void NuPortalInit();
void NuPortalVisibility(void *);
void fn_8002933C(void *);
void fn_80043328();
void fn_80043D8C();
void fn_80067114(void *);
void memset();
extern s8 lbl_802D9F18[];
extern s8 *lbl_80408F94;
extern s32 lbl_8040AF9C;

typedef struct PortalEnt {
    u8 pad[0x10];
    u32 b0 : 2;
    u32 vis : 1;
    u32 rest : 29;
    u8 pad2[4];
} PortalEnt;

void fn_8009EB80(void) {
    s32 i;
    s32 n;
    void *temp_r31;
    PortalEnt *e;
    s8 *out;

    if (*(void **)((s8 *)lbl_80409410 + 0x1C0) != NULL) {
        if (lbl_8040AF9C == 0) {
            NuPortalInit();
            NuPortalVisibility(*(void **)((s8 *)lbl_80409410 + 0x1C0));
            temp_r31 = *(void **)((s8 *)lbl_80409410 + 0x1C0);
            lbl_802D9F18[0] = 1;
            memset(lbl_80408F94, 0, 0x100);
            if (temp_r31 != NULL) {
                n = *(s32 *)((s8 *)temp_r31 + 0x90);
                if (n > 0) {
                    e = *(PortalEnt **)((s8 *)temp_r31 + 0x94);
                    out = lbl_80408F94;
                    for (i = 0; i < n; i++) {
                        if (e->vis) {
                            *out = 1;
                        } else {
                            *out = e->vis;
                        }
                        e++;
                        out++;
                    }
                }
            }
        }
        fn_8002933C(*(void **)((s8 *)lbl_80409410 + 0x1C0));
        fn_80043D8C(*(void **)((s8 *)lbl_80409410 + 0x1C0));
        fn_80043328(*(void **)((s8 *)lbl_80409410 + 0x1C0));
        fn_80067114(*(void **)((s8 *)lbl_80409410 + 0x1C0));
    }
}

void OSResumeThread(s32 *);
void OSSuspendThread(s32 *);
extern s32 lbl_802D56F8[];
extern s32 lbl_802D5A10[];
s32 fn_8009D4CC(void) {
    u8 buf[0x28];
    OSResumeThread(lbl_802D56F8);
    OSSuspendThread(lbl_802D5A10);
    return 0;
}

s32 NuFileExists(void *);
s32 fn_80065C14(char *, s32);
void fn_8006F8A8();
int sprintf(char *, const char *, ...);
extern char lbl_8019EAB4[];

void LoadObjectAnimFile(void *arg0) {
    char buf[0x100];

    if (*(s32 *)((s8 *)arg0 + 0x5E8) == -1) {
        sprintf(buf, lbl_8019EAB4, (s8 *)arg0 + 0x80);
        if (NuFileExists(buf) != 0) {
            fn_8006F8A8(1);
            *(s32 *)((s8 *)arg0 + 0x5E8) = fn_80065C14(buf, *(s32 *)((s8 *)arg0 + 0x1C0));
            fn_8006F8A8(0);
        }
    }
}

s32 NuFileExists(void *);
void fn_80068F14(char *);
void fn_800698B8();
int sprintf(char *, const char *, ...);
extern char lbl_8019EAAC[];
extern s32 lbl_803E04F0[];

void LoadObjectFile(void *arg0) {
    char buf[0x100];

    fn_800698B8();
    if (*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0x1A8) + 4) & 0x8000) {
        sprintf(buf, lbl_8019EAAC, (s8 *)arg0 + 0x80);
        if (NuFileExists(lbl_803E04F0) != 0) {
            fn_80068F14(buf);
        }
    }
}

void fn_80037170(void);
extern f32 lbl_8019EB94[];
extern f32 lbl_8040A63C;

void fn_800A1CEC(void) {
    u8 order[16] = {4, 2, 5, 3, 0, 6, 1, 7, 5, 3, 4, 2, 1, 7, 0, 6};

    fn_80037170();
    lbl_8040A63C = lbl_8019EB94[0];
}

extern s32 lbl_8040AFC8;
extern s32 lbl_8040AFCC;
extern s32 lbl_8040AFD0;
extern s32 lbl_8040AFD4;

s32 fn_8009FAD8(void) {
    s32 moved;

    moved = 0;
    {
        s32 d = lbl_8040AFC8 - lbl_8040AFD0;
        if (d != 0) {
            d /= 4;
            if (d != 0) {
                lbl_8040AFD0 += d;
            } else if (lbl_8040AFD0 < lbl_8040AFC8) {
                lbl_8040AFD0++;
            } else if (lbl_8040AFD0 > lbl_8040AFC8) {
                lbl_8040AFD0--;
            }
            moved = 1;
        }
    }
    {
        s32 d = lbl_8040AFCC - lbl_8040AFD4;
        if (d != 0) {
            d /= 4;
            if (d != 0) {
                lbl_8040AFD4 += d;
            } else if (lbl_8040AFD4 < lbl_8040AFCC) {
                lbl_8040AFD4++;
            } else if (lbl_8040AFD4 > lbl_8040AFCC) {
                lbl_8040AFD4--;
            }
            moved = 1;
        }
    }
    return moved;
}

s32 (*fn_80009970(s32 *, s32))();
s32 fn_80014EC0(s32, s32 *, s32 *, s32);
extern s32 lbl_8019E9B8[];
extern s32 lbl_801BC904[];
extern s32 lbl_80408F6C;
extern s32 lbl_80408F70;
extern s32 str_AnimatedTextureScript_LoadFailed[];

void fn_800A1FF0(void) {
    s32 sp8;
    s32 *p;

    p = lbl_801BC904;
    while (*p != 0) {
        sp8 = lbl_80408F70;
        {
            s32 *a = &lbl_80408F6C;
            *a = (*a + 0x3F) & ~0x3F;
        }
        if (fn_80014EC0(*p, &lbl_80408F6C, &sp8, 0x3C) == 0) {
            fn_80009970(lbl_8019E9B8, 0xC0F)(str_AnimatedTextureScript_LoadFailed, *p);
        }
        p++;
    }
    {
        s32 *a = &lbl_80408F6C;
        *a = (*a + 0xF) & ~0xF;
    }
}

s32 OSCreateThread(void *, void *, s32, void *, s32, s32, s32);
void OSInitMessageQueue(s32 *, s32 *, s32);
void OSInitSemaphore(s32 *, s32);
void OSResumeThread(s32 *);
s32 fn_8009D41C(void);
s32 fn_8009D4CC(void);
extern s32 lbl_802D4EF7[];
extern s32 lbl_802D56F7[];
extern s32 lbl_802D5D28[];
extern s32 lbl_802D5D48[];
extern s32 lbl_802D5D54[];
extern s32 lbl_80408E78;

void fn_8009D23C(void) {
    s32 i;

    if (lbl_80408E78 == 0) {
        lbl_80408E78 = 1;
        OSCreateThread(lbl_802D56F8, fn_8009D41C, 0, lbl_802D4EF7, 0x10000, 0x14, 0);
        OSCreateThread(lbl_802D5A10, fn_8009D4CC, 0, lbl_802D56F7, 0x800, 0x14, 0);
        OSInitMessageQueue(lbl_802D5D28, lbl_802D5D54, 0x10);
        OSInitSemaphore(lbl_802D5D48, 0x10);
        OSResumeThread(lbl_802D5A10);
        for (i = 15; i >= 0; i--) {
            lbl_802D5D54[i] = i;
        }
    }
}

void OSSendMessage(void *, void *, s32);
void OSWaitSemaphore(void *);
void *memcpy();
extern s32 lbl_802D5D94[];
extern s32 lbl_80408E7C;
extern s32 lbl_80408E80;

typedef struct NetMsg {
    s32 a;
    s32 b;
    u32 flags;
    s32 pad;
    u8 data[0x408];
} NetMsg;

void *fn_8009D160(s32 arg0, s32 arg1, void *src, s32 len) {
    NetMsg *m;
    void *tok;

    OSWaitSemaphore(lbl_802D5D48);
    m = &((NetMsg *)lbl_802D5D94)[lbl_80408E7C];
    tok = lbl_802D5D54[lbl_80408E7C];
    lbl_80408E80++;
    if (++lbl_80408E7C > 15) {
        lbl_80408E7C = 0;
    }
    m->a = arg0;
    m->b = arg1;
    m->flags &= 0x3FFFFFFF;
    if (src != NULL && len != 0) {
        memcpy(m->data, src, len);
    }
    OSSendMessage(lbl_802D5D28, tok, 0);
    return m;
}

static inline void *PostMsg(void *a, void *b, void *src, s32 len) {
    NetMsg *m;
    void *tok;

    OSWaitSemaphore(lbl_802D5D48);
    m = &((NetMsg *)lbl_802D5D94)[lbl_80408E7C];
    tok = lbl_802D5D54[lbl_80408E7C];
    lbl_80408E80++;
    if (++lbl_80408E7C > 15) {
        lbl_80408E7C = 0;
    }
    m->a = (s32)a;
    m->b = (s32)b;
    m->flags &= 0x3FFFFFFF;
    if (src != NULL && len != 0) {
        memcpy(m->data, src, len);
    }
    OSSendMessage(lbl_802D5D28, tok, 0);
    return m;
}

void fn_8009D000(void) {
    PostMsg(fn_8009D550, fn_8009D540, NULL, 0);
}

void fn_8009D0AC(void) {
    PostMsg(fn_8009D57C, fn_8009D540, NULL, 0);
}

void LoadWorldInfo(void *);
s32 NuHGobjEvalAnim(void *, s32);
typedef struct LevData { u8 pad[0x32]; u32 hi : 4; u32 flag : 1; u32 lo : 3; u8 pad2[0x35]; } __attribute__((packed)) LevData;
extern LevData lbl_801DC074[];
extern u8 lbl_803DB158[];
extern s32 lbl_804093BC;
extern void *lbl_80409414;
extern s32 lbl_8040AF60;
extern s32 lbl_8040AF64;

void fn_8009CF30(void) {
    if (lbl_80409414 == lbl_80409410) {
        s32 i = lbl_804093C8;
        s32 ok = 1;
        if (i != -1) {
            LevData *p = &lbl_801DC074[i];
            ok = !p->flag;
        }
        if (ok) {
            u8 *w = lbl_803DB158;
            if (lbl_80409414 == w) {
                w += 0x1E18;
            }
            lbl_80409414 = w;
        }
    }
    if (NuHGobjEvalAnim(lbl_80409414, lbl_8040AF60) != 0) {
        lbl_8040AF64 = lbl_8040AF60;
        LoadWorldInfo(lbl_80409414);
    }
    {
        s32 *cur = lbl_80409414;
        lbl_8040AF64 = -1;
        if (cur[0x64] != 0) {
            lbl_804093BC = 1;
        }
    }
}

/* The 0xF00 calls also pass a third int argument in r5. */
#define AXFXSetHooks4 ((void (*)(s32, s32, s32, f32))AXFXSetHooks)
void NuCameraCalcFrustrumPlanes(void *);
void fn_80027668(s32, s32, s32, f32);
void fn_800B4A88(f32);
typedef struct Mtx44Blk { s32 m[16]; } Mtx44Blk;
extern f32 lbl_8019EB24[];
extern Mtx44Blk lbl_801B0F08;
extern s32 lbl_8040A628;
extern s32 lbl_8040A62C;
extern Mtx44Blk *lbl_8040AF5C;
extern f32 lbl_8040AF74;

void fn_800A02A0(void) {
    *lbl_8040AF5C = lbl_801B0F08;
    NuCameraCalcFrustrumPlanes(lbl_8040AF5C);
    if (fn_800274BC(-1) != 0) {
        if (lbl_8040A628 == lbl_8040A62C) {
            AXFXSetHooks4(0xF00, lbl_8040A62C, lbl_8040A62C, lbl_8019EB24[0]);
        } else {
            fn_80027668(0xF00, lbl_8040A628, lbl_8040A62C, lbl_8019EB24[0]);
        }
        if (lbl_8040AF74 != lbl_8019EB24[0]) {
            fn_800B4A88(lbl_8019EB24[0] - lbl_8040AF74);
        }
        fn_80027564();
    }
}

void NuTexReadBitmapMMEx(s32);
void fn_800140EC(s32);
void fn_80014180(s32, s32);
s32 fn_800274BC(s32);
void fn_80027564();
void fn_800275E0(s32);
void fn_80027830();
void fn_80027C00(s32, s32 *);
void fn_80027C54(s32, s32 *, s32 *);
void fn_800282E0();
void fn_8005D6E4();
void fn_8005D8BC();
void fn_80060F58(s32, s32);
void fn_80064984();
void fn_8006EB40();
void fn_80074374(s32);
void fn_8009EB80();
void fn_800A039C();
void fn_800A2498();
void fn_800A2A9C();
void fn_800A8FF4();
void fn_800ABDAC();
void fn_800AFF54();
void fn_800B4974();
void fn_800B4A88(f32);
void fn_800B7F70();
void fn_800B9BB8();
void fn_800BA434();
void fn_800CBD6C();
void fn_800CC9CC();
void fn_800EBD40();
void fn_800EBF2C(void *);
void fn_800F9374();
void fn_8010ACC0();
void fn_8010BC24(s32);
void fn_8011E1EC();
void fn_80121724(void *);
void fn_801258B4();
void fn_801259EC(void *);
void fn_80126C6C();
void fn_8013EA90(void *, s32, s32);
void fn_8013FA74();
void fn_8013FB08();
void fn_801410F4(s32);
extern s32 MenuHeader[];
extern f32 lbl_8019EB2C[];
extern f32 lbl_8019EB30[];
extern s32 lbl_801BC964[];
extern s32 lbl_801BC9E4[];
extern s32 lbl_8038E6FC[];
extern s32 lbl_803E04C4[];
extern s32 lbl_80408EB4;
extern f32 lbl_80408FE4;
extern f32 lbl_80408FE8;
extern f32 lbl_80408FEC;
extern s32 lbl_80409698;
extern f32 lbl_80409874;
extern s32 lbl_804098D8;
extern f32 lbl_8040A640;
extern s32 lbl_8040AF78;
extern s32 lbl_8040AF7C;
extern s32 lbl_8040AFE0;
extern s32 *lbl_8040AFE4;
extern f32 lbl_8040AFE8;
extern s32 lbl_8040AFEC;

void fn_800A0474(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f13;
    s32 temp_r11;
    s32 temp_r3;
    s32 var_r31;

    fn_800A039C();
    fn_8013FA74();
    fn_800B9BB8();
    lbl_8040AFE4 = MenuHeader;
    if ((s32) lbl_8040AFE0 == 0) {
        fn_800A8FF4(1);
    }
    temp_r3 = fn_800274BC(-1);
    if (temp_r3 != 0) {
        if (lbl_8040A628 == lbl_8040A62C) {
            AXFXSetHooks4(0xF00, lbl_8040A62C, lbl_8040A62C, lbl_8019EB2C[0]);
        } else {
            fn_80027668(0xF00, lbl_8040A628, lbl_8040A62C, lbl_8019EB2C[0]);
        }
        fn_801259EC(lbl_80409410);
    }
    if ((s32) lbl_8040AFE0 == 0) {
        fn_80074374(lbl_8040912C);
        if ((s32) lbl_8040AFE0 == 0) {
            fn_800ABDAC();
        }
    }
    fn_8013FA74();
    if (((s32) lbl_80408EA8 == 0) && ((s32) lbl_8040912C == 0) && ((s32) lbl_8040AFAC == 0)) {
        if ((s32) lbl_8040AFE0 == 0) {
            fn_800A2498();
            fn_800F9374();
            goto block_15;
        }
    } else {
block_15:
        if ((s32) lbl_8040AFE0 == 0) {
            fn_800A2A9C();
        }
    }
    if (((s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x19C))) == 3) && ((s32) lbl_8040AFE0 == 0)) {
        temp_f13 = lbl_8040AFE8 / lbl_80409874;
        if (lbl_8040A640 > temp_f13) {
            lbl_8040A640 = lbl_8040A640 - (2.0f * lbl_80408E9C);
            if (lbl_8040A640 < temp_f13) {
                lbl_8040A640 = temp_f13;
            }
        } else if (lbl_8040A640 < temp_f13) {
            lbl_8040A640 = lbl_8040A640 + (2.0f * lbl_80408E9C);
            if (lbl_8040A640 > temp_f13) {
                lbl_8040A640 = temp_f13;
            }
        }
        fn_8009CFF0(lbl_80408FE8 * lbl_8040A640, lbl_80408FEC * lbl_8040A640);
        if (lbl_80408FE4 > lbl_8019EB30[0]) {
            fn_8009CFF4(0, lbl_80408FE4);
        }
    }
    if ((s32) lbl_80408EB4 != 0) {
        var_r31 = lbl_8040AF78;
    } else {
        var_r31 = lbl_8040912C;
    }
    if (((s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x774))) != 0) && (((s32) lbl_8040AFE0 == 0) || ((s32) lbl_8040AFEC != 0))) {
        fn_800B4974();
    }
    if (temp_r3 != 0) {
        if ((s32) lbl_8040AFE0 == 0) {
            fn_8009EB80();
            fn_801258B4();
            fn_800CC9CC();
            fn_800CBD6C();
            fn_80126C6C();
            fn_8010ACC0();
            fn_800B7F70();
            fn_800BA434();
            fn_800EBF2C(lbl_80409410);
            fn_800EBD40();
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x71C))), (*(s32 *)((s8 *)(lbl_80409410) + (0x734))));
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x720))), (*(s32 *)((s8 *)(lbl_80409410) + (0x738))));
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x724))), (*(s32 *)((s8 *)(lbl_80409410) + (0x73C))));
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x72C))), (*(s32 *)((s8 *)(lbl_80409410) + (0x744))));
            fn_8013FB08();
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x730))), (*(s32 *)((s8 *)(lbl_80409410) + (0x748))));
            fn_8013FA74();
            fn_8013EA90(lbl_80409410, (*(s32 *)((s8 *)(lbl_80409410) + (0x718))), 0x40);
            fn_80121724(lbl_80409410);
            fn_80027C54(lbl_8038E6FC[0], lbl_801BC964, lbl_801BC9E4);
        }
        fn_8011E1EC();
        NuTexReadBitmapMMEx(lbl_8040AF7C);
        fn_800282E0(var_r31);
        temp_r11 = (*(s32 *)((s8 *)(lbl_80409410) + (0x198)));
        if ((temp_r11 == 0x7C) || ((*(s32 *)((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (4))) & 0x4000) || (temp_r11 == 0x7D)) {
            fn_800B4A88(lbl_8019EB2C[0]);
        }
        if (lbl_8040AF74 != lbl_8019EB2C[0]) {
            fn_800B4A88(lbl_8019EB2C[0] - lbl_8040AF74);
        }
        if ((s32) lbl_80408EA8 != 0) {
            fn_800140EC(lbl_80409698);
            fn_80014180(0xC, 0xC);
            fn_8006EB40();
        }
        fn_80027830();
        fn_80060F58(var_r31 ^ lbl_80408EA8, 1);
        fn_801410F4(lbl_804098D8);
        fn_8010BC24(var_r31);
        fn_80027564();
        fn_80027C00(var_r31, lbl_803E04C4);
        fn_800274BC(-1);
        fn_8005D8BC();
        fn_8005D6E4();
        fn_80060F58(var_r31 ^ lbl_80408EA8, 0);
        fn_800275E0(0);
        fn_80064984();
        if ((s32) lbl_80408EB4 == 0) {
            fn_800AFF54();
        }
    }
}

void fn_80027690(s32, s32, s32, s32, f32, f32, f32, f32, u32 *, s32);
void fn_80027868(s32, s32, s32, s32, f32, f32, f32, f32, u32, s32);
extern f32 lbl_8019EA8C[];
extern f32 lbl_8019EA90[];
extern f32 lbl_8019EA94[];
extern s32 lbl_80408F40;
extern s32 lbl_80408F44;
extern s32 lbl_80408F48;
extern s32 lbl_80408F4C;
struct main_mtl_s {
    u8 pad0[0xB8];
    u8 fb8;
    u8 fb9;
    u8 padba;
    u8 fbb;
    u8 fbc;
    u8 padbd;
    u8 fbe;
    u8 fbf;
    u8 fc0;
    u8 padc1[0x2F];
    f32 ff0;
    s32 ff4;
    s16 ff8;
};

extern struct main_mtl_s *lbl_8040A630;
extern s32 lbl_8040AD20;
extern s32 lbl_8040AD24;

void fn_8009E6FC(void) {
    u32 col[4];

    if (fn_800274BC(-1) != 0) {
        if (lbl_8040AF74 < lbl_8019EA8C[0]) {
            u32 c = ((s32)(lbl_8040AF74 * lbl_8019EA90[0]) << 24) | 0x808080;
            col[0] = c;
            col[1] = c;
            col[2] = c;
            col[3] = c;
            fn_80027690(lbl_80408F40, lbl_80408F44, lbl_80408F48, lbl_80408F4C, lbl_8019EA94[0], lbl_8019EA94[0], lbl_8019EA8C[0], lbl_8019EA8C[0], col, lbl_8040A630);
        } else {
            fn_80027868(0, 0, lbl_8040AD20 * 16, lbl_8040AD24 * 16, lbl_8019EA94[0], lbl_8019EA94[0], lbl_8019EA8C[0], lbl_8019EA8C[0], 0x80808080, lbl_8040A630);
        }
        fn_80027564();
    }
}

typedef struct AreaEnt { s32 pad; s32 flags; u8 pad2[0x3C]; s8 lev; u8 pad3[0x63]; } AreaEnt;
extern AreaEnt lbl_801D68E0[];
extern s32 lbl_804093AC;
extern s32 lbl_80408F30;
extern s32 lbl_80408F18;
extern s32 lbl_80408ED4;

void fn_8009E620(void) {
    s32 lev;
    LevData *p;

    lbl_80408F30 = 0;
    lev = lbl_801D68E0[lbl_804093B0].lev;
    if ((lbl_801D68E0[lbl_804093AC].flags & 0x4000) && lbl_804093B0 != 0x7B
        && (lev == -1 || (p = &lbl_801DC074[lev], !(((u8 *)p)[0x32] & 4)))) {
        lbl_80408ED4 = 1;
        lbl_80408F18 = 1;
        return;
    }
    if (lbl_8040913C == -1 && lbl_804093B0 != -1) {
        if (lbl_801D68E0[lbl_804093AC].flags & 0x4000) {
            if (lbl_804093B0 != 0x7B) {
                lbl_80408F30 = 1;
            }
        } else if (lev != -1 && lev == lbl_804093C8) {
            lbl_80408F30 = 1;
        }
    }
}

s32 OSReceiveMessage(void *, void *, s32);
s32 OSSignalSemaphore(void *);
typedef struct NetJob {
    void (*volatile run)(struct NetJob *);
    void (*volatile done)(struct NetJob *);
    u8 state;
    u8 pad1[3];
    s32 pad;
    u8 data[0x408];
} NetJob;

s32 fn_8009D41C(void) {
    s32 idx;

    for (;;) {
        OSReceiveMessage(lbl_802D5D28, &idx, 1);
        lbl_8040A624 = (s32)&((NetJob *)lbl_802D5D94)[idx];
        if ((NetJob *)lbl_8040A624 != NULL) {
            ((NetJob *)lbl_8040A624)->state |= 0x80;
            if (((NetJob *)lbl_802D5D94)[idx].run != NULL) {
                ((NetJob *)lbl_802D5D94)[idx].run((NetJob *)lbl_8040A624);
            }
            if (((NetJob *)lbl_8040A624)->done != NULL) {
                ((NetJob *)lbl_8040A624)->done((NetJob *)lbl_8040A624);
            }
            lbl_8040A624 = 0;
        }
        OSSignalSemaphore(lbl_802D5D48);
        lbl_80408E80--;
    }
}

s32 fn_800B9ED4();
extern f32 lbl_8019E9F8[];
extern f32 lbl_8019E9FC[];
extern s32 lbl_80408F0C;
extern s32 lbl_80408F10;

void fn_8009DAE8(void) {
    s32 r;

    do {
        r = 1 << (fn_800B9ED4() / 0x4000);
        lbl_80408F0C = r;
    } while (r == lbl_80408F10);
    lbl_80408F10 = r;
    lbl_80408F04 = lbl_8019E9F8[0];
    if (lbl_8040913C != -1 ||
        (lbl_804093B0 != -1 &&
         ((lbl_804093C8 != -1 && lbl_801D68E0[lbl_804093B0].lev == lbl_804093C8) ||
          (lbl_801D68E0[lbl_804093AC].flags & 0x4000)))) {
        lbl_80408F00 = lbl_8019E9FC[0];
        if (lbl_801D68E0[lbl_804093AC].flags & 0x4000) {
            if (lbl_804093B0 == 0x7D) {
                lbl_80408F18 = 1;
                lbl_80408F14 = 0;
                return;
            }
            if (lbl_804093B0 == 0x7B) {
                lbl_80408F18 = 0;
                lbl_80408F14 = 0;
                return;
            }
        }
        lbl_80408F18 = 0;
        lbl_80408F14 = 1;
    }
}

void NuStrCpy(char *, char *);
s32 NuStrICmp(char *, char *);
extern char lbl_8019E608[];
extern char lbl_8019E610[];
extern char lbl_8019E61C[];
extern char lbl_8019E620[];
extern char lbl_8019E628[];
extern char lbl_8019E634[];
extern char lbl_8019E640[];
extern char lbl_8019E644[];
extern char lbl_8019E64C[];
extern char lbl_8019E658[];
extern char lbl_8019E664[];
extern char lbl_8019E668[];
extern char lbl_8019E670[];
extern char lbl_8019E678[];
extern char lbl_8019E680[];
extern char lbl_8019E684[];
extern char lbl_8019E68C[];
extern char lbl_8019E69C[];
extern char lbl_8019E6A0[];
extern char lbl_8019E6B0[];

s32 fn_8009CD4C(char *name, char *out) {
    if (NuStrICmp(name, lbl_8019E608) == 0 || NuStrICmp(name, lbl_8019E610) == 0 || NuStrICmp(name, lbl_8019E61C) == 0) {
        NuStrCpy(out, lbl_8019E620);
        return 1;
    }
    if (NuStrICmp(name, lbl_8019E628) == 0 || NuStrICmp(name, lbl_8019E634) == 0 || NuStrICmp(name, lbl_8019E640) == 0) {
        NuStrCpy(out, lbl_8019E644);
        return 1;
    }
    if (NuStrICmp(name, lbl_8019E64C) == 0 || NuStrICmp(name, lbl_8019E658) == 0 || NuStrICmp(name, lbl_8019E664) == 0) {
        NuStrCpy(out, lbl_8019E668);
        return 1;
    }
    if (NuStrICmp(name, lbl_8019E670) == 0 || NuStrICmp(name, lbl_8019E678) == 0 || NuStrICmp(name, lbl_8019E680) == 0) {
        NuStrCpy(out, lbl_8019E684);
        return 1;
    }
    if (NuStrICmp(name, lbl_8019E68C) == 0) {
        NuStrCpy(out, lbl_8019E69C);
        return 1;
    }
    if (NuStrICmp(name, lbl_8019E6A0) == 0) {
        NuStrCpy(out, lbl_8019E6B0);
        return 1;
    }
    return 0;
}

struct main_object_context_s {
    u8 pad0[0x6c];
    u32 flags;
};

struct main_object_slot_s {
    struct main_object_context_s *obj;
    u8 pad4[0x20];
    u8 state;
    u8 pad25[0x37];
};

s32 fn_800A1B50(s32 index, s32 checkState)
{
    s32 mode, result;

    if ((checkState && !((struct main_object_slot_s *)((u8 *)lbl_803D9A58 + index * sizeof(struct main_object_slot_s)))->state)
        || (((struct main_object_context_s *)lbl_803D9A58[index * (sizeof(struct main_object_slot_s) / sizeof(s32))])->flags & 0x20000000)
        || lbl_80408FE0 != 0
        || (mode = fn_800B2ED4(), mode == 1)
        || (result = 1, mode == 0x1a)) {
        result = 0;
    }
    return result;
}

struct main_player_sub_s {
    u8 pad0[0x61C];
    s32 *f61c;
    u8 pad620[0xD8];
    f32 f6f8;
    u8 pad6fc[0x68];
    f32 f764;
};

struct main_player_s {
    u8 pad0[0x90];
    u8 f90[0x17C];
    s32 f20c;
    u8 pad210[0xCDC];
    struct main_player_sub_s *sub;
};

s32 Menu_Open(s32, s32, s32);
s32 fn_80044FD4(void);
s32 fn_8006DEE4(s32);
s32 fn_8006E11C(void);
s32 fn_800B9928(s32 *, f32);
s32 fn_800CC6C4(void);

extern struct main_player_s *gPlayer1Pointer[];
extern s32 lbl_8019EABC[];
extern s32 lbl_803E0108[];
extern s32 lbl_80408BF0;
extern s32 lbl_80408C48;
extern s32 lbl_80408F98;
extern f32 lbl_8040902C;
extern f32 lbl_80409578;
extern f32 lbl_8040AFA0;
extern f32 lbl_8040AFA4;

s32 fn_8009EC80(s32 arg0)
{
    s32 i;
    s32 temp_r3;

    lbl_8040912C = 1;
    if (lbl_80408C48 != 0 && lbl_80408BF0 != 0) {
        Menu_Open(0x3F3, 0, -1);
    } else {
        Menu_Open(2, 0, -1);
    }
    fn_800B9928(lbl_803E0108, 0.0f);
    fn_8006DEE4(0);
    fn_8006E11C();
    fn_8006DCD4(lbl_8019EABC, NULL);
    fn_80044FD4();
    lbl_80408F98 = arg0;
    lbl_8040AFA0 = 0.0f;
    lbl_80409578 = 0.0f;
    for (i = 0; i < 8; i++) {
        if (gPlayer1Pointer[i] != NULL) {
            gPlayer1Pointer[i]->sub->f6f8 = 0.0f;
            gPlayer1Pointer[i]->sub->f764 = lbl_8040902C;
        }
    }
    temp_r3 = fn_800CC6C4();
    lbl_8040AFA4 = 0.0f;
    return temp_r3;
}

struct main_tex_s {
    s32 type;
    s32 width;
    s32 height;
    s32 pad[3];
};

s32 fn_80024F10(struct main_tex_s *);
void fn_80033FC8();
void fn_8007BF60(void);

extern s32 lbl_80408F20;
extern s32 lbl_80408F28;
extern struct main_mtl_s *lbl_8040A634;
extern struct main_mtl_s *lbl_8040A638;

void fn_8009E174(void)
{
    struct main_tex_s tex;

    tex.type = 0xB;
    tex.width = 0x100;
    tex.height = 0x100;
    lbl_80408F28 = fn_80024F10(&tex);

    lbl_8040A630 = (struct main_mtl_s *)fn_80024BF0(1);
    lbl_8040A630->fbe = 3;
    lbl_8040A630->fbb = 1;
    lbl_8040A630->fbc = 1;
    lbl_8040A630->fb9 = 1;
    lbl_8040A630->fbf = 2;
    lbl_8040A630->fc0 = 1;
    lbl_8040A630->ff0 = 1.0f;
    lbl_8040A630->fb8 = 1;
    lbl_8040A630->ff8 = 0x7FFF;
    lbl_8040A630->ff4 = lbl_80408F28;
    fn_80024CD4(lbl_8040A630);
    fn_80024CD4(lbl_8040A630);
    fn_80033FC8(lbl_8040A630);

    lbl_80408F28 = 1;
    lbl_8040A634 = (struct main_mtl_s *)fn_80024BF0(1);
    lbl_8040A634->fbe = 3;
    lbl_8040A634->fbb = 1;
    lbl_8040A634->fbc = 1;
    lbl_8040A634->fb9 = 1;
    lbl_8040A634->fbf = 2;
    lbl_8040A634->fc0 = 1;
    lbl_8040A634->ff0 = 1.0f;
    lbl_8040A634->fb8 = 0;
    lbl_8040A634->ff4 = -1;
    lbl_8040A634->ff8 = 0x7FFE;

    lbl_8040A638 = (struct main_mtl_s *)fn_80024BF0(1);
    lbl_8040A638->fbe = 3;
    lbl_8040A638->fbb = 1;
    lbl_8040A638->fbc = 1;
    lbl_8040A638->fb9 = 1;
    lbl_8040A638->fbf = 2;
    lbl_8040A638->fc0 = 1;
    lbl_8040A638->ff0 = 1.0f;
    lbl_8040A638->fb8 = 1;
    lbl_8040A638->ff8 = 0x7FFE;
    lbl_8040A638->ff4 = 0;
    fn_80024CD4(lbl_8040A638);
    fn_8007BF60();
    lbl_80408F20 = 0;
}

void fn_80025C38(s32, s32, s32, s32, s32, struct main_mtl_s *);
extern f32 lbl_80408F34;
extern f32 lbl_80408F38;

void fn_8009E7DC(void)
{
    s32 alpha;
    u32 fade_dir;
    f32 tmp;
    f32 rate;

    if (lbl_80408EA8 == 0) {
        fade_dir = lbl_8040912C;
        alpha = (s32)((lbl_80408F38 * lbl_8040A63C) + ((1.0f - lbl_8040A63C) * 0.0f));
        lbl_8040A63C = (fade_dir != 0)
            ? ((rate = lbl_80408F34, tmp = (lbl_80408E9C * rate) + lbl_8040A63C) < 1.0f ? tmp : 1.0f)
            : ((tmp = lbl_8040A63C - (lbl_80408E9C * lbl_80408F34)) > 0.0f ? tmp : 0.0f);
        if (lbl_8040A63C != 0.0f) {
            fn_80025C38(0, 0, 0x2800, 0xE00, alpha << 24, lbl_8040A638);
        }
    }
}

struct main_pad_s {
    u8 pad0[0x5C];
    s32 f5c;
    s32 f60;
    s32 f64;
    u8 pad68[0x0F];
    u8 lx;
    u8 ly;
    u8 rx;
    u8 ry;
};

struct main_input_slot_s {
    struct main_pad_s *pad;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    u8 f24;
    u8 pad25[0x37];
};

struct main_area_info_s {
    s32 f00;
    s32 flags;
};

struct main_world_s {
    u8 pad0[0x198];
    s32 f198;
    s32 f19c;
    u8 pad1a0[0x08];
    struct main_area_info_s *f1a8;
};

s32 fn_800395E8(struct main_pad_s *);
extern struct main_pad_s *lbl_80408EB8;
extern s32 lbl_80409128;

s32 fn_8009ED84(s32 arg0)
{
    struct main_input_slot_s *slot;
    struct main_pad_s *pad;
    s32 mode;
    s32 res;
    f32 v;

    slot = &((struct main_input_slot_s *)lbl_803D9A58)[arg0];
    pad = slot->pad;
    if (lbl_80409118 != 0 || (lbl_80409410 != NULL && ((struct main_world_s *)lbl_80409410)->f19c == 0x15 && lbl_803E028C[0] == 5)) {
        mode = 0;
    } else if (lbl_80408FA0 != 0 || lbl_80409410 == NULL
               || ((struct main_world_s *)lbl_80409410)->f198 == 0x7C || ((struct main_world_s *)lbl_80409410)->f198 == 0x7E
               || (((struct main_world_s *)lbl_80409410)->f1a8->flags & 0x4000) || ((struct main_world_s *)lbl_80409410)->f198 == 0x7D) {
        mode = 1;
    } else {
        mode = 0;
        if (arg0 < lbl_80409128) {
            struct main_player_s *pl = gPlayer1Pointer[arg0];
            if (pl != NULL && pl->sub != NULL) {
                mode = 1;
                if (!(pl->f20c & 0x01000000)) {
                    mode = 2;
                }
            }
        }
    }
    res = 0;
    slot->f0c = 0;
    slot->f10 = 0;
    slot->f18 = 0;
    slot->f1c = 0;
    slot->f04 = 0;
    slot->f08 = 0;
    if (pad != NULL && fn_800395E8(pad) != 0 && mode > 0) {
        if (mode == 2) {
            res = 2;
            slot->f08 |= pad->f64 & 0x4000;
        } else {
            {
                f32 thresh = 85.0f;
                s32 cur;
                slot->f0c = 0;
                v = (f32)pad->rx - 127.5f;
                if (v < -thresh) {
                    slot->f0c = 4;
                } else if (v > thresh) {
                    slot->f0c = 8;
                }
                v = (f32)pad->ry - 127.5f;
                if (v < -thresh) {
                    slot->f0c |= 1;
                } else if (v > thresh) {
                    slot->f0c |= 2;
                }
                cur = slot->f0c;
                slot->f10 = cur & ~slot->f14;
                slot->f14 = cur;
                slot->f18 = 0;
            }
            {
                f32 thresh = 85.0f;
                v = (f32)pad->lx - 127.5f;
                if (v < -thresh) {
                    slot->f18 = 4;
                } else if (v > thresh) {
                    slot->f18 = 8;
                }
                v = (f32)pad->ly - 127.5f;
                if (v < -thresh) {
                    slot->f18 |= 1;
                } else if (v > thresh) {
                    slot->f18 |= 2;
                }
            }
            slot->f1c = slot->f18 & ~slot->f20;
            slot->f20 = slot->f18;
            slot->f24 = 1;
            res = 1;
            slot->f04 = pad->f5c;
            slot->f08 = pad->f64;
            lbl_80408EB8 = slot->pad;
        }
    }
    return res;
}

struct main_load_req_s {
    s32 *arg1;
    s32 val;
    char path[0x200];
};

static inline void *main_enqueue_msg(s32 arg0, s32 arg1, void *src, s32 len)
{
    NetMsg *m;
    void *tok;

    OSWaitSemaphore(lbl_802D5D48);
    m = &((NetMsg *)lbl_802D5D94)[lbl_80408E7C];
    tok = (void *)lbl_802D5D54[lbl_80408E7C];
    lbl_80408E80++;
    if (++lbl_80408E7C > 15) {
        lbl_80408E7C = 0;
    }
    m->a = arg0;
    m->b = arg1;
    m->flags &= 0x3FFFFFFF;
    if (src != NULL && len != 0) {
        memcpy(m->data, src, len);
    }
    OSSendMessage(lbl_802D5D28, tok, 0);
    return tok;
}

s32 fn_8009D320(char *arg0, s32 *arg1, s32 *arg2)
{
    struct main_load_req_s req;
    s32 val = *arg2;

    NuStrCpy(req.path, arg0);
    req.arg1 = arg1;
    req.val = val;
    lbl_80408E84++;
    main_enqueue_msg((s32)fn_8009D504, (s32)fn_8009D540, &req, sizeof(req));
    return *arg1;
}

struct main_menu_hdr_s {
    u8 pad0[0x40];
    Mtx44Blk mtx;
};

struct __attribute__((packed)) main_menu_entry_s {
    u8 pad0[0x14];
    s16 f14;
    u8 pad16[0xCA];
};

struct main_area_upd_s {
    s32 f00;
    s32 flags;
    u8 pad08[0x1C];
    void (*update)(void);
};

struct main_world_upd_s {
    u8 pad0[0x198];
    s32 f198;
    u8 pad19c[0x0C];
    struct main_area_upd_s *f1a8;
    u8 pad1ac[0x14];
    s32 f1c0;
    u8 pad1c4[0x124];
    s32 f2e8;
    u8 pad2ec[0x284];
    s32 f570;
    s32 f574;
    s32 f578;
    u8 pad57c[0x19C];
    s32 f718;
    s32 f71c;
    s32 f720;
    s32 f724;
    s32 f728;
    s32 f72c;
    s32 f730;
    s32 f734;
    s32 f738;
    s32 f73c;
    s32 f740;
    s32 f744;
    s32 f748;
    u8 pad74c[0x14];
    s32 f760;
};

void Menu_ResetAndReturn(void);
void NuTexAnimSetSignals(s32);
void UpdateBolts(void);
void __fini_cpp_exceptions(void);
void fn_80015EFC(void);
void fn_80024BB8(f32, s32);
void fn_80027BF8(s32);
void fn_80027D2C(s32);
void fn_80029050(s32, f32);
void fn_80030A0C(f32);
void fn_80030A20(void);
void fn_80043128(void **);
void fn_800434C8(void **);
void fn_80044D4C(void);
void fn_80044F6C(s32, s32);
void fn_80045000(f32);
void fn_8004504C(u8, s32);
void fn_800451B4(s32);
void fn_8004D4D0(void);
void fn_8004D600(void);
void fn_80062FF8(s32);
void fn_80064E6C(f32);
void fn_80066524(f32);
void fn_8006D69C(f32);
void fn_80071848(s32, f32);
void fn_8007373C(f32);
void fn_800ABD50(struct main_player_s *);
void fn_800AD4C4(void *, struct main_player_s *);
void fn_800AFDC0(void);
void fn_800B203C(void *);
void fn_800B3980(void);
void fn_800B594C(s32 *);
void fn_800BA1AC(f32);
void fn_800BA390(void);
void fn_800CC0F8(void);
void fn_800CC994(void);
void fn_800D0964(void);
void fn_800D197C(void);
void fn_800D5264(void);
void fn_800D88B8(void);
void fn_800E346C(void);
void fn_800E5714(void);
void fn_800E631C(void);
void fn_800E6504(void);
void fn_800EC2F4(void);
void fn_8010438C(void);
void fn_8010443C(struct main_world_upd_s *);
void fn_801052F0(struct main_world_upd_s *);
void fn_8010682C(struct main_world_upd_s *);
void fn_801070BC();
void fn_80107828(struct main_world_upd_s *);
void fn_80107DA4(struct main_world_upd_s *);
void fn_8010859C(s32);
void fn_80109314(struct main_world_upd_s *);
void fn_80109720(void);
void fn_8010AB90(f32);
void fn_8010B464(struct main_area_upd_s *, s32);
void fn_8011D78C();
void fn_8011E134(void);
void fn_8012228C(struct main_world_upd_s *);
void fn_801275D4(struct main_world_upd_s *);
void fn_80129CCC(s32);
void fn_8012BF24(s32);
void fn_8013E4DC(struct main_world_upd_s *, s32, s32);
void fn_8013EFD8(struct main_player_s *);
void fn_8013FCA0(s32, f32);
void fn_80140ACC(s32);

extern u8 lbl_803E029C[];
extern u8 lbl_803E029D[];
extern u8 lbl_803E04B9[];
extern s32 lbl_804086E8;
extern s32 lbl_80408EFC;
extern f32 lbl_80408F9C;
extern s32 lbl_80408FC4;
extern f32 lbl_80409734;
extern f32 lbl_80409A28;
extern f32 lbl_80409A2C;
extern s32 lbl_8040A628;
extern f32 lbl_8040AFD8[];

void fn_8009FB78(s32 *arg0)
{
    void *pos[8];
    s32 i;

    fn_80027BF8(lbl_80408FC4);
    fn_800E631C();
    if (lbl_8040912C == 0) {
        fn_80129CCC(((struct main_world_upd_s *)lbl_80409410)->f2e8);
    }
    lbl_8040AFD8[1] = 0.0f;
    lbl_8040AFD8[0] = 0.0f;
    Menu_ResetAndReturn();
    if (lbl_804086E8 == 0) {
        if (lbl_8040912C != 0 && ((struct main_menu_entry_s *)gMenuStack)[gMenuDepth].f14 == 4) {
            fn_8004504C(lbl_803E04B9[0], 0);
        } else {
            fn_8004504C(lbl_803E029D[0], 0);
        }
        fn_80044D4C();
        fn_800E6504();
        if (lbl_803E029C[0] != 0) {
            s32 a = (gPlayer1Pointer[0] != NULL && (gPlayer1Pointer[0]->f20c & 0x01000000)) ? *gPlayer1Pointer[0]->sub->f61c : 0;
            s32 b = (gPlayer1Pointer[1] != NULL && (gPlayer1Pointer[1]->f20c & 0x01000000)) ? *gPlayer1Pointer[1]->sub->f61c : 0;
            fn_80044F6C(a, b);
            fn_800451B4(1);
        } else {
            fn_800451B4(0);
            fn_80044F6C(0, 0);
        }
        fn_80045000(lbl_80408E9C);
        fn_8006D69C(lbl_80408E9C);
        fn_800E5714();
    }
    for (i = 0; i < 8; i++) {
        if (gPlayer1Pointer[i] != NULL) {
            pos[i] = &gPlayer1Pointer[i]->f90;
        } else {
            pos[i] = NULL;
        }
    }
    if (lbl_8040912C != 0) {
        fn_80027D2C(1);
        *lbl_8040AF5C = ((struct main_menu_hdr_s *)MenuHeader)->mtx;
        NuCameraCalcFrustrumPlanes(lbl_8040AF5C);
        fn_800B203C(lbl_803D9A58);
        for (i = 0; i < 8; i++) {
            if (gPlayer1Pointer[i] != NULL && (gPlayer1Pointer[i]->f20c & 0x01000000)) {
                fn_8013EFD8(gPlayer1Pointer[i]);
            }
        }
        fn_80062FF8(1);
    } else {
        fn_80027D2C(0);
        NuTexAnimSetSignals(lbl_80408EFC);
        fn_80015EFC();
        __fini_cpp_exceptions();
        fn_8011D78C(lbl_8040912C);
        if (((struct main_world_upd_s *)lbl_80409410)->f1a8->flags & 8) {
            fn_8004D4D0();
        }
        if (lbl_8040AFAC == 0) {
            fn_8012228C((struct main_world_upd_s *)lbl_80409410);
        }
        if (((struct main_world_upd_s *)lbl_80409410)->f578 != 0) {
            fn_8013FCA0(((struct main_world_upd_s *)lbl_80409410)->f578, lbl_80408E9C);
        }
        if (((struct main_world_upd_s *)lbl_80409410)->f570 != 0) {
            fn_8012BF24(((struct main_world_upd_s *)lbl_80409410)->f570);
        }
        if (((struct main_world_upd_s *)lbl_80409410)->f574 != 0) {
            fn_8010859C(((struct main_world_upd_s *)lbl_80409410)->f574);
        }
        if (((struct main_world_upd_s *)lbl_80409410)->f1c0 != 0) {
            fn_80029050(((struct main_world_upd_s *)lbl_80409410)->f1c0, lbl_80408E9C * 60.0f);
        }
        fn_80066524(1.0f);
        fn_80064E6C(1.0f);
        fn_800434C8(pos);
        fn_80043128(pos);
        fn_80071848(((struct main_world_upd_s *)lbl_80409410)->f760, lbl_80408E9C);
        if (((struct main_world_upd_s *)lbl_80409410)->f1a8->flags & 8) {
            fn_8004D600();
        }
        if (lbl_8040AFAC == 0) {
            fn_800D0964();
            fn_800D197C();
        } else {
            for (i = 0; i < 8; i++) {
                if (gPlayer1Pointer[i] != NULL && (gPlayer1Pointer[i]->f20c & 0x01000000) && *gPlayer1Pointer[i]->sub->f61c != 0) {
                    fn_800ABD50(gPlayer1Pointer[i]);
                }
            }
        }
        fn_8010438C();
        if (lbl_8040AFAC == 0) {
            fn_801070BC((struct main_world_upd_s *)lbl_80409410);
            fn_80107828((struct main_world_upd_s *)lbl_80409410);
            fn_8010682C((struct main_world_upd_s *)lbl_80409410);
            fn_80109314((struct main_world_upd_s *)lbl_80409410);
            fn_8010443C((struct main_world_upd_s *)lbl_80409410);
            fn_800CC994();
            fn_80107DA4((struct main_world_upd_s *)lbl_80409410);
            fn_801052F0((struct main_world_upd_s *)lbl_80409410);
            UpdateBolts();
            fn_8007373C(lbl_80408E9C);
            if (lbl_80409A28 > 0.0f) {
                lbl_80409A28 -= lbl_80408E9C;
            }
            if (lbl_80409A2C > 0.0f) {
                lbl_80409A2C -= lbl_80408E9C;
            }
            if (lbl_80409734 > 0.0f) {
                lbl_80409734 -= lbl_80408E9C;
            }
            fn_800BA390();
            fn_800EC2F4();
            fn_800D88B8();
            fn_800E346C();
        }
        if (((struct main_world_upd_s *)lbl_80409410)->f1a8->update != NULL) {
            ((struct main_world_upd_s *)lbl_80409410)->f1a8->update();
        }
        fn_800B203C(lbl_803D9A58);
        fn_80062FF8(0);
        if (lbl_8040AFAC == 0) {
            fn_80109720();
        }
        fn_80140ACC(lbl_804098D8);
        fn_80024BB8(lbl_80408E9C, 0xFFFF);
        if (gPlayer1Pointer[1] != NULL && (gPlayer1Pointer[1]->f20c & 0x01000000)
            && (gPlayer1Pointer[0] == NULL || !(gPlayer1Pointer[0]->f20c & 0x01000000))) {
            fn_800AD4C4(MenuHeader, gPlayer1Pointer[1]);
        } else {
            fn_800AD4C4(MenuHeader, gPlayer1Pointer[0]);
        }
        fn_800D5264();
        fn_800AFDC0();
        if (lbl_8040AFAC == 0) {
            fn_8010AB90(lbl_80408E9C);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f71c, ((struct main_world_upd_s *)lbl_80409410)->f734);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f720, ((struct main_world_upd_s *)lbl_80409410)->f738);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f724, ((struct main_world_upd_s *)lbl_80409410)->f73c);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f72c, ((struct main_world_upd_s *)lbl_80409410)->f744);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f730, ((struct main_world_upd_s *)lbl_80409410)->f748);
            fn_8013E4DC((struct main_world_upd_s *)lbl_80409410, ((struct main_world_upd_s *)lbl_80409410)->f718, 0x40);
            fn_801275D4((struct main_world_upd_s *)lbl_80409410);
        }
        {
            s32 area = ((struct main_world_upd_s *)lbl_80409410)->f198;
            if ((u32)(area - 0x7B) <= 1U || (((struct main_world_upd_s *)lbl_80409410)->f1a8->flags & 0x4000) || area == 0x7D) {
                fn_800BA1AC(lbl_80408E9C);
            }
        }
    }
    fn_800CC0F8();
    fn_8010B464(((struct main_world_upd_s *)lbl_80409410)->f1a8, lbl_8040912C);
    fn_8011E134();
    if (lbl_8040912C != 0) {
        if (lbl_80408F9C < 1.0f) {
            lbl_80408F9C += 2.0f * lbl_80408E9C;
            if (lbl_80408F9C > 1.0f) {
                lbl_80408F9C = 1.0f;
            }
        }
    } else {
        if (lbl_80408F9C > 0.0f) {
            lbl_80408F9C -= 2.0f * lbl_80408E9C;
            if (lbl_80408F9C < 0.0f) {
                lbl_80408F9C = 0.0f;
            }
        }
    }
    if (lbl_8040912C != 0 && lbl_80408EA8 == 0) {
        fn_80030A0C(0.0f);
    } else {
        fn_80030A0C(lbl_80408E9C / (1.0f / 60.0f));
    }
    fn_80030A20();
    fn_800B3980();
    *arg0 = fn_8009FAD8();
    fn_8009DC18();
    fn_800B594C(&lbl_8040A628);
    if ((lbl_8040913C != -1 || lbl_804093B0 != -1) && lbl_80408F00 == -0.1f) {
        fn_8009DAE8();
    }
}
