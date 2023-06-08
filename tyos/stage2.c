#include <helper.h>

void __attribute__((naked)) init()
{
	clear ();
	
	echo ("Hello, World! Welcome to TinyOS!" NL);

	echo ("Please type your commands on the prompt below. (Max.: 10 characters)" NL);

	echo ("> ");

	char c = getchar();

	putchar(c);
	
	system_halt();
}
