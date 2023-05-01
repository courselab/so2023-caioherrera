	# Hello World using AT&T assembly
	# Setting mode as 16-bit
	.code16

	# Defining starting point for linker
	.global	_start

_start:
	# Setting initial values for registers

	# Setting BIOS mode
	movb	$0xe, %ah

	# Setting index for the loop
	movw	$0x0, %si

loop:
	# Loads current character and jumps to halt if it's byte 0
	movb	msg(%si), %al
	cmp	$0x0, %al
	je	halt

	# Call interruption for BIOS video service
	int	$0x10

	# Increases index register and goes back to the loop
	add	$0x1, %si
	jmp	loop

halt:
	# Halts the execution of the program
	hlt
	jmp	halt

msg:
	# Stores the desired message
	.string	"Hello, World!"

	# Fills the remaining bytes with 0s
	.fill	510 - (. - _start), 1, 0

	# Adds final bytes
	.word 0xaa55
