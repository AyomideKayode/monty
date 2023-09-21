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
