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
	int count;
	va_list args;
	va_start(args, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			int precision;
			precision = -1;
			format++;

			if (*format >= '0' && *format <= '9')
			{
				precision = 0;
				while (*format >= '0' && *format <= '9')
				{
					precision = precision * 10 + (*format - '0');
					format++;
				}
			}
			/* Handle conversion specifiers */
			switch (*format)
			{
				case 'c':
					count += putchar(va_arg(args, int));
					break;
				case 's':
					count += printf("%.*s", precision, va_arg(args, char *));
					break;
				case '%':
					count += putchar('%');
					break;
					/* more cases for additional conversion with specifiers */
				default:
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
