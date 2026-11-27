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
    s8 kinds[8];
    u8 numEffects;
    u8 unk29;
    s8 page;
    u8 unk2B;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 emissionRate;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 emissionPeriod;
    f32 emissionPeriodRandom;
    f32 emissionPause;
    f32 emissionPauseRandom;
    s16 unk68[6];
    s32 flags;
    s32 unk78;
    s32 unk7C;
    f32 unk80;
    f32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98[4];
    u8 unkA8[4];
    f32 unkAC;
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
    u8 unk03C[0x80 - 0x3C];
    struct nuvec_s velocity;
    struct nuvec_s boundsMin;
    struct nuvec_s boundsMax;
    struct nuvec_s hitPos;
    struct nuvec_s hitNormal;
    u8 unk0BC[0xD4 - 0xBC];
    void *owner;
    u8 unk0D8[0xDC - 0xD8];
    f32 radius;
    f32 hitRadius;
    u8 unk0E4[0xE8 - 0xE4];
    f32 gravity;
    u8 unk0EC[0xF4 - 0xEC];
    f32 step;
    f32 age;
    u8 unk0FC[0x104 - 0xFC];
    u32 flags;
    u8 unk108[0x114 - 0x108];
    s32 rotationRates[2];
    u8 unk11C[0x126 - 0x11C];
    u8 rotationAxes[2];
    u32 state;
    u8 special[0xC];
    s32 specialName;
    u8 unk13C[0x140 - 0x13C];
    u8 unk140[0xC];
    u8 unk14C[0xC];
    u8 unk158[0xC];
    u8 unk164[0xC];
    u8 unk170[0xC];
    u8 unk17C[0xC];
    u8 unk188[0x1A8 - 0x188];
    void (*kill)(struct Part *, s32);
    u8 unk1AC[0x1B8 - 0x1AC];
    s32 (*canReset)(struct Part *);
    u8 unk1BC[0x1C0 - 0x1BC];
    s32 *unk1C0;
    s32 *unk1C4;
    u8 unk1C8[0x1DC - 0x1C8];
    s32 unk1DC;
    u8 unk1E0[0x1E4 - 0x1E0];
    s32 debris;
    u8 unk1E8[0x1F4 - 0x1E8];
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

extern struct nuvec_s lbl_803D9060;
extern Entry6C *lbl_804088C0;
extern PartType *lbl_804088C4;
extern s32 lbl_8040AF0C;

void fn_80074DDC(f32 best)
{
    struct nuvec_s d;
    s32 i;
    f32 dist;

    if (lbl_8040AF0C != -1 && lbl_803D8280[lbl_8040AF0C].id != -1) {
        NuVecSub(&d, &lbl_803D9060, &lbl_803D8280[lbl_8040AF0C].position);
        dist = d.x * d.x + d.y * d.y + d.z * d.z;
        if (dist == 0.0f) {
            return;
        }
    }
    lbl_8040AF0C = -1;
    for (i = 0; i < 32; i++) {
        if (lbl_803D8280[i].id != -1) {
            NuVecSub(&d, &lbl_803D9060, &lbl_803D8280[i].position);
            dist = d.x * d.x + d.y * d.y + d.z * d.z;
            if (best < 0.0f || dist < best) {
                lbl_8040AF0C = i;
                best = dist;
            }
        }
    }
    lbl_804088C0 = NULL;
    lbl_804088C4 = NULL;
    if (lbl_8040AF0C != -1) {
        lbl_804088C0 = &lbl_803D8280[lbl_8040AF0C];
        if (lbl_804088C0->id != -1) {
            lbl_804088C4 = &((PartType *)lbl_803D5680)[lbl_804088C0->id];
        }
    }
}

s32 NuSpecialFindMultiWC(void *, struct numtx_s *);
void fn_8002D9E8(void *, void *, void *, void *, void *, void *);
void fn_8002DAD0(void *);

