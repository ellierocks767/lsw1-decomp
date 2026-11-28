#include "types.h"

extern s32 lbl_8040B2BC;
extern s32 lbl_8040B2B8;
extern s32 lbl_8040A80C;
extern s32 lbl_8040B2CC;
void fn_80146F1C(void)
{

}

void fn_801508F4(void)
{

}

void fn_8014CF8C(void)
{
    lbl_8040B2B8 = 0;
    lbl_8040A80C = 0;
    lbl_8040B2CC = 0;
    lbl_8040B2BC = 0;
}

s32 DrawTopShelf(s32);
extern s32 gShopCurrentCategory;
extern s32 (*gShopDrawAltCallback)();

void Shop_DrawSubMenuAndTopShelf(void) {
    if (((s32 (*)()) gShopDrawAltCallback) != NULL) {
        gShopDrawAltCallback();
    }
    DrawTopShelf(gShopCurrentCategory);
}

extern s32 (*gShopDrawCallback)();
extern s32 lbl_80409B98;

void fn_8014BD04(void) {
    if (((s32) lbl_80409B98 != 0) && (((s32 (*)()) gShopDrawCallback) != NULL)) {
        gShopDrawCallback();
    }
}

s32 fn_8014ABAC();

void fn_8014BE90(void) {
    fn_8014ABAC();
}

s32 PodraceUpdateStartLights();
s32 fn_8014D7C8();
void fn_8014DA40(void);
void fn_8014EBBC(void);

void fn_8014FD9C(void) {
    fn_8014EBBC();
    PodraceUpdateStartLights();
    fn_8014DA40();
    fn_8014D7C8();
}

extern s32 lbl_804093B8;
extern s32 lbl_8040B108;

void fn_8014FE74(void) {
    s32 var_r9;

    var_r9 = 0x1B;
    if ((s32) lbl_8040B108 > 2) {
        var_r9 = 0x1E;
    }
    lbl_804093B8 = var_r9;
}

s32 fn_801451A4(void *);
extern void *lbl_80409410;

void fn_80146EF4(void) {
    fn_801451A4((*(s32 *)((s8 *)(lbl_80409410) + (0x1984))));
}

void PodraceCreateMine(void);
s32 (*fn_80009948(s32 *, s32))();
void fn_8010BD90(void);
s32 fn_80142BA8(s32, s32);
s32 memset();
extern void *lbl_80409410;
extern s32 lbl_80409C94;
extern s32 str_Assert_Podrace_NotWorking[];
extern s32 str_SourceFile_Podrace[];

void fn_8014FD18(void) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((s8 *)(lbl_80409410) + (0x198C)));
    lbl_80409C94 = temp_r0;
    if (temp_r0 == 0) {
        fn_80009948(str_SourceFile_Podrace, 0x326)(str_Assert_Podrace_NotWorking);
    }
    memset(lbl_80409C94, 0, 0xB020);
    fn_80142BA8(lbl_80409C94, 0x20);
    PodraceCreateMine();
    fn_8010BD90();
}

s32 ProcessSpaceLevel(s32);
s32 fn_800D875C(s32, s32);
s32 fn_80145F18(void *, s32 *);
extern f32 lbl_801AF6FC[];
extern s32 lbl_801E184C[];
extern u8 lbl_803E0411[];
extern f32 lbl_803E8420[];
extern s32 lbl_804093D0;
extern void *lbl_80409410;
extern u8 lbl_8040B060[];

void fn_80146DF8(void) {
    fn_80145F18(lbl_80409410, lbl_801E184C);
    ProcessSpaceLevel((*(s32 *)((s8 *)(lbl_80409410) + (0x1984))));
    if (((s32) lbl_804093D0 == 0) && ((s32) lbl_8040B060[0] == 0) && ((s32) lbl_803E0411[0] == 0) && ((lbl_803E8420[0] >= lbl_801AF6FC[0]))) {
        fn_800D875C(0x26A, 0);
        lbl_8040B060[0] = 1;
    }
}

void fn_801470AC(void) {
    volatile s32 pad[4];
}

s32 fn_800130F4(void *);
s32 fn_80013200(void *, s32);
typedef struct { s32 a, b, c; } PodSnd12;
extern PodSnd12 lbl_80407154[];

void fn_8014D01C(u32 arg0) {
    s32 i;

    if (arg0 <= 2U) {
        for (i = 0; i < 3; i++) {
            if (fn_800130F4(&lbl_80407154[i]) != 0) {
                fn_80013200(&lbl_80407154[i], 0);
            }
        }
        if (fn_800130F4(&lbl_80407154[arg0]) != 0) {
            fn_80013200(&lbl_80407154[arg0], 1);
        }
    }
}

s32 PodraceUpdateStartLights();
s32 fn_8014D1F8();
void fn_8014EBBC(void);
extern PodSnd12 lbl_803EAD24[];

void fn_8014FFE8(void) {
    s32 i;

    fn_8014EBBC();
    PodraceUpdateStartLights();
    fn_8014D1F8();
    if ((s32) lbl_8040B060[0] == 1) {
        for (i = 0; i < 10; i++) {
            if (fn_800130F4(&lbl_803EAD24[i]) != 0) {
                fn_80013200(&lbl_803EAD24[i], 1);
            }
        }
        lbl_8040B060[0] = 2;
    }
}

void PodraceCreateMine(void);
s32 (*fn_80009948(s32 *, s32))();
#define fn_8010BD90 ((s32(*)(void))fn_8010BD90)
#define fn_80142BA8 ((s32(*)(s32, s32))fn_80142BA8)
s32 memset();
extern f32 lbl_801AFF48[];
extern s32 lbl_80409CFC;
extern s32 lbl_8040A820;
extern s32 lbl_8040A824;

void fn_8014FE90(void) {
    void *temp_r0;

    temp_r0 = (*(void **)((s8 *)(lbl_80409410) + (0x198C)));
    lbl_80409C94 = temp_r0;
    if (temp_r0 == NULL) {
        fn_80009948(str_SourceFile_Podrace, 0x326)(str_Assert_Podrace_NotWorking);
    }
    memset(lbl_80409C94, 0, 0xB020);
    fn_80142BA8(lbl_80409C94, 0x20);
    PodraceCreateMine();
    fn_8010BD90();
    lbl_80409CFC = 0;
    lbl_8040A820 = 0;
    lbl_8040A824 = 1;
    if ((s32) lbl_8040B108 <= 1) {
        (*(f32 *)((s8 *)(lbl_80409C94) + (0xB000))) = (f32) lbl_801AFF48[0];
    }
}
#undef fn_8010BD90
#undef fn_80142BA8

s32 NuSpecialFindMultiWC(s32 *, s32);
s32 fn_800133FC(void *);
extern s32 lbl_80407184[];
extern PodSnd12 lbl_80407190[];

void fn_8014CFA4(void) {
    s32 i;

    for (i = 0; i < lbl_8040B2BC; i++) {
        if (fn_800130F4(&lbl_80407190[i]) != 0) {
            NuSpecialFindMultiWC(lbl_80407184, fn_800133FC(&lbl_80407190[i]));
        }
    }
}

f32 AIParamToFloat(s32, s32);
s32 NuStrIStr(s32, s32 *);
extern f32 lbl_801AFF70[];
extern s32 str_Podrace_AttemptsPerIncrement[];
extern s32 str_Podrace_Increment[];
extern s32 str_Podrace_LapTime[];
extern s32 str_Podrace_MaxLapTime[];

s32 PodraceLoadLapSettings(s32 pad0, s32 pad1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5) {
    s32 p;
    s32 i;

    if ((arg5 != 0) && ((*(f32 *)((s8 *)(lbl_80409C94) + (0xB00C))) == lbl_801AFF70[0])) {
        for (i = 0; i < arg4; i++) {
            if ((p = NuStrIStr(arg3[i], str_Podrace_MaxLapTime)) != 0) {
                (*(f32 *)((s8 *)(lbl_80409C94) + (0xB010))) = AIParamToFloat(arg2, p + 0xB);
            } else if ((p = NuStrIStr(arg3[i], str_Podrace_LapTime)) != 0) {
                (*(f32 *)((s8 *)(lbl_80409C94) + (0xB00C))) = AIParamToFloat(arg2, p + 8);
            } else if ((p = NuStrIStr(arg3[i], str_Podrace_AttemptsPerIncrement)) != 0) {
                (*(s32 *)((s8 *)(lbl_80409C94) + (0xB018))) = (s32) AIParamToFloat(arg2, p + 0x18);
            } else if ((p = NuStrIStr(arg3[i], str_Podrace_Increment)) != 0) {
                (*(f32 *)((s8 *)(lbl_80409C94) + (0xB014))) = AIParamToFloat(arg2, p + 0xA);
            }
        }
        if ((*(f32 *)((s8 *)(lbl_80409C94) + (0xB010))) == lbl_801AFF70[0]) {
            (*(f32 *)((s8 *)(lbl_80409C94) + (0xB010))) = (*(f32 *)((s8 *)(lbl_80409C94) + (0xB00C)));
        }
    }
    return 1;
}

