        ## Boot, say hello, and halt (AT&T assembly)

	.code16				# setting code mode to 16 bits
	.global _start
	
_start:	
	mov $0xe, %ah			# initialize BIOS tty mode
	mov $0x0, %bx			# initialize string index

loop:
	mov msg(%bx), %al		# moves the current value on msg[idx] to al
	cmp $0x0, %al			# checks if al contains byte 0
	je halt				# if so, jumps to halt
	int $0x10			# interruption 10, prints a character on screen	
	add $0x1, %bx			# increases the index by 1
	jmp loop			# goes back to the start of the loop

halt:
	hlt
	jmp halt			# goes back to the halt

msg:
	.string "Hello, World!"		# stores the desired string
	
	.fill 510 - (. - _start), 1, 0	# fills the remaining bytes with 0
	.word 0xaa55
