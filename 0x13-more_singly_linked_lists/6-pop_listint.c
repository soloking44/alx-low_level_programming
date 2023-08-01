#include "lists.h"

/**
 * pop_listint - custom function that deletes the head node of a listint_t.
 * @head: a double pointer to head in function
 * Return: node data in the list.
 */
int pop_listint(listint_t **head)
{
	listint_t *new_head;
	int a;

	/*Ask if the head was not imput*/
	if (head == NULL || *head == NULL)
		return (0);

	new_head = (*head)->next;
	a = (*head)->n;
	free(*head);
	*head = new_head;
	return (a);
}
