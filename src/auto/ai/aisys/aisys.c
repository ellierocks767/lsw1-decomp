#include "game/ai.h"

extern s32 lbl_80408CC8;
extern s32 lbl_80408CCC;
extern s32 lbl_80408D08;
extern s32 lbl_80408D0C;
extern s32 lbl_80408D10;
extern s32 lbl_80408D14;
extern s32 lbl_80408D18;
extern s32 lbl_80408D1C;
extern s32 lbl_80408D20;
extern s32 lbl_80408D24;
extern s32 lbl_80408D38;
extern s32 lbl_80408D3C;
extern s32 lbl_80408D40;
extern s32 lbl_80408D44;
extern s32 lbl_80408D48;
extern s32 lbl_80408D4C;

void fn_80083A3C(s32 a)
{
    lbl_80408CCC = a;
}

void fn_80083A44(s32 a)
{
    lbl_80408CC8 = a;
}

void fn_8008F224(s32 a)
{
    lbl_80408D08 = a;
}

void fn_8008F22C(s32 a)
{
    lbl_80408D0C = a;
}

void fn_8008F234(s32 a)
{
    lbl_80408D10 = a;
}

void fn_8008F23C(s32 a)
{
    lbl_80408D14 = a;
}

void fn_8008F244(s32 a)
{
    lbl_80408D18 = a;
}

void fn_8008F24C(s32 a)
{
    lbl_80408D1C = a;
}

void fn_8008F254(s32 a)
{
    lbl_80408D20 = a;
}

void fn_8008F25C(s32 a)
{
    lbl_80408D24 = a;
}

void fn_8008F264(s32 a)
{
    lbl_80408D38 = a;
}

void fn_8008F26C(s32 a)
{
    lbl_80408D3C = a;
}

void fn_8008F274(s32 a)
{
    lbl_80408D40 = a;
}

void fn_8008F27C(s32 a)
{
    lbl_80408D44 = a;
}

void fn_8008F284(s32 a)
{
    lbl_80408D48 = a;
}

void fn_8008F28C(s32 a)
{
    lbl_80408D4C = a;
}

f32 Condition_Timer(s32 unused3, struct NUAISCRIPTPROCESS_s* a)
{
    return a->timer;
}

f32 Condition_GotLocator(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && p->locator) return 1.0f;
    return 0.0f;
}

f32 Condition_GotTriggerArea(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && p->triggerArea) return 1.0f;
    return 0.0f;
}

f32 Condition_GotOpponent(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && p->opponent) return 1.0f;
    return 0.0f;
}

f32 Condition_OnPath(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && (p->pathFlags & 0x8000)) return 1.0f;
    return 0.0f;
}

f32 Condition_PathBlocked(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && (p->movementFlags & 0x100)) return 1.0f;
    return 0.0f;
}

f32 Condition_TimeOffPath(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (!p) return 0.0f;
    /* The redundant guard preserves retail null-path block placement. */
    if (p) return p->timeOffPath;
    return p->timeOffPath;
}

f32 Condition_OpponentRange(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && p->opponent) return p->opponentRange;
    return 3.402823466e+38f;
}

f32 Condition_NearestOpponentRange(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    if (p && p->nearestOpponent) return p->nearestOpponentRange;
    return 3.402823466e+38f;
}

f32 Condition_StuckTime(void* sys, void* proc, struct NUAIPACKET_s* p)
{
    struct NUAPIOBJECT_s* owner;
    if (p && (owner = p->owner)) return owner->stuckTime;
    return 0.0f;
}

s32 Action_ResetTimer(void* sys, struct NUAISCRIPTPROCESS_s* proc,
    struct NUAIPACKET_s* packet, void* params, s32 count, s32 start)
{
    if (start) proc->timer = 0.0f;
    return 1;
}

extern s32 NuStrICmp(char*, char*);
extern char lbl_8019BEA0[];

struct ai_action_owner_s {
    u8 pad0[0x208];
    u32 flags208;
    u32 flags20c;
};

struct ai_action_packet_s {
    u8 pad0[0x50];
    struct ai_action_owner_s* owner;
    u8 pad54[0x14c];
    u32 flags1a0;
};

s32 Action_IgnoreWallSplines(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && firstTime != 0) {
        packet->flags1a0 |= 0x01000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->flags1a0 &= ~0x01000000;
            }
        }
    }
    return 1;
}

s32 Action_CheckWallSplines(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && firstTime != 0) {
        packet->flags1a0 |= 0x00800000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->flags1a0 &= ~0x00800000;
            }
        }
    }
    return 1;
}

s32 Action_RequiresLOS(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && firstTime != 0) {
        packet->flags1a0 |= 0x00002000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->flags1a0 &= ~0x00002000;
            }
        }
    }
    return 1;
}

s32 Action_NoTerrain(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x04000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x04000000;
            }
        }
    }
    return 1;
}

s32 Action_NoLosCheck(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x00200000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x00200000;
            }
        }
    }
    return 1;
}

s32 Action_FlatTerrain(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x08000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x08000000;
            }
        }
    }
    return 1;
}

s32 Action_ShadowTerrain(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x10000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x10000000;
            }
        }
    }
    return 1;
}

s32 Action_DontUseShadowTerrain(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x02000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x02000000;
            }
        }
    }
    return 1;
}

s32 Action_CanSeeBehind(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x00100000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x00100000;
            }
        }
    }
    return 1;
}

s32 Action_SetFullPathSearch(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c &= ~0x00002000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c |= 0x00002000;
            }
        }
    }
    return 1;
}

s32 Action_NoShadows(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && firstTime != 0 && packet->owner != 0) {
        packet->owner->flags208 |= 0x00002000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags208 &= ~0x00002000;
            }
        }
    }
    return 1;
}

s32 Action_DontPush(void* sys, void* process, struct ai_action_packet_s* packet,
                           char** params, s32 count, s32 firstTime, f32 time)
{
    s32 index;

    if (packet != 0 && packet->owner != 0 && firstTime != 0) {
        packet->owner->flags20c |= 0x40000000;
        for (index = 0; index < count; index++) {
            if (NuStrICmp(params[index], lbl_8019BEA0) == 0) {
                packet->owner->flags20c &= ~0x40000000;
            }
        }
    }
    return 1;
}

extern u64 __ashldi3();
extern f32 lbl_8019C59C[];
extern f32 lbl_8019C5A0[];

f32 Condition_InTriggerArea(void* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* owner;
    u8* area;

    if (packet != 0 && (owner = *(u8**)(packet + 0x50)) != 0) {
        if (inputArea == 0) {
            area = *(u8**)(packet + 0xf8);
        } else {
            area = inputArea;
        }
        if (area != 0) {
            if ((*(u64*)(area + 0x30) & __ashldi3(0, 1, owner[0x291])) != 0) {
                return lbl_8019C59C[0];
            }
        }
    }
    return lbl_8019C5A0[0];
}

extern f32 lbl_8019C5F8[];
extern f32 lbl_8019C5FC[];
f32 Condition_OpponentInTriggerArea(void* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* owner;
    u8* area;

    if (packet != 0 && (owner = *(u8**)(packet + 0x64)) != 0 && *(u8**)(packet + 0x50) != 0) {
        if (inputArea == 0) {
            area = *(u8**)(packet + 0xf8);
        } else {
            area = inputArea;
        }
        if (area != 0) {
            if ((*(u64*)(area + 0x30) & __ashldi3(0, 1, owner[0x291])) != 0) {
                return lbl_8019C5F8[0];
            }
        }
    }
    return lbl_8019C5FC[0];
}

extern f32 lbl_8019C5D0[];
extern f32 lbl_8019C5D4[];

f32 Condition_PlayerInTriggerArea(u8* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* area = 0;

    if (sys != 0 && *(u8**)(sys + 0x1380) != 0) {
        if (inputArea != 0) {
            area = inputArea;
        } else if (packet != 0) {
            area = *(u8**)(packet + 0xf8);
        }
        if (area != 0) {
            if ((*(u64*)(area + 0x30) & __ashldi3(0, 1, (*(u8**)(sys + 0x1380))[0x291])) != 0) {
                return lbl_8019C5D0[0];
            }
        }
    }
    return lbl_8019C5D4[0];
}

extern f32 fn_8000C038(void);
extern void NuFParPopCom(void*);
f32 Condition_Random(void)
{
    return fn_8000C038();
}
void fn_80083A4C(void* parser)
{
    NuFParPopCom(parser);
}

extern f32 lbl_8019C594[];
extern f32 lbl_8019C598[];
extern void* AIPathFindLocator(void*, char*);
extern void* AISysFindArea(void*, char*);
extern void* memset(void*, ...);

f32 Condition_CurrentLocatorIs(void* sys, void* process, struct NUAIPACKET_s* packet, char* params, void* locator)
{
    if (locator && packet && packet->locator == locator)
        return lbl_8019C594[0];
    return lbl_8019C598[0];
}

void fn_8008F1F0(void* packet)
{
    if (packet)
        memset(packet, 0, 0x134);
}

void* Condition_CurrentLocatorIsInit(void* sys, char* arg)
{
    if (arg)
        return AIPathFindLocator(sys, arg);
    return 0;
}

void* Condition_OpponentToLocatorInit(void* sys, char* arg)
{
    if (arg)
        return AIPathFindLocator(sys, arg);
    return 0;
}

void* Condition_PlayerToLocatorInit(void* sys, char* arg)
{
    if (arg)
        return AIPathFindLocator(sys, arg);
    return 0;
}

void* Condition_LocatorRangeInit(void* sys, char* arg)
{
    if (arg)
        return AIPathFindLocator(sys, arg);
    return 0;
}

void* Condition_InTriggerAreaInit(void* sys, char* arg)
{
    if (arg)
        return AISysFindArea(sys, arg);
    return 0;
}

void* Condition_PlayerInTriggerAreaInit(void* sys, char* arg)
{
    if (arg)
        return AISysFindArea(sys, arg);
    return 0;
}

void* Condition_BaddyInTriggerAreaInit(void* sys, char* arg)
{
    if (arg)
        return AISysFindArea(sys, arg);
    return 0;
}

void* Condition_GoodyInTriggerAreaInit(void* sys, char* arg)
{
    if (arg)
        return AISysFindArea(sys, arg);
    return 0;
}

void* Condition_OpponentInTriggerAreaInit(void* sys, char* arg)
{
    if (arg)
        return AISysFindArea(sys, arg);
    return 0;
}

extern f32 lbl_8019C608[], lbl_8019C60C[], lbl_8019C670[];
extern f32 lbl_8019C5E8[], lbl_8019C5EC[], lbl_8019C5F0[], lbl_8019C5F4[];
extern void* (*lbl_80408DA4)(void*, char*);
extern void* AIPathFindNode(void*, void*, char*);

f32 Condition_OpponentIsAThreat(void* sys, void* process, struct NUAIPACKET_s* packet)
{
    if (packet && packet->opponent && (packet->movementFlags & 0x100000))
        return lbl_8019C608[0];
    return lbl_8019C60C[0];
}

void fn_8008F090(u8* p)
{
    if (p[0x49] & 1)
        memset(p, 0, 0x4c);
}

void* Condition_IAmInit(void* sys, char* arg)
{
    if (arg && lbl_80408DA4)
        return lbl_80408DA4(sys, arg);
    return 0;
}

f32 Condition_BaddyInTriggerArea(void* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* area = 0;
    if (inputArea) area = inputArea;
    else if (packet) area = *(u8**)(packet + 0xf8);
    if (area && (area[0x2a] & 4)) return lbl_8019C5E8[0];
    return lbl_8019C5EC[0];
}

f32 Condition_GoodyInTriggerArea(void* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* area = 0;
    if (inputArea) area = inputArea;
    else if (packet) area = *(u8**)(packet + 0xf8);
    if (area && (area[0x2a] & 2)) return lbl_8019C5F0[0];
    return lbl_8019C5F4[0];
}

void* Condition_InLevelNodeInit(u8* sys, char* arg)
{
    u8* level;
    if (sys && (level = *(u8**)(sys + 0xc)) && *level)
        return AIPathFindNode(sys, *(void**)(level + 8), arg);
    return 0;
}

void* Condition_PlayerInLevelNodeInit(u8* sys, char* arg)
{
    u8* level;
    if (sys && (level = *(u8**)(sys + 0xc)) && *level)
        return AIPathFindNode(sys, *(void**)(level + 8), arg);
    return 0;
}

void* fn_80084058(u8* sys, char* arg)
{
    u8* level;
    if (sys && (level = *(u8**)(sys + 0xc)) && *level)
        return AIPathFindNode(sys, *(void**)(level + 8), arg);
    return 0;
}

extern f32 lbl_8019C650[], lbl_8019C630[], lbl_8019C634[], lbl_8019C638[];
extern f32 lbl_8019C610[], lbl_8019C614[];

f32 Condition_OpponentBelow(void* sys, void* process, u8* packet)
{
    u8* opponent;
    if (packet && (opponent = *(u8**)(packet + 0x64))) {
        u8* owner = *(u8**)(packet + 0x50);
        if (*(f32*)(opponent + 0x70) < *(f32*)(owner + 0x70) - lbl_8019C630[0])
            return lbl_8019C634[0];
    }
    return lbl_8019C638[0];
}

f32 Condition_OpponentOnSamePath(void* sys, void* process, u8* packet)
{
    u8* opponent;
    u8* otherPacket;
    void* path;
    if (packet && (opponent = *(u8**)(packet + 0x64)) && (path = *(void**)(packet + 0x10c)) &&
        (otherPacket = *(u8**)(opponent + 4)) && path == *(void**)(otherPacket + 0x10c))
        return lbl_8019C610[0];
    return lbl_8019C614[0];
}


extern f32 NuVecDist(void*, void*, void*);
extern f32 NuVecXZDist(void*, void*, void*);
extern f32 lbl_8019C5C4[], lbl_8019C5A4[], lbl_8019C578[], lbl_8019C57C[], lbl_8019C648[], lbl_8019C64C[];

f32 Condition_NodeRange(void* sys, void* process, u8* packet, char* params, u8* node)
{
    u8* owner;
    f32 out[3], result;
    if (packet && (owner = *(u8**)(packet + 0x50)) && node)
        result = NuVecDist(node + 4, owner + 0x6c, out);
    else result = lbl_8019C5C4[0];
    return result;
}

f32 Condition_PlayerRange(u8* sys, void* process, u8* packet)
{
    u8* owner;
    u8* player;
    f32 out[3], result;
    if (packet && (owner = *(u8**)(packet + 0x50)) && sys && (player = *(u8**)(sys + 0x1380)))
        result = NuVecDist(player + 0x6c, owner + 0x6c, out);
    else result = lbl_8019C5A4[0];
    return result;
}


extern f32 lbl_8019C63C[], lbl_8019C640[], lbl_8019C644[];
f32 Condition_OriginRange(u8* sys, void* process, u8* packet)
{
    f32 out[3], result;
    if (packet && *(void**)(packet + 0x50) && packet[0xa6] != 0xff && sys)
        result = NuVecDist(packet + 0x100, *(u8**)(sys + 0x14) + packet[0xa6] * 0xa8 + 0x30, out);
    else result = lbl_8019C63C[0];
    return result;
}
f32 Condition_OpponentToOrigin(u8* sys, void* process, u8* packet)
{
    u8* opponent;
    f32 out[3], result;
    if (sys && packet && (opponent = *(u8**)(packet + 0x64)) && packet[0xa6] != 0xff)
        result = NuVecDist(opponent + 0x6c, *(u8**)(sys + 0x14) + packet[0xa6] * 0xa8 + 0x30, out);
    else result = lbl_8019C640[0];
    return result;
}
f32 Condition_PlayerToOrigin(u8* sys, void* process, u8* packet)
{
    u8* player;
    f32 out[3], result;
    if (sys && packet && (player = *(u8**)(sys + 0x1380)) && packet[0xa6] != 0xff)
        result = NuVecDist(player + 0x6c, *(u8**)(sys + 0x14) + packet[0xa6] * 0xa8 + 0x30, out);
    else result = lbl_8019C644[0];
    return result;
}

extern void* fn_800076C4(void*);
extern void* fn_800076CC(void*, void*);
extern f32 lbl_8019C674[], lbl_8019C678[];f32 Condition_IAm(void* sys, void* process, u8* packet, char* name, void* actor)
{
    u8* owner;
    u8* model;
    f32 result;
    if (packet && (owner = *(u8**)(packet + 0x50)) &&
        (owner == actor || ((model = *(u8**)(owner + 0x64)) && *(char**)(model + 0xc) && NuStrICmp(*(char**)(model + 0xc), name) == 0)))
        result = lbl_8019C674[0];
    else result = lbl_8019C678[0];
    return result;
}

extern void* fn_8008386C(char*, u8*);
s32 fn_8008F35C(u8* process, u32 priority, u32 id, char* name, f32 value)
{
    void* script;
    if (priority >= process[0x44] && (script = fn_8008386C(name, *(void**)(process + 4)))) {
        process[0x44] = priority;
        process[0x45] = id;
        *(f32*)(process + 0x48) = value;
        *(void**)(process + 0x4c) = script;
        return 1;
    }
    return 0;
}

extern char lbl_8019BFCC[];
extern char* NuStrIStr(char*, char*);
extern void fn_8008F3D4(void*, char*);
s32 Action_ClearInterrupt(void* sys, void* process, void* packet, char** args, s32 count, void* active)
{
    char* name = 0;
    s32 i;
    if (active && process) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(args[i], lbl_8019BFCC);
            if (found) name = found + 6;
        }
        if (name) fn_8008F3D4(process, name);
    }
    return 1;
}

struct ai_level_node { u8 bytes[0x58]; };
extern f32 lbl_8019C5AC[], lbl_8019C5B0[], lbl_8019C5B4[], lbl_8019C5B8[];
f32 Condition_InLevelNode(u8* sys, void* process, u8* packet, char* params, struct ai_level_node* node)
{
    if (packet && node && sys) {
        u8* level = *(u8**)(sys + 0xc);
        u8* data = *(u8**)(level + 8);
        if (*(s16*)(packet + 0xa0) == node - *(struct ai_level_node**)(data + 0x78))
            return lbl_8019C5AC[0];
    }
    return lbl_8019C5B0[0];
}
f32 Condition_PlayerInLevelNode(u8* sys, void* process, void* packet, char* params, struct ai_level_node* node)
{
    u8* player;
    if (sys && (player = *(u8**)(sys + 0x1380)) && node) {
        u8* level = *(u8**)(sys + 0xc);
        u8* data = *(u8**)(level + 8);
        u8* ai = *(u8**)(player + 4);
        if (*(s16*)(ai + 0xa0) == node - *(struct ai_level_node**)(data + 0x78))
            return lbl_8019C5B4[0];
    }
    return lbl_8019C5B8[0];
}

void fn_800838EC(u8* process, u8* script)
{
    void* state;
    if (process && script) {
        *(u8**)(process + 8) = script;
        *(void**)(process + 0xc) = 0;
        *(void**)(process + 0x10) = 0;
        state = fn_800076C4(script + 0x10);
        if (state) {
            *(void**)(process + 0xc) = state;
            *(u32*)(process + 0x3c) |= 0x80000000;
        } else *(void**)(process + 0xc) = state;
    }
}


extern f32 lbl_8019C5D8[], lbl_8019C5DC[];
f32 Condition_Player2InTriggerArea(u8* sys, void* process, u8* packet, char* params, u8* inputArea)
{
    u8* area = 0;

    if (sys != 0 && *(u8**)(sys + 0x1384) != 0) {
        if (inputArea != 0) {
            area = inputArea;
        } else if (packet != 0) {
            area = *(u8**)(packet + 0xf8);
        }
        if (area != 0) {
            if ((*(u64*)(area + 0x30) & __ashldi3(0, 1, (*(u8**)(sys + 0x1384))[0x291])) != 0) {
                return lbl_8019C5D8[0];
            }
        }
    }
    return lbl_8019C5DC[0];
}

extern f32 lbl_8019C5BC[], lbl_8019C5C0[];
f32 Condition_EitherPlayerInLevelNode(u8* sys, void* process, void* packet, char* params, struct ai_level_node* node)
{
    u8* player;
    if (sys && node) {
        player = *(u8**)(sys + 0x1380);
        if (player && *(s16*)(*(u8**)(player + 4) + 0xa0) == node - *(struct ai_level_node**)(*(u8**)(*(u8**)(sys + 0xc) + 8) + 0x78))
            return lbl_8019C5BC[0];
        player = *(u8**)(sys + 0x1384);
        if (player && *(s16*)(*(u8**)(player + 4) + 0xa0) == node - *(struct ai_level_node**)(*(u8**)(*(u8**)(sys + 0xc) + 8) + 0x78))
            return lbl_8019C5BC[0];
    }
    return lbl_8019C5C0[0];
}
extern f32 fn_8000CD08(void*, void*, void*);
extern f32 NuFsqrt(f32);
extern f32 lbl_8019C5A8[];
f32 Condition_NearestPlayerRange(u8* sys, void* process, u8* packet)
{
    f32 distance = lbl_8019C5A8[0];
    f32 out[3];
    if (packet && *(u8**)(packet + 0x50) && sys) {
        u8* player = *(u8**)(sys + 0x1380);
        if (player)
            distance = fn_8000CD08(player + 0x6c, *(u8**)(packet + 0x50) + 0x6c, out);
        player = *(u8**)(sys + 0x1384);
        if (player) {
            f32 other = fn_8000CD08(player + 0x6c, *(u8**)(packet + 0x50) + 0x6c, out);
            if (other < distance) distance = other;
        }
        if (distance != lbl_8019C5A8[0]) distance = NuFsqrt(distance);
    }
    return distance;
}
extern f32 lbl_8019C5E0[], lbl_8019C5E4[];extern void (*fn_80009948(char*, int))(char*, ...);
extern char lbl_8019C6DC[], str_AISysBufferAlloc_LevelBufferTooSmall[], str_AISysBufferAlloc_NoBuffer[];
void* fn_8008F0C8(u32* current, u32* end, u32 size)
{
    u32 result = 0;
    if (current && end) {
        if (*current + size < *end) {
            result = (*current + 15) & ~15;
            *current = result + size;
        } else fn_80009948(lbl_8019C6DC, 0x3bd)(str_AISysBufferAlloc_LevelBufferTooSmall);
    } else fn_80009948(lbl_8019C6DC, 0x3c1)(str_AISysBufferAlloc_NoBuffer);
    return (void*)result;
}
s32 AISysSetLevelPath(u8* sys, char* name)
{
    char* selected = 0;
    if (sys && *(u8**)(sys + 0xc)) {
        if (name) {
            s32 i;
            for (i = 0; i < **(u8**)(sys + 0xc); i++) {
                u8* level = *(u8**)(sys + 0xc);
                char** names = *(char***)(level + 4);
                if (NuStrICmp(names[i], name) == 0) {
                    selected = (*(char***)(*(u8**)(sys + 0xc) + 4))[i];
                    break;
                }
            }
        } else selected = **(char****)(*(u8**)(sys + 0xc) + 4);
        if (selected && selected != *(char**)(*(u8**)(sys + 0xc) + 8)) {
            *(char**)(*(u8**)(sys + 0xc) + 8) = selected;
            return 1;
        }
    }
    return 0;
}
extern char lbl_8019BF88[], lbl_8019BF90[], lbl_8019BFB4[];
extern u8* fn_8008A6D4(void*, void*, char*, char*, s32*);
s32 Action_PathConnectionObstacle(void* sys, void* process, void* packet, char** args, s32 count, void* active)
{
    s32 enabled = 0;
    s32 unused = 0;
    char* from = 0;
    char* to = 0;
    s32 i;
    if (sys && active) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(args[i], lbl_8019BF88);
            if (found) from = found + 5;
            else if ((found = NuStrIStr(args[i], lbl_8019BF90))) to = found + 3;
            else if (!NuStrICmp(args[i], lbl_8019BFB4)) enabled = 1;
        }
        if (from && to) {
            u8* connection = fn_8008A6D4(sys, 0, from, to, &unused);
            if (connection && (*(u32*)(connection + 4) & 0x20000000)) connection[0x21] = enabled;
        }
    }
    return 1;
}

void* fn_8008386C(char* name, u8* script)
{
    u8* entry = fn_800076C4(script + 0x10);
    if (!name) return 0;
    for (; entry; entry = fn_800076CC(script + 0x10, entry))
        if (!NuStrICmp(name, *(char**)(entry + 0x18))) return entry;
    return 0;
}
f32 Condition_InterruptID(void* sys, u8* process)
{
    if (process) return (f32)process[0x45];
    return lbl_8019C670[0];
}

f32 Condition_OpponentToLocatorY(void* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* opponent;
    u8* locator;
    if (packet && (opponent = *(u8**)(packet + 0x64))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) return *(f32*)(opponent + 0x70) - *(f32*)(locator + 0x14);
    }
    return lbl_8019C650[0];
}

f32 Condition_LocatorRange(void* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* object;
    u8* locator;
    f32 out[3], result;
    if (packet && (object = *(u8**)(packet + 0x50))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) result = NuVecDist(packet + 0x100, locator + 0x10, out);
        else result = lbl_8019C578[0];
    } else result = lbl_8019C578[0];
    return result;
}

f32 Condition_LocatorRangeXZ(void* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* object;
    u8* locator;
    f32 out[3], result;
    if (packet && (object = *(u8**)(packet + 0x50))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) result = NuVecXZDist(packet + 0x100, locator + 0x10, out);
        else result = lbl_8019C57C[0];
    } else result = lbl_8019C57C[0];
    return result;
}

f32 Condition_OpponentToLocator(void* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* object;
    u8* locator;
    f32 out[3], result;
    if (packet && (object = *(u8**)(packet + 0x64))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) result = NuVecDist(object + 0x6c, locator + 0x10, out);
        else result = lbl_8019C648[0];
    } else result = lbl_8019C648[0];
    return result;
}

f32 Condition_OpponentToLocatorXZ(void* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* object;
    u8* locator;
    f32 out[3], result;
    if (packet && (object = *(u8**)(packet + 0x64))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) result = NuVecXZDist(object + 0x6c, locator + 0x10, out);
        else result = lbl_8019C64C[0];
    } else result = lbl_8019C64C[0];
    return result;
}

extern f32 lbl_8019C658[];
f32 Condition_NearestPlayerToLocator(u8* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    f32 distance = lbl_8019C658[0];
    f32 out[3];
    if (packet && sys) {
        u8* locator;
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) {
            u8* player = *(u8**)(sys + 0x1380);
            if (player) distance = fn_8000CD08(player + 0x6c, locator + 0x10, out);
            player = *(u8**)(sys + 0x1384);
            if (player) {
                f32 other = fn_8000CD08(player + 0x6c, locator + 0x10, out);
                if (other < distance) distance = other;
            }
        }
        if (distance != lbl_8019C658[0]) distance = NuFsqrt(distance);
    }
    return distance;
}
extern f32 lbl_8019C654[];
f32 Condition_PlayerToLocator(u8* sys, void* process, u8* packet, char* params, u8* inputLocator)
{
    u8* player;
    u8* locator;
    f32 out[3], result;
    if (packet && sys && (player = *(u8**)(sys + 0x1380))) {
        if (inputLocator) locator = inputLocator;
        else locator = *(u8**)(packet + 0xfc);
        if (locator) result = NuVecDist(player + 0x6c, locator + 0x10, out);
        else result = lbl_8019C654[0];
    } else result = lbl_8019C654[0];
    return result;
}

