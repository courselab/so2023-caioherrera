#ifndef UTILS_H
#define UTILS_H

#define NL "\r\n"

void __attribute__ ((naked, fastcall)) print (const char *str);

void __attribute__ ((naked, fastcall)) clrstr (void);

void system_hlt();

#endif
