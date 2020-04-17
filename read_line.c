#include "shell.h"
/**
 * get_line - Prints "$ " and wait for a command
 * @isatty_value: check if it's an entry
 * Return: buffer
 *
 **/
char *get_line(int isatty_value)
{
	ssize_t characters_read = 0;
	size_t num_bytes = 0;
	char *buffer = NULL;

	if (isatty_value == 1)
	{
		printf("$ ");
	}

	characters_read = getline(&buffer, &num_bytes, stdin);

	if (characters_read == EOF)
	{
		if (isatty_value == 1)
		{
			printf("\n");
		}
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
