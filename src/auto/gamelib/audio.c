#include "types.h"
#include "nu3dx/nu3dx.h"

extern s16 lbl_801BB44C[];
extern s16 lbl_801BB452[];
extern s16 lbl_801BB456[];
extern f32 lbl_801BB460[];
extern s32 lbl_80408488;
extern s32 lbl_8040848C;
extern s32 lbl_80408490;
extern s32 lbl_804085C0;
extern f32 lbl_8040870C;

void fn_80066290(void)
{

}

void fn_80066474(s32 a)
{
    lbl_80408488 = a;
}

void fn_8006647C(s32 a)
{
    lbl_8040848C = a;
}

void fn_80066484(s32 a)
{
    lbl_80408490 = a;
}

s32 fn_8006648C(void)
{
    return -1;
}

void fn_80066494(void)
{

}

void fn_800698B0(s32 a)
{
    lbl_804085C0 = a;
}

void fn_8006DEB0(f32 x)
{
    lbl_8040870C = x;
}

void fn_8006DF18(void)
{

}

s32 fn_8006DF50(void)
{
    return lbl_801BB452[0];
}

s32 fn_8006DF5C(void)
{
    return lbl_801BB456[0];
}

s32 fn_8006E2C0(void)
{
    return lbl_801BB44C[0];
}

void fn_8006E370(f32 x)
{
    lbl_801BB460[0] = x;
}

extern s32 fn_800076E4(const char*, const char*, s32);

s32 fn_80069900(const char* name)
{
    s32 i;
    if (lbl_804085C0) {
        for (i = 0; i < *(s32*)((u8*)lbl_804085C0 + 0x20); i++) {
            u8* entries = *(u8**)((u8*)lbl_804085C0 + 0x24);
            if (fn_800076E4(*(const char**)(entries + i * 0x50 + 0x44), name, 0x13) == 0)
                return i;
        }
    }
    return -1;
}

extern s32 lbl_804086EC, lbl_804086E8, lbl_80408298;
extern void fn_80044BF4(s32);

void fn_8006E00C(void)
{
    s32 minimum;
    if (!lbl_804086EC && !lbl_804086E8 && lbl_80408298 != -1 &&
        (u32)((u16)lbl_801BB44C[0] - 11) > 2) {
        minimum = 5;
        fn_80044BF4(lbl_801BB44C[2]);
        if (lbl_801BB44C[0] > 10) return;
        if (lbl_801BB44C[0] >= minimum)
            fn_80044BF4(1 - lbl_801BB44C[2]);
    }
}

extern s32 lbl_804086DC;
extern f32 lbl_804086FC;
extern void fn_80044C30(s32, s32);

void fn_8006DF68(f32 volume)
{
    if (!lbl_804086E8 && !lbl_804086EC) {
        lbl_804086FC = volume;
        if (lbl_801BB44C[0] == 4) {
            s32 index = lbl_801BB44C[3];
            s32* entries = (s32*)lbl_804086DC;
            fn_80044C30(lbl_801BB44C[2], (s32)((f32)entries[index * 5 + 3] * volume));
        }
    }
}

extern void fn_80044BB8(s32);

void fn_8006E094(void)
{
    s32 minimum;
    if ((!lbl_804086EC || !lbl_804086E8) && lbl_80408298 != -1 &&
        (u32)((u16)lbl_801BB44C[0] - 11) > 2) {
        minimum = 5;
        fn_80044BB8(lbl_801BB44C[2]);
        if (lbl_801BB44C[0] > 10) return;
        if (lbl_801BB44C[0] >= minimum)
            fn_80044BF4(1 - lbl_801BB44C[2]);
    }
}

/* 0x40-byte sound table entry: `next` chains a name-hash bucket (PauseMenu_HandleEntry1). */
struct AudioNameEntry {
    const char *name;
    signed int bankBit : 15;
    unsigned int flag16 : 1;
    unsigned int flag16_a : 1;
    unsigned int flag17 : 1;
    unsigned int flag18 : 1;
    unsigned int flag19 : 1;
    unsigned int flag20 : 1;
    unsigned int flag21 : 1;
    unsigned int flagRest : 10;
    s32 freq;
    u8 unkC;
    u8 padD[3];
    s16 next;
    s16 unk12;
    s16 linked;
    s16 unk16;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    s32 unk30;
    f32 unk34;
    f32 unk38;
    u8 pad3C[4];
};
extern struct AudioNameEntry lbl_803B6E04[];
extern char lbl_8019854C[], lbl_8019857C[];
extern void (*fn_80009970(char*, s32))();

s32 fn_8006DDC4(const char* name, s32 length)
{
    struct AudioNameEntry* entry = lbl_803B6E04;
    s32 i;
    for (i = 0; i < 800; i++) {
        if (fn_800076E4(name, (entry++)->name, length) == 0)
            return i;
    }
    (*fn_80009970(lbl_8019854C, 0x3ef))(lbl_8019857C, name);
    return -1;
}

extern s32 fn_80044C78(s32);

s32 fn_8006CECC(void)
{
    s32 index = 1 - lbl_801BB44C[2];
    u8* pending = (u8*)lbl_801BB44C + 0x12;
    if (pending[index]) {
        pending[index]--;
        return 0;
    }
    if (lbl_804086E8 || lbl_804086EC)
        return 0;
    if (fn_80044C78(index) == 2) return 0;
    return 1;
}

extern s32 fn_8006E37C(s32);
extern s32 fn_8006E394(s32, s32);

void fn_8006DC1C(s32* list, void (*callback)(s32))
{
    s32 value = *list++;
    while (value != -1) {
        if (value >= 0) {
            s32 linked;
            callback(value);
            linked = lbl_803B6E04[value].linked;
            if (linked != -1) {
                s32 i;
                s32 count = fn_8006E37C(linked);
                for (i = 0; i < count; i++)
                    callback(fn_8006E394(linked, i));
            }
        }
        value = *list++;
    }
}

s32 fn_8000759C(s32 *, s32, s32);
extern s32 lbl_803D45B8[];

void fn_8006DBB8(s32 arg0) {
    fn_8000759C(lbl_803D45B8, arg0, 0x64);
}

s32 fn_80044F04();
s32 fn_80044F24(s32);
extern s32 lbl_804086E8;

void fn_8006DEE4(void) {
    if ((s32) lbl_804086E8 == 0) {
        fn_80044F04();
        fn_80044F24(0);
    }
}

extern s32 lbl_80408298;
extern s32 lbl_804086E8;
extern s32 lbl_804086EC;

void fn_8006E11C(void) {
    if (((s32) lbl_804086EC == 0) && ((s32) lbl_804086E8 == 0) && ((s32) lbl_80408298 != -1) && (((s16) (*(s16 *)((s8 *)(lbl_801BB44C) + (0))) == 0xB) || ((s16) (*(s16 *)((s8 *)(lbl_801BB44C) + (0))) == 0xD))) {
        fn_80044BF4(1 - (*(s16 *)((s8 *)(lbl_801BB44C) + (4))));
    }
}

extern s32 lbl_80408298;
extern s32 lbl_804086E8;
extern s32 lbl_804086EC;