f32 AIParamToFloat(s32, s32);
s32 NuStrIStr(s32, s32 *);
extern f32 lbl_80409D00;
extern f32 lbl_80409D04;
extern f32 lbl_80409D08;
extern f32 lbl_80409D0C;
extern f32 lbl_80409D14;
extern s32 str_Podrace_MaxTimeAvailable[];
extern s32 str_Podrace_TimeAvailable[];
extern s32 str_Podrace_TimeIncrement[];
extern s32 str_Podrace_TriggerCollapse[];
extern s32 str_Podrace_TriggerCrash[];

s32 PodraceLoadTimeTrialSettings(s32 pad0, s32 pad1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 var_r28;
    s32 var_r29;

    if ((arg5 != 0) && ((s32) lbl_80409CFC == 0)) {
        for (var_r28 = 0; var_r28 < arg4; var_r28++) {
            var_r29 = var_r28 * 4;
            {
                temp_r3 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_TriggerCrash);
                if (temp_r3 != 0) {
                    lbl_80409D00 = AIParamToFloat(arg2, temp_r3 + 0xE);
                } else {
                    temp_r3_2 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_TriggerCollapse);
                    if (temp_r3_2 != 0) {
                        lbl_80409D04 = AIParamToFloat(arg2, temp_r3_2 + 0x11);
                    } else {
                        temp_r3_3 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_MaxTimeAvailable);
                        if (temp_r3_3 != 0) {
                            lbl_80409D0C = AIParamToFloat(arg2, temp_r3_3 + 0x13);
                        } else {
                            temp_r3_4 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_TimeAvailable);
                            if (temp_r3_4 != 0) {
                                lbl_80409D08 = AIParamToFloat(arg2, temp_r3_4 + 0xF);
                            } else {
                                temp_r3_5 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_TimeIncrement);
                                if (temp_r3_5 != 0) {
                                    lbl_80409D14 = AIParamToFloat(arg2, temp_r3_5 + 0xF);
                                } else {
                                    temp_r3_6 = NuStrIStr(*(s32 *)(var_r29 + arg3), str_Podrace_AttemptsPerIncrement);
                                    if (temp_r3_6 != 0) {
                                        lbl_8040A824 = (s32) AIParamToFloat(arg2, temp_r3_6 + 0x18);
                                    }
                                }
                            }
                        }
                    }
                }
                if (lbl_80409D0C < lbl_80409D08) {
                    lbl_80409D0C = lbl_80409D08;
                }
            }
        }
        lbl_80409CFC = 1;
    }
    return 1;
}

s32 FindForceObject(void *, s32 *, s32);
s32 FindObstacle(void *, s32);
s32 NuSpecialFind(s32, void *, s32 *, s32);
s32 fn_800B9ED4();
extern s32 lbl_801AFC08[];
extern s32 lbl_801AFC14[];
extern s32 *lbl_801E1924[];
extern s32 lbl_801E193C[];
extern s32 *lbl_801E1948[];
extern s32 *lbl_801E1954[];
extern s32 lbl_80407100[];
extern PodSnd12 lbl_8040710C[];
extern s32 lbl_80407178[];
extern s8 lbl_80409C8C;
extern s32 lbl_8040B2AC;
extern s32 lbl_8040B2B0;
extern s32 lbl_8040B2B4;

void fn_8014C728(void *arg0) {
    s32 i;

    lbl_8040B2AC = lbl_80407100[0] = (fn_800B9ED4() / 21846) + 3;
    for (i = 0; i < 6; i++) {
        NuSpecialFind(*(s32 *)((s8 *)arg0 + 0x1C0), &lbl_8040710C[i], lbl_801E1924[i], 1);
    }
    for (i = 0; i < 3; i++) {
        NuSpecialFind(*(s32 *)((s8 *)arg0 + 0x1C0), &lbl_80407154[i], lbl_801E1948[i], 1);
    }
    fn_8014D01C(lbl_8040B2AC - 3);
    for (i = 0; i < 3; i++) {
        lbl_80407178[i] = FindObstacle(arg0, lbl_801E193C[i]);
    }
    lbl_8040B2B0 = FindForceObject(arg0, lbl_801AFC08, 0);
    NuSpecialFind(*(s32 *)((s8 *)arg0 + 0x1C0), lbl_80407184, lbl_801AFC14, 1);
    for (i = 0; i < 3; i++) {
        NuSpecialFind(*(s32 *)((s8 *)arg0 + 0x1C0), &lbl_80407190[i], lbl_801E1954[i], 1);
    }
    lbl_8040B2B4 = 0;
    lbl_8040B2B8 = 0;
    lbl_8040A80C = 0;
    lbl_8040B2BC = 0;
    lbl_80409C8C = 0;
}

s32 PodraceUpdateStartLights();
s32 fn_800133FC(void *);
s32 fn_800137D0(void *, s32);
void fn_8011E9C4(s32);
void fn_8014EBBC(void);
extern f32 NuRndrHackWaterLevel[];
extern f32 lbl_801AFEA4[];
extern f32 lbl_801AFEA8[];
extern f32 lbl_801AFEAC[];
extern f32 lbl_803E01C4[];
extern u8 lbl_803E03C1[];
extern f32 lbl_80408E9C;
extern void *lbl_80409CF8;
extern f32 lbl_80409D10;

void fn_8014F058(void) {
    if (lbl_8040B108 == 2 && *(f32 *)((s8 *)lbl_80409C94 + 0xB004) > lbl_801AFEA4[0] && lbl_80409CFC != 0) {
        switch (lbl_8040B060[1]) {
        case 0:
            if (lbl_803E01C4[0] > lbl_80409D00) {
                fn_8011E9C4(0x17);
                lbl_8040B060[1] = 1;
            }
            break;
        case 1:
            if (lbl_80409CF8 != NULL && (*(s32 *)((s8 *)lbl_80409CF8 + 0x88) & 0x80000)) {
                fn_8011E9C4(0x18);
                lbl_8040B060[1] = 2;
                lbl_80409D10 = lbl_80409D08;
            }
            break;
        case 2:
            lbl_80409D10 -= lbl_80408E9C;
            if (lbl_80409D10 < lbl_801AFEA8[0]) {
                fn_8011E9C4(0x19);
                lbl_8040A820++;
                if (lbl_8040A824 > 0 && lbl_8040A820 % lbl_8040A824 == 0) {
                    lbl_80409D08 += lbl_80409D14;
                    if (lbl_80409D08 > lbl_80409D0C) {
                        lbl_80409D08 = lbl_80409D0C;
                    }
                }
                lbl_8040B060[1] = 4;
            } else if (lbl_803E01C4[0] > lbl_80409D04) {
                lbl_8040B060[1] = 3;
            }
            break;
        case 3:
            if (fn_800130F4(lbl_803EAD24) != 0 && fn_800137D0(lbl_803EAD24, fn_800133FC(lbl_803EAD24)) == 0) {
                lbl_8040B060[1] = 4;
            }
            break;
        case 4:
            break;
        }
    }
    fn_8014EBBC();
    PodraceUpdateStartLights();
    if (lbl_8040B108 == 1 && lbl_8040B060[0] == 0 && lbl_803E03C1[0] == 0 && NuRndrHackWaterLevel[0] >= lbl_801AFEAC[0]) {
        fn_800D875C(0x27E, 0);
        lbl_8040B060[0] = 1;
    }
}

s32 fn_800D6C50(u8, s32, f32, s32, s32, u8, s32, f32, s32, s32);
s32 fn_8014BBE0();
extern s32 Shop_UpdateCodes[];
extern s32 Shop_UpdateMainMenu[];
extern s32 Shop_UpdateSubMenu[];
extern s32 gShopUpdateCallback;
extern f32 lbl_801AF9A8[];
extern f32 lbl_801AF9AC[];
extern u8 lbl_8040B0DC;
extern u8 lbl_8040B0DD;

void fn_8014BD40(void) {
    f32 scale = lbl_801AF9A8[0];
    s32 a = -1;
    s32 b = -1;

    if (gShopUpdateCallback == (s32)Shop_UpdateMainMenu) {
        a = 0x2D6;
        b = 0x2C5;
    } else if (gShopUpdateCallback == (s32)Shop_UpdateSubMenu) {
        a = 0x342;
        if (fn_8014BBE0() == 0) {
            scale = lbl_801AF9AC[0];
        }
        b = 0x2D7;
    } else if (gShopUpdateCallback == (s32)Shop_UpdateCodes) {
        a = 0x2D6;
        b = 0x2D7;
    }
    if (a != -1 || b != -1) {
        fn_800D6C50(lbl_8040B0DC, a, scale, -1, b, lbl_8040B0DD, a, scale, -1, b);
    }
}

