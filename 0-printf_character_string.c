#include "main.h"

/**
 * printf_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printf_char(va_list l, flags_t *f)
{
        (void)f;
        _putchar(va_arg(l, int));
        return (1);
}

/**
 * printf_string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printf_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * printf_percent - prints percent sign
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags which turns the flags on
 * Return: number of char printed
 */
int printf_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
