#include "game/levels.h"

extern f32 lbl_8019FEDC[];
extern f32 lbl_801A4EC0[];
extern s32 lbl_8040B170;
extern f32 lbl_8040A6B8;
extern s32 lbl_8040A6B0;
extern f32 lbl_8040A6B4;
struct fn_800CF198_s {
    u8 pad0[0x52];
    u16 h52;
    u8 pad54[4];
    f32 f58;
};
extern struct fn_800CF198_s lbl_803ED35C[];
extern f32 lbl_801A4F18[];
extern s32 gTotalStudsBalance[];
extern f32 lbl_801A4EDC[];
extern s32 lbl_801D5744[];
extern s32 lbl_801D5768[];
extern u8 lbl_801DC964[];
extern u8 lbl_802E0C78[];
extern s32 lbl_804093B8;
extern s32 lbl_804093D8;
extern s32 lbl_804093DC;
extern f32 lbl_8040B0C8;
extern s32 lbl_8040B164;

s32 DebugMenu_ToggleOption2(void)
{
    return lbl_801D5744[0];
}

s32 fn_800AFF48(void)
{
    return lbl_801D5768[0];
}

void fn_800AFF54(void)
{

}

void Menu_Unknown15_Enter(void)
{

}

void fn_800B5948(void)
{

}

s32 fn_800BA734(void)
{
    return gTotalStudsBalance[0];
}

void SceneSelect_HandleEntry(void)
{
    lbl_801DC964[0] = 0;
    lbl_804093D8 = 0;
    lbl_804093DC = -1;
}

void fn_800CDD18(void)
{
    lbl_8040B164 = 0;
    lbl_8040B0C8 = lbl_801A4EDC[0];
}

void fn_800CF02C(void)
{
    lbl_802E0C78[0] = 0;
}

void fn_800CF0B4(void)
{
    lbl_804093B8 = 115;
}

void fn_800ABF60(u8* a)
{
    f32 t0 = lbl_8019FEDC[0];
    *(u8*)(a + 16) = 0;
    *(f32*)(a + 12) = t0;
    *(f32*)(a + 4) = t0;
}

void fn_800B02E0(f32 x, f32 y, f32 z, u8* a)
{
    *(f32*)(a + 328) = x;
    *(f32*)(a + 332) = y;
    *(f32*)(a + 336) = z;
}

void fn_800CC6C4(void)
{
    f32 t0 = lbl_801A4EC0[0];
    lbl_8040A6B0 = -1;
    lbl_8040B170 = -1;
    lbl_8040A6B4 = t0;
    lbl_8040A6B8 = t0;
}

void fn_800CF198(void)
{
    lbl_803ED35C[0].f58 = lbl_801A4F18[0];
    lbl_803ED35C[0].h52 = lbl_803ED35C[0].h52 - 1;
}

extern void fn_8006DF68(f32);
extern void fn_8006DEB0(f32);

f32 fn_800B9D44(u8* settings)
{
    f32 volume = ((f32)settings[3] / 10.0f) * ((f32)settings[4] / 10.0f);
    fn_8006DF68(volume);
    return volume;
}

f32 fn_800B9DC8(u8* settings)
{
    f32 volume = ((f32)settings[2] / 10.0f) * ((f32)settings[4] / 10.0f);
    fn_8006DEB0(volume);
    return volume;
}

s32 Menu_ResetFromGame();

void Menu_Unknown13_HandleSelection(void) {
    Menu_ResetFromGame();
}

s32 fn_800DF8A8();

void Menu_Unknown14_BuildOptions(void) {
    fn_800DF8A8();
}

s32 fn_800DFC04();

void Menu_Unknown14_Close(void) {
    fn_800DFC04();
}

s32 fn_800E27CC();

void Menu_Unknown14_Enter(void) {
    fn_800E27CC();
}

s32 fn_800DF360();

void Menu_Unknown14_HandleSelection(void) {
    fn_800DF360();
}

s32 fn_800E0790();

void Menu_Unknown15_BuildOptions(void) {
    fn_800E0790();
}

s32 fn_8010C570(s32, f32);
extern f32 lbl_8040B0E0;
extern s32 lbl_8040B0EC;

void Menu_Unknown16_BuildOptions(void) {
    fn_8010C570(lbl_8040B0EC, lbl_8040B0E0);
}

s32 fn_800DD1C8();

void Menu_Unknown17_BuildOptions(void) {
    fn_800DD1C8();
}

s32 fn_800DA478();

void Menu_Unknown17_HandleSelection(void) {
    fn_800DA478();
}

s32 fn_800A20AC();

void Menu_Unknown4_Close(void) {
    fn_800A20AC();
}

void Menu_Unknown3_BuildOptions(void *);

void Menu_Unknown6_BuildOptions(void *menu) {
    Menu_Unknown3_BuildOptions(menu);
}

s32 RotDiff(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = arg1 - arg0;
    if (temp_r3 > 0x8000) {
        return temp_r3 + 0xFFFF0000;
    }
    if (temp_r3 < -0x8000) {
        return temp_r3 + 0x10000;
    }
    return temp_r3;
}

extern s32 gPlayer1Pointer[];
extern void *gPlayerPointers[];
extern void *lbl_80409004;
extern void *lbl_80409008;

void fn_800ABCC8(void) {
    if (((void *) (*(void **)((s8 *)(gPlayer1Pointer) + (0))) != NULL) && ((*(s32 *)((s8 *)((*(void **)((s8 *)(gPlayer1Pointer) + (0)))) + (0x20C))) & 0x01000000)) {
        lbl_80409004 = (*(void **)((s8 *)(gPlayer1Pointer) + (0)));
        if (((void *) (*(void **)((s8 *)(gPlayer1Pointer) + (4))) != NULL) && ((*(s32 *)((s8 *)((*(void **)((s8 *)(gPlayer1Pointer) + (4)))) + (0x20C))) & 0x01000000)) {
            lbl_80409008 = (*(void **)((s8 *)(gPlayer1Pointer) + (4)));
            return;
        }
        lbl_80409008 = NULL;
        return;
    }
    if (((void *) gPlayerPointers[0] != NULL) && ((*(s32 *)((s8 *)(gPlayerPointers[0]) + (0x20C))) & 0x01000000)) {
        lbl_80409004 = gPlayerPointers[0];
        lbl_80409008 = NULL;
        return;
    }
    lbl_80409004 = NULL;
}

extern s32 lbl_804091F8;

s32 fn_800AC658(void *arg0) {
    s32 temp_r0;

    if (((s32) lbl_804091F8 == 0) && ((s16) (*(s16 *)((s8 *)(arg0) + (0x1074))) == 0xD) && ((temp_r0 = (*(s32 *)((s8 *)(lbl_80409410) + (0x19C))), ((temp_r0 == 9) != 0)) || (temp_r0 == 0xB))) {
        return 1;
    }
    return 0;
}

s32 fn_80028238(s32);

void fn_800B9BB8(void) {
    fn_80028238(0x80808080);
}

extern s32 lbl_80409134;

u16 fn_800B9ED4(void) {
    u16 temp_r9;

    temp_r9 = (lbl_80409134 * 0x24CD) + 1;
    lbl_80409134 = (s32) temp_r9;
    return temp_r9;
}

s32 NuRandSetSeed(s32, s32);
s32 fn_80064BEC(s32);
s32 srand(s32);
extern s32 lbl_80409134;

void fn_800B9EF0(void) {
    srand(0);
    lbl_80409134 = 0x3039;
    NuRandSeed(0);
    fn_80064BEC(0);
    NuRandSetSeed(0, 0);
}

s32 fn_800130F4();
void *fn_8001384C(s32);

s32 fn_800BA1E8(s32 arg0) {
    void *temp_r3;

    if (fn_800130F4() != 0) {
        temp_r3 = fn_8001384C(arg0);
        if (temp_r3 != NULL) {
            (*(s32 *)((s8 *)(temp_r3) + (0x50))) = (s32) ((*(s32 *)((s8 *)(temp_r3) + (0x50))) | 0x80000000);
            return 1;
        }
    }
    return 0;
}

void fn_800BA434(void) {
    s32 var_ctr;

    var_ctr = 4;
    do {
        var_ctr -= 1;
    } while (var_ctr != 0);
}

s32 NuSpecialFind(s32, s32 *, s32 *, s32);
s32 FindForceObject(void *, s32 *, s32);
s32 fn_801276E4(void *, s32, s32);
extern s32 lbl_801A1F2C[];
extern s32 lbl_801A1F38[];
extern s32 lbl_801A1F44[];
extern s32 lbl_801A1F50[];
extern s32 lbl_801A1F58[];
extern s32 lbl_802DA1F8[];
extern s32 lbl_802DA204[];
extern s32 lbl_803EAD24[];
extern s32 lbl_803EAD30[];
extern s32 lbl_803EB044[];
extern s32 lbl_803EB048[];
extern s32 lbl_803EB04C[];

void RetakeFInit(void) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3 = FindForceObject(lbl_80409410, lbl_801A1F2C, 0);
    if (temp_r3 != 0) {
        lbl_803EB044[0] = fn_801276E4(lbl_80409410, temp_r3, 0);
    }
    temp_r3_2 = FindForceObject(lbl_80409410, lbl_801A1F38, 0);
    if (temp_r3_2 != 0) {
        lbl_803EB048[0] = fn_801276E4(lbl_80409410, temp_r3_2, 0);
    }
    temp_r3_3 = FindForceObject(lbl_80409410, lbl_801A1F44, 0);
    if (temp_r3_3 != 0) {
        lbl_803EB04C[0] = fn_801276E4(lbl_80409410, temp_r3_3, 0);
    }
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD24, lbl_801A1F50, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_802DA1F8, lbl_801A1F50, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD30, lbl_801A1F58, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_802DA204, lbl_801A1F58, 1);
}

s32 NuSpecialFind(s32, s32 *, s32 *, s32);
s32 CheckAIMessage(s32, s32 *, s32);
s32 FindForceObject(void *, s32 *, s32);
extern s32 lbl_801A20AC[];
extern s32 lbl_801A20B4[];
extern s32 lbl_801A20C0[];
extern s32 lbl_801A20D0[];
extern s32 lbl_801A20E0[];
extern s32 lbl_801A20F0[];
extern s32 lbl_801A2100[];
extern s32 lbl_801A2110[];
extern s32 lbl_801A2120[];
extern s32 lbl_801A2130[];
extern s32 lbl_801A2140[];
extern s32 lbl_803EAD24[];
extern s32 lbl_803EAD30[];
extern s32 lbl_803EAD3C[];
extern s32 lbl_803EAD48[];
extern s32 lbl_803EAD54[];
extern s32 lbl_803EAD60[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_80408F58;
extern s32 lbl_80409240;
extern s32 lbl_80409244;
extern s32 lbl_8040B154;

void MaulFInit(void) {
    lbl_80409240 = CheckAIMessage(lbl_80408F58, lbl_801A20AC, 0);
    lbl_80409244 = CheckAIMessage(lbl_80408F58, lbl_801A20B4, 0);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD24, lbl_801A20C0, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD30, lbl_801A20D0, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD3C, lbl_801A20E0, 1);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A20F0, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A2100, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A2110, 0);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD48, lbl_801A2120, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD54, lbl_801A2130, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD60, lbl_801A2140, 1);
    lbl_8040B154 = 0;
}

s32 ConfigureAllCharacters(s32);

void fn_800CC970(void) {
    ConfigureAllCharacters(1);
}


void fn_800CC994(void) {
    s32 (*temp_r0)();

    temp_r0 = (*(s32 (**)())((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (0x20)));
    if (temp_r0 != NULL) {
        temp_r0();
    }
}


void fn_800CC9CC(void) {
    s32 (*temp_r0)();

    temp_r0 = (*(s32 (**)())((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (0x28)));
    if (temp_r0 != NULL) {
        temp_r0();
    }
}

s32 fn_8012676C(s32);

void fn_800CCDC0(void) {
    fn_8012676C(0x1B);
}

s32 CheckAIMessage(s32, s32 *, s32);
extern s32 lbl_801A1E5C[];
extern s32 lbl_801A1E68[];
extern s32 lbl_80408F58;
extern s32 lbl_80409224;
extern s32 lbl_80409228;

void RetakeGReset(void) {
    lbl_80409224 = CheckAIMessage(lbl_80408F58, lbl_801A1E5C, 0);
    lbl_80409228 = CheckAIMessage(lbl_80408F58, lbl_801A1E68, 0);
}

s32 fn_80127518(s32);
extern s32 lbl_803EB044[];

void fn_800CD484(void) {
    fn_80127518((*(s32 *)((s8 *)(lbl_803EB044) + (0))));
    fn_80127518((*(s32 *)((s8 *)(lbl_803EB044) + (4))));
    fn_80127518((*(s32 *)((s8 *)(lbl_803EB044) + (8))));
}

s32 fn_800BE9B0();

void fn_800CD960(void) {
    fn_800BE9B0();
}

s32 fn_800D515C(s32, s32, s32);
s32 fn_800D95B8();
extern f32 lbl_801A4ED0[];
extern void *lbl_802DA6E4[];

s32 fn_800CD980(void) {
    s32 var_r3;

    var_r3 = fn_800D515C(7, 1, 1);
    if ((var_r3 != 0) && ((void *) lbl_802DA6E4[0] != NULL) && ((*(f32 *)((s8 *)(lbl_802DA6E4[0]) + (0x28))) == lbl_801A4ED0[0])) {
        var_r3 = fn_800D95B8();
    }
    return var_r3;
}

s32 fn_8014CFA4();

void fn_800CDC64(void) {
    fn_8014CFA4();
}

extern s32 lbl_804091F8;
extern s32 lbl_804093B8;

void fn_800CE064(void) {
    s32 var_r9;

    var_r9 = 0x4A;
    if ((s32) lbl_804091F8 != 0) {
        var_r9 = 0x4B;
    }
    lbl_804093B8 = var_r9;
}

s32 fn_800C3A24(s32 *);
extern s32 lbl_801D6648[];

void fn_800CE11C(void) {
    fn_800C3A24(lbl_801D6648);
}

s32 fn_800D7ED8(s32, s32, s32);
extern f32 lbl_801A4EE4[];
extern u8 lbl_8040B060[];
extern f32 lbl_8040B168;

void fn_800CE18C(void) {
    if (((s32) lbl_8040B060[0] == 1) && (lbl_8040B168 > lbl_801A4EE4[0])) {
        fn_800D7ED8((s32) lbl_8040B168 + 1, 0, 0);
    }
}

s32 fn_800D515C(s32, s32, s32);
s32 fn_800D95B8();
extern f32 lbl_801A4EEC[];
extern void *lbl_802E0B8C[];

s32 fn_800CE280(void) {
    s32 var_r3;

    var_r3 = fn_800D515C(0xE, 1, 1);
    if ((var_r3 != 0) && ((void *) lbl_802E0B8C[0] != NULL) && ((*(f32 *)((s8 *)(lbl_802E0B8C[0]) + (0x28))) == lbl_801A4EEC[0])) {
        var_r3 = fn_800D95B8();
    }
    return var_r3;
}

extern s32 lbl_804091F8;
extern s32 lbl_804093B8;

void fn_800CE2DC(void) {
    s32 var_r9;

    var_r9 = 0x52;
    if ((s32) lbl_804091F8 != 0) {
        var_r9 = 0x53;
    }
    lbl_804093B8 = var_r9;
}

s32 fn_800130F4(s32 *);
void fn_80013200(s32 *, s32);
extern s32 lbl_803EAD24[];
extern s32 lbl_803EAD30[];
extern u8 lbl_8040B060[];

void fn_800CE38C(void) {
    if ((s32) lbl_8040B060[0] == 1) {
        lbl_8040B060[0] = 2;
        if (fn_800130F4(lbl_803EAD24) != 0) {
            fn_80013200(lbl_803EAD24, 1);
        }
        if (fn_800130F4(lbl_803EAD30) != 0) {
            fn_80013200(lbl_803EAD30, 1);
        }
    }
}

s32 CheckAIMessage(s32, s32 *, s32);
extern s32 lbl_801A20B4[];
extern s32 lbl_80408F58;
extern s32 lbl_80409344;
extern s32 lbl_80409348;

void fn_800CE8C0(void) {
    lbl_80409348 = 0;
    lbl_80409344 = CheckAIMessage(lbl_80408F58, lbl_801A20B4, 0);
}

extern f32 lbl_801A4F0C[];
extern s32 lbl_80408F2C;
extern void *lbl_80409368;
extern s32 lbl_804093B0;
extern s32 lbl_8040AF64;
extern s32 lbl_8040AF94;

void fn_800CEFE8(void) {
    if (((void *) lbl_80409368 != NULL) && ((*(f32 *)((s8 *)(lbl_80409368) + (0x28))) == lbl_801A4F0C[0])) {
        lbl_80408F2C = 1;
        lbl_804093B0 = 0x72;
        if ((s32) lbl_8040AF64 != -1) {
            lbl_8040AF94 = 1;
        }
    }
}

s32 CheckAIMessage(s32, s32 *, s32);
extern s32 lbl_801A2E90[];
extern s32 lbl_80408F58;
extern s32 lbl_8040A6A8;

void BonusAReset(void) {
    lbl_8040A6A8 = CheckAIMessage(lbl_80408F58, lbl_801A2E90, 0);
}

s32 Shop_DrawSubMenuAndTopShelf();
s32 fn_800E1D0C();

void fn_800CF214(void) {
    Shop_DrawSubMenuAndTopShelf();
    fn_800E1D0C();
}

s32 ResetPlayerContexts(void *);
s32 fn_800ABA78();
s32 fn_800AC020(s32, f32);
s32 fn_801044F0(void *);
extern f32 lbl_801A5258[];

void DeactivatePlayer(void *arg0, f32 farg0) {
    f32 temp_f31;
    void *temp_r9;

    temp_r9 = (*(void **)((s8 *)(arg0) + (0xEEC)));
    if ((s32) (*(u8 *)((s8 *)(temp_r9) + (0x7DF))) != 0x1B) {
        temp_f31 = (*(f32 *)((s8 *)(temp_r9) + (0x6AC)));
        fn_800ABA78();
        ResetPlayerContexts((*(void **)((s8 *)(arg0) + (0xEEC))));
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x6AC))) = temp_f31;
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x7DF))) = 0x1BU;
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x714))) = farg0;
        (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x7A6))) = 0x47;
        if ((u32) ((*(u16 *)((s8 *)(arg0) + (0x1074))) - 0x1D) <= 1U) {
            fn_801044F0(arg0);
        }
        fn_800AC020(*(*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x61C))), lbl_801A5258[0]);
    }
}

void fn_800D5090(void *arg0) {
    f32 temp_f11;
    f32 temp_f12;

    temp_f12 = (*(f32 *)((s8 *)(arg0) + (0x1014)));
    temp_f11 = (*(f32 *)((s8 *)(arg0) + (0x1018)));
    (*(f32 *)((s8 *)(arg0) + (0x101C))) = temp_f12;
    (*(f32 *)((s8 *)(arg0) + (0x1020))) = temp_f11;
    (*(f32 *)((s8 *)(arg0) + (0x1030))) = (f32) ((temp_f11 - temp_f12) / (2.0f * (*(f32 *)((s8 *)(arg0) + (0x1028)))));
}

extern f32 lbl_801A553C[];
extern f32 lbl_801A5540[];
extern void *lbl_80409570;
extern f32 lbl_8040B1E4;

void CancelHint(void) {
    f32 temp_f0;
    f32 temp_f12;

    if ((void *) lbl_80409570 != NULL) {
        temp_f12 = (*(f32 *)((s8 *)(lbl_80409570) + (4)));
        if (temp_f12 != lbl_801A553C[0]) {
            temp_f0 = temp_f12 - lbl_801A5540[0];
            if (lbl_8040B1E4 < temp_f0) {
                lbl_8040B1E4 = temp_f0;
            }
        }
        (*(f32 *)((s8 *)(lbl_80409570) + (0xC))) = (f32) lbl_801A553C[0];
    }
}

s32 FindObstacle(s32, s32 *);
extern s32 lbl_801A2080[];
extern s32 lbl_801A2084[];
extern s32 lbl_801A2088[];
extern s32 lbl_801A208C[];
extern s32 lbl_801A2090[];
extern s32 lbl_801A2094[];
extern s32 lbl_801A2098[];
extern s32 lbl_801A209C[];
extern s32 lbl_801A20A0[];
extern s32 lbl_801A20A4[];
extern s32 lbl_803EAE44[];

void MaulBInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0))) = FindObstacle(lbl_80409410, lbl_801A2080);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (4))) = FindObstacle(lbl_80409410, lbl_801A2084);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (8))) = FindObstacle(lbl_80409410, lbl_801A2088);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0xC))) = FindObstacle(lbl_80409410, lbl_801A208C);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x10))) = FindObstacle(lbl_80409410, lbl_801A2090);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x14))) = FindObstacle(lbl_80409410, lbl_801A2094);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x18))) = FindObstacle(lbl_80409410, lbl_801A2098);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x1C))) = FindObstacle(lbl_80409410, lbl_801A209C);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x20))) = FindObstacle(lbl_80409410, lbl_801A20A0);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0x24))) = FindObstacle(lbl_80409410, lbl_801A20A4);
}

s32 NewRumbleAllPlayers(f32, f32);
s32 UpdatePulses(s32 *);
void fn_800CC3FC();
void *fn_800CCA04(struct lbl_80409410_s *, char *);
extern void *gPlayerPointers[];
extern s32 lbl_801A29B8[];
extern f32 lbl_801A29C8[];
extern f32 lbl_801A29CC[];
extern f32 lbl_801A29D0[];
extern s32 lbl_801D6648[];
extern u8 lbl_8040B060[];

void GunshipAUpdate(void) {
    UpdatePulses(lbl_801D6648);
    if (((s32) lbl_8040B060[0] == 0) && ((((void *) gPlayer1Pointer[0] != NULL) && ((s32) (*(u8 *)((s8 *)(gPlayer1Pointer[0]) + (0x601))) == 0) && ((*(f32 *)((s8 *)(gPlayer1Pointer[0]) + (0x62C))) > lbl_801A29C8[0])) || (((void *) gPlayerPointers[0] != NULL) && ((s32) (*(u8 *)((s8 *)(gPlayerPointers[0]) + (0x601))) == 0) && ((*(f32 *)((s8 *)(gPlayerPointers[0]) + (0x62C))) > lbl_801A29C8[0])))) {
        fn_800CCA04(lbl_80409410, lbl_801A29B8);
        fn_800CC3FC();
        lbl_8040B060[0] = 1;
        NewRumbleAllPlayers(lbl_801A29CC[0], lbl_801A29D0[0]);
    }
}

s32 FindObstacle(s32, s32 *);
extern s32 lbl_801A1C90[];
extern s32 lbl_801A1C98[];
extern s32 lbl_801A1CA0[];
extern s32 lbl_801A1CA8[];
extern s32 lbl_803EAE44[];

void GunganBInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0))) = FindObstacle(lbl_80409410, lbl_801A1C90);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (4))) = FindObstacle(lbl_80409410, lbl_801A1C98);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (8))) = FindObstacle(lbl_80409410, lbl_801A1CA0);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0xC))) = FindObstacle(lbl_80409410, lbl_801A1CA8);
}

extern s32 lbl_801A1CBC[];
extern s32 lbl_801A1CC8[];
extern s32 lbl_801A1CD4[];
extern s32 lbl_803EAEC4[];

void GunganEInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A1CBC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A1CC8, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A1CD4, 0);
}

s32 FindObstacle(s32, s32 *);
extern s32 lbl_801A1D64[];
extern s32 lbl_801A1D70[];
extern s32 lbl_801A1D80[];
extern s32 lbl_803EAE44[];

void RescueEInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0))) = FindObstacle(lbl_80409410, lbl_801A1D64);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (4))) = FindObstacle(lbl_80409410, lbl_801A1D70);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (8))) = FindObstacle(lbl_80409410, lbl_801A1D80);
}

s32 FindObstacle(s32, s32 *);
extern s32 lbl_801A1E78[];
extern s32 lbl_803EAE44[];

void RetakeGInit(void) {
    lbl_803EAE44[0] = FindObstacle(lbl_80409410, lbl_801A1E78);
}

s32 fn_800D515C(s32, s32, s32);
s32 fn_800D95B8();
extern f32 lbl_801A4ECC[];

s32 fn_800CD6A8(void) {
    s32 var_r3;

    var_r3 = fn_800D515C(8, 1, 1);
    if ((var_r3 != 0) && ((void *) lbl_80409244 != NULL) && ((*(f32 *)((s8 *)(lbl_80409244) + (0x28))) == lbl_801A4ECC[0])) {
        var_r3 = fn_800D95B8();
    }
    return var_r3;
}

extern s32 lbl_801A2220[];
extern s32 lbl_802DA1E8[];
extern s32 lbl_803EAEC4[];

void fn_800CD898(void) {
    s32 temp_r3;

    temp_r3 = FindForceObject(lbl_80409410, lbl_801A2220, 0);
    lbl_803EAEC4[0] = temp_r3;
    if (temp_r3 != 0) {
        lbl_802DA1E8[0] = fn_8001384C(temp_r3 + 4);
    }
}

extern s32 lbl_801A2470[];
extern s32 lbl_803EAEC4[];

void KaminoEInit(void) {
    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A2470, 0);
}

s32 fn_8014C728(s32);

void fn_800CDB98(void) {
    fn_8014C728(lbl_80409410);
}

s32 CheckAIMessage(s32, s32 *, s32);
s32 fn_8014CF8C(s32);
extern s32 lbl_801A25B8[];
extern s32 lbl_80408F58;
extern s32 lbl_8040B19C;

void FactoryBReset(void) {
    fn_8014CF8C(lbl_80409410);
    lbl_8040B19C = CheckAIMessage(lbl_80408F58, lbl_801A25B8, 0);
}

extern s32 lbl_801A2628[];
extern s32 lbl_801A2630[];
extern s32 lbl_801A2638[];
extern s32 lbl_801A2640[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_804092C4;

void FactoryGInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A2628, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A2630, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A2638, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0xC))) = FindForceObject(lbl_80409410, lbl_801A2640, 0);
    lbl_804092C4 = 0;
}

extern s32 lbl_801A2B7C[];
extern s32 lbl_801A2B84[];
extern s32 lbl_803EAEC4[];

void CruiserFInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A2B7C, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A2B84, 0);
}

extern s32 lbl_801A1BA8[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_8040B154;

void fn_800CE7F4(void) {
    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A1BA8, 0);
    lbl_8040B154 = 1;
}

extern s32 lbl_801A2BA8[];
extern s32 lbl_803EAEC4[];

void KashyyykAInit(void) {
    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A2BA8, 0);
}

s32 CheckAIMessage(s32, s32 *, s32);
s32 fn_8011EBF4(s32, s32);
extern s32 lbl_801A2BB8[];
extern s32 lbl_801A2BC8[];
extern s32 lbl_80408F58;
extern s32 lbl_8040934C;
extern s32 lbl_80409350;
extern s32 lbl_80409354;

void fn_800CE980(void) {
    lbl_8040934C = CheckAIMessage(lbl_80408F58, lbl_801A2BB8, 0);
    lbl_80409350 = CheckAIMessage(lbl_80408F58, lbl_801A2BC8, 0);
    lbl_80409354 = fn_8011EBF4(lbl_80409410, 0x50);
}

extern s32 lbl_801A2C08[];
extern s32 lbl_803EAEC4[];

void KashyyykCInit(void) {
    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A2C08, 0);
}

extern s32 lbl_801A2CE0[];
extern s32 lbl_801A2CEC[];
extern s32 lbl_801A2CFC[];
extern s32 lbl_801A2D0C[];
extern s32 lbl_801A2D1C[];
extern s32 lbl_803EAEC4[];

void TempleCInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A2CE0, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A2CEC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A2CFC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0xC))) = FindForceObject(lbl_80409410, lbl_801A2D0C, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x10))) = FindForceObject(lbl_80409410, lbl_801A2D1C, 0);
}

extern s32 lbl_801A2D30[];
extern s32 lbl_803EAEC4[];

void TempleBInit(void) {
    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A2D30, 0);
}

extern f32 lbl_801A4F14[];
extern s32 lbl_80408F2C;
extern s32 lbl_804093B0;
extern s32 lbl_8040AF64;
extern s32 lbl_8040AF94;

void fn_800CF0F4(void) {
    if (((void *) lbl_8040A6A8 != NULL) && ((*(f32 *)((s8 *)(lbl_8040A6A8) + (0x28))) == lbl_801A4F14[0])) {
        lbl_804093B0 = 0x7A;
        lbl_80408F2C = 1;
        if ((s32) lbl_8040AF64 != -1) {
            lbl_8040AF94 = 1;
        }
    }
}

extern s32 lbl_803FD4E0[];
extern s32 lbl_80409484;

void fn_800D97F8(void)
{
  s8 *new_var;
  s32 new_var2;
  s32 var_ctr;
  var_ctr = 0x40;
  new_var = lbl_803FD4E0;
  do
  {
    new_var = (s8 *) new_var;
    *((s8 *) (((s8 *) new_var) + 0x8B)) = 0;
    new_var += 0x9C;
    var_ctr -= 1;
  }
  while (var_ctr != 0);
  var_ctr = 1;
  new_var2 = var_ctr;
  lbl_80409484 = -new_var2;
}

s32 NuSpecialFind(s32, s32 *, s32 *, s32);
s32 FindForceObject(void *, s32 *, s32);
extern s32 lbl_801A2EA4[];
extern s32 lbl_801A2EA8[];
extern s32 lbl_801A2EAC[];
extern s32 lbl_801A2EB0[];
extern s32 lbl_801A2EB4[];
extern s32 lbl_801A2EB8[];
extern s32 lbl_801A2EBC[];
extern s32 lbl_801A2EC0[];
extern s32 lbl_801A2EC4[];
extern s32 lbl_801A2EC8[];
extern s32 lbl_801A2ECC[];
extern s32 lbl_801A2ED0[];
extern s32 lbl_801A2ED4[];
extern s32 lbl_801A2ED8[];
extern s32 lbl_801A2EDC[];
extern s32 lbl_801A2EE0[];
extern s32 lbl_801A2EE4[];
extern s32 lbl_801A2EE8[];
extern s32 lbl_801A2EEC[];
extern s32 lbl_801A2EF0[];
extern s32 lbl_801A2EF4[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_803ED350[];
extern s8 lbl_8040936C;
extern s8 lbl_8040A6AC;

void BonusBInit(void)
{
  s32 temp_r3;
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0)) = FindForceObject(lbl_80409410, lbl_801A2EA4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 4)) = FindForceObject(lbl_80409410, lbl_801A2EA8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 8)) = FindForceObject(lbl_80409410, lbl_801A2EAC, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0xC)) = FindForceObject(lbl_80409410, lbl_801A2EB0, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x10)) = FindForceObject(lbl_80409410, lbl_801A2EB4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x14)) = FindForceObject(lbl_80409410, lbl_801A2EB8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x18)) = FindForceObject(lbl_80409410, lbl_801A2EBC, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x1C)) = FindForceObject(lbl_80409410, lbl_801A2EC0, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x20)) = FindForceObject(lbl_80409410, lbl_801A2EC4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x24)) = FindForceObject(lbl_80409410, lbl_801A2EC8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x28)) = FindForceObject(lbl_80409410, lbl_801A2ECC, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x2C)) = FindForceObject(lbl_80409410, lbl_801A2ED0, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x30)) = FindForceObject(lbl_80409410, lbl_801A2ED4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x34)) = FindForceObject(lbl_80409410, lbl_801A2ED8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x38)) = FindForceObject(lbl_80409410, lbl_801A2EDC, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x3C)) = FindForceObject(lbl_80409410, lbl_801A2EE0, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x40)) = FindForceObject(lbl_80409410, lbl_801A2EE4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x44)) = FindForceObject(lbl_80409410, lbl_801A2EE8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x48)) = FindForceObject(lbl_80409410, lbl_801A2EEC, 0);
  temp_r3 = FindForceObject(lbl_80409410, lbl_801A2EF0, 0);
  lbl_8040936C = (lbl_8040A6AC = 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x4C)) = temp_r3;
  NuSpecialFind(*((s32 *) (((s8 *) lbl_80409410) + 0x1C0)), lbl_803ED350, lbl_801A2EF4, 1);
}

s32 NuAnimDataFixPtrs();
extern s32 lbl_801A1AEC[];
extern s32 lbl_801A1AF8[];
extern s32 lbl_801A1B08[];
extern s32 lbl_801A1B18[];
extern s32 lbl_801A1B28[];
extern s32 lbl_801A1B38[];
extern s32 lbl_801A1B48[];
extern s32 lbl_801A1B58[];
extern s32 lbl_801A1B68[];
extern s32 lbl_801A1B78[];
extern s32 lbl_801A1B88[];
extern s32 lbl_801A1B98[];
extern u8 lbl_803EACC9[];

s32 NegotiationsAInit(void) {
    s32 var_r3;

    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A1AEC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A1AF8, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A1B08, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0xC))) = FindForceObject(lbl_80409410, lbl_801A1B18, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x10))) = FindForceObject(lbl_80409410, lbl_801A1B28, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x14))) = FindForceObject(lbl_80409410, lbl_801A1B38, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x18))) = FindForceObject(lbl_80409410, lbl_801A1B48, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x1C))) = FindForceObject(lbl_80409410, lbl_801A1B58, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x20))) = FindForceObject(lbl_80409410, lbl_801A1B68, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x24))) = FindForceObject(lbl_80409410, lbl_801A1B78, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x28))) = FindForceObject(lbl_80409410, lbl_801A1B88, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x2C))) = FindForceObject(lbl_80409410, lbl_801A1B98, 0);
    var_r3 = FindForceObject(lbl_80409410, lbl_801A1BA8, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x30))) = var_r3;
    lbl_8040B154 = 1;
    if ((s32) lbl_803EACC9[0] != 0) {
        var_r3 = fn_8011EBF4((s32) lbl_80409410, 5);
        if (var_r3 != 0) {
            var_r3 = NuAnimDataFixPtrs();
        }
    }
    return var_r3;
}

extern s32 lbl_801A1D90[];
extern s32 lbl_801A1D98[];
extern s32 lbl_801A1DA4[];
extern s32 lbl_801A1DB0[];
extern s32 lbl_801A1DBC[];
extern s32 lbl_801A1DC8[];
extern s32 lbl_801A1DD4[];
extern s32 lbl_801A1DE0[];
extern s32 lbl_801A1DEC[];
extern s32 lbl_801A1DF8[];
extern s32 lbl_801A1E04[];
extern s32 lbl_801A1E10[];
extern s32 lbl_801A1E1C[];
extern s32 lbl_801A1E28[];
extern s32 lbl_801A1E34[];
extern s32 lbl_801A1E40[];
extern s32 lbl_801A1E4C[];
extern s32 lbl_803EB038[];
extern s32 lbl_803EB050[];
extern s32 lbl_803EB054[];
extern s32 lbl_803EB058[];
extern s32 lbl_803EB05C[];
extern s32 lbl_803EB060[];
extern s32 lbl_803EB064[];
extern s32 lbl_803EB068[];
extern s32 lbl_803EB06C[];
extern s32 lbl_803EB070[];
extern s32 lbl_803EB074[];
extern s32 lbl_803EB078[];
extern s32 lbl_803EB07C[];

void RetakeBInit(void) {
    s32 temp_r3;
    s32 temp_r3_10;
    s32 temp_r3_11;
    s32 temp_r3_12;
    s32 temp_r3_13;
    s32 temp_r3_14;
    s32 temp_r3_15;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r3_9;

    *lbl_803EAEC4 = FindForceObject(lbl_80409410, lbl_801A1D90, 0);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB038, lbl_801A1D98, 1);
    temp_r3 = FindForceObject(lbl_80409410, lbl_801A1DA4, 0);
    if (temp_r3 != 0) {
        *lbl_803EB044 = fn_801276E4(lbl_80409410, temp_r3, 0);
    }
    temp_r3_2 = FindForceObject(lbl_80409410, lbl_801A1DB0, 0);
    if (temp_r3_2 != 0) {
        *lbl_803EB048 = fn_801276E4(lbl_80409410, temp_r3_2, 0);
    }
    temp_r3_3 = FindForceObject(lbl_80409410, lbl_801A1DBC, 0);
    if (temp_r3_3 != 0) {
        *lbl_803EB04C = fn_801276E4(lbl_80409410, temp_r3_3, 0);
    }
    temp_r3_4 = FindForceObject(lbl_80409410, lbl_801A1DC8, 0);
    if (temp_r3_4 != 0) {
        lbl_803EB050[0] = fn_801276E4(lbl_80409410, temp_r3_4, 0);
    }
    temp_r3_5 = FindForceObject(lbl_80409410, lbl_801A1DD4, 0);
    if (temp_r3_5 != 0) {
        lbl_803EB054[0] = fn_801276E4(lbl_80409410, temp_r3_5, 0);
    }
    temp_r3_6 = FindForceObject(lbl_80409410, lbl_801A1DE0, 0);
    if (temp_r3_6 != 0) {
        lbl_803EB058[0] = fn_801276E4(lbl_80409410, temp_r3_6, 0);
    }
    temp_r3_7 = FindForceObject(lbl_80409410, lbl_801A1DEC, 0);
    if (temp_r3_7 != 0) {
        lbl_803EB05C[0] = fn_801276E4(lbl_80409410, temp_r3_7, 0);
    }
    temp_r3_8 = FindForceObject(lbl_80409410, lbl_801A1DF8, 0);
    if (temp_r3_8 != 0) {
        lbl_803EB060[0] = fn_801276E4(lbl_80409410, temp_r3_8, 0);
    }
    temp_r3_9 = FindForceObject(lbl_80409410, lbl_801A1E04, 0);
    if (temp_r3_9 != 0) {
        lbl_803EB064[0] = fn_801276E4(lbl_80409410, temp_r3_9, 0);
    }
    temp_r3_10 = FindForceObject(lbl_80409410, lbl_801A1E10, 0);
    if (temp_r3_10 != 0) {
        lbl_803EB068[0] = fn_801276E4(lbl_80409410, temp_r3_10, 0);
    }
    temp_r3_11 = FindForceObject(lbl_80409410, lbl_801A1E1C, 0);
    if (temp_r3_11 != 0) {
        lbl_803EB06C[0] = fn_801276E4(lbl_80409410, temp_r3_11, 0);
    }
    temp_r3_12 = FindForceObject(lbl_80409410, lbl_801A1E28, 0);
    if (temp_r3_12 != 0) {
        lbl_803EB070[0] = fn_801276E4(lbl_80409410, temp_r3_12, 0);
    }
    temp_r3_13 = FindForceObject(lbl_80409410, lbl_801A1E34, 0);
    if (temp_r3_13 != 0) {
        lbl_803EB074[0] = fn_801276E4(lbl_80409410, temp_r3_13, 0);
    }
    temp_r3_14 = FindForceObject(lbl_80409410, lbl_801A1E40, 0);
    if (temp_r3_14 != 0) {
        lbl_803EB078[0] = fn_801276E4(lbl_80409410, temp_r3_14, 0);
    }
    temp_r3_15 = FindForceObject(lbl_80409410, lbl_801A1E4C, 0);
    if (temp_r3_15 != 0) {
        lbl_803EB07C[0] = fn_801276E4(lbl_80409410, temp_r3_15, 0);
    }
}

