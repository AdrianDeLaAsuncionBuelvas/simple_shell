#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(void)
{
	char *s = NULL;
	char *tok = NULL;

	do {
		s = get_line();
		tok = func_strtok(s);
		execute_program(tok);
		free(s);
		free(tok);
	} while (EOF != 0);

	return (0);
}
