#include "game/ai.h"
#include "nucore/nufpar.h"

/* AI script loader (`AIScript*`, `ScriptKeyword_*`). Shapes follow OpenSaga's
 * src/legoapi/ai/core/aisysall.cpp (a later engine); offsets are from GC accesses. */

struct AIPARAM_s {
    char *name;
    f32 default_val;
};

struct AILIST_s {
    void *head;
    void *tail;
};

struct AISTATE_s {
    u8 node[8];
    struct AILIST_s conditions; /* 0x08 */
    u8 unk10[8];
    char *name; /* 0x18 */
    struct AILIST_s ref_scripts; /* 0x1C */
};

struct AIREFSCRIPT_s {
    u8 node[8];
    char *name; /* 0x08 */
    u8 unkC[4];
    char *return_state_name; /* 0x10 */
    u8 unk14[4];
    u32 check_global_scripts : 1; /* 0x18 */
    u32 check_level_scripts : 1;
    struct AILIST_s conditions; /* 0x1C */
};

struct AISCRIPT_s {
    u8 unk0[0xC];
    char *script; /* 0x0C */
    struct AILIST_s states; /* 0x10 */
    struct AIPARAM_s params[4]; /* 0x18 */
    u8 unk38[4];
    u32 flags; /* 0x3C */
};

void (*fn_80009948(char *file, s32 line))();
void (*fn_8000995C(char *file, s32 line))();
char *NuStrIStr(char *haystack, char *needle);
void AIScriptParseConditions(struct nufpar_s *parser);
s32 NuStrLen(char *s);
s32 NuStrCpy(char *dst, char *src);
s32 NuStrICmp(char *, char *);
void *memset();
s32 fn_80006398(struct nufpar_s *parser); /* NuFParGetLine */
void NuWaterRender(struct nufpar_s *parser); /* NuFParInterpretWord (symbol misnamed) */
void fn_80007610(struct AILIST_s *list, void *node); /* NuLinkedListAppend */
void fn_80007648(struct AILIST_s *list, void *node); /* NuLinkedListInsert */
u8 *fn_800081CC(u16 *dst, u8 *src);
s32 fn_8001FBB0(s32);
s32 fn_800203A4(void *, f32);
void *fn_80024BF0(s32);
s32 fn_80024CD4(void *);
void *fn_8002C460(void *, void *, s32, s32, void *, void *);
s32 fn_8002CB8C(void *);
u16 fn_8002CD7C(void *, s32);
void *fn_8002CDF0(void *, s32, s32, void *, void *);
s32 fn_80042730();
s32 fn_8007A448();

extern char str_SourceFile_AIScriptC[];
extern char str_AIScriptBufferAlloc_BufferTooSmall[];
extern char str_AIScriptBufferAlloc_NoBuffer[];
extern char str_ScriptState_Base_2[];
extern char str_ScriptToken_CloseBrace[];
extern char str_ScriptSection_Conditions[];
extern char str_ScriptSource_Script[];
extern char str_ScriptSource_Source[];
extern char str_ScriptSource_Global[];
extern char str_ScriptSource_Level[];
extern char str_ScriptState_ReturnState[];
extern char str_ScriptCmd_xRefScript[];
extern f32 lbl_8019BC44[];
extern struct nufpcom_s lbl_801BC040[]; /* cfgtab_State */

extern s32 lbl_80408224;
extern s32 lbl_80408234;
extern s32 lbl_80408BDC;
extern s32 lbl_80408C48;
extern s32 lbl_80408C4C;
extern s32 lbl_80408C68;
extern s32 lbl_80408C78;
extern void *lbl_80408C7C; /* current font */
extern void *lbl_80408C80;
extern void *lbl_80408C84;
extern void *lbl_80408C88;
extern void *lbl_80408C8C;
extern s32 lbl_80408C90;
extern s32 lbl_80408C94;
extern s32 lbl_80408C98;
extern s32 lbl_80408C9C;
extern s32 lbl_80408CA4;
extern s32 lbl_80408CB4;
extern u32 *lbl_80408CB8; /* load_buff */
extern u32 *lbl_80408CBC; /* load_endbuff */
extern struct AISCRIPT_s *lbl_80408CC0; /* load_aiscript */
extern struct AISTATE_s *lbl_80408CC4; /* load_aistate */
extern struct AILIST_s *lbl_80408CD0; /* load_refscripthdr */
extern struct AILIST_s *lbl_80408CD4; /* load_conditionshdr */
extern void *lbl_8040AF28;

void fn_8007AC80(void *, f32, f32, f32, f32, f32, f32, s32, u8, u8, u8, u8);

