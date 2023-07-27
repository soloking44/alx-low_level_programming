#include "lists.h"

/**
 * add_node - a function that adds a node at the begining of a list.
 * @head: the current head address
 * @str: a pointer to string
 * Return: the number of nodes.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t nchar;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	for (nchar = 0; str[nchar]; nchar++)
		;

	new_node->len = nchar;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}