void fn_8008F968(void *);

void *fn_8008EE48(s32 *arg0, u32 *arg1, s32 arg2) {
    s32 temp_r10;
    s32 temp_r11;
    s32 temp_r11_2;
    s32 var_r28;
    s32 var_r29;

    var_r29 = 0;
    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_r11 = *arg0;
        if ((u32) (temp_r11 + 0x18) < (u32) *arg1) {
            var_r29 = (temp_r11 + 0xF) & 0xFFFFFFF0;
            *arg0 = var_r29 + 0x18;
        } else {
            fn_80009948(lbl_8019C6DC, 0x3BD)(str_AISysBufferAlloc_LevelBufferTooSmall);
        }
    } else {
        fn_80009948(lbl_8019C6DC, 0x3C1)(str_AISysBufferAlloc_NoBuffer);
    }
    if (var_r29 != 0) {
        var_r28 = 0;
        memset((void *) var_r29, 0, 0x18);
        temp_r10 = arg2 * 0x2C;
        if ((arg0 != NULL) && (arg1 != NULL)) {
            temp_r11_2 = *arg0;
            if ((u32) (temp_r11_2 + temp_r10) < (u32) *arg1) {
                var_r28 = (temp_r11_2 + 0xF) & 0xFFFFFFF0;
                *arg0 = var_r28 + temp_r10;
            } else {
                fn_80009948(lbl_8019C6DC, 0x3BD)(str_AISysBufferAlloc_LevelBufferTooSmall);
            }
        } else {
            fn_80009948(lbl_8019C6DC, 0x3C1)(str_AISysBufferAlloc_NoBuffer);
        }
        (*(s32 *)((s8 *)(var_r29) + (4))) = var_r28;
        if (var_r28 != 0) {
            (*(s32 *)((s8 *)(var_r29) + (0))) = arg2;
            fn_8008F968((void *) var_r29);
        }
    }
    return (void *) var_r29;
}

struct aiscriptparam_s {
    char *name;
    f32 value;
};
struct aiscript_s {
    u8 pad0[0x18];
    struct aiscriptparam_s params[4];
};
struct aiparamproc_s {
    u8 pad0[4];
    struct aiscript_s *script;
    u8 pad8[0x38];
    f32 actionTimer;
};

extern s32 NuAToI(char *s);
extern s32 strcasecmp(const char *a, const char *b);
extern f32 fn_800077E8(char *s);
extern char str_ScriptToken_ParamLower[];
extern f32 lbl_8019C574[];

f32 AIParamToFloat(struct aiparamproc_s *processor, char *param) {
    char *cursor;
    u32 n;
    s32 i;

    if (param != NULL) {
        if (processor != NULL) {
            cursor = NuStrIStr(param, str_ScriptToken_ParamLower);
            if (cursor != NULL) {
                i = NuAToI(cursor);
                if ((u32)i < 4) return processor->script->params[i].value;
            } else if (processor->script != NULL) {
                for (i = 0; i < 4; i++) {
                    if (processor->script->params[i].name != NULL &&
                        strcasecmp(processor->script->params[i].name, param) == 0) {
                        return processor->script->params[i].value;
                    }
                }
            }
        }
        return fn_800077E8(param);
    }
    return lbl_8019C574[0];
}
static inline f32 aiParamFloat(struct aiparamproc_s *processor, char *param)
{
    char *cursor;
    s32 i;
    if (param != NULL) {
        if (processor != NULL) {
            cursor = NuStrIStr(param, str_ScriptToken_ParamLower);
            if (cursor != NULL) {
                i = NuAToI(cursor);
                if ((u32)i < 4) return processor->script->params[i].value;
            } else if (processor->script != NULL) {
                for (i = 0; i < 4; i++) {
                    if (processor->script->params[i].name != NULL &&
                        strcasecmp(processor->script->params[i].name, param) == 0) {
                        return processor->script->params[i].value;
                    }
                }
            }
        }
        return fn_800077E8(param);
    }
    return 0.0f;
}
struct aimovevec_s { f32 x, y, z; };
struct aimoveview_s {
    u8 pad0[0x9c];
    f32 field9c;
    u8 padA0[0x6c];
    struct aimovevec_s field10c;
    u8 pad118[0xc];
    struct aimovevec_s field124;
};

extern s32 (*lbl_80408D2C)(char*, void*);
extern f32 lbl_8019BE30[];
extern void AIMoveInstruction(void*,void*,f32,void*,s32,f32);
s32 Action_FollowOpponent(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(packet + 0x64);
    if (target && *(u8**)(target + 4)) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 1, *(f32*)(packet + 0x134));
    }
    return 0;
}

struct aicreatureview_s {
    u8 pad0[0x98];
    f32 field98;
    f32 field9c;
    f32 fielda0;
    f32 fielda4;
};

s32 Action_FollowPlayer(u8* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet || !sys || !*(void**)(sys + 0x1380)) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(sys + 0x1380);
    if (target) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 1, *(f32*)(packet + 0x134));
    }
    return 0;
}

extern f32 lbl_8019BE7C[];
s32 Action_RetreatFromOpponent(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        *(f32*)(packet + 0x134) = lbl_8019BE7C[0];
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(packet + 0x64);
    if (target && *(u8**)(target + 4)) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 2, *(f32*)(packet + 0x134));
    }
    return 0;
}

extern f32 lbl_8019BE84[];
s32 Action_RetreatFromNearestOpponent(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        *(f32*)(packet + 0x134) = lbl_8019BE84[0];
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(packet + 0x54);
    if (target) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 2, *(f32*)(packet + 0x134));
    }
    return 0;
}

extern char str_ScriptParam_Face[];
s32 Action_MoveAwayFromOpponent(u8* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            if (!NuStrICmp(params[i], str_ScriptParam_Face)) packet[0xb2] = 1;
            else *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(packet + 0x64);
    if (target && *(u8**)(target + 4)) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 2, *(f32*)(packet + 0x134));
        if (packet[0xb2]) *(void**)(packet + 0x19c) = *(u8**)(packet + 0x64) + 0x6c;
    }
    return 0;
}

s32 Action_MoveAwayFromPlayer(u8* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            if (!NuStrICmp(params[i], str_ScriptParam_Face)) packet[0xb2] = 1;
            else *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(sys + 0x1380);
    if (target) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 2, *(f32*)(packet + 0x134));
    }
    return 0;
}

struct aisysview_s {
    u8 pad0[0x14];
    struct aicreatureview_s *creatures;
};

struct aicircleflags_s {
    u32 pad0 : 9;
    u32 direction : 1;
    u32 pad10 : 22;
};

extern char str_ScriptDir_AntiClockwise_2[], str_ScriptDir_Clockwise_2[], str_ScriptDir_Reverse_2[];
extern char str_ScriptParam_Facing[];
s32 Action_CircleOpponent(u8* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            if (!NuStrICmp(params[i], str_ScriptDir_AntiClockwise_2)) *(u32*)(packet + 0x1a0) &= ~0x400000;
            else if (!NuStrICmp(params[i], str_ScriptDir_Clockwise_2)) *(u32*)(packet + 0x1a0) |= 0x400000;
            else if (!NuStrICmp(params[i], str_ScriptDir_Reverse_2)) {
                ((struct aicircleflags_s*)(packet + 0x1a0))->direction = !((struct aicircleflags_s*)(packet + 0x1a0))->direction;
            }
            else if (!NuStrICmp(params[i], str_ScriptParam_Facing)) packet[0xb2] = 1;
            else *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(packet + 0x64);
    if (target && *(u8**)(target + 4)) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 3, *(f32*)(packet + 0x134));
        if (packet[0xb2]) *(void**)(packet + 0x19c) = *(u8**)(packet + 0x64) + 0x6c;
    }
    return 0;
}

s32 Action_CirclePlayer(u8* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s32 i;
    u8* target;
    if (!packet || !sys || !*(void**)(sys + 0x1380)) return 1;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            if (lbl_80408D2C && lbl_80408D2C(params[i], packet + 0xb0)) continue;
            if (!NuStrICmp(params[i], str_ScriptDir_AntiClockwise_2)) *(u32*)(packet + 0x1a0) &= ~0x400000;
            else if (!NuStrICmp(params[i], str_ScriptDir_Clockwise_2)) *(u32*)(packet + 0x1a0) |= 0x400000;
            else if (!NuStrICmp(params[i], str_ScriptDir_Reverse_2)) {
                ((struct aicircleflags_s*)(packet + 0x1a0))->direction = !((struct aicircleflags_s*)(packet + 0x1a0))->direction;
            }
            else if (!NuStrICmp(params[i], str_ScriptParam_Facing)) packet[0xb2] = 1;
            else *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
        }
    }
    target = *(u8**)(sys + 0x1380);
    if (target) {
        struct aimoveview_s* ai = *(struct aimoveview_s**)(target + 4);
        AIMoveInstruction(packet, &ai->field124, ai->field9c, &ai->field10c, 3, *(f32*)(packet + 0x134));
        if (packet[0xb2]) *(void**)(packet + 0x19c) = *(u8**)(packet + 0x64) + 0x6c;
    }
    return 0;
}

extern char str_ScriptToken_Default[];
s32 Action_SetViewDistance(struct aisysview_s* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    u8* object;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110) && firstTime) {
        if (packet[0xa6] != 0xff) {
            struct aicreatureview_s* creature = sys->creatures + packet[0xa6];
            *(f32*)(object + 0x234) = creature->field98;
        } else if (lbl_80408D3C) {
            *(f32*)(*(u8**)(packet + 0x50) + 0x234) = ((f32 (*)(s32))lbl_80408D3C)(**(s16**)(object + 0x60));
        } else {
            *(f32*)(object + 0x234) = 1.0f;
        }
        if (count && NuStrICmp(params[0], str_ScriptToken_Default))
            *(f32*)(*(u8**)(packet + 0x50) + 0x234) = aiParamFloat(processor, params[0]);
    }
    return 1;
}

s32 Action_SetMinViewHeight(struct aisysview_s* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    u8* object;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110) && firstTime) {
        if (packet[0xa6] != 0xff) {
            struct aicreatureview_s* creature = sys->creatures + packet[0xa6];
            *(f32*)(object + 0x240) = creature->fielda4;
        } else if (lbl_80408D48) {
            *(f32*)(*(u8**)(packet + 0x50) + 0x240) = ((f32 (*)(s32))lbl_80408D48)(**(s16**)(object + 0x60));
        } else {
            *(f32*)(object + 0x240) = 1.0f;
        }
        if (count && NuStrICmp(params[0], str_ScriptToken_Default))
            *(f32*)(*(u8**)(packet + 0x50) + 0x240) = aiParamFloat(processor, params[0]);
    }
    return 1;
}

s32 Action_SetMaxViewHeight(struct aisysview_s* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    u8* object;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110) && firstTime) {
        if (packet[0xa6] != 0xff) {
            struct aicreatureview_s* creature = sys->creatures + packet[0xa6];
            *(f32*)(object + 0x23c) = creature->fielda0;
        } else if (lbl_80408D44) {
            *(f32*)(*(u8**)(packet + 0x50) + 0x23c) = ((f32 (*)(s32))lbl_80408D44)(**(s16**)(object + 0x60));
        } else {
            *(f32*)(object + 0x23c) = 1.0f;
        }
        if (count && NuStrICmp(params[0], str_ScriptToken_Default))
            *(f32*)(*(u8**)(packet + 0x50) + 0x23c) = aiParamFloat(processor, params[0]);
    }
    return 1;
}

s32 Action_SetHearDistance(struct aisysview_s* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    u8* object;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110) && firstTime) {
        if (packet[0xa6] != 0xff) {
            struct aicreatureview_s* creature = sys->creatures + packet[0xa6];
            *(f32*)(object + 0x238) = creature->field9c;
        } else if (lbl_80408D40) {
            *(f32*)(*(u8**)(packet + 0x50) + 0x238) = ((f32 (*)(s32))lbl_80408D40)(**(s16**)(object + 0x60));
        } else {
            *(f32*)(object + 0x238) = 1.0f;
        }
        if (count && NuStrICmp(params[0], str_ScriptToken_Default))
            *(f32*)(*(u8**)(packet + 0x50) + 0x238) = aiParamFloat(processor, params[0]);
    }
    return 1;
}

extern char lbl_8019BFBC[], lbl_8019BFC8[], lbl_8019BFD4[];
extern f32 lbl_8019BFDC[];
s32 Action_SetInterrupt(void* sys, struct aiparamproc_s* processor, void* packet, char** params, s32 count, s32 firstTime)
{
    f32 time = 0.0f;
    u8 priority = 0;
    u8 id = 0;
    char* state = 0;
    s32 i;
    if (firstTime && processor) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(params[i], lbl_8019BFBC);
            if (found) { found += 9; priority = (s32)aiParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i], lbl_8019BFC8))) { found += 3; id = (s32)aiParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i], lbl_8019BFCC))) state = found + 6;
            else if ((found = NuStrIStr(params[i], lbl_8019BFD4))) { found += 5; time = aiParamFloat(processor,found); }
        }
        if (state) fn_8008F35C(processor,priority,id,state,time);
    }
    return 1;
}

extern char lbl_8019BF6C[], lbl_8019BF78[], lbl_8019BF80[];
extern u8* lbl_80408DF0;
extern s16 FindAnimIX(void*,char*);
s32 Action_OverrideAnimation(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    s16 a = -1;
    s16 b = -1;
    s32 i;
    u8* object;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)object && firstTime) {
        for (i = 0; i < count; i++) {
            char* found;
            if (!NuStrICmp(params[i], lbl_8019BF6C)) a = *(s16*)(lbl_80408DF0 + 0xa);
            else if ((found = NuStrIStr(params[i], lbl_8019BF78))) a = FindAnimIX(*(void**)(*(u8**)(packet + 0x50) + 0x64), found + 5);
            else if ((found = NuStrIStr(params[i], lbl_8019BF80))) b = FindAnimIX(*(void**)(*(u8**)(packet + 0x50) + 0x64), found + 3);
            else processor->actionTimer = aiParamFloat(processor,params[0]);
        }
        if (b == -1) a = -1;
        *(s16*)(packet + 0xa2) = a;
        *(s16*)(packet + 0xa4) = b;
    }
    return 1;
}

extern char str_ScriptParam_MinTime[], str_ScriptParam_MaxTime[];
extern f32 lbl_8019BE2C[];
s32 Action_Idle(void* sys, struct aiparamproc_s* processor, void* packet, char** params, s32 count, s32 firstTime, f32 elapsed)
{
    f32 min = 0.0f;
    f32 max = min;
    s32 i;
    if (firstTime) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(params[i],str_ScriptParam_MinTime);
            if (found) { found += 8; min = aiParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],str_ScriptParam_MaxTime))) { found += 8; max = aiParamFloat(processor,found); }
            else processor->actionTimer = aiParamFloat(processor,params[0]);
        }
        if (processor->actionTimer == 0.0f) {
            if (min != 0.0f && max != 0.0f) processor->actionTimer = fn_8000C038() * (max - min) + min;
            else processor->actionTimer = lbl_8019BE2C[0];
        }
    } else if (processor->actionTimer > min) {
        processor->actionTimer -= elapsed;
        if (processor->actionTimer <= min) {
            processor->actionTimer = min;
            return 1;
        }
    }
    return 0;
}

struct aipathnodeview_s {
    u8 pad0[4];
    struct aimovevec_s field4;
    u8 pad10[4];
    f32 field14;
    u8 pad18[0x10];
    u8 count;
    u8 pad29[7];
    u8** connections;
    u8 pad34[0x24];
};

extern f32 fn_8000CDFC(void*,void*,void*);
s32 Action_GoToNodeRandom(void* sys, void* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    struct aimovevec_s out;
    struct aipathnodeview_s* node;
    if (packet && *(void**)(packet + 0x50) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110)) {
        if (firstTime) {
            if (count) {
                struct aipathnodeview_s* selected;
                s32 index = (s32)((f32)count * fn_8000C038());
                if (index >= count) index = count - 1;
                selected = AIPathFindNode(sys,*(void**)(packet + 0x10c),params[index]);
                *(void**)(packet + 0xb4) = selected;
                node = selected;
                if (node && node->count) {
                    u8* path = *(u8**)(packet + 0x10c);
                    u8* connection;
                    s32 nodeIndex = node - *(struct aipathnodeview_s**)(path + 0x78);
                    *(u8**)(packet + 0xcc) = path;
                    connection = node->connections[0];
                    *(u8**)(packet + 0xd0) = connection;
                    if (connection[0] == nodeIndex) *(f32*)(packet + 0xdc) = 0.0f;
                    else *(f32*)(packet + 0xdc) = 1.0f;
                    packet[0xd4] = 0;
                    *(u32*)(packet + 0xd8) |= 0x8000;
                    *(f32*)(packet + 0xe0) = 0.0f;
                    AIMoveInstruction(packet,&selected->field4,0.0f,packet + 0xcc,1,*(f32*)(packet + 0x134));
                } else return 1;
            }
        } else {
            node = *(struct aipathnodeview_s**)(packet + 0xb4);
            if (node) {
                f32 distance = fn_8000CDFC(packet + 0x100,&node->field4,&out);
                AIMoveInstruction(packet,&node->field4,0.0f,packet + 0xcc,1,*(f32*)(packet + 0x134));
                if (distance < node->field14) return 1;
            } else return 1;
        }
        goto finished;
    }
    return 1;
finished:
    return 0;
}

extern char lbl_8019BFA8[];
extern f32 lbl_8019BFB0[];
s32 Action_PathConnectionMaxLength(u8* sys, struct aiparamproc_s* processor, void* packet, char** params, s32 count, s32 firstTime)
{
    s32 direction = 0;
    char* from = 0;
    f32 length = 0.0f;
    char* to = 0;
    s32 i;
    if (sys && firstTime) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(params[i], lbl_8019BF88);
            if (found) from = found + 5;
            else if ((found = NuStrIStr(params[i], lbl_8019BF90))) to = found + 3;
            else if ((found = NuStrIStr(params[i], lbl_8019BFA8))) { found += 7; length = aiParamFloat(processor,found); }
        }
        if (from && to) {
            u8* connection = fn_8008A6D4(sys, *(void**)(*(u8**)(sys + 0xc) + 8), from,to,&direction);
            if (connection) {
                *(f32*)(connection + 0x24) = length;
                if (length != 0.0f && *(f32*)(connection + 0x1c) > length + *(f32*)(*(u8**)(*(u8**)(*(u8**)(sys + 0xc) + 8) + 0x78) + 0x10) + *(f32*)(*(u8**)(*(u8**)(*(u8**)(sys + 0xc) + 8) + 0x78) + 0x10)) {
                    *(u32*)(connection + 4) |= 0x08000000;
                    *(u32*)(connection + 8) |= 0x08000000;
                } else {
                    *(u32*)(connection + 4) &= ~0x08000000;
                    *(u32*)(connection + 8) &= ~0x08000000;
                }
            }
        }
    }
    return 1;
}

s32 Action_GoToNode(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    struct aimovevec_s out;
    struct aipathnodeview_s* node;
    if (packet && *(void**)(packet + 0x50) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110)) {
        if (firstTime) {
            if (count) {
                struct aipathnodeview_s* selected;
                s32 i;
                for (i = 1; i < count; i++) {
                    if (!lbl_80408D2C || !lbl_80408D2C(params[i], packet + 0xb0))
                        *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
                }
                selected = AIPathFindNode(sys,*(void**)(packet + 0x10c),params[0]);
                *(void**)(packet + 0xb4) = selected;
                node = selected;
                if (node && node->count) {
                    u8* path = *(u8**)(packet + 0x10c);
                    u8* connection;
                    s32 nodeIndex = node - *(struct aipathnodeview_s**)(path + 0x78);
                    *(u8**)(packet + 0xcc) = path;
                    connection = node->connections[0];
                    *(u8**)(packet + 0xd0) = connection;
                    if (connection[0] == nodeIndex) *(f32*)(packet + 0xdc) = 0.0f;
                    else *(f32*)(packet + 0xdc) = 1.0f;
                    packet[0xd4] = 0;
                    *(u32*)(packet + 0xd8) |= 0x8000;
                    *(f32*)(packet + 0xe0) = 0.0f;
                    AIMoveInstruction(packet,&selected->field4,0.0f,packet + 0xcc,1,*(f32*)(packet + 0x134));
                } else return 1;
            }
        } else {
            node = *(struct aipathnodeview_s**)(packet + 0xb4);
            if (node) {
                f32 distance = fn_8000CDFC(packet + 0x100,&node->field4,&out);
                AIMoveInstruction(packet,&node->field4,0.0f,packet + 0xcc,1,*(f32*)(packet + 0x134));
                if (distance < node->field14) return 1;
            } else return 1;
        }
        goto finished;
    }
    return 1;
finished:
    return 0;
}

extern void AISysCharacterSetPath(void*,void*);
s32 Action_MoveAwayFromNode(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    struct aimovevec_s out;
    struct aipathnodeview_s* node;
    if (packet && *(void**)(packet + 0x50) && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110)) {
        if (firstTime) {
            if (count) {
                struct aipathnodeview_s* selected;
                s32 i;
                for (i = 1; i < count; i++) {
                    if (!lbl_80408D2C || !lbl_80408D2C(params[i], packet + 0xb0))
                        *(f32*)(packet + 0x134) = aiParamFloat(processor, params[i]);
                }
                selected = AIPathFindNode(sys,*(void**)(packet + 0x10c),params[0]);
                *(void**)(packet + 0xb4) = selected;
                node = selected;
                if (node && node->count) {
                    u8* path = *(u8**)(packet + 0x10c);
                    u8* connection;
                    s32 nodeIndex = node - *(struct aipathnodeview_s**)(path + 0x78);
                    AISysCharacterSetPath(packet,path);
                    connection = node->connections[0];
                    *(u8**)(packet + 0xd0) = connection;
                    if (connection[0] == nodeIndex) *(f32*)(packet + 0xdc) = 0.0f;
                    else *(f32*)(packet + 0xdc) = 1.0f;
                    packet[0xd4] = 0;
                    *(u32*)(packet + 0xd8) |= 0x8000;
                    *(f32*)(packet + 0xe0) = 0.0f;
                    AIMoveInstruction(packet,&selected->field4,0.0f,packet + 0xcc,2,*(f32*)(packet + 0x134));
                } else return 1;
            }
        } else {
            node = *(struct aipathnodeview_s**)(packet + 0xb4);
            if (node) {
                f32 distance = fn_8000CDFC(packet + 0x100,&node->field4,&out);
                if (distance < node->field14) return 1;
                AIMoveInstruction(packet,&node->field4,0.0f,packet + 0xcc,2,*(f32*)(packet + 0x134));
            } else return 1;
        }
        goto finished;
    }
    return 1;
finished:
    return 0;
}

extern f32 lbl_8019BEE0[];
extern void NuVecRotateY(void*,void*,s32);
extern void NuVecAdd(void*,void*,void*);
s32 Action_GoToOrigin(struct aisysview_s* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    struct aimovevec_s out;
    struct aicreatureview_s* creature;
    u8* object;
    s32 i;
    if (!packet || !(object = *(u8**)(packet + 0x50)) || !*(void**)(packet + 0x10c) || !*(void**)(packet + 0x110) || !(*(u32*)(object + 0x208) & 0x400) || packet[0xa6] == 0xff) return 1;
    creature = sys->creatures + packet[0xa6];
    if (firstTime) {
        *(f32*)(packet + 0x134) = lbl_8019BEE0[0];
        if (count) {
            for (i = 0; i < count; i++)
                if (!lbl_80408D2C || !lbl_80408D2C(params[i],packet + 0xb0))
                    *(f32*)(packet + 0x134) = aiParamFloat(processor,params[i]);
        }
        AIMoveInstruction(packet,(u8*)creature + 0x30,0.0f,(u8*)creature + 0x40,1,*(f32*)(packet + 0x134));
        *(f32*)(packet + 0xc0) = 0.0f;
        *(f32*)(packet + 0xc4) = 0.0f;
        *(f32*)(packet + 0xc8) = 1.0f;
        NuVecRotateY(packet + 0xc0,packet + 0xc0,*(s32*)((u8*)creature + 0x3c));
        NuVecAdd(packet + 0xc0,packet + 0xc0,(u8*)creature + 0x30);
    } else {
        f32 distance;
        AIMoveInstruction(packet,(u8*)creature + 0x30,0.0f,(u8*)creature + 0x40,1,*(f32*)(packet + 0x134));
        distance = fn_8000CDFC(packet + 0x100,(u8*)creature + 0x30,&out);
        if (distance < *(f32*)(packet + 0x134) * *(f32*)(packet + 0x134)) {
            *(void**)(packet + 0x19c) = packet + 0xc0;
            return 1;
        }
    }
    return 0;
}

extern char lbl_8019BEEC[], lbl_8019BEF4[], lbl_8019BF00[], lbl_8019BF08[], lbl_8019BF10[], lbl_8019BF18[];
extern s32 NuRand(s32);
s32 Action_SetLocator(void* sys, void* processor, u8* packet, char** params, s32 count, s32 firstTime)
{
    char filename[64];
    s32 a = 0;
    s32 b = 0;
    s32 n = 0;
    char* name = 0;
    u8* object;
    s32 i;
    if (packet && (object = *(u8**)(packet + 0x50)) && *(void**)object && *(void**)(packet + 0x10c) && *(void**)(packet + 0x110) && firstTime) {
        *(void**)(packet + 0xfc) = 0;
        if (count) {
            for (i = 0; i < count; i++) {
                char* found = NuStrIStr(params[i],lbl_8019BEEC);
                if (found) name = found + 5;
                else if (NuStrIStr(params[i],lbl_8019BEF4)) a = 1;
                else if (NuStrIStr(params[i],lbl_8019BF00)) b = 1;
                else if ((found = NuStrIStr(params[i],lbl_8019BF08))) { found += 9; n = (s32)aiParamFloat((struct aiparamproc_s*)packet,found); }
            }
            if (name) {
                if (b && *(s8*)(*(u8**)(packet + 0x50) + 0x284) != -1)
                    sprintf(filename,lbl_8019BF10,name,*(s8*)(*(u8**)(packet + 0x50) + 0x284));
                else if (a && *(void**)(*(u8**)(packet + 0x50) + 0x64))
                    sprintf(filename,lbl_8019BF18,name,*(s32*)(*(u8**)(*(u8**)(packet + 0x50) + 0x64) + 0xc));
                else if (n) sprintf(filename,lbl_8019BF10,name,NuRand(0) % n);
                else sprintf(filename,name);
                *(void**)(packet + 0xfc) = AIPathFindLocator(sys,filename);
            }
        }
    }
    return 1;
}

