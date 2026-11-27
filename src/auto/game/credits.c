#include "types.h"

extern f32 lbl_8040B240;
extern f32 lbl_8040B244;
extern f32 lbl_8040B248;
extern s32 lbl_8040B0AC;
extern f32 lbl_8040B0B0;
extern f32 lbl_8040B0B4;
extern f32 lbl_8040B0B8;
extern s32 lbl_801DEC0C[];

void fn_8010BBD8(u8* a)
{
    f32 x = *(f32*)(a + 140);
    f32 y = *(f32*)(a + 144);
    f32 z = *(f32*)(a + 148);
    s32 one = 1;
    lbl_8040B0B0 = x;
    lbl_8040B0B4 = y;
    lbl_8040B0B8 = z;
    lbl_8040B240 = x;
    lbl_8040B244 = y;
    lbl_8040B248 = z;
    lbl_8040B0AC = one;
}

void fn_8010BC08(u8* a)
{
    f32 x = *(f32*)(a + 140);
    f32 y = *(f32*)(a + 144);
    f32 z = *(f32*)(a + 148);
    lbl_8040B0B0 = x;
    lbl_8040B0B4 = y;
    lbl_8040B0B8 = z;
}

void fn_8010BD90(void)
{
    s32 v = -1;
    lbl_801DEC0C[1] = v;
    lbl_801DEC0C[2] = v;
    lbl_801DEC0C[3] = v;
    lbl_801DEC0C[4] = v;
    lbl_801DEC0C[5] = v;
    lbl_801DEC0C[6] = v;
    lbl_801DEC0C[7] = v;
    lbl_801DEC0C[0] = v;
}

extern s32 NuStrICmp(const char*, const char*);

u8* fn_80109294(u8* scene, const char* name)
{
    u8* entry;
    s32 i;
    if (scene && (entry = *(u8**)(scene + 0x230))) {
        for (i = 0; i < *(s32*)(scene + 0x234); i++, entry += 0x30) {
            if (NuStrICmp(name, (char*)entry) == 0)
                return entry;
        }
    }
    return 0;
}

void fn_80109314(u8* scene)
{
    u8* entry;
    s32 i;
    u8* selection;
    if (scene && (entry = *(u8**)(scene + 0x230))) {
        for (i = 0; i < *(s32*)(scene + 0x234); i++, entry += 0x30) {
            u8* object = *(u8**)(entry + 0x28);
            selection = scene + 0x250;
            if ((!object || (*(u16*)(object + 0x20) & 0x101)) &&
                (*(s8*)(entry + 0x2d) == -1 ||
                 selection[*(s8*)(entry + 0x2d)] == entry[0x2e]))
                entry[0x2c] = 1;
            else
                entry[0x2c] = 0;
        }
    }
}

u8* FindObstacle(u8* scene, const char* name)
{
    u8* entry = *(u8**)(scene + 0x238);
    s32 i;
    if (entry) {
        for (i = 0; i < *(s32*)(scene + 0x23c); i++) {
            if (NuStrICmp((char*)entry, name) == 0)
                return entry;
            entry += *(u16*)(entry + 0x1c);
        }
    }
    return 0;
}

u8* fn_80109128(u8* scene, const char* name)
{
    u8* entry;
    s32 i;
    if (scene) {
        entry = *(u8**)(scene + 0x248);
        for (i = 0; i < *(s32*)(scene + 0x24c); i++) {
            const char* entry_name = *(const char**)entry;
            if (entry_name && NuStrICmp(name, entry_name) == 0)
                return entry;
            entry += *(u16*)(entry + 4);
        }
    }
    return 0;
}

s32 fn_8010B6FC(u8* table, const char* name)
{
    s32 i;
    if (table) {
        for (i = *(s32*)table; i < *(s32*)(table + 4); i++) {
            u8* entries = *(u8**)(table + 8);
            if (NuStrICmp(name, (char*)(entries + i * 0x14 + 4)) == 0)
                return *(s32*)(*(u8**)(table + 8) + i * 0x14);
        }
    }
    return -1;
}

