#include "variadic_functions.h"

/**
 * print_numbers - a function that prints numbers.
 * @separator: a string to be printed between numbers.
 * @n: a number of integers passed to the function.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list list;
	unsigned int i;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(list, int));
		if (separator && i < (n - 1))
			printf("%s", separator);
	}

	printf("\n");
	va_end(list);
}