extern char str_ScriptPath_ScriptTxtFormat[], str_ScriptPath_ScpFormat[];
extern u32 lbl_8040AF30;
extern u8* NuFParCreate(char*);
extern void NuFParGetWord(void*);
extern s32 fn_80006398(void*);
extern void NuMemAllocFn(void*);
extern u8* AIScriptLoadScp(char*,char*,void*,void*);
extern void fn_80007610(void*,void*);
extern s32 fn_8007E064(void*,void*,void*,void*);
extern s32 sprintf(char*,char*,...);
void AIScriptLoadScriptTxt(char* path, void* arg1, void* arg2, u8* sys)
{
    char names[128][32];
    char filename[128];
    s32 n = 0;
    void* list;
    u8* parser;
    u8* script;
    s32 i;
    s32 done;
    list = sys ? sys + 0x18 : &lbl_8040AF30;
    sprintf(filename, str_ScriptPath_ScriptTxtFormat, path);
    parser = NuFParCreate(filename);
    if (parser) {
        while (fn_80006398(parser)) {
            NuFParGetWord(parser);
            sprintf(names[n++], str_ScriptPath_ScpFormat, parser + 0x30a);
        }
        NuMemAllocFn(parser);
    }
    for (i = 0; i < n; i++) {
        script = AIScriptLoadScp(names[i], path, arg1, arg2);
        if (script) {
            fn_80007610(list, script);
            if (sys) *(u32*)(script + 0x3c) |= 0x80000000;
        }
    }
    if (sys) {
        void* lastList = sys + 0x18;
        do {
            done = 1;
            for (script = fn_800076C4(lastList); script; script = fn_800076CC(lastList, script))
                if (!fn_8007E064(script, arg1, arg2, sys)) done = 0;
        } while (!done);
    }
}

struct aiconnectionview_s { u8 nodes[2]; u8 pad2[2]; u32 flags[2]; };
extern char lbl_8019BF94[], lbl_8019BFA0[];
static inline void aiBlockConnection(u8* path, char* from, char* to, s32 blocked)
{
    s32 direction = 0;
    u8* connection = 0;
    if (path && from && to) {
        struct aipathnodeview_s* first = AIPathFindNode(0,path,from);
        struct aipathnodeview_s* last = AIPathFindNode(0,path,to);
        if (first && last) {
            s32 index = last - *(struct aipathnodeview_s**)(path + 0x78);
            s32 i;
            for (i = 0; i < first->count; i++) {
                if (first->connections[i][0] == index) { connection = first->connections[i]; direction = 1; break; }
                if (first->connections[i][1] == index) { connection = first->connections[i]; direction = 0; break; }
            }
            if (connection) {
                if (blocked) ((struct aiconnectionview_s*)connection)->flags[direction] |= 0x80000000;
                else ((struct aiconnectionview_s*)connection)->flags[direction] &= 0x7fffffff;
            }
        }
    }
}
s32 Action_BlockPath(u8* sys, void* processor, void* packet, char** params, s32 count, s32 firstTime)
{
    s32 blocked = 1;
    s32 both = 0;
    char* from = 0;
    char* to = 0;
    s32 i;
    u8* pathsys;
    if (sys && (pathsys = *(u8**)(sys + 0xc)) && pathsys[0] && firstTime) {
        for (i = 0; i < count; i++) {
            char* found = NuStrIStr(params[i],lbl_8019BF88);
            if (found) from = found + 5;
            else if ((found = NuStrIStr(params[i],lbl_8019BF90))) to = found + 3;
            else if (!NuStrICmp(params[i],lbl_8019BF94)) both = 1;
            else if (!NuStrICmp(params[i],lbl_8019BFA0)) blocked = 0;
        }
        if (from && to) {
            aiBlockConnection(*(u8**)(*(u8**)(sys + 0xc) + 8),from,to,blocked);
            if (both) aiBlockConnection(*(u8**)(*(u8**)(sys + 0xc) + 8),to,from,blocked);
        }
    }
    return 1;
}

struct aifaceobj_s { u8 pad0[4]; void* field4; u8 pad8[0x64]; struct aimovevec_s position; };
extern void NuVecNorm(void*,void*);
extern char str_ScriptParam_FaceOffset[];
extern f32 lbl_8019BE9C[];
s32 Action_FaceOpponent(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime, f32 elapsed)
{
    f32 min = 0.0f;
    f32 max = min;
    s32 i;
    if (!packet) return 1;
    if (firstTime) {
        packet[0xb2] = 0;
        for (i = 0; i < count; i++) {
            char* found;
            found = NuStrIStr(params[i],str_ScriptParam_MinTime);
            if (found) { found += 8; min = aiParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],str_ScriptParam_MaxTime))) { found += 8; max = aiParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],str_ScriptParam_FaceOffset))) { found += 11; *(f32*)(packet + 0xb8) = aiParamFloat(processor,found); }
            else processor->actionTimer = aiParamFloat(processor,params[i]);
        }
        if (processor->actionTimer == 0.0f) {
            if (min != 0.0f && max != 0.0f) processor->actionTimer = fn_8000C038() * (max - min) + min;
            else processor->actionTimer = lbl_8019BE9C[0];
        }
    }
    {
        struct aifaceobj_s* opponent = *(struct aifaceobj_s**)(packet + 0x64);
        if (opponent && opponent->field4) {
            if (*(f32*)(packet + 0xb8) == 0.0f) *(void**)(packet + 0x19c) = &opponent->position;
            else {
                struct aimovevec_s direction;
                struct aifaceobj_s* object = *(struct aifaceobj_s**)(packet + 0x50);
                direction.x = opponent->position.z - object->position.z;
                {
                    f32 objectX = object->position.x;
                    f32 opponentX = opponent->position.x;
                    direction.y = 0.0f;
                    direction.z = objectX - opponentX;
                }
                NuVecNorm(&direction,&direction);
                {
                    struct aifaceobj_s* target = *(struct aifaceobj_s**)(packet + 0x64);
                    *(f32*)(packet + 0xc0) = direction.x * *(f32*)(packet + 0xb8) + target->position.x;
                    *(f32*)(packet + 0xc4) = target->position.y;
                    *(f32*)(packet + 0xc8) = direction.z * *(f32*)(packet + 0xb8) + target->position.z;
                    *(void**)(packet + 0x19c) = packet + 0xc0;
                }
            }
        }
    }
    if (processor->actionTimer > 0.0f) {
        processor->actionTimer -= elapsed;
        if (processor->actionTimer <= 0.0f) {
            processor->actionTimer = 0.0f;
            return 1;
        }
    }
    return 0;
}

extern char lbl_8019BF24[], lbl_8019BF30[], lbl_8019BF3C[], lbl_8019BF48[];
extern f32 lbl_8019BF58[], lbl_8019BF5C[], lbl_8019BF60[], lbl_80408CFC;
static inline f32 aiLocatorParamFloat(struct aiparamproc_s *processor, char *param)
{
    char *cursor;
    s32 i;
    if (param != NULL) {
        if (processor != NULL) {
            cursor = NuStrIStr(param, str_ScriptToken_ParamLower);
            if (cursor != NULL) {
                i = NuAToI(cursor);
                if ((u32)i < 4) return processor->script->params[i].value;
            } else if (processor->script != NULL) {
                for (i = 0; i < 4; i++) {
                    if (processor->script->params[i].name != NULL &&
                        strcasecmp(processor->script->params[i].name, param) == 0) {
                        return processor->script->params[i].value;
                    }
                }
            }
        }
        return fn_800077E8(param);
    }
    return lbl_8019BF58[0];
}
s32 Action_GoToLocator(void* sys, struct aiparamproc_s* processor, u8* packet, char** params, s32 count, s32 firstTime, f32 elapsed)
{
    struct aimovevec_s difference;
    char filename[64];
    f32 min = lbl_8019BF58[0];
    s32 personal = 0, indexed = 0, random = 0;
    f32 max = min;
    s32 i;
    u8* object;
    u8* locator;
    if (!packet || !(object = *(u8**)(packet + 0x50)) || !*(void**)object || !*(void**)(packet + 0x10c) || !*(void**)(packet + 0x110)) goto complete;
    if (firstTime) {
        *(void**)(packet + 0xb4) = *(void**)(packet + 0xfc);
        if (count) for (i = 0; i < count; i++) {
            char* found;
            if (lbl_80408D2C && lbl_80408D2C(params[i],packet + 0xb0)) continue;
            if (NuStrIStr(params[i],lbl_8019BEEC) || NuStrIStr(params[i],lbl_8019BF24)) {
                i++;
                if (i < count) {
                    if (indexed && *(s8*)(*(u8**)(packet + 0x50) + 0x284) != -1)
                        sprintf(filename,lbl_8019BF10,params[i],*(s8*)(*(u8**)(packet + 0x50) + 0x284));
                    else if (personal && *(void**)(*(u8**)(packet + 0x50) + 0x64))
                        sprintf(filename,lbl_8019BF18,params[i],*(s32*)(*(u8**)(*(u8**)(packet + 0x50) + 0x64) + 0xc));
                    else if (random) { s32 value = NuRand(0); sprintf(filename,lbl_8019BF10,params[i],value % random); }
                    else sprintf(filename,params[i]);
                    *(void**)(packet + 0xb4) = AIPathFindLocator(sys,filename);
                }
                if (NuStrIStr(params[i-1],lbl_8019BF24)) {
                    locator = *(u8**)(packet + 0xb4);
                    if (locator) *(struct aimovevec_s*)(*(u8**)(packet + 0x50) + 0x6c) = *(struct aimovevec_s*)(locator + 0x10);
                    goto complete;
                }
            } else if (NuStrIStr(params[i],lbl_8019BEF4)) personal = 1;
            else if (NuStrIStr(params[i],lbl_8019BF00)) indexed = 1;
            else if ((found = NuStrIStr(params[i],lbl_8019BF08))) { found += 9; random = (s32)aiLocatorParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],lbl_8019BF30))) { found += 9; processor->actionTimer = aiLocatorParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],str_ScriptParam_MinTime))) { found += 8; min = aiLocatorParamFloat(processor,found); }
            else if ((found = NuStrIStr(params[i],str_ScriptParam_MaxTime))) { found += 8; max = aiLocatorParamFloat(processor,found); }
            else if (!NuStrICmp(params[i],lbl_8019BF3C)) packet[0xb2] = 1;
            else if (!NuStrICmp(params[i],lbl_8019BF48)) packet[0xb3] = 1;
            else *(f32*)(packet + 0x134) = aiLocatorParamFloat(processor,params[i]);
        }
        if (processor->actionTimer == lbl_8019BF58[0]) {
            if (min != lbl_8019BF58[0] && max != lbl_8019BF58[0]) processor->actionTimer = fn_8000C038() * (max-min) + min;
            else processor->actionTimer = lbl_8019BF5C[0];
        }
        locator = *(u8**)(packet + 0xb4);
        if (!locator) goto complete;
        AIMoveInstruction(packet,locator + 0x10,lbl_8019BF58[0],locator + 0x20,1,*(f32*)(packet + 0x134));
        {
            f32 zero = lbl_8019BF58[0];
            f32 one = lbl_8019BF60[0];
            struct ailocatorpacket_s { u8 pad[0xc0]; struct aimovevec_s facing; };
            struct ailocatorpacket_s* view = (struct ailocatorpacket_s*)packet;
            view->facing.x = zero; view->facing.z = one; view->facing.y = zero;
        }
        NuVecRotateY(packet + 0xc0,packet + 0xc0,*(s32*)(locator + 0x1c));
        NuVecAdd(packet + 0xc0,packet + 0xc0,locator + 0x10);
    } else {
        f32 distance, radius;
        s32 near;
        locator = *(u8**)(packet + 0xb4);
        if (!locator) goto complete;
        near = 0;
        AIMoveInstruction(packet,locator + 0x10,min,locator + 0x20,1,*(f32*)(packet + 0x134));
        if (packet[0xb2] && !(*(u8**)(packet + 0x50))[0x285]) goto running;
        if (packet[0xb3]) distance = fn_8000CDFC(packet + 0x100,locator + 0x10,&difference);
        else distance = fn_8000CD08(packet + 0x100,locator + 0x10,&difference);
        radius = *(f32*)(packet + 0x134) + lbl_80408CFC;
        if (distance < radius * radius) near = 1;
        if (near) {
            f32 zero;
            f32 time;
            *(void**)(packet + 0x19c) = packet + 0xc0;
            zero = lbl_8019BF58[0];
            time = processor->actionTimer;
            if (time > zero) {
                time -= elapsed;
                processor->actionTimer = time;
                if (time < zero) processor->actionTimer = zero;
            } else goto complete;
        }
    }
    goto running;
complete:
    return 1;
running:
    return 0;
}

extern s32 fn_8000ABDC(f32, f32);
extern f32 lbl_8019C628[], lbl_8019C62C[];
f32 Condition_YawToOpponent(void *sys, void *process, u8 *packet)
{
    f32 relative[3];
    u8 *opponent;
    u8 *owner;
    if (packet && (opponent = *(u8 **)(packet + 0x64))) {
        owner = *(u8 **)(packet + 0x50);
        relative[0] = *(f32 *)(opponent + 0x6c) - *(f32 *)(owner + 0x6c);
        relative[2] = *(f32 *)(opponent + 0x74) - *(f32 *)(owner + 0x74);
        NuVecRotateY(relative, relative, -*(u16 *)(owner + 0x27e));
        return (f32)fn_8000ABDC(relative[0], relative[2]) * lbl_8019C628[0];
    }
    return lbl_8019C62C[0];
}

static inline void *aiFindState(char *name, u8 *script)
{
    u8 *entry = fn_800076C4(script + 0x10);
    if (!name) return 0;
    for (; entry; entry = fn_800076CC(script + 0x10, entry))
        if (!NuStrICmp(name, *(char **)(entry + 0x18))) return entry;
    return 0;
}
s32 Action_SetState(void *sys, u8 *process, void *packet, char **params, s32 count, s32 firstTime)
{
    if (firstTime && count)
        *(void **)(process + 0x10) = aiFindState(params[0], *(u8 **)(process + 4));
    return 0;
}

s32 Action_SetMoveRadius(void *sys, struct aiparamproc_s *process, u8 *packet, char **params, s32 count, s32 firstTime)
{
    u8 *owner;
    if (packet && (owner = *(u8 **)(packet + 0x50)) && *(void **)(packet + 0x10c) && *(void **)(packet + 0x110) && firstTime) {
        *(f32 *)(packet + 0x9c) = 2.0f * *(f32 *)(owner + 0xbc);
        if (count && NuStrICmp(params[0], str_ScriptToken_Default))
            *(f32 *)(packet + 0x9c) = aiParamFloat(process, params[0]);
    }
    return 1;
}

extern char lbl_8019BFE0[];
struct aiignorebits_s { u32 pad0:17; u32 value:1; u32 pad18:14; };
s32 Action_SetIgnoreAntinodes(void *sys, void *process, u8 *packet, char **params, s32 count, s32 firstTime)
{
    u8 *object = 0;
    s32 ignore = 1;
    s32 i;
    char *value;
    if (firstTime) {
        if (packet && *(u8 **)(packet + 0x50)) object = *(u8 **)(packet + 0x50);
        for (i = 0; i < count; i++) {
            value = NuStrIStr(params[i], lbl_8019BFE0);
            if (value) {
                value += 10;
                if (lbl_80408DA4) object = lbl_80408DA4(sys, value);
            } else if (NuStrICmp(lbl_8019BFA0, params[0]) == 0) ignore = 0;
        }
        if (object) ((struct aiignorebits_s *)(object + 0x20c))->value = ignore;
    }
    return 1;
}

extern f32 lbl_8019C684[];
static inline f32 aiParamFloatFace(struct aiparamproc_s *processor, char *param)
{
    char *cursor;
    s32 i;
    if (param != NULL) {
        if (processor != NULL) {
            cursor = NuStrIStr(param, str_ScriptToken_ParamLower);
            if (cursor != NULL) {
                i = NuAToI(cursor);
                if ((u32)i < 4) return processor->script->params[i].value;
            } else if (processor->script != NULL) {
                for (i = 0; i < 4; i++) {
                    if (processor->script->params[i].name != NULL &&
                        strcasecmp(processor->script->params[i].name, param) == 0) {
                        return processor->script->params[i].value;
                    }
                }
            }
        }
        return fn_800077E8(param);
    }
    return lbl_8019C684[0];
}
s32 Action_FacePlayer(u8 *sys, struct aiparamproc_s *process, u8 *packet, char **params, s32 count, s32 firstTime, f32 elapsed)
{
    u8 *player;
    f32 timer, zero;
    if (!packet) return 1;
    if (firstTime && count) process->actionTimer = aiParamFloatFace(process, params[0]);
    player = *(u8 **)(sys + 0x1380);
    if (player) *(void **)(packet + 0x19c) = player + 0x6c;
    timer = process->actionTimer;
    zero = lbl_8019C684[0];
    if (timer > zero) {
        timer -= elapsed;
        process->actionTimer = timer;
        if (timer <= zero) {
            process->actionTimer = zero;
            return 1;
        }
    }
    return 0;
}

struct aiturnbits_s { u32 pad0:16; u32 value:1; u32 pad17:15; };
s32 NuAngAdd(s32, s32);
s32 NuAngSub(s32, s32);
extern f32 lbl_80408D54;
extern f32 lbl_80408D58;


void AISysCheckAntinode_Circle(void *object, void *region, void *relative, f32 radius)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 startAngle;
    s32 endAngle;
    s32 angle;
    s32 var_r0;
    s32 maxTurn;
    s32 turn;
    void *temp_r11;
    void *temp_r9;
    void *temp_r9_2;

    temp_f0 = *(f32 *)((u8 *)relative + 8);
    temp_f13 = *(f32 *)((u8 *)relative + 0);
    if (((temp_f13 * temp_f13) + (temp_f0 * temp_f0)) < (radius * radius)) {
        temp_f1 = *(f32 *)((u8 *)object + 0x6c) - *(f32 *)((u8 *)region + 0);
        *(f32 *)((u8 *)relative + 0) = temp_f1;
        temp_f13_2 = *(f32 *)((u8 *)region + 8);
        temp_f0_2 = *(f32 *)((u8 *)object + 0x74) - temp_f13_2;
        *(f32 *)((u8 *)relative + 8) = temp_f0_2;
        startAngle = fn_8000ABDC(temp_f1, temp_f0_2);
        temp_f1_2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x80))) - *(f32 *)((u8 *)region + 0);
        *(f32 *)((u8 *)relative + 0) = temp_f1_2;
        temp_f0_3 = (*(f32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x88))) - *(f32 *)((u8 *)region + 8);
        *(f32 *)((u8 *)relative + 8) = temp_f0_3;
        angle = fn_8000ABDC(temp_f1_2, temp_f0_3);
        turn = NuAngSub(angle, startAngle);
        temp_r11 = (*(void **)((s8 *)(object) + (4)));
        temp_f12 = *(f32 *)((u8 *)temp_r11 + 0x140);
        if (temp_f12 > 0.0f) {
            if ((((s32) (*(s32 *)((u8 *)temp_r11 + 0x118) & 0xC000) == 0x4000) || (*(f32 *)((u8 *)object + 0x1e8) > 1.0f)) && (temp_f12 < lbl_80408D54)) {
                ((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value = !((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value;
                (*(f32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x140))) = (f32) (lbl_80408D58 + lbl_80408D54);
            }
            if ((*(s32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x1A0))) & 0x8000) {
                if (turn < 0) {
                    turn += 0x10000;
                }
            } else if (turn > 0) {
                turn += 0xFFFF0000;
            }
        } else {
            if (turn > 0) {
                var_r0 = *(s32 *)((u8 *)temp_r11 + 0x1a0) | 0x8000;
            } else {
                var_r0 = *(s32 *)((u8 *)temp_r11 + 0x1a0) & 0xFFFF7FFF;
            }
            *(s32 *)((u8 *)temp_r11 + 0x1a0) = var_r0;
        }
        if (!(*(u8 *)((u8 *)region + 0x49) & 2)) {
            temp_r9 = (*(void **)((s8 *)(object) + (4)));
            if (*(f32 *)((u8 *)temp_r9 + 0x140) < lbl_80408D54) {
                *(f32 *)((u8 *)temp_r9 + 0x140) = (f32) lbl_80408D54;
            }
        }
        maxTurn = (s32) ((lbl_80408CFC / radius) * 10430.378f);
        if ((turn > maxTurn) || (maxTurn = -maxTurn, ((turn < maxTurn) != 0))) {
            turn = maxTurn;
        }
        endAngle = NuAngAdd(startAngle, turn);
        *(f32 *)((u8 *)relative + 0) = (f32) 0.0f;
        *(f32 *)((u8 *)relative + 4) = (f32) 0.0f;
        *(f32 *)((u8 *)relative + 8) = radius;
        NuVecRotateY(relative, relative, endAngle);
        (*(f32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x90))) = (f32) (*(f32 *)((u8 *)relative + 0) + *(f32 *)((u8 *)region + 0));
        temp_r9_2 = (*(void **)((s8 *)(object) + (4)));
        *(f32 *)((u8 *)temp_r9_2 + 0x94) = (f32) *(f32 *)((u8 *)temp_r9_2 + 0x84);
        (*(f32 *)((s8 *)((*(void **)((s8 *)(object) + (4)))) + (0x98))) = (f32) (*(f32 *)((u8 *)relative + 8) + *(f32 *)((u8 *)region + 8));
    }
}

struct aipointertable_s { u8 pad0[0xc]; void *entries[16]; };

void fn_800868B4(void *arg0, void *arg1)
{
    f32 temp_f0;
    f32 temp_f7;
    s32 temp_r9;
    s32 var_r7;
    u32 temp_r10;
    u8 temp_r11;
    u8 temp_r9_2;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_r11 = (*(u8 *)((s8 *)(arg0) + (7)));
        if (temp_r11 <= 0xFU) {
            temp_r10 = (*(u8 *)((s8 *)(arg0) + (8)));
            temp_r9 = temp_r11 + 1;
            var_r7 = temp_r9 / (s32) temp_r10;
            if (temp_r9 != (s32) (var_r7 * temp_r10)) {
                var_r7 += 1;
            }
            if (var_r7 <= 4) {
                if ((s32) temp_r11 == 0) {
                    temp_f7 = (*(f32 *)((s8 *)(arg0) + (0x128)));
                    (*(void **)((s8 *)(arg0) + (0))) = arg1;
                    if (temp_f7 > 0.0f) {
                        temp_f0 = temp_f7 * ((f32) (f64) temp_r10 - 1.0f) * 0.5f;
                        (*(f32 *)((s8 *)(arg0) + (0x124))) = temp_f0;
                        (*(s16 *)((s8 *)(arg0) + (4))) = (s16) (((*(f32 *)((s8 *)(arg0) + (0x130))) / (temp_f0 * 6e+01f)) * 10430.378f);
                    } else {
                        (*(f32 *)((s8 *)(arg0) + (0x124))) = (f32) 0.0f;
                        (*(s16 *)((s8 *)(arg0) + (4))) = 0x64;
                    }
                }
                (*(s8 *)((s8 *)(arg0) + (6))) = (s8) var_r7;
                (*(void **)((s8 *)((*(void **)((s8 *)(arg1) + (4)))) + (0xF0))) = arg0;
                (*(u8 *)((s8 *)((*(void **)((s8 *)(arg1) + (4)))) + (0xF4))) = (u8) (*(u8 *)((s8 *)(arg0) + (7)));
                (*(s8 *)((s8 *)((*(void **)((s8 *)(arg1) + (4)))) + (0xF6))) = (s8) ((u8) (*(u8 *)((s8 *)(arg0) + (7))) / (u8) (*(u8 *)((s8 *)(arg0) + (8))));
                (*(s8 *)((s8 *)((*(void **)((s8 *)(arg1) + (4)))) + (0xF5))) = (s8) ((*(u8 *)((s8 *)(arg0) + (7))) % (*(u8 *)((s8 *)(arg0) + (8))));
                ((struct aipointertable_s *)arg0)->entries[(*(u8 *)((u8 *)arg0 + 7))++] = arg1;
            }
        }
    }
}

struct aioriginobject_s {
    u8 pad0[0x6c];
    struct aimovevec_s position;
    u8 pad78[0x190];
    u32 flags208;
};
struct aiorigincreature_s {
    u8 pad0[0x30];
    struct aimovevec_s position;
    u8 pad3c[0x6c];
};
struct aioriginsys_s {
    u8 pad0[0x14];
    struct aiorigincreature_s *creatures;
};
struct aioriginpacket_s {
    u8 pad0[0x50];
    struct aioriginobject_s *owner;
    u8 pad54[0x52];
    u8 index;
};

s32 Action_ResetToOrigin(struct aioriginsys_s *sys, void *process, struct aioriginpacket_s *packet)
{
    struct aioriginobject_s *owner = packet->owner;
    if ((owner->flags208 & 0x400) && packet->index != 0xff) {
        struct aiorigincreature_s *creature = sys->creatures + packet->index;
        owner->position = creature->position;
    }
    return 1;
}

extern f32 lbl_8019C68C[];

s32 Action_FollowPath(void *sys, void *process, void *packet, char **params, s32 count, s32 firstTime)
{
    s32 *owner;
    char **param;
    s32 remaining;

    if ((packet == NULL) || (owner = (*(s32 **)((s8 *)(packet) + (0x50))), ((owner == NULL) != 0)) || ((s32) *owner == 0)) {
        return 1;
    }
    if (!*(void **)((u8 *)packet + 0x10c) || !*(void **)((u8 *)packet + 0x110)) return 0;
    {
        if (firstTime != 0) {
            (*(s32 *)((s8 *)(packet) + (0x13C))) = 0;
            if (count > 0) {
                param = params;
                remaining = count;
                do {
                    if (lbl_80408D2C != NULL) {
                        lbl_80408D2C(*param, packet + 0xB0);
                    }
                    param += 1;
                    remaining -= 1;
                } while (remaining != 0);
            }
        }
        AIMoveInstruction(packet, 0, lbl_8019C68C[0], 0, 4, (*(f32 *)((s8 *)(packet) + (0x134))));
    }
    return 0;
}

f32 Condition_EitherPlayerInTriggerArea(u8 *sys, void *process, u8 *packet, char *params, u8 *inputArea)
{
    u8 *area = 0;
    u8 *player;

    if (sys) {
        if (inputArea) area = inputArea;
        else if (packet) area = *(u8 **)(packet + 0xf8);
        if (area) {
            player = *(u8 **)(sys + 0x1380);
            if (player && (*(u64 *)(area + 0x30) & __ashldi3(1ULL, player[0x291])))
                return lbl_8019C5E0[0];
            if (*(u8 **)(sys + 0x1384) && (*(u64 *)(area + 0x30) & __ashldi3(1ULL, (*(u8 **)(sys + 0x1384))[0x291])))
                return lbl_8019C5E0[0];
        }
    }
    return lbl_8019C5E4[0];
}

f32 NuCosApprox(s32);
f32 NuSinApprox(s32);
void NuVecScale(void *, void *, f32);

