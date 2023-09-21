#include "monty.h"

/**
 * execute - function to select correct operation function
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*execute(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}

/**
 * check_int - checks if a string represents a valid integer
 * @n: a string to check
 * Return: 0 if it's a number, -1 if not
 */
int check_int(const char *n)
{
	int i = 0;

	if (n == NULL || *n == '\0')
		return (-1);

	if (n[i] == '-' || n[i] == '+')
		i++;

	for (; n[i] != '\0'; i++)
	{
		if (!isdigit(n[i]))
			return (-1);
	}

	return (0);
}

/**
 * push - adds node to the start of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */

void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (check_int(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_node(h, atoi(n)) == -1)
		{
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - print all nodes in stack
 * @h: head of list
 * @line_number: bytecode line number
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	node = *h;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

