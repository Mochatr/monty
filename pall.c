#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: parameter
 */

void pall(sstack_t **stack)
{
	sstack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
