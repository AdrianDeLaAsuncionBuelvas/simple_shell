#include "shell.h"

/**
 * _env - print the current environment.
 *
 * @num: Numers of arguments received for the getline
 *
 * Return:  0
 */
int _env(int num)
{
	int i = 0, len = 0;

	if (num > 1)
	{
		perror("Error");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		len = strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
