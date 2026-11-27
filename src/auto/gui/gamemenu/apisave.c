#include "types.h"
#include "game/gamemenu.h"

extern f32 lbl_8019B9D4[];
extern s32 lbl_80408BF0;
extern f32 lbl_80408C40;
extern s32 lbl_80408C48;
extern s32 lbl_80408C4C;

void fn_800790A4(void)
{
    lbl_80408C48 = 1;
    lbl_80408BF0 = 0;
}

void fn_8007917C(void)
{
    lbl_80408C4C = 0;
}

void fn_80079188(void)
{
    lbl_80408C40 = lbl_8019B9D4[0];
}

void fn_800790B8(void)
{
    lbl_80408C48 = 0;
    lbl_80408BF0 = 0;
}

extern char lbl_803D992C[];
extern const char *lbl_80408AC8, *lbl_80408ACC;
extern s32 lbl_8040A618, lbl_8040A61C, lbl_8040A620;
extern void (*lbl_80408A5C)(u8*, f32);
extern f32 lbl_8040AF18;
extern s32 lbl_80408AAC;
extern u8 lbl_80408A57;
extern void NuStrCpy(char*, const char*);
extern void fn_800769B4(u8*, s32, s32);

void fn_80079198(u8* menu)
{
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408A5C) lbl_80408A5C(menu, -0.5f);
    {
        s32 state = *(s32*)(menu + 0x90);
        f32 time = lbl_8040AF18;
        s32 action = lbl_80408AAC;
        *(s32*)(menu + 0x90) = state + 1;
        *(f32*)(menu + 0x9c) = time;
        fn_800769B4(menu, action, lbl_80408A57);
    }
}

void fn_80079604(u8* menu)
{
    NuStrCpy(lbl_803D992C, lbl_80408ACC);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    if (lbl_80408A5C) lbl_80408A5C(menu, -0.5f);
    {
        s32 state = *(s32*)(menu + 0x90);
        f32 time = lbl_8040AF18;
        s32 action = lbl_80408AAC;
        *(s32*)(menu + 0x90) = state + 1;
        *(f32*)(menu + 0x9c) = time;
        fn_800769B4(menu, action, lbl_80408A57);
    }
}

extern char *lbl_80408B00, *lbl_80408B10, *lbl_80408B14;
extern s32 lbl_80408AA0, lbl_80408AA4;
extern f32 lbl_80408A84;

void fn_80079698(u8* menu)
{
    NuStrCpy(lbl_803D992C, lbl_80408ACC);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    fn_8007AC80(lbl_80408B00, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, lbl_80408A57);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AA0;
        *(f32*)(menu + 0x9c) = time - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408AA4, lbl_80408A57);
}

void fn_8007975C(u8* menu)
{
    NuStrCpy(lbl_803D992C, lbl_80408AC8);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    fn_8007AC80(lbl_80408B10, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, lbl_80408A57);
    {
        f32 offset = *(f32*)(menu + 0xa8);
        s32 action = lbl_80408AA0;
        *(f32*)(menu + 0x9c) = -0.5f - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408AA4, lbl_80408A57);
}

void fn_80079824(u8* menu)
{
    NuStrCpy(lbl_803D992C, lbl_80408ACC);
    lbl_8040A618 = 0;
    lbl_8040A61C = 127;
    lbl_8040A620 = 255;
    fn_8007AC80(lbl_80408B14, 0.0f, -0.3f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, lbl_80408A57);
    {
        f32 offset = *(f32*)(menu + 0xa8);
        s32 action = lbl_80408AA0;
        *(f32*)(menu + 0x9c) = -0.5f - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408AA4, lbl_80408A57);
}

extern s32 lbl_80408BFC, lbl_80408C00, lbl_80408224;
extern f32 lbl_80408C20, lbl_80408C34;
extern f32 lbl_8019BAC4, lbl_8019BAC8;
extern void Menu_CloseCurrent(void);

void fn_80079E28(void)
{
    if (lbl_80408BFC || lbl_80408C00 || lbl_80408C20 > 0.0f)
        lbl_80408C34 = 1.5f;
    if (lbl_80408BFC && lbl_80408224) {
        lbl_80408BFC = 0;
        Menu_CloseCurrent();
    }
    if (lbl_80408C34 <= 0.0f)
        Menu_CloseCurrent();
}

