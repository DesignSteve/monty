#include "monty.h"

/**
 * _pint - Prints the value at the top of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * pint_error - Prints error messages for "pint"
 * operation on empty stacks.
 *
 * @line_number: Line number in the Monty bytecode
 * file where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
