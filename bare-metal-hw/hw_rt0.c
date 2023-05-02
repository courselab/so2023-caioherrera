void __attribute__((naked)) _start()
{
	__asm__ volatile
	("\
		mov	$__END_STACK__ , %%sp	\n\
		call 	main			\n\
	loop%=:					\n\
		hlt				\n\
		jmp loop%=			\n\
	"
	:::
	);
}
