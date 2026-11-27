#include "types.h"


s32 fn_80042E20(void)
{
    return 0;
}

struct PoolNode;
struct Pool {
    struct PoolNode *free_head, *free_tail, *used_head, *used_tail;
    u16 count, size, stride, used;
    s32 owner;
};
struct PoolNode { struct Pool* pool; struct PoolNode *next, *prev; u32 flags; };
extern s32 lbl_8040810C;
extern void (*lbl_80407B1C)(void), (*lbl_80407B20)(void);

struct PoolSlot { struct Pool* pool; struct PoolSlot* next; struct PoolSlot* prev; u16 index; u16 flags; };

struct Pool* fn_80040B4C(s32 count, s32 size, u32* mem, u32* end, s32 align)
{
    struct Pool* pool;
    struct Pool* ret;
    struct PoolSlot* node;
    struct PoolSlot* next;
    u32 total;
    s32 i;
    s32 stride = (size + align + 0xf) & ~(align - 1);

    total = count * stride + 0x20;
    pool = (struct Pool*)((*mem + (align - 1)) & ~(align - 1));
    ret = 0;
    *mem = (u32)pool;
    if (total < *end - (u32)pool) {
        ret = pool;
        *mem = (u32)ret + total;
        node = (struct PoolSlot*)((u8*)ret + 0x20);
        ret->free_head = (struct PoolNode*)node;
        ret->used_head = 0;
        ret->used_tail = 0;
        ret->count = count;
        ret->size = size;
        ret->stride = stride;
        ret->used = 0;
        next = (struct PoolSlot*)((u8*)node + stride);
        for (i = 1; i < count; i++) {
            node->next = next;
            node->pool = pool;
            node->index = i - 1;
            node = next;
            next = (struct PoolSlot*)((u8*)node + stride);
        }
        node->next = 0;
        pool->free_tail = (struct PoolNode*)node;
        node->index = i - 1;
        node->pool = pool;
        pool->owner = lbl_8040810C;
    }
    return ret;
}

void* fn_80040C24(struct Pool* pool)
{
    struct PoolNode* node;
    s32 owner;
    if (pool->free_head) {
        owner = lbl_8040810C;
        if (pool->owner != owner) lbl_80407B1C();
        node = pool->free_head;
        pool->free_head = node->next;
        if (!pool->free_head) pool->free_tail = 0;
        else pool->free_head->prev = 0;
        node->prev = pool->used_tail;
        if (pool->used_tail) pool->used_tail->next = node;
        else pool->used_head = node;
        node->next = 0;
        pool->used_tail = node;
        node->flags |= 0x8000;
        pool->used++;
        if (pool->owner != owner) lbl_80407B20();
        return node + 1;
    } else return 0;
}

void fn_80040D00(void* data)
{
    struct PoolNode* node = (struct PoolNode*)data;
    s32 owner = lbl_8040810C;
    struct Pool* pool = (--node)->pool;
    if (pool->owner != owner) lbl_80407B1C();
    if (node->next) node->next->prev = node->prev;
    else pool->used_tail = node->prev;
    if (node->prev) node->prev->next = node->next;
    else pool->used_head = node->next;
    node->prev = pool->free_tail;
    node->next = 0;
    if (pool->free_tail) pool->free_tail->next = node;
    else { pool->free_head = node; pool->free_tail = node; }
    pool->free_tail = node;
    pool->used--;
    node->flags &= ~0x8000;
    if (pool->owner != owner) lbl_80407B20();
}

void fn_800424F4();
extern s32 lbl_8040A434;

void fn_80042E28(void) {
    if (((s32) lbl_8040A434 == 0xB) || ((s32) lbl_8040A434 == 0x1A) || ((s32) lbl_8040A434 == 0x17)) {
        lbl_8040A434 = 0x11;
        fn_800424F4();
    }
}

void OSReport(void *, ...);
extern s32 lbl_80193898[];
extern s32 lbl_8019389C[];
extern s32 lbl_801938B0[];
extern s32 lbl_801938C4[];
extern s32 lbl_801938DC[];
extern s32 lbl_801938F0[];
extern s32 lbl_80193908[];
extern s32 lbl_80193920[];
extern s32 lbl_80193938[];
extern s32 lbl_80193954[];
extern s32 lbl_8019396C[];
extern s32 lbl_80193988[];
extern s32 lbl_8019399C[];
extern s32 lbl_801939B0[];
extern s32 lbl_801939C4[];
extern s32 lbl_801939DC[];
extern s32 lbl_801939F8[];
extern s32 lbl_80193A18[];
extern s32 lbl_80193A30[];
extern s32 lbl_80193A4C[];
extern s32 lbl_80193A64[];
extern s32 lbl_80193A80[];
extern s32 lbl_80193A9C[];
extern s32 lbl_80193AB4[];
extern s32 lbl_80193ACC[];
extern s32 lbl_80193AE4[];
extern s32 lbl_80193B00[];
extern s32 lbl_80193B18[];
extern s32 lbl_8040824C;
extern s32 lbl_8040A434;

