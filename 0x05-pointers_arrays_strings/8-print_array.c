#include "main.h"
#include <stdio.h>

/**
 * print_array - prints an inputted number of elements of an array of integers
 * @a: array of integers
 * @n: number of elements to be printed.
 */
void print_array(int *a, int n)
{
	int index;

	for (index = 0; index < n; index++)
	{
		printf("%d", a[index]);

		if (index == n - 1)
			continue;

		printf(", ");
	}
	printf("\n");
}
