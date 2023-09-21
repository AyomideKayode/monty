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
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n += (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @h: top of list
 * @line_number: line of command
 */

void _sub(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n -= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @h: top of list
 * @line_number: line of command
 */

void _div(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(h);
	}
	(*h)->next->n /= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * _mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @h: top of list
 * @line_number: line of command
 */

void _mul(stack_t **h, unsigned int line_number)
{
	if (*h == NULL || (*h)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n *= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}

/**
 * _mod - computes the rest of the division
 * of the second top element of the stack
 * by the top element of the stack.
 * @h: top of list
 * @line_number: line of command
 */

void _mod(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
