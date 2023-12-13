#include "monty.h"

/**
  * montyfile_error - Prints error message USAGE if
  * user don't give any file or more than 1 argument.
  *
  * Return: EXIT_FAILURE
  */
int montyfile_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