s32 NuMtxTranslate(s32, s32);
s32 fn_8000DD40(s32, u16);
s32 fn_8000E3C0(s32, u16);
s32 fn_800CFE08(s32, s32, s32);
extern u16 lbl_8040B05C;
extern u16 lbl_8040B120;

void fn_8010B940(s32 arg0, s32 arg1, s32 arg2) {
    fn_800CFE08(arg1, 0, 0);
    fn_8000DD40(arg0, lbl_8040B05C);
    fn_8000E3C0(arg0, lbl_8040B120);
    NuMtxTranslate(arg0, arg2);
}

typedef struct { u8 pad[0x250]; u8 arr[1]; } D250;
u8 fn_80108DA8(D250 *arg0, s32 arg1) { return arg0->arr[arg1]; }

s32 NuFileExists(void *);
s32 fn_8006A6C8(s32 *, s32, s32);
s32 fn_800911D0(void *, void *, s32, s32, s32 *, s32);
int sprintf(void *, void *, ...);
extern s32 lbl_801A9CFC[];
extern s32 lbl_801DE70C[];

void LoadParticleFile(void *arg0) {
    char sp8[0x100];

    (*(s32 *)((s8 *)(arg0) + (0x5E0))) = -1;
    sprintf(sp8, lbl_801A9CFC, arg0 + 0x80);
    if (NuFileExists(sp8) != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x5E0))) = fn_8006A6C8(sp8, 1, (*(s32 *)((s8 *)(arg0) + (0x1C0))));
    }
    (*(s32 *)((s8 *)(arg0) + (0x1B8))) = fn_800911D0(arg0 + 0x184, arg0 + 0x188, 0x100, 0x42, lbl_801DE70C, (*(s32 *)((s8 *)(arg0) + (0x5E0))));
}

void fn_80007610(void *, void *);
void fn_80007680(void *, void *);
s32 memset();

void fn_80108CCC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 != 0)) {
        fn_80007680(arg0 + 0x10, arg1);
        memset(arg1, 0, 0x160);
        fn_80007610(arg0 + 8, arg1);
    }
}

s32 TriggerObstacle(void *, void *);
extern void *lbl_80409410;

void fn_80108DB4(void *arg0, void *arg1) {
    s32 var_r30;
    u8 temp_r0;
    void *var_r31;

    var_r31 = (*(void **)((s8 *)(arg0) + (0x238)));
    if (var_r31 != NULL) {
        var_r30 = 0;
        if (var_r30 < (s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x23C)))) {
            do {
                if (((s32) (*(u8 *)((s8 *)(var_r31) + (0x22))) == 0) && !((*(s32 *)((s8 *)(var_r31) + (0x18))) & 0x20000) && ((s32) (*(u8 *)((s8 *)(var_r31) + (0x1F))) == 0)) {
                    temp_r0 = (*(u8 *)((s8 *)(var_r31) + (0x21)));
                    if (((s8) temp_r0 != -1) && ((s8) (*(u8 *)((s8 *)((*(void **)((s8 *)(arg1) + (0xEEC)))) + (0x7E7))) == (s8) temp_r0)) {
                        TriggerObstacle(var_r31, arg1);
                    }
                }
                var_r30 += 1;
                var_r31 += (*(u16 *)((s8 *)(var_r31) + (0x1C)));
            } while (var_r30 < (s32) (*(s32 *)((s8 *)(lbl_80409410) + (0x23C))));
        }
    }
}

extern s32 lbl_804098E0;
extern s8 lbl_804098E3;
extern s32 lbl_804098E4;
extern s8 lbl_804098E7;
s32 fn_8006497C(s32);
s32 fn_8006638C(s32);
s32 fn_8006AD0C(s8);
s32 fn_80075C78(s8);
s32 fn_80063D9C();
s32 fn_800663D8(s32);
s32 fn_8006AE9C(s8);
s32 fn_80075CD8(s8);

void fn_8010B5F0(void) {
    if (*(s32 *)((u8 *)lbl_80409410 + 0x5E0) != -1) {
        fn_8006AD0C(*(s8 *)((u8 *)lbl_80409410 + 0x5E3));
    }
    if (*(s32 *)((u8 *)lbl_80409410 + 0x5E4) != -1) {
        fn_80075C78(*(s8 *)((u8 *)lbl_80409410 + 0x5E7));
    }
    fn_8006497C(1);
    {
        s32 v = *(s32 *)((u8 *)lbl_80409410 + 0x5E8);
        if (v >= 0) fn_8006638C(v);
    }
}