void fn_80074374(s32 keep)
{
    struct numtx_s tmp;
    struct numtx_s *mtx;
    Part *part;
    s32 i;
    s32 found;

    for (i = 0, part = lbl_8040AEFC; i < lbl_80408888; i++, part++) {
        if ((s32)part->state < 0 && !(part->flags & 0x1000)
            && (part->canReset == NULL || part->canReset(part) != 0)) {
            if (part->state & 0x10000000) {
                fn_8002D9E8(part->unk164, part->unk140, part->unk170, part->unk14C, part->unk17C, part->unk158);
                fn_8002DAD0(part->unk188);
            }
            part->state &= ~0x400000;
            mtx = (struct numtx_s *)part;
            if ((u32)part & 0xF) {
                tmp = *(struct numtx_s *)part;
                mtx = &tmp;
            }
            if (part->specialName != 0 && NuSpecialFindMultiWC(part->special, mtx) != 0) {
                found = 1;
                part->state |= 0x600000;
            } else {
                found = 0;
            }
            if (found == 0 && keep == 0 && (!(part->flags & 0x10) || (part->state & 0x800000))) {
                fn_80074880(part, 0);
            }
        }
    }
}

typedef struct {
    u8 unk00[0xB4];
    char *name;
    u8 unkB8[0xD0 - 0xB8];
} PartSceneItem;

typedef struct {
    u8 unk00[0x6C];
    s32 count;
    PartSceneItem *items;
} PartSceneTable;

typedef struct {
    u8 unk00[0x1A0];
    PartSceneTable *table;
} PartScene;

void fn_8006F7E8(char *buf, s32 len);
s32 fn_8006F71C(void);
f32 fn_8006F28C(void);
s32 fn_8006F55C(void);
s32 fn_8006F46C(void);
s32 fn_80064A28(void *arg0);
s32 fn_8006DDC4(char *name, s32 len);
extern PartScene *lbl_8040848C;
extern char lbl_801BB51C[];
extern f32 lbl_8019A958[];
extern const f32 lbl_8019A95C[];
extern f32 lbl_8019A960[];

static inline s32 Part_FindSceneEffect(char *name, PartScene *scene) {
    s32 i;

    if (*name == 0) {
        return -1;
    }
    if (NuStrNCmp(name, lbl_801BB51C, 0x10) == 0) {
        return 9999;
    }
    if (scene == NULL) {
        return -1;
    }
    for (i = 0; i < scene->table->count; i++) {
        if (NuStrNCmp(name, scene->table->items[i].name, 0x10) == 0) {
            return i;
        }
    }
    return -1;
}

#define PART_LOOKUP(dst, n, k, s) \
    if ((k) == 0) { (dst) = Part_FindSceneEffect(n, s); } \
    else if ((k) == 1) { (dst) = Part_FindSceneEffect(n, lbl_8040848C); } \
    else { (dst) = -1; }