extern u16 lbl_80408BAA;
extern s32 lbl_8040AE0C, lbl_80408A30, lbl_8040821C, lbl_80408220, lbl_8040822C, lbl_80408230;
extern void Menu_Open(s32, s32, s32);

void fn_800790C8(u8* menu)
{
    u16 selection = lbl_80408BAA;
    s32 active = lbl_8040AE0C;
    *(u16*)(menu + 0x12) = 1;
    *(u16*)(menu + 0x10) = selection - 1;
    lbl_80408C4C = 0;
    lbl_80408A30 = 0;
    if (active)
        Menu_Open(0x3fd, -1, -1);
    else if (lbl_8040821C != 2)
        Menu_Open(0x3ec, -1, -1);
    else if (!lbl_80408220)
        Menu_Open(0x3ee, 1, -1);
    else if (!lbl_8040822C || !lbl_80408230)
        Menu_Open(0x3ed, -1, -1);
}

extern s32 lbl_80408A54;
extern char *lbl_80408B7C, *lbl_80408B88;

void fn_80079434(u8* menu)
{
    fn_8007B298(lbl_80408B7C, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.5f, 3, 0, 0,
                lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AA0;
        *(f32*)(menu + 0x9c) = time - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408AA4, lbl_80408A57);
}

extern s32 lbl_80408C0C, lbl_80408C10;
extern f32 lbl_80408C24, lbl_80408C38;
extern void fn_80076194(void);
extern void Menu_OpenSpecial(void*);

void fn_80079EBC(void)
{
    if (lbl_80408C0C || lbl_80408C10 || lbl_80408C24 > 0.0f)
        lbl_80408C38 = 1.5f;
    if (lbl_80408C0C && lbl_80408224) {
        lbl_80408C0C = 0;
        fn_80076194();
        Menu_OpenSpecial((u8 *)gMenuStack + gMenuDepth * 0xe0);
    }
    if (lbl_80408C38 <= 0.0f)
        Menu_CloseCurrent();
}

extern char *lbl_80408B78, *lbl_80408B84, *lbl_80408B34;
extern s32 lbl_80408AB0;

void fn_8007922C(u8* menu)
{
    char* title;
    f32 half = 0.5f;
    if (lbl_8040821C == 1) title = lbl_80408B78;
    else if (lbl_8040821C == 3) title = lbl_80408B84;
    else title = lbl_80408B34;
    fn_8007B298(title, 0.0f, 0.3f, 1.0f, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0,
                lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AB0;
        *(f32*)(menu + 0x9c) = time - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408AAC, lbl_80408A57);
}

void fn_80079A30(u8* menu)
{
    if (*(s32*)(menu + 0x6c)) {
        fn_80076194();
        Menu_Open(0x3f8, 1, -1);
    }
    if (*(s32*)(menu + 0x68)) {
        if (*(s16*)(menu + 0x0a) == *(s16*)(menu + 0x12)) {
            fn_80076194();
            Menu_Open(0x3f8, 1, -1);
        }
        if (*(s32*)(menu + 0x68) && *(s16*)(menu + 0x0a) == 0)
            Menu_CloseCurrent();
    }
}

void fn_80079AC4(u8* menu)
{
    if (*(s32*)(menu + 0x6c)) {
        fn_80076194();
        Menu_Open(0x3f9, 1, -1);
    }
    if (*(s32*)(menu + 0x68)) {
        if (*(s16*)(menu + 0x0a) == *(s16*)(menu + 0x12)) {
            fn_80076194();
            Menu_Open(0x3f9, 1, -1);
        }
        if (*(s32*)(menu + 0x68) && *(s16*)(menu + 0x0a) == 0)
            Menu_CloseCurrent();
    }
}

void fn_80079B58(u8* menu)
{
    if (*(s32*)(menu + 0x6c)) {
        fn_80076194();
        Menu_Open(0x3f8, 1, -1);
    }
    if (*(s32*)(menu + 0x68)) {
        if (*(s16*)(menu + 0x0a) == 0) Menu_CloseCurrent();
        else if (*(s16*)(menu + 0x0a) == 1) {
            fn_80076194();
            Menu_Open(0x3f8, 1, -1);
        }
    }
}

extern s32 lbl_80408A44, lbl_80408BD0, lbl_80408BD4, lbl_80408BD8;
extern s32 lbl_80408BCC, lbl_80408BC0, lbl_80408BC4, lbl_80408BC8;

