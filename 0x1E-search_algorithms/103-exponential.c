#include "search_algos.h"

/**
 * _binary_search - Checking for a value in a sorted array
 *                  of integers using binary check.
 * @array: A reference to fresh element of an array to check.
 * @left: The position of the [sub]array to check.
 * @right: The end position of the [sub]array to check.
 * @value: A value to check for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Shows the [sub]array being checked after every change.
 */
int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (k = left; k < right; k++)
			printf("%d, ", array[k]);
		printf("%d\n", array[k]);

		k = left + (right - left) / 2;
		if (array[k] == value)
			return (k);
		if (array[k] > value)
			right = k - 1;
		else
			left = k + 1;
	}

	return (-1);
}

/**
 * exponential_search - Checking for a value in a sorted array
 *                      of integers using exponential check.
 * @array: A reference to fresh element of an array to check.
 * @size: A number of elements in an array.
 * @value: A value to check for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Shows the value eche time is compared in an array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t k = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (k = 1; k < size && array[k] <= value; k = k * 2)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
	}

	right = k < size ? k : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", k / 2, right);
	return (_binary_search(array, k / 2, right, value));
}
