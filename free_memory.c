#include "shell.h"

/**
 * free_memory - frees stored memory data.
 * @token: variable to release
 */

void free_memory(char **token)
{
	int i;

	for (i = 0; token[i]; i++)
	{
		free(token[i]);
		token[i] = NULL;
	}
	free(token);
	token = NULL;
}
