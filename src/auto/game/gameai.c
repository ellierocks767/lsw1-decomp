#include "game/ai.h"
#include "game/creature.h"

struct fn_8012CD28_s {
    s32 x;
    s32 y;
    s32 z;
};
extern struct fn_8012CD28_s lbl_804017EC[];
extern s32 lbl_8040B010;

void fn_8012CD28(s32 a, struct fn_8012CD28_s* b)
{
    lbl_8040B010 = a;
    lbl_804017EC[0] = *b;
}

extern void *lbl_80408DF0;

s32 fn_8012CEF4(s32 arg0) {
    if ((arg0 != 0xFF) && (arg0 < (s32) (*(s32 *)((s8 *)(lbl_80408DF0) + (0))))) {
        return (*(s32 *)((s8 *)(((arg0 * 0x48) + (*(s32 *)((s8 *)(lbl_80408DF0) + (0x20))))) + (0xC)));
    }
    return 0;
}

s32 fn_80083A3C(s32 *);
s32 fn_80083A44(s32 *);
s32 fn_8008F224(s32 *);
s32 fn_8008F22C(s32 *);
s32 fn_8008F234(s32 *);
s32 fn_8008F23C(s32 *);
s32 fn_8008F244(s32 *);
s32 fn_8008F24C(s32 *);
s32 fn_8008F254(s32 *);
s32 fn_8008F25C(s32 *);
s32 fn_8008F264(s32 *);
s32 fn_8008F26C(s32 *);
s32 fn_8008F274(s32 *);
s32 fn_8008F27C(s32 *);
s32 fn_8008F284(s32 *);
s32 fn_8008F28C(s32 *);
s32 fn_8008F434(s32 *);
s32 fn_8008F43C(s32 *);
s32 fn_8008F444(s32 *);
s32 fn_8008F44C(s32 *);
s32 fn_8008F454(s32 *);
extern s32 fn_800AB85C[];
void fn_8012A138(u8 *w, s32 mode);
s32 fn_8012A2EC(u8 *c);
s32 fn_8012A3F4();
extern s32 fn_8012A8C8[];
extern s32 fn_8012AD98[];
u8 fn_8012CD50(char *name);
s32 fn_8012CE08(s32 arg0);
u8 fn_8012CE4C(s32 arg0);
u8 fn_8012CE74(char *name);
extern s32 fn_8012CF28[];
s32 fn_8012D068(s32 arg0);
s32 GameAIActionParseSpeed(char *name, u8 *out);
extern s32 fn_8012D13C[];
extern s32 fn_8012D1CC[];
extern s32 fn_8012D1E8[];
extern s32 fn_8012D204[];
extern s32 fn_8012D220[];
extern f32 lbl_801ACF04[];
extern f32 lbl_801ACF08[];
extern s32 lbl_801E0D08[];
extern s32 lbl_801E1158[];
extern f32 lbl_80408CDC;
extern s8 lbl_80408CE0;
extern s8 lbl_80408CE1;
extern s8 lbl_80408CE2;
extern f32 lbl_80408CE4;
extern f32 lbl_80408CE8;

void fn_8012A5D0(void)
{
  fn_80083A3C(lbl_801E1158);
  fn_80083A44(lbl_801E0D08);
  fn_8008F224(fn_8012CD50);
  fn_8008F22C(fn_8012CE08);
  fn_8008F234(fn_8012CE4C);
  fn_8008F23C(fn_8012CE74);
  fn_8008F244(fn_8012CEF4);
  fn_8008F24C(fn_8012CF28);
  fn_8008F254(fn_8012D068);
  fn_8008F25C(fn_800AB85C);
  fn_8008F264(fn_8012D13C);
  fn_8008F26C(fn_8012D1CC);
  fn_8008F274(fn_8012D1E8);
  fn_8008F27C(fn_8012D204);
  fn_8008F284(fn_8012D220);
  fn_8008F454(fn_8012A138);
  fn_8008F434(fn_8012AD98);
  fn_8008F43C(fn_8012A8C8);
  fn_8008F444(GameAIActionParseSpeed);
  fn_8008F44C(fn_8012A2EC);
  fn_8008F28C(fn_8012A3F4);
  lbl_80408CE0 = 1;
  lbl_80408CDC = lbl_801ACF04[0];
  lbl_80408CE2 = (lbl_80408CE1 = 0);
  lbl_80408CE8 = (lbl_80408CE4 = lbl_801ACF08[0]);
}

