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
s32 fn_8014DA40();
s32 fn_8014EBBC();

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

s32 PodraceCreateMine();
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
s32 fn_8014EBBC();
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

s32 PodraceCreateMine();
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
s32 fn_8014EBBC();
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
