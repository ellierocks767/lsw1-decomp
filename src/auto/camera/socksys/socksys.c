#include "types.h"
#include "game/levels.h"
#include "numath/numath.h"

/* 0x10 bytes and up of a character animation record (OpenSaga CHARACTERANIM_s). */
struct socksys_anim_rec_s {
    u8 pad0[0x10];
    f32 blend_out_time;
    f32 playback_rate;
};

/* 0x54-byte character model (OpenSaga CHARACTERMODEL_s): per-animation tables. */
struct socksys_model_s {
    u8 pad0[0x8];
    struct socksys_anim_rec_s** anims;
    void** anim_data;
    u8 pad10[0x54 - 0x10];
};

/* Character system behind lbl_80408DF0 (OpenSaga apicharsys). */
struct socksys_a_s {
    s32 character_count;
    u8 pad4[4];
    s32 anim_capacity;
    u8 padC[0x18 - 0xC];
    struct socksys_model_s* models;
    s16* ids;
};

struct socksys_item_s {
    u8 pad0[0x20];
    f32 f20;
    f32 values[4];
};

struct socksys_list_s {
    u8 pad0[8];
    struct socksys_item_s** items;
    s32* present;
};

/* Sock (camera rail) node state; fn_80095558 initialises it and fn_80095630 picks the
 * sub-record whose id matches. */
struct socksys_b_s {
    f32 f0;
    f32 f4;
    u8 pad8[0x10 - 0x8];
    f32 f10;
    f32 f14;
    u8 pad18[0x3c - 0x18];
    u8 b3c;
    u8 flag;
    s16 s3e;
    s16 s40;
    s16 s42;
    s16 s44;
    s16 s46;
    u8 pad48[0x4c - 0x48];
    u8 b4c;
    u8 b4d;
    u8 b4e;
    u8 pad4f[0x52 - 0x4f];
    s16 s52;
};

/* 0x14-byte effect records (lbl_80409410->unk1B8): fn_800958F8 spawns record idx. */
struct socksys_fx_item_s {
    s32 id;
    u8 pad4[0x14 - 0x4];
};

struct socksys_fx_s {
    u8 pad0[4];
    s32 count;
    struct socksys_fx_item_s *items;
};

extern struct socksys_a_s* lbl_80408DF0;
extern s32 lbl_80408DE4;
extern s32 lbl_8040AF38;
extern f32 lbl_8019DFB8[];

void fn_80094F90(s32 a)
{
    lbl_80408DE4 = a;
}

s32 fn_80094F98(void)
{
    return lbl_80408DE4;
}

s32 fn_800952D8(s32 idx)
{
    if (lbl_80408DF0->ids[idx] != -1) {
        return 1;
    }
    return 0;
}

f32 fn_80095688(struct socksys_list_s* l, s32 idx)
{
    if (idx != -1 && l->present[idx] != 0) {
        return l->items[idx]->f20;
    }
    return lbl_8019DFB8[0];
}

s16 fn_800956C0(struct socksys_b_s* o)
{
    if (o->flag != 0) {
        return o->s40;
    }
    return o->s42;
}

f32* fn_80095724(struct socksys_list_s* l, s32 idx)
{
    if (l->present[idx] != 0) {
        return &l->items[idx]->values[0];
    }
    return 0;
}

void fn_80095874(s32 a)
{
    lbl_8040AF38 = a;
}

extern u32 NuRandInt(void);
extern f32 lbl_8019DFC4[];
extern f32 lbl_8019DFC8[];
extern f32 lbl_8019DFCC[];
extern f32 lbl_8019DFD0[];

s32 ParticlesPerFrame(f32 rate, f32 time)
{
    s32 scaled = (s32)((rate * lbl_8019DFC4[0]) * (time * lbl_8019DFC8[0]));
    s32 count = 0;
    while (scaled > 0xffff) {
        scaled -= 0x10000;
        count++;
    }
    if ((NuRandInt() >> 16) < (u32)scaled)
        count++;
    return count;
}

