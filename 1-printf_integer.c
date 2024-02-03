#include "main.h"

/**
 * printf_integer - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of character printed
 */
int printf_integer(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = count_digits(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		res += _putchar('+');
	if (n <= 0)
		res++;
	printf_digits(n);
	return (res);
}

/**
 * printf_digits - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void printf_digits(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		printf_digits(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * count_digits - returns the number of digits in an integer
 * for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digits(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
