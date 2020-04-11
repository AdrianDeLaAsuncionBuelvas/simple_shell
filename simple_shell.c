#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(void)
{
	char *s = NULL;
	char **tok = NULL;

	while (1) {
		s = get_line();
		tok = func_strtok(s);
		execute_program(tok);
		free(s);
                free(tok);		
	}

	exit(EXIT_SUCCESS);
}
