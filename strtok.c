#include "shell.h"

/**
 * func_strtok - Split a string into tokens
 * @mensaje: Input recieved from user input
 * Return: The token(s)
 */
char **func_strtok(char *buffer)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *token, *ev = "";
        char **array;
        int i = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}

        array = malloc(strlen(buffer) + 1024);

	token = strtok(buffer, delimiters);
        array[i] = token;

	ev = "env";
	if (strcmp(ev, array[0]) == 0)
	{
		free(buffer);
		_env(i);
	}
	ev = "1";

        while (token)
        {
		i++;
		token = strtok(NULL, delimiters);
		array[i] = token;
        }

        i++;
        array[i] = NULL;

	return (array);
}
