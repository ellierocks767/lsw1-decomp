#include "types.h"
#include "numath/numath.h"


typedef struct HVQM4AudioNode HVQM4AudioNode;
struct HVQM4AudioNode {
    HVQM4AudioNode* nextFree;
    HVQM4AudioNode* nextSend;
    u32 size;
    void* data;
};

typedef struct {
    HVQM4AudioNode* freeHead;
    HVQM4AudioNode* freeTail;
    HVQM4AudioNode* sendHead;
    HVQM4AudioNode* sendTail;
} HVQM4AudioQueue;

typedef struct HVQM4VideoNode HVQM4VideoNode;
struct HVQM4VideoNode {
    HVQM4VideoNode* nextFree;
    HVQM4VideoNode* prevFree;
    HVQM4VideoNode* nextDisplay;
    u32 size;
    void* data;
    s32 busy;
};

typedef struct {
    HVQM4VideoNode* freeHead;
    HVQM4VideoNode* displayHead;
    HVQM4VideoNode* displayTail;
} HVQM4VideoQueue;

typedef struct HVQM4DvdStream {
    u8 fileInfo[0x3c];
    void* buffer;
    u8 unk40[0xc];
    s32 driveStatus;
    u8 unk50[8];
    s32 readOffset;
    u8 unk5c[4];
    s32 nextOffset;
    s32 result;
    s32 seeking;
    void (*onStatusChange)(s32, s32, s32);
    s32 callbackArg0;
    s32 callbackArg1;
} HVQM4DvdStream;

extern s32 lbl_80408388;
s32 DVDGetCommandBlockStatus(const void*);
s32 DVDClose(void*);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
s32 OSJoinThread(void*, void*);
s32 OSResumeThread(void*);
s32 fn_8004B66C(HVQM4DvdStream*);

typedef struct HVQM4PlayerState {
    HVQM4DvdStream* stream;
    u8 unk04[0x5c];
    void* work;
    HVQM4VideoQueue* video;
    HVQM4AudioQueue* audio;
    void* sound;
    u8 unk70[0x320];
    void* stack;
    u32 readSize;
    void* readBuffer;
    s32 started;
    s32 executing;
    s32 buffering;
    s32 control;
    s32 unk3ac;
    s32 unk3b0;
    s32 wait;
    s32 drop;
    s32 exiting;
    u32 interlaced;
    u32 field;
    u64 elapsed;
    u64 nextTime;
    u32 frameTime;
    u8 unk3dc[0x5c];
    s32 missedFrames;
} HVQM4PlayerState;

extern u32 lbl_80408380;
extern volatile s32 lbl_8040837C;
u32 VIGetNextField(void);
s32 HVQM4DecSoundClose(void*);

extern s32 lbl_804083B0;
extern s32 lbl_8040A604;
extern s32 lbl_8040A608;

void HVQM4PlayerExBufvSetBusyFlag(u8* a, s32 b)
{
    *(s32*)(a + 20) = b;
}

void fn_8005A320(s32 a, u8* b, s32 c)
{
    lbl_804083B0 = a;
    lbl_8040A604 = b;
    *(s32*)b = 0;
    lbl_8040A608 = c;
}

void HVQM4PlayerEx1stFrameFunc(u8* a, s32 b, s32 c)
{
    *(s32*)(a + 988) = b;
    *(s32*)(a + 992) = c;
}

s32 HVQM4PlayerExCheckExecute(u8* a)
{
    return *(s32*)(a + 928);
}

s32 HVQM4PlayerExGetMicroSecPerFrame(u8* a)
{
    return *(s32*)(a + 40);
}

s32 HVQM4PlayerExGetAudioSamples(u8* a)
{
    return *(s32*)(a + 68);
}

s32 fn_8004ACE0(u8* a)
{
    return *(s32*)(a + 16);
}

s32 fn_8004ADAC(u8* a)
{
    return *(s32*)(a + 12);
}

s32 fn_8004ADB4(u8* a)
{
    return *(s32*)(a + 8);
}

s32 HVQM4PlayerExControlExit(u8* a)
{
    *(s32*)(a + 956) = 1;
    *(s32*)(a + 944) = 1;
    return 1;
}

s32 fn_8004BCB0(u8* a)
{
    return *(s32*)(a + 84);
}

s32 HVQM4BufaChkSend(void *arg0) {
    s32 interrupts;
    s32 temp_r29;

    interrupts = OSDisableInterrupts();
    temp_r29 = (*(s32 *)((s8 *)(arg0) + (8)));
    OSRestoreInterrupts(interrupts);
    return temp_r29;
}

s32 HVQM4BufaGetSendNums(void *arg0) {
    s32 interrupts;
    s32 var_r31;
    void *var_r9;

    var_r31 = 0;
    interrupts = OSDisableInterrupts();
    var_r9 = (*(void **)((s8 *)(arg0) + (8)));
    if (var_r9 != NULL) {
        do {
            var_r9 = (*(void **)((s8 *)(var_r9) + (4)));
            var_r31 += 1;
        } while (var_r9 != NULL);
    }
    OSRestoreInterrupts(interrupts);
    return var_r31;
}

