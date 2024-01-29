#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
void handle_s(int *count, va_list args, int precision);
#endif /* MAIN_H */
