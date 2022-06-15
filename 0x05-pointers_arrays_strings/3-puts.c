#include "main.h"

/**
 * _puts - primts a string to standard output
 * @str: the string to be printed
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}
