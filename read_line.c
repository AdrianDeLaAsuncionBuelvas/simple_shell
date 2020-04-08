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
	char *mensaje;

printf("$ ");
characters_read = getline(&mensaje, &num_bytes, stdin);

if (characters_read == EOF)
{
printf("Shell closed\n");
exit(EXIT_SUCCESS);
}

return (mensaje);
}
