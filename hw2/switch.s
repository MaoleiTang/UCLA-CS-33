	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_switch_prob
	.align	4, 0x90
_switch_prob:                           ## @switch_prob
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
                                        ## kill: ESI<def> ESI<kill> RSI<def>
                                        ## kill: EDI<def> EDI<kill> RDI<def>
	addl	$-50, %esi
	cmpl	$5, %esi
	ja	LBB0_6
## BB#1:
	leaq	LJTI0_0(%rip), %rax
	movslq	(%rax,%rsi,4), %rcx
	addq	%rax, %rcx
	jmpq	*%rcx
LBB0_2:
	shll	$2, %edi
	jmp	LBB0_7
LBB0_3:
	sarl	$2, %edi
	jmp	LBB0_7
LBB0_4:
	leal	(%rdi,%rdi,2), %edi
LBB0_5:
	imull	%edi, %edi
LBB0_6:
	addl	$10, %edi
LBB0_7:
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc
	.align	2, 0x90
L0_0_set_2 = LBB0_2-LJTI0_0
L0_0_set_6 = LBB0_6-LJTI0_0
L0_0_set_3 = LBB0_3-LJTI0_0
L0_0_set_4 = LBB0_4-LJTI0_0
L0_0_set_5 = LBB0_5-LJTI0_0
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_6
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5


.subsections_via_symbols
