#include "monty.h"

/**
 * _mod - Computes the modulus of the top value by the second value on
 * a stack_t linked list.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 *
 * Description: This function calculates the modulus of the second value
 * from the top of the stack by the top value. The result
 * is stored in the second value node, and the top value is removed.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_tok_error(briefstack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}

