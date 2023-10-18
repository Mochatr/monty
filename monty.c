#include "monty.h"
/**
 * main - entry point
 * @argc: argument number
 * @argv: argument array
 * Return: value
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		char *opcode = strtok(line, " \n\t$");
		char *arg = strtok(NULL, " \n\t$");

		if (opcode == NULL)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number, arg);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
	}
	free(line);
	fclose(file);
	return (0);
}