void fn_80079FA0(u8* menu)
{
    if (*(s32*)(menu + 0x68)) {
        s16 choice = *(s16*)(menu + 0x0a);
        *(s32*)(menu + 0x50) = lbl_80408A44;
        if (choice == 1) Menu_CloseCurrent();
        else if (lbl_80408C4C) {
            fn_80076194();
            Menu_Open(0x3ff, -1, -1);
        } else if (lbl_8040821C != 2) Menu_CloseCurrent();
        else {
            lbl_80408BD0 = 1;
            lbl_80408BD4 = 0;
            lbl_80408BD8 = 0;
            fn_80076194();
            Menu_Open(0x3f1, 0, -1);
        }
    } else if (*(s32*)(menu + 0x6c)) Menu_CloseCurrent();
}

void fn_8007A1E0(u8* menu)
{
    if (*(s32*)(menu + 0x68)) {
        s16 choice = *(s16*)(menu + 0x0a);
        *(s32*)(menu + 0x50) = lbl_80408A44;
        if (choice == 1) Menu_CloseCurrent();
        else if (lbl_80408C4C) {
            fn_80076194();
            Menu_Open(0x3ff, -1, -1);
        } else if (lbl_8040821C != 2) Menu_CloseCurrent();
        else {
            lbl_80408BC0 = 1;
            lbl_80408BC4 = 0;
            lbl_80408BC8 = 0;
            lbl_80408BCC = 0;
            fn_80076194();
            Menu_Open(0x3f6, 0, -1);
        }
    } else if (*(s32*)(menu + 0x6c)) Menu_CloseCurrent();
}

extern s32 lbl_80408C14;

void fn_80079D48(u8* menu)
{
    if (*(s32*)(menu + 0x68)) {
        *(s32*)(menu + 0x50) = lbl_80408A44;
        if (*(s16*)(menu + 0x0a) == 1) {
            fn_80076194();
            Menu_Open(0x3f8, 1, -1);
        } else if (lbl_80408C4C) {
            fn_80076194();
            Menu_Open(0x3ff, -1, -1);
        } else if (lbl_8040821C != 2) Menu_CloseCurrent();
        else {
            lbl_80408C0C = 1;
            lbl_80408C10 = 0;
            lbl_80408C14 = 0;
            fn_80076194();
            Menu_Open(0x3fc, 0, -1);
            *(s32*)(menu + 0x50) = lbl_80408A44;
        }
    } else if (*(s32*)(menu + 0x6c)) {
        fn_80076194();
        Menu_Open(0x3f8, 1, -1);
    }
}

extern f32 lbl_80408C1C, lbl_80408C30;
extern s32 lbl_80408C68, lbl_80408234;

void fn_8007A044(void)
{
    if (lbl_80408BD0) lbl_80408C1C = 1.5f;
    if (lbl_80408BD0 || lbl_80408BD4 || lbl_80408C1C > 0.0f)
        lbl_80408C30 = 1.5f;
    if (lbl_80408BD0 && lbl_80408224) {
        lbl_80408BD0 = 0;
        lbl_80408BD8 = 1;
    }
    if (lbl_80408C30 <= 0.0f) {
        if (lbl_80408BD8) Menu_CloseCurrent();
        else if (lbl_80408C68 && lbl_80408234 != -1) {
            fn_80076194();
            fn_80076194();
            Menu_Open(0x3f2, 1, -1);
        } else {
            fn_80076194();
            Menu_CloseCurrent();
        }
    }
}

extern s32 lbl_8034705C[], lbl_80408218, lbl_80408C54, lbl_80408BB4, lbl_80408A4C;

void fn_800798EC(u8* menu)
{
    s32 index = *(s16*)(menu + 8) - *(s16*)(menu + 0x0c);
    if (*(s32*)(menu + 0x68)) {
        if (*(s16*)(menu + 0x0a) == *(s16*)(menu + 0x12))
            Menu_Open(0x3f8, 1, -1);
        else if (lbl_80408C4C) Menu_Open(0x3ff, -1, -1);
        else if (lbl_8040821C != 2) Menu_OpenSpecial(menu);
        else if (lbl_8034705C[index] || lbl_80408218 >= lbl_80408C54) {
            lbl_80408BB4 = index;
            Menu_Open(0x3f0, 1, -1);
            *(s32*)(menu + 0x50) = lbl_80408A44;
        } else *(s32*)(menu + 0x50) = lbl_80408A4C;
    } else if (*(s32*)(menu + 0x6c)) Menu_Open(0x3f8, 1, -1);
}

