#include "lists.h"

/**
 * print_dlistint -A function that prints all the elements of a list
 * @h: A pointer to the list
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t p;
	const dlistint_t *temp;

	if (h == NULL)
		return (0);
	temp = h;

	for (p = 0; temp != NULL; p++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (p);
}