void fn_80040E48(void) {
    s32 *var_r4;

    if ((s32) lbl_8040A434 != (s32) lbl_8040824C) {
        var_r4 = lbl_80193898;
        switch ((s32) lbl_8040A434) {               /* irregular */
        case 1:
            var_r4 = lbl_8019389C;
            break;
        case 2:
            var_r4 = lbl_801938B0;
            break;
        case 3:
            var_r4 = lbl_801938C4;
            break;
        case 4:
            var_r4 = lbl_801938DC;
            break;
        case 5:
            var_r4 = lbl_801938F0;
            break;
        case 6:
            var_r4 = lbl_80193908;
            break;
        case 7:
            var_r4 = lbl_80193920;
            break;
        case 8:
            var_r4 = lbl_80193938;
            break;
        case 9:
            var_r4 = lbl_80193954;
            break;
        case 10:
            var_r4 = lbl_8019396C;
            break;
        case 11:
            var_r4 = lbl_80193988;
            break;
        case 12:
            var_r4 = lbl_8019399C;
            break;
        case 13:
            var_r4 = lbl_801939B0;
            break;
        case 14:
            var_r4 = lbl_801939C4;
            break;
        case 15:
            var_r4 = lbl_801939DC;
            break;
        case 16:
            var_r4 = lbl_801939F8;
            break;
        case 17:
            var_r4 = lbl_80193A18;
            break;
        case 18:
            var_r4 = lbl_80193A30;
            break;
        case 19:
            var_r4 = lbl_80193A4C;
            break;
        case 20:
            var_r4 = lbl_80193A64;
            break;
        case 21:
            var_r4 = lbl_80193A80;
            break;
        case 22:
            var_r4 = lbl_80193A9C;
            break;
        case 23:
            var_r4 = lbl_80193AB4;
            break;
        case 24:
            var_r4 = lbl_80193ACC;
            break;
        case 25:
            var_r4 = lbl_80193AE4;
            break;
        case 26:
            var_r4 = lbl_80193B00;
            break;
        }
        OSReport(lbl_80193B18, var_r4);
        lbl_8040824C = lbl_8040A434;
    }
}

s32 (*fn_80009948(s32 *, s32))();
void fn_800424F4();
extern s32 lbl_80193B1C[];
extern s32 lbl_80193B78[];
extern s32 lbl_8040A434;
extern s32 lbl_8040A494;
extern s32 lbl_8040A498;
extern s32 lbl_8040A49C;

void fn_80042E6C(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 > 0x1C00) {
        fn_80009948(lbl_80193B1C, 0x73E)(lbl_80193B78);
        return;
    }
    if ((s32) lbl_8040A434 == 0xB) {
        lbl_8040A494 = arg0;
        lbl_8040A434 = 0xC;
        lbl_8040A498 = arg1;
        lbl_8040A49C = arg2;
        fn_800424F4();
    }
}

s32 (*fn_80009948(s32 *, s32))();
void fn_800424F4();
extern s32 lbl_80193B1C[];
extern s32 lbl_80193B78[];
extern s32 lbl_8040A434;
extern s32 lbl_8040A494;
extern s32 lbl_8040A498;
extern s32 lbl_8040A49C;
extern s32 lbl_8040A4A0;

void fn_80042EE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0x1C00) {
        fn_80009948(lbl_80193B1C, 0x76B)(lbl_80193B78);
        return;
    }
    if ((s32) lbl_8040A434 == 0xB) {
        lbl_8040A494 = arg0;
        lbl_8040A434 = 0xD;
        lbl_8040A498 = arg1;
        lbl_8040A49C = arg2;
        lbl_8040A4A0 = arg3;
        fn_800424F4();
    }
}

void *fn_80040DE8(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = arg0 + (((*(s16 *)((s8 *)(arg0) + (0x14))) * arg1) + 0x20);
    if ((*(s32 *)((s8 *)(temp_r3) + (0xC))) & 0x8000) {
        return temp_r3 + 0x10;
    }
    return NULL;
}

void *fn_80040E14(struct Pool *pool, void *data)
{
    struct PoolNode *node;

    if (data != NULL) {
        node = ((struct PoolNode *)data - 1)->next;
        if (node != NULL) {
            return node + 1;
        }
    } else {
        node = pool->used_head;
        if (node != NULL) {
            return node + 1;
        }
    }
    return NULL;
}

