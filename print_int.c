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
	int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++; /* Move to the next character after '%' */

			/* Handle conversion specifiers */
			switch (*format)
			{
			case 'd':
			case 'i':
				count += printf("%d", va_arg(args, int));
				break;
			default:
				/* If an unknown specifier is encountered, print '%' and the character */
				count += putchar('%');
				count += putchar(*format);
				break;
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);
	return (count);
}
