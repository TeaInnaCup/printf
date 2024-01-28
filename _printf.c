#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */
			switch (*format)
			{
				case 'c':
					/* Character */
					count += putchar(va_arg(args, int));
					break;
				case 's':
					/* String */
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					/* Percentage sign */
					count += putchar('%');
					break;
				default:
					/* Invalid specifier, just print the character */
					count += putchar('%');
					count += putchar(*format);
					break;
			}
		}
		else
		{
			/* Regular character */
			count += putchar(*format)
		}
		format++; /* Move to the next character in the format string */
	}
	va_end(args);
	return (count);
}
