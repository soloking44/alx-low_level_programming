#include "lists.h"

/**
 * list_len - a function that returns the number of elements
 * in a linked list_t list
 * @h: a pointer to the list address
 * Return: the number of nodes
 */
size_t list_len(const list_t *h)
{
	int i;

	for (i = 0; h != NULL; i++)
	{
		h = h->next;
	}
	return (i);
}
