#include "shell.h"

/**
 * func_strtok - Split a string into tokens
 * @mensaje: Input recieved from user input
 * Return: The token(s)
 */

char *func_strtok(char *mensaje)
{
	char *delimiters = " ,!¡¿?'\"\n\t";
	char *token;

	if (mensaje == NULL)
	{
		return (NULL);
	}
	token = strtok(mensaje, delimiters);

	if (token == NULL)
	{
		return (NULL);
	}
	token = strtok(mensaje, delimiters);
	return (token);
}