struct sl_tex_s {
    u8 pad0[0x0C];
    void *f0c;
    u8 pad10[0x28];
    void *f38;
};

void NuFileWrite(s32);
s32 fn_80024DC8(s32, void **, void **);
struct sl_tex_s *fn_80033FF0(s32);
extern s32 lbl_802995A0[];
extern s32 lbl_802999A0[];
extern s32 lbl_80408248;

void fn_800410B8(void)
{
    u8 buf[0x1000];
    void *end;
    void *cur;
    s32 tex;

    if (lbl_80408248 != 0) {
        cur = buf;
        end = &end;
        tex = fn_80024DC8(lbl_80408248, &cur, &end);
        if (tex != 0) {
            struct sl_tex_s *info = fn_80033FF0(tex);
            __builtin_memcpy(lbl_802995A0, info->f0c, 0x400);
            __builtin_memcpy(lbl_802999A0, info->f38, 0x200);
            NuFileWrite(tex);
        }
    }
}

s32 CARDFormatAsync(s32, void *);
void fn_80043040(void);
extern s32 lbl_8040A438;
extern s32 lbl_8040A440;
extern s32 lbl_8040A444;

static inline void sl_card_error(s32 res)
{
    switch (res) {
    case -128:
        lbl_8040A434 = 0x15;
        break;
    case -3:
        lbl_8040A434 = 0x16;
        break;
    case -6:
        lbl_8040A434 = 0x17;
        break;
    case -5:
        lbl_8040A434 = 0x18;
        break;
    case -2:
        lbl_8040A434 = 0x19;
        break;
    case -13:
        lbl_8040A434 = 0x1A;
        break;
    }
}

