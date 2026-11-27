#include "types.h"
#include "game/gamemenu.h"
#include "numath/numath.h"

extern s32 lbl_8040889C;

void fn_8007483C(void)
{

}

void fn_80074B80(s32 a)
{
    lbl_8040889C = a;
}

extern s32 lbl_803D9020[];
extern s32 lbl_804088B0;

typedef struct {
    struct nuvec_s position;
    s32 id;
    char name[16];
    f32 lastEmission;
    f32 periodStart;
    f32 periodEnd;
    s16 rotation[3];
    u8 unk32;
    u8 unk33;
    s32 shotsRemaining;
    f32 unk38;
    u8 unk3C;
    u8 unk3D;
    u8 unk3E[2];
    f32 unk40;
    s16 unk44;
    s16 unk46;
    u8 unk48[0x6C - 0x48];
} Entry6C;
extern Entry6C lbl_803D8280[];
extern f32 lbl_8019AEF4[];

void fn_80075C78(s32 arg0) {
    s32 i;
    f32 *p;

    Entry6C *b = lbl_803D8280;
    for (i = 0, p = (f32 *)((s8 *)b + 0x40); i < 0x20; i++, p += 0x6C / 4) {
        if (*(s32 *)((s8 *)p - 0x34) != -1 && *((s8 *)p - 0xE) == arg0) {
            *p = lbl_8019AEF4[0];
        }
    }
    lbl_803D9020[arg0] = 1;
    lbl_804088B0 = arg0;
}

void fn_80075CD8(s32 arg0) {
    *(s32 *)(((s8 *)lbl_803D9020) + (arg0 * 4)) = 0;
    if ((s32) lbl_804088B0 == arg0) {
        lbl_804088B0 = 0;
    }
}

s32 NuStrNCmp(char *a, char *b, s32 n);
extern char lbl_803D5680[];

s32 PARTLookupType(char *name) {
    s32 i;
    char *p;

    if (*name == 0) return -1;
    {
        for (i = 0, p = lbl_803D5680; i < 0x40; i++, p += 0xB0) {
            if (NuStrNCmp(name, p, 0x10) == 0) {
                return i;
            }
        }
    }
    return -1;
}

typedef struct {
    char name[16];
    s16 effectIds[8];
    u8 unk20[0x2A - 0x20];
    s8 page;
    u8 unk2B[0x38 - 0x2B];
    f32 emissionRate;
    u8 unk3C[0x58 - 0x3C];
    f32 emissionPeriod;
    f32 emissionPeriodRandom;
    f32 emissionPause;
    f32 emissionPauseRandom;
    u8 unk64[0xB0 - 0x68];
} PartType;

extern s32 lbl_804088AC;

void fn_80074CD8(s32 i) {
    if (i != -1) {
        if (lbl_803D8280[i].id != -1) {
            lbl_803D8280[i].id = -1;
            lbl_804088AC--;
        }
    }
}

int sprintf(char *, const char *, ...);
extern s32 lbl_80408234;
extern s32 lbl_80408A54;
extern char *lbl_80408B4C;
extern char *lbl_80408B50;
extern void (*lbl_80408C70)(void);

