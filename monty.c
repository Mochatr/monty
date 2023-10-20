#include "monty.h"
/**
 * main - entry point
 * @argc: argument number
 * @argv: argument array
 * Return: value
 */
int main(int argc, char *argv[])
{
	sstack_t *stack = NULL;
	FILE *file;
	char line[1024];
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		handle_opcode(line, &stack, line_number);
	}
	fclose(file);
	return (0);
}
