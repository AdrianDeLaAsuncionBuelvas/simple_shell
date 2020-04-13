#include "shell.h"

/**
 * func_strtok - Split a string into tokens
 * @mensaje: Input recieved from user input
 * Return: The token(s)
 */
char **func_strtok(char *mensaje)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *token = NULL;
        char **array = NULL;
        int i = 0;

	if (mensaje == NULL)
	{
		return (NULL);
	}

        array = malloc(strlen(mensaje) + 1024);

	token = strtok(mensaje, delimiters);
        array[i] = token;

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