void AISysCheckAntinode_Ellipse(void *arg0, f32 *arg1, f32 *arg2, f32 farg0)
{
    f32 boundary[3];
    f32 tangent[3];
    f32 outer[3];
    f32 sp38[3];
    f32 sp48[3];
    f32 sp58[3];
    f32 *temp_r3;
    f32 *temp_r3_2;
    f32 temp_f0;
    f32 x1, x2;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f13;
    f32 temp_f13_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f29;
    f32 temp_f30;
    f32 temp_f31;
    s32 temp_r0;
    s32 angle;
    s32 temp_r0_2;
    s32 temp_r27;

    s32 temp_r9_2;
    s32 var_r0;
    s32 var_r31;
    void *temp_r11;
    void *temp_r9;

    temp_f0 = (*(f32 *)((s8 *)(arg2) + (8)));
    temp_f13 = (*(f32 *)((s8 *)(arg2) + (0)));
    temp_f29 = (temp_f13 * temp_f13) + (temp_f0 * temp_f0);
    if (temp_f29 < (farg0 * farg0)) {
        temp_f13_2 = (*(f32 *)((s8 *)(arg1) + (0x44)));
        temp_f30 = 0.0f;
        temp_f31 = temp_f13_2 / (*(f32 *)((s8 *)(arg1) + (0x40)));
        (*(f32 *)((s8 *)(arg2) + (4))) = temp_f30;
        NuVecRotateY(sp38, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
        temp_r27 = fn_8000ABDC(sp38[0] * temp_f31, sp38[2]);
        temp_f1 = NuSinApprox(temp_r27);
        outer[1] = temp_f30;
        temp_f1_2 = temp_f1 * (*(f32 *)((s8 *)(arg1) + (0x40)));
        outer[0] = temp_f1_2;
        temp_f1_3 = NuCosApprox(temp_r27) * (*(f32 *)((s8 *)(arg1) + (0x44)));
        outer[2] = temp_f1_3;
        NuVecNorm(arg2, &outer[0]);
        NuVecScale(arg2, arg2, (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x9C))));
        NuVecAdd(&outer[0], &outer[0], arg2);
        if (temp_f29 < ((outer[0] * outer[0]) + (outer[2] * outer[2]))) {
            x1 = (*(f32 *)((s8 *)(arg0) + (0x6C))) - (*(f32 *)((s8 *)(arg1) + (0)));
            (*(f32 *)((s8 *)(arg2) + (4))) = temp_f30;
            (*(f32 *)((s8 *)(arg2) + (0))) = x1;
            (*(f32 *)((s8 *)(arg2) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x74))) - (*(f32 *)((s8 *)(arg1) + (8))));
            NuVecRotateY(sp48, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
            temp_r27 = fn_8000ABDC(sp48[0] * temp_f31, sp48[2]);
            temp_f1_4 = NuSinApprox(temp_r27);
            boundary[1] = temp_f30;
            temp_f1_5 = temp_f1_4 * (*(f32 *)((s8 *)(arg1) + (0x40)));
            boundary[0] = temp_f1_5;
            temp_f1_6 = NuCosApprox(temp_r27) * (*(f32 *)((s8 *)(arg1) + (0x44)));
            boundary[2] = temp_f1_6;
            NuVecNorm(arg2, &boundary[0]);
            NuVecScale(arg2, arg2, (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x9C))));
            NuVecAdd(&boundary[0], &boundary[0], arg2);
            x2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x80))) - (*(f32 *)((s8 *)(arg1) + (0)));
            (*(f32 *)((s8 *)(arg2) + (4))) = temp_f30;
            (*(f32 *)((s8 *)(arg2) + (0))) = x2;
            (*(f32 *)((s8 *)(arg2) + (8))) = (f32) ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x88))) - (*(f32 *)((s8 *)(arg1) + (8))));
            NuVecRotateY(sp58, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
            angle = fn_8000ABDC(sp58[0] * temp_f31, sp58[2]);
            var_r31 = NuAngSub(angle, temp_r27);
            temp_r11 = (*(void **)((s8 *)(arg0) + (4)));
            temp_f12 = (*(f32 *)((s8 *)(temp_r11) + (0x140)));
            if (temp_f12 > temp_f30) {
                if ((((s32) ((*(s32 *)((s8 *)(temp_r11) + (0x118))) & 0xC000) == 0x4000) || ((*(f32 *)((s8 *)(arg0) + (0x1E8))) > 1.0f)) && (temp_f12 < lbl_80408D54)) {
                    temp_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0)));
                    ((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value = !((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value;
                    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x140))) = (f32) (lbl_80408D58 + lbl_80408D54);
                }
                if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x1A0))) & 0x8000) {
                    if (var_r31 < 0) {
                        var_r31 += 0x10000;
                    }
                } else if (var_r31 > 0) {
                    var_r31 += 0xFFFF0000;
                }
            } else {
                if (var_r31 > 0) {
                    var_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) | 0x8000;
                } else {
                    var_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) & 0xFFFF7FFF;
                }
                (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) = var_r0;
            }
            if (!((*(u8 *)((s8 *)(arg1) + (0x49))) & 2)) {
                temp_r9 = (*(void **)((s8 *)(arg0) + (4)));
                if ((*(f32 *)((s8 *)(temp_r9) + (0x140))) < lbl_80408D54) {
                    (*(f32 *)((s8 *)(temp_r9) + (0x140))) = (f32) lbl_80408D54;
                }
            }
            temp_f1_7 = NuCosApprox(temp_r27) * (*(f32 *)((s8 *)(arg1) + (0x40)));
            tangent[0] = temp_f1_7;
            temp_f1_8 = -NuSinApprox(temp_r27) * (*(f32 *)((s8 *)(arg1) + (0x44)));
            tangent[2] = temp_f1_8;
            if (var_r31 < 0) {
                tangent[2] = -temp_f1_8;
                tangent[0] = -tangent[0];
            }
            temp_r9_2 = var_r31 >> 0x1F;
            temp_r0_2 = (temp_r9_2 ^ var_r31) - temp_r9_2;
            if (temp_r0_2 <= 0x71B) {
                temp_f0_2 = (f32) (f64) temp_r0_2 / 1.82e+03f;
                tangent[0] *= temp_f0_2;
                tangent[2] *= temp_f0_2;
            }
            (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x90))) = (f32) (boundary[0] + tangent[0]);
            (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x94))) = (f32) 0.0f;
            (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x98))) = (f32) (boundary[2] + tangent[2]);
            temp_r3 = (*(void **)((s8 *)(arg0) + (4))) + 0x90;
            NuVecRotateY(temp_r3, temp_r3, (*(s32 *)((s8 *)(arg1) + (0x38))));
            temp_r3_2 = (*(void **)((s8 *)(arg0) + (4))) + 0x90;
            NuVecAdd(temp_r3_2, temp_r3_2, arg1);
        }
    }
}

f32 fn_8000ED40(f32);
extern f32 lbl_8019C818[];

void AISysCheckAntinode_Rectangle(void *arg0, void *arg1, f32 *arg2, f32 farg0)
{
    f32 tangent[3];
    f32 sp18[3];
    f32 sp28[3];
    f32 *temp_r3_2;
    f32 temp_f0;
    f32 x;
    f32 sinAngle;
    f32 cosAngle;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f31;
    s32 temp_r0;
    s32 angle;
    s32 temp_r0_2;
    s32 temp_r28;
    s32 temp_r31;
    s32 temp_r9_5;
    s32 var_r0;
    s32 var_r27;
    void *temp_r11;
    void *temp_r11_4;
    void *temp_r11_5;
    void *temp_r3_3;
    void *temp_r9;

    temp_f0 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x90))) - (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg2) + (0))) = temp_f0;
    if (!(temp_f0 > farg0)) {
        temp_f12 = -farg0;
        if (!(temp_f0 < temp_f12)) {
            temp_f0_2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x98))) - (*(f32 *)((s8 *)(arg1) + (8)));
            (*(f32 *)((s8 *)(arg2) + (8))) = temp_f0_2;
            if (!(temp_f0_2 > farg0) && !(temp_f0_2 < temp_f12) && !((*(f32 *)((s8 *)(arg0) + (0x18C))) > (*(f32 *)((s8 *)(arg1) + (0x18)))) && !((*(f32 *)((s8 *)(arg1) + (0x10))) > (*(f32 *)((s8 *)(arg0) + (0x198))))) {
                NuVecRotateY(arg2, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
                if ((fn_8000ED40((*(f32 *)((s8 *)(arg2) + (0)))) < ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x9C))) + (*(f32 *)((s8 *)(arg1) + (0x40))))) && (fn_8000ED40((*(f32 *)((s8 *)(arg2) + (8)))) < ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x9C))) + (*(f32 *)((s8 *)(arg1) + (0x44)))))) {
                    temp_f31 = 0.0f;
                    (*(f32 *)((s8 *)(arg2) + (0))) = (*(f32 *)((s8 *)(arg0) + (0x6C))) - (*(f32 *)((s8 *)(arg1) + (0)));
                    (*(f32 *)((s8 *)(arg2) + (4))) = temp_f31;
                    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x74))) - (*(f32 *)((s8 *)(arg1) + (8))));
                    NuVecRotateY(sp18, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
                    temp_r28 = fn_8000ABDC(sp18[0], sp18[2]);
                    x = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x80))) - (*(f32 *)((s8 *)(arg1) + (0)));
                    (*(f32 *)((s8 *)(arg2) + (4))) = temp_f31;
                    (*(f32 *)((s8 *)(arg2) + (0))) = x;
                    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x88))) - (*(f32 *)((s8 *)(arg1) + (8))));
                    NuVecRotateY(sp28, arg2, -(*(s32 *)((s8 *)(arg1) + (0x38))));
                    angle = fn_8000ABDC(sp28[0], sp28[2]);
                    var_r27 = NuAngSub(angle, temp_r28);
                    temp_r11 = (*(void **)((s8 *)(arg0) + (4)));
                    temp_f12_2 = (*(f32 *)((s8 *)(temp_r11) + (0x140)));
                    if (temp_f12_2 > temp_f31) {
                        if ((((s32) ((*(s32 *)((s8 *)(temp_r11) + (0x118))) & 0xC000) == 0x4000) || ((*(f32 *)((s8 *)(arg0) + (0x1E8))) > 1.0f)) && (temp_f12_2 < lbl_80408D54)) {
                            temp_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0)));
                            ((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value = !((struct aiturnbits_s *)((u8 *)temp_r11 + 0x1a0))->value;
                            (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x140))) = (f32) (lbl_80408D58 + lbl_80408D54);
                        }
                        if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x1A0))) & 0x8000) {
                            if (var_r27 < 0) {
                                var_r27 += 0x10000;
                            }
                        } else if (var_r27 > 0) {
                            var_r27 += 0xFFFF0000;
                        }
                    } else {
                        if (var_r27 > 0) {
                            var_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) | 0x8000;
                        } else {
                            var_r0 = (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) & 0xFFFF7FFF;
                        }
                        (*(s32 *)((s8 *)(temp_r11) + (0x1A0))) = var_r0;
                    }
                    if (!((*(u8 *)((s8 *)(arg1) + (0x49))) & 2)) {
                        temp_r9 = (*(void **)((s8 *)(arg0) + (4)));
                        if ((*(f32 *)((s8 *)(temp_r9) + (0x140))) < lbl_80408D54) {
                            (*(f32 *)((s8 *)(temp_r9) + (0x140))) = (f32) lbl_80408D54;
                        }
                    }
                    temp_r31 = fn_8000ABDC((*(f32 *)((s8 *)(arg1) + (0x40))), (*(f32 *)((s8 *)(arg1) + (0x44))));
                    temp_r28 = NuAngAdd(temp_r28, 0);
                    if (temp_r28 > (s32)(0x8000U - temp_r31)) {
                        tangent[0] = -1.0f;
                        tangent[2] = 0.0f;
                        sinAngle = NuSinApprox(temp_r28);
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x90) = (*(f32 *)((u8 *)arg1 + 0x40) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c)) * sinAngle;
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x98) = -(*(f32 *)((u8 *)arg1 + 0x44) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c));
                    } else if (temp_r28 > temp_r31) {
                        tangent[0] = 0.0f;
                        tangent[2] = -1.0f;
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x90) = *(f32 *)((u8 *)arg1 + 0x40) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c);
                        cosAngle = NuCosApprox(temp_r28);
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x98) = (*(f32 *)((u8 *)arg1 + 0x44) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c)) * cosAngle;
                    } else if (temp_r28 > -temp_r31) {
                        tangent[0] = 1.0f;
                        tangent[2] = 0.0f;
                        sinAngle = NuSinApprox(temp_r28);
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x90) = (*(f32 *)((u8 *)arg1 + 0x40) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c)) * sinAngle;
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x98) = *(f32 *)((u8 *)arg1 + 0x44) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c);
                    } else if (temp_r28 > temp_r31 - 0x8000) {
                        tangent[0] = 0.0f;
                        tangent[2] = 1.0f;
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x90) = -(*(f32 *)((u8 *)arg1 + 0x40) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c));
                        cosAngle = NuCosApprox(temp_r28);
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x98) = (*(f32 *)((u8 *)arg1 + 0x44) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c)) * cosAngle;
                    } else {
                        tangent[0] = -1.0f;
                        tangent[2] = 0.0f;
                        sinAngle = NuSinApprox(temp_r28);
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x90) = (*(f32 *)((u8 *)arg1 + 0x40) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c)) * sinAngle;
                        *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x98) = -(*(f32 *)((u8 *)arg1 + 0x44) + *(f32 *)(*(u8 **)((u8 *)arg0 + 4) + 0x9c));
                    }
                    if (var_r27 < 0) {
                        tangent[0] = -tangent[0];
                        tangent[2] = -tangent[2];
                    }
                    temp_r9_5 = var_r27 >> 0x1F;
                    temp_r0_2 = (temp_r9_5 ^ var_r27) - temp_r9_5;
                    if (temp_r0_2 <= 0x71B) {
                        temp_f0_3 = (f32) (f64) temp_r0_2 / lbl_8019C818[0];
                        tangent[0] *= temp_f0_3;
                        tangent[2] *= temp_f0_3;
                    }
                    temp_r11_4 = (*(void **)((s8 *)(arg0) + (4)));
                    (*(f32 *)((s8 *)(temp_r11_4) + (0x90))) = (f32) ((*(f32 *)((s8 *)(temp_r11_4) + (0x90))) + tangent[0]);
                    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x94))) = (f32) 0.0f;
                    temp_r11_5 = (*(void **)((s8 *)(arg0) + (4)));
                    (*(f32 *)((s8 *)(temp_r11_5) + (0x98))) = (f32) ((*(f32 *)((s8 *)(temp_r11_5) + (0x98))) + tangent[2]);
                    temp_r3_2 = (*(void **)((s8 *)(arg0) + (4))) + 0x90;
                    NuVecRotateY(temp_r3_2, temp_r3_2, (*(s32 *)((s8 *)(arg1) + (0x38))));
                    temp_r3_3 = (*(void **)((s8 *)(arg0) + (4))) + 0x90;
                    NuVecAdd(temp_r3_3, temp_r3_3, arg1);
                }
            }
        }
    }
}

struct aiprocessbits_s {
    u32 upper:17;
    u32 initialized:1;
    u32 mid:3;
    u32 transient:4;
    u32 lower:2;
    u32 source:2;
    u32 active:1;
    u32 bit1:1;
    u32 bit0:1;
};

struct aiprocessnode_s {
    u8 pad0[0x2a];
    u8 field2a;
    u8 pad2b[0x2d];
};

struct aiprocesspath_s {
    u8 pad0[0x18];
    u8 updated[0x40];
    u8 inside[0x20];
    struct aiprocessnode_s *nodes;
};

struct aiprocesspacket_s {
    u8 pad0[4];
    void *script;
    void *state;
    u8 padc[0x74];
    struct aimovevec_s destination;
    f32 stopping;
    struct aimovevec_s result;
    f32 step;
    s16 node;
    u8 pada2[4];
    u8 creature;
    u8 fielda7;
    u8 pada8[0x54];
    u8 *locator;
    u8 pad100[0xc];
    struct aiprocesspath_s *path;
    u8 *connection;
    u32 field114;
    u32 flags118;
    u8 pad11c[8];
    struct aimovevec_s position;
    u8 pad130[8];
    void *field138;
    u8 pad13c[0x60];
    u32 field19c;
    union {
        u32 flags;
        struct aiprocessbits_s bits;
    };
    u32 flags1a4;
    f32 radius;
    u32 field1ac;
    u32 field1b0;
    u8 pad1b4[0xc];
    f32 timeOffPath;
};

struct aiprocessowner_s {
    u8 pad0[0x6c];
    struct aimovevec_s position;
    u8 pad78[0x190];
    u32 flags208;
    u32 flags20c;
    u8 pad210[0x72];
    s16 field282;
};

extern void AIPathNodeUpdatePos(void *, struct aiprocesspath_s *, struct aiprocessnode_s *);
extern void AISysGetCharacterPathPos(void *, void *, void *, s32, s32);
extern s32 fn_8007EBD0(void *, void *);
extern void AIScriptProcess(void *, void *, void *, void *, f32);
extern void fn_8008EAC4(void *, void *, void *, s32);
extern f32 NuVecDot(void *, void *);
extern f32 NuFdiv(f32, f32);
extern void NuVecSub(void *, void *, void *);
extern u8 lbl_8019C7D0[];
extern s32 (*lbl_80408D30)(void *);
extern s32 lbl_80408D50;

void AISysProcessCharacter(void *system, struct aiprocessowner_s *object,
    struct aiprocesspacket_s *packet, s32 checks, f32 elapsed, s32 use3d)
{
    struct aimovevec_s delta, movement;
    struct aiprocesspath_s *path;
    struct aiprocessnode_s *first, *second;
    struct aimovevec_s *position, *destination;
    f32 clearance, distance, step, stopping;
    u32 flags;

    if ((packet->flags & 0x20) || ((object->flags20c & 0x20000000) &&
        (packet->flags118 & 0x8000) && object->field282 == -1)) {
        path = packet->path;
        if (path && packet->connection) {
            u32 nodeIndex = packet->connection[0];
            first = &path->nodes[nodeIndex];
            second = &path->nodes[packet->connection[1]];
            if (first->field2a && !((path->updated[nodeIndex >> 3] >> (nodeIndex & 7)) & 1)) {
                AIPathNodeUpdatePos(system, path, first);
            }
            if (second->field2a && !((packet->path->updated[packet->connection[1] >> 3] >>
                (packet->connection[1] & 7)) & 1)) {
                AIPathNodeUpdatePos(system, packet->path, second);
            }
        }
        if (packet->node != -1 && packet->path) {
            s16 byteIndex = packet->node / 8;
            s16 bitIndex = packet->node % 8;
            packet->path->inside[byteIndex] |= 1 << bitIndex;
        }
        packet->timeOffPath = 0.0f;
    } else {
        if (packet->path) {
            if (object->flags20c & 0x2000) {
                AISysGetCharacterPathPos(system, object, packet, 0, checks);
            } else {
                AISysGetCharacterPathPos(system, object, packet, lbl_80408D50, checks);
            }
        } else {
            packet->position = object->position;
        }
        if (packet->flags118 & 0x8000) {
            packet->timeOffPath = 0.0f;
        } else {
            packet->timeOffPath += elapsed;
        }
    }
    flags = packet->flags & 0xefdff7df;
    packet->field19c = 0;
    packet->flags = flags;
    if (!packet->bits.initialized) {
        void *saved = packet->state;
        if (fn_8007EBD0(packet, lbl_8019C7D0)) {
            AIScriptProcess(system, object, packet, packet, 0.0f);
            fn_800838EC(packet, saved);
        }
        packet->flags |= 0x4000;
    }
    if ((object->flags20c & 0x1800000) == 0x1000000) {
        packet->fielda7 = 0;
        packet->field138 = 0;
        packet->destination = object->position;
        position = &object->position;
        destination = &packet->destination;
        packet->flags &= 0xfffff87f;
        packet->flags &= ~1;
        packet->flags1a4 &= 0x3fffffff;
    } else {
        if (lbl_80408D30 && lbl_80408D30(object)) return;
        if (system && packet->script) AIScriptProcess(system, object, packet, packet, elapsed);
        packet->field1b0 = 0;
        packet->flags &= 0xfffff87f;
        packet->bits.bit0 = 0;
        packet->flags1a4 &= 0x3fffffff;
        if (packet->bits.active) {
            switch (packet->bits.source) {
            case 1:
                if (packet->creature != 0xff) {
                    u8 *creature = *(u8 **)((u8 *)system + 0x14) + packet->creature * 0xa8;
                    AIMoveInstruction(packet, creature + 0x30, 0.0f, creature + 0x40, 1, 0.0f);
                }
                break;
            case 2:
                if (packet->locator) AIMoveInstruction(packet, packet->locator + 0x10, 0.0f, packet->locator + 0x20, 1, 0.0f);
                break;
            default: packet->flags &= ~4; break;
            }
        }
        fn_8008EAC4(system, packet, object, checks);
        if (((packet->flags >> 3) & 3) && !packet->field138 && packet->radius > 0.0f &&
            (object->flags208 & 0x400)) {
            struct aimovevec_s *source = 0;
            switch ((packet->flags >> 3) & 3) {
            case 1:
                source = (struct aimovevec_s *)(*(u8 **)((u8 *)system + 0x14) +
                    packet->creature * 0xa8 + 0x30);
                break;
            case 2:
                if (packet->locator) source = (struct aimovevec_s *)(packet->locator + 0x10);
                break;
            }
            position = &object->position;
            destination = &packet->destination;
            if (source) {
                distance = fn_8000CDFC(source, position, &delta);
                if (packet->flags & 4) {
                    if (distance < packet->radius * packet->radius) packet->flags &= ~4;
                } else {
                    f32 radius = packet->radius;
                    if (distance > radius * radius) {
                        f32 release = radius + 0.5f;
                        if (distance > release * release) packet->flags |= 4;
                        else {
                            f32 zero = 0.0f;
                            movement.x = packet->destination.x - object->position.x;
                            movement.y = zero;
                            movement.z = packet->destination.z - object->position.z;
                            if (NuVecDot(&movement, &delta) < zero) {
                                packet->destination = object->position;
                                packet->stopping = zero;
                            }
                        }
                    }
                }
            }
        }
    }
    position = &object->position;
    destination = &packet->destination;
    if (packet->stopping == 0.0f) clearance = 0.0f;
    else clearance = packet->step;
    if (use3d) {
        distance = NuVecDist(destination, position, &delta);
        step = packet->step;
        stopping = packet->stopping;
        if (distance > clearance + step + stopping) {
            NuVecScale(&delta, &delta, NuFdiv(step, distance));
            NuVecAdd(&packet->result, position, &delta);
        } else {
            NuVecScale(&delta, &delta, NuFdiv(clearance + stopping, distance));
            NuVecSub(&packet->result, destination, &delta);
        }
    } else {
        distance = NuVecXZDist(destination, position, &delta);
        step = packet->step;
        stopping = packet->stopping;
        if (distance > clearance + step + stopping) {
            NuVecScale(&delta, &delta, NuFdiv(step, distance));
            NuVecAdd(&packet->result, position, &delta);
        } else {
            NuVecScale(&delta, &delta, NuFdiv(clearance + stopping, distance));
            NuVecSub(&packet->result, destination, &delta);
        }
    }
}

extern s32 NuStrCmp(char *, char *);
extern f32 lbl_8019CAA8[];

struct aiscriptname_s { char unk0[0x18]; char *name; };
struct aiinterruptproc_s {
    char unk0[0x44];
    u8 priority;
    u8 id;
    char unk46[2];
    f32 value;
    struct aiscriptname_s *script;
};
void fn_8008F3D4(void *processArg, char *name)
{
    struct aiinterruptproc_s *process = processArg;
    if (process->script && NuStrCmp(name, process->script->name) == 0) {
        process->priority = 0;
        process->value = 0.0f;
        process->id = 0;
        process->script = 0;
    }
}

struct aiwslot_s {
    char unk0[0x8];
    u8 id;
    char unk9[0x47];
    u32 busy : 1;
    u32 flag1 : 1;
    u32 flag2 : 1;
    u32 pending : 1;
    u32 rest : 28;
    char unk54[0xd4];
    f32 pos[3];
};
struct aiwentry_s {
    char unk0[0x30];
    struct aiwslot_s slots[16];
};
struct aiwslot_s *fn_8008F180(struct aiwentry_s *sys, s32 id, f32 x, f32 y, f32 z)
{
    s32 i;
    struct aiwslot_s *slot;
    if (sys && id) {
        slot = sys->slots;
        for (i = 0; i < 16; i++, slot++) {
            if (!slot->busy) {
                sys->slots[i].busy = 1;
                slot->id = id;
                slot->pos[0] = x;
                slot->pos[1] = y;
                slot->pos[2] = z;
                slot->pending = 0;
                return slot;
            }
        }
    }
    return 0;
}

struct aiantinode_s {
    f32 pos[3];
    f32 radius;
    f32 minY;
    char unk14[4];
    f32 maxY;
    char unk1C[0x2c];
    u8 used;
    u8 flags;
    char unk4A[2];
};

struct aivec3_s { f32 x, y, z; };
extern struct aiantinode_s lbl_801BC3F8[16];
extern f32 lbl_80408CDC;

struct aiantinode_s *fn_8008EFD0(struct aivec3_s *pos, f32 radius)
{
    s32 i;
    for (i = 0; i < 16; i++) {
        struct aiantinode_s *node = &lbl_801BC3F8[i];
        if (!node->used) {
            memset(node, 0, 0x4c);
            node->used = 1;
            node->flags |= 1;
            *(struct aivec3_s *)node->pos = *pos;
            node->radius = radius;
            node->minY = node->pos[1] - lbl_80408CDC;
            node->maxY = node->pos[1] + lbl_80408CDC;
            return node;
        }
    }
    return 0;
}

struct aiwalkitem_s {
    char unk0[0x2d];
    u8 active;
    char unk2E[2];
    u32 flag0 : 1;
    u32 marked : 1;
    u32 rest : 30;
};
struct aiwalklist_s {
    u32 unk0;
    char unk4[2];
    u8 count;
    char unk7[0x49];
    u32 flag0 : 1;
    u32 flag1 : 1;
    u32 reverse : 1;
    u32 enabled : 1;
    u32 marked : 1;
    u32 rest : 27;
    struct aiwalkitem_s items[1];
};
typedef s32 (*aiwalkfn_t)(struct aiwalklist_s *, struct aiwalkitem_s *, struct aiwalkitem_s *, u32);
void fn_8008CDE8(struct aiwalklist_s *list, aiwalkfn_t fn)
{
    struct aiwalkitem_s *prev = 0;
    s32 marked = 0;
    s32 i;
    struct aiwalkitem_s *item;
    if (fn && list->enabled) {
        if (list->reverse) {
            for (i = list->count - 1; i >= 0; i--) {
                item = &list->items[i];
                if (item->active) {
                    if (fn(list, item, prev, list->unk0)) break;
                    if (item->marked) marked = 1;
                    prev = item;
                }
            }
        } else {
            for (i = 0; i < list->count; i++) {
                item = &list->items[i];
                if (item->active) {
                    if (fn(list, item, prev, list->unk0)) break;
                    if (item->marked) marked = 1;
                    prev = item;
                }
            }
        }
    }
    list->marked = marked;
}

struct aipathnode_s {
    char *name;
    u8 pad4[0x24];
    u8 count;
    u8 pad29[7];
    u8 **connections;
    u8 pad34[0x24];
};
struct aipath_s {
    u8 pad0[0x10];
    u8 count;
    u8 pad11[0x67];
    struct aipathnode_s *nodes;
};
struct aipathsys_s {
    u8 count;
    u8 pad1[7];
    struct aipath_s *active;
};
struct aisysroot_s {
    u8 pad0[0xc];
    struct aipathsys_s *paths;
};

