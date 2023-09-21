#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	unsigned int line_num = 1;
	char *token, *buffer = malloc(sizeof(char) * 10000);
	int fd = open(argv[1], O_RDONLY), ispush = 0;
	ssize_t reader = read(fd, buffer, 10000);
	stack_t *h = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (!buffer)
		return (0);
	if (reader == -1)
	{
		free(buffer);
		close(fd);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(&h, line_num, token);
			ispush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			line_num++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (execute(token) != 0)
			{
				execute(token)(&h, line_num);
			}
			else
			{
				free_list(&h);
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, token);
				exit(EXIT_FAILURE);
			}
		}
		line_num++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}
	free_list(&h);
	free(buffer);
	close(fd);
	return (0);
}