void fn_8006E184(void) {
    if ((((s32) lbl_804086EC == 0) || ((s32) lbl_804086E8 == 0)) && ((s32) lbl_80408298 != -1) && (((s16) (*(s16 *)((s8 *)(lbl_801BB44C) + (0))) == 0xB) || ((s16) (*(s16 *)((s8 *)(lbl_801BB44C) + (0))) == 0xD))) {
        fn_80044BB8(1 - (*(s16 *)((s8 *)(lbl_801BB44C) + (4))));
    }
}

f32 NuFParGetFloat();
extern f32 lbl_804086E4;

void fn_8006E3BC(void) {
    lbl_804086E4 = NuFParGetFloat();
}

extern s32 lbl_803D45B8[];
extern s32 lbl_803D461C[];

void fn_8006DBE8(void) {
    fn_8000759C(lbl_803D45B8, lbl_803D461C, 0x64);
}

extern f32 lbl_801986F0[];
extern f32 lbl_801BB460[];

void fn_8006E328(void)
{
  if (((s16) (*((s16 *) (((s8 *) lbl_801BB44C) + 0)))) == 0xB)
  {
    *((s16 *) (((s8 *) lbl_801BB44C) - -6)) = -1;
  }
  else
  {
    *((s16 *) (((s8 *) lbl_801BB44C) + 2)) = (*((s16 *) (((s8 *) lbl_801BB44C) + 0xA)) = -1);
    *((s16 *) (((s8 *) lbl_801BB44C) + 0xC)) = 0;
  }
  lbl_801BB460[0] = lbl_801986F0[0];
}

void fn_8006DB8C(s32 *arg0) {
    fn_8000759C(arg0, (s32) lbl_803D45B8, 0x64);
}

void fn_8006DB3C(s32 arg0, s32 arg1) {
    s32 var_ctr;
    s32 var_r11;

    var_r11 = 0;
    var_ctr = 0x32;
    do {
        *(s16 *)((var_r11 + arg0)) = *(u16 *)((var_r11 + arg0)) & *(u16 *)((var_r11 + arg1));
        var_r11 += 2;
        var_ctr -= 1;
    } while (var_ctr != 0);
}

void *memset(void *, s32, u32);

void fn_8006DB64(void *arg0) {
    memset(arg0, -1, 0x64);
}

extern u32 lbl_803C3B24[];
extern s16 *lbl_8040AEEC;

/* Sound id for a name: upper-cased CRC32 (table lbl_803C3B24) whose low byte picks a bucket
 * of lbl_8040AEEC; entries of lbl_803B6E04 chain through `next`. -1 when absent. */
s32 PauseMenu_HandleEntry1(const char *name) {
    u32 hash = 0;
    s32 i = 0;
    s16 id;
    s8 c;
    u8 bucket;

    while (name[i] != 0) {
        u32 top = hash >> 24;
        c = name[i++];
        if ((u32)(c - 'a') <= 'z' - 'a') {
            c -= 0x20;
        }
        top ^= c;
        hash = (hash << 8) ^ lbl_803C3B24[top];
    }
    bucket = hash;
    if (lbl_8040AEEC == NULL) {
        return -1;
    }
    id = lbl_8040AEEC[bucket];
    /* The do-while(0) scopes are what give retail its register allocation (r28 name,
     * r29 table base). */
next:
    do {
        if (id == -1) {
            return -1;
        }
    } while (0);
    do {
        if (fn_800076E4(name, lbl_803B6E04[id].name, 0x20) != 0) {
            id = lbl_803B6E04[id].next;
            goto next;
        }
    } while (0);
    return id;
}

extern s32 fn_8006B328(s32 id, void *pos, f32 a, f32 b);
extern f32 lbl_801986C8[];
extern f32 lbl_801986D4[];

/* Play the sound named `name` at `pos`. */
void fn_8006DCD4(const char *name, void *pos) {
    s32 id = PauseMenu_HandleEntry1(name);
    if (id != -1) {
        fn_8006B328(id, pos, lbl_801986C8[0], lbl_801986C8[0]);
    }
}

extern f32 lbl_801986CC[];

void fn_8006DD1C(const char *name, void *pos, f32 a)
{
    s32 id = PauseMenu_HandleEntry1(name);

    if (id != -1)
        fn_8006B328(id, pos, a, lbl_801986CC[0]);
}

extern f32 lbl_801986D0[];

void fn_8006DD70(const char *name, void *pos, f32 b)
{
    s32 id = PauseMenu_HandleEntry1(name);

    if (id != -1)
        fn_8006B328(id, pos, lbl_801986D0[0], b);
}

void fn_8006DE5C(s32 id, void *pos) {
    fn_8006B328(id, pos, lbl_801986D4[0], lbl_801986D4[0]);
}

extern f32 lbl_801986D8[];

void fn_8006DE88(s32 id, void *pos, f32 a)
{
    fn_8006B328(id, pos, a, lbl_801986D8[0]);
}

extern void fn_80021738(struct nuhspecial_s *, struct nugscn_s *, s32);
extern s32 fn_800130F4(struct nuhspecial_s *);
extern s32 fn_800135B0(struct nuhspecial_s *);

s32 fn_8006624C(s32 index, struct nugscn_s *scene)
{
    struct nuhspecial_s special;

    fn_80021738(&special, scene, index);
    if (fn_800130F4(&special))
        return fn_800135B0(&special);
    return -1;
}

extern s32 fn_8002171C(struct nugscn_s *);
extern char *NuSpecialGetInstAnim(struct nuhspecial_s *);

s32 fn_80066294(const char *name, struct nugscn_s *scene)
{
    struct nuhspecial_s special;
    s32 i;

    if (scene != NULL) {
        for (i = 0; i < fn_8002171C(scene); i++) {
            fn_80021738(&special, scene, i);
            if (fn_800130F4(&special) &&
                fn_800076E4(NuSpecialGetInstAnim(&special), name, 0x13) == 0)
                return i;
        }
    }
    return -1;
}

extern s32 lbl_80399D8C[8];
extern s32 lbl_80399D60[8];
extern s32 lbl_80399D40[8];

void fn_8006638C(s32 index)
{
    if (lbl_80399D8C[index] && lbl_80399D60[index] && !lbl_80399D40[index])
        lbl_80399D40[index] = 1;
}

void fn_800663D8(s32 index)
{
    lbl_80399D40[index] = 0;
}

struct AudioSceneObject {
    s32 id;
    u8 pad4[0x2d0 - 4];
    s8 group;
    u8 pad2D1[3];
};

struct AudioPath {
    s32 id;
    u8 pad4[0x1c - 4];
    s32 unk1C;
    s32 pointCount;
    s32 unk24;
    u8 pad28[0x2c - 0x28];
    struct nuvec_s position;
    u8 pad38[0x13c - 0x38];
    char slotNames[8][16];
    s32 tags[8];
    s32 unk1DC[8];
    s32 unk1FC[8];
    struct nuivec_s offsets[8];
    u8 pad27C[0x2a0 - 0x27c];
    char pointNames[8][16];
    s32 pointModes[16];
    f32 pointTimes[8];
    struct nuvec_s points[8];
    u8 pad3E0[0x3ec - 0x3e0];
};