extern s32 lbl_80409AF8;
void fn_80147088(void *arg0) {
    s32 old = lbl_80409AF8;
    *(s32 *)((s8 *)arg0 + 0x1984) = 0;
    if (old == *(s32 *)((s8 *)arg0 + 0x1988)) {
        lbl_80409AF8 = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x1988) = 0;
}

extern s32 lbl_801E1830[];
void fn_80146D34(void) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        lbl_801E1830[i] = -1;
    }
}

void fn_8006E370(f32);
void fn_80146C74(void) {
    fn_8006E370(*(f32 *)(*(s8 **)((s8 *)lbl_80409410 + 0x1984) + 0x6371C));
}

s32 fn_80145BCC(s32);
s32 fn_80146588(s32, s32, s32, s32, s32);
#define fn_801470AC ((void (*)(void *))fn_801470AC)
extern s32 lbl_80409AE0;
extern s32 lbl_8040B27C;

void fn_80146E94(void) {
    fn_80145BCC(*(s32 *)((s8 *)lbl_80409410 + 0x1984));
    if (lbl_80409AE0 != 0 && lbl_8040B27C != 0) {
        fn_80146588(*(s32 *)((s8 *)lbl_80409410 + 0x2DC), lbl_80409AE0, 4, 5, 8);
    }
    fn_801470AC(lbl_80409410);
}
#undef fn_801470AC

extern f32 lbl_801AFF50[];
extern f32 lbl_801AFF54[];
extern f32 lbl_801AFF58[];

s32 fn_80150068(void) {
    if (*(s32 *)((s8 *)lbl_80409410 + 0x198) == 0x1B && lbl_8040B108 == 2 &&
        *(f32 *)((s8 *)lbl_80409C94 + 0xB004) > lbl_801AFF50[0] && lbl_80409CFC != 0 &&
        lbl_803E01C4[0] > lbl_80409D00 - lbl_801AFF54[0] && lbl_803E01C4[0] <= lbl_80409D00 + lbl_801AFF58[0]) {
        return 1;
    }
    return 0;
}

extern f32 lbl_801AFF5C[];
extern f32 lbl_801AFF60[];

s32 fn_801500F0(void) {
    if ((s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x198))) == 0x1C && (s32) lbl_8040B108 == 3 && lbl_803E01C4[0] > lbl_801AFF5C[0] && (*(f32 *)((s8 *)(lbl_80409C94) + (0xB004))) < ((((*(f32 *)((s8 *)(lbl_80409C94) + (0xB00C))) - lbl_801AFF60[0]) + lbl_803E01C4[0]) - lbl_801AFF5C[0])) {
        return 1;
    }
    return 0;
}

extern f32 lbl_801AFF64[];
extern f32 lbl_801AFF68[];

s32 fn_8015015C(void) {
    if ((s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x198))) == 0x1B && (s32) lbl_8040B108 == 1 && lbl_803E01C4[0] > lbl_801AFF64[0] && (*(f32 *)((s8 *)(lbl_80409C94) + (0xB004))) < ((((*(f32 *)((s8 *)(lbl_80409C94) + (0xB00C))) - lbl_801AFF68[0]) + lbl_803E01C4[0]) - lbl_801AFF64[0])) {
        return 1;
    }
    return 0;
}

void fn_800958F8(s32, s32, s32);
void fn_80074D14(s32, s32, s32);
extern u8 lbl_804072F4[];

void fn_801501C8(s32 arg0) {
    u8 *p = lbl_804072F4;

    if (*(s16 *)(p + 0x73E) != -1) {
        fn_800958F8(*(s32 *)((s8 *)lbl_80409410 + 0x1B8), *(s16 *)(p + 0x73E), arg0 + 0x30);
    }
    if (*(s32 *)(p + 0x740) != -1) {
        fn_80074D14(*(s32 *)(p + 0x740), arg0 + 0x30, 1);
    }
}

extern s32 lbl_80409C90;
s32 fn_8014D0A8();
extern f32 lbl_801AFF4C[];
extern s32 lbl_80409C98;
extern s32 lbl_8040A810;
extern s32 lbl_8040B068;

void fn_8014FF48(void) {
    s8 *p = (s8 *)lbl_80409C94;

    *(f32 *)(p + 0xB004) = lbl_801AFF4C[0];
    memset(p + 0xA600, 0, 0xA00);
    lbl_80409C98 = 0;
    lbl_8040A810 = -1;
    switch (lbl_8040B108) {
    case 1:
        lbl_8040B068 = 2;
        break;
    case 2:
        lbl_8040B068 = 5;
        break;
    case 3:
        lbl_8040B068 = 8;
        break;
    }
    lbl_80409C90 = 0;
    fn_8014D0A8();
}

int sprintf(void *, void *, ...);
extern s32 lbl_803E04F0[];
extern u8 lbl_803EACDE[];
extern s32 lbl_804091F8;
extern s32 str_Podrace_Boost[];

void PodraceInitBoost(void) {
    s32 i;
    s32 temp_r0;

    temp_r0 = *(s32 *)((s8 *)lbl_80409410 + 0x198C);
    lbl_80409C94 = temp_r0;
    if (temp_r0 == 0) {
        fn_80009948(str_SourceFile_Podrace, 0x326)(str_Assert_Podrace_NotWorking);
    }
    memset(lbl_80409C94, 0, 0xB020);
    fn_80142BA8(lbl_80409C94, 0x20);
    PodraceCreateMine();
    fn_8010BD90();
    lbl_8040B060[0] = 0;
    for (i = 0; i < 10; i++) {
        sprintf(lbl_803E04F0, str_Podrace_Boost, i + 1);
        NuSpecialFind(*(s32 *)((s8 *)lbl_80409410 + 0x1C0), &lbl_803EAD24[i], lbl_803E04F0, 1);
    }
    if (lbl_804091F8 != 0 || lbl_803EACDE[0] != 0) {
        for (i = 0; i < 10; i++) {
            if (fn_800130F4(&lbl_803EAD24[i]) != 0) {
                fn_80013200(&lbl_803EAD24[i], 1);
            }
        }
        lbl_8040B060[0] = 2;
        return;
    }
    for (i = 0; i < 17; i++) {
        if (fn_800130F4(&lbl_803EAD24[i]) != 0) {
            fn_80013200(&lbl_803EAD24[i], 0);
        }
    }
}

s32 fn_8011EBF4(void *, s32);
s32 fn_8003AD00(void);
extern f32 lbl_801AFEA0[];
extern s32 str_Podrace_CollapsingMush[];

s32 PodraceCreateCollapsingMush(void) {
    s32 r;
    s8 *p = (s8 *)lbl_80409C94;

    *(f32 *)(p + 0xB004) = lbl_801AFEA0[0];
    memset(p + 0xA600, 0, 0xA00);
    lbl_80409C98 = 0;
    lbl_8040A810 = -1;
    switch (lbl_8040B108) {
    case 1:
        lbl_8040B068 = 1;
        break;
    case 2:
        lbl_8040B068 = 4;
        break;
    case 3:
        lbl_8040B068 = 7;
        break;
    }
    lbl_80409C90 = 0;
    lbl_8040B060[0] = 0;
    lbl_8040B060[1] = 0;
    lbl_80409CF8 = (void *)fn_8011EBF4(lbl_80409410, 0x17);
    r = NuSpecialFind(*(s32 *)((s8 *)lbl_80409410 + 0x1C0), lbl_803EAD24, str_Podrace_CollapsingMush, 1);
    if (lbl_8040B108 <= 2) {
        r = fn_8011EBF4(lbl_80409410, 0x18);
        if (r != 0) {
            r = fn_8003AD00();
        }
    }
    return r;
}

f32 NuFmod(f32, f32);
void fn_8007AC80(void *, f32, f32, f32, f32, f32, f32, s32, u8, u8, u8, u8);
void fn_800D9264(f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, void *, s32);
extern f32 lbl_801AFDD0[];
extern f32 lbl_801AFDD4[];
extern f32 lbl_801AFDD8[];
extern f32 lbl_801AFDDC[];
extern f32 lbl_801AFDE0[];
extern f32 lbl_8040953C;
extern f32 lbl_80409CE8;
extern f32 lbl_80409CEC;
extern f32 lbl_80409CF0;
extern f32 lbl_8040A814;
extern f32 lbl_8040A818;
extern f32 lbl_8040A81C;
extern s32 str_Format_Int[];