s32 fn_80041BB4(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A444 = 0;
    lbl_8040A440 = CARDFormatAsync(0, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    return 1;
}

s32 CARDDeleteAsync(s32, void *, void *);
s32 CARDOpen(s32, void *, void *);
s32 CARDReadAsync(void *, void *, s32, s32, void *);
s32 CARDCreateAsync(s32, void *, s32, void *, void *);

extern char lbl_80193B70[];
extern s32 lbl_802935A0[];
extern s32 lbl_80299BA0[];
extern s32 lbl_8040A458;
extern s32 lbl_8040A460;
extern s32 lbl_8040A468;

s32 fn_80041A74(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A444 = 0;
    lbl_8040A440 = CARDDeleteAsync(0, lbl_80193B70, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    lbl_8040A458 = 0;
    lbl_8040A460 = 0;
    return 1;
}

s32 fn_800417CC(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A440 = CARDOpen(0, lbl_80193B70, lbl_80299BA0);
    if (lbl_8040A440 != 0 && lbl_8040A440 != -4) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    if (lbl_8040A440 == 0) {
        lbl_8040A458 = 1;
    }
    return 1;
}

s32 fn_80041CE8(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A444 = 0;
    lbl_8040A440 = CARDReadAsync(lbl_80299BA0, lbl_802935A0, 0x6000, 0, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    return 1;
}

s32 fn_80041914(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A444 = 0;
    lbl_8040A440 = CARDCreateAsync(0, lbl_80193B70, ((0x5FFF / lbl_8040A468) + 1) * lbl_8040A468, lbl_80299BA0, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    lbl_8040A458 = 1;
    return 1;
}

s32 CARDFreeBlocks(s32, s32 *, s32 *);
s32 CARDSetStatusAsync(s32, s32, void *, void *);

struct sl_card_stat_s {
    u8 pad0[0x2E];
    s8 bannerFormat;
    u8 pad2f;
    u32 iconAddr;
    u16 iconFormat;
    u16 iconSpeed;
    u32 commentAddr;
};

extern s32 lbl_80299BA4[];
extern struct sl_card_stat_s lbl_80299BB4[];
extern s32 lbl_8040A448;
extern s32 lbl_8040A44C;
extern s32 lbl_8040A46C;
extern s32 lbl_8040A470;

s32 fn_80041674(void)
{
    if (lbl_8040A444 == 0) {
        return -1;
    }
    lbl_8040A440 = lbl_8040A448;
    if (lbl_8040A448 != 0) {
        sl_card_error(lbl_8040A448);
        return 0;
    }
    lbl_8040A440 = CARDFreeBlocks(0, &lbl_8040A46C, &lbl_8040A470);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    if (lbl_8040A44C != 0) {
        return 2;
    }
    return 1;
}

s32 fn_80042378(void)
{
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_80299BB4[0].iconFormat = (lbl_80299BB4[0].iconFormat & ~3) | 1;
    lbl_80299BB4[0].iconAddr = 0x40;
    lbl_80299BB4[0].iconSpeed |= 3;
    lbl_80299BB4[0].bannerFormat &= ~4;
    lbl_80299BB4[0].commentAddr = 0;
    lbl_8040A444 = 0;
    CARDSetStatusAsync(0, lbl_80299BA4[0], lbl_80299BB4, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    return 1;
}

s32 CARDMountAsync(s32, void *, void *, void *);
s32 CARDGetSerialNo(s32, void *);
void fn_80042FC8(void);

extern s32 lbl_80289560[];
extern s32 lbl_8034705C[];
extern s32 lbl_80408240;
extern s32 lbl_8040A450;
extern s32 lbl_8040A454;
extern s32 lbl_8040A474;
extern s32 lbl_8040A478;
extern s32 lbl_8040A47C;
extern s32 lbl_8040A480;
extern s32 lbl_8040A488;
extern s32 lbl_8040A48C;
extern s32 lbl_8040A490;

s32 NuTexAnimProgReadScript(void)
{
    s32 i;

    lbl_8040A44C = 0;
    if (lbl_8040A438 != 0) {
        sl_card_error(lbl_8040A438);
        return 0;
    }
    lbl_8040A444 = 0;
    lbl_8040A440 = CARDMountAsync(0, lbl_80289560, fn_80042FC8, fn_80043040);
    if (lbl_8040A440 != 0) {
        sl_card_error(lbl_8040A440);
        return 0;
    }
    for (i = 2; i >= 0; i--) {
        lbl_8034705C[i] = 0;
    }
    return 1;
}

extern s32 lbl_80408210;
extern s32 lbl_80408214;
extern s32 lbl_80408218;
extern s32 lbl_8040821C;
extern s32 lbl_80408220;
extern s32 lbl_80408224;
extern s32 lbl_8040822C;
extern s32 lbl_80408230;
extern s32 lbl_80408238;
extern s32 lbl_8040AE0C;
extern s32 lbl_8040ADF8;
extern s32 lbl_8040A45C;

void fn_800424F4(void)
{

    switch (lbl_8040A434) {
    case 2: case 3: case 4: case 5: case 6:
        lbl_80408210 = 3;
        lbl_80408214 = 0;
        break;
    case 1:
    case 9: case 10:
    case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x13:
        lbl_80408214 = lbl_80408210 = 0;
        break;
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        lbl_80408210 = 1;
        lbl_80408214 = 3;
        break;
    case 0xb:
    case 0x15:
        lbl_80408210 = 1;
        lbl_80408214 = 0;
        break;
    }
    lbl_80408218 = 0;
    lbl_8040821C = -1;
    lbl_80408220 = 0;
    lbl_80408230 = 0;
    lbl_8040822C = 0;
    lbl_8040AE0C = 0;
    lbl_80408238 = 0;
    lbl_8040ADF8 = 0;
    lbl_80408224 = 0;
    if (lbl_8040A490 == 1) {
        lbl_80408224 = lbl_8040A490;
        if (lbl_8040A474 != 0 && lbl_8040A480 != 0 && lbl_8040A478 == lbl_8040A488 && lbl_8040A47C == lbl_8040A48C) {
            lbl_80408224 = 0;
        }
    }
    lbl_8040A490 = 0;
    if (lbl_8040A434 == 0x19) {
        lbl_8040821C = 1;
        return;
    }
    if (lbl_8040A434 == 0x18) {
        lbl_8040821C = 3;
        return;
    }
    if (lbl_8040A450 != 0) {
        lbl_8040821C = 2;
        if (lbl_8040A470 <= 0 || lbl_8040A468 == 0) {
            lbl_80408218 = 0;
        } else {
            lbl_80408218 = lbl_8040A46C / lbl_8040A468;
        }
        if (lbl_8040A454 != 0) {
            lbl_80408220 = 1;
        }
        if (lbl_8040A458 != 0) {
            lbl_8040822C = 1;
            if (lbl_8040A460 != 0) {
                lbl_8040AE0C = 1;
            }
        }
        if (lbl_8040A458 != 0 && lbl_8040A460 == 0 && lbl_8040A45C != 0) {
            lbl_80408230 = 1;
        }
        if ((lbl_8040A434 >= 0xd && lbl_8040A434 <= 0x10) || lbl_8040A434 == 9 || lbl_8040A434 == 0xa
            || lbl_8040A434 == 0x11 || lbl_8040A434 == 0x12 || lbl_8040A434 == 0x13 || lbl_8040A434 == 0x14) {
            lbl_80408238 = 1;
        }
        if ((lbl_8040A434 >= 2 && lbl_8040A434 <= 5) || lbl_8040A434 == 7 || lbl_8040A434 == 8) {
            lbl_8040ADF8 = 1;
        }
    }
}