static inline void *AIScriptBufferAlloc(u32 *buf, u32 *buf_end, u32 size)
{
    u32 ret = 0;
    if (buf != NULL && buf_end != NULL) {
        if (*buf + size < *buf_end) {
            ret = (*buf + 15) & ~15;
            *buf = ret + size;
        } else {
            fn_80009948(str_SourceFile_AIScriptC, 0x2D4)(str_AIScriptBufferAlloc_BufferTooSmall);
        }
    } else {
        fn_80009948(str_SourceFile_AIScriptC, 0x2D7)(str_AIScriptBufferAlloc_NoBuffer);
    }
    return (void *)ret;
}

static inline char *AIScriptCopyString(char *str, u32 *buf, u32 *buf_end)
{
    char *dst = NULL;
    s32 len;
    if (str != NULL) {
        len = NuStrLen(str);
        if (len != 0) {
            dst = AIScriptBufferAlloc(buf, buf_end, len + 1);
            NuStrCpy(dst, str);
        }
    }
    return dst;
}

void fn_8007AC0C(void)
{
    fn_80042730();
    if (lbl_80408224 != 0) {
        lbl_80408C4C = 1;
    }
    fn_8007A448();
}

s32 fn_8007AC44(void)
{
    if (lbl_80408C68 != 0 && lbl_80408C48 != 0 && lbl_80408234 != -1) {
        lbl_80408BDC = 1;
        return 1;
    }
    return 0;
}

s32 fn_8007BC74(void *name, void *texname, void *buf, void *end, s32 size)
{
    lbl_80408C7C = fn_8002C460(name, texname, 4, size, buf, end);
    if (lbl_80408C90 != 0) {
        lbl_80408C80 = fn_8002CDF0(lbl_80408C7C, 4, size - 1, buf, end);
    }
    if (lbl_80408C94 != 0) {
        lbl_80408C84 = fn_8002CDF0(lbl_80408C7C, 4, 0x40000, buf, end);
    }
    if (lbl_80408C98 != 0) {
        lbl_80408C88 = fn_8002CDF0(lbl_80408C7C, 0x18, size, buf, end);
    }
    if (lbl_80408C9C != 0) {
        lbl_80408C8C = fn_8002CDF0(lbl_80408C7C, 0x4C, size, buf, end);
    }
    lbl_80408CA4 = 1;
    return lbl_80408C78;
}

void fn_8007BD64(u8 *s, u16 *out)
{
    u16 c;

    if (*s != 0) do {
        s = fn_800081CC(&c, s);
        if (c == 0x7E) {
            if (*s == 0) {
                break;
            }
            s = fn_800081CC(&c, s);
        } else {
            *out = fn_8002CD7C(lbl_80408C7C, c);
            if (*out == 0xFFFF) {
                *out = fn_8002CD7C(lbl_80408C7C, 0x3F);
            }
            out++;
        }
    } while (*s != 0);
    *out = 0;
}

void fn_8007BE20(void *text, s32 a1, u8 a2, u8 a3, u8 a4, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5)
{
    fn_8007AC80(text, f0, f1, f2, f3, f4, f5, a1, a2, a3, a4, 0x80);
}

void fn_8007BE44(void *text, f32 f0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, s32 a1, u8 a2, u8 a3, u8 a4, u8 a5)
{
    void *old;

    if (lbl_80408C80 != NULL) {
        old = lbl_80408C7C;
        lbl_80408C7C = lbl_80408C80;
        fn_8002CB8C(lbl_80408C80);
        fn_8007AC80(text, f0, f1, f2, f3, f4, f5, a1, a2, a3, a4, a5);
        lbl_80408C7C = old;
        fn_8002CB8C(old);
    }
}

void fn_8007BF24(void)
{
    fn_8001FBB0(3);
    fn_8002CB8C(lbl_80408C7C);
    fn_800203A4(lbl_80408C7C, lbl_8019BC44[0]);
}

void fn_8007BF60(void)
{
    u8 *mtl;

    mtl = fn_80024BF0(1);
    lbl_8040AF28 = mtl;
    mtl[0xBE] = 3;
    ((u8 *)lbl_8040AF28)[0xB9] = 1;
    ((u8 *)lbl_8040AF28)[0xBF] = 2;
    ((u8 *)lbl_8040AF28)[0xBB] = 1;
    ((u8 *)lbl_8040AF28)[0xBC] = 1;
    ((u8 *)lbl_8040AF28)[0xC0] = 1;
    ((u8 *)lbl_8040AF28)[0xB8] = 1;
    fn_80024CD4(lbl_8040AF28);
    lbl_80408CB4 = 1;
}

void ScriptKeyword_PARAM(struct nufpar_s *parser)
{
    u32 idx;

    if (lbl_80408CC0 != NULL) {
        idx = NuFParGetInt(parser);
        if (idx < 4 && NuFParGetWord(parser) != 0) {
            lbl_80408CC0->params[idx].name = AIScriptCopyString((char *)parser->word.b, lbl_80408CB8, lbl_80408CBC);
            lbl_80408CC0->params[idx].default_val = NuFParGetFloat(parser);
        }
    }
}