s32 fn_800133FC(s32 *);
s32 fn_8006DCD4(s32 *, s32);
s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

/* Shared by the level exit callbacks: the side of the scene spline (world +0x1974) that the
 * players' average position (or `pos`) lies on picks `yes` or `no`. */
static inline void exit_by_spline(struct nuvec_s *pos, s32 yes, s32 no) {
    struct nuvec_s tmp;
    struct nuvec_s *p;
    struct nugspline_s *spl;
    s8 *pts;
    s16 size;

    p = NULL;
    spl = lbl_80409410->unk1974;
    if (spl != NULL) {
        if (pos != NULL) {
            tmp = *pos;
            p = &tmp;
        } else if (fn_800AAC04(&tmp, NULL) != 0) {
            p = &tmp;
        }
        if (p != NULL) {
            pts = spl->pts;
            size = spl->ptsize;
            if (fn_800CFD4C(tmp.x, tmp.z, (*(f32 *)((s8 *)(pts) + (0))), (*(f32 *)((s8 *)(pts) + (8))), (*(f32 *)((s8 *)(&pts[size]) + (0))), (*(f32 *)((s8 *)(&pts[size]) + (8)))) != 0) {
                lbl_804093B8 = yes;
            } else {
                lbl_804093B8 = no;
            }
        }
    }
}

extern s32 lbl_801A1D04[];
extern s32 lbl_803EB038[];

void fn_800BCED8(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x24;
            } else {
                lbl_804093B8 = 0x26;
            }
        }
    }
    if ((fn_800130F4(lbl_803EB038) != 0) && ((s32) (*(s32 *)((s8 *)(fn_8001384C((s32) lbl_803EB038)) + (0x50))) < 0)) {
        fn_8006DCD4(lbl_801A1D04, fn_800133FC(lbl_803EB038) + 0x30);
    }
}

extern s32 lbl_801A1EC4[];
extern s32 lbl_801A1ED4[];
extern s32 lbl_801A1EE4[];
extern f32 lbl_801A1EFC[];
extern s32 lbl_803EB084[];
extern s32 lbl_803EB090[];
extern s32 lbl_803EB09C[];
extern s32 lbl_803EB0A8[];
extern s32 lbl_8040A670;
extern f32 lbl_801A1F28[];
extern s32 lbl_803EB0B4[];
extern s32 lbl_803EB0C0[];
extern s32 lbl_803EB0CC[];
extern s32 lbl_8040922C;
extern s32 lbl_80409230;
extern s32 lbl_80409234;
s32 fn_800131B8(s32 *);

/* Retake_D (exit) and Retake_E (update) lifts: each special's instance animation plays
 * a start sound once while running (flags < 0) and a stop sound at its end frame. Live in
 * Retake_E (2026-11-08): the specials are lift_r2_lift*, end frame 64, ltime 1 at rest. */
#define NuSpecialExistsFn ((s32 (*)(struct nuhspecial_s *))fn_800130F4)
#define NuSpecialGetInstAnim ((struct nuinstanim_s *(*)(struct nuhspecial_s *))fn_8001384C)
#define fn_800133FC_ ((s32 (*)(struct nuhspecial_s *))fn_800133FC)
#define SPECIAL(x) ((struct nuhspecial_s *)(x))

#define RETAKE_LIFT_FLAG(sp, bit) \
    if (NuSpecialExistsFn(SPECIAL(sp)) != 0) { \
        ia = NuSpecialGetInstAnim(SPECIAL(sp)); \
        if (ia != NULL) { \
            end = *SPECIAL(sp)->scene->instanim_data[ia->anim_ix]; \
            if (ia->flags < 0) { \
                fn_8006DCD4(lbl_801A1EC4, fn_800133FC_(SPECIAL(sp)) + 0x30); \
            } else if (ia->ltime >= end && !(lbl_8040B154 & bit)) { \
                lbl_8040B154 |= bit; \
                fn_8006DCD4(lbl_801A1ED4, fn_800133FC_(SPECIAL(sp)) + 0x30); \
            } else if (ia->ltime <= lbl_801A1EFC[0]) { \
                lbl_8040B154 &= ~bit; \
            } \
        } \
    }

void fn_800BD1F4(void) {
    struct nuinstanim_s *ia;
    f32 end;

    exit_by_spline(NULL, 0x25, 0x27);
    RETAKE_LIFT_FLAG(lbl_803EB084, 1)
    RETAKE_LIFT_FLAG(lbl_803EB090, 2)
    RETAKE_LIFT_FLAG(lbl_803EB09C, 4)
    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0A8)) != 0) {
        ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0A8));
        if (ia != NULL) {
            end = *SPECIAL(lbl_803EB0A8)->scene->instanim_data[ia->anim_ix];
            if (ia->flags < 0 && lbl_8040A670 == 0) {
                lbl_8040A670 = 1;
                fn_8006DCD4(lbl_801A1EE4, fn_800133FC_(SPECIAL(lbl_803EB0A8)) + 0x30);
            } else if (ia->ltime <= lbl_801A1EFC[0] || ia->ltime >= end) {
                lbl_8040A670 = 0;
            }
        }
    }
}

#define fn_800131B8_ ((s32 (*)(struct nuhspecial_s *))fn_800131B8)

void fn_800BD594(void) {
    struct nuinstanim_s *ia;
    f32 end;
    s32 r;

    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0B4)) != 0) {
        ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0B4));
        if (ia != NULL) {
            end = *SPECIAL(lbl_803EB0B4)->scene->instanim_data[ia->anim_ix];
            if (ia->flags < 0 && lbl_8040922C == 0) {
                lbl_8040922C = 1;
                fn_8006DCD4(lbl_801A1EE4, fn_800133FC_(SPECIAL(lbl_803EB0B4)) + 0x30);
            } else if (ia->ltime <= lbl_801A1F28[0] || ia->ltime >= end) {
                lbl_8040922C = 0;
            }
        }
    }
    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0C0)) != 0) {
        r = fn_800131B8_(SPECIAL(lbl_803EB0C0));
        if (r == 1) {
            ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0C0));
            if (ia != NULL) {
                end = *SPECIAL(lbl_803EB0C0)->scene->instanim_data[ia->anim_ix];
                if (ia->flags < 0 && lbl_80409230 == 0) {
                    lbl_80409230 = r;
                    fn_8006DCD4(lbl_801A1EE4, fn_800133FC_(SPECIAL(lbl_803EB0C0)) + 0x30);
                } else if (ia->ltime <= lbl_801A1F28[0] || ia->ltime >= end) {
                    lbl_80409230 = 0;
                }
            }
        }
    }
    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0CC)) != 0) {
        ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0CC));
        if (ia != NULL) {
            end = *SPECIAL(lbl_803EB0CC)->scene->instanim_data[ia->anim_ix];
            if (ia->flags < 0) {
                fn_8006DCD4(lbl_801A1EC4, fn_800133FC_(SPECIAL(lbl_803EB0CC)) + 0x30);
            } else if (lbl_80409234 == 0 && ia->ltime >= end) {
                lbl_80409234 = 1;
                fn_8006DCD4(lbl_801A1ED4, fn_800133FC_(SPECIAL(lbl_803EB0CC)) + 0x30);
            }
        }
    }
}
#undef NuSpecialExistsFn
#undef NuSpecialGetInstAnim
#undef fn_800133FC_
#undef fn_800131B8_
#undef SPECIAL
#undef RETAKE_LIFT_FLAG

extern s32 lbl_801A25D4[];
extern s32 lbl_801A25DC[];
extern s32 lbl_801A25E4[];
extern s32 lbl_801A25EC[];
extern s32 lbl_801A25F4[];
extern s32 lbl_801A25FC[];
extern s32 lbl_801A2604[];
extern s32 lbl_801A260C[];
extern s32 lbl_803EB12C[];
extern s32 lbl_803EB138[];
extern s32 lbl_803EB144[];
extern s32 lbl_803EB150[];
extern s32 lbl_803EB15C[];
extern s32 lbl_803EB168[];
extern s32 lbl_803EB174[];
extern s32 lbl_803EB180[];
extern s8 lbl_8040A68C;

void FactoryFInit(void) {
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB12C, lbl_801A25D4, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB138, lbl_801A25DC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB144, lbl_801A25E4, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB150, lbl_801A25EC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB15C, lbl_801A25F4, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB168, lbl_801A25FC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB174, lbl_801A2604, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB180, lbl_801A260C, 1);
    lbl_8040A68C = 0;
}

s32 PauseMenu_HandleEntry1(s32 *);
s32 fn_800133FC(s32 *);
extern s32 lbl_801A1BD0[];
extern s32 lbl_801A1BE4[];
extern s32 lbl_802DA264[];
extern s32 lbl_8040A658;
extern s32 lbl_8040A65C;

void fn_800CCB4C(void) {
    s32 var_r3;

    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA264, lbl_801A1BD0, 1);
    lbl_8040A658 = PauseMenu_HandleEntry1(lbl_801A1BE4);
    var_r3 = fn_800130F4(lbl_802DA264);
    if (var_r3 != 0) {
        var_r3 = fn_800133FC(lbl_802DA264) + 0x30;
    }
    lbl_8040A65C = var_r3;
}

s32 PauseMenu_HandleEntry1(s32 *);
s32 fn_800133FC(s32 *);
extern s32 lbl_801A1BE4[];
extern s32 lbl_801A1BEC[];
extern s32 lbl_802DA270[];
extern s32 lbl_8040A660;
extern s32 lbl_8040A664;

void fn_800CCC24(void) {
    s32 var_r3;

    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA270, lbl_801A1BEC, 1);
    lbl_8040A660 = PauseMenu_HandleEntry1(lbl_801A1BE4);
    var_r3 = fn_800130F4(lbl_802DA270);
    if (var_r3 != 0) {
        var_r3 = fn_800133FC(lbl_802DA270) + 0x30;
    }
    lbl_8040A664 = var_r3;
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CCDE4(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 8;
            } else {
                lbl_804093B8 = 0xA;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CCE78(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 9;
            } else {
                lbl_804093B8 = 0xB;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CCF0C(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s32 var_r29;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r29 = 0xC;
    if ((s32) lbl_804091F8 != 0) {
        var_r29 = 0xD;
    }
    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0xA;
                return;
            }
            lbl_804093B8 = var_r29;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CCFB8(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x11;
            } else {
                lbl_804093B8 = 0x13;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD144(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s32 var_r29;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r29 = 0x15;
    if ((s32) lbl_804091F8 != 0) {
        var_r29 = 0x16;
    }
    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x13;
                return;
            }
            lbl_804093B8 = var_r29;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD3F0(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x26;
            } else {
                lbl_804093B8 = 0x28;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD4C8(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x27;
            } else {
                lbl_804093B8 = 0x29;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD55C(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s32 var_r29;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r29 = 0x2A;
    if ((s32) lbl_804091F8 != 0) {
        var_r29 = 0x2B;
    }
    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x28;
                return;
            }
            lbl_804093B8 = var_r29;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD700(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x2D;
            } else {
                lbl_804093B8 = 0x2F;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD804(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x2F;
            } else {
                lbl_804093B8 = 0x31;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CD9DC(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x36;
            } else {
                lbl_804093B8 = 0x37;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDA70(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x38;
            } else {
                lbl_804093B8 = 0x3A;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDB04(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x37;
            } else {
                lbl_804093B8 = 0x39;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDD30(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x41;
            } else {
                lbl_804093B8 = 0x43;
            }
        }
    }
}

extern s32 lbl_801A269C[];
extern s32 lbl_801A26A4[];
extern s32 lbl_801A26AC[];
extern s32 lbl_801A26B4[];
extern s32 lbl_801A26BC[];
extern s32 lbl_801A26C4[];
extern s32 lbl_802DA750[];
extern s32 lbl_802DA75C[];
extern s32 lbl_802DA768[];
extern s32 lbl_802DA774[];
extern s32 lbl_802DA780[];
extern s32 lbl_802DA78C[];

void FactoryDInit(void) {
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA750, lbl_801A269C, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA75C, lbl_801A26A4, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA768, lbl_801A26AC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA774, lbl_801A26B4, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA780, lbl_801A26BC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA78C, lbl_801A26C4, 1);
    lbl_8040B154 = 0;
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDEA8(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x42;
            } else {
                lbl_804093B8 = 0x44;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDF3C(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x43;
            } else {
                lbl_804093B8 = 0x45;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CDFD0(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x45;
            } else {
                lbl_804093B8 = 0x47;
            }
        }
    }
}

extern s32 lbl_801A2B00[];
extern s32 lbl_801A2B10[];
extern u8 lbl_803EAD09[];

void CruiserAInit(void) {
    *lbl_8040B060 = 0;
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD24, lbl_801A2B00, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD30, lbl_801A2B10, 1);
    if (((s32) lbl_804091F8 != 0) || ((s32) lbl_803EAD09[0] != 0)) {
        *lbl_8040B060 = 2;
    }
}

extern f32 lbl_801A4EF4[];

/* Cruiser_B exit (level table +0x24): socks 5-8, or sock 2 short of 8.125, lead to
 * Cruiser_G (0x5E); everything else to Cruiser_C (0x5A). */
void fn_800CE4EC(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;
    s32 level;

    if (fn_800AAC04(&pos, &sp) != 0) {
        if (((sp.sock >= 5) && (sp.sock <= 8)) || ((sp.sock == 2) && (sp.distance < lbl_801A4EF4[0]))) {
            level = 0x5E;
        } else {
            level = 0x5A;
        }
        lbl_804093B8 = level;
    }
}

extern f32 lbl_801A4EF8[];

/* Cruiser_C exit: sock 5, or sock 6 past 2.5, leads to Cruiser_B (0x59); else Cruiser_D. */
void fn_800CE558(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;
    s32 level;

    if (fn_800AAC04(&pos, &sp) != 0) {
        if ((sp.sock == 5) || ((sp.sock == 6) && (sp.distance > lbl_801A4EF8[0]))) {
            level = 0x59;
        } else {
            level = 0x5B;
        }
        lbl_804093B8 = level;
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CE5C4(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x5C;
            } else {
                lbl_804093B8 = 0x5A;
            }
        }
    }
}

extern f32 lbl_801A4EFC[];

/* Cruiser_E exit: sock 2 short of 5.25 (the Cruiser_D end) leads back to Cruiser_D (0x5B);
 * else Cruiser_F (0x5D). */
void fn_800CE658(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;

    if (fn_800AAC04(&pos, &sp) != 0) {
        if ((sp.sock == 2) && (sp.distance < lbl_801A4EFC[0])) {
            lbl_804093B8 = 0x5B;
        } else {
            lbl_804093B8 = 0x5D;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CE6B4(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s32 var_r29;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r29 = 0x5F;
    if ((s32) lbl_804091F8 != 0) {
        var_r29 = 0x61;
    }
    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x5C;
                return;
            }
            lbl_804093B8 = var_r29;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CE760(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x58;
            } else {
                lbl_804093B8 = 0x59;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CEAD4(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x64;
            } else {
                lbl_804093B8 = 0x66;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CEB68(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x65;
            } else {
                lbl_804093B8 = 0x67;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CEBFC(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x66;
            } else {
                lbl_804093B8 = 0x68;
            }
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

void fn_800CED34(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x6D;
            } else {
                lbl_804093B8 = 0x6B;
            }
        }
    }
}

s32 fn_80105500(struct lbl_80409410_s *, s8, s32, s32);
extern s32 lbl_801A307C[];
extern s16 lbl_803ED3AC[];

/* Bonus_A exit: sock 3 with one candidate leads to Bonus_Status (0x7A); else Bonus_B. */
void fn_800CF138(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;

    if ((fn_800AAC04(&pos, &sp) != 0) && (sp.sock != -1)) {
        if ((sp.sock == 3) && (sp.candidate_count == 1)) {
            lbl_804093B8 = 0x7A;
        } else {
            lbl_804093B8 = 0x79;
        }
    }
}

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

/* Temple_C exit: socks 10-13 (the far end) load Temple_Status (0x6E); elsewhere the side of
 * the spline picks Temple_B (0x6C) or Temple_Status. Chapter 6 has no outro level, so the
 * exit goes to the status level in story mode as well (Ellie: the story cutscene is played
 * at the end some other way). */
void fn_800C61DC(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;

    if ((fn_800AAC04(&pos, &sp) != 0) && (sp.sock != -1)) {
        if ((sp.sock >= 10) && (sp.sock <= 13)) {
            lbl_804093B8 = 0x6E;
            return;
        }
        exit_by_spline(NULL, 0x6C, 0x6E);
    }
}

void MapEReset(void) {
    s32 temp_r3;

    lbl_803ED3AC[0] = -1;
    temp_r3 = FindObstacle((s32) lbl_80409410, lbl_801A307C);
    if (temp_r3 != 0) {
        fn_80105500(lbl_80409410, (s8) (*(u8 *)((s8 *)(temp_r3) + (0x71))), 0, 0);
    }
}

void fn_8000CBF4(void *, void *, void *, void *);
extern f32 lbl_801A4C28[];
extern const f32 lbl_801A4C2C[];

void InitDoors(void) {
    struct lbl_80409410_240_s *a;
    s32 i;
    f32 d;
    char *pts;

    a = lbl_80409410->unk240;
    if (a != NULL) {
        for (i = 0; i < lbl_80409410->unk244; i++, a++) {
            pts = a->spl->pts;
            NuVecAdd(&a->centre, (struct nuvec_s *)pts, (struct nuvec_s *)(pts + a->spl->ptsize));
            NuVecAdd(&a->centre, &a->centre, (struct nuvec_s *)(a->spl->pts + a->spl->ptsize * 2));
            NuVecAdd(&a->centre, &a->centre, (struct nuvec_s *)(a->spl->pts + a->spl->ptsize * 3));
            NuVecScale(&a->centre, &a->centre, lbl_801A4C28[0]);
            a->radius = NuVecDist(&a->centre, a->spl->pts, 0);
            d = NuVecDist(&a->centre, a->spl->pts + a->spl->ptsize, 0);
            if (d > a->radius) {
                a->radius = d;
            }
            d = NuVecDist(&a->centre, a->spl->pts + a->spl->ptsize * 2, 0);
            if (d > a->radius) {
                a->radius = d;
            }
            d = NuVecDist(&a->centre, a->spl->pts + a->spl->ptsize * 3, 0);
            if (d > a->radius) {
                a->radius = d;
            }
            a->radius *= lbl_801A4C2C[0];
            fn_8000CBF4(a->unk74, a->spl->pts, a->spl->pts + a->spl->ptsize, a->spl->pts + a->spl->ptsize * 3);
        }
    }
}

extern const f32 lbl_8019FEE0[];
extern f32 lbl_80408E9C;

void fn_800ABF7C(void *arg0) {
    f32 temp_f13;
    f32 temp_f13_2;
    u8 temp_r9;

    temp_f13 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    if (temp_f13 > lbl_8019FEE0[0]) {
        (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (temp_f13 - lbl_80408E9C);
    }
    temp_f13_2 = (*(f32 *)((s8 *)(arg0) + (4)));
    if (temp_f13_2 > lbl_8019FEE0[0]) {
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (temp_f13_2 - lbl_80408E9C);
    }
    temp_r9 = (*(u8 *)((s8 *)(arg0) + (0x10)));
    if ((s32) temp_r9 != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x10))) = (u8) (temp_r9 - 1);
    }
}

extern f32 lbl_801A1A08[];

s32 fn_800BA244(s32 *arg0)
{
  void *temp_r3;
  if (fn_800130F4(arg0) != 0)
  {
    temp_r3 = fn_8001384C((s32) arg0);
    if (temp_r3 != ((void *) 0))
    {
      *((f32 *) (((s8 *) temp_r3) + 0x4C)) = (f32) lbl_801A1A08[0];
      temp_r3++;
      temp_r3--;
      *((s32 *) (((s8 *) temp_r3) + 0x50)) = (s32) ((*((s32 *) (((s8 *) temp_r3) + 0x50))) & 0x7FFFFFFF);
      return 1;
    }
  }
  return 0;
}

#define NuSpecialExistsFn ((s32 (*)(struct nuhspecial_s *))fn_800130F4)
#define NuSpecialGetInstAnim ((struct nuinstanim_s *(*)(struct nuhspecial_s *))fn_8001384C)
#define PlaySfxAt ((s32 (*)(s32 *, void *))fn_8006DCD4)
#define FindPlayer ((s8 *(*)(s32, s32, s32))fn_800D515C)
s32 fn_8011E9C4(s32);
/* Maul_F: the first three blocks track force-object lifts (lbl_803EAEC4 entries hold a
 * nuhspecial_s at +4; confirmed live) and the last three track special lifts. The
 * duplicated 0x7E fallback keeps the retail placement of the r29-r31 re-`lis`. */
extern s32 lbl_801A2150[];
extern s32 lbl_801A2164[];
extern s32 lbl_801A2170[];
extern f32 lbl_801A217C[];
extern f32 lbl_801A2180[];
extern s32 lbl_801D68E4[];
extern s32 lbl_803EAD48[];
extern s32 lbl_803EAD54[];
extern s32 lbl_803EAD60[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_80408F2C;
extern s32 lbl_80408FE0;
extern s32 lbl_804091F8;
extern s32 lbl_80409240;
extern s32 lbl_804093B0;
extern s32 lbl_8040AF64;
extern s32 lbl_8040AF94;
extern u8 lbl_8040B060[];
extern s32 lbl_8040B154;

#define MAULF_FORCE(i, bit) \
    if (lbl_803EAEC4[i] != 0) { \
        ia = NuSpecialGetInstAnim((struct nuhspecial_s *)(lbl_803EAEC4[i] + 4)); \
        if (ia != NULL) { \
            if (ia->flags < 0) { \
                if (!(lbl_8040B154 & bit)) { \
                    lbl_8040B154 |= bit; \
                    PlaySfxAt(lbl_801A2150, &ia->pad0[0x30]); \
                } \
            } else if (ia->ltime <= lbl_801A2180[0]) { \
                lbl_8040B154 &= ~bit; \
            } \
        } \
    }

#define MAULF_SPECIAL(sp, bit) \
    if (NuSpecialExistsFn((struct nuhspecial_s *)sp) != 0) { \
        ia = NuSpecialGetInstAnim((struct nuhspecial_s *)sp); \
        if (ia != NULL) { \
            if (ia->flags < 0) { \
                PlaySfxAt(lbl_801A2164, &ia->pad0[0x30]); \
            } else if (ia->ltime > lbl_801A2180[0] && !(lbl_8040B154 & bit)) { \
                lbl_8040B154 |= bit; \
                PlaySfxAt(lbl_801A2170, &ia->pad0[0x30]); \
            } \
        } \
    }

void MaulFUpdate(void) {
    struct nuinstanim_s *ia;
    s8 *p;
    struct episode_s *area;
    s32 i;
    s32 n;

    if ((void *)lbl_80409240 != NULL && *(f32 *)(lbl_80409240 + 0x28) == lbl_801A217C[0] && lbl_8040B060[0] == 0) {
        p = FindPlayer(8, 1, 1);
        if (p == NULL || !(*(s32 *)(p + 0xF24) & 2) || (*(u8 *)(p + 0x28F) == 0 && *(u8 *)(p + 0x1085) != 0)) {
            p = NULL;
        }
        if (p != NULL) {
            lbl_8040B060[0] = 1;
            if (lbl_804091F8 != 0) {
                lbl_80408F2C = 1;
                lbl_804093B0 = 0x7B;
                if (lbl_80408FE0 == 0) {
                    area = (struct episode_s *)lbl_80409410->unk1AC;
                    if (area != NULL) {
                        i = 0;
                        n = -1;
                        if (i < area->count) {
                            do {
                                n = area->levels[i];
                                if (!(lbl_801D68E4[n * 0xA8 / 4] & 0x4000)) {
                                    n = -1;
                                    i++;
                                }
                            } while (i < area->count && n == -1);
                        }
                        if (n != -1) {
                            lbl_804093B0 = n;
                        }
                    } else {
                        lbl_804093B0 = 0x7E;
                    }
                } else {
                    lbl_804093B0 = 0x7E;
                }
                if (lbl_8040AF64 != -1) {
                    lbl_8040AF94 = 1;
                }
            } else {
                fn_8011E9C4(0x25);
            }
        }
    }
    MAULF_FORCE(0, 1)
    MAULF_FORCE(1, 2)
    MAULF_FORCE(2, 4)
    MAULF_SPECIAL(lbl_803EAD48, 8)
    MAULF_SPECIAL(lbl_803EAD54, 0x10)
    MAULF_SPECIAL(lbl_803EAD60, 0x20)
}

#undef MAULF_SPECIAL
#undef MAULF_FORCE
#undef FindPlayer
#undef PlaySfxAt
#undef NuSpecialGetInstAnim
#undef NuSpecialExistsFn

extern s32 lbl_801A2194[];
extern s32 lbl_803EB120[];
extern u8 lbl_8040A67E;
extern s32 lbl_8040B158;

void fn_800BE6E4(void)
{
  struct nuvec_s sp8;
  s32 *new_var;
  s16 temp_r0;
  s32 var_r9;
  s8 *temp_r9;
  struct nugspline_s *temp_r31;
  struct nuvec_s *var_r30;
  void *temp_r3;
  var_r30 = (void *) 0;
  temp_r31 = lbl_80409410->unk1974;
  if (temp_r31 != ((void *) 0))
  {
    if (fn_800AAC04(&sp8, (void *) 0) != 0)
    {
      var_r30 = &sp8;
    }
    if (var_r30 != ((void *) 0))
    {
      temp_r9 = temp_r31->pts;
      temp_r0 = temp_r31->ptsize;
      if (fn_800CFD4C(*((f32 *) (&sp8)), sp8.z, *((f32 *) (((s8 *) temp_r9) + 0)), *((f32 *) (((s8 *) temp_r9) + 8)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 0)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 8))) != 0)
      {
        lbl_804093B8 = 0x2E;
      }
      else
      {
        lbl_804093B8 = 0x30;
      }
    }
  }
  new_var = lbl_803EB120;
  if (((fn_800130F4(new_var) == 0) || ((temp_r3 = fn_8001384C((s32) lbl_803EB120), (temp_r3 == ((void *) 0)) != 0))) || ((var_r9 = 1, (((s32) (*((s32 *) (((s8 *) temp_r3) + 0x50)))) < 0) == 0)))
  {
    var_r9 = 0;
  }
  if ((var_r9 != 0) && (((s32) lbl_8040A67E) == 0))
  {
    lbl_8040A67E = 1;
    fn_8006DCD4(lbl_801A2194, lbl_8040B158);
  }
}

extern s32 lbl_801A21A8[];
extern s32 lbl_801A21B4[];
extern s32 lbl_801A21C0[];
extern s32 lbl_801A21CC[];
extern s32 lbl_801A21D8[];
extern s32 lbl_801A21E4[];
extern s32 lbl_801A21F0[];
extern s32 lbl_801A21FC[];
extern s32 lbl_803EAEC4[];
extern s8 lbl_8040A683;

void MaulEInit(void)
{
  int new_var2;
  s32 var_ctr;
  long new_var;
  s8 *var_r9;
  new_var2 = 1;
  var_ctr = 4;
  var_r9 = &lbl_8040A683;
  do
  {
    *var_r9 = new_var2;
    var_r9 -= new_var2;
    var_ctr -= new_var2;
  }
  while (var_ctr != 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0)) = FindForceObject(lbl_80409410, lbl_801A21A8, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 4)) = FindForceObject(lbl_80409410, lbl_801A21B4, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 8)) = FindForceObject(lbl_80409410, lbl_801A21C0, 0);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0xC)) = FindForceObject(lbl_80409410, lbl_801A21CC, 0);
  new_var = 0;
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x10)) = FindForceObject(lbl_80409410, lbl_801A21D8, new_var);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x14)) = FindForceObject(lbl_80409410, lbl_801A21E4, new_var);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x18)) = FindForceObject(lbl_80409410, lbl_801A21F0, new_var);
  *((s32 *) (((s8 *) lbl_803EAEC4) + 0x1C)) = FindForceObject(lbl_80409410, lbl_801A21FC, new_var);
}

extern s32 lbl_8038E7A0[];
extern u8 lbl_803E0199[];
extern s32 lbl_8040AFAC;

void fn_800C10CC(void)
{
  struct nuvec_s sp8;
  s16 temp_r0;
  s32 var_r29;
  s8 *temp_r9;
  s8 var_r11;
  s32 *new_var;
  struct nugspline_s *temp_r31;
  struct nuvec_s *var_r30;
  var_r29 = 0x3B;
  if (((s32) lbl_804091F8) != 0)
  {
    var_r29 = 0x3D;
  }
  var_r30 = (void *) 0;
  temp_r31 = lbl_80409410->unk1974;
  if (temp_r31 != ((void *) 0))
  {
    if (fn_800AAC04(&sp8, (void *) 0) != 0)
    {
      var_r30 = &sp8;
    }
    if (var_r30 != ((void *) 0))
    {
      temp_r9 = temp_r31->pts;
      temp_r0 = temp_r31->ptsize;
      if (fn_800CFD4C(*((f32 *) (&sp8)), sp8.z, *((f32 *) (((s8 *) temp_r9) + 0)), *((f32 *) (((s8 *) temp_r9) + 8)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 0)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 8))) != 0)
      {
        lbl_804093B8 = 0x3A;
      }
      else
      {
        lbl_804093B8 = var_r29;
      }
    }
  }
  fn_800BE9B0();
  new_var = lbl_8038E7A0;
  var_r11 = 0;
  if ((((s32) lbl_8040AFAC) != 0) || (((s32) lbl_803E0199[0]) == 0x1E))
  {
    var_r11 = 1;
  }
  *((s8 *) (((s8 *) new_var) + 1)) = var_r11;
}

extern s32 lbl_801A1EA4[];
extern s32 lbl_801A1EAC[];
extern s32 lbl_801A1EB4[];
extern s32 lbl_801A1EBC[];
extern s32 lbl_803EB084[];
extern s32 lbl_803EB090[];
extern s32 lbl_803EB09C[];
extern s32 lbl_803EB0A8[];
extern s32 lbl_8040A668;
extern s32 lbl_8040A66C;
extern s32 lbl_8040A670;

void fn_800CD2B4(void)
{
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB084, lbl_801A1EA4, 1);
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB090, lbl_801A1EAC, 1);
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB09C, lbl_801A1EB4, 1);
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0A8, lbl_801A1EBC, 1);
  lbl_8040B154 = 0;
  lbl_8040A668 = 0;
  lbl_8040A66C = 0;
 do { lbl_8040A670 = 0; } while (0);
}

extern s32 lbl_801A1F00[];
extern s32 lbl_801A1F10[];
extern s32 lbl_801A1F20[];
extern s32 lbl_803EB0B4[];
extern s32 lbl_803EB0C0[];
extern s32 lbl_803EB0CC[];
extern s32 lbl_8040922C;
extern s32 lbl_80409230;
extern s32 lbl_80409234;

void fn_800CD364(void)
{
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0B4, lbl_801A1F00, 1);
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0C0, lbl_801A1F10, 1);
  NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0CC, lbl_801A1F20, 1);
  lbl_80409234 = 0;
 do { lbl_8040922C = 0; } while (0);
  lbl_80409230 = 0;
}

s32 fn_8006DCD4(s32 *, s32);
s32 fn_8014CAE8();
extern s32 lbl_801A25C8[];
extern f32 lbl_801A4ED4[];
extern f32 lbl_801A4ED8[];
extern s32 lbl_8040B18C;

void fn_800CDBF8(void)
{
  s32 new_var;
  f32 var_f0;
  fn_8014CAE8();
  if (((s32) lbl_8040B18C) != 2)
  {
    fn_8006DCD4(lbl_801A25C8, 0);
  }
  if (((void *) lbl_8040B19C) != ((void *) 0))
  {
    new_var = lbl_8040B19C;
    if (((s32) lbl_8040B18C) == 2)
    {
      var_f0 = lbl_801A4ED4[0];
    }
    else
    {
      var_f0 = lbl_801A4ED8[0];
    }
    *((f32 *) (((s8 *) new_var) + 0x28)) = var_f0;
  }
}

s32 memset(s32 *, ...);
extern s32 lbl_803EAAA0[];
extern s32 lbl_804091E0;

void fn_800BA2AC(void) {
    memset(lbl_803EAAA0, 0, 0xC0);
    lbl_804091E0 = 0;
}

s32 memset(s32 *, ...);
extern s32 lbl_803E8690[];
extern s32 lbl_8040A64C;

void fn_800BA444(void) {
    memset(lbl_803E8690, 0, 0x2200);
    lbl_8040A64C = 0;
}

s32 memset(s32 *, ...);
extern s32 lbl_802E0B9C[];

void fn_800CE408(void) {
    memset(lbl_802E0B9C, 0, 0x14);
}

s32 fn_800951FC(s32);

extern void *lbl_80409430;
extern s32 lbl_8040B058;

void fn_800D4C88(void) {
    memset(lbl_80409430, 0, 0x42600);
    fn_800951FC((*(s32 *)((s8 *)(lbl_80409410) + (0x2E0))));
    lbl_8040B058 = 0;
}

void fn_800AB8C8(void);
s32 fn_80105C74(s32);
s32 fn_801205AC(s32);
s32 fn_8013DE58(s32, ...);
s32 fn_8014093C(s32);

void fn_800CCAFC(s32 arg0) {
    fn_800AB8C8();
    fn_8013DE58(arg0);
    fn_80105C74(arg0);
    fn_801205AC(arg0);
    fn_8014093C(arg0);
}

extern s32 lbl_803E8284[];

s32 fn_800ABA50(void *arg0) {
    s32 temp_r3;

    temp_r3 = lbl_803E8284[(*(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0xEEC)) + 0x7B1)) & 7];
    if (temp_r3 == 0) {
        return lbl_803E8284[0];
    }
    return temp_r3;
}

extern u8 NuTimeBar_DefaultColours[];

s32 fn_800AC304(s32 arg0) {
    u8 *var_r9;
    u8 temp_r0;

    var_r9 = NuTimeBar_DefaultColours;
    if ((s32) NuTimeBar_DefaultColours[0] != 0xFF) {
loop_1:
        if ((s32) (*(u8 *)((s8 *)(var_r9) + (0))) == arg0) {
            return 1;
        }
        temp_r0 = (*(u8 *)((s8 *)(var_r9) + (1)));
        var_r9 += 1;
        if ((s32) temp_r0 == 0xFF) {
            /* Duplicate return node #4. Try simplifying control flow for better match */
            goto done;
        }
        goto loop_1;
    }
done:
    return 0;
}

s32 fn_8002B3A0(s32);
extern void *lbl_80408DF0;

void fn_800D4C00(s32 arg0) {
    s32 var_r30;
    s32 var_r31;
    void *var_r9;

    if (arg0 == 0) {
        var_r31 = (*(s32 *)((s8 *)(lbl_80408DF0) + (0xC)));
    } else {
        var_r31 = 0;
    }
    var_r9 = lbl_80408DF0;
    if (var_r31 < (s32) (*(s32 *)((s8 *)(var_r9) + (0x10)))) {
        var_r30 = var_r31 * 0x54;
        do {
            if ((s32) (*(s32 *)((s8 *)((var_r30 + (*(s32 *)((s8 *)(var_r9) + (0x18))))) + (4))) != 0) {
                fn_8002B3A0((*(s32 *)((s8 *)((var_r30 + (*(s32 *)((s8 *)(var_r9) + (0x18))))) + (4))));
            }
            var_r9 = lbl_80408DF0;
            var_r31 += 1;
            var_r30 += 0x54;
        } while (var_r31 < (s32) (*(s32 *)((s8 *)(var_r9) + (0x10))));
    }
}

extern f32 lbl_8019FF08[];
extern f32 lbl_8019FF0C[];
extern s32 lbl_8040AF5C;

f32 fn_800AC178(struct nuvec_s *arg0, f32 farg0, f32 farg1, f32 farg2) {
    struct nuvec_s sp8;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f28;

    temp_f28 = lbl_8019FF08[0];
    if (!(farg2 <= temp_f28)) {
        NuVecSub(&sp8, arg0, lbl_8040AF5C + 0x30);
        temp_f0 = (*(f32 *)&(sp8));
        temp_f1 = (sp8.z * sp8.z) + ((temp_f0 * temp_f0) + (sp8.y * sp8.y));
        if (temp_f1 < (farg1 * farg1)) {
            if (temp_f1 > (farg0 * farg0)) {
                return farg2 * (lbl_8019FF0C[0] - ((NuFsqrt(temp_f1) - farg0) / (farg1 - farg0)));
            }
            return farg2;
        }
    }
    return temp_f28;
}

s32 Menu_CloseCurrent();
s32 fn_800C9648(s32, s32);

void Menu_Unknown10_HandleSelection(void *arg0) {
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        fn_800C9648((*(s32 *)((s8 *)(lbl_80409410) + (0x240))) + (((*(s16 *)((s8 *)(arg0) + (0xA))) - (*(s16 *)((s8 *)(arg0) + (0xE)))) * 0x94), 0);
        return;
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
        Menu_CloseCurrent();
    }
}

s32 Menu_CloseCurrent();
extern s32 lbl_804090E0;
extern s32 lbl_804090F4;
extern s32 lbl_804093B0;
extern s32 lbl_8040AFF0;
extern s32 lbl_8040AFF8;

void SceneSelect_HandleSelection(void *arg0) {
    s32 temp_r31;

    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        temp_r31 = *(s32 *)(&lbl_804090F4 + ((*(s32 *)((s8 *)(arg0) + (0x34)))));
        if ((s32) lbl_8040AFF8 == 0) {
            lbl_8040AFF0 = 1;
            lbl_8040AFF8 = 1;
        }
        SceneSelect_HandleEntry();
        lbl_804093B0 = temp_r31;
        lbl_804090E0 = 1;
        return;
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
        Menu_CloseCurrent();
    }
}

s32 fn_800D05E0(void *);
extern void *lbl_80409430;
extern s32 lbl_8040B058;

void fn_800AB85C(void) {
    s32 var_r30;
    void *var_r31;

    var_r30 = 0;
    var_r31 = lbl_80409430;
    for (; var_r30 < (s32)lbl_8040B058; var_r30 += 1, var_r31 += 0x1098) {
            if (((s32) (*(s32 *)((s8 *)(var_r31) + (0x20C))) < 0) && ((*(s32 *)((s8 *)(var_r31) + (0x208))) & 0x400)) {
                fn_800D05E0(var_r31);
            }
    }
}