void fn_80074F48(PartType *t, s32 ver, PartScene *scene) {
    char name[16];
    s32 i;

    fn_8006F7E8(t->name, 0x10);
    if (ver > 5) {
        for (i = 0; i < 8; i++) {
            t->kinds[i] = fn_8006F71C();
        }
    } else if (ver > 1) {
        t->kinds[0] = fn_8006F71C();
        for (i = 1; i < 8; i++) {
            t->kinds[i] = -1;
        }
    } else {
        t->kinds[0] = 0;
        for (i = 1; i < 8; i++) {
            t->kinds[i] = -1;
        }
    }
    if (ver > 5) {
        for (i = 0; i < 8; i++) {
            fn_8006F7E8(name, 0x10);
            PART_LOOKUP(t->effectIds[i], name, t->kinds[i], scene);
        }
    } else {
        fn_8006F7E8(name, 0x10);
        PART_LOOKUP(t->effectIds[0], name, t->kinds[0], scene);
    }
    t->numEffects = 0;
    for (i = 0; i < 8; i++) {
        if (t->effectIds[i] != -1 && t->effectIds[i] != 9999) {
            t->numEffects++;
        }
    }
    if (ver > 5) {
        t->unk29 = fn_8006F71C();
    } else {
        t->unk29 = 0;
    }
    t->unk2C = fn_8006F28C();
    t->unk30 = fn_8006F28C();
    t->unk34 = fn_8006F28C();
    t->emissionRate = fn_8006F28C();
    if (ver > 7) {
        t->unk3C = fn_8006F28C();
    } else {
        t->unk3C = lbl_8019A958[0];
    }
    t->unk40 = fn_8006F28C();
    t->unk44 = fn_8006F28C();
    t->unk48 = fn_8006F28C();
    t->unk4C = fn_8006F28C();
    t->unk50 = fn_8006F28C();
    t->unk54 = fn_8006F28C();
    t->emissionPeriod = fn_8006F28C();
    t->emissionPeriodRandom = fn_8006F28C();
    t->emissionPause = fn_8006F28C();
    t->emissionPauseRandom = fn_8006F28C();
    t->unk68[0] = fn_8006F55C();
    t->unk68[1] = fn_8006F55C();
    t->unk68[2] = fn_8006F55C();
    t->unk68[3] = fn_8006F55C();
    t->unk68[4] = fn_8006F55C();
    t->unk68[5] = fn_8006F55C();
    t->flags = fn_8006F46C();
    if (t->effectIds[0] == 9999) {
        t->flags |= 0x10;
    }
    if (ver > 8) {
        fn_8006F7E8(name, 0x10);
        t->unk78 = fn_80064A28(name);
        fn_8006F7E8(name, 0x10);
        t->unk7C = fn_80064A28(name);
        fn_8006F7E8(name, 0x10);
        t->unk88 = fn_80064A28(name);
        t->unk80 = fn_8006F28C();
        t->unk84 = fn_8006F28C();
    } else if (ver > 4) {
        fn_8006F7E8(name, 0x10);
        t->unk78 = fn_80064A28(name);
        t->unk7C = -1;
        fn_8006F7E8(name, 0x10);
        t->unk88 = fn_80064A28(name);
        t->unk80 = fn_8006F28C();
        t->unk84 = lbl_8019A95C[0];
    } else if (ver > 2) {
        s32 k;
        t->unk88 = t->unk7C = t->unk78 = -1;
        k = fn_8006F71C();
        fn_8006F7E8(name, 0x10);
        if (k == 0) {
            t->unk78 = fn_80064A28(name);
        } else if (k == 1) {
            t->unk88 = fn_80064A28(name);
        }
        t->unk80 = fn_8006F28C();
        t->unk84 = lbl_8019A95C[0];
    } else {
        f32 z = lbl_8019A95C[0];
        t->unk78 = -1;
        t->unk7C = -1;
        t->unk88 = -1;
        t->unk80 = z;
        t->unk84 = z;
    }
    if (ver > 3) {
        fn_8006F7E8(name, 0x10);
        t->unk94 = fn_80064A28(name);
        fn_8006F7E8(name, 0x10);
        t->unk8C = fn_80064A28(name);
    } else {
        t->unk8C = -1;
        t->unk94 = -1;
    }
    if (ver > 11) {
        fn_8006F7E8(name, 0x10);
        t->unk90 = PARTLookupType(name);
    } else {
        t->unk90 = -1;
    }
    if (ver > 6) {
        for (i = 0; i < 4; i++) {
            fn_8006F7E8(name, 0x10);
            t->unk98[i] = fn_8006DDC4(name, 0x10);
        }
        for (i = 0; i < 4; i++) {
            t->unkA8[i] = fn_8006F71C();
        }
    } else {
        for (i = 0; i < 4; i++) {
            t->unk98[i] = -1;
            t->unkA8[i] = 0;
        }
    }
    if (ver > 9) {
        t->unkAC = fn_8006F28C();
    } else {
        t->unkAC = lbl_8019A960[0];
    }
}