extern s32 lbl_804093EC;

s32 fn_8012CE08(s32 arg0) {
    u8 temp_r3;

    if ((arg0 != 0xFF) && ((s32) lbl_804093EC != 0)) {
        temp_r3 = *(u8 *)(((arg0 * 2) + lbl_804093EC));
        if ((s32) temp_r3 != 0xFF) {
            return (*(s32 *)((s8 *)(((temp_r3 * 0x48) + (*(s32 *)((s8 *)(lbl_80408DF0) + (0x20))))) + (0xC)));
        }
    }
    return 0;
}

u8 fn_8012CE4C(s32 arg0) {
    if ((arg0 != 0xFF) && ((s32) lbl_804093EC != 0)) {
        return *(u8 *)(((arg0 * 2) + lbl_804093EC));
    }
    return 0xFFU;
}

s32 fn_8012D068(s32 arg0) {
    s16 temp_r3;

    if (arg0 != 0xFF) {
        temp_r3 = *(s16 *)(((arg0 * 2) + (*(s32 *)((s8 *)(lbl_80408DF0) + (0x1C)))));
        if (temp_r3 != -1) {
            return (*(s32 *)((s8 *)(((temp_r3 * 0x54) + (*(s32 *)((s8 *)(lbl_80408DF0) + (0x18))))) + (4)));
        }
    }
    return 0;
}

void *fn_8008F0C8(void *, void *, u32);
void fn_8012CB04(void *);
s32 memset();

void *fn_8012CA84(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_r3;
    void *temp_r3_2;

    temp_r3 = fn_8008F0C8(arg0, arg1, 0x18);
    if (temp_r3 != NULL) {
        memset(temp_r3, 0, 0x18);
        temp_r3_2 = fn_8008F0C8(arg0, arg1, arg2 * 0xA8);
        (*(void **)((s8 *)(temp_r3) + (4))) = temp_r3_2;
        if (temp_r3_2 != NULL) {
            (*(s32 *)((s8 *)(temp_r3) + (0))) = arg2;
            fn_8012CB04(temp_r3);
        }
    }
    return temp_r3;
}

f32 fn_8000CD08(void *, void *, s32 *);
extern f32 lbl_801ACDB0[];

void *fn_801272FC(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    char sp8[0x10];
    f32 temp_f1;
    f32 var_f31;
    s16 temp_r9;
    s32 temp_r0;
    s32 var_r28;
    void *var_r27;
    void *var_r31;
    var_r27 = NULL;
    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x57C))) != 0) {
        return NULL;
    }
    var_f31 = lbl_801ACDB0[0];
    var_r28 = 0;
    var_r31 = (*(void **)((s8 *)(arg0) + (0x58C)));
    if (var_r28 < (s32) (*(s32 *)((s8 *)(arg0) + (0x590)))) {
        do {
            if (!((*(u16 *)((s8 *)(var_r31) + (0x20))) & 3) && ((arg2 == 0) || ((temp_r0 = (*(s32 *)((s8 *)((*(void **)((s8 *)(var_r31) + (0x4C)))) + (0x34))), (((temp_r0 & 0x02000000) == 0) == 0)) && (temp_r0 & 0x10000000) && ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg1) + (0x64)))) + (4))) & 4) && ((temp_r9 = (*(s16 *)((s8 *)(var_r31) + (0x22))), ((temp_r9 == -1) != 0)) || (temp_r9 != (s16) (*(s16 *)((s8 *)(arg1) + (0x282))))))) && ((temp_f1 = fn_8000CD08(var_r31 + 0x78, arg1 + 0x90, sp8), ((arg3 == 0) == 0)) || (temp_f1 < (*(f32 *)((s8 *)(var_r31) + (0x74))))) && (temp_f1 < var_f31)) {
                var_f31 = temp_f1;
                var_r27 = var_r31;
            }
            var_r28 += 1;
            var_r31 += 0xF4;
        } while (var_r28 < (*(s32 *)((s8 *)(arg0) + (0x590))));
    }
    return var_r27;
}

