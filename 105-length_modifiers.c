#include "main.h"

/**
 * get_size - handles length modifiers
 * @format: format specifier
 * @i: list of arguments to be printed
 * Return: string print
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

/**
 * convert_size_number - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsigned - casts unsigned number to the specified size
 * @num: unsigned number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of unsigned number
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