static inline struct aipathnode_s *aiPathFindNode(struct aisysroot_s *sys, struct aipath_s *path, char *name)
{
    s32 i;
    if (!path) {
        if (sys && sys->paths && sys->paths->count) path = sys->paths->active;
    }
    if (path) {
        for (i = 0; i < path->count; i++) {
            if (path->nodes[i].name && NuStrICmp(path->nodes[i].name, name) == 0) return &path->nodes[i];
        }
    }
    return 0;
}

u8 *fn_8008A6D4(void *sysArg, void *pathArg, char *fromName, char *toName, s32 *direction)
{
    struct aisysroot_s *sys = sysArg;
    struct aipath_s *path = pathArg;
    struct aipathnode_s *from, *to;
    s32 index, i;

    if (!path) {
        if (sys && sys->paths && sys->paths->count) path = sys->paths->active;
    }
    if (path) {
        from = aiPathFindNode(sys, path, fromName);
        to = aiPathFindNode(sys, path, toName);
        if (from && to && from != to) {
            index = to - path->nodes;
            for (i = 0; i < from->count; i++) {
                if (from->connections[i][0] == index) {
                    *direction = 1;
                    return from->connections[i];
                }
                if (from->connections[i][1] == index) {
                    *direction = 0;
                    return from->connections[i];
                }
            }
        }
    }
    return 0;
}

struct aiscxcnx_s {
    u8 nodes[2];
    u8 pad2[2];
    u32 flags[2];
    u8 padc[8];
    s16 rotation;
    u16 mask;
    u8 pad18[4];
    f32 dist;
};
struct aiscxnode_s {
    char *name;
    f32 pos[3];
    u8 pad10[0x48];
};
struct aiscxpath_s {
    u8 pad0[0x14];
    u8 routecount;
    u8 pad15[0x63];
    struct aiscxnode_s *nodes;
};
struct aiscxpacket_s {
    u8 pad0[0x50];
    void *owner;
    u8 pad54[0x53];
    u8 state;
    u8 pada8[0x64];
    struct aiscxpath_s *path;
    struct aiscxcnx_s *connection;
    u8 direction;
    u8 pad115[3];
    u32 flags;
    f32 dist;
    f32 width;
    u8 pad124[0x44];
    u16 available;
    u8 route;
    u8 next;
    u8 pad16c[0x40];
    u32 caps;
};
struct aiscxvec_s { f32 x, y, z; };

static inline void aiSysFindRoute(struct aiscxpacket_s *packet)
{
    s32 route, first;

    if (!packet->path->routecount) return;
    if (!(packet->connection->mask & packet->available)) return;
    first = packet->next;
    if (first < 0 || first >= packet->path->routecount) first = 0;
    route = first;
    do {
        if ((s32)((u64)(packet->connection->mask & packet->available) >> route) & 1) {
            packet->route = route;
            packet->next = route + 1;
            return;
        }
        route++;
        if (route >= packet->path->routecount) route = 0;
    } while (route != first);
}

void AISysCharacterSetPathCnx(struct aiscxpacket_s *packet, f32 *position, struct aiscxcnx_s *cnx, s32 direction)
{
    struct aiscxvec_s rotated;
    struct aiscxvec_s delta;
    struct aiscxnode_s *node;
    u32 flags;

    if (cnx && packet->owner) {
        if (packet->connection == cnx && packet->direction == direction && (packet->flags & 0xa000) != 0x8000) return;
        flags = cnx->flags[direction];
        if (flags) {
            if (flags & 0x98000000) {
                aiSysFindRoute(packet);
                return;
            }
            if (!(flags & packet->caps)) return;
        }
        if (packet->connection != cnx || packet->direction != direction) {
            packet->direction = direction;
            packet->state = 0;
            packet->connection = cnx;
            node = &packet->path->nodes[cnx->nodes[0]];
            delta.x = position[0] - node->pos[0];
            delta.z = position[2] - node->pos[2];
            NuVecRotateY(&rotated, &delta, -cnx->rotation);
            packet->dist = rotated.z / cnx->dist;
            packet->width = rotated.x;
            packet->flags &= ~0x2000;
        }
        if ((packet->flags & 0xa000) == 0x8000) {
            if (packet->route != 0xff && !((s32)((u64)packet->connection->mask >> packet->route) & 1)) packet->route = 0xff;
            if (packet->route == 0xff) aiSysFindRoute(packet);
            packet->flags |= 0x2000;
        }
    } else {
        packet->connection = cnx;
        packet->route = 0xff;
        packet->next = 0;
    }
}

struct aiffpathinfo_s { u32 w[6]; };
struct aiffrow_s {
    struct aiffpathinfo_s info;
    f32 pos[3];
    s32 yrot;
    u8 pad28[0xc];
};
struct aiffgroup_s {
    u8 pad0[6];
    u8 rowcount;
    u8 pad7;
    u8 across;
    u8 pad9[0x47];
    u32 flags;
    struct aiffrow_s rows[1];
    u8 pad88[0xa0];
    f32 spacing;
};
struct aiffmove_s {
    u32 mode : 3;
    u32 follow : 1;
    u32 pad : 28;
};
struct aiffpacket_s {
    u8 pad0[0xc0];
    f32 actionpos[3];
    u8 padcc[0x24];
    struct aiffgroup_s *group;
    u8 padf4;
    u8 column;
    u8 row;
    u8 padf7[0x79];
    f32 dest[3];
    f32 stopping;
    f32 param;
    struct aiffpathinfo_s info;
    f32 *look;
    union { u32 flags; struct aiffmove_s move; } m;
};
struct aiffvec_s { f32 x, y, z; };


static inline void aiFFMoveInstruction(struct aiffpacket_s *packet, struct aiffvec_s *destination, f32 stopping, struct aiffpathinfo_s *info, s32 mode, f32 param)
{
    struct aiffgroup_s *group = packet->group;
    if (group && (group->flags & 0x10000000)) {
        if (mode == 5) mode = 1;
    }
    if (destination) *(struct aiffvec_s *)packet->dest = *destination;
    if (info) packet->info = *info;
    packet->stopping = stopping;
    packet->m.move.mode = mode;
    packet->param = param;
}

void AIFormationFollow(struct aiffpacket_s *packet)
{
    struct aiffgroup_s *group = packet->group;
    struct aiffrow_s *row;
    u8 column;
    struct aiffvec_s destination;
    struct aiffvec_s offset;
    f32 colOffset;
    s32 half;

    if (packet->row < group->rowcount) {
        row = &group->rows[packet->row];
        half = (packet->column + 1) / 2;
        column = packet->column;
        if (packet->m.flags & 0x40) {
            if (group->across & 1) offset.x = 0.0f; else offset.x = -(group->spacing * 0.5f);
            if (packet->group->flags & 0x20000000) offset.x = -offset.x;
        } else {
            colOffset = group->spacing * half;
            offset.x = (column & 1) ? -colOffset : colOffset;
            if (packet->group->flags & 0x20000000) offset.x = -offset.x;
        }
        offset.y = 0.0f;
        offset.z = 0.0f;
        NuVecRotateY(&offset, &offset, row->yrot);
        NuVecAdd(&destination, &offset, row->pos);
        packet->m.move.follow = 1;
        aiFFMoveInstruction(packet, &destination, 0.0f, &row->info, 5, 0.0f);
        packet->actionpos[0] = 0.0f;
        packet->actionpos[1] = 0.0f;
        packet->actionpos[2] = 100.0f;
        NuVecRotateY(packet->actionpos, packet->actionpos, row->yrot);
        NuVecAdd(packet->actionpos, packet->actionpos, row->pos);
        packet->look = packet->actionpos;
    }
}

struct aiupdcnx_s {
    u8 nodes[2];
    u8 pad2[2];
    u32 flags[2];
    u8 padc[8];
    s16 rotation;
    u16 mask;
    u8 pad18[4];
    f32 dist;
    u8 pad20[4];
    f32 maxdist;
};
struct aiupdnode_s {
    char *name;
    f32 pos[3];
    f32 radius;
    u8 pad14[4];
    f32 minh;
    f32 minoff;
    f32 maxh;
    f32 maxoff;
    u8 count;
    u8 pad29;
    u8 special;
    u8 flags;
    u8 pad2c[4];
    struct aiupdcnx_s **connections;
    u8 pad34[8];
    u8 handle[0xc];
    f32 spos[3];
    u8 pad54[4];
};
struct aiupdpath_s {
    u8 pad0[0x18];
    u8 updated[0x60];
    struct aiupdnode_s *nodes;
};
struct aiupdvec_s { f32 x, y, z; };
struct aiupdanim_s { u8 pad0[0x40]; f32 speed; u8 pad44[0xc]; s32 flags; };

extern s32 fn_800131B8(void *);
extern void *fn_800133FC(void *);
extern struct aiupdanim_s *fn_8001384C(void *);
extern void NuVecMtxTransform(void *, void *, void *);
extern f32 NuAtan2(f32, f32);

void AIPathNodeUpdatePos(void *system, struct aiprocesspath_s *pathArg, struct aiprocessnode_s *nodeArg)
{
    struct aiupdpath_s *path = (struct aiupdpath_s *)pathArg;
    struct aiupdnode_s *node = (struct aiupdnode_s *)nodeArg;
    struct aiupdnode_s *other;
    struct aiupdcnx_s *cnx;
    struct aiupdvec_s prev;
    struct aiupdvec_s dir;
    struct aiupdanim_s *anim;
    void *mtx;
    s32 index;
    s32 i;
    if (node->special) {
        index = node - path->nodes;
        if (!((path->updated[index / 8] >> (index % 8)) & 1)) {
            path->updated[index / 8] |= 1 << (index % 8);
            if (node->flags & 4) {
                if (!fn_800131B8(node->handle)) {
                    return;
                }
                node->flags &= ~4;
                for (i = 0; i < node->count; i++) {
                    cnx = node->connections[i];
                    if (cnx->nodes[0] == index) {
                        other = &path->nodes[cnx->nodes[1]];
                    } else {
                        other = &path->nodes[cnx->nodes[0]];
                    }
                    if (!(other->flags & 4)) {
                        cnx->flags[0] &= ~0x10000000;
                        cnx->flags[1] &= ~0x10000000;
                    }
                }
            } else if (!fn_800131B8(node->handle)) {
                if ((!lbl_80408D4C) || (!((s32 (*)(void *, void *))lbl_80408D4C)(system, node->handle))) {
                    node->flags |= 4;
                    for (i = 0; i < node->count; i++) {
                        cnx = node->connections[i];
                        cnx->flags[0] |= 0x10000000;
                        cnx->flags[1] |= 0x10000000;
                    }

                    return;
                }
            }
            prev = *((struct aiupdvec_s *)node->pos);
            mtx = fn_800133FC(node->handle);
            NuVecMtxTransform(node->pos, node->spos, mtx);
            node->minh = node->pos[1] + node->minoff;
            node->maxh = node->pos[1] + node->maxoff;
            for (i = 0; i < node->count; i++) {
                cnx = node->connections[i];
                if (cnx->nodes[0] == index) {
                    other = &path->nodes[cnx->nodes[1]];
                    cnx->dist = NuVecXZDist(other->pos, node->pos, &dir);
                    cnx->rotation = NuAtan2(dir.x, dir.z) * 10430.378f;
                } else {
                    other = &path->nodes[cnx->nodes[0]];
                    cnx->dist = NuVecXZDist(node->pos, other->pos, &dir);
                    cnx->rotation = NuAtan2(dir.x, dir.z) * 10430.378f;
                }
                if (cnx->maxdist != 0.0f) {
                    if (cnx->dist > ((cnx->maxdist + node->radius) + other->radius)) {
                        cnx->flags[0] |= 0x08000000;
                        cnx->flags[1] |= 0x08000000;
                    } else {
                        cnx->flags[0] &= ~0x08000000;
                        cnx->flags[1] &= ~0x08000000;
                    }
                }
            }

            if (((node->pos[0] != prev.x) || (node->pos[1] != prev.y)) || (node->pos[2] != prev.z)) {
                node->flags |= 2;
            } else if (((anim = fn_8001384C(node->handle)) && (anim->flags < 0)) && (anim->speed != 0.0f)) {
                node->flags |= 2;
            } else {
                node->flags &= ~2;
            }
        }
    }
}

struct aire2vec_s { f32 x, y, z; };
struct aire2info_s { u32 w[6]; };
struct aire2object_s { u8 pad0[0x6c]; struct aire2vec_s position; };
struct aire2packet_s {
    u8 pad0[0x80];
    struct aire2vec_s dest;
    f32 stopping;
    u8 pad90[0x7c];
    struct aire2info_s info;
    struct aire2vec_s pathpos;
    u8 pad130[0x40];
    struct aire2vec_s fallback;
    u8 pad17c[4];
    f32 param;
};

void fn_8008E494(void *system, struct aire2packet_s *packet, struct aire2object_s *object, s32 checks)
{
    struct aire2vec_s difference;
    f32 distance;
    struct aire2info_s info;
    struct aire2vec_s position;
    struct aire2vec_s pathpos;

    distance = NuVecXZDist(&object->position, &packet->fallback, &difference);
    if (distance == 0.0f) {
        difference.x = packet->param;
        difference.y = 0.0f;
        difference.z = 0.0f;
    } else {
        NuVecScale(&difference, &difference, packet->param / distance);
    }
    NuVecAdd(&packet->dest, &packet->fallback, &difference);
    packet->stopping = 0.0f;
    info = packet->info;
    position = object->position;
    pathpos = packet->pathpos;
    object->position = packet->dest;
    AISysGetCharacterPathPos(system, object, packet, 0, 1);
    packet->dest = packet->pathpos;
    packet->info = info;
    object->position = position;
    packet->pathpos = pathpos;
}

struct aiinscnx_s { u8 nodes[2]; u8 pad2[0x12]; s16 rotation; };
struct aiinsnode_s { u8 pad0[4]; f32 pos[3]; u8 pad10[0x48]; };
struct aiinspath_s { u8 pad0[0x78]; struct aiinsnode_s *nodes; };
struct aiinsobject_s { u8 pad0[0x291]; u8 field291; };
struct aiinsflags_s { u32 pad0 : 5; u32 right : 1; u32 left : 1; u32 pad7 : 25; };
struct aiinspacket_s {
    u8 pad0[0x10c];
    struct aiinspath_s *path;
    u8 pad110[0x34];
    struct aiinscnx_s *cnx;
    struct aiinscnx_s *target;
    u8 right[0xc];
    u8 left[0xc];
    u8 pad164[6];
    u8 route;
    u8 pad16b[0x35];
    union { u32 flags; struct aiinsflags_s bits; } m;
};

extern s32 fn_8008ACD8(void *, f32 *, struct aiinspath_s *, struct aiinscnx_s *, s32, struct aiinscnx_s *, u8, u8, void *, f32, void *);
extern u32 fn_8008BA28(struct aiinsobject_s *, struct aiinscnx_s *, struct aiinscnx_s *, s32, s32, struct aiinsnode_s *, struct aiinsnode_s *, struct aiinsnode_s *, void *);

u32 fn_8008BCC0(void *system, struct aiinspacket_s *packet, struct aiinsobject_s *object, struct aiinscnx_s *cnx, struct aiinscnx_s *target)
{
    struct aiinspath_s *path;
    struct aiinsnode_s *before;
    struct aiinsnode_s *shared;
    struct aiinsnode_s *after;
    s32 first;
    s32 second;

    if (cnx == packet->cnx && target == packet->target) {
        return packet->m.bits.right | packet->m.bits.left;
    }
    {
        packet->m.flags &= ~0x06000000;
        packet->cnx = cnx;
        packet->target = target;
        path = packet->path;
        if (cnx->nodes[0] == target->nodes[0]) {
            before = &path->nodes[cnx->nodes[1]];
            shared = &path->nodes[cnx->nodes[0]];
            after = &path->nodes[target->nodes[1]];
            first = NuAngAdd(cnx->rotation, 0x8000);
            second = NuAngAdd(target->rotation, 0x8000);
        } else if (cnx->nodes[0] == target->nodes[1]) {
            before = &path->nodes[cnx->nodes[1]];
            shared = &path->nodes[cnx->nodes[0]];
            after = &path->nodes[target->nodes[0]];
            first = NuAngAdd(cnx->rotation, 0x8000);
            second = target->rotation;
        } else if (cnx->nodes[1] == target->nodes[0]) {
            before = &path->nodes[cnx->nodes[0]];
            shared = &path->nodes[cnx->nodes[1]];
            after = &path->nodes[target->nodes[1]];
            first = cnx->rotation;
            second = NuAngAdd(target->rotation, 0x8000);
        } else if (cnx->nodes[1] == target->nodes[1]) {
            before = &path->nodes[cnx->nodes[0]];
            shared = &path->nodes[cnx->nodes[1]];
            after = &path->nodes[target->nodes[0]];
            first = cnx->rotation;
            second = target->rotation;
        } else {
            return 0;
        }
        if (fn_8008ACD8(system, after->pos, path, cnx, 1, cnx, packet->route, object->field291, 0, 0.0f, 0)) {
            return 0;
        }
        packet->m.bits.right = fn_8008BA28(object, cnx, target, first, second, before, shared, after, packet->right);
        packet->m.bits.left = fn_8008BA28(object, target, cnx, second, first, after, shared, before, packet->left);
    }
    return packet->m.bits.right | packet->m.bits.left;
}

struct aiinsvec_s { f32 x, y, z; };
struct aiinsobjrad_s { u8 pad0[0xbc]; f32 radius; };
struct aiinscnxd_s { u8 pad0[0x1c]; f32 dist; };
struct aiinsnoder_s { u8 pad0[4]; struct aiinsvec_s pos; f32 radius; };

extern f32 lbl_80408D5C;
extern s32 fn_8000AEC4(f32);
extern s32 NuMtlGet3dBuffer(void *, void *, void *, void *, f32 *, f32 *);

u32 fn_8008BA28(struct aiinsobject_s *objectArg, struct aiinscnx_s *cnxArg, struct aiinscnx_s *targetArg, s32 first, s32 second, struct aiinsnode_s *beforeArg, struct aiinsnode_s *sharedArg, struct aiinsnode_s *afterArg, void *result)
{
    struct aiinsobjrad_s *object = (struct aiinsobjrad_s *)objectArg;
    struct aiinscnxd_s *cnx = (struct aiinscnxd_s *)cnxArg;
    struct aiinscnxd_s *target = (struct aiinscnxd_s *)targetArg;
    struct aiinsnoder_s *before = (struct aiinsnoder_s *)beforeArg;
    struct aiinsnoder_s *shared = (struct aiinsnoder_s *)sharedArg;
    struct aiinsnoder_s *after = (struct aiinsnoder_s *)afterArg;
    struct aiinsvec_s firstStart;
    struct aiinsvec_s firstEnd;
    struct aiinsvec_s secondStart;
    struct aiinsvec_s secondEnd;
    struct aiinsvec_s firstOrigin;
    struct aiinsvec_s firstDir;
    struct aiinsvec_s secondOrigin;
    struct aiinsvec_s secondDir;
    f32 firstParam;
    f32 secondParam;
    f32 clearance;
    f32 beforeRadius;
    f32 sharedRadius;
    f32 afterRadius;
    s32 angle;

    clearance = object->radius + lbl_80408D5C;
    beforeRadius = before->radius - clearance;
    if (beforeRadius < 0.0f) {
        beforeRadius = 0.0f;
    }
    sharedRadius = shared->radius - clearance;
    if (sharedRadius < 0.0f) {
        sharedRadius = 0.0f;
    }
    afterRadius = after->radius - clearance;
    if (afterRadius < 0.0f) {
        afterRadius = 0.0f;
    }
    firstStart.x = beforeRadius;
    firstStart.y = 0.0f;
    firstStart.z = 0.0f;
    firstEnd.x = beforeRadius;
    firstEnd.y = 0.0f;
    firstEnd.z = cnx->dist;
    angle = NuAngAdd(first, fn_8000AEC4((sharedRadius - beforeRadius) / cnx->dist));
    NuVecRotateY(&firstStart, &firstStart, angle);
    NuVecRotateY(&firstEnd, &firstEnd, angle);
    NuVecAdd(&firstStart, &firstStart, &before->pos);
    NuVecAdd(&firstEnd, &firstEnd, &before->pos);
    secondStart.x = -afterRadius;
    secondStart.y = 0.0f;
    secondStart.z = 0.0f;
    secondEnd.x = -afterRadius;
    secondEnd.y = 0.0f;
    secondEnd.z = target->dist;
    angle = NuAngSub(second, fn_8000AEC4((sharedRadius - afterRadius) / target->dist));
    NuVecRotateY(&secondStart, &secondStart, angle);
    NuVecRotateY(&secondEnd, &secondEnd, angle);
    NuVecAdd(&secondStart, &secondStart, &after->pos);
    NuVecAdd(&secondEnd, &secondEnd, &after->pos);
    firstOrigin = firstStart;
    NuVecSub(&firstDir, &firstEnd, &firstOrigin);
    secondOrigin = secondStart;
    NuVecSub(&secondDir, &secondEnd, &secondOrigin);
    if (NuMtlGet3dBuffer(&firstOrigin, &firstDir, &secondOrigin, &secondDir, &firstParam, &secondParam) && firstParam >= 0.0f && secondParam >= 0.0f && firstParam <= 1.0f && secondParam <= 1.0f) {
        NuVecScale(&firstDir, &firstDir, firstParam);
        NuVecAdd(result, &firstOrigin, &firstDir);
        return 1;
    }
    return 0;
}

struct aigpcnx_s { u8 nodes[2]; };
struct aigpnode_s { u8 pad0[0x28]; u8 count; u8 pad29[7]; struct aigpcnx_s **connections; u8 pad34[0x24]; };
struct aigppath_s { u8 pad0[0x10]; u8 count; u8 pad11[0x67]; struct aigpnode_s *nodes; };
struct aigpinfo_s {
    struct aigppath_s *path;
    struct aigpcnx_s *cnx;
    u8 direction;
    u8 pad9[3];
    u32 next : 16;
    u32 onpath : 1;
    u32 pad : 15;
};
struct aigppathsys_s { u8 count; u8 pad1[7]; struct aigppath_s *active; };
struct aigpsys_s { u8 pad0[0xc]; struct aigppathsys_s *pathsys; };
struct aigcflags_s {
    u32 next : 16;
    u32 onpath : 1;
    u32 wasonpath : 1;
    u32 bit2 : 1;
    u32 bit3 : 1;
    u32 pad : 12;
};
struct aigcpacket_s {
    u8 pad0[0xa7];
    u8 state;
    u8 pada8[0x64];
    struct aigppath_s *path;
    struct aigpcnx_s *cnx;
    u8 direction;
    u8 pad115[3];
    struct aigcflags_s flags;
    u8 pad11c[0x1c];
    s32 target;
};
struct aigcobject_s {
    u8 pad0[0x6c];
    f32 pos[3];
    u8 pad78[0x194];
    u32 flags;
};
extern s32 AISysCharacterTestPathCnx(struct aigpsys_s *, struct aigcobject_s *, struct aigcpacket_s *, struct aigpcnx_s *, s32, f32 *, u8 *);
extern f32 lbl_8019C850[];

static inline void aiClearChecked(u8 *buf)
{
    memset(buf, 0, 0x1fe0);
}

void AISysGetCharacterPathPos(void *systemArg, void *objectArg, void *packetArg, s32 checks, s32 adjacent)
{
    struct aigpsys_s *system = systemArg;
    struct aigcobject_s *object = objectArg;
    struct aigcpacket_s *packet = packetArg;
    u8 checked[0x1fe0];
    f32 distance;
    struct aigppath_s *path;
    struct aigpcnx_s *current;
    struct aigpcnx_s *cnx;
    struct aigpnode_s *node;
    u8 direction;
    u8 other;
    s32 dir;
    s32 i;
    s32 remaining;

    aiClearChecked(checked);
    distance = lbl_8019C850[0];
    packet->flags.wasonpath = packet->flags.onpath;
    packet->flags.onpath = 0;
    packet->flags.bit3 = 0;
    if (system && system->pathsys && system->pathsys->count) {
        path = packet->path;
        if (!path) {
            AISysCharacterSetPath(packet, system->pathsys->active);
            AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, object->pos, 0, 0);
            packet->flags.next = (s32)path;
        }
        current = packet->cnx;
        if (current) {
            direction = packet->direction;
            if (AISysCharacterTestPathCnx(system, object, packet, current, direction, &distance, checked)) {
                return;
            }
            if (!(object->flags & 0x01000000) && (packet->target || packet->state || !adjacent)) {
                return;
            }
            node = &packet->path->nodes[current->nodes[direction]];
            for (i = 0; i < node->count; i++) {
                cnx = node->connections[i];
                if (cnx != current) {
                    dir = 1;
                    if (cnx->nodes[0] == current->nodes[direction]) {
                        dir = 0;
                    }
                    if (AISysCharacterTestPathCnx(system, object, packet, cnx, dir, &distance, checked)) {
                        return;
                    }
                }
            }
            node = &packet->path->nodes[current->nodes[direction == 0]];
            for (i = 0; i < node->count; i++) {
                cnx = node->connections[i];
                if (cnx != current) {
                    dir = 1;
                    if (cnx->nodes[0] == current->nodes[direction == 0]) {
                        dir = 0;
                    }
                    if (AISysCharacterTestPathCnx(system, object, packet, cnx, dir, &distance, checked)) {
                        return;
                    }
                }
            }
        }
        remaining = checks;
        if (remaining > packet->path->count) {
            remaining = packet->path->count;
        }
        while (remaining) {
            node = &packet->path->nodes[packet->flags.next];
            for (i = 0; i < node->count; i++) {
                if (AISysCharacterTestPathCnx(system, object, packet, node->connections[i], -1, &distance, checked)) {
                    return;
                }
            }
            remaining--;
            packet->flags.next = (packet->flags.next + 1) % packet->path->count;
        }
    } else {
        packet->flags.onpath = 0;
        AISysCharacterSetPath(packet, 0);
        AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, object->pos, 0, 0);
    }
}

void fn_8008B4D8(struct aigpsys_s *system, f32 *pos, struct aigpinfo_s *info, struct aigppath_s *path, s32 checks)
{
    u8 checked[0x1fe0];
    struct aigpcnx_s *current;
    struct aigpnode_s *node;
    s32 i;
    s32 remaining;
    s32 zero;

    aiClearChecked(checked);
    info->onpath = 0;
    if (system && system->pathsys && system->pathsys->count) {
        if (!path) {
            path = system->pathsys->active;
        }
        if (info->path != path) {
            zero = 0;
            info->path = path;
            info->cnx = (void *)zero;
            info->next = zero;
        }
        current = info->cnx;
        if (current) {
            if (fn_8008ACD8(system, pos, (struct aiinspath_s *)path, (struct aiinscnx_s *)current, 1, 0, 0xff, 0xff, info, 0.0f, checked)) {
                return;
            }
            node = &info->path->nodes[current->nodes[info->direction]];
            for (i = 0; i < node->count; i++) {
                if (node->connections[i] != current && fn_8008ACD8(system, pos, (struct aiinspath_s *)path, (struct aiinscnx_s *)node->connections[i], 1, 0, 0xff, 0xff, info, 0.0f, checked)) {
                    return;
                }
            }
            node = &info->path->nodes[current->nodes[info->direction == 0]];
            for (i = 0; i < node->count; i++) {
                if (node->connections[i] != current && fn_8008ACD8(system, pos, (struct aiinspath_s *)path, (struct aiinscnx_s *)node->connections[i], 1, 0, 0xff, 0xff, info, 0.0f, checked)) {
                    return;
                }
            }
        }
        remaining = checks;
        if (remaining > info->path->count) {
            remaining = info->path->count;
        }
        while (remaining) {
            node = &info->path->nodes[info->next];
            for (i = 0; i < node->count; i++) {
                if (fn_8008ACD8(system, pos, (struct aiinspath_s *)path, (struct aiinscnx_s *)node->connections[i], 1, 0, 0xff, 0xff, info, 0.0f, checked)) {
                    return;
                }
            }
            info->next = (info->next + 1) % info->path->count;
            remaining--;
        }
    }
}