void fn_8014E734(void) {
    s32 off;
    s8 *b;
    f32 t;
    f32 s;

    if (lbl_8040A814 > lbl_801AFDD0[0]) {
        off = (lbl_8040B108 + 0xD1) * 0x10;
        b = (s8 *)lbl_80409410 + 0x774;
        if (*(s32 *)(b + off) != 0) {
            fn_800D9264(lbl_801AFDD0[0], lbl_8040953C, lbl_801AFDD4[0], lbl_80409CE8, lbl_80409CE8, lbl_80409CE8, lbl_8040A814, 0, 0, 0, (s8 *)lbl_80409410 + (off + 0x76C), 0);
        }
    }
    if (lbl_8040A818 > lbl_801AFDD0[0] && *(f32 *)((s8 *)lbl_80409C94 + 0xB008) > lbl_801AFDD0[0]) {
        sprintf(lbl_803E04F0, str_Format_Int, (s32)*(f32 *)((s8 *)lbl_80409C94 + 0xB008) + 1);
        t = NuFmod(*(f32 *)((s8 *)lbl_80409C94 + 0xB008), lbl_801AFDD4[0]);
        if (t >= lbl_801AFDD8[0]) {
            s = (t - lbl_801AFDD8[0]) / lbl_801AFDDC[0] + lbl_801AFDD4[0];
        } else {
            s = lbl_801AFDD4[0];
        }
        s *= lbl_80409CF0;
        fn_8007AC80(lbl_803E04F0, lbl_801AFDD0[0], lbl_80409CEC, lbl_801AFDD4[0], s, s, s, 0, 0xFF, 0x3F, 0, lbl_8040A818 * lbl_801AFDE0[0]);
    }
    if (lbl_8040A81C != lbl_801AFDD0[0] && *(f32 *)((s8 *)lbl_80409C94 + 0xB000) > lbl_801AFDD0[0]) {
        sprintf(lbl_803E04F0, str_Format_Int, (s32)*(f32 *)((s8 *)lbl_80409C94 + 0xB000) + 1);
        t = NuFmod(*(f32 *)((s8 *)lbl_80409C94 + 0xB000), lbl_801AFDD4[0]);
        if (t >= lbl_801AFDD8[0]) {
            s = (t - lbl_801AFDD8[0]) / lbl_801AFDDC[0] + lbl_801AFDD4[0];
        } else {
            s = lbl_801AFDD4[0];
        }
        s *= lbl_80409CF0;
        fn_8007AC80(lbl_803E04F0, lbl_801AFDD0[0], lbl_80409CEC, lbl_801AFDD4[0], s, s, s, 0, 0, 0xFF, 0, lbl_8040A81C * lbl_801AFDE0[0]);
    }
}

extern void *lbl_8040A7E8;
extern void *lbl_8040B0A4;
typedef struct { s32 a, b, c; } PodV12;

void fn_8014BE18(PodV12 *out) {
    if (gShopUpdateCallback == (s32)Shop_UpdateMainMenu && lbl_8040A7E8 != NULL && gShopCurrentCategory != -1) {
        *out = *(PodV12 *)(*(s8 **)((s8 *)lbl_8040A7E8 + 8) + gShopCurrentCategory * *(s16 *)((s8 *)lbl_8040A7E8 + 2));
        return;
    }
    *out = *(PodV12 *)lbl_8040B0A4;
}

typedef struct PodracePlayerTiming {
    u8 opaque[0x62c];
    f32 value62c;
} PodracePlayerTiming;

extern PodracePlayerTiming *gPlayer1Pointer[];

void fn_80146CA4(void)
{
    f32 first = gPlayer1Pointer[0]->value62c;
    f32 second;

    if (first > 435.0f || (second = gPlayer1Pointer[1]->value62c) > 435.0f) {
        fn_8006E370(133.1f);
    } else if (first > 196.0f || second > 196.0f) {
        fn_8006E370(59.449684f);
    } else {
        fn_8006E370(0.0f);
    }
}

void fn_8007B298(char *, f32, f32, f32, f32, f32, f32, s32, u8, u8, u8, f32, s32, void *, s32, s32);

extern char str_Format_StringExclaim[];
extern char *gShopUnlockedCodeItem;
extern f32 lbl_80409BF4;
extern f32 lbl_80409BF8;
extern f32 lbl_80409C30;
extern f32 lbl_80409C34;
extern u8 lbl_80409C38;

void Shop_DrawCodeBuyFeedback(void)
{
    char text[256];

    sprintf(text, str_Format_StringExclaim, gShopUnlockedCodeItem);
    if (lbl_80409BF4 > 0.0f && gShopUnlockedCodeItem != NULL) {
        if (lbl_80409BF4 == lbl_80409BF8) {
            lbl_80409C38 = 0;
            lbl_80409C34 = lbl_80409C30;
        }
        if (lbl_80409C34 <= 0.0f) {
            lbl_80409C38 = !lbl_80409C38;
            lbl_80409C34 = lbl_80409C30;
        }
        if (lbl_80409C38) {
            fn_8007B298(text, 0.0f, -0.5f, 1.0f, 0.75f, 0.75f, 0.75f,
                        0, 255, 255, 255, 1.0f, 1, NULL, 0, 128);
        }
        lbl_80409BF4 -= lbl_80408E9C;
        lbl_80409C34 -= lbl_80408E9C;
    }
}

typedef struct PodraceSpaceEntry {
    u8 opaque0[0x400];
    u32 word400;
    f32 value404;
    f32 value408;
    u8 opaque40c[0x108];
    u32 word514;
    u32 word518;
    u8 opaque51c[0x14];
} PodraceSpaceEntry;

typedef struct PodraceSpaceEntries {
    u8 opaque[0x34d0];
    PodraceSpaceEntry entries[256];
} PodraceSpaceEntries;

typedef struct PodraceSpaceScene {
    u8 opaque0[0x198];
    s32 level;
    u8 opaque19c[0x17e8];
    PodraceSpaceEntries *space;
} PodraceSpaceScene;

void fn_80146D5C(void)
{
    s32 i;
    s32 offset;
    PodraceSpaceEntry *entry;

    fn_801451A4(((PodraceSpaceScene *)lbl_80409410)->space);
    for (i = 0, offset = 0; i < 256; ++i, offset += 0x530) {
        PodraceSpaceEntries *space = ((PodraceSpaceScene *)lbl_80409410)->space;
        PodraceSpaceEntries *offsetSpace = (PodraceSpaceEntries *)((u8 *)space + offset);
        offsetSpace->entries[0].word400 = 0;
    }

    if (((PodraceSpaceScene *)lbl_80409410)->level == 0x56) {
        fn_80142BA8((s32)((PodraceSpaceScene *)lbl_80409410)->space->entries, 256);
    }

    entry = ((PodraceSpaceScene *)lbl_80409410)->space->entries;
    for (i = 0; i < 256; ++i, ++entry) {
        entry->value404 = entry->value408;
        entry->word518 = entry->word514;
    }
}

typedef struct ShopItem {
    char name[0x40];
    char modelName[0x30];
    u16 id;
    u8 type;
    u8 unlocked;
    s32 price;
    u8 opaque[0x18];
} ShopItem;

typedef struct ShopSaveView {
    u8 opaque0[0x1d0];
    u16 extraUnlocked;
    u8 opaque1d2[0x2e];
    u32 extraPurchased;
    s32 studs;
} ShopSaveView;

extern ShopSaveView lbl_803E0298;
extern u64 lbl_803E0458[];
extern u64 lbl_803E0460[];
extern s32 gShopExtraItemCount;
extern f32 lbl_80409BA4;
extern f32 lbl_8040A7D8;
extern char str_Shop_BuyCheat[];
extern u8 lbl_80401834[];
extern void fn_8006DCD4(char *, void *);

s32 BuyShopItem(ShopItem *items, s32 index, s32 charge)
{
    ShopItem *item = (ShopItem *)((s32)(index * sizeof(ShopItem)) + (s32)items);
    u64 *purchased;

    if (item->type == 1) {
        purchased = lbl_803E0458;
    } else if (item->type == 0) {
        purchased = lbl_803E0460;
    } else if (item->type == 3) {
        purchased = NULL;
        if (index >= 0 && index <= gShopExtraItemCount) {
            lbl_803E0298.extraUnlocked |= 1U << index;
        }
    } else {
        purchased = NULL;
    }

    if (purchased != NULL) {
        purchased[index / 64] |= 1ULL << (index % 64);
    }
    if (charge) {
        lbl_803E0298.studs -= items[index].price;
    }
    items[index].unlocked = 1;
    lbl_8040A7D8 = lbl_80409BA4;
    if (charge) {
        fn_8006DCD4(str_Shop_BuyCheat, lbl_80401834);
    }
    return 1;
}

typedef struct { s32 id; f32 val; } ShopPair;
typedef struct { char pad[0x63734]; s32 count; ShopPair pairs[256]; } ShopData;
typedef struct { char pad[0x1984]; ShopData *shop; } ShopRoot;
#define SHOP() (((ShopRoot *)lbl_80409410)->shop)
#define ID (*(s32 *)(*(char **)((char *)arg0 + 0xD4) + 0x524))
#define VAL (*(f32 *)((char *)arg0 + 0xF8))
s32 fn_80146194(void *arg0) {
    s32 i;
    i = 0;
    for (; i < SHOP()->count; i++) {
        if (SHOP()->pairs[i].id == ID && SHOP()->pairs[i].val == VAL) return 0;
    }
    if (i <= 0xFF) {
    SHOP()->pairs[i].id = ID; SHOP()->pairs[i].val = VAL; SHOP()->count++; return 1;
    }
    return 0;
}