struct forceobj_s {
    char *name;
    u8 id[0xF0];
};

extern s32 NuStrICmp(const char *a, const char *b);
extern s32 fn_80013890(void *a, void *b);

struct forceobj_s *FindForceObject(void *world, char *name, void *id) {
    struct forceobj_s *obj = *(struct forceobj_s **)((s8 *)world + 0x58C);
    s32 i;

    if (*(s32 *)((s8 *)world + 0x57C) == 0) {
        for (i = 0; i < *(s32 *)((s8 *)world + 0x590); i++, obj++) {
            if (id != NULL) {
                if (fn_80013890(obj->id, id) != 0) return obj;
            } else if (NuStrICmp(obj->name, name) == 0) {
                return obj;
            }
        }
    }
    return NULL;
}

void fn_80007610(void *, void *);

struct aipath_s {
    s32 count;
    u8 *items;
    u8 a[8];
    u8 b[0xA8];
};

void fn_8012CB04(void *pv) {
    struct aipath_s *p = pv;
    s32 i;
    if (p != NULL) {
        memset(p->a, 0, 0xA8);
        memset(p->b, 0, 0xA8);
        memset(p->items, 0, p->count * 0xA8);
        for (i = 0; i < p->count; i++) {
            fn_80007610(p->a, p->items + i * 0xA8);
        }
    }
}

s32 fn_800CC284(void *, s32);

s32 fn_8012CCCC(void *arg0) {
    s16 t;
    if (fn_800CC284(arg0, 0) != 0) {
        return 1;
    }
    t = *(s16 *)((u8 *)arg0 + 0x1074);
    if (t == 0x4A) {
        return 1;
    }
    return t == 0x71;
}

struct gai7fbc_s { s32 a; s32 b; u8 pad[0x48]; };

void fn_80127FBC(void *arg0) {
    s32 i;
    for (i = 0; i < 0x180; i++) {
        (*(struct gai7fbc_s **)((u8 *)arg0 + 0x580))[i].a = -1;
        (*(struct gai7fbc_s **)((u8 *)arg0 + 0x580))[i].b = -1;
    }
    *(s32 *)((u8 *)arg0 + 0x584) = 0;
    *(s32 *)((u8 *)arg0 + 0x588) = 0;
}

struct gai_rec { s32 id; s32 _4; u16 size; u8 _a; u8 flags; };

void *fn_801276E4(void *arg0, s32 id, s32 *outIdx) {
    struct gai_rec *r = *(struct gai_rec **)((u8 *)arg0 + 0x5D4);
    s32 n, i;
    if (r != NULL) {
        n = 0;
        for (i = 0; i < *(s32 *)((u8 *)arg0 + 0x5D8); i++) {
            if (r->id == id) {
                if ((r->flags & 8) && outIdx != NULL) *outIdx = n;
                return r;
            }
            if (r->flags & 8) n++;
            r = (struct gai_rec *)((u8 *)r + r->size);
        }
    }
    if (outIdx != NULL) *outIdx = -1;
    return NULL;
}

u8 fn_8012CE74(char *name) {
    u8 i;
    for (i = 0; i < *(s32 *)lbl_80408DF0; i++) {
        if (NuStrICmp(name, *(char **)(i * 0x48 + *(s32 *)((u8 *)lbl_80408DF0 + 0x20) + 0xC)) == 0) {
            return i;
        }
    }
    return 0xFF;
}

extern char str_MoveMode_RUN[];
extern char str_MoveMode_WALK[];
extern char str_MoveMode_TIPTOE[];

s32 GameAIActionParseSpeed(char *name, u8 *out) {
    if (NuStrICmp(name, str_MoveMode_RUN) == 0) {
        *out = 0;
        return 1;
    }
    if (NuStrICmp(name, str_MoveMode_WALK) == 0) {
        *out = 1;
        return 1;
    }
    if (NuStrICmp(name, str_MoveMode_TIPTOE) == 0) {
        *out = 2;
        return 1;
    }
    return 0;
}

extern char str_GameVar_Everyone[];

