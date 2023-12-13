#include "monty.h"

/**
  * openfile_error - prints can't open file error message,
  * @filename: is the name of the file that failed to open
  *
  *Return: EXIT_FAILURE
  */
int openfile_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}