typedef struct { s32 w[3]; } ShopIcon;
extern ShopIcon atoz0to9icon[];
extern char str_Format_ShopChar[];

void Shop_InitCodeChars(void) {
    char buf[16];
    s8 c;
    s32 i;

    c = 'a';
    i = 0;
    for (; c <= 'z'; c++, i++) {
        memset(buf, 0, 16);
        sprintf(buf, str_Format_ShopChar, c);
        NuSpecialFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), &atoz0to9icon[i], buf, 1);
    }
    for (c = '0'; c <= '9'; c++, i++) {
        memset(buf, 0, 16);
        sprintf(buf, str_Format_ShopChar, c);
        NuSpecialFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), &atoz0to9icon[i], buf, 1);
    }
}

typedef struct { s32 x, y, z; } BoltVec;
typedef struct { char pad0[0xE0]; char obj[5][0x130]; } BoltRow;
extern s32 CollideBoltStarFighter(void *, void *, void *, void *);

s32 fn_80146F20(void *arg0, void *arg1) {
    BoltVec b;
    BoltVec a;
    char *w;
    s32 i;
    s32 j;
    if (*(s32 *)((s8 *)lbl_80409410 + 0x1980) != 0) {
        w = *(char **)((s8 *)lbl_80409410 + 0x1984);
        if (w != NULL && (*(u16 *)((s8 *)arg0 + 0xE8) & 1)) {
            a = *(BoltVec *)((s8 *)arg1 + 0xC);
            b = *(BoltVec *)((s8 *)arg0 + 0x9C);
            for (i = 0; i < 8; i++) {
                if (*(s32 *)(w + 0x708 + i * 0x680) != 0) {
                    for (j = 0; j < 5; j++) {
                        if (*(s32 *)(w + 0x1F0 + i * 0x680 + j * 0x130) != 0 &&
                            CollideBoltStarFighter(arg0, w + 0xE0 + i * 0x680 + j * 0x130, &a, &b) != 0) {
                            return 1;
                        }
                    }
                }
            }
            for (j = 0; j < 96; j++) {
                if (*(s32 *)(w + 0x565E0 + j * 0x130) != 0 &&
                    CollideBoltStarFighter(arg0, w + 0x564D0 + j * 0x130, &a, &b) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

typedef struct { s16 count; s16 stride; s32 pad4; char *data; } ShopSpline;
extern ShopSpline *NuSplineFind(void *, void *);
extern s32 lbl_801AF754[];
extern s32 lbl_801AF760[];
extern s32 lbl_801AF770[];
extern PodV12 lbl_80401810[];
extern PodV12 lbl_80401864[];
extern PodV12 lbl_80401894[];
extern ShopSpline *lbl_8040A7EC;
extern ShopSpline *lbl_8040A7F0;

void Shop_InitShelfItemPositions(void) {
    s16 n0;
    s16 n1;
    s16 n2;
    s32 i;
    lbl_8040A7E8 = NuSplineFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), lbl_801AF754);
    lbl_8040A7EC = NuSplineFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), lbl_801AF760);
    lbl_8040A7F0 = NuSplineFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), lbl_801AF770);
    if (lbl_8040A7E8 != NULL && lbl_8040A7EC != NULL && lbl_8040A7F0 != NULL) {
        n0 = ((ShopSpline *)lbl_8040A7E8)->count;
        n1 = lbl_8040A7EC->count;
        n2 = lbl_8040A7F0->count;
        memset(lbl_80401810, 0, 0x54);
        memset(lbl_80401864, 0, 0x30);
        memset(lbl_80401894, 0, 0x48);
        for (i = 0; i < n0; i++) {
            lbl_80401864[i] = *(PodV12 *)(((ShopSpline *)lbl_8040A7E8)->data + i * ((ShopSpline *)lbl_8040A7E8)->stride);
        }
        for (i = 0; i < n1; i++) {
            lbl_80401810[i] = *(PodV12 *)(lbl_8040A7EC->data + i * lbl_8040A7EC->stride);
        }
        for (i = 0; i < n2; i++) {
            lbl_80401894[i] = *(PodV12 *)(lbl_8040A7F0->data + i * lbl_8040A7F0->stride);
        }
    }
}

extern s32 gShopBackPending;
extern s32 gShopDrawCallbackDepth;
extern s32 gShopDrawCallbackStack[];
extern f32 gShopMenuTransitionTimer;
extern s32 gShopPreviousSelection;
extern s32 gShopUpdateCallbackDepth;
extern s32 gShopUpdateCallbackStack[];
extern f32 lbl_80409BE4;
extern f32 lbl_80409BE8;
extern f32 lbl_80409BFC;
extern f32 lbl_8040A7DC;
extern f32 lbl_8040A7E0;
extern f32 lbl_8040B0D4;
extern s32 Shop_DrawSubMenuTitle();

s32 Shop_UpdateMenu(void) {
    s32 z;
    s32 r;
    s32 d;
    s32 n;
    s32 o;

    if (lbl_8040B0D4 < 1.0f) {
        lbl_8040B0D4 += 2.0f * lbl_80408E9C;
        if (lbl_8040B0D4 > 1.0f) lbl_8040B0D4 = 1.0f;
    }
    lbl_8040A7E0 = lbl_80409BE4;
    lbl_8040A7DC = lbl_80409BE8;
    z = gShopUpdateCallback;
    if (z == 0) {
        gShopDrawCallbackStack[z] = z;
        gShopUpdateCallback = (s32)Shop_UpdateMainMenu;
        gShopPreviousSelection = -1;
        gShopMenuTransitionTimer = lbl_80409BFC;
        gShopDrawCallback = Shop_DrawSubMenuTitle;
        gShopUpdateCallbackStack[z] = z;
        gShopCurrentCategory = z;
        gShopUpdateCallbackDepth = z;
        gShopDrawCallbackDepth = z;
        gShopBackPending = z;
    }
    r = ((s32 (*)())gShopUpdateCallback)();
    switch (r) {
    case 5:
        d = 1;
        break;
    case 6:
        n = gShopUpdateCallbackDepth;
        o = gShopUpdateCallbackStack[n];
        gShopUpdateCallbackStack[n] = 0;
        gShopUpdateCallbackDepth = n - 1;
        gShopUpdateCallback = o;
        if (gShopUpdateCallbackDepth < 0) gShopUpdateCallbackDepth = 0;
        gShopDrawAltCallback = NULL;
        n = gShopDrawCallbackDepth;
        o = gShopDrawCallbackStack[n];
        gShopDrawCallbackStack[n] = 0;
        gShopDrawCallbackDepth = n - 1;
        gShopDrawCallback = o;
        if (gShopDrawCallbackDepth < 0) gShopDrawCallbackDepth = 0;
    default:
        d = 0;
        break;
    }
    r = 1;
    if (d == 0) r = 0;
    return r;
}

void *fn_800AAD10(s32);
s32 fn_800AAE44(s32);
extern s32 gTotalStudsBalance[];

s32 SelectShopItem(ShopItem *items, s32 index) {
    s32 bought = 0;
    ShopItem *item = (ShopItem *)((s32)(index * sizeof(ShopItem)) + (s32)items);

    switch (item->type) {
    case 0:
        if (item->unlocked == 1) return 0;
        if (gTotalStudsBalance[0] < item->price) return -1;
        {
            s32 id = item->id;
            if (id >= 0) {
                if (id <= 0x84) {
                    if (!fn_800AAD10(id)) return -1;
                    bought = fn_800AAE44(id);
                }
            }
        }
        break;
    case 1:
        if (item->unlocked == 1) return 1;
        if (item->price == 0) return 1;
        if (gTotalStudsBalance[0] < item->price) return -1;
        bought = 1;
        break;
    case 3:
        if (lbl_803E0298.studs < item->price) return -1;
        if ((lbl_803E0298.extraPurchased >> item->id) & 1) return 0;
        bought = 1;
        lbl_803E0298.extraPurchased |= 1 << item->id;
        break;
    default:
        return -1;
    }
    if (bought) BuyShopItem(items, index, 1);
    return 1;
}

typedef struct ShopExtraDef { u16 nameIdx; u8 pad2[6]; s32 price; char *model; } ShopExtraDef;
typedef struct ShopSpecial { s32 w[3]; } ShopSpecial;
typedef struct ShopExtraItem {
    char name[0x40];
    char modelName[0x30];
    u16 id;
    u8 type;
    u8 unlocked;
    s32 price;
    ShopSpecial special;
    u8 pad[0x0c];
} ShopExtraItem;
extern ShopExtraItem ExtraItems[];
extern ShopExtraItem GameMenu[];
extern ShopExtraDef lbl_801D5994[];
extern char *lbl_803DED88[];
extern ShopSpecial lbl_804021DC[];
extern s32 NuStrCpy(char *, char *);
extern void NuStrCat(char *, const char *);

