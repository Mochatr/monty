#include "monty.h"

/**
 * handle_opcode - Parse and execute opcodes.
 * @line: Input line from Monty byte code file.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void handle_opcode(char *line, sstack_t **stack, unsigned int line_number)
{
	char *opcode = strtok(line, " \n\t$");
	char *arg = strtok(NULL, " \n\t$");

	if (opcode == NULL)
	{
		return;
	}

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, arg);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
}
