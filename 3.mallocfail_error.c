#include "monty.h"

/**
  * malloc_fail - Prints malloc failed if can't malloc.
  *
  * Return: EXIT_FAILURE.
  */
int malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