s32 fn_800131B8(s32 *);
void fn_8006DE5C(s32, s32);
extern s32 lbl_80408FE0;

s32 fn_800CFD4C(f32, f32, f32, f32, f32, f32);

/* Negotiations_A exit (level table +0x24): on socks 3, 7 and 8 the side of the
 * spline picks Negotiations_C (4) or Negotiations_B (3); any other sock leads to _B. */
void fn_800BBE10(void) {
    struct nuvec_s pos;
    struct sockposition_s sp;

    if ((fn_800AAC04(&pos, &sp) != 0) && (sp.sock != -1)) {
        if ((sp.sock == 3) || (sp.sock == 7) || (sp.sock == 8)) {
            exit_by_spline(&pos, 4, 3);
        } else {
            lbl_804093B8 = 3;
        }
    }
}

void fn_800BBED0(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s16 temp_r0_2;
    s32 var_r29;
    s8 *temp_r9;
    s8 *temp_r9_2;
    struct nugspline_s *temp_r31;
    struct nugspline_s *temp_r31_2;
    struct nuvec_s *var_r30;
    struct nuvec_s *var_r30_2;

    if ((s32) lbl_80408FE0 == 2) {
        lbl_804093B8 = lbl_80408FE0;
    } else if ((s32) lbl_80408FE0 == 1) {
        var_r30 = NULL;
        temp_r31 = lbl_80409410->unk1974;
        if (temp_r31 != NULL) {
            if (fn_800AAC04(&sp8, NULL) != 0) {
                var_r30 = &sp8;
            }
            if (var_r30 != NULL) {
                temp_r9 = temp_r31->pts;
                temp_r0 = temp_r31->ptsize;
                if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) == 0) {
                    lbl_804093B8 = 5;
                } else {
                    goto block_16;
                }
            }
        }
    } else {
        var_r29 = 5;
        if ((s32) lbl_804091F8 != 0) {
            var_r29 = 6;
        }
        var_r30_2 = NULL;
        temp_r31_2 = lbl_80409410->unk1974;
        if (temp_r31_2 != NULL) {
            if (fn_800AAC04(&sp8, NULL) != 0) {
                var_r30_2 = &sp8;
            }
            if (var_r30_2 != NULL) {
                temp_r9_2 = temp_r31_2->pts;
                temp_r0_2 = temp_r31_2->ptsize;
                if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9_2) + (0))), (*(f32 *)((s8 *)(temp_r9_2) + (8))), (*(f32 *)((s8 *)(&temp_r9_2[temp_r0_2]) + (0))), (*(f32 *)((s8 *)(&temp_r9_2[temp_r0_2]) + (8)))) != 0) {
block_16:
                    lbl_804093B8 = 2;
                } else {
                    lbl_804093B8 = var_r29;
                }
            }
        }
    }
    if ((fn_800130F4(lbl_802DA270) != 0) && (fn_800131B8(lbl_802DA270) == 0) && ((s32) lbl_8040A660 != -1) && ((s32) lbl_8040A664 != 0)) {
        fn_8006DE5C(lbl_8040A660, lbl_8040A664);
    }
}

extern f32 lbl_8019FE90[];
extern f32 lbl_8019FE94[];
extern f32 lbl_8019FE98[];
s32 SetPlayerOnSurface(void *arg0, s32 arg1)
{
  f32 temp_f0;
  f32 temp_f0_2;
  f32 temp_f0_3;
  f32 temp_f10;
  f32 temp_f11;
  f32 temp_f12;
  s32 var_r10;
  var_r10 = 0;
  if ((!((*((s32 *) (((s8 *) (*((void **) (((s8 *) lbl_80409410) + 0x1A8)))) + 4))) & 0x20)) && ((*((f32 *) (((s8 *) arg0) + 0x220))) != lbl_8019FE90[0]))
  {
    if (((s16) (*((s16 *) (((s8 *) arg0) + 0x1074)))) == 0xF)
    {
      temp_f0 = (*((f32 *) (((s8 *) arg0) + 0x101C))) * (*((f32 *) (((s8 *) arg0) + 0xB8)));
      *((f32 *) (((s8 *) arg0) + 0x70)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x70))) - temp_f0);
      *((f32 *) (((s8 *) arg0) + 0x94)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x94))) - temp_f0);
    }
    if (arg1 == 2)
    {
      temp_f0_2 = ((*((f32 *) (((s8 *) arg0) + 0x18C))) - ((*((f32 *) (((s8 *) arg0) + 0x101C))) * (*((f32 *) (((s8 *) arg0) + 0xB8))))) + lbl_8019FE94[0];
 do { *((f32 *) (((s8 *) arg0) + 0x94)) = temp_f0_2; } while (0);
      *((f32 *) (((s8 *) arg0) + 0x70)) = temp_f0_2;
      *((f32 *) (((s8 *) arg0) + 0xAC)) = temp_f0_2;
    }
    temp_f10 = *((f32 *) (((s8 *) arg0) + 0x220));
    temp_f11 = *((f32 *) (((s8 *) arg0) + 0x101C));
    temp_f12 = *((f32 *) (((s8 *) arg0) + 0xB8));
    if ((arg1 == 0) || (!(((temp_f11 * temp_f12) + (*((f32 *) (((s8 *) arg0) + 0x70)))) > (temp_f10 + lbl_8019FE94[0]))))
    {
      var_r10 = 1;
      temp_f0_3 = (temp_f10 - (temp_f11 * temp_f12)) + lbl_8019FE94[0];
      *((f32 *) (((s8 *) arg0) + 0x94)) = temp_f0_3;
      *((f32 *) (((s8 *) arg0) + 0x70)) = temp_f0_3;
      do { *((f32 *) (((s8 *) arg0) + 0xAC)) = temp_f0_3; } while (0);
    }
    *((f32 *) (((s8 *) arg0) + 0x7C)) = (f32) lbl_8019FE98[0];
  }
  return var_r10;
}

extern const f32 lbl_801A5268[];
extern const f32 lbl_801A526C[];
extern const f32 lbl_801A5270[];

s32 GameObjectNearFloor(void *arg0, f32 *arg1) {
    f32 temp_f10;
    f32 temp_f13;
    f32 var_f11;

    temp_f10 = (*(f32 *)((s8 *)(arg0) + (0x220)));
    if (temp_f10 != lbl_801A5268[0]) {
        var_f11 = ((*(f32 *)((s8 *)(arg0) + (0xBC))) / lbl_801A526C[0]) * lbl_801A5270[0];
        if (var_f11 < lbl_801A5270[0]) {
            var_f11 = lbl_801A5270[0];
        }
        temp_f13 = (((*(f32 *)((s8 *)(arg0) + (0x101C))) * (*(f32 *)((s8 *)(arg0) + (0xB8)))) + (*(f32 *)((s8 *)(arg0) + (0x70)))) - temp_f10;
        if (arg1 != NULL) {
            *arg1 = temp_f13;
        }
        if (temp_f13 < var_f11) {
            return 1;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        goto done;
    }
    if (arg1 != NULL) {
        *arg1 = lbl_801A5268[0];
    }
done:
    return 0;
}

void fn_800CCBC0(void) {
    if ((fn_800130F4(lbl_802DA264) != 0) && (fn_800131B8(lbl_802DA264) == 1) && ((s32) lbl_8040A658 != -1) && ((s32) lbl_8040A65C != 0)) {
        fn_8006DE5C(lbl_8040A658, lbl_8040A65C);
    }
}

void Menu_Open(s32, s32, s32);
extern s8 gDifficulty[];

void Menu_Unknown11_HandleSelection(void *arg0) {
    s8 temp_r9;

    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        temp_r9 = (*(u8 *)((s8 *)(arg0) + (0x37))) + 1;
        gDifficulty[0] = temp_r9;
        Menu_Open(7, -1, -1);
        return;
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
        Menu_CloseCurrent();
    }
}

void *AISysFindArea(void *, void *);
extern s32 lbl_801A1CB0[];
extern s32 lbl_803EB004[];

void GunganBReset(void) {
    lbl_803EB004[0] = AISysFindArea((*(s32 *)((s8 *)(lbl_80409410) + (0x2E8))), lbl_801A1CB0);
}

s32 fn_801261FC(void *, s32);

s32 fn_800ABA78(void *arg0) {
    return fn_801261FC(arg0, 0);
}

f32 NuFsqrt(f32);
s16 fn_8000ABDC(f32, f32);
extern u16 lbl_8040B05C;
extern s16 lbl_8040B120;
extern s32 lbl_8040B124;


void fn_800CFE08(void *arg0, u16 *arg1, s16 *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f31;
    s16 temp_r3;

    temp_r3 = fn_8000ABDC((*(f32 *)((s8 *)(arg0) + (0))), (*(f32 *)((s8 *)(arg0) + (8))));
    lbl_8040B120 = temp_r3;
    if (arg2 != NULL) {
        *arg2 = temp_r3;
    }
    temp_f1 = (*(f32 *)((s8 *)(arg0) + (8)));
    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0)));
    temp_f31 = (*(f32 *)((s8 *)(arg0) + (4)));
    lbl_8040B124 = -fn_8000ABDC(temp_f31, NuFsqrt((temp_f0 * temp_f0) + (temp_f1 * temp_f1)));
    lbl_8040B05C = ((u16 *)&lbl_8040B124)[1];
    if (arg1 != NULL) {
        *arg1 = ((u16 *)&lbl_8040B124)[1];
    }
}

f32 fn_8000ED40(f32);
extern const f32 lbl_801A0054[];
extern const f32 lbl_801A0058[];

typedef struct { char pad[0x130]; f32 f130; f32 f134; char pad2[0x176-0x138]; s8 b176; s8 b177; } AFFD8Obj;
void JudderGameCamera(AFFD8Obj *o, s8 arg1, s8 arg2, f32 farg0) {
    f32 temp_f1;
    f32 d;
    f32 v;

    temp_f1 = fn_8000ED40(farg0);
    if (temp_f1 > o->f130) {
        if (arg2 != 0) {
            d = NuVecDist((s8 *)o + 0xDC, (void *)arg2, 0);
            if (d < lbl_801A0054[0]) {
                v = temp_f1 * ((lbl_801A0054[0] - d) / lbl_801A0054[0]);
                o->f130 = o->f134 = v;
                if (farg0 < lbl_801A0058[0]) {
                    o->b176 = 1;
                } else {
                    o->b176 = 0;
                }
            }
        } else {
            o->f130 = o->f134 = temp_f1;
            if (farg0 < lbl_801A0058[0]) {
                o->b176 = 1;
            } else {
                o->b176 = arg2;
            }
        }
        o->b177 = arg1;
    }
}

s32 fn_800130F4(s32 *);
s32 fn_800B2ED4();
extern f32 lbl_801A1AD4[];
extern f32 lbl_801A1AD8[];
extern s32 lbl_803EAD24[];
extern f32 lbl_80408E9C;
extern f32 lbl_8040B14C;
extern f32 lbl_8040B150;

static inline void fn_800BB6D8_approach(f32 *v, f32 t) {
    if (*v > t) {
        *v -= 2.0f * lbl_80408E9C;
        if (*v < t) {
            *v = t;
        }
    } else if (*v < t) {
        *v += 2.0f * lbl_80408E9C;
        if (*v > t) {
            *v = t;
        }
    }
}

void fn_800BB6D8(void) {
    f32 t;
    s32 m;

    if (fn_800130F4(lbl_803EAD24) != 0) {
        m = fn_800B2ED4();
        if (m == -1 || m == 0 || m == 1 || m == 4) {
            t = lbl_801A1AD4[0];
        } else {
            t = lbl_801A1AD8[0];
        }
        fn_800BB6D8_approach(&lbl_8040B14C, t);
    }
    fn_800BB6D8_approach(&lbl_8040B150, lbl_801A1AD4[0]);
}

s32 fn_8006D1BC(s16, s32);
s32 fn_8006DCD4(s32 *, s32);
void fn_800B9928(f32 *, f32);
s32 fn_8010CA18(s32, s32 *, s32 *);
extern f32 NuRndrHackWaterLevel[];
extern const f32 lbl_801A0414[];
extern const f32 lbl_801A0418[];
extern s32 lbl_804086E8;
extern s32 lbl_804086EC;
extern s32 lbl_80408F7C;
extern s32 lbl_80408F80;
extern s32 lbl_80408FE0;
extern f32 lbl_804090EC;
extern s32 lbl_804091F8;
extern s32 lbl_804091FC;
extern s32 lbl_804093B0;
extern const s32 str_Confirm[];

void Menu_Main_HandleSelection(void *arg0) {
    if ((*(f32 *)((s8 *)(arg0) + (0))) >= lbl_804090EC) {
        fn_8010CA18(0, &lbl_80408F7C, &lbl_80408F80);
        if (((s32) lbl_804086E8 == 0) && ((s32) lbl_804086EC == 0)) {
            fn_8006D1BC((*(s16 *)((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (0x3C))), 1);
        }
        (*(f32 *)((s8 *)(arg0) + (0))) = (f32) lbl_801A0414[0];
        fn_800B9928(NuRndrHackWaterLevel, lbl_801A0414[0]);
    }
    if (!(NuRndrHackWaterLevel[0] < lbl_801A0418[0])) {
        if ((s32) lbl_80408FE0 != 0) {
            if ((s32) (*(s32 *)((s8 *)(arg0) + (0x80))) != 0) {
                lbl_804091F8 = lbl_804091FC = lbl_804093B0 = 0;
                fn_8006DCD4(str_Confirm, 0);
            }
        } else if ((s32) (*(s32 *)((s8 *)(arg0) + (0x80))) != 0) {
            lbl_804093B0 = 0x7B;
            fn_8006DCD4(str_Confirm, 0);
        }
    }
}

extern s32 lbl_801A2614[];
extern s32 lbl_801D6524[];
extern s32 lbl_801D6530[];

void fn_800C12D0(void) {
    struct nuvec_s sp8;
    s16 temp_r0;
    s32 i;
    s8 *temp_r9;
    struct nugspline_s *temp_r31;
    struct nuvec_s *var_r30;

    var_r30 = NULL;
    temp_r31 = lbl_80409410->unk1974;
    if (temp_r31 != NULL) {
        if (fn_800AAC04(&sp8, NULL) != 0) {
            var_r30 = &sp8;
        }
        if (var_r30 != NULL) {
            temp_r9 = temp_r31->pts;
            temp_r0 = temp_r31->ptsize;
            if (fn_800CFD4C((*(f32 *)&(sp8)), sp8.z, (*(f32 *)((s8 *)(temp_r9) + (0))), (*(f32 *)((s8 *)(temp_r9) + (8))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (0))), (*(f32 *)((s8 *)(&temp_r9[temp_r0]) + (8)))) != 0) {
                lbl_804093B8 = 0x44;
            } else {
                lbl_804093B8 = 0x46;
            }
        }
    }
    if ((s8) (u8) lbl_8040A68C != -1) {
        fn_8006DCD4(lbl_801A2614, (s32) lbl_801D6524);
        lbl_8040A68C = 0;
        for (i = 0; i < 8; i++) {
            if ((fn_800130F4(&lbl_803EB12C[i * 3]) != 0) && (fn_800131B8(&lbl_803EB12C[i * 3]) == 0)) {
                lbl_8040A68C++;
            }
        }
        if ((s32) (u8) lbl_8040A68C == 6) {
            lbl_8040A68C = -1;
        }
    } else {
        fn_8006DCD4(lbl_801A2614, (s32) lbl_801D6530);
    }
}

s32 FindForceObject(void *, s32 *, s32);
extern s32 lbl_801A23CC[];
extern s32 lbl_801A23E0[];
extern s32 lbl_801A23F4[];
extern s32 lbl_801A2408[];
extern s32 lbl_801A241C[];
extern s32 lbl_801A2430[];
extern s32 lbl_801A2444[];
extern s32 lbl_801A244C[];
extern s32 lbl_801A2460[];
extern s32 lbl_803EAE44[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_8040B15C;
extern s32 lbl_8040B160;

void KaminoDInit(void) {
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A23CC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A23E0, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A23F4, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0xC))) = FindForceObject(lbl_80409410, lbl_801A2408, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x10))) = FindForceObject(lbl_80409410, lbl_801A241C, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x14))) = FindForceObject(lbl_80409410, lbl_801A2430, 0);
    lbl_8040B15C = 0;
    lbl_8040B160 = AISysFindArea(((s32 *)lbl_80409410)[0xBA], lbl_801A2444);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x18))) = FindForceObject(lbl_80409410, lbl_801A244C, 0);
    lbl_803EAE44[0] = FindObstacle(lbl_80409410, lbl_801A2460);
}

f32 NuSinApprox(s32);
void fn_800769B4(void *, s32, s32);
extern f32 NuRndrHackWaterLevel[];
extern f32 lbl_801A0178[];
extern f32 lbl_801A017C[];
extern f32 lbl_801A0180[];
extern f32 lbl_801A0184[];
extern s32 lbl_803DED88[];
extern s32 lbl_80408A30;
extern s32 lbl_80408A54;
extern f32 lbl_804090E8;
extern f32 lbl_8040B0BC;
extern f32 str_MenuSelect[];

void Menu_Unknown1_BuildOptions(void *arg0)
{
  f32 var_f1;
  s32 temp_r30;
  s8 *tbl;
  temp_r30 = (s32) (((f32) ((f64) lbl_80408A54)) * lbl_8040B0BC);
  if (((s32) lbl_80408A30) == 0)
  {
    if (NuRndrHackWaterLevel[0] < lbl_801A0178[0])
    {
      var_f1 = lbl_801A017C[0];
    }
    else
      if (NuRndrHackWaterLevel[0] < lbl_801A0180[0])
    {
      var_f1 = NuSinApprox((s32) (2.0f * ((NuRndrHackWaterLevel[0] - lbl_801A0178[0]) * lbl_801A0184[0])));
    }
    else
    {
      var_f1 = str_MenuSelect[0];
    }
    tbl = (s8 *) lbl_803DED88;
    *((f32 *) (((s8 *) arg0) + 0x9C)) = (f32) (lbl_804090E8 - (*((f32 *) (((s8 *) arg0) + 0xA8))));
    temp_r30 = (s32) (((f32) ((f64) temp_r30)) * var_f1);
    fn_800769B4(arg0, *((s32 *) (tbl + 0xAF4)), (u8) temp_r30);
    fn_800769B4(arg0, *((s32 *) (tbl + 0xBD4)), (u8) temp_r30);
    fn_800769B4(arg0, *((s32 *) (tbl + 0xB20)), (u8) temp_r30);
  }
}

s32 NuSpecialFind(s32, s32 *, s32 *, s32);
s32 fn_800130F4(s32 *);
void fn_80013200(s32 *, s32);
s32 fn_80108A34(s32, s32);
s32 FindForceObject(void *, s32 *, s32);
extern s32 lbl_801A29D4[];
extern s32 lbl_801A29DC[];
extern s32 lbl_801A29E4[];
extern s32 lbl_801A29EC[];
extern s32 lbl_801A29F8[];
extern s32 lbl_801A2A04[];
extern s32 lbl_801A2A10[];
extern s32 lbl_801A2A1C[];
extern s32 lbl_801A2A28[];
extern s32 lbl_801A2A34[];
extern s32 lbl_801A2A40[];
extern s32 lbl_801A2A4C[];
extern s32 lbl_801A2A58[];
extern s32 lbl_801A2A64[];
extern s32 lbl_801A2A70[];
extern s32 lbl_801A2A78[];
extern s32 lbl_801A2A80[];
extern s32 lbl_801A2A88[];
extern s32 lbl_801A2A90[];
extern s32 lbl_801A2A98[];
extern s32 lbl_801A2AA0[];
extern s32 lbl_801A2AA8[];
extern s32 lbl_801D6774[];
extern s32 lbl_803EAD24[];
extern s32 lbl_803EAE14[];
extern s32 lbl_803EAE20[];
extern s32 lbl_803EAE44[];
extern s32 lbl_803EAEC4[];

typedef struct {
    s32 *name;
    char pad[0xE];
    s16 flag;
} LevelSpecialEntry;

void GunshipBInit(void) {
    s32 i;
    LevelSpecialEntry *tbl;

    lbl_803EAE44[0] = FindObstacle(lbl_80409410, lbl_801A29D4);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAE14, lbl_801A29DC, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAE20, lbl_801A29E4, 1);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0))) = FindForceObject(lbl_80409410, lbl_801A29EC, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (4))) = FindForceObject(lbl_80409410, lbl_801A29F8, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (8))) = FindForceObject(lbl_80409410, lbl_801A2A04, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0xC))) = FindForceObject(lbl_80409410, lbl_801A2A10, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x10))) = FindForceObject(lbl_80409410, lbl_801A2A1C, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x14))) = FindForceObject(lbl_80409410, lbl_801A2A04, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x18))) = FindForceObject(lbl_80409410, lbl_801A2A28, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x1C))) = FindForceObject(lbl_80409410, lbl_801A2A34, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x20))) = FindForceObject(lbl_80409410, lbl_801A2A40, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x24))) = FindForceObject(lbl_80409410, lbl_801A2A4C, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x28))) = FindForceObject(lbl_80409410, lbl_801A2A58, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x2C))) = FindForceObject(lbl_80409410, lbl_801A2A64, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x50))) = FindForceObject(lbl_80409410, lbl_801A2A70, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x54))) = FindForceObject(lbl_80409410, lbl_801A2A78, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x58))) = FindForceObject(lbl_80409410, lbl_801A2A80, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x5C))) = FindForceObject(lbl_80409410, lbl_801A2A88, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x60))) = FindForceObject(lbl_80409410, lbl_801A2A90, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x64))) = FindForceObject(lbl_80409410, lbl_801A2A98, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x68))) = FindForceObject(lbl_80409410, lbl_801A2AA0, 0);
    (*(s32 *)((s8 *)(lbl_803EAEC4) + (0x6C))) = FindForceObject(lbl_80409410, lbl_801A2AA8, 0);
    tbl = (LevelSpecialEntry *)lbl_801D6774;
    if (tbl[0].name != 0) {
        i = 0;
        do {
            NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), &lbl_803EAD24[i * 3], tbl[i].name, 1);
            if (fn_800130F4(&lbl_803EAD24[i * 3]) != 0) {
                fn_80013200(&lbl_803EAD24[i * 3], 0);
                tbl[i].flag = 0;
            }
            i++;
        } while (tbl[i].name != 0);
    }
    fn_80108A34(lbl_803EAE44[0], 0);
}

void fn_8014E9B8(void);
extern s32 gPlayer1Pointer[];
extern s32 gPlayerTotalStuds;
extern s32 gTrueJediTotal;
extern f32 lbl_801A5354[];
extern f32 lbl_801A5358[];
extern f32 lbl_801A535C[];
extern f32 lbl_801A5360[];
extern f32 lbl_801A5364[];
extern u8 lbl_803E028C[];
extern f32 lbl_80408E9C;
extern f32 lbl_80408F00;
extern s32 lbl_80409118;
extern s32 lbl_8040912C;
extern s32 lbl_804091F8;
extern f32 lbl_8040A6BC;
extern f32 lbl_8040A6C0;
extern f32 lbl_8040A6C4;
extern s32 lbl_8040AFAC;
extern f32 lbl_8040B0D0;
extern f32 lbl_8040B1BC;
extern f32 lbl_8040B1C0;
extern f32 lbl_8040B1C4;
extern f32 lbl_8040B1D8;
extern f32 lbl_8040B1DC;
extern f32 lbl_8040B1E0;

static inline void fn_800D64B0_approach(f32 *v, f32 t) {
    if (*v > t) {
        *v -= lbl_80408E9C;
        if (*v < t) {
            *v = t;
        }
    } else if (*v < t) {
        *v += lbl_80408E9C;
        if (*v > t) {
            *v = t;
        }
    }
}

#define FN_800D64B0_APPROACHK(v, k)                     \
    if ((v) > lbl_801A5358[0]) {                        \
        (v) -= lbl_80408E9C * (k);                      \
        if ((v) < lbl_801A5358[0]) {                    \
            (v) = lbl_801A5358[0];                      \
        }                                               \
    } else if ((v) < lbl_801A5358[0]) {                 \
        (v) += lbl_80408E9C * (k);                      \
        if ((v) > lbl_801A5358[0]) {                    \
            (v) = lbl_801A5358[0];                      \
        }                                               \
    }

void fn_800D64B0(void) {
    f32 t0;
    f32 t1;
    f32 t2;
    f32 t3;
    s32 n;
    void *p;

    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (4))) & 0x4002) {
        if ((lbl_80408F00 == lbl_801A5354[0]) && (lbl_8040AFAC == 0) && (lbl_80409118 == 0) && (((*(s32 *)((s8 *)(lbl_80409410) + (0x19C))) != 0x15) || (lbl_803E028C[0] != 5))) {
            t0 = lbl_801A5358[0];
        } else {
            t0 = lbl_801A535C[0];
        }
        fn_800D64B0_approach(&lbl_8040A6BC, t0);
        if (lbl_8040B1E0 > lbl_801A535C[0]) {
            lbl_8040B1E0 -= lbl_80408E9C;
        }
        if ((lbl_80408F00 == lbl_801A5354[0]) && (lbl_8040AFAC == 0) && ((lbl_8040912C != 0) || (lbl_8040B1E0 > lbl_801A535C[0]))) {
            t1 = lbl_801A5358[0];
        } else {
            t1 = lbl_801A535C[0];
        }
        fn_800D64B0_approach(&lbl_8040A6C0, t1);
        FN_800D64B0_APPROACHK(lbl_8040B1DC, lbl_801A5360[0])
        if (lbl_8040B1C4 > lbl_801A535C[0]) {
            lbl_8040B1C4 -= lbl_80408E9C;
        }
        if ((lbl_80408F00 == lbl_801A5354[0]) && (lbl_8040AFAC == 0) && ((lbl_8040912C != 0) || (lbl_8040B1C4 > lbl_801A535C[0]) || (gTrueJediTotal != 0))) {
            t2 = lbl_801A5358[0];
        } else {
            t2 = lbl_801A535C[0];
        }
        fn_800D64B0_approach(&lbl_8040B1BC, t2);
        p = (*(void **)((s8 *)(lbl_80409410) + (0x1AC)));
        if ((p != NULL) && ((*(u8 *)((s8 *)((*(void **)((s8 *)(p) + (0x40)))) + (2))) == 0)) {
            if (lbl_804091F8 != 0) {
                n = (*(s32 *)((s8 *)(p) + (0x1C)));
            } else {
                n = (*(s32 *)((s8 *)(p) + (0x18)));
            }
            if (n > 0) {
                if (gTrueJediTotal == 0) {
                    gPlayerTotalStuds = 0;
                    if ((*(void **)((s8 *)(gPlayer1Pointer) + (0))) != NULL) {
                        gPlayerTotalStuds = (*(s32 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(gPlayer1Pointer) + (0)))) + (0xEEC)))) + (0x140)));
                    }
                    if ((*(void **)((s8 *)(gPlayer1Pointer) + (4))) != NULL) {
                        gPlayerTotalStuds += (*(s32 *)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)(gPlayer1Pointer) + (4)))) + (0xEEC)))) + (0x140)));
                    }
                    if (gPlayerTotalStuds >= n) {
                        gTrueJediTotal = 1;
                    }
                }
                FN_800D64B0_APPROACHK(lbl_8040B1C0, lbl_801A5364[0])
            }
        }
        if (lbl_8040B0D0 > lbl_801A535C[0]) {
            lbl_8040B0D0 -= lbl_80408E9C;
        }
        if ((lbl_80408F00 == lbl_801A5354[0]) && (lbl_8040AFAC == 0) && ((lbl_8040912C != 0) || (lbl_8040B0D0 > lbl_801A535C[0]))) {
            t3 = lbl_801A5358[0];
        } else {
            t3 = lbl_801A535C[0];
        }
        fn_800D64B0_approach(&lbl_8040A6C4, t3);
        FN_800D64B0_APPROACHK(lbl_8040B1D8, lbl_801A5364[0])
        if ((*(s32 *)((s8 *)(lbl_80409410) + (0x19C))) == 3) {
            if (((*(s32 *)((s8 *)((*(void **)((s8 *)(lbl_80409410) + (0x1A8)))) + (4))) & 0x5000) == 0) {
                fn_8014E9B8();
            }
        }
    }
}

void fn_800BB3FC(s32, s32, f32);
s32 fn_8011E9C4(s32);
extern f32 lbl_801A2BA4[];
extern f32 lbl_80408E9C;
extern s32 lbl_804091F8;
extern u8 lbl_8040B060[];
extern f32 lbl_8040B0C8;

void fn_800C4EA0(void) {
    f32 temp_f0;
    f32 temp_f31;
    s32 var_r0;
    void *var_r3;

    if ((void *) lbl_80409348 == NULL) {
        lbl_80409348 = fn_800D515C(0x4A, 1, 1);
    }
    if ((s32) lbl_804091F8 != 0) {
        fn_800BB3FC(0x4A, 0, lbl_801A2BA4[0]);
        return;
    }
    temp_f31 = lbl_801A2BA4[0];
    switch ((s32) lbl_8040B060[0]) {
    case 0:
        var_r3 = fn_800D515C(0x4A, 1, 1);
        if ((var_r3 == NULL) || !((*(s32 *)((s8 *)(var_r3) + (0xF24))) & 2) || (((s32) (*(u8 *)((s8 *)(var_r3) + (0x28F))) == 0) && ((s32) (*(u8 *)((s8 *)(var_r3) + (0x1085))) != 0))) {
            var_r3 = NULL;
        }
        if (var_r3 == NULL) {
            goto block_17;
        }
        if (!(temp_f31 <= lbl_801A2BA4[0])) {
            lbl_8040B060[0] = 1;
            goto block_17;
        }
        goto block_16;
    case 1:
        temp_f0 = lbl_8040B0C8 + lbl_80408E9C;
        lbl_8040B0C8 = temp_f0;
        if (temp_f0 >= temp_f31) {
block_16:
            lbl_8040B060[0] = 2;
            var_r0 = 1;
            break;
        }
    default:
block_17:
        var_r0 = 0;
        break;
    }
    if (var_r0 != 0) {
        fn_8011E9C4(0x4D);
    }
}

extern s32 lbl_801A1F60[];
extern s32 lbl_801A1F74[];
extern s32 lbl_801A1F88[];
extern s32 lbl_801A1F98[];
extern s32 lbl_801A1FA8[];
extern s32 lbl_801A1FB4[];
extern s32 lbl_801A1FC0[];
extern s32 lbl_801A1FD0[];
extern s32 lbl_801A1FE0[];
extern s32 lbl_803EAED0[];
extern s32 lbl_803EB0D8[];
extern s32 lbl_803EB0E4[];
extern s32 lbl_803EB0F0[];
extern s32 lbl_803EB0FC[];
extern s32 lbl_803EB108[];
extern s32 lbl_803EB114[];
extern s32 lbl_80409238;
extern s32 lbl_8040923C;
extern s8 lbl_8040A674;
extern s8 lbl_8040A675;
extern s8 lbl_8040A676;
extern s8 lbl_8040A677;
extern s8 lbl_8040A678;
extern s8 lbl_8040A679;
extern s8 lbl_8040A67A;
extern s8 lbl_8040A67B;
extern s8 lbl_8040A67C;
extern s8 lbl_8040A67D;

void fn_800BD8E8(void) {
    lbl_8040A674 = 0;
    lbl_8040A675 = 0;
    lbl_8040A676 = 0;
    lbl_8040A677 = 0;
    lbl_8040A678 = 0;
    lbl_8040A679 = 0;
    lbl_8040A67A = 0;
    lbl_8040A67B = 0;
    lbl_8040A67C = 0;
    lbl_8040A67D = 0;
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0D8, lbl_801A1F60, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0E4, lbl_801A1F74, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0F0, lbl_801A1F88, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB0FC, lbl_801A1F98, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB108, lbl_801A1FA8, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB114, lbl_801A1FB4, 1);
    lbl_803EAED0[0] = FindForceObject(lbl_80409410, lbl_801A1FC0, 0);
    lbl_80409238 = CheckAIMessage(lbl_80408F58, lbl_801A1FD0, 0);
    lbl_8040923C = CheckAIMessage(lbl_80408F58, lbl_801A1FE0, 0);
}

#define NuSpecialExistsFn ((s32 (*)(struct nuhspecial_s *))fn_800130F4)
#define NuSpecialGetInstAnim ((struct nuinstanim_s *(*)(struct nuhspecial_s *))fn_8001384C)
#define NuSpecialGetMtx ((s8 *(*)(struct nuhspecial_s *))fn_800133FC)
#define PlaySfxAt ((s32 (*)(s32 *, void *))fn_8006DCD4)
#define SPECIAL(x) ((struct nuhspecial_s *)(x))
s32 fn_8010B780(s32, s32, s32);
s32 fn_800958F8(s32, s32, s32);
extern f32 lbl_801A206C[];
extern f32 lbl_801A2070[];
extern f32 lbl_801A2074[];
extern f32 lbl_801A2078[];
extern f32 lbl_801A207C[];
extern s32 lbl_801A1FE8[];
extern s32 lbl_801A1FF4[];
extern s32 lbl_801A2000[];
extern s32 lbl_801A2014[];
extern s32 lbl_801A2024[];
extern s32 lbl_801A2034[];
extern s32 lbl_801A2048[];
extern s32 lbl_801A205C[];
extern s32 lbl_803EAEC4[];

/* Maul_A update (level table +0x20): a cutscene timer (lbl_8040B060 state 0 -> 1 -> 2)
 * that, once lbl_8040B0C8 reaches its end, enables the two force objects, then one-shot
 * sounds keyed to the six specials found by fn_800BD8E8 and the lbl_803EAED0 object. */
void fn_800BDA3C(void) {
    struct nuinstanim_s *ia;
    struct nuinstanim_s *t;
    f32 start;
    f32 end;
    s32 i;
    s32 *fo;
    s32 a;
    s32 b;

    start = lbl_801A206C[0];
    switch (lbl_8040B060[0]) {
    case 0:
        if ((void *)lbl_80409238 != NULL && *(f32 *)(lbl_80409238 + 0x28) != start) {
            lbl_8040B0C8 = start;
            lbl_8040B060[0] = 1;
        }
        break;
    case 1:
        fo = lbl_803EAEC4; /* unused, but keeps the retail lis/addi/mr placement */
        lbl_8040B0C8 += lbl_80408E9C;
        if (lbl_8040B0C8 >= lbl_801A2070[0]) {
            lbl_8040B060[0] = 2;
            fn_80105500(lbl_80409410, 1, 10, 1);
            fn_80105500(lbl_80409410, 5, 10, 1);
            lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A1FE8, 0);
            lbl_803EAEC4[1] = FindForceObject(lbl_80409410, lbl_801A1FF4, 0);
            for (i = 0; i < 2; i++) {
                if (lbl_803EAEC4[i] != 0) {
                    fn_8010B780(lbl_80409410->unk1BC, 1, lbl_803EAEC4[i] + 0x78);
                    fn_800958F8(lbl_80409410->unk1B8, 0x2E, lbl_803EAEC4[i] + 0x78);
                }
            }
        }
        break;
    }

    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0D8)) != 0) {
        ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0D8));
        if (ia != NULL && ia->flags < 0 && ia->ltime >= lbl_801A2074[0] && lbl_8040A674 == 0) {
            lbl_8040A674 = 1;
            PlaySfxAt(lbl_801A2000, NuSpecialGetMtx(SPECIAL(lbl_803EB0D8)) + 0x30);
        }
    }
    if (NuSpecialExistsFn(SPECIAL(lbl_803EB0E4)) != 0) {
        ia = NuSpecialGetInstAnim(SPECIAL(lbl_803EB0E4));
        if (ia != NULL && ia->flags < 0 && ia->ltime >= lbl_801A2074[0] && lbl_8040A675 == 0) {
            lbl_8040A675 = 1;
            PlaySfxAt(lbl_801A2000, NuSpecialGetMtx(SPECIAL(lbl_803EB0E4)) + 0x30);
        }
    }

    {
        s32 *sp = lbl_803EB0F0;
        end = lbl_801A2078[0];
        if (NuSpecialExistsFn(SPECIAL(sp)) != 0 && (t = NuSpecialGetInstAnim(SPECIAL(sp))) != NULL
            && t->flags < 0) {
            b = 1;
            if (t->ltime >= end) {
                b = 2;
            }
        } else {
            b = 0;
        }
    }
    if (b > 0 && lbl_8040A676 == 0) {
        lbl_8040A676 = 1;
        PlaySfxAt(lbl_801A2014, NuSpecialGetMtx(SPECIAL(lbl_803EB0F0)) + 0x30);
    }
    if (b == 2 && lbl_8040A677 == 0) {
        lbl_8040A677 = 1;
    }
    if (lbl_8040A677 != 0) {
        PlaySfxAt(lbl_801A2024, NuSpecialGetMtx(SPECIAL(lbl_803EB0F0)) + 0x30);
    }

    {
        s32 *sp = lbl_803EB108;
        if (NuSpecialExistsFn(SPECIAL(sp)) != 0 && (t = NuSpecialGetInstAnim(SPECIAL(sp))) != NULL
            && t->flags < 0) {
            a = 1;
        } else {
            a = 0;
        }
    }
    {
        s32 *sp = lbl_803EB114;
        if (NuSpecialExistsFn(SPECIAL(sp)) != 0 && (t = NuSpecialGetInstAnim(SPECIAL(sp))) != NULL
            && t->flags < 0) {
            b = 1;
        } else {
            b = 0;
        }
    }
    if (lbl_8040A678 == 0 && a == 1) {
        lbl_8040A678 = a;
        PlaySfxAt(lbl_801A2034, NuSpecialGetMtx(SPECIAL(lbl_803EB108)) + 0x30);
    }
    if (lbl_8040A679 == 0 && b == 1) {
        lbl_8040A679 = b;
        PlaySfxAt(lbl_801A2048, NuSpecialGetMtx(SPECIAL(lbl_803EB114)) + 0x30);
    }
    if (lbl_8040A678 == 1 && a == 0 && lbl_8040A679 == 1 && b == 0 && lbl_8040A67C == 0) {
        lbl_8040A677 = 0;
        lbl_8040A67C = 1;
        PlaySfxAt(lbl_801A205C, NuSpecialGetMtx(SPECIAL(lbl_803EB0FC)) + 0x30);
    }

    if (lbl_803EAED0[0] != 0 && lbl_8040A67B == 0) {
        t = NuSpecialGetInstAnim(SPECIAL(lbl_803EAED0[0] + 4));
        if (t != NULL && t->flags >= 0 && t->ltime > lbl_801A207C[0]) {
            lbl_8040A67B = 1;
        }
    }
    if (lbl_8040A67B == 1 && lbl_803EAED0[0] != 0 && ia->flags >= 0) {
        lbl_8040A67D = 1;
    }
    if (lbl_8040A67D == 1 && lbl_803EAED0[0] != 0) {
        PlaySfxAt(lbl_801A2024, NuSpecialGetMtx(SPECIAL(lbl_803EAED0[0] + 4)) + 0x30);
    }
}