void ScriptKeyword_STATE(struct nufpar_s *parser)
{
    if (lbl_80408CC0 != NULL && NuFParGetWord(parser) != 0) {
        lbl_80408CC4 = AIScriptBufferAlloc(lbl_80408CB8, lbl_80408CBC, sizeof(struct AISTATE_s));
        lbl_80408CD0 = &lbl_80408CC4->ref_scripts;
        if (lbl_80408CC4 != NULL) {
            memset(lbl_80408CC4, 0, sizeof(struct AISTATE_s));
            lbl_80408CC4->name = AIScriptCopyString((char *)parser->word.b, lbl_80408CB8, lbl_80408CBC);
            if (NuStrICmp(lbl_80408CC4->name, str_ScriptState_Base_2) == 0) {
                fn_80007648(&lbl_80408CC0->states, lbl_80408CC4);
            } else {
                fn_80007610(&lbl_80408CC0->states, lbl_80408CC4);
            }
            NuFParPushCom(parser, lbl_801BC040);
            while (fn_80006398(parser) != 0) {
                NuFParGetWord(parser);
                lbl_80408CD4 = &lbl_80408CC4->conditions;
                NuWaterRender(parser);
            }
            NuFParPopCom(parser);
            lbl_80408CD0 = NULL;
            lbl_80408CC4 = NULL;
            lbl_80408CD4 = NULL;
        }
    }
}

#define AISCRIPT_UTF8_CONT(c) ((u8)((c) + 0x80) <= 0x3F)
#define AISCRIPT_IS_BREAK(c, p) \
    (((c) == ' ' && (p)[1] != '!' && (p)[1] != '?') || ((c) == '.' && (p)[1] != '.') || \
     (u32)((c) - ',') <= 1)

s32 fn_8007B0C4(u8 *s, s32 pos)
{
    s32 fwd;
    s32 back;
    s32 len;
    s32 last;
    s32 i;
    u8 *pf;
    u8 *pb;
    u8 c;

    while (AISCRIPT_UTF8_CONT(s[pos])) {
        pos--;
    }
    back = fwd = pos;
    len = NuStrLen((char *)s);
    pb = s + pos;
    last = len - 1;
    i = 0;
    pf = pb;
    do {
        if (fwd < len) {
            c = pf[0];
            if (AISCRIPT_IS_BREAK(c, pf)) {
                goto found_fwd;
            }
        }
        if (fwd < last) {
            pf++;
            fwd++;
        }
        while (AISCRIPT_UTF8_CONT(*pf)) {
            pf++;
            fwd++;
        }
        if (back >= 0) {
            c = pb[0];
            if (AISCRIPT_IS_BREAK(c, pb)) {
                goto found_back;
            }
            if (back > 0) {
                pb--;
                back--;
            }
        }
        while (AISCRIPT_UTF8_CONT(*pb)) {
            pb--;
            back--;
        }
    } while (++i <= 10);
    if (s[pos] == '~') {
        if (pos > 0 && s[pos - 1] == '~') {
            pos--;
        }
    } else if (pos > 0 && s[pos - 1] == '~' && pos > 1 && s[pos - 2] != '~') {
        pos--;
    }
    return pos;
found_fwd:
    return fwd;
found_back:
    return back;
}

void fn_8007CC34(struct nufpar_s *parser)
{
    s32 done = 0;
    char *str;

    if (lbl_80408CC0 != NULL && lbl_80408CC0->script == NULL) {
        lbl_80408CC0->flags &= ~0x20000000;
        while (!done && fn_80006398(parser) != 0) {
            while (!done && NuFParGetWord(parser) != 0) {
                if (NuStrICmp((char *)parser->word.b, str_ScriptToken_CloseBrace) == 0) {
                    done = 1;
                } else if ((str = NuStrIStr((char *)parser->word.b, str_ScriptSource_Script)) != NULL) {
                    str += 7;
                    lbl_80408CC0->script = AIScriptCopyString(str, lbl_80408CB8, lbl_80408CBC);
                } else if (NuStrIStr((char *)parser->word.b, str_ScriptSource_Source) != NULL) {
                    if (NuStrIStr((char *)parser->word.b, str_ScriptSource_Global) != NULL) {
                        lbl_80408CC0->flags &= ~0x20000000;
                    } else if (NuStrIStr((char *)parser->word.b, str_ScriptSource_Level) != NULL) {
                        lbl_80408CC0->flags |= 0x20000000;
                    }
                }
            }
        }
        if (lbl_80408CC0->script != NULL) {
            lbl_80408CC0->flags |= 0x40000000;
        }
    }
}