u8 fn_8012CD50(char *name) {
    s32 i;
    if (NuStrICmp(name, str_GameVar_Everyone) == 0) {
        return 0x40;
    }
    if ((u8 *)lbl_804093EC != NULL) {
        for (i = 0; ((u8 *)lbl_804093EC)[i * 2] != 0xFF && i < 0x40; i++) {
            if (NuStrICmp(name, *(char **)(((u8 *)lbl_804093EC)[i * 2] * 0x48 + *(s32 *)((u8 *)lbl_80408DF0 + 0x20) + 0xC)) == 0) {
                return i;
            }
        }
    }
    return 0xFF;
}

s32 fn_800130F4(void *);
void fn_80013200(void *, s32);

struct g7518_ent { u8 a[0xC]; u8 flags; u8 _d[3]; };
struct g7518_owner { u8 _0[0x20]; u16 flags; };
struct g7518 { struct g7518_owner *owner; u8 _4[6]; u8 count; u8 _b[0x19]; struct g7518_ent ents[1]; };

void fn_80127518(struct g7518 *p) {
    s32 i;
    u16 v;
    if (p != NULL) {
        for (i = 0; i < p->count; i++) {
            if ((*((u8 *)p + i * 16 + 0x30) & 0xC) == 0 && (*((u8 *)p + i * 16 + 0x30) & 3) && fn_800130F4(&p->ents[i]) != 0) {
                if (*((u8 *)p + i * 16 + 0x30) & 1) v = p->owner->flags ^ 0x100; else v = p->owner->flags;
                fn_80013200(&p->ents[i], (v >> 8) & 1);
            }
        }
    }
}

void *fn_8001384C(void *);

struct cba8_s {
    u8 _0[0xC];
    u8 *xC;
    u8 _10[8];
    u8 *x18;
    u8 _1c[8];
    u32 bits[32];
};

void fn_8012CBA8(struct cba8_s *p, s32 first, s32 last) {
    s32 max;
    s32 i;
    u8 *t;
    if (p != NULL) {
        max = 1;
        if (p->x18 != NULL) {
            max = *(f32 *)(*(u8 **)(p->x18 + 0x58) + 8);
        } else {
            t = fn_8001384C(&p->xC);
            if (t != NULL) {
                max = **(f32 **)(*(u8 **)(p->xC + 0x50) + t[0x5C] * 4);
            }
        }
        if (max > 0x400) max = 0x400;
        if (first == -1) first = max;
        if (last == -1) last = max;
        if (first <= 0) first = 1;
        if (last > max) last = max;
        last--;
        for (i = first - 1; i <= last; i++) {
            p->bits[i % 32] |= 1 << (i / 32);
        }
    }
}

f32 NuFmod(f32, f32);
void fn_8013F050(f32 *);
extern f32 lbl_801ACDB4[];
extern f32 lbl_801ACDB8[];
extern f32 lbl_801ACDBC[];
extern f32 lbl_801ACDC0[];
extern u8 lbl_801D59D6[];
extern f32 lbl_803E04B0[];
extern f32 lbl_80408F00;
extern void *lbl_80409410;
extern s32 lbl_8040AFB8;

void fn_801275D4(void *arg0) {
    f32 v[3];
    s32 i;
    struct gai_rec *r;
    f32 dy;

    if (lbl_8040AFB8 != 0 && lbl_80408F00 == lbl_801ACDB4[0] && lbl_801D59D6[0] != 0
        && NuFmod(lbl_803E04B0[0], lbl_801ACDB8[0]) < lbl_801ACDBC[0]) {
        r = *(struct gai_rec **)((u8 *)lbl_80409410 + 0x5D4);
        if (r != NULL) {
            i = 0;
            if (i < *(s32 *)((u8 *)arg0 + 0x5D8)) {
                dy = lbl_801ACDC0[0];
                do {
                    if (r->flags & 8) {
                        if ((*(u16 *)(*(u8 **)r + 0x20) & 0x101) == 0) {
                            v[0] = *(f32 *)(*(u8 **)r + 0x78);
                            v[1] = *(f32 *)(*(u8 **)r + 0x7C) + dy;
                            v[2] = *(f32 *)(*(u8 **)r + 0x80);
                            fn_8013F050(v);
                        }
                    }
                    r = (struct gai_rec *)((u8 *)r + r->size);
                } while (++i < *(s32 *)((u8 *)arg0 + 0x5D8));
            }
        }
    }
}