s32 HVQM4BufvChkDisp(void *arg0) {
    s32 interrupts;
    s32 temp_r29;

    interrupts = OSDisableInterrupts();
    temp_r29 = (*(s32 *)((s8 *)(arg0) + (4)));
    OSRestoreInterrupts(interrupts);
    return temp_r29;
}

s32 HVQM4BufvGetDispNums(void *arg0) {
    s32 interrupts;
    s32 var_r31;
    void *var_r9;

    var_r31 = 0;
    interrupts = OSDisableInterrupts();
    var_r9 = (*(void **)((s8 *)(arg0) + (4)));
    if (var_r9 != NULL) {
        do {
            var_r9 = (*(void **)((s8 *)(var_r9) + (8)));
            var_r31 += 1;
        } while (var_r9 != NULL);
    }
    OSRestoreInterrupts(interrupts);
    return var_r31;
}

void HVQM4BufvSetFree(s32 **arg0, s32 *arg1) {
    s32 interrupts;
    s32 *temp_r11;
    s32 *temp_r9;

    interrupts = OSDisableInterrupts();
    temp_r11 = *arg0;
    if (temp_r11 == NULL) {
        (*(s32 **)((s8 *)(arg1) + (0))) = arg1;
        (*(s32 **)((s8 *)(arg1) + (4))) = arg1;
        *arg0 = arg1;
    } else {
        temp_r9 = (*(s32 **)((s8 *)(temp_r11) + (4)));
        (*(s32 **)((s8 *)(temp_r11) + (4))) = arg1;
        (*(s32 **)((s8 *)(arg1) + (0))) = temp_r11;
        (*(s32 **)((s8 *)(arg1) + (4))) = temp_r9;
        *temp_r9 = arg1;
    }
    OSRestoreInterrupts(interrupts);
}

void HVQM4BufaSetFree(HVQM4AudioQueue*, HVQM4AudioNode*);
HVQM4AudioNode* HVQM4BufaGetSend(HVQM4AudioQueue*);
HVQM4VideoNode* HVQM4BufvGetDisp(HVQM4VideoQueue*);

void HVQM4PlayerExBufaSetFree(HVQM4PlayerState* player, HVQM4AudioNode* node)
{
    HVQM4BufaSetFree(player->audio, node);
}

s32 fn_8004A578(s32, s32 *);
extern s32 lbl_80408378;

s32 HVQM4PlayerExClose(s32 arg0, s32 *arg1) {
    s32 sp8;
    s32 var_r29;

    OSJoinThread((void*)(arg0 + 0x78), &sp8);
    var_r29 = 1;
    if (fn_8004A578(arg0, arg1) == 0) {
        var_r29 = 0;
    }
    if ((s32) lbl_80408378 != 0) {
        if (arg1 != NULL) {
            *arg1 = 0xD;
        }
        var_r29 = 0;
    }
    return var_r29;
}

s32 HVQM4PlayerExStart(s32 arg0) {
    OSResumeThread((void*)(arg0 + 0x78));
    return 1;
}

void fn_80049A10(void*);

s32 fn_8004B088(HVQM4AudioQueue* queue) {
    fn_80049A10(queue);
    return 1;
}


s32 fn_8004B3EC(HVQM4VideoQueue* queue) {
    fn_80049A10(queue);
    return 1;
}

s32 fn_8004BCB8(HVQM4DvdStream* stream)
{
    return DVDGetCommandBlockStatus(stream);
}

s32 fn_8004BC1C(HVQM4DvdStream*);

s32 fn_8004BCD8(void *arg0) {
    s32 (*temp_r0)(s32, s32, s32);
    s32 temp_r3;

    if ((s32) (*(s32 *)((s8 *)(arg0) + (0x64))) == 0) {
        temp_r3 = DVDGetCommandBlockStatus(arg0);
        if (temp_r3 != (s32) (*(s32 *)((s8 *)(arg0) + (0x4C)))) {
            temp_r0 = (*(s32 (**)(s32, s32, s32))((s8 *)(arg0) + (0x6C)));
            (*(s32 *)((s8 *)(arg0) + (0x4C))) = temp_r3;
            if (temp_r0 != NULL) {
                temp_r0((*(s32 *)((s8 *)(arg0) + (0x70))), (*(s32 *)((s8 *)(arg0) + (0x74))), temp_r3);
            }
        }
        return 1;
    }
    return 0;
}