struct AudioAnimState {
    struct numtx_s matrix;
    f32 tfactor;
    f32 unk44;
    f32 unk48;
    f32 time;
    u32 playing : 1;
    u32 backwards : 1;
    u32 repeating : 1;
    u32 oscillate : 1;
    u32 padFlags : 28;
};

struct AudioPathSlot {
    struct numtx_s matrix;
    s16 id;
    u8 pad42[2];
    u32 flag0 : 1;
    u32 visible : 1;
    u32 flagRest : 30;
    struct AudioAnimState *animation;
    u8 pad4C[4];
};

extern struct AudioSceneObject lbl_8038E840[64];
extern struct AudioPath lbl_8039B1AC[64];
extern struct AudioPathSlot lbl_80399DAC[64];


extern s32 lbl_8040846C;
extern s32 lbl_8040AECC;

void fn_80066328(void)
{
    s32 i;

    for (i = 63; i >= 0; i--)
        lbl_8038E840[i].id = -1;

    lbl_8040AECC = 0;
    lbl_8040846C = 0;
    for (i = 0; i < 8; i++) {
        lbl_80399D8C[i] = 0;
        lbl_80399D40[i] = 0;
    }
}

void fn_800663F0(s32 index)
{
    s32 i;

    if (lbl_80399D40[index] != 0)
        lbl_80399D40[index] = 0;
    for (i = 0; i < 64; i++) {
        if (lbl_8038E840[i].group == index) {
            lbl_8038E840[i].id = -1;
            lbl_8040846C--;
        }
    }
    lbl_80399D8C[index] = 0;
    lbl_80399D60[index] = 0;
}

struct AudioInstEntry {
    u8 pad0[0xb4];
    const char *name;
    u8 padB8[0xd0 - 0xb8];
};

struct AudioInstList {
    u8 pad0[0x6c];
    s32 count;
    struct AudioInstEntry *entries;
};

struct AudioInstOwner {
    u8 pad0[0x1a0];
    struct AudioInstList *list;
};

s32 fn_80066498(const char *name, struct AudioInstOwner *owner)
{
    s32 i;
    char pad[16];

    if (owner != NULL) {
        for (i = 0; i < owner->list->count; i++) {
            if (fn_800076E4(owner->list->entries[i].name, name, 0x13) == 0)
                return i;
        }
    }
    return -1;
}

extern char *strcpy(char *, const char *);

void fn_80068CB8(s32 index, s32 i)
{

    for (; i < lbl_8039B1AC[index].pointCount - 1; i++) {
        lbl_8039B1AC[index].pointModes[i] = lbl_8039B1AC[index].pointModes[i + 1];
        lbl_8039B1AC[index].pointTimes[i] = lbl_8039B1AC[index].pointTimes[i + 1];
        lbl_8039B1AC[index].points[i] = lbl_8039B1AC[index].points[i + 1];
        strcpy(lbl_8039B1AC[index].pointNames[i], lbl_8039B1AC[index].pointNames[i + 1]);

    }
    --lbl_8039B1AC[index].pointCount;
}

void fn_80068DE0(s32 index, s32 i)
{

    for (; i < lbl_8039B1AC[index].unk1C - 1; i++) {
        lbl_8039B1AC[index].tags[i] = lbl_8039B1AC[index].tags[i + 1];
        lbl_8039B1AC[index].unk1DC[i] = lbl_8039B1AC[index].unk1DC[i + 1];
        lbl_8039B1AC[index].unk1FC[i] = lbl_8039B1AC[index].unk1FC[i + 1];
        lbl_8039B1AC[index].offsets[i] = lbl_8039B1AC[index].offsets[i + 1];
        strcpy(lbl_8039B1AC[index].slotNames[i], lbl_8039B1AC[index].slotNames[i + 1]);

    }
    --lbl_8039B1AC[index].unk1C;
}

extern s32 lbl_804086E0;

struct AudioTrackEntry {
    s32 id;
    s32 fields[4];
};

void fn_8006DF1C(struct AudioTrackEntry *entry)
{
    s32 count;

    lbl_804086E0 = 0;
    lbl_804086DC = (s32)entry;
    if (entry->id != 0) {
        count = 0;
        do {
            entry++;
            count++;
        } while (entry->id != 0);
        lbl_804086E0 = count;
    }
}

struct AudioIndexRange {
    s16 start;
    s16 count;
    u8 pad4[4];
};
extern struct AudioIndexRange lbl_803C3604[];

s32 fn_8006E37C(s32 index)
{
    return lbl_803C3604[index].count;
}

extern s16 lbl_803C3924[];

s32 fn_8006E394(s32 index, s32 offset)
{
    return lbl_803C3924[lbl_803C3604[index].start + offset];
}

void fn_8006E288(s32 value, s32 mode)
{
    u16 current = lbl_801BB44C[0];

    *(s32 *)(lbl_801BB44C + 14) = value;
    if ((u32)(current - 11) > 2)
        return;

    if (mode != 13)
        lbl_801BB44C[0] = 11;
    else
        lbl_801BB44C[0] = mode;
}

extern s16 lbl_801BB458[];

s32 fn_8006E2CC(void)
{
    if (lbl_801BB458[0] != 0)
        return 1;
    if (fn_80044C78(0) == 2 || fn_80044C78(1) == 2)
        return 1;
    return 0;
}

struct AudioVoice {
    struct nuvec_s pos;
    s32 unkC;
    s32 id;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 pad1E[2];
    f32 unk20;
    u8 unk24[0x10];
    s32 unk34;
    s32 unk38;
    f32 unk3C;
    s16 unk40;
    s16 unk42;
    f32 unk44;
    f32 unk48;
    s16 unk4C;
    u8 pad4E[3];
    s8 group;
    u8 pad52[2];
};

extern struct AudioVoice lbl_803AC5B8[512];
extern s32 lbl_8038E820[8];
extern s32 lbl_803B6DD8[8];
extern s32 lbl_804085E4;

void fn_8006B1E0(void)
{
    s32 i;

    for (i = 511; i >= 0; i--)
        lbl_803AC5B8[i].id = -1;

    for (i = 0; i < 8; i++) {
        lbl_8038E820[i] = 0;
        lbl_803B6DD8[i] = 0;
    }
    lbl_804085E4 = 0;
}

#include "nucore/nufpar.h"

struct AudioRequestEntry {
    s32 fields[5];
};
struct numem_req_s;

extern s32 fn_80006398(struct nufpar_s *);
extern s32 NuWaterRender(struct nufpar_s *);
extern void NuMemAllocFn(struct numem_req_s *);
extern s32 NuRndrWaterRip(struct AudioRequestEntry *);
extern void NuSoundSetRequestTable(s32, s32);
extern void fn_80044D4C(void);
extern struct nufpcom_s lbl_801BB42C[];
extern struct AudioRequestEntry lbl_803D0724[];
extern s32 lbl_804086C8;