void Shop_InitExtras(void) {
    char buf[32];
    s32 i;

    for (i = 0; i <= 9; i++) {
        NuStrCpy(ExtraItems[i].name, lbl_803DED88[lbl_801D5994[i].nameIdx]);
        NuStrCpy(ExtraItems[i].modelName, lbl_801D5994[i].model);
        NuSpecialFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), &ExtraItems[i].special, ExtraItems[i].modelName, 1);
        ExtraItems[i].id = i;
        ExtraItems[i].type = 3;
        ExtraItems[i].unlocked = 0;
        if ((lbl_803E0298.extraUnlocked >> i) & 1) {
            ExtraItems[i].unlocked = 1;
            lbl_803E0298.extraPurchased |= 1 << i;
        }
        ExtraItems[i].price = lbl_801D5994[i].price;
    }
    gShopExtraItemCount = 10;
    for (i = 0; i < gShopExtraItemCount; i++) {
        NuStrCpy(buf, GameMenu[i].name);
        NuStrCat(buf, "b");
        NuSpecialFind(*(void **)((s8 *)lbl_80409410 + 0x1C0), &lbl_804021DC[i], buf, 1);
    }
}

typedef struct SplineKnots { u8 pad[0x400]; s32 n; u8 pad2[0xc]; f32 len; f32 knots[1]; } SplineKnots;
s32 CalcSplinePoint(void *, f32);
void fn_80146B8C(SplineKnots *s, f32 t) {
    s32 i;
    f32 lo;
    if (t >= s->len) {
        t = 1.0f;
    } else {
        for (i = 0; i < s->n; i++) {
            if (t < s->knots[i]) {
                if (i == 0) lo = 0.0f; else lo = s->knots[i - 1];
                t = (t - lo) / (s->knots[i] - lo);
                t = ((f32)i + t) / (f32)s->n;
                break;
            }
        }
    }
    CalcSplinePoint(s, t);
}

s32 fn_800E6484();
extern f32 NuRndrHackWaterLevel[];
extern f32 lbl_80408E9C;
extern f32 lbl_80408F00;
extern s32 lbl_8040912C;
extern void *lbl_80409410;
extern s32 lbl_8040A810;
extern f32 lbl_8040A814;
extern f32 lbl_8040A818;
extern f32 lbl_8040A81C;
extern s32 lbl_8040AFA8;
extern s32 lbl_8040AFAC;

void fn_8014E9B8(void) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f13;
    f32 var_f12;
    s32 prev;

    if ((lbl_80408F00 != -0.1f) || ((s32) lbl_8040AFA8 != 0) || ((s32) lbl_8040AFAC != 0)) {
        lbl_8040A814 = 0.0f;
        lbl_8040A818 = 0.0f;
        lbl_8040A81C = 0.0f;
    } else {
        if (((s32) lbl_8040912C != 0) || (((s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x198))) == 0x1B) && ((NuRndrHackWaterLevel[0] >= 1.0f)) && (NuRndrHackWaterLevel[0] < 6.0f))) {
            var_f12 = 1.0f;
        } else {
            var_f12 = 0.0f;
        }
        if (lbl_8040A814 > var_f12) {
            temp_f0 = lbl_8040A814 - (2.0f * lbl_80408E9C);
            lbl_8040A814 = temp_f0;
            if (temp_f0 < var_f12) {
                lbl_8040A814 = var_f12;
            }
        } else if (lbl_8040A814 < var_f12) {
            temp_f0_2 = lbl_8040A814 + (2.0f * lbl_80408E9C);
            lbl_8040A814 = temp_f0_2;
            if (temp_f0_2 > var_f12) {
                lbl_8040A814 = var_f12;
            }
        }
    }
    prev = lbl_8040A810;
    if (((s32) lbl_8040912C == 0) && ((void *) lbl_80409C94 != NULL) && (temp_f13 = (*(f32 *)((s8 *)(lbl_80409C94) + (0xB008))), ((temp_f13 < 1e+01f) != 0))) {
        lbl_8040A810 = (s32) temp_f13;
        if (lbl_8040A818 < 1.0f) {
            temp_f0_3 = lbl_8040A818 + (2.0f * lbl_80408E9C);
            lbl_8040A818 = temp_f0_3;
            if (temp_f0_3 > 1.0f) {
                lbl_8040A818 = 1.0f;
            }
        }
    } else {
        lbl_8040A818 = 0.0f;
    }
    if (((s32) lbl_8040A810 > 0) && ((s32) lbl_8040A810 != prev)) {
        fn_800E6484();
    }
    if (((s32) lbl_8040912C == 0) && ((void *) lbl_80409C94 != NULL) && ((*(f32 *)((s8 *)(lbl_80409C94) + (0xB000))) > 0.0f) && (lbl_8040A81C < 1.0f)) {
        temp_f0_4 = lbl_8040A81C + (2.0f * lbl_80408E9C);
        lbl_8040A81C = temp_f0_4;
        if (temp_f0_4 > 1.0f) {
            lbl_8040A81C = 1.0f;
        }
    }
}

s32 fn_8002A4B0(s32 *, s32 *, s8 *);
extern s32 lbl_80408F8C;
extern s32 lbl_80408FE0;
extern s32 lbl_80409C70;
extern s32 lbl_8040B100;
extern s8 str_Extension_Gsc2[];
extern s8 str_Path_Legal[];
extern s8 str_Path_LegalCubeDanish[];
extern s8 str_Path_LegalCubeDutch[];
extern s8 str_Path_LegalCubeEnglish[];
extern s8 str_Path_LegalCubeFrench[];
extern s8 str_Path_LegalCubeItalian[];
extern s8 str_Path_LegalCubeJap[];
extern s8 str_Path_LegalCubeSpanish[];
extern s8 str_Path_LegalCubeUS[];
extern s8 str_Path_StuffDir[];

typedef struct { s32 w[16]; } PodStruct40;
void fn_8014BFEC(s32 *arg0, void *arg1, void *arg2) {
    char sp8[0x100];
    s32 sp10C;
    volatile s32 sp108;
    s32 temp_r0;
    s32 temp_r29;
    s32 temp_r31;
    s32 temp_r3;
    s32 var_r3;
    s32 var_r9;

    temp_r29 = lbl_80408F8C;
    sp10C = temp_r29 + 0xFFC00000;
    NuStrCpy(sp8, str_Path_StuffDir);
    if ((s32) lbl_80408FE0 != 0) {
        NuStrCat(sp8, str_Path_Legal);
    } else {
        temp_r31 = lbl_8040B100;
        switch (temp_r31) {                         /* irregular */
        default:
            NuStrCat(sp8, str_Path_LegalCubeUS);
            break;
        case 1:
            NuStrCat(sp8, str_Path_LegalCubeFrench);
            lbl_80409C70 = temp_r31;
            break;
        case 2:
            NuStrCat(sp8, str_Path_LegalCubeEnglish);
            lbl_80409C70 = temp_r31;
            break;
        case 3:
            NuStrCat(sp8, str_Path_LegalCubeItalian);
            break;
        case 4:
            NuStrCat(sp8, str_Path_LegalCubeSpanish);
            break;
        case 5:
            NuStrCat(sp8, str_Path_LegalCubeDanish);
            break;
        case 6:
            NuStrCat(sp8, str_Path_LegalCubeDutch);
            break;
        case 7:
            NuStrCat(sp8, str_Path_LegalCubeJap);
            break;
        }
    }
    NuStrCat(sp8, str_Extension_Gsc2);
    sp108 = temp_r29;
    *arg0 = fn_8002A4B0(&sp10C, &sp108, sp8);
    memset(arg1, 0, 0xC);
    temp_r3 = *arg0;
    if (temp_r3 != 0) {
        NuSpecialFind(temp_r3, arg1, (s32 *) str_Path_Legal, 1);
        if (fn_800130F4(arg1) != 0) {
            *(PodStruct40 *) arg2 = *(PodStruct40 *) fn_800133FC(arg1);
        }
    }
}

typedef struct PodStartState {
    u8 pad[0xB000];
    f32 fB000, fB004, fB008, fB00C, fB010, fB014;
    s32 iB018, iB01C;
} PodStartState;
#define ST ((PodStartState *) lbl_80409C94)
s32 fn_800D4F70(void *, s32, s32, void *);
s32 fn_800D5378(void *, s32);
s32 fn_8014DDEC(void *);
extern void *gPlayerPointers[];
extern f32 lbl_80408F00;
extern s32 lbl_80409004;
extern f32 lbl_8040AFE8;
extern s8 str_Podrace_EngStartup1[];
extern s8 str_Podrace_EngStartup2[];
extern s8 str_Podrace_Go[];
extern s8 str_Podrace_Light[];