void fn_8010B660(void) {
    {
        s32 v = *(s32 *)((u8 *)lbl_80409410 + 0x5E8);
        if (v != -1) fn_800663D8(v);
    }
    if (*(s32 *)((u8 *)lbl_80409410 + 0x5E4) != -1) {
        fn_80075CD8(*(s8 *)((u8 *)lbl_80409410 + 0x5E7));
    }
    if (*(s32 *)((u8 *)lbl_80409410 + 0x5E0) != -1) {
        fn_8006AE9C(*(s8 *)((u8 *)lbl_80409410 + 0x5E3));
    }
    if (lbl_804098E4 != -1) fn_8006AE9C(lbl_804098E7);
    if (lbl_804098E0 != -1) fn_8006AE9C(lbl_804098E3);
    fn_80063D9C();
}

s32 fn_80075760(s32 *, s32, s32);
s32 fn_80109550(void *, void *, s32, s32, s32 *, s32);
extern s32 lbl_801A9D04[];
extern s32 lbl_801DEB0C[];

void LoadPARTFile(void *arg0) {
    char sp8[0x100];

    (*(s32 *)((s8 *)(arg0) + (0x5E4))) = -1;
    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x1A8)))) + (4)) & 0x5000) == 0) {
        sprintf(sp8, lbl_801A9D04, arg0 + 0x80);
        if (NuFileExists(sp8) > 0) {
            (*(s32 *)((s8 *)(arg0) + (0x5E4))) = fn_80075760((s32 *)sp8, 1, (*(s32 *)((s8 *)(arg0) + (0x1C0))));
        }
        (*(s32 *)((s8 *)(arg0) + (0x1BC))) = fn_80109550(arg0 + 0x184, arg0 + 0x188, 0x40, 6, lbl_801DEB0C, (*(s32 *)((s8 *)(arg0) + (0x5E4))));
    }
}

s32 NewRumble(s32, f32);
s32 fn_8006DCD4(s32 *, void *);
s32 fn_8009595C(s32, s32, f32, f32, f32);
s32 fn_800AC058(s32, s32);
extern s32 lbl_801AA118[];
extern f32 lbl_801AA144[];

void AddWaterSplash(void *arg0, void *arg1) {
    fn_8009595C((*(s32 *)((s8 *)(lbl_80409410) + (0x1B8))), 0xB, (*(f32 *)((s8 *)(arg1) + (0))), (*(f32 *)((s8 *)(arg0) + (0x224))), (*(f32 *)((s8 *)(arg1) + (8))));
    fn_8006DCD4(lbl_801AA118, arg0 + 0x90);
    NewRumble(*(s32 *)(*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x61C))), lbl_801AA144[0]);
    fn_800AC058(*(s32 *)(*(s32 **)((s8 *)((*(void **)((s8 *)(arg0) + (0xEEC)))) + (0x61C))), 1);
}

s32 fn_800282E4(f32, f32, f32);
extern f32 lbl_801AA154[];

void fn_8010BC24(void) {
    if (lbl_8040B244 > lbl_801AA154[0]) {
        fn_800282E4(lbl_8040B240, lbl_8040B244, lbl_8040B248);
    }
}

s32 fn_80074D14(s32, s32, s32);

void fn_8010B780(void *arg0, s32 arg1, s32 arg2) {
    if ((arg0 != NULL) && (arg1 >= 0) && (arg1 <= 5)) {
        arg1 = *(s32 *)((arg1 * 0x14) + (*(s32 *)((s8 *)(arg0) + (8))));
        if (arg1 != -1) {
            fn_80074D14(arg1, arg2, 1);
        }
    }
}

s32 fn_80013890(s32, void *);
s32 fn_8011FB44(s32);

