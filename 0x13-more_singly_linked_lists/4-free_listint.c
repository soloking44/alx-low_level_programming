#include "lists.h"

/**
 * free_listint - custom function that free memory of all list.
 * @head: pointer to head in fucntion
 * Return: Always success.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
