#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_node(h);
}

/**
 * swap - swaps the top two elements of the stack.
 * @h: node to be swapped
 * @line_number: node number
 */

void swap(stack_t **h, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	node = (*h)->next;
	if (node->next != NULL)
	{
		(*h)->next = node->next;
		(*h)->next->prev = *h;
	}
	else
	{
		node->prev->prev = node;
		node->prev->next = NULL;
	}
	node->prev = NULL;
	node->next = *h;
	(*h) = node;
}

/**
 * nop - doesn’t do anything.
 * @h: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **h, unsigned int line_number)
{
	(void)h;
	(void)line_number;
}