s32 PodraceUpdateStartLights(void) {
    PodracePlayerTiming **var_r10;
    PodracePlayerTiming *temp_r9;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f31;
    s32 temp_r11;
    s32 temp_r8;
    PodStartState *p;
    s32 temp_r9_2;
    s32 var_r29;
    s32 var_r30;
    s32 var_r31;
    s32 var_r3;

    temp_f31 = ST->fB000;
    if (temp_f31 > 0.0f) {
        var_r10 = gPlayer1Pointer;
        ST->fB008 = (f32) ST->fB00C;
        lbl_8040AFE8 = 0.0f;
        do {
            temp_r9 = *var_r10;
            var_r10 += 1;
            if ((temp_r9 != NULL) && ((*(s32 *)((s8 *)(temp_r9) + (0x20C))) & 0x01000000)) {
                (*(f32 *)((s8 *)((*(void **)((s8 *)(temp_r9) + (0xEEC)))) + (0x708))) = (f32) 0.0f;
            }
        } while ((s32) var_r10 <= (s32) (gPlayer1Pointer + 1));
        if (lbl_80408F00 == -0.1f) {
            ST->fB000 = (f32) (ST->fB000 - lbl_80408E9C);
        }
        if ((ST->fB000 < 2.9f) && ((temp_f31 >= 2.9f))) {
            fn_8006DCD4(str_Podrace_EngStartup1, NULL);
        }
        if ((ST->fB000 < 1.5f) && ((temp_f31 >= 1.5f))) {
            fn_8006DCD4(str_Podrace_EngStartup2, NULL);
        }
        temp_f13 = ST->fB000;
        if ((temp_f13 <= 0.0f)) {
            fn_8006DCD4(str_Podrace_Go, NULL);
        } else if ((s32) temp_f13 != (s32) temp_f31) {
            fn_8006DCD4(str_Podrace_Light, NULL);
        }
    } else {
        p = ST;
        temp_f12 = p->fB00C;
        temp_f0 = p->fB004 + lbl_80408E9C;
        p->fB004 = temp_f0;
        if (temp_f12 > 0.0f) {
            temp_f0_2 = temp_f12 - temp_f0;
            p->fB008 = temp_f0_2;
            if (temp_f0_2 < 0.0f) {
                p->fB008 = 0.0f;
                if ((PodracePlayerTiming *) *gPlayer1Pointer != NULL) {
                    temp_r8 = (*(s32 *)((s8 *)(*gPlayer1Pointer) + (0x20C))) & 0x01000000;
                    if (temp_r8 != 0) {
                        fn_800D5378(*gPlayer1Pointer, 1);
                    }
                }
                if (((void *) gPlayerPointers[0] != NULL) && ((*(s32 *)((s8 *)(gPlayerPointers[0]) + (0x20C))) & 0x01000000)) {
                    fn_800D5378(gPlayerPointers[0], 1);
                }
                lbl_80409C98 = 1;
                fn_800D4F70(lbl_80409004, 3, 1, 0);
                p = ST;
                temp_f12_2 = p->fB00C;
                temp_f13_2 = p->fB010;
                temp_r9_2 = p->iB01C + 1;
                p->iB01C = temp_r9_2;
                if (temp_f12_2 < temp_f13_2) {
                    temp_r11 = p->iB018;
                    if ((temp_r11 != 0) && (temp_r9_2 == (s32) ((temp_r9_2 / temp_r11) * temp_r11))) {
                        temp_f0_3 = temp_f12_2 + p->fB014;
                        p->fB00C = temp_f0_3;
                        if (temp_f0_3 > temp_f13_2) {
                            p->fB00C = temp_f13_2;
                        }
                    }
                }
            }
        }
    }
    var_r29 = 0;
    var_r31 = 0xA600;
    var_r30 = 0x10;
    do {
        var_r3 = lbl_80409C94;
        if ((s32) (*(s32 *)((s8 *)((var_r3 + var_r29)) + (0xA694))) != 0) {
            var_r3 = fn_8014DDEC(var_r3 + var_r31);
        }
        var_r31 += 0xA0;
        var_r29 += 0xA0;
        var_r30 -= 1;
    } while (var_r30 != 0);
    return var_r3;
}

typedef struct PodSpecEnt {
    s32 active;
    f32 pos[4];
    f32 scale;
    u16 rotY;
    u16 rotX;
} PodSpecEnt;
extern PodSpecEnt lbl_80407300[0x40];
void NuMtxTranslate(void *, void *);
void fn_8000DCE0(void *, void *);
void fn_8000E318(void *, s32);
void fn_8000E498(void *, s32);

void fn_8014FDC8(void) {
    s32 mtx[0x10];
    f32 scale[3];
    PodSpecEnt *e;
    s32 i;

    if (fn_800130F4(lbl_804072F4) != 0) {
        e = lbl_80407300;
        i = 0x40;
        do {
            if (e->active != 0) {
                scale[2] = e->scale;
                scale[1] = e->scale;
                scale[0] = e->scale;
                fn_8000DCE0(mtx, scale);
                NuMtxTranslate(mtx, e->pos);
                fn_8000E318(mtx, e->rotY);
                fn_8000E498(mtx, e->rotX);
                NuSpecialFindMultiWC((s32 *)lbl_804072F4, (s32)mtx);
            }
            e++;
        } while (--i != 0);
    }
}

extern f32 lbl_801AFE14[];
extern f32 lbl_801AFE18[];
extern s32 lbl_8040B2DC;

void fn_8014ECEC(void) {
    s8 *p = (s8 *)lbl_80409C94;
    u8 *q;

    *(f32 *)(p + 0xB004) = lbl_801AFE14[0];
    memset(p + 0xA600, 0, 0xA00);
    lbl_80409C98 = 0;
    lbl_8040A810 = -1;
    switch (lbl_8040B108) {
    case 1:
        lbl_8040B068 = 3;
        break;
    case 2:
        lbl_8040B068 = 6;
        break;
    case 3:
        lbl_8040B068 = 9;
        break;
    }
    lbl_80409C90 = 0;
    memset(lbl_80407300, 0, 0x700);
    q = (u8 *)lbl_80407300 - 0xC;
    *(f32 *)(q + 0x710) = lbl_801AFE18[0];
    *(f32 *)(q + 0x744) = lbl_801AFE14[0];
    lbl_8040B2DC = 0;
}

s32 AISysFindArea(s32, void *);
s16 FindGameDebris(s32, s32 *);
s32 PARTLookupType(s32 *);
f32 fn_80013764(void *);
extern s32 str_Format_NoMine[];
extern s32 str_Podrace_Mine[];
extern s32 str_Podrace_MinePart[];
extern s32 str_Podrace_MinePop[];

typedef struct PodMineData {
    u8 special[0x70C];
    f32 unk70C;
    f32 unk710;
    s32 mines[10];
    s16 mineCount;
    s16 debris;
    s32 part;
    f32 unk744;
} PodMineData;

#define MINE ((PodMineData *)lbl_804072F4)
void PodraceCreateMine(void) {
    s32 *mines;
    s32 i;
    s32 r;
    s32 buf[8];

    memset(MINE, 0, 0x748);
    r = NuSpecialFind(*(s32 *)((s8 *)lbl_80409410 + 0x1C8), MINE, str_Podrace_Mine, 1);
    if (r != 0) {
        MINE->unk70C = fn_80013764(MINE);
        mines = MINE->mines;
        for (i = 0; i <= 9; i++) {
            sprintf(buf, str_Format_NoMine, i);
            r = AISysFindArea(*(s32 *)((s8 *)lbl_80409410 + 0x2E8), buf);
            mines[MINE->mineCount] = r;
            if (mines != NULL) {
                MINE->mineCount++;
            }
        }
        MINE->debris = FindGameDebris(*(s32 *)((s8 *)lbl_80409410 + 0x1B8), str_Podrace_MinePop);
        MINE->part = PARTLookupType(str_Podrace_MinePart);
    }
}

