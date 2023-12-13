#include "monty.h"

/**
 * pchar_error - Prints error messages for pchar, handling empty stacks
 * and non-character values.
 *
 * @line_number: Line number in the Monty bytecode file
 * where the error occurred.
 *
 * @message: The corresponding error message to print.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}

/**
 * _pchar - Outputs the character stored in the top value
 * node of a stack_t linked list.
 *
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in a Monty bytecode file.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}
