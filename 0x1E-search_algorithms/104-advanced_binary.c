#include "search_algos.h"

/**
 * rec_search - Checks for a value in an array of
 * integers using the Binary search algorithm
 *
 *
 * @array: Entry array
 * @size: A size of an array
 * @value: A value to check for
 * Return: Position of the number
 */
int rec_search(int *array, size_t size, int value)
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
	{
		if (half > 0)
			return (rec_search(array, half + 1, value));
		return ((int)half);
	}

	if (value < array[half])
		return (rec_search(array, half + 1, value));

	half++;
	return (rec_search(array + half, size - half, value) + half);
}

/**
 * advanced_binary - Functions to rec_search that yield
 * the position of the number
 *
 * @array: Entry array
 * @size: A size of an array
 * @value: A value to check for
 * Return: Position of the number
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