void NuVecSub(void *, void *, void *);
void NuVecRotateY(void *, void *, s32);
extern f32 lbl_801ACFA0[];

struct gaibox_s {
    u8 _0[0x10];
    f32 pos[3];
    f32 x;
    f32 y;
    f32 z;
    s16 yrot;
    u8 flags;
    u8 unk2B[5];
    u64 objectMask;
};

s32 fn_8012C994(struct gaibox_s *box, f32 *pos, f32 r) {
    f32 v[3];
    if (box != NULL && pos != NULL) {
        NuVecSub(v, pos, box->pos);
        NuVecRotateY(v, v, -box->yrot);
        if (v[0] + r >= -box->x && v[1] + r >= lbl_801ACFA0[0] && v[2] + r >= -box->z
            && v[0] - r <= box->x && v[1] - r <= box->y && v[2] - r <= box->z) {
            return 1;
        }
    }
    return 0;
}

void NuMtxToQuat(void *, void *, s32, f32);
s32 fn_800A3224(void *);
extern f32 lbl_801ACEF8[];
extern f32 lbl_801ACEFC[];
extern f32 lbl_801ACF00[];
struct gaiv3 { f32 x, y, z; };
extern struct gaiv3 lbl_801D5964;

s32 fn_8012A2EC(u8 *c) {
    f32 thr = lbl_801ACEF8[0];
    if (c[0x28F] == 0 && !(*(s32 *)(*(u8 **)(c + 4) + 0x118) & 0x8000) && (*(s32 *)(c + 0x20C) & 0x40000)) {
        s32 f = *(s32 *)(*(u8 **)(c + 0x64) + 4);
        if (!(f & 0x08000000) && *(f32 *)(c + 0x1E8) > thr) {
            if (!(f & 0x04000000)) {
                NuMtxToQuat(*(void **)c, c + 0x1DC, 0, lbl_801ACEFC[0]);
            } else {
                *(struct gaiv3 *)(c + 0x9C) = *(struct gaiv3 *)(c + 0x1DC);
                *(struct gaiv3 *)(c + 0x6C) = *(struct gaiv3 *)(c + 0x9C);
                *(struct gaiv3 *)(c + 0x78) = lbl_801D5964;
                fn_800A3224(*(void **)c);
                *(f32 *)(c + 0x1E8) = lbl_801ACF00[0];
            }
        }
    }
    return 0;
}

void AIScriptProcessorInit(void *, void *, void *, s32, char *, s32, s32, void *, void *);
s32 AISysSetLevelPath(void *, char *);
void ResetAICreatures(void *);
void fn_800A4C78(void *);
int sprintf(char *, const char *, ...);
extern char str_Format_LevelNum[];
extern char str_GameVar_Level[];

struct gaiproc_s { u8 _0[0x50]; };
struct gaisys_s { u8 _0[0x2EC]; s32 nprocs; struct gaiproc_s procs[8]; };

void GameAISysReset(void *world) {
    char buf[0x20];
    s32 i;
    struct gaisys_s *sys;

    if (world != NULL) {
        AISysSetLevelPath(world, NULL);
        *(s32 *)((u8 *)lbl_80409410 + 0x2EC) = 0;
        for (i = 0; i <= 7; i++) {
            if (i != 0) {
                sprintf(buf, str_Format_LevelNum, i);
            } else {
                sprintf(buf, str_GameVar_Level);
            }
            if (fn_80083754(*(void **)((u8 *)lbl_80409410 + 0x2E8), buf, 0, 1, 0) != 0) {
                sys = (struct gaisys_s *)lbl_80409410;
                AIScriptProcessorInit(world, NULL, &sys->procs[sys->nprocs++], 0, buf, 0, 0, NULL, NULL);
            }
        }
        fn_8012CB04(*(void **)((u8 *)lbl_80409410 + 0x570));
        fn_800A4C78(world);
        ResetAICreatures(world);
    }
}

s32 fn_8006F37C(void);
s32 fn_8006F71C(void);
void fn_8006F7E8(char *, s32);
extern char str_MoveMode_LEGO[];