void fn_801093A4(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 j;
    u8 *e;
    u8 *p;

    if (arg1 != NULL) {
        p = arg1 + 0xA8;
        for (i = 0; i < arg1[0x1E]; i++) {
            u8 *q = arg1 + i * 0x34;
            if ((q[0xD8] & 0x18) == 0) {
                e = *(u8 **)(arg0 + 0x58C);
                for (j = 0; j < *(s32 *)(arg0 + 0x590); j++, e += 0xF4) {
                    if (fn_80013890((s32)(e + 4), p) != 0) {
                        fn_8011FB44((s32)e);
                        break;
                    }
                }
            }
            p += 0x34;
        }
    }
}

s32 fn_800BA2E8(f32 *, void *, s8, s32 *, s32, f32, f32);
s32 fn_800ED36C(void *, f32 *, s32);
extern s32 fn_800B836C[];
extern f32 lbl_801AA148[];
extern f32 lbl_801AA14C[];
extern f32 lbl_801AA150[];

void fn_8010BA24(u8 *arg0) {
    f32 sp8[3];

    fn_800ED36C(arg0, sp8, 0);
    fn_800BA2E8(sp8, arg0, *(u8 *)(*(u8 **)(arg0 + 0xEEC) + 0x7E1), fn_800B836C, 0, lbl_801AA148[0], lbl_801AA14C[0]);
    if ((*(s16 *)(arg0 + 0x1074) == 0xF) && (*(u8 *)(arg0 + 0x287) == 1) && (sp8[1] < *(f32 *)(arg0 + 0x224))) {
        fn_8009595C(*(s32 *)((u8 *)lbl_80409410 + 0x1B8), 0xB, sp8[0], *(f32 *)(arg0 + 0x224), sp8[2]);
        fn_8006DCD4(lbl_801AA118, arg0 + 0x90);
        NewRumble(**(s32 **)(*(u8 **)(arg0 + 0xEEC) + 0x61C), lbl_801AA150[0]);
        fn_800AC058(**(s32 **)(*(u8 **)(arg0 + 0xEEC) + 0x61C), 1);
    }
}

s32 CloseDoorObstacle(s32, void *);

void fn_801091AC(u8 *arg0, char *arg1) {
    s32 i;
    s32 j;
    u8 *e;

    if (arg0 != NULL) {
        e = *(u8 **)(arg0 + 0x248);
        for (i = 0; i < *(s32 *)(arg0 + 0x24C); i++) {
            char *n = *(char **)e;
            if (n != NULL && NuStrICmp(arg1, n) == 0) goto found;
            e += *(u16 *)(e + 4);
        }
    }
    e = NULL;
found:
    if (e != NULL) {
        *(u32 *)(*(u8 **)e + 0x18) &= ~0x20;
        *(u32 *)(*(u8 **)e + 0x18) |= 8;
        CloseDoorObstacle(0, *(void **)e);
        for (j = 0; j < e[6]; j++) {
            *(u32 *)(*(u8 **)(e + 0x14 + j * 4) + 0x18) &= ~0x20;
        }
    }
}

s32 fn_80105DEC(void *, s32);

void fn_80109458(u8 *arg0) {
    u8 *e;
    u8 *s;
    u8 *q;
    s32 k;
    s32 i;
    u8 *p;
    s32 j;

    s = *(u8 **)(arg0 + 0x238);
    if (s != NULL) {
        for (k = 0; k < *(s32 *)(arg0 + 0x23C); k++) {
            fn_80105DEC(s, 0);
            if (s != NULL) {
                p = s + 0xA8;
                for (i = 0; i < s[0x1E]; i++) {
                    q = s + i * 0x34;
                    if ((q[0xD8] & 0x18) == 0) {
                        e = *(u8 **)(arg0 + 0x58C);
                        for (j = 0; j < *(s32 *)(arg0 + 0x590); j++, e += 0xF4) {
                            if (fn_80013890((s32)(e + 4), p) != 0) {
                                fn_8011FB44((s32)e);
                                break;
                            }
                        }
                    }
                    p += 0x34;
                }
            }
            s += *(u16 *)(s + 0x1C);
        }
    }
}

s32 fn_80107BFC(void *, void *, s32);
extern s32 lbl_8040B18C;

