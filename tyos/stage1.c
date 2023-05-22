#include <utils.h>

void __attribute__ ((naked)) load_stage2();

int main()
{
	clear();

	echo ("Stage 1 : loading second stage..." NL NL);

	load_stage2();

	init();

	return 0;
}

extern char drive;

void __attribute__ ((naked)) load_stage2()
{
	__asm__
	(
	"	xor	%dx, %dx		;"
	"	mov	$_STAGE2_SIZE, %ax	;"
	"	mov	$512, %cx		;"
	"	div	%cx			;"
	"	add	$1, %ax			;"
	"	mov	%ax, size2		;"

	"reset:					;"
	"	mov	$0x0, %ah		;"
	"	mov	drive, %dl		;"
	"	int	$0x13			;"
	
	"	jnc	load			;"
	"	mov	$err2, %cx		;"
	"	call	fatal			;"

	"load:					;"
	"	mov	drive, %dl		;"
	"	mov	$0x2, %ah		;"
	"	mov	size2, %al		;"
	"	mov	$0x0, %ch		;"
	"	mov	$0x2, %cl		;"
	"	mov	$0x0, %dh		;"
	"	mov	$_STAGE2_ADDR, %bx	;"
	"	int	$0x13			;"

	"	mov	$err1, %cx		;"
	"	jc	fatal			;"

	"	ret				;"
	);
}

const char err1[] = "Error : device reset failure." NL;
const char err2[] = "Error : device read failure." NL;