extern f32 lbl_8019BAC0[];
extern s32 lbl_80408210;

void Menu_ConditionalClose(f32 *arg0) {
    if ((*arg0 > lbl_8019BAC0[0]) && ((s32) lbl_80408210 == 1)) {
        Menu_CloseCurrent();
    }
}

extern s32 lbl_80408A44;

void fn_80079BDC(void *arg0) {
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
        if ((s16) (*(s16 *)((s8 *)(arg0) + (0xA))) == 0) {
            Menu_CloseCurrent();
        } else {
            fn_80076194();
            Menu_CloseCurrent();
        }
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
        fn_80076194();
        Menu_CloseCurrent();
    }
}

extern s32 lbl_80408224;

void fn_8007A138(void *arg0) {
    if ((s32) lbl_80408224 != 0) {
        Menu_CloseCurrent();
    }
    if (((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) || ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0)) {
        Menu_CloseCurrent();
    }
}

extern f32 lbl_8019BAE0[];
extern s32 lbl_80408A34;
extern f32 lbl_80408C30;

void fn_8007A18C(void *arg0) {
    if (!(lbl_80408C30 > lbl_8019BAE0[0]) && (((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) || ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0))) {
        lbl_80408A34 = 1;
        Menu_CloseCurrent();
    }
}

extern s32 lbl_80408A44;

void fn_8007A388(void *arg0) {
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        if ((s16) (*(s16 *)((s8 *)(arg0) + (0xA))) == 0) {
            fn_80076194();
        }
        goto block_4;
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
block_4:
        Menu_CloseCurrent();
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
    }
}

extern s32 lbl_80408A44;

void fn_8007A3E8(void *arg0) {
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        if ((s16) (*(s16 *)((s8 *)(arg0) + (0xA))) == 0) {
            fn_80076194();
        }
        goto block_4;
    }
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
block_4:
        Menu_CloseCurrent();
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
    }
}

s32 NuMemAlloc(s32, s32 *, s32);
extern s32 lbl_8019BB3C[];
extern s32 lbl_80408BA8;
extern s32 lbl_80408C5C;
extern s32 lbl_80408C60;
extern s32 lbl_80408C64;
extern s32 lbl_80408C68;
extern s32 lbl_80408C6C;
extern s32 lbl_80408C70;

void fn_8007ABA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 > 3) {
        var_r3 = 3;
    }
    lbl_80408BA8 = var_r3;
    lbl_80408C5C = arg2;
    lbl_80408C6C = arg1;
    lbl_80408C64 = arg3;
    lbl_80408C60 = NuMemAlloc(arg3 + 4, lbl_8019BB3C, 0xDE);
    lbl_80408C68 = arg4;
    lbl_80408C70 = arg5;
}

s32 fn_80077038();
extern u8 lbl_80408A57;
extern s32 lbl_80408AA8;
extern f32 lbl_8040AF18;

void fn_800795C0(void *arg0)
{
  s8 *new_var3;
  s32 new_var4;
  s8 *new_var2;
  void *new_var;
  fn_80077038();
  new_var4 = lbl_80408AA8;
  new_var = arg0;
  new_var3 = (s8 *) arg0;
  new_var2 = new_var3 + 0x9C;
  *((f32 *) new_var2) = (f32) lbl_8040AF18;
  fn_800769B4(new_var, new_var4, lbl_80408A57);
}

extern s32 lbl_80408A38;

void fn_8007907C(void) {
    s32 var_r0;

    var_r0 = lbl_8034705C[lbl_80408BB4];
    if (var_r0 != 0) {
        var_r0 = 1;
    }
    lbl_80408A38 = var_r0;
}

s32 memset();

void Menu_ResetStack(void) {
    memset(gMenuStack, 0, 0x8C0);
    (*(s16 *)((s8 *)(gMenuStack) + (0x14))) = -1;
    gMenuDepth = 0;
}

