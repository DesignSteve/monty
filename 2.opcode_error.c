#include "monty.h"

/**
  * opcode_error - prints error message if,
  * invalid instruction input.
  * @opcode: line number where instruction occured.
  * @line_number: Monty file where the error appeared.
  *
  * Return: EXIT_FAILURE.
  */
int opcode_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
	return (EXIT_FAILURE);
}