void fn_8006C65C(char *name)
{
    s32 *mask;
    s32 index;
    struct nufpar_s *parser = NuFParCreate(name);

    if (parser != NULL) {
        NuFParPushCom(parser, lbl_801BB42C);
        while (fn_80006398(parser)) {
            NuFParGetWord(parser);
            if (parser->word.b[0] != 0)
                NuWaterRender(parser);
        }
        NuMemAllocFn((struct numem_req_s *)parser);
    }
    index = lbl_804086C8;
    lbl_803D0724[index].fields[2] = 0;
    lbl_803D0724[index].fields[1] = 0;
    lbl_803D0724[index].fields[0] = 0;
    lbl_803D0724[index].fields[3] = -1;
    NuRndrWaterRip(lbl_803D0724);
    mask = lbl_803D45B8;
    ((void *(*)())memset)(mask, 0, 0x64);
    if (!lbl_804086E8)
        NuSoundSetRequestTable((s32)mask, 0x32);
    fn_80044D4C();
}

s32 fn_8006DEB8(s32 id)
{
    if (id != -1)
        return lbl_803B6E04[id].flag16;
    return -1;
}

extern void fn_80044B7C(s32);
extern void fn_80044D20(void);
extern void fn_80044D8C(void);
extern f32 lbl_801986EC[];

struct AudioStreamInit {
    s16 values[9];
    s8 pending[2];
    u8 pad14[4];
    f32 fade;
};

void fn_8006E1EC(void)
{
    s32 state;

    if (lbl_804086E8 == 0) {
        state = lbl_804086EC;
        if (state == 0) {
            fn_80044B7C(0);
            fn_80044B7C(1);
            {
                struct AudioStreamInit *stream = (struct AudioStreamInit *)lbl_801BB44C;
                stream->values[7] = state;
                stream->values[1] = -1;
                stream->values[3] = -1;
                stream->values[2] = state;
                stream->values[5] = -1;
                stream->fade = lbl_801986EC[0];
                stream->values[4] = state;
                stream->values[6] = state;
                stream->pending[0] = 0;
                stream->pending[1] = 0;
                stream->values[0] = state;
            }
        }
    }
    fn_80044D8C();
    fn_80044D20();
    fn_80044D4C();
}

void fn_8006DAC8(u16 *table, s32 id)
{
    s32 bank;
    s32 bankBit;
    s32 bit;
    s32 index;
    u16 *entry;

    if (id < 0)
        return;
    bank = lbl_803B6E04[id].bankBit;
    bankBit = bank;
    if ((u32)bank > 799)
        return;
    index = bank / 16;
    if (index > 49)
        return;
    bit = bankBit & 15;
    entry = &table[index];
    *entry &= 0xffffu - (1u << bit);
}

extern s32 lbl_8040AEDC;

void fn_800698B8(void)
{
    s32 i;
    s16 none = -1;

    for (i = 0; i < 64; i++) {
        lbl_80399DAC[i].id = none;
        lbl_8039B1AC[i].id = -1;
    }
    lbl_8040AEDC = 0;
}

void fn_80069810(void)
{
    s32 i;

    for (i = 0; i < 64; i++) {
        struct AudioPathSlot *slot = &lbl_80399DAC[i];
        lbl_8039B1AC[i].tags[0] = -1;
        if (slot->id != -1) {
            struct AudioAnimState *anim = slot->animation;
            if (anim != NULL) {
                anim->unk44 = 0.0f;
                anim->repeating = 1;
                anim->time = (f32)lbl_8039B1AC[i].unk24;
                anim->playing = 0;
                anim->backwards = 0;
            }
        }
    }
}

extern void NuVecSub(struct nuvec_s *, struct nuvec_s *, struct nuvec_s *);
extern struct nuvec_s lbl_803AADAC;
extern s32 lbl_8040AED8;

void fn_80067294(f32 bestDist)
{
    struct nuvec_s diff;
    s32 i;
    f32 dist;

    if (lbl_8040AED8 != -1) {
        NuVecSub(&diff, &lbl_803AADAC, (struct nuvec_s *)&lbl_80399DAC[lbl_8040AED8].matrix._30);
        dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
        if (dist == 0.0f)
            return;
    }

    lbl_8040AED8 = -1;
    for (i = 0; i < 64; i++) {
        if (lbl_80399DAC[i].id != -1) {
            NuVecSub(&diff, &lbl_803AADAC, (struct nuvec_s *)&lbl_80399DAC[i].matrix._30);
            dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
            if (bestDist < 0.0f || dist < bestDist) {
                lbl_8040AED8 = i;
                bestDist = dist;
            }
        }
    }
}

extern struct nuvec_s lbl_803B6DF8;
extern s32 lbl_8040AEE8;

void fn_8006998C(f32 bestDist)
{
    struct nuvec_s diff;
    s32 i;
    f32 dist;

    if (lbl_8040AEE8 != -1 &&
        lbl_803AC5B8[lbl_8040AEE8].id != -1 &&
        lbl_803AC5B8[lbl_8040AEE8].id != 99999) {
        NuVecSub(&diff, &lbl_803B6DF8, (struct nuvec_s *)&lbl_803AC5B8[lbl_8040AEE8]);
        dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
        if (dist == 0.0f)
            return;
    }

    lbl_8040AEE8 = -1;
    for (i = 0; i < 512; i++) {
        if (lbl_803AC5B8[i].id != -1 && lbl_803AC5B8[i].id != 99999) {
            NuVecSub(&diff, &lbl_803B6DF8, (struct nuvec_s *)&lbl_803AC5B8[i]);
            dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
            if (bestDist < 0.0f || dist < bestDist) {
                lbl_8040AEE8 = i;
                bestDist = dist;
            }
        }
    }
}

struct AudioEntry2EC {
    u8 pad0[0x102];
    s16 unk102;
    u8 pad104[0x2EC - 0x104];
};

extern void fn_80064424(struct AudioEntry2EC *, s16);
extern void **lbl_804083FC;
extern struct AudioEntry2EC *lbl_80408404;

struct AudioEmitter {
    u8 pad0[0x11];
    s8 group;
    s16 unk12;
    s16 unk14;
    u8 pad16[6];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    u8 pad28[0x7c];
    f32 unkA4;
    u8 padA8[0x200];
    s32 unk2A8;
    u8 pad2AC[0x15C];
    s16 unk408;
};

void fn_80069ACC(struct AudioEmitter *arg0)
{
    f32 onTime = 0.0f;
    f32 totalTime = 0.0f;
    s32 i;

    while (totalTime < arg0->unkA4) {
        f32 rem = arg0->unkA4 - totalTime;
        f32 pulse = arg0->unk1C + arg0->unk20;
        if (rem < pulse) {
            onTime += rem;
            totalTime += rem;
        } else {
            onTime += pulse;
            totalTime += pulse;
        }
        rem = arg0->unkA4 - totalTime;
        if (rem < arg0->unk24) {
            totalTime += rem;
        } else {
            totalTime += arg0->unk24;
        }
    }

    arg0->unk12 = (s16)((f32)arg0->unk14 * (onTime / totalTime) * arg0->unkA4);
    if (arg0->unk12 <= 0) {
        arg0->unk12 = 1;
    }
    arg0->unk12 *= (arg0->unk408 + 1);

    for (i = 0; i < 512; i++) {
        s32 id = lbl_803AC5B8[i].id;
        if (id != -1 && id != 99999) {
            if (lbl_804083FC[lbl_80408404[id].unk102] == arg0) {
                fn_80064424(&lbl_80408404[id], arg0->unk12);
            }
        }
    }
}