struct aimvvec_s { f32 x, y, z; };
struct aimvobject_s { u8 pad0[0x6c]; struct aimvvec_s position; };
struct aimvpacket_s {
    u8 pad0[0x80];
    struct aimvvec_s dest;
    f32 stopping;
    u8 pad90[0x7c];
    void *path;
    void *cnx;
    u8 pad114[4];
    u32 pathflags;
    u8 pad11c[0x54];
    struct aimvvec_s fallback;
    f32 fallbackstop;
    f32 param;
    u8 pad184[0x1c];
    u32 flags;
    u32 flags2;
};
extern s32 (*lbl_80408DA0)(void *, struct aimvpacket_s *, struct aimvobject_s *);
extern s32 lbl_80408D68;
extern void fn_8008CF0C(void *, struct aimvpacket_s *, struct aimvobject_s *, s32);
extern void fn_8008DCE0(void *, struct aimvpacket_s *, struct aimvobject_s *, s32);
extern void fn_8008E650(void *, struct aimvpacket_s *, struct aimvobject_s *, s32);

static inline void aiMoveAvoidingCamera(void *system, struct aimvpacket_s *packet, struct aimvobject_s *object, s32 checks)
{
    struct aimvvec_s saved;

    saved = packet->fallback;
    fn_8008CF0C(system, packet, object, checks);
    packet->fallback = saved;
}

static inline void aiRetreat(void *system, struct aimvpacket_s *packet, struct aimvobject_s *object, s32 checks)
{
    struct aimvvec_s diff;
    f32 distance;

    if (lbl_80408D68) {
        fn_8008E494(system, (struct aire2packet_s *)packet, (struct aire2object_s *)object, checks);
        return;
    }
    if (packet->pathflags & 0x8000) {
        distance = NuVecXZDist(&object->position, &packet->fallback, &diff);
        if (distance == 0.0f) {
            diff.x = packet->param;
            diff.y = 0.0f;
            diff.z = 0.0f;
        } else {
            NuVecScale(&diff, &diff, packet->param / distance);
        }
        NuVecAdd(&packet->dest, &object->position, &diff);
        packet->stopping = 0.0f;
        return;
    }
    fn_8008DCE0(system, packet, object, checks);
}

static inline void aiCircle(void *system, struct aimvpacket_s *packet, struct aimvobject_s *object, s32 checks)
{
    f32 radius;
    struct aimvvec_s diff;
    s32 angle;
    struct aimvvec_s circle;

    radius = packet->param < packet->fallbackstop ? packet->fallbackstop : packet->param;
    NuVecSub(&diff, &object->position, &packet->fallback);
    angle = fn_8000ABDC(diff.x, diff.z);
    diff.x = 0.0f;
    diff.z = radius;
    NuVecRotateY(&diff, &diff, angle);
    NuVecAdd(&circle, &packet->fallback, &diff);
    if (packet->flags & 0x400000) {
        angle = NuAngSub(angle, 0x4000);
    } else {
        angle = NuAngAdd(angle, 0x4000);
    }
    diff.x = 0.0f;
    diff.y = 0.0f;
    diff.z = 0.5f;
    NuVecRotateY(&diff, &diff, angle);
    NuVecAdd(&packet->dest, &circle, &diff);
    packet->flags |= 0x200000;
    packet->stopping = 0.0f;
}

void fn_8008EAC4(void *system, void *packetArg, void *objectArg, s32 checks)
{
    struct aimvpacket_s *packet = packetArg;
    struct aimvobject_s *object = objectArg;

    packet->flags &= ~2;
    if (lbl_80408DA0 && lbl_80408DA0(system, packet, object)) {
        packet->flags |= 0x800;
        packet->flags2 |= 0x80000000;
        return;
    }
    if (!packet->path || !packet->cnx) {
        packet->dest = object->position;
        packet->stopping = 0.0f;
        if ((packet->flags >> 29) == 1) {
            packet->dest = packet->fallback;
            packet->stopping = packet->fallbackstop;
        }
        return;
    }
    packet->dest = object->position;
    packet->stopping = 0.0f;
    switch ((s32)(packet->flags >> 29)) {
    case 0:
        break;
    case 1:
        fn_8008CF0C(system, packet, object, checks);
        break;
    case 6:
        aiMoveAvoidingCamera(system, packet, object, checks);
        break;
    case 2:
        aiRetreat(system, packet, object, checks);
        break;
    case 3:
        aiCircle(system, packet, object, checks);
        break;
    case 4:
        fn_8008E650(system, packet, object, checks);
        break;
    }
    packet->flags &= 0x1fffffff;
}

struct aiwdvec_s { f32 x, y, z; };
struct aiwdcnx_s {
    u8 nodes[2];
    u8 pad2[2];
    s32 blocked[2];
    u8 padc[8];
    s16 rotation;
    u16 routemask;
};
struct aiwdnode_s {
    u8 pad0[4];
    struct aiwdvec_s position;
    f32 approachRadius;
    f32 radiusSquared;
    u8 pad18[0x10];
    u8 count;
    u8 pad29[7];
    struct aiwdcnx_s **connections;
    u8 pad34[0x22];
    u16 boundarymask;
};
struct aiwdpath_s {
    u8 pad0[0x78];
    struct aiwdnode_s *nodes;
    u8 pad7c[4];
    u8 **routeTable;
};
struct aiwdpacket_s {
    u8 pad0[0x80];
    struct aiwdvec_s dest;
    f32 stopping;
    u8 pad90[0x67];
    u8 targetdir;
    u8 padf8[8];
    struct aiwdvec_s terrain;
    struct aiwdpath_s *path;
    struct aiwdcnx_s *cnx;
    u8 direction;
    u8 pad115[0x1b];
    struct aiwdnode_s *goal;
    u8 pad134[8];
    struct aiwdcnx_s *target;
    u8 pad140[0xc];
    struct aiwdvec_s right;
    struct aiwdvec_s left;
    u8 pad164[6];
    u8 route;
    u8 pad16b[0x35];
    u32 flags;
};
struct aiwdobject_s {
    u8 pad0[0x6c];
    struct aiwdvec_s position;
    u8 pad78[0x44];
    f32 radius;
    u8 padc0[0x1d1];
    u8 field291;
};
extern u32 NuRandInt(void);

void fn_8008E650(void *system, struct aimvpacket_s *packetArg, struct aimvobject_s *objectArg, s32 checks)
{
    struct aiwdpacket_s *packet = (struct aiwdpacket_s *)packetArg;
    struct aiwdobject_s *object = (struct aiwdobject_s *)objectArg;
    struct aiwdvec_s diff;
    struct aiwdnode_s *node;
    struct aiwdcnx_s *target;
    s32 index;
    s32 start;
    s32 i;
    s32 angle;
    s32 done;

    if (packet->target) {
        index = packet->cnx->nodes[packet->direction == 0];
        if (packet->target->nodes[0] != index && packet->target->nodes[1] != index) {
            packet->target = 0;
        }
    }
    if (!packet->target) {
        index = packet->cnx->nodes[packet->direction == 0];
        node = &packet->path->nodes[index];
        start = NuRandInt() % node->count;
        for (i = 0; i < node->count; i++) {
            packet->target = target = node->connections[(i + start) % node->count];
            if (target != packet->cnx) {
                if (packet->route == 0xff || ((s32)((u64)target->routemask >> packet->route) & 1) ||
                    ((s32)((u64)node->boundarymask >> packet->route) & 1)) {
                    if (packet->target->nodes[0] == index) {
                        packet->targetdir = 0;
                    } else {
                        packet->targetdir = 1;
                    }
                    if (!packet->target->blocked[packet->targetdir]) {
                        break;
                    }
                }
            }
            packet->target = 0;
        }
    }
    if (packet->target) {
        packet->flags |= 0x800;
        if (fn_8008ACD8(system, (f32 *)&packet->terrain, (struct aiinspath_s *)packet->path, (struct aiinscnx_s *)packet->target, checks,
                        (struct aiinscnx_s *)packet->cnx, packet->route, object->field291, 0, object->radius, 0)) {
            AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position, (struct aiscxcnx_s *)packet->target, packet->targetdir);
            index = packet->cnx->nodes[packet->direction == 0];
            packet->goal = &packet->path->nodes[index];
            packet->dest = packet->goal->position;
            packet->stopping = 0.0f;
            packet->target = 0;
        } else {
            index = packet->target->nodes[packet->targetdir == 0];
            node = &packet->path->nodes[index];
            packet->dest = node->position;
            packet->stopping = 0.0f;
            if (fn_8008BCC0(system, (struct aiinspacket_s *)packet, (struct aiinsobject_s *)object, (struct aiinscnx_s *)packet->cnx, (struct aiinscnx_s *)packet->target)) {
                done = 0;
                if (packet->flags & 0x02000000) {
                    NuVecSub(&diff, &packet->left, &object->position);
                    angle = fn_8000ABDC(diff.x, diff.z);
                    NuVecSub(&diff, &packet->dest, &object->position);
                    if (NuAngSub(fn_8000ABDC(diff.x, diff.z), angle) < 0) {
                        packet->dest = packet->left;
                        done = 1;
                    }
                }
                if (!done && (packet->flags & 0x04000000)) {
                    NuVecSub(&diff, &packet->right, &object->position);
                    angle = fn_8000ABDC(diff.x, diff.z);
                    NuVecSub(&diff, &packet->dest, &object->position);
                    if (NuAngSub(fn_8000ABDC(diff.x, diff.z), angle) > 0) {
                        packet->dest = packet->right;
                    }
                }
            }
        }
    } else {
        index = packet->cnx->nodes[packet->direction == 0];
        node = &packet->path->nodes[index];
        if (fn_8000CDFC(&object->position, &node->position, &diff) < node->radiusSquared) {
            AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position, (struct aiscxcnx_s *)packet->cnx, packet->direction == 0);
            index = packet->cnx->nodes[packet->direction == 0];
            node = &packet->path->nodes[index];
            packet->goal = node;
        }
        packet->dest = node->position;
        packet->stopping = 0.0f;
    }
}

struct airtvec_s { f32 x, y, z; };
struct airtcnx_s {
    u8 nodes[2];
    u8 pad2[2];
    u32 blocked[2];
    u8 padc[0xa];
    u16 routemask;
    f32 distance;
};
struct airtnode_s {
    u8 pad0[4];
    struct airtvec_s position;
    u8 pad10[0x18];
    u8 count;
    u8 pad29[7];
    struct airtcnx_s **connections;
    u8 pad34[0x20];
    u16 membership;
    u16 boundary;
};
struct airtpath_s { u8 pad0[0x78]; struct airtnode_s *nodes; };
struct airtpacket_s {
    u8 pad0[0x80];
    struct airtvec_s dest;
    f32 stopping;
    u8 pad90[0x67];
    u8 targetdir;
    u8 padf8[8];
    struct airtvec_s terrain;
    struct airtpath_s *path;
    struct airtcnx_s *cnx;
    u8 direction;
    u8 pad115[7];
    f32 dist;
    u8 pad120[0x10];
    struct airtnode_s *goal;
    u8 pad134[8];
    struct airtcnx_s *target;
    u8 pad140[0xc];
    struct airtvec_s right;
    struct airtvec_s left;
    u8 pad164[6];
    u8 route;
    u8 pad16b[0x19];
    struct airtpath_s *fpath;
    struct airtcnx_s *fcnx;
    u8 pad18c[8];
    f32 fdist;
    u8 pad198[8];
    u32 flags;
};
struct airtobject_s {
    u8 pad0[0x6c];
    struct airtvec_s position;
    u8 pad78[0x44];
    f32 radius;
    u8 padc0[0x1d1];
    u8 field291;
};
extern f32 fn_8008A370(struct airtpath_s *, s32, s32, s32, s32);

void fn_8008DCE0(void *system, struct aimvpacket_s *packetArg, struct aimvobject_s *objectArg, s32 checks)
{
    struct airtpacket_s *packet = (struct airtpacket_s *)packetArg;
    struct airtobject_s *object = (struct airtobject_s *)objectArg;
    struct airtvec_s diff;
    struct airtvec_s *pos;
    struct airtpath_s *path;
    struct airtcnx_s *cnx;
    struct airtcnx_s *dcnx;
    struct airtcnx_s *target;
    struct airtnode_s *node;
    struct airtnode_s *enode;
    struct airtnode_s *rnode;
    f32 param;
    f32 partA;
    f32 partB;
    f32 destA;
    f32 destB;
    f32 best;
    f32 candidate;
    s32 direction;
    s32 endnode;
    s32 index;
    s32 start;
    s32 i;
    s32 angle;
    s32 done;

    if (!packet->cnx || !packet->fcnx || (path = packet->path) != packet->fpath) {
        return;
    }
    dcnx = packet->fcnx;
    if (packet->cnx == dcnx) {
        direction = 0;
        if (packet->dist < packet->fdist) {
            direction = 1;
        }
        AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position, (struct aiscxcnx_s *)dcnx, direction);
    } else {
        param = packet->dist;
        best = 0.0f;
        direction = 0;
        if (param > 1.0f) {
            param = 1.0f;
        } else if (param < 0.0f) {
            param = 0.0f;
        }
        partA = fn_8000ED40(param * packet->cnx->distance);
        partB = fn_8000ED40((1.0f - param) * packet->cnx->distance);
        destA = fn_8000ED40(packet->fdist * packet->fcnx->distance);
        destB = fn_8000ED40((1.0f - packet->fdist) * packet->fcnx->distance);
        if (packet->route != 0xff && !((s32)((u64)packet->fcnx->routemask >> packet->route) & 1)) {
            dcnx = packet->fcnx;
            rnode = &path->nodes[dcnx->nodes[0]];
            if ((s32)((u64)(rnode->membership & ~rnode->boundary) >> packet->route) & 1) {
                destA = 3.4028235e38f;
            }
            rnode = &path->nodes[dcnx->nodes[1]];
            if ((s32)((u64)(rnode->membership & ~rnode->boundary) >> packet->route) & 1) {
                destB = 3.4028235e38f;
            }
        }
        if (!(packet->cnx->blocked[1] & 0x40000000)) {
            param = fn_8008A370(packet->path, packet->cnx->nodes[0], packet->fcnx->nodes[0], packet->route, 0) + partA + destA;
            if (param > best) {
                best = param;
                direction = 1;
            }
            param = fn_8008A370(packet->path, packet->cnx->nodes[0], packet->fcnx->nodes[1], packet->route, 0) + partA + destB;
            if (param > best) {
                best = param;
                direction = 1;
            }
        }
        if (!(packet->cnx->blocked[0] & 0x40000000)) {
            param = fn_8008A370(packet->path, packet->cnx->nodes[1], packet->fcnx->nodes[0], packet->route, 0) + partB + destA;
            if (param > best) {
                best = param;
                direction = 0;
            }
            param = fn_8008A370(packet->path, packet->cnx->nodes[1], packet->fcnx->nodes[1], packet->route, 0) + partB + destB;
            if (param > best) {
                direction = 0;
            }
        }
        AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position, (struct aiscxcnx_s *)packet->cnx, direction);
    }
    pos = &object->position;
    endnode = packet->cnx->nodes[packet->direction == 0];
    packet->goal = &path->nodes[endnode];
    if (packet->target) {
        index = packet->cnx->nodes[packet->direction == 0];
        if (packet->target->nodes[0] != index && packet->target->nodes[1] != index) {
            packet->target = 0;
        }
    }
    if (!packet->target) {
        index = packet->cnx->nodes[packet->direction == 0];
        node = &packet->path->nodes[index];
        start = NuRandInt() % node->count;
        for (i = 0; i < node->count; i++) {
            packet->target = target = node->connections[(i + start) % node->count];
            if (target != packet->cnx &&
                (packet->route == 0xff || ((s32)((u64)target->routemask >> packet->route) & 1) ||
                 ((s32)((u64)node->boundary >> packet->route) & 1))) {
                direction = 1;
                if (packet->target->nodes[0] == index) {
                    direction = 0;
                }
                if (!packet->target->blocked[direction]) {
                    break;
                }
            }
            packet->target = 0;
        }
    }
    if (!packet->target) {
        cnx = packet->cnx;
        start = cnx->nodes[packet->direction];
        enode = &path->nodes[start];
        for (i = 0; i < enode->count; i++) {
            packet->target = target = enode->connections[i];
            if (target != cnx) {
                direction = 1;
                if (target->nodes[0] == start) {
                    direction = 0;
                }
                if (target->blocked[direction]) {
                    goto next;
                }
                AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)pos, (struct aiscxcnx_s *)cnx, packet->direction == 0);
                endnode = packet->cnx->nodes[packet->direction == 0];
                packet->goal = &path->nodes[endnode];
                break;
            }
        next:
            packet->target = 0;
        }
    }
    if (packet->target) {
        if (fn_8008ACD8(system, (f32 *)&packet->terrain, (struct aiinspath_s *)packet->path, (struct aiinscnx_s *)packet->target, checks,
                        (struct aiinscnx_s *)packet->cnx, packet->route, object->field291, 0, object->radius, 0)) {
            if (packet->target->nodes[0] == endnode) {
                AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)pos, (struct aiscxcnx_s *)packet->target, 0);
            } else {
                AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)pos, (struct aiscxcnx_s *)packet->target, 1);
            }
            endnode = packet->cnx->nodes[packet->direction == 0];
            packet->goal = &path->nodes[endnode];
            packet->dest = packet->goal->position;
            packet->stopping = 0.0f;
            packet->target = 0;
        } else {
            index = packet->target->nodes[packet->targetdir == 0];
            node = &packet->path->nodes[index];
            packet->dest = node->position;
            packet->stopping = 0.0f;
            if (fn_8008BCC0(system, (struct aiinspacket_s *)packet, (struct aiinsobject_s *)object, (struct aiinscnx_s *)packet->cnx, (struct aiinscnx_s *)packet->target)) {
                done = 0;
                if (packet->flags & 0x02000000) {
                    NuVecSub(&diff, &packet->left, pos);
                    angle = fn_8000ABDC(diff.x, diff.z);
                    NuVecSub(&diff, &packet->dest, pos);
                    if (NuAngSub(fn_8000ABDC(diff.x, diff.z), angle) < 0) {
                        packet->dest = packet->left;
                        done = 1;
                    }
                }
                if (!done && (packet->flags & 0x04000000)) {
                    NuVecSub(&diff, &packet->right, pos);
                    angle = fn_8000ABDC(diff.x, diff.z);
                    NuVecSub(&diff, &packet->dest, pos);
                    if (NuAngSub(fn_8000ABDC(diff.x, diff.z), angle) > 0) {
                        packet->dest = packet->right;
                    }
                }
            }
        }
    } else {
        packet->dest = packet->goal->position;
        packet->stopping = 0.0f;
    }
}

struct aidncnx_s {
    u8 nodes[2];
    u8 pad2[0x14];
    u16 routemask;
    f32 distance;
};
struct aidnnode_s {
    u8 pad0[0x2e];
    u8 cachenodes[2];
    struct aidncnx_s **connections;
    f32 cache[2];
    u8 pad3c[0x18];
    u16 membership;
    u8 pad56[2];
};
struct aidnroute_s {
    char *name;
    u8 *noderoutes;
    u8 pad8[4];
    u8 *exitnodes;
    u8 routecount;
    u8 exitcount;
    u8 pad12[2];
    u8 **routenodes;
    u8 pad18[0x10];
};
struct aidnpath_s {
    u8 pad0[0x78];
    struct aidnnode_s *nodes;
    u8 pad7c[4];
    u8 **matrix;
    struct aidnroute_s *routes;
};
extern char str_AIPathNodeDistanceToPathNode_SpecialRouteProblem[];
extern void (*fn_8000995C(char *file, s32 line))(char *fmt, ...);

f32 fn_8008A370(struct airtpath_s *pathArg, s32 start, s32 dest, s32 routeIndex, s32 mask)
{
    struct aidnpath_s *path = (struct aidnpath_s *)pathArg;
    struct aidnnode_s *startnode;
    struct aidnnode_s *node;
    struct aidnnode_s *destination;
    struct aidncnx_s *cnx;
    struct aidncnx_s *previous;
    struct aidnroute_s *route;
    f32 *cached;
    f32 distance;
    f32 nearest;
    f32 first;
    f32 second;
    f32 candidate;
    s32 index;
    s32 i;
    u32 bit;
    u8 from;
    u8 to;
    u8 ci;

    distance = 0.0f;
    previous = 0;
    route = 0;
    cached = 0;
    if (!path->matrix) {
        return 3.4028235e38f;
    }
    if (start == dest) {
        return distance;
    }
    startnode = &path->nodes[start];
    destination = &path->nodes[dest];
    if (mask == 0 && routeIndex == 0xff) {
        if (startnode->cachenodes[0] == dest) {
            return startnode->cache[0];
        }
        if (startnode->cachenodes[1] == dest) {
            return startnode->cache[1];
        }
        startnode->cachenodes[1] = startnode->cachenodes[0];
        startnode->cache[1] = startnode->cache[0];
        startnode->cachenodes[0] = dest;
        cached = &startnode->cache[0];
        *cached = distance;
    }
    node = startnode;
    index = node - path->nodes;
    if (routeIndex != 0xff) {
        route = &path->routes[routeIndex];
        if (!((s32)((u64)node->membership >> routeIndex) & 1)) {
            return 3.4028235e38f;
        }
    }
    while (node != destination) {
        if (route) {
            if ((s32)((u64)destination->membership >> routeIndex) & 1) {
                from = route->noderoutes[index];
                if (from < route->routecount && (to = route->noderoutes[dest]) < route->routecount) {
                    ci = route->routenodes[from][to];
                } else {
                    fn_8000995C(lbl_8019C6DC, 0xebb)(str_AIPathNodeDistanceToPathNode_SpecialRouteProblem, route->name, index, dest);
                    ci = 0xff;
                }
            } else {
                nearest = 3.4028235e38f;
                for (i = 0; i < route->exitcount; i++) {
                    if (route->exitnodes[i] == start) {
                        first = 0.0f;
                    } else {
                        first = fn_8008A370(pathArg, start, route->exitnodes[i], routeIndex, 0);
                    }
                    if (route->exitnodes[i] == dest) {
                        second = 0.0f;
                    } else {
                        second = fn_8008A370(pathArg, route->exitnodes[i], dest, 0xff, (u32)((u64)1 << routeIndex));
                    }
                    candidate = first + second;
                    if (candidate < nearest) {
                        nearest = candidate;
                    }
                }
                if (nearest != 3.4028235e38f) {
                    distance += nearest;
                    break;
                }
                if (cached) {
                    *cached = 3.4028235e38f;
                }
                return 3.4028235e38f;
            }
        } else {
            ci = path->matrix[index][dest];
        }
        if (ci == 0xff) {
            if (cached) {
                *cached = 3.4028235e38f;
            }
            return 3.4028235e38f;
        }
        cnx = node->connections[ci];
        if (!cnx) {
            return 3.4028235e38f;
        }
        if (cnx->routemask & mask) {
            if (cached) {
                *cached = 3.4028235e38f;
            }
            return 3.4028235e38f;
        }
        if (previous == cnx) {
            break;
        }
        previous = cnx;
        if (index == cnx->nodes[0]) {
            index = cnx->nodes[1];
        } else {
            index = cnx->nodes[0];
        }
        distance += cnx->distance;
        node = &path->nodes[index];
    }
    if (cached) {
        *cached = distance;
    }
    return distance;
}

#include "types.h"


struct aisys_state_s {
    u8 pad0[0x10];
    u8 actions[8];
    char *name;
};

struct aisys_script_s {
    u8 pad0[0x10];
    u8 states[8];
};

struct aisys_proc_s {
    u8 pad0[4];
    struct aisys_script_s *script;
    struct aisys_state_s *state;
    void *action;
    s32 unk10;
    u8 pad14[0x28];
    u32 flags;
};

static inline struct aisys_state_s *aisys_find_state(struct aisys_script_s *script, char *name)
{
    struct aisys_state_s *state;
    for (state = (struct aisys_state_s *)fn_800076C4(&script->states); state != 0; state = (struct aisys_state_s *)fn_800076CC(&script->states, state)) {
        if (NuStrICmp(name, state->name) == 0) {
            return state;
        }
    }
    return 0;
}

static inline void aisys_set_state(struct aisys_proc_s *proc, struct aisys_state_s *state)
{
    void *action;
    if (proc != 0) {
        proc->state = state;
        proc->action = 0;
        proc->unk10 = 0;
        action = fn_800076C4(&state->actions);
        if (action != 0) {
            proc->action = action;
            proc->flags |= 0x80000000;
        } else {
            proc->action = 0;
        }
    }
}

s32 fn_8007EBD0(void *procArg, void *nameArg)
{
    struct aisys_proc_s *proc = (struct aisys_proc_s *)procArg;
    char *name = (char *)nameArg;
    struct aisys_state_s *state;

    if (name != 0 && proc != 0 && proc->script != 0) {
        state = aisys_find_state(proc->script, name);
        if (state != 0) {
            aisys_set_state(proc, state);
            return 1;
        }
    }
    return 0;
}

#include "types.h"


struct aisys_cond_desc_s {
    char *name;
    f32 (*fn)(void *, void *, void *, void *, void *);
};

struct aisys_cond_s {
    u8 pad0[8];
    f32 value;
    s8 op;
    s8 varIdx;
    u32 isAnd : 1;
    u32 isVar : 1;
    void *param0;
    void *param1;
    struct aisys_cond_desc_s *desc;
};

struct aisys_proc_cond_s {
    u8 pad0[0x14];
    f32 vars[8];
};

struct aisys_cond_s *fn_8007EFA0(void *sys, void *condList, void *unused, void *packet, struct aisys_proc_cond_s *proc, f32 time)
{
    struct aisys_cond_s *cond;
    f32 val = 0.0f;
    f32 cmpVal;
    s32 ok;

    if (proc != 0 && condList != 0) {
        cond = (struct aisys_cond_s *)fn_800076C4(condList);
        while (cond != 0) {
            ok = 0;
            if (cond->desc != 0) {
                if (cond->desc->fn != 0) {
                    val = cond->desc->fn(sys, proc, packet, cond->param0, cond->param1);
                }
                if (cond->isVar) {
                    cmpVal = proc->vars[cond->varIdx];
                } else {
                    cmpVal = cond->value;
                }
                switch (cond->op) {
                    case 0:
                        if (val == cmpVal) ok = 1;
                        break;
                    case 1:
                        if (val < cmpVal) ok = 1;
                        break;
                    case 2:
                        if (val > cmpVal) ok = 1;
                        break;
                    case 3:
                        if (val != cmpVal) ok = 1;
                        break;
                }
            }
            if (ok) {
                if (!cond->isAnd) {
                    return cond;
                }
                cond = (struct aisys_cond_s *)fn_800076CC(condList, cond);
                continue;
            } else {
                while (cond != 0 && cond->isAnd) {
                    cond = (struct aisys_cond_s *)fn_800076CC(condList, cond);
                }
                if (cond == 0) {
                    break;
                }
            }
            cond = (struct aisys_cond_s *)fn_800076CC(condList, cond);
        }
    }
    return 0;
}

