#include "types.h"
#include "game/levels.h"

struct fn_80140918_s {
    s32 x;
    s32 y;
    s32 z;
};
extern struct fn_80140918_s lbl_801E1774[];

void fn_80140918(struct fn_80140918_s* a)
{
    lbl_801E1774[0] = *a;
}

s32 fn_800D875C(s32, s32);
s32 fn_800D99AC();
extern f32 lbl_801AF204[];
extern f32 lbl_801AF208[];
extern f32 lbl_80408E9C;
extern f32 lbl_80409578;
extern s32 lbl_80409AC0;
extern f32 lbl_8040A794;

void fn_80141DEC(void) {
    if ((s32) lbl_80409AC0 != -1) {
        if (lbl_8040A794 > lbl_801AF204[0]) {
            lbl_8040A794 -= lbl_80408E9C;
            return;
        }
        if ((lbl_80409578 == lbl_801AF208[0]) && (fn_800D99AC() == -1)) {
            fn_800D875C(lbl_80409AC0, 0);
        }
    }
}

s32 fn_80140E78(void *);

void fn_801410F4(void *arg0) {
    s32 var_r30;
    void *var_r31;

    var_r30 = 0;
    if (arg0 != NULL) {
        var_r31 = (*(void **)((s8 *)(arg0) + (0xC)));
        if (var_r30 < (s32) (*(u16 *)((s8 *)(arg0) + (2)))) {
            do {
                if (var_r31 != NULL) {
                    fn_80140E78(var_r31);
                    var_r31 = (*(void **)((s8 *)(var_r31) + (0x78)));
                }
                var_r30 += 1;
            } while (var_r30 < (s32) (*(u16 *)((s8 *)(arg0) + (2))));
        }
    }
}

void fn_801433C0(void *records, s32 count)
{
    s32 remaining;
    u8 *cursor;

    /* Retail walks the 0x50-byte records with its cursor at offset 0x20. */
    remaining = count;
    if (count > 0) {
        cursor = (u8 *)records + 0x20;
        do {
            *(s16 *)(cursor + 0x22) = 0;
            *(f32 *)(cursor - 0x20) = 80.0f;
            *(f32 *)(cursor - 0x1C) = 55.0f;
            *(f32 *)(cursor - 0x18) = 200.0f;
            *(f32 *)(cursor - 0x14) = 1.0f;
            *(f32 *)(cursor + 0x10) = 0.0f;
            *(f32 *)(cursor + 0x14) = 0.0f;
            *(f32 *)(cursor + 0x18) = 0.0f;
            *(f32 *)(cursor + 0x1C) = 0.0f;
            *(f32 *)(cursor - 0x10) = 0.0f;
            *(f32 *)(cursor - 0xC) = 0.0f;
            *(f32 *)(cursor - 4) = 0.0f;
            *(f32 *)cursor = 0.0f;
            *(f32 *)(cursor + 4) = 0.0f;
            (*(f32 *)((s8 *)(cursor) + (8))) = 0.0f;
            *(f32 *)(cursor + 0xC) = 0.0f;
            (*(f32 *)((s8 *)(cursor) + (-8))) = 200.0f;
            *(s32 *)(cursor + 0x28) = 0xFFFFFF;
            *(s16 *)(cursor + 0x20) = 0;
            *(f32 *)(cursor + 0x2C) = 5.0f;
            cursor += 0x50;
            remaining -= 1;
        } while (remaining != 0);
    }
}

struct CHRIS43468_s {
    f32 field00[4];
    void *field10;
    s32 field14;
    s32 field18;
    s32 field1C;
    u8 pad20[0xC];
    u8 *field2C;
};

struct CHRISBUFFER_s {
    void *entries;
    s32 capacity;
    s32 count;
};

extern u8 lbl_801E17C0[];
extern f32 lbl_802E9B40[4];

void *memset(void *dest, int ch, unsigned int count);

void fn_80143468(struct CHRIS43468_s *state, u8 *data)
{
    struct CHRISBUFFER_s *buffer;
    s32 capacity;

    if (lbl_80409410->unk198 == 0x56) {
        lbl_802E9B40[0] = 4.0f;
        lbl_802E9B40[1] = 4.0f;
        lbl_802E9B40[2] = 4.0f;
        lbl_802E9B40[3] = 1.0f;
        state->field00[0] = -141.0f;
        state->field00[1] = -121.0f;
        state->field00[2] = -1034.0f;
        state->field00[3] = 1.0f;
        state->field10 = NULL;
    } else {
        lbl_802E9B40[0] = 4.0f;
        lbl_802E9B40[1] = 4.0f;
        lbl_802E9B40[2] = 4.0f;
        lbl_802E9B40[3] = 1.0f;
        state->field00[0] = -141.0f;
        state->field00[1] = -121.0f;
        state->field00[2] = -1034.0f;
        state->field00[3] = 1.0f;
        state->field10 = lbl_801E17C0;
    }
    buffer = (struct CHRISBUFFER_s *)(data + 0x636D0);
    if (buffer != NULL) {
        capacity = buffer->capacity;
        if (capacity != 0) {
            memset(buffer->entries, 0, capacity * 0x60);
            buffer->count = 0;
        }
    }
    state->field14 = 0;
    state->field1C = 4;
    state->field18 = 0;
    state->field2C = data;
    *(f32 *)(data + 0x6372C) = 1.0f;
    *(f32 *)(data + 0x63730) = 1.0f;
}
