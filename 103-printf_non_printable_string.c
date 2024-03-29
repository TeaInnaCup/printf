#include "main.h"

/**
 * printf_non_printable - prints non-printable string
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Decription: non-printable string (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * Return: number of characters printed
 */
int printf_non_printable(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}
