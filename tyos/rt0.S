	
	.code16
	.global _start
	.global drive
	.global size2

_start:
	jmp	code
	.fill	60, 1, 0

code:
	cli
	xor	%ax, %ax
	mov	%ax, %ds
	mov	%ax, %es
	mov	%ax, %fs
	mov	%ax, %gs
	mov	%ax, %ss
	mov	$_END_STACK, %sp
	mov	%dl, drive
	jmp 	$0x0, $init0

init0:
	sti
	call	main

halt:
	hlt
	jmp	halt

drive:
	.byte	0x0

size2:
	.byte	0x0
