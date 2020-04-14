#include "shell.h"

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