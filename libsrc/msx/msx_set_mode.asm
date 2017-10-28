;
;	MSX specific routines
;
;	GFX - a small graphics library 
;	Copyright (C) 2004  Rafael de Oliveira Jannone
;
;	extern bool __FASTCALL__ msx_set_mode(unsigned char id);
;
;	set screen mode
;
;	$Id: msx_set_mode.asm $
;

        SECTION code_clib
	PUBLIC	msx_set_mode
	PUBLIC	_msx_set_mode
	
	EXTERN	msxbios

IF FORsvi
    INCLUDE	"msx/vdp.inc"
    INCLUDE "svibios.def"
    INCLUDE "svibasic.def"
ENDIF

msx_set_mode:
_msx_set_mode:

IF FORmsx
	; MSX supports G1 natively
ELSE
	ld	a,h
	or	l
	jr	z,txt32
setmode:
ENDIF
	push	ix
	push	hl
	pop	ix
	call	msxbios
	pop	ix
	ret

IF FORmsx
	; MSX supports G1 natively
ELSE
txt32:
	ld    hl,INIGRP		; (Graphics 2)
	call  setmode

	; Now bend the configuration to Graphics 1 (change reg#0)
	xor   a
	ld    (RG0SAV),a
	di
	out   (VDP_CMD),a
	nop     ; ..do we have timing constraints ?
	or    $80
	ei
	out   (VDP_CMD),a

	; Bend register #3
	ld	a,$80
	di
	out   (VDP_CMD),a
	ld    a,3  ; reg3
	or    $80
	ei
	out   (VDP_CMD),a
	
	; Bend register #4
	xor	  a
	di
	out   (VDP_CMD),a
	ld    a,4  ; reg4  -  PT./TXT/MCOL-GEN.TAB.
	or    $80
	ei
	out   (VDP_CMD),a
	
	
	ld	hl,$1800		; SCREEN 1 name table
	ld	bc,32*24
	ld	a,c	; ' '
	ld ix,FILVRM
	call	msxbios
	
	LD A,(FORCLR)
	ADD A,A
	ADD A,A
	ADD A,A
	ADD A,A
	LD HL,BAKCLR
	OR (HL)
	ld	hl,$2000		; SCREEN 1 color table
	ld	bc,32
;	ld a,$1F
	ld ix,FILVRM
	call	msxbios

	ld	hl,font
	ld	de,0			; SCREEN 1 character pattern table
	ld	bc,2048
	ld	ix,LDIRVM
	call	msxbios

	ret
	
.font
binary "../stdio/ansi/FONT8.BIN"

ENDIF
