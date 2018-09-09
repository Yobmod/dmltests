/* Generated by Nim Compiler v0.18.0 */
/*   (c) 2018 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, i386, gcc */
/* Command for C compiler:
   gcc.exe -c  -w -mno-ms-bitfields -DWIN32_LEAN_AND_MEAN  -IC:\Users\Yobmod\.choosenim\toolchains\nim-0.18.0\lib -o c:\Webdev\dmltests\nim\jester\nimcache\stdlib_cookies.o c:\Webdev\dmltests\nim\jester\nimcache\stdlib_cookies.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 32

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
typedef struct tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct tyObject_DateTime_S7qec11z7km5Pal3UXrHmw tyObject_DateTime_S7qec11z7km5Pal3UXrHmw;
typedef struct RootObj RootObj;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct tySequence_4eQHGndY6XBYpFOH09apV8Q tySequence_4eQHGndY6XBYpFOH09apV8Q;
typedef struct tyObject_Timezone_g1TRr0fUzr8gtJpVPUSSnA tyObject_Timezone_g1TRr0fUzr8gtJpVPUSSnA;
typedef struct tyObject_ZonedTime_WigfH9apQAxJ69bBPh3wB8RQ tyObject_ZonedTime_WigfH9apQAxJ69bBPh3wB8RQ;
typedef struct tyTuple_UV3llMMYFckfui8YMBuUZA tyTuple_UV3llMMYFckfui8YMBuUZA;
struct TGenericSeq {
NI len;
NI reserved;
};
struct NimStringDesc {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef NU8 tyEnum_StringTableMode_G9c4wVDFIzf0xHmQvxso9a9cQ;
typedef NU8 tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A;
typedef NU8 tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ;
typedef N_NIMCALL_PTR(void, tyProc_ojoeKfW4VYIm36I9cpDTQIg) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ) (void* p);
struct TNimType {
NI size;
tyEnum_TNimKind_jIBKr1ejBgsfM33Kxw4j7A kind;
tySet_tyEnum_TNimTypeFlag_v8QUszD1sWlSIWZz7mC4bQ flags;
TNimType* base;
TNimNode* node;
void* finalizer;
tyProc_ojoeKfW4VYIm36I9cpDTQIg marker;
tyProc_WSm2xU5ARYv9aAR4l0z9c9auQ deepcopy;
};
struct RootObj {
TNimType* m_type;
};
struct tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw {
  RootObj Sup;
NI counter;
tySequence_4eQHGndY6XBYpFOH09apV8Q* data;
tyEnum_StringTableMode_G9c4wVDFIzf0xHmQvxso9a9cQ mode;
};
typedef NU8 tyEnum_Month_JS0JuFvCBbC2GL3xXBnPQw;
typedef NU8 tyEnum_WeekDay_SVfemTA9aCOyua2TJYa6yBg;
struct tyObject_ZonedTime_WigfH9apQAxJ69bBPh3wB8RQ {
NI64 adjTime;
NI utcOffset;
NIM_BOOL isDst;
};
typedef struct {
N_NIMCALL_PTR(tyObject_ZonedTime_WigfH9apQAxJ69bBPh3wB8RQ, ClP_0) (NI64 time, void* ClE_0);
void* ClE_0;
} tyProc_ye9aJuuf18PyKew55REW9aIA;
struct tyObject_Timezone_g1TRr0fUzr8gtJpVPUSSnA {
tyProc_ye9aJuuf18PyKew55REW9aIA zoneInfoFromUtc;
tyProc_ye9aJuuf18PyKew55REW9aIA zoneInfoFromTz;
NimStringDesc* name;
};
struct tyObject_DateTime_S7qec11z7km5Pal3UXrHmw {
  RootObj Sup;
NI second;
NI minute;
NI hour;
NI monthday;
tyEnum_Month_JS0JuFvCBbC2GL3xXBnPQw month;
NI year;
tyEnum_WeekDay_SVfemTA9aCOyua2TJYa6yBg weekday;
NI yearday;
NIM_BOOL isDst;
tyObject_Timezone_g1TRr0fUzr8gtJpVPUSSnA timezone;
NI utcOffset;
};
typedef NU8 tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ;
struct TNimNode {
tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct tyTuple_UV3llMMYFckfui8YMBuUZA {
NimStringDesc* Field0;
NimStringDesc* Field1;
};
struct tySequence_4eQHGndY6XBYpFOH09apV8Q {
  TGenericSeq Sup;
  tyTuple_UV3llMMYFckfui8YMBuUZA data[SEQ_DECL_SIZE];
};
N_LIB_PRIVATE N_NIMCALL(tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw*, parseCookies_RcSdzp0zvCIEbbx9aZFErPw)(NimStringDesc* s);
N_LIB_PRIVATE N_NIMCALL(tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw*, nstnewStringTable)(tyEnum_StringTableMode_G9c4wVDFIzf0xHmQvxso9a9cQ mode);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, subInt)(NI a, NI b);
N_LIB_PRIVATE N_NIMCALL(void, nstPut)(tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw* t, NimStringDesc* key, NimStringDesc* val);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI start, NI last);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* s, NI first, NI last);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(NimStringDesc*, setCookie_cVqDY1Al9avJ2peWiiox8pQ)(NimStringDesc* key, NimStringDesc* value, NimStringDesc* domain, NimStringDesc* path, NimStringDesc* expires, NIM_BOOL noName, NIM_BOOL secure, NIM_BOOL httpOnly);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
static N_INLINE(void, copyMem_fPlwH3r9agN9aEHB6yCPMh0wsystem)(void* dest, void* source, NI size);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* dest, NI addlen);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_LIB_PRIVATE N_NIMCALL(NimStringDesc*, setCookie_vCiMXJ59a46fB7F4CNRPeyw)(NimStringDesc* key, NimStringDesc* value, tyObject_DateTime_S7qec11z7km5Pal3UXrHmw* expires, NimStringDesc* domain, NimStringDesc* path, NIM_BOOL noName, NIM_BOOL secure, NIM_BOOL httpOnly);
N_LIB_PRIVATE N_NIMCALL(NimStringDesc*, format_3T6OLpwC4t6tQHwM5gTL4w)(tyObject_DateTime_S7qec11z7km5Pal3UXrHmw* dt, NimStringDesc* f);
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_9, "", 0);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_10, "Set-Cookie: ", 12);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_11, "=", 1);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_12, "; Domain=", 9);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_13, "; Path=", 7);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_14, "; Expires=", 10);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_15, "; Secure", 8);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_16, "; HttpOnly", 10);
STRING_LITERAL(TM_qg48f9bYtWpFXEmOP9bmoCgw_17, "ddd\',\' dd MMM yyyy HH:mm:ss \'GMT\'", 33);

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU32)(a) + (NU32)(b));
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

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU32)(a) - (NU32)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ (NI)((NU32) ~(b))));
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

N_LIB_PRIVATE N_NIMCALL(tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw*, parseCookies_RcSdzp0zvCIEbbx9aZFErPw)(NimStringDesc* s) {
	tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw* result;
	NI i;
	nimfr_("parseCookies", "cookies.nim");
	result = (tyObject_StringTableObj_DKRIdH9c9cKI7YpQb9c0wKlEw*)0;
	nimln_(25, "cookies.nim");
	result = nstnewStringTable(((tyEnum_StringTableMode_G9c4wVDFIzf0xHmQvxso9a9cQ) 1));
	nimln_(26, "cookies.nim");
	i = ((NI) 0);
	{
		nimln_(27, "cookies.nim");
		while (1) {
			NI keystart;
			NI keyend;
			NI TM_qg48f9bYtWpFXEmOP9bmoCgw_4;
			NI TM_qg48f9bYtWpFXEmOP9bmoCgw_5;
			NI valstart;
			NimStringDesc* T19_;
			NI TM_qg48f9bYtWpFXEmOP9bmoCgw_7;
			NimStringDesc* T20_;
			NI TM_qg48f9bYtWpFXEmOP9bmoCgw_8;
			{
				nimln_(28, "cookies.nim");
				while (1) {
					NIM_BOOL T5_;
					NI TM_qg48f9bYtWpFXEmOP9bmoCgw_2;
					T5_ = (NIM_BOOL)0;
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T5_ = ((NU8)(s->data[i]) == (NU8)(32));
					if (T5_) goto LA6_;
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T5_ = ((NU8)(s->data[i]) == (NU8)(9));
					LA6_: ;
					if (!T5_) goto LA4;
					TM_qg48f9bYtWpFXEmOP9bmoCgw_2 = addInt(i, ((NI) 1));
					i = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_2);
				} LA4: ;
			}
			nimln_(29, "cookies.nim");
			keystart = i;
			{
				nimln_(30, "cookies.nim");
				while (1) {
					NIM_BOOL T9_;
					NI TM_qg48f9bYtWpFXEmOP9bmoCgw_3;
					T9_ = (NIM_BOOL)0;
					nimln_(398, "system.nim");
					nimln_(30, "cookies.nim");
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T9_ = !(((NU8)(s->data[i]) == (NU8)(61)));
					if (!(T9_)) goto LA10_;
					nimln_(398, "system.nim");
					nimln_(30, "cookies.nim");
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T9_ = !(((NU8)(s->data[i]) == (NU8)(0)));
					LA10_: ;
					if (!T9_) goto LA8;
					TM_qg48f9bYtWpFXEmOP9bmoCgw_3 = addInt(i, ((NI) 1));
					i = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_3);
				} LA8: ;
			}
			nimln_(31, "cookies.nim");
			TM_qg48f9bYtWpFXEmOP9bmoCgw_4 = subInt(i, ((NI) 1));
			keyend = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_4);
			nimln_(32, "cookies.nim");
			{
				if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
				if (!((NU8)(s->data[i]) == (NU8)(0))) goto LA13_;
				goto LA1;
			}
			LA13_: ;
			nimln_(33, "cookies.nim");
			TM_qg48f9bYtWpFXEmOP9bmoCgw_5 = addInt(i, ((NI) 1));
			i = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_5);
			nimln_(34, "cookies.nim");
			valstart = i;
			{
				nimln_(35, "cookies.nim");
				while (1) {
					NIM_BOOL T17_;
					NI TM_qg48f9bYtWpFXEmOP9bmoCgw_6;
					T17_ = (NIM_BOOL)0;
					nimln_(398, "system.nim");
					nimln_(35, "cookies.nim");
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T17_ = !(((NU8)(s->data[i]) == (NU8)(59)));
					if (!(T17_)) goto LA18_;
					nimln_(398, "system.nim");
					nimln_(35, "cookies.nim");
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					T17_ = !(((NU8)(s->data[i]) == (NU8)(0)));
					LA18_: ;
					if (!T17_) goto LA16;
					TM_qg48f9bYtWpFXEmOP9bmoCgw_6 = addInt(i, ((NI) 1));
					i = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_6);
				} LA16: ;
			}
			nimln_(36, "cookies.nim");
			T19_ = (NimStringDesc*)0;
			T19_ = copyStrLast(s, keystart, keyend);
			TM_qg48f9bYtWpFXEmOP9bmoCgw_7 = subInt(i, ((NI) 1));
			T20_ = (NimStringDesc*)0;
			T20_ = copyStrLast(s, valstart, (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_7));
			nstPut(result, T19_, T20_);
			nimln_(37, "cookies.nim");
			{
				if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
				if (!((NU8)(s->data[i]) == (NU8)(0))) goto LA23_;
				goto LA1;
			}
			LA23_: ;
			nimln_(38, "cookies.nim");
			TM_qg48f9bYtWpFXEmOP9bmoCgw_8 = addInt(i, ((NI) 1));
			i = (NI)(TM_qg48f9bYtWpFXEmOP9bmoCgw_8);
		}
	} LA1: ;
	popFrame();
	return result;
}

static N_INLINE(void, copyMem_fPlwH3r9agN9aEHB6yCPMh0wsystem)(void* dest, void* source, NI size) {
	void* T1_;
	T1_ = (void*)0;
	T1_ = memcpy(dest, source, ((size_t) (size)));
}

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	copyMem_fPlwH3r9agN9aEHB6yCPMh0wsystem(((void*) ((&(*dest).data[((*dest).Sup.len)- 0]))), ((void*) ((*src).data)), ((NI) ((NI)((*src).Sup.len + ((NI) 1)))));
	(*dest).Sup.len += (*src).Sup.len;
}

N_LIB_PRIVATE N_NIMCALL(NimStringDesc*, setCookie_cVqDY1Al9avJ2peWiiox8pQ)(NimStringDesc* key, NimStringDesc* value, NimStringDesc* domain, NimStringDesc* path, NimStringDesc* expires, NIM_BOOL noName, NIM_BOOL secure, NIM_BOOL httpOnly) {
	NimStringDesc* result;
	NimStringDesc* T5_;
	nimfr_("setCookie", "cookies.nim");
	result = (NimStringDesc*)0;
	nimln_(45, "cookies.nim");
	result = copyString(((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_9));
	nimln_(46, "cookies.nim");
	{
		if (!!(noName)) goto LA3_;
		result = resizeString(result, 12);
appendString(result, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_10));
	}
	LA3_: ;
	nimln_(47, "cookies.nim");
	T5_ = (NimStringDesc*)0;
	T5_ = rawNewString(key->Sup.len + value->Sup.len + 1);
appendString(T5_, key);
appendString(T5_, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_11));
appendString(T5_, value);
	result = resizeString(result, T5_->Sup.len + 0);
appendString(result, T5_);
	nimln_(48, "cookies.nim");
	{
		NimStringDesc* T10_;
		nimln_(398, "system.nim");
		nimln_(48, "cookies.nim");
		if (!!(((domain) && (domain)->Sup.len == 0))) goto LA8_;
		T10_ = (NimStringDesc*)0;
		T10_ = rawNewString(domain->Sup.len + 9);
appendString(T10_, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_12));
appendString(T10_, domain);
		result = resizeString(result, T10_->Sup.len + 0);
appendString(result, T10_);
	}
	LA8_: ;
	nimln_(49, "cookies.nim");
	{
		NimStringDesc* T15_;
		nimln_(398, "system.nim");
		nimln_(49, "cookies.nim");
		if (!!(((path) && (path)->Sup.len == 0))) goto LA13_;
		T15_ = (NimStringDesc*)0;
		T15_ = rawNewString(path->Sup.len + 7);
appendString(T15_, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_13));
appendString(T15_, path);
		result = resizeString(result, T15_->Sup.len + 0);
appendString(result, T15_);
	}
	LA13_: ;
	nimln_(50, "cookies.nim");
	{
		NimStringDesc* T20_;
		nimln_(398, "system.nim");
		nimln_(50, "cookies.nim");
		if (!!(((expires) && (expires)->Sup.len == 0))) goto LA18_;
		T20_ = (NimStringDesc*)0;
		T20_ = rawNewString(expires->Sup.len + 10);
appendString(T20_, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_14));
appendString(T20_, expires);
		result = resizeString(result, T20_->Sup.len + 0);
appendString(result, T20_);
	}
	LA18_: ;
	nimln_(51, "cookies.nim");
	{
		if (!secure) goto LA23_;
		result = resizeString(result, 8);
appendString(result, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_15));
	}
	LA23_: ;
	nimln_(52, "cookies.nim");
	{
		if (!httpOnly) goto LA27_;
		result = resizeString(result, 10);
appendString(result, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_16));
	}
	LA27_: ;
	popFrame();
	return result;
}

N_LIB_PRIVATE N_NIMCALL(NimStringDesc*, setCookie_vCiMXJ59a46fB7F4CNRPeyw)(NimStringDesc* key, NimStringDesc* value, tyObject_DateTime_S7qec11z7km5Pal3UXrHmw* expires, NimStringDesc* domain, NimStringDesc* path, NIM_BOOL noName, NIM_BOOL secure, NIM_BOOL httpOnly) {
	NimStringDesc* result;
	NimStringDesc* T1_;
	nimfr_("setCookie", "cookies.nim");
{	result = (NimStringDesc*)0;
	nimln_(61, "cookies.nim");
	nimln_(62, "cookies.nim");
	T1_ = (NimStringDesc*)0;
	T1_ = format_3T6OLpwC4t6tQHwM5gTL4w(expires, ((NimStringDesc*) &TM_qg48f9bYtWpFXEmOP9bmoCgw_17));
	result = setCookie_cVqDY1Al9avJ2peWiiox8pQ(key, value, domain, path, T1_, noName, secure, httpOnly);
	goto BeforeRet_;
	}BeforeRet_: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_cookiesInit000)(void) {
	nimfr_("cookies", "cookies.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_cookiesDatInit000)(void) {
}