void fn_80077038(void) {
    char buf[0x80];
    f32 one = 1.0f;
    f32 half = 0.5f;

    if (lbl_80408C70 != NULL) {
        lbl_80408C70();
    }
    sprintf(buf, lbl_80408B4C, lbl_80408234 + 1);
    fn_8007B298(buf, 0.0f, 0.45f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B50, 0.0f, -0.5f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
}

extern s32 lbl_80408A48;
extern f32 lbl_80408A50;

void fn_80076194(void) {
    MenuFrame *m;
    MenuDef *d;

    if (gMenuDepth != 0) {
        m = &gMenuStack[gMenuDepth];
        if (gRegisteredMenuDefinitions[m->id].close != NULL) {
            gRegisteredMenuDefinitions[m->id].close(m);
        }
        if (m->id != -1) {
            d = &gRegisteredMenuDefinitions[m->id];
            if (d->sel8 != -1) {
                d->sel8 = m->sel8;
            }
            d = &gRegisteredMenuDefinitions[m->id];
            if (d->selA != -1) {
                d->selA = m->selA;
            }
        }
        m->unkBC = 1;
        m->id = -1;
        m->unkB8 = 0;
        m->unkC0 = 0;
        gMenuDepth--;
        m = &gMenuStack[gMenuDepth];
        m->unkBC = 1;
        m->unkB8 = 1;
        m->unkB4 = 0;
        m->unkC4 = 0;
        m->t0 = 0.0f;
        m->unk50 = lbl_80408A48;
        lbl_80408A50 = 0.0f;
        lbl_80408A54 = 0;
    }
}

void Menu_CloseCurrent(void) {
    MenuFrame *m;
    MenuDef *d;

    if (gMenuDepth != 0) {
        m = &gMenuStack[gMenuDepth];
        if (gRegisteredMenuDefinitions[m->id].close != NULL) {
            gRegisteredMenuDefinitions[m->id].close(m);
        }
        if (m->id != -1) {
            d = &gRegisteredMenuDefinitions[m->id];
            if (d->sel8 != -1) {
                d->sel8 = m->sel8;
            }
            d = &gRegisteredMenuDefinitions[m->id];
            if (d->selA != -1) {
                d->selA = m->selA;
            }
        }
        m->id = -1;
        m->unkB8 = 0;
        m->unkBC = 1;
        m->unkC0 = 0;
        gMenuDepth--;
        m = &gMenuStack[gMenuDepth];
        m->unkB4 = 0;
        m->unkC4 = 0;
        m->unkBC = 1;
        m->unkB8 = 1;
        m->t0 = 0.0f;
        m->unk50 = lbl_80408A48;
        if (m->id != -1 && gRegisteredMenuDefinitions[m->id].enter != NULL) {
            gRegisteredMenuDefinitions[m->id].enter(m);
        }
        lbl_80408A54 = 0;
        lbl_80408A50 = 0.0f;
    }
}

s32 Menu_Open(s32, s32, s32);
extern s32 lbl_8040821C;
extern s32 lbl_80408A3C;
extern s32 lbl_80408A44;
extern s32 lbl_80408C4C;

void Menu_Navigate(void *arg0) {
    s32 var_r3;
    s32 var_r4;
    s16 temp_r9;
    s32 temp_r0;
    s32 var_r31;

    var_r31 = 0;
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        temp_r9 = (*(s16 *)((s8 *)(arg0) + (0xA)));
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
        if (temp_r9 == 0) {
            if ((s32) lbl_80408C4C != 0) {
                if ((s32) gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id != 0x3FA) {
                    fn_80076194();
                    var_r3 = 0x3FF;
                    var_r4 = -1;
                    goto block_7;
                }
                goto block_9;
            }
            if ((s32) lbl_8040821C == 2) {
                fn_80076194();
                var_r3 = 0x3FE;
                var_r4 = 1;
block_7:
                Menu_Open(var_r3, var_r4, -1);
            } else {
                goto block_9;
            }
        } else if (temp_r9 == 1) {
block_9:
            Menu_CloseCurrent();
        } else {
            goto block_11;
        }
    } else if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
block_11:
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        temp_r0 = gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id;
        if (temp_r0 == 0x3E8) {
            fn_80076194();
            Menu_Open(0x3F8, 1, -1);
            return;
        }
        if (temp_r0 == 0x3FA) {
            lbl_80408A3C = 3;
            Menu_CloseCurrent();
            return;
        }
        fn_80076194();
        Menu_Open(0x3F9, 1, -1);
    }
}

extern char *lbl_80408B34;
extern char *lbl_80408B40;
extern s32 lbl_80408A68;
extern s32 lbl_80408C50;
extern char *lbl_80408B78;
extern char *lbl_80408B84;
extern f32 lbl_8040AF18;
extern f32 lbl_80408A84;
extern char *lbl_80408AB0;
extern char *lbl_80408B18;
extern u8 lbl_80408A57;
void fn_800769B4(void *, char *, u32);

