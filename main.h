#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

int printf_integer(va_list l, flags_t *f);
void printf_digits(int n);
int printf_unsigned(va_list l, flags_t *f);
int count_digits(int i);
int printf_hex(va_list l, flags_t *f);
int printf_Hex(va_list l, flags_t *f);
int printf_binary(va_list l, flags_t *f);
int printf_octal(va_list l, flags_t *f);
char *convert(unsigned long int num, int base, int lowercase);
int _printf(const char *format, ...);
int (*_printf_handler(char s))(va_list, flags_t *);
int get_flag(char s, flags_t *f);
int printf_string(va_list l, flags_t *f);
int printf_char(va_list l, flags_t *f);
int _putchar(char c);
int _puts(char *str);
int printf_Rot13(va_list l, flags_t *f);
int printf_reverse(va_list l, flags_t *f);
int printf_non_printable(va_list l, flags_t *f);
int printf_pointer(va_list l, flags_t *f);
int printf_percent(va_list l, flags_t *f);

#endif