extern f32 NuFsqrt(f32);
extern s32 fn_80027688(void *, void *);

struct AudioCam7114 {
    u8 pad0[0x30];
    struct nuvec_s pos;
};

extern struct AudioCam7114 lbl_80313268;
extern s32 lbl_8040AED0;
extern s32 lbl_8040AED4;

struct AudioScene7114 {
    u8 pad0[0x14];
    void **objs;
};

static inline s32 audio_in_range(struct nuvec_s *pos, f32 maxDist)
{
    f32 dx = pos->x - lbl_80313268.pos.x;
    f32 dy = pos->y - lbl_80313268.pos.y;
    f32 dz = pos->z - lbl_80313268.pos.z;
    if (NuFsqrt(dx * dx + dy * dy + dz * dz) > maxDist)
        return 0;
    return 1;
}

void fn_80067114(struct AudioScene7114 *arg0)
{
    s32 i;

    for (i = 0; i < 64; i++) {
        struct AudioPathSlot *slot = &lbl_80399DAC[i];
        if (slot->id != -1) {
            struct AudioAnimState *anim = slot->animation;
            if ((lbl_8040AED0 || lbl_8040AED4) && lbl_8040AED8 == i) {
                slot->visible = fn_80027688(arg0->objs[slot->id], slot);
            } else if (anim != NULL) {
                if (audio_in_range((struct nuvec_s *)&anim->matrix._30, 40.0f)) {
                    slot->visible = fn_80027688(arg0->objs[slot->id], anim);
                }
            } else {
                if (audio_in_range((struct nuvec_s *)&slot->matrix._30, 40.0f)) {
                    slot->visible = fn_80027688(arg0->objs[slot->id], slot);
                }
            }
        }
    }
}

extern char lbl_802BEAA8[][32];
extern struct AudioNameEntry lbl_803C3F24[];
extern s32 lbl_804086D0;

void fn_8006BA54(s32 arg0)
{
    lbl_803B6E04[arg0].bankBit = -1;
    lbl_803B6E04[arg0].freq = 22050;
    lbl_803B6E04[arg0].name = lbl_802BEAA8[lbl_804086D0];
    lbl_803B6E04[arg0].unkC = 0;
    lbl_803B6E04[arg0].unk18 = 0.0f;
    lbl_803B6E04[arg0].unk12 = 0x3FFF;
    lbl_803B6E04[arg0].unk1C = 0.0f;
    lbl_803B6E04[arg0].unk20 = 0.0f;
    lbl_803B6E04[arg0].linked = -1;
    lbl_803B6E04[arg0].flag16 = 0;
    lbl_803B6E04[arg0].flag16_a = 0;
    lbl_803B6E04[arg0].flag17 = 0;
    lbl_803B6E04[arg0].flag18 = 0;
    lbl_803B6E04[arg0].flag20 = 0;
    lbl_803B6E04[arg0].unk24 = 0.0f;
    lbl_803B6E04[arg0].unk28 = 0.0f;
    lbl_803B6E04[arg0].unk2C = 0.0f;
    lbl_803B6E04[arg0].unk30 = 0;
    lbl_803B6E04[arg0].unk34 = 0.0f;
    lbl_803B6E04[arg0].unk38 = 0.0f;
    lbl_803B6E04[arg0].unk16 = 0;
    lbl_803B6E04[arg0].flag21 = 0;
    lbl_803C3F24[arg0] = lbl_803B6E04[arg0];
}

extern void fn_80060120(s32 *, s32, f32, f32, f32);
extern void fn_800644E4(s32, s16, s16);
extern void fn_80064730(s32, s16, s16, s16);
extern void fn_80064860(s32, s16, s16, f32, f32);
extern void fn_80064888(s32, f32);
extern void fn_800648B4(s32, s32, s32, f32);
extern void fn_800648D8(s32, s16);
extern void fn_800648F4(s32, s32);
extern s32 fn_80064A04(u8 *, s32);
extern s32 lbl_803B6DB8[];

void fn_8006AD0C(s32 arg0)
{
    s32 i;

    for (i = 0; i < 512; i++) {
        if (lbl_803AC5B8[i].group == arg0) {
            s32 savedId = lbl_803AC5B8[i].id;
            if (savedId == 99999) {
                lbl_803AC5B8[i].id = -1;
                lbl_803AC5B8[i].unkC = fn_80064A04(lbl_803AC5B8[i].unk24, arg0);
                fn_80060120(&lbl_803AC5B8[i].id, lbl_803AC5B8[i].unkC, lbl_803AC5B8[i].pos.x, lbl_803AC5B8[i].pos.y, lbl_803AC5B8[i].pos.z);
                if (lbl_803AC5B8[i].id != -1) {
                    lbl_80408404[lbl_803AC5B8[i].id].pad104[0x175] = 0;
                    fn_800644E4(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk14, lbl_803AC5B8[i].unk16);
                    fn_80064730(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk18, lbl_803AC5B8[i].unk1A, lbl_803AC5B8[i].unk1C);
                    fn_80064888(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk20);
                    fn_800648B4(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk34, lbl_803AC5B8[i].unk38, lbl_803AC5B8[i].unk3C);
                    fn_80064860(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk40, lbl_803AC5B8[i].unk42, lbl_803AC5B8[i].unk44, lbl_803AC5B8[i].unk48);
                    fn_800648D8(lbl_803AC5B8[i].id, lbl_803AC5B8[i].unk4C);
                    fn_800648F4(lbl_803AC5B8[i].id, lbl_803B6DB8[lbl_803AC5B8[i].group]);
                } else {
                    lbl_803AC5B8[i].id = savedId;
                }
            }
        }
    }
    lbl_803B6DD8[arg0] = 1;
}

extern void fn_8005EB80(s32 *);
extern void fn_8005ECC8(void *);
extern s32 *lbl_804083EC;
extern s32 lbl_804083F0;
extern s32 lbl_804083F4;
extern s32 lbl_804085D8;
extern s32 lbl_8040AEAC;

void fn_8006AE9C(s32 arg0)
{
    s32 i;
    s32 j;
    s32 none = -1;

    lbl_803B6DD8[arg0] = 0;
    for (i = 0; i < 512; i++) {
        if (lbl_803AC5B8[i].id != -1 && lbl_803AC5B8[i].id != 99999) {
            if (lbl_803AC5B8[i].group == arg0) {
                if (lbl_803AC5B8[i].id != -1 && lbl_803AC5B8[i].id != 99999) {
                    fn_8005EB80(&lbl_803AC5B8[i].id);
                    lbl_803AC5B8[i].id = 99999;
                }
            } else if (lbl_803AC5B8[i].unkC > 0) {
                struct AudioEmitter *em = (struct AudioEmitter *)lbl_804083FC[lbl_803AC5B8[i].unkC];
                if (em != NULL && em->group == arg0) {
                    if (lbl_803AC5B8[i].id != -1) {
                        if (lbl_803AC5B8[i].id != 99999) {
                            fn_8005EB80(&lbl_803AC5B8[i].id);
                        }
                        lbl_803AC5B8[i].id = none;
                        lbl_804085E4--;
                    }
                }
            }
        }
    }
    for (i = 1; i < lbl_804083F4; i++) {
        struct AudioEmitter *em = (struct AudioEmitter *)lbl_804083FC[i];
        if (em != NULL && em->group == arg0) {
            for (j = 0; j < lbl_804083F0; j++) {
                if (lbl_80408404[j].unk102 == i) {
                    s32 tmp = j;
                    fn_8005EB80(&tmp);
                }
            }
            fn_8005ECC8(lbl_804083FC[i]);
        }
    }
}