s32 fn_800957E0(f32 rate, f32 time)
{
    s32 scaled = (s32)(((rate / lbl_8019DFCC[0]) * lbl_8019DFD0[0]) * (time * lbl_8019DFCC[0]));
    s32 count = 0;
    while (scaled > 0xffff) {
        scaled -= 0x10000;
        count++;
    }
    if ((NuRandInt() >> 16) < (u32)scaled)
        count++;
    return count;
}

struct socksys_anim_s {
    f32 time;
    u8 unknown04[0x42];
    s16 index;
};
extern f32 fn_8000C038(void);
extern f32 fn_800215F0(void*);
extern f32 lbl_8019DFB4[];
void fn_800955A8(struct socksys_list_s* list, struct socksys_anim_s* anim)
{
    f32 time;
    if (list != NULL && anim != NULL && list->present[anim->index] != 0) {
        time = fn_8000C038();
        time = time * (fn_800215F0((void*)list->present[anim->index]) - lbl_8019DFB4[0]) + lbl_8019DFB4[0];
        anim->time = time;
    }
}

struct relation_object {
    u32 word0;
    u8 pad04[0x20c - 4];
    union {
        s32 flags;
        struct {
            u32 occupied : 1;
            u32 : 31;
        };
    };
    u8 pad210[0x81];
    u8 index;
};
struct relation_pool { s32 stride; struct relation_object* objects; u64 masks[64]; };

struct relation_object *fn_800950D0(struct relation_pool *pool)
{
    struct relation_object *object;
    u32 index;

    if (pool != NULL) {
        object = pool->objects;
        for (index = 0; index < 64; index++) {
            if (object->occupied == 0) {
                object->word0 = 0;
                object->occupied = 1;
                object->index = index;
                return object;
            }
            object = (struct relation_object *)((u8 *)object + pool->stride);
        }
    }
    return NULL;
}

extern u64 __ashldi3();
extern void* memset();
void fn_80095128(struct relation_pool* pool, struct relation_object* object)
{
    u64* masks;
    struct relation_object* p;
    s32 i;
    if (pool != NULL && object != NULL) {
        if (pool->masks != NULL) {
            p = pool->objects;
            for (i = 64; i != 0; i--) {
                masks = pool->masks;
                if (p->flags < 0) {
                    u64* mask = &masks[p->index];
                    *mask &= ~__ashldi3(1ULL, object->index);
                }
                p = (struct relation_object*)((u8*)p + pool->stride);
            }
            pool->masks[object->index] = 0;
        }
        memset(object, 0, pool->stride);
    }
}

s32 memset(s32, s32, s32);

void fn_800951FC(void *arg0) {
    if (arg0 != NULL) {
        memset((*(s32 *)((s8 *)(arg0) + (4))), 0, (*(s32 *)((s8 *)(arg0) + (0))) << 6);
    }
}

s32 NuStrICmp(s32, s32);

