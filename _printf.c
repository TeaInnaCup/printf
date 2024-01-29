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
    int precision;

    va_start(args, format);
    count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            /* Handle conversion specifiers */
            format++; /* Move to the next character after '%' */

            precision = -1; /* Initialize precision to -1 (no precision specified) */

            if (*format >= '0' && *format <= '9')
            {
                /* If a digit is present, parse it as precision */
                precision = 0;
                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }

            switch (*format)
            {
            case 'c':
                count += putchar(va_arg(args, int));
                break;
            case 's':
                handle_s(&count, args, precision);
                break;
            case '%':
                count += putchar('%');
                break;
            /* more cases for additional conversion specifiers */
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
    return count;
}

/**
 * handle_s - Handle the 's' conversion specifier
 * @count: Pointer to the count of characters printed
 * @args: Variable argument list
 * @precision: Precision for the 's' specifier
 */
void handle_s(int *count, va_list args, int precision)
{
    const char *str = va_arg(args, const char *);

    if (precision == -1)
    {
        /* If precision is not specified, print the entire string */
        while (*str != '\0')
        {
            *count += putchar(*str);
            str++;
        }
    }
    else
    {
        /* If precision is specified, print up to the specified number of characters */
        int i;
        for (i = 0; i < precision && *str != '\0'; i++)
        {
            *count += putchar(*str);
            str++;
        }
    }
}
