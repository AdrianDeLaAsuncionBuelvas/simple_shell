#include "shell.h"
/**
 * get_line - Prints "$ " and wait for a command
 *
 * Return: The read command or error if not
 *
 **/
char *get_line(void)
{
	ssize_t characters_read = 0;
	size_t num_bytes = 0;
	char *buffer = NULL;
        int val_isatty = 0;

        val_isatty = isatty(STDIN_FILENO);

        if (val_isatty == 1)
        {
	  printf("$ ");
        }
	characters_read = getline(&buffer, &num_bytes, stdin);

	if (characters_read == EOF)
	{
            if (val_isatty == 1)
            {
		printf("\n");
            }
                free(buffer);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(buffer,"exit\n") == 0)
	{
                free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
