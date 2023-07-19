#include "function_pointers.h"

/**
 * print_name - it prints a name depends on the function.
 *
 * @name: a pointer to Name's string.
 * @f: a pointer to function.
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
