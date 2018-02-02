/* Generated by Nim Compiler v0.17.2 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\nim-0.17.2\dist\mingw64\bin\gcc.exe -c  -w -mno-ms-bitfields  -IC:\nim-0.17.2\lib -o c:\webdev\dmlauto\nim\hello\nimcache\stdlib_strutils.o c:\webdev\dmlauto\nim\hello\nimcache\stdlib_strutils.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef powerpc
#undef unix
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct tyObject_Slice_WC2BEYwxNBO9aTbMc8sJqPg tyObject_Slice_WC2BEYwxNBO9aTbMc8sJqPg;
struct TGenericSeq {
NI len;
NI reserved;
};
struct NimStringDesc {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct tyObject_Slice_WC2BEYwxNBO9aTbMc8sJqPg {
NI a;
NI b;
};
N_NIMCALL(void, reverse_LoixoqZetR6FfezoPedx8w)(NimStringDesc** a, NI aLen_0);
N_NIMCALL(void, reverse_XQiN4wExsmIg8NFBmG3ObA)(NimStringDesc** a, NI aLen_0, NI first, NI last);
static N_INLINE(NIM_BOOL, contains_I9cy9aN2znlBRynMcXN4pBGgstrutils)(NIM_CHAR* a, NI aLen_0, NIM_CHAR item);
static N_INLINE(NI, find_b3HPX1XboPhUmnxkTjazFQstrutils)(NIM_CHAR* a, NI aLen_0, NIM_CHAR item);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NIM_BOOL, contains_tKnjuJQDI4zGjoGUKWyD2wstrutils)(tyObject_Slice_WC2BEYwxNBO9aTbMc8sJqPg s, NI value);
N_NIMCALL(NF, round_FL9bhksfuQsfLDCxRHuknsg)(NF x, NI places);
static N_INLINE(void, stareq__7kHiltrvRlcg6wSYR3CxAwstrutils)(NF* x, NF y);
static N_INLINE(void, pluseq__7kHiltrvRlcg6wSYR3CxAw_2strutils)(NF* x, NF y);
N_NIMCALL(NIM_CHAR, nsuToLowerAsciiChar)(NIM_CHAR c);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(NI, subInt)(NI a, NI b);
extern NIM_THREADVAR TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ b));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI T1_;
	T1_ = (NI)0;
	{
		if (!(framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA4_;
		T1_ = ((NI) 0);
	}
	goto LA2_;
	LA4_: ;
	{
		T1_ = ((NI) ((NI16)((*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1))));
	}
	LA2_: ;
	(*s).calldepth = ((NI16) (T1_));
	(*s).prev = framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9_;
		stackOverflow_II46IjNZztN9bmbxUD8dt8g();
	}
	LA9_: ;
}

static N_INLINE(void, popFrame)(void) {
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).prev;
}

static N_INLINE(NI, find_b3HPX1XboPhUmnxkTjazFQstrutils)(NIM_CHAR* a, NI aLen_0, NIM_CHAR item) {
	NI result;
	nimfr_("find", "system.nim");
{	result = (NI)0;
	{
		NIM_CHAR i;
		NI i_2;
		i = (NIM_CHAR)0;
		nimln_(2078, "system.nim");
		i_2 = ((NI) 0);
		{
			nimln_(2079, "system.nim");
			while (1) {
				NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_2;
				NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_3;
				if (!(i_2 < aLen_0)) goto LA3;
				nimln_(2080, "system.nim");
				if ((NU)(i_2) >= (NU)(aLen_0)) raiseIndexError();
				i = a[i_2];
				nimln_(2312, "system.nim");
				{
					if (!((NU8)(i) == (NU8)(item))) goto LA6_;
					goto BeforeRet_;
				}
				LA6_: ;
				nimln_(2313, "system.nim");
				TM_JGc9b9bh2D3nTdUR7TGyq8aA_2 = addInt(result, ((NI) 1));
				result = (NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_2);
				nimln_(2081, "system.nim");
				TM_JGc9b9bh2D3nTdUR7TGyq8aA_3 = addInt(i_2, ((NI) 1));
				i_2 = (NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_3);
			} LA3: ;
		}
	}
	nimln_(2314, "system.nim");
	result = ((NI) -1);
	}BeforeRet_: ;
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, contains_I9cy9aN2znlBRynMcXN4pBGgstrutils)(NIM_CHAR* a, NI aLen_0, NIM_CHAR item) {
	NIM_BOOL result;
	NI T1_;
	nimfr_("contains", "system.nim");
{	result = (NIM_BOOL)0;
	nimln_(2319, "system.nim");
	T1_ = (NI)0;
	T1_ = find_b3HPX1XboPhUmnxkTjazFQstrutils(a, aLen_0, item);
	result = (((NI) 0) <= T1_);
	goto BeforeRet_;
	}BeforeRet_: ;
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, contains_tKnjuJQDI4zGjoGUKWyD2wstrutils)(tyObject_Slice_WC2BEYwxNBO9aTbMc8sJqPg s, NI value) {
	NIM_BOOL result;
	NIM_BOOL T1_;
	nimfr_("contains", "system.nim");
	result = (NIM_BOOL)0;
	nimln_(1159, "system.nim");
	T1_ = (NIM_BOOL)0;
	T1_ = (((NI) (s.a)) <= ((NI) (value)));
	if (!(T1_)) goto LA2_;
	T1_ = (((NI) (value)) <= ((NI) (s.b)));
	LA2_: ;
	result = T1_;
	popFrame();
	return result;
}

static N_INLINE(void, stareq__7kHiltrvRlcg6wSYR3CxAwstrutils)(NF* x, NF y) {
	nimfr_("*=", "system.nim");
	nimln_(3544, "system.nim");
	(*x) = ((NF)((*x)) * (NF)(y));
	popFrame();
}

static N_INLINE(void, pluseq__7kHiltrvRlcg6wSYR3CxAw_2strutils)(NF* x, NF y) {
	nimfr_("+=", "system.nim");
	nimln_(3534, "system.nim");
	(*x) = ((NF)((*x)) + (NF)(y));
	popFrame();
}

N_NIMCALL(NI, nsuFindChar)(NimStringDesc* s, NIM_CHAR sub, NI start, NI last) {
	NI result;
	NI last_2;
	void* found;
	nimfr_("find", "strutils.nim");
{	result = (NI)0;
	{
		if (!(((NI) (last)) == ((NI) 0))) goto LA3_;
		last_2 = (s ? (s->Sup.len-1) : -1);
	}
	goto LA1_;
	LA3_: ;
	{
		last_2 = ((NI) (last));
	}
	LA1_: ;
	found = memchr(((void*) ((&s->data[start]))), sub, (NI)((NI)(last_2 - ((NI) (start))) + ((NI) 1)));
	{
		if (!!((found == 0))) goto LA8_;
		result = (NI)((NU64)(((NI) (found))) - (NU64)(((NI) (s->data))));
		goto BeforeRet_;
	}
	LA8_: ;
	result = ((NI) -1);
	goto BeforeRet_;
	}BeforeRet_: ;
	popFrame();
	return result;
}

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = (NI)0;
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (a <= i);
		if (!(T3_)) goto LA4_;
		T3_ = (i <= b);
		LA4_: ;
		if (!T3_) goto LA5_;
		result = i;
		goto BeforeRet_;
	}
	goto LA1_;
	LA5_: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1_: ;
	}BeforeRet_: ;
	return result;
}

N_NIMCALL(NIM_CHAR, nsuToLowerAsciiChar)(NIM_CHAR c) {
	NIM_CHAR result;
	nimfr_("toLowerAscii", "strutils.nim");
	result = (NIM_CHAR)0;
	nimln_(209, "strutils.nim");
	{
		NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_4;
		if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA3_;
		nimln_(210, "strutils.nim");
		TM_JGc9b9bh2D3nTdUR7TGyq8aA_4 = addInt(((NI) (((NU8)(c)))), ((NI) 32));
		result = ((NIM_CHAR) (((NI)chckRange((NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_4), ((NI) 0), ((NI) 255)))));
	}
	goto LA1_;
	LA3_: ;
	{
		nimln_(212, "strutils.nim");
		result = c;
	}
	LA1_: ;
	popFrame();
	return result;
}

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

N_NIMCALL(NI, nsuCmpIgnoreCase)(NimStringDesc* a, NimStringDesc* b) {
	NI result;
	NI i;
	NI m;
	NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_7;
	nimfr_("cmpIgnoreCase", "strutils.nim");
{	result = (NI)0;
	nimln_(410, "strutils.nim");
	i = ((NI) 0);
	nimln_(411, "strutils.nim");
	m = (((a ? a->Sup.len : 0) <= (b ? b->Sup.len : 0)) ? (a ? a->Sup.len : 0) : (b ? b->Sup.len : 0));
	{
		nimln_(412, "strutils.nim");
		while (1) {
			NIM_CHAR T3_;
			NIM_CHAR T4_;
			NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_5;
			NI TM_JGc9b9bh2D3nTdUR7TGyq8aA_6;
			if (!(i < m)) goto LA2;
			nimln_(413, "strutils.nim");
			if ((NU)(i) > (NU)(a->Sup.len)) raiseIndexError();
			T3_ = (NIM_CHAR)0;
			T3_ = nsuToLowerAsciiChar(a->data[i]);
			if ((NU)(i) > (NU)(b->Sup.len)) raiseIndexError();
			T4_ = (NIM_CHAR)0;
			T4_ = nsuToLowerAsciiChar(b->data[i]);
			TM_JGc9b9bh2D3nTdUR7TGyq8aA_5 = subInt(((NI) (((NU8)(T3_)))), ((NI) (((NU8)(T4_)))));
			result = (NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_5);
			nimln_(414, "strutils.nim");
			{
				nimln_(378, "system.nim");
				nimln_(414, "strutils.nim");
				if (!!((result == ((NI) 0)))) goto LA7_;
				goto BeforeRet_;
			}
			LA7_: ;
			nimln_(415, "strutils.nim");
			TM_JGc9b9bh2D3nTdUR7TGyq8aA_6 = addInt(i, ((NI) 1));
			i = (NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_6);
		} LA2: ;
	}
	nimln_(416, "strutils.nim");
	TM_JGc9b9bh2D3nTdUR7TGyq8aA_7 = subInt((a ? a->Sup.len : 0), (b ? b->Sup.len : 0));
	result = (NI)(TM_JGc9b9bh2D3nTdUR7TGyq8aA_7);
	}BeforeRet_: ;
	popFrame();
	return result;
}

N_NIMCALL(NIM_BOOL, nsuStartsWith)(NimStringDesc* s, NimStringDesc* prefix) {
	NIM_BOOL result;
	NI i;
	nimfr_("startsWith", "strutils.nim");
{	result = (NIM_BOOL)0;
	i = ((NI) 0);
	{
		while (1) {
			{
				if (!((NU8)(prefix->data[i]) == (NU8)(0))) goto LA5_;
				result = NIM_TRUE;
				goto BeforeRet_;
			}
			LA5_: ;
			{
				if (!!(((NU8)(s->data[i]) == (NU8)(prefix->data[i])))) goto LA9_;
				result = NIM_FALSE;
				goto BeforeRet_;
			}
			LA9_: ;
			i += ((NI) 1);
		}
	}
	}BeforeRet_: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsInit000)(void) {
	nimfr_("strutils", "strutils.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsDatInit000)(void) {
}