void fn_80078E90(void *arg0) {
    s16 temp_r0;
    void *temp_r11;
    void *temp_r11_2;

    temp_r0 = (*(s16 *)((s8 *)(arg0) + (0x14)));
    if (temp_r0 != -1) {
        temp_r11 = (temp_r0 * 0x1C) + ((s8 *)gRegisteredMenuDefinitions);
        if ((s16) (*(s16 *)((s8 *)(temp_r11) + (0x14))) != -1) {
            (*(s16 *)((s8 *)(temp_r11) + (0x14))) = (s16) (*(u16 *)((s8 *)(arg0) + (8)));
        }
        temp_r11_2 = ((*(s16 *)((s8 *)(arg0) + (0x14))) * 0x1C) + ((s8 *)gRegisteredMenuDefinitions);
        if ((s16) (*(s16 *)((s8 *)(temp_r11_2) + (0x16))) != -1) {
            (*(s16 *)((s8 *)(temp_r11_2) + (0x16))) = (s16) (*(u16 *)((s8 *)(arg0) + (0xA)));
        }
    }
}

#define Menu_CloseCurrent ((s32 (*)())Menu_CloseCurrent)
extern f32 lbl_8019BAD4[];
extern f32 lbl_80408C40;

void fn_80079F68(void) {
    if ((lbl_80408C40 <= lbl_8019BAD4[0])) {
        Menu_CloseCurrent();
    }
}
#undef Menu_CloseCurrent

#define Menu_CloseCurrent ((s32 (*)())Menu_CloseCurrent)
#define Menu_Open ((s32 (*)(s32, s32, s32))Menu_Open)
#define fn_80076194 ((s32 (*)())fn_80076194)
extern f32 lbl_8019BAE4[];
extern f32 lbl_8019BAE8[];
extern s32 lbl_80408BC0;
extern s32 lbl_80408BC4;
extern f32 lbl_80408C18;
extern f32 lbl_80408C2C;
extern s32 lbl_80408C68;


#undef Menu_CloseCurrent
#undef Menu_Open
#undef fn_80076194

void fn_8007A288(void)
{
  s32 temp_cr0_eq;
  ;
  if ((((s32) lbl_80408BC0) == 0) == 0)
  {
    lbl_80408C18 = lbl_8019BAE4[0];
  }
  if ((((((s32) lbl_80408BC0) == 0) == 0) || (((s32) lbl_80408BC4) != 0)) || (lbl_80408C18 > lbl_8019BAE8[0]))
  {
    lbl_80408C2C = lbl_8019BAE4[0];
  }
  if ((((s32) lbl_80408BC0) != 0) && (((s32) lbl_80408224) != 0))
  {
    lbl_80408BC0 = 0;
    lbl_80408BC8 = 1;
  }
  if (lbl_80408C2C <= lbl_8019BAE8[0])
  {
    if (((s32) lbl_80408BC8) != 0)
    {
      ((s32 (*)()) Menu_CloseCurrent)();
      return;
    }
    if (((((s32) lbl_80408C68) != 0) && (((s32) lbl_80408234) != (-1))) && (((s32) lbl_80408BCC) == 0))
    {
      ((s32 (*)()) fn_80076194)();
      ((s32 (*)()) fn_80076194)();
      ((s32 (*)(s32, s32, s32)) Menu_Open)(0x3F2, 1, -1);
      return;
    }
    ((s32 (*)()) fn_80076194)();
    ((s32 (*)()) Menu_CloseCurrent)();
  }
}

s32 fn_80079050(void) {
    return gRegisteredMenuDefinitions[gMenuStack[gMenuDepth].id].id;
}

extern s32 lbl_80408C04;

void fn_80079C48(void *arg0) {
    s32 var_r31;
    s32 var_r3;
    s32 var_r4;

    var_r31 = 0;
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x68))) != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x50))) = (s32) lbl_80408A44;
        if ((s16) (*(s16 *)((s8 *)(arg0) + (0xA))) != 1) {
            if ((s32) lbl_80408C4C != 0) {
                if ((s32) gRegisteredMenuDefinitions[gMenuStack[gMenuDepth - 1].id].id != 0x3FA) {
                    fn_80076194();
                    var_r3 = 0x3FF;
                    var_r4 = -1;
                    goto block_8;
                }
                goto block_6;
            }
            if ((s32) lbl_8040821C != 2) {
block_6:
                Menu_CloseCurrent();
            } else {
                lbl_80408C00 = 0;
                lbl_80408BFC = 1;
                lbl_80408C04 = 0;
                fn_80076194();
                var_r3 = 0x3EF;
                var_r4 = 0;
block_8:
                Menu_Open(var_r3, var_r4, -1);
            }
        } else {
            goto block_10;
        }
    } else if ((s32) (*(s32 *)((s8 *)(arg0) + (0x6C))) != 0) {
block_10:
        var_r31 = 1;
    }
    if (var_r31 != 0) {
        fn_80076194();
        Menu_Open(0x3EE, 1, -1);
    }
}