struct a138_e { s32 _0; s32 a[2]; s32 b[2]; u8 _14[0x14]; };
struct a138_i { u8 _0[0x12]; u16 n; u8 _14[0x68]; struct a138_e *e; };
struct a138_l { u8 count; u8 _1[3]; struct a138_i **items; };

void fn_8012A138(u8 *w, s32 mode) {
    char name[8];
    u8 tmp[8];
    s32 i, j, k;
    s32 f;
    s32 n;
    struct a138_i *it;
    struct a138_e *e;

    if (mode <= 11 && *(struct a138_l **)(w + 0xC) != NULL) {
        for (i = 0; i < (*(struct a138_l **)(w + 0xC))->count; i++) {
            it = (*(struct a138_l **)(w + 0xC))->items[i];
            for (j = 0; j < it->n; j++) {
                e = &it->e[j];
                for (k = 0; k < 2; k++) {
                    f = e->a[k];
                    e->a[k] = 0;
                    if (f & 1) e->a[k] = 1;
                    if (f & 2) e->a[k] |= 2;
                    if (f & 8) e->a[k] |= 0x40000000;
                    if (f & 0x10) e->a[k] |= 0x80000000;
                    if (f & 0x20) e->a[k] |= 4;
                    if (f & 0x40) e->a[k] |= 8;
                    if (f & 0x80) e->a[k] |= 0x10;
                    if (f & 0x100) e->a[k] |= 0x20;
                    e->b[k] = e->a[k];
                }
            }
        }
    }
    n = fn_8006F71C();
    if (n != 0 && n <= 8) {
        fn_8006F7E8(name, n);
        if (NuStrICmp(name, str_MoveMode_LEGO) == 0) {
            fn_8006F37C();
            *(void **)(w + 0x137C) = fn_8008F0C8(tmp, w + 4, 4);
        }
    }
}

f32 fn_8000ED40(f32);
s32 fn_800130F4(void *);
s32 fn_800131B8(void *);
extern f32 lbl_804099C4;

struct gaihandle { s32 a; s32 b; u8 *obj; };
struct gaigroup { s16 n; s16 size; struct gaihandle h[1]; };

s32 fn_8012A3F4(u8 *w, struct gaihandle *h) {
    struct gaigroup *g;
    s32 i, j, k;
    u8 *o;

    if (h != NULL && fn_800130F4(h) != 0) {
        g = *(struct gaigroup **)((u8 *)lbl_80409410 + 0x2D0);
        if (g != NULL) {
            for (i = 0; i < *(s32 *)((u8 *)lbl_80409410 + 0x2D4); i++) {
                for (j = 0; j < g->n; j++) {
                    if (fn_80013890(h, &g->h[j]) != 0) {
                        for (k = 0; k < g->n; k++) {
                            if (fn_800131B8(&g->h[k]) != 0) {
                                *h = g->h[k];
                                return 1;
                            }
                        }
                        return 0;
                    }
                }
                g = (struct gaigroup *)((u8 *)g + g->size);
            }
        }
        for (i = 0; i < *(s32 *)(*(u8 **)(*(u8 **)(w + 0x1388) + 0x1A0) + 0x6C); i++) {
            o = *(u8 **)(*(u8 **)(*(u8 **)(w + 0x1388) + 0x1A0) + 0x70) + i * 0xD0;
            if (o != h->obj && (*(s32 *)(o + 0xB8) & 2)
                && !(fn_8000ED40(*(f32 *)(o + 0x70) - *(f32 *)(h->obj + 0x70)) > lbl_804099C4)
                && !(fn_8000ED40(*(f32 *)(o + 0x74) - *(f32 *)(h->obj + 0x74)) > lbl_804099C4)
                && !(fn_8000ED40(*(f32 *)(o + 0x78) - *(f32 *)(h->obj + 0x78)) > lbl_804099C4)) {
                h->obj = o;
                return 1;
            }
        }
    }
    return 0;
}

extern f32 lbl_801ACEC8[];
extern f32 lbl_801ACECC[];
extern struct NUGAMEOBJECT_s *lbl_80409430;
extern s32 lbl_8040B058;

