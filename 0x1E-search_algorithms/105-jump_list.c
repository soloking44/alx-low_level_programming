#include "search_algos.h"
#include <math.h>

/**
 * jump_list - Checking for a value in an array of
 * integers using the Jump check algorithm
 *
 * @list: Entry list
 * @size: A size of an array
 * @value: A Value to search for
 * Return: Position of the number
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, o, p;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);

	p = (size_t)sqrt((double)size);
	index = 0;
	o = 0;

	do {
		prev = list;
		o++;
		index = o * p;

		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

	} while (index < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);

	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}

	return (NULL);
}
