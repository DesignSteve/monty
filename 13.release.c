#include "monty.h"

/**
  * release_error - Prints error messages for "pop"
  * operation on empty stacks.
  *
  * @line_number: Line number in the script where
  * the error occurred.
  *
  * Return: Always returns (EXIT_FAILURE).
  */
int release_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't release an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * _release - Removes the top element from
 * a stack_t linked list.
 *
 * @stack: A pointer to the top node of a
 * stack_t linked list.
 *
 * @line_number: The current line number in
 * the Monty bytecode file.
 */
void _release(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		op_tok_error(release_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
