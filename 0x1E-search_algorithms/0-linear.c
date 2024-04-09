#include "search_algos.h"

/**
 * linear_search - It checks value within an array of
 * integers used the Linear search algorithm
 *
 * @array: An input array
 * @size: The size of the array
 * @value: A value to check for
 * Return: Always EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	for (k = 0; k < size; k++)
	{
		if (array[k] == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)k, array[k]);
			return ((int)k);
		}
		printf("Value checked array[%d] = [%d]\n", (int)k, array[k]);
	}
	return (-1);
}
