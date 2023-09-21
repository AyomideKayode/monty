#include "monty.h"

/**
 * rotl - rotate the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: bytecode line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	top = *stack;
	second = (*stack)->next;

	while (top->next != NULL)
		top = top->next;

	top->next = *stack;
	(*stack)->prev = top;
	(*stack)->next = NULL;

	*stack = second;
	(*stack)->prev = NULL;
}