#undef SPECIAL
#undef PlaySfxAt
#undef NuSpecialGetMtx
#undef NuSpecialGetInstAnim
#undef NuSpecialExistsFn

s32 fn_8000E250(s32, s32);
s32 fn_8000E3C0(s32, s32);
s32 fn_8000E540(s32, s32);

void fn_800D0374(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    switch (arg1) {
    case 0:
        if (arg2 != 0) fn_8000E250(arg0, arg2);
        if (arg3 != 0) fn_8000E3C0(arg0, arg3);
        if (arg4 != 0) fn_8000E540(arg0, arg4);
        break;
    case 1:
        if (arg3 != 0) fn_8000E3C0(arg0, arg3);
        if (arg2 != 0) fn_8000E250(arg0, arg2);
        if (arg4 != 0) fn_8000E540(arg0, arg4);
        break;
    case 2:
        if (arg3 != 0) fn_8000E3C0(arg0, arg3);
        if (arg4 != 0) fn_8000E540(arg0, arg4);
        if (arg2 != 0) fn_8000E250(arg0, arg2);
        break;
    case 3:
        if (arg4 != 0) fn_8000E540(arg0, arg4);
        if (arg2 != 0) fn_8000E250(arg0, arg2);
        if (arg3 != 0) fn_8000E3C0(arg0, arg3);
        break;
    }
}

void NewRumble(s32, f32);
s32 fn_800AC020(s32, f32);
s32 fn_801261FC(void *, s32);
extern s32 gPlayer1Pointer[];
extern f32 lbl_801A19A0[];
extern f32 lbl_801A19A4[];
extern void *lbl_80409430;
extern s32 lbl_8040B058;

void PartKill(void *arg0, s32 arg1) {
    s32 i;
    s8 *o;
    u8 f;
    s32 *pl;

    o = lbl_80409430;
    for (i = 0; i < lbl_8040B058; i++, o += 0x1098) {
        if (*(s32 *)(o + 0x20C) < 0 && *(void **)(*(s8 **)(o + 0xEEC) + 0x64C) == arg0) {
            fn_801261FC(o, 0);
        }
    }
    if (arg1 == 1) {
        f = *(u8 *)((s8 *)arg0 + 0x1EA);
        if ((s8)f != -1) {
            if ((f & 1) && (void *)gPlayer1Pointer[0] != NULL) {
                fn_800AC020(**(s32 **)(*(s8 **)(gPlayer1Pointer[0] + 0xEEC) + 0x61C), lbl_801A19A0[0]);
                NewRumble(**(s32 **)(*(s8 **)(gPlayer1Pointer[0] + 0xEEC) + 0x61C), lbl_801A19A4[0]);
            }
            if ((*(u8 *)((s8 *)arg0 + 0x1EA) & 2) && (pl = gPlayer1Pointer, (void *)pl[1] != NULL)) {
                fn_800AC020(**(s32 **)(*(s8 **)(pl[1] + 0xEEC) + 0x61C), lbl_801A19A0[0]);
                NewRumble(**(s32 **)(*(s8 **)(pl[1] + 0xEEC) + 0x61C), lbl_801A19A4[0]);
            }
        }
    }
}

f32 NuCosApprox(s32);
f32 fn_8000CD08(void *, s32, struct nuvec_s *);
extern s32 PartKill_ForceThrow[];
void fn_800C5640(void *);
extern const f32 lbl_801A19D4[];
extern const f32 lbl_801A19D8[];
extern s32 lbl_80408888;
extern void *lbl_8040AEFC;

void *fn_800B9BE0(s32 arg0, struct nuvec_s *arg1, f32 farg0) {
    struct nuvec_s sp8;
    s32 ang;
    f32 d;
    f32 dot;
    f32 best;
    s32 i;
    void *found;
    s8 *o;

    found = NULL;
    o = lbl_8040AEFC;
    best = farg0;
    for (i = 0; i < lbl_80408888; i++, o += 0x1F4) {
        if (*(s32 *)(o + 0x128) < 0 && (*(s32 *)(o + 0x198) == (s32)fn_800C5640 || *(s32 *)(o + 0x1A8) == (s32)PartKill_ForceThrow)) {
            d = fn_8000CD08(o + 0x30, arg0, &sp8);
            if (d < farg0) {
                NuVecNorm(&sp8, &sp8);
                dot = NuVecDot(&sp8, arg1);
                if (d < lbl_801A19D4[0]) {
                    ang = 0x38E3;
                } else if (d < lbl_801A19D8[0]) {
                    ang = 0x238E;
                } else {
                    ang = 0xE38;
                }
                if (dot > NuCosApprox(ang) && d < best) {
                    best = d;
                    found = o;
                }
            }
        }
    }
    return found;
}

s32 OpenDoorObstacle(s32, s32, s32, s32, f32);
s32 fn_8013F0AC(s32);
extern f32 lbl_801A20A8[];
extern u8 lbl_803EAF8E[];

void fn_800BE054(void) {
    s32 i;
    s32 all;

    all = 1;
    if (lbl_803EAF8E[0] == 0) {
        for (i = 0; i < 10; i++) {
            if (lbl_803EAE44[i] != 0 && !(*(s32 *)(lbl_803EAE44[i] + 0x18) & 0x1000)) {
                all = 0;
            }
        }
        if (all) {
            for (i = 0; i < 10; i++) {
                if (lbl_803EAE44[i] != 0) {
                    OpenDoorObstacle(0, lbl_803EAE44[i], 1, 1, lbl_801A20A8[0]);
                }
            }
            lbl_803EAF8E[0] = 1;
            fn_8013F0AC(0xA);
        }
    }
}

s32 NuSplineFind(s32, s32);
s32 NuStrCat(s32 *, s32 *);
s32 NuStrCpy(s32 *, s32);
s32 Shop_Init();
s32 InitMapAI();
s32 fn_800E1564();
s32 fn_800E1F88();
extern s32 lbl_801A3000[];
extern s32 lbl_801A3008[];
extern s32 lbl_801A300C[];
extern s32 lbl_801A3010[];
extern s32 lbl_801A3014[];
extern s32 lbl_801A3018[];
extern s32 lbl_801A3024[];
extern s32 lbl_801A3030[];
extern s32 lbl_801A303C[];
extern s32 lbl_801A3048[];
extern s32 lbl_801A3058[];
extern s32 lbl_801A3068[];
extern f32 lbl_801A3078[];
extern s32 lbl_801DC074[];
extern s32 lbl_802DA210[];

void MapEInit(void) {
    s32 buf[16];
    s32 i;
    s8 *o;

    o = (s8 *)lbl_801DC074;
    for (i = 0x16; i != 0; i--, o += 0x68) {
        if (*(s32 **)(o + 0x20) != NULL) {
            *(s32 *)(o + 0x44) = FindObstacle((s32) lbl_80409410, *(s32 **)(o + 0x20));
            *(s32 *)(o + 0x48) = FindObstacle((s32) lbl_80409410, *(s32 **)(o + 0x24));
        }
        if (*(s32 *)(o + 0x34) != 0) {
            memset((s32 *)(o + 0x4C), 0, 0xC);
            NuStrCpy(buf, *(s32 *)(o + 0x34));
            NuStrCat(buf, lbl_801A3000);
            NuSpecialFind(lbl_80409410->unk1C0, (s32 *)(o + 0x4C), buf, 1);
            memset((s32 *)(o + 0x58), 0, 0xC);
            NuStrCpy(buf, *(s32 *)(o + 0x34));
            NuStrCat(buf, lbl_801A3008);
            NuSpecialFind(lbl_80409410->unk1C0, (s32 *)(o + 0x58), buf, 1);
        }
        *(s32 *)(o + 0x64) = NuSplineFind(lbl_80409410->unk1C0, *(s32 *)(o + 0x28));
    }
    (*(s32 *)((s8 *)(lbl_803EAE44) + (0))) = FindObstacle((s32) lbl_80409410, lbl_801A300C);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (4))) = FindObstacle((s32) lbl_80409410, lbl_801A3010);
    (*(s32 *)((s8 *)(lbl_803EAE44) + (8))) = FindObstacle((s32) lbl_80409410, lbl_801A3014);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD24, lbl_801A3018, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD30, lbl_801A3024, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD3C, lbl_801A3030, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD48, lbl_801A303C, 1);
    fn_800CC6C4();
    Shop_Init();
    fn_800E1F88();
    fn_800E1564();
    lbl_8040B0C8 = lbl_801A3078[0];
    InitMapAI();
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA1F8, lbl_801A3048, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA204, lbl_801A3058, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_802DA210, lbl_801A3068, 1);
}

s32 NuSpecialFind(s32, s32 *, s32 *, s32);
s32 fn_8002A4B0(s32 *, s32 *, s32 *);
extern s32 lbl_801A161C[];
extern s32 lbl_801A1630[];
extern s32 lbl_801A1638[];
extern s32 lbl_801A1640[];
extern s32 lbl_801A1648[];
extern s32 lbl_803E8660[];
extern s32 lbl_80408F64;
extern s32 lbl_80408F6C;
extern s32 lbl_80408F70;

void InitStarField(void) {
    s32 sp8;
    s32 *p;

    sp8 = lbl_80408F70;
    lbl_80408F64 = fn_8002A4B0(&lbl_80408F6C, &sp8, lbl_801A161C);
    p = lbl_803E8660;
    memset(p, 0, 0x30);
    NuSpecialFind(lbl_80408F64, p, lbl_801A1630, 1);
    NuSpecialFind(lbl_80408F64, p + 3, lbl_801A1638, 1);
    NuSpecialFind(lbl_80408F64, p + 6, lbl_801A1640, 1);
    NuSpecialFind(lbl_80408F64, p + 9, lbl_801A1648, 1);
}

s32 fn_800D95B8(void *);
extern f32 lbl_801A4F00[];
extern s32 lbl_80409348;

void fn_800CE8FC(void) {
    if (((s32) lbl_80409348 != 0) && ((void *) lbl_80409344 != NULL) && ((*(f32 *)((s8 *)(lbl_80409344) + (0x28))) == lbl_801A4F00[0])) {
        fn_800D95B8((void *) lbl_80409348);
    }
}

void fn_800D6968(s32, f32, f32, f32, s32, f32, f32, f32, s32);
s32 fn_800D7B64(void *, s32, f32, f32, f32);
extern f32 lbl_801A54FC[];
extern f32 lbl_801A5500[];
extern f32 lbl_801A5504[];
extern f32 lbl_80408F00;
extern f32 lbl_80409534;
extern f32 lbl_80409538;
extern f32 lbl_8040953C;
extern f32 lbl_80409540;

s32 fn_800D95B8(void *arg0) {
    if (lbl_80408F00 == lbl_801A54FC[0]) {
        fn_800D6968(*(s16 *)((s8 *)arg0 + 0x1074), lbl_801A5500[0], lbl_8040953C, lbl_801A5500[0], 0xCA, lbl_80409540, lbl_801A5504[0], lbl_801A5504[0], 1);
        fn_800D7B64(arg0, 0, lbl_801A5500[0], lbl_80409534, lbl_80409538);
    }
}

extern s32 lbl_801A2184[];
extern s32 lbl_801A218C[];

void fn_800CD794(void) {
    struct nuvec_s sp8;

    NuSpecialFind(lbl_80409410->unk1C0, &sp8, lbl_801A2184, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB120, lbl_801A218C, 1);
    lbl_8040B158 = fn_800133FC(&sp8) + 0x30;
    lbl_8040A67E = 0;
}

s32 Menu_CloseCurrent();
s32 PauseMenu_HandleEntry1(s32 *);
s32 fn_800B9D2C(s32);
s32 fn_800C8E38(s32);
extern s32 lbl_80409158;
extern s32 lbl_8040915C;
extern s32 lbl_8040AFF4;
extern const s32 str_Cancel[];
extern const s32 str_Confirm[];

void Menu_Unknown3_HandleSelection(void *arg0) {
    if (*(s32 *)((s8 *)arg0 + 0x68) != 0) {
        if (*(s32 *)((s8 *)arg0 + 0x34) == 0) {
            SceneSelect_HandleEntry();
            fn_800C8E38(lbl_80409410);
            fn_800B9D2C(lbl_8040AFF4);
            lbl_80409158 = 1;
            lbl_8040915C |= 1;
            *(s32 *)((s8 *)arg0 + 0x50) = PauseMenu_HandleEntry1((s32 *)str_Confirm);
            return;
        }
    } else if (*(s32 *)((s8 *)arg0 + 0x6C) == 0) {
        return;
    }
    Menu_CloseCurrent();
    *(s32 *)((s8 *)arg0 + 0x50) = PauseMenu_HandleEntry1((s32 *)str_Cancel);
}

extern s32 lbl_801A1CE0[];
extern s32 lbl_801A1CEC[];
extern s32 lbl_801A1CF8[];
extern s32 lbl_803EB014[];
extern s32 lbl_803EB020[];
extern s32 lbl_803EB02C[];
extern s32 lbl_80409214;
extern s32 lbl_80409218;
extern s32 lbl_8040921C;
extern s32 lbl_80409220;

void fn_800CD04C(void) {
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB014, lbl_801A1CE0, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB020, lbl_801A1CEC, 1);
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EB02C, lbl_801A1CF8, 1);
    lbl_80409214 = 0;
    lbl_80409218 = 0;
    lbl_8040921C = 0;
    lbl_80409220 = 0;
}

extern s32 lbl_801A2B98[];
extern s32 lbl_803EACC4[];

void fn_800CE834(void) {
    u8 *p;

    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD24, lbl_801A2B98, 1);
    if (fn_800130F4(lbl_803EAD24) != 0) {
        if (lbl_804091F8 != 0 || (p = (u8 *)lbl_803EACC4, p[0x4B] != 0 && p[0x4C] != 0)) {
            fn_80013200(lbl_803EAD24, 0);
        }
    }
}

int sprintf(void *, void *, ...);
extern s32 lbl_801A2C14[];
extern s32 lbl_801A2C1C[];
extern s32 lbl_801A2C24[];
extern s32 lbl_801A2C2C[];
extern s32 lbl_801A2C38[];
extern s32 lbl_801A2C44[];
extern s32 lbl_801A2C50[];
extern s32 lbl_801A2C5C[];
extern f32 lbl_801A2C68[];
extern s32 lbl_802DA1E8[];
extern s32 lbl_803E04F0[];
extern s32 lbl_803EAD24[];
extern s32 lbl_803EAD9C[];
extern s32 lbl_803EADD8[];
extern s32 lbl_803EADE4[];
extern s32 lbl_803EADF0[];
extern s32 lbl_803EADFC[];
extern s32 lbl_803EAE44[];
extern s32 lbl_803EAEC4[];
extern s32 lbl_803ED320[];
extern s32 lbl_8040935C;
extern f32 lbl_8040A6A4;

void KashyyykDInit(void) {
    s32 *p;
    s32 i;

    lbl_803EAEC4[0] = FindForceObject(lbl_80409410, lbl_801A2C14, 0);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EAD9C, lbl_801A2C1C, 1);
    for (i = 0; i < 3; i++) {
        lbl_803ED320[i] = 0;
        sprintf(lbl_803E04F0, lbl_801A2C24, i + 1);
        p = &lbl_803EAD24[i * 3];
        NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), p, lbl_803E04F0, 1);
        if (fn_800130F4(p) != 0) {
            fn_80013200(p, 1);
            lbl_802DA1E8[i] = fn_8001384C(p);
        }
    }
    lbl_8040A6A4 = lbl_801A2C68[0];
    lbl_8040935C = 0;
    lbl_803EAE44[0] = FindObstacle(lbl_80409410, lbl_801A2C2C);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EADD8, lbl_801A2C38, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EADE4, lbl_801A2C44, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EADF0, lbl_801A2C50, 1);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), lbl_803EADFC, lbl_801A2C5C, 1);
}

s32 SetAIMessage(s32, s32 *, s32, f32);
s32 CheckAIMessage(s32, s32 *, s32);
extern s32 lbl_801A20B4[];
extern s32 lbl_801A2AE4[];
extern s32 lbl_801A2AF0[];
extern f32 lbl_801A4EE8[];
extern s32 lbl_802E0B88[];
extern s32 lbl_80408F58;

void DookuCReset(void) {
    s32 *p;

    p = (s32 *)lbl_802E0B88;
    memset(p, 0, 0x14);
    p[0] = SetAIMessage(lbl_80408F58, lbl_801A2AE4, 0, lbl_801A4EE8[0]);
    p[1] = CheckAIMessage(lbl_80408F58, lbl_801A20B4, 0);
    NuSpecialFind((*(s32 *)((s8 *)(lbl_80409410) + (0x1C0))), p + 2, lbl_801A2AF0, 1);
}

s32 CloseDoorObstacle(s32, void *);
extern s32 lbl_802DA6D8[];

typedef struct {
    char pad[0x28];
    s8 *a[4];
    s32 n;
    s8 *b[4];
} C0438Tbl;

void fn_800C0438(void) {
    s32 i;
    C0438Tbl *t;

    t = (C0438Tbl *)lbl_802DA6D8;
    t->n = 0;
    for (i = 0; i < 4; i++) {
        *(u16 *)(t->a[i] + 0x6E) &= 0xFF3F;
        *(u16 *)(t->a[i] + 0x6E) |= 1;
        *(s8 *)(t->a[i] + 0x73) = 0xA;
        CloseDoorObstacle(0, t->b[i]);
        *(s32 *)(t->b[i] + 0x18) = 0x18;
    }
}

extern f32 lbl_801A5530[];
extern f32 lbl_801A5534[];
extern f32 lbl_80409A70;
extern f32 lbl_8040A6BC;
extern f32 lbl_8040A6C4;
extern f32 lbl_8040B0D0;
extern f32 lbl_8040B1BC;
extern f32 lbl_8040B1C0;
extern f32 lbl_8040B1C4;
extern f32 lbl_8040B1D8;
extern f32 lbl_8040B1DC;
extern f32 lbl_8040B1E0;
void fn_800D97BC(void) {
    lbl_8040A6BC = lbl_801A5530[0];
    lbl_80409A70 = lbl_801A5530[0];
    lbl_8040B1E0 = lbl_801A5530[0];
    lbl_8040B1DC = lbl_801A5534[0];
    lbl_8040B1C4 = lbl_801A5530[0];
    lbl_8040B1BC = lbl_801A5530[0];
    lbl_8040B1C0 = lbl_801A5534[0];
    lbl_8040B0D0 = lbl_801A5530[0];
    lbl_8040A6C4 = lbl_801A5530[0];
    lbl_8040B1D8 = lbl_801A5534[0];
}

extern s32 lbl_801A2DE8[];
extern f32 lbl_801A4F08[];
void VaderBReset(void) {
    lbl_80409368 = SetAIMessage(lbl_80408F58, lbl_801A2DE8, 0, lbl_801A4F08[0]);
}

extern f32 lbl_801A5248[];
void fn_800D4EC8(void *arg0, f32 arg1) {
    NewRumble(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), arg1);
    fn_800AC020(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), lbl_801A5248[0]);
}

extern f32 lbl_801A524C[];
extern f32 lbl_801A5250[];
void KillRumble(void *arg0) {
    NewRumble(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), lbl_801A524C[0]);
    fn_800AC020(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), lbl_801A5250[0]);
}

extern f32 lbl_801A5240[];
extern f32 lbl_801A5244[];
void fn_800D4E70(void *arg0) {
    NewRumble(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), lbl_801A5240[0]);
    fn_800AC020(**(s32 **)(*(s8 **)((s8 *)arg0 + 0xEEC) + 0x61C), lbl_801A5244[0]);
}

void VaderAStartCollapseStage(void);
s32 fn_800D7ED8(s32, s32, s32);
extern s32 lbl_802E0BBC[];
void fn_800CEEF0(void) {
    s32 *p;
    fn_800D7ED8(0, 0, 1);
    p = lbl_802E0BBC;
    if (*(s16 *)((s8 *)p + 8) != 0) {
        VaderAStartCollapseStage();
    }
    p[9] = 1;
}

s32 fn_80127518(s32);
extern s32 lbl_803EB044[];
void fn_800CD1F0(void) {
    s32 i;
    for (i = 0; i <= 14; i++) {
        fn_80127518(lbl_803EB044[i]);
    }
}

extern u8 lbl_801D53C8[];
s32 fn_800AC340(s32 arg0) {
    s32 i;
    u8 *p;
    i = 0;
    p = lbl_801D53C8;
    while (*p != 0xFF) {
        if (*p == arg0) {
            return i;
        }
        p += 0xC;
        i++;
    }
    return -1;
}

s32 fn_8011FB44(void *);
void fn_800CEE00(void) {
    void *p = (void *)lbl_803EAEC4[0];
    if (p != NULL && (*(u16 *)((s8 *)p + 0x20) & 0x101) == 0) {
        fn_8011FB44(p);
    }
}

extern s32 lbl_8038E7A0[];
extern u8 lbl_803E0199[];
extern s32 lbl_8040AFAC;
void fn_800CD8E8(void) {
    s8 *p;
    s8 v;
    p = (s8 *)lbl_8038E7A0;
    v = 0;
    if (lbl_8040AFAC == 0 && (s8)lbl_803E0199[0] != 5 && (s8)lbl_803E0199[0] != 6) {
        v = 1;
    }
    p[1] = v;
}

extern f32 lbl_801A5538[];
extern s16 lbl_801DCB5C[];
void fn_800D98B4(void) {
    s16 *p;
    p = lbl_801DCB5C;
    while (*p != -1) {
        *(f32 *)(p + 6) = lbl_801A5538[0];
        p += 8;
    }
    lbl_80409570 = 0;
}

s16 *fn_800D9878(s32 arg0) {
    s16 *p;
    p = lbl_801DCB5C;
    while (*p != -1) {
        if (*p == arg0) {
            return p;
        }
        p += 8;
    }
    return NULL;
}

s32 KillParts(void *, s32, s32, s32);
extern s32 lbl_80409444;
void fn_800D532C(void *arg0, s32 arg1) {
    s32 v;
    v = -1;
    if (*(s16 *)((s8 *)arg0 + 0x1074) == 0x71 && *(s8 *)((s8 *)arg0 + 0x1085) <= 1) {
        v = lbl_80409444;
    }
    KillParts(arg0, -1, v, arg1);
}

s32 fn_80044F28(s32, s32, f32, f32, f32);
extern f32 lbl_8019FEEC[];
s32 fn_800AC020(s32 arg0, f32 farg0) {
    if (arg0 != 0) {
        arg0 = fn_80044F28(arg0, 0, farg0, lbl_8019FEEC[0], lbl_8019FEEC[0]);
    }
    return arg0;
}

s32 fn_800E1F88();
extern s32 lbl_803E0298[];
extern s32 lbl_804093E0;
typedef struct DMH1Ent { u8 a; u8 b; u8 pad[6]; } DMH1Ent;
typedef struct DMH1Tbl { u8 pad[0x110]; DMH1Ent e[0x16]; } DMH1Tbl;
void DebugMenu_HandleEntry1(void) {
    s32 i;
    DMH1Tbl *t;
    t = (DMH1Tbl *)lbl_803E0298;
    for (i = 0; i < 0x16; i++) {
        t->e[i].a = 1;
        t->e[i].b = 1;
    }
    if (*(s32 *)((s8 *)lbl_80409410 + 0x198) == 0x7B) {
        fn_800E1F88();
    }
    lbl_804093E0 = 1;
}

typedef struct D4Tbl { u8 pad[0x14]; s32 a[8]; } D4Tbl;
extern f32 lbl_801A523C[];
void fn_800D4CD0(void *arg0) {
    f32 f;
    s8 idx;
    void *t;
    void *q;
    if (*(u8 *)((s8 *)arg0 + 0x107D) != 0) {
        t = *(void **)((s8 *)arg0 + 0xEEC);
        if (t != NULL && *(f32 *)((s8 *)t + 0x6AC) == lbl_801A523C[0]) {
            q = *(void **)((s8 *)*(void **)((s8 *)arg0 + 0x64) + 0x20);
            idx = *(s8 *)((s8 *)q + 0xDC);
            if (idx != -1 && (*(D4Tbl **)((s8 *)arg0 + 0x60))->a[idx] != 0
                && *(u8 *)((s8 *)arg0 + 0x290) != 0) {
                f = *(f32 *)((s8 *)arg0 + 0x1024) * *(f32 *)((s8 *)q + 0x6C);
                *(f32 *)((s8 *)arg0 + 0x1F0) = f;
                *(f32 *)((s8 *)arg0 + 0x1EC) = f;
                return;
            }
        }
    }
    *(f32 *)((s8 *)arg0 + 0x1EC) = *(f32 *)((s8 *)arg0 + 0xBC);
    *(f32 *)((s8 *)arg0 + 0x1F0) = *(f32 *)((s8 *)arg0 + 0xC0);
}

s16 NuPortalWhichRoom(void *, void *);
typedef struct AC728Flags { u32 pad : 25; u32 b40 : 1; u32 b20 : 1; u32 lo : 5; } AC728Flags;
void fn_800AC728(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    s16 r;
    AC728Flags *fl = (AC728Flags *)((s8 *)arg0 + 0xF24);
    if (arg1 != 0) {
        fl->b40 = 1;
        fl->b20 = arg2;
        if (arg3 != -1) {
            *(s16 *)((s8 *)arg0 + 0x1078) = arg3;
            return;
        }
        if (*(void **)((s8 *)lbl_80409410 + 0x1C0) != NULL) {
            r = NuPortalWhichRoom(*(void **)((s8 *)lbl_80409410 + 0x1C0), (s8 *)arg0 + 0x90);
        } else {
            r = -1;
        }
        *(s16 *)((s8 *)arg0 + 0x1078) = r;
        return;
    }
    fl->b40 = 0;
}

s32 fn_800130F4(s32 *);
extern s32 lbl_802DA1F8[];
void fn_800CC500(void) {
    s32 i;
    for (i = 0; i <= 7; i++) {
        if (fn_800130F4(lbl_802DA1F8 + i * 3) != 0) {
            fn_80013200(lbl_802DA1F8 + i * 3, 0);
        }
    }
}

extern s32 lbl_802E0BBC[];
void fn_800CEF44(void) {
    s8 *p = (s8 *)lbl_802E0BBC;
    if (*(s16 *)(p + 8) != 0 && *(s16 *)(p + 8) <= 2) {
        fn_800D7ED8((s32)*(f32 *)(p + 4) + 1, *(s16 *)(p + 0xA), 0);
        *(s16 *)(p + 0xA) = 0;
    }
}

extern f32 lbl_801A4EE0[];
extern s32 lbl_801D6774[];
void fn_800CE144(void) {
    u8 *p = (u8 *)lbl_8040B060;
    p[0] = 0;
    p[1] = 0;
    lbl_8040B168 = lbl_801A4EE0[0];
    fn_800C3A24(lbl_801D6774);
}

extern f32 lbl_801A4F10[];
struct levelstate_c6900_0_s {
    u8 pad0[0x28];
    f32 unk28;
};

/* Level state block at lbl_802E0BE4 as read by fn_800C6900. */
struct levelstate_c6900_s {
    struct levelstate_c6900_0_s *unk0;
    void *unk4;                   /* nuvec_s at +0x10 */
    struct nuhspecial_s unk8[10];
    s16 unk80[10];
    u8 unk94;
    u8 pad95[0x98 - 0x95];
};

extern struct levelstate_c6900_s lbl_802E0BE4;
void fn_800CF03C(void) {
    s32 v;
    if (lbl_802E0BE4.unk0 != NULL && lbl_802E0BE4.unk0->unk28 == lbl_801A4F10[0] && lbl_80409008 == NULL) {
        if ((s32)lbl_80409004 == gPlayer1Pointer[0]) {
            v = gPlayer1Pointer[1];
        } else {
            v = gPlayer1Pointer[0];
        }
        if (v != 0) {
            fn_800D95B8(v);
        }
    }
}

extern f32 lbl_801A4EF0[];
extern s32 lbl_802E0B9C[];
void fn_800CE43C(void) {
    s32 *p = lbl_802E0B9C;
    if (p[1] != 0 && (void *)p[0] != NULL && *(f32 *)((s8 *)p[0] + 0x28) == lbl_801A4EF0[0]) {
        fn_800D95B8((void *)p[1]);
    }
}

/* AI path locator (OpenSaga AIPathFindLocator result): position, then a u16 direction. */
struct ailocator_s {
    u8 pad0[0x10];
    struct nuvec_s position;
    u8 pad1C[2];
    u16 direction;
};

/* CruiserC level state (lbl_802E0B9C, cleared by fn_800CE408). */
struct cruiserc_s {
    f32 *dookuFight;              /* AI message "DookuFight" */
    s32 countDooku;
    f32 *freePalpatine;           /* AI message "FreePalpatine"; value at +0x28 */
    s8 *palpatine;
    struct ailocator_s *palpatineLocator;
};

#define cruiser_c (*(struct cruiserc_s *)lbl_802E0B9C)

struct ailocator_s *AIPathFindLocator(s32, s32 *);
extern s32 lbl_801A2B20[];
extern s32 lbl_801A2B30[];
extern f32 lbl_801A2B3C[];

void CruiserCUpdate(void)
{
    if (cruiser_c.freePalpatine == NULL) {
        cruiser_c.freePalpatine = (f32 *)CheckAIMessage(lbl_80408F58, lbl_801A2B20, 0);
    }
    if (cruiser_c.palpatine == NULL) {
        cruiser_c.palpatine = (s8 *)fn_800D515C(0x64, 0, 1);
    }
    if (cruiser_c.palpatineLocator == NULL) {
        cruiser_c.palpatineLocator = AIPathFindLocator(*(s32 *)((s8 *)lbl_80409410 + 0x2E8), lbl_801A2B30);
    }
    if (cruiser_c.dookuFight == NULL) {
        cruiser_c.dookuFight = (f32 *)CheckAIMessage(lbl_80408F58, lbl_801A2AE4, 0);
    }
    if (cruiser_c.countDooku == 0) {
        cruiser_c.countDooku = fn_800D515C(0xE, 1, 1);
    }
    if (lbl_804091F8 == 0 && cruiser_c.palpatine != NULL && cruiser_c.palpatineLocator != NULL &&
        cruiser_c.freePalpatine != NULL && cruiser_c.freePalpatine[10] < lbl_801A2B3C[0]) {
        *(struct nuvec_s *)(cruiser_c.palpatine + 0x6C) = cruiser_c.palpatineLocator->position;
        *(u16 *)(cruiser_c.palpatine + 0x27E) = cruiser_c.palpatineLocator->direction;
    }
}

s32 fn_800C8CE4();
extern s32 lbl_8040B110;
extern s32 lbl_8040B190;
void fn_800CC3FC(s32 arg0) {
    s32 t = arg0;
    if (t != 0 && t != lbl_8040B110) {
        NuStrCpy((s32 *)lbl_801DC964, t);
        fn_800C8CE4();
        lbl_8040B110 = t;
        lbl_8040B190 = t;
    }
}

extern f32 lbl_801A4F9C[];
extern f32 lbl_80408E9C;
u16 SeekRot(s32 arg0, s32 arg1, f32 farg0) {
    f32 f;
    s32 d;
    f = farg0 * lbl_80408E9C;
    if (f > lbl_801A4F9C[0]) {
        f = lbl_801A4F9C[0];
    }
    d = arg1 - arg0;
    if (d > 0x8000) {
        d -= 0x10000;
    } else if (d < -0x8000) {
        d += 0x10000;
    }
    return (u16)(s32)((f32)arg0 + (f32)d * f);
}

extern f32 lbl_801A511C[];
extern f32 lbl_801A5120[];
extern void *lbl_80408DF0;
extern void *lbl_804093A8;
extern s32 lbl_8040AFC4;
void fn_800D3ACC(void *arg0) {
    s8 *a = arg0;
    f32 x, hi, lo;
    s32 v;
    s8 *t;
    if (lbl_8040AFC4 != 0 && (x = *(f32 *)(a + 0x1048)) < (hi = *(f32 *)((s8 *)lbl_804093A8 + 0x84))) {
        lo = *(f32 *)((s8 *)lbl_804093A8 + 0x80);
        if (x > lo) {
            *(f32 *)(a + 0x1050) = lbl_801A5120[0] - (x - lo) / (hi - lo);
        } else {
            *(f32 *)(a + 0x1050) = lbl_801A5120[0];
        }
    } else {
        *(f32 *)(a + 0x1050) = lbl_801A511C[0];
    }
    if (lbl_8040AFC4 > 0 && *(s16 *)(a + 0x1074) != 0x75) {
        if (*(u8 *)(a + 0x28F) != 0
            && (v = *(s32 *)(*(s8 **)(*(s32 *)((s8 *)lbl_80408DF0 + 0x20) + **(s16 **)(a + 0x60) * 0x48 + 0x20) + 0xAC)) != 0) {
            *(s32 *)(a + 0x1060) = v;
        } else {
            x = *(f32 *)(a + 0x1048);
            t = *(s8 **)(*(s8 **)(a + 0x64) + 0x20);
            if (x > *(f32 *)(t + 0xB4)) {
                *(s32 *)(a + 0x1060) = *(s32 *)(t + 0xA8);
            } else if (x > *(f32 *)(t + 0xB0)) {
                *(s32 *)(a + 0x1060) = *(s32 *)(t + 0xA4);
            } else {
                *(s32 *)(a + 0x1060) = *(s32 *)(t + 0xA0);
            }
        }
        switch (*(s16 *)(a + 0x1074)) {
        case 0x71:
            if (*(s8 *)(a + 0x1085) <= 1) {
                *(s32 *)(a + 0x1060) &= ~0x10;
            }
            break;
        case 0x43:
            if (*(s32 *)(a + 0xF28) & 0x40000) {
                *(s32 *)(a + 0x1060) |= 0x20;
            } else {
                *(s32 *)(a + 0x1060) |= 0x40;
            }
            break;
        }
    }
}

extern f32 lbl_8019FEF8[];
extern f32 lbl_8019FEFC[];

void fn_800AC058(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80044F28(arg0, 0, (f32) (f64) arg1 / lbl_8019FEF8[0], lbl_8019FEFC[0], lbl_8019FEFC[0]);
    }
}

extern s32 lbl_8040913C;
extern s32 lbl_804093C0;

s32 fn_800B9D2C(s32 arg0) {
    lbl_8040913C = arg0;
    lbl_804093C0 = (-1 - arg0) == 0;
}

extern u8 lbl_802DA6BD[];

s32 fn_800CC610(void) {
    return (lbl_802DA6BD[0] ^ 2) == 0;
}

extern s16 lbl_803ED3AC[];

s32 fn_800CC6E4(void) {
    return (lbl_803ED3AC[0] ^ 4) == 0;
}

s32 fn_800D5408(void *arg0) {
    return ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x7DF))) ^ 0x24) == 0;
}

#define Menu_Open ((s32 (*)(s32, s32, s32))Menu_Open)
void Menu_ResetStack(void);
s32 Shop_UpdateMenu();
void fn_80078E90(void *);
s32 fn_8007AC44();
int memcmp(void *, void *, u32);
extern s32 gMenuDepth;
extern s32 gMenuStack[];
extern f32 lbl_801A03B0[];
extern f32 lbl_801A03B4[];
extern f32 lbl_801A03B8[];
extern s32 lbl_803E8430[];
extern s32 lbl_80409124;
extern s32 lbl_80409B98;
extern f32 lbl_8040AFA0;
extern f32 lbl_8040B0C8;
extern s32 lbl_8040B0CC;
extern f32 lbl_8040B0D0;
extern f32 lbl_8040B0D4;
extern s32 str_menuBack2[];

void Menu_Unknown12_HandleSelection(void) {
    f32 temp_f31;
    s32 temp_r31;

    temp_r31 = lbl_80409124;
    if (temp_r31 != 0) {
        lbl_8040B0C8 = lbl_801A03B0[0];
        lbl_8040B0CC = 1;
        lbl_8040B0D0 = lbl_801A03B4[0];
        fn_80078E90((gMenuDepth * 0xE0) + ((s8 *)gMenuStack));
        Menu_ResetStack();
        lbl_80409124 = 0;
        lbl_8040AFA0 = lbl_801A03B8[0];
        return;
    }
    if (Shop_UpdateMenu() != 0) {
        fn_8006DCD4(str_menuBack2, 0);
        temp_f31 = lbl_801A03B8[0];
        lbl_80409B98 = temp_r31;
        lbl_8040B0D4 = temp_f31;
        if ((memcmp(lbl_803E8430, lbl_803E0298, 0x210) != 0) && (fn_8007AC44() == 0)) {
            lbl_80409124 = 1;
            Menu_Open(0x3E8, -1, -1);
            return;
        }
        lbl_8040B0C8 = lbl_801A03B0[0];
        lbl_8040B0CC = 1;
        lbl_8040B0D0 = lbl_801A03B4[0];
        fn_80078E90((gMenuDepth * 0xE0) + ((s8 *)gMenuStack));
        Menu_ResetStack();
        lbl_8040AFA0 = temp_f31;
    }
}
#undef Menu_Open

#define fn_800B9ED4 ((s32 (*)(void))fn_800B9ED4)
extern const f32 lbl_8019FEC0[];
extern const f32 lbl_8019FED0[];
extern const f32 lbl_8019FED4[];
extern const f32 lbl_8019FED8[];

void fn_800ABEB0(void *arg0, s32 arg1) {
    f32 temp_f31;

    temp_f31 = lbl_8019FEC0[0];
    (*(s16 *)((s8 *)(arg0) + (0x50))) = 1;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = temp_f31;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (((f32) (f64) fn_800B9ED4() * lbl_8019FED0[0] * lbl_8019FED4[0]) + lbl_8019FED8[0]);
    if (arg1 > 0) {
        (*(f32 *)((s8 *)(arg0) + (0x20))) = temp_f31;
        if (arg1 > 1) {
            (*(s16 *)((s8 *)(arg0) + (0x52))) = -1;
        }
    }
}
#undef fn_800B9ED4

void fn_800D4D64(void *);

