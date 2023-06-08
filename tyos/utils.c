#include <utils.h>

void __attribute__((fastcall, naked)) print (const char* buffer)
{
	__asm__
	(
	"	mov	%cx, %bx	;"
	"	mov	$0x0e, %ah	;"
	"	mov	$0x0, %si	;"
	"loop:				;"
	"	mov	(%bx, %si), %al	;"
	"	cmp	$0x0, %al	;"
	"	je	end		;"
	"	int	$0x10		;"
	"	add	$0x1, %si	;"
	"	jmp	loop		;"
	"end:				;"
	"	ret			;"
	);
}

void __attribute__((fastcall, naked)) fatal (const char* msg)
{
	print (msg);
	print (NL);

	__asm__
	(
	"fatal_halt2:			;"
	"	hlt			;"
	"	jmp	fatal_halt2	;"
	);
}

void __attribute__((fastcall, naked)) clrstr (void)
{
	__asm__
	(
	"	mov $0x0600, %ax	;"
	"	mov $0x07, %bh		;"
	"	mov $0x0, %cx		;"
	"	mov $0x184f, %dx	;"
	"	int $0x10		;"
	"	ret			;"
	);
}

void system_hlt()
{
	__asm__
	(
	"sys_halt:			;"
	"	hlt			;"
	"	jmp sys_halt		;"
	);
}
