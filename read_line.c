#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

if (characters_read < 0)
{
printf("Error reading input\n");
exit(EXIT_FAILURE);
}

return (mensaje);
}