void fn_800ABC50(void *arg0) {
    f32 temp_f0;
    f32 temp_f13;
    void *temp_r10;

    temp_r10 = (*(void **)((s8 *)(arg0) + (0x64)));
    (*(u8 *)((s8 *)(arg0) + (0x1087))) = (u8) (*(u8 *)((s8 *)((*(void **)((s8 *)(temp_r10) + (0x20)))) + (0xE0)));
    (*(f32 *)((s8 *)(arg0) + (0xB8))) = (f32) (*(f32 *)((s8 *)(temp_r10) + (0x38)));
    (*(f32 *)((s8 *)(arg0) + (0x1028))) = (f32) (*(f32 *)((s8 *)(temp_r10) + (0x2C)));
    temp_f0 = (*(f32 *)((s8 *)(temp_r10) + (0x30)));
    (*(f32 *)((s8 *)(arg0) + (0x1014))) = temp_f0;
    temp_f13 = (*(f32 *)((s8 *)(temp_r10) + (0x34)));
    (*(f32 *)((s8 *)(arg0) + (0x101C))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x1018))) = temp_f13;
    (*(f32 *)((s8 *)(arg0) + (0x1020))) = temp_f13;
    fn_800D4D64(arg0);
}

s32 fn_800D9824(s32 arg0, s32 arg1) {
    u8 *var_r9;
    s32 var_ctr;
    s32 var_r3;

    var_ctr = 0x40;
    var_r9 = (u8 *)lbl_803FD4E0;
    var_r3 = 0;
    do {
        if (((s32) (*(u8 *)((s8 *)(var_r9) + (0x8B))) != 0) && ((s8) (*(u8 *)((s8 *)(var_r9) + (0x93))) == arg0)) {
            var_r3 = 1;
            if (arg1 != 0) {
                (*(u8 *)((s8 *)(var_r9) + (0x8B))) = 0U;
            }
        }
        var_r9 += 0x9C;
        var_ctr -= 1;
    } while (var_ctr != 0);
    return var_r3;
}

extern s32 MenuHeader[];
extern f32 lbl_801A0060[];
extern f32 lbl_801A0064[];
extern s32 lbl_80409088;
extern f32 lbl_8040993C;
extern s32 lbl_8040B06C;
extern f32 lbl_8040B070;
extern f32 lbl_8040B074;
extern f32 lbl_8040B078;
extern f32 lbl_8040B07C;
extern f32 lbl_8040B088;
extern s32 lbl_8040B08C;

void fn_800B0120(s32 arg0, s32 arg1, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    if (arg0 != 0) {
        lbl_8040B06C = arg0;
        lbl_8040B074 = farg1;
        lbl_8040B078 = farg3;
        lbl_80409088 = 0;
        lbl_8040B07C = farg0;
        lbl_8040B070 = lbl_801A0060[0];
        lbl_8040B088 = farg2;
        lbl_8040B08C = arg1;
        if ((arg1 != 0) && (farg0 == lbl_801A0060[0]) && ((farg2 <= lbl_801A0060[0]))) {
            lbl_8040993C = lbl_801A0064[0];
        }
        if (((lbl_8040B07C <= lbl_801A0060[0])) && ((lbl_8040B088 <= lbl_801A0060[0]))) {
            s8 *p = (s8 *)MenuHeader;
            *(s8 *)(p + 0x174) = -1;
            *(f32 *)(p + 0x138) = *(f32 *)(p + 0x13C);
        }
    }
}

extern s32 lbl_801A1D14[];
extern s32 lbl_801A1D28[];
extern f32 lbl_801A1D3C[];
extern f32 lbl_801A1D40[];
extern f32 lbl_801A1D44[];
extern f32 lbl_801A1D48[];
extern f32 lbl_801A1D4C[];
extern f32 lbl_801A1D50[];
extern f32 lbl_801A1D54[];
extern f32 lbl_801A1D58[];
extern f32 lbl_801A1D5C[];
extern f32 lbl_801A1D60[];

void RescueCAlwaysUpdate(void)
{
  struct nuvec_s sp8;
  f32 temp_f31;
  f32 temp_f31_3;
  s16 temp_r0;
  s8 *temp_r9;
  struct nugspline_s *temp_r31;
  struct nuvec_s *var_r30;
  void *temp_r3;
  void *temp_r3_2;
  void *temp_r3_3;
  var_r30 = (void *) 0;
  temp_r31 = lbl_80409410->unk1974;
  if (temp_r31 != ((void *) 0))
  {
    if (fn_800AAC04(&sp8, (void *) 0) != 0)
    {
      var_r30 = &sp8;
    }
    if (var_r30 != ((void *) 0))
    {
      temp_r9 = temp_r31->pts;
      temp_r0 = temp_r31->ptsize;
      if (fn_800CFD4C(*((f32 *) (&sp8)), sp8.z, *((f32 *) (((s8 *) temp_r9) + 0)), *((f32 *) (((s8 *) temp_r9) + 8)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 0)), *((f32 *) (((s8 *) (&temp_r9[temp_r0])) + 8))) != 0)
      {
        lbl_804093B8 = 0x12;
      }
      else
      {
        lbl_804093B8 = 0x14;
      }
    }
  }
  if (fn_800130F4(lbl_803EB014) != 0)
  {
    temp_r3 = fn_8001384C((s32) lbl_803EB014);
    if ((temp_r3 != ((void *) 0)) && ((((temp_f31 = *((f32 *) (((s8 *) temp_r3) + 0x4C)), temp_f31 >= lbl_801A1D3C[0])) && (temp_f31 <= lbl_801A1D40[0])) || ((temp_f31 >= lbl_801A1D44[0]) && (temp_f31 <= lbl_801A1D48[0]))))
    {
      fn_8006DCD4(lbl_801A1D04, fn_800133FC(lbl_803EB014) + 0x30);
    }
  }
  if (fn_800130F4(lbl_803EB020) != 0)
  {
    temp_r3_2 = fn_8001384C((s32) lbl_803EB020);
    if (temp_r3_2 != ((void *) 0))
    {
      temp_f31 = *((f32 *) (((s8 *) temp_r3_2) + 0x4C));
      if (((temp_f31 >= lbl_801A1D4C[0]) && (temp_f31 <= lbl_801A1D50[0])) || ((temp_f31 >= lbl_801A1D54[0]) && (temp_f31 <= lbl_801A1D58[0])))
      {
        lbl_80409214 = 0;
      }
      if ((temp_f31 >= lbl_801A1D5C[0]) && (temp_f31 <= lbl_801A1D60[0]))
      {
        lbl_80409218 = 0;
      }
      if (((((s32) lbl_80409214) == 0) && (temp_f31 >= lbl_801A1D3C[0])) && (temp_f31 <= lbl_801A1D40[0]))
      {
        fn_8006DCD4(lbl_801A1D14, fn_800133FC(lbl_803EB020) + 0x30);
        lbl_80409214 = 1;
      }
      if (((((s32) lbl_80409218) == 0) && (temp_f31 >= lbl_801A1D44[0])) && (temp_f31 <= lbl_801A1D48[0]))
      {
        fn_8006DCD4(lbl_801A1D28, fn_800133FC(lbl_803EB020) + 0x30);
        lbl_80409218 = 1;
      }
    }
  }
  if (fn_800130F4(lbl_803EB02C) != 0)
  {
    temp_r3_3 = fn_8001384C((s32) lbl_803EB02C);
    if (temp_r3_3 != ((void *) 0))
    {
      temp_f31_3 = *((f32 *) (((s8 *) temp_r3_3) + 0x4C));
      if (((temp_f31_3 >= lbl_801A1D4C[0]) && (temp_f31_3 <= lbl_801A1D50[0])) || ((temp_f31_3 >= lbl_801A1D54[0]) && (temp_f31_3 <= lbl_801A1D58[0])))
      {
        lbl_8040921C = 0;
      }
      if ((temp_f31_3 >= lbl_801A1D5C[0]) && (temp_f31_3 <= lbl_801A1D60[0]))
      {
        lbl_80409220 = 0;
      }
      if (((((s32) lbl_8040921C) == 0) && (temp_f31_3 >= lbl_801A1D3C[0])) && (temp_f31_3 <= lbl_801A1D40[0]))
      {
        fn_8006DCD4(lbl_801A1D14, fn_800133FC(lbl_803EB02C) + 0x30);
        lbl_8040921C = 1;
      }
      if (((((s32) lbl_80409220) == 0) && (temp_f31_3 >= lbl_801A1D44[0])) && (temp_f31_3 <= lbl_801A1D48[0]))
      {
        fn_8006DCD4(lbl_801A1D28, fn_800133FC(lbl_803EB02C) + 0x30);
        lbl_80409220 = 1;
      }
    }
  }
}

void fn_800BA740(void) { volatile s32 pad[3]; }

void fn_800ABCAC(void *arg0, s32 arg1) {
    u8 max = *(u8 *)((s8 *)arg0 + 0x1084);
    *(s8 *)((s8 *)arg0 + 0x1085) = arg1;
    if ((s8)arg1 > max) {
        *(s8 *)((s8 *)arg0 + 0x1085) = max;
    }
}

extern f32 lbl_801A5274[];
void fn_800D5530(void *arg0, f32 farg0) {
    f32 lim = lbl_801A5274[0];
    f32 v = *(f32 *)((s8 *)arg0 + 0x1EC) - farg0;
    *(f32 *)((s8 *)arg0 + 0x1EC) = v;
    if (v <= lim) {
        *(s32 *)((s8 *)arg0 + 0x198) = 0;
        *(s32 *)((s8 *)arg0 + 0x1B8) = 0;
    }
}

s16 fn_800D99AC(void) { return lbl_80409570 ? *(s16 *)lbl_80409570 : -1; }

extern f32 lbl_801A5278[];
s32 fn_800D5560(void *arg0) { f32 c = lbl_801A5278[0]; s32 r = 0; if (!(*(f32 *)((s8 *)arg0 + 0x1EC) > c)) r = 1; return r; }

extern f32 lbl_801A5524[];
extern f32 lbl_801A5528[];
extern f32 lbl_801A552C[];
extern f32 lbl_80409450;
extern f32 lbl_80409454;
extern f32 lbl_8040B094;
extern f32 lbl_8040B098;
void fn_800D9784(void) {
    f32 a = lbl_801A5524[0];
    f32 b = lbl_801A552C[0];
    lbl_8040B094 = b / (lbl_80409454 * lbl_801A5528[0]);
    lbl_8040B098 = a / lbl_80409450;
}

extern f32 lbl_801A4F98[];
s32 fn_800CFD4C(f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5) {
    f32 t = ((farg0 - farg2) * (farg5 - farg3)) + ((farg1 - farg3) * (farg2 - farg4));
    return t >= lbl_801A4F98[0];
}

s32 fn_800CC5D8(void) {
    s32 r = 0;
    if (*(s32 *)((s8 *)lbl_80409410 + 0x19C) == 7 && *(s32 *)((s8 *)lbl_80409410 + 0x198) == 0x37) {
        r = (lbl_803E0199[0] ^ 0x15) == 0;
    }
    return r;
}

typedef struct { s32 v[3]; } DbgVec;
extern void *lbl_80409004;
void DebugMenu_ToggleOption1(s32 arg0, s32 arg1) {
    if (lbl_80409004 != NULL) {
        lbl_801D5744[0] = arg0;
        if (arg0 != 0) {
            lbl_801D5744[9] = arg1;
            *(DbgVec *)&lbl_801D5744[1] = *(DbgVec *)((s8 *)lbl_80409004 + 0x90);
            return;
        }
        lbl_801D5744[9] = arg0;
    }
}

s32 fn_800CFE9C(void *arg0, void *arg1, f32 farg0, f32 farg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f2;
    f32 temp_f2_2;

    temp_f2_2 = farg0 + farg1;
    temp_f2 = temp_f2_2 * temp_f2_2;
    temp_f12 = (*(f32 *)((s8 *)(arg1) + (4))) - (*(f32 *)((s8 *)(arg0) + (4)));
    temp_f13 = (*(f32 *)((s8 *)(arg1) + (0))) - (*(f32 *)((s8 *)(arg0) + (0)));
    temp_f0_2 = (*(f32 *)((s8 *)(arg1) + (8))) - (*(f32 *)((s8 *)(arg0) + (8)));
    temp_f0 = (temp_f0_2 * temp_f0_2) + ((temp_f13 * temp_f13) + (temp_f12 * temp_f12));
    return temp_f0 <= temp_f2;
}

typedef struct {
    u8 pad0[0xA];
    s16 selA;
    u8 padC[2];
    s16 minE;
    u8 pad10[2];
    s16 max12;
    s16 id;
    u8 pad16[0x94 - 0x16];
    f32 unk94;
    u8 pad98[4];
    f32 unk9C;
    u8 padA0[8];
    f32 unkA8;
    u8 padAC[0xE0 - 0xAC];
} MenuFrame;
extern s32 gRegisteredMenuDefinitions[];
s32 fn_800B2ED4(void) {
    s16 id = ((MenuFrame *)gMenuStack)[gMenuDepth].id;
    if (id == -1) {
        return -1;
    }
    return *(s32 *)((s8 *)gRegisteredMenuDefinitions + id * 0x1C);
}

extern f32 lbl_8019FEA8[];
extern f32 lbl_80408E9C;
void fn_800ABD50(void *arg0) {
    f32 zero = lbl_8019FEA8[0];
    s8 *p = (s8 *)*(s32 *)((s8 *)*(void **)((s8 *)arg0 + 0xEEC) + 0x61C) + 0x40;
    if (*(f32 *)(p + 0xC) > zero) {
        *(f32 *)(p + 0xC) -= lbl_80408E9C;
    }
    if (*(f32 *)(p + 4) > zero) {
        *(f32 *)(p + 4) -= lbl_80408E9C;
    }
    if (*(u8 *)(p + 0x10) != 0) {
        *(u8 *)(p + 0x10) -= 1;
    }
}

s32 fn_800CFD80(void *, s32, s32);
extern f32 lbl_801A50F0[];
extern f32 lbl_801A50F4[];
extern f32 lbl_801A50F8[];
extern u16 lbl_8040B05E;

void fn_800D2E44(void *arg0, s32 arg1) {
    s16 temp_r0;
    s32 var_r30;
    u16 temp_r3;
    u16 temp_r3_2;
    u16 temp_r3_3;
    u16 temp_r3_4;
    u16 temp_r4;
    u16 temp_r4_2;
    u16 var_r30_2;
    u16 var_r4;
    void *temp_r9;

    temp_r0 = ((u32) (*(u32 *)((s8 *)(arg0) + (0x20C))) >> 0x1DU) & 1;
    if (temp_r0 == 0) {
        if (((*(f32 *)((s8 *)(arg0) + (0xF48))) == lbl_801A50F0[0]) && ((*(f32 *)((s8 *)(arg0) + (0xF4C))) == lbl_801A50F4[0]) && ((*(f32 *)((s8 *)(arg0) + (0xF50))) == lbl_801A50F0[0])) {
            (*(s16 *)((s8 *)(arg0) + (0x106E))) = temp_r0;
            (*(s16 *)((s8 *)(arg0) + (0x1070))) = temp_r0;
        } else {
            fn_800CFD80(arg0 + 0xF48, 0, 0);
            { u16 a = lbl_8040B05C; u16 b = lbl_8040B05E;
            (*(s16 *)((s8 *)(arg0) + (0x106E))) = a;
            (*(s16 *)((s8 *)(arg0) + (0x1070))) = b; }
        }
    }
    if (((s32) (*(u8 *)((s8 *)(arg0) + (0x285))) != 0) && (((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x64)))) + (4))) & 0x100) || ((temp_r9 = (*(void **)((s8 *)(arg0) + (0xEEC))), ((temp_r9 == NULL) == 0)) && ((s32) (*(u8 *)((s8 *)(temp_r9) + (0x7DF))) == 0x12)))) {
        var_r30 = 1;
    } else {
        var_r30 = 0;
    }
    if (arg1 == 1) {
        (*(u16 *)((s8 *)(arg0) + (0x106A))) = (u16) (*(s16 *)((s8 *)(arg0) + (0x106E)));
        (*(u16 *)((s8 *)(arg0) + (0x106C))) = (u16) (*(s16 *)((s8 *)(arg0) + (0x1070)));
        if (var_r30 != 0) {
            if ((*(f32 *)((s8 *)(arg0) + (0xF4C))) > NuCosApprox(0x2000)) {
                (*(u16 *)((s8 *)(arg0) + (0x27C))) = (u16) (*(s16 *)((s8 *)(arg0) + (0x106E)));
                (*(u16 *)((s8 *)(arg0) + (0x280))) = (u16) (*(s16 *)((s8 *)(arg0) + (0x1070)));
                return;
            }
            (*(u16 *)((s8 *)(arg0) + (0x280))) = 0U;
            (*(u16 *)((s8 *)(arg0) + (0x27C))) = 0U;
            return;
        }
        (*(u16 *)((s8 *)(arg0) + (0x280))) = (u16) var_r30;
        (*(u16 *)((s8 *)(arg0) + (0x27C))) = (u16) var_r30;
        return;
    } else if (arg1 == 2) {
        temp_r3 = (*(u16 *)((s8 *)(arg0) + (0x106A)));
        temp_r4 = (u16) (*(s16 *)((s8 *)(arg0) + (0x106E)));
        if ((s32) temp_r3 != (s32) temp_r4) {
            (*(u16 *)((s8 *)(arg0) + (0x106A))) = SeekRot((s32) temp_r3, (s32) temp_r4, lbl_801A50F8[0]);
        }
        temp_r3_2 = (*(u16 *)((s8 *)(arg0) + (0x106C)));
        temp_r4_2 = (u16) (*(s16 *)((s8 *)(arg0) + (0x1070)));
        if ((s32) temp_r3_2 != (s32) temp_r4_2) {
            (*(u16 *)((s8 *)(arg0) + (0x106C))) = SeekRot((s32) temp_r3_2, (s32) temp_r4_2, lbl_801A50F8[0]);
        }
        if (((s32) (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x7E5))) != 1) && ((s32) (*(u8 *)((s8 *)(arg0) + (0x107E))) == 2)) {
            if ((var_r30 != 0) && ((*(f32 *)((s8 *)(arg0) + (0xF4C))) > NuCosApprox(0x2000))) {
                var_r4 = (u16) (*(s16 *)((s8 *)(arg0) + (0x106E)));
                var_r30_2 = (u16) (*(s16 *)((s8 *)(arg0) + (0x1070)));
            } else {
                var_r30_2 = 0;
                var_r4 = 0;
            }
            temp_r3_3 = (*(u16 *)((s8 *)(arg0) + (0x27C)));
            if ((s32) temp_r3_3 != (s32) var_r4) {
                (*(u16 *)((s8 *)(arg0) + (0x27C))) = SeekRot((s32) temp_r3_3, (s32) var_r4, lbl_801A50F8[0]);
            }
            temp_r3_4 = (*(u16 *)((s8 *)(arg0) + (0x280)));
            if ((s32) temp_r3_4 != (s32) var_r30_2) {
                (*(u16 *)((s8 *)(arg0) + (0x280))) = SeekRot((s32) temp_r3_4, (s32) var_r30_2, lbl_801A50F8[0]);
            }
        }
    }
}

extern f32 lbl_801A1E58[];
void fn_801268CC(s32);

static inline s32 ForceObjsReady(s32 count)
{
    s32 *p = lbl_803EAEC4;
    s32 o;

    do {
        o = *p++;
        if (o == 0 || (*(u16 *)(o + 0x20) & 0x101) == 0) {
            return 0;
        }
    } while (--count > 0);
    return 1;
}

/* Each level's intro timer compares against its own copy of the 0.0f literal. */
#define DEFINE_INTRO_UPDATE(name, zero)                                  \
    static inline s32 name(s32 count, f32 time)                          \
    {                                                                    \
        s32 i;                                                           \
                                                                         \
        switch (lbl_8040B060[0]) {                                       \
        case 0:                                                          \
            if (ForceObjsReady(count)) {                                 \
                for (i = 0; i < count; i++) {                            \
                    fn_801268CC(lbl_803EAEC4[i]);                        \
                }                                                        \
                if (time <= zero[0]) {                                   \
                    goto done;                                           \
                }                                                        \
                lbl_8040B060[0] = 1;                                     \
            }                                                            \
            break;                                                       \
        case 1:                                                          \
            lbl_8040B0C8 += lbl_80408E9C;                                \
            if (lbl_8040B0C8 >= time) {                                  \
            done:                                                        \
                lbl_8040B060[0] = 2;                                     \
                return 1;                                                \
            }                                                            \
            break;                                                       \
        }                                                                \
        return 0;                                                        \
    }

DEFINE_INTRO_UPDATE(IntroUpdate_800BCD9C, lbl_801A1E58)

void fn_800BCD9C(void)
{
    if (lbl_803EAF8E[0] == 0 && IntroUpdate_800BCD9C(1, lbl_801A1E58[0])) {
        lbl_803EAF8E[0] = 1;
        fn_8013F0AC(10);
    }
}

extern u8 lbl_803EAF86[];
extern f32 lbl_801A2C10[];
DEFINE_INTRO_UPDATE(IntroUpdate_800C535C, lbl_801A2C10)

void fn_800C535C(void)
{
    if (lbl_803EAF86[0] == 0 && IntroUpdate_800C535C(1, lbl_801A2C10[0])) {
        lbl_803EAF86[0] = 1;
        fn_8013F0AC(2);
    }
}

extern u8 lbl_803EAF84[];
extern f32 lbl_801A2BD8[];
DEFINE_INTRO_UPDATE(IntroUpdate_800C4FDC, lbl_801A2BD8)

void fn_800C4FDC(void)
{
    s32 i;
    s32 p;

    if (lbl_803EAF84[0] == 0 && IntroUpdate_800C4FDC(1, lbl_801A2BD8[0])) {
        lbl_803EAF84[0] = 1;
        fn_8013F0AC(0);
    }
    if (lbl_80409354 != 0 && (*(s32 *)(lbl_80409354 + 0x88) & 0x80000)) {
        for (i = 0; i < 8; i++) {
            p = gPlayer1Pointer[i];
            if (p != 0 && *(s16 *)(p + 0x1074) == 0xF) {
                *(u8 *)(*(s32 *)(p + 0xEEC) + 0x7CB) = 0;
            }
        }
        lbl_80409354 = 0;
    }
}

s32 fn_800BB20C(s32, s32, s32, f32);
void fn_800C5A10(s32);
extern f32 lbl_801A2CA8[];
extern f32 lbl_801A2CAC[];
extern f32 lbl_801A2CB0[];
DEFINE_INTRO_UPDATE(IntroUpdate_800C5B9C, lbl_801A2CAC)
void fn_800C5B9C(void)
{
    s32 o;
    s32 i;

    if (lbl_804091F8 != 0) {
        fn_800BB20C(0, 0, 1, lbl_801A2CA8[0]);
    } else if (IntroUpdate_800C5B9C(1, lbl_801A2CA8[0])) {
        fn_8011E9C4(0x51);
    }
    if (lbl_8040A6A4 <= lbl_801A2CAC[0]) {
        if (lbl_803EAE44[0] == 0 || !(*(s32 *)(lbl_803EAE44[0] + 0x18) & 0x80)) {
            i = lbl_8040935C;
            o = lbl_803ED320[i];
            if (o == 0) {
                fn_800C5A10(i);
                lbl_8040935C++;
                if (lbl_8040935C == 3) {
                    lbl_8040935C = o;
                }
                lbl_8040A6A4 = lbl_801A2CB0[0];
            }
        }
    } else {
        lbl_8040A6A4 -= lbl_80408E9C;
    }
}

#define fn_800133FC ((s32 (*)(s32))fn_800133FC)
void *fn_8001384C(s32);
s32 fn_8006DCD4(s32 *, s32);
extern s32 lbl_801A1BB4[];
extern f32 lbl_801A2B94[];
extern f32 lbl_8040933C;
extern u8 lbl_80409340;
extern u8 lbl_80409341;

void fn_800C4DAC(void) {
    u8 var_r0;
    void *temp_r3;

    if ((s32) lbl_803EAEC4[0] != 0) {
        temp_r3 = fn_8001384C(lbl_803EAEC4[0] + 4);
        if ((s32) (*(s32 *)((s8 *)(temp_r3) + (0x50))) < 0) {
            if ((((*(f32 *)((s8 *)(temp_r3) + (0x4C))) >= lbl_8040933C)) && ((*(f32 *)((s8 *)(temp_r3) + (0x4C))) < (lbl_8040933C + lbl_801A2B94[0]))) {
                if ((s32) lbl_80409341 == 0) {
                    var_r0 = 1;
                    lbl_80409341 = 1;
                } else {
                    goto block_8;
                }
                goto block_9;
            }
            if ((*(f32 *)((s8 *)(temp_r3) + (0x4C))) < lbl_8040933C) {
                lbl_80409340 = lbl_80409341 = 0;
            } else {
block_8:
                var_r0 = 0;
block_9:
                lbl_80409340 = var_r0;
            }
            if ((s32) lbl_80409340 != 0) {
                lbl_8040B154 &= 0xFFFFFFFE;
            }
            if (!(lbl_8040B154 & 1)) {
                lbl_8040B154 |= 1;
                fn_8006DCD4(lbl_801A1BB4, fn_800133FC(lbl_803EAEC4[0] + 4) + 0x30);
            }
        }
    }
}
#undef fn_800133FC

#define fn_800BB3FC ((s32(*)(s32, s32, f32))fn_800BB3FC)
#define fn_800D515C ((void *(*)(s32, s32, s32))fn_800D515C)
void fn_80103F84(void *);
extern f32 lbl_801A2AFC[];

void fn_800C4614(void) {
    f32 temp_f0;
    f32 temp_f31;
    s32 var_r0;
    void *var_r3;

    if ((s32) lbl_804091F8 != 0) {
        fn_800BB3FC(0xE, 0, lbl_801A2AFC[0]);
    } else {
        temp_f31 = lbl_801A2AFC[0];
        switch ((s32) lbl_8040B060[0]) {
        case 0:
            var_r3 = fn_800D515C(0xE, 1, 1);
            if ((var_r3 == NULL) || !((*(s32 *)((s8 *)(var_r3) + (0xF24))) & 2) || (((s32) (*(u8 *)((s8 *)(var_r3) + (0x28F))) == 0) && ((s32) (*(u8 *)((s8 *)(var_r3) + (0x1085))) != 0))) {
                var_r3 = NULL;
            }
            if (var_r3 == NULL) {
                goto block_17;
            }
            if (!(temp_f31 <= lbl_801A2AFC[0])) {
                lbl_8040B060[0] = 1;
                goto block_17;
            }
            goto block_16;
        case 1:
            temp_f0 = lbl_8040B0C8 + lbl_80408E9C;
            lbl_8040B0C8 = temp_f0;
            if (temp_f0 >= temp_f31) {
block_16:
                lbl_8040B060[0] = 2;
                var_r0 = 1;
                break;
            }
        default:
block_17:
            var_r0 = 0;
            break;
        }
        if (var_r0 != 0) {
            lbl_80408F2C = 1;
            lbl_804093B0 = 0x52;
            if ((s32) lbl_8040AF64 != -1) {
                lbl_8040AF94 = 1;
            }
        }
    }
    { s32 *p = lbl_802E0B88; fn_80103F84(p + 2); }
}
#undef fn_800BB3FC
#undef fn_800D515C

void AIScriptProcessorInit(void *, void *, void *, s32, s32, s32, s32, void *, void *);
#define lbl_80409410 (*(void *(*))&lbl_80409410)

void fn_800AB98C(void *arg0)
{
    void *script;

    script = *(void **)((s8 *)arg0 + 0x2A0);
    if (script != NULL) {
        AIScriptProcessorInit(*(void **)((s8 *)lbl_80409410 + 0x2E8), (s8 *)arg0 + 0x2A0, (s8 *)arg0 + 0x2A0, 0, 0, 0, 0, script,
                              *(void **)((s8 *)script + 0x38));
        *(s32 *)((s8 *)arg0 + 0x2D8) = 0;
    }
}
#undef lbl_80409410

#define Menu_CloseCurrent ((void (*)(void))Menu_CloseCurrent)
#define fn_8006DCD4 ((s32(*)(void *, s32))fn_8006DCD4)
extern s32 lbl_801D5994[];
extern u32 lbl_803E0498[];
extern s32 str_Enabled[];

typedef struct {
    u8 pad0[2];
    u8 on;
    u8 pad3[0xD];
} MenuToggle;

void Menu_Unknown5_HandleSelection(void *arg0)
{
    MenuToggle *e;
    s32 sel;
    s32 cur;
    s32 i;

    if (*(s32 *)((s8 *)arg0 + 0x68) != 0) {
        sel = *(s32 *)((s8 *)arg0 + 0x34);
        if ((lbl_803E0498[0] >> sel) & 1) {
            e = (MenuToggle *)lbl_801D5994;
            e[sel].on = e[sel].on == 0;
            fn_8006DCD4(str_Confirm, 0);
            cur = *(s32 *)((s8 *)arg0 + 0x34);
            if (e[cur].on != 0 && cur > 6 && cur <= 9) {
                for (i = 7; i < 10; i++) {
                    if (i != *(s32 *)((s8 *)arg0 + 0x34)) {
                        e[i].on = 0;
                    }
                }
            }
        } else {
            fn_8006DCD4(str_Enabled, 0);
        }
    } else if (*(s32 *)((s8 *)arg0 + 0x6C) != 0) {
        Menu_CloseCurrent();
        *(s32 *)((s8 *)arg0 + 0x50) = PauseMenu_HandleEntry1(str_Cancel);
    }
}
#undef fn_8006DCD4
#undef Menu_CloseCurrent

s32 NuHGobjRndrMtxDwa(s32, s32, f32, f32);
extern f32 lbl_801A03EC[];
extern f32 lbl_801A03F0[];
extern f32 lbl_80409104;
extern f32 lbl_80409108;

void fn_800B2E10(void *arg0, f32 farg0)
{
    f32 dx;
    f32 dy;
    f32 x;
    f32 y;
    s32 i;

    dx = lbl_80409104;
    dy = lbl_80409108;
    x = lbl_801A03F0[0] - (2.0f * dx * lbl_801A03EC[0]);
    y = farg0 - (2.0f * dy * lbl_801A03EC[0]);
    for (i = 0; i < 3; i++) {
        NuHGobjRndrMtxDwa(*(s16 *)((s8 *)arg0 + 0xA) == *(s16 *)((s8 *)arg0 + 0xE) && *(s16 *)((s8 *)arg0 + 8) == i, i, x, y);
        x += dx;
        y += dy;
    }
}

s32 fn_80039CB0(s32, s32, s32);
#define fn_800ABF7C ((s32 (*)(s32 *))fn_800ABF7C)
extern f32 lbl_801A55A4[];
extern f32 lbl_801A55A8[];
extern s32 lbl_801DCFC8[];
extern s32 lbl_803D9A58[];

void fn_800D9AB0(void)
{
    f32 zero;
    f32 k;
    s8 *p;
    u8 *g;
    u8 *en;
    s32 *q;
    s32 i;
    s32 on;
    s32 amt;
    s32 dev;

    p = (s8 *)lbl_801DCFC8;
    zero = lbl_801A55A4[0];
    k = lbl_801A55A8[0];
    g = (u8 *)lbl_803E0298;
    en = (u8 *)p - 0x20;
    q = lbl_803D9A58;
    for (i = 0; i < 2; i++) {
        fn_800ABF7C((s32 *)p);
        if (g[4] != 0 && en[i] != 0) {
            dev = *q;
            on = 0;
            if (*(f32 *)(p + 0xC) > zero || *(u8 *)(p + 0x10) != 0) {
                on = 1;
            }
            if (*(f32 *)(p + 4) > zero) {
                amt = (s32)((*(f32 *)(p + 0) * *(f32 *)(p + 4) * k) / *(f32 *)(p + 8));
            } else {
                amt = 0;
            }
            fn_80039CB0(dev, on, amt);
        } else {
            fn_80039CB0(*q, 0, 0);
        }
        q += 23;
        p += 0x14;
    }
}
#undef fn_800ABF7C

extern s32 lbl_801D5AA0[];

void fn_800BA628(s32 arg0) {
    s32 i_var_r31;
    void *var_r31;
    void *var_r30;
    s32 *var_r3;
    s32 temp_r3;

    i_var_r31 = 0;
    do {
        var_r31 = (void *) ((s8 *) (lbl_801D5AA0) + i_var_r31 * 8);
        var_r30 = (void *) ((s8 *) (arg0 + 0x76C) + i_var_r31 * 16);
        var_r3 = (*(s32 **)((s8 *)(var_r31) + (0)));
        if (var_r3 == NULL) {
            var_r3 = arg0 + 0x1C0;
        } else if (var_r3 == (s32 *)-1) {
            var_r3 = arg0 + 0x1C8;
        }
        temp_r3 = *var_r3;
        if (temp_r3 != 0) {
            NuSpecialFind(temp_r3, var_r30, (*(s32 **)((s8 *)(var_r31) + (4))), 1);
        }
        i_var_r31 += 1;
    } while (i_var_r31 <= 286);
}

/* Fields fn_800B00B8 reads and writes (MenuHeader-shaped: fn_800B0120 uses the same
 * 0x138/0x13C pair on MenuHeader). */
struct levels_fade_s {
    u8 pad0[0xE8];
    struct nuvec_s vE8;
    u8 padF4[0x138 - 0xF4];
    f32 f138;
    f32 f13C;
    f32 f140;
    u8 pad144[0x168 - 0x144];
    u16 h168;
    u16 h16A;
    u16 h16C;
    u16 h16E;
    u16 h170;
    u16 h172;
    u8 pad174;
    u8 b175;
    u8 pad176[2];
    u8 b178;
};
extern f32 lbl_801A005C[];

void fn_800B00B8(struct levels_fade_s *o, f32 a, f32 b) {
    f32 zero = lbl_801A005C[0];
    if (a > zero) {
        s8 *p = (s8 *)MenuHeader;
        o->vE8 = *(struct nuvec_s *)(p + 0xF4);
        o->f140 = b;
        o->h168 = o->h16A;
        o->h16C = o->h16E;
        o->h170 = o->h172;
        o->f138 = zero;
        o->f13C = a;
        o->b178 = o->b175;
    }
}

void fn_8002A3A8(void *);

struct levels_ac698_s {
    u8 pad0[0x1CC];
    void *p1CC;
    u8 pad1D0[0x8];
    void *p1D8;
    u8 pad1DC[0x8];
    void *p1E4;
    u8 pad1E8[0x8];
    void *p1F0;
    u8 pad1F4[0x8];
    void *p1FC;
};

void fn_800AC698(struct levels_ac698_s *arg0) {
    if (arg0->p1FC != NULL) {
        fn_8002A3A8(arg0->p1FC);
    }
    arg0->p1FC = NULL;
    if (arg0->p1F0 != NULL) {
        fn_8002A3A8(arg0->p1F0);
    }
    arg0->p1F0 = NULL;
    if (arg0->p1E4 != NULL) {
        fn_8002A3A8(arg0->p1E4);
    }
    arg0->p1E4 = NULL;
    if (arg0->p1D8 != NULL) {
        fn_8002A3A8(arg0->p1D8);
    }
    arg0->p1D8 = NULL;
    if (arg0->p1CC != NULL) {
        fn_8002A3A8(arg0->p1CC);
    }
    arg0->p1CC = NULL;
}

extern f32 lbl_8019FF18[];
extern s32 lbl_80409000;

struct levels_ac7ac_s {
    u8 pad0[0x270];
    f32 x;
    f32 y;
    f32 z;
};

void fn_800AC7AC(void *arg0, struct levels_ac7ac_s *arg1, struct nuvec_s *arg2) {
    arg1->x = arg2->x;
    arg1->y = 0.0f;
    arg1->z = arg2->z;
    if ((fn_8000ED40(arg2->x) > 0.1f) || (fn_8000ED40(arg2->z) > 0.1f)) {
        lbl_80409000 += 1;
    }
    if ((arg1->x == 0.0f) && (arg1->z == 0.0f)) {
        arg1->x = lbl_8019FF18[0];
    }
}

s32 fn_800AAE44(s32);
extern s32 lbl_803E0470[];
extern s32 lbl_8040B044;

void fn_800AC384(void) {
    s32 i;

    lbl_8040B044 = 0;
    NuTimeBar_DefaultColours[lbl_8040B044] = 0xFF;
    for (i = 0; i <= 0x84; i++) {
        if (((u32)lbl_803E0470[i / 32] >> (i & 0x1F)) & 1) {
            fn_800AAE44(i);
        }
    }
    for (lbl_8040B044 = 0; lbl_8040B044 < 0x3F && NuTimeBar_DefaultColours[lbl_8040B044] != 0xFF; lbl_8040B044++) {
    }
}

s32 APILoadCharacterModels(void *, s32, void *, void *, s32);
extern s32 lbl_80408DF4;
extern s32 lbl_8040907C;
extern u8 lbl_8040907F;
extern s32 lbl_80409080;

struct levels_ac85c_s {
    u8 b0;
    u8 b1;
    s16 h2;
};

void fn_800AC85C(void) {
    s32 sp8;
    s32 *p = &sp8;
    struct levels_ac85c_s spC;
    s32 tmp;

    spC.b0 = lbl_8040907F;
    spC.h2 = -0x100;
    spC.b1 = 1;
    lbl_80408DF4 = 1;
    *p = lbl_80408F80;
    APILoadCharacterModels(&spC, 0, &lbl_80408F7C, p, 1);
    tmp = lbl_8040907C;
    lbl_8040907C = -1;
    lbl_80409080 = tmp;
}

void AISysGetCharacterPathPos(void *, void *, void *, s32, s32);
extern const f32 lbl_8019FE9C[];

struct levels_abb94_s {
    u8 pad0[0x2A0];
    u8 path2A0[0xA0];
    s16 h340;
    s16 h342;
    s16 h344;
    u8 pad346[0x66];
    u8 arr3AC[0x18];
    u8 pad3C4[0x14];
    s32 f3D8;
    u8 pad3DC[0x8];
    s32 f3E4;
    s32 f3E8;
    u8 pad3EC[0x1E];
    u8 b40A;
    u8 b40B;
    u8 pad40C[0x34];
    u32 f440;
    u8 pad444[0xC];
    s32 f450;
    u8 pad454[0xAD4];
    u32 bfF28_0 : 26;
    u32 bfF28_26 : 1;
    u32 bfF28_27 : 5;
    s32 fF2C;
    u8 padF30[0x15A];
    u8 b108A;
    u8 b108B;
    f32 f108C;
};

void fn_800ABB94(struct levels_abb94_s *arg0) {
    arg0->f3E4 = 0;
    arg0->f3E8 = 0;
    arg0->h342 = -1;
    arg0->h344 = -1;
    arg0->f3D8 = 0;
    arg0->b108A = 0;
    arg0->b108B = 0;
    arg0->f450 = 0;
    arg0->fF2C = 0;
    arg0->f440 &= ~0x06000000;
    arg0->f108C = lbl_8019FE9C[0];
    arg0->f440 &= ~0x00400000;
    arg0->bfF28_26 = 0;
    memset(arg0->arr3AC, 0, 0x18);
    arg0->b40B = 0;
    arg0->b40A = 0xFF;
    arg0->h340 = -1;
    AISysGetCharacterPathPos(*(void **)((s8 *)lbl_80409410 + 0x2E8), arg0, arg0->path2A0, 0xFF, 1);
}

