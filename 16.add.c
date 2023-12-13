#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_error(briefstack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}