void DebugMenu_HandleEntry3(u8 *arg0) {
    s32 i;
    s32 j;
    s32 c;
    s32 n;
    s32 flag;
    u8 *s;
    u8 *q;

    s = *(u8 **)(arg0 + 0x238);
    if (s != NULL) {
        for (i = 0; i < *(s32 *)((u8 *)lbl_80409410 + 0x23C); i++) {
            flag = 0;
            if (s[0x22] == 2) {
                if ((s8)s[0x31] == -1) {
                    n = 0;
                    c = s[0x1E];
                    for (j = 0; j < c; j++) {
                        q = s + 0xAC + j * 0x34;
                        if ((q[0x2C] & 8) && *(s32 *)q != 0) {
                            n++;
                        }
                    }
                    if (n > 0) {
                        flag = 1;
                    }
                } else {
                    flag = 1;
                }
            }
            if (flag != 0) {
                fn_80107BFC(arg0, s, 0);
            }
            s += *(u16 *)(s + 0x1C);
        }
    }
    if (lbl_8040B18C != 2) {
        lbl_8040B18C = 1;
    }
}

s32 PlayFootStepSfx();
extern f32 lbl_801AA128[];

void fn_8010B35C(u8 *arg0) {
    f32 a;
    f32 b;
    f32 f;
    f32 *p;
    s32 i;
    s32 hit;

    if (arg0[0x45] == 0) {
        s16 idx = *(s16 *)(arg0 + 0x4A);
        if (idx != -1) {
            u8 *t = *(u8 **)(arg0 + 0x60);
            if (((s32 *)*(u8 **)(t + 0xC))[idx] != 0) {
                p = (f32 *)((s32 *)*(u8 **)(t + 8))[idx];
                if (*(u16 *)((u8 *)p + 8) & 0x100) {
                    b = *(f32 *)(arg0 + 0xC);
                    a = *(f32 *)(arg0 + 8);
                    if (a != b) {
                        p += 9;
                        hit = 0;
                        i = 0;
                        for (; i < 4; p++, i++) {
                            if (i > 1 || *(s16 *)(arg0 + 0x1074) == 2 || *(s16 *)(arg0 + 0x1074) == 0x3F || *(s16 *)(arg0 + 0x1074) == 0x41 || *(s16 *)(arg0 + 0x1074) == 0x40) {
                                f = *p;
                                if (f >= lbl_801AA128[0]) {
                                    if (a >= f) {
                                        if (b > a) {
                                            hit = 1;
                                        } else if (b < f) {
                                            hit = 1;
                                        }
                                    } else if (b > a) {
                                        if (b < f) {
                                            hit = 1;
                                        }
                                    }
                                }
                            }
                        }
                        if (hit != 0) {
                            PlayFootStepSfx();
                        }
                    }
                }
            }
        }
    }
}

extern f32 lbl_801AA0E4[];
extern void *lbl_8040A738;
extern void *lbl_8040A740;
extern void *lbl_8040A744;
void fn_8010AB90(f32 dt) {
    f32 *zp;
    u8 *p;
    u8 *c;
    u8 *nx;
    u8 *fr;
    u8 *t;
    if (dt == lbl_801AA0E4[0]) {
        return;
    }
    for (p = lbl_8040A744; p != NULL; p = nx) {
        zp = lbl_801AA0E4;
        nx = *(u8 **)p;
        if (*(u8 **)(p + 0x10) == NULL) {
            u8 **o = *(u8 ***)(p + 0x14);
            if (o != NULL && *o == p) {
                *o = NULL;
                *(u8 **)(p + 0x14) = NULL;
            }
        }
        c = *(u8 **)(p + 8);
        *(u8 **)(p + 0x10) = NULL;
        if (c != NULL) {
            f32 zero = *zp;
            fr = lbl_8040A738;
            do {
                f32 v = *(f32 *)(c + 0xE4) - dt;
                *(f32 *)(c + 0xE4) = v;
                if (v <= zero && *(u8 **)c == NULL) {
                    t = *(u8 **)(c + 4);
                    if (t != NULL) {
                        *(u8 **)t = NULL;
                    } else {
                        *(u8 **)(p + 8) = NULL;
                    }
                    t = *(u8 **)c;
                    if (t != NULL) {
                        *(u8 **)(t + 4) = *(u8 **)(c + 4);
                    }
                    *(u8 **)c = fr;
                    fr = c;
                    break;
                }
                c = *(u8 **)c;
            } while (c != NULL);
            lbl_8040A738 = fr;
        }
        if (*(u8 **)(p + 8) == NULL) {
            t = *(u8 **)(p + 4);
            if (t != NULL) {
                *(u8 **)t = *(u8 **)p;
            } else {
                lbl_8040A744 = *(u8 **)p;
            }
            t = *(u8 **)p;
            if (t != NULL) {
                *(u8 **)(t + 4) = *(u8 **)(p + 4);
            }
            *(u8 **)p = lbl_8040A740;
            lbl_8040A740 = p;
        }
    }
}

