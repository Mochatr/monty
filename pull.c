#include "monty.h"
/**
 * pall - prints all the values on the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number in the fil
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
