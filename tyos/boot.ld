OUTPUT_FORMAT(binary)
SECTIONS
{
	. = 0x7c00;
	.text :
	{
		rt0.o (.text .data .bss .rodata)
		stage1.o (.text .data .bss .rodata)
		utils.o (.text .data .bss .rodata)
	}

	. = 0x7c00 + 510;
	.signature :
	{
		BYTE(0x55)
		BYTE(0xAA)
	}

	_STAGE2_ADDR = .;

	.text2 :
	{
		stage2.o (.text .data .bss .rodata)
		helper.o (.text .data .bss .rodata)
	}

	_STAGE2_SIZE = . - _STAGE2_ADDR;

	_END_STACK = 0x7bff;
}
STARTUP(rt0.o)
