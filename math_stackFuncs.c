#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @h: top node
 * @line_number: node number
 */
void _add(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