void fn_80129F6C(struct gaibox_s *box)
{
    struct NUGAMEOBJECT_s *object;
    s32 i;
    f32 offset[3];
    s32 flags;

    box->objectMask = 0;
    box->flags &= ~7;
    object = lbl_80409430;
    i = 0;
    if (i < lbl_8040B058) {
        f32 minValue = lbl_801ACEC8[0];
        f32 minY = lbl_801ACECC[0];
        do {
            if ((object->flags20C & 0x80080000) == 0x80080000 &&
                object->playerPacket != NULL &&
                (object->unk28F == 0 || object->unk103C > minValue)) {
                NuVecSub(offset, object->position, box->pos);
                NuVecRotateY(offset, offset, -box->yrot);
                if (offset[0] >= -box->x && offset[1] >= minY &&
                    offset[2] >= -box->z && offset[0] <= box->x &&
                    offset[1] <= box->y && offset[2] <= box->z) {
                    box->objectMask |= 1ULL << object->maskIndex;
                    if (object->playerPacket != NULL && (object->flags20C & 0x01000000)) {
                        box->flags |= 1;
                    }
                    flags = object->motionFlags;
                    if (flags & 1) {
                        box->flags |= 4;
                    } else if (!(flags & 4)) {
                        box->flags |= 2;
                    }
                }
            }
            i++;
            object++;
        } while (i < lbl_8040B058);
    }
}

struct gameai_special_s {
    void *scene;
    s32 index;
    s32 unk8;
};

struct gameai_controller_flags_s {
    u32 reverse : 1;
    u32 unk : 31;
};

struct gameai_controller_s {
    u8 links[8];
    void *connection;
    struct gameai_special_s special;
    s32 cutscene;
    u8 unk1C[0x88];
    struct gameai_controller_flags_s flags;
};

struct gameai_controller_system_s {
    s32 capacity;
    s32 unk4;
    u8 available[8];
    u8 active[8];
};

s32 FindCutScene(char *);
s32 NuSpecialFind(void *, struct gameai_special_s *, char *, s32);
void fn_80007680(void *, void *);
void *fn_800076C4(void *);
void (*fn_80009948(const char *, s32))(const char *, ...);
u8 *fn_8008A6D4(void *, void *, char *, char *, s32 *);
s32 fn_8011EBF4(void *, s32);
extern char str_Assert_AIPathCnxController_TooMany[];
extern char str_SourceFile_GameAI[];

struct gameai_controller_s *AIPathCnxControllerCreate(
    struct gameai_controller_system_s *system, void *ai, void *path, char *from,
    char *to, char *object, char *cutscene)
{
    struct gameai_controller_s *controller = NULL;
    s32 cutsceneInstance = 0;
    void *connection;
    struct gameai_special_s special;
    s32 direction;

    if (system != NULL && from != NULL && to != NULL && (object != NULL || cutscene != NULL)) {
        if (cutscene != NULL) {
            s32 index;
            connection = fn_8008A6D4(ai, path, from, to, &direction);
            index = FindCutScene(cutscene);
            if (index != -1) {
                cutsceneInstance = fn_8011EBF4(lbl_80409410, index);
            }
            if (connection != NULL && cutsceneInstance != 0) {
                u8 *available = system->available;
                controller = fn_800076C4(available);
                if (controller != NULL) {
                    fn_80007680(available, controller);
                    fn_80007610(system->active, controller);
                    controller->connection = connection;
                    controller->flags.reverse = direction;
                    controller->cutscene = cutsceneInstance;
                } else {
                    fn_80009948(str_SourceFile_GameAI, 0xF6F)(str_Assert_AIPathCnxController_TooMany, system->capacity);
                }
            }
        } else {
            NuSpecialFind(*(void **)((u8 *)ai + 0x1388), &special, object, 1);
            connection = fn_8008A6D4(ai, path, from, to, &direction);
            if (connection != NULL && fn_800130F4(&special) != 0) {
                u8 *available = system->available;
                controller = fn_800076C4(available);
                if (controller != NULL) {
                    fn_80007680(available, controller);
                    fn_80007610(system->active, controller);
                    controller->connection = connection;
                    controller->flags.reverse = direction;
                    controller->special = special;
                } else {
                    fn_80009948(str_SourceFile_GameAI, 0xF83)(str_Assert_AIPathCnxController_TooMany, system->capacity);
                }
            }
        }
    }
    return controller;
}
