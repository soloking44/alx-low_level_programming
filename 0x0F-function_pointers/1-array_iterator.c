#include "function_pointers.h"

/**
 * array_iterator - it executes a function given as a parameter on each elem of
 * an array.
 * @array: a pointer to array.
 * @size: the size of array.
 * @action: function pointer
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array != NULL && action != NULL)
		for (i = 0; i < size; i++)
			action(array[i]);
}
