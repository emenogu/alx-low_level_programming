#include "main.h"

/**
 * print_numbers - prints 0123456789 followed by new line
 *
 * Return: void
 */

void print_numbers(void)
{
	int ch;

	for (ch = 48; ch < 58; ch++)
	{
		_putchar(ch);
	}
	_putchar('\n');
}