void fn_8004BDD0(void *arg0) {
    s32 (*temp_r0)(s32, s32, s32);
    s32 temp_r3;

    temp_r3 = DVDGetCommandBlockStatus(arg0);
    if (temp_r3 != (s32) (*(s32 *)((s8 *)(arg0) + (0x4C)))) {
        temp_r0 = (*(s32 (**)(s32, s32, s32))((s8 *)(arg0) + (0x6C)));
        (*(s32 *)((s8 *)(arg0) + (0x4C))) = temp_r3;
        if (temp_r0 != NULL) {
            temp_r0((*(s32 *)((s8 *)(arg0) + (0x70))), (*(s32 *)((s8 *)(arg0) + (0x74))), temp_r3);
        }
    }
}

f32 NuCosApprox(s32);
f32 NuSinApprox(s32);
f32 NuFsqrt(f32);

typedef struct terrainvec_s {
    f32 x;
    f32 y;
    f32 z;
} terrainvec_s;

typedef struct terrainpoly_s {
    u8 pad00[0x18];
    terrainvec_s verts[4];
    terrainvec_s normal;
    terrainvec_s normal2;
    u8 unk60;
    u8 unk61;
    u8 flags;
    u8 unk63;
} terrainpoly_s;

typedef struct terrainnode_s {
    terrainvec_s origin;
    u8 pad0c[0x20];
    s32 unk2c;
    s16 index;
    u8 pad32[6];
} terrainnode_s;

typedef struct terrainsphere_s {
    terrainvec_s pos;
    f32 rad;
} terrainsphere_s;

typedef struct terrainwall_s {
    u16 count;
    u8 unk2;
    u8 flags;
    terrainvec_s pts[1];
} terrainwall_s;

typedef struct terrainwallpt_s {
    terrainvec_s pos;
    u8 unk_c;
    u8 unk_d;
    u8 unk_e;
    u8 unk_f;
} terrainwallpt_s;

typedef struct NUTERRAININDEXEDENTRY_s {
    u8 pad00[0x40];
    u32 active;
    u8 pad44[4];
    s16 compactIndex;
    u8 pad4A[0x22];
} TerrainIndexedEntry;

typedef struct NUTERRAINTRACKEDENTRY_s {
    u32 active;
    s16 index;
    u8 pad06[0x12];
} TerrainTrackedEntry;

typedef struct terrainhdr_s {
    terrainnode_s *nodes;
    u8 pad004[0x64];
    TerrainIndexedEntry *indexedEntries;
    u8 pad06C[0xDC];
    terrainwall_s *walls;
    s16 compactCount;
    u8 pad14E[2];
    s32 remapCount;
    u8 pad154[0x44];
    TerrainTrackedEntry trackedEntries[64];
    u8 pad798[0x1400];
    s16 remapStart;
    s16 remapLength;
    u8 pad1B9C[0x18];
    s16 *remap;
    u8 pad1BB8[0x89E4];
    s32 indexedCount;
} terrainhdr_s;

typedef struct terrainscan_s {
    u8 pad00[0x1c];
    terrainvec_s start;
    terrainvec_s delta;
    u8 unk34;
    s8 unk35;
    u8 pad36[6];
    f32 horiz_dist;
    u8 pad40[4];
    f32 rotationX;
    f32 rotationY;
    f32 len;
    f32 rad;
    f32 rad_sq;
    f32 field58;
    f32 unk5c;
    u8 pad60[4];
    f32 unk64;
    f32 field68;
    s16 unk6c;
    u8 pad6e[2];
    terrainvec_s pos;
    terrainvec_s end_pos;
    u8 type;
    u8 pad89;
    s16 unk8a;
    u8 pad8c[4];
    terrainpoly_s *hit_poly;
    terrainpoly_s *poly;
    f32 best_t;
    u8 pad9c[4];
    f32 fieldA0;
    f32 unk_a4;
    terrainvec_s norm;
    terrainvec_s scaledDirection;
    u8 padc0[0x3c];
    terrainvec_s local_verts[4];
    u8 pad12c[0x1c];
    s32 inline_list[1];
} terrainscan_s;

extern terrainscan_s *lbl_8040AE5C;
extern terrainhdr_s *lbl_8040AE4C;
extern s32 *lbl_8040A5F4;
extern s32 lbl_8040A588;
extern s32 lbl_8040A5CC;
extern s32 lbl_8040A5D0;
extern s32 lbl_8040839C;
extern u8 *lbl_804083A0;
extern terrainwallpt_s *lbl_8040A5B4;
extern s32 lbl_8040A5B8;
extern s32 lbl_8040A5BC;
extern s32 lbl_8040A5E8;
extern terrainsphere_s lbl_802B13B4[];

s32 fn_80052590(terrainpoly_s *, f32, f32, f32, f32);
void fn_80052CAC(void);

