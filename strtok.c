#include "shell.h"

/**
 * func_strtok - Split a string into tokens
 * @mensaje: Input recieved from user input
 * Return: The token(s)
 */
char **func_strtok(char *buffer)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *token = NULL, *ev = "";
        char **array = NULL;
        int i = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}

        array = malloc(strlen(buffer) + 1024);

	token = strtok(buffer, delimiters);
        array[i] = token;

        while (token)
        {
		i++;
		token = strtok(NULL, delimiters);
		array[i] = token;
        }

	ev = "env";
	if (strcmp(buffer, ev) == 0)
	{
		free(buffer);
		_env(i);
	}
	ev = "1";
        i++;
        array[i] = NULL;

	return (array);
}
