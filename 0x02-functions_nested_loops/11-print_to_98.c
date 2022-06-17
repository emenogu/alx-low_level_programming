#include <stdio.h>

/**
 * print_to_98 - Prints all natural numbers
 * from n to 98.
 *
 * @n: input number.
 *
 * Return: no return.
 */
void print_to_98(int n)
{
	int n;

	for (n = 0; n <= 98; n++)
	{
		printf("%d, ", n);
	}
	printf("\n");
}
