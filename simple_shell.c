#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(void)
{
	char *str = NULL;
	char **tok = NULL;

	while (1) {
		str = get_line();
		tok = func_strtok(str);
		execute_program(tok);
		free(str);
                free(tok);
	}

	exit(EXIT_SUCCESS);
}
