	bits 16 		; 16-bit mode (legacy mode)
	mov ah, 0xe		; BIOS teletype mode
				; 'Hello' word in ASCII
	mov al, 'H'
	int 0x10
	mov al, 'e'
	int 0x10
	mov al, 'l'
	int 0x10
	mov al, 'l'
	int 0x10
	mov al, 'o'
	int 0x10
				; space in ASCII
	mov al, ' '
	int 0x10
				; 'World' word in ASCII
	mov al, 'W'
	int 0x10
	mov al, 'o'
	int 0x10
	mov al, 'r'
	int 0x10
	mov al, 'l'
	int 0x10
	mov al, 'd'
	int 0x10
	mov al, '!'
	int 0x10

halt:
	hlt
	jmp halt

	times 510 - ($ - $$) db 0
	dw 0xaa55