s32 FindGameDebris(void *arg0, s32 arg1) {
    s32 var_r30;
    s32 var_r31;

    var_r31 = (*(s32 *)((s8 *)(arg0) + (0)));
    if (var_r31 < (s32) (*(s32 *)((s8 *)(arg0) + (4)))) {
        var_r30 = var_r31 * 0x14;
loop_2:
        if (NuStrICmp(arg1, (*(s32 *)((s8 *)(arg0) + (8))) + var_r30 + 4) == 0) {
            return var_r31;
        }
        var_r31 += 1;
        var_r30 += 0x14;
        if (var_r31 >= (s32) (*(s32 *)((s8 *)(arg0) + (4)))) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    return -1;
}

extern f32 lbl_8019E4F4[];

f32 fn_8009CB2C(s32 *arg0, void *arg1) {
    u8 temp_r0;
    void *temp_r9;

    if (arg0 != NULL) {
        temp_r0 = (*(u8 *)((s8 *)(arg1) + (1)));
        if ((s8) temp_r0 != -1) {
            temp_r9 = (*(s32 *)((s8 *)((((s8) temp_r0 * 0x104) + *arg0)) + (0x30))) + ((*(s16 *)((s8 *)(arg1) + (2))) << 7);
            return ((*(f32 *)((s8 *)(temp_r9) + (0x78))) * (*(f32 *)((s8 *)(arg1) + (4)))) + (*(f32 *)((s8 *)(temp_r9) + (0x7C)));
        }
    }
    return lbl_8019E4F4[0];
}

void fn_8009CB88(s32 *arg0, s32 arg1) {
    void *temp_r9;

    if ((arg0 != NULL) && (arg1 >= 0) && (arg1 <= 0x1F)) {
        temp_r9 = (arg1 * 0x104) + *arg0;
        (*(u16 *)((s8 *)(temp_r9) + (0x64))) = (u16) ((*(u16 *)((s8 *)(temp_r9) + (0x64))) & 0xFDFF);
    }
}

void fn_8009CBC4(s32 *arg0, s32 arg1) {
    void *temp_r9;

    if ((arg0 != NULL) && (arg1 >= 0) && (arg1 <= 0x1F)) {
        temp_r9 = (arg1 * 0x104) + *arg0;
        (*(u16 *)((s8 *)(temp_r9) + (0x64))) = (u16) ((*(u16 *)((s8 *)(temp_r9) + (0x64))) | 0x200);
    }
}

void fn_8009CAB4(s32 arg0, s32 arg1) {
    s32 temp_r11;
    s32 temp_r8;
    s32 var_r11;

    var_r11 = arg1;
    if (arg1 < 0) {
        var_r11 = arg1 + 0x1F;
    }
    temp_r8 = arg0 + 0xD8;
    temp_r11 = (var_r11 >> 5) * 4;
    *(s32 *)(temp_r8 + temp_r11) = *(s32 *)(temp_r8 + temp_r11) | (1 << (arg1 & 0x1F));
}

void fn_80093D84(void *, void *, void *, void *, void *, f32, s32);

void fn_80095B58(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, f32 farg0) {
    fn_80093D84(arg0, arg1, arg2, arg3, arg4, farg0, 0);
}

void fn_80093D84(void *, void *, void *, void *, void *, f32, s32);

void fn_80095B7C(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, f32 farg0) {
    fn_80093D84(arg0, arg1, arg2, arg3, arg4, farg0, 1);
}

struct socksys_b_s *fn_80095630(struct socksys_b_s *o, s32 id, s32 a, s32 b) {
    if (o->flag != 0) {
        if (a != 0 && o->s40 == id) {
            return (struct socksys_b_s *)&o->f14;
        }
        if (b != 0 && o->s3e == id) {
            return (struct socksys_b_s *)&o->f10;
        }
    } else if (o->s42 == id) {
        return o;
    }
    return NULL;
}

extern void fn_80063E14(s32 *, s32, void *, s32);

s32 fn_800958F8(struct socksys_fx_s *l, s32 idx, void *pos) {
    s32 sp8;

    if (idx >= 0 && idx < l->count && l->items[idx].id != -1) {
        sp8 = -1;
        fn_80063E14(&sp8, l->items[idx].id, pos, 1);
        return 1;
    }
    return 0;
}

extern f32 lbl_8019DFB0[];

void fn_80095558(struct socksys_b_s *o, s32 id) {
    f32 z;
    if (o != NULL) {
        z = lbl_8019DFB0[0];
        o->s46 = id;
        o->s44 = id;
        o->s42 = id;
        o->f4 = z;
        o->f14 = z;
        o->f0 = z;
        o->b3c = 4;
        o->s52 = -1;
        o->flag = 0;
        o->b4e = 0;
        o->b4c = 0;
        o->b4d = 0;
    }
}

extern f32 lbl_8019DF68[];
extern f32 lbl_8019DF6C[];
extern f32 lbl_8019DF70[];
extern f32 lbl_8019DF74[];
extern f32 lbl_8040AF3C;

f32 AnimDuration(s32 character, s32 anim, f32 start, f32 end, s32 subtract_blend) {
    f32 duration;
    struct socksys_model_s *model;

    if (character < 0 || character >= lbl_80408DF0->character_count)
        return lbl_8019DF68[0];
    if (anim < 0 || anim >= lbl_80408DF0->anim_capacity)
        return lbl_8019DF68[0];
    if (lbl_80408DF0->ids[character] == -1)
        return lbl_8019DF68[0];

    model = &lbl_80408DF0->models[lbl_80408DF0->ids[character]];
    if (model->anim_data[anim] == NULL)
        return lbl_8019DF68[0];

    duration = fn_800215F0(model->anim_data[anim]);
    if (start >= lbl_8019DF6C[0] && start < duration) {
        if (end >= lbl_8019DF6C[0] && end < duration && end > start) {
            duration = end - start;
        } else {
            duration -= start;
        }
    } else if (end >= lbl_8019DF6C[0] && end < duration && end > start) {
        duration = end - lbl_8019DF6C[0];
    } else {
        duration -= lbl_8019DF6C[0];
    }

    duration *= (lbl_8019DF6C[0] / (model->anims[anim]->playback_rate / lbl_8019DF70[0])) * lbl_8019DF74[0];
    lbl_8040AF3C = model->anims[anim]->blend_out_time;
    if (subtract_blend != 0) {
        duration -= lbl_8040AF3C;
    }
    return duration;
}

f32 NuFsqrt(f32);
f32 fn_8000ED40(f32);

struct socksys_speed_s {
    u8 unknown00[0x78];
    struct nuvec_s velocity;
    u8 unknown84[0x22c - 0x84];
    f32 speed;
    f32 horizontal_speed;
};


void fn_80094FA0(struct socksys_speed_s *object)
{
    f32 horizontal_sq;
    f32 zero = 0.0f;
    f32 x = object->velocity.x;
    f32 speed;

    if (x != zero || object->velocity.z != zero) {
        f32 z = object->velocity.z;
        f32 y;
        horizontal_sq = x * x + z * z;

        speed = NuFsqrt(horizontal_sq);
        y = object->velocity.y;
        object->horizontal_speed = speed;
        if (y != zero) {
            speed = NuFsqrt(y * y + horizontal_sq);
        }
    } else {
        object->horizontal_speed = zero;
        speed = fn_8000ED40(object->velocity.y);
    }
    object->speed = speed;
}

extern void *fn_8008F0C8(u32 *, u32 *, u32);

struct socksys_table_s {
    s32 stride;
    void *items;
    u8 unknown08[0x218 - 8];
};

struct socksys_table_s *fn_80095038(s32 stride, u32 *current, u32 *end)
{
    struct socksys_table_s *table = fn_8008F0C8(current, end, sizeof(*table));

    if (table != NULL) {
        ((void *(*)())memset)(table, 0, sizeof(*table));
        if (stride != 0) {
            u32 size = stride << 6;
            if ((table->items = fn_8008F0C8(current, end, size)) != NULL) {
                table->stride = stride;
                memset((s32)table->items, 0, size);
            }
        }
    }
    return table;
}

extern f32 lbl_8019DFBC[];

f32 fn_800956DC(struct socksys_list_s *list, s32 item, s32 component)
{
    if (list->present[item] != 0 && component >= 0 && component < 4) {
        return list->items[item]->values[component];
    }
    return lbl_8019DFBC[0];
}

s32 fn_8009595C(struct socksys_fx_s *effects, s32 index, f32 x, f32 y, f32 z)
{
    struct nuvec_s pos;
    s32 handle;

    if (index >= 0 && index < effects->count && effects->items[index].id != -1) {
        pos.x = x;
        pos.y = y;
        pos.z = z;
        handle = -1;
        fn_80063E14(&handle, effects->items[index].id, &pos, 1);
        return 1;
    }
    return 0;
}

struct socksys_id_s {
    u8 id;
    u8 unknown01;
};

s32 fn_80095AF8(struct socksys_id_s *entries, s32 id, s32 *out)
{
    if (entries != NULL) {
        s32 index = 0;
        while (entries->id != 0xff) {
            if (entries->id == id) {
                if (out != NULL) {
                    *out = index;
                }
                return 1;
            }
            entries++;
            index++;
        }
    }
    if (out != NULL) {
        *out = -1;
    }
    return 0;
}

extern void fn_80063E40(s32, void *, s32, s16, s16);

s32 fn_800959D4(struct socksys_fx_s *effects, s32 index, void *position, s32 count, s32 a, s32 b)
{
    s32 id;

    if (index >= 0 && index < effects->count && (id = effects->items[index].id) != -1 && count > 0) {
        fn_80063E40(id, position, count, (s16)a, (s16)b);
        return 1;
    }
    return 0;
}

struct socksys_joint_list_s {
    u8 unknown00[0x7e];
    u8 count;
};

struct socksys_joints_s {
    u8 unknown00[4];
    struct socksys_joint_list_s *list;
};

s32 fn_8009536C(struct socksys_joints_s *object, s16 *out, u32 selection)
{
    s32 count;
    u32 bit;
    s32 index;

    if (object == NULL) {
        return 0;
    }
    count = 0;
    bit = 1;
    for (index = 0; index < 32 && object->list->count > index; index++, bit <<= 1) {
        if (selection & bit) {
            *out = index;
            count++;
            out++;
        }
    }
    return count;
}

extern void fn_80063F80(s32, const struct nuvec_s *, const struct nuvec_s *, s32, s32, s32);

s32 fn_80095A44(struct socksys_fx_s *effects, s32 index, const struct nuvec_s *position, s32 count,
                const struct nuvec_s *direction)
{
    struct nuvec_s zero;
    struct nuvec_s *zero_direction;
    if (index >= 0 && index < effects->count && effects->items[index].id != -1 && count > 0) {
        zero_direction = &zero;
        ((void *(*)())memset)(zero_direction, 0, sizeof(zero));
        if (direction == NULL) {
            direction = zero_direction;
        }
        fn_80063F80(effects->items[index].id, position, direction, count, 0, 0);
        return 1;
    }
    return 0;
}

struct socksys_anim_range_s {
    u8 unknown00[0xc];
    f32 end;
    f32 start;
};

struct socksys_anim_ranges_s {
    u8 unknown00[8];
    struct socksys_anim_range_s **ranges;
};

extern f32 lbl_8019DFAC[];

f32 fn_80095510(struct socksys_anim_ranges_s *list, s32 first, s32 second)
{
    struct socksys_anim_range_s *a = list->ranges[first];
    struct socksys_anim_range_s *b;
    f32 duration;

    if (a == NULL) {
missing:
        return lbl_8019DFAC[0];
    }
    b = list->ranges[second];
    if (b == NULL) {
        goto missing;
    }
    duration = b->end;
    if (a->start < duration) {
        duration = a->start;
    }
    return duration;
}

struct socksys_anim_state_s {
    s16 index;
    u8 unknown02;
    u8 unknown03;
    s32 unknown04;
    void **definitions;
    void **data;
    void **names;
    u8 unknown14[0x40];
};

void fn_80095234(struct socksys_anim_state_s *state)
{
    state->index = 0;
    state->unknown02 = 0;
    state->unknown03 = 0;
    state->unknown04 = 0;

    if (lbl_80408DF0->anim_capacity != 0) {
        memset((s32)state->definitions, 0, lbl_80408DF0->anim_capacity * 4);
        memset((s32)state->data, 0, lbl_80408DF0->anim_capacity * 4);
        memset((s32)state->names, 0, lbl_80408DF0->anim_capacity * 4);
    }
    ((void *(*)())memset)(state->unknown14, 0, sizeof(state->unknown14));
}

#include "numath/numath.h"

struct nudlist_hgobj_s;
struct socksys_pois_s {
    u8 unknown00[4];
    struct nudlist_hgobj_s *hierarchy;
    u8 unknown08[0x14 - 8];
    s32 present[16];
};

extern void fn_8002B49C(struct nudlist_hgobj_s *, s32, struct numtx_s *, struct numtx_s *, struct numtx_s *);

void fn_800953D4(struct socksys_pois_s *object, struct numtx_s *basis, struct numtx_s *joints,
                 struct nuvec_s *positions, struct numtx_s *matrices)
{
    struct numtx_s matrix;
    s32 index;

    if (positions != NULL || matrices != NULL) {
        for (index = 0; index < 16; index++) {
            if (object->present[index] != 0) {
                fn_8002B49C(object->hierarchy, (u8)index, basis, joints, &matrix);
                if (positions != NULL) {
                    positions[index] = *(struct nuvec_s *)&matrix._30;
                }
                if (matrices != NULL) {
                    matrices[index] = matrix;
                }
            }
        }
    }
}

struct socksys_offset_anim_s {
    u8 unknown00[0x34];
    struct nuvec_s offset;
};

struct socksys_offset_anims_s {
    u8 unknown00[8];
    struct socksys_offset_anim_s **anims;
};

struct socksys_motion_s {
    u8 unknown00[8];
    f32 time;
    u8 unknown0c[0x4e - 0xc];
    s16 anim;
    u8 unknown50[0x60 - 0x50];
    struct socksys_offset_anims_s *animations;
    u8 unknown64[0xc8 - 0x64];
    struct numtx_s basis;
    u8 unknown108[0x248 - 0x108];
    struct nuvec_s last_position;
    u8 unknown254[0x260 - 0x254];
    f32 last_time;
    u8 unknown264[0x270 - 0x264];
    struct nuvec_s motion;
};

extern f32 lbl_8019DF90[];
extern f32 lbl_8019DF94[];

void fn_80093D84(void *destination, void *motion, void *position, void *unused,
                 void *translation, f32 unused_time, s32 include_y)
{
    struct numtx_s *out = destination;
    struct socksys_motion_s *state = motion;
    struct nuvec_s *pos = position;
    struct nuvec_s *base = translation;
    struct nuvec_s offset;
    s16 index;

    if (state->last_time > state->time) {
        state->last_position = *pos;
    }
    state->motion.x = pos->x - state->last_position.x;
    state->motion.y = include_y ? pos->y - state->last_position.y : lbl_8019DF90[0];
    state->motion.z = pos->z - state->last_position.z;
    NuVecMtxRotate(&state->motion, &state->motion, &state->basis);
    if (!include_y) {
        state->motion.y = lbl_8019DF90[0];
    }
    state->last_position = *pos;
    index = state->anim;
    state->last_time = state->time;
    if (index != -1) {
        struct socksys_offset_anims_s *animations = state->animations;
        f32 x;
        offset.x = animations->anims[index]->offset.x;
        x = base->x + offset.x;
        offset.z = animations->anims[index]->offset.z;
        out->_30 = x;
        out->_32 = base->z + offset.z;
        if (!include_y) {
            goto horizontal;
        }
        offset.y = state->animations->anims[state->anim]->offset.y;
        out->_31 = base->y + offset.y;
    } else {
        out->_30 = base->x;
        if (include_y) {
            out->_31 = base->y;
        }
        out->_32 = base->z;
    }
    if (include_y && state->motion.y == lbl_8019DF90[0]) {
        state->motion.y = lbl_8019DF94[0];
        return;
    }
horizontal:
    if (state->motion.x == lbl_8019DF90[0] && state->motion.z == lbl_8019DF90[0]) {
        state->motion.x = lbl_8019DF94[0];
    }
}

struct socksys_named_anim_s {
    const char *name;
    s16 index;
    u8 unknown06[0x40 - 6];
};

struct socksys_named_anims_s {
    u8 unknown00[0x10];
    struct socksys_named_anim_s *anims;
};

s16 FindAnimIX(struct socksys_named_anims_s *list, const char *name)
{
    struct socksys_named_anim_s *anim;
    const char *entry_name;

    if (list != NULL) {
        anim = list->anims;
        for (; anim != NULL && (entry_name = anim->name, entry_name != NULL); anim++) {
            if (NuStrICmp((s32)name, (s32)anim->name) == 0) {
                return anim->index;
            }
        }
    }
    return -1;
}

struct socksys_rotation_s {
    u16 x;
    u16 y;
};

struct socksys_rail_s {
    struct nugspline_s *camera;
    u8 pad04[0x28];
    u16 segment_count;
    u8 pad2e;
    u8 flag2f;
    u8 pad30[4];
    struct socksys_rotation_s *camera_rotations;
    struct socksys_rotation_s *midpoint_rotations;
    u8 pad3c[0xd8 - 0x3c];
    u32 overlapExclusionMask[1];
    u8 padDC[0x104 - 0xdc];
};

struct socksys_rails_s {
    struct socksys_rail_s *rails;
};

struct socksys_position_s {
    u8 pad00;
    s8 rail;
    s16 segment;
    f32 fraction;
    u8 pad08[0x18];
    struct socksys_rotation_s camera_rotation;
    struct socksys_rotation_s midpoint_rotation;
    s16 next_segment;
    u8 pad2a[2];
    f32 segment_position;
    f32 normalized_position;
};

extern struct nuvec_s lbl_802C4EE8;

static inline s32 socksys_rotation_delta(u16 from, u16 to)
{
    s32 delta = to - from;
    if (delta > 0x8000) {
        delta -= 0x10000;
    } else if (delta < -0x8000) {
        delta += 0x10000;
    }
    return delta;
}

static inline void socksys_point_on_segment(struct nuvec_s *out, struct nugspline_s *spline,
                                            s32 first, s32 next, f32 fraction)
{
    struct nuvec_s *from = (struct nuvec_s *)(spline->pts + first * spline->ptsize);
    struct nuvec_s *to = (struct nuvec_s *)(spline->pts + next * spline->ptsize);
    out->x = (to->x - from->x) * fraction + from->x;
    out->y = (to->y - from->y) * fraction + from->y;
    out->z = (to->z - from->z) * fraction + from->z;
}

void fn_8009758C(struct socksys_rails_s *system, struct socksys_position_s *position)
{
    if (system != NULL) {
        struct socksys_rail_s *rail = &system->rails[position->rail];
        s32 segment = position->segment;
        s32 next = position->next_segment;

        socksys_point_on_segment(&lbl_802C4EE8, rail->camera, segment, next, position->fraction);

        position->camera_rotation.x = (s32)(rail->camera_rotations[segment].x +
            (f32)socksys_rotation_delta(rail->camera_rotations[segment].x, rail->camera_rotations[next].x)
                * position->fraction);
        position->camera_rotation.y = (s32)(rail->camera_rotations[segment].y +
            (f32)socksys_rotation_delta(rail->camera_rotations[segment].y, rail->camera_rotations[next].y)
                * position->fraction);
        position->midpoint_rotation.x = (s32)(rail->midpoint_rotations[segment].x +
            (f32)socksys_rotation_delta(rail->midpoint_rotations[segment].x, rail->midpoint_rotations[next].x)
                * position->fraction);
        position->midpoint_rotation.y = (s32)(rail->midpoint_rotations[segment].y +
            (f32)socksys_rotation_delta(rail->midpoint_rotations[segment].y, rail->midpoint_rotations[next].y)
                * position->fraction);

        position->segment_position = (f32)position->segment + position->fraction;
        position->normalized_position = position->segment_position /
            (rail->flag2f ? (f32)(rail->segment_count + 1) : (f32)(s32)rail->segment_count);
    }
}

s32 fn_8009CAEC(const struct socksys_rail_s *rail, s32 index)
{
    // Signed operands keep ProDG from turning the mask into a right shift.
    s32 flags = (s32)rail->overlapExclusionMask[index / 32];
    s32 mask = (s32)(1U << (index & 31));

    if (flags & mask) {
        return 1;
    }
    return 0;
}
