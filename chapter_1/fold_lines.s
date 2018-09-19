	.file	"fold_lines.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"\n%c"
	.text
	.globl	fold_line
	.type	fold_line, @function
fold_line:
.LFB11:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	sub	rsp, 8
	.cfi_def_cfa_offset 32
	mov	ebp, edi
	jmp	.L2
.L10:
	mov	esi, 32
	jmp	.L3
.L4:
	movsx	edi, sil
	call	putchar@PLT
.L2:
	mov	rdi, QWORD PTR stdin[rip]
	call	getc@PLT
	mov	esi, eax
	cmp	al, -1
	je	.L1
	cmp	al, 42
	je	.L1
	add	ebx, 1
	cmp	al, 10
	je	.L10
.L3:
	cmp	ebx, ebp
	jl	.L4
	movsx	esi, sil
	lea	rdi, .LC0[rip]
	mov	eax, 0
	call	printf@PLT
	mov	ebx, 0
	jmp	.L2
.L1:
	add	rsp, 8
	.cfi_def_cfa_offset 24
	pop	rbx
	.cfi_def_cfa_offset 16
	pop	rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	fold_line, .-fold_line
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edi, 20
	call	fold_line
	mov	eax, 0
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
