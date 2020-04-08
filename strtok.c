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

<<<<<<< HEAD
if (mensaje == NULL)
{
return (NULL);
}
token = strtok(mensaje, delimiters);
=======
	if (mensaje == NULL)
	{
		return (NULL);
	}
	token = strtok(mensaje, delimiters);
>>>>>>> b07ed61631a5c59c2bd4eccef352c144946506ed

	return (token);
}