void fn_8006B03C(s32 arg0)
{
    s32 i;
    s32 j;
    s32 sentinel = 99999;
    s32 none = -1;

    lbl_803B6DD8[arg0] = 0;
    lbl_8038E820[arg0] = 0;
    for (i = 0; i < 512; i++) {
        if (lbl_803AC5B8[i].group == arg0) {
            if (lbl_803AC5B8[i].id != -1) {
                if (lbl_803AC5B8[i].id != sentinel) {
                    fn_8005EB80(&lbl_803AC5B8[i].id);
                }
                lbl_803AC5B8[i].id = none;
                lbl_804085E4--;
            }
        }
    }
    for (i = 1; i < lbl_804083F4; i++) {
        struct AudioEmitter *em = (struct AudioEmitter *)lbl_804083FC[i];
        if (em != NULL && em->group == arg0) {
            for (j = 0; j < lbl_804083F0; j++) {
                if (lbl_80408404[j].unk102 == i) {
                    s32 tmp = j;
                    fn_8005EB80(&tmp);
                }
            }
            fn_8005ECC8(lbl_804083FC[i]);
            if (((struct AudioEmitter *)lbl_804083FC[i])->unk2A8 != 0) {
                lbl_8040AEAC--;
                lbl_804083EC[lbl_8040AEAC] = ((struct AudioEmitter *)lbl_804083FC[i])->unk2A8;
                ((struct AudioEmitter *)lbl_804083FC[i])->unk2A8 = 0;
            }
            lbl_804083FC[i] = NULL;
            lbl_804085D8--;
        }
    }
}

void fn_8006D4F0(s32 arg0)
{
    s32 prev;
    s32 old;

    if (!lbl_804086E8 && !lbl_804086EC) {
        lbl_801BB44C[2] = 1 - lbl_801BB44C[2];
        old = lbl_801BB44C[3];
        lbl_801BB44C[3] = lbl_801BB44C[5];
        lbl_801BB44C[5] = old;
        prev = lbl_801BB44C[3];
        fn_80044BB8(lbl_801BB44C[2]);
        if (arg0 == 1) {
            fn_80044C30(lbl_801BB44C[2], (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[prev].fields[2] * lbl_804086FC));
            fn_80044BF4(1 - lbl_801BB44C[2]);
            fn_80044C30(lbl_801BB44C[2], 0);
            lbl_801BB44C[0] = 4;
            *(f32 *)((u8 *)lbl_801BB44C + 0x18) = 1.0f;
        } else {
            if ((u32)((u16)lbl_801BB44C[0] - 5) <= 1) {
                *(f32 *)((u8 *)lbl_801BB44C + 0x18) = 1.0f - *(f32 *)((u8 *)lbl_801BB44C + 0x18);
            } else {
                *(f32 *)((u8 *)lbl_801BB44C + 0x18) = 0.0f;
            }
            fn_80044C30(lbl_801BB44C[2], (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[prev].fields[2] * *(f32 *)((u8 *)lbl_801BB44C + 0x18)));
            lbl_801BB44C[0] = (arg0 == 3) ? 6 : 5;
        }
        fn_80044D4C();
    }
}

extern void fn_80044668(s32, ...);
extern s32 lbl_801BB468[];
extern f32 lbl_80408700;

struct AudioStreamState {
    s16 state;
    s16 unk2;
    s16 chan;
    s16 curTrack;
    s16 timer;
    s16 prevTrack;
    s16 pendingFlag;
    s16 waitTimer;
    s16 lastChan;
    u8 pending[2];
    f32 fadeIn;
    f32 fade;
    u8 *obj;
};

void fn_8006C9E0(s16 arg0)
{
    if (!lbl_804086E8 && !lbl_804086EC) {
        if (arg0 >= 0 && arg0 <= lbl_804086E0 - 1 && ((struct AudioStreamState *)lbl_801BB44C)->state == 4 &&
            (((struct AudioStreamState *)lbl_801BB44C)->unk2 != arg0 || ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag != 0)) {
            ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->unk2 = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
            if (((struct AudioStreamState *)lbl_801BB44C)->timer > 63) {
                s32 chan = 1 - ((struct AudioStreamState *)lbl_801BB44C)->chan;
                s32 one = 1;
                f32 fade = ((struct AudioStreamState *)lbl_801BB44C)->fadeIn;
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
                fn_80044B7C(chan);
                fn_80044668(2, chan, 3, arg0, 6, 0, 10, 12, fade, one);
                fn_80044D4C();
                ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                ((struct AudioStreamState *)lbl_801BB44C)->fadeIn = 0.0f;
            } else {
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 1;
            }
        }
        if (arg0 >= 0 && arg0 <= lbl_804086E0 - 1 && (u32)((u16)((struct AudioStreamState *)lbl_801BB44C)->state - 11) <= 2 &&
            (((struct AudioStreamState *)lbl_801BB44C)->curTrack != arg0 || ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag != 0)) {
            ((struct AudioStreamState *)lbl_801BB44C)->state = 11;
            ((struct AudioStreamState *)lbl_801BB44C)->curTrack = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->unk2 = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
            if (((struct AudioStreamState *)lbl_801BB44C)->timer > 63) {
                s32 chan;
                f32 fade;
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
                chan = ((struct AudioStreamState *)lbl_801BB44C)->chan;
                fade = ((struct AudioStreamState *)lbl_801BB44C)->fadeIn;
                if (!lbl_804086E8 && !lbl_804086EC) {
                    fn_80044B7C(chan);
                    fn_80044668(2, chan, 3, arg0, 6, 0, 10, 12, fade, 1);
                    fn_80044D4C();
                    ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                    ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                }
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                ((struct AudioStreamState *)lbl_801BB44C)->fadeIn = 0.0f;
            } else {
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 1;
            }
        }
    }
}

