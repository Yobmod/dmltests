/* Generated by Nim Compiler v0.18.0 */
/*   (c) 2018 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, i386, gcc */
/* Command for C compiler:
   gcc.exe -c  -w -mno-ms-bitfields -DWIN32_LEAN_AND_MEAN  -IC:\Users\Yobmod\.choosenim\toolchains\nim-0.18.0\lib -o c:\Webdev\dmltests\nim\jester\nimcache\stdlib_net.o c:\Webdev\dmltests\nim\jester\nimcache\stdlib_net.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 32

#include "nimbase.h"
#include "winsock2.h"
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
typedef struct tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef NU8 tyEnum_Domain_Q79bEtFARvq0ekDNtvj3Vqg;
struct tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ {
tyEnum_Domain_Q79bEtFARvq0ekDNtvj3Vqg val;
NIM_BOOL has;
};
typedef NU8 tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg;
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
typedef NU8 tySet_tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg;
typedef NU8 tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ;
typedef NU8 tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ;
struct TNimNode {
tyEnum_TNimNodeKind_unfNsxrcATrufDZmpBq4HQ kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isNone_Q4RsUqhsTDIbkeIguPSpvA)(tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ self);
N_LIB_PRIVATE N_NIMCALL(tyEnum_Domain_Q79bEtFARvq0ekDNtvj3Vqg, unsafeGet_fdGmwO5YUOWb8OBjkhgjng)(tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ self);
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isSome_Q4RsUqhsTDIbkeIguPSpvA_2)(tyObject_Option_V9bnQIoRETSshkjE1kDWuNQ self);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
TNimType NTI_4xio0cAXR7XG4pF9bVcpxEg_;
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;

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

N_LIB_PRIVATE N_NIMCALL(int, toOSFlags_OfxuUkOMe7cgSmyynuaSLQ)(tySet_tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg socketFlags) {
	int result;
	nimfr_("toOSFlags", "net.nim");
	result = (int)0;
	{
		tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg f;
		NI i;
		f = (tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg)0;
		nimln_(2219, "system.nim");
		i = ((NI) 0);
		{
			nimln_(2220, "system.nim");
			while (1) {
				NI TM_XqsrSBxhOTPgLQ9cX4MmV4A_5;
				if (!(i <= ((NI) 1))) goto LA3;
				nimln_(2221, "system.nim");
				{
					if (!((socketFlags &(1U<<((NU)(((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg)chckRange(i, ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 0), ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 1))))&7U)))!=0)) goto LA6_;
					f = ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg)chckRange(i, ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 0), ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 1)));
					{
						nimln_(200, "net.nim");
						switch (f) {
						case ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 0):
						{
							nimln_(202, "net.nim");
							result = (NI32)(result | ((NI32) 2));
						}
						break;
						case ((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 1):
						{
							nimln_(203, "net.nim");
							goto LA8;
						}
						break;
						}
					} LA8: ;
				}
				LA6_: ;
				nimln_(2222, "system.nim");
				TM_XqsrSBxhOTPgLQ9cX4MmV4A_5 = addInt(i, ((NI) 1));
				i = (NI)(TM_XqsrSBxhOTPgLQ9cX4MmV4A_5);
			} LA3: ;
		}
	}
	popFrame();
	return result;
}

N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isDisconnectionError_40p9aaw5rEmIprdUBGKsyYQ)(tySet_tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg flags, NI32 lastError) {
	NIM_BOOL result;
	NIM_BOOL T1_;
	nimfr_("isDisconnectionError", "net.nim");
	result = (NIM_BOOL)0;
	nimln_(187, "net.nim");
	nimln_(190, "net.nim");
	T1_ = (NIM_BOOL)0;
	T1_ = ((flags &(1U<<((NU)(((tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg) 1))&7U)))!=0);
	if (!(T1_)) goto LA2_;
	nimln_(191, "net.nim");
	T1_ = (lastError == ((NI) 10054) || lastError == ((NI) 10053) || lastError == ((NI) 10052) || lastError == ((NI) 10101) || lastError == ((NI) 64));
	LA2_: ;
	result = T1_;
	popFrame();
	return result;
}

N_LIB_PRIVATE N_NIMCALL(int, toCInt_ne8KyyT0jskmnqTgYiJN4w)(tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ opt) {
	int result;
	nimfr_("toCInt", "net.nim");
	result = (int)0;
	nimln_(886, "net.nim");
	nimln_(887, "net.nim");
	switch (opt) {
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 0):
	{
		result = SO_ACCEPTCONN;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 1):
	{
		result = SO_BROADCAST;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 2):
	{
		result = SO_DEBUG;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 3):
	{
		result = SO_DONTROUTE;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 4):
	{
		result = SO_KEEPALIVE;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 5):
	{
		result = SO_OOBINLINE;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 6):
	{
		result = SO_REUSEADDR;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 7):
	{
		result = SO_REUSEADDR;
	}
	break;
	case ((tyEnum_SOBool_SDlZUtKctfhvUZ58547HWQ) 8):
	{
		result = TCP_NODELAY;
	}
	break;
	}
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_netInit000)(void) {
	nimfr_("net", "net.nim");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_netDatInit000)(void) {
static TNimNode* TM_XqsrSBxhOTPgLQ9cX4MmV4A_2[2];
NI TM_XqsrSBxhOTPgLQ9cX4MmV4A_4;
static char* NIM_CONST TM_XqsrSBxhOTPgLQ9cX4MmV4A_3[2] = {
"Peek", 
"SafeDisconn"};
static TNimNode TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[3];
NTI_4xio0cAXR7XG4pF9bVcpxEg_.size = sizeof(tyEnum_SocketFlag_4xio0cAXR7XG4pF9bVcpxEg);
NTI_4xio0cAXR7XG4pF9bVcpxEg_.kind = 14;
NTI_4xio0cAXR7XG4pF9bVcpxEg_.base = 0;
NTI_4xio0cAXR7XG4pF9bVcpxEg_.flags = 3;
for (TM_XqsrSBxhOTPgLQ9cX4MmV4A_4 = 0; TM_XqsrSBxhOTPgLQ9cX4MmV4A_4 < 2; TM_XqsrSBxhOTPgLQ9cX4MmV4A_4++) {
TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4+0].kind = 1;
TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4+0].offset = TM_XqsrSBxhOTPgLQ9cX4MmV4A_4;
TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4+0].name = TM_XqsrSBxhOTPgLQ9cX4MmV4A_3[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4];
TM_XqsrSBxhOTPgLQ9cX4MmV4A_2[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4] = &TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[TM_XqsrSBxhOTPgLQ9cX4MmV4A_4+0];
}
TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[2].len = 2; TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[2].kind = 2; TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[2].sons = &TM_XqsrSBxhOTPgLQ9cX4MmV4A_2[0];
NTI_4xio0cAXR7XG4pF9bVcpxEg_.node = &TM_XqsrSBxhOTPgLQ9cX4MmV4A_0[2];
}

