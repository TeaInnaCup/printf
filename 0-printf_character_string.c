#include "main.h"

/**
 * printf_char - handles c specifier
 * @args: no. of arguments
 * @printed: printed characters
 * Return: printed characters
 */

int printf_char(va_list args, int printed)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (printed + 1);
}

/**
 * printf_string - handles s specifier
 * @args: no. of arguements
 * @printed: printed characters
 * Return: printed characters
 */

int printf_string(va_list args, int printed)
{
	char *string = va_arg(args, char *);

	while (*string != '\0')
	{
		_putchar(*string);
		printed++;
		string++;
	}
	return (printed);
}
