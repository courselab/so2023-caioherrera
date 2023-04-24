	.code16
	.global start

_start:
	mov $0xe, %ah
	mov $0x0, %bx

loop:
	mov msg(%bx), %al
	cmp $0x0, %al
	je halt
	int $0x10
	add $0x1, %bx
	jmp loop

halt:
	hlt
	jmp halt

msg:
	.string "Hello World!"
	
	.fill 510 - (. - _start), 1, 0
	.word 0xaa55