struct levels_turretmask_s {
    u8 pad0[8];
    u64 mask;
};

void fn_800AB8C8(void) {
    struct levels_turretmask_s *m = *(struct levels_turretmask_s **)((s8 *)lbl_80409410 + 0x1B4);
    if (m != NULL) {
        s8 *p = (s8 *)lbl_80409430;
        s32 i;
        m->mask = 0;
        for (i = 0; i < lbl_8040B058; i++, p += 0x1098) {
            if (*(s32 *)(p + 0x20C) < 0 && (*(s32 *)(p + 0x208) & 0x400) && *(u8 *)(p + 0x40C) == 3) {
                (*(struct levels_turretmask_s **)((s8 *)lbl_80409410 + 0x1B4))->mask |= (1ULL << i);
            }
        }
    }
}

extern const f32 lbl_8019FF84[];
extern void *lbl_804093A8;

void fn_800ACAF8(void *arg0, struct nuvec_s *arg1, struct nuvec_s *arg2) {
    f32 dist[2];
    f32 h;
    f32 t;
    struct nuvec_s *target;
    void *sub;

    h = (*(f32 *)((s8 *)arg0 + 0x1014) + *(f32 *)((s8 *)arg0 + 0x1018))
        * *(f32 *)(*(s8 **)((s8 *)arg0 + 0x64) + 0x38)
        * lbl_8019FF84[0];
    sub = *(void **)((s8 *)arg0 + 0xEEC);
    if (sub != NULL
        && (*(s8 *)((s8 *)arg0 + 0x28F) != 0 || *(u8 *)((s8 *)sub + 0x7D5) != 0)
        && !(*(s32 *)((s8 *)lbl_804093A8 + 4) & 0x20)) {
        if (*(s8 *)((s8 *)arg0 + 0x28F) != 0) {
            *arg1 = *(struct nuvec_s *)((s8 *)arg0 + 0x6C);
        } else {
            *arg1 = *(struct nuvec_s *)((s8 *)arg0 + 0x1D0);
        }
        arg1->y += h;
        return;
    }
    target = NULL;
    arg1->x = *(f32 *)((s8 *)arg0 + 0x6C);
    arg1->y = *(f32 *)((s8 *)arg0 + 0x70) + h;
    arg1->z = *(f32 *)((s8 *)arg0 + 0x74);
    {
        s8 *sub2 = *(s8 **)((s8 *)arg0 + 0xEEC);
        switch (*(s8 *)(sub2 + 0x7DF)) {
        case 9:
            target = (struct nuvec_s *)(*(s8 **)(sub2 + 0x620) + 0x78);
            break;
        case 31: {
            s8 *p = *(s8 **)(sub2 + 0x678);
            if (p != NULL) {
                target = (struct nuvec_s *)(p + 0x90);
            }
            break;
        }
        case 33: {
            s8 *p = *(s8 **)(sub2 + 0x64C);
            if (p != NULL && *(s32 *)(p + 0x128) < 0) {
                target = (struct nuvec_s *)(p + 0x30);
            }
            break;
        }
        }
    }
    if (target != NULL) {
        dist[0] = NuVecDist(arg2, arg1, NULL);
        dist[1] = NuVecDist(arg2, target, NULL);
        t = dist[0] / (dist[0] + dist[1]);
        arg1->x += (target->x - arg1->x) * t;
        arg1->y += (target->y - arg1->y) * t;
        arg1->z += (target->z - arg1->z) * t;
    }
}

s32 NuCameraCalcFrustrumPlanes(void *);
s32 fn_800AA92C(void);
extern f32 lbl_80313268[];
extern f32 lbl_80408FF8;
extern f32 lbl_80408FFC;
extern s32 lbl_8040AFB8;

void fn_800ABDAC(void) {
    f32 old = lbl_80313268[0x54 / 4];

    lbl_80313268[0x54 / 4] = (lbl_8040AFB8 != 0) ? lbl_80408FFC : lbl_80408FF8;
    if (lbl_80313268[0x54 / 4] > old) {
        lbl_80313268[0x54 / 4] = old;
    }
    NuCameraCalcFrustrumPlanes(lbl_80313268);
    fn_800AA92C();
    lbl_80313268[0x54 / 4] = old;
    NuCameraCalcFrustrumPlanes(lbl_80313268);
}

extern const f32 lbl_801A0120[];
extern const f32 lbl_801A0124[];
extern s32 lbl_803DF8DC[];
extern s32 lbl_803DF8E4[];
extern u8 lbl_803E029C[];
extern u8 lbl_803E04B8[];
extern u8 lbl_803E04C0[];
extern u8 lbl_80408A57;
extern f32 lbl_80408A98;
extern s32 lbl_8040AF10;
extern s32 str_Off[];
extern s32 str_On[];

struct levels_menu4_s {
    u8 pad0[0xA];
    s16 hA;
    u8 padC[0x84];
    s32 f90;
    f32 f94;
    u8 pad98[4];
    f32 f9C;
    u8 padA0[8];
    f32 fA8;
};

void Menu_Unknown4_BuildOptions(struct levels_menu4_s *arg0) {
    s32 dirty;
    u8 *flags;

    if (*(s32 *)((s8 *)lbl_80409410 + 0x198) == 0x7C) {
        arg0->f94 = lbl_801A0120[0];
        arg0->f9C = lbl_804090E8 - (arg0->fA8 * lbl_801A0120[0]);
    } else {
        arg0->f94 = lbl_801A0124[0];
    }
    NuStrCpy(lbl_803E04F0, (void *)lbl_803DED88[0xB64 / 4]);
    NuStrCat(lbl_803E04F0, str_On);
    NuStrCat(lbl_803E04F0, lbl_803E04B8[0] != 0 ? (s32 *)lbl_803DED88[0xB48 / 4] : (s32 *)lbl_803DED88[0xB4C / 4]);
    flags = &lbl_80408A57;
    lbl_80408A98 = arg0->f94;
    fn_800769B4(arg0, (s32)lbl_803E04F0, *flags);

    sprintf(lbl_803E04F0, str_Off, (void *)lbl_803DED88[0xD40 / 4], lbl_803E04B8[4], 10);
    lbl_80408A98 = arg0->f94;
    fn_800769B4(arg0, (s32)lbl_803E04F0, *flags);

    NuStrCpy(lbl_803E04F0, (void *)lbl_803DED88[0xB78 / 4]);
    NuStrCat(lbl_803E04F0, str_On);
    NuStrCat(lbl_803E04F0, lbl_803E04B8[5] != 0 ? (s32 *)lbl_803DED88[0xB48 / 4] : (s32 *)lbl_803DED88[0xB4C / 4]);
    lbl_80408A98 = arg0->f94;
    fn_800769B4(arg0, (s32)lbl_803E04F0, lbl_80408A57);

    if (*(s32 *)((s8 *)lbl_80409410 + 0x19C) == 0xD) {
        NuStrCpy(lbl_803E04F0, (void *)lbl_803DED88[0xD8 / 4]);
        NuStrCat(lbl_803E04F0, str_On);
        NuStrCat(lbl_803E04F0, lbl_803E04C0[0] != 0 ? (s32 *)lbl_803DED88[0xB34 / 4] : (s32 *)lbl_803DED88[0xB44 / 4]);
        lbl_80408A98 = arg0->f94;
        fn_800769B4(arg0, (s32)lbl_803E04F0, lbl_80408A57);
    }
    dirty = memcmp(lbl_803E04B8, lbl_803E029C, 0xC) != 0;
    if (arg0->hA == arg0->f90 || !dirty || lbl_8040AF10 == 0) {
        if (dirty) {
            NuStrCpy(lbl_803E04F0, (void *)lbl_803DF8DC[0]);
        } else {
            NuStrCpy(lbl_803E04F0, (void *)lbl_803DF8E4[0]);
        }
    } else {
        *(s8 *)lbl_803E04F0 = 0;
    }
    lbl_80408A98 = arg0->f94;
    fn_800769B4(arg0, (s32)lbl_803E04F0, lbl_80408A57);
}

s32 fn_80059C44(struct nuvec_s *, struct nuvec_s *, f32, void *);
extern struct nuvec_s gCameraState[];
extern f32 lbl_804090D4;

struct levels_skin_p_s {
    u8 pad0[0x90];
    struct nuvec_s pos90;
    u8 pad9C[0x150];
    f32 f1EC;
    f32 f1F0;
    u8 pad1F4[0x18];
    s32 f20C;
    u8 pad210[0x7F];
    u8 b28F;
    u8 pad290[0xC5C];
    void *pEEC;
    u8 padEF0[0x30];
    f32 fF20;
    u8 padF24[4];
    u32 bf_top : 24;
    u32 bf_bit7 : 1;
    u32 bf_bit6 : 1;
    u32 bf_low : 6;
};

struct levels_water_s {
    f32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

void NuPs2CreateSkinNorm(void) {
    struct nuvec_s sp8;
    struct nuvec_s sp18;
    s32 i;

    if (lbl_8040AFB8 == 0 && *(s32 *)((s8 *)lbl_80409410 + 0x198) != 0x31) {
        for (i = 0; i < 2; i++) {
            struct levels_skin_p_s *p = (struct levels_skin_p_s *)gPlayer1Pointer[i];
            if (p != NULL && (p->f20C & 0x01000000)) {
                if (lbl_80408F00 != -0.1f
                    || p->b28F != 0
                    || *(u8 *)((s8 *)p->pEEC + 0x7D5) != 0
                    || *(f32 *)((s8 *)p->pEEC + 0x6F8) > 0.0f
                    || fn_800B2ED4() != -1
                    || *(u8 *)((s8 *)p->pEEC + 0x7DF) == 0x12) {
                    *(u32 *)((s8 *)p + 0xF28) &= ~0xC0;
                    *(f32 *)((s8 *)p + 0xF20) = 0.0f;
                } else {
                    s32 prev = p->bf_bit7;
                    if ((((struct levels_water_s *)NuRndrHackWaterLevel)->fC & 1) == i) {
                        sp8.y = 0.0f;
                        sp8.x = 0.0f;
                        sp8.z = (f32)(s32)fn_800B9ED4() * (1.0f / 65535.0f) * p->f1EC;
                        NuVecRotateX(&sp8, &sp8, (s32)((f32)(s32)fn_800B9ED4() * (1.0f / 65535.0f) * -16384.0f));
                        sp8.y *= p->f1F0 / p->f1EC;
                        NuVecRotateY(&sp8, &sp8, fn_800B9ED4());
                        NuVecAdd(&sp8, &sp8, &p->pos90);
                        NuVecSub(&sp18, &sp8, gCameraState);
                        p->bf_bit7 = fn_80059C44(gCameraState, &sp18, 0.0f, NULL);
                    }
                    if ((s32)p->bf_bit7 == prev) {
                        if (p->fF20 < lbl_804090D4) {
                            p->fF20 += lbl_80408E9C;
                            if (p->fF20 >= lbl_804090D4) {
                                p->fF20 = lbl_804090D4;
                                p->bf_bit6 = p->bf_bit7;
                            }
                        }
                    } else {
                        p->fF20 = 0.0f;
                    }
                }
            }
        }
    }
}

void fn_800AC534(s32 arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    switch (arg0) {
    case 3:
    case 0xF:
    case 0x6D:
    case 0x70:
        *arg1 = 1;
        *arg2 = 0xEC;
        break;
    case 4:
    case 5:
    case 0xD:
    case 0x5B:
    case 0x5C:
    case 0x61:
    case 0x6E:
    case 0x6F:
        *arg1 = 2;
        *arg2 = 0xF0;
        break;
    case 0x75:
        if (arg3 != 0) {
            *arg1 = 1;
            *arg2 = 0xEC;
        } else {
            *arg1 = 2;
            *arg2 = 0xF0;
        }
        break;
    case 6:
    case 8:
    case 0xE:
    case 0x4A:
    case 0x4E:
        *arg1 = 0;
        *arg2 = 0xEE;
        break;
    case 0x23:
    case 0x53:
    case 0x71:
        *arg1 = 3;
        *arg2 = 0xF2;
        break;
    default:
        *arg1 = -1;
        *arg2 = -1;
        break;
    }
}

void fn_8014BD40(void);
extern f32 lbl_801A044C[];
extern f32 lbl_801A0450[];
extern f32 lbl_804094A8;
extern f32 lbl_804094D0;
extern f32 lbl_804094D8;
extern f32 lbl_804094DC;
extern s16 lbl_8040B0D8;
extern s16 lbl_8040B0DA;
extern u8 lbl_8040B0DC;
extern u8 lbl_8040B0DD;

void Menu_Unknown12_BuildOptions(void) {
    f32 opacity;

    if (lbl_8040B0DC == 0) {
        opacity = lbl_804094A8;
    } else {
        opacity = lbl_801A044C[0];
    }
    fn_800D6968(lbl_8040B0D8, -lbl_804094DC, lbl_804094D0, lbl_801A0450[0], 0xC9, lbl_804094D8, opacity, opacity, 1);
    if (lbl_8040B0DD == 0) {
        opacity = lbl_804094A8;
    } else {
        opacity = lbl_801A044C[0];
    }
    fn_800D6968(lbl_8040B0DA, lbl_804094DC, lbl_804094D0, lbl_801A0450[0], 0xC8, lbl_804094D8, opacity, opacity, 1);
    fn_8014BD40();
}

s32 fn_800D6C50(u8, s32, f32, s32, s32, u8, s32, f32, s32, s32);
extern f32 lbl_801A03BC[];
extern f32 lbl_801A03C0[];

void Menu_Unknown13_BuildOptions(void) {
    f32 opacity;

    if (lbl_8040B0DC == 0) {
        opacity = lbl_804094A8;
    } else {
        opacity = lbl_801A03BC[0];
    }
    fn_800D6968(lbl_8040B0D8, -lbl_804094DC, lbl_804094D0, lbl_801A03C0[0], 0xC9, lbl_804094D8, opacity, opacity, 1);
    if (lbl_8040B0DD == 0) {
        opacity = lbl_804094A8;
    } else {
        opacity = lbl_801A03BC[0];
    }
    fn_800D6968(lbl_8040B0DA, lbl_804094DC, lbl_804094D0, lbl_801A03C0[0], 0xC8, lbl_804094D8, opacity, opacity, 1);
    fn_800D6C50(lbl_8040B0DC, -1, lbl_801A03BC[0], -1, 0x2C5, lbl_8040B0DD, -1, lbl_801A03BC[0], -1, 0x2C5);
}

void fn_8006E1EC(void);
extern f32 lbl_801A03D0[];
extern f32 lbl_80409920;
extern f32 lbl_8040B0E4;
extern f32 lbl_8040B0E8;
extern s32 str_Select[];

void Menu_Unknown16_HandleSelection(void *menu) {
    f32 triggerTimer;
    f32 fade;
    f32 timer;
    f32 volume;
    f32 previousTimer;
    f32 progress;

    volume = fn_800B9D44(lbl_803E029C);
    previousTimer = lbl_8040B0E0;
    if (lbl_8040B060[0] != 0) {
        fn_8006DF68(0.0f);
        timer = lbl_8040B0E0 + lbl_80408E9C;
        lbl_8040B0E0 = timer;
        switch (lbl_8040B060[0]) {
        case 1:
            if (previousTimer < 0.1f && timer >= 0.1f) {
                fn_8006E1EC();
            }
            if (lbl_8040B0E0 >= 0.5f) {
                lbl_8040B060[0] = 2;
                fn_8006DCD4(str_Select, 0);
                goto fullProgress;
            } else {
                progress = 2.0f * lbl_8040B0E0;
            }
            break;
        case 2:
            if (timer >= 4.0f) {
                lbl_8040B060[0] = 3;
                lbl_8040B0E0 = 0.0f;
            }
fullProgress:
            progress = lbl_801A03D0[0];
            break;
        default:
            if (lbl_8040B0E0 >= 0.6f) {
                lbl_804093B0 = 0x7B;
                fn_8006DF68(volume);
            }
            progress = 1.0f - 2.0f * lbl_8040B0E0;
            if (progress < 0.0f) {
                progress = 0.0f;
            }
            break;
        }
        lbl_8040B0E4 = NuSinApprox((s32) (progress * 16384.0f));
        return;
    }
    if (lbl_80408F00 == -0.1f) {
        lbl_8040B0E0 = previousTimer + lbl_80408E9C;
    }
    if (lbl_8040B0E8 > 0.0f) {
        triggerTimer = lbl_8040B0E8 + lbl_80408E9C;
        lbl_8040B0E8 = triggerTimer;
        if (triggerTimer >= 1.1f) {
            lbl_8040B0E4 = 0.0f;
            lbl_8040B060[0] = 1;
            lbl_8040B0E0 = 0.0f;
        }
        if (lbl_8040B0E4 > 0.0f) {
            fade = lbl_8040B0E4 - lbl_80408E9C;
            lbl_8040B0E4 = fade;
            if (fade < 0.0f) {
                lbl_8040B0E4 = 0.0f;
            }
        }
    } else if ((*(s32 *)((u8 *)menu + 0x44) & 0x10) || lbl_8040B0E0 >= lbl_80409920) {
        lbl_8040B0E8 = 0.001f;
    }
    fn_8006DF68(volume * lbl_8040B0E4);
}

void Menu_CleanupAndReset(void);
s32 Menu_OpenFromRegistry(f32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 fn_80078FA4(void);
void fn_8007AC0C(void);
s32 fn_800A1B50(s32, s32);
struct MenuPlayerFlags {
    u8 pad0[0x4C];
    u8 flags[2];
};
extern struct MenuPlayerFlags lbl_801DCF5C[];
extern s32 lbl_803D9AB4[];
extern s32 lbl_80408EA8;
extern s32 lbl_80408F98;
extern s32 lbl_804093CC;
extern u8 lbl_8040B02C[];
extern f32 str_ExitDemo[];
extern s32 str_menuBack[];

void fn_800B203C(s32 *input)
{
    s32 *pad;
    s16 frameId;
    s32 newSelection38;
    s32 menuId;
    s32 opened;
    s32 newSelection34;
    s32 input04;
    s32 input08;
    s32 input0C;
    s32 input10;
    s32 combine;
    s32 second;
    s32 first;
    MenuFrame *frame;

    pad = input;
    menuId = fn_800B2ED4();
    if (lbl_80408EA8 == 0) {
        fn_8007AC0C();
    }

    frame = &((MenuFrame *)gMenuStack)[gMenuDepth];
    frameId = frame->id;
    if ((gPlayer1Pointer[0] == 0 ||
         !(*(u32 *)(gPlayer1Pointer[0] + 0x20C) & 0x01000000) ||
         fn_800A1B50(0, 1) == 0 || fn_80078FA4() != 0) &&
        (gPlayerPointers[0] == NULL ||
         !(*(u32 *)((u8 *)gPlayerPointers[0] + 0x20C) & 0x01000000) ||
         fn_800A1B50(1, 1) == 0 || fn_80078FA4() != 0)) {
        combine = 0;
        if (lbl_8040912C != 0 && lbl_80408F98 != -1) {
            pad = (s32 *)((u8 *)lbl_803D9A58 + lbl_80408F98 * 0x5C);
        } else if (lbl_80409410 == NULL ||
                   (menuId != -1 &&
                    (lbl_80409410->unk198 == 0x7C ||
                     (menuId != 0x1B && (lbl_80409410->unk1A8->flags & 0x4000) &&
                      lbl_801DCF5C[0].flags[0] != 0 && lbl_801DCF5C[0].flags[1] != 0))) ||
                   (menuId == 0x1A && lbl_8040B02C[0] != 0 && lbl_8040B02C[1] != 0) ||
                   (lbl_80408FE0 != 0 && lbl_80409410->unk198 == 0x7E) ||
                   (gPlayer1Pointer[0] != 0 &&
                    (*(u32 *)(gPlayer1Pointer[0] + 0x20C) & 0x01000000) &&
                    gPlayer1Pointer[1] != 0 &&
                    (*(u32 *)(gPlayer1Pointer[1] + 0x20C) & 0x01000000))) {
            combine = 1;
        } else if (pad == lbl_803D9A58) {
            if (lbl_80409410->unk1A8->flags & 0x4000) {
                const volatile struct MenuPlayerFlags *flags = lbl_801DCF5C;
                first = flags->flags[0];
                second = flags->flags[1];
            } else if (lbl_80409410->unk198 == 0x7D) {
                const volatile u8 *flags = lbl_8040B02C;
                first = flags[0];
                second = flags[1];
            } else if (gPlayer1Pointer[0] != 0 && gPlayer1Pointer[1] != 0) {
                first = (*(const volatile u32 *)(gPlayer1Pointer[0] + 0x20C) >> 24) & 1;
                second = (*(const volatile u32 *)(gPlayer1Pointer[1] + 0x20C) >> 24) & 1;
            } else {
                second = 0;
                first = 0;
            }

            if (first == 0 && second != 0) {
                pad = lbl_803D9AB4;
            }
        }

        if (lbl_80409410 == NULL ||
            (!(lbl_80408F00 > str_ExitDemo[0]) && lbl_80408EA8 == 0 &&
             lbl_8040913C == -1 && lbl_804093B0 == -1)) {
            if (combine != 0) {
                input04 = lbl_803D9A58[1] | lbl_803D9A58[24];
                input08 = lbl_803D9A58[2] | lbl_803D9A58[25];
                input0C = lbl_803D9A58[3] | lbl_803D9A58[26];
                input10 = lbl_803D9A58[4] | lbl_803D9A58[27];
            } else {
                input04 = pad[1];
                input08 = pad[2];
                input0C = pad[3];
                input10 = pad[4];
            }

            second = *(s32 *)((u8 *)frame + 0x34);
            first = *(s32 *)((u8 *)frame + 0x38);
            opened = Menu_OpenFromRegistry(lbl_80408E9C, input04, input08, input0C, input10,
                                           0x20, 0x10, 0x4000, 0x8000);
            if (*(s32 *)((u8 *)frame + 0x50) == -1) {
                newSelection34 = *(s32 *)((u8 *)frame + 0x34);
                if (newSelection34 != -1) {
                    newSelection38 = *(s32 *)((u8 *)frame + 0x38);
                    if (newSelection38 != -1 && second != -1 && first != -1 &&
                        (newSelection34 != second || newSelection38 != first) &&
                        fn_800B2ED4() == menuId) {
                        fn_8006DCD4(str_menuBack, 0);
                    }
                }
            }
            if (opened == 1 && lbl_8040912C != 0) {
                Menu_CleanupAndReset();
            }
        }

        if (frameId != -1 && lbl_804093B0 != -1) {
            lbl_804093CC = 1;
        }
    }
}

extern s32 gDebugFpsDisplayEnabled;
extern s32 gDebugLevelStreamingEnabled;
extern s32 gDebugLiftPlayerEnabled;
extern s32 gDebugPanelEnabled;
extern s32 gDebugStreamingDisplayEnabled;
extern f32 lbl_80408A84;
extern f32 lbl_80408A94;
extern s32 str_DebugMenu_BuyAllShopCharacters[];
extern s32 str_DebugMenu_CollectAllCharacters[];
extern s32 str_DebugMenu_CollectAllMinikits[];
extern s32 str_DebugMenu_CollectAllSuperkitPieces[];
extern s32 str_DebugMenu_CollectStoryCharacters[];
extern s32 str_DebugMenu_Difficulty[];
extern s32 str_DebugMenu_FpsDisplay[];
extern s32 str_DebugMenu_FreePlay[];
extern s32 str_DebugMenu_GameMode[];
extern s32 str_DebugMenu_GoToDoor[];
extern s32 str_DebugMenu_GoToLevel[];
extern s32 str_DebugMenu_GoToScene[];
extern s32 str_DebugMenu_LevelStreaming[];
extern s32 str_DebugMenu_LiftPlayer[];
extern s32 str_DebugMenu_OpenAllDoors[];
extern s32 str_DebugMenu_OpenAllLevels[];
extern s32 str_DebugMenu_Panel[];
extern s32 str_DebugMenu_Restart[];
extern s32 str_DebugMenu_Story[];
extern s32 str_DebugMenu_StreamingDisplay[];
extern s32 str_DebugMenu_UnlockAllCheats[];
extern s32 str_FPS[];
extern s32 str_Mode[];
extern s32 str_On[];
extern s32 str_Player[];

void DebugMenu_BuildOptions(void *menu)
{
    s32 *modeLabel;
    s32 *panelLabel;
    s32 *liftLabel;
    s32 *fpsLabel;
    s32 *levelStreamingLabel;
    s32 *streamingLabel;
    s32 *optionLabel;
    s32 option;
    f32 menuScale;
    s32 finalFlags;
    s32 finalText;
    u8 *flagsFps;
    u8 *flagsStreaming;
    u8 *itemFlags = &lbl_80408A57;

    *(f32 *)((u8 *)menu + 0x9C) =
        (f32)-(s32)*(s16 *)((u8 *)menu + 0xA) * lbl_80408A84 * *(f32 *)((u8 *)menu + 0x94);
    fn_800769B4(menu, (s32) str_DebugMenu_GoToScene, *itemFlags);
    fn_800769B4(menu, (s32) str_DebugMenu_GoToLevel, *itemFlags);
    fn_800769B4(menu, (s32) str_DebugMenu_GoToDoor, *itemFlags);
    fn_800769B4(menu, (s32) str_DebugMenu_Restart, *itemFlags);
    fn_800769B4(menu, (s32) str_DebugMenu_OpenAllDoors, *itemFlags);

    if (lbl_804091FC != 0) {
        modeLabel = str_DebugMenu_FreePlay;
    } else {
        modeLabel = str_DebugMenu_Story;
    }
    sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_GameMode, modeLabel);
    fn_800769B4(menu, (s32) lbl_803E04F0, lbl_80408A57);

    if (gDebugPanelEnabled != 0) {
        panelLabel = str_Player;
    } else {
        panelLabel = str_FPS;
    }
    sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_Panel, panelLabel);
    fn_800769B4(menu, (s32) lbl_803E04F0, lbl_80408A57);

    /* The single-iteration blocks reproduce ProDG's address and branch placement. */
    do {
        if (gDebugLiftPlayerEnabled != 0) {
            liftLabel = str_FPS;
        } else {
            liftLabel = str_Player;
        }
        sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_LiftPlayer, liftLabel);
        fn_800769B4(menu, (s32) lbl_803E04F0, lbl_80408A57);
    } while (0);

    if (gDebugFpsDisplayEnabled != 0) {
        fpsLabel = str_FPS;
    } else {
        fpsLabel = str_Player;
    }
    sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_FpsDisplay, fpsLabel);
    flagsFps = &lbl_80408A57;
    fn_800769B4(menu, (s32) lbl_803E04F0, *flagsFps);
    fn_800769B4(menu, (s32) str_DebugMenu_Difficulty, *flagsFps);

    do {
        if (gDebugLevelStreamingEnabled != 0) {
            levelStreamingLabel = str_FPS;
        } else {
            levelStreamingLabel = str_Player;
        }
        sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_LevelStreaming, levelStreamingLabel);
        fn_800769B4(menu, (s32) lbl_803E04F0, lbl_80408A57);
    } while (0);

    if (gDebugStreamingDisplayEnabled != 0) {
        streamingLabel = str_FPS;
    } else {
        streamingLabel = str_Player;
    }
    sprintf(lbl_803E04F0, str_Mode, str_DebugMenu_StreamingDisplay, streamingLabel);
    flagsStreaming = &lbl_80408A57;
    fn_800769B4(menu, (s32) lbl_803E04F0, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_OpenAllLevels, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_CollectAllMinikits, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_CollectAllSuperkitPieces, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_CollectStoryCharacters, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_CollectAllCharacters, *flagsStreaming);
    fn_800769B4(menu, (s32) str_DebugMenu_UnlockAllCheats, *flagsStreaming);

    itemFlags = (u8 *)lbl_803DED88;
    NuStrCpy(lbl_803E04F0, *(s32 *)(itemFlags + 0xCE4));
    NuStrCat(lbl_803E04F0, str_On);
    option = DebugMenu_ToggleOption2();
    do {
        switch (option) {
        case 0:
            optionLabel = *(s32 **)(itemFlags + 0xB4C);
            NuStrCat(lbl_803E04F0, optionLabel);
            break;
        case 1:
            optionLabel = *(s32 **)(itemFlags + 0xCE8);
            NuStrCat(lbl_803E04F0, optionLabel);
            break;
        case 2:
            do {
                NuStrCat(lbl_803E04F0, *(s32 **)(itemFlags + 0xCEC));
            } while (0);
            break;
        }
    } while (0);

    itemFlags = &lbl_80408A57;
    finalText = (s32)lbl_803E04F0;
    menuScale = *(const volatile f32 *)((u8 *)menu + 0x94);
    finalFlags = *(const volatile u8 *)itemFlags;
    lbl_80408A94 = menuScale;
    fn_800769B4(menu, finalText, finalFlags);
    fn_800769B4(menu, (s32) str_DebugMenu_BuyAllShopCharacters, *itemFlags);
}

extern s32 str_DebugMenu_DifficultyValue[];
extern s32 str_menuMove[];

void Menu_Unknown11_BuildOptions(void *menu)
{
    s32 difficulty = 1;
    u8 *flags;

    do {
        sprintf(lbl_803E04F0, str_menuMove, str_DebugMenu_DifficultyValue, difficulty);
        difficulty++;
        flags = &lbl_80408A57;
        fn_800769B4(menu, (s32) lbl_803E04F0, *flags);
    } while (difficulty <= 10);
}

extern f32 lbl_801A018C[];
extern f32 lbl_801A0190[];
extern s32 lbl_8040AFA8;
extern s32 lbl_804093C8;

void Menu_Unknown6_HandleSelection(void *menu)
{
    s32 index;
    s32 scene;
    s32 pending;
    s32 players;
    s32 bothPlayers;
    s32 player;

    if (*(s32 *)((u8 *) menu + 0x68) != 0) {
        if (*(s32 *)((u8 *) menu + 0x34) == 0) {
            bothPlayers = 0;
            if (gPlayer1Pointer[0] != 0 &&
                (*(u32 *)(gPlayer1Pointer[0] + 0x20C) & 0x01000000) &&
                gPlayer1Pointer[1] != 0 &&
                (*(u32 *)(gPlayer1Pointer[1] + 0x20C) & 0x01000000)) {
                bothPlayers = 1;
            }
            if (bothPlayers != 0) {
                index = lbl_80408F98 * sizeof(s32);
                players = (s32) gPlayer1Pointer;
                player = *(s32 *)(players + index);
                *(u32 *)(player + 0x20C) &= ~0x01000000u;
                fn_800AB98C((void *) *(s32 *)(players + index));
                if (lbl_8040AFA8 != 2) {
                    fn_800B00B8((struct levels_fade_s *) MenuHeader, lbl_801A018C[0], lbl_801A0190[0]);
                }
                Menu_CleanupAndReset();
            } else {
                if (lbl_80408FE0 != 0) {
                    if (lbl_8040AFF8 == 0) {
                        lbl_8040AFF0 = 1;
                        lbl_8040AFF8 = 1;
                    }
                    SceneSelect_HandleEntry();
                    pending = 1;
                    scene = 0x7C;
                    lbl_804093B0 = scene;
                    lbl_804090E0 = pending;
                } else if (lbl_804093C8 == 0x15) {
                    if (lbl_8040AFF8 == 0) {
                        lbl_8040AFF0 = 1;
                        lbl_8040AFF8 = 1;
                    }
                    SceneSelect_HandleEntry();
                    pending = 1;
                    scene = 0x7C;
                    lbl_804093B0 = scene;
                    lbl_804090E0 = pending;
                } else {
                    if (lbl_8040AFF8 == 0) {
                        lbl_8040AFF0 = 1;
                        lbl_8040AFF8 = 1;
                    }
                    SceneSelect_HandleEntry();
                    pending = 1;
                    scene = 0x7B;
                    lbl_804093B0 = scene;
                    lbl_804090E0 = pending;
                }
            }
            *(s32 *)((u8 *) menu + 0x50) = PauseMenu_HandleEntry1(str_Confirm);
        } else {
            goto cancel;
        }
        return;
    }
    if (*(s32 *)((u8 *) menu + 0x6C) != 0) {
cancel:
        Menu_CloseCurrent();
        *(s32 *)((u8 *) menu + 0x50) = PauseMenu_HandleEntry1(str_Cancel);
    }
}

extern s32 gLegoOptionsMenuEnabled;
extern s32 lbl_803DEE64[];
extern s32 lbl_803DF89C[];
extern s32 lbl_803DF8B8[];
extern s32 lbl_803DFA54[];
extern s32 str_PauseMenu_LegoOptions[];

void PauseMenu_BuildOptions(void *menu)
{
    s32 bothPlayers;
    s32 label;
    s8 *labels = (s8 *) lbl_803DED88;
    u8 *firstFlags = &lbl_80408A57;
    u8 *flags;

    fn_800769B4(menu, *(s32 *)(labels + 0xB08), *firstFlags);
    fn_800769B4(menu, *(s32 *)(labels + 0xB20), *firstFlags);
    flags = firstFlags;
    if (lbl_80408FE0 == 0) {
        fn_800769B4(menu, *(s32 *)(labels + 0xA5C), *flags);
    }
    bothPlayers = 0;
    if (gPlayer1Pointer[0] != 0 &&
        (*(u32 *)(gPlayer1Pointer[0] + 0x20C) & 0x01000000) &&
        gPlayer1Pointer[1] != 0 &&
        (*(u32 *)(gPlayer1Pointer[1] + 0x20C) & 0x01000000)) {
        bothPlayers = 1;
    }
    if (bothPlayers != 0) {
        label = lbl_803DFA54[0];
    } else if (lbl_804093C8 == 0x15) {
        label = lbl_803DF8B8[0];
    } else if (lbl_80408FE0 != 0) {
        label = lbl_803DF89C[0];
    } else {
        label = lbl_803DEE64[0];
    }
    fn_800769B4(menu, label, lbl_80408A57);
    if (gLegoOptionsMenuEnabled != 0 && lbl_80408FE0 == 0) {
        fn_800769B4(menu, (s32) str_PauseMenu_LegoOptions, *flags);
    }
}

void Player_UpdateState(s32, s32);

void PauseMenu_HandleSelection(void *menu)
{
    s32 destination;
    s32 option;
    s32 selection;
    s32 idx;
    s32 remaining;
    s32 bothPlayers;
    s32 nextIndex;
    s32 *players;
    s32 mode;
    s32 confirm;
    s32 player;

    if (*(s32 *)((u8 *) menu + 0x68) != 0) {
        confirm = PauseMenu_HandleEntry1(str_Confirm);
        selection = *(s32 *)((u8 *) menu + 0x34);
        *(s32 *)((u8 *) menu + 0x50) = confirm;
        if (selection == 0) {
            Menu_CleanupAndReset();
            return;
        }
        nextIndex = 2;
        if (selection == 1) {
            destination = 4;
            option = -1;
            goto openMenu;
        }
        if ((mode = lbl_80408FE0) == 0) {
            nextIndex = 3;
            if (selection == 2) {
                destination = 5;
                option = -1;
                goto openMenu;
            }
        }
        idx = *(s32 *)((u8 *) menu + 0x34);
        if (idx == nextIndex++) {
            bothPlayers = 0;
            if (gPlayer1Pointer[0] != 0 &&
                (*(u32 *)(gPlayer1Pointer[0] + 0x20C) & 0x01000000) &&
                gPlayer1Pointer[1] != 0 &&
                (*(u32 *)(gPlayer1Pointer[1] + 0x20C) & 0x01000000)) {
                bothPlayers = 1;
            }
            if (bothPlayers != 0) {
                Player_UpdateState(lbl_80408F98, 1);
                remaining = 8;
                players = gPlayer1Pointer;
                do {
                    player = *players;
                    players += 1;
                    if (player != 0) {
                        *(u32 *)(player + 0xF28) &= ~0x20u;
                    }
                    remaining -= 1;
                } while (remaining != 0);
                return;
            }
            destination = 6;
            option = 1;
openMenu:
            Menu_Open(destination, option, -1);
            return;
        }
        if (gLegoOptionsMenuEnabled != 0 && lbl_80408FE0 == 0 && idx == nextIndex) {
            Menu_Open(7, -1, -1);
        }
    }
}

void Menu_Unknown9_HandleSelection(void *menu)
{
    u8 *state = (u8 *) menu;
    u8 *table = (u8 *) lbl_801DC074;
    u8 *entry;
    u8 *selectedEntry;
    u8 count;
    u16 origin;
    u32 adjusted;
    u32 base;
    s32 row;
    s32 column;
    s32 offset;
    s32 selectedOffset;
    s32 selectedRow;
    s32 selectedColumn;
    s16 value;

    row = *(s16 *)(state + 8) - *(s16 *)(state + 0xC);
    offset = row * 0x68;
    if (*(s32 *)(table + offset) != 0) {
        origin = *(u16 *)(state + 0xE);
        entry = offset + (u8 *) lbl_801DC074;
        count = entry[0x3A];
        column = *(s16 *)(state + 0xA) - (s16) origin;
        if (column >= count) {
            /* Preserve the wide adjustment before the halfword store. */
            adjusted = ((u32) count & 0xFFFFu) | 0x10000u;
            adjusted--;
            *(s16 *)(state + 0xA) = (s16) (origin + adjusted);
        }
    } else {
        column = 0;
    }
    *(s32 *)(state + 0x34) = row;
    *(s32 *)(state + 0x38) = column;

    if (*(s32 *)(state + 0x68) != 0) {
        selectedRow = *(s16 *)(state + 8) - *(s16 *)(state + 0xC);
        base = (u32) lbl_801DC074;
        selectedOffset = selectedRow * 0x68;
        *(s32 *)(state + 0x34) = selectedRow;
        if (*(s32 *)(base + selectedOffset) != 0) {
            selectedEntry = (u8 *)(selectedOffset + base);
            if (selectedEntry[0x3A] != 0) {
                selectedColumn = *(s16 *)(state + 0xA) - (s16) *(u16 *)(state + 0xE);
                *(s32 *)(state + 0x38) = selectedColumn;
                if (selectedColumn < selectedEntry[0x3A]) {
                    value = *(s16 *)(selectedColumn * 2 + *(s32 *)(base + selectedOffset));
                    if (lbl_8040AFF8 == 0) {
                        lbl_8040AFF0 = 1;
                        lbl_8040AFF8 = 1;
                    }
                    SceneSelect_HandleEntry();
                    lbl_804093B0 = value;
                    lbl_804090E0 = 1;
                }
            }
        }
    } else if (*(s32 *)(state + 0x6C) != 0) {
        Menu_CloseCurrent();
    }
}