s32 fn_80078F68(void)
{
    s32 id = gRegisteredMenuDefinitions[gMenuStack[gMenuDepth].id].id;
    return id >= 0x3E8 && id <= 0x3FF;
}

s32 fn_8007900C(void)
{
    s32 id = gRegisteredMenuDefinitions[gMenuStack[gMenuDepth].id].id;
    switch (id) {
    case 0x3F4:
    case 0x3F5:
    case 0x3F6:
        return 1;
    }
    return 0;
}

s32 fn_80078FA4(void)
{
    switch (gRegisteredMenuDefinitions[gMenuStack[gMenuDepth].id].id) {
    case 0x3E9:
    case 0x3EF:
    case 0x3F1:
    case 0x3F6:
    case 0x3F7:
        return 1;
    }
    return 0;
}

void fn_800793C0(void)
{
    f32 one = 1.0f;
    f32 half = 0.5f;
    fn_8007B298(lbl_80408B88, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, 1.5f, 2, 0, 0,
                lbl_80408A54);
}

extern char *lbl_80408B1C;

void fn_80079304(u8* menu)
{
    f32 one = 1.0f;
    f32 half = 0.5f;
    fn_8007B298(lbl_80408B1C, 0.0f, 0.0f, one, half, half, half, 0, 255, 127, 0, 1.5f, -1, 0, 0,
                lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AB0;
        *(f32*)(menu + 0x9c) = time - offset;
        fn_800769B4(menu, action, lbl_80408A57);
    }
    {
        f32 time = lbl_8040AF18;
        s32 action = lbl_80408AAC;
        *(f32*)(menu + 0x9c) = time;
        fn_800769B4(menu, action, lbl_80408A57);
    }
}

extern f32 lbl_8019B938[], lbl_8019B93C[], lbl_8019B940[], lbl_8019B944[], lbl_8019B948[];
extern u8 lbl_8040A61B, lbl_8040A61F, lbl_8040A623;
extern f32 lbl_8040AF1C;

void fn_80078EE4(void)
{
    fn_8007B298(lbl_803D992C, 0.0f, lbl_8040AF1C - 0.2f, 1.0f, 0.5f, 0.5f, 0.5f, 0, lbl_8040A61B,
                lbl_8040A61F, lbl_8040A623, 1.2f, 1, 0, 0, lbl_80408A54);
}

extern s32 lbl_80408A68, lbl_80408B74;
extern char *lbl_80408B70;

void fn_800794E8(u8* menu)
{
    char buf[0x80];
    sprintf(buf, lbl_80408B70, lbl_80408A68);
    fn_8007B298(buf, 0.0f, 0.0f, 1.0f, 0.5f, 0.5f, 0.5f, 0, 255, 127, 0, 1.3f, 3, 0, 0,
                lbl_80408A54);
    {
        f32 time = lbl_8040AF18;
        f32 offset = lbl_80408A84;
        s32 action = lbl_80408AB0;
        *(f32*)(menu + 0x9c) = time - (offset + offset);
        fn_800769B4(menu, action, lbl_80408A57);
    }
    fn_800769B4(menu, lbl_80408B74, lbl_80408A57);
    fn_800769B4(menu, lbl_80408AAC, lbl_80408A57);
}

extern f32 lbl_8019BB70[];
extern f32 lbl_8019BB74[];
extern f32 lbl_8019BB78[];
extern s32 lbl_80408214, lbl_80408238, lbl_8040823C;
extern s32 lbl_80408BDC, lbl_80408BE0, lbl_80408BEC, lbl_80408BF4, lbl_80408BF8;
extern s32 lbl_80408C04, lbl_80408C08;
extern f32 lbl_80408BE4, lbl_80408BE8, lbl_80408C28, lbl_80408C3C, lbl_80408C44;
void fn_8000759C(void *dst, void *src, s32 size);
void fn_80042E28(void);
void fn_80042E6C(s32 arg0, s32 arg1, s32 arg2);
void fn_80042EE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void fn_80042F58(s32 arg0);
void fn_80042F8C(void);

