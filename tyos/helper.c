#include <helper.h>

extern short screen_pos;

void __attribute__((fastcall)) putchar (const char c)
{
	short *video = (short *) VIDEO_MEMORY;
	
	if (c == NL[0])
		screen_pos += ((screen_pos / VIDEO_SIZE_COLS) + 1) * VIDEO_SIZE_COLS - screen_pos;
	else
		video[screen_pos++] = (VIDEO_ATTRIBUTE << 8) + c;
}

void __attribute__((fastcall, naked)) echo (const char* buffer)
{
	int i = 0;
	while(buffer[i])
	{
		putchar(buffer[i++]);
	}
	__asm__("ret");
}

void __attribute__((fastcall, naked)) fatal_halt (const char* msg)
{
	echo (msg);
	echo (NL);

	__asm__
	(
	"fatal_halt2:			;"
	"	hlt			;"
	"	jmp	fatal_halt2	;"
	);
}

void __attribute__((fastcall, naked)) clear (void)
{
	short *video = (short *) VIDEO_MEMORY;
	int i = 0;
	while (i < VIDEO_SIZE_ROWS * VIDEO_SIZE_COLS)
	{
		video[i++] = (VIDEO_ATTRIBUTE << 8) + ' ';
	}

	screen_pos = 0;
	
	__asm__("ret");
}

char __attribute__((fastcall)) getchar (void)
{
	__asm__
	(
	"	mov	$0x0, %ah	;"
	"	int	$0x16		;"
	"	ret			;"
	);
}

char __attribute__((fastcall, naked)) gets (const int max_size)
{
	int available = max_size;
	while (available)
	{
		char c = getchar();

	}
}	

void system_halt()
{
	__asm__
	(
	"sys_halt:			;"
	"	hlt			;"
	"	jmp sys_halt		;"
	);
}
