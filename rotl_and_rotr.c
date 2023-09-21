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

/**
 * rotr - rotate the stack to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: bytecode line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_to_last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	second_to_last = last->prev;

	second_to_last->next = NULL;
	last->prev = NULL;

	last->next = *stack;
	(*stack)->prev = last;

	*stack = last;
}
