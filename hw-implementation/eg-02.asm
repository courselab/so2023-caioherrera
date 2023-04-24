	bits 16

	org 0x7c00
	
	mov ah, 0xe
	mov bx, 0x00
	
loop:
	mov al, [msg + bx]
	int 0x10
	cmp al, 0x0
	je halt
	add bx, 0x1
	jmp loop

halt:
	hlt
	jmp halt

msg:
	db 'Hello, World!', 0x0

	times 510 - ($ - $$) db 0
	dw 0xaa55
