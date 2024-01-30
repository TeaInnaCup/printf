#include "main.h"

/**
 * _putchar - outputs character
 * @character: character
 * Return: 1, success; -1, error
 */

int _putchar(char character)
{
	return (write(1, &character, 1));
}
