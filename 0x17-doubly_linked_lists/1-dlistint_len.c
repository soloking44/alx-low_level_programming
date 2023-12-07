#include "lists.h"

/**
 * dlistint_len -A function that returns number of elements in a list.
 * @h: A pointer to the list
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t p;
	const dlistint_t *temp;

	if (h == NULL)
		return (0);
	temp = h;

	for (p = 0; temp != NULL; p++)
	{
		temp = temp->next;
	}
	return (p);
}