void fn_8006CC1C(s16 arg0, f32 fade)
{
    if (fade < 0.0f) {
        fade = lbl_801BB460[0];
    }
    if (arg0 >= 0 && arg0 <= lbl_804086E0 - 1 && (u32)((u16)((struct AudioStreamState *)lbl_801BB44C)->state - 11) <= 2) {
        if (((struct AudioStreamState *)lbl_801BB44C)->curTrack != arg0 || ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag != 0) {
            ((struct AudioStreamState *)lbl_801BB44C)->state = 11;
            ((struct AudioStreamState *)lbl_801BB44C)->unk2 = -1;
            ((struct AudioStreamState *)lbl_801BB44C)->curTrack = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = arg0;
            ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
            if (((struct AudioStreamState *)lbl_801BB44C)->timer > 63) {
                s32 chan;
                s32 vol;
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
                chan = ((struct AudioStreamState *)lbl_801BB44C)->chan;
                vol = (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_804086FC);
                if (!lbl_804086E8 && !lbl_804086EC) {
                    fn_80044B7C(chan);
                    fn_80044668(2, chan, 3, arg0, 6, vol, 10, 12, fade, 1);
                    fn_80044D4C();
                    ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                    ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                }
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                ((struct AudioStreamState *)lbl_801BB44C)->fadeIn = 0.0f;
            } else {
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 1;
            }
        }
    } else if (arg0 >= 0 && arg0 <= lbl_804086E0 - 1) {
        s32 chan;
        s32 vol;
        ((struct AudioStreamState *)lbl_801BB44C)->state = 4;
        ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
        ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
        ((struct AudioStreamState *)lbl_801BB44C)->curTrack = arg0;
        ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = arg0;
        ((struct AudioStreamState *)lbl_801BB44C)->unk2 = arg0;
        ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
        chan = ((struct AudioStreamState *)lbl_801BB44C)->chan;
        vol = (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_804086FC);
        if (!lbl_804086E8 && !lbl_804086EC) {
            fn_80044B7C(chan);
            fn_80044668(2, chan, 3, arg0, 6, vol, 10, 12, fade, 1);
            fn_80044D4C();
            ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
            ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
        }
    }
}

void fn_8006CF50(s16 arg0, s16 arg1, s32 arg2)
{
    if (!lbl_804086E8 && !lbl_804086EC && arg0 >= 0 && arg0 <= lbl_804086E0 - 1) {
        ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
        ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = arg0;
        ((struct AudioStreamState *)lbl_801BB44C)->pending[1 - ((struct AudioStreamState *)lbl_801BB44C)->chan] = 6;
        fn_80044BF4(((struct AudioStreamState *)lbl_801BB44C)->chan);
        fn_80044C30(((struct AudioStreamState *)lbl_801BB44C)->chan, (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_80408700));
        if (((struct AudioStreamState *)lbl_801BB44C)->unk2 == arg0 && ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag == 0) {
            fn_80044BB8(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan);
            fn_80044C30(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan, (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_80408700));
            fn_80044D4C();
        } else {
            s32 chan = 1 - ((struct AudioStreamState *)lbl_801BB44C)->chan;
            s32 vol = (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_80408700);
            if (!lbl_804086E8 && !lbl_804086EC) {
                fn_80044B7C(chan);
                fn_80044668(2, chan, 3, arg0, 6, vol, 0, 1);
                fn_80044D4C();
                ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
            }
        }
        ((struct AudioStreamState *)lbl_801BB44C)->unk2 = -1;
        ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
        ((struct AudioStreamState *)lbl_801BB44C)->fade = 1.0f;
        if (arg1 == 13) {
            ((struct AudioStreamState *)lbl_801BB44C)->state = arg1;
        } else {
            if (((struct AudioStreamState *)lbl_801BB44C)->state == 0) {
                ((struct AudioStreamState *)lbl_801BB44C)->state = 12;
            } else {
                ((struct AudioStreamState *)lbl_801BB44C)->state = 11;
            }
        }
        lbl_801BB468[0] = arg2;
    }
}

void fn_8006D1BC(s32 arg0, s32 arg1)
{
    if (!lbl_804086E8 && !lbl_804086EC && arg0 >= 0 && arg0 <= lbl_804086E0 - 1) {
        ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
        ((struct AudioStreamState *)lbl_801BB44C)->prevTrack = ((struct AudioStreamState *)lbl_801BB44C)->curTrack;
        ((struct AudioStreamState *)lbl_801BB44C)->curTrack = arg0;
        if (((struct AudioStreamState *)lbl_801BB44C)->state == 0 || arg1 == 1 || lbl_80408298 == -1) {
            ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
            if (((struct AudioStreamState *)lbl_801BB44C)->unk2 == arg0) {
                ((struct AudioStreamState *)lbl_801BB44C)->chan = 1 - ((struct AudioStreamState *)lbl_801BB44C)->chan;
            }
            fn_80044B7C(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan);
            if (((struct AudioStreamState *)lbl_801BB44C)->unk2 == arg0 && ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag == 0) {
                fn_80044BB8(((struct AudioStreamState *)lbl_801BB44C)->chan);
                fn_80044C30(((struct AudioStreamState *)lbl_801BB44C)->chan, (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_804086FC));
                fn_80044D4C();
            } else {
                s32 chan = ((struct AudioStreamState *)lbl_801BB44C)->chan;
                s32 vol = (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[arg0].fields[2] * lbl_804086FC);
                if (!lbl_804086E8 && !lbl_804086EC) {
                    fn_80044B7C(chan);
                    fn_80044668(2, chan, 3, arg0, 6, vol, 0, 1);
                    fn_80044D4C();
                    ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                    ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                }
            }
            ((struct AudioStreamState *)lbl_801BB44C)->fade = 1.0f;
            ((struct AudioStreamState *)lbl_801BB44C)->state = 4;
        } else {
            ((struct AudioStreamState *)lbl_801BB44C)->chan = 1 - ((struct AudioStreamState *)lbl_801BB44C)->chan;
            ((struct AudioStreamState *)lbl_801BB44C)->pending[((struct AudioStreamState *)lbl_801BB44C)->chan] = 0;
            if (((struct AudioStreamState *)lbl_801BB44C)->unk2 == arg0 && ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag == 0) {
                ((struct AudioStreamState *)lbl_801BB44C)->state = (arg1 == 3) ? 9 : 7;
                fn_80044BB8(((struct AudioStreamState *)lbl_801BB44C)->chan);
                fn_80044C30(((struct AudioStreamState *)lbl_801BB44C)->chan, 0);
                fn_80044D4C();
            } else {
                s32 chan;
                if (arg1 == 3) {
                    ((struct AudioStreamState *)lbl_801BB44C)->state = 10;
                } else {
                    ((struct AudioStreamState *)lbl_801BB44C)->state = 8;
                }
                chan = ((struct AudioStreamState *)lbl_801BB44C)->chan;
                if (!lbl_804086E8 && !lbl_804086EC) {
                    fn_80044B7C(chan);
                    fn_80044668(2, chan, 3, arg0, 6, 0, 0, 1);
                    fn_80044D4C();
                    ((struct AudioStreamState *)lbl_801BB44C)->lastChan = chan;
                    ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                }
            }
            ((struct AudioStreamState *)lbl_801BB44C)->fade = 0.0f;
        }
        ((struct AudioStreamState *)lbl_801BB44C)->unk2 = -1;
        ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag = 0;
    }
}

extern s32 NuFileClose(char *);
extern void NuStrCat(char *, const char *);
extern void NuStrCatW(char *, const char *, const char *, s32);
extern void NuStrCpy(char *, const char *);
extern void fn_80037E1C(void);
extern void fn_80037FEC(void);
extern s32 fn_8009D320();
extern s32 fn_8009D414(void);
extern char lbl_802B15E4[][64];
extern s32 lbl_804086CC;
extern s32 lbl_80408710;

