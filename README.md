This is the repo for the 0x11. C - printf team project.



Note:
Compiling together with the provided main.c file using:

	gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

will always give this:

	root@112ca6679672:~/printf# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
	main.c: In function 'main':
	main.c:42:23: error: unknown conversion type character 'r' in format [-Werror=format=]
  	 42 |     printf("Unknown:[%r]\n");
  	    |                       ^
	cc1: all warnings being treated as errors

because r has been designated as reverse string specifier in the custom _printf function.


Therefore, after using the -Wno-format flag to compile successfully, i.e. compiling using:

	gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c

and testing the a.out executable file that is created, using this:

	./a.out

the custom _printf will not give the required result as the standard library printf on the last test contained on the last two lines of main.c:

	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");


Instead of returning, as required for both _printf and printf, this:

	Unknown:[%r]
	Unknown:[%r]

this is instead returned:

	Unknown:[
	]FF300008 ,ff300
	]0f145736eff
	]%
	]21[:neL]
	Unknown:[%r]	

in error for the custom _printf.


To debug this,
edit the second-to-the-last line of main.c partaining to the custom _printf functing, i.e.

	_printf("Unknown:[%r]\n");

by typing in a second  %, as an escape character to the first % format specifier, inbetween %r:

	_printf("Unknown:[%%r]\n");

save, quit editor and recompile successfully as before, and test the executable file again, as before.

The desired output should be gotten this time.


	root@112ca6679672:~/printf# cat main.c
	#include <limits.h>
	#include <stdio.h>
	#include "main.h"

	/**
	 * main - Entry point
	 *
	 * Return: Always 0
	 */
	int main(void)
	{
	    int len;
	    int len2;
	    unsigned int ui;
	    void *addr;

	    len = _printf("Let's try to printf a simple sentence.\n");
	    len2 = printf("Let's try to printf a simple sentence.\n");
	    ui = (unsigned int)INT_MAX + 1024;
	    addr = (void *)0x7ffe637541f0;
	    _printf("Length:[%d, %i]\n", len, len);
	    printf("Length:[%d, %i]\n", len2, len2);
	    _printf("Negative:[%d]\n", -762534);
	    printf("Negative:[%d]\n", -762534);
	    _printf("Unsigned:[%u]\n", ui);
	    printf("Unsigned:[%u]\n", ui);
	    _printf("Unsigned octal:[%o]\n", ui);
	    printf("Unsigned octal:[%o]\n", ui);
	    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	    _printf("Character:[%c]\n", 'H');
	    printf("Character:[%c]\n", 'H');
	    _printf("String:[%s]\n", "I am a string !");
	    printf("String:[%s]\n", "I am a string !");
	    _printf("Address:[%p]\n", addr);
	    printf("Address:[%p]\n", addr);
	    len = _printf("Percent:[%%]\n");
	    len2 = printf("Percent:[%%]\n");
	    _printf("Len:[%d]\n", len);
	    printf("Len:[%d]\n", len2);
	    _printf("Unknown:[%%r]\n");
	    printf("Unknown:[%r]\n");
	    return (0);
	}	 
	root@112ca6679672:~/printf# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c
	root@112ca6679672:~/printf# ./a.out
	Let's try to printf a simple sentence.
	Let's try to printf a simple sentence.
	Length:[39, 39]
	Length:[39, 39]
	Negative:[-762534]
	Negative:[-762534]
	Unsigned:[2147484671]
	Unsigned:[2147484671]
	Unsigned octal:[20000001777]
	Unsigned octal:[20000001777]
	Unsigned hexadecimal:[800003ff, 800003FF]
	Unsigned hexadecimal:[800003ff, 800003FF]
	Character:[H]
	Character:[H]
	String:[I am a string !]
	String:[I am a string !]
	Address:[0x7ffe637541f0]
	Address:[0x7ffe637541f0]
	Percent:[%]
	Percent:[%]
	Len:[12]
	Len:[12]
	Unknown:[%r]
	Unknown:[%r]
	root@112ca6679672:~/printf# 

