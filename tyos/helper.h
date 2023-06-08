#ifndef HELPER_H
#define HELPER_H

#define VIDEO_MEMORY 0xb8000
#define VIDEO_ATTRIBUTE 0x02

#define VIDEO_SIZE_ROWS 25
#define VIDEO_SIZE_COLS 80

#define NL "\n"

void __attribute__ ((fastcall)) putchar (const char c);

void __attribute__ ((naked, fastcall)) echo (const char *str);

void __attribute__ ((naked, fastcall)) clear (void);

char __attribute__ ((naked, fastcall)) getchar (void);

void system_halt();

#endif
