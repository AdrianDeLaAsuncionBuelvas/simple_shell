#include "shell.h"
/**
 * get_line - Prints "$ " and wait for a command
 *
 * Return: The read command or error if not
 *
 **/
char *get_line(int isatty_value)
{
	ssize_t characters_read = 0;
	size_t num_bytes = 0;
	char *mensaje = NULL;

	if (isatty_value == 1)
	{
		printf("$ ");
	}

	characters_read = getline(&mensaje, &num_bytes, stdin);

	if (characters_read == EOF)
	{
		if (isatty_value == 1)
		{
			printf("\n");
		}
		free(mensaje);
		exit(EXIT_SUCCESS);
	}
	return (mensaje);
}
