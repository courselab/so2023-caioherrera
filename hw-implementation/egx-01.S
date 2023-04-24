	.code16

_start:
	mov ah, 0xe
	mov bx, 0

loop:
	mov al, BYTE PTR [msg + bx]
	cmp al, 0x0
	je halt
	int 0x10
	add bx, 0x1
	jmp loop

halt:
	hlt
	jmp halt

msg:
	.string "Hello World!"
	
	.fill 510 - (.-_start), 1, 0
	.word 0xaa55