void fn_8004F590(void *arg0)
{
  f32 temp_f11;
  f32 *new_var3;
  f32 temp_f12;
  f32 temp_f13;
  f32 temp_f13_2;
  f32 temp_f1;
  f32 temp_f29;
  f32 *new_var;
  s8 *new_var2;
  f32 temp_f30;
  f32 temp_f31;
  new_var2 = (s8 *) arg0;
  temp_f29 = NuSinApprox((s32) (-(*((f32 *) (((s8 *) lbl_8040AE5C) + 0x44)))));
  temp_f30 = NuCosApprox((s32) (-(*((f32 *) (((s8 *) lbl_8040AE5C) + 0x44)))));
  temp_f31 = NuSinApprox((s32) (-(*((f32 *) (((s8 *) lbl_8040AE5C) + 0x48)))));
  temp_f1 = NuCosApprox((s32) (-(*((f32 *) (((s8 *) lbl_8040AE5C) + 0x48)))));
  temp_f11 = (*((f32 *) (((s8 *) arg0) + 0))) - (*((f32 *) (((s8 *) lbl_8040AE5C) + 0x1C)));
  temp_f12 = *((f32 *) (new_var2 + 4));
  temp_f13 = (*((f32 *) (new_var2 + 8))) - (*((f32 *) (((s8 *) lbl_8040AE5C) + 0x24)));
  new_var3 = (f32 *) (((s8 *) lbl_8040AE5C) + 0x20);
  new_var = (f32 *) (((s8 *) lbl_8040AE5C) + 0x50);
  if (!temp_f11)
  {
  }
  *((f32 *) (((s8 *) arg0) + 0)) = (f32) ((temp_f13 * temp_f31) + (temp_f11 * temp_f1));
  temp_f13_2 = (temp_f13 * temp_f1) - (temp_f11 * temp_f31);
  *((f32 *) (((s8 *) arg0) + 8)) = (f32) ((((temp_f12 + (*new_var)) - (*new_var3)) * temp_f29) + (temp_f13_2 * temp_f30));
  *((f32 *) (((s8 *) arg0) + 4)) = (f32) ((((temp_f12 + (*new_var)) - (*new_var3)) * temp_f30) - (temp_f13_2 * temp_f29));
}

s32 HVQM4PlayerExControlCheckNormal(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x3A8))) == 0;
}

void HVQM4BufaSetSend(void *arg0, void *arg1) {
    s32 interrupts = OSDisableInterrupts();
    if ((void *) (*(void **)((s8 *)(arg0) + (8))) == NULL) {
        (*(void **)((s8 *)(arg0) + (8))) = arg1;
        (*(void **)((s8 *)(arg0) + (0xC))) = arg1;
    } else {
        (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (0xC)))) + (4))) = arg1;
        (*(void **)((s8 *)(arg0) + (0xC))) = arg1;
    }
    (*(s32 *)((s8 *)(arg1) + (4))) = 0;
    OSRestoreInterrupts(interrupts);
}

void HVQM4BufvSetDisp(void *arg0, void *arg1) {
    s32 interrupts = OSDisableInterrupts();
    if ((void *) (*(void **)((s8 *)(arg0) + (4))) == NULL) {
        (*(void **)((s8 *)(arg0) + (4))) = arg1;
        (*(void **)((s8 *)(arg0) + (8))) = arg1;
    } else {
        (*(void **)((s8 *)((*(void **)((s8 *)(arg0) + (8)))) + (8))) = arg1;
        (*(void **)((s8 *)(arg0) + (8))) = arg1;
    }
    (*(s32 *)((s8 *)(arg1) + (8))) = 0;
    OSRestoreInterrupts(interrupts);
}

HVQM4VideoNode* fn_8004ACF0(HVQM4PlayerState* player)
{
    HVQM4VideoNode* node;
    HVQM4VideoNode* next;

    if (player->buffering) {
        return NULL;
    }
    if (lbl_80408378 != 0) {
        while ((node = HVQM4BufvGetDisp(player->video)) != NULL) {
            node->busy = 0;
        }
    } else {
        node = HVQM4BufvGetDisp(player->video);
        if (node != NULL && player->drop) {
            while ((next = HVQM4BufvGetDisp(player->video)) != NULL) {
                node->busy = 0;
                node = next;
            }
        }
        if (node == NULL) {
            player->missedFrames++;
        }
    }
    return node;
}

HVQM4AudioNode* fn_8004ADE0(HVQM4PlayerState* player)
{
    HVQM4AudioNode* node;
    HVQM4AudioNode* next;

    if (player->buffering || !player->started || player->audio == NULL) {
        return NULL;
    }
    if (lbl_80408378 != 0) {
        while ((node = HVQM4BufaGetSend(player->audio)) != NULL) {
            HVQM4BufaSetFree(player->audio, node);
        }
    } else {
        node = HVQM4BufaGetSend(player->audio);
        if (node != NULL && player->drop) {
            while ((next = HVQM4BufaGetSend(player->audio)) != NULL) {
                HVQM4BufaSetFree(player->audio, node);
                node = next;
            }
        }
    }
    return node;
}

