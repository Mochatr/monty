#include "monty.h"
/**
 * push - add into stack
 * @stack: the stack
 * @line_number: the number
 * @argument: args
 */
void push(sstack_t **stack, unsigned int line_number, char *argument)
{
	sstack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(sstack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (argument == NULL || !isdigit(*argument)
			|| (atoi(argument) == 0 && *argument != '0'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