struct socksys_fx_s;
s32 ParticlesPerFrame(f32, f32);
s32 fn_80095A44(struct socksys_fx_s *, s32, const struct nuvec_s *, s32, const struct nuvec_s *);
extern f32 lbl_801A17A8[];

void BoltDebris(u8 *bolt, struct nuvec_s *positions, s32 index, const struct nuvec_s *direction) {
    struct nuvec_s *position;
    struct nuvec_s *selected;
    u8 *object;
    s32 i;
    s32 effects;
    s32 particleEffects;
    s8 particle;
    s8 effect;

    effect = -1;
    if (bolt[0xE4] == 6) {
        effect = 0x3F;
    } else {
        object = *(u8 **)bolt;
        if (object != NULL) {
            switch (*(s16 *)(object + 0x1074)) {
            case 0x79:
            case 0x39:
                effect = 0x2A;
                break;
            case 0x5D:
                effect = 0x2C;
                break;
            }
        }
    }
    if (bolt[0xE6] == 0x34) {
        effect = 0x34;
    }
    if (effect != -1) {
        effects = lbl_80409410->unk1B8;
        if (index == -1) {
            selected = positions + 1;
        } else {
            selected = &positions[index];
        }
        fn_800958F8(effects, effect, (s32)selected);
        return;
    }

    position = positions;
    i = 0;
    do {
        if (bolt[0xE5] != 0 && index == -1 && i != 1) {
            goto next;
        }
        if (index != -1 && index != i) {
            goto next;
        }
        if (direction != NULL) {
            particleEffects = lbl_80409410->unk1B8;
            particle = (s8)bolt[0xE6];
            fn_80095A44((struct socksys_fx_s *)particleEffects, particle, position,
                        ParticlesPerFrame(lbl_801A17A8[0], lbl_80408E9C), direction);
        } else {
            fn_800958F8(lbl_80409410->unk1B8, (s8)bolt[0xE6], (s32)&positions[i]);
        }
next:
        i++;
        position++;
    } while (i <= 2);
}

struct bolt_hit_flags_s {
    u32 pad0 : 10;
    u32 mode : 2;
    u32 padC : 20;
};

s32 SmashForce(s32, s32, s32, void *, s32);
s32 fn_800C03BC(void *);
s32 fn_8012647C(s16);
void fn_80140504(struct NUTURRET_s *, char *, void *, s32);
char *fn_801408D4(struct NUTURRET_s *, s32);
extern s32 lbl_801A17AC[];
extern f32 lbl_801A17B8[];
extern s32 lbl_804093AC;

void BoltHitPlat(u8 *bolt) {
    void *position;
    u8 *object;
    u8 *owner;
    u8 *rumbleObject;
    char *entry;
    struct NUTURRET_s *turrets;
    s32 controller;
    s32 force;
    u8 *player;
    s32 platform;
    u8 *record;
    s32 count;

    position = bolt + 0x84;
    fn_8006DCD4(lbl_801A17AC, (s32)position);
    object = *(u8 **)bolt;
    if (object != NULL) {
        ((struct bolt_hit_flags_s *)(object + 0xF24))->mode = 2;
        (*(u8 **)bolt)[0x1081] = 0xFF;
    }
    entry = fn_801408D4(lbl_80409410->turrets, *(s16 *)(bolt + 0xE0));
    if (entry != NULL) {
        owner = *(u8 **)bolt;
        turrets = lbl_80409410->turrets;
        if (owner != NULL) {
            controller = (s8)owner[0x284];
        } else {
            controller = -1;
        }
        fn_80140504(turrets, entry, position, controller);
        return;
    }

    force = fn_8012647C(*(s16 *)(bolt + 0xE0));
    if (force != 0) {
        SmashForce(0, force, 1, bolt, -1);
        rumbleObject = *(u8 **)bolt;
        if (rumbleObject != NULL) {
            player = *(u8 **)(rumbleObject + 0xEEC);
            if (player != NULL) {
                NewRumble(**(s32 **)(player + 0x61C), lbl_801A17B8[0]);
            }
        }
    } else {
        count = 0x11F;
        record = &lbl_80409410->pad57C[0x1F0];
        platform = *(s16 *)(bolt + 0xE0);
        do {
            if (*(s32 *)(record + 0xC) == platform) {
                break;
            }
            record += 0x10;
            count--;
        } while (count != 0);
        if (lbl_804093AC == 0x39) {
            fn_800C03BC(bolt);
        }
    }
}

extern u8 lbl_803E029F[];
extern f32 lbl_80408284;
extern f32 lbl_80408288;
extern const f32 lbl_801A165C[];
extern const f32 lbl_801A1660[];
extern const f32 lbl_801A1664[];
extern const f32 lbl_801A1668[];
extern const f32 lbl_801A166C[];
extern const f32 lbl_801A1670[];
extern const f32 lbl_801A1674[];

void DaveSetSoundFadeDist(void) {
    u8 *options;
    u8 *volume;
    f32 divisor;

    if (lbl_80409410 != NULL) {
        options = (u8 *)lbl_803E0298;
        options[6] = 8;
        options[7] = 9;
        switch (lbl_80409410->unk19C) {
        case 3:
            options[6] = 8;
            options[7] = 5;
            lbl_80408284 = lbl_801A165C[0];
            lbl_80408288 = lbl_801A1660[0];
            break;
        case 9:
            options[7] = 9;
            options[6] = 7;
            break;
        case 10:
            lbl_80408284 = lbl_801A1664[0];
            lbl_80408288 = lbl_801A1668[0];
            break;
        case 13:
            options[6] = 8;
            options[7] = 10;
            lbl_80408284 = lbl_801A1664[0];
            lbl_80408288 = lbl_801A166C[0];
            break;
        default:
            lbl_80408284 = lbl_801A1670[0];
            lbl_80408288 = lbl_801A1674[0];
            break;
        }
        if (lbl_80409410->unk1A8->flags & 0x4000) {
            lbl_803E029F[0] = 4;
        }
        divisor = lbl_801A165C[0];
        volume = lbl_803E029C;
        fn_8006DEB0(((f32)(f64)volume[2] / divisor) * ((f32)(f64)volume[4] / divisor));
        fn_8006DF68(((f32)(f64)volume[3] / divisor) * ((f32)(f64)volume[4] / divisor));
    }
}

s32 fn_800272A0(s32 *, s32, f32);
extern f32 lbl_801A1650[];
extern f32 lbl_801A1654[];
extern f32 lbl_801A1658[];

void fn_800B4A88(f32 intensity) {
    struct numtx_s matrix;
    u8 *state;
    u8 *modes;
    u32 index;
    f32 elapsed;
    s32 level;
    s32 i;
    u8 *base;
    s32 *special;

    if (lbl_80408F64 != 0) {
        level = lbl_80409410->unk198;
        if (level == 0x7C) {
            intensity *= lbl_8040B0BC;
        } else if (level == 0x7D && lbl_8040B060[0] == 3) {
            intensity *= lbl_8040B0E4;
        } else if (fn_800B2ED4() == 0x1B) {
            state = (u8 *)lbl_801DCF5C;
            index = state[0x4E];
            modes = state + 0x30;
            if (modes[index] == 0xD) {
                elapsed = *(f32 *)(state + 0x44);
                if (elapsed < lbl_801A1650[0]) {
                    intensity = lbl_801A1654[0] - 2.0f * elapsed;
                } else {
                    intensity = lbl_801A1658[0];
                }
            }
        }
        if (intensity > lbl_801A1658[0]) {
            base = (u8 *)lbl_803E8660;
            for (i = 0; i < 4; i++) {
                special = (s32 *)(i * 0xC + (u32)base);
                if (fn_800130F4(special) != 0) {
                    matrix = *(struct numtx_s *)fn_800133FC(special);
                    fn_800272A0((s32 *)(i * 0xC + (u32)base), (s32)&matrix, intensity);
                }
            }
        }
    }
}

s32 fn_800B2F10(void) {
    s32 depth = gMenuDepth;
    s16 id;

    if (depth <= 1) {
        return -1;
    }

    depth--;
    id = ((MenuFrame *)gMenuStack)[depth].id;
    if (id == -1) {
        return -1;
    }
    return *(s32 *)((s8 *)gRegisteredMenuDefinitions + id * 0x1C);
}


typedef struct {
    s32 word0;
    s32 word1;
    s32 word2;
} MenuResetWords;

typedef struct {
    s32 unk0;
    MenuResetWords saved;
} MenuResetPrefix;

void Menu_Unknown4_Enter(void) {
    if ((u32)fn_800B2F10() - 1U <= 1U) {
        MenuResetPrefix *prefix = (MenuResetPrefix *)lbl_803E0298;

        *(MenuResetWords *)lbl_803E04B8 = prefix->saved;
    }
}

void fn_800AC384(void);
void fn_800E32F8(s32);
extern u8 lbl_801DC9C8[];
extern s32 lbl_80409074[];
extern s32 lbl_8040B100;

void fn_800B43F0(void) {
    MenuResetPrefix *prefix = (MenuResetPrefix *)lbl_803E0298;
    MenuToggle *toggle;
    s32 i;

    *(MenuResetWords *)lbl_803E04B8 = prefix->saved;
    memset(lbl_803E0298, 0, 0x210);
    prefix->saved = *(MenuResetWords *)lbl_803E04B8;
    fn_800E32F8(lbl_8040B100);
    ((u8 *)prefix)[1] = 5;
    ((DMH1Tbl *)prefix)->e[(s8)lbl_801DC9C8[0]].a = 1;
    ((s32 *)prefix)[0x1D8 / sizeof(s32)] |= 0x18;
    fn_800AC384();
    lbl_80409074[0] = 3;
    lbl_80409074[1] = 4;
    i = 10;
    lbl_804093E0 = 0;
    toggle = (MenuToggle *)lbl_801D5994;
    do {
        toggle[i - 1].on = 0;
    } while (--i != 0);
}

void fn_8007BE20(char *, f32, f32, f32, f32, f32, f32, s32, u8, u8, u8);
extern f32 lbl_801A041C[], lbl_801A0420[], lbl_801A0424[], lbl_801A0428[];
extern char *lbl_803DF930[];
extern f32 lbl_80409120;

void Menu_Main_BuildOptions(void) {
    if (NuRndrHackWaterLevel[0] >= lbl_801A041C[0]) {
        f32 scale = lbl_801A0420[0];

        if (NuRndrHackWaterLevel[0] >= scale && NuRndrHackWaterLevel[2] < lbl_801A0424[0]) {
            fn_8007BE20(lbl_803DF930[0], lbl_801A0428[0], lbl_80409120, scale,
                         0.5f, 0.5f, 0.5f, 0, 0xFF, 0xFF, 0xFF);
        }
    }
}

extern f32 lbl_801A0448[];
extern f32 lbl_80408A98;
extern f32 lbl_804090E4;

void Menu_Unknown10_BuildOptions(MenuFrame *menu) {
    f32 height = (f32)(menu->max12 - menu->minE);
    f32 selected = (f32)-menu->selA;
    f32 step = lbl_80408A84;
    f32 scale = lbl_804090E4;
    f32 factor = lbl_801A0448[0];
    s32 i = 0;
    s32 offset;
    struct lbl_80409410_s *level;

    menu->unk94 = scale;
    menu->unkA8 = height * step * scale * factor;
    menu->unk9C = selected * step * scale;
    level = lbl_80409410;
    if (i < level->unk244) {
        offset = 0;
        do {
            s32 text = (s32)((u8 *)level->unk240 + offset);

            lbl_80408A98 = menu->unk94;
            i++;
            offset += sizeof(*level->unk240);
            fn_800769B4(menu, text, lbl_80408A57);
            level = lbl_80409410;
        } while (i < level->unk244);
    }
}

void fn_8007AC80(char *, f32, f32, f32, f32, f32, f32, s32, u8, u8, u8, u8);
extern f32 lbl_801A0364[];
extern f32 lbl_801A0368[];
extern s32 lbl_803DEE68[];
extern s32 lbl_803DF898[];
extern s32 lbl_803DF8A0[];
extern s32 lbl_803DF8A4[];

void Menu_Unknown3_BuildOptions(void *menu) {
    s32 id;
    f32 y;
    f32 scale;
    u8 *flags;
    u8 *text;
    f32 lineHeight;
    f32 yOffset;

    if (lbl_80408FE0 != 0) {
        NuStrCpy(lbl_803E04F0, lbl_803DF8A0[0]);
    } else {
        NuStrCpy(lbl_803E04F0, lbl_803DEE68[0]);
    }
    id = *(s16 *)((u8 *)menu + 0x14);
    if (id != -1) {
        s32 type = *(s32 *)((u8 *)gRegisteredMenuDefinitions + id * 0x1C);
        if (type != 1) {
            if (type == 3) {
                NuStrCpy(lbl_803E04F0, lbl_803DF898[0]);
            } else if (lbl_804093C8 == 0x15) {
                NuStrCpy(lbl_803E04F0, lbl_803DF8A4[0]);
            }
        }
    }
    scale = lbl_801A0364[0];
    lineHeight = lbl_80408A84;
    yOffset = lbl_801A0368[0];
    y = lineHeight * scale + *(f32 *)((u8 *)menu + 0x9C);
    *(f32 *)((u8 *)menu + 0x9C) = y;
    flags = &lbl_80408A57;
    fn_8007AC80((char *)lbl_803E04F0, *(f32 *)((u8 *)menu + 0x98),
        y - lineHeight * yOffset, 1.0f, scale, scale, scale,
        0, 0xFF, 0xBF, 0, *flags);
    text = (u8 *)lbl_803DED88;
    fn_800769B4(menu, *(s32 *)(text + 0xB34), *flags);
    fn_800769B4(menu, *(s32 *)(text + 0xB44), *flags);
}

void fn_8000DCE0(struct numtx_s *, struct nuvec_s *);
s32 NuSpecialFindMultiWC(struct nuhspecial_s *, struct numtx_s *);
extern f32 lbl_801A1614[], lbl_801A1618[];
extern s32 lbl_80409154;
extern void *lbl_8040AFE4;

void fn_800B4974(void) {
    struct numtx_s matrix;
    struct nuvec_s scale;
    struct numtx_s aligned;

    if (lbl_80409154 != 0) {
        struct numtx_s *result;
        f32 value = *(f32 *)(lbl_8040AF5C + 0x4C) * lbl_801A1614[0] * lbl_801A1618[0];
        scale.x = scale.y = scale.z = value;
        fn_8000DCE0(&matrix, &scale);
        result = &matrix;
        matrix._30 = *(f32 *)((u8 *)lbl_8040AFE4 + 0x70);
        matrix._31 = *(f32 *)((u8 *)lbl_8040AFE4 + 0x74);
        matrix._32 = *(f32 *)((u8 *)lbl_8040AFE4 + 0x78);
        if (*(s32 *)((u8 *)lbl_80409410 + 0x774) != 0) {
            if ((u32)result & 8) {
                aligned = matrix;
                result = &aligned;
            }
            NuSpecialFindMultiWC((struct nuhspecial_s *)((u8 *)lbl_80409410 + 0x76C), result);
        }
    }
}

void fn_800B9974(void *arg0) {
    f32 temp_f11;
    f32 var_f13;

    temp_f11 = (*(f32 *)((s8 *)(arg0) + (0)));
    var_f13 = (*(f32 *)((s8 *)(arg0) + (8))) + lbl_80408E9C;
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (temp_f11 + lbl_80408E9C);
    (*(f32 *)((s8 *)(arg0) + (4))) = temp_f11;
    (*(f32 *)((s8 *)(arg0) + (8))) = var_f13;
    if ((var_f13 >= 1.0f)) {
        do {
            var_f13 -= 1.0f;
        } while ((var_f13 >= 1.0f));
        (*(f32 *)((s8 *)(arg0) + (8))) = var_f13;
    }
    (*(s32 *)((s8 *)(arg0) + (0xC))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0xC))) + 1);
}

void fn_80029050(s32, f32);
extern f32 lbl_801A1A04[];

void fn_800BA1AC(f32 farg0)
{
    if (lbl_80408F64 != 0) {
        fn_80029050(lbl_80408F64, farg0 * lbl_801A1A04[0]);
    }
}

f32 NuFmod(f32, f32);
extern f32 lbl_801A19B4[];

void fn_800B9928(f32 *arg0, f32 farg0)
{
    arg0[1] = farg0;
    arg0[0] = farg0;
    arg0[2] = NuFmod(farg0, 1.0f);
    ((s32 *)arg0)[3] = 0;
}

void fn_800B57DC(void);
extern f32 lbl_801A19CC[];
extern f32 lbl_801A19D0[];
extern f32 lbl_80409178;
extern f32 lbl_8040917C;
extern f32 lbl_80409180;
extern f32 lbl_80409184;
extern f32 lbl_80409188;
extern f32 lbl_8040918C;
extern f32 lbl_80409190;

void fn_800B9B6C(void)
{
    lbl_80409178 = lbl_801A19CC[0];
    lbl_80409190 = lbl_801A19D0[0];
    lbl_8040917C = lbl_801A19CC[0];
    lbl_80409180 = lbl_801A19CC[0];
    lbl_80409184 = lbl_801A19CC[0];
    lbl_80409188 = lbl_801A19CC[0];
    lbl_8040918C = lbl_801A19CC[0];
    fn_800B57DC();
}

void fn_80074840(void);
void fn_8010BB08(void);
void fn_8011FCCC(void *);
void fn_8013DB18(void *);
extern f32 lbl_801A19FC[];
extern s32 lbl_80409158;
extern s32 lbl_8040B128;
extern f32 lbl_8040B12C;
extern s32 lbl_8040B130;
extern f32 lbl_8040B134;
extern s32 lbl_8040B138;
extern s32 lbl_8040B13C;
extern s32 lbl_8040B140;

void fn_800B9E4C(s32 arg0)
{
    if (lbl_80409158 != 0 || arg0 == 1) {
        lbl_8040B128 = 1;
        lbl_8040B0C8 = lbl_801A19FC[0];
        lbl_8040B12C = lbl_801A19FC[0];
        fn_8013DB18(lbl_80409410);
        fn_8011FCCC(lbl_80409410);
    }
    lbl_8040B138 = 0;
    lbl_8040B134 = lbl_801A19FC[0];
    lbl_8040B13C = 0;
    lbl_8040B140 = 0;
    lbl_8040B130 = 0;
    fn_8010BB08();
    fn_800BA444();
    fn_80074840();
    fn_800BA2AC();
}

void fn_800135B0(void *);
s32 fn_8005A5F8(void);

typedef struct LevelSpecialSlot {
    s32 unk0[3];
    s32 unkC;
} LevelSpecialSlot;

void fn_800BA6AC(void *arg0)
{
    s32 i;
    LevelSpecialSlot *slots = (LevelSpecialSlot *)((s8 *)arg0 + 0x76C);

    for (i = 0; i < 287; i++) {
        slots[i].unkC = -1;
        if (*(s32 *)((s8 *)arg0 + 0x1C4) != 0 && fn_800130F4((s32 *)&slots[i]) != 0 && ((s32 *)lbl_801D5AA0)[i * 2] == 0) {
            fn_800135B0(&slots[i]);
            slots[i].unkC = fn_8005A5F8();
        }
    }
}

typedef struct LevelTimedEffect {
    s32 unk0;
    s32 unk4;
    void *owner;
    void (*callback)(struct LevelTimedEffect *);
    struct nuvec_s pos;
    f32 unk1C;
    f32 time;
    f32 duration;
    u16 seed;
    s8 unk2A;
    s8 unk2B;
    s32 unk2C;
} LevelTimedEffect;

typedef struct LevelEffectOwner {
    u8 pad0[0x20C];
    u32 active : 1;
    u32 rest : 31;
} LevelEffectOwner;

void fn_800BA390(void)
{
    s32 i;
    LevelTimedEffect *effect = (LevelTimedEffect *)lbl_803EAAA0;

    for (i = 0; i < 4; i++, effect++) {
        if (effect->time < effect->duration) {
            effect->time += lbl_80408E9C;
            if (effect->time >= effect->duration) {
                effect->time = effect->duration;
            } else {
                if (effect->owner != NULL && !((LevelEffectOwner *)effect->owner)->active) {
                    effect->owner = NULL;
                }
                if (effect->callback != NULL) {
                    effect->callback(effect);
                }
            }
        }
    }
}

typedef struct LevelSpecialItem {
    s32 unk0;
    s32 unk4;
    s32 active;
    s32 unkC;
} LevelSpecialItem;

typedef struct LevelSpecialTable {
    u8 pad0[0x76C];
    LevelSpecialItem specials[287];
} LevelSpecialTable;

s32 fn_800BA014(s32 arg0, struct numtx_s *arg1)
{
    struct numtx_s aligned;

    if (arg0 == -1) {
        return 1;
    }
    if (((LevelSpecialTable *)lbl_80409410)->specials[arg0].active != 0) {
        if ((u32)arg1 & 0xF) {
            aligned = *arg1;
            arg1 = &aligned;
        }
        return NuSpecialFindMultiWC((struct nuhspecial_s *)&((LevelSpecialTable *)lbl_80409410)->specials[arg0], arg1);
    }
    return 0;
}

extern s32 lbl_801A1AC0[];
extern f32 lbl_802DA258[];
extern struct numtx_s lbl_803EAF44;

void fn_800BB5A8(void)
{
    NuSpecialFind(lbl_80409410->unk1C0, lbl_803EAD24, lbl_801A1AC0, 1);
    lbl_8040B14C = 1.0f;
    if (fn_800130F4(lbl_803EAD24) != 0) {
        lbl_803EAF44 = *(struct numtx_s *)fn_800133FC(lbl_803EAD24);
        fn_80013200(lbl_803EAD24, 0);
        lbl_802DA258[0] = lbl_803EAF44._30;
        lbl_802DA258[1] = 0.0f;
        lbl_802DA258[2] = lbl_803EAF44._32 - 0.5f;
    }
    lbl_8040B150 = 1.0f;
}

void fn_800BB7CC(void)
{
    struct numtx_s mtx;

    if (fn_800130F4(lbl_803EAD24) != 0 && lbl_8040B14C > 0.0f) {
        mtx = lbl_803EAF44;
        if (NuRndrHackWaterLevel[0] < 3.0f) {
            f32 s = NuSinApprox((s32)((NuRndrHackWaterLevel[0] / 3.0f) * 16384.0f));
            mtx._30 = (lbl_803EAF44._30 - lbl_802DA258[0]) * s + lbl_802DA258[0];
            mtx._31 = (lbl_803EAF44._31 - lbl_802DA258[1]) * s + lbl_802DA258[1];
            mtx._32 = (lbl_803EAF44._32 - lbl_802DA258[2]) * s + lbl_802DA258[2];
        }
        fn_800272A0(lbl_803EAD24, (s32)&mtx,
                    lbl_8040B0BC * lbl_8040B150 * (1.0f - NuCosApprox((s32)(lbl_8040B14C * 16384.0f))));
    }
}

f32 fn_8000CB50(struct nuvec_s *);
s32 fn_800D02E4(void *, void *, void *, f32);

void *fn_800B99D0(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1)
{
    struct nuvec_s dir;
    f32 radSq = farg0 * farg0;
    s8 *obj = (s8 *)lbl_8040AEFC;
    void *best = NULL;
    f32 bestDist = (farg1 > 0.0f) ? farg1 : 100.0f;
    s32 i;

    for (i = 0; i < lbl_80408888; i++, obj += 0x1F4) {
        if (*(s32 *)(obj + 0x128) < 0 &&
            *(s32 *)(obj + 0xD4) != arg0 &&
            (*(s32 *)(obj + 0x104) & arg2) == arg2) {
            f32 dist;
            if (farg1 > 0.0f) {
                dist = fn_8000CD08(obj + 0x30, arg1, NULL);
                if (dist < bestDist) {
                    bestDist = dist;
                    best = obj;
                }
            } else {
                f32 speed = fn_8000CB50((struct nuvec_s *)(obj + 0x80));
                f32 lim;
                NuVecScale(&dir, (struct nuvec_s *)(obj + 0x80), 1.0f / speed);
                lim = speed * 0.5f;
                lim *= lim;
                dist = fn_8000CD08(obj + 0x30, arg1, NULL);
                if (dist < lim &&
                    fn_800D02E4(obj + 0x30, &dir, (void *)arg1, radSq) != 0) {
                    bestDist = dist;
                    best = obj;
                }
            }
        }
    }
    return best;
}

extern s32 lbl_8040AF64;
extern s32 lbl_8040AF94;

void fn_800BB3FC(s32 arg0, s32 arg1, f32 farg0)
{
    s32 triggered;

    switch (*(arg1 + lbl_8040B060)) {
    case 0: {
        s8 *p = (s8 *)fn_800D515C(arg0, 1, 1);
        if (p == NULL || !(*(s32 *)(p + 0xF24) & 2) ||
            (*(u8 *)(p + 0x28F) == 0 && *(u8 *)(p + 0x1085) != 0)) {
            p = NULL;
        }
        if (p != NULL) {
            if (!(farg0 <= 0.0f)) {
                *(arg1 + lbl_8040B060) = 1;
                goto not_triggered;
            }
            goto set_triggered;
        }
        goto not_triggered;
    }
    case 1:
        lbl_8040B0C8 += lbl_80408E9C;
        if (lbl_8040B0C8 >= farg0) {
        set_triggered:
            *(arg1 + lbl_8040B060) = 2;
            triggered = 1;
        } else {
        default:
        not_triggered:
            triggered = 0;
        }
        break;
    }

    if (triggered) {
        lbl_80408F2C = 1;
        lbl_804093B0 = 0x7B;
        if (lbl_80408FE0 == 0 && lbl_80409410->unk1AC != NULL) {
            s8 *hdr = (s8 *)lbl_80409410->unk1AC;
            s32 i = 0;
            s16 found = -1;
            while (i < *(u8 *)(hdr + 0x3A) && found == -1) {
                found = (*(s16 **)hdr)[i];
                if (!(*(s32 *)((s8 *)lbl_801D68E4 + found * 0xA8) & 0x4000)) {
                    found = -1;
                    i++;
                }
            }
            if (found != -1) {
                lbl_804093B0 = found;
            }
        } else {
            lbl_804093B0 = 0x7E;
        }
        if (lbl_8040AF64 != -1) {
            lbl_8040AF94 = 1;
        }
    }
}

extern s32 lbl_801A2208[];
extern u8 lbl_8040A680[4];

void fn_800BE8E8(void) {
    s32 i;
    s32 p;
    s32 *q;
    s32 n;

    n = 4;
    i = 0;
    q = lbl_803EAEC4;
    do {
        if ((*(u16 *)(q[0] + 0x20) & 1) && (*(u16 *)(q[1] + 0x20) & 1) && lbl_8040A680[i] == 1) {
            lbl_8040A680[i] = 0;
        }
        q += 2;
        i++;
    } while (--n != 0);
    i = 0;
    p = (s32)lbl_803EAEC4;
    do {
        if (lbl_8040A680[i] != 0) {
            fn_8006DCD4(lbl_801A2208, fn_800133FC((s32 *)(*(s32 *)p + 4)) + 0x30);
        }
        do { p += 8; } while (0);
        i++;
    } while (p <= (s32)(lbl_803EAEC4 + 7));
}

extern f32 lbl_801A1E84[];
extern f32 lbl_801A1E88[];

void fn_800BCFAC(void) {
    f32 temp_f0;
    s16 *var_r10;
    s16 var_r11;
    s32 var_r8;
    u8 temp_r0;
    u8 temp_r11;
    void *temp_r9;
    struct episode_s *area;
    s32 i;
    s32 n;

    temp_r11 = *lbl_8040B060;
    switch ((s32) temp_r11) {                       /* irregular */
    case 0:
        if (((s32) *lbl_803EAE44 != 0) && ((*(s32 *)((s8 *)(*lbl_803EAE44) + (0x18))) & 0x20)) {
            *lbl_8040B060 = 1;
            lbl_8040B0C8 = lbl_801A1E84[0];
            return;
        }
        return;
    case 1:
        temp_f0 = lbl_8040B0C8 + lbl_80408E9C;
        lbl_8040B0C8 = temp_f0;
        if (temp_f0 >= lbl_801A1E88[0]) {
            *lbl_8040B060 = 2;
            if ((s32) lbl_804091F8 != 0) {
                lbl_80408F2C = (s32) temp_r11;
                lbl_804093B0 = 0x7B;
                if (lbl_80408FE0 == 0 && (area = (struct episode_s *)lbl_80409410->unk1AC) != NULL) {
                    i = 0;
                    n = -1;
                    if (i < area->count) {
                        do {
                            n = area->levels[i];
                            if (!(lbl_801D68E4[n * 0xA8 / 4] & 0x4000)) {
                                n = -1;
                                i++;
                            }
                        } while (i < area->count && n == -1);
                    }
                    if (n != -1) {
                        lbl_804093B0 = n;
                    }
                } else {
                    lbl_804093B0 = 0x7E;
                }
                if ((s32) lbl_8040AF64 != -1) {
                    lbl_8040AF94 = 1;
                    return;
                }
            } else {
                lbl_804093B0 = 0x2A;
                lbl_80408F2C = (s32) temp_r11;
                if ((s32) lbl_8040AF64 != -1) {
                    lbl_8040AF94 = (s32) temp_r11;
                    return;
                }
            }
        }
        break;
    }
}

extern f32 lbl_801A2874[];
extern f32 lbl_801A2878[];
extern s32 lbl_802DA798[];
typedef struct { char pad[0x6304]; s16 a; s16 b; f32 c; } C2F20Tbl;

void fn_800C2F20(void) {
#define t ((C2F20Tbl *)lbl_802DA798)
    struct episode_s *area;
    s32 i;
    s32 n;

    if (t->c < lbl_801A2874[0]) {
        t->c = (f32) (t->c + lbl_80408E9C);
        return;
    }
    if (t->a > 6) {
        if ((s32) lbl_804091F8 == 0) {
            lbl_804093B0 = 0x4A;
            lbl_80408F2C = 1;
            if ((s32) lbl_8040AF64 != -1) {
                lbl_8040AF94 = 1;
            }
        } else {
            lbl_80408F2C = 1;
            lbl_804093B0 = 0x7B;
            if (lbl_80408FE0 == 0 && (area = (struct episode_s *)lbl_80409410->unk1AC) != NULL) {
                i = 0;
                n = -1;
                if (i < area->count) {
                    do {
                        n = area->levels[i];
                        if (!(lbl_801D68E4[n * 0xA8 / 4] & 0x4000)) {
                            n = -1;
                            i++;
                        }
                    } while (i < area->count && n == -1);
                }
                if (n != -1) {
                    lbl_804093B0 = n;
                }
            } else {
                lbl_804093B0 = 0x7E;
            }
            if ((s32) lbl_8040AF64 != -1) {
                lbl_8040AF94 = 1;
            }
        }
    }
    t->c = lbl_801A2878[0];
    t->b = 0;
}
#undef t

extern s32 lbl_801A2318[];
extern s32 lbl_801A2328[];
extern s32 lbl_801A2338[];
extern s32 lbl_801A2344[];
extern f32 lbl_801A2350[];
s32 SetAIMessage(s32, s32 *, s32, f32);
s32 fn_80107A6C(s32, s32);

struct kaminoc_s {
    s32 unk0;
    s32 specialA[16][3];
    s32 specialB[32][3];
    s32 specialC[16][3];
    s32 obstacle304;
    s32 obstacle308;
    u8 unk30C[0x10];
    s8 count;
    u8 unk31D;
    s8 unk31E;
    s8 unk31F;
    f32 unk320;
    s32 msg324;
    s32 msg328;
};
extern struct kaminoc_s lbl_802DA3A0;

void KaminoCReset(void) {
    s32 i;
    u8 *p;

    p = lbl_802DA3A0.unk30C;
    memset(p, 0, 0x10);
    lbl_802DA3A0.unk31D = 0;
    lbl_802DA3A0.unk320 = lbl_801A2350[0];
    lbl_802DA3A0.unk31F = lbl_802DA3A0.unk31E = -1;
    for (i = 0; i < lbl_802DA3A0.count; i++) {
        fn_80013200(lbl_802DA3A0.specialA[i], 1);
        fn_80013200(lbl_802DA3A0.specialB[i], 0);
        fn_80013200(lbl_802DA3A0.specialC[i], 0);
    }
    lbl_802DA3A0.msg324 = SetAIMessage(lbl_80408F58, lbl_801A2318, 0, lbl_801A2350[0]);
    lbl_802DA3A0.msg328 = SetAIMessage(lbl_80408F58, lbl_801A2328, 0, lbl_801A2350[0]);
    lbl_802DA3A0.obstacle304 = FindObstacle((s32)lbl_80409410, lbl_801A2338);
    lbl_802DA3A0.obstacle308 = FindObstacle((s32)lbl_80409410, lbl_801A2344);
    if (lbl_802DA3A0.obstacle304 != 0) {
        fn_80105500(lbl_80409410, *(s8 *)(lbl_802DA3A0.obstacle304 + 0x71), *(s8 *)(lbl_802DA3A0.obstacle304 + 0x72), 0);
        fn_80107A6C(lbl_802DA3A0.obstacle304, 0);
    }
}

extern f32 lbl_801D640C[];
s32 fn_800D515C(s32, s32, s32);
void TriggerObstacle(s32, s8 *);
void fn_800D875C(s32, s32);
s16 fn_800D99AC(void);
void CancelHint(void);
void fn_800D99C8(s32);

void fn_800BC4FC(void) {
    s32 i;
    s32 j;
    s8 *pl;
    s8 *area;
    s8 *other;
    u64 mask;

    for (i = 0; i < 4; i++) {
        if (lbl_803EAE44[i] != 0) {
            for (j = 0; j < 2 && *(u8 *)(lbl_803EAE44[i] + 0x1F) == 0; j++) {
                pl = (s8 *)gPlayer1Pointer[j];
                if (pl != NULL && (*(s32 *)(pl + 0x20C) & 0x01000000) && *(u8 *)(pl + 0x601) == 1 &&
                    *(f32 *)(pl + 0x62C) > lbl_801D640C[i]) {
                    TriggerObstacle(lbl_803EAE44[i], pl);
                }
            }
        }
    }
    if (lbl_804091F8 == 0 && lbl_803EB004[0] != 0) {
        if (*(u8 *)(lbl_803EAE44[0] + 0x1F) == 0) {
            other = (s8 *)fn_800D515C(9, 0, 1);
            if (other != NULL) {
                area = (s8 *)lbl_803EB004[0];
                mask = (u64)1 << *(u8 *)(other + 0x291);
                if (*(u64 *)(area + 0x30) & mask) {
                    fn_800D875C(0x275, 0);
                }
            }
        } else if (fn_800D99AC() == 0x275) {
            CancelHint();
            fn_800D99C8(0x275);
        }
    }
}

extern f32 lbl_801A2734[];
extern f32 lbl_801A2738[];
extern f32 lbl_801A273C[];
extern f32 lbl_801A2740[];
f32 NuFsqrt(f32);
f32 fn_8005A470(struct nuvec_s *, s32, f32, f32);
void fn_8008B4D8(void *, struct nuvec_s *, void *, s32, s32);

/* Circular blocker in the AI system: x, z and radius used. */
struct jedib_blocker_s {
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
    u8 pad10[0x4C - 0x10];
};

struct jedib_locator_s {
    u8 pad0[0x10];
    struct nuvec_s pos;
    s32 id;
    struct {
        void *path;
        void *cnx;
        u8 direction;
        u8 pad9[3];
        u32 next : 16;
        u32 onpath : 1;
        u32 pad : 15;
    } info;
    u8 pad30[0x3C - 0x30];
};

s32 JediBInitLocator(struct nuvec_s *pos, s32 id, struct jedib_locator_s *loc, f32 range) {
    s8 *sys;
    struct jedib_blocker_s *b;
    s32 i;
    s32 n;
    f32 dx;
    f32 dz;
    f32 d2;
    f32 s;
    f32 r;
    f32 y;

    sys = *(s8 **)((s8 *)lbl_80409410 + 0x2E8);
    if (sys != NULL) {
        n = *(s32 *)(sys + 0x1370);
        b = *(struct jedib_blocker_s **)(sys + 0x1374);
        for (i = 0; i < n; i++, b++) {
            if (b->radius != lbl_801A2734[0]) {
                dx = pos->x - b->x;
                dz = pos->z - b->z;
                d2 = dx * dx + dz * dz;
                r = b->radius + lbl_801A2738[0];
                if (d2 < r * r) {
                    s = r / NuFsqrt(d2);
                    dx *= s;
                    dz *= s;
                    pos->x = dx + b->x;
                    pos->z = dz + b->z;
                    break;
                }
            }
        }
    }
    memset(loc, 0, sizeof(*loc));
    if (pos->x * pos->x + pos->z * pos->z < range * range) {
        y = fn_8005A470(pos, 0, lbl_801A2734[0], lbl_801A273C[0]);
        if (y != lbl_801A2740[0]) {
            pos->y = y;
        }
        fn_8008B4D8(*(void **)((s8 *)lbl_80409410 + 0x2E8), pos, &loc->info, 0, 0xFF);
        if (loc->info.onpath) {
            loc->pos = *pos;
            loc->id = id;
            return 1;
        }
    }
    return 0;
}

s32 fn_800C04C4();
extern f32 lbl_801A25B0[];
extern f32 lbl_801A25B4[];
extern u8 lbl_803EACF1[];

typedef struct {
    s8 *p0;
    char pad[0x24];
    s8 *a[4];
    s8 *c;
    s8 *b[4];
} C0EC0Tbl;

void fn_800C0EC0(void) {
#define tb ((C0EC0Tbl *)lbl_802DA6D8)
    f32 t;
    s8 *p;
    s32 ok;
    s32 i;
    s8 *a;
    s8 *b;

    if (lbl_804091F8 != 0) {
        fn_800BB3FC(7, 0, lbl_801A25B0[0]);
    } else {
        t = lbl_801A25B0[0];
        switch (lbl_8040B060[0]) {
        case 0:
            p = (s8 *)fn_800D515C(7, 1, 1);
            if (p == NULL || !(*(s32 *)(p + 0xF24) & 2) || (*(u8 *)(p + 0x28F) == 0 && *(u8 *)(p + 0x1085) != 0)) {
                p = NULL;
            }
            if (p == NULL) {
                goto none;
            }
            if (t <= lbl_801A25B0[0]) {
                goto two;
            }
            lbl_8040B060[0] = 1;
            goto none;
        case 1:
            lbl_8040B0C8 += lbl_80408E9C;
            if (lbl_8040B0C8 >= t) {
                goto two;
            }
            goto none;
        two:
            lbl_8040B060[0] = 2;
            ok = 1;
            break;
        default:
        none:
            ok = 0;
            break;
        }
        if (ok) {
            lbl_80408F2C = 1;
            lbl_804093B0 = 0x3B;
            if (lbl_8040AF64 != -1) {
                lbl_8040AF94 = 1;
            }
        }
    }
    if (*(f32 *)(tb->p0 + 0x28) == lbl_801A25B0[0] && lbl_804091F8 == 0 && lbl_803EACF1[0] != 0) {
        *(f32 *)(tb->p0 + 0x28) = lbl_801A25B4[0];
    }
    fn_800C04C4();
    if (tb->c != NULL && (*(u16 *)(tb->c + 0x6E) & 0xC0) != 0) {
        tb->c = NULL;
    }
    for (i = 0; i < 4; i++) {
        a = tb->a[i];
        if (a != NULL) {
            b = tb->b[i];
            if (b != NULL) {
                if (!(*(u16 *)(a + 0x6E) & 0xC0) && (*(u16 *)(a + 0x6E) & 1) && (*(s32 *)(b + 0x18) & 0x1000)) {
                    *(u16 *)(a + 0x6E) &= ~1;
                }
            }
        }
    }
#undef tb
}

