#include "search_algos.h"

/**
  * linear_search - Checks for a value in an array
  *                 of integers used linear search.
  * @array: A reference to the new element of an array to check.
  * @size: The value of elements within an array.
  * @value: The value to check for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         else, the first index where the value is located.
  *
  * Description: Shows the value eche time is compared within array.
  */
int linear_search(int *array, size_t size, int value)
{
	size_t k;

	if (array == NULL)
		return (-1);

	for (k = 0; k < size; k++)
	{
		printf("Value checked array[%ld] = [%d]\n", k, array[k]);
		if (array[i] == value)
			return (k);
	}

	return (-1);
}
