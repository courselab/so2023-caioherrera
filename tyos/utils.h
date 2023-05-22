#ifndef UTILS_H
#define UTILS_H

#define VIDEO_MEMORY 0xb8000
#define VIDEO_ATTRIBUTE 0x02

#define NL "\r\n"

void __attribute__ ((naked, fastcall)) echo (const char *str);

void __attribute__ ((naked, fastcall)) clear (void);

void system_halt();

#endif