void *fn_800D5680(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
f32 NuSinApprox(s32);
extern f32 lbl_801AFDF8[];
extern f32 lbl_801AFDFC[];
extern f32 lbl_801AFE00[];
extern f32 lbl_801AFE04[];
extern f32 lbl_801AFE08[];
extern f32 lbl_801AFE0C[];
extern f32 lbl_801AFE10[];
extern f32 lbl_803E04B0[];
extern s32 lbl_80408F20;
extern s32 lbl_8040948C;
extern f32 lbl_80409CF4;
extern f32 lbl_8040AFA4;

void fn_8014EBBC(void) {
    u8 *obj;
    f32 var;

    if (lbl_80409C90 != 0) {
        if (lbl_80408F00 == lbl_801AFDF8[0] && lbl_80408F20 == 0) {
            lbl_8040AFA4 = lbl_8040AFA4 + 2.0f * lbl_80408E9C;
            if (lbl_8040AFA4 > lbl_801AFDFC[0]) {
                lbl_8040AFA4 = lbl_801AFDFC[0];
            }
            if (NuFmod(lbl_803E04B0[0], lbl_801AFE00[0]) < lbl_801AFE04[0]) {
                var = lbl_80409CF4;
                lbl_8040948C = 0xD1;
                obj = fn_800D5680(0, lbl_80409C90 + 0x1A0, 0, 0xFF, 0x3F, 0x3F, 0x8083, var, lbl_801AFE08[0], lbl_801AFE08[0]);
                if (obj != NULL) {
                    obj[0x90] = (s32)(NuSinApprox((s32)(lbl_8040AFA4 * lbl_801AFE0C[0])) * lbl_801AFE10[0]);
                }
            }
        } else {
            lbl_8040AFA4 = lbl_801AFE08[0];
        }
    }
}

s32 NuVecAdd(f32 *, f32 *, void *);
s32 NuVecRotateY(f32 *, f32 *, u16);
extern f32 fn_8000C038(void);
s32 fn_8014D5A0(f32 *);
extern char MenuHeader[];
#define MENUF(o) (*(f32 *)(mh + (o)))
#define P2F4F(o) (*(f32 *)(pp + (o)))
extern f32 lbl_801AFCFC[];
extern f32 lbl_801AFD00[];
extern f32 lbl_801AFD04[];
extern f32 lbl_801AFD08[];
extern f32 lbl_801E1960[];
extern f32 lbl_80409CB0;
extern f32 lbl_80409CB4;
extern f32 lbl_80409CB8;
extern s32 lbl_8040B108;

void fn_8014DA40(void) {
    f32 v[3];

    if (lbl_8040B108 <= 3 && lbl_8040AFA8 == 0) {
        u8 *pp = lbl_804072F4;
        char *mh;

        P2F4F(0x744) = P2F4F(0x744) + lbl_80408E9C;
        if (P2F4F(0x744) > lbl_801AFCFC[0]) {
            if (P2F4F(0x710) == lbl_801AFD00[0]) {
                { char *m0 = MenuHeader; P2F4F(0x710) = *(f32 *)(m0 + 0xAC); }
            }
            mh = MenuHeader;
            if (MENUF(0xAC) < lbl_80409CB8 && MENUF(0xAC) >= P2F4F(0x710)) {
                v[0] = 2.0f * lbl_80409CB0 * (lbl_801AFD04[0] - fn_8000C038());
                v[1] = lbl_801AFD08[0];
                v[2] = lbl_80409CB4;
                NuVecRotateY(v, v, *(u16 *)((u8 *)lbl_80409004 + 0x626));
                NuVecAdd(v, v, (u8 *)lbl_80409004 + 0x90);
                if (fn_8014D5A0(v) != 0) {
                    P2F4F(0x710) = MENUF(0xAC) + lbl_801E1960[lbl_8040B108];
                }
            }
        }
    }
}

s32 CloseDoorObstacle(s32, s32);
s32 ProcessForceObject(s32);
s32 fn_80108710(s32, s32);
s32 fn_8014C8B0();
extern s8 lbl_801AFC2C[];
extern s8 lbl_801AFC3C[];
extern f32 lbl_801AFC4C[];
extern s32 lbl_804093AC;
extern f32 lbl_80409C88;
extern s32 lbl_8040A800;
extern s32 lbl_8040A804;
extern s32 lbl_8040A808;
extern s32 lbl_8040B2C0;
extern s32 lbl_8040B2C4;
extern s32 lbl_8040B2D0;
extern s32 lbl_8040B2D4;

#define PAIRID(a, b, r) \
    if (((a) == 0 && (b) == 1) || ((a) == 1 && (b) == 0)) { r = 3; } \
    else if (((a) == 2 && (b) == 1) || ((a) == 1 && (b) == 2)) { r = 4; } \
    else if (((a) == 0 && (b) == 2) || ((a) == 2 && (b) == 0)) { r = 5; } \
    else { r = -1; }

static inline s32 PodPairId(s32 a, s32 b) {
    if ((a == 0 && b == 1) || (a == 1 && b == 0)) {
        return 3;
    } else if ((a == 2 && b == 1) || (a == 1 && b == 2)) {
        return 4;
    } else if ((a == 0 && b == 2) || (a == 2 && b == 0)) {
        return 5;
    }
    return -1;
}

void fn_8014CAE8(void) {
    s32 hit = 0;
    s32 a, b, r, i, k, r2;

    if (lbl_804093AC == 0x42) {
        if (lbl_8040B2B4 == 0) {
            if (lbl_8040B2CC != 0) {
                fn_8014C8B0();
                if (lbl_8040B2B8 != 0) {
                    r = PodPairId(lbl_8040A804, lbl_8040A808);
                    if (r == lbl_8040B2AC) {
                        hit = 1;
                    }
                    if (hit != 0) {
                        fn_8006DCD4((char *)lbl_801AFC2C, (void *)(fn_800133FC(lbl_80407154) + 0x30));
                        lbl_8040B2BC++;
                        if (lbl_8040B2BC == 3) {
                            lbl_8040B2B4 = 1;
                        }
                    } else {
                        lbl_8040B2BC = hit;
                        memset(lbl_80407100, 0xFF, 0xC);
                    }
                    lbl_80409C88 = lbl_801AFC4C[0];
                    lbl_8040A808 = -1;
                    lbl_8040A804 = -1;
                    lbl_8040B2B8 = 0;
                    lbl_8040B2CC = 0;
                    lbl_8040A800 = lbl_8040B2AC;
                    do {
                        r = (fn_800B9ED4() / 21846) + 3;
                        lbl_8040B2AC = r;
                        if (lbl_8040B2BC > 0) {
                            u32 n = lbl_8040B2BC;
                            s32 old = lbl_8040A800;
                            s32 *q = lbl_80407100;
                            do {
                                k = *q++;
                                if (r == k) { r = old; }
                            } while (--n);
                            lbl_8040B2AC = r;
                        }
                    } while (lbl_8040B2AC == lbl_8040A800);
                    {
                        u32 u = lbl_8040B2AC - 3;
                        if (u <= 2U) {
                            PodSnd12 *p = lbl_80407154;
                            do {
                                if (fn_800130F4(p) != 0) {
                                    fn_80013200(p, 0);
                                }
                                p++;
                            } while ((s32)p <= (s32)lbl_80407154 + 0x18);
                            p = &lbl_80407154[u];
                            if (fn_800130F4(p) != 0) {
                                fn_80013200(p, 1);
                            }
                        }
                    }
                }
            } else if (lbl_8040A80C == 0) {
                {
                    s32 *q = lbl_80407178;
                    s32 j = 0;
                    k = 3;
                    do {
                        s32 x = *q++;
                        if (*(s32 *)(x + 0x18) & 0x1000) {
                            a = j;
                            goto found_a;
                        }
                        j++;
                    } while (--k != 0);
                    a = -1;
                }
found_a:
                lbl_8040A804 = a;
                if (a != -1) {
                    s32 o = lbl_80407178[a];
                    lbl_8040B2D0 = o;
                    if (o == 0) {
                        s32 *q = lbl_80407178;
                        i = 0;
                        k = 3;
                        do {
                            s32 x = *q++;
                            if (*(s32 *)(x + 0x18) & 0x1000) {
                                b = i;
                                goto found_b;
                            }
                            i++;
                        } while (--k != 0);
                        b = -1;
                    } else {
                        s32 *q = lbl_80407178;
                        i = 0;
                        k = 3;
                        do {
                            s32 x = *q++;
                            if (x != o && (*(s32 *)(x + 0x18) & 0x1000)) {
                                b = i;
                                goto found_b;
                            }
                            i++;
                        } while (--k != 0);
                        b = -1;
                    }
found_b:
                    lbl_8040A808 = b;
                    if (lbl_8040A804 != -1 && b != -1) {
                        lbl_8040B2CC = 1;
                        lbl_8040B2D4 = lbl_80407178[b];
                        lbl_8040B2B8 = 0;
                        lbl_8040B2C0 = 0;
                        lbl_8040B2C4 = PodPairId(lbl_8040A804, b);
                        CloseDoorObstacle(0, lbl_8040B2D0);
                        CloseDoorObstacle(0, lbl_8040B2D4);
                        fn_80108710(0, lbl_8040B2D0);
                        fn_80108710(0, lbl_8040B2D4);
                        lbl_8040A80C = 1;
                    }
                } else {
                    lbl_8040A808 = a;
                }
            } else if ((*(s32 *)(lbl_8040B2D0 + 0x18) & 8) && (*(s32 *)(lbl_8040B2D4 + 0x18) & 8)) {
                lbl_8040A80C = lbl_8040B2CC;
            }
            if (lbl_8040B2B4 != 0) {
                goto block_83;
            }
        } else {
block_83:
            {
                s32 fo = lbl_8040B2B0;
                if (!(*(u16 *)(fo + 0x20) & 0x100)) {
                    *(u16 *)(fo + 0x20) |= 0x2042;
                    ProcessForceObject(fo);
                    if (lbl_80409C8C == 0) {
                        lbl_80409C8C = 1;
                        fn_8006DCD4((char *)lbl_801AFC3C, (void *)(fn_800133FC(lbl_8040B2B0 + 4) + 0x30));
                    }
                }
            }
        }
    }
}