void fn_8006C748(u32 *arg0, u32 *arg1, char *arg2)
{
    char buf[1024];
    u32 end;
    u32 saved;
    u32 i;
    s32 j;
    s32 count;
    u32 base;
    u32 savedEnd = *arg1;

    base = (*arg0 + 3) & ~3u;
    *arg0 = base;
    lbl_8040AEEC = (s16 *)base;
    *arg0 = base + 0x200;

    for (i = 0; i < 256; i++) {
        u32 crc = i << 24;
        for (j = 0; j < 8; j++) {
            u32 bit = crc >> 31;
            crc <<= 1;
            if (bit) {
                crc ^= 0x04C11DB7;
            }
        }
        lbl_803C3B24[i] = crc;
    }

    for (j = 255; j >= 0; j--) {
        lbl_8040AEEC[j] = -1;
    }

    lbl_804086C8 = 0;
    lbl_804086D0 = 0;
    for (count = 0; count < lbl_804086E0; count++) {
        lbl_803D0724[count] = ((struct AudioRequestEntry *)lbl_804086DC)[count];
        lbl_803D0724[count].fields[3] = count;
        NuStrCpy(lbl_802B15E4[count], (const char *)lbl_803D0724[count].fields[0]);
        NuStrCat(lbl_802B15E4[count], ".wav");
        lbl_803D0724[count].fields[0] = (s32)lbl_802B15E4[count];
        lbl_804086C8++;
        lbl_804086CC++;
    }

    lbl_803D0724[count].fields[1] = 0;
    lbl_803D0724[count].fields[0] = 0;
    lbl_803D0724[count].fields[2] = 0;
    lbl_803D0724[count].fields[3] = -1;

    NuStrCatW(buf, arg2, "fpk", 0x400);
    if (NuFileClose(buf) != 0) {
        fn_80037E1C();
    }
    end = savedEnd;
    saved = *arg0;
    lbl_80408710 = fn_8009D320(buf, arg0, &end);
    while (fn_8009D414() != 0) {
        fn_80037FEC();
    }
    *arg0 = saved;
    fn_8006C65C(arg2);
    {
        u16 *mask = (u16 *)lbl_803D461C;
        ((void *(*)())memset)(mask, 0, 0x64);
    }
    for (j = 0; j < lbl_804086D0; j++) {
        if (lbl_803B6E04[j].flag17) {
            s32 bank = lbl_803B6E04[j].bankBit;
            ((u16 *)lbl_803D461C)[bank >> 4] |= 1 << (bank & 15);
        }
    }
    fn_8000759C(lbl_803D45B8, (s32)lbl_803D461C, 0x64);
}

void fn_8006D69C(f32 dt)
{
    if (dt != 0.0f) {
        switch (((struct AudioStreamState *)lbl_801BB44C)->state) {
        case 8:
        case 10:
            if (fn_80044C78(((struct AudioStreamState *)lbl_801BB44C)->chan) != 2) {
                ((struct AudioStreamState *)lbl_801BB44C)->state = 7;
            }
            break;

        case 5:
        case 6:
        case 7:
        case 9:
            if (((struct AudioStreamState *)lbl_801BB44C)->state == 9 ||
                ((struct AudioStreamState *)lbl_801BB44C)->state == 6) {
                ((struct AudioStreamState *)lbl_801BB44C)->fade += 2.0f * dt;
            } else {
                ((struct AudioStreamState *)lbl_801BB44C)->fade += dt * 0.2f;
            }
            if (((struct AudioStreamState *)lbl_801BB44C)->fade >= 1.0f) {
                ((struct AudioStreamState *)lbl_801BB44C)->fade = 1.0f;
                if ((u32)((u16)((struct AudioStreamState *)lbl_801BB44C)->state - 5) > 1) {
                    fn_80044B7C(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan);
                } else {
                    fn_80044BF4(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan);
                }
                ((struct AudioStreamState *)lbl_801BB44C)->state = 4;
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
            }
            {
                s32 vol0 = (s32)(((struct AudioStreamState *)lbl_801BB44C)->fade *
                                 (f32)((struct AudioTrackEntry *)lbl_804086DC)[((struct AudioStreamState *)lbl_801BB44C)->curTrack].fields[2] *
                                 lbl_804086FC);
                s32 vol1 = (s32)((1.0f - ((struct AudioStreamState *)lbl_801BB44C)->fade) *
                                 (f32)((struct AudioTrackEntry *)lbl_804086DC)[((struct AudioStreamState *)lbl_801BB44C)->prevTrack].fields[2] *
                                 lbl_804086FC);
                fn_80044C30(((struct AudioStreamState *)lbl_801BB44C)->chan, vol0);
                fn_80044C30(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan, vol1);
            }
            break;

        case 11:
        case 12:
        case 13:
            if (*(u32 *)(((struct AudioStreamState *)lbl_801BB44C)->obj + 0x88) & 0x40000000) {
                ((struct AudioStreamState *)lbl_801BB44C)->waitTimer = 0;
            } else if (((struct AudioStreamState *)lbl_801BB44C)->waitTimer <= 63) {
                ((struct AudioStreamState *)lbl_801BB44C)->waitTimer++;
            }
            if (((struct AudioStreamState *)lbl_801BB44C)->waitTimer > 8 &&
                ((struct AudioStreamState *)lbl_801BB44C)->curTrack != -1 &&
                ((struct AudioStreamState *)lbl_801BB44C)->state != 13 &&
                fn_80044C78(((struct AudioStreamState *)lbl_801BB44C)->chan) != 2 &&
                ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag == 0) {
                ((struct AudioStreamState *)lbl_801BB44C)->state = 4;
                ((struct AudioStreamState *)lbl_801BB44C)->fade = 1.0f;
                fn_80044B7C(1 - ((struct AudioStreamState *)lbl_801BB44C)->chan);
                fn_80044BB8(((struct AudioStreamState *)lbl_801BB44C)->chan);
                fn_80044C30(((struct AudioStreamState *)lbl_801BB44C)->chan,
                            (s32)((f32)((struct AudioTrackEntry *)lbl_804086DC)[((struct AudioStreamState *)lbl_801BB44C)->curTrack].fields[2] * lbl_804086FC));
                fn_80044D4C();
                ((struct AudioStreamState *)lbl_801BB44C)->timer = 0;
                ((struct AudioStreamState *)lbl_801BB44C)->unk2 = -1;
            }
            if (fn_80044C78(((struct AudioStreamState *)lbl_801BB44C)->lastChan) != 2) {
                if (((struct AudioStreamState *)lbl_801BB44C)->timer <= 127) {
                    ((struct AudioStreamState *)lbl_801BB44C)->timer++;
                }
                if (((struct AudioStreamState *)lbl_801BB44C)->timer > 64 &&
                    ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag != 0) {
                    fn_8006C9E0(((struct AudioStreamState *)lbl_801BB44C)->unk2);
                }
            }
            break;

        case 4:
            if (fn_80044C78(((struct AudioStreamState *)lbl_801BB44C)->lastChan) != 2) {
                if (((struct AudioStreamState *)lbl_801BB44C)->timer <= 127) {
                    ((struct AudioStreamState *)lbl_801BB44C)->timer++;
                }
                if (((struct AudioStreamState *)lbl_801BB44C)->timer > 64 &&
                    ((struct AudioStreamState *)lbl_801BB44C)->pendingFlag != 0) {
                    fn_8006C9E0(((struct AudioStreamState *)lbl_801BB44C)->unk2);
                }
            }
            break;
        }
    }
}
