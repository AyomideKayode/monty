#include "monty.h"

/* Global variable to track the current mode (stack or queue) */
int is_queue_mode = 0; /* Initialized to 0 (stack mode) by default */

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the head of the stack
 * @line_number: bytecode line number
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	/* Update the mode to stack (LIFO) */
	is_queue_mode = 0;
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the head of the stack
 * @line_number: bytecode line number
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = NULL;
	stack_t *current = *stack;
	stack_t *next = NULL;

	(void) line_number;
	/* Update the mode to queue (FIFO) */

	/* Reverse the order of elements in the stack to make it a queue */
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}

	/* Update the head of the stack to the new front (top of the queue) */
	*stack = prev;

	/* Update the mode to queue */
	is_queue_mode = 1;
}
