#include "monty.h"

/**
 * _pstr - Outputs the string stored in a stack_t linked list.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 *
 * @line_number: The current line number in a Monty bytecode file.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