void fn_80077340(void *arg0) {
    char buf[0x80];
    char *title;
    f32 half = 0.5f;

    if (lbl_8040821C == 1) {
        title = lbl_80408B78;
    } else if (lbl_8040821C == 3) {
        title = lbl_80408B84;
    } else {
        title = lbl_80408B34;
    }
    fn_8007B298(title, 0.0f, 0.3f, 1.0f, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
    sprintf(buf, lbl_80408B40, lbl_80408A68, lbl_80408C50);
    fn_8007B298(buf, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        char *action = lbl_80408AB0;
        *(f32 *)((u8 *)arg0 + 0x9C) = time - offset;
        fn_800769B4(arg0, action, lbl_80408A57);
    }
    fn_800769B4(arg0, lbl_80408B18, lbl_80408A57);
}

extern char *lbl_80408B44;
extern char *lbl_80408B30;

void fn_80077274(void) {
    fn_8007B298(lbl_80408B44, 0.0f, 0.25f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B30, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
}

extern char *lbl_80408B54;
extern char *lbl_80408B58;
extern char *lbl_80408B5C;

void fn_80077148(void) {
    f32 one = 1.0f;
    f32 half = 0.5f;

    fn_8007B298(lbl_80408B54, 0.0f, 0.4f, one, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B58, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B5C, 0.0f, -0.4f, one, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
}

extern char *lbl_80408B48;

void fn_80077480(void *arg0) {
    char buf[0x80];
    f32 one = 1.0f;
    f32 half = 0.5f;

    fn_8007B298(lbl_80408B48, 0.0f, 0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
    sprintf(buf, lbl_80408B40, lbl_80408A68, lbl_80408C50);
    fn_8007B298(buf, 0.0f, -0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        char *action = lbl_80408AB0;
        *(f32 *)((u8 *)arg0 + 0x9C) = time - offset;
        fn_800769B4(arg0, action, lbl_80408A57);
    }
    fn_800769B4(arg0, lbl_80408B18, lbl_80408A57);
}

extern char lbl_803D992C[];
extern const char *lbl_80408AC8;
extern s32 lbl_8040A618, lbl_8040A61C, lbl_8040A620;
extern s32 lbl_80408AA0, lbl_80408AAC;
extern char *lbl_80408B68, *lbl_80408B6C;
void NuStrCpy(char *, const char *);

void fn_80077C34(void *arg0) {
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    fn_8007B298(lbl_80408B68, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.2f, 2, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B6C, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.2f, 2, 0, 0, lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AA0;
        *(f32 *)((u8 *)arg0 + 0x9C) = time - offset;
        fn_800769B4(arg0, action, lbl_80408A57);
    }
    fn_800769B4(arg0, lbl_80408AAC, lbl_80408A57);
}

extern s32 lbl_80408A38;
extern s32 lbl_80408AA4;
extern char *lbl_80408B04, *lbl_80408B08;

void fn_80077D54(void *arg0) {
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408A38 != 0) {
        fn_8007B298(lbl_80408B08, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.2f, 2, 0, 0, lbl_80408A54);
    } else {
        fn_8007B298(lbl_80408B04, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.2f, 2, 0, 0, lbl_80408A54);
    }
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AA0;
        *(f32 *)((u8 *)arg0 + 0x9C) = time - offset;
        fn_800769B4(arg0, action, lbl_80408A57);
    }
    fn_800769B4(arg0, lbl_80408AA4, lbl_80408A57);
}

extern char *lbl_80408B38, *lbl_80408B3C;

void fn_80077AD4(void *arg0) {
    fn_8007B298(lbl_80408B38, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 2, 0, 0, lbl_80408A54);
    fn_8007B298(lbl_80408B3C, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.2f, 2, 0, 0, lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84 + lbl_80408A84;
        s32 action = lbl_80408AA0;
        *(f32 *)((u8 *)arg0 + 0x9C) = time - offset;
        fn_800769B4(arg0, action, lbl_80408A57);
    }
    fn_800769B4(arg0, lbl_80408AB0, lbl_80408A57);
    if (gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id == 0x3F4) {
        fn_800769B4(arg0, lbl_80408AAC, lbl_80408A57);
    } else {
        fn_800769B4(arg0, lbl_80408B18, lbl_80408A57);
    }
}

extern s32 lbl_80408C00, lbl_80408BFC, lbl_80408C04;
extern f32 lbl_80408C20;
extern s32 lbl_80408B8C;
extern char *lbl_80408AE8, *lbl_80408AFC, *lbl_80408AE0;

void fn_800775B4(void) {
    if (lbl_80408C00 != 0 || lbl_80408BFC != 0 || lbl_80408C20 > 0.0f) {
        f32 one = 1.0f;
        f32 half = 0.5f;

        lbl_80408B8C = 0;
        fn_8007AC80(lbl_80408AE8, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        fn_8007B298(lbl_80408B30, 0.0f, -0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    } else if (lbl_80408C04 != 0) {
        if (lbl_80408B8C == 0) {
            lbl_80408A54 = 0;
            lbl_80408B8C = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408AFC, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    } else {
        if (lbl_80408B8C == 0) {
            lbl_80408A54 = 0;
            lbl_80408B8C = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408AE0, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    }
}

extern const char *lbl_80408AD0;
extern s32 lbl_80408BF4, lbl_80408BF8;
extern f32 lbl_80408C28;
extern s32 lbl_80408B90;
extern char *lbl_80408AE4, *lbl_80408ADC;

void fn_80077770(void) {
    NuStrCpy(lbl_803D992C, lbl_80408AD0);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408BF4 != 0 || lbl_80408BF8 != 0 || lbl_80408C28 > 0.0f) {
        f32 one = 1.0f;
        f32 half = 0.5f;

        lbl_80408B90 = 0;
        fn_8007AC80(lbl_80408AE4, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        fn_8007B298(lbl_80408B30, 0.0f, -0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    } else {
        if (lbl_80408B90 == 0) {
            lbl_80408A54 = 0;
            lbl_80408B90 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408ADC, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    }
}

extern s32 lbl_80408C10, lbl_80408C0C, lbl_80408C14;
extern f32 lbl_80408C24;
extern s32 lbl_80408B94;
extern char *lbl_80408B60, *lbl_80408B2C, *lbl_80408B64;

void fn_800778F0(void) {
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408C10 != 0 || lbl_80408C0C != 0 || lbl_80408C24 > 0.0f) {
        f32 one = 1.0f;
        f32 half = 0.5f;

        lbl_80408B94 = 0;
        fn_8007AC80(lbl_80408B60, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        fn_8007B298(lbl_80408B30, 0.0f, -0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    } else if (lbl_80408C14 != 0) {
        if (lbl_80408B94 == 0) {
            lbl_80408A54 = 0;
            lbl_80408B94 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408B2C, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    } else {
        if (lbl_80408B94 == 0) {
            lbl_80408A54 = 0;
            lbl_80408B94 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408B64, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    }
}

extern const char *lbl_80408ACC;
extern s32 lbl_80408BC0, lbl_80408BC4, lbl_80408BC8, lbl_80408BCC;
extern f32 lbl_80408C18;
extern s32 lbl_80408BA0;
extern char *lbl_80408B24, *lbl_80408AF4, *lbl_80408AF0, *lbl_80408AD8;

void fn_8007818C(void) {
    NuStrCpy(lbl_803D992C, lbl_80408ACC);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408BC0 != 0 || lbl_80408BC4 != 0 || lbl_80408C18 > 0.0f) {
        f32 one = 1.0f;
        f32 half = 0.5f;

        lbl_80408BA0 = 0;
        fn_8007AC80(lbl_80408B24, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        fn_8007B298(lbl_80408B30, 0.0f, -0.3f, one, half, half, half, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    } else if (lbl_80408BC8 != 0) {
        if (lbl_80408BA0 == 0) {
            lbl_80408A54 = 0;
            lbl_80408BA0 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408AF4, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    } else if (lbl_80408BCC != 0) {
        if (lbl_80408BA0 == 0) {
            lbl_80408A54 = 0;
            lbl_80408BA0 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408AF0, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    } else {
        if (lbl_80408BA0 == 0) {
            lbl_80408A54 = 0;
            lbl_80408BA0 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;
            fn_8007AC80(lbl_80408AD8, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    }
}

extern s32 lbl_80408A3C, lbl_80408A20;
extern f32 lbl_8040945C, lbl_8040AF1C;
extern char *lbl_80408B0C;
extern s32 lbl_80408B80;

void fn_800783B8(void *arg0) {
    char buf[0x80];
    s32 mode = lbl_80408A3C;

    if ((mode != 0 || lbl_80408A20 != 0) && mode != 3 && mode != 4) {
        *(f32 *)((u8 *)arg0 + 0x9C) = lbl_8040945C - (lbl_80408A84 + lbl_80408A84);
        switch (mode) {
        case 1:
            fn_8007B298(lbl_80408B34, 0.0f, lbl_8040AF1C, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 0, 0, 1.5f, 2, 0, 0, lbl_80408A54);
            break;
        case 2:
            fn_8007B298(lbl_80408B48, 0.0f, lbl_8040AF1C, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 0, 0, 1.5f, 2, 0, 0, lbl_80408A54);
            break;
        case 5:
            fn_8007B298(lbl_80408B78, 0.0f, lbl_8040AF1C, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 0, 0, 1.5f, 2, 0, 0, lbl_80408A54);
            break;
        case 6:
            fn_8007B298(lbl_80408B84, 0.0f, lbl_8040AF1C, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 0, 0, 1.5f, 2, 0, 0, lbl_80408A54);
            break;
        }
        sprintf(buf, lbl_80408B40, lbl_80408A68, lbl_80408C50);
        fn_8007B298(buf, 0.0f, 0.25f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
        fn_8007B298(lbl_80408B0C, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
        fn_800769B4(arg0, lbl_80408AB0, lbl_80408A57);
        fn_800769B4(arg0, lbl_80408B18, lbl_80408A57);
        if (lbl_80408A3C == 2) {
            fn_800769B4(arg0, lbl_80408B80, lbl_80408A57);
        }
    }
}

extern void *memset(void *, int, u32);
extern void *lbl_8040AEFC;
extern s32 lbl_80408888;
extern s32 lbl_8040888C;

void fn_80074840(void)
{
    if (lbl_8040AEFC != NULL) {
        memset(lbl_8040AEFC, 0, lbl_80408888 * 0x1F4);
    }
    lbl_8040888C = 0;
}

typedef struct Part {
    u8 unk000[0x30];
    struct nuvec_s position;
    u8 unk03C[0x8C - 0x3C];
    struct nuvec_s boundsMin;
    struct nuvec_s boundsMax;
    u8 unk0A4[0xD4 - 0xA4];
    void *owner;
    u8 unk0D8[0xDC - 0xD8];
    f32 radius;
    u8 unk0E0[0x104 - 0xE0];
    u32 flags;
    u8 unk108[0x114 - 0x108];
    s32 rotationRates[2];
    u8 unk11C[0x126 - 0x11C];
    u8 rotationAxes[2];
    u32 state;
    u8 unk12C[0x1A8 - 0x12C];
    void (*kill)(struct Part *, s32);
    u8 unk1AC[0x1C0 - 0x1AC];
    s32 *unk1C0;
    s32 *unk1C4;
    u8 unk1C8[0x1DC - 0x1C8];
    s32 unk1DC;
    u8 unk1E0[0x1F4 - 0x1E0];
} Part;

s32 fn_8005EB80(s32 *);
void fn_800718FC(s32);
void fn_80063E14(s32 *, s32, struct nuvec_s *, s32);

void fn_80074880(Part *part, s32 reason)
{
    part->state &= 0x7FFFFFFF;
    if ((part->flags & 0x20000) != 0 && part->unk1C0 != NULL) {
        fn_8005EB80(part->unk1C0);
    }
    if (part->unk1C4 != NULL) {
        fn_800718FC(*part->unk1C4);
        *part->unk1C4 = -1;
    }
    if (part->unk1DC != -1) {
        s32 handle = -1;

        fn_80063E14(&handle, part->unk1DC, &part->position, 1);
    }
    if (part->kill != NULL) {
        part->kill(part, reason);
    }
}

u32 NuRandInt(void);
f32 fn_8000C038(void);

void fn_80074934(Part *part)
{
    s32 i = 0;

    do {
        do {
            part->rotationAxes[i] = (NuRandInt() % 65535U) / 21845U + 1;
        } while (i == 1 && part->rotationAxes[1] == part->rotationAxes[0]);
        part->rotationRates[i] = (s32)((2.0f * fn_8000C038() - 1.0f) * 65536.0f);
        i++;
    } while (i < 2);
}

s32 fn_80074C00(char *name, s32 page)
{
    s32 i;

    if (*name == 0) {
        return -1;
    }
    if ((u32)(page - 1) <= 6) {
        for (i = 0; i < 64; i++) {
            PartType *type = &((PartType *)lbl_803D5680)[i];

            if (type->page == page && NuStrNCmp(name, type->name, 16) == 0) {
                return i;
            }
        }
    }
    for (i = 0; i < 64; i++) {
        PartType *type = &((PartType *)lbl_803D5680)[i];

        if (type->page == 0 && NuStrNCmp(name, type->name, 16) == 0) {
            return i;
        }
    }
    return -1;
}

f32 NuRandIntSeeded(s32 *);
extern s32 lbl_804088A0;
extern f32 lbl_804088A4;

void fn_8007452C(s32 index, f32 offset)
{
    Entry6C *emitter;
    PartType *type;
    f32 interval;

    if (index != -1) {
        emitter = &lbl_803D8280[index];
        if (emitter->id != -1) {
            type = &((PartType *)lbl_803D5680)[emitter->id];
            if (type->emissionPeriodRandom != 0.0f || type->emissionPauseRandom != 0.0f) {
                emitter->periodStart = lbl_804088A4;
                emitter->periodEnd = NuRandIntSeeded(&lbl_804088A0) * type->emissionPeriodRandom
                                   + (emitter->periodStart + type->emissionPeriod);
            } else {
                f32 duration = type->emissionPeriod;
                f32 cycle = duration + type->emissionPause;
                f32 time = lbl_804088A4;
                f32 start = cycle * (f32)(s32)(time / cycle) + offset;
                f32 end = start + duration;

                emitter->periodStart = start;
                emitter->periodEnd = emitter->periodStart + duration;
                if (lbl_804088A4 > start && lbl_804088A4 > end) {
                    do {
                        if (emitter->periodStart >= emitter->periodEnd) {
                            emitter->periodEnd = emitter->periodStart + type->emissionPeriod;
                        } else {
                            emitter->periodStart = emitter->periodEnd + type->emissionPause;
                        }
                    } while (lbl_804088A4 > emitter->periodStart && lbl_804088A4 > emitter->periodEnd);
                }
            }
            interval = 1.0f / type->emissionRate;
            if (emitter->periodEnd < lbl_804088A4) {
                emitter->lastEmission = emitter->periodStart - interval;
            } else {
                emitter->lastEmission = interval * (f32)(s32)(lbl_804088A4 / interval);
            }
            emitter->unk38 = lbl_804088A4;
        }
    }
}

extern s32 lbl_80408218;
extern s32 lbl_80408220;
extern s32 lbl_8040822C;
extern u16 lbl_80408BAA;
extern s32 lbl_8040AE0C;
void NuStrCpy(char *, const char *);

void Menu_OpenSpecial(MenuFrame *arg0) {
    s32 var_r3;
    s32 var_r4;

    lbl_80408C4C = 0;
    arg0->max10 = lbl_80408BAA - 1;
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 0x7F;
    lbl_8040A620 = 0xFF;
    arg0->max12 = 1;
    if (lbl_8040821C != 2) {
        Menu_Open(0x3EA, -1, -1);
        return;
    }
    if (lbl_8040AE0C != 0) {
        Menu_Open(0x3FD, -1, -1);
        return;
    }
    if (lbl_80408220 == 0) {
        Menu_Open(0x3EE, 1, -1);
        return;
    }
    if (lbl_8040822C == 0 && lbl_80408218 < lbl_80408C50) {
        Menu_Open(0x3EB, -1, -1);
        return;
    }
    if (lbl_8040821C == 2 && lbl_8040822C == 0) {
        Menu_Open(0x3FB, 1, -1);
    }
}

s32 fn_80079050();

void fn_800787B4(void *arg0) {
    s32 var_r3;
    s32 var_r4;
    s16 temp_r9;
    s32 var_r31;

    var_r31 = 0;
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        temp_r9 = (*(s16 *)((s8 *)(arg0) + (0xA)));
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
        if (temp_r9 == 0) {
            goto block_9;
        } else if (temp_r9 == 1) {
            if ((s32) lbl_80408C4C != 0) {
                if ((s32) gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id != 0x3FA) {
                    fn_80076194();
                    var_r3 = 0x3FF;
                    var_r4 = -1;
                    goto block_7;
                }
                goto block_9;
            }
            if ((s32) lbl_8040821C != 2) {
block_9:
                Menu_CloseCurrent();
            } else {
                lbl_80408BF4 = temp_r9;
                lbl_80408BF8 = 0;
                fn_80076194();
                var_r3 = 0x3F7;
                var_r4 = 0;
block_7:
                Menu_Open(var_r3, var_r4, -1);
            }
        } else {
            goto block_11;
        }
    } else if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
block_11:
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        fn_80076194();
        if (fn_80079050() == 0x3E8) {
            Menu_Open(0x3F8, 1, -1);
            return;
        }
        if ((s32) gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id == 0x3FA) {
            lbl_80408A3C = 3;
            Menu_CloseCurrent();
            return;
        }
        Menu_CloseCurrent();
    }
}

extern s32 lbl_803D9000[];
extern void (*lbl_80407B1C)(void);
extern void (*lbl_80407B20)(void);
extern s32 lbl_804088A8;

void fn_80075B44(s32 page) {
    s32 i;

    lbl_80407B1C();
    fn_8007483C();
    if (lbl_803D9020[page] != 0) {
        lbl_803D9020[page] = 0;
        if (lbl_804088B0 == page) {
            lbl_804088B0 = 0;
        }
    }
    for (i = 0; i < 0x40; i++) {
        PartType *type = &((PartType *)lbl_803D5680)[i];
        if (type->page == page && type->effectIds[0] != -1) {
            type->effectIds[0] = -1;
            type->name[0] = 0;
            lbl_804088A8--;
        }
    }
    for (i = 0; i < 0x20; i++) {
        if ((s8)lbl_803D8280[i].unk32 == page) {
            if (lbl_803D8280[i].id != -1) {
                lbl_803D8280[i].id = -1;
                lbl_804088AC--;
            }
        }
    }
    fn_8007483C();
    lbl_80407B20();
    lbl_803D9000[page] = 0;
}

extern s32 lbl_8034705C[];
extern s32 lbl_80408A30;
extern s32 lbl_80408A4C;
extern s32 lbl_80408BB4;

static inline void MenuFrame_ResetRange(MenuFrame *m) {
    m->max10 = lbl_80408BAA - 1;
    m->max12 = 1;
    lbl_80408C4C = 0;
    lbl_80408A30 = 0;
}

void fn_80078A44(MenuFrame *m) {
    s32 sel;

    if (*(s32 *)((s8 *)m + 0x68) != 0) {
        if (m->selA < m->max12) {
            if (lbl_80408C4C != 0) {
                Menu_Open(0x3FF, -1, -1);
            } else if (lbl_8040821C != 2) {
                MenuFrame_ResetRange(m);
                if (lbl_8040AE0C != 0) {
                    Menu_Open(0x3FD, -1, -1);
                } else {
                    Menu_Open(0x3EC, -1, -1);
                }
            } else {
                sel = m->sel8 - m->minC;
                lbl_80408BB4 = sel;
                if (lbl_8034705C[sel] != 0) {
                    Menu_Open(0x3F5, 1, -1);
                    m->unk50 = lbl_80408A44;
                } else {
                    m->unk50 = lbl_80408A4C;
                }
            }
        } else {
            Menu_Open(0x3F9, 1, -1);
            m->unk50 = lbl_80408A44;
        }
    } else if (*(s32 *)((s8 *)m + 0x6C) != 0) {
        Menu_Open(0x3F9, 1, -1);
    }
}

extern f32 lbl_8019B92C[];
extern f32 lbl_8019B930[];
extern s32 lbl_80408224;
extern s32 lbl_80408230;
extern s32 lbl_80408BF4;
extern f32 lbl_80408C3C;

void fn_8007890C(void) {
    if (lbl_80408BF4 != 0 || lbl_80408C28 > lbl_8019B92C[0]) {
        lbl_80408C3C = lbl_8019B930[0];
    }
    if (lbl_80408BF4 != 0 && lbl_80408224 != 0) {
        lbl_80408BF4 = 0;
        fn_80076194();
        MenuFrame_ResetRange(&gMenuStack[gMenuDepth]);
        if (lbl_8040AE0C != 0) {
            Menu_Open(0x3FD, -1, -1);
        } else if (lbl_8040821C != 2) {
            Menu_Open(0x3EC, -1, -1);
        } else if (lbl_80408220 == 0) {
            Menu_Open(0x3EE, 1, -1);
        } else if (lbl_8040822C == 0 || lbl_80408230 == 0) {
            Menu_Open(0x3ED, -1, -1);
        }
    }
    if (lbl_80408C3C <= lbl_8019B92C[0]) {
        Menu_CloseCurrent();
    }
}

void fn_800385A4(void);
extern f32 lbl_8019B934[];
extern s32 lbl_80408210;

void fn_80078B5C(MenuFrame *m) {
    s32 mode = lbl_80408A3C;
    *(s32 *)((u8 *)m + 0x3C) = mode;
    switch (mode) {
    case 4:
        break;
    case 0:
        if (lbl_80408210 == 1) {
            if (lbl_8040821C == 1) {
                lbl_80408A3C = 5;
            } else if (lbl_8040821C == 3) {
                lbl_80408A3C = 6;
            } else if (lbl_8040821C != 2) {
                lbl_80408A3C = 1;
            } else if (lbl_80408220 == 0) {
                Menu_Open(0x3EE, 1, -1);
            } else if (lbl_8040AE0C != 0) {
                Menu_Open(0x3FD, -1, -1);
            } else if (lbl_80408218 < lbl_80408C50 && lbl_8040822C == 0) {
                lbl_80408A3C = lbl_8040821C;
            } else {
                lbl_80408A3C = 3;
            }
        }
        break;
    case 1:
    case 2:
    case 5:
    case 6:
        {
            s32 cur = lbl_80408A3C;
            if (cur == 1) {
                goto set_max;
            }
            if (cur == 2) {
            set_max:
                m->max12 = cur;
            }
        }
        if (*(s32 *)((u8 *)m + 0x68) != 0) {
            s32 sel;
            m->unk50 = lbl_80408A44;
            sel = *(s32 *)((u8 *)m + 0x34);
            if (sel == 0) {
                lbl_80408A3C = sel;
                lbl_80408C4C = sel;
            } else if (sel == 1) {
                lbl_80408A3C = 3;
            } else if (sel == 2) {
                if (lbl_80408A3C == 2) {
                    lbl_80408A3C = 4;
                    fn_800385A4();
                }
            }
        }
        break;
    }
    if (lbl_80408A3C == 3) {
        Menu_CloseCurrent();
    } else if (lbl_80408A3C != *(s32 *)((u8 *)m + 0x3C)) {
        m->t4 = lbl_8019B934[0];
    }
}

extern f32 lbl_8019B110[];
extern f32 lbl_8019B114[];
extern f32 lbl_8019B120[];
extern void (*lbl_80408A60)(MenuFrame *);
extern void (*lbl_80408A64)(void);
extern s32 lbl_80408BE0;
extern f32 lbl_80408BE4;
extern f32 lbl_80408BE8;
void fn_80076B94(s32 arg0) {
    s32 busy = lbl_80408BE0;
    if (busy != 0 || lbl_80408BE8 > lbl_8019B110[0] || lbl_80408BE4 > lbl_8019B110[0]) {
        if (lbl_80408C70 != NULL) {
            lbl_80408C70();
        }
    } else {
        MenuFrame *m = &gMenuStack[gMenuDepth];
        if (m->id != -1) {
            s16 first = m->minE;
            f32 h;
            *(f32 *)((u8 *)m + 0x94) = lbl_8019B114[0];
            *(f32 *)((u8 *)m + 0xA4) = lbl_8019B110[0];
            *(f32 *)((u8 *)m + 0x98) = lbl_8019B110[0];
            *(f32 *)((u8 *)m + 0xA0) = lbl_8019B114[0];
            *(s32 *)((u8 *)m + 0xB0) = arg0;
            h = (f32)(m->max12 - first) * lbl_80408A84 * lbl_8019B120[0];
            *(f32 *)((u8 *)m + 0xA8) = h;
            *(s32 *)((u8 *)m + 0x90) = first;
            *(f32 *)((u8 *)m + 0x9C) = -h;
            lbl_803D992C[0] = busy;
            if (lbl_80408A60 != NULL) {
                lbl_80408A60(m);
            }
            if (gRegisteredMenuDefinitions[m->id].build != NULL) {
                gRegisteredMenuDefinitions[m->id].build(m);
            }
            if (lbl_80408A64 != NULL) {
                lbl_80408A64();
            }
        }
    }
}

extern void (*fn_80009970(char *, int))(char *, ...);
extern s32 gRegisteredMenuDefinitionCount;
extern char lbl_8019B09C[];
extern char lbl_8019B0AC[];
extern s32 lbl_80408A28;
extern s32 lbl_80408A58;
extern s32 lbl_80408A5C;
extern f32 lbl_80409458;

void Menu_RegisterDescriptors(MenuDef *defs, s32 count, s32 arg2, s32 arg3, s32 arg4) {
    char buf[0x40];
    s32 i;
    s32 total;

    if (count + 24 > 100) {
        count = 76;
    }
    for (i = 0; i < count; i++) {
        gRegisteredMenuDefinitions[i + 24] = defs[i];
    }
    total = count + 24;
    gRegisteredMenuDefinitionCount = total;
    sprintf(buf, lbl_8019B09C, total);
    fn_80009970(lbl_8019B0AC, 0x1ED)(buf);
    lbl_803D992C[0] = 0;
    lbl_80408A28 = arg2;
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (arg3 != 0) {
        lbl_80408A5C = arg3;
    }
    lbl_80408A58 = arg4;
    lbl_8040AF1C = lbl_80409458;
    lbl_8040AF18 = lbl_8040945C;
}

extern s32 lbl_80408BD0, lbl_80408BD4, lbl_80408BD8;
extern f32 lbl_80408C1C;
extern s32 lbl_80408B98;
extern char *lbl_80408AEC, *lbl_80408B20, *lbl_80408AF8, *lbl_80408B28, *lbl_80408AD4;

void fn_80077E9C(void) {
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408BD0 != 0 || lbl_80408BD4 != 0 || lbl_80408C1C > 0.0f) {
        lbl_80408B98 = 0;
        {
            f32 one = 1.0f;
            f32 half = 0.5f;

            if (lbl_80408A38 != 0) {
                fn_8007AC80(lbl_80408AEC, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
            } else {
                fn_8007AC80(lbl_80408B20, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
            }
        }
        fn_8007B298(lbl_80408B30, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0, lbl_80408A54);
    } else if (lbl_80408BD8 != 0) {
        if (lbl_80408B98 == 0) {
            lbl_80408A54 = 0;
            lbl_80408B98 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 one = 1.0f;
            f32 half = 0.5f;

            if (lbl_80408A38 != 0) {
                fn_8007AC80(lbl_80408AF8, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
            } else {
                fn_8007AC80(lbl_80408B28, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, lbl_80408A57);
            }
        }
    } else {
        if (lbl_80408B98 == 0) {
            lbl_80408A54 = 0;
            lbl_80408B98 = 1;
            lbl_80408A50 = 0.0f;
        }
        {
            f32 half = 0.5f;

            fn_8007AC80(lbl_80408AD4, 0.0f, 0.0f, 1.0f, half, half, half, 0, 255, 127, 0, lbl_80408A57);
        }
    }
}
