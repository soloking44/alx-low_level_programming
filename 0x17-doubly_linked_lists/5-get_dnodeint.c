#include "lists.h"
/**
 * get_dnodeint_at_index - A funct that returns the nth nod of a linked list.
 * @head: A pointer to first node
 * @index: The node index
 * Return: It returns the nth node of a linked list.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int p;
	dlistint_t *temp = NULL;

	if (head == NULL)
		return (NULL);
	temp = head;
	for (p = 0; temp != NULL; p++)
	{
		if (index == 0)
			return (temp);
		temp = temp->next;
		if (p == (index - 1) && index != 0)
		{
			return (temp);
		}
	}
	return (NULL);
}
