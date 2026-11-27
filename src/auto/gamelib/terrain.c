#include "types.h"


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
extern void *lbl_8040AE5C;

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
    HVQM4AudioNode* next;
    HVQM4AudioNode* node;
    s32 interrupts;

    interrupts = OSDisableInterrupts();
    node = queue->freeHead;

    if (node != NULL) {
        next = node->nextFree;

        do {
            if (next == NULL) {
                queue->freeTail = next;
            }
        } while (0);
        queue->freeHead = next;
        node->nextFree = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

HVQM4AudioNode* HVQM4BufaGetSend(HVQM4AudioQueue* queue)
{
    HVQM4AudioNode* next;
    HVQM4AudioNode* node;
    s32 interrupts;

    interrupts = OSDisableInterrupts();
    node = queue->sendHead;

    if (node != NULL) {
        next = node->nextSend;

        do {
            if (next == NULL) {
                queue->sendTail = next;
            }
        } while (0);
        queue->sendHead = next;
        node->nextSend = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

HVQM4VideoNode* HVQM4BufvGetDisp(HVQM4VideoQueue* queue)
{
    HVQM4VideoNode* next;
    HVQM4VideoNode* node;
    s32 interrupts;

    interrupts = OSDisableInterrupts();
    node = queue->displayHead;

    if (node != NULL) {
        next = node->nextDisplay;

        do {
            if (next == NULL) {
                queue->displayTail = next;
            }
        } while (0);
        queue->displayHead = next;
        node->nextDisplay = NULL;
    }
    OSRestoreInterrupts(interrupts);
    return node;
}

static inline void unlinkFreeVideoNode(HVQM4VideoNode* node)
{
    node->prevFree->nextFree = node->nextFree;
    node->nextFree->prevFree = node->prevFree;
}

HVQM4VideoNode* HVQM4BufvGetFree(HVQM4VideoQueue* queue)
{
    HVQM4VideoNode* result = NULL;
    s32 interrupts = OSDisableInterrupts();
    HVQM4VideoNode* node = queue->freeHead;

    if (node != NULL) {
        do {
            if (node->busy == 0) {
                result = node;
                if (result == queue->freeHead) {
                    if (result->nextFree == result) {
                        queue->freeHead = NULL;
                    } else {
                        queue->freeHead = result->nextFree;
                        unlinkFreeVideoNode(result);
                    }
                } else {
                    unlinkFreeVideoNode(result);
                }
                node->prevFree = NULL;
                node->nextFree = NULL;
                break;
            }
            node = node->nextFree;
        } while (node != queue->freeHead);
    }
    OSRestoreInterrupts(interrupts);
    return result;
}
