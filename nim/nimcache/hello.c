/* Generated by Nim Compiler v0.17.2 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\nim17\nim-0.17.2\dist\mingw64\bin\gcc.exe -c  -w -mno-ms-bitfields  -IC:\nim17\nim-0.17.2\lib -o c:\Webdev\dmltests\nim\brainfuck\nimcache\hello.o c:\Webdev\dmltests\nim\brainfuck\nimcache\hello.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <stdio.h>
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
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
struct TGenericSeq {
NI len;
NI reserved;
};
struct NimStringDesc {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI x);
static N_INLINE(void, initStackBottomWith)(void* locals);
N_NOINLINE(void, setStackBottom)(void* theStackBottom);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
NIM_EXTERNC N_NOINLINE(void, systemInit000)(void);
NIM_EXTERNC N_NOINLINE(void, systemDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, NimMainModule)(void);
NIM_EXTERNC N_NOINLINE(void, helloDatInit000)(void);
NI x_9caDjiQ3CTRfMyPX9am9bnDfg;
NI i_ucpY3nVmm6TF4veRL5kxXg;
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
STRING_LITERAL(TM_xLHv575t3PG1lB5wK05Xqg_4, "Halo world", 10);

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

static N_INLINE(void, initStackBottomWith)(void* locals) {
	setStackBottom(locals);
}
void PreMainInner(void) {
	systemInit000();
	helloDatInit000();
}

void PreMain(void) {
	void (*volatile inner)(void);
	systemDatInit000();
	inner = PreMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int cmdCount;
char** cmdLine;
char** gEnv;
N_CDECL(void, NimMainInner)(void) {
	NimMainModule();
}

N_CDECL(void, NimMain)(void) {
	void (*volatile inner)(void);
	PreMain();
	inner = NimMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int main(int argc, char** args, char** env) {
	cmdLine = args;
	cmdCount = argc;
	gEnv = env;
	NimMain();
	return nim_program_result;
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
NIM_EXTERNC N_NOINLINE(void, NimMainModule)(void) {
	NimStringDesc* T4_;
	nimfr_("hello", "hello.nim");
	nimln_(1, "hello.nim");
	x_9caDjiQ3CTRfMyPX9am9bnDfg = ((NI) 0);
	{
		NI res;
		nimln_(1986, "system.nim");
		res = ((NI) 1);
		{
			nimln_(1987, "system.nim");
			while (1) {
				NI TM_xLHv575t3PG1lB5wK05Xqg_2;
				NI TM_xLHv575t3PG1lB5wK05Xqg_3;
				if (!(res <= ((NI) 100000000))) goto LA3;
				nimln_(1988, "system.nim");
				i_ucpY3nVmm6TF4veRL5kxXg = res;
				nimln_(3, "hello.nim");
				TM_xLHv575t3PG1lB5wK05Xqg_2 = addInt(x_9caDjiQ3CTRfMyPX9am9bnDfg, ((NI) 1));
				x_9caDjiQ3CTRfMyPX9am9bnDfg = (NI)(TM_xLHv575t3PG1lB5wK05Xqg_2);
				nimln_(1989, "system.nim");
				TM_xLHv575t3PG1lB5wK05Xqg_3 = addInt(res, ((NI) 1));
				res = (NI)(TM_xLHv575t3PG1lB5wK05Xqg_3);
			} LA3: ;
		}
	}
	nimln_(5, "hello.nim");
	T4_ = (NimStringDesc*)0;
	T4_ = nimIntToStr(x_9caDjiQ3CTRfMyPX9am9bnDfg);
	printf("%s%s\015\012", ((NimStringDesc*) &TM_xLHv575t3PG1lB5wK05Xqg_4)? (((NimStringDesc*) &TM_xLHv575t3PG1lB5wK05Xqg_4))->data:"nil", T4_? (T4_)->data:"nil");
	fflush(stdout);
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, helloDatInit000)(void) {
}