s32 ObjHitObj(s32, void *, s32);
s32 fn_80063A58(s32 *, f32);
s32 fn_80064A94(void *, f32, f32);
s32 fn_80064B40(void *, f32, f32);
extern s32 gCameraState[];
extern u8 *gPlayer1Pointer[];
extern f32 lbl_801A9D0C[];
extern f32 lbl_801A9D10[];
void fn_80109720(void) {
    s32 i;
    fn_80063A58(gCameraState, lbl_801A9D0C[0]);
    for (i = 0; i < 8; i++) {
        u8 *t = gPlayer1Pointer[i];
        if (t != NULL && *(u8 *)(t + 0x28F) == 0) {
            if (*(f32 *)(t + 0x1044) <= lbl_801A9D10[0] && !(*(f32 *)(t + 0x102C) > lbl_801A9D10[0]) && !(*(s32 *)(t + 0xF28) & 0x10)) {
                void *q = t + 0x90;
                if (fn_80064B40(q, *(f32 *)(t + 0xBC), *(f32 *)(t + 0x1030)) != -1) {
                    ObjHitObj(0, t, 1);
                }
                if (fn_80064A94(q, *(f32 *)(t + 0xBC), *(f32 *)(t + 0x1030)) != -1) {
                    ObjHitObj(0, t, 1);
                }
            }
        }
    }
}

s32 NuStrCpy(void *, void *);
s32 fn_80074C00(void *, s32);
typedef struct PartDef { char name[0x28]; s8 enabled; u8 pad[0x87]; } PartDef;
extern PartDef lbl_803D5680[];

typedef struct PartName { s32 id; char name[0x10]; } PartName;
typedef struct PartTable { s32 n; s32 total; PartName *items; } PartTable;

s32 fn_80109550(void *heap, void *end, s32 total, s32 n, s32 *names, s32 arg5) {
    PartTable *t;
    s32 i;
    PartDef *p;

    t = (PartTable *)((*(s32 *)heap + 0xF) & ~0xF);
    *(s32 *)heap = (s32)(t + 1);
    if (t != 0) {
        memset(t, 0, sizeof(PartTable));
        t->n = n;
        t->total = total;
        t->items = (PartName *)((*(s32 *)heap + 0xF) & ~0xF);
        *(s32 *)heap = ((*(s32 *)heap + 0xF) & ~0xF) + total * sizeof(PartName);
        if (t->items != 0) {
            i = 0;
            memset(t->items, -1, total * sizeof(PartName));
            for (; i < t->n; i++) {
                NuStrCpy(t->items[i].name, (void *)names[i]);
                t->items[i].id = -1;
                t->items[i].id = fn_80074C00(t->items[i].name, arg5);
            }
            if (i < t->total) {
                p = lbl_803D5680;
                do {
                    t->items[i].id = -1;
                    if (p->enabled > 0) {
                        NuStrCpy(t->items[i].name, p->name);
                        t->items[i].id = fn_80074C00(t->items[i].name, arg5);
                        i++;
                    }
                    p++;
                    if (i >= t->total) break;
                } while ((s32)p <= (s32)&lbl_803D5680[63]);
            }
            for (; i < t->total; i++)
                t->items[i].id = -1;
            return (s32)t;
        }
    }
    return 0;
}
