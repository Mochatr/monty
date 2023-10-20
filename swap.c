#include "monty.h"

/**
 * swap - swap.
 *
 * @stack: pointer to head
 * @line_number: line number
 * @arg: argum
 *
 * Return: 0 value
 */

int swap(sstack_t **stack, unsigned int line_number, char *arg)
{
	int y;
	(void)arg;

	if (*stack && (*stack)->next)
	{
		y = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		return (-1);
	}
	return (0);
}
