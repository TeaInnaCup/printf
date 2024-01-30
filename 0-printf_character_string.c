#include "main.h"

/**
 * _printf - outputs specified format
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	int printed = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed = selector(format, args, printed);
			format++;
		}
		else
		{
			_putchar(*format);
			printed++;
			format++;
		}
	}
	va_end(args);
	return (printed);
}

/**
 * selector - selects format specifiers
 * @args: no. of arguments
 * @printed: the printed characters
 * @format: the format specifier
 * Return: printed charcaters
 */

int selector(const char *format, va_list args, int printed)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			printed = printf_integer(args, printed);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			printed++;
			break;
		case 's':
			printed = printf_string(args, printed);
			break;
		case '%':
			_putchar('%');
			printed++;
			break;
		case 'b':
			printed = printf_binary(va_arg(args, unsigned int), printed);
			break;
		case 'x':
		case 'X':
			printed = _x(va_arg(args, unsigned int), printed, (*format == 'X') ? 1 : 0);
			break;
		case 'o':
			printed = printf_octal(va_arg(args, unsigned int), printed);
			break;
		case 'u':
			printed = printf_unsigned(va_arg(args, unsigned int), printed);
			break;
		case 'r':
			printed = printf_reverse(args, printed);
			break;
		case 'p':
			printed = printf_pointer(args, printed);
			break;
		default:
			break;
	}
	return (printed);
}
