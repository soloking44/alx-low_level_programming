#include "search_algos.h"

/**
 * recursive_search - Checks for value within an array 
 * integers used for Binary search algorithm
 *
 *
 * @array: Entry array
 * @size: The size of an array
 * @value: The value to search for
 * Return: Position of the number
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t k;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (k = 0; k < size; k++)
		printf("%s %d", (k == 0) ? ":" : ",", array[k]);

	printf("\n");

	if (half && size % 2 == 0)
		half--;

	if (value == array[half])
		return ((int)half);

	if (value < array[half])
		return (recursive_search(array, half, value));

	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 * binary_search - Function of binary_search that yield
 * to position of the number
 *
 * @array: Entry array
 * @size: A size of an array
 * @value: The value to search for
 * Return: Position of the number
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
