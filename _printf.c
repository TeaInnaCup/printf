#include "main.h"

/**
 * _printf - custom printf function that produces output
 * according to format
 * @format: const char pointer
 * Return: b_len
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = _printf_handler(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}

/**
 * _printf_handler - selects the right printing format
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing format
 */
int (*_printf_handler(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', printf_integer},
		{'s', printf_string},
		{'c', printf_char},
		{'d', printf_integer},
		{'u', printf_unsigned},
		{'x', printf_hex},
		{'X', printf_Hex},
		{'b', printf_binary},
		{'o', printf_octal},
		{'R', printf_Rot13},
		{'r', printf_reverse},
		{'S', printf_non_printable},
		{'p', printf_pointer},
		{'%', printf_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}
