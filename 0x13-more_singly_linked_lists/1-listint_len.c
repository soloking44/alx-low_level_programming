#include "lists.h"

/**
 * listint_len - custom function that returns the number of elements
 * in a linked listint_t list.
 * @h: pointer to the header address
 * Return: numbers of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
	{
		h = h->next;
	}
	return (i);
}
