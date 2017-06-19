
// automatically generated by m4 from headers in proto subdir


#ifndef _ARCH_TS2068_H
#define _ARCH_TS2068_H

#include <arch.h>

#include <stddef.h>
#include <rect.h>

// COMMON CONSTANTS

#define INK_BLACK                   0x00
#define INK_BLUE                    0x01
#define INK_RED                     0x02
#define INK_MAGENTA                 0x03
#define INK_GREEN                   0x04
#define INK_CYAN                    0x05
#define INK_YELLOW                  0x06
#define INK_WHITE                   0x07

#define PAPER_BLACK                 0x00
#define PAPER_BLUE                  0x08
#define PAPER_RED                   0x10
#define PAPER_MAGENTA               0x18
#define PAPER_GREEN                 0x20
#define PAPER_CYAN                  0x28
#define PAPER_YELLOW                0x30
#define PAPER_WHITE                 0x38

#define BRIGHT                      0x40
#define FLASH                       0x80

// GLOBAL VARIABLES

extern unsigned char GLOBAL_TS_PORT_FE;
extern unsigned char GLOBAL_ZX_PORT_FE;

// IO MAPPED REGISTERS

#ifdef __CLANG

extern unsigned char IO_FE;

#else

__sfr __at 0xfe IO_FE;

#endif

// misc

extern void zx_border(unsigned char colour) __preserves_regs(b,c,d,e,iyl,iyh);
extern void zx_border_fastcall(unsigned char colour) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_border(a) zx_border_fastcall(a)


extern void zx_cls(unsigned char attr) __preserves_regs(iyl,iyh);
extern void zx_cls_fastcall(unsigned char attr) __preserves_regs(iyl,iyh) __z88dk_fastcall;
#define zx_cls(a) zx_cls_fastcall(a)


extern void zx_cls_wc(struct r_Rect8 *r,unsigned char attr);
extern void zx_cls_wc_callee(struct r_Rect8 *r,unsigned char attr) __z88dk_callee;
#define zx_cls_wc(a,b) zx_cls_wc_callee(a,b)


extern void zx_scroll_up(unsigned char rows,unsigned char attr) __preserves_regs(iyl,iyh);
extern void zx_scroll_up_callee(unsigned char rows,unsigned char attr) __preserves_regs(iyl,iyh) __z88dk_callee;
#define zx_scroll_up(a,b) zx_scroll_up_callee(a,b)


extern void zx_scroll_wc_up(struct r_Rect8 *r,unsigned char rows,unsigned char attr);
extern void zx_scroll_wc_up_callee(struct r_Rect8 *r,unsigned char rows,unsigned char attr) __z88dk_callee;
#define zx_scroll_wc_up(a,b,c) zx_scroll_wc_up_callee(a,b,c)



// display

// In the following, screen address refers to a pixel address within the display file while
// attribute address refers to the attributes area.
//
// Function names are constructed from the following atoms:
//
// saddr = screen address
// aaddr = attribute address
// 
// px    = pixel x coordinate (0..255)
// py    = pixel y coordinate (0..191)
// pxy   = pixel (x,y) coordinate
//
// cx    = character x coordinate (0..31)
// cy    = character y coordinate (0..23)
// cxy   = character (x,y) coordinate
//
// So for example:
//
// zx_saddr2cy(saddr) will return the character y coordinate corresponding to the given screen address
// zx_saddr2aaddr(saddr) will return the attribute address corresponding to the given screen address
// zx_pxy2aaddr(px,py) will return the attribute address corresponding to the given (x,y) pixel coordinate
//
// Some functions will return with carry flag set if coordinates or addresses move out of
// bounds.  In these cases the special z88dk keywords iferror() and ifnerror() can be used
// to test the carry flag and determine if invalid results are returned.  Check with the
// wiki documentation or the asm source files to see which functions support this.  If
// comments in the asm source file do not mention this, it is not supported.

// Standard Spectrum Display 256x192 pixel 32x24 colour