#include "types.h"

extern void fn_80007680(void *, void *);

struct aisys_rr_cond_desc_s {
    char *name;
    void *fn;
    void *(*resolve)(void *, void *);
};

struct aisys_rr_cond_s {
    u8 pad0[0x10];
    void *param0;
    void *param1;
    struct aisys_rr_cond_desc_s *desc;
};

struct aisys_rr_override_s {
    u8 pad0[8];
    char *scriptName;
    void *script;
    char *returnStateName;
    void *returnState;
    u32 searchGlobal : 1;
    u32 searchLocal : 1;
    u32 pad18 : 30;
    u8 condList[8];
};

struct aisys_rr_state_s {
    u8 pad0[0x18];
    char *name;
    u8 overrides[8];
};

struct aisys_rr_script_s {
    u8 pad0[8];
    char *name;
    u8 padC[4];
    u8 states[8];
    u8 pad18[0x28];
    u8 overrides[8];
};

struct aisys_rr_sys_s {
    u8 pad0[0x18];
    u8 scripts[8];
};

struct aisys_rr_script_s *fn_80083754(struct aisys_rr_sys_s *sys, char *name,
                                      s32 useDefault, s32 searchLocal, s32 searchGlobal)
{
    struct aisys_rr_script_s *script;

    if (name != 0) {
        if (searchLocal != 0 && sys != 0) {
            for (script = fn_800076C4(&sys->scripts); script != 0; script = fn_800076CC(&sys->scripts, script)) {
                if (NuStrICmp(name, script->name) == 0) {
                    return script;
                }
            }
        }
        if (searchGlobal != 0) {
            for (script = fn_800076C4(&lbl_8040AF30); script != 0; script = fn_800076CC(&lbl_8040AF30, script)) {
                if (NuStrICmp(name, script->name) == 0) {
                    return script;
                }
            }
        }
    }
    if (useDefault == 0) {
        return 0;
    }
    for (script = fn_800076C4(&lbl_8040AF30); script != 0; script = fn_800076CC(&lbl_8040AF30, script)) {
        if (NuStrICmp(str_ScriptToken_Default, script->name) == 0) {
            return script;
        }
    }
    return 0;
}

static inline struct aisys_rr_script_s *aisys_rr_find_script(struct aisys_rr_sys_s *sys, char *name, u32 searchLocal, u32 searchGlobal)
{
    struct aisys_rr_script_s *s;
    if (name != 0) {
        if (searchLocal != 0 && sys != 0) {
            for (s = (struct aisys_rr_script_s *)fn_800076C4(&sys->scripts); s != 0; s = (struct aisys_rr_script_s *)fn_800076CC(&sys->scripts, s)) {
                if (NuStrICmp(name, s->name) == 0) {
                    return s;
                }
            }
        }
        if (searchGlobal != 0) {
            for (s = (struct aisys_rr_script_s *)fn_800076C4(&lbl_8040AF30); s != 0; s = (struct aisys_rr_script_s *)fn_800076CC(&lbl_8040AF30, s)) {
                if (NuStrICmp(name, s->name) == 0) {
                    return s;
                }
            }
        }
    }
    for (s = (struct aisys_rr_script_s *)fn_800076C4(&lbl_8040AF30); s != 0; s = (struct aisys_rr_script_s *)fn_800076CC(&lbl_8040AF30, s)) {
        if (NuStrICmp(str_ScriptToken_Default, s->name) == 0) {
            return s;
        }
    }
    return 0;
}

static inline struct aisys_rr_state_s *aisys_rr_find_state(void *stateList, char *name)
{
    struct aisys_rr_state_s *st = (struct aisys_rr_state_s *)fn_800076C4(stateList);
    if (!name) {
        return 0;
    }
    for (; st != 0; st = (struct aisys_rr_state_s *)fn_800076CC(stateList, st)) {
        if (NuStrICmp(name, st->name) == 0) {
            return st;
        }
    }
    return 0;
}

void AIScriptResolveReferences(struct aisys_rr_sys_s *sys, struct aisys_rr_script_s *script)
{
    struct aisys_rr_override_s *ov;
    struct aisys_rr_override_s *nextOv;
    struct aisys_rr_state_s *state;
    struct aisys_rr_cond_s *cond;

    if (sys != 0 && script != 0) {
        for (ov = (struct aisys_rr_override_s *)fn_800076C4(&script->overrides); ov != 0; ov = nextOv) {
            nextOv = (struct aisys_rr_override_s *)fn_800076CC(&script->overrides, ov);
            ov->script = aisys_rr_find_script(sys, ov->scriptName, ov->searchLocal, ov->searchGlobal);
            if (ov->script == 0 || ov->script == script) {
                fn_80007680(&script->overrides, ov);
            } else {
                ov->returnState = aisys_rr_find_state(&script->states, ov->returnStateName);
                for (cond = (struct aisys_rr_cond_s *)fn_800076C4(&ov->condList); cond != 0; cond = (struct aisys_rr_cond_s *)fn_800076CC(&ov->condList, cond)) {
                    if (cond->desc->resolve != 0) {
                        cond->param1 = cond->desc->resolve(sys, cond->param0);
                    }
                }
            }
        }
        for (state = (struct aisys_rr_state_s *)fn_800076C4(&script->states); state != 0; state = (struct aisys_rr_state_s *)fn_800076CC(&script->states, state)) {
            for (ov = (struct aisys_rr_override_s *)fn_800076C4(&state->overrides); ov != 0; ov = nextOv) {
                nextOv = (struct aisys_rr_override_s *)fn_800076CC(&state->overrides, ov);
                ov->script = aisys_rr_find_script(sys, ov->scriptName, ov->searchLocal, ov->searchGlobal);
                if (ov->script == 0 || ov->script == script) {
                    fn_80007680(&script->overrides, ov);
                }
                ov->returnState = aisys_rr_find_state(&script->states, ov->returnStateName);
                for (cond = (struct aisys_rr_cond_s *)fn_800076C4(&ov->condList); cond != 0; cond = (struct aisys_rr_cond_s *)fn_800076CC(&ov->condList, cond)) {
                    if (cond->desc->resolve != 0) {
                        cond->param1 = cond->desc->resolve(sys, cond->param0);
                    }
                }
            }
        }
    }
}

#include "types.h"

extern char str_ScriptState_Base_2[];

struct aisys_init_state_s {
    u8 pad0[0x10];
    u8 actions[8];
    char *name;
};

struct aisys_init_var_s {
    f32 value;
    u32 pad4;
};

struct aisys_init_script_s {
    u8 pad0[8];
    char *name;
    u8 padC[4];
    u8 states[8];
    u8 pad18[4];
    struct aisys_init_var_s vars[4];
};

struct aisys_init_sys_s {
    u8 pad0[0x18];
    u8 scripts[8];
};

struct aisys_init_override_s {
    u8 pad0[0x58];
    s32 varMask;
    u8 pad5C[0x10];
    f32 vars[4];
};

struct aisys_init_proc_s {
    struct aisys_init_script_s *rootScript;
    struct aisys_init_script_s *script;
    struct aisys_init_state_s *state;
    void *action;
    s32 unk10;
    f32 vars[4];
    u8 pad24[0x18];
    u32 flags;
    u8 pad40[4];
    u8 unk44;
    u8 unk45;
    u8 pad46[2];
    f32 unk48;
    s32 unk4C;
};

static inline struct aisys_init_script_s *aisys_find_script_init(struct aisys_init_sys_s *sys, char *name, s32 useDefault)
{
    struct aisys_init_script_s *script;
    if (name != 0) {
        if (sys != 0) {
            for (script = (struct aisys_init_script_s *)fn_800076C4(&sys->scripts); script != 0; script = (struct aisys_init_script_s *)fn_800076CC(&sys->scripts, script)) {
                if (NuStrICmp(name, script->name) == 0) {
                    return script;
                }
            }
        }
        for (script = (struct aisys_init_script_s *)fn_800076C4(&lbl_8040AF30); script != 0; script = (struct aisys_init_script_s *)fn_800076CC(&lbl_8040AF30, script)) {
            if (NuStrICmp(name, script->name) == 0) {
                return script;
            }
        }
    }
    if (!useDefault) {
        return 0;
    }
    for (script = (struct aisys_init_script_s *)fn_800076C4(&lbl_8040AF30); script != 0; script = (struct aisys_init_script_s *)fn_800076CC(&lbl_8040AF30, script)) {
        if (NuStrICmp(str_ScriptToken_Default, script->name) == 0) {
            return script;
        }
    }
    return 0;
}

static inline struct aisys_init_state_s *aisys_find_state_init(struct aisys_init_script_s *script, char *name)
{
    struct aisys_init_state_s *state;
    for (state = (struct aisys_init_state_s *)fn_800076C4(&script->states); state != 0; state = (struct aisys_init_state_s *)fn_800076CC(&script->states, state)) {
        if (NuStrICmp(name, state->name) == 0) {
            return state;
        }
    }
    return 0;
}

static inline void aisys_set_state_init(struct aisys_init_proc_s *proc, struct aisys_init_state_s *state)
{
    void *action;
    if (proc != 0 && state != 0) {
        proc->state = state;
        proc->action = 0;
        proc->unk10 = 0;
        action = fn_800076C4(&state->actions);
        if (action != 0) {
            proc->action = action;
            proc->flags |= 0x80000000;
        } else {
            proc->action = 0;
        }
    }
}

void AIScriptProcessorInit(struct aisys_init_sys_s *sys, void *packet, struct aisys_init_proc_s *proc,
    struct aisys_init_override_s *overrideData, char *scriptName, char *stateName, s32 useDefault,
    struct aisys_init_script_s *script, struct aisys_init_state_s *state)
{
    s32 i;

    if (proc != 0) {
        if (script == 0) {
            script = aisys_find_script_init(sys, scriptName, useDefault);
        }
        if (script != 0) {
            proc->unk10 = 0;
            proc->script = script;
            if (proc->rootScript == 0) {
                proc->rootScript = script;
            }
            if (overrideData != 0) {
                for (i = 0; i < 4; i++) {
                    proc->vars[i] = overrideData->vars[i];
                }
                for (i = 0; i < 4; i++) {
                    if (!((u64)overrideData->varMask & ((u64)2 << i))) {
                        proc->vars[i] = script->vars[i].value;
                    }
                }
            } else {
                for (i = 0; i < 4; i++) {
                    proc->vars[i] = script->vars[i].value;
                }
            }
            if (state == 0) {
                if (stateName != 0) {
                    state = aisys_find_state_init(script, stateName);
                }
            }
            if (state != 0) {
                aisys_set_state_init(proc, state);
            } else {
                fn_8007EBD0(proc, str_ScriptState_Base_2);
            }
        }
        proc->unk44 = 0;
        proc->unk45 = 0;
        proc->unk48 = 0.0f;
        proc->unk4C = 0;
    }
}

#include "types.h"

extern void (*lbl_80408D28)(void *, void *, void *);

struct aisys_p_action_desc_s {
    char *name;
    s32 (*fn)(void *, void *, void *, void *, s32, s32, f32);
};

struct aisys_p_action_s {
    u8 pad0[8];
    void *params;
    s32 paramCount;
    struct aisys_p_action_desc_s *desc;
};

struct aisys_p_cond_s {
    u8 pad0[0x20];
    struct aisys_p_state_s *targetState;
};

struct aisys_p_state_s {
    u8 pad0[8];
    u8 conds[8];
    u8 actions[8];
    u8 pad18[4];
    u8 overrides[8];
};

struct aisys_p_script_s {
    u8 pad0[0x10];
    u8 states[8];
    u8 pad18[0x20];
    struct aisys_p_state_s *baseState;
    u8 pad3C[4];
    u8 overrides[8];
};

struct aisys_p_override_s {
    u8 pad0[0xc];
    struct aisys_p_script_s *subScript;
    u8 pad10[4];
    struct aisys_p_state_s *returnState;
    u8 pad18[4];
    u8 condList[8];
};

struct aisys_p_sys_s {
    u8 pad0[0x14];
    u8 *charTable;
};

struct aisys_p_packet_s {
    u8 pad0[0xa6];
    u8 charIdx;
    u8 padA7[9];
    u8 unkB0;
    u8 padB1;
    u8 unkB2;
    u8 unkB3;
    s32 unkB4;
    f32 unkB8;
    f32 unkBC;
    u8 padC0[0x70];
    s32 unk130;
    f32 unk134;
};

struct aisys_p_proc_s {
    struct aisys_p_script_s *rootScript;
    struct aisys_p_script_s *script;
    struct aisys_p_state_s *state;
    struct aisys_p_action_s *action;
    struct aisys_p_state_s *nextState;
    u8 pad14[0x10];
    f32 timer;
    struct aisys_p_override_s *stack[4];
    s32 stackDepth;
    u32 flags;
    f32 unk40;
    u8 unk44;
    u8 pad45[3];
    f32 interruptTimer;
    struct aisys_p_state_s *interruptState;
};