s32 fn_8004A578(s32 state, s32* error)
{
    HVQM4PlayerState* player = (HVQM4PlayerState*)state;
    s32 success = 1;
    s32 interrupts;

    if (player->readBuffer != NULL) {
        fn_80049A10(player->readBuffer);
        player->readBuffer = NULL;
        player->readSize = 0;
    }
    if (player->stream != NULL) {
        if (fn_8004BCB8(player->stream) == -1) {
            if (error != NULL) {
                *error = 12;
            }
            success = 0;
        }
        fn_8004BC1C(player->stream);
        player->stream = NULL;
    }
    if (player->work != NULL) {
        fn_80049A10(player->work);
        player->work = NULL;
    }
    if (player->video != NULL) {
        fn_8004B3EC(player->video);
        player->video = NULL;
    }
    if (player->audio != NULL) {
        fn_8004B088(player->audio);
        player->audio = NULL;
    }
    if (player->sound != NULL) {
        HVQM4DecSoundClose(player->sound);
        player->sound = NULL;
    }
    if (player->stack != NULL) {
        fn_80049A10(player->stack);
        player->stack = NULL;
    }
    fn_80049A10(player);
    interrupts = OSDisableInterrupts();
    if (lbl_8040837C > 0) {
        lbl_8040837C--;
    }
    OSRestoreInterrupts(interrupts);
    return success;
}

s32 fn_8004AEB4(HVQM4PlayerState* player)
{
    HVQM4AudioNode* audio;
    HVQM4VideoNode* video;
    s32 interrupts = OSDisableInterrupts();
    s32 decrementInterrupts;

    if (player->control) {
        if (player->audio != NULL) {
            while ((audio = HVQM4BufaGetSend(player->audio)) != NULL) {
                HVQM4BufaSetFree(player->audio, audio);
            }
        }
        while ((video = HVQM4BufvGetDisp(player->video)) != NULL) {
            video->busy = 0;
        }
        player->buffering = 1;
    }
    player->control = 0;
    OSRestoreInterrupts(interrupts);

    player->drop = 0;
    decrementInterrupts = OSDisableInterrupts();
    if (player->wait > 0) {
        player->wait--;
    }
    OSRestoreInterrupts(decrementInterrupts);
    return 1;
}

void fn_8004BD4C(s32 length, HVQM4DvdStream* stream)
{
    volatile HVQM4DvdStream* state = stream;

    fn_8004BDD0(stream);
    if (stream->result == 0) {
        if (length < 0) {
            stream->result = -1;
        } else if (length == state->readOffset - state->nextOffset) {
            if (lbl_80408388 != 0) {
                stream->result = -1;
            } else {
                state->nextOffset = state->readOffset;
                fn_8004B66C(stream);
            }
        }
    }
}

void HVQM4BufaSetFree(HVQM4AudioQueue* queue, HVQM4AudioNode* node)
{
    s32 interrupts = OSDisableInterrupts();

    if (queue->freeHead == NULL) {
        queue->freeHead = node;
        queue->freeTail = node;
    } else {
        queue->freeTail->nextFree = node;
        queue->freeTail = node;
    }
    node->nextFree = NULL;
    OSRestoreInterrupts(interrupts);
}

