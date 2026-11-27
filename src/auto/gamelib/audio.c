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
    unsigned int : 16;
    u8 pad8[8];
    s16 next;
    u8 pad12[2];
    s16 linked;
    u8 rest[0x2a];
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
    u8 pad0[0x30];
    struct nuvec_s position;
    u8 pad3C[8];
    f32 unk44;
    u8 pad48[4];
    f32 time;
    u32 flags;
};

struct AudioPathSlot {
    struct numtx_s matrix;
    s16 id;
    u8 pad42[2];
    u32 flags;
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
    u8 pad0[0x10];
    s32 id;
    u8 pad14[0x40];
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