static inline s32 SaveChecksum(s32 *buf, s32 size)
{
    s32 sum = 0;
    s32 i;
    for (i = 0; i < size / 4; i++) {
        sum += buf[i];
    }
    return sum;
}

void fn_8007A448(void)
{
    s32 cb;

    if (lbl_80408C18 > lbl_8019BB70[0]) {
        lbl_80408C18 -= lbl_8019BB74[0];
    } else if (lbl_80408C2C > lbl_8019BB70[0]) {
        lbl_80408C2C -= lbl_8019BB74[0];
    }
    if (lbl_80408C1C > lbl_8019BB70[0]) {
        lbl_80408C1C -= lbl_8019BB74[0];
    } else {
        lbl_80408238 = 0;
        if (lbl_80408C30 > lbl_8019BB70[0]) {
            lbl_80408C30 -= lbl_8019BB74[0];
        }
    }
    {
        f32 t;
        if ((t = lbl_80408BE4) > lbl_8019BB70[0]) {
            lbl_80408BE4 = t - lbl_8019BB74[0];
        } else if ((t = lbl_80408BE8) > lbl_8019BB70[0]) {
            lbl_80408BE8 = t - lbl_8019BB74[0];
            if (lbl_80408BE8 <= lbl_8019BB70[0]) {
                lbl_80408BEC = 0;
            }
        }
    }
    if (lbl_80408C20 > lbl_8019BB70[0]) {
        lbl_80408C20 -= lbl_8019BB74[0];
    } else if (lbl_80408C34 > lbl_8019BB70[0]) {
        lbl_80408C34 -= lbl_8019BB74[0];
    }
    if (lbl_80408C24 > lbl_8019BB70[0]) {
        lbl_80408C24 -= lbl_8019BB74[0];
    } else if (lbl_80408C38 > lbl_8019BB70[0]) {
        lbl_80408C38 -= lbl_8019BB74[0];
    }
    if (lbl_80408C28 > lbl_8019BB70[0]) {
        lbl_80408C28 -= lbl_8019BB74[0];
    } else if (lbl_80408C3C > lbl_8019BB70[0]) {
        lbl_80408C3C -= lbl_8019BB74[0];
    }
    if (lbl_80408C40 > lbl_8019BB70[0]) {
        lbl_80408C40 -= lbl_8019BB74[0];
    } else if (lbl_80408C44 > lbl_8019BB70[0]) {
        lbl_80408C44 -= lbl_8019BB74[0];
    }

    if (lbl_8040821C != 2) {
        lbl_80408C08 = 0;
    }
    if (lbl_8040823C != 0) {
        if (lbl_80408BE0 != 0) {
            lbl_80408C30 = lbl_8019BB78[0];
        }
        lbl_80408BE0 = 0;
        lbl_80408BEC = 0;
        lbl_80408BDC = 0;
        lbl_80408BE4 = lbl_8019BB70[0];
        lbl_80408BE8 = lbl_8019BB70[0];
        lbl_80408BF0 = 1;
    }

    if (lbl_80408BC0 != 0) {
        if (lbl_80408210 == 1 && lbl_8040821C == 2 && lbl_80408220 != 0) {
            lbl_80408C18 = lbl_8019BB78[0];
            if (lbl_80408C60 == 0 || lbl_80408C64 == 0) {
                lbl_80408BC8 = 1;
                lbl_80408BC0 = 0;
                lbl_80408BC4 = 0;
                return;
            }
            fn_80042E6C(lbl_80408BB4, lbl_80408C60, lbl_80408C64 + 4);
            lbl_80408BC0 = 0;
            lbl_80408BCC = 0;
            if (lbl_80408210 != 1) {
                lbl_80408BC4 = 1;
                lbl_80408BC8 = 0;
            } else {
                lbl_80408BC4 = 0;
                lbl_80408BC8 = 1;
            }
        }
    } else if (lbl_80408BC4 != 0 && lbl_80408210 == 1) {
        lbl_80408BC4 = 0;
        if (lbl_80408214 == 0) {
            if (SaveChecksum((s32 *)lbl_80408C60, lbl_80408C64) != *(s32 *)(lbl_80408C60 + lbl_80408C64)) {
                lbl_80408BCC = 1;
                lbl_80408234 = -1;
            } else {
                fn_8000759C((void *)lbl_80408C5C, (void *)lbl_80408C60, lbl_80408C64);
                lbl_80408A30 = 1;
            }
        } else {
            lbl_80408BC8 = 1;
        }
    }

    if (lbl_80408BDC != 0) {
        if (lbl_80408234 != -1) {
            lbl_80408BE0 = 1;
            lbl_80408BEC = 1;
            lbl_80408BDC = 0;
            lbl_80408BE4 = lbl_8019BB78[0];
        } else {
            lbl_80408BDC = 0;
        }
    } else if (lbl_80408BE0 != 0) {
        if (lbl_80408BD0 == 0 && lbl_80408BD4 == 0 && lbl_80408BE4 <= lbl_8019BB70[0]) {
            lbl_80408BD0 = 1;
            lbl_80408BB4 = lbl_80408234;
        }
    }

    if (lbl_80408BD0 != 0) {
        if (lbl_80408210 == 1 && lbl_8040821C == 2 && lbl_80408220 != 0) {
            lbl_80408238 = 1;
            lbl_80408C1C = lbl_8019BB78[0];
            if (lbl_80408C60 == 0 || lbl_80408C64 == 0) {
                lbl_80408BD8 = 1;
                lbl_80408BD0 = 0;
                lbl_80408BD4 = 0;
                return;
            }
            if (lbl_80408C6C != 0) {
                cb = ((s32 (*)(void))lbl_80408C6C)();
            } else {
                cb = -1;
            }
            fn_8000759C((void *)lbl_80408C60, (void *)lbl_80408C5C, lbl_80408C64);
            *(s32 *)(lbl_80408C60 + lbl_80408C64) = SaveChecksum((s32 *)lbl_80408C60, lbl_80408C64);
            fn_80042EE0(lbl_80408BB4, lbl_80408C60, lbl_80408C64 + 4, cb);
            lbl_80408BD0 = 0;
            if (lbl_80408210 != 1) {
                lbl_80408BD8 = 0;
                lbl_80408BD4 = 1;
            } else {
                lbl_80408BD4 = 0;
                lbl_80408BD8 = 1;
            }
            lbl_80408C08 = 0;
        }
    } else if (lbl_80408BD4 != 0 && lbl_80408210 == 1) {
        lbl_80408BD4 = 0;
        if (lbl_80408214 != 0) {
            lbl_80408BD8 = 1;
        }
        if (lbl_80408BE0 != 0) {
            lbl_80408BE0 = 0;
            lbl_80408BE8 = lbl_8019BB78[0];
        }
    }

    if (lbl_80408BF4 != 0) {
        if (lbl_80408210 == 1 && lbl_8040821C == 2 && lbl_80408220 != 0) {
            fn_80042F58(lbl_80408BB4);
            lbl_80408BF4 = 0;
            lbl_80408BF8 = 1;
            lbl_80408C28 = lbl_8019BB78[0];
        }
    } else if (lbl_80408BF8 != 0 && lbl_80408210 == 1) {
        lbl_80408BF8 = 0;
    }

    if (lbl_80408BFC != 0) {
        if (lbl_80408210 == 1 && lbl_8040821C == 2) {
            fn_80042E28();
            lbl_80408C00 = 1;
            lbl_80408C20 = lbl_8019BB78[0];
            lbl_80408BFC = 0;
            lbl_80408C04 = 0;
            lbl_80408C08 = 0;
        }
    } else if (lbl_80408C00 != 0 && (lbl_80408210 == 3 || lbl_80408210 == 1)) {
        if (lbl_80408214 == 0) {
            lbl_80408C00 = 0;
            lbl_80408C08 = 1;
        } else {
            lbl_80408C00 = 0;
            lbl_80408C04 = 1;
        }
    }

    if (lbl_80408C0C != 0) {
        if (lbl_80408210 == 1 && lbl_8040821C == 2) {
            fn_80042F8C();
            lbl_80408C10 = 1;
            lbl_80408C0C = 0;
            lbl_80408C14 = 0;
            lbl_80408C24 = lbl_8019BB78[0];
        }
    } else if (lbl_80408C10 != 0 && (lbl_80408210 == 3 || lbl_80408210 == 1)) {
        if (lbl_80408214 == 0) {
            lbl_80408C10 = 0;
        } else {
            lbl_80408C10 = 0;
            lbl_80408C14 = 1;
        }
    }
}
