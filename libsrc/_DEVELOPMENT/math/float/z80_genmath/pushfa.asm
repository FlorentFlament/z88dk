;
;       Z88dk Generic Floating Point Math Library
;
;       Push FA onto the stack
;
;       $Id: pushfa.asm,v 1.1 2015-03-27 06:03:29 aralbrec Exp $:


		PUBLIC	pushfa

		PUBLIC	pushf2

		EXTERN	fa

.pushfa
	ex	de,hl
.pushf2
	ld	hl,(fa)
        ex      (sp),hl
        push    hl
        ld      hl,(fa+2)
        ex      (sp),hl
        push    hl
        ld      hl,(fa+4)
        ex      (sp),hl
        push    hl
        ex      de,hl
        ret


