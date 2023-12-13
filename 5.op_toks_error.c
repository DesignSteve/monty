#include "monty.h"

/**
 * op_tok_error - Sets the last element of op_toks to an error code.
 *
 * @error_code: Integer to be stored as a string in op_toks.
 */
void op_tok_error(int error_code)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = tokenarray_length();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_fail();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = fetch_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_fail();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}

