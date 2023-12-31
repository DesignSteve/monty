#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - The entry point to Monty Interpreter.
 *
 * @argc: The count of arguments passed to the program.
 * @argv: Pointer to an array of char pointers to arguments.
 *
 * Return: Returns EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (montyfile_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (openfile_error(argv[1]));
	exit_code = execute_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}

