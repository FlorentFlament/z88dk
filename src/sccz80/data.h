/* data.c */
extern char amivers[];
extern char titlec[];
extern char Banner[];
extern char Version[];
extern char Overflow[];
extern SYMBOL *symtab;
extern SYMBOL *loctab;
extern SYMBOL *locptr;
extern int glbcnt;
extern SYMBOL *dummy_sym[];
extern WHILE_TAB *wqueue;
extern WHILE_TAB *wqptr;
extern unsigned char *litq;
extern unsigned char *dubq;
extern unsigned char *glbq;
extern unsigned char *tempq;
extern int gltptr;
extern int litptr;
extern int dubptr;
extern char macq[];
extern int macptr;
extern char *stage;
extern char *stagenext;
extern char *stagelast;
extern SW_TAB *swnext;
extern SW_TAB *swend;
extern char line[];
extern char mline[];
extern int lptr;
extern int mptr;
extern char Filename[];
extern int need_floatpack;
extern int c_doinline;
extern int ncomp;
extern int stackargs;
extern int defstatic;
extern int filenum;
extern char c_default_unsigned;
extern char fnflags;
extern char c_mathz88;
extern char c_compact_code;
extern int nxtlab;
extern int glblab;
extern int litlab;
extern int Zsp;
extern int undeclared;
extern int ncmp;
extern int errcnt;
extern int c_errstop;
extern int eof;
extern int c_intermix_ccode;
extern int cmode;
extern int declared;
extern int lastst;
extern int iflevel;
extern int skiplevel;
extern int fnstart;
extern int lineno;
extern int infunc;

extern int swactive;
extern int swdefault;
extern int c_verbose;
extern FILE *input;
extern FILE *output;
extern FILE *inpt2;
extern FILE *saveout;
extern SYMBOL *currfn;

extern char endasm;
extern int ltype;
extern int c_share_offset;
extern int debuglevel;
extern int c_assembler_type;
extern int c_framepointer_is_ix;
extern int c_double_strings;
extern int usempm;
extern int z80asm_sections;
extern int c_standard_escapecodes;
extern uint32_t scanf_format_option;
extern uint32_t printf_format_option;
extern FILE * buffer_fps[];
extern int buffer_fps_num;
extern struct parser_stack *pstack;
extern int c_use_r2l_calling_convention;
extern int c_cpu;
extern char *c_init_section;
extern char *c_code_section;
extern char *c_bss_section;
extern char *c_data_section;
extern char *c_rodata_section;
extern int c_fp_mantissa_bytes;
extern int c_fp_exponent_bias;
extern int c_disable_builtins;
extern uint32_t c_size_optimisation;
extern int incritical;