#include "monty.h"

/**
 * _pop - Removes the top element from
 * a stack_t linked list.
 *
 * @stack: A pointer to the top node of a
 * stack_t linked list.
 *
 * @line_number: The current line number in
 * the Monty bytecode file.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
  * pop_error - Prints error messages for "pop"
  * operation on empty stacks.
  *
  * @line_number: Line number in the script where
  * the error occurred.
  *
  * Return: Always returns (EXIT_FAILURE).
  */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
