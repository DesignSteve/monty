#include "monty.h"
#include <string.h>
#include <stdio.h>

int execute_monty(FILE *script_fd);

/**
 * free_memory - Deallocates memory used by the
 * global op_toks array of strings.
 *
 * Returns: void
 */
void free_memory(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;
	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokenarray_length - Obtains the length of the current op_toks.
 *
 * Return: Length of the current op_toks (as an integer).
 */
unsigned int tokenarray_length(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * empty_line - This function checks whether a line,
 * obtained from getline,contains only delimiter characters.
 *
 * @line: A pointer to the line to be checked.
 * @delims: A string of delimiter characters.
 *
 * Return: 1 if the line consists solely of delimiters,0 otherwise.
 */
int empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; delims[j]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

/**
 * operation_func - Finds the function corresponding
 * to a given opcode.
 *
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*operation_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
 * execute_monty - Main function for executing a
 * Monty bytecode script.
 *
 * @script_fd: File descriptor for an open Monty bytecode script.
 *
 * Return: Returns EXIT_SUCCESS on success,
 * or the appropriate error code on failure.
 */
int execute_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (activate_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = tokenize_string(line, DELIMS);
		if (op_toks == NULL)
		{
			if (empty_line(line, DELIMS))
				continue;
			unload_stack(&stack);
			return (malloc_fail());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_memory();
			continue;
		}
		op_func = operation_func(op_toks[0]);
		if (op_func == NULL)
		{
			unload_stack(&stack);
			exit_status = opcode_error(op_toks[0], line_number);
			free_memory();
			break;
		}
		prev_tok_len = tokenarray_length();
		op_func(&stack, line_number);
		if (tokenarray_length() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_memory();
			break;
		}
		free_memory();
	}
	unload_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_fail());
	}

	free(line);
	return (exit_status);
}