s32 fn_8007F130(void *sys, void *obj, void *packet, void *procArg, f32 time)
{
    struct aisys_p_proc_s *proc = procArg;
    struct aisys_p_override_s *ov;
    struct aisys_p_cond_s *cond;
    struct aisys_p_state_s *state;

    if (sys != 0 && proc != 0 && proc->script != 0 && proc->stackDepth < 4) {
        ov = fn_800076C4(proc->script->overrides);
        if (ov != 0) {
            struct aisys_p_override_s **stack = proc->stack;

            for (; ov != 0; ov = fn_800076CC(proc->script->overrides, ov)) {
                void *conds = ov->condList;

                if (fn_800076C4(conds) == 0 || fn_8007EFA0(sys, conds, obj, packet, (void *)proc, time) != 0) {
                    cond = (void *)fn_8007EFA0(sys, ov->subScript->baseState->conds, obj, packet, (void *)proc, time);
                    if (cond != 0 && cond->targetState != ov->subScript->baseState) {
                        stack[proc->stackDepth++] = ov;
                        AIScriptProcessorInit(sys, packet, (void *)proc, 0, 0, 0, 0,
                            (void *)ov->subScript, (void *)cond->targetState);
                        return 1;
                    }
                }
            }
        }

        state = proc->state;
        if (state != 0) {
            ov = fn_800076C4(state->overrides);
            if (ov != 0) {
                struct aisys_p_override_s **stack = proc->stack;

                for (; ov != 0; ov = fn_800076CC(state->overrides, ov)) {
                    void *conds = ov->condList;

                    if (fn_800076C4(conds) == 0 || fn_8007EFA0(sys, conds, obj, packet, (void *)proc, time) != 0) {
                        cond = (void *)fn_8007EFA0(sys, ov->subScript->baseState->conds, obj, packet, (void *)proc, time);
                        if (cond != 0 && cond->targetState != ov->subScript->baseState) {
                            stack[proc->stackDepth++] = ov;
                            AIScriptProcessorInit(sys, packet, (void *)proc, 0, 0, 0, 0,
                                (void *)ov->subScript, (void *)cond->targetState);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

static inline void aisys_p_set_state(struct aisys_p_proc_s *proc, struct aisys_p_state_s *state)
{
    struct aisys_p_action_s *action;
    if (proc != 0 && state != 0) {
        proc->state = state;
        proc->action = 0;
        proc->nextState = 0;
        action = (struct aisys_p_action_s *)fn_800076C4(&state->actions);
        if (action != 0) {
            proc->action = action;
            proc->flags |= 0x80000000;
        } else {
            proc->action = 0;
        }
    }
}

static inline s32 aisys_p_next_action(struct aisys_p_proc_s *proc)
{
    struct aisys_p_action_s *action;
    if (proc != 0) {
        if (proc->action != 0) {
            action = (struct aisys_p_action_s *)fn_800076CC(&proc->state->actions, proc->action);
        } else {
            action = (struct aisys_p_action_s *)fn_800076C4(&proc->state->actions);
        }
        if (action != 0) {
            proc->action = action;
            proc->flags |= 0x80000000;
        } else {
            proc->action = 0;
        }
        return 1;
    }
    return 0;
}

void AIScriptProcess(void *sysArg, void *arg1, void *packetArg, void *procArg, f32 time)
{
    struct aisys_p_sys_s *sys = (struct aisys_p_sys_s *)sysArg;
    struct aisys_p_packet_s *packet = (struct aisys_p_packet_s *)packetArg;
    struct aisys_p_proc_s *proc = (struct aisys_p_proc_s *)procArg;
    s32 i;
    struct aisys_p_override_s *ov;
    void *overrideData;
    struct aisys_p_cond_s *cond;

    if (proc == 0) {
        return;
    }
    proc->timer += time;
    for (i = 0; i < proc->stackDepth; i++) {
        ov = proc->stack[i];
        if (fn_800076C4(&ov->condList) != 0 && fn_8007EFA0(sys, &ov->condList, arg1, packet, proc, time) == 0) {
            proc->stackDepth = i;
            if (proc->stackDepth == 0) {
                if (packet->charIdx == 0xff) {
                    overrideData = 0;
                } else {
                    overrideData = (void *)(sys->charTable + packet->charIdx * 0xa8);
                }
                AIScriptProcessorInit(sys, packet, proc, overrideData, 0, 0, 0, proc->rootScript, ov->returnState);
            } else {
                goto pop_nested_ref;
            }
            break;
        }
    }
after_ref_check:
    if (proc->stackDepth != 0 && proc->nextState == 0) {
        if (proc->script->baseState == proc->state) {
            ov = proc->stack[proc->stackDepth - 1];
            proc->stackDepth--;
            if (proc->stackDepth != 0) {
                AIScriptProcessorInit(sys, packet, proc, 0, 0, 0, 0, proc->stack[proc->stackDepth - 1]->subScript, ov->returnState);
                if (0) {
pop_nested_ref:
                    AIScriptProcessorInit(sys, packet, proc, 0, 0, 0, 0, proc->stack[proc->stackDepth - 1]->subScript, ov->returnState);
                    goto after_ref_check;
                }
            } else {
                if (packet->charIdx == 0xff) {
                    overrideData = 0;
                } else {
                    overrideData = (void *)(sys->charTable + packet->charIdx * 0xa8);
                }
                AIScriptProcessorInit(sys, packet, proc, overrideData, 0, 0, 0, proc->rootScript, ov->returnState);
            }
        }
    }
    if (proc->nextState != 0) {
        aisys_p_set_state(proc, proc->nextState);
        proc->nextState = 0;
    } else if (proc->state == 0) {
        aisys_p_set_state(proc, (struct aisys_p_state_s *)fn_800076C4(&proc->script->states));
    }
    if (proc->state != 0) {
action_loop:
        {
            struct aisys_p_action_s *action = proc->action;
            s32 first;
            if (action != 0) {
                if (action->desc != 0 && action->desc->fn != 0) {
                    if ((s32)proc->flags < 0) {
                        proc->unk40 = 0.0f;
                        if (packet != 0) {
                            packet->unkB0 = 0;
                            packet->unk130 = 0;
                            packet->unkB2 = 0;
                            packet->unkB3 = 0;
                            packet->unkB8 = 0.0f;
                            packet->unkB4 = 0;
                            packet->unkBC = 0.0f;
                            packet->unk134 = 0.0f;
                            if (lbl_80408D28 != 0) {
                                lbl_80408D28(sys, packet, proc);
                            }
                        }
                        first = 1;
                        proc->flags &= ~0x80000000;
                    } else {
                        first = 0;
                    }
                    if (action->desc->fn(sys, proc, packet, action->params, action->paramCount, first, time) == 0) {
                        goto actions_done;
                    }
                } else {
                    proc->flags &= ~0x80000000;
                }
                if ((s32)proc->flags < 0) {
                    goto action_loop;
                }
                if (aisys_p_next_action(proc)) {
                    goto action_loop;
                }
            }
        }
    }
actions_done:
    if (!fn_8007F130(sys, arg1, packet, proc, time)) {
        f32 prevTimer = proc->interruptTimer;
        if (prevTimer > 0.0f) {
            proc->interruptTimer -= time;
        }
        if (prevTimer > 0.0f && proc->interruptTimer <= 0.0f && proc->interruptState != 0) {
            aisys_p_set_state(proc, proc->interruptState);
            proc->unk44 = 0;
            proc->interruptState = 0;
        } else if (proc->state != 0) {
            cond = (struct aisys_p_cond_s *)fn_8007EFA0(sys, &proc->state->conds, arg1, packet, proc, time);
            if (cond != 0) {
                aisys_p_set_state(proc, cond->targetState);
            }
        }
    }
}

struct airtcnx_s *fn_8008B79C(struct airtpacket_s *packet, s32 *direction)
{
    struct airtcnx_s *cnx = 0;
    s32 exitNode = 0;

    struct airtnode_s *goal = packet->goal;

    if (goal) {
        struct airtpath_s *path = packet->path;
        struct airtnode_s *nodes = path->nodes;
        s32 start = packet->cnx->nodes[packet->direction == 0];
        s32 dest = goal - nodes;
        s32 index = ((struct aidnpath_s *)path)->matrix[start][dest];
        struct airtnode_s *node = &nodes[start];
        s32 routeIndex;

        if (index < node->count) {
            cnx = node->connections[index];
            if (cnx->nodes[0] == start) {
                *direction = 0;
            } else {
                *direction = 1;
            }
        }
        routeIndex = packet->route;
        if (routeIndex != 0xff) {
            struct aidnroute_s *route;
            struct airtnode_s *destNode;
            s32 reverse;

            if (!((s32)((u64)node->membership >> routeIndex) & 1)) {
                goto no_connection;
            }
            if ((s32)((u64)node->boundary >> routeIndex) & 1) {
                if (!cnx || !((s32)((u64)cnx->routemask >> routeIndex) & 1)) {
                    goto done;
                }
            }
            route = &((struct aidnpath_s *)packet->path)->routes[routeIndex];
            destNode = &packet->path->nodes[dest];
            cnx = 0;
            if ((s32)((u64)destNode->membership >> routeIndex) & 1) {
                index = route->routenodes[route->noderoutes[start]][route->noderoutes[dest]];
            } else {
                f32 nearest = 3.4028235e38f;
                s32 i;

                for (i = 0; i < route->exitcount; i++) {
                    f32 first = fn_8008A370(packet->path, start, route->exitnodes[i], packet->route, 0);
                    f32 distance = first + fn_8008A370(packet->path, route->exitnodes[i], dest, 0xff,
                                                    (u32)((u64)1 << packet->route));

                    if (distance < nearest) {
                        nearest = distance;
                        exitNode = route->exitnodes[i];
                    }
                }
                if (nearest == 3.4028235e38f) {
no_connection:
                    return 0;
                }
                index = route->routenodes[route->noderoutes[start]][route->noderoutes[exitNode]];
            }
            if (index < node->count) {
                cnx = node->connections[index];
                if (cnx->nodes[0] == start) {
                    /* Reuse the exit-node temporary after the route lookup. */
                    exitNode = 0;
                    reverse = exitNode;
                } else {
                    reverse = 1;
                }
                *direction = reverse;
            }
        }
done:
        return cnx;
    }
    goto no_connection;
}

struct airow_s {
    struct aiwdpath_s *path;
    struct aiwdcnx_s *connection;
    u8 direction;
    u8 pad9[7];
    f32 t;
    u8 pad14[4];
    struct aiffvec_s position;
    s32 rotation;
    struct aiwdcnx_s *next;
    u8 nextDirection;
    u8 pad2d[3];
    u32 flags;
};

struct airowpacket_s {
    u8 pad0[0xcc];
    struct aiwdpath_s *targetPath;
    struct aiwdcnx_s *targetCnx;
    u8 padd4[8];
    f32 targetT;
    u8 pade0[0x8a];
    u8 route;
};

struct airowobject_s {
    void *object;
    struct airowpacket_s *packet;
    u8 pad8[0x64];
    struct aiffvec_s position;
    u8 pad78[0x194];
    u32 flags;
    u8 pad210[0x7f];
    u8 field28f;
};

struct airowgroup_s {
    struct airowobject_s *leader;
    s16 rotationSpeed;
    u8 rowCount;
    u8 memberCount;
    u8 pad8[4];
    struct airowobject_s *members[17];
    union {
        u32 word;
        struct {
            u32 pad0 : 2;
            u32 reversed : 1;
            u32 pad3 : 29;
        } bits;
    } flags;
    struct airow_s rows[4];
    f32 radius;
};

extern f32 fn_8000BDD0(void *, void *, void *);

s32 fn_8008C13C(struct airowgroup_s *group, struct airow_s *row,
                struct airow_s *previous, struct airowobject_s *leader)
{
    struct aiffvec_s rotated;
    struct aiffvec_s offset;
    struct aiffvec_s centre;
    struct aiffvec_s *position;
    struct aiwdcnx_s *current;
    struct aiwdcnx_s *next;
    struct aiwdnode_s *node;
    struct aiwdnode_s *nodes;
    struct aiwdcnx_s *candidate;
    struct aiwdcnx_s *replacement;
    s32 count;
    struct airowobject_s *member, *reverse;
    s32 nodeIndex;
    s32 offsetIndex, sourceNodeIndex, nextNodeIndex;
    struct aiwdcnx_s *turnConnection, *turnNext;
    struct aiwdcnx_s *currentNext, *begin;
    struct aiwdcnx_s *postNext;
    struct aiwdnode_s *other;
    struct aiwdcnx_s *initialNext;
    s32 first;
    s32 direction;
    s32 currentAngle;
    s32 angle;
    s32 step;
    s32 i;
    u8 route;
    f32 distance;

    if (!row->connection) {
        return 0;
    }
    current = row->connection;
    nodeIndex = current->nodes[row->direction == 0];
    node = &row->path->nodes[nodeIndex];
    initialNext = row->next;
    if (!initialNext) {
        if (previous) {
            replacement = previous->connection;
            if (current == replacement) {
                replacement = previous->next;
            }
        } else {
            first = NuRandInt() % node->count;
            for (i = 0; i < node->count; i++) {
                candidate = node->connections[(i + first) % node->count];
                row->next = candidate;
                if (candidate != row->connection) {
                    route = leader->packet->route;
                    if (route == 0xff || ((s32)((u64)candidate->routemask >> route) & 1) ||
                        ((s32)((u64)node->boundarymask >> route) & 1)) {
                        next = row->next;
                        direction = 1;
                        if (next->nodes[0] == nodeIndex) {
                            direction = 0;
                        }
                        other = &row->path->nodes[next->nodes[direction ^ 1]];
                        if (other->approachRadius > group->radius && !next->blocked[direction]) {
                            break;
                        }
                    }
                }
                row->next = 0;
            }
            if (row->next) {
                goto nextReady;
            }
            replacement = row->connection;
        }
        /* Keep the store separate from the following null check. */
        *(struct aiwdcnx_s *volatile *)&row->next = replacement;
        if (!row->next) {
            return 0;
        }
    nextReady:
        direction = 1;
        postNext = row->next;
        if (postNext->nodes[0] == nodeIndex) {
            direction = 0;
        }
        if (postNext->blocked[direction] == 0) {
            if (row->direction) {
                currentAngle = NuAngAdd(0x8000, row->connection->rotation);
            } else {
                currentAngle = row->connection->rotation;
            }
            offsetIndex = row->direction;
            turnConnection = row->connection;
            turnNext = row->next;
            sourceNodeIndex = turnConnection->nodes[offsetIndex == 0];
            nextNodeIndex = turnNext->nodes[0];
            if (sourceNodeIndex == nextNodeIndex) {
                row->nextDirection = 0;
                angle = turnNext->rotation;
            } else {
                row->nextDirection = 1;
                angle = NuAngAdd(0x8000, turnNext->rotation);
            }
            if (NuAngSub(angle, currentAngle) < 0) {
                row->flags |= 0x80000000;
            } else {
                row->flags &= ~0x80000000;
            }
        }
        if (!row->next) {
            return 0;
        }
    }
    offset.y = 0.0f;
    offset.z = 0.0f;
    if (row->flags & 0x80000000) {
        offset.x = -group->radius;
    } else {
        offset.x = group->radius;
    }
    NuVecRotateY(&rotated, &offset, row->rotation);
    NuVecAdd(&centre, &rotated, &row->position);

    if (!(row->flags & 0x40000000)) {
        begin = row->connection;
        currentNext = row->next;
        if (begin == currentNext) {
            node = &row->path->nodes[currentNext->nodes[row->direction == 0]];
            distance = fn_8000CDFC(&row->position, &node->position, &rotated);
            if (distance < node->radiusSquared) {
                i = 0;
                if (i < group->rowCount) {
                    do {
                        group->rows[i].next = 0;
                        group->rows[i].rotation = NuAngAdd(group->rows[i].rotation, 0x8000);
                        group->rows[i].direction = !group->rows[i].direction;
                    } while (++i < group->rowCount);
                }
                group->leader = 0;
                group->flags.bits.reversed = !group->flags.bits.reversed;
                if (group->flags.bits.reversed) {
                    i = group->memberCount - 1;
                    if (i >= 0) {
                        do {
                            reverse = group->members[i];
                            if (reverse && (reverse->flags & 0x80080000) == 0x80080000 &&
                                !reverse->field28f) {
                                group->leader = reverse;
                                goto reversed;
                            }
                        } while (--i >= 0);
                    }
                } else {
                    count = group->memberCount;
                    i = 0;
                    if (i < count) {
                        do {
                            member = group->members[i];
                            if (member->object && (member->flags & 0x80080000) == 0x80080000 &&
                                !member->field28f) {
                                group->leader = member;
                                goto reversed;
                            }
                        } while (++i < group->memberCount);
                    }
                }
            reversed:
                return 1;
            }
        } else {
            nodes = row->path->nodes;
            other = &nodes[currentNext->nodes[0]];
            distance = fn_8000BDD0(&other->position, &nodes[currentNext->nodes[1]].position, &centre);
            if (distance <= group->radius * group->radius) {
                row->flags |= 0x40000000;
            }
        }
    }
    if (row->flags & 0x40000000) {
        angle = row->next->rotation;
        if (row->nextDirection) {
            angle = NuAngAdd(angle, 0x8000);
        }
        angle = NuAngSub(angle, row->rotation);
        step = group->rotationSpeed;
        if (angle > step) {
            angle = step;
        } else if (angle < -step) {
            angle = -step;
        } else {
            row->flags &= ~0x40000000;
            row->connection = row->next;
            row->direction = row->nextDirection;
            row->next = 0;
        }
        row->rotation = NuAngAdd(angle, row->rotation);
        NuVecRotateY(&rotated, &offset, row->rotation);
        NuVecSub(&row->position, &centre, &rotated);
    } else if (!(group->flags.word & 0x08000000)) {
        position = &row->position;
        angle = row->connection->rotation;
        if (row->direction) {
            angle = NuAngAdd(angle, 0x8000);
        }
        angle = NuAngSub(angle, row->rotation);
        step = group->rotationSpeed;
        if (angle > step) {
            angle = step;
        } else if (angle < -step) {
            angle = -step;
        }
        row->rotation = NuAngAdd(angle, row->rotation);
        rotated.x = 0.0f;
        rotated.y = 0.0f;
        rotated.z = 0.0f;
        if (lbl_80408D38) {
            rotated.z = ((f32 (*)(struct airowobject_s *))lbl_80408D38)(leader);
        }
        NuVecRotateY(&rotated, &rotated, row->rotation);
        NuVecAdd(position, position, &rotated);
        row->position.y = leader->position.y;
    }
    return 0;
}

s32 fn_8008C768(struct airowgroup_s *group, struct airow_s *row,
                struct airow_s *previous, struct airowobject_s *leader)
{
    struct aiffvec_s rotated;
    struct aiffvec_s offset;
    struct aiffvec_s centre;
    struct aiffvec_s *position;
    struct aiwdpath_s *path;
    struct aiwdcnx_s *current;
    struct aiwdnode_s *node;
    struct aiwdnode_s *nodes;
    struct aiwdcnx_s *candidate;
    struct aiwdcnx_s *replacement;
    struct airowpacket_s *leaderPacket;
    s32 count;
    struct airowobject_s *member, *reverse;
    u8 nodeIndex;
    u8 fromNode;
    u8 cnxIdx;
    s32 offsetIndex, sourceNodeIndex, nextNodeIndex;
    struct aiwdcnx_s *turnConnection, *turnNext;
    struct aiwdcnx_s *currentNext, *begin;
    struct aiwdcnx_s *postNext;
    struct aiwdnode_s *other;
    s32 direction;
    s32 currentAngle;
    s32 angle;
    s32 step;
    s32 i;
    f32 distance;

    if (row->connection) {
        current = row->connection;
        nodeIndex = current->nodes[row->direction == 0];
        path = row->path;
        if (!row->next) {
            if (previous) {
                replacement = previous->connection;
                if (current == replacement) {
                    replacement = previous->next;
                }
                row->next = replacement;
            } else {
                if (group->leader) {
                    leaderPacket = group->leader->packet;
                    if (leaderPacket->targetPath == path) {
                        fromNode = nodeIndex;
                        if (leaderPacket->targetT > 0.5f) {
                            nodeIndex = leaderPacket->targetCnx->nodes[1];
                        } else {
                            nodeIndex = leaderPacket->targetCnx->nodes[0];
                        }
                        cnxIdx = path->routeTable[fromNode][nodeIndex];
                        if (cnxIdx != 0xff) {
                            candidate = path->nodes[fromNode].connections[cnxIdx];
                            row->next = candidate;
                            direction = 1;
                            if (candidate->nodes[0] == fromNode) {
                                direction = 0;
                            }
                            if (candidate->blocked[direction]) {
                                row->next = 0;
                            }
                        }
                    }
                }
            }
            postNext = row->next;
            if (!postNext) {
                goto noNext;
            }
            {
                direction = 1;
                if (postNext->nodes[0] == nodeIndex) {
                    direction = 0;
                }
                if (postNext->blocked[direction] == 0) {
                    if (row->direction) {
                        currentAngle = NuAngAdd(0x8000, row->connection->rotation);
                    } else {
                        currentAngle = row->connection->rotation;
                    }
                    offsetIndex = row->direction;
                    turnConnection = row->connection;
                    turnNext = row->next;
                    sourceNodeIndex = turnConnection->nodes[offsetIndex == 0];
                    nextNodeIndex = turnNext->nodes[0];
                    if (sourceNodeIndex == nextNodeIndex) {
                        row->nextDirection = 0;
                        angle = turnNext->rotation;
                    } else {
                        row->nextDirection = 1;
                        angle = NuAngAdd(0x8000, turnNext->rotation);
                    }
                    if (NuAngSub(angle, currentAngle) < 0) {
                        row->flags |= 0x80000000;
                    } else {
                        row->flags &= ~0x80000000;
                    }
                }
            }
        }
        if (row->next) {
            offset.y = 0.0f;
            offset.z = 0.0f;
            if (row->flags & 0x80000000) {
                offset.x = -group->radius;
            } else {
                offset.x = group->radius;
            }
            NuVecRotateY(&rotated, &offset, row->rotation);
            NuVecAdd(&centre, &rotated, &row->position);

            if (!(row->flags & 0x40000000)) {
                begin = row->connection;
                currentNext = row->next;
                if (begin == currentNext) {
                    node = &row->path->nodes[currentNext->nodes[row->direction == 0]];
                    distance = fn_8000CDFC(&row->position, &node->position, &rotated);
                    if (distance < node->radiusSquared) {
                        i = 0;
                        if (i < group->rowCount) {
                            do {
                                group->rows[i].next = 0;
                                group->rows[i].rotation = NuAngAdd(group->rows[i].rotation, 0x8000);
                                group->rows[i].direction = !group->rows[i].direction;
                            } while (++i < group->rowCount);
                        }
                        group->leader = 0;
                        group->flags.bits.reversed = !group->flags.bits.reversed;
                        if (group->flags.bits.reversed) {
                            i = group->memberCount - 1;
                            if (i >= 0) {
                                do {
                                    reverse = group->members[i];
                                    if (reverse && (reverse->flags & 0x80080000) == 0x80080000 &&
                                        !reverse->field28f) {
                                        group->leader = reverse;
                                        goto reversed;
                                    }
                                } while (--i >= 0);
                            }
                        } else {
                            count = group->memberCount;
                            i = 0;
                            if (i < count) {
                                do {
                                    member = group->members[i];
                                    if (member->object && (member->flags & 0x80080000) == 0x80080000 &&
                                        !member->field28f) {
                                        group->leader = member;
                                        goto reversed;
                                    }
                                } while (++i < group->memberCount);
                            }
                        }
                    reversed:
                        return 1;
                    }
                } else {
                    nodes = row->path->nodes;
                    other = &nodes[currentNext->nodes[0]];
                    distance = fn_8000BDD0(&other->position, &nodes[currentNext->nodes[1]].position, &centre);
                    if (distance <= group->radius * group->radius) {
                        row->flags |= 0x40000000;
                    }
                }
            }
            if (row->flags & 0x40000000) {
                angle = row->next->rotation;
                if (row->nextDirection) {
                    angle = NuAngAdd(angle, 0x8000);
                }
                angle = NuAngSub(angle, row->rotation);
                step = group->rotationSpeed;
                if (angle > step) {
                    angle = step;
                } else if (angle < -step) {
                    angle = -step;
                } else {
                    row->flags &= ~0x40000000;
                    row->connection = row->next;
                    row->direction = row->nextDirection;
                    row->next = 0;
                }
                row->rotation = NuAngAdd(angle, row->rotation);
                NuVecRotateY(&rotated, &offset, row->rotation);
                NuVecSub(&row->position, &centre, &rotated);
            } else if (!(group->flags.word & 0x08000000)) {
                position = &row->position;
                angle = row->connection->rotation;
                if (row->direction) {
                    angle = NuAngAdd(angle, 0x8000);
                }
                angle = NuAngSub(angle, row->rotation);
                step = group->rotationSpeed;
                if (angle > step) {
                    angle = step;
                } else if (angle < -step) {
                    angle = -step;
                }
                row->rotation = NuAngAdd(angle, row->rotation);
                rotated.x = 0.0f;
                rotated.y = 0.0f;
                rotated.z = 0.0f;
                if (lbl_80408D38) {
                    rotated.z = ((f32 (*)(struct airowobject_s *))lbl_80408D38)(leader);
                }
                NuVecRotateY(&rotated, &rotated, row->rotation);
                NuVecAdd(position, position, &rotated);
                row->position.y = leader->position.y;
            }
        } else {
        noNext:
            if (row->direction) {
                if (row->t < 0.0f) {
                    return 1;
                }
            } else {
                if (row->t > 1.0f) {
                    return 1;
                }
            }
            angle = row->connection->rotation;
            if (row->direction) {
                angle = NuAngAdd(angle, 0x8000);
            }
            angle = NuAngSub(angle, row->rotation);
            step = group->rotationSpeed;
            if (angle > step) {
                angle = step;
            } else if (angle < -step) {
                angle = -step;
            }
            row->rotation = NuAngAdd(angle, row->rotation);
            rotated.x = 0.0f;
            rotated.y = 0.0f;
            rotated.z = 0.0f;
            if (lbl_80408D38) {
                rotated.z = ((f32 (*)(struct airowobject_s *))lbl_80408D38)(leader);
            }
            NuVecRotateY(&rotated, &rotated, row->rotation);
            NuVecAdd(&row->position, &row->position, &rotated);
            row->position.y = leader->position.y;
        }
    }
    return 0;
}

struct aimtdcnx_s {
    u8 nodes[2];
    u8 pad2[2];
    u32 blocked[2];
    u8 padc[0xa];
    u16 routemask;
    f32 distance;
};

struct aimtdnode_s {
    u8 pad0[4];
    struct airtvec_s position;
    u8 pad10[0x1a];
    u8 hasSpecial;
    u8 pad2b[0x29];
    u16 membership;
    u16 boundary;
};

struct aimtdpath_s {
    u8 pad0[0x14];
    u8 routeCount;
    u8 pad15[0x63];
    struct aimtdnode_s *nodes;
};

struct aimtdpacket_s {
    u8 pad0[0x80];
    struct airtvec_s dest;
    f32 stopping;
    u8 pad90[0x70];
    struct airtvec_s terrain;
    struct aimtdpath_s *path;
    struct aimtdcnx_s *cnx;
    u8 direction;
    u8 pad115[3];
    u32 pathflags;
    f32 dist;
    u8 pad120[0x10];
    struct aimtdnode_s *goal;
    u8 pad134[0x18];
    struct airtvec_s right;
    struct airtvec_s left;
    u8 pad164[4];
    u16 routeMask;
    u8 route;
    u8 nextRoute;
    u8 pad16c[4];
    struct airtvec_s fallback;
    f32 fallbackstop;
    f32 param;
    struct aimtdpath_s *fpath;
    struct aimtdcnx_s *fcnx;
    u8 pad18c[8];
    f32 fdist;
    u8 pad198[8];
    u32 flags;
    u32 flags2;
    u8 pad1a8[4];
    u32 capabilities;
    u32 frameState;
};

struct aimtdobject_s {
    u8 pad0[0x6c];
    struct airtvec_s position;
    u8 pad78[0x44];
    f32 radius;
    u8 padc0[0x1c2];
    s16 platformId;
    u8 pad284[0xd];
    u8 field291;
    u8 pad292[2];
    u16 flags294;
};

extern f32 lbl_80408D60;
extern f32 lbl_80408D64;
extern s32 (*lbl_80408D9C)(struct aimvpacket_s *, struct aimvobject_s *, s32);

void fn_8008CF0C(void *system, struct aimvpacket_s *packetArg, struct aimvobject_s *objectArg, s32 checks)
{
    struct aimtdpacket_s *packet = (struct aimtdpacket_s *)packetArg;
    struct aimtdobject_s *object = (struct aimtdobject_s *)objectArg;
    struct airtvec_s offset;
    struct airtvec_s target;
    struct airtvec_s diff;
    f32 endDist[2];
    s32 direction = 0;
    struct aimtdpath_s *path = packet->path;
    struct aimtdcnx_s *dcnx = packet->fcnx;
    struct aimtdcnx_s *cnx = packet->cnx;
    struct aimtdcnx_s *next;
    struct aimtdcnx_s *prevNext;
    struct aimtdnode_s *shared;
    u32 triedRoutes = 0;
    f32 distSq;
    f32 param;
    f32 destA;
    f32 destB;
    f32 best = 3.4028235e38f;
    u8 goalIdx;
    s32 searching;
    u64 cflags;
    s32 useLeft;
    s32 angle;

    distSq = fn_8000CD08(&packet->fallback, &object->position, &diff);
    if (object->platformId == -1 ||
        (path->nodes[cnx->nodes[0]].hasSpecial != 0 && path->nodes[cnx->nodes[1]].hasSpecial != 0)) {
        if (packet->param != 0.0f && diff.y < lbl_80408D60 && diff.y > lbl_80408D64 &&
            distSq < packet->param * packet->param) {
            packet->dest = object->position;
            packet->stopping = 0.0f;
            return;
        }
    }

    if (packet->path != packet->fpath || packet->fcnx == 0) {
        packet->dest = packet->fallback;
        packet->stopping = 0.0f;
        return;
    }

    if (packet->cnx != packet->fcnx) {
        if (fn_8008ACD8(system, (f32 *)&packet->terrain, (struct aiinspath_s *)packet->path,
                        (struct aiinscnx_s *)packet->fcnx, checks, (struct aiinscnx_s *)packet->cnx,
                        packet->route, object->field291, 0, object->radius, 0) != 0) {
            if (packet->fcnx->nodes[0] == packet->cnx->nodes[0] ||
                packet->fcnx->nodes[0] == packet->cnx->nodes[1]) {
                direction = 0;
            } else {
                direction = 1;
            }
            AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position,
                                     (struct aiscxcnx_s *)packet->fcnx, direction);
        }
        if (packet->cnx != packet->fcnx) {
            direction = packet->direction;
            best = 3.4028235e38f;
            param = packet->dist;
            goalIdx = dcnx->nodes[0];
            if (param > 1.0f) {
                param = 1.0f;
            } else if (param < 0.0f) {
                param = 0.0f;
            }
            endDist[0] = fn_8000ED40(param * cnx->distance);
            endDist[1] = fn_8000ED40((1.0f - param) * cnx->distance);
            destA = fn_8000ED40(packet->fdist * dcnx->distance);
            destB = fn_8000ED40((1.0f - packet->fdist) * dcnx->distance);
            if (packet->route != 0xff) {
                packet->flags |= 0x400;
            }
            searching = 1;
            do {
                if (packet->route != 0xff && !((s32)((u64)dcnx->routemask >> packet->route) & 1)) {
                    shared = &path->nodes[dcnx->nodes[0]];
                    if ((s32)((u64)(shared->membership & ~shared->boundary) >> packet->route) & 1) {
                        destA = 3.4028235e38f;
                    }
                    shared = &path->nodes[dcnx->nodes[1]];
                    if ((s32)((u64)(shared->membership & ~shared->boundary) >> packet->route) & 1) {
                        destB = 3.4028235e38f;
                    }
                }
                if (!(cnx->blocked[packet->direction] & 0x40000000)) {
                    param = fn_8008A370((struct airtpath_s *)packet->path, cnx->nodes[packet->direction == 0],
                                        dcnx->nodes[0], packet->route, 0) +
                            endDist[packet->direction == 0] + destA;
                    if (param < best) {
                        best = param;
                        goalIdx = dcnx->nodes[0];
                        direction = packet->direction;
                        packet->flags &= ~0x400;
                    }
                    param = fn_8008A370((struct airtpath_s *)packet->path, cnx->nodes[packet->direction == 0],
                                        dcnx->nodes[1], packet->route, 0) +
                            endDist[packet->direction == 0] + destB;
                    if (param < best) {
                        best = param;
                        goalIdx = dcnx->nodes[1];
                        direction = packet->direction;
                        packet->flags &= ~0x400;
                    }
                }
                if (!(cnx->blocked[packet->direction == 0] & 0x40000000)) {
                    param = fn_8008A370((struct airtpath_s *)packet->path, cnx->nodes[packet->direction],
                                        dcnx->nodes[0], packet->route, 0) +
                            endDist[packet->direction] + destA;
                    if (param < best) {
                        goalIdx = dcnx->nodes[0];
                        best = param;
                        direction = packet->direction == 0;
                        packet->flags &= ~0x400;
                    }
                    param = fn_8008A370((struct airtpath_s *)packet->path, cnx->nodes[packet->direction],
                                        dcnx->nodes[1], packet->route, 0) +
                            endDist[packet->direction] + destB;
                    if (param < best) {
                        goalIdx = dcnx->nodes[1];
                        best = param;
                        direction = packet->direction == 0;
                        packet->flags &= ~0x400;
                    }
                }
                if (packet->flags & 0x400) {
                    if (packet->route != 0xff) {
                        triedRoutes |= 1 << packet->route;
                    }
                    aiSysFindRoute((struct aiscxpacket_s *)packet);
                    if ((triedRoutes >> packet->route) & 1) {
                        return;
                    }
                    destA = fn_8000ED40(packet->fdist * dcnx->distance);
                    destB = fn_8000ED40((1.0f - packet->fdist) * dcnx->distance);
                } else {
                    searching = 0;
                }
            } while (searching);
            packet->goal = &path->nodes[goalIdx];
            prevNext = 0;
            AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position,
                                     (struct aiscxcnx_s *)cnx, direction);
            next = (struct aimtdcnx_s *)fn_8008B79C((struct airtpacket_s *)packet, &direction);
            if (next != 0) {
                while (next != 0 && next != prevNext &&
                       fn_8008ACD8(system, (f32 *)&packet->terrain, (struct aiinspath_s *)packet->path,
                                   (struct aiinscnx_s *)next, checks, (struct aiinscnx_s *)packet->cnx,
                                   packet->route, object->field291, 0, object->radius, 0) != 0 &&
                       cnx != dcnx) {
                    cnx = next;
                    prevNext = cnx;
                    AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position,
                                             (struct aiscxcnx_s *)cnx, direction);
                    if (packet->cnx == cnx && packet->direction == direction) {
                        next = (struct aimtdcnx_s *)fn_8008B79C((struct airtpacket_s *)packet, &direction);
                    } else {
                        next = 0;
                    }
                }
            } else {
                u32 bf;
                u64 bf64;
                next = dcnx;
                bf = (next->blocked[0] | next->blocked[1]) & 0xdfffffff;
                bf64 = bf;
                if ((bf64 & 0xd8000000) == 0 && (bf == 0 || (bf & packet->capabilities))) {
                    if (fn_8008ACD8(system, (f32 *)&packet->terrain, (struct aiinspath_s *)packet->path,
                                    (struct aiinscnx_s *)next, checks, (struct aiinscnx_s *)packet->cnx,
                                    packet->route, object->field291, 0, object->radius, 0) != 0) {
                        AISysCharacterSetPathCnx((struct aiscxpacket_s *)packet, (f32 *)&object->position,
                                                 (struct aiscxcnx_s *)next, 0);
                    }
                }
            }
        }
    }

    if (lbl_80408D9C != 0) {
        if (cnx != dcnx) {
            packet->flags |= 2;
        }
        if (lbl_80408D9C((struct aimvpacket_s *)packet, (struct aimvobject_s *)object, checks) != 0) {
            packet->flags |= 0x801;
            return;
        }
    }

    cnx = packet->cnx;
    if (cnx->blocked[packet->direction] & 0xd8000000) {
        packet->dest = path->nodes[cnx->nodes[packet->direction]].position;
        packet->stopping = 0.0f;
        packet->flags |= 0x100;
        packet->frameState = cnx->blocked[packet->direction];
        return;
    }

    if (cnx == dcnx && (packet->route == 0xff || ((s32)((u64)cnx->routemask >> packet->route) & 1))) {
        if (packet->pathflags & 0x8000) {
            if (packet->param != 0.0f) {
                if (distSq < packet->param * packet->param) {
                    packet->dest = object->position;
                    packet->stopping = 0.0f;
                    return;
                }
                NuVecScale(&diff, &diff, packet->param / NuFsqrt(distSq));
                packet->dest.x = packet->fallback.x - diff.x;
                packet->dest.y = packet->fallback.y;
                packet->dest.z = packet->fallback.z - diff.z;
                if (packet->param > packet->fallbackstop) {
                    packet->stopping = 0.0f;
                    return;
                }
                packet->stopping = packet->fallbackstop;
                return;
            }
        }
        packet->dest = packet->fallback;
        packet->stopping = packet->fallbackstop;
        return;
    }

    if (cnx->nodes[0] == dcnx->nodes[0]) {
        shared = &path->nodes[dcnx->nodes[0]];
        direction = 0;
    } else if (cnx->nodes[0] == dcnx->nodes[1]) {
        shared = &path->nodes[dcnx->nodes[1]];
        direction = 1;
    } else if (cnx->nodes[1] == dcnx->nodes[0]) {
        shared = &path->nodes[cnx->nodes[1]];
        direction = 0;
    } else if (cnx->nodes[1] == dcnx->nodes[1]) {
        shared = &path->nodes[cnx->nodes[1]];
        direction = 1;
    } else {
        shared = 0;
    }

    if (shared != 0) {
        if (packet->route != 0xff && !((s32)((u64)dcnx->routemask >> packet->route) & 1) &&
            !((s32)((u64)shared->boundary >> packet->route) & 1)) {
            shared = 0;
        }
    }
    if (shared != 0) {
        next = dcnx;
    } else {
        next = (struct aimtdcnx_s *)fn_8008B79C((struct airtpacket_s *)packet, &direction);
    }

    if (next != 0) {
        u32 cf = next->blocked[direction];
        cflags = cf;
        if (cflags & ~0x20000000ULL) {
            if (cf & 0xd8000000) {
                packet->dest = object->position;
                packet->stopping = 0.0f;
                packet->flags |= 0x100;
                packet->frameState = next->blocked[direction];
                return;
            }
            if (!(cf & packet->capabilities)) {
                packet->flags |= 0x300;
                packet->frameState = next->blocked[direction];
                next = 0;
            } else {
                object->flags294 |= 0x800;
                packet->flags2 |= 0x40000000;
            }
        }
        if (next != 0) {
            if (next == dcnx) {
                target = packet->fallback;
            } else {
                target = path->nodes[next->nodes[direction]].position;
                packet->flags |= 0x800;
            }
            if (fn_8008ACD8(system, (f32 *)&target, (struct aiinspath_s *)packet->path,
                            (struct aiinscnx_s *)cnx, checks, (struct aiinscnx_s *)packet->cnx,
                            packet->route, object->field291, 0, object->radius, 0) == 0) {
                if (fn_8008BCC0(system, (struct aiinspacket_s *)packet, (struct aiinsobject_s *)object,
                                (struct aiinscnx_s *)cnx, (struct aiinscnx_s *)next) != 0) {
                    useLeft = 0;
                    if (packet->flags & 0x02000000) {
                        NuVecSub(&offset, &packet->left, &object->position);
                        angle = fn_8000ABDC(offset.x, offset.z);
                        NuVecSub(&offset, &target, &object->position);
                        if (NuAngSub(fn_8000ABDC(offset.x, offset.z), angle) < 0) {
                            useLeft = 1;
                            target = packet->left;
                            packet->flags |= 0x800;
                        }
                    }
                    if (!useLeft && (packet->flags & 0x04000000)) {
                        NuVecSub(&offset, &packet->right, &object->position);
                        angle = fn_8000ABDC(offset.x, offset.z);
                        NuVecSub(&offset, &target, &object->position);
                        if (NuAngSub(fn_8000ABDC(offset.x, offset.z), angle) > 0) {
                            target = packet->right;
                            packet->flags |= 0x800;
                        }
                    }
                } else {
                    target = path->nodes[next->nodes[direction]].position;
                }
            }
            packet->dest = target;
            packet->stopping = 0.0f;
            return;
        }
    }

    packet->dest = path->nodes[packet->cnx->nodes[packet->direction == 0]].position;
    packet->stopping = 0.0f;
    if (fn_8000CD08(&packet->dest, &object->position, &offset) < 1.0f) {
        packet->dest = object->position;
    }
}