extern unsigned char zx_aaddr2cx(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_aaddr2cx_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_aaddr2cx(a) zx_aaddr2cx_fastcall(a)


extern unsigned char zx_aaddr2cy(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_aaddr2cy_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddr2cy(a) zx_aaddr2cy_fastcall(a)


extern unsigned char zx_aaddr2px(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_aaddr2px_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_aaddr2px(a) zx_aaddr2px_fastcall(a)


extern unsigned char zx_aaddr2py(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_aaddr2py_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddr2py(a) zx_aaddr2py_fastcall(a)


extern unsigned char *zx_aaddr2saddr(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_aaddr2saddr_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddr2saddr(a) zx_aaddr2saddr_fastcall(a)


extern unsigned char *zx_aaddrcdown(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_aaddrcdown_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddrcdown(a) zx_aaddrcdown_fastcall(a)


extern unsigned char *zx_aaddrcleft(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_aaddrcleft_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddrcleft(a) zx_aaddrcleft_fastcall(a)


extern unsigned char *zx_aaddrcright(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_aaddrcright_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddrcright(a) zx_aaddrcright_fastcall(a)


extern unsigned char *zx_aaddrcup(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_aaddrcup_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_aaddrcup(a) zx_aaddrcup_fastcall(a)


extern unsigned char zx_bitmask2px(unsigned char bitmask) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_bitmask2px_fastcall(unsigned char bitmask) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_bitmask2px(a) zx_bitmask2px_fastcall(a)


extern unsigned char *zx_cxy2aaddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_cxy2aaddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define zx_cxy2aaddr(a,b) zx_cxy2aaddr_callee(a,b)


extern unsigned char *zx_cxy2saddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_cxy2saddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define zx_cxy2saddr(a,b) zx_cxy2saddr_callee(a,b)


extern unsigned char *zx_cy2aaddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_cy2aaddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_cy2aaddr(a) zx_cy2aaddr_fastcall(a)


extern unsigned char *zx_cy2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_cy2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_cy2saddr(a) zx_cy2saddr_fastcall(a)


extern unsigned char zx_px2bitmask(unsigned char x) __preserves_regs(c,d,e,iyl,iyh);
extern unsigned char zx_px2bitmask_fastcall(unsigned char x) __preserves_regs(c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_px2bitmask(a) zx_px2bitmask_fastcall(a)


extern unsigned char *zx_pxy2aaddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_pxy2aaddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define zx_pxy2aaddr(a,b) zx_pxy2aaddr_callee(a,b)


extern unsigned char *zx_pxy2saddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_pxy2saddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define zx_pxy2saddr(a,b) zx_pxy2saddr_callee(a,b)


extern unsigned char *zx_py2aaddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_py2aaddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_py2aaddr(a) zx_py2aaddr_fastcall(a)


extern unsigned char *zx_py2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_py2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_py2saddr(a) zx_py2saddr_fastcall(a)


extern unsigned char *zx_saddr2aaddr(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddr2aaddr_fastcall(void *saddr) __preserves_regs(b,c,d,e,l,iyl,iyh) __z88dk_fastcall;
#define zx_saddr2aaddr(a) zx_saddr2aaddr_fastcall(a)


extern unsigned char zx_saddr2cx(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_saddr2cx_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_saddr2cx(a) zx_saddr2cx_fastcall(a)


extern unsigned char zx_saddr2cy(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char zx_saddr2cy_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_saddr2cy(a) zx_saddr2cy_fastcall(a)


extern unsigned int zx_saddr2px(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned int zx_saddr2px_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_saddr2px(a) zx_saddr2px_fastcall(a)


extern unsigned int zx_saddr2py(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned int zx_saddr2py_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define zx_saddr2py(a) zx_saddr2py_fastcall(a)


extern unsigned char *zx_saddrcdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrcdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrcdown(a) zx_saddrcdown_fastcall(a)


extern unsigned char *zx_saddrcleft(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrcleft_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrcleft(a) zx_saddrcleft_fastcall(a)


extern unsigned char *zx_saddrcright(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrcright_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrcright(a) zx_saddrcright_fastcall(a)


extern unsigned char *zx_saddrcup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrcup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrcup(a) zx_saddrcup_fastcall(a)


extern unsigned char *zx_saddrpdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrpdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrpdown(a) zx_saddrpdown_fastcall(a)


extern unsigned char *zx_saddrpleft(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *zx_saddrpleft_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define zx_saddrpleft(a,b) zx_saddrpleft_callee(a,b)


extern unsigned char *zx_saddrpright(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *zx_saddrpright_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define zx_saddrpright(a,b) zx_saddrpright_callee(a,b)


extern unsigned char *zx_saddrpup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *zx_saddrpup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define zx_saddrpup(a) zx_saddrpup_fastcall(a)



// Timex Hi-Colour Display 256x192 pixel 32x192 colour

extern unsigned char tshc_aaddr2cx(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_aaddr2cx_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddr2cx(a) tshc_aaddr2cx_fastcall(a)


extern unsigned char tshc_aaddr2cy(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_aaddr2cy_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddr2cy(a) tshc_aaddr2cy_fastcall(a)


extern unsigned char tshc_aaddr2px(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_aaddr2px_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddr2px(a) tshc_aaddr2px_fastcall(a)


extern unsigned char tshc_aaddr2py(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_aaddr2py_fastcall(void *aaddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddr2py(a) tshc_aaddr2py_fastcall(a)


extern unsigned char *tshc_aaddr2saddr(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddr2saddr_fastcall(void *aaddr) __preserves_regs(a,b,c,d,e,l,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddr2saddr(a) tshc_aaddr2saddr_fastcall(a)


extern unsigned char *tshc_aaddrcdown(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrcdown_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrcdown(a) tshc_aaddrcdown_fastcall(a)


extern unsigned char *tshc_aaddrcleft(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrcleft_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrcleft(a) tshc_aaddrcleft_fastcall(a)


extern unsigned char *tshc_aaddrcright(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrcright_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrcright(a) tshc_aaddrcright_fastcall(a)


extern unsigned char *tshc_aaddrcup(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrcup_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrcup(a) tshc_aaddrcup_fastcall(a)


extern unsigned char *tshc_aaddrpdown(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrpdown_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrpdown(a) tshc_aaddrpdown_fastcall(a)


extern unsigned char *tshc_aaddrpleft(void *aaddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshc_aaddrpleft_callee(void *aaddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshc_aaddrpleft(a,b) tshc_aaddrpleft_callee(a,b)


extern unsigned char *tshc_aaddrpright(void *aaddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshc_aaddrpright_callee(void *aaddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshc_aaddrpright(a,b) tshc_aaddrpright_callee(a,b)


extern unsigned char *tshc_aaddrpup(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_aaddrpup_fastcall(void *aaddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_aaddrpup(a) tshc_aaddrpup_fastcall(a)


extern unsigned char tshc_bitmask2px(unsigned char bitmask) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_bitmask2px_fastcall(unsigned char bitmask) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_bitmask2px(a) tshc_bitmask2px_fastcall(a)


extern unsigned char *tshc_cxy2aaddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_cxy2aaddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define tshc_cxy2aaddr(a,b) tshc_cxy2aaddr_callee(a,b)


extern unsigned char *tshc_cxy2saddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_cxy2saddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define tshc_cxy2saddr(a,b) tshc_cxy2saddr_callee(a,b)


extern unsigned char *tshc_cy2aaddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_cy2aaddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_cy2aaddr(a) tshc_cy2aaddr_fastcall(a)


extern unsigned char *tshc_cy2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_cy2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_cy2saddr(a) tshc_cy2saddr_fastcall(a)


extern unsigned char tshc_px2bitmask(unsigned char x) __preserves_regs(c,d,e,iyl,iyh);
extern unsigned char tshc_px2bitmask_fastcall(unsigned char x) __preserves_regs(c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_px2bitmask(a) tshc_px2bitmask_fastcall(a)


extern unsigned char *tshc_pxy2aaddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_pxy2aaddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define tshc_pxy2aaddr(a,b) tshc_pxy2aaddr_callee(a,b)


extern unsigned char *tshc_pxy2saddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_pxy2saddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define tshc_pxy2saddr(a,b) tshc_pxy2saddr_callee(a,b)


extern unsigned char *tshc_py2aaddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_py2aaddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_py2aaddr(a) tshc_py2aaddr_fastcall(a)


extern unsigned char *tshc_py2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_py2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_py2saddr(a) tshc_py2saddr_fastcall(a)


extern unsigned char *tshc_saddr2aaddr(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddr2aaddr_fastcall(void *saddr) __preserves_regs(a,b,c,d,e,l,iyl,iyh) __z88dk_fastcall;
#define tshc_saddr2aaddr(a) tshc_saddr2aaddr_fastcall(a)


extern unsigned char tshc_saddr2cx(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_saddr2cx_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_saddr2cx(a) tshc_saddr2cx_fastcall(a)


extern unsigned char tshc_saddr2cy(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_saddr2cy_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_saddr2cy(a) tshc_saddr2cy_fastcall(a)


extern unsigned char tshc_saddr2px(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_saddr2px_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_saddr2px(a) tshc_saddr2px_fastcall(a)


extern unsigned char tshc_saddr2py(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshc_saddr2py_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshc_saddr2py(a) tshc_saddr2py_fastcall(a)


extern unsigned char *tshc_saddrcdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrcdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrcdown(a) tshc_saddrcdown_fastcall(a)


extern unsigned char *tshc_saddrcleft(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrcleft_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrcleft(a) tshc_saddrcleft_fastcall(a)


extern unsigned char *tshc_saddrcright(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrcright_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrcright(a) tshc_saddrcright_fastcall(a)


extern unsigned char *tshc_saddrcup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrcup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrcup(a) tshc_saddrcup_fastcall(a)


extern unsigned char *tshc_saddrpdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrpdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrpdown(a) tshc_saddrpdown_fastcall(a)


extern unsigned char *tshc_saddrpleft(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshc_saddrpleft_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshc_saddrpleft(a,b) tshc_saddrpleft_callee(a,b)


extern unsigned char *tshc_saddrpright(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshc_saddrpright_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshc_saddrpright(a,b) tshc_saddrpright_callee(a,b)


extern unsigned char *tshc_saddrpup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshc_saddrpup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshc_saddrpup(a) tshc_saddrpup_fastcall(a)



// Timex Hi-Res Display, 512x192 monochrome

extern unsigned char tshr_bitmask2px(unsigned char bitmask) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshr_bitmask2px_fastcall(unsigned char bitmask) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_bitmask2px(a) tshr_bitmask2px_fastcall(a)


extern unsigned char *tshr_cxy2saddr(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_cxy2saddr_callee(unsigned char x,unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_callee;
#define tshr_cxy2saddr(a,b) tshr_cxy2saddr_callee(a,b)


extern unsigned char *tshr_cy2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_cy2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_cy2saddr(a) tshr_cy2saddr_fastcall(a)


extern unsigned char tshr_px2bitmask(unsigned char x) __preserves_regs(c,d,e,iyl,iyh);
extern unsigned char tshr_px2bitmask_fastcall(unsigned char x) __preserves_regs(c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_px2bitmask(a) tshr_px2bitmask_fastcall(a)


extern unsigned char *tshr_pxy2saddr(unsigned int x,unsigned char y) __preserves_regs(iyl,iyh);
extern unsigned char *tshr_pxy2saddr_callee(unsigned int x,unsigned char y) __preserves_regs(iyl,iyh) __z88dk_callee;
#define tshr_pxy2saddr(a,b) tshr_pxy2saddr_callee(a,b)


extern unsigned char *tshr_py2saddr(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_py2saddr_fastcall(unsigned char y) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_py2saddr(a) tshr_py2saddr_fastcall(a)


extern unsigned char tshr_saddr2cx(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshr_saddr2cx_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_saddr2cx(a) tshr_saddr2cx_fastcall(a)


extern unsigned char tshr_saddr2cy(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshr_saddr2cy_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_saddr2cy(a) tshr_saddr2cy_fastcall(a)


extern unsigned int tshr_saddr2px(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned int tshr_saddr2px_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_saddr2px(a) tshr_saddr2px_fastcall(a)


extern unsigned char tshr_saddr2py(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char tshr_saddr2py_fastcall(void *saddr) __preserves_regs(b,c,d,e,h,iyl,iyh) __z88dk_fastcall;
#define tshr_saddr2py(a) tshr_saddr2py_fastcall(a)


extern unsigned char *tshr_saddrcdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrcdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrcdown(a) tshr_saddrcdown_fastcall(a)


extern unsigned char *tshr_saddrcleft(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrcleft_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrcleft(a) tshr_saddrcleft_fastcall(a)


extern unsigned char *tshr_saddrcright(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrcright_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrcright(a) tshr_saddrcright_fastcall(a)


extern unsigned char *tshr_saddrcup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrcup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrcup(a) tshr_saddrcup_fastcall(a)


extern unsigned char *tshr_saddrpdown(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrpdown_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrpdown(a) tshr_saddrpdown_fastcall(a)


extern unsigned char *tshr_saddrpleft(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshr_saddrpleft_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshr_saddrpleft(a,b) tshr_saddrpleft_callee(a,b)


extern unsigned char *tshr_saddrpright(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh);
extern unsigned char *tshr_saddrpright_callee(void *saddr,unsigned char bitmask) __preserves_regs(b,c,iyl,iyh) __z88dk_callee;
#define tshr_saddrpright(a,b) tshr_saddrpright_callee(a,b)


extern unsigned char *tshr_saddrpup(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh);
extern unsigned char *tshr_saddrpup_fastcall(void *saddr) __preserves_regs(b,c,d,e,iyl,iyh) __z88dk_fastcall;
#define tshr_saddrpup(a) tshr_saddrpup_fastcall(a)



// graphics

extern int zx_pattern_fill(unsigned char x,unsigned char y,void *pattern,unsigned int depth);
extern int zx_pattern_fill_callee(unsigned char x,unsigned char y,void *pattern,unsigned int depth) __z88dk_callee;
#define zx_pattern_fill(a,b,c,d) zx_pattern_fill_callee(a,b,c,d)



#endif