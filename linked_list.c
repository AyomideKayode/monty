#include "monty.h"

/**
 * add_node - add node to linked list
 * @h: pointer to head of the linked list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */
int add_node(stack_t **h, int n)
{
	stack_t *new_node;

	if (!h)
		return (-1);

	/* allocate new node data */
	new_node = malloc(sizeof(struct stack_s));
	if (!new_node)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new_node->n = n;

	/* if empty linked list */
	if (*h == NULL)
	{
		*h = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *h;
		(*h)->prev = new_node;
		*h = new_node;
	}
	return (0);
}

/**
 * delete_node - deletes node of linked list
 * @h: pointer to head of the linked list
 */
void delete_node(stack_t **h)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

/**
 * free_list - frees a doubly linked list with only int data, no strings
 * @h: pointer to head of list
 */
void free_list(stack_t **h)
{
	if (!h)
		return; /* return if empty list */

	while (*h && (*h)->next)
	{
		*h = (*h)->next;
		free((*h)->prev);
	}
	free(*h);
}