typedef struct {
    char pad[0x28];
    s8 *a[4];
    s8 *sel;
    s8 *b[4];
    char pad2[0x76 - 0x4C];
    s16 id;
} C03BCTbl;

s32 fn_800C03BC(void *arg0) {
#define t ((C03BCTbl *)lbl_802DA6D8)
    s8 **q;
    s32 i;
    s8 *p;

    if (*(s16 *)((s8 *)arg0 + 0xE0) == t->id) {
        for (i = 0; i < 4; i++) {
            p = t->a[i];
            if (p != NULL && t->b[i] != NULL) {
                if ((*(u16 *)(p + 0x6E) & 0xC0) == 0 && ((*(u16 *)(p + 0x6E) & 1) == 0 && t->sel == NULL)) {
                    t->sel = p;
                }
            }
        }
        return 1;
    }
    return 0;
#undef t
}

extern const f32 lbl_801A2868[];
extern f32 lbl_801A286C[];
extern f32 lbl_801A2870[];
extern f32 lbl_802E0B74[];
struct c2d14_ent { char pad[0x5C]; u32 flags; };
struct c2d14_s {
    struct c2d14_ent ents[0x108];
    s16 count;
    s16 unk6302;
    s16 state;
    s16 unk6306;
    f32 timer;
    char pad630C[0x63B0 - 0x630C];
    f32 *unk63B0;
    f32 *unk63B4;
    char pad63B8[0x63D0 - 0x63B8];
    u8 done[6];
    char pad63D6[2];
    s8 *unk63D8;
    f32 unk63DC;
};

void fn_800C2D14(void) {
#define p ((struct c2d14_s *)lbl_802DA798)
    s32 ok;
    s32 i;
    s32 n;
    struct c2d14_ent *e;
    s32 *fl;
    s32 cnt;

    ok = 0;
    p->timer += lbl_80408E9C;
    switch (p->state) {
    case 1:
    case 2:
    case 3:
        p->unk63B4[10] = (f32) p->unk6302;
        if (p->unk63B0[10] == lbl_801A2868[0]) {
            ok = 1;
        }
        break;
    case 4:
    case 5:
    case 6:
        ok = 1;
        for (i = 0; i < 6; i++) {
            if (p->done[i] == 0) {
                ok = 0;
                break;
            }
        }
        p->unk63DC += lbl_80408E9C;
        if (p->unk63DC > lbl_801A286C[0]) {
            cnt = p->count;
            i = 0;
            n = -1;
            if (i < cnt && !(p->ents[0].flags & 0x08000000)) {
                fl = &p->ents[0].flags;
                do {
                    if (*fl & 0x10000000) {
                        n = i;
                    }
                    i++;
                    fl += 0x18;
                    if (i >= cnt) {
                        break;
                    }
                    if (*fl & 0x08000000) {
                        n = -1;
                        break;
                    }
                } while (1);
            }
            if (n != -1) {
                e = &p->ents[n];
                e->flags |= 0x08000000;
            }
            lbl_802E0B74[0] = lbl_801A2870[0];
        }
        break;
    case 7:
        if (p->unk63D8 == NULL && (p->unk63D8 = (s8 *) fn_800D515C(7, 1, 1)) == NULL) {
            break;
        }
        if (p->unk63D8[0x28F] != 0 || p->unk63D8[0x1085] == 0) {
            ok = 1;
        }
        break;
    }
    if (ok) {
        p->timer = lbl_801A2870[0];
        p->unk6306 = 2;
    }
#undef p
}

extern const f32 lbl_801A282C[];
extern const f32 lbl_801A2830[];
f32 fn_8000C038(void);
struct c267c_ent {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    char pad18[0x58 - 0x18];
    s32 unk58;
    u32 flags;
};
struct c267c_s {
    struct c267c_ent ents[0x100];
    struct c267c_ent ents2[8];
    s16 count;
    s16 count2;
    char pad6304[0x63C4 - 0x6304];
    s16 ids[6];
    u8 done[6];
    char pad63D6[0x63DC - 0x63D6];
    f32 unk63DC;
    char pad63E0[0x63E8 - 0x63E0];
    u32 unk63E8;
};

void fn_800C267C(s32 arg0) {
#define p ((struct c267c_s *)lbl_802DA798)
    struct c267c_ent *e;
    s32 c;
    s32 i;
    s32 j;

    c = 0;
    if (arg0 == 0) {
        return;
    }
    for (i = 0; i < p->count2; i++) {
        if (p->ents2[i].unk14 == arg0) {
            p->ents2[i].unk14 = 0;
            for (i = 0; i < p->count2; i++) {
                if (p->ents2[i].unk14 != 0) {
                    c++;
                }
            }
            if (c == 0) {
                p->count2 = c;
            }
            return;
        }
    }
    for (i = 0; i < p->count; i++) {
        if (p->ents[i].unk14 == arg0) {
            for (j = 0; j < 6; j++) {
                if (p->ids[j] == p->ents[i].unk10 && p->done[j] == 0) {
                    p->done[j] = 1;
                    p->unk63DC = lbl_801A282C[0];
                    break;
                }
            }
            e = &p->ents[i];
            e->flags |= 0x80000000;
            p->ents[i].unk14 = 0;
            e->flags &= ~0x18000000;
            if (e == NULL) {
                return;
            }
            if ((e->flags >> 30) & 1) {
                if (lbl_804091F8 == 0) {
                    if ((s32) p->unk63E8 >= 0) {
                        e->unk10 = 0x6D;
                        p->unk63E8 |= 0x80000000;
                        goto done;
                    }
                    if (!(p->unk63E8 & 0x40000000)) {
                        e->unk10 = 0x6E;
                        p->unk63E8 |= 0x40000000;
                        goto done;
                    }
                }
                if (fn_8000C038() < lbl_801A2830[0]) {
                    e->unk10 = 0x41;
                } else {
                    e->unk10 = 0x43;
                }
            } else {
                e->unk10 = 0x75;
            }
done:
            e->unk58 = 0;
            e->flags &= ~0x38000000;
            return;
        }
    }
#undef p
}

extern s32 lbl_801A2B40[];
extern struct nuhspecial_s lbl_802E0BB0;
extern s32 lbl_8040A694;
extern s32 lbl_8040A698;
extern s32 lbl_8040A69C;
extern struct nuinstanim_s *lbl_8040A6A0;

void fn_800C48A4(void) {
    s32 i;
    s32 id;

    for (i = 0; i < ((struct episode_s *)lbl_80409410->unk1AC)->count; i++) {
        id = ((struct episode_s *)lbl_80409410->unk1AC)->levels[i];
        if (id == 0x5B) {
            lbl_8040A698 = i;
        }
        if (id == 0x5C) {
            lbl_8040A69C = i;
        }
    }
    if (NuSpecialFind(lbl_80409410->unk1C0, (s32 *)&lbl_802E0BB0, lbl_801A2B40, 1) != 0) {
        lbl_8040A6A0 = fn_8001384C((s32)&lbl_802E0BB0);
        fn_800135B0(&lbl_802E0BB0);
        lbl_8040A694 = fn_8005A5F8();
    }
    lbl_803EAE44[0] = FindObstacle((s32)lbl_80409410, lbl_801A1EBC);
}

extern f32 lbl_801A2B8C[];
extern f32 lbl_801A2B90[];
DEFINE_INTRO_UPDATE(IntroUpdate_800C4C4C, lbl_801A2B90)

void fn_800C4C4C(void)
{
    if (lbl_804091F8 != 0) {
        fn_800BB20C(0, 0, 2, lbl_801A2B8C[0]);
    } else if (IntroUpdate_800C4C4C(2, lbl_801A2B8C[0])) {
        lbl_80408F2C = 1;
        lbl_804093B0 = 0x5F;
        if (lbl_8040AF64 != -1) {
            lbl_8040AF94 = 1;
        }
    }
}

struct aimessage_s {
    u8 links[8];
    char name[0x20];
    f32 value;
};

f32 *fn_80013380(struct nuhspecial_s *);
void fn_800D3054(s32, s32);
extern s32 lbl_801A2B58[];
extern f32 lbl_801A2B6C[];
extern f32 lbl_801A2B78[];
extern f32 lbl_8040932C;
extern s32 lbl_80409330;
extern f32 lbl_80409334;
extern s32 lbl_80409338;
extern struct aimessage_s *lbl_8040A690;

void fn_800C4A8C(void) {
    s32 i;
    s32 p;
    f32 *sp;

    lbl_80409330 = 0;
    if (fn_800130F4((s32 *)&lbl_802E0BB0) != 0 && lbl_8040A6A0 != NULL && lbl_8040A690 != NULL) {
        lbl_8040A690->value = lbl_801A2B6C[0];
        if (lbl_80409338 >= 0 && lbl_803EAE44[0] != 0 && (*(s32 *)(lbl_803EAE44[0] + 0x18) & 0x1000)) {
            lbl_80409338 = -1;
            lbl_8040A6A0->tfactor = -lbl_8040932C;
            lbl_8040A6A0->flags |= 0x80000000;
        }
        if (lbl_8040A6A0->flags < 0) {
            if (lbl_8040A694 != -1) {
                if ((f32)lbl_80409338 >= lbl_801A2B6C[0]) {
                    lbl_80409330 = 1;
                    lbl_8040A690->value = lbl_801A2B78[0];
                }
                sp = fn_80013380(&lbl_802E0BB0);
                for (i = 0; i < 8; i++) {
                    p = gPlayer1Pointer[i];
                    if (p != 0 && *(u8 *)(p + 0x28F) == 0
                        && (*(s16 *)(p + 0x282) == lbl_8040A694 || *(f32 *)(p + 0x98) > sp[2])) {
                        fn_800D3054(p, 2);
                    }
                }
            }
            if (lbl_8040A6A0->flags < 0) {
                sp = fn_80013380(&lbl_802E0BB0);
                fn_8006DCD4(lbl_801A2B58, (s32)sp);
            }
        }
        lbl_80409334 = lbl_8040A6A0->ltime;
    }
}

struct gameaiscript_level_s {
    u8 unk0[0x1D0];
    u32 beenTo : 1;
    u32 unk1D0 : 31;
    u8 unk1D4[4];
};

extern s32 lbl_801A2B48[];
extern f32 lbl_801A2B54[];
extern struct gameaiscript_level_s lbl_803EB190[];

void fn_800C4978(void) {
    lbl_8040A690 = (struct aimessage_s *)CheckAIMessage(lbl_80408F58, lbl_801A2B48, 0);
    if (fn_800130F4((s32 *)&lbl_802E0BB0) != 0 && lbl_8040A6A0 != NULL) {
        if (!lbl_803EB190[lbl_8040A69C].beenTo) {
            lbl_80409334 = lbl_8040A6A0->ltime = lbl_801A2B54[0];
            lbl_80409338 = 1;
            lbl_8040A6A0->tfactor = lbl_8040932C;
            lbl_8040A6A0->flags |= 0x80000000;
        } else if (lbl_80409338 >= 0) {
            lbl_8040A6A0->ltime = lbl_802E0BB0.scene->instanim_data[lbl_8040A6A0->anim_ix][0];
            lbl_8040A6A0->tfactor = lbl_8040932C;
            lbl_8040A6A0->flags &= 0x7FFFFFFF;
        } else {
            lbl_8040A6A0->tfactor = -lbl_8040932C;
            lbl_8040A6A0->ltime = lbl_80409334;
            lbl_8040A6A0->flags |= 0x80000000;
        }
    }
    lbl_80409330 = 0;
}

void fn_800D963C(s16 *, u8 *, s32);
extern f32 lbl_801A2BE8[];

void fn_800C5174(void) {
    s16 ids[3] = {0x63, 0x63, 0x63};
    u8 flags[3] = {1, 1, 1};
    s32 n;
    s32 m;
    s32 i;

    if (lbl_8040934C != 0 && ((struct aimessage_s *)lbl_8040934C)->value > lbl_801A2BE8[0]) {
        n = ((struct aimessage_s *)lbl_8040934C)->value;
        if (n > 3) {
            n = 3;
        }
        if (lbl_80409350 != 0 && ((struct aimessage_s *)lbl_80409350)->value > lbl_801A2BE8[0]) {
            m = ((struct aimessage_s *)lbl_80409350)->value;
            if (m > 3) {
                m = 3;
            }
            for (i = 0; i < m; i++) {
                flags[i] = 0;
            }
            fn_800D963C(ids, flags, n);
        }
    }
}

struct c38e8_ent {
    char pad0[0x12];
    s16 id;
    s32 obj;
    char pad18[0x60 - 0x18];
};
struct c38e8_s {
    char pad0[0x6000];
    struct c38e8_ent ents[8];
    char pad6300[2];
    s16 count;
    s16 state;
    s16 mode;
    char pad6308[0x63C4 - 0x6308];
    s16 ids[6];
    u8 done[6];
    char pad63D6[2];
    s8 *unk63D8;
};

void fn_800C38E8(void)
{
#define p ((struct c38e8_s *)lbl_802DA798)
    s16 ids[8];
    u8 flags[8] = {0};
    s32 n;
    s32 i;

    if (p->mode == 1) {
        switch (p->state) {
        case 1:
        case 2:
        case 3:
            n = p->count;
            if (n != 0) {
                if (n > 8) {
                    n = 8;
                }
                for (i = 0; i < n; i++) {
                    ids[i] = p->ents[i].id;
                    if (p->ents[i].obj == 0) {
                        flags[i] = 1;
                    }
                }
            } else {
                n = 1;
                if (p->state == 1) {
                    ids[0] = 0x16;
                } else if (p->state == 2) {
                    ids[0] = 0xD;
                } else if (p->state == 3) {
                    ids[0] = 5;
                }
            }
            fn_800D963C(ids, flags, n);
            break;
        case 4:
        case 5:
        case 6:
            fn_800D963C(p->ids, p->done, 6);
            break;
        case 7:
            if (p->unk63D8 != NULL) {
                fn_800D95B8(p->unk63D8);
            }
            break;
        }
    }
#undef p
}

extern f32 lbl_801A2D2C[];
DEFINE_INTRO_UPDATE(IntroUpdate_800C6094, lbl_801A2D2C)

void fn_800C6094(void)
{
    if (lbl_804091F8 != 0) {
        fn_800BB20C(0, 0, 1, lbl_801A2D2C[0]);
    } else if (IntroUpdate_800C6094(1, lbl_801A2D2C[0])) {
        fn_8011E9C4(0x54);
    }
}

void *fn_8008EFD0(f32 *, f32);
void fn_8008F090(void *);
extern f32 lbl_801A2C04[];
extern struct nuhspecial_s lbl_803ED2C0[6];
extern void *lbl_803ED308[6];
extern f32 lbl_80409358;

void fn_800C525C(void)
{
    struct nuinstanim_s *ia;
    s32 i;

    if (lbl_803EAF84[0] == 0 && ((s32 (*)(struct nuhspecial_s *))fn_800130F4)((struct nuhspecial_s *)lbl_803EAD24) != 0) {
        ia = ((struct nuinstanim_s *(*)(struct nuhspecial_s *))fn_8001384C)((struct nuhspecial_s *)lbl_803EAD24);
        if (ia != NULL && ia->flags >= 0 && ia->ltime > lbl_801A2C04[0]) {
            lbl_803EAF84[1] = 1;
            fn_8013F0AC(0);
        }
    }
    for (i = 0; i < 6; i++) {
        if (((s32 (*)(struct nuhspecial_s *))fn_800131B8)(&lbl_803ED2C0[i]) != 0) {
            if (lbl_803ED308[i] == NULL) {
                lbl_803ED308[i] = fn_8008EFD0(fn_80013380(&lbl_803ED2C0[i]), lbl_80409358);
            }
        } else if (lbl_803ED308[i] != NULL) {
            fn_8008F090(lbl_803ED308[i]);
            lbl_803ED308[i] = NULL;
        }
    }
}

/* Kashyyyk_D thrown part: lbl_803ED320[i] are the three live parts, each following
 * special lbl_803EAD24[i] (instance animation lbl_802DA1E8[i]). */
struct forcepart_s {
    struct numtx_s mtx;           /* row 3 is the position */
    u8 pad40[0x80 - 0x40];
    struct nuvec_s vel;
    u8 pad8C[0xFC - 0x8C];
    f32 unkFC;
    u8 pad100[0x128 - 0x100];
    s32 unk128;
};

void fn_80074880(void *, s32);
extern s32 lbl_801A2C6C[];
extern const f32 lbl_801A2C7C[];
extern struct nuvec_s lbl_801D5964;
extern struct nuvec_s lbl_803ED32C[3];

void fn_800C5640(void *arg0)
{
    struct forcepart_s *p = arg0;
    f32 k;
    struct nuinstanim_s *ia;
    s32 i;

    if (arg0 == (void *)lbl_803ED320[0]) {
        i = 0;
    } else if (arg0 == (void *)lbl_803ED320[1]) {
        i = 1;
    } else if (arg0 == (void *)lbl_803ED320[2]) {
        i = 2;
    } else {
        fn_80074880(arg0, 0);
        return;
    }
    lbl_803ED32C[i] = *(struct nuvec_s *)&p->mtx._30;
    p->mtx = *(struct numtx_s *)fn_800133FC(&lbl_803EAD24[i * 3]);
    k = lbl_801A2C7C[0];
    if (p->unkFC < k) {
        p->vel = lbl_801D5964;
    } else {
        NuVecSub(&p->vel, (struct nuvec_s *)&p->mtx._30, &lbl_803ED32C[i]);
        NuVecScale(&p->vel, &p->vel, k / lbl_80408E9C);
    }
    ia = (struct nuinstanim_s *)lbl_802DA1E8[i];
    if (ia->ltime > lbl_801A2C7C[0] && ia->flags >= 0) {
        fn_80074880(arg0, 0);
    }
    if (p->unk128 < 0) {
        fn_8006DCD4(lbl_801A2C6C, (s32)&p->mtx._30);
    }
}

/* Emitter request handed to fn_80120AEC. lbl_803EAD9C is lbl_803EAD24[10]: retail loads
 * the scene word through lbl_803EAD24 + 0x78 and the other two through lbl_803EAD9C. */
struct partemit_entry_s {
    struct nuhspecial_s sp;
    u8 flag;
};

struct partemit_s {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 count;
    u8 unkB;
    s16 sfx;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    struct partemit_entry_s e[61];
    u8 pad3F4[0xC];               /* frame is 0x420: 0x400 bytes of locals */
};

s32 fn_80120AEC(struct partemit_s *, struct nuvec_s *, s32 *);
extern s32 lbl_801A2C80[];
extern f32 lbl_801A2C94[];
extern f32 lbl_801A2C98[];
extern f32 lbl_801A2C9C[];
extern f32 lbl_801A2CA0[];

void fn_800C582C(void *arg0)
{
    struct partemit_s s;
    struct partemit_s *ps = &s;
    struct partemit_entry_s *e;
    s32 idx;
    s32 i;
    s32 p;
    s32 c;

    if (arg0 == (void *)lbl_803ED320[0]) {
        idx = 0;
    } else if (arg0 == (void *)lbl_803ED320[1]) {
        idx = 1;
    } else if (arg0 == (void *)lbl_803ED320[2]) {
        idx = 2;
    } else {
        idx = -1;
    }
    if (idx != -1 && arg0 != NULL) {
        if (fn_800130F4(lbl_803EAD9C) != 0) {
            ps->unk0 = 0;
            ps->unk4 = 0x38;
            ps->unk6 = -1;
            ps->unk8 = 0;
            ps->count = 0xF;
            ps->unkB = 0;
            ps->sfx = PauseMenu_HandleEntry1(lbl_801A2C80);
            ps->unk10 = lbl_801A2C94[0];
            ps->unk14 = lbl_801A2C98[0];
            ps->unk18 = lbl_801A2C9C[0];
            ps->unk1C = lbl_801A2CA0[0];
            ps->unk20 = lbl_801A2C98[0];
            for (i = 0; i < ps->count; i++) {
                e = &ps->e[i];
                *(s32 *)&e->sp.scene = lbl_803EAD24[30];
                *(s32 *)&e->sp.special = lbl_803EAD9C[1];
                *(s32 *)&e->sp.display = lbl_803EAD9C[2];
                e->flag = 0;
            }
            fn_80120AEC(ps, (struct nuvec_s *)((s8 *)arg0 + 0x30), &lbl_803EAD24[idx * 3]);
        }
        fn_800BA244(&lbl_803EAD24[idx * 3]);
        for (i = 0; i < 8; i++) {
            p = gPlayer1Pointer[i];
            if (p != 0) {
                c = *(s32 *)(p + 0xEEC);
                if (*(s32 *)(c + 0x64C) == lbl_803ED320[idx]) {
                    *(s32 *)(c + 0x64C) = 0;
                }
            }
        }
        lbl_803ED320[idx] = 0;
    }
}

/* Part spawn template (gameaiscript.c's gameaiscript_part_s, lbl_801BB478). */
struct levelpart_s {
    void *mtx;
    u32 unk4;
    void *dir;
    u32 unkC;
    u32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    u32 unk20;
    void *special;
    s32 unk28;
    u32 unk2C;
    s32 unk30;
    u32 unk34;
    void (*update)(void *);
    u32 unk3C[2];
    void *collide;
    void (*kill)(void *);
    u32 unk4C[16];
    f32 unk8C;
    u32 unk90[5];
};

s32 fn_80072410(struct levelpart_s *);
extern s32 PartCollide[];
extern struct levelpart_s lbl_801BB478;
extern s32 lbl_801B0F08[];
extern const f32 lbl_801A2CA4[];
extern f32 lbl_80409360;

void fn_800C5A10(s32 i)
{
    struct levelpart_s part;
    s32 o;

    if (fn_800130F4(&lbl_803EAD24[i * 3]) != 0 && lbl_802DA1E8[i] != 0) {
        fn_800BA244(&lbl_803EAD24[i * 3]);
        fn_800BA1E8((s32)&lbl_803EAD24[i * 3]);
        part = lbl_801BB478;
        part.mtx = lbl_801B0F08;
        part.dir = &lbl_801D5964;
        part.unk18 = lbl_80409360;
        part.unk14 = lbl_80409360;
        part.unk1C = lbl_801A2CA4[0];
        part.special = &lbl_803EAD24[i * 3];
        part.unk30 = 0x80861A;
        part.unk28 = 0;
        part.unkC = 0;
        part.update = fn_800C5640;
        part.collide = PartCollide;
        part.kill = fn_800C582C;
        part.unk8C = lbl_80408E9C;
        o = fn_80072410(&part);
        if (o != 0) {
            lbl_803ED320[i] = o;
        }
    }
}

s32 NuStrICmp(char *, char *);
extern void *lbl_8040AE4C;
extern const f32 lbl_801A2E88[];
extern const f32 lbl_801A2E8C[];
extern char lbl_801A2E7C[];

#define LS (&lbl_802E0BE4)

struct levelnames_c67b8_s {
    char *name[10];
};

extern const struct levelnames_c67b8_s lbl_801A2E48;
extern char lbl_801A2E70[];
extern s32 lbl_801A2D3C[];
extern s32 lbl_8040B16C;

void fn_800C67B8(void)
{
    struct levelstate_c6900_s *ls;
    struct levelnames_c67b8_s names;
    s32 i;

    names = lbl_801A2E48;
    ls = &lbl_802E0BE4;
    memset((s32 *)ls, 0, sizeof(*ls));
    ls->unk0 = (void *)CheckAIMessage(lbl_80408F58, (s32 *)lbl_801A2E70, 0);
    ls->unk4 = (void *)AIPathFindLocator(lbl_80409410->unk2E8, lbl_801A2D3C);
    for (i = 0; i < 10; i++) {
        if (NuSpecialFind(lbl_80409410->unk1C0, (s32 *)&ls->unk8[i], (s32 *)names.name[i], 1) != 0) {
            fn_800135B0(&ls->unk8[i]);
            ls->unk80[i] = fn_8005A5F8();
        } else {
            ls->unk80[i] = -1;
        }
    }
    lbl_8040B16C = 0;
}


void fn_800C6900(void)
{
    struct lbl_80409410_240_s *e;
    s32 i;
    s32 j;
    s16 id;
    void *p0;

    if (LS->unk0 != NULL && LS->unk0->unk28 == lbl_801A2E88[0] && LS->unk4 != NULL
        && lbl_80409004 != NULL && *(s16 *)((s8 *)lbl_80409004 + 0x282) != -1) {
        *(struct nuvec_s *)((s8 *)LS->unk4 + 0x10) = *(struct nuvec_s *)((s8 *)lbl_80409004 + 0x1AC);
        p0 = (void *)gPlayer1Pointer[0];
        for (i = 0; i < 10; i++) {
            void *p;
            if (p0 != NULL && LS->unk80[i] != -1 && *(u8 *)((s8 *)p0 + 0x285) != 0
                && *(s16 *)((s8 *)p0 + 0x282) == LS->unk80[i]
                && *(f32 *)((s8 *)p0 + 0x70) >= *(f32 *)((s8 *)*(void **)((s8 *)(*(s32 *)((s8 *)lbl_8040AE4C + 0x68) + *(s16 *)((s8 *)p0 + 0x282) * 0x6C) + 0x40) + 0x34)) {
                LS->unk94 |= 1;
            }
            p = (void *)gPlayer1Pointer[1];
            if (p != NULL && LS->unk80[i] != -1 && *(u8 *)((s8 *)p + 0x285) != 0
                && *(s16 *)((s8 *)p + 0x282) == LS->unk80[i]
                && *(f32 *)((s8 *)p + 0x70) >= *(f32 *)((s8 *)*(void **)((s8 *)(*(s32 *)((s8 *)lbl_8040AE4C + 0x68) + *(s16 *)((s8 *)p + 0x282) * 0x6C) + 0x40) + 0x34)) {
                LS->unk94 |= 2;
            }
        }
        if (lbl_802E0C78[0] == 3) {
            LS->unk0->unk28 = lbl_801A2E8C[0];
            for (j = 0, e = lbl_80409410->unk240; j < lbl_80409410->unk244; j++, e++) {
                if (NuStrICmp((char *)e, lbl_801A2E7C) == 0) {
                    fn_800C9648((s32)e, 1);
                    break;
                }
            }
        }
    }
}

s32 NuSpecialFindMulti(s32, struct nuhspecial_s *, char *, s32, s32);
struct levelflags_s {
    s32 count;
    u32 flags[1];
};

struct levelflags_s *fn_8008A6D4(void *, s32, char *, char *, s32 *);
extern char lbl_801A2D48[];
extern char lbl_801A2D68[];
extern char lbl_801A2D74[];
extern char lbl_801A2D80[];
extern char lbl_801A2D90[];
extern char lbl_801A2D98[];
extern char lbl_801A2DA0[];
extern char lbl_801A2DA8[];
extern char lbl_801A2DB0[];
extern const f32 lbl_801A2DB8[];
extern f32 lbl_801D687C[];

void VaderAStartCollapseStage(void)
{
    struct nuhspecial_s specials[100];
    s32 idx;
    void *loc;
    struct levelflags_s *p;
    s32 o;
    s32 n;
    s32 i;

    loc = (void *)lbl_80409410->unk2E8;
    p = fn_8008A6D4(loc, *(s32 *)(*(s8 **)((s8 *)loc + 0xC) + 8), lbl_801A2D68, lbl_801A2D74, &idx);
    if (p != NULL) {
        u32 *f = p->flags;

        f[idx] |= 0x80000000;
    }
    o = FindObstacle((s32)lbl_80409410, (s32 *)lbl_801A2D80);
    if (o != 0) {
        fn_80105500(lbl_80409410, *(s8 *)(o + 0x71), *(s8 *)(o + 0x72), 0);
        fn_80107A6C(o, 0);
    }
    lbl_802E0BBC[4] = FindForceObject(lbl_80409410, (s32 *)lbl_801A2D90, 0);
    lbl_802E0BBC[5] = FindForceObject(lbl_80409410, (s32 *)lbl_801A2D98, 0);
    lbl_802E0BBC[6] = FindForceObject(lbl_80409410, (s32 *)lbl_801A2DA0, 0);
    lbl_802E0BBC[7] = FindForceObject(lbl_80409410, (s32 *)lbl_801A2DA8, 0);
    *(s16 *)((s8 *)lbl_802E0BBC + 8) = 1;
    *(f32 *)((s8 *)lbl_802E0BBC + 4) = lbl_801D687C[0];
    SetAIMessage(lbl_80408F58, (s32 *)lbl_801A2D48, lbl_802E0BBC[0], lbl_801A2DB8[0]);
    n = NuSpecialFindMulti(lbl_80409410->unk1C0, specials, lbl_801A2DB0, 100, 0);
    for (i = 0; i < n; i++) {
        fn_80013200((s32 *)&specials[i], 0);
    }
}

/* Vader A collapse state at lbl_802E0BBC (VaderAStartCollapseStage, fn_800C6430). */
struct vadera_s {
    s32 msg;
    f32 timer;
    s16 stage;
    s16 hit;
    u8 padC[0x10 - 0xC];
    s32 force[4];
    u8 pad20[0x24 - 0x20];
    s32 surface;
};

#define VA ((struct vadera_s *)lbl_802E0BBC)

s32 SetPlayerOnSurface(void *, s32);
void *NuCameraGetViewMtx(void);
s32 fn_800E6484();
void fn_800B01C4(void *, void *, f32, f32, f32, f32, s32, s32);
extern void *lbl_802E0BDC[];
extern f32 lbl_80409364;
extern char lbl_801A2DBC[];
extern char lbl_801A2DCC[];
extern const f32 lbl_801A2DDC[];
extern const f32 lbl_801A2DE0[];
extern const f32 lbl_801A2DE4[];
extern s32 lbl_801D6888[];
extern s32 lbl_801D6894[];

static inline s32 levels_alldone(s32 *list, s32 n)
{
    s32 o;

    do {
        o = *list++;
        if (o == 0 || (*(u16 *)(o + 0x20) & 0x101) == 0) {
            return 0;
        }
    } while (--n > 0);
    return 1;
}

void fn_800C6430(void)
{
    s32 i;
    s32 o;
    f32 old;
    f32 wait;

    if (VA->surface != 0) {
        VA->surface = 0;
        for (i = 0; i < 8; i++) {
            if (gPlayer1Pointer[i] != 0 && *(s32 *)(gPlayer1Pointer[i] + 0x20C) < 0) {
                SetPlayerOnSurface((void *)gPlayer1Pointer[i], 1);
            }
        }
    }
    if (lbl_802E0BDC[0] != NULL && lbl_80409004 != NULL && *(s16 *)((s8 *)lbl_80409004 + 0x282) != -1) {
        *(struct nuvec_s *)((s8 *)lbl_802E0BDC[0] + 0x10) = *(struct nuvec_s *)((s8 *)lbl_80409004 + 0x1AC);
    }
    if (VA->stage != 0) {
        old = VA->timer;
        VA->timer = old - lbl_80408E9C;
        if (VA->stage <= 2) {
            for (i = 0; i < 4; i++) {
                if (VA->force[i] != 0 && (*(u16 *)(VA->force[i] + 0x20) & 1)) {
                    VA->hit = 1;
                    VA->timer += lbl_80409364;
                    VA->force[i] = 0;
                }
            }
            if (VA->timer < lbl_801D687C[VA->stage]) {
                o = 0;
                switch (VA->stage) {
                case 1:
                    o = FindObstacle((s32)lbl_80409410, (s32 *)lbl_801A2DBC);
                    break;
                do {
                case 2:
                    o = FindObstacle((s32)lbl_80409410, (s32 *)lbl_801A2DCC);
                    VA->timer = lbl_801A2DDC[0];
                    NuCameraGetViewMtx();
                    fn_800B01C4(lbl_801D6888, lbl_801D6894, lbl_801A2DE0[0], lbl_801A2DDC[0], lbl_801A2DE0[0], lbl_801A2DE4[0], 0, 1);
                    break;
                } while (0);
                }
                if (o != 0) {
                    fn_80105500(lbl_80409410, *(s8 *)(o + 0x71), *(s8 *)(o + 0x72), 0);
                    fn_80107A6C(o, 0);
                }
                VA->stage++;
            }
            if (VA->hit != 0 || (VA->timer > lbl_801A2DE0[0] && (s32)old != (s32)VA->timer)) {
                fn_800E6484();
            }
        } else if (VA->timer <= lbl_801A2DE0[0]) {
            fn_800D3054((s32)lbl_80409004, 2);
        }
    }
    wait = lbl_801A2DE0[0];
    switch (lbl_8040B060[0]) {
    case 0:
        if (levels_alldone(lbl_803EAEC4, 2)) {
            {
                s32 *pp = lbl_803EAEC4;

                do {
                    fn_801268CC(*pp);
                    pp++;
                } while ((s32)pp < (s32)&lbl_803EAEC4[2]);
            }
            if (wait <= lbl_801A2DE0[0]) {
                goto set2;
            }
            lbl_8040B060[0] = 1;
        }
        break;
    case 1:
        lbl_8040B0C8 += lbl_80408E9C;
        if (lbl_8040B0C8 >= wait) {
        set2:
            lbl_8040B060[0] = 2;
        }
        break;
    }
}

s32 fn_800CC558(void) {
    s32 ret = 0;

    if (lbl_80409410->unk19C == 7) {
        switch (lbl_80409410->unk198) {
        case 0x36:
            if (lbl_8040AFAC != 0 || (s8)lbl_803E0199[0] == 5 || (s8)lbl_803E0199[0] == 6) {
                ret = 1;
            }
            break;
        case 0x39:
            if (lbl_8040AFAC == 0 && lbl_803E0199[0] != 0x1E) {
                ret = 1;
            }
            break;
        }
    }
    return ret;
}

void fn_800CC450(void) {
    struct episode_s *area;
    s32 i;
    s32 n;

    lbl_80408F2C = 1;
    lbl_804093B0 = 0x7B;
    if (lbl_80408FE0 == 0 && (area = (struct episode_s *)lbl_80409410->unk1AC) != NULL) {
        i = 0;
        n = -1;
        if (i < area->count) {
            do {
                n = area->levels[i];
                if (!(lbl_801D68E4[n * 0xA8 / 4] & 0x4000)) {
                    n = -1;
                    i++;
                }
            } while (i < area->count && n == -1);
        }
        if (n != -1) {
            lbl_804093B0 = n;
        }
    } else {
        lbl_804093B0 = 0x7E;
    }
    if (lbl_8040AF64 != -1) {
        lbl_8040AF94 = 1;
    }
}

struct fn_800CC6FC_ent {
    u8 flag;
    u8 pad1[7];
};
struct fn_800CC6FC_row {
    u8 pad0[4];
    s8 ids[8];
    u8 count;
    u8 pad0D[3];
};
extern struct fn_800CC6FC_row lbl_801DC9C4[];
extern struct fn_800CC6FC_ent lbl_803E03A8[];

s32 fn_800CC6FC(s32 row)
{
    s32 n = 0;
    s32 i = 0;
    struct fn_800CC6FC_row *r = &lbl_801DC9C4[row];
    s32 cnt = r->count;
    s8 *p;

    if (n < cnt) {
        p = lbl_801DC9C4[row].ids;
        do {
            if (lbl_803E03A8[*p++].flag != 0) {
                n++;
            }
            i++;
        } while (i < cnt);
    }
    return n;
}

extern struct fn_800CC6FC_ent lbl_803E03A9[];

s32 fn_800CC764(s32 row)
{
    s32 i = 0;
    struct fn_800CC6FC_row *r = &lbl_801DC9C4[row];
    s32 cnt = r->count - 1;
    s8 *p;

    if (i < cnt) {
        p = lbl_801DC9C4[row].ids;
        do {
            if (lbl_803E03A9[*p++].flag == 0) {
                return 0;
            }
            i++;
        } while (i < cnt);
    }
    return 1;
}

struct fn_800CCA04_ent {
    char name[0x80];
    s16 level;
    u8 pad82;
    u8 flags;
    u8 pad84[0x94 - 0x84];
};
extern s32 NuStrICmp(char *, char *);

void *fn_800CCA04(struct lbl_80409410_s *obj, char *name)
{
    struct fn_800CCA04_ent *e = (struct fn_800CCA04_ent *)obj->unk240;
    s32 i;

    if (e != NULL) {
        for (i = 0; i < obj->unk244; i++, e++) {
            if (NuStrICmp(name, e->name) == 0) {
                return e;
            }
        }
    }
    return NULL;
}

struct fn_800CCA80_area {
    u8 pad0[4];
    u32 flags;
    u8 pad8[0x3C];
    s8 key;
    s8 chapter;
    u8 pad46[0xA8 - 0x46];
};
extern struct fn_800CCA80_area lbl_801D68E0[];

void *fn_800CCA80(struct lbl_80409410_s *obj, s32 key)
{
    struct fn_800CCA04_ent *e = (struct fn_800CCA04_ent *)obj->unk240;
    struct fn_800CCA80_area *a;
    s32 n;
    s32 i;
    if (e == NULL) {
        return NULL;
    }
    for (i = 0; i < obj->unk244; i++, e++) {
        if ((e->flags & 8) || e->level == -1) continue;
        a = &lbl_801D68E0[e->level];
        if (a->key == key) {
            return e;
        }
    }
    return NULL;
}
s16 fn_800CC830(s16 level)
{
    s32 ep = lbl_801D68E0[level].key;
    s32 i = lbl_801D68E0[level].chapter;
    s32 n;
    s16 *p;
    s16 l;
    s32 t;
    struct episode_s *e;

    if (ep != -1) {
        e = (struct episode_s *)((u8 *)lbl_801DC074 + ep * 0x68);
        n = e->count - 1;
        if (i < n) {
            p = (s16 *)(i * 2 + (s32)e->levels);
            do {
                t = *p++;
                ep = t;
                l = ep;
                if (!(lbl_801D68E0[l].flags & 0x1000)) {
                    return l;
                }
                i++;
            } while (i < n);
        }
    }
    return level;
}
