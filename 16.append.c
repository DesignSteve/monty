#include "monty.h"

/**
 * _append - Adds the top two values of a stack_t linked list.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file
 *
 * Description: The result is stored in the second value node
 * from the top, and the top value is removed.
 */
void _append(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_error(briefstack_error(line_number, "append"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}