HVQM4AudioNode* HVQM4BufaGetFree(HVQM4AudioQueue* queue)
{
    register HVQM4AudioNode* node asm("r30");
    HVQM4AudioNode* next;
    s32 interrupts = OSDisableInterrupts();

    node = queue->freeHead;
    if (node != NULL) {
        next = node->nextFree;
        if (next == NULL) {
            queue->freeTail = next;
        }
        queue->freeHead = next;
        node->nextFree = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

HVQM4AudioNode* HVQM4BufaGetSend(HVQM4AudioQueue* queue)
{
    register HVQM4AudioNode* node asm("r30");
    HVQM4AudioNode* next;
    s32 interrupts = OSDisableInterrupts();

    node = queue->sendHead;
    if (node != NULL) {
        next = node->nextSend;
        if (next == NULL) {
            queue->sendTail = next;
        }
        queue->sendHead = next;
        node->nextSend = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

HVQM4VideoNode* HVQM4BufvGetDisp(HVQM4VideoQueue* queue)
{
    register HVQM4VideoNode* node asm("r30");
    HVQM4VideoNode* next;
    s32 interrupts = OSDisableInterrupts();

    node = queue->displayHead;
    if (node != NULL) {
        next = node->nextDisplay;
        if (next == NULL) {
            queue->displayTail = next;
        }
        queue->displayHead = next;
        node->nextDisplay = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

s32 fn_8005241C(terrainvec_s *p, f32 r) {
    f32 sum_r;
    f32 r_sq;
    f32 d_sq;
    f32 dz;
    f32 t;

    if (p->z < -lbl_8040AE5C->rad - r) {
        return 0;
    }
    sum_r = lbl_8040AE5C->rad + r;
    if (p->z > sum_r + lbl_8040AE5C->len) {
        return 0;
    }
    r_sq = sum_r * sum_r;
    d_sq = p->x * p->x + p->y * p->y;
    if (d_sq > r_sq) {
        return 0;
    }
    dz = NuFsqrt(r_sq - d_sq);
    t = p->z - dz;
    if (t < 0.0f || t > lbl_8040AE5C->len) {
        d_sq += p->z * p->z;
        if (d_sq < r_sq) {
            dz = 1.0f / NuFsqrt(d_sq);
            lbl_8040AE5C->type = 20;
            lbl_8040AE5C->best_t = 0.0f;
            lbl_8040AE5C->norm.x = -p->x * dz;
            lbl_8040AE5C->norm.y = -p->y * dz;
            lbl_8040AE5C->norm.z = -p->z * dz;
            return 1;
        }
        return 0;
    }
    d_sq = t / lbl_8040AE5C->len;
    if (d_sq < lbl_8040AE5C->best_t) {
        lbl_8040AE5C->type = 4;
        lbl_8040AE5C->best_t = d_sq;
        lbl_8040AE5C->norm.x = -p->x;
        lbl_8040AE5C->norm.y = -p->y;
        lbl_8040AE5C->norm.z = -dz;
        return 1;
    }
    return 0;
}

s32 fn_80052224(s32 idx) {
    f32 d_sq;
    f32 dz;
    f32 t;

    if (lbl_8040AE5C->local_verts[idx].z < -lbl_8040AE5C->rad) {
        return 0;
    }
    if (lbl_8040AE5C->local_verts[idx].z > lbl_8040AE5C->rad + lbl_8040AE5C->len) {
        return 0;
    }
    d_sq = lbl_8040AE5C->local_verts[idx].x * lbl_8040AE5C->local_verts[idx].x +
           lbl_8040AE5C->local_verts[idx].y * lbl_8040AE5C->local_verts[idx].y;
    if (d_sq > lbl_8040AE5C->rad_sq) {
        return 0;
    }
    dz = NuFsqrt(lbl_8040AE5C->rad_sq - d_sq);
    t = lbl_8040AE5C->local_verts[idx].z - dz;
    if (t < 0.0f || t > lbl_8040AE5C->len) {
        d_sq += lbl_8040AE5C->local_verts[idx].z * lbl_8040AE5C->local_verts[idx].z;
        if (d_sq < lbl_8040AE5C->rad_sq) {
            f32 pen;
            d_sq = NuFsqrt(d_sq);
            pen = d_sq - lbl_8040AE5C->rad;
            if (pen < lbl_8040AE5C->best_t) {
                terrainpoly_s *poly = lbl_8040AE5C->poly;
                dz = (lbl_8040AE5C->pos.x - poly->verts[idx].x) * poly->normal.x +
                     (lbl_8040AE5C->pos.y - poly->verts[idx].y) * poly->normal.y +
                     (lbl_8040AE5C->pos.z - poly->verts[idx].z) * poly->normal.z;
                if (dz > 0.0f) {
                    dz = 1.0f / d_sq;
                    lbl_8040AE5C->best_t = pen;
                    lbl_8040AE5C->type = 19;
                    lbl_8040AE5C->norm.x = -lbl_8040AE5C->local_verts[idx].x * dz;
                    lbl_8040AE5C->norm.y = -lbl_8040AE5C->local_verts[idx].y * dz;
                    lbl_8040AE5C->norm.z = -lbl_8040AE5C->local_verts[idx].z * dz;
                    return 1;
                }
            }
        }
        return 0;
    }
    d_sq = t / lbl_8040AE5C->len;
    if (d_sq < lbl_8040AE5C->best_t) {
        lbl_8040AE5C->type = 3;
        lbl_8040AE5C->best_t = d_sq;
        lbl_8040AE5C->norm.x = -lbl_8040AE5C->local_verts[idx].x;
        lbl_8040AE5C->norm.y = -lbl_8040AE5C->local_verts[idx].y;
        lbl_8040AE5C->norm.z = -dz;
        return 1;
    }
    return 0;
}

void fn_8005592C(void);
extern const f32 lbl_8019510C[];
extern const f32 lbl_80195110[];
extern const f32 lbl_80195114[];

s32 fn_80056A38(u8 *flags)
{
    terrainscan_s *motion;
    f32 scale;
    f32 threshold;
    s32 mode;

    fn_8005592C();
    motion = lbl_8040AE5C;
    mode = motion->type;
    switch (mode) {
        case 0:
            flags[0] = mode;
            lbl_8040AE5C->start.x += lbl_8040AE5C->delta.x;
            lbl_8040AE5C->start.y += lbl_8040AE5C->delta.y;
            lbl_8040AE5C->start.z += lbl_8040AE5C->delta.z;
            return 0;

        case 1:
        case 2:
        case 3:
        case 4:
            motion->best_t -= motion->fieldA0;
            if (motion->best_t < lbl_8019510C[0]) {
                motion->best_t = lbl_8019510C[0];
            }

            threshold = lbl_80195110[0];
            scale = lbl_8040AE5C->best_t;
            lbl_8040AE5C->start.x += lbl_8040AE5C->delta.x * scale;
            lbl_8040AE5C->start.y += lbl_8040AE5C->delta.y * scale;
            lbl_8040AE5C->start.z += lbl_8040AE5C->delta.z * scale;
            if (lbl_8040AE5C->scaledDirection.y < threshold) {
                flags[0] = 0;
            } else {
                flags[0] = 1;
                flags[1] = 1;
                lbl_8040AE5C->start.y += lbl_8040AE5C->norm.y * lbl_80195114[0];
            }
            return 0;

        case 17:
        case 18:
        case 19:
        case 20:
            return 1;
    }
    return 1;
}

extern void (*fn_80009948(char *file, s32 line))(char *, ...);
extern char lbl_80194C94[];
extern char lbl_80194D84[];
extern u8 *lbl_804083A4;
extern u8 *lbl_8040A5F0;

void fn_8005A338(u8 **cursor, u8 **limit)
{
    u8 *end = *limit;
    u8 *secondStart;
    u8 *thirdStart;
    u8 *regionEnd;
    u8 *fourthStart;
    u8 *previous;

    if (lbl_804083A0 == NULL) {
        lbl_804083A0 = *cursor;
    }
    previous = lbl_804083A4;
    secondStart = *cursor + 0xC800;
    *cursor = secondStart;
    if (previous == NULL) {
        lbl_804083A4 = secondStart;
    }
    previous = lbl_8040A5F0;
    thirdStart = secondStart + 0xC800;
    *cursor = thirdStart;
    if (previous == NULL) {
        lbl_8040A5F0 = thirdStart;
    }
    previous = (u8 *)lbl_8040A5B4;
    fourthStart = thirdStart + 0x2000;
    *cursor = fourthStart;
    if (previous == NULL) {
        lbl_8040A5B4 = (terrainwallpt_s *)fourthStart;
    }
    regionEnd = fourthStart + 0x600;
    *cursor = regionEnd;
    if (regionEnd > end) {
        fn_80009948(lbl_80194C94, 0x665)(lbl_80194D84);
    }
}

extern u8 lbl_802B1504[];
extern u8 lbl_802B1565[];
extern u8 lbl_802B1566[];
extern u8 lbl_802B1567[];
extern u8 *lbl_8040A594;
extern s32 lbl_8040A5A0;

void fn_8005592C(void)
{
    s32 mode = lbl_8040AE5C->type;
    terrainpoly_s *source;
    s32 index;
    u8 flag;

    switch (mode) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;

        case 17:
        case 18:
        case 19:
        case 20:
            break;

        case 0:
            return;

        default:
            return;
    }
    if (lbl_8040AE5C->unk6c == -1) {
        return;
    }

    source = lbl_8040AE5C->hit_poly;
    if (source != NULL) {
        flag = source->unk60;
        if (flag != 0) {
            lbl_802B1504[0x60] = flag;
        }
        flag = lbl_8040AE5C->hit_poly->unk61;
        if (flag != 0) {
            lbl_802B1565[0] = flag;
        }
        flag = lbl_8040AE5C->hit_poly->flags;
        if (flag != 0) {
            lbl_802B1566[0] = flag;
        }
        flag = lbl_8040AE5C->hit_poly->unk63;
        if (flag != 0) {
            lbl_802B1567[0] = flag;
        }
    }
    index = lbl_8040AE5C->unk6c;
    lbl_8040A594 = lbl_802B1504;
    lbl_8040A5A0 = index;
}

extern const f32 lbl_801950CC[];
extern u32 lbl_8040AE6C;

void fn_800559FC(void)
{
    terrainscan_s *motion;
    terrainvec_s *direction;
    f32 sinX;
    f32 cosX;
    f32 cosY;
    f32 sinY;
    f32 rotatedZ;
    f32 inverseLength;
    f32 x;
    f32 y;
    f32 z;
    f32 unit;

    fn_8005592C();
    switch ((s32)lbl_8040AE5C->type) {
        case 4:
        case 20:
            lbl_8040AE6C |= 4;
            /* fall through */
        case 2:
        case 3:
        case 18:
        case 19:
            motion = lbl_8040AE5C;
            direction = &motion->norm;
            sinX = NuSinApprox((s32)motion->rotationX);
            rotatedZ = direction->y * sinX
                     + direction->z * NuCosApprox((s32)lbl_8040AE5C->rotationX);
            cosX = NuCosApprox((s32)lbl_8040AE5C->rotationX);
            direction->y = direction->y * cosX
                         - direction->z * NuSinApprox((s32)lbl_8040AE5C->rotationX);
            cosY = NuCosApprox((s32)lbl_8040AE5C->rotationY);
            direction->z = rotatedZ * cosY
                         - motion->norm.x * NuSinApprox((s32)lbl_8040AE5C->rotationY);
            sinY = NuSinApprox((s32)lbl_8040AE5C->rotationY);
            motion->norm.x = rotatedZ * sinY
                                 + motion->norm.x * NuCosApprox((s32)lbl_8040AE5C->rotationY);

            if ((lbl_8040AE5C->type & 0x10) == 0) {
                f32 directionScale = lbl_8040AE5C->field58;
                lbl_8040AE5C->norm.x *= directionScale;
                lbl_8040AE5C->norm.y *= directionScale;
                lbl_8040AE5C->norm.z *= directionScale;
            }
            /* fall through */
        case 1:
        case 17:
            unit = lbl_801950CC[0];
            if (lbl_8040AE5C->unk5c == unit) {
                lbl_8040AE5C->scaledDirection.x = lbl_8040AE5C->norm.x;
                lbl_8040AE5C->scaledDirection.y =
                lbl_8040AE5C->norm.y;
                lbl_8040AE5C->scaledDirection.z = lbl_8040AE5C->norm.z;
                return;
            }
            y = lbl_8040AE5C->norm.y;
            x = lbl_8040AE5C->norm.x;
            z = lbl_8040AE5C->norm.z;
            inverseLength = unit / NuFsqrt(z * z + (x * x + y * y * lbl_8040AE5C->field68));
            lbl_8040AE5C->scaledDirection.x = lbl_8040AE5C->norm.x * inverseLength;
            lbl_8040AE5C->scaledDirection.y =
                lbl_8040AE5C->norm.y * lbl_8040AE5C->unk64 * inverseLength;
            lbl_8040AE5C->scaledDirection.z = lbl_8040AE5C->norm.z * inverseLength;
            return;
    }
}

typedef struct NUTERRAINPLANARADJUSTMENT_s {
    struct nuvec_s vector;
    f32 fieldC;
    f32 limit;
} TerrainPlanarAdjustment;

extern TerrainPlanarAdjustment *lbl_8040A5C0;

void fn_80058F04(const struct nuvec_s *axis, struct nuvec_s *offset)
{
    TerrainPlanarAdjustment *adjustment = lbl_8040A5C0;
    f32 vectorZ = adjustment->vector.z;
    f32 vectorX = adjustment->vector.x;
    f32 axisX = axis->x;
    f32 axisZ = axis->z;
    f32 limit = adjustment->limit;
    f32 along = vectorX * axisX + vectorZ * axisZ;
    f32 across = vectorX * axisZ - vectorZ * axisX;
    f32 lower;
    f32 acrossScale;
    f32 acrossLimit;

    if (along > limit) {
        along = limit;
    }
    lower = -limit;
    if (along < lower) {
        along = lower;
    }
    acrossScale = 0.2f;
    acrossLimit = limit * acrossScale;
    if (across > acrossLimit) {
        across = acrossLimit;
    }
    acrossLimit = lower * acrossScale;
    if (across < acrossLimit) {
        across = acrossLimit;
    }

    offset->x -= (along * axisX + across * axisZ) - vectorX;
    offset->z -= (along * axis->z - across * axis->x) - adjustment->vector.z;
    adjustment->vector.x = along * axis->x + across * axis->z;
    adjustment->vector.z = along * axis->z - across * axis->x;
}

s32 fn_8005A160(s32 index)
{
    s32 i;
    s32 remapIndex;

    if (index < 0 || index >= lbl_8040AE4C->indexedCount ||
        lbl_8040AE4C->indexedEntries[index].active == 0) {
        return 0;
    }

    lbl_8040AE4C->compactCount--;
    lbl_8040AE4C->remapCount--;
    lbl_8040AE4C->indexedEntries[
        lbl_8040AE4C->nodes[lbl_8040AE4C->compactCount].index].compactIndex =
        lbl_8040AE4C->indexedEntries[index].compactIndex;
    lbl_8040AE4C->nodes[lbl_8040AE4C->indexedEntries[index].compactIndex] =
        lbl_8040AE4C->nodes[lbl_8040AE4C->compactCount];
    lbl_8040AE4C->nodes[lbl_8040AE4C->compactCount].unk2c = -1;
    lbl_8040AE4C->indexedEntries[index].active = 0;

    for (i = 0, remapIndex = lbl_8040AE4C->remapStart;
         i < lbl_8040AE4C->remapLength;
         i++, remapIndex++) {
        if (lbl_8040AE4C->remap[remapIndex] == lbl_8040AE4C->compactCount) {
            lbl_8040AE4C->remap[remapIndex] = lbl_8040AE4C->remap[lbl_8040AE4C->remapCount];
            break;
        }
    }

    lbl_8040AE4C->remapLength--;
    for (i = 0; i < 64; i++) {
        if (lbl_8040AE4C->trackedEntries[i].index == index) {
            lbl_8040AE4C->trackedEntries[i].active = 0;
        }
    }
    return 1;
}
